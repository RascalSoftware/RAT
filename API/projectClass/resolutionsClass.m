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
       resolPars 
       resolutions
    end

    properties(Dependent)
       showPriors
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
            % params = parametersClass({'Resolution par 1', 0.01, 0.03, 0.05, false});
            % resolution = resolutionsClass(params , {'Resolution 1', 'constant', 'Tails'});
            obj.resolPars = parameters;
            
            % Make a multiType table to define the actual resolutions
            obj.resolutions = multiTypeTable();
            obj.resolutions.typesAutoNameString = 'New Resolution';
            obj.addResolution(startResolution{:});
        end
        
        function flag = get.showPriors(obj)
            flag = obj.resolPars.showPriors;
        end
        
        function set.showPriors(obj, value)
            obj.resolPars.showPriors = value;
        end
        
        function names = getResolNames(obj)
            % Returns a N x 1 cell array of names of the resolutions 
            % in the object. 
            % 
            % names = resolution.getResolNames();
            resolTable = obj.resolutions.typesTable;
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
                thisRow = {};
            else
                thisRow = {'','','','','','',''}; 
                if length(in) == 1
                    % Assume the input is just a name
                    thisRow = {in};
                else
                    thisRow{1} = in;
                end
            end
            
            if length(in) > 1 
               % Check that second param is legal
               typeVal = validateOption(in{2}, 'allowedTypes', obj.invalidTypeMessage).value;

               if any(strcmpi(typeVal, {allowedTypes.Constant.value, allowedTypes.Function.value})) && length(in) < 3
                   throw(invalidNumberOfInputs(sprintf('For type ''%s'', at least three inputs are required, but only %d are supplied', typeVal, length(in))));
               end

               thisRow{1} = in{1};
               thisRow{2} = in{2};

               % Check that the other params inputted are either valid
               % resolution names, or numbers in range..
               switch typeVal
                   case allowedTypes.Constant.value
                       % Param 3 must be a valid parameter
                       thisParam = obj.validateParam(in(3));
                       thisRow{3} = thisParam;

                   case allowedTypes.Function.value
                       % Param 3 is assumed to be function name
                       % any other given parameters must be in paramNames
                       % list or numbers in range
                       thisRow{3} = in{3};
                       for i = 4:length(in)
                          thisParam = obj.validateParam(in(i));
                          thisRow{i} = thisParam;
                       end
                       
                   case allowedTypes.Data.value
                       % Resolution is assumed to be given by a 4th column 
                       % of a data file. We don't have access to the
                       % data files at this point so this (i.e. that data is
                       % [n x 4] ) will be checked downstream
                       thisRow = {in{1}, in{2}, '', '', '', '', ''};
                end
            end
            obj.resolutions.addRow(thisRow);      
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
            % resolution.setResolution(1, 'name', 'res 1', 'type', 'constant', 'value1', 'param_name');
            if ischar(row)
                row = obj.resolutions.findRowIndex(row, obj.getResolNames());
            elseif isnumeric(row)
                count = obj.resolutions.typesCount;
                if (row < 1) || (row > count)
                    throw(indexOutOfRange(sprintf('The row index %d is not within the range 1 - %d', row, count)));
                end
            else
                throw(invalidType('Unrecognised row'));
            end
            
            p = inputParser;
            addParameter(p, 'name', obj.resolutions.typesTable{row, 1}, @(x) isText(x));
            addParameter(p, 'type', obj.resolutions.typesTable{row, 2}, @(x) isText(x) || isenum(x));
            addParameter(p, 'value1', obj.resolutions.typesTable{row, 3}, @(x) isText(x));
            addParameter(p, 'value2', obj.resolutions.typesTable{row, 4}, @(x) isText(x));
            addParameter(p, 'value3', obj.resolutions.typesTable{row, 5}, @(x) isText(x));
            addParameter(p, 'value4', obj.resolutions.typesTable{row, 6}, @(x) isText(x));

            parse(p, varargin{:});
            inputBlock = p.Results;

            obj.resolutions.setValue(row, 1, inputBlock.name);
            
            if ~isempty(inputBlock.type)
                inputBlock.type = validateOption(inputBlock.type, 'allowedTypes', obj.invalidTypeMessage).value;
                obj.resolutions.setValue(row, 2, inputBlock.type);
            end    
            values = {inputBlock.value1, inputBlock.value2, inputBlock.value3, inputBlock.value4};
            for i = 1:4
                value = convertStringsToChars(values{i});
                % for function type, value 1 is the function name so no validation is done 
                if ~isempty(value) && ~(i==1 && strcmpi(inputBlock.type,allowedTypes.Function.value))
                    value = obj.validateParam(value);
                end
                obj.resolutions.setValue(row, i + 2, value);
            end
        end
        
        function resolStruct = toStruct(obj)
            % Converts the class parameters into a structure array.
            resolParamsStruct = obj.resolPars.toStruct();
            
            resolStruct.resolParNames = resolParamsStruct.paramNames;
            resolStruct.resolParConstr = resolParamsStruct.paramConstr;
            resolStruct.resolPars = resolParamsStruct.params;
            resolStruct.resolFitYesNo = resolParamsStruct.fitYesNo;
            resolStruct.nResolPars = resolParamsStruct.nParams;
            resolStruct.resolParPriors = resolParamsStruct.priors;
            
            resolutionNames = obj.resolutions.typesTable{:,1};
            resolutionTypes = obj.resolutions.typesTable{:,2};
            resolutionValues = table2cell(obj.resolutions.typesTable(:,3:7));
            
            resolStruct.resolutionNames = resolutionNames;
            resolStruct.resolutionTypes = resolutionTypes;
            resolStruct.resolutionValues = resolutionValues;  
         end
        
        function displayResolutionsObject(obj)
            % Displays the resolution parameters and resolution table.
            fprintf('    Resolutions: --------------------------------------------------------------------------------------------- \n\n');
            fprintf('    (a) Resolutions Parameters: \n');
            obj.resolPars.displayParametersTable;
            
            fprintf('    (b) Resolutions:  \n')
            obj.resolutions.displayTypesTable;
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
            parList = obj.resolPars.getParamNames(); 
            if isnumeric(param)
                if (param < 1) || (param > length(parList))
                    throw(indexOutOfRange(sprintf('Resolution Parameter %d is out of range', param)));
                end
                thisPar = parList(param);
            else
                if ~strcmpi(param, parList)
                    throw(nameNotRecognised(sprintf('Unrecognised parameter name %s', param)));
                end
                thisPar = param;
            end   
        end
    end
end 
