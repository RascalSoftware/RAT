classdef backgroundsClass < handle
    
    % This makes the backgrounds class.
    % Backgrounds are defined in a two stage process. Firstly we define the
    % actual fitted parameters. These are held in a 'ParametersClass'
    % table. Then, we group these into the backgrounds themselves using a
    % multiTypeTable. So, we can then use th ebackground parameters to
    % either define background as  constant, data or a function. For
    % constant only one parameter is supplied to multi type table. For data
    % only the itself is supplied as a cell. For function, the function
    % name is supplied, allong with up to three parameters (from the
    % parameters table) which are then supplied to the function to
    % calculate the background. 
    % In each case, the background can either be added to the simulation or
    % subtracted from the data.
    
    properties
        
       backPars 
       backgrounds
       showPriors = false
       
    end
    
    properties (Access = private)
        
       allowedTypes = {'constant', 'data', 'function'};
        
    end
    

    methods
        function  obj = backgroundsClass(varargin) 
            
            startBackPars = varargin{1};
            startBackgrounds = varargin{2};
            
            % Make a table to hold the fittable variables
            obj.backPars = parametersClass(startBackPars);
            
            % Make a multiType table to define the actual backgrounds
            obj.backgrounds = multiTypeTable(startBackgrounds);
            obj.backgrounds.allowedTypes = obj.allowedTypes;
            obj.backgrounds.allowedActions = {'add','subtract'};
            obj.backgrounds.typesAutoNameString = 'New background';

        end
        
        function names = getBackgroundNames(obj)
            
            backsTable = obj.backgrounds.typesTable;
            names = backsTable{:,1};
            
        end
        
        function names = getBacksParNames(obj)
            
            backsParTable = obj.backPars.paramsTable;
            names = backsParTable{:,1};
            
        end
        
        % --- BackParams table edit methods -----------------------
        
        function obj = addBacksPar(obj,varargin)
            
            % Add a parameter to the backs parameter table
            in = varargin{:};
            backParsTable = obj.backPars;
            if isempty(in)
                % Empty call - pass no parameter
                backParsTable = backParsTable.addParam();
            elseif length(in) == 1
                % Name only being passed
                backParsTable = backParsTable.addParam(in);
            else
                % Passing a fuller expression - pass it all
                backParsTable = backParsTable.addParam(in);
            end
            obj.backPars = backParsTable;    

        end
        
        function obj = setBacksParValue(obj,varargin)
            % Set a parameter value in the backs parameter table
            obj.backPars.setValue(varargin{:});
        end
        
        function obj = setBacksParConstr(obj,varargin)
            % Set a parameter constraint in the backs parameter table
            obj.backPars.setConstr(varargin{:});
        end
        
        function obj = setBacksParName(obj,varargin)
           % Set a parameter name in the backs parameter table 
           obj.backPars.setName(varargin{:});
        end
        
        function obj = removeBacksPar(obj,varargin)
            % Remove a parameter from the backsPar table
            obj.backPars.removeParam(varargin{:});
        end
        
        function obj = setBacksPar(obj, varargin)
           % General purpose backPar set using name / value pairs
           obj.backPars.setParameter(varargin{:});
            
        end
        
        % ---------------------------------------------------------
         
        function obj = addBackground(obj,varargin)
            
            % Decide on what type of set we are
            % doing, make sure the inputs are valid and build the row cell
            % to be added
            
            in = varargin{:};
            paramNames = obj.backPars.paramsTable{:,1};
            
            if isempty(in)
                thisRow = {};
            else
                thisRow = {'','','','','','',''};
            end
            

            if length(in) == 1
                % Assume the input is just a name
                thisRow{1} = in;
            
            elseif length(in) > 1
               
               % Check that second param is legal
               typeVal = in{2};
               if ~strcmpi(typeVal,obj.allowedTypes)
                    error('Unrecognised background type %s. Must be ''constant'',''data'', or ''function''', typeVal);
               end

               thisRow{1} = in{1};
               thisRow{2} = in{2};

               % Check that the other params inputted are either valid
               % background names, or numbers in range..
               switch typeVal
                   case 'constant'
                       % Param 3 must be a valid parameter
                       thisParam = parseParam(in(3),paramNames);
                       thisRow{3} = thisParam;

                   case 'function'
                       % Param 3 is assumed to be function name
                       % any other given parameters must be in paramNames
                       % list or numbers in range
                       thisRow{3} = in{3};
                       for i = 4:length(in)
                          thisParam = parseParam(in(i),paramNames);
                          thisRow{i} = thisParam;
                       end
                end
            end
            obj.backgrounds.addRow(thisRow);
                
        end
        
        function obj = removeBackground(obj, varargin)
            thisRow = varargin{:};
            obj.backgrounds.removeRow(thisRow);
        end
        
        function obj = setBackgroundValue(obj,varargin)
            
            in = varargin{:};
            if length(in) ~= 3
                error('Expect three inputs into setBackgroundValue');
            end
            
            % Need to check that param 3 is allowed
            % If it's col 1 or 3, anything is allowed
            % If it's col(2) must be in allowed type of table
            % Other cols must be existing param name or number,
            col = in{2};
            
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
                % Do Nothing - any value is allowed so use as is 
                inputPar = in{3};
            elseif strcmpi(col,'type') 
                allowedList = {'constant','data','function'};
                inputPar = parseParam(in{3},allowedList);
            else
                allowedList = obj.backPars.paramsTable{:,1};
                inputPar = parseParam(in{3},allowedList);
            end
            
            in{3} = inputPar;
            obj.backgrounds.setValue(in);
        
        end
        
        function obj = setBackgroundName(obj,varargin)
            
            in = varargin{:};
            if length(in) ~= 2
                error('Expect two inputs into setBackgroundName');
            end
            
            % Need to check that param 2 is allowed
            % Must be a char value
            name = in{2};
            if ~ischar(name)
                error('Name must be a character array');
            end

            obj.backgrounds.setValue(in);
            
        end
        
        function displayBackgroundsObject(obj)
            
            fprintf('    Backgrounds: ----------------------------------------------------------------------------------------------- \n\n');
            fprintf('    (a) Background Parameters: \n');
            obj.backPars.displayParametersTable;
            
            fprintf('    (b) Backgrounds:  \n')
            obj.backgrounds.displayTypesTable;
            %fprintf('\n    ----------------------------------------------------------------------------------- \n\n');
            
        end
        
        function backStruct = toStruct(obj)
    
            backParamsStruct = obj.backPars.toStruct();
            
            backStruct.backParNames = backParamsStruct.paramNames;
            backStruct.backParconstr = backParamsStruct.paramConstr;
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

end

function thisPar = parseParam(par,parList)
    
    if iscell(par)
        par = par{:};
    end

    if isnumeric(par)
        if (par < 1) || (par > length(parList))
            error('Background Parameter %d is out of range',par);
        else
            thisPar = parList(par);
        end
    elseif ischar(par)
        if ~strcmpi(par,parList)
            error('Parameter %s is not recognised',par);
        else
            thisPar = par;
        end
    elseif isempty(par)
        error('Background parameter not recognised');
    end
    
end
