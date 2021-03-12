classdef projectClass < handle & matlab.mixin.CustomDisplay 
    
    % Class definition for Standard Layers with no absorption.
    % Layers defined in terms of thickness, roughness, real SLD and
    % hydration.
    %
    % Sub objects used are:
    % parametersClass       - parameter definition with priors
    % layersClass_realSLD   - layers defined as (d,rho_real,rough,hydration)
    
    properties
        experimentName
        Geometry            
        parameters          % parametersClass object
        layers              % layersClass_realSLD object
        bulkIn              % parametersClass object
        bulkOut             % parametersClass object
        background          % backgroundsClass object
        resolution          % resolutionClass object
        contrasts           % contrastsClass object
        data                % dataClass object
        
        UsePriors = false
    end
    
    properties (Constant)
        experimentType = 'Standard Layers with (d,rho,rough) layers'
    end
    
    methods
        function obj = projectClass(name)
            
            % Class constructor
            obj.experimentName = name;
            obj.Geometry = 'Air/substrate';
            
            % Initailise the Parameters Table
            obj.parameters = parametersClass({'Substrate Roughness',1 3 5,true,'uniform',0,Inf});
            
            % Initialise the layers table
            obj.layers = layersClass_realSLD();
            
            % Initialise bulkIn table
            obj.bulkIn = parametersClass({'SLD Air',0,0,0,false,'uniform',0,Inf});
            
            % Initialise bulkOut table
            obj.bulkOut = parametersClass({'SLD D2O',6.2e-6,6.35e-6,6.35e-6,false,'uniform',0,Inf});
            
            % Initialise backs object
            backPars = {'Backs par 1',1e-8,1e-7,1e-6,false,'uniform',0,Inf};
            backgrounds = {'Background 1','constant','Backs Par 1','','','',''};
            obj.background = backgroundsClass(backPars,backgrounds);
            
            % Initialise resolution object
            resolPars = {'Resolution par 1',0.01,0.03,0.05,true,'uniform',0,Inf};
            resolutions = {'Resolution 1','gaussian','Resolution par 1','','','',''};
            obj.resolution = resolutionsClass(resolPars,resolutions);
            
            % Initialise data object
            obj.data = dataClass({'Data 1',{[]},{[]}, {[]}});
            
            % Initialise Contrasts object.
            obj.contrasts = contrastsClass();
            
        end
        
        
        function obj = setUsePriors(obj,showFlag)
            % Sets the priors flag 
            
            if ~islogical(showFlag)
                error('usePriors must be logical ''true'' or ''false''');
            end
            obj.UsePriors = showFlag;

            % Also need to set the flag in sub-objects 
            % where relevant..
            % (1) Parameters
            obj.parameters.showPriors = true;
            
            % (2) Bulk In
            obj.bulkIn.showPriors = true;
            
            % (3) Bulk out
            obj.bulkOut.showPriors = true;
            
            % (4) Backgrounds (parameters table)
            obj.background.backPars.showPriors = true;
            
        end
        
        function obj = setGeometry(obj,val)
            % Sets the experiment geometry
            
            if ~ischar(val)
                error('Expecting char array')
            end
            
            if ~any(strcmpi(val,{'Air/substrate','Substrate/Liquid'}))
                error('Expecting Air/Substrate or Substrate/Liquid')
            end
            
            obj.geometry = val;
          
        end
        
        function names = getAllAllowedNames(obj)
            
            % Returns a cell array of all currently
            % set parameter names for the project.
            names.backsNames = obj.background.getBackgroundNames();
            names.bulkInNames = obj.bulkIn.getParamNames();
            names.bulkOutNames = obj.bulkOut.getParamNames();
            names.resolsNames = obj.resolution.getResolNames();
            names.layersNames = obj.layers.getLayersNames();
            names.dataNames = obj.data.getDataNames();

        end
        
        % ---------------------------------
        
        % Editing Parameters Block
        
        function obj = addParamGroup(obj,varargin)
            % Add a group of parameters to the 
            % parameters object. Expects a cell
            % array of parameter cell arrays 
            
            input = varargin{:};
            if ~iscell(input)
                error('Expecting a cell array of parameters');
            end
            
            for i = 1:length(input)
                obj = addParam(obj,input{i});
            end
        end
        
       
        function obj = addParam(obj,varargin)
            % Adds an individual parameter to
            % the parameters object.
            
            % Check how many parameters we are adding
            % and make sure all the inputs are cells
            if isempty(varargin)
                obj.parameters.addParam();
            else
                % If the input is wrapped in a cell (so varargin is a cell of a cell)
                % need to unwrap one layer of it, otherwise keep varargin as it is
                if iscell(varargin{:})
                    thisParam = varargin{:};
                else
                    thisParam = varargin;
                end
                obj.parameters.addParam(thisParam);
            end

        end
        
        
        function obj = removeParam(obj,varargin)
           % Removes a parameter from the parameters
           % object. The parameter will also be removed 
           % from the layers array if it is in use
           
           removing = varargin;
           numberOfParams = length(removing);
           
           % Remove the param
           for i = 1:numberOfParams
               thisParam = varargin{i};
               
               % Make sure we don't remove substrate roughness
               if (isequal(thisParam{1},1)) || (strcmpi(thisParam{1},'Substrate Roughness'))
                   error('Can''t remove protected parameter Substrate Roughness');
               end
              
               % No need to check validity of the parameter
               % as this is done in the parameters class
               obj.parameters.removeParam(thisParam);
               
               % Need to chack if it is used in the layers
               % array and remove it if so. Should be able
               % to do this with array indexing, but can't quite figure
               % that out atm, so just use a (dirty) loop over all 
               % the elementsfor now..
               
               findParam = string(thisParam);
               laysTable = obj.layers.layersTable;
               dims = size(laysTable);
               for m = 1:dims(1)
                   for n = 1:dims(2)
                       tablePar = laysTable{m,n};   % Should be a string
                       if isequal(findParam,tablePar)
                           obj.layers.layersTable(m,n) = {""};
                       end
                   end
               end
           end
           
        end
        
        
        function obj = setParamValue(obj,varargin) 
           % Set the value of a given parameter
           obj.parameters.setValue(varargin);
        end
        
        function obj = setParamConstr(obj,varargin)
           % Set the constraints of an existing parameter
           obj.parameters.setConstr(varargin);
        end
        
        function obj = setParamName(obj,varargin)
           % Set the name of an existing parameter
           inputValue = varargin;
           if (isequal(inputValue{1},1)) || (strcmpi(inputValue{1},'Substrate Roughness'))
               error('Can''t rename protected parameter Substrate Roughness');
           end
           obj.parameters.setName(varargin); %= updatedParams;
        end
        
        function obj = setParamFit(obj,varargin)
           % Set the 'fit' to off or on for parameter
           obj.parameters.setFit(varargin);
        end
        
        function obj = setParamPrior(obj,varargin)
            
            disp('Todo');
            
        end
        
        % -----------------------------------------------------
        
        % Editing of layers block
        function obj = addLayerGroup(obj,varargin)
            % Add a group of layers to the 
            % layers object. Expects a cell
            % array of layer cell arrays 
            
            input = varargin{:};
            if ~iscell(input)
                error('Expecting a cell array of layers');
            end
            
            for i = 1:length(input)
                obj = addLayer(obj,input{i});
            end
            
        end
       
       
        function obj = addLayer(obj,varargin)
            
            
            % Decide on what type of set we are
            % doing so we can call the correct
            % add layers method.
            
            if isempty(varargin)
                % No input, so empty layer
                whatToAdd = {'empty'};
                
            elseif ischar(varargin{:})
                % Input is string, so named empty layer
                whatToAdd = {'empty named', varargin};
                
            elseif iscell(varargin{:})
                % Input is cell, so adding layer with parameters
                whatToAdd = {'full layer', varargin};
            end
            
            % Layers class will also need to know which parameters are
            % currently defined (could also be done here rather than in
            % object)
            table = obj.parameters.paramsTable;
            paramNames = table(:,1);
            
            % Call the addLayers method
            obj.layers.addLayer(whatToAdd,paramNames);
            
        end
        
        function obj = setLayerValue(obj,varargin)
            
            % Set a value of a given layer
            if length(varargin) ~= 3
                error('Three parameters expected into setLayerValue');
            end
            inputPars = varargin;
            
            % Check if set value exists as a parameter
            inputVal = inputPars{3};
            parNames = obj.parameters.paramsTable{:,1};
            
            if ischar(inputVal)
                if ~find(strcmpi(inputVal,parNames))
                    error('Parameter %s not recognised',inputVal);
                end
            elseif isnumeric(inputVal)
                if inputVal < 1 || inputVal > length(parNames)
                    error('Parameter is out of range')
                end
                inputPars{3} = parNames{inputVal};
            end
            
            % call the layers class to set the value
            obj.layers.setLayerValue(inputPars);
            
            
            disp('debug');
            
        end
        
        % ---------------------------------------------------------------
        
        % Editing of Backgrounds block
        
        
        %(1) Backgound Parameters
        function obj = addBacksPar(obj, varargin)
           % Add a background parameter to the background parameters table
            obj.background.addBacksPar(varargin);
        end
        
        function obj = removeBacksPar(obj, varargin)
           % Remove a background parameter from the backgrounds parameters
           % table
           obj.background.removeBacksPar(obj, varargin);
        end
        
        function obj = setBacksParValue(obj,varargin)
            % Set the value of existing backsPar
            obj.background.setBacksParValue(varargin);
        end
        
        function obj = setBacksParConstr(obj,varargin)
            % Set the constraints of existing backsPar
            obj.background.setBacksParConstr(varargin);
        end
        
        function obj = setBacksParName(obj,varargin)
            % Set the name of existing backsPar
            obj.background.setBacksParName(varargin);   
        end

        % (2) Backgrounds
        function obj = addBackground(obj,varargin)
           % Add a background to the multi-table
           obj.background.addBackground(varargin);
        end
        
        function obj = setBackgroundValue(obj,varargin)
            % Set the value of an existing background parameter
            obj.background.setBackgroundValue(varargin);
        end
        
        function obj = setBackgroundName(obj,varargin)
            % Set the name of an existing Background parameter
            obj.background.setBackgroundName(varargin);
        end
        

    % ------------------------------------------------------------
    %   Editing of Data block 
        
        function obj = addData(obj, varargin)
            
            % Add a new data parameter
            obj.data.addData(varargin);
        end
        
        function obj = setData(obj, varargin)
            
           % Edit an existing data parameter
           nameChanged = obj.data.setData(varargin);
           obj.contrasts.updateContrastName(nameChanged);
        end
        
        
    % ---------------------------------------------------------------
    %   Editing of Bulk out block
        
        function obj = addBulkOut(obj,varargin)
        
            obj.bulkOut.addParam(varargin{:});
        end

        
        
        
    % ----------------------------------------------------------------
    %
    %   Editing of Contrasts Block
    
        function obj = addContrast(obj,varargin)
            
            allowedNames = obj.getAllAllowedNames();
            obj.contrasts.addContrast(allowedNames,varargin);
    
        end
        
        
        function obj = setContrast(obj,varargin)
            
            % Allow setting of all parameters in terms of name value pairs.
            % First input must be contrast number or name, subsequent
            % inputs are name / value pairs for the parts involved
            
            firstInput = varargin{1};
            inputVals = varargin(2:end);
            
            contrastNames = obj.contrasts.getAllContrastNames();
            numberOfContrasts = obj.contrasts.numberOfContrasts;
            
            % Find if we are referencing and existing contrast
            if isnumeric(firstInput) 
                if (firstInput < 1 || firstInput > numberOfContrasts)
                    error('Contrast number %d is out of range',firstInput);
                end
                thisContrast = firstInput;
                
            elseif ischar(firstInput)
                [present,idx] = ismember(firstInput, contrastNames);
                if ~present
                    error('Contrast %s is not recognised',firstInput)
                end
                thisContrast = idx;
                
            end
            
            % Get the list of allowed values depending on what is 
            % set for the other contrasts.
            allowedValues = obj.getAllAllowedNames;    
            
            % Call the setContrast method
            obj.contrasts.setContrast(thisContrast,allowedValues,inputVals);
            
        end

    end     % end public methods
  
    % ------------------------------------------------------------------
    
    methods (Access = protected)
      
        function paramNum = findPar(paramName)
            existingNames = obj.parameters.paramsTable{:,1};
            index = strcmp(paramName, existingNames);
            if isempty(index)
                paramNum = -1;
            else
                paramNum = find(index);
            end
        end
        
        % Display methods
        function group = getPropertyGroup1(obj)
            % Initial Parameters at the start of the class
            masterPropList = struct('experimentType',{obj.experimentType},...
                'experimentName',{obj.experimentName},...
                'Geometry', obj.Geometry);
            
            if isscalar(obj)
                group = matlab.mixin.util.PropertyGroup(masterPropList);
            else
                group = getPropertyGroup1@matlab.mixin.CustomDisplay(obj);
            end
        end
        
        function displayScalarObject(obj)
            % Display the whole class. Call the display methods for
            % the sub-classes where appropriate
            
            % Display initial properties
            startProps = getPropertyGroup1(obj);
            matlab.mixin.CustomDisplay.displayPropertyGroups(obj,startProps);
            
            % Display the parameters table
            fprintf('    Parameters: ---------------------------------------------------------------------------------------------- \n\n');
            obj.parameters.displayParametersTable;
            
            % Display the layers table
            fprintf('    Layers: -------------------------------------------------------------------------------------------------- \n\n');
            obj.layers.displayLayersTable;
            
            % Display the Bulk In table
            fprintf('    Bulk In: -------------------------------------------------------------------------------------------------- \n\n');
            obj.bulkIn.displayParametersTable;

            % Display the Bulk Out table
            fprintf('    Bulk Out: ------------------------------------------------------------------------------------------------- \n\n');
            obj.bulkOut.displayParametersTable;

            % Display the backgrounds object
            obj.background.displayBackgroundsObject;
            
            % Display the resolutions object
            obj.resolution.displayResolutionsObject;
                    
            % Display the data object
            obj.data.displayDataObject;
            
            % Display the contrasts object
            obj.contrasts.displayContrastsObject;

        end
        
    end
  
end

