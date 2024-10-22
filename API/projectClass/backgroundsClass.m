classdef backgroundsClass < handle
    % Backgrounds are defined in a two stage process. Firstly we define the
    % actual fitted parameters. These are held in a 'ParametersClass'
    % table. Then, we group these into the backgrounds themselves using a
    % multiTypeTable. So, we can then use the background parameters to
    % either define background as constant, data or a function. 
    % 
    % For constant only one background parameter is supplied to multi type table. 
    % 
    % For data an entry in the data table and an optional offset is
    % required
    % 
    % For function, the function name is supplied, along with up to five
    % parameters (from the background parameters table) which are then
    % supplied to the function to calculate the background. 
    %
    % In each case, the background can either be added to the simulation or
    % subtracted from the data.
    
    properties
       backgroundParams 
       backgrounds
    end

    properties(Access = private, Constant, Hidden)
        invalidTypeMessage = sprintf('Allowed type must be a allowedTypes enum or one of the following strings (%s)', ...
                                     strjoin(allowedTypes.values(), ', '))
    end
    
    methods
        function  obj = backgroundsClass(parameters, startBackground)
            % Creates a background object. The arguments should be 
            % an instance of the parameter class with the background parameters
            % and a cell array of  backgrounds
            %
            % params = parametersClass({'Background Param 1', 1e-7, 1e-6, 1e-5, false, 'uniform', 0, Inf});
            % background = backgroundClass(params, {'Background 1', 'constant', 'Background Param 1'});
            obj.backgroundParams = parameters;
            
            % Make a multiType table to define the actual backgrounds
            obj.backgrounds = multiTypeTable();
            obj.backgrounds.typesAutoNameString = 'New background';
            obj.addBackground(startBackground{:});
        end
        
        function names = getNames(obj)
            % Returns a N x 1 cell array of names of the backgrounds 
            % in the object. 
            % 
            % names = background.getNames();
            names = obj.backgrounds.varTable{:,1};      
        end
                 
        function obj = addBackground(obj, varargin)
            % Adds a new entry to the background table.  
            %
            % background.addBackground('New Row');
            % background.addBackground('New Row', 'constant', 'param_name');
            % background.addBackground('New Row', 'function', 'function_name', 'param_name');
            % background.addBackground('New Row', 'data', 'data name', 'offset');
            in = varargin;

            if isempty(in)
                newRow = {};
            else
                newRow = {'','','','','','','',''};
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
               % background names, or numbers in range
               switch typeVal
                   case allowedTypes.Constant.value
                       % Param 3 (source) must be a valid background parameter
                       newRow{3} = obj.validateParam(in(3));

                   case allowedTypes.Function.value
                       % Param 3 (source) is assumed to be function name - should
                       % there be validation here??
                       newRow{3} = in{3};

                       % any other given parameters must valid background
                       % parameters
                       for i = 4:length(in)
                          thisParam = obj.validateParam(in(i));
                          newRow{i} = thisParam;
                       end

                   case allowedTypes.Data.value
                       % Background is contained within a data file.
                       % We don't have access to the data files at this
                       % point so this will be checked downstream.
                       % We also allow for an optional data offset
                       newRow{3} = in{3};
                       if length(in) >= 4
                           newRow{4} = obj.validateParam(in(4));
                       end
                end
            end
            obj.backgrounds.addRow(newRow{:});   
        end
        
        function obj = removeBackground(obj, row)
            % Removes a background entry from the table. Expects the 
            % index or array of indices of background(s) to remove.
            %
            % background.removeBackground(2);
            % background.removeBackground([1, 3]);
            obj.backgrounds.removeRow(row);
        end
        
        function obj = setBackground(obj, row, varargin)
            % Changes the value of a given background in the table. Expects the 
            % index or name of background and keyword/value pairs to set. 
            %
            % background.setBackground(1, 'name', 'back 1', 'type', 'constant', 'source', 'param_name');
            if isText(row)
                row = obj.backgrounds.findRowIndex(row, obj.getNames(), 'Unrecognised background');
            elseif isnumeric(row)
                count = obj.backgrounds.rowCount;
                if (row < 1) || (row > count)
                    throw(exceptions.indexOutOfRange(sprintf('The row index %d is not within the range 1 - %d', row, count)));
                end
            else
                throw(exceptions.invalidType('Unrecognised row'));
            end
            
            p = inputParser;
            addParameter(p, 'name', obj.backgrounds.varTable{row, 1}, @isText);
            addParameter(p, 'type', obj.backgrounds.varTable{row, 2}, @(x) isText(x) || isenum(x));
            addParameter(p, 'source', obj.backgrounds.varTable{row, 3}, @isText);
            addParameter(p, 'value1', obj.backgrounds.varTable{row, 4}, @isText);
            addParameter(p, 'value2', obj.backgrounds.varTable{row, 5}, @isText);
            addParameter(p, 'value3', obj.backgrounds.varTable{row, 6}, @isText);
            addParameter(p, 'value4', obj.backgrounds.varTable{row, 7}, @isText);
            addParameter(p, 'value5', obj.backgrounds.varTable{row, 8}, @isText);

            parse(p, varargin{:});
            inputBlock = p.Results;

            obj.backgrounds.setValue(row, 1, inputBlock.name);
            
            if ~isempty(inputBlock.type)
                inputBlock.type = validateOption(inputBlock.type, 'allowedTypes', obj.invalidTypeMessage).value;
                obj.backgrounds.setValue(row, 2, inputBlock.type);
            end

            % For data and function types, source is the data/function name so no validation is done
            source = convertStringsToChars(inputBlock.source);
            if ~isempty(source) && strcmpi(inputBlock.type, allowedTypes.Constant.value)
                source = obj.validateParam(source);
            end
            obj.backgrounds.setValue(row, 3, source);

            values = {inputBlock.value1, inputBlock.value2, inputBlock.value3, inputBlock.value4, inputBlock.value5};
            for i = 1:5
                value = convertStringsToChars(values{i});
                if ~isempty(value)
                    value = obj.validateParam(value);
                end
                obj.backgrounds.setValue(row, i + 3, value);
            end
        end
         
        function obj = setBackgroundName(obj, row, name)
            % Sets the name of a given background in the table. Expects 
            % an index and the new name. 
            %
            % background.setBackgroundName(1, 'new_name');
            if ~isText(name)
                throw(exceptions.invalidType(sprintf('%s must be a character array or string', name)));
            end
            obj.backgrounds.setValue(row, 'name', name);
        end

        function displayBackgroundsObject(obj, showPriors)
            % Displays the background parameters and background table. 
            % Optional showPriors to display the priors default is false
            %
            % background.displayBackgroundsObject(true);
            arguments
                obj
                showPriors {logical} = false
            end
            fprintf('    (a) Background Parameters: \n\n');
            obj.backgroundParams.displayTable(showPriors);
            
            fprintf('    (b) Backgrounds:  \n\n')
            obj.backgrounds.displayTable;
        end
        
        function backgroundStruct = toStruct(obj)
            % Converts the class parameters into a structure array
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

    methods (Access = protected)
        function thisPar = validateParam(obj, param)
            % Checks that given parameter index or name is valid, then returns the
            % parameter name. 
            %
            % param = obj.validateParam('param_name');
            if iscell(param)
                param = param{:};
            end
            parList = obj.backgroundParams.getNames();
            if isnumeric(param)
                if (param < 1) || (param > length(parList))
                    throw(exceptions.indexOutOfRange(sprintf('Background Parameter %d is out of range', param)));
                else
                    thisPar = parList(param);
                end
            elseif isText(param)
                if ~strcmpi(param, parList)
                    throw(exceptions.nameNotRecognised(sprintf('Unrecognised parameter name %s', param)));
                else
                    thisPar = param;
                end
            end
        end
    end
end
