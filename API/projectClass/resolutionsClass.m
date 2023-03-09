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
       invalidTypeMessage = "Unrecognised type '%s'. Must be one of the types defined in 'obj.allowedTypes'"
    end
    
    properties (Access = private)
       allowedTypes = {'constant', 'data', 'function'}
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
            obj.resolutions.allowedTypes = obj.allowedTypes;
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
         
        function addResolution(obj,varargin)
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
               typeVal = in{2};
               if ~strcmpi(typeVal, obj.allowedTypes)
                   throw(invalidOption(sprintf(obj.invalidTypeMessage, typeVal)));
               end

               thisRow{1} = in{1};
               thisRow{2} = in{2};

               % Check that the other params inputted are either valid
               % resolution names, or numbers in range..
               switch typeVal
                   case 'constant'
                       % Param 3 must be a valid parameter
                       thisParam = obj.validateParam(in(3));
                       thisRow{3} = thisParam;

                   case 'function'
                       % Param 3 is assumed to be function name
                       % any other given parameters must be in paramNames
                       % list or numbers in range
                       thisRow{3} = in{3};
                       for i = 4:length(in)
                          thisParam = obj.validateParam(in(i));
                          thisRow{i} = thisParam;
                       end
                       
                   case 'data'
                       % Resolution is assumed to be given by a 4th column 
                       % of a data file. We don't have access to the
                       % data files at this point so this (i.e. that data is
                       % [n x 4] ) will be checked downstream
                       thisRow = {in(1), in(2), '', '', '', '', ''};
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
            addParameter(p, 'name', obj.resolutions.typesTable{row, 1}, @(x) isstring(x) || ischar(x));
            addParameter(p, 'type', obj.resolutions.typesTable{row, 2}, @(x) isstring(x) || ischar(x));
            addParameter(p, 'value1', obj.resolutions.typesTable{row, 3}, @(x) isstring(x) || ischar(x));
            addParameter(p, 'value2', obj.resolutions.typesTable{row, 4}, @(x) isstring(x) || ischar(x));
            addParameter(p, 'value3', obj.resolutions.typesTable{row, 5}, @(x) isstring(x) || ischar(x));
            addParameter(p, 'value4', obj.resolutions.typesTable{row, 6}, @(x) isstring(x) || ischar(x));

            parse(p, varargin{:});
            inputBlock = p.Results;

            obj.resolutions.setValue(row, 1, inputBlock.name);
            
            if ~strcmpi(inputBlock.type, obj.allowedTypes)
               throw(invalidOption(sprintf(obj.invalidTypeMessage, inputBlock.type)));
            end
            obj.resolutions.setValue(row, 2, inputBlock.type);      
            
            values = {inputBlock.value1, inputBlock.value2, inputBlock.value3, inputBlock.value4};
            for i = 1:4
                value = convertStringsToChars(values{i});
                % for function type, value 1 is the function name so no validation is done 
                if ~isempty(value) && ~(i==1 && strcmpi(inputBlock.type,'function'))
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
        function thisPar = validateParam(obj, par)
            % Checks that given parameter index or name is valid, then returns the
            % parameter name. 
            %
            % param = obj.validateParam('param_name');
            if iscell(par)
                par = par{:};
            end
            parList = obj.resolPars.getParamNames(); 
            if isnumeric(par)
                if (par < 1) || (par > length(parList))
                    throw(indexOutOfRange(sprintf('Resolution Parameter %d is out of range', par)));
                end
                thisPar = parList(par);
            else
                if ~strcmpi(par, parList)
                    throw(nameNotRecognised(sprintf('Unrecognised parameter name %s', par)));
                end
                thisPar = par;
            end   
        end
    end
end 
