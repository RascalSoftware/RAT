classdef backgroundsClass < handle
    % Backgrounds are defined in a two-stage process. Firstly, we define the
    % actual fitted parameters. These background parameters are held in a ``parametersClass`` object 
    % and can be used define backgrounds as constant, data or a function. 
    % 
    % For constant backgrounds, only one background parameter is supplied. 
    % 
    % For data backgrounds, an entry in the data table and an optional offset is
    % required
    % 
    % For function, the function name is supplied, along with up to five
    % parameters (from the background parameters table) which are then
    % passed to the function to calculate the background. 
    %
    % In each case, the background can either be added to the simulation or
    % subtracted from the data.
    %
    % Examples
    % --------
    % >>> allowedNames = project.getAllAllowedNames();
    % >>> backgroundParams = parametersClass('Background Parameter SMW', 1e-8, 1e-5, 1e-3, true);
    % >>> background = backgroundClass(backgroundParams, {'Background SMW','constant','Background Parameter SMW'}, allowedNames);
    %
    % Parameters
    % ----------
    % parameters : parameterClass
    %     The background parameters. 
    % startBackground : cell
    %     A cell array containing the properties for the first background.
    % allowedNames : struct
    %     A struct containing the valid names of data, and custom files that can be referenced in the background.
    %
    % Attributes
    % ----------
    % backgroundParams : parameterClass
    %     The background parameters.
    % backgrounds : multiTypeTable
    %     A custom table object that contains the background entries.
    properties
       backgroundParams 
       backgrounds
    end

    properties(Access = private, Constant, Hidden)
        maxValues = struct('constant', 0, 'data', 1, 'function', 5)
        invalidTypeMessage = sprintf('Allowed type must be a allowedTypes enum or one of the following strings (%s)', ...
                                     strjoin(allowedTypes.values(), ', '))
    end
    
    methods
        function  obj = backgroundsClass(parameters, startBackground, allowedNames)
            obj.backgroundParams = parameters;
            
            % Make a multiType table to define the actual backgrounds
            obj.backgrounds = multiTypeTable();
            obj.backgrounds.typesAutoNameString = 'New background';
            obj.addBackground(allowedNames, startBackground{:});
        end
        
        function names = getNames(obj)
            % Returns a N x 1 cell array of names of the backgrounds in the object. 
            % 
            % Returns
            % -------
            % names : cell
            %     A cell array which contains the names of background entries.
            names = obj.backgrounds.varTable{:,1};      
        end
                 
        function obj = addBackground(obj, allowedNames, name, type, source, value1, value2, value3, value4, value5)
            % Adds a new background to the background table. 
            %
            % Examples
            % --------
            % To add a new constant background with name only.
            % 
            % >>> allowedNames = project.getAllAllowedNames();
            % >>> background.addBackground(allowedNames, 'New Background');
            % 
            % To add a constant background.
            % 
            % >>> background.addBackground(allowedNames, 'New Background', 'constant', 'param name');
            % 
            % To add a function background with 2 parameters.
            % 
            % >>> background.addBackground(allowedNames, 'New Background', 'function', 'function name', 'param name', 'param name 2');    
            %
            % To add a data background with an offset.
            % 
            % >>> background.addBackground(allowedNames, 'New Background', 'data', 'data name', 'offset param name');
            % 
            % Parameters
            % ----------
            % allowedNames: struct
            %     A struct containing the valid names of data, and custom files that can be referenced in the background.
            % name : string or char array, default: auto-generated name
            %     The name of the background. 
            % type : allowedTypes, default: allowedTypes.Constant
            %     The type of background (constant, function or data).
            % source : string or char array or whole number, default: ''
            %     The source of the background. 
            %     if type is 'constant', this should be the name (or the row index) of a background parameter.
            %     if type is 'data', this should be the name (or the row index) of a dataset defined in `projectClass.data`.
            %     if type is 'function', this should be the name (or the row index) of a custom function defined in `projectClass.customFiles`.
            % value1, value2, value3, value4, value5 : string or char array or whole number, default: ''
            %     Any extra values required for the background.
            %     if type is 'constant', all values will be ignored.
            %     if type is 'data', value1 may be the name (or the row index) of a background parameter for an optional offset. Other values are ignored.
            %     if type is 'function', these values may be the names (or the row index) of up to 5 parameters which are passed to the function.
            arguments
                obj
                allowedNames {mustBeA(allowedNames, 'struct')}
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
                if isempty(source)
                    throw(exceptions.invalidNumberOfInputs(sprintf('For type ''%s'', at least three inputs are required, source must be provided', newRow{2})));
                end

               % Check that the other params inputted are either valid
               % background names, or numbers in range
               switch newRow{2}
                   case allowedTypes.Constant.value
                       % Param 3 (source) must be a valid background parameter
                       newRow{3} = validateParameter(source, obj.backgroundParams.getNames(), 'Background Param');


                   case allowedTypes.Data.value
                       % Background is contained within a data file.
                       newRow{3} = validateParameter(source, allowedNames.dataNames, 'Data');
                       % We also allow for an optional data offset
                       if ~isempty(value1)
                           newRow{4} = validateParameter(value1, obj.backgroundParams.getNames(), 'Background Param');
                       end


                   case allowedTypes.Function.value
                       % Param 3 (source) is the function name, defined in
                       % the custom files table
                       newRow{3} = validateParameter(source, allowedNames.customFileNames, 'Custom File');

                       if ~isempty(value1)
                           % Any other given parameters must be valid
                           % background parameters
                           params = newRow(4:end);
                           params = params(~(cellfun(@(x) isequal(x,""), params)));
                           for i = 1:length(params)
                              thisParam = validateParameter(params{i}, obj.backgroundParams.getNames(), 'Background Param');
                              newRow{i+3} = thisParam;
                           end
                       end
               end

               % Check number of non-empty values
               if sum(~(cellfun(@(x) isequal(x,""), newRow))) > obj.maxValues.(newRow{2}) + 3
                   warning('warnings:invalidNumberOfInputs', 'Value fields %d - 5 are not required for type ''%s'' backgrounds, they will not be included', obj.maxValues.(newRow{2}) + 1, newRow{2})
               end

            end
            obj.backgrounds.addRow(newRow{:});   
        end
        
        function obj = removeBackground(obj, row)
            % Removes a background entry from the table.
            %
            % Examples
            % --------
            % To remove the second background in the table (background in row 2).  
            % 
            % >>> backgrounds.removeBackground(2);
            % 
            % To remove background with a specific name.
            % 
            % >>> backgrounds.removeBackground('Background 1');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the background to remove. If it is text, 
            %     it is the name of the background to remove.
            obj.backgrounds.removeRow(row);
        end
        
        function obj = setBackground(obj, row, allowedNames, options)
            % General purpose method for updating properties of an existing background.
            %
            % Examples
            % --------
            % To change the name and value of the second background in the table (background in row 2).
            % 
            % >>> allowedNames = project.getAllAllowedNames();
            % >>> backgrounds.setBackground(2, allowedNames, name='Background 1', type='constant', source='param name');
            % 
            % To change the properties of a background called 'Background 1'.
            % 
            % >>> backgrounds.setBackground('Background 1', allowedNames, name='New Background', type='function', source='custom file name', value1='param name');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the background to update. If it is text, 
            %     it is the name of the background to update.
            % allowedNames: struct
            %     A struct containing the valid names of data, and custom files that can be referenced in the background.
            % options
            %    Keyword/value pair to properties to update for the specific background.
            %       * name (char array or string, default: '') the new name of the background.
            %       * type (allowedTypes, default: allowedTypes.empty()) the type of background (constant, function or data).
            %       * source (char array or string or whole number, default: '') the new source of the background.
            %       * value1, value2, value3, value4, value5 (char array or string or whole number, default: '') any extra values required for the background.
            arguments
                obj
                row
                allowedNames {mustBeA(allowedNames, 'struct')}
                options.name {mustBeTextScalar} = ''
                options.type = allowedTypes.empty()
                options.source {mustBeScalarTextOrWholeNumber} = ''
                options.value1 {mustBeScalarTextOrWholeNumber} = ''
                options.value2 {mustBeScalarTextOrWholeNumber} = ''
                options.value3 {mustBeScalarTextOrWholeNumber} = ''
                options.value4 {mustBeScalarTextOrWholeNumber} = ''
                options.value5 {mustBeScalarTextOrWholeNumber} = ''
            end
            row = obj.backgrounds.getValidRow(row);
            defaults = obj.backgrounds.varTable{row, :};
            fields = fieldnames(options);
          
            if ~isempty(options.type)   
                options.type = validateOption(options.type, 'allowedTypes', obj.invalidTypeMessage).value; 
                % If the type of the background is changed, clear all
                % source and value fields
                if ~strcmpi(options.type, obj.backgrounds.varTable{row, 2})
                    warning("warnings:fieldsCleared", "When changing the type of a background all unset fields are cleared");
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
                    source = validateParameter(source, obj.backgroundParams.getNames(), 'Background Param');
                end
                if strcmpi(options.type, allowedTypes.Data.value)
                    source = validateParameter(source, allowedNames.dataNames, 'Data');
                end
                if strcmpi(options.type, allowedTypes.Function.value)
                    source = validateParameter(source, allowedNames.customFileNames, 'Custom File');
                end
            end

            values = {options.value1, options.value2, options.value3, options.value4, options.value5};
            for i = 1:5
                value = convertStringsToChars(values{i});
                if ~isempty(value)
                    values{i} = validateParameter(value, obj.backgroundParams.getNames(), 'Background Param');
                    if i > obj.maxValues.(options.type)
                        warning('warnings:invalidNumberOfInputs', 'Value fields %d - 5 are not required for type ''%s'' backgrounds, they will be ignored by RAT', obj.maxValues.(options.type) + 1, options.type)
                        break
                    end
                end
            end

            % Validation is done, so set the fields to the new values
            obj.backgrounds.setValue(row, 1, options.name);
            obj.backgrounds.setValue(row, 2, options.type);
            obj.backgrounds.setValue(row, 3, source);
            for i = 1:5
                obj.backgrounds.setValue(row, i + 3, convertStringsToChars(values{i}));
            end

        end
         
        function obj = setBackgroundName(obj, row, name)
            % Sets the name of a given background in the table. 
            %
            % Examples
            % --------
            % To change the name of the second background in the table (background in row 2)
            % 
            % >>> backgrounds.setBackgroundName(2, 'new name');
            % 
            % To change the name of a background called 'old name' to 'new name'
            % 
            % >>> backgrounds.setBackgroundName('old name', 'new name');
            %
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the background to update. If it is text, 
            %     it is the name of the background to update.
            % name : string or char array
            %     The new name of the background.
            arguments
                obj
                row
                name {mustBeTextScalar}
            end
            obj.backgrounds.setValue(row, 'name', name);
        end

        function displayTable(obj, showPriors)
            % Prints the backgrounds and background parameters tables to the console.
            %
            % Examples
            % --------
            % To print the background parameters table with the prior information.
            % 
            % >>> backgrounds.displayTable(true);
            %
            % Parameters
            % ----------
            % showPriors : logical, default: false
            %     Indicates if the prior type, mu, and sigma columns in the background parameters table should be displayed.
            arguments
                obj
                showPriors {mustBeA(showPriors, 'logical')} = false
            end
            fprintf('    (a) Background Parameters: \n\n');
            obj.backgroundParams.displayTable(showPriors);
            
            fprintf('    (b) Backgrounds:  \n\n')
            obj.backgrounds.displayTable;
        end
        
        function backgroundStruct = toStruct(obj)
            % Converts the backgroundClass into a structure array.
            %
            % Returns
            % -------
            % backgroundStruct : struct
            %     A struct which contains the properties for all the backgrounds and background parameters.
            backgroundParamsStruct = obj.backgroundParams.toStruct();
            
            backgroundStruct.backgroundParamNames = backgroundParamsStruct.names;
            backgroundStruct.backgroundParamLimits = backgroundParamsStruct.limits;
            backgroundStruct.backgroundParamValues = backgroundParamsStruct.values;
            backgroundStruct.fitBackgroundParam = backgroundParamsStruct.fit;
            backgroundStruct.backgroundParamPriors = backgroundParamsStruct.priors;
            
            backgroundNames = obj.backgrounds.varTable{:,1};
            backgroundTypes = obj.backgrounds.varTable{:,2};
            backgroundValues = table2cell(obj.backgrounds.varTable(:,3:width(obj.backgrounds.varTable)));
            
            backgroundStruct.backgroundNames = backgroundNames;
            backgroundStruct.backgroundTypes = backgroundTypes;
            backgroundStruct.backgroundValues = backgroundValues;
        end
    end
end
