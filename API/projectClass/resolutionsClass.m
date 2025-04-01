classdef resolutionsClass < handle
    % Resolutions are defined in a two-stage process. Firstly, we define the
    % actual fitted parameters. These resolution parameters are held in a ``parametersClass`` object 
    % and can be used define resolutions. 
    % 
    % For constant resolutions, only one resolution parameter is supplied. 
    % 
    % For data resolutions, there are no parameters supplied, but it informs RAT to expect a fourth 
    % column in the datafile. 
    %
    % Examples
    % --------
    % >>> resolutionParams = parametersClass('Resolution Parameter 1', 1e-8, 1e-5, 1e-3, true);
    % >>> resolution = resolutionClass(resolutionParams, {'Resolution 1','constant','Resolution Parameter 1'});
    %
    % Parameters
    % ----------
    % parameters : parameterClass
    %     The resolution parameters. 
    % startResolution : cell
    %     A cell array containing the properties for the first resolution.
    %
    % Attributes
    % ----------
    % resolutionParams : parameterClass
    %     The resolution parameters.
    % resolutions : multiTypeTable
    %     A custom table object that contains the resolution entries.
    properties   
       resolutionParams 
       resolutions
    end
    
    properties(Access = private, Constant, Hidden)
        invalidTypeMessage = sprintf('Allowed type must be a allowedTypes enum or one of the following strings (%s)', ...
                                     strjoin(allowedTypes.values(), ', '))
    end
    
    methods
        function  obj = resolutionsClass(parameters, startResolution)
            obj.resolutionParams = parameters;
            
            % Make a multiType table to define the actual resolutions
            obj.resolutions = multiTypeTable();
            obj.resolutions.typesAutoNameString = 'New Resolution';
            obj.addResolution(startResolution{:});
        end
        
        function names = getNames(obj)
            % Returns a N x 1 cell array of names of the resolutions in the object. 
            % 
            % Returns
            % -------
            % names : cell
            %     A cell array which contains the names of resolution entries.
            resolTable = obj.resolutions.varTable;
            names = resolTable{:,1};   
        end
         
        function addResolution(obj, name, type, source, value1, value2, value3, value4, value5)
            % Adds a new resolution to the resolution table. 
            %
            % Examples
            % --------
            % To add a new constant resolution with name only.
            % 
            % >>> resolution.addResolution('New Resolution');
            % 
            % To add a constant resolution.
            % 
            % >>> resolution.addResolution(New Resolution', 'constant', 'param name');
            %
            % To add a data resolution.
            % 
            % >>> resolution.addResolution('New Resolution', 'data');
            % 
            % Parameters
            % ----------
            % name : string or char array, default: auto-generated name
            %     The name of the resolution. 
            % type : allowedTypes, default: allowedTypes.Constant
            %     The type of resolution (constant or data).
            % source : string or char array, default: ''
            %     The source of the resolution. 
            %     if type is 'constant', this should be the name (or the row index) of a resolution parameter.
            %     if type is 'data', this should be empty. RAT will expect a fourth column in the datafile.
            % value1, value2, value3, value4, value5 : string or char array, default: ''
            %     Any extra values required by the resolution.
            %     if type is 'constant', all values will be ignored.
            %     if type is 'data', all values will be ignored.
            arguments
                obj
                name {mustBeTextScalar} = ''
                type = allowedTypes.empty()
                source {mustBeScalarTextOrWholeNumber} = ''
                value1 {mustBeScalarTextOrWholeNumber} = ''
                value2 {mustBeScalarTextOrWholeNumber} = ''
                value3 {mustBeScalarTextOrWholeNumber} = ''
                value4 {mustBeScalarTextOrWholeNumber} = ''
                value5 {mustBeScalarTextOrWholeNumber} = ''
            end
                       
            newRow = {};

            if ~isempty(name) && isempty(type)
                newRow = {name};
            elseif ~isempty(name) && ~isempty(type)
                newRow = {name, type, source, value1, value2, value3, value4, value5};
                newRow{2} = validateOption(type, 'allowedTypes', obj.invalidTypeMessage).value;
                
                if strcmpi(newRow{2}, allowedTypes.Constant.value) && isempty(source)
                    throw(exceptions.invalidNumberOfInputs(sprintf('For type ''%s'', at least three inputs are required, but only 2 are supplied', newRow{2})));
                end

                % Check that the other params inputted are either valid
                % resolution names, or numbers in range.
                switch newRow{2}
                    case allowedTypes.Constant.value
                        % Param 3 (source) must be a valid resolution parameter
                        newRow{3} = validateParameter(source, obj.resolutionParams.getNames(), 'Resolution Param');
                        if sum(~(cellfun(@(x) isequal(x,""), newRow))) > 3
                            warning('warnings:invalidNumberOfInputs', 'Value fields 1 - 5 are not required for type ''constant'' resolutions, they will not be included')
                        end
                        
                    case allowedTypes.Data.value
                        % Resolution is assumed to be given by a 4th column 
                        % of a data file, so no further parameters are
                        % required
                        if sum(~(cellfun(@(x) isequal(x,""), newRow))) > 3
                            warning('warnings:invalidNumberOfInputs', 'The Source and Value fields 1 - 5 are not required for type ''data'' resolutions, they will not be included')
                        end
                    case allowedTypes.Function.value
                        throw(exceptions.invalidOption('Function Resolutions are not yet supported!'));
                end
            end
            obj.resolutions.addRow(newRow{:});      
        end
        
        function removeResolution(obj, row)
            % Removes a resolution entry from the table.
            %
            % Examples
            % --------
            % To remove the second resolution in the table (resolution in row 2).  
            % 
            % >>> resolutions.removeResolution(2);
            % 
            % To remove resolution with a specific name.
            % 
            % >>> resolutions.removeResolution('Resolution 1');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the resolution to remove. If it is text, 
            %     it is the name of the resolution to remove.
            obj.resolutions.removeRow(row);
        end
        
        function setResolution(obj, row, options)
            % General purpose method for updating properties of an existing resolution.
            %
            % Examples
            % --------
            % To change the name and value of the second resolution in the table (resolution in row 2).
            % 
            % >>> resolutions.setResolution(2, name='Resolution 1', type='constant', source='param name');
            % 
            % To change the properties of a resolution called 'Resolution 1'.
            % 
            % >>> resolutions.setResolution('Resolution 1', name='New Resolution', type='data');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the resolution to update. If it is text, 
            %     it is the name of the resolution to update.
            % options
            %    Keyword/value pair to properties to update for the specific resolution.
            %       * name (char array or string, default: '') the new name of the resolution.
            %       * type (allowedTypes, default: allowedTypes.empty()) the type of resolution (constant or data).
            %       * source (char array or string, or whole number, default: '') the new source of the resolution.
            %       * value1, value2, value3, value4, value5 (char array or string or whole number, default: '') any extra values required for the resolution.
            arguments
                obj
                row
                options.name {mustBeTextScalar} = ''
                options.type = allowedTypes.empty()
                options.source {mustBeScalarTextOrWholeNumber} = ''
                options.value1 {mustBeScalarTextOrWholeNumber} = ''
                options.value2 {mustBeScalarTextOrWholeNumber} = ''
                options.value3 {mustBeScalarTextOrWholeNumber} = ''
                options.value4 {mustBeScalarTextOrWholeNumber} = ''
                options.value5 {mustBeScalarTextOrWholeNumber} = ''
            end
            
            % if isText(row)
            %     row = obj.resolutions.findRowIndex(row, obj.getNames(), 'Unrecognised resolution');
            % elseif isnumeric(row)
            %     count = obj.resolutions.rowCount;
            %     if (row < 1) || (row > count)
            %         throw(exceptions.indexOutOfRange(sprintf('The row index %d is not within the range 1 - %d', row, count)));
            %     end
            % else
            %     throw(exceptions.invalidType('Unrecognised row'));
            % end
            row = obj.resolutions.getValidRow(row);
            
            defaults = obj.resolutions.varTable{row, :};
            fields = fieldnames(options);
          
            if ~isempty(options.type)   
                options.type = validateOption(options.type, 'allowedTypes', obj.invalidTypeMessage).value;
                if strcmpi(options.type, allowedTypes.Function.value)
                    throw(exceptions.invalidOption('Function Resolutions are not yet supported!'));
                end
                % If the type of the resolution is changed, clear all
                % source and value fields
                if ~strcmpi(options.type, obj.resolutions.varTable{row, 2})
                    warning("warnings:fieldsCleared", "When changing the type of a resolution all unset fields are cleared");
                    defaults(3:end) = "";
                end
            end
            
            % Fill up empty options
            for i = 1:length(fields)
                if isempty(options.(fields{i}))
                    options.(fields{i}) =  defaults(i);
                end
            end

            % For data and function types, source is the data/function name
            source = convertStringsToChars(options.source);
            if ~isempty(source) 
                if strcmpi(options.type, allowedTypes.Constant.value)
                    source = validateParameter(source, obj.resolutionParams.getNames(), 'Resolution Param');
                elseif strcmpi(options.type, allowedTypes.Data.value)
                    source = '';
                    warning('warnings:invalidNumberOfInputs', 'The Source field is not required for type ''Data'' resolutions, they will be ignored by RAT')
                end
            end

            values = {options.value1, options.value2, options.value3, options.value4, options.value5};
            for i = 1:5
                value = convertStringsToChars(values{i});
                if ~isempty(value)
                    values{i} = validateParameter(value, obj.resolutionParams.getNames(), 'Resolution Param');
                    if ~strcmpi(options.type, allowedTypes.Function.value)
                        values = {'', '', '', '', ''};
                        warning('warnings:invalidNumberOfInputs', 'Value fields 1 - 5 are not required for type ''%s'' resolutions, they will be ignored by RAT', options.type)
                        break
                    end
                end
            end

            % Validation is done, so set the fields to the new values
            obj.resolutions.setValue(row, 1, options.name);
            obj.resolutions.setValue(row, 2, options.type);
            obj.resolutions.setValue(row, 3, source);
            for i = 1:5
                obj.resolutions.setValue(row, i + 3, convertStringsToChars(values{i}));
            end
        end

        function obj = setResolutionName(obj, row, name)
            % Sets the name of a given resolution in the table. 
            %
            % Examples
            % --------
            % To change the name of the second resolution in the table (resolution in row 2)
            % 
            % >>> resolutions.setResolutionName(2, 'new name');
            % 
            % To change the name of a resolution called 'old name' to 'new name'
            % 
            % >>> resolutions.setResolutionName('old name', 'new name');
            %
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the resolution to update. If it is text, 
            %     it is the name of the resolution to update.
            % name : string or char array
            %     The new name of the resolution.
            if ~isText(name)
                throw(exceptions.invalidType(sprintf('%s must be a character array or string', name)));
            end
            obj.resolutions.setValue(row, 'name', name);
        end
        
        function resolutionStruct = toStruct(obj)
            % Converts the resolutionClass into a structure array.
            %
            % Returns
            % -------
            % resolutionStruct : struct
            %     A struct which contains the properties for all the resolutions and resolution parameters.
            resolutionParamsStruct = obj.resolutionParams.toStruct();
            
            resolutionStruct.resolutionParamNames = resolutionParamsStruct.names;
            resolutionStruct.resolutionParamLimits = resolutionParamsStruct.limits;
            resolutionStruct.resolutionParamValues = resolutionParamsStruct.values;
            resolutionStruct.fitResolutionParam = resolutionParamsStruct.fit;
            resolutionStruct.resolutionParamPriors = resolutionParamsStruct.priors;
            
            resolutionNames = obj.resolutions.varTable{:,1};
            resolutionTypes = obj.resolutions.varTable{:,2};
            resolutionValues = table2cell(obj.resolutions.varTable(:,3:width(obj.resolutions.varTable)));
            
            resolutionStruct.resolutionNames = resolutionNames;
            resolutionStruct.resolutionTypes = resolutionTypes;
            resolutionStruct.resolutionValues = resolutionValues;  
         end
        
        function  displayTable(obj, showPriors)
            % Prints the resolutions and resolution parameters tables to the console.
            %
            % Examples
            % --------
            % To print the resolution parameters table with the prior information.
            % 
            % >>> resolutions.displayTable(true);
            %
            % Parameters
            % ----------
            % showPriors : logical, default: false
            %     Indicates if the prior type, mu, and sigma columns in the resolution parameters table should be displayed.
            
            arguments
                obj
                showPriors {mustBeA(showPriors, 'logical')} = false
            end
            fprintf('    (a) Resolutions Parameters: \n\n');
            obj.resolutionParams.displayTable(showPriors);
            
            fprintf('    (b) Resolutions:  \n\n')
            obj.resolutions.displayTable;
        end 
    end
end 
