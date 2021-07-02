classdef resolutionsClass < handle
    
       
    % This makes the rosolutions class.
    % Backgrounds are defined in a two stage process. Firstly we define the
    % actual fitted parameters. These are held in a 'ParametersClass'
    % table. Then, we group these into the resolutions themselves using a
    % multiTypeTable. So, we can then use th eresolution parameters to
    % either define resolution as  constant, data or a function. For
    % constant only one parameter is supplied to multi type table. For data
    % only the itself is supplied as a cell. For function, the function
    % name is supplied, allong with up to three parameters (from the
    % parameters table) which are then supplied to the function to
    % calculate the resolution. 
    % In each case, the resolution can either be added to the simulation or
    % subtracted from the data.
    
    properties
        
       resolPars 
       resolutions
       showPriors = false
       
    end
    
    properties (Access = private)
        
       allowedTypes = {'constant', 'data', 'function'};
        
    end
    

    methods
        function  obj = resolutionsClass(varargin) 
            
            startResolPars = varargin{1};
            startResolutions = varargin{2};
            
            % Make a table to hold the fittable variables
            obj.resolPars = parametersClass(startResolPars);
            
            % Make a multiType table to define the actual resolutions
            obj.resolutions = multiTypeTable(startResolutions);
            obj.resolutions.allowedTypes = obj.allowedTypes;
            obj.resolutions.typesAutoNameString = 'New Resolution';

        end
        
        function names = getResolNames(obj)
            
            resolTable = obj.resolutions.typesTable;
            names = resolTable{:,1};
            
        end

        
        % --- resolParams table edit methods -----------------------
        
        function obj = addResolPar(obj,varargin)
            
            % Add a parameter to the backs parameter table
            in = varargin{:};
            resolParsTable = obj.resolPars;
            if isempty(in)
                % Empty call - pass no parameter
                resolParsTable = resolParsTable.addParam();
            elseif length(in) == 1
                % Name only being passed
                resolParsTable = resolParsTable.addParam(in);
            else
                % Passing a fuller expression - pass it all
                resolParsTable = resolParsTable.addParam(in);
            end
            obj.resolPars = resolParsTable;    

        end
        
        function obj = setResolParValue(obj,varargin)
            % Set a parameter value in the resol parameter table
            obj.resolPars.setValue(varargin{:});
        end
        
        function obj = setResolParConstr(obj,varargin)
            % Set a parameter constraint in the resol parameter table
            obj.resolPars.setConstr(varargin{:});
        end
        
        function obj = setBacksParName(obj,varargin)
           % Set a parameter name in the resol parameter table 
           obj.resolPars.setName(varargin{:});
        end
        
        function obj = removeResolPar(obj,varargin)
            % Remove a parameter from the resolPar table
            disp('Todo');
        end
        
        function obj = setResolPar(obj, varargin)
           % General purpose backPar set using name / value pairs
           obj.resolPars.setParameter(varargin{:});
            
        end
        
        
        
        % ---------------------------------------------------------
         
        function obj = addResolution(obj,varargin)
            
            % Decide on what type of set we are
            % doing, make sure the inputs are valid and build the row cell
            % to be added
            
            in = varargin{:};
            paramNames = obj.resolPars.paramsTable{:,1};
            
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
                    error('Unrecognised resolution type %s. Must be ''constant'',''data'', or ''function''', typeVal);
               end

               thisRow{1} = in{1};
               thisRow{2} = in{2};

               % Check that the other params inputted are either valid
               % resolution names, or numbers in range..
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
            obj.resolutions.addRow(thisRow);
                
        end
        
        function obj = setResolutionValue(obj,varargin)
            
            in = varargin{:};
            if length(in) ~= 3
                error('Expect three inputs into setResolutionValue');
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
                allowedList = obj.resolPars.paramsTable{:,1};
                inputPar = parseParam(in{3},allowedList);
            end
            
            in{3} = inputPar;
            obj.resolutions.setValue(in);
        
        end
        
        function obj = setResolutionName(obj,varargin)
            
            disp('todo');
            
        end
        
        function resolStruct = toStruct(obj)
    
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
            
            fprintf('    Resolutions: --------------------------------------------------------------------------------------------- \n\n');
            fprintf('    (a) Resolutions Parameters: \n');
            obj.resolPars.displayParametersTable;
            
            fprintf('    (b) Resolutions:  \n')
            obj.resolutions.displayTypesTable;
            %fprintf('\n    ----------------------------------------------------------------------------------- \n\n');
            
        end
      
    end
    
end

function thisPar = parseParam(par,parList)
    
    if iscell(par)
        par = par{:};
    end

    if isnumeric(par)
        if (par < 1) || (par > length(parList))
            error('Resolution Parameter %d is out of range',par);
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
        error('Resolution parameter not recognised');
    end
    
end 
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    


