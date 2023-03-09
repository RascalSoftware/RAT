classdef backgroundsClass < handle
    % Backgrounds are defined in a two stage process. Firstly we define the
    % actual fitted parameters. These are held in a 'ParametersClass'
    % table. Then, we group these into the backgrounds themselves using a
    % multiTypeTable. So, we can then use the background parameters to
    % either define background as  constant, data or a function. 
    % 
    % For constant only one parameter is supplied to multi type table. 
    % 
    % For data only the itself is supplied as a cell. 
    % 
    % For function, the function name is supplied, along with up to three 
    % parameters (from the parameters table) which are then supplied to the 
    % function to calculate the background. 
    %
    % In each case, the background can either be added to the simulation or
    % subtracted from the data.
    
    properties
       backPars 
       backgrounds
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
        function  obj = backgroundsClass(parameters, startBackground)
            % Creates a background object. The arguments should be 
            % an instance of the parameter class with the background parameters
            % and a cell array of  backgrounds
            %
            % params = parametersClass({'Backs par 1', 1e-7, 1e-6, 1e-5, false, 'uniform', 0, Inf});
            % background = backgroundClass(params, {'Background 1', 'constant', 'Backs Par 1'});
            obj.backPars = parameters;
            
            % Make a multiType table to define the actual backgrounds
            obj.backgrounds = multiTypeTable();
            obj.backgrounds.allowedTypes = obj.allowedTypes;
            obj.backgrounds.typesAutoNameString = 'New background';
            obj.addBackground(startBackground{:});
        end

        function flag = get.showPriors(obj)
            flag = obj.backPars.showPriors;
        end
        
        function set.showPriors(obj, value)
            obj.backPars.showPriors = value;
        end
        
        function names = getBackgroundNames(obj)
            % Returns a N x 1 cell array of names of the backgrounds 
            % in the object. 
            % 
            % names = background.getBackgroundNames();
            backsTable = obj.backgrounds.typesTable;
            names = backsTable{:,1};      
        end
                 
        function obj = addBackground(obj,varargin)
            % Adds a new entry to the background table.  
            %
            % background.addBackground('New Row');
            % background.addBackground('New Row', 'constant', 'param_name');
            % background.addBackground('New Row', 'function', 'function_name', 'param_name');
            % background.addBackground('New Row', 'data');
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
               if ~strcmpi(typeVal,obj.allowedTypes)
                    throw(invalidOption(sprintf(obj.invalidTypeMessage, typeVal)));
               end

               thisRow{1} = in{1};
               thisRow{2} = in{2};

               % Check that the other params inputted are either valid
               % background names, or numbers in range..
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
                       % Background is assumed to be given by a 4th column 
                       % of a data file. We don't have access to the
                       % data files at this point so this (i.e. that data is
                       % [n x 4] ) will be checked downstream
                       thisRow = {in(1), in(2), '', '', '', '', ''};
                end
            end
            obj.backgrounds.addRow(thisRow);   
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
            % background.setBackground(1, 'name', 'back 1', 'type', 'constant', 'value1', 'param_name');
            if ischar(row)
                row = obj.backgrounds.findRowIndex(row, obj.getBackgroundNames());
            elseif isnumeric(row)
                count = obj.backgrounds.typesCount;
                if (row < 1) || (row > count)
                    throw(indexOutOfRange(sprintf('The row index %d is not within the range 1 - %d', row, count)));
                end
            else
                throw(invalidType('Unrecognised row'));
            end
            
            p = inputParser;
            addParameter(p, 'name', obj.backgrounds.typesTable{row, 1}, @(x) isstring(x) || ischar(x));
            addParameter(p, 'type', obj.backgrounds.typesTable{row, 2}, @(x) isstring(x) || ischar(x));
            addParameter(p, 'value1', obj.backgrounds.typesTable{row, 3}, @(x) isstring(x) || ischar(x));
            addParameter(p, 'value2', obj.backgrounds.typesTable{row, 4}, @(x) isstring(x) || ischar(x));
            addParameter(p, 'value3', obj.backgrounds.typesTable{row, 5}, @(x) isstring(x) || ischar(x));
            addParameter(p, 'value4', obj.backgrounds.typesTable{row, 6}, @(x) isstring(x) || ischar(x));

            parse(p, varargin{:});
            inputBlock = p.Results;

            obj.backgrounds.setValue(row, 1, inputBlock.name);
            
            if ~strcmpi(inputBlock.type, obj.allowedTypes)
               throw(invalidOption(sprintf(obj.invalidTypeMessage, inputBlock.type)));
            end
            obj.backgrounds.setValue(row, 2, inputBlock.type);
            
            values = {inputBlock.value1, inputBlock.value2, inputBlock.value3, inputBlock.value4};
            for i = 1:4
                value = convertStringsToChars(values{i});
                % for function type, value 1 is the function name so no validation is done 
                if ~isempty(value) && ~(i==1 && strcmpi(inputBlock.type,'function'))
                    value = obj.validateParam(value);
                end
                obj.backgrounds.setValue(row, i + 2, value);
            end
        end
         
        function obj = setBackgroundName(obj, index, name)
            % Sets the name of a given background in the table. Expects 
            % an index and the new name. 
            %
            % background.setBackgroundName(1, 'new_name');
            if ~ischar(name)
                throw(invalidType(sprintf('%s must be a character array', name)));
            end
            obj.backgrounds.setValue(index, 'name', name);
        end

        function displayBackgroundsObject(obj)
            % Displays the background parameters and background table.
            fprintf('    Backgrounds: ----------------------------------------------------------------------------------------------- \n\n');
            fprintf('    (a) Background Parameters: \n');
            obj.backPars.displayParametersTable;
            
            fprintf('    (b) Backgrounds:  \n')
            obj.backgrounds.displayTypesTable;
            %fprintf('\n    ----------------------------------------------------------------------------------- \n\n');
        end
        
        function backStruct = toStruct(obj)
            % Converts the class parameters into a structure array
            backParamsStruct = obj.backPars.toStruct();
            
            backStruct.backParNames = backParamsStruct.paramNames;
            backStruct.backParConstr = backParamsStruct.paramConstr;
            backStruct.backParVals = backParamsStruct.params;
            backStruct.backParFitYesNo = backParamsStruct.fitYesNo;
            backStruct.nBackPars = backParamsStruct.nParams;
            backStruct.backsPriors = backParamsStruct.priors;
            
            backgroundNames = obj.backgrounds.typesTable{:,1};
            backgroundTypes = obj.backgrounds.typesTable{:,2};
            backgroundValues = table2cell(obj.backgrounds.typesTable(:,3:7));
            
            backStruct.backgroundNames = backgroundNames;
            backStruct.backgroundTypes = backgroundTypes;
            backStruct.backgroundValues = backgroundValues;
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
            parList = obj.backPars.getParamNames();
            if isnumeric(par)
                if (par < 1) || (par > length(parList))
                    throw(indexOutOfRange(sprintf('Background Parameter %d is out of range', par)));
                else
                    thisPar = parList(par);
                end
            elseif ischar(par)
                if ~strcmpi(par,parList)
                    throw(nameNotRecognised(sprintf('Unrecognised parameter name %s', par)));
                else
                    thisPar = par;
                end
            end
        end
    end
end
