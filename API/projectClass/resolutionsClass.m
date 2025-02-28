classdef resolutionsClass < handle
    % Resolutions are defined in a two stage process. Firstly we define the
    % actual fitted parameters. These are held in a 'ParametersClass'
    % table. Then, we group these into the resolutions themselves using a
    % multiTypeTable. So, we can then use the resolution parameters to
    % either define resolution as  constant, data or a function. 
    % 
    % For constant only one parameter is supplied to multi type table. 
    % 
    % For data the name is supplied, along with the name of the data in the 
    % data table. 
    % 
    % For function, the function name is supplied, along with up to three parameters (from the
    % parameters table) which are then supplied to the function to calculate the resolution. 
    
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
            % Creates a Resolutions object. The arguments should be 
            % an instance of the parameter class with the resolution parameters and a
            % cell array with the first resolution entry
            %
            % params = parametersClass({'Resolution Param 1', 0.01, 0.03, 0.05, false});
            % resolution = resolutionsClass(params, {'Resolution 1', 'constant', 'Tails'});
            obj.resolutionParams = parameters;
            
            % Make a multiType table to define the actual resolutions
            obj.resolutions = multiTypeTable();
            obj.resolutions.typesAutoNameString = 'New Resolution';
            obj.addResolution(startResolution{:});
        end
        
        function names = getNames(obj)
            % Returns a N x 1 cell array of names of the resolutions 
            % in the object. 
            % 
            % names = resolution.getNames();
            resolTable = obj.resolutions.varTable;
            names = resolTable{:,1};   
        end
         
        function addResolution(obj, varargin)
            % Adds a new entry to the resolution table.  
            %
            % resolution.addResolution('New Row');
            % resolution.addResolution('New Row', 'constant', 'param_name');
            % resolution.addResolution('New Row', 'function', 'function_name', 'param_name');
            % resolution.addResolution('New Row', 'data');
            in = varargin;
            
            if isempty(in)
                newRow = {};
            else
                newRow = {'','','','','','',''}; 
                if length(in) == 1
                    % Assume the input is just a name
                    newRow = {in};
                else
                    newRow{1} = in;
                end
            end
            
            if length(in) > 1 
               % Check that second param is legal
               typeVal = validateOption(in{2}, 'allowedTypes', obj.invalidTypeMessage).value;

               if any(strcmpi(typeVal, {allowedTypes.Constant.value, allowedTypes.Function.value})) && length(in) < 3
                   throw(exceptions.invalidNumberOfInputs(sprintf('For type ''%s'', at least three inputs are required, but only %d are supplied', typeVal, length(in))));
               end

               newRow{1} = in{1};
               newRow{2} = in{2};

               % Check that the other params inputted are either valid
               % resolution names, or numbers in range..
               switch typeVal
                   case allowedTypes.Constant.value
                       % Param 3 (source) must be a valid resolution parameter
                       newRow{3} = validateParameter(in{3}, obj.resolutionParams.getNames(), 'Resolution Param');
                       if sum(~(cellfun(@(x) isequal(x,""), in))) > 3
                           warning('warnings:invalidNumberOfInputs', 'Value fields 1 - 5 are not required for type ''constant'' resolutions, they will not be included')
                       end
                       
                   case allowedTypes.Data.value
                       % Resolution is assumed to be given by a 4th column 
                       % of a data file, so no further parameters are
                       % required
                       if sum(~(cellfun(@(x) isequal(x,""), in))) > 3
                           warning('warnings:invalidNumberOfInputs', 'The Source and Value fields 1 - 5 are not required for type ''data'' resolutions, they will not be included')
                       end
               end

            end
            obj.resolutions.addRow(newRow{:});      
        end
        
        function removeResolution(obj, row)
            % Removes a resolution entry from the table. Expects the 
            % index or array of indices of resolution(s) to remove.
            %
            % resolution.removeResolution(2);
            % resolution.removeResolution([1, 3]);
            obj.resolutions.removeRow(row);
        end
        
        function setResolution(obj, row, varargin)
            % Changes the value of a given resolution in the table. Expects the 
            % index or name of resolution and keyword/value pairs to set. 
            %
            % resolution.setResolution(1, 'name', 'resolution 1', 'type', 'constant', 'source', 'param_name');
            if isText(row)
                row = obj.resolutions.findRowIndex(row, obj.getNames(), 'Unrecognised resolution');
            elseif isnumeric(row)
                count = obj.resolutions.rowCount;
                if (row < 1) || (row > count)
                    throw(exceptions.indexOutOfRange(sprintf('The row index %d is not within the range 1 - %d', row, count)));
                end
            else
                throw(exceptions.invalidType('Unrecognised row'));
            end
            
            inputBlock = obj.makeInputBlock(row, varargin{:});
            
            if ~isempty(inputBlock.type)
                inputBlock.type = validateOption(inputBlock.type, 'allowedTypes', obj.invalidTypeMessage).value;
                                
                % If the type of the resolution is changed, clear all
                % source and value fields
                if ~strcmpi(inputBlock.type, obj.resolutions.varTable{row, 2})
                    warning('warnings:fieldsCleared', "When changing the type of a resolution all unset fields are cleared");
                    for i = 3:width(obj.resolutions.varTable)
                        obj.resolutions.setValue(row, i, '');
                    end

                    % Having cleared the table, we need to re-parse the
                    % inputs to the function
                    inputBlock = obj.makeInputBlock(row, varargin{:});
                end
            end

            % For data and function types, source is the data/function name
            source = convertStringsToChars(inputBlock.source);
            if ~isempty(source) 
                if strcmpi(inputBlock.type, allowedTypes.Constant.value)
                    source = validateParameter(source, obj.resolutionParams.getNames(), 'Resolution Param');
                elseif strcmpi(inputBlock.type, allowedTypes.Data.value)
                    warning('warnings:invalidNumberOfInputs', 'The Source field is not required for type ''Data'' resolutions, they will be ignored by RAT')
                end
            end

            values = {inputBlock.value1, inputBlock.value2, inputBlock.value3, inputBlock.value4, inputBlock.value5};
            for i = 1:5
                value = convertStringsToChars(values{i});
                if ~isempty(value)
                    validateParameter(value, obj.resolutionParams.getNames(), 'Resolution Param');
                    warning('warnings:invalidNumberOfInputs', 'Value fields 1 - 5 are not required for type ''%s'' backgrounds, they will be ignored by RAT', inputBlock.type)
                    break
                end
            end

            % Validation is done, so set the  fields to the new values
            obj.resolutions.setValue(row, 1, inputBlock.name);
            obj.resolutions.setValue(row, 2, inputBlock.type);
            obj.resolutions.setValue(row, 3, source);
            for i = 1:5
                obj.resolutions.setValue(row, i + 3, convertStringsToChars(values{i}));
            end
        end

        function obj = setResolutionName(obj, row, name)
            % Sets the name of a given resolution in the table. Expects 
            % an index and the new name. 
            %
            % resolution.setResolutionName(1, 'new_name');
            if ~isText(name)
                throw(exceptions.invalidType(sprintf('%s must be a character array or string', name)));
            end
            obj.resolutions.setValue(row, 'name', name);
        end
        
        function resolutionStruct = toStruct(obj)
            % Converts the class parameters into a structure array.
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
        
        function displayResolutionsObject(obj, showPriors)
            % Displays the resolution parameters and resolution table.
            % Optional showPriors to display the priors default is false
            %
            % resolution.displayResolutionsObject(true);
            arguments
                obj
                showPriors {logical} = false
            end
            fprintf('    (a) Resolutions Parameters: \n\n');
            obj.resolutionParams.displayTable(showPriors);
            
            fprintf('    (b) Resolutions:  \n\n')
            obj.resolutions.displayTable;
        end 
    end

    methods (Access = private)
        function inputBlock = makeInputBlock(obj, row, varargin)
            % Parses the input arguments.
            %
            % param = obj.makeInputBlock(1, 'name', 'back 1', 'type', 'constant', 'source', 'param_name');
            p = inputParser;
            p.PartialMatching = false;
            addParameter(p, 'name', obj.resolutions.varTable{row, 1}, @isText);
            addParameter(p, 'type', obj.resolutions.varTable{row, 2}, @(x) isText(x) || isenum(x));
            addParameter(p, 'source', obj.resolutions.varTable{row, 3}, @isText);
            addParameter(p, 'value1', obj.resolutions.varTable{row, 4}, @isText);
            addParameter(p, 'value2', obj.resolutions.varTable{row, 5}, @isText);
            addParameter(p, 'value3', obj.resolutions.varTable{row, 6}, @isText);
            addParameter(p, 'value4', obj.resolutions.varTable{row, 7}, @isText);
            addParameter(p, 'value5', obj.resolutions.varTable{row, 8}, @isText);

            parse(p, varargin{:});
            inputBlock = p.Results;
        end
    end
end 
