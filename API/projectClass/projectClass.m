classdef projectClass < handle & matlab.mixin.CustomDisplay
    
    % Class definition for Standard Layers with no absorption.
    % Layers defined in terms of thickness, roughness, real SLD and
    % hydration.
    %
    % Sub objects used are:
    % parametersClass       - parameter definition with priors
    % layersClass_realSLD   - layers defined as (d,rho_real,rough,hydration)
    % backgroundsClass      - 
    % resolutionsClass      -
    % dataClass             -
    % contrastsClass        -
    % customFileClass       -
    
    properties
        experimentName
        Geometry
        parameters          % parametersClass object
        layers              % layersClass_realSLD object
        bulkIn              % parametersClass object
        bulkOut             % parametersClass object
        background          % backgroundsClass object
        scalefactors        % parametersClass object
        qzshifts            % parametersClass object
        resolution          % resolutionClass object
        contrasts           % contrastsClass object
        data                % dataClass object
        customFile          % Custom file object
        
        UsePriors = false

        ModelType = 'Standard Layers'
    end
    
    properties (Access = private)
        
        experimentType = 'Non polarised no absorption';
        
    end
    
    methods

        function obj = projectClass(varargin)
            
            % Class constructor
            if isempty(varargin)
                name = '';
            elseif ~ischar(varargin{:})
                error('Input must be char');
            else
                name = varargin{:};
            end

            obj.experimentName = name;
            obj.Geometry = 'air/substrate';
            
            % Initailise the Parameters Table
            obj.parameters = parametersClass({'Substrate Roughness',1 3 5,true,'uniform',0,Inf});
            
            % Initialise the layers table
            obj.layers = layersClass_realSLD();
            
            % Initialise bulkIn table
            obj.bulkIn = parametersClass({'SLD Air',0,0,0,false,'uniform',0,Inf});
            
            % Initialise bulkOut table
            obj.bulkOut = parametersClass({'SLD D2O',6.2e-6,6.35e-6,6.35e-6,false,'uniform',0,Inf});
            
            % Initialise scalefactors table
            obj.scalefactors = parametersClass({'Scalefactor 1',0.02,0.23,0.25,false,'uniform',0,Inf});
            
            % Initialise qzshifts table
            obj.qzshifts = parametersClass({'Qz shift 1',-1e-4,0,1e-4,false,'uniform',0,Inf});
            
            % Initialise backs object
            backPars = {'Backs par 1',1e-7,1e-6,1e-5,false,'uniform',0,Inf};
            backgrounds = {'Background 1','constant','Backs Par 1','','','',''};
            obj.background = backgroundsClass(backPars,backgrounds);
            
            % Initialise resolution object
            resolPars = {'Resolution par 1',0.01,0.03,0.05,false,'uniform',0,Inf};
            resolutions = {'Resolution 1','gaussian','Resolution par 1','','','',''};
            obj.resolution = resolutionsClass(resolPars,resolutions);
            
            % Initialise data object
            obj.data = dataClass({'Simulation',{[]},{[]}, {[]}});
            
            % Initialise Contrasts object.
            obj.contrasts = contrastsClass();
            
            % Initialise custom file object
            obj.customFile = customFileClass();
            
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
            
            % (4) Scalefactors
            obj.scalefactors.showPriors = true;
            
            % (5) Qz shifts
            obj.qzshifts.showPriors = true;
            
            % (6) Backgrounds (parameters table)
            obj.background.backPars.showPriors = true;
            
            % (7) Resolutions (parameters table)
            obj.resolution.resolPars.showPriors = true;
            
        end
        
        function obj = setGeometry(obj,val)
            % Sets the experiment geometry
            
            if ~ischar(val)
                error('Expecting char array')
            end
            
            if ~any(strcmpi(val,{'Air/substrate','Substrate/Liquid'}))
                error('Expecting Air/Substrate or Substrate/Liquid')
            end
            
            if strcmpi(val,'air/substrate')
                obj.Geometry = 'air/substrate';
            elseif strcmpi(val,'substrate/liquid')
                obj.Geometry = 'substrate/liquid';
            end
        end
        
        function obj = setModelType(obj,val)
            % Sets the experiment type
            
            if ~ischar(val)
                error('Expecting a char array');
            end
            
            if ~any(strcmpi(val,{'standard layers','custom layers','custom xy'}))
                error('experiment type has to be Standard Layers, Custom Layers or Custom XY');
            end
            
            obj.ModelType = val;
            
        end
        

        function names = getAllAllowedNames(obj)
            
            % Returns a cell array of all currently
            % set parameter names for the project.
            names.paramNames = obj.parameters.getParamNames();
            names.backsNames = obj.background.getBackgroundNames();
            names.backParNames = obj.background.getBacksParNames();
            names.bulkInNames = obj.bulkIn.getParamNames();
            names.bulkOutNames = obj.bulkOut.getParamNames();
            names.resolsNames = obj.resolution.getResolNames();
            names.resolParNames = obj.resolution.getResolParNames();
            names.layersNames = obj.layers.getLayersNames();
            names.dataNames = obj.data.getDataNames();
            names.scalefacNames = obj.scalefactors.getParamNames();
            names.qzShiftNames = obj.qzshifts.getParamNames();
            names.customNames = obj.customFile.getCustomNames();
            
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
                thisParam = varargin;%{i};
                
                % Make sure we don't remove substrate roughness
                if (isequal(thisParam{1},1)) || (strcmpi(thisParam{1},'Substrate Roughness'))
                    error('Can''t remove protected parameter Substrate Roughness');
                end
                
                if iscell(thisParam)
                    thisParam = thisParam{:};
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
        
        function obj = setParameter(obj,varargin)
            % Gerenal purpose st parameter method
            obj.parameters.setParameter(varargin);
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
            obj.parameters.setPrior(varargin);  
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
            obj.background.removeBacksPar(varargin{:});
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
        
        function obj = removeBackground(obj,varargin)
            % Remove background from the multi-table
            obj.background.removeBackground(varargin);
        end
        
        function obj = setBackgroundValue(obj,varargin)
            % Set the value of an existing background parameter
            obj.background.setBackgroundValue(varargin);
        end
        
        function obj = setBackgroundName(obj,varargin)
            % Set the name of an existing Background parameter
            obj.background.setBackgroundName(varargin);
        end
        
        function obj = setBacksPar(obj,varargin);
            % Set back par with name value pairs
            obj.background.setBacksPar(varargin);
        end
        
        % -------------------------------------------------------------
        %   Editing of Resolutions block
        
        % Resol Pars
        function obj = setResolParValue(obj,varargin)
            % Set the value of existing backsPar
            obj.resolution.setResolParValue(varargin);
        end
        
        function obj = addResolPar(obj, varargin)
            % Add a background parameter to the background parameters table
            obj.resolution.addResolPar(varargin);
        end
        
        function obj = setResolPar(obj,varargin)
            % Set the value of existing backsPar
            obj.resolution.setResolPar(varargin);
        end
        
        function obj = removeResolPar(obj,varargin)
            % Remove an existing resolPars
            obj.resolution.removeResolPar(varargin{:});
        end
        
        % Resolutions
        function obj = addResolution(obj,varargin)
            % Add a resolution to the multi-table
            obj.resolution.addResolution(varargin);
        end
        
        function obj = removeResolution(obj,varargin)
            % Remove background from the multi-table
            obj.resolution.removeResolution(varargin);
        end
        
        
        % ------------------------------------------------------------
        %   Editing of Data block
        
        function obj = addData(obj, varargin)
            
            % Add a new data parameter
            obj.data.addData(varargin);
        end
        
        function obj = removeData(obj,varargin)
            
            disp('Todo');
        end
        
        function obj = setData(obj, varargin)
            
            % Edit an existing data parameter
            nameChanged = obj.data.setData(varargin);
            
            if ~isempty(nameChanged)
                obj.contrasts.updateContrastName(nameChanged);
            end
        end
        
        
        % ---------------------------------------------------------------
        %   Editing of Bulk out block
        
        function obj = addBulkOut(obj,varargin)
            obj.bulkOut.addParam(varargin);
        end
        
        function obj = removeBulkOut(obj,varargin)
            obj.bulkOut.removeParam(varargin{:});
        end
        
        function obj = setBulkOut(obj,varargin)
            % Gerenal purpose set bulkOut method
            obj.bulkOut.setParameter(varargin);
        end
        
        
        % ------------------------------------------------------------------
        % Editing of bulk in block
        
        function obj = addBulkIn(obj,varargin)
            obj.bulkIn.addParam(varargin);
        end
        
        function obj = removeBulkIn(obj,varargin)
            obj.bulkIn.removeParam(varargin{:});
        end
        
        function obj = setBulkIn(obj,varargin)
            % Gerenal purpose set scalefactor method
            obj.bulkIn.setParameter(varargin);
        end
        
        % -------------------------------------------------------------------
        % Editing of scalefactors block
        
        function obj = addScalefactor(obj,varargin)
            obj.scalefactors.addParam(varargin{:});
        end
        
        function obj = removeScalefactor(obj,varargin)
           obj.scalefactors.removeParam(varargin{:}); 
        end
        
        function obj = setScalefactor(obj,varargin)
            % Gerenal purpose set scalefactor method
            obj.scalefactors.setParameter(varargin);
        end
        

        % -----------------------------------------------------------------
        % Editing of qzshifts block
        
        function obj = addQzshift(obj,varargin)
            obj.qzshifts.addParam(varargin{:}); 
        end
        
        
        % -----------------------------------------------------------------
        % editing of custom models block
        
        function obj = addCustomFile(obj, varargin)
            obj.customFile.addFile(varargin{:});
        end
        
        function obj = setCustomFile(obj,varargin)
            % Gerenal purpose set scalefactor method
            obj.customFile.setCustomFile(varargin);
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
        
        function obj = setContrastModel(obj,varargin)
            
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
            
            % Make a different allowed list depending on whether 
            % it is custom or layers
            ModelType = obj.ModelType;
            
            if ~strcmpi(ModelType,{'custom layers','custom xy'})
                % Standard Layers
                allowedValues = obj.layers.getLayersNames();
                ModelType = 'standard';
                inputVals = inputVals{:};
            else
                % Custom models
                allowedValues = obj.customFile.getCustomNames();
                ModelType = 'custom';
            end
            
            % Call the setContrastModel method
            obj.contrasts.setContrastModel(thisContrast,ModelType,allowedValues,inputVals);

        end
        
        function outStruct = toStruct(obj)
            
            % Converts the class parameters
            % into a struct array for input into
            % the RAT toolbox
            
            % Set which typr of experiment this is
            generalStruct.experimentName = obj.experimentName;
            generalStruct.TF = 'standardTF';
            
            % Add the 'general' fields
            thisType = obj.ModelType;
            
            switch lower(thisType)
                case 'standard layers'
                    generalStruct.ModelType = 'layers';
                case 'custom layers'
                    generalStruct.ModelType = 'custom layers';
                case 'custom xy'
                    generalStruct.ModelType = 'custom xy';
            end
                     
            generalStruct.geometry = obj.Geometry;
            
            % Parameters
            params = obj.parameters.toStruct();
            paramStruct = cell2struct(struct2cell(params),{'paramNames',...
                'nParams','paramConstr','params','paramFitYesNo','paramPriors'});
            
            % Backgrounds
            backgroundStruct = obj.background.toStruct();
            
            % Resolutions
            resolutionStruct = obj.resolution.toStruct();
            
            % Bulk in
            bulkInStruct = obj.bulkIn.toStruct();
            bulkInStruct = cell2struct(struct2cell(bulkInStruct),{'nbairNames',...
                'nNba','nbairConstr','nbairs','nbaFitYesNo','nbaPriors'});
            
            % Bulk out
            bulkOutStruct = obj.bulkOut.toStruct();
            bulkOutStruct = cell2struct(struct2cell(bulkOutStruct),{'nbsubNames',...
                'nNbs','nbsubConstr','nbsubs','nbsFitYesNo','nbsPriors'});
            
            % Scalefactors
            scalefactorStruct = obj.scalefactors.toStruct();
            scalefactorStruct = cell2struct(struct2cell(scalefactorStruct),{'scalefactorNames',...
                'nScalefcators','scalefactorConstr','scalefactors','scalefactorFitYesNo','scalefactorPriors'});
            
            % Qzshifts
            qzshiftStruct = obj.qzshifts.toStruct();
            qzshiftStruct = cell2struct(struct2cell(qzshiftStruct),{'qzshiftNames',...
                'nQzshifts','qzshiftConstr','qzshifts','qzshiftFitYesNo','qzshiftPriors'});
            
            % Layers
            layersCell = obj.layers.toStruct();
            layersStruct.numberOfLayers = size(layersCell,1);
            layersStruct.layersnames = layersCell(:,1);
            
            % parse the layers details
            layersValues = layersCell(:,2:end);
            paramNames = string(paramStruct.paramNames);
            
            switch generalStruct.ModelType
                case 'layers'
                    numberOfLayers = layersStruct.numberOfLayers;
                    
                    if numberOfLayers > 0
                        % Standard layers with layers present
                        for i = 1:layersStruct.numberOfLayers
                            thisLayer = layersValues(i,:);
                            min = find(strcmpi(thisLayer{1},paramNames));
                            val = find(strcmpi(thisLayer{2},paramNames));
                            max = find(strcmpi(thisLayer{3},paramNames));
                            if ismissing(thisLayer(4))
                                hydr = NaN;
                            else
                                hydr = find(strcmpi(thisLayer{4},paramNames));
                            end
                            if strcmpi(thisLayer{5},'bulk in')
                                hydrWhat = 1;
                            else
                                hydrWhat = 2;
                            end
                            layersDetails{i} = [min val max hydr hydrWhat];
                        end
                        layersStruct.layersDetails = layersDetails(:);
                    else
                        % No layers present - still need to set
                        % layersDetails
                        layersStruct.layersDetails = {};
                    end
                otherwise
                    % Not standard layers experiment type
                    layersStruct.layersDetails = {};
            end
            
            % Custom files
            customFileStruct = obj.customFile.toStruct();
            
            % Contrasts.
            allNames = obj.getAllAllowedNames;
            dataTable = obj.data.dataTable;
            
            modelType = generalStruct.ModelType;
            contrastStruct = obj.contrasts.toStruct(allNames,modelType,dataTable);
            
            % Merge all the outputs into one large structure
            outStruct = mergeStructs(generalStruct,...
                paramStruct,...
                backgroundStruct,...
                resolutionStruct,...
                bulkInStruct,...
                bulkOutStruct,...
                scalefactorStruct,...
                qzshiftStruct,...
                layersStruct,...
                customFileStruct,...
                contrastStruct);
            
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
            masterPropList = struct('ModelType',{obj.ModelType},...
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
            
            % There are two versions, depending on whether the model
            % is standard layers or custom, the difference being
            % the display of the layers table..
            
            % Display initial properties
            startProps = getPropertyGroup1(obj);
            matlab.mixin.CustomDisplay.displayPropertyGroups(obj,startProps);
            
            % Display the parameters table
            fprintf('\n    Parameters: ---------------------------------------------------------------------------------------------- \n\n');
            obj.parameters.displayParametersTable;
            
            % Display the layers table if not a custom model
            val = obj.ModelType;
            if ~any(strcmpi(val,{'custom layers','custom xy'}))
                fprintf('\n    Layers: -------------------------------------------------------------------------------------------------- \n\n');
                obj.layers.displayLayersTable;
            end
            
            % Display the Bulk In table
            fprintf('\n    Bulk In: -------------------------------------------------------------------------------------------------- \n\n');
            obj.bulkIn.displayParametersTable;
            
            % Display the Bulk Out table
            fprintf('\n    Bulk Out: ------------------------------------------------------------------------------------------------- \n\n');
            obj.bulkOut.displayParametersTable;
            
            % Display the Scalefactors table
            fprintf('\n    Scalefactors: ------------------------------------------------------------------------------------------------- \n\n');
            obj.scalefactors.displayParametersTable;

            % Display the backgrounds object
            obj.background.displayBackgroundsObject;
            
            % Display the resolutions object
            obj.resolution.displayResolutionsObject;
            
            % Display the data object
            obj.data.displayDataObject;
            
            % Display custome files object
            obj.customFile.displayCustomFileObject;
            
            % Display the contrasts object
            obj.contrasts.displayContrastsObject;
            
        end
        
        
    end
    
end

