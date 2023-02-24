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
       allowedTypes = {'constant', 'data', 'function', 'gaussian'}
    end
    
    methods
        function  obj = resolutionsClass(parameters, startResolution) 
            % Creates a Resolutions object. The arguments should be 
            % a cell array with the content of the first parameter and a
            % cell array with the first resolution entry
            %
            % resolution = resolutionsClass({'Tails', 10, 20, 30, true, 'uniform', 0, Inf},... 
            %                                {'Resolution 1', 'constant', 'Tails'});
            obj.resolPars = parametersClass(parameters);
            
            % Make a multiType table to define the actual resolutions
            obj.resolutions = multiTypeTable(startResolution);
            obj.resolutions.allowedTypes = obj.allowedTypes;
            obj.resolutions.typesAutoNameString = 'New Resolution';
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
        
        function names = getResolParNames(obj)
            % Returns a N x 1 cell array of parameter names in the resolutions 
            % object. 
            % 
            % names = resolution.getResolParNames();
            names = obj.resolPars.getParamNames();
        end

        % --- resolParams table edit methods -----------------------
        function addResolPar(obj,varargin)
            % Adds a new resolution parameter. A parameter consists 
            % of a name, min, value, max, fit flag, prior type', mu,
            % and sigma
            %
            % resolution.addResolPar('ResolPar 1', 1e-8, 2.8e-6, 1e-5, true);
            obj.resolPars.addParam(varargin);  
        end
        
        function setResolParValue(obj,varargin)
            % Sets the value of existing resolution            
            % parameter. Expects index or name of parameter 
            % and new value to set
            %
            % resolution.setResolParValue(1, 5.5e-6);
            obj.resolPars.setValue(varargin);
        end
        
        function setResolParConstr(obj,varargin)
            % Sets the constraint of existing resolution            
            % parameter value. Expects index or name of parameter 
            % and new minimum and maximum value to set
            %
            % resolution.setResolParValue(1, 2, 3);
            obj.resolPars.setConstr(varargin);
        end
        
        function setResolParName(obj,varargin)
            % Sets the name of existing resolution            
            % parameter. Expects index or name of parameter 
            % and new name to set
            %
            % resolution.setResolParName(1, 'new_name');
            obj.resolPars.setName(varargin);
        end
        
        function removeResolPar(obj, varargin)
            % Removes a given resolution parameter.
            % Expects index or name of parameter(s) to remove
            % 
            % resolution.removeResolPar(2);
            obj.resolPars.removeParam(varargin{:});
        end
        
        function setResolPar(obj, varargin)
            % Sets the value of an existing resolution parameter. Expects
            % index or name of parameter and keyword/value pairs to set
            %
            % resolution.setResolPar(1, 'name', 'ResolPar');
            obj.resolPars.setParameter(varargin);
        end
        
        % ---------------------------------------------------------
         
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
                       % of a datafile. We don't have access to the
                       % datafiles at this point so this (i.e. that data is
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
            %  resolution.removeResolution([1, 3]);
            obj.resolutions.removeRow({row});
        end
        
        function setResolutionValue(obj, row, col, value)
            % Changes the value of a given resolution in the table. Expects the row
            % and column of the parameter as name or index and the new value. 
            %
            % resolution.setResolutionValue(1, 1, "res 1");       
            if isnumeric(col)
                if col == 1
                    col = 'name';
                elseif col == 2
                    col = 'type';
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
           
            obj.resolutions.setValue({row, col, inputPar}); 
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
            parList = obj.getResolParNames(); 
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
