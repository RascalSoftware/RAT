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
       allowedTypes = {'constant', 'data', 'function', 'gaussian'}
    end
    
    methods
        function  obj = backgroundsClass(parameters, startBackgrounds)
            % Creates a background object. The arguments should be two
            % a cell arrays of parameters and the background
            %
            % background = backgroundClass({'Backs par 1', 1e-7, 1e-6, 1e-5, false, 'uniform', 0, Inf},... 
            %                                {'Background 1', 'constant', 'Backs Par 1','','','',''});
            obj.backPars = parametersClass(parameters);
            
            % Make a multiType table to define the actual backgrounds
            obj.backgrounds = multiTypeTable(startBackgrounds);
            obj.backgrounds.allowedTypes = obj.allowedTypes;
            obj.backgrounds.typesAutoNameString = 'New background';
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
        
        function names = getBacksParNames(obj)
            % Returns a N x 1 cell array of parameter names in  
            % the backgrounds object.
            % 
            % names = background.getBacksParNames();
            backsParTable = obj.backPars.paramsTable;
            names = backsParTable{:,1};       
        end
        
        % --- backParams table edit methods -----------------------
        function obj = addBacksPar(obj,varargin)
            % Adds a new background parameter. A parameter consists 
            % of a name, min, value, max, fit flag, prior type', mu,
            % and sigma
            %
            % background.addBacksPar('Backs par 1', 1e-7, 1e-6, 1e-5, false, 'uniform', 0, Inf);
            obj.backPars.addParam(varargin);
             
        end
        
        function obj = setBacksParValue(obj,varargin)
            % Sets the value of existing background            
            % parameter. Expects index or name of parameter 
            % and new value to set
            %
            % background.setBacksParValue(1, 5.5e-6);
            obj.backPars.setValue(varargin);
        end
        
        function obj = setBacksParConstr(obj,varargin)
            % Sets the constraint of existing background            
            % parameter value. Expects index or name of parameter 
            % and new minimum and maximum value to set
            %
            % background.setBacksParValue(1, 2, 3);
            obj.backPars.setConstr(varargin);
        end
        
        function obj = setBacksParName(obj,varargin) 
            % Sets the name of existing background            
            % parameter. Expects index or name of parameter 
            % and new name to set
            %
            % background.setBacksParName(1, 'new_name');
           obj.backPars.setName(varargin);
        end
        
        function obj = removeBacksPar(obj,varargin)
            % Removes a given background parameter.
            % Expects index or name of parameter(s) to remove
            % 
            % background.removeBacksPar(2);
            obj.backPars.removeParam(varargin{:});
        end
        
        function obj = setBacksPar(obj, varargin)
            % Sets the value of an existing background parameter. Expects
            % index or name of parameter and keyword/value pairs to set
            %
            % background.setBacksPar(1, 'name', 'BackPar');
           obj.backPars.setParameter(varargin);  
        end
        
        % ---------------------------------------------------------
         
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
            obj.backgrounds.removeRow({row});
        end
        
        function obj = setBackgroundValue(obj, row, col, value)
            % Changes the value of a given background in the table. Expects the row
            % and column of the parameter as name or index and the new value. 
            %
            % background.setBackgroundValue(1, 1, "back 1"); 
            if isnumeric(col)
                if col == 2
                    col = 'type';
                elseif col == 1
                    col = 'name';
                elseif col == 3
                    col = 'Value 1';
                end
            end
                    
            if strcmpi(col,'name') || strcmpi(col,'Value 1') 
                inputPar = value;
            elseif strcmpi(col,'type') 
                if ~strcmpi(value, obj.allowedTypes)
                   throw(invalidOption(sprintf(obj.invalidTypeMessage, value)));
                end
                inputPar = value;
            else
                inputPar = obj.validateParam(value);
            end
            
            obj.backgrounds.setValue({row, col, inputPar});
        end
         
        function obj = setBackgroundName(obj, index, name)
            % Sets the name of a given background in the table. Expects 
            % an index and the new name. 
            %
            % background.setBackgroundName(1, 'new_name');
            if ~ischar(name)
                throw(invalidType(sprintf('%s must be a character array', name)));
            end
            obj.backgrounds.setValue({index, 'name', name});
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
            parList = obj.getBacksParNames();
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
