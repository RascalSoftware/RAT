classdef projectClass < handle & matlab.mixin.CustomDisplay
    
    % Class definition for Standard Layers with no absorption.
    % Layers defined in terms of thickness, roughness, real SLD and
    % hydration.
    %
    % Sub objects used are:
    % parametersClass      - parameter definition with priors
    % layersClass          - layers defined as (d,rho_real,rough,hydration)
    % backgroundsClass     - 
    % resolutionsClass     -
    % dataClass            -
    % contrastsClass       -
    % customFileClass      -
    
    properties
        experimentName
        geometry
        parameters          % parametersClass object
        layers              % layersClass object
        bulkIn              % parametersClass object
        bulkOut             % parametersClass object
        background          % backgroundsClass object
        scalefactors        % parametersClass object
        qzshifts            % parametersClass object
        resolution          % resolutionClass object
        contrasts           % contrastsClass object
        data                % dataClass object
        customFile          % Custom file object

        modelType = modelTypes.StandardLayers.value
        usePriors = false
    end

    properties (SetObservable, AbortSet)
        absorption {mustBeA(absorption,'logical')} = false
    end

    properties (SetAccess = immutable)
        calculationType
        protectedParameters
    end

    properties(Access = protected, Constant, Hidden)
        classes = struct(name = ["parameters", "bulkIn", "bulkOut", "scalefactors", "qzshifts", "backgroundParams", "resolutionParams", "domainRatio", "layers", "customFile", "backgrounds", "resolutions", "data", "contrast"], ...
                         addRoutine = ["addParameter", "addBulkIn", "addBulkOut", "addScalefactor", "addQzshift", "addBackgroundParam", "addResolutionParam", "addDomainRatio", "addLayer", "addCustomFile", "addBackground", "addResolution", "addData", "addContrast"], ...
                         removeRoutine = ["removeParameter", "removeBulkIn", "removeBulkOut", "removeScalefactor", "removeQzshift", "removeBackgroundParam", "removeResolutionParam", "removeDomainRatio", "removeLayer", "removeCustomFile", "removeBackground", "removeResolution", "removeData", "removeContrast"]);
    end

    methods

        function obj = projectClass(experimentName, calculationType, modelType, geometry, absorption)
            % Creates a Project object. The input arguments are the
            % experiment name which is a char array; the calculation type,
            % which is a calculationTypes enum; the model type,
            % which is a modelTypes enum; the geometry, which is a
            % geometryOptions enum; and a logical to state whether or not
            % absorption terms are included in the refractive index.
            % All of the arguments are optional.
            %
            % problem = projectClass('New experiment');
            arguments
                experimentName {mustBeTextScalar} = ''
                calculationType = calculationTypes.NonPolarised
                modelType = modelTypes.StandardLayers
                geometry = geometryOptions.AirSubstrate
                absorption {mustBeA(absorption,'logical')} = false
            end

            % Validate input options
            invalidTypeMessage = sprintf('calculationType must be a calculationTypes enum or one of the following strings (%s)', ...
                                 strjoin(calculationTypes.values(), ', '));

            obj.calculationType = validateOption(calculationType, 'calculationTypes', invalidTypeMessage).value;

            invalidModelMessage = sprintf('modelType must be a modelTypes enum or one of the following strings (%s)', ...
                                         strjoin(modelTypes.values(), ', '));

            obj.modelType = validateOption(modelType, 'modelTypes', invalidModelMessage).value;

            invalidGeometryMessage = sprintf('geometry must be a geometryOptions enum or one of the following strings (%s)', ...
                                     strjoin(geometryOptions.values(), ', '));

            obj.geometry = validateOption(geometry, 'geometryOptions', invalidGeometryMessage).value;

            obj.experimentName = experimentName;

            % Initialise the Parameters Table
            obj.parameters = parametersClass('Substrate Roughness',1,3,5,true,priorTypes.Uniform,0,Inf);

            if isequal(calculationType, calculationTypes.OilWater.value)
                obj.addParameter('Oil Thickness');
                obj.addParameter('Oil Roughness');
            end
            
            obj.protectedParameters = cellstr(obj.parameters.getNames');

            % Initialise the layers table. Then set the value of
            % absorption, listen for any changes, and modify the layers
            % table accordingly
            if strcmpi(obj.modelType, modelTypes.StandardLayers.value)
                obj.layers = layersClass();
            end
            addlistener(obj, 'absorption', 'PostSet', @obj.modifyLayersTable);
            obj.absorption = absorption;
            
            % Initialise bulkIn table
            obj.bulkIn = parametersClass('SLD Air',0,0,0,false,priorTypes.Uniform,0,Inf);
            
            % Initialise bulkOut table
            obj.bulkOut = parametersClass('SLD D2O',6.2e-6,6.35e-6,6.35e-6,false,priorTypes.Uniform,0,Inf);
            
            % Initialise scalefactors table
            obj.scalefactors = parametersClass('Scalefactor 1',0.02,0.23,0.25,false,priorTypes.Uniform,0,Inf);
            
            % Initialise qzshifts table
            obj.qzshifts = parametersClass('Qz shift 1',-1e-4,0,1e-4,false,priorTypes.Uniform,0,Inf);
            
            % Initialise backgrounds object
            backgroundParams = parametersClass('Background Param 1',1e-7,1e-6,1e-5,false,priorTypes.Uniform,0,Inf);
            backgrounds = {'Background 1',allowedTypes.Constant.value,'Background Param 1','','','',''};
            obj.background = backgroundsClass(backgroundParams, backgrounds);
            
            % Initialise resolution object
            resolutionParams = parametersClass('Resolution par 1',0.01,0.03,0.05,false,priorTypes.Uniform,0,Inf);
            resolutions = {'Resolution 1',allowedTypes.Constant.value,'Resolution par 1','','','',''};
            obj.resolution = resolutionsClass(resolutionParams, resolutions);
            
            % Initialise data object
            obj.data = dataClass('Simulation', [], [], []);

            % Initialise custom file object
            obj.customFile = customFileClass();

            % Initialise contrasts object
            obj.contrasts = contrastsClass();               
        end

        function delete(obj)
            % Destroys the wrappers
            delete(obj.customFile);
        end

        function domainsObj = toDomainsClass(obj)
            % Alias of the converter routine from projectClass to
            % domainsClass.
            % This routine takes the currently defined project and
            % converts it to a domains calculation, preserving all
            % currently defined properties.
            %
            % domainsProblem = problem.toDomainsClass();
            domainsObj = obj.domainsClass();
        end

        function obj = setUsePriors(obj, showFlag)
            % Sets the use priors flag. The showFlag should be a boolean/logical.
            %
            % problem.setUsePriors(true); 
            if ~islogical(showFlag)
                throw(exceptions.invalidType('usePriors must be logical ''true'' or ''false'''));
            end
            obj.usePriors = showFlag;
            
            % Also need to set the flag in sub-objects
            % where relevant..
            % (1) Parameters
            % replace with showFlag
            obj.parameters.showPriors = showFlag;
            
            % (2) Bulk In
            obj.bulkIn.showPriors = showFlag;
            
            % (3) Bulk out
            obj.bulkOut.showPriors = showFlag;
            
            % (4) Scalefactors
            obj.scalefactors.showPriors = showFlag;
            
            % (5) Qz shifts
            obj.qzshifts.showPriors = showFlag;
            
            % (6) Backgrounds (parameters table)
            obj.background.backgroundParams.showPriors = showFlag;
            
            % (7) Resolutions (parameters table)
            obj.resolution.resolutionParams.showPriors = showFlag;
            
        end
        
        function obj = setGeometry(obj, geometry)
            % Sets the experiment geometry. The geometry should be a string,  
            % either "Air/Substrate" or "Substrate/Liquid" is permitted.
            %
            % problem.setGeometry('Substrate/liquid');
            invalidTypeMessage = sprintf('Geometry must be a geometryOptions enum or one of the following strings (%s)', ...
                                         strjoin(geometryOptions.values(), ', '));
            obj.geometry = validateOption(geometry, 'geometryOptions', invalidTypeMessage).value;
        end

        function obj = setModelType(obj, modelType)
            % Sets the experiment type. The type should be a string,  
            % either "standard layers", "custom layers", or "custom xy" is
            % permitted.
            %
            % problem.setModelType('Custom Layers');
            oldModel = obj.modelType;
            invalidTypeMessage = sprintf('Experiment type must be a modelTypes enum or one of the following strings (%s)', ...
                                         strjoin(modelTypes.values(), ', '));
            obj.modelType = validateOption(modelType, 'modelTypes', invalidTypeMessage).value;

            % Need to adjust layers and contrasts for new model type
            if ~strcmpi(obj.modelType, oldModel)
                for i=1:obj.contrasts.numberOfContrasts
                    obj.contrasts.contrasts{i}.model = '';
                end
            end

            if strcmpi(obj.modelType, modelTypes.StandardLayers.value)
                if ~isa(obj.layers, 'layersClass')
                    obj.layers = layersClass();
                end
            else
                obj.layers = [];
            end
        end

        function names = getAllAllowedNames(obj)     
            % Returns a cell array of all currently
            % set parameter names for the project.
            names.paramNames = obj.parameters.getNames();
            names.backgroundNames = obj.background.getNames();
            names.backgroundParamNames = obj.background.backgroundParams.getNames();
            names.bulkInNames = obj.bulkIn.getNames();
            names.bulkOutNames = obj.bulkOut.getNames();
            names.resolutionNames = obj.resolution.getNames();
            names.resolutionParamNames = obj.resolution.resolutionParams.getNames();
            names.dataNames = obj.data.getNames();
            names.scalefactorNames = obj.scalefactors.getNames();
            names.qzShiftNames = obj.qzshifts.getNames();
            names.customFileNames = obj.customFile.getNames();
            if isa(obj.layers, 'layersClass')
                names.layerNames = obj.layers.getNames();
            end
        end
        
        % ---------------------------------  
        % Editing Parameters Block
        
        function obj = addParameterGroup(obj, paramGroup)
            % Adds a group of parameters to the parameters object.
            % Expects a cell array of parameter cell arrays.
            %
            % problem.addParameterGroup({{'Tails Thickness'}, {'Heads Thickness'}});
            for i = 1:length(paramGroup)
                if iscell(paramGroup{i})
                    obj = addParameter(obj, paramGroup{i});
                else
                    throw(exceptions.invalidType('Expecting a cell array of parameters in ''addParameterGroup'''));
                end
            end
        end
        
        
        function obj = addParameter(obj, varargin)
            % Adds an individual parameter to the parameters object.
            % Check how many parameters we are adding and make sure all 
            % the inputs are cells. A parameter consists of a name, min,
            % value, max, fit flag, prior type', mu, and sigma. The input 
            % is optional but if provided should contain 1, 2, 4, 5, or 8 
            % values of the parameter to added.
            %
            % problem.addParameter('Tails Roughness');  
            if isempty(varargin)
                obj.parameters.addParameter();
            else
                if length(varargin) == 1 && iscell(varargin{:})
                    params = varargin{:};
                else
                    params = varargin;
                end
                obj.parameters.addParameter(params{:});
            end 
        end
                
        function obj = removeParameter(obj, row)
            % Removes a parameter from the parameters object. The 
            % parameter will also be removed from the layers array 
            % if it is in use. Expects series of indices or names of
            % parameters to remove
            %
            % problem.removeParameter(2);
            if isa(row, 'double')
                row = num2cell(sort(row, 'descend'));
            elseif isText(row)
                row = cellstr(row);
            elseif iscell(row)
            else
                throw(exceptions.invalidType('Unrecognised Row'))
            end

            for i = 1:length(row)
                thisParam = row{i};
                
                % Make sure we don't remove any protected parameters
                if (isnumeric(thisParam) && thisParam <= length(obj.protectedParameters)) || any((strcmpi(thisParam, obj.protectedParameters)))
                    throw(exceptions.invalidOption(sprintf('Can''t remove protected parameters')));
                end
                
                % No need to check validity of the parameter
                % as this is done in the parameters class
                obj.parameters.removeParameter(thisParam);
                
                % Need to check if it is used in the layers
                % array and remove it if so. Should be able
                % to do this with array indexing, but can't quite figure
                % that out atm, so just use a (dirty) loop over all
                % the elements for now..
                if isa(obj.layers, 'layersClass')
                    findParam = string(thisParam);
                    laysTable = obj.layers.varTable;
                    dims = size(laysTable);
                    for m = 1:dims(1)
                        for n = 1:dims(2)
                            tablePar = laysTable{m,n};   % Should be a string
                            if isequal(findParam, tablePar)
                                obj.layers.varTable(m,n) = {''};
                            end
                        end
                    end
                end
            end
            
        end
        
        function obj = setParameter(obj, row, varargin)
            % General purpose set parameter method. Expects
            % index or name of parameter and keyword/value pairs to set
            %
            % problem.setParameter(2, 'value', 50);
            obj.parameters.setParameter(row, varargin{:});
        end
        
        
        function obj = setParameterValue(obj, row, value)
            % Sets the value of a given parameter. Expects
            % index or name of parameter and new value to set
            %
            % problem.setParameterValue(2, 50);
            obj.parameters.setValue(row, value);
        end
        
        function obj = setParameterLimits(obj, row, min, max)
            % Sets the limits of an existing parameter.
            % Expects index or name of parameter and new min 
            % and max of the parameter's value
            %
            % problem.setParameterLimits(2, 0, 100);
            obj.parameters.setLimits(row, min, max);
        end
        
        function obj = setParameterName(obj, row, name)
            % Sets the name of an existing parameter
            % Expects index or name of parameter and the
            % new name
            %
            % problem.setParameterName(2, 'new name');
            if (isnumeric(row) && row <= length(obj.protectedParameters)) || any((strcmpi(row, obj.protectedParameters)))
                throw(exceptions.invalidOption('Can''t rename protected parameters'));
            end
            obj.parameters.setName(row, name);
        end
        
        function obj = setParameterFit(obj, row, fitFlag)
            % Sets the 'fit' to off or on for parameter.
            % Expects index or name of parameter and 
            % new fit flag
            %
            % problem.setParameterFit(2, true);
            obj.parameters.setFit(row, fitFlag);
        end
        
        function obj = setParameterPrior(obj, row, varargin)
            % Sets the prior type of the parameter.
            % Expects index or name of parameter and 
            % new prior type('uniform','gaussian','jeffreys')
            %
            % problem.setParameterPrior(2, 'uniform');        
            obj.parameters.setPrior(row, varargin{:});  
        end
        
        % -----------------------------------------------------
        
        % Editing of layers block
        function obj = addLayerGroup(obj, layerGroup)
            % Adds a group of layers to the layers object. Expects 
            % a cell array of layer cell arrays
            %
            % problem.addLayerGroup({{'Layer 1'}, {'Layer 2'}});
            if isa(obj.layers, 'layersClass')
                for i = 1:length(layerGroup)
                    if iscell(layerGroup{i})
                        obj = addLayer(obj, layerGroup{i});
                    else
                        throw(exceptions.invalidType('Expecting a cell array of parameters in ''addLayerGroup'''));
                    end
                end
            else
                throw(exceptions.invalidProperty(sprintf('Layer are not defined for the model type: %s', obj.modelType)));
            end
        end
        
        function obj = addLayer(obj, varargin)
            % Adds a single layer to the layers object. Expects layer
            % details which are name, thickness, SLD, roughness,
            % hydration, and hydrate with, or provide with no details,
            % or just a name, to create an empty layer.
            %
            % problem.addLayer('New Layer');
            if isa(obj.layers, 'layersClass')
                if isempty(varargin)
                    obj.layers.addLayer(obj.parameters.varTable{:,1});
                else
                    % If the input is wrapped in a cell (so varargin is a cell of a cell)
                    % need to unwrap one layer of it, otherwise keep varargin as it is
                    if length(varargin) == 1 && iscell(varargin{:})
                        thisLayer = varargin{:};
                    else
                        thisLayer = varargin;
                    end
                    obj.layers.addLayer(obj.parameters.varTable{:,1}, thisLayer{:});
                end
            else
                throw(exceptions.invalidProperty(sprintf('Layer are not defined for the model type: %s', obj.modelType)));
            end
        end

        function obj = removeLayer(obj, layer)
            % Removes layer(s) from the layers object. Expects
            % index of layer(s) to remove.
            %
            % problem.removeLayer(1);
            if isa(obj.layers, 'layersClass')
                obj.layers.removeRow(layer);
            else
                throw(exceptions.invalidProperty(sprintf('Layer are not defined for the model type: %s', obj.modelType)));
            end
        end

        function obj = setLayerValue(obj, row, col, value)
            % Sets a value of a given layer. Expects the row/name and
            % column of layer value to set, then the name/index of the 
            % parameter to set the value to.
            % 
            % problem.setLayerValue(1, 2, 'Tails Thickness');
            if isa(obj.layers, 'layersClass')
                obj.layers.setLayerValue(row, col, value, obj.parameters.varTable{:,1});
            else
                throw(exceptions.invalidProperty(sprintf('Layer are not defined for the model type: %s', obj.modelType)));
            end
        end
        
        % ---------------------------------------------------------------
        
        % Editing of Backgrounds block
        
        
        %(1) Background Parameters
        function obj = addBackgroundParam(obj, varargin)
            % Adds a new background parameter. A parameter consists 
            % of a name, min, value, max, fit flag, prior type', mu,
            % and sigma
            %
            % problem.addBackgroundParam('Backs Value D2O', 1e-8, 2.8e-6, 1e-5);
            obj.background.backgroundParams.addParameter(varargin{:});
        end
        
        function obj = removeBackgroundParam(obj, varargin)
            % Removes a given background parameter.
            % Expects index or name of parameter to remove
            % 
            % problem.removeBackgroundParam(2);
            obj.background.backgroundParams.removeParameter(varargin{:});
        end
        
        function obj = setBackgroundParamValue(obj, row, value)
            % Sets the value of existing background            
            % parameter. Expects index or name of parameter 
            % and new value to set
            %
            % problem.setBackgroundParamValue(1, 5.5e-6);
            obj.background.backgroundParams.setValue(row, value);
        end
        
        function obj = setBackgroundParamLimits(obj, row, min, max)
            % Sets the constraints of existing background
            % parameter. Expects index or name of parameter 
            % and new min and max of the parameter's value
            %
            % problem.setBackgroundParamLimits(1, 0, 1);
            obj.background.backgroundParams.setLimits(row, min, max);
        end
        
        function obj = setBackgroundParamName(obj, row, name)
            % Sets the name of an existing background 
            % parameter. Expects index or name of parameter 
            % and the new name
            %
            % problem.setBackgroundParamName(2, 'new name');
            obj.background.backgroundParams.setName(row, name);
        end
        
        % (2) Backgrounds
        function obj = addBackground(obj, varargin)
            % Adds a background to the project. Expects a 
            % cell array with background name and type and 
            % up to 4 parameters
            %
            % problem.addBackground('name', 'constant', 'par');
            obj.background.addBackground(varargin{:});
        end
        
        function obj = removeBackground(obj, row)
            % Removes background from the project. Expects
            % index or array of indices of background(s) of background(s)
            % to remove
            %
            % problem.removeBackground(1);
            obj.background.removeBackground(row);
        end
        
        function obj = setBackground(obj, row, varargin)
            % Sets the value of an existing background. Expects
            % index or name of background and keyword/value pairs to set
            %
            % problem.setBackground(1, 'name', 'Background ACMW');
            obj.background.setBackground(row, varargin{:});
        end
        
        function obj = setBackgroundName(obj, row, name)
            % Sets the name of an existing Background.
            % Expects index or name of background and the new name
            %
            % problem.setBackgroundName(2, 'new name');
            obj.background.setBackgroundName(row, name);
        end
        
        function obj = setBackgroundParam(obj, varargin)
            % Sets the value of an existing background parameter. Expects
            % index or name of parameter and keyword/value pairs to set
            %
            % problem.setBackgroundParam(1, 'name', 'Backs Value H2O');
            obj.background.backgroundParams.setParameter(varargin{:});
        end
        
        % -------------------------------------------------------------
        %   Editing of Resolutions block
        
        % Resol Pars
        function obj = setResolutionParamValue(obj, row, value)
            % Sets the value of existing resolution            
            % parameter. Expects index or name of parameter 
            % and new value to set
            %
            % problem.setResolutionParamValue(1, 5.5e-6);
            obj.resolution.resolutionParams.setValue(row, value);
        end
        
        function obj = addResolutionParam(obj, varargin)
            % Adds a new resolution parameter. A parameter consists 
            % of a name, min, value, max, fit flag, prior type', mu,
            % and sigma
            %
            % problem.addResolutionParam('Resolution Param 1', 1e-8, 2.8e-6, 1e-5);
            obj.resolution.resolutionParams.addParameter(varargin{:});
        end
        
        function obj = setResolutionParam(obj, varargin)
            % Sets the value of an existing resolution parameter. Expects
            % index or name of parameter and keyword/value pairs to set
            %
            % problem.setResolutionParam(1, 'name', 'Resolution Param');
            obj.resolution.resolutionParams.setParameter(varargin{:});
        end
        
        function obj = removeResolutionParam(obj, varargin)
            % Removes a given resolution parameter.
            % Expects index or name of parameter to remove
            % 
            % problem.removeResolutionParam(2);
            obj.resolution.resolutionParams.removeParameter(varargin{:});
        end
        
        % Resolutions
        function obj = addResolution(obj, varargin)
            % Adds a resolution to the project. Expects a 
            % cell array with resolution name and type and 
            % up to 4 parameters
            %
            % problem.addResolution('name','constant','par');
            obj.resolution.addResolution(varargin{:});
        end
        
        function obj = removeResolution(obj, row)
            % Removes resolution from the project. Expects
            % index of resolution to remove
            %
            % problem.removeResolution(1);
            obj.resolution.removeResolution(row);
        end
        
        
        % ------------------------------------------------------------
        %   Editing of Data block
        
        function obj = addData(obj, varargin)
            % Adds a new data parameter. Expects the name
            % of data and the data array
            % 
            % problem.addData('Sim 2', data);
            obj.data.addData(varargin{:});
        end
        
        function obj = removeData(obj, row)
            % Removes a dataset. Expects the index or array of
            % indices of dataset(s) to remove.
            % 
            % problem.removeData(2);
            obj.data.removeRow(row);
        end
        
        function obj = setData(obj, varargin)
            % Edits an existing data parameter. Expects the
            % index of data to edit and key-value pairs
            %
            % problem.setData(1, 'name', 'Sim 1', 'data', zeros(4, 3));
            nameChanged = obj.data.setData(varargin{:});
            
            if ~isempty(nameChanged)
                obj.contrasts.updateDataName(nameChanged);
            end
        end
        
        
        % ---------------------------------------------------------------
        %   Editing of Bulk out block
        
        function obj = addBulkOut(obj, varargin)
            % Adds a new bulk-out parameter. Expects the name
            % of bulk-out, min, value, max, and if fit is off or on
            % 
            % problem.addBulkOut('SLD ACMW', -1e-6, 0.0, 1e-6, true);
            obj.bulkOut.addParameter(varargin{:});
        end
        
        function obj = removeBulkOut(obj, varargin)
            % Removes specified bulk-out parameter. Expects the name/index
            % of bulk-out to remove
            % 
            % problem.removeBulkOut(2);
            obj.bulkOut.removeParameter(varargin{:});
        end
        
        function obj = setBulkOut(obj, varargin)
            % Edits an existing bulk-out parameter. Expects the
            % index of bulk-out to edit and key-value pairs
            %
            % problem.setBulkOut(1, 'name', 'SLD H2O', 'min', 2.07e-6);
            obj.bulkOut.setParameter(varargin{:});
        end
        
        
        % ------------------------------------------------------------------
        % Editing of bulk in block
        
        function obj = addBulkIn(obj, varargin)
            % Adds a new bulk-in parameter. Expects the name
            % of bulk-in, min, value, max, and if fit is off or on
            % 
            % problem.addBulkIn('Silicon', -1e-6, 0.0, 1e-6, true);
            obj.bulkIn.addParameter(varargin{:});
        end
        
        function obj = removeBulkIn(obj, varargin)
            % Removes specified bulk-in parameter. Expects the name/index
            % of bulk-in to remove
            % 
            % problem.removeBulkIn(2);
            obj.bulkIn.removeParameter(varargin{:});
        end
        
        function obj = setBulkIn(obj, varargin)
            % Edits an existing bulk-in parameter. Expects the
            % index of bulk-in to edit and key-value pairs
            %
            % problem.setBulkIn(1, 'name', 'Silicon', 'max', 2.07e-6);
            obj.bulkIn.setParameter(varargin{:});
        end
        
        % -------------------------------------------------------------------
        % Editing of scalefactors block
        
        function obj = addScalefactor(obj, varargin)
            % Adds a new scale factor parameter. Expects the name
            % of scale factor, min, value, max, and if fit is off or on
            % 
            % problem.addScalefactor('Scalefactor 2', 0.1, 0.19, 1.0, true);
            obj.scalefactors.addParameter(varargin{:});
        end
        
        function obj = removeScalefactor(obj, varargin)
            % Removes specified scale factor parameter. Expects the name/index
            % of scale factor to remove
            % 
            % problem.removeScalefactor(2);
           obj.scalefactors.removeParameter(varargin{:}); 
        end
        
        function obj = setScalefactor(obj, varargin)
            % Edits an existing scale factor parameter. Expects the
            % index of scale factor to edit and key-value pairs
            %
            % problem.setScalefactor(1, 'name','Scalefactor 1', 'value', 0.23251);
            obj.scalefactors.setParameter(varargin{:});
        end
        

        % -----------------------------------------------------------------
        % Editing of qzshifts block
        
        function obj = addQzshift(obj, varargin)
            % Adds a new qz shift parameter. Expects the name
            % of qz shift, min, value, max, and if fit is off or on
            % 
            % problem.addQzshift('Qz shift 2', -0.2e-4, 0, 2e-4, false);
            obj.qzshifts.addParameter(varargin{:}); 
        end

        function obj = removeQzshift(obj, varargin)
            % Removes specified qz shift parameter. Expects the name/index
            % of qz shift parameter to remove
            % 
            % problem.removeQzshift(2);
            obj.qzshifts.removeParameter(varargin{:}); 
        end

        function obj = setQzshift(obj, varargin)
            % Edits an existing qz shift parameter. Expects the index of
            % qz shift parameter to edit and key-value pairs
            %
            % problem.setScalefactor(1, 'name','Qz shift 1', 'value', 0.0001);
            obj.qzshifts.setParameter(varargin{:});
        end

        
        % -----------------------------------------------------------------
        % editing of custom models block
        
        function obj = addCustomFile(obj, varargin)            
            % Adds a new custom file parameter. Expects a parameter name, filename, 
            % language (matlab, octave, or cpp), and working directory
            % 
            % problem.addCustomFile('model 1', 'custom.m', 'matlab', 'pwd');
            obj.customFile.addCustomFile(varargin{:});
        end

        function obj = removeCustomFile(obj, row)
            % Removes custom file entry(ies) from the custom files object.
            % Expects index of entry(ies) to remove.
            %
            % problem.removeCustomFile(1);
            obj.customFile.removeRow(row);
        end

        function obj = setCustomFile(obj, row, varargin)
            % Edits an existing custom file parameter. Expects the
            % index of custom file to edit and key-value pairs
            %
            % problem.setCustomFile(2, 'filename', 'custom.cpp');
            obj.customFile.setCustomFile(row, varargin{:});
        end
        
        
        % ----------------------------------------------------------------
        %
        %   Editing of Contrasts Block
        
        function obj = addContrast(obj, varargin)
            % Adds a new contrast parameter. Expects a parameter name, and with 
            % key-value pairs with one or more of the following "data",
            % "background", "bulk in", "bulk out", "scalefactor",
            % "resolution", "resample", "model"
            % 
            % problem.addContrast('contrast 1', 'bulkIn', 'Silicon');
            allowedNames = obj.getAllAllowedNames();
            obj.contrasts.addContrast(allowedNames, varargin{:});   
        end

        function obj = removeContrast(obj, row)
            % Removes a specified contrast parameter. Expects
            % index or name of resolution to remove
            %
            % problem.removeContrast(1);
            obj.contrasts.removeContrast(row);
        end

        function obj = setContrast(obj, row, varargin)   
            % Allow setting of all parameters in terms of name value pairs.
            % First input must be contrast number or name, subsequent
            % inputs are name / value pairs for the parts involved
            %
            % problem.setContrast(1, 'name', 'contrast')
                        
            % Get the list of allowed values depending on what is
            % set for the other contrasts.
            allowedValues = obj.getAllAllowedNames;
            
            % Call the setContrast method
            obj.contrasts.setContrast(row, allowedValues, varargin{:});
        end
        
        function obj = setContrastModel(obj, row, model)
            % Edits the model of an existing contrast parameter. Expects
            % the index of contrast parameter and cell array of layer names
            %
            % problem.setContrastModel(1, {'layer 1'})
                        
            % Make a different allowed list depending on whether 
            % it is custom or layers
            if strcmpi(obj.modelType, modelTypes.StandardLayers.value)
                % Standard Layers
                allowedValues = obj.layers.getNames();
            else
                % Custom models
                allowedValues = obj.customFile.getNames();
            end
            
            % Call the setContrastModel method
            obj.contrasts.setContrastModel(row, obj.modelType, allowedValues, model);
        end

        % ----------------------------------------------------------------

        function outStruct = toStruct(obj)    
            % Converts the class parameters into a struct array for input
            % into the RAT toolbox
            
            % Set which type of experiment this is
            generalStruct.experimentName = obj.experimentName;
            generalStruct.TF = obj.calculationType;
            
            % Add the 'general' fields
            generalStruct.modelType = lower(obj.modelType);  
            generalStruct.geometry = obj.geometry;

            % Set useImaginary flag
            generalStruct.useImaginary = obj.absorption;
            
            % Parameters
            params = obj.parameters.toStruct();
            paramStruct = cell2struct(struct2cell(params),{'paramNames',...
                'paramLimits','paramValues','fitParam','param'});
            
            % Backgrounds
            backgroundStruct = obj.background.toStruct();
            
            % Resolutions
            resolutionStruct = obj.resolution.toStruct();
            
            % Bulk in
            bulkInStruct = obj.bulkIn.toStruct();
            bulkInStruct = cell2struct(struct2cell(bulkInStruct),{'bulkInNames',...
                'bulkInLimits','bulkInValues','fitBulkIn','bulkIn'});
            
            % Bulk out
            bulkOutStruct = obj.bulkOut.toStruct();
            bulkOutStruct = cell2struct(struct2cell(bulkOutStruct),{'bulkOutNames',...
                'bulkOutLimits','bulkOutValues','fitBulkOut','bulkOut'});
            
            % Scalefactors
            scalefactorStruct = obj.scalefactors.toStruct();
            scalefactorStruct = cell2struct(struct2cell(scalefactorStruct),{'scalefactorNames',...
                'scalefactorLimits','scalefactorValues','fitScalefactor','scalefactor'});
            
            % Qzshifts
            qzshiftStruct = obj.qzshifts.toStruct();
            qzshiftStruct = cell2struct(struct2cell(qzshiftStruct),{'qzshiftNames',...
                'qzshiftLimits','qzshiftValues','fitQzshift','qzshift'});
            
            % Layers
            if isa(obj.layers, 'layersClass')
                layersStruct = obj.layers.toStruct(paramStruct.paramNames);
            else
                layersStruct.numberOfLayers = 0;
                layersStruct.layerNames = strings(0,1);
                layersStruct.layerDetails = {};
            end

            % Custom files
            customFileStruct = obj.customFile.toStruct();
            
            % Contrasts
            allNames = obj.getAllAllowedNames;
            dataTable = obj.data.varTable;
            
            contrastStruct = obj.contrasts.toStruct(allNames, generalStruct.modelType, dataTable);

            % Merge all the outputs into one large structure
            outStruct = mergeStructs(generalStruct, ...
                                     paramStruct, ...
                                     backgroundStruct, ...
                                     resolutionStruct, ...
                                     bulkInStruct, ...
                                     bulkOutStruct, ...
                                     scalefactorStruct, ...
                                     qzshiftStruct, ...
                                     layersStruct, ...
                                     customFileStruct, ...
                                     contrastStruct);
            
        end

        function writeScript(obj, options)
            % Writes a MATLAB script that can be run to reproduce this
            % projectClass object.
            %
            % problem.writeScript(script = "newScript.m");
            arguments
                obj
                options.objName {mustBeTextScalar} = 'problem'
                options.script {mustBeTextScalar} = 'projectScript.m'
            end

            % Need to ensure correct format for script name
            [filePath, fileName, extension] = fileparts(options.script);
            
            % The empty string fails "isempty", so need to test for it
            % explicitly
            if strcmp(extension, "")
                % Add the correct extension
                fileName = sprintf('%s.m', fileName);
                options.script = fullfile(filePath, fileName);
            elseif ~strcmp(extension, ".m")
                % Raise error if incorrect format is used
                throw(exceptions.invalidValue(sprintf('The filename chosen for the script has the "%s" extension, rather than a MATLAB ".m" extension', extension)));
            end

            fileID = fopen(options.script, 'w');
            fprintf(fileID, "%s\n\n", '% THIS FILE IS GENERATED FROM RAT VIA THE "WRITESCRIPT" ROUTINE. IT IS NOT PART OF THE RAT CODE.');

            % Start by getting input arguments
            projectSpec = "%s = createProject(name='%s', calcType='%s', model='%s', geometry='%s', absorption=%s);\n\n";
            fprintf(fileID, projectSpec, options.objName, obj.experimentName, obj.calculationType,  obj.modelType, obj.geometry,  string(obj.absorption));
            if obj.usePriors
                fprintf(fileID, "%s.setUsePriors(true);\n\n", options.objName);
            end

            % Add all parameters, with different actions for protected
            % parameters
            paramGroup = cell(sum(~strcmpi(obj.parameters.varTable{:, 1}, obj.protectedParameters)), 1);
            groupIndex = 1;
            for i=1:height(obj.parameters.varTable)
                % Set protected parameters
                if any(strcmpi(obj.parameters.varTable{i, 1}, obj.protectedParameters))
                    fprintf(fileID, options.objName + ".setParameterValue(%d, %.15g);\n", i, obj.parameters.varTable{i, 3});
                    fprintf(fileID, options.objName + ".setParameterLimits(%d, %.15g, %.15g);\n", i, obj.parameters.varTable{i, 2}, obj.parameters.varTable{i, 4});
                    fprintf(fileID, options.objName + ".setParameterFit(%d, %s);\n", i, string(obj.parameters.varTable{i, 5}));
                    fprintf(fileID, options.objName + ".setParameterPrior(%d, '%s', %.15g, %.15g);\n", i, obj.parameters.varTable{i, 6}, obj.parameters.varTable{i, 7}, obj.parameters.varTable{i, 8});
                % Add non-protected parameters to a parameter group
                else
                    paramRow = table2cell(obj.parameters.varTable(i, :))';
                    paramRow{5} = string(paramRow{5});
                    paramGroup{groupIndex} = paramRow;
                    groupIndex = groupIndex + 1;
                end
            end

            fprintf(fileID, "\n");

            % Write the parameter group to the script
            if size(paramGroup, 1) > 0
                fprintf(fileID, "paramGroup = {\n");
                for i = 1:size(paramGroup, 1)
                    paramSpec = blanks(14) + "{'%s', %.15g, %.15g, %.15g, %s, '%s', %.15g, %.15g};\n";
                    fprintf(fileID, paramSpec, paramGroup{i}{:});
                end
                fprintf(fileID, blanks(14) + "%s\n\n", "};");
                fprintf(fileID, options.objName + ".addParameterGroup(paramGroup);\n");
            end

            fprintf(fileID, "\n");

            % Add all parameters based on a parametersClass
            paramClasses = ["bulkIn", "bulkOut", "scalefactors", "qzshifts", "background", "resolution"];
            paramSubclasses = ["", "", "", "", "backgroundParams", "resolutionParams"];

            if isprop(obj, 'domainRatio')
                paramClasses(end + 1) = "domainRatio";
                paramSubclasses(end + 1) = "";
            end

            for i=1:length(paramClasses)

                if isprop(obj.(paramClasses(i)), 'varTable')

                    removeRoutine = obj.classes.removeRoutine(obj.classes.name == paramClasses(i));
                    addRoutine = obj.classes.addRoutine(obj.classes.name == paramClasses(i));
                    numParams = height(obj.(paramClasses(i)).varTable);
                    paramTable = table2cell(obj.(paramClasses(i)).varTable)';

                elseif isprop(obj.(paramClasses(i)).(paramSubclasses(i)), 'varTable')

                    removeRoutine = obj.classes.removeRoutine(obj.classes.name == paramSubclasses(i));
                    addRoutine = obj.classes.addRoutine(obj.classes.name == paramSubclasses(i));
                    numParams = height(obj.(paramClasses(i)).(paramSubclasses(i)).varTable);
                    paramTable = table2cell(obj.(paramClasses(i)).(paramSubclasses(i)).varTable)';

                end

                % Remove default parameter
                fprintf(fileID, options.objName + "." + removeRoutine + "(1);\n");
                % Convert logical parameter
                for j=1:numParams
                    paramTable{5, j} = string(paramTable{5, j});
                end
                % Add the parameters that have been defined
                paramSpec = options.objName + "." + addRoutine + "('%s', %.15g, %.15g, %.15g, %s, '%s', %.15g, %.15g);\n";
                fprintf(fileID, paramSpec, paramTable{:});
                fprintf(fileID, "\n");

            end

            % Now deal with classes where all of the fields are strings
            stringClasses = ["customFile", "background", "resolution"];
            stringSubclasses = ["", "backgrounds", "resolutions"];

            if isa(obj.layers, 'layersClass')
                stringClasses = ["layers", stringClasses];
                stringSubclasses = ["", stringSubclasses];
            end

            fprintf(fileID, options.objName + ".removeBackground(1);\n");
            fprintf(fileID, options.objName + ".removeResolution(1);\n");
            fprintf(fileID, "\n");

            for i=1:length(stringClasses)
                stringTable = table();

                if isprop(obj.(stringClasses(i)), 'varTable')

                    addRoutine = obj.classes.addRoutine(obj.classes.name == stringClasses(i));
                    numCols = width(obj.(stringClasses(i)).varTable);
                    stringTable = table2array(obj.(stringClasses(i)).varTable)';

                elseif isprop(obj.(stringClasses(i)).(stringSubclasses(i)), 'varTable')

                    addRoutine = obj.classes.addRoutine(obj.classes.name == stringSubclasses(i));
                    numCols = width(obj.(stringClasses(i)).(stringSubclasses(i)).varTable);
                    stringTable = table2array(obj.(stringClasses(i)).(stringSubclasses(i)).varTable)';

                end

                % Add parameters if any have been defined
                if ~isempty(stringTable)
                    stringSpec = options.objName + "." + addRoutine + "(" + join(repmat("'%s'", 1, numCols), ", ") + ");\n";
                    fprintf(fileID, stringSpec, stringTable);
                    fprintf(fileID, "\n");
                end

            end

            % Data class requires writing and reading the data
            fprintf(fileID, options.objName + ".removeData(1);\n");

            for i=1:obj.data.rowCount

                % Write and read data if it exists, else add an empty,
                % named row
                if isempty(obj.data.varTable{i, 2}{:})
                    fprintf(fileID, options.objName + ".addData('%s');\n", obj.data.varTable{i, 1});
                else
                    writematrix(obj.data.varTable{i, 2}{:}, "data_" + string(i) + ".dat");
                    fprintf(fileID, "data_%d = readmatrix('%s');\n", i, "data_" + string(i) + ".dat");
                    fprintf(fileID, options.objName + ".addData('%s', data_%d);\n", obj.data.varTable{i, 1}, i);
                end

                % Also need to set dataRange and simRange explicitly as they
                % are optional
                if ~isempty(obj.data.varTable{i, 3}{:})
                    fprintf(fileID, options.objName + ".setData(%d, 'dataRange', [%.15g %.15g]);\n", i, obj.data.varTable{i, 3}{:});
                end
                if ~isempty(obj.data.varTable{i, 4}{:})
                    fprintf(fileID, options.objName + ".setData(%d, 'simRange', [%.15g %.15g]);\n", i, obj.data.varTable{i, 4}{:});
                end

                fprintf(fileID, "\n");

            end

            % Contrasts are a cell array rather than a table
            % Need to handle resample and model fields separately
            for i=1:obj.contrasts.numberOfContrasts

                reducedStruct = rmfield(obj.contrasts.contrasts{i}, {'resample', 'model'});
                contrastParams = string(namedargs2cell(reducedStruct));
                contrastSpec = options.objName + ".addContrast(" + join(repmat("'%s'", 1, length(contrastParams)), ", ") + ");\n";
                fprintf(fileID, contrastSpec, contrastParams);
                fprintf(fileID, options.objName + ".setContrast(%d, 'resample', %s);\n", i, string(obj.contrasts.contrasts{i}.resample));
                if ~isempty(obj.contrasts.contrasts{i}.model)
                    fprintf(fileID, options.objName + ".setContrastModel(%d, {" + join(repmat("'%s'", 1, length(obj.contrasts.contrasts{i}.model))) +"});\n", i, obj.contrasts.contrasts{i}.model{:});
                end
                fprintf(fileID, "\n");

            end

            if isprop(obj, 'domainContrasts')
                for i=1:obj.domainContrasts.numberOfContrasts
                    
                    reducedStruct = rmfield(obj.domainContrasts.contrasts{i}, {'model'});
                    contrastParams = string(namedargs2cell(reducedStruct));
                    contrastSpec = options.objName + ".addDomainContrast(" + join(repmat("'%s'", 1, length(contrastParams)), ", ") + ");\n";
                    fprintf(fileID, contrastSpec, contrastParams);
                    if ~isempty(obj.contrasts.contrasts{i}.model)
                        fprintf(fileID, options.objName + ".setDomainContrastModel(%d, {" + join(repmat("'%s'", 1, length(obj.domainContrasts.contrasts{i}.model))) +"});\n", i, obj.domainContrasts.contrasts{i}.model{:});
                    end
                    fprintf(fileID, "\n");
                    
                end
            end
            
            fclose(fileID);

        end
        
    end     % end public methods
    
    % ------------------------------------------------------------------
    
    methods (Access = protected)
        % Display methods
        function group = getPropertyGroup1(obj)
            % Initial Parameters at the start of the class
            masterPropList = struct('modelType',{obj.modelType},...
                'experimentName',{obj.experimentName},...
                'geometry', obj.geometry);
            
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
            % the display of the layers table and domain contrasts.
            
            % Display initial properties
            startProps = getPropertyGroup1(obj);
            matlab.mixin.CustomDisplay.displayPropertyGroups(obj,startProps);
            
            % Display the parameters table
            fprintf('\n    Parameters: ---------------------------------------------------------------------------------------------- \n\n');
            obj.parameters.displayTable;
                        
            % Display the Bulk In table
            fprintf('\n    Bulk In: -------------------------------------------------------------------------------------------------- \n\n');
            obj.bulkIn.displayTable;
            
            % Display the Bulk Out table
            fprintf('\n    Bulk Out: ------------------------------------------------------------------------------------------------- \n\n');
            obj.bulkOut.displayTable;
            
            % Display the Scalefactors table
            fprintf('\n    Scalefactors: ------------------------------------------------------------------------------------------------- \n\n');
            obj.scalefactors.displayTable;

            % Display the domain ratio if defined
            if isprop(obj, 'domainRatio') && isa(obj.domainRatio, 'parametersClass')
                fprintf('\n   Domain Ratios: ----------------------------------------------------------------------------------------------- \n\n');
                obj.domainRatio.displayTable;
            end

            % Display the backgrounds object
            fprintf('\n    Backgrounds: ----------------------------------------------------------------------------------------------- \n\n');
            obj.background.displayBackgroundsObject;
            
            % Display the resolutions object
            fprintf('\n    Resolutions: --------------------------------------------------------------------------------------------- \n\n');
            obj.resolution.displayResolutionsObject;

            % Display the layers table if not a custom model
            if isa(obj.layers, 'layersClass')
                fprintf('\n    Layers: -------------------------------------------------------------------------------------------------- \n\n');
                obj.layers.displayTable;
            end

            % Display custom files object
            fprintf('\n    Custom Files: ------------------------------------------------------------------------------------------------------ \n\n');
            obj.customFile.displayTable;
            
            % Display the data object
            fprintf('\n    Data: ------------------------------------------------------------------------------------------------------ \n\n');
            obj.data.displayTable;
            
            % Display the domainContrasts object if defined
            if isprop(obj, 'domainContrasts') && isa(obj.domainContrasts, 'domainContrastsClass')
                fprintf('\n   Domains Contrasts: ----------------------------------------------------------------------------------------------- \n\n');
                obj.domainContrasts.displayContrastsObject; 
            end
            
            % Display the contrasts object
            fprintf('\n   Contrasts: ----------------------------------------------------------------------------------------------- \n\n');
            obj.contrasts.displayContrastsObject;
            
        end
        
    end

    methods (Access = protected, Hidden)

        function modifyLayersTable(obj,~,~)
            % Add or remove a column from the layers table whenever the
            % "absorption" property is modified.
            if isa(obj.layers, 'layersClass')
                if obj.absorption
                    newCol = repmat("", height(obj.layers.varTable), 1);
                    obj.layers.varTable = addvars(obj.layers.varTable, newCol, 'After', 'SLD', 'NewVariableNames', 'SLD Imaginary');
                    obj.layers.varTable = renamevars(obj.layers.varTable, 'SLD', 'SLD Real');
                else
                    obj.layers.varTable = removevars(obj.layers.varTable, 'SLD Imaginary');
                    obj.layers.varTable = renamevars(obj.layers.varTable, 'SLD Real', 'SLD');
                end
            end
        end

    end

    methods (Hidden)

        function domainsObj = domainsClass(obj)
            % Converter routine from projectClass to domainsClass.
            % This routine takes the currently defined project and
            % converts it to a domains calculation, preserving all
            % currently defined properties.
            %
            % domainsProblem = problem.domainsClass();
            domainsObj = domainsClass(obj.experimentName, calculationTypes.Domains, obj.modelType, obj.geometry, obj.absorption);
            domainsObj = copyProperties(obj, domainsObj);

            % Need to treat contrasts separately due to changes in the
            % class for domains calculations
            domainsObj.contrasts = copyProperties(obj.contrasts, contrastsClass(domains=true, oilWater=obj.contrasts.oilWaterCalc));
            for i=1:domainsObj.contrasts.numberOfContrasts
                domainsObj.contrasts.contrasts{i}.domainRatio = '';
            end
        end

    end

end
