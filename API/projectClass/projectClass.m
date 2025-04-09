classdef projectClass < handle & projectParametersMixin & matlab.mixin.CustomDisplay
    % ``projectClass`` stores all the information that describes the experiment which is essential for running a RAT calculation. There are several components of a 
    % project such as the parameters, backgrounds, resolutions, custom files, data, contrast etc, the ``projectClass`` provides a number of methods to add, remove, 
    % and update these components. For example, for parameters, the ``addParameter``, ``removeParameter``, and ``setParameter`` methods are available for adding, removing,  
    % and updating parameters.
    % 
    % Examples
    % --------
    % >>> project = projectClass();
    % >>> project = projectClass("Example Project");
    % >>> project = projectClass("Example Project", 'custom layers', 'substrate/liquid', true);
    % 
    % Parameters
    % ---------- 
    % experimentName : string or char array, default: ''
    %     The name of the project.
    % modelType : modelTypes, default: modelTypes.StandardLayers
    %     The layer model type which can be 'standard layers', 'custom layers', or 'custom xy'.
    % geometry : geometryOptions, default: geometryOptions.AirSubstrate
    %     The geometry to use which can be 'air/substrate' or 'substrate/liquid'.  
    % absorption : logical, default: false
    %     Indicates whether imaginary component is used for the SLD value in layers.
    % 
    % Attributes
    % ----------
    % parameters : parametersClass
    %     The project parameters. 
    % bulkIn : parametersClass
    %     The bulkIn parameters. 
    % bulkOut : parametersClass
    %     The bulkOut parameters. 
    % scalefactors : parametersClass
    %     The scalefactors parameters. 
    % layers : layersClass
    %     An object which contains the layers information. 
    % data : dataClass
    %     An object which contains the data table. 
    % customFile : Custom file object
    %     An object which contains the defined customFiles. 
    % background : backgroundsClass object
    %     An object which contains defined backgrounds and background parameters. 
    % resolution : resolutionClass object
    %     An object which contains defined resolutions and resolution parameters. 
    % contrasts : contrastsClass object
    %     An object which contains contrast information. 
    
    properties
        experimentName
        modelType
        geometry
        showPriors = false

        layers              % layersClass object
        data                % dataClass object
        customFile          % Custom file object
        background          % backgroundsClass object
        resolution          % resolutionClass object
        contrasts           % contrastsClass object
    end

    properties (AbortSet)
        absorption {mustBeA(absorption,'logical')} = false
    end

    properties (SetAccess = protected)
        calculationType
    end

    properties(Access = protected, Constant, Hidden)
        classes = struct(name = ["parameters", "bulkIn", "bulkOut", "scalefactors", "backgroundParams", "resolutionParams", "domainRatio", "layers", "customFile", "backgrounds", "resolutions", "data", "contrast"], ...
                         addRoutine = ["addParameter", "addBulkIn", "addBulkOut", "addScalefactor", "addBackgroundParam", "addResolutionParam", "addDomainRatio", "addLayer", "addCustomFile", "addBackground", "addResolution", "addData", "addContrast"], ...
                         removeRoutine = ["removeParameter", "removeBulkIn", "removeBulkOut", "removeScalefactor", "removeBackgroundParam", "removeResolutionParam", "removeDomainRatio", "removeLayer", "removeCustomFile", "removeBackground", "removeResolution", "removeData", "removeContrast"])
    end

    methods

        function obj = projectClass(experimentName, modelType, geometry, absorption)
            arguments
                experimentName {mustBeTextScalar} = ''
                modelType = modelTypes.StandardLayers
                geometry = geometryOptions.AirSubstrate
                absorption {mustBeA(absorption, 'logical')} = false
            end
            obj = obj@projectParametersMixin();
            % Validate input options
            invalidModelMessage = sprintf('modelType must be a modelTypes enum or one of the following strings (%s)', ...
                                  strjoin(modelTypes.values(), ', '));

            obj.modelType = validateOption(modelType, 'modelTypes', invalidModelMessage).value;

            invalidGeometryMessage = sprintf('geometry must be a geometryOptions enum or one of the following strings (%s)', ...
                                     strjoin(geometryOptions.values(), ', '));

            obj.geometry = validateOption(geometry, 'geometryOptions', invalidGeometryMessage).value;

            obj.experimentName = experimentName;
            obj.calculationType = calculationTypes.Normal.value;

            % Initialise the layers table. Then set the value of
            % absorption, which will modify the layers table accordingly
            if strcmpi(obj.modelType, modelTypes.StandardLayers.value)
                obj.layers = layersClass();
            end
            obj.absorption = absorption;

            % Initialise data object
            obj.data = dataClass('Simulation', [], [], []);

            % Initialise custom file object
            obj.customFile = customFileClass();
            
            % Initialise backgrounds object
            backgroundParams = parametersClass('Background Param 1',1e-7,1e-6,1e-5,false,priorTypes.Uniform,0,Inf);
            backgrounds = {'Background 1',allowedTypes.Constant.value,'Background Param 1','','','',''};
            obj.background = backgroundsClass(backgroundParams, backgrounds, struct());
            
            % Initialise resolution object
            resolutionParams = parametersClass('Resolution par 1',0.01,0.03,0.05,false,priorTypes.Uniform,0,Inf);
            resolutions = {'Resolution 1',allowedTypes.Constant.value,'Resolution par 1','','','',''};
            obj.resolution = resolutionsClass(resolutionParams, resolutions);

            % Initialise contrasts object
            obj.contrasts = contrastsClass();
        end

        function delete(obj)
            % Destroys the wrappers
            delete(obj.customFile);
        end

        function set.showPriors(obj, flag)
            % Setter for the showPriors property. It indicates whether
            % priors should be visible when printing the project. The flag
            % should be a boolean/logical.
            if ~islogical(flag)
                throw(exceptions.invalidType('Show priors must be true or false'));
            end
            obj.showPriors = flag;
        end

        function set.absorption(obj, absorption)
            % Setter for the absorption property. It states whether we
            % allow an imaginary component for the SLD value in layers.
            % The flag should be a boolean/logical.
            if ~islogical(absorption)
                throw(exceptions.invalidType('absorption must be true or false'));
            end
            obj.absorption = absorption;
            if isa(obj.layers, 'layersClass')
                obj.layers.absorption = absorption;
            end
        end
        
        function set.geometry(obj, geometry)
            % Setter for the experiment geometry. The geometry should be a
            % string, either "Air/Substrate" or "Substrate/Liquid" are
            % permitted.
            invalidTypeMessage = sprintf('Geometry must be a geometryOptions enum or one of the following strings (%s)', ...
                                         strjoin(geometryOptions.values(), ', '));
            obj.geometry = validateOption(geometry, 'geometryOptions', invalidTypeMessage).value;
        end
        
        function set.modelType(obj, modelType)
            % Setter for the model type used in the experiment. The type
            % should be a string, either "standard layers", "custom layers",
            % or "custom xy" are permitted.
            oldModel = obj.modelType;

            invalidTypeMessage = sprintf('Experiment type must be a modelTypes enum or one of the following strings (%s)', ...
                                         strjoin(modelTypes.values(), ', '));
            obj.modelType = validateOption(modelType, 'modelTypes', invalidTypeMessage).value;

            obj.setLayersAndContrasts(oldModel);
        end

        function names = getAllAllowedNames(obj)
            % Returns a struct with all currently set names of normal parameters, background and resolution 
            % parameters, backgrounds, resolutions, bulk-ins, bulk-outs, scalefactors, data, custom files and 
            % contrasts for the project.
            % 
            % Returns
            % -------
            % names : struct
            %     A struct with names of all the normal parameters, background and resolution 
            %     parameters, backgrounds, resolutions, bulk-ins, bulk-outs, scalefactors, data, custom files and 
            %     contrasts entries in the project.
            names.paramNames = obj.parameters.getNames();
            names.backgroundNames = obj.background.getNames();
            names.backgroundParamNames = obj.background.backgroundParams.getNames();
            names.bulkInNames = obj.bulkIn.getNames();
            names.bulkOutNames = obj.bulkOut.getNames();
            names.resolutionNames = obj.resolution.getNames();
            names.resolutionParamNames = obj.resolution.resolutionParams.getNames();
            names.dataNames = obj.data.getNames();
            names.scalefactorNames = obj.scalefactors.getNames();
            names.customFileNames = obj.customFile.getNames();
            if isa(obj.layers, 'layersClass')
                names.layerNames = obj.layers.getNames();
            end
            if strcmpi(obj.modelType, modelTypes.StandardLayers.value)
                if strcmpi(obj.calculationType, calculationTypes.Domains.value)
                    names.modelNames = obj.domainContrasts.getNames();
                else
                    names.modelNames = obj.layers.getNames();
                end
            else
                names.modelNames = obj.customFile.getNames();
            end
        end


        % ---------------------------------------------------------------------------
        % Editing of layers block
        %----------------------------------------------------------------------------
        function obj = addLayerGroup(obj, layerGroup)
            % Adds a group of layers to the project.
            %              
            % Examples
            % --------
            % >>> firstLayer = {'Water Layer', 'Water thickness', 'Water SLD', 'Bilayer heads roughness', 'Water hydration', 'Bulk out'};
            % >>> secondLayer = {'Layer 1', 'Layer thickness', 'Layer Real SLD', 'Layer Imaginary SLD', 'Layers roughness, 'Layer hydration', 'Bulk in'}; 
            % >>> project.addLayerGroup({firstLayer, secondLayer});
            %  
            % Parameters
            % ----------
            % layerGroup : cell of cell array
            %     The inner cells should contain the properties of the layers to add. 
            %
            % project.addLayerGroup({{'Layer 1'}, {'Layer 2'}});
            
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
            % Adds a new layer to the project. This method can be called in 2 ways. The first for when ``absorption`` is false  
            %
            % ``addLayer(name, thickness, realSLD, roughness, hydration, hydrateWith)``
            % 
            % and the second includes an extra argument imaginarySLD for when ``absorption`` is true.
            % 
            % ``addLayer(name, thickness, realSLD, imaginarySLD, roughness, hydration, hydrateWith)``
            %
            % Examples
            % --------
            % To add a new layer with name only.
            % 
            % >>> project.addLayer(, 'New layer');
            % 
            % To add a new layer when ``absorption`` is false.
            % 
            % >>> project.addLayer('Water Layer', 'Water thickness', 'Water SLD', 'Bilayer heads roughness', 'Water hydration', 'Bulk out');
            % 
            % To add a new layer when ``absorption`` is true.
            % 
            % >>> project.addLayer('Layer 1', 'Layer thickness', 'Layer Real SLD', 'Layer Imaginary SLD', 'Layers roughness, 'Layer hydration', 'Bulk in');
            %  
            % Parameters
            % ----------
            % name : string or char array, default: auto-generated name
            %     The name of this layer.
            % thickness : string or char array or whole number, default: ''
            %     The name (or the row index) of the parameter describing the thickness of this layer.
            % realSLD : string or char array or whole number, default: ''
            %     The name (or the row index) of the parameter describing the real (scattering) term
            %     for the scattering length density of this layer.
            % imaginarySLD : string or char array or whole number, default: ''
            %     The name (or the row index) of the parameter describing the imaginary (absorption) term
            %     for the scattering length density of this layer.
            % roughness : string or char array or whole number, default: ''
            %     The name (or the row index) of the parameter describing the roughness of this layer.
            % hydration : string or char array or whole number, default: ''
            %     The name (or the row index) of the parameter describing the percent hydration for the layer
            % hydrateWith : hydrationTypes, default: hydrationTypes.BulkOut
            %     Whether the layer is hydrated with the "bulk in" or "bulk out".

            if isa(obj.layers, 'layersClass')
                % If the input is wrapped in a cell (so varargin is a cell of a cell)
                % need to unwrap one layer of it, otherwise keep varargin as it is
                if isscalar(varargin) && iscell(varargin{:})
                    thisLayer = varargin{:};
                else
                    thisLayer = varargin;
                end
                obj.layers.addLayer(obj.parameters.varTable{:,1}, thisLayer{:});
            else
                throw(exceptions.invalidProperty(sprintf('Layer are not defined for the model type: %s', obj.modelType)));
            end
        end

        function obj = removeLayer(obj, layer)
            % Removes a given layer from the project.
            %
            % Examples
            % --------
            % To remove the second layer in the table (layer in row 2).  
            % 
            % >>> project.removeLayer(2);
            % 
            % To remove layer with a specific name.
            % 
            % >>> project.removeLayer('D2O');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the layer to remove. If it is text, 
            %     it is the name of the layer to remove.
            if isa(obj.layers, 'layersClass')
                obj.layers.removeRow(layer);
            else
                throw(exceptions.invalidProperty(sprintf('Layer are not defined for the model type: %s', obj.modelType)));
            end
        end

        function obj = setLayer(obj, row, varargin)
            % Update properties of an existing layer. 
            % Any unset property will remain unchanged.
            %
            % Examples
            % --------
            % To update the thickness of the second layer in the table (layer in row 2).
            % 
            % >>> project.setLayer(2, thickness='New thickness');
            % 
            % To change the properties of a layer called 'Layer 1'.
            % 
            % >>> project.setLayer('Layer 1', name='new layer', thickness='New thickness', sld='Layer SLD');
            % 
            % To change the imaginary SLD when absorption is true.
            % 
            % >>> project.setLayer('Layer 1', name='new layer', thickness='New thickness', realSLD='Layer SLD', imaginarySLD='Layer Imaginary SLD');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row of the layer to update. If it is text, 
            %     it is the name of the layer to update.
            % varargin
            %    Keyword/value pair to properties to update for the specific parameter.
            %       * name (string or char array or whole number, default: '') the new name of the layer.
            %       * thickness (string or char array or whole number, default: '') The name (or the row index) of the parameter describing the thickness of this layer.
            %       * sld, realSLD (string or char array or whole number, default: '') The name (or the row index) of the parameter describing the real (scattering) term.
            %       * imaginarySLD (string or char array or whole number, default: '') the new name (or the row index) of the parameter describing the imaginary (absorption) term.
            %       * roughness (string or char array or whole number, default: '') the new name (or the row index) of the parameter describing the roughness of this layer.           
            %       * hydration (string or char array or whole number, default: '') the new name (or the row index) of the parameter describing the percent hydration for the layer           
            %       * hydrateWith (hydrationTypes, default: hydrationTypes.empty()) whether the layer is hydrated with the "bulk in" or "bulk out".  
            if isa(obj.layers, 'layersClass')
                obj.layers.setLayer(row, obj.parameters.varTable{:,1}, varargin{:});
            else
                throw(exceptions.invalidProperty(sprintf('Layer are not defined for the model type: %s', obj.modelType)));
            end
        end
        
        % --------------------------------------------------------------- 
        % Editing of Backgrounds block
        
        
        %(1) Background Parameters
        function obj = addBackgroundParam(obj, name, min, value, max, fit, priorType, mu, sigma)
            % Adds a new background parameter to project.
            %
            % Examples
            % --------
            % To add a new background parameter with no properties and an autogenerated name.
            % 
            % >>> project.addBackgroundParam();
            % 
            % To add a background parameter with all available properties.
            % 
            % >>> project.addBackgroundParam('Background Value D2O'', 1e-8, 2.8e-6, 1e-5, true, 'gaussian', 1, 5);
            % 
            % Other examples of adding background parameters with a subset of properties.
            % 
            % >>> project.addBackgroundParam('Background Value D2O');  % Background parameter name only with others set to default
            % >>> project.addBackgroundParam('Background Value D2O', 1e-8);  % Background parameter name and min only. Value and max will be set to 1e-8 to keep limits valid
            % >>> project.addBackgroundParam('Background Value D2O', 1e-8, 2.8e-6, 1e-5, true);  % priors will be default
            % 
            % Parameters
            % ----------
            % name : string or char array, default: auto-generated name
            %     The name of the background parameter. 
            % min : double, default: 0.0
            %     The minimum value that the background parameter could take when fitted.
            % value : double, default: 0.0
            %     The value of the background parameter, default will be equal to ``min`` if this is not set.
            % max : double, default: 0.0
            %     The maximum value that the background parameter could take when fitted, default will be equal to ``value`` if this is not set.
            % fit : logical, default: false
            %     Whether the background parameter should be fitted in a calculation.
            % priorType : PriorTypes, default: PriorTypes.Uniform 
            %     For Bayesian calculations, whether the prior likelihood is assumed to be ‘uniform’, ‘gaussian’, or ‘jeffreys’.
            % mu : double, default: 0.0
            %     If the prior type is Gaussian, the mean of the Gaussian function for the prior likelihood.
            % sigma : double, default: Inf
            %     If the prior type is Gaussian, the standard deviation of the Gaussian function for the prior likelihood.
            arguments
                obj
                name {mustBeTextScalar} = ''
                min {mustBeNumeric, isscalar} = 0.0
                value {mustBeScalarOrEmpty, mustBeNumeric} = []
                max {mustBeScalarOrEmpty, mustBeNumeric} = []
                fit {mustBeA(fit, 'logical')} = false
                priorType = priorTypes.Uniform
                mu {mustBeNumeric, isscalar} = 0.0
                sigma {mustBeNumeric, isscalar} = Inf
            end
            obj.background.backgroundParams.addParameter(name, min, value, max, fit, priorType, mu, sigma);
        end

        function obj = removeBackgroundParam(obj, row)
            % Removes a given background parameter from the project.
            %
            % Examples
            % --------
            % To remove the second background parameter in the table (parameter in row 2).  
            % 
            % >>> project.removeBackgroundParam(2);
            % 
            % To remove background parameter with a specific name.
            % 
            % >>> project.removeBackgroundParam('Background Value D2O');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the background parameter to remove. If it is text, 
            %     it is the name of the background parameter to remove.
            obj.background.backgroundParams.removeParameter(row);
        end

        function obj = setBackgroundParam(obj, row, options)
            % General purpose method for updating properties of an existing parameter. 
            % Any unset property will remain unchanged.
            %
            % Examples
            % --------
            % To change the name and value of the second background parameter in the table (parameter in row 2).
            % 
            % >>> project.setBackgroundParam(2, 'name', 'Background 2', 'value', 50);
            % 
            % To change the all properties of a background parameter called 'Background Value D2O'.
            % 
            % >>> project.setBackgroundParam('Background Value D2O', 'name', 'Background 2', 'min', 20, 'value', 50, 'max', 60, ...
            % >>>                            'fit', true, 'priorType', 'gaussian', 'mu', 1, 'sigma', 5);
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the background parameter to update. If it is text, 
            %     it is the name of the background parameter to update.
            % options
            %    Keyword/value pair to properties to update for the specific background parameter.
            %       * name (char array or string, default: '') the new name of the background parameter.
            %       * min (double, default: []) the new minimum value of the background parameter.
            %       * value (double, default: []) the new value of the background parameter.
            %       * max (double, default: []) the new maximum value of the background parameter.
            %       * fit (logical, default: logical.empty()) the new fit flag of the background parameter.
            %       * priorTypes (priorTypes, default: priorTypes.empty()) the new prior type of the background parameter.            
            %       * mu (double, default: []) the new mean of the Gaussian function for the prior.            
            %       * sigma (double, default: []) The new standard deviation of the Gaussian function for the prior.   
            arguments
                obj
                row
                options.name {mustBeTextScalar} = ''
                options.min {mustBeScalarOrEmpty, mustBeNumeric} = []
                options.value {mustBeScalarOrEmpty, mustBeNumeric} = []
                options.max {mustBeScalarOrEmpty, mustBeNumeric} = []
                options.fit {mustBeScalarOrEmptyLogical} = logical.empty()
                options.priorType = priorTypes.empty()
                options.mu {mustBeScalarOrEmpty, mustBeNumeric} = []
                options.sigma {mustBeScalarOrEmpty, mustBeNumeric} = []
            end
            obj.background.backgroundParams.setParameter(row, name=options.name, min=options.min, value=options.value, ... 
                                                         max=options.max, fit=options.fit, priorType=options.priorType, ...
                                                         mu=options.mu, sigma=options.sigma);
        end
        
        % (2) Backgrounds
        function obj = addBackground(obj, name, type, source, value1, value2, value3, value4, value5)
            % Adds a new background to the project. 
            %
            % Examples
            % --------
            % To add a new constant background with name only.
            % 
            % >>> project.addBackground('New Background');
            % 
            % To add a constant background.
            % 
            % >>> project.addBackground('New Background', 'constant', 'param name');
            % 
            % To add a function background with 2 parameters.
            % 
            % >>> project.addBackground('New Background', 'function', 'function name', 'param name', ''param name 2'');    
            %
            % To add a data background with an offset.
            % 
            % >>> project.addBackground('New Background', 'data', 'data name', 'offset param name');
            % 
            % Parameters
            % ----------
            % name : string or char array, default: auto-generated name
            %     The name of the background. 
            % type : allowedTypes, default: allowedTypes.Constant
            %     The type of background (constant, function or data).
            % source : string or char array or whole number, default: ''
            %     The source of the background. 
            %     if type is 'constant', this should be the name (or the row index) of a background parameter.
            %     if type is 'data', this should be the name (or the row index) of a dataset defined in `projectClass.data`.
            %     if type is 'function', this should be the name (or the row index) of a custom function defined in `projectClass.customFiles`.
            % value1, value2, value3, value4, value5 : string or char array or whole number, default: ''
            %     Any extra values required for the background.
            %     if type is 'constant', all values will be ignored.
            %     if type is 'data', value1 may be the name (or the row index) of a background parameter for an optional offset. Other values are ignored.
            %     if type is 'function', these values may be the names (or the row index) of up to 5 parameters which are passed to the function.
            arguments
                obj
                name {mustBeTextScalar} = ''
                type = allowedTypes.empty()
                source {mustBeScalarTextOrWholeNumber} = ''
                value1 {mustBeScalarTextOrWholeNumber} = ''
                value2 {mustBeScalarTextOrWholeNumber} = ''
                value3 {mustBeScalarTextOrWholeNumber} = ''
                value4 {mustBeScalarTextOrWholeNumber} = ''
                value5 {mustBeScalarTextOrWholeNumber} = ''
            end
            obj.background.addBackground(obj.getAllAllowedNames(), name, type, source, value1, value2, value3, value4, value5);
        end
        
        function obj = removeBackground(obj, row)
            % Removes a background from the project.
            %
            % Examples
            % --------
            % To remove the second background in the table (background in row 2).  
            % 
            % >>> project.removeBackground(2);
            % 
            % To remove background with a specific name.
            % 
            % >>> project.removeBackground('Background 1');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the background to remove. If it is text, 
            %     it is the name of the background to remove.
            obj.background.removeBackground(row);
        end
        
        function obj = setBackground(obj, row, options)
            % General purpose method for updating properties of an existing background.
            %
            % Examples
            % --------
            % To change the name and value of the second background in the table (background in row 2).
            % 
            % >>> backgrounds.setBackground(2, name='Background 1', type='constant', source='param name');
            % 
            % To change the properties of a background called 'Background 1'.
            % 
            % >>> backgrounds.setBackground('Background 1', name='New Background', type='function', source='custom file name', value1='param name');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the background to update. If it is text, 
            %     it is the name of the background to update.
            % options
            %    Keyword/value pair to properties to update for the specific background.
            %       * name (char array or string, default: '') the new name of the background.
            %       * type (allowedTypes, default: allowedTypes.empty()) the type of background (constant, function or data).
            %       * source (char array or string or whole number, default: '') the new source of the background.
            %       * value1, value2, value3, value4, value5 (char array or string or whole number, default: '') any extra values required for the background.
            arguments
                obj
                row
                options.name {mustBeTextScalar} = ''
                options.type = allowedTypes.empty()
                options.source {mustBeScalarTextOrWholeNumber} = ''
                options.value1 {mustBeScalarTextOrWholeNumber} = ''
                options.value2 {mustBeScalarTextOrWholeNumber} = ''
                options.value3 {mustBeScalarTextOrWholeNumber} = ''
                options.value4 {mustBeScalarTextOrWholeNumber} = ''
                options.value5 {mustBeScalarTextOrWholeNumber} = ''
            end
            obj.background.setBackground(row, obj.getAllAllowedNames(), name=options.name, type=options.type, source=options.source, ...
                                         value1=options.value1,  value2=options.value2, value3=options.value3, value4=options.value4, value5=options.value5);
        end
        
        % -------------------------------------------------------------
        % Editing of Resolutions block
        
        % Resolution Params       
        function obj = addResolutionParam(obj, name, min, value, max, fit, priorType, mu, sigma)
            % Adds a new resolution parameter to the project. 
            %
            % Examples
            % --------
            % To add a new resolution parameter with no properties and an autogenerated name.
            % 
            % >>> project.addResolutionParam();
            % 
            % To add a resolution parameter with all available properties.
            % 
            % >>> project.addResolutionParam('Resolution Param 1', 20, 50, 60, true, 'gaussian', 1, 5);
            % 
            % Other examples of adding resolution parameters with a subset of properties.
            % 
            % >>> project.addResolutionParam('Resolution Param 1');  % Resolution parameter name only with others set to default
            % >>> project.addResolutionParam('Resolution Param 1', 23);  % Resolution parameter name and min only. Value and max will be set to 23 to keep limits valid
            % >>> project.addResolutionParam('Resolution Param 1', 23, 24, 25, true);  % priors will be default
            % 
            % Parameters
            % ----------
            % name : string or char array, default: auto-generated name
            %     The name of the resolution parameter. 
            % min : double, default: 0.0
            %     The minimum value that the resolution parameter could take when fitted.
            % value : double, default: 0.0
            %     The value of the resolution parameter, default will be equal to ``min`` if this is not set.
            % max : double, default: 0.0
            %     The maximum value that the resolution parameter could take when fitted, default will be equal to ``value`` if this is not set.
            % fit : logical, default: false
            %     Whether the resolution parameter should be fitted in a calculation.
            % priorType : PriorTypes, default: PriorTypes.Uniform 
            %     For Bayesian calculations, whether the prior likelihood is assumed to be ‘uniform’, ‘gaussian’, or ‘jeffreys’.
            % mu : double, default: 0.0
            %     If the prior type is Gaussian, the mean of the Gaussian function for the prior likelihood.
            % sigma : double, default: Inf
            %     If the prior type is Gaussian, the standard deviation of the Gaussian function for the prior likelihood.
            arguments
                obj
                name {mustBeTextScalar} = ''
                min {mustBeNumeric, isscalar} = 0.0
                value {mustBeScalarOrEmpty, mustBeNumeric} = []
                max {mustBeScalarOrEmpty, mustBeNumeric} = []
                fit {mustBeA(fit, 'logical')} = false
                priorType = priorTypes.Uniform
                mu {mustBeNumeric, isscalar} = 0.0
                sigma {mustBeNumeric, isscalar} = Inf
            end
            obj.resolution.resolutionParams.addParameter(name, min, value, max, fit, priorType, mu, sigma);
        end
        
        function obj = removeResolutionParam(obj, row)
            % Removes a resolution parameter from the project.
            %
            % Examples
            % --------
            % To remove the second resolution parameter in the table (parameter in row 2).  
            % 
            % >>> project.removeResolutionParam(2);
            % 
            % To remove resolution parameter with a specific name.
            % 
            % >>> project.removeResolutionParam('Resolution Param 1');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the resolution parameter to remove. If it is text, 
            %     it is the name of the resolution parameter to remove.
            obj.resolution.resolutionParams.removeParameter(row);
        end

        function obj = setResolutionParam(obj, row, options)
            % General purpose method for updating properties of an existing resolution parameter. 
            % Any unset property will remain unchanged.
            %
            % Examples
            % --------
            % To change the name and value of the second resolution parameter in the table (parameter in row 2).
            % 
            % >>> project.setResolutionParam(2, 'name', 'Resolution Param 1', 'value', 50);
            % 
            % To change the all properties of a resolution parameter called 'Resolution Param 2'.
            % 
            % >>> project.setResolutionParam('Resolution Param 2', 'name', 'Resolution Param 1', 'min', 20, 'value', 50, 'max', 60, ...
            % >>>                            'fit', true, 'priorType', 'gaussian', 'mu', 1, 'sigma', 5);
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the resolution parameter to update. If it is text, 
            %     it is the name of the resolution parameter to update.
            % options
            %    Keyword/value pair to properties to update for the specific resolution parameter.
            %       * name (char array or string, default: '') the new name of the resolution parameter.
            %       * min (double, default: []) the new minimum value of the resolution parameter.
            %       * value (double, default: []) the new value of the resolution parameter.
            %       * max (double, default: []) the new maximum value of the resolution parameter.
            %       * fit (logical, default: logical.empty()) the new fit flag of the resolution parameter.
            %       * priorTypes (priorTypes, default: priorTypes.empty()) the new prior type of the resolution parameter.            
            %       * mu (double, default: []) the new mean of the Gaussian function for the prior.            
            %       * sigma (double, default: []) The new standard deviation of the Gaussian function for the prior.   
            arguments
                obj
                row
                options.name {mustBeTextScalar} = ''
                options.min {mustBeScalarOrEmpty, mustBeNumeric} = []
                options.value {mustBeScalarOrEmpty, mustBeNumeric} = []
                options.max {mustBeScalarOrEmpty, mustBeNumeric} = []
                options.fit {mustBeScalarOrEmptyLogical} = logical.empty()
                options.priorType = priorTypes.empty()
                options.mu {mustBeScalarOrEmpty, mustBeNumeric} = []
                options.sigma {mustBeScalarOrEmpty, mustBeNumeric} = []
            end
            obj.resolution.resolutionParams.setParameter(row, name=options.name, min=options.min, value=options.value, ... 
                                                         max=options.max, fit=options.fit, priorType=options.priorType, ...
                                                         mu=options.mu, sigma=options.sigma);
        end

        % Resolutions
        function obj = addResolution(obj, name, type, source, value1, value2, value3, value4, value5)
            % Adds a new resolution to the project. 
            %
            % Examples
            % --------
            % To add a new constant resolution with name only.
            % 
            % >>> project.addResolution('New Resolution');
            % 
            % To add a constant resolution.
            % 
            % >>> project.addResolution(New Resolution', 'constant', 'param name');
            %
            % To add a data resolution.
            % 
            % >>> project.addResolution('New Resolution', 'data');
            % 
            % Parameters
            % ----------
            % name : string or char array, default: auto-generated name
            %     The name of the resolution. 
            % type : allowedTypes, default: allowedTypes.Constant
            %     The type of resolution (constant or data).
            % source : string or char array, default: ''
            %     The source of the resolution. 
            %     if type is 'constant', this should be the name (or the row index) of a resolution parameter.
            %     if type is 'data', this should be empty. RAT will expect a fourth column in the datafile.
            % value1, value2, value3, value4, value5 : string or char array, default: ''
            %     Any extra values required by the resolution.
            %     if type is 'constant', all values will be ignored.
            %     if type is 'data', all values will be ignored.
            arguments
                obj
                name {mustBeTextScalar} = ''
                type = allowedTypes.empty()
                source {mustBeScalarTextOrWholeNumber} = ''
                value1 {mustBeScalarTextOrWholeNumber} = ''
                value2 {mustBeScalarTextOrWholeNumber} = ''
                value3 {mustBeScalarTextOrWholeNumber} = ''
                value4 {mustBeScalarTextOrWholeNumber} = ''
                value5 {mustBeScalarTextOrWholeNumber} = ''
            end
            obj.resolution.addResolution(name, type, source, value1, value2, value3, value4, value5);
        end
        
        function obj = removeResolution(obj, row)
            % Removes a resolution from project.
            %
            % Examples
            % --------
            % To remove the second resolution in the table (resolution in row 2).  
            % 
            % >>> project.removeResolution(2);
            % 
            % To remove resolution with a specific name.
            % 
            % >>> project.removeResolution('Resolution 1');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the resolution to remove. If it is text, 
            %     it is the name of the resolution to remove.
            obj.resolution.removeResolution(row);
        end
        
        function obj = setResolution(obj, row, options)
            % General purpose method for updating properties of an existing resolution.
            %
            % Examples
            % --------
            % To change the name and value of the second resolution in the table (resolution in row 2).
            % 
            % >>> project.setResolution(2, name='Resolution 1', type='constant', source='param name');
            % 
            % To change the properties of a resolution called 'Resolution 1'.
            % 
            % >>> project.setResolution('Resolution 1', name='New Resolution 1', type='data');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the resolution to update. If it is text, 
            %     it is the name of the resolution to update.
            % options
            %    Keyword/value pair to properties to update for the specific resolution.
            %       * name (char array or string, default: '') the new name of the resolution.
            %       * type (allowedTypes, default: allowedTypes.empty()) the type of resolution (constant or data).
            %       * source (char array or string, or whole number, default: '') the new source of the resolution.
            %       * value1, value2, value3, value4, value5 (char array or string or whole number, default: '') any extra values required for the resolution.
            arguments
                obj
                row
                options.name {mustBeTextScalar} = ''
                options.type = allowedTypes.empty()
                options.source {mustBeScalarTextOrWholeNumber} = ''
                options.value1 {mustBeScalarTextOrWholeNumber} = ''
                options.value2 {mustBeScalarTextOrWholeNumber} = ''
                options.value3 {mustBeScalarTextOrWholeNumber} = ''
                options.value4 {mustBeScalarTextOrWholeNumber} = ''
                options.value5 {mustBeScalarTextOrWholeNumber} = ''
            end
            obj.resolution.setResolution(row, name=options.name, type=options.type, source=options.source, ...
                                         value1=options.value1,  value2=options.value2, value3=options.value3, value4=options.value4, value5=options.value5);
        end
        
        % ------------------------------------------------------------
        % Editing of Data block
        
        function obj = addData(obj, name, data, dataRange, simRange)
            % Adds a new dataset to the project.
            % 
            % Examples
            % --------
            % To add a new dataset with name only.
            % 
            % >>> project.addData('Data 1');
            % 
            % To add dataset with name and data.
            % 
            % >>> project.addData('Data 1', [1, 0, 0; 2, 0, 0; 3, 0, 0; 4, 0, 0]);
            % 
            % To add dataset with name, data and the ranges.
            % 
            % >>> project.addData('Data 1', [1, 0, 0; 2, 0, 0; 3, 0, 0; 4, 0, 0], [2, 3], [1, 4]);
            % 
            % Parameters
            % ----------
            % name : string or char array, default: auto-generated name
            %     The name of the dataset.
            % data : float, default: []
            %     3 or 4 column data for the dataset, the data should have (x, y, error) columns and may have optional resolution column.
            % dataRange : float, default: [data(1, 1), data(end, 1)] or [] if no data 
            %     The minimum and maximum range of ``data`` to use from the dataset. 
            % simRange : float, default: [0.005, 0.7]
            %     The minimum and maximum range to use for simulation.
            arguments
                obj
                name {mustBeTextScalar} = ''
                data {mustBeNumeric} = []
                dataRange {mustBeNumeric} = []
                simRange {mustBeNumeric} = []
            end
            obj.data.addData(name, data, dataRange, simRange);
        end
        
        function obj = removeData(obj, row)
            % Removes a given dataset from the project.
            %
            % Examples
            % --------
            % To remove the second dataset in the table (dataset in row 2).  
            % 
            % >>> project.removeData(2);
            % 
            % To remove dataset with a specific name.
            % 
            % >>> project.removeData('D2O');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the dataset to remove. If it is text, 
            %     it is the name of the dataset to remove.
            obj.data.removeData(row);
        end
        
        function obj = setData(obj, row, options)
            % General purpose method for updating properties of an existing dataset.
            %
            % Examples
            % --------
            % To change the name and data of the second dataset in the table (dataset in row 2).
            % 
            % >>> project.setData(2, name='Data 1', data=[1, 0, 0; 2, 0, 0; 3, 0, 0; 4, 0, 0]);
            % 
            % To change the properties of a dataset called 'Data 1'.
            % 
            % >>> project.setData('Data 1', name='Data H2O', dataRange=[2, 3]);
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the dataset to update. If it is text, 
            %     it is the name of the dataset to update.
            % options
            %    Keyword/value pair to properties to update for the specific dataset.
            %       * name (char array or string, default: '') the new name of the dataset.
            %       * data (float, default: []) the new data array.
            %       * dataRange (float, default: []) the new data range.
            %       * simRange (float, default: []) the new simulation range.
            arguments
                obj
                row
                options.name {mustBeTextScalar} = ''
                options.data {mustBeNumeric} = []
                options.dataRange {mustBeNumeric} = []
                options.simRange {mustBeNumeric} = []
            end
            nameChanged = obj.data.setData(row, name=options.name, data=options.data, dataRange=options.dataRange, simRange=options.simRange);
            
            if ~isempty(nameChanged)
                obj.contrasts.updateDataName(nameChanged);
            end
        end
       
        % -----------------------------------------------------------------
        % Editing of custom models block
        
        function obj = addCustomFile(obj, name, filename, language, path, functionName)            
            % Adds a new custom file to the project. For MATLAB, the provided file must 
            % be in the matlab path when running.
            % 
            % Examples
            % --------
            % To add a new custom file entry with name only.
            % 
            % >>> project.addCustomFile('custom file 1');
            % 
            % To add custom file with name, and filename.
            % 
            % >>> project.addCustomFile('custom file 1', 'customBilayer.m');
            % 
            % To add a Python custom files.
            % 
            % >>> project.addCustomFile('custom file 1', 'customBilayer.py', 'python', 'C:/stuff', 'custom_bilayer);
            % 
            % Parameters
            % ----------
            % name : string or char array, default: auto-generated name
            %     The name of this custom file object.
            % filename : string or char array, default: ''
            %     The name of the file containing the custom function.
            % language : supportedLanguages, default: supportedLanguages.Matlab
            %     What language the custom function is written in: 'matlab', 'python', or 'cpp' (via a dynamic library) 
            % path : string or char array, default: ''
            %     The path to the custom file.
            % functionName : string or char array, default: ''
            %     The name of the custom function within the file.
            arguments
                obj
                name {mustBeTextScalar} = ''
                filename {mustBeTextScalar} = ''
                language  = supportedLanguages.Matlab
                path {mustBeTextScalar} = ''
                functionName {mustBeTextScalar} = '' 
            end
            obj.customFile.addCustomFile(name, filename, language, path, functionName);
        end

        function obj = removeCustomFile(obj, row)
            % Removes a given custom file from the project.
            %
            % Examples
            % --------
            % To remove the second custom file in the table (custom file in row 2).  
            % 
            % >>> project.removeCustomFile(2);
            % 
            % To remove custom file with a specific name.
            % 
            % >>> project.removeCustomFile('custom file 1');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the custom file to remove. If it is text, 
            %     it is the name of the custom file to remove.
            obj.customFile.removeRow(row);
        end

        function obj = setCustomFile(obj, row, options)
            % General purpose method for updating properties of an existing custom file.
            %
            % Examples
            % --------
            % To change the name and filename of the second custom file in the table (custom file in row 2).
            % 
            % >>> file.setCustomFile(2, name='custom file 1', filename='customFunction.m');
            % 
            % To change the properties of a custom file called 'custom file 1'.
            % 
            % >>> file.setCustomFile('custom file 1', name='new custom file', filename='customFunction.py', language='python');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the custom file to update. If it is text, 
            %     it is the name of the custom file to update.
            % options
            %    Keyword/value pair to properties to update for the specific custom file.
            %       * name (char array or string, default: '') the new name of the custom file.
            %       * filename (char array or string, default: '') the new filename of the custom file.
            %       * language (supportedLanguages, default: supportedLanguages.empty()) the new language of the custom file.
            %       * path (char array or string, default: '') the new path of the custom file.
            %       * functionName (char array or string, default: ') the new function name of the custom file.
            arguments
                obj
                row
                options.name {mustBeTextScalar} = ''
                options.filename {mustBeTextScalar} = ''
                options.language = supportedLanguages.empty()
                options.path {mustBeTextScalar} = ''
                options.functionName {mustBeTextScalar} = '' 
            end
            obj.customFile.setCustomFile(row, name=options.name, filename=options.filename, language=options.language, ...
                                         path=options.path, functionName=options.functionName);
        end
        
        
        % ----------------------------------------------------------------
        % Editing of Contrasts Block
        
        function obj = addContrast(obj, varargin)
            % Adds a new contrast parameter. Expects a parameter name, and with 
            % key-value pairs with one or more of the following "data",
            % "background", "bulk in", "bulk out", "scalefactor",
            % "resolution", "resample", "model"
            % 
            % project.addContrast('contrast 1', 'bulkIn', 'Silicon');
            obj.contrasts.addContrast(obj.getAllAllowedNames(), varargin{:});
        end

        function obj = removeContrast(obj, row)
            % Removes a given contrast from the project.
            %
            % Examples
            % --------
            % To remove the second contrast in the table (contrast in row 2).  
            % 
            % >>> project.removeContrast(2);
            % 
            % To remove contrast with a specific name.
            % 
            % >>> project.removeContrast('contrast 1');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the contrast to remove. If it is text, 
            %     it is the name of the contrast to remove.
            obj.contrasts.removeContrast(row);
        end

        function obj = setContrast(obj, row, varargin)   
            % Allow setting of all parameters in terms of name value pairs.
            % First input must be contrast number or name, subsequent
            % inputs are name / value pairs for the parts involved
            %
            % project.setContrast(1, 'name', 'contrast')
                        
            % Get the list of allowed values depending on what is
            % set for the other contrasts.
            allowedValues = obj.getAllAllowedNames();
            
            % Call the setContrast method
            obj.contrasts.setContrast(row, allowedValues, varargin{:});
        end
        
        function obj = setContrastModel(obj, row, model)
            % Edits the model of an existing contrast parameter. Expects
            % the index of contrast parameter and cell array of layer
            % names. Multiple models can be set simultaneously by using 
            % an 1D array of indices or cell of strings
            %
            % project.setContrastModel(1, {'layer 1'})
            % project.setContrastModel(1:3, {'layer 1'})
            allowedValues = obj.getAllAllowedNames();
            
            % Call the setContrastModel method
             if isText(row)
                row = {row};
             elseif isnumeric(row) 
                row = num2cell(row);
             end
             for i=1:length(row)
                 obj.contrasts.setContrastModel(row{i}, allowedValues, model);
             end
        end

        %----------------------------------------------------------------
        % Conversion Helper Methods
        %----------------------------------------------------------------
        function outStruct = toStruct(obj)    
            % Converts the projectClass into a structure array.
            %
            % Returns
            % -------
            % outStruct : struct
            %     A struct which contains the properties from the projectClass.
            
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
                'paramLimits','paramValues','fitParam','paramPriors'});
            
            % Backgrounds
            backgroundStruct = obj.background.toStruct();
            
            % Resolutions
            resolutionStruct = obj.resolution.toStruct();
            
            % Bulk in
            bulkInStruct = obj.bulkIn.toStruct();
            bulkInStruct = cell2struct(struct2cell(bulkInStruct),{'bulkInNames',...
                'bulkInLimits','bulkInValues','fitBulkIn','bulkInPriors'});
            
            % Bulk out
            bulkOutStruct = obj.bulkOut.toStruct();
            bulkOutStruct = cell2struct(struct2cell(bulkOutStruct),{'bulkOutNames',...
                'bulkOutLimits','bulkOutValues','fitBulkOut','bulkOutPriors'});
            
            % Scalefactors
            scalefactorStruct = obj.scalefactors.toStruct();
            scalefactorStruct = cell2struct(struct2cell(scalefactorStruct),{'scalefactorNames',...
                'scalefactorLimits','scalefactorValues','fitScalefactor','scalefactorPriors'});
            
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

            % Data
            dataStruct = obj.data.toStruct();
            
            % Contrasts
            allNames = obj.getAllAllowedNames();
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
                                     layersStruct, ...
                                     customFileStruct, ...
                                     dataStruct, ...
                                     contrastStruct);
            
        end

        function domainsObj = toDomainsClass(obj)
            % Creates a new domainsClass object and copies the properties from current projectClass. 
            %
            % Examples
            % --------
            % >>> domainsProject = project.toDomainsClass();
            %
            % Returns
            % -------
            % domainsObj : domainsClass
            %     An instance of domainsClass with the same properties defined in the projectClass.

            domainsObj = domainsClass(obj);
        end

        function clonedProject = clone(obj)
            % Creates a clone of the project.
            %
            % Examples
            % --------
            % >>> clonedProject = project.clone();
            %
            % Returns
            % -------
            % clonedProject : projectClass
            %     A new instance of projectClass with the same properties defined in the current projectClass.

            script = obj.toScript(objName='problem', exportData=false);
            eval(script);
            clonedProject = eval('problem');
        end

        function writeScript(obj, options)
            % Writes a MATLAB script to a given file path. This script can be run to reproduce the current projectClass object.
            %
            % Examples
            % --------
            % >>> project.writeScript(path="newScript.m");
            % 
            % Parameters
            % ----------
            % objName : string or char array, default: 'project'
            %     The name to use for the project object in the script. 
            % path : string or char array, default: 'projectScript.m'
            %     The relative or absolute file path where the script should be written to.

            arguments
                obj
                options.objName {mustBeTextScalar} = 'project'
                options.path {mustBeTextScalar} = 'projectScript.m'
            end

            % Need to ensure correct format for script name
            [filePath, fileName, extension] = fileparts(options.path);
            
            % The empty string fails "isempty", so need to test for it
            % explicitly
            if strcmp(extension, "")
                % Add the correct extension
                fileName = sprintf('%s.m', fileName);
                options.path = fullfile(filePath, fileName);
            elseif ~strcmp(extension, ".m")
                % Raise error if incorrect format is used
                throw(exceptions.invalidValue(sprintf('The filename chosen for the script has the "%s" extension, rather than a MATLAB ".m" extension', extension)));
            end

            script = obj.toScript(objName=options.objName);
            fileID = fopen(options.path, 'w');
            fprintf(fileID, '%s\n', script);
            fclose(fileID);
        end
        
    end     % end public methods
    
    % ------------------------------------------------------------------
    methods (Hidden)
        function domainsObj = domainsClass(obj)
            % Object Converter method to convert to domainsClass 
            % https://uk.mathworks.com/help/matlab/matlab_oop/converting-objects-to-another-class.html. 
            %
            % Examples
            % --------
            % >>> project = projectClass();
            % >>> domainsProject = domainsClass(project);
            %
            % Returns
            % -------
            % domainsObj : domainsClass
            %     An instance of domainsClass with the same properties defined in the projectClass.

            domainsObj = domainsClass(obj.experimentName, obj.modelType, obj.geometry, obj.absorption);
            domainsObj = copyProperties(obj, domainsObj);

            % Need to treat contrasts separately due to changes in the
            % class for domains calculations
            domainsObj.contrasts = copyProperties(obj.contrasts, contrastsClass(domains=true));
            for i=1:domainsObj.contrasts.numberOfContrasts
                domainsObj.contrasts.contrasts{i}.domainRatio = '';
            end
        end
    end

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
            obj.parameters.displayTable(obj.showPriors);
                        
            % Display the Bulk In table
            fprintf('\n    Bulk In: -------------------------------------------------------------------------------------------------- \n\n');
            obj.bulkIn.displayTable(obj.showPriors);
            
            % Display the Bulk Out table
            fprintf('\n    Bulk Out: ------------------------------------------------------------------------------------------------- \n\n');
            obj.bulkOut.displayTable(obj.showPriors);
            
            % Display the Scalefactors table
            fprintf('\n    Scalefactors: ------------------------------------------------------------------------------------------------- \n\n');
            obj.scalefactors.displayTable(obj.showPriors);

            % Display the domain ratio if defined
            if isprop(obj, 'domainRatio') && isa(obj.domainRatio, 'parametersClass')
                fprintf('\n   Domain Ratios: ----------------------------------------------------------------------------------------------- \n\n');
                obj.domainRatio.displayTable(obj.showPriors);
            end

            % Display the backgrounds object
            fprintf('\n    Backgrounds: ----------------------------------------------------------------------------------------------- \n\n');
            obj.background.displayTable(obj.showPriors);
            
            % Display the resolutions object
            fprintf('\n    Resolutions: --------------------------------------------------------------------------------------------- \n\n');
            obj.resolution.displayTable(obj.showPriors);

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

        function setLayersAndContrasts(obj, oldModel)
            % Adjust layers and contrast objects when the model type is
            % changed.
            %
            % Parameters
            % ----------
            % oldModel : modelTypes
            %     The model type of the project before it was changed.

            if strcmpi(obj.modelType, modelTypes.StandardLayers.value)
                if ~isa(obj.layers, 'layersClass')
                    obj.layers = layersClass();
                    obj.layers.absorption = obj.absorption;
                end
            else
                obj.layers = [];
            end

            if isa(obj.contrasts, 'contrastsClass')
                if ~strcmpi(obj.modelType, oldModel)
                    for i=1:obj.contrasts.numberOfContrasts
                        obj.contrasts.contrasts{i}.model = '';
                    end
                end
            end
        end

    end

    methods (Access = private)
        function script = toScript(obj, options)
            % Convert to a MATLAB script that can be run to reproduce this
            % projectClass object.
            % 
            % Examples
            % --------
            % >>> script = project.toScript(exportData=false);
            % 
            % Parameters
            % ----------
            % options
            %     Keyword/value pair to properties to update for the specific parameter.
            %       * objName (string or char array, default: 'project') the name to use for the project object in the script. 
            %       * exportData (logical, default: true) indicates if the data should be exported to file otherwise the data is written into the script.

            arguments
                obj
                options.objName {mustBeTextScalar} = 'project'
                options.exportData {mustBeA(options.exportData, 'logical')} = true
            end
            script = "";
            script = script + sprintf("%s\n\n", '% THIS FILE IS GENERATED FROM RAT VIA THE "WRITESCRIPT" ROUTINE. IT IS NOT PART OF THE RAT CODE.');

            % Start by getting input arguments
            projectSpec = "%s = createProject(name='%s', calcType='%s', model='%s', geometry='%s', absorption=%s);\n\n";
            script = script + sprintf(projectSpec, options.objName, obj.experimentName, obj.calculationType,  obj.modelType, obj.geometry,  string(obj.absorption));
            if obj.showPriors
                script = script + sprintf("%s.showPriors = true;\n\n", options.objName);
            end

            % Add all parameters, with different actions for protected
            % parameters
            paramGroup = cell(sum(~strcmpi(obj.parameters.varTable{:, 1}, obj.protectedParameters)), 1);
            groupIndex = 1;
            for i=1:height(obj.parameters.varTable)
                % Set protected parameters
                if any(strcmpi(obj.parameters.varTable{i, 1}, obj.protectedParameters))
                    script = script + sprintf(options.objName + ".setParameter(%d, 'min', %.15g, 'value', %.15g, 'max', %.15g, 'fit', %s, 'priorType', '%s', 'mu', %.15g, 'sigma', %.15g);\n", ...
                                              i, obj.parameters.varTable{i, 2}, obj.parameters.varTable{i, 3}, obj.parameters.varTable{i, 4}, string(obj.parameters.varTable{i, 5}), ...
                                              obj.parameters.varTable{i, 6}, obj.parameters.varTable{i, 7}, obj.parameters.varTable{i, 8});
                % Add non-protected parameters to a parameter group
                else
                    paramRow = table2cell(obj.parameters.varTable(i, :))';
                    paramRow{5} = string(paramRow{5});
                    paramGroup{groupIndex} = paramRow;
                    groupIndex = groupIndex + 1;
                end
            end

            script = script + newline;

            % Write the parameter group to the script
            if size(paramGroup, 1) > 0
                script = script + sprintf("paramGroup = {\n");
                for i = 1:size(paramGroup, 1)
                    paramSpec = blanks(14) + "{'%s', %.15g, %.15g, %.15g, %s, '%s', %.15g, %.15g};\n";
                    script = script + sprintf(paramSpec, paramGroup{i}{:});
                end
                script = script + sprintf(blanks(14) + "%s\n\n", "};");
                script = script + sprintf(options.objName + ".addParameterGroup(paramGroup);\n");
            end

            script = script + newline;

            % Add all parameters based on a parametersClass
            paramClasses = ["bulkIn", "bulkOut", "scalefactors", "background", "resolution"];
            paramSubclasses = ["", "", "", "backgroundParams", "resolutionParams"];

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
                script = script + sprintf(options.objName + "." + removeRoutine + "(1);\n");
                % Convert logical parameter
                for j=1:numParams
                    paramTable{5, j} = string(paramTable{5, j});
                end
                % Add the parameters that have been defined
                paramSpec = options.objName + "." + addRoutine + "('%s', %.15g, %.15g, %.15g, %s, '%s', %.15g, %.15g);\n";
                script = script + sprintf(paramSpec, paramTable{:});
                script = script + newline;

            end

            % Now deal with classes where all of the fields are strings

            % First, custom files
            addRoutine = obj.classes.addRoutine(obj.classes.name == "customFile");
            numCols = width(obj.customFile.varTable);
            stringTable = table2array(obj.customFile.varTable)';
            stringTable = stringTable([1 2 4 5 3],:);  % Needs to switch columns to match argument order
            
            % Add parameters if any have been defined
            if ~isempty(stringTable)
                stringSpec = options.objName + "." + addRoutine + "(" + join(repmat("'%s'", 1, numCols), ", ") + ");\n";
                script = script + sprintf(stringSpec, stringTable);
                script = script + newline;
            end

            % Data class requires writing and reading the data
            script = script + sprintf(options.objName + ".removeData(1);\n");

            for i=1:obj.data.rowCount

                % Write and read data if it exists, else add an empty,
                % named row
                if isempty(obj.data.varTable{i, 2}{:})
                    script = script + sprintf(options.objName + ".addData('%s');\n", obj.data.varTable{i, 1});
                else
                    if options.exportData
                        writematrix(obj.data.varTable{i, 2}{:}, "data_" + string(i) + ".dat");
                        script = script + sprintf("data_%d = readmatrix('%s');\n", i, "data_" + string(i) + ".dat");
                        script = script + sprintf(options.objName + ".addData('%s', data_%d);\n", obj.data.varTable{i, 1}, i);
                    else
                        script = script + sprintf("data_%d = %s;\n", i, mat2str(obj.data.varTable{i, 2}{:}, 15));
                        script = script + sprintf(options.objName + ".addData('%s', data_%d);\n", obj.data.varTable{i, 1}, i);
                    end
                end

                % Also need to set dataRange and simRange explicitly as they
                % are optional
                if ~isempty(obj.data.varTable{i, 3}{:})
                    script = script + sprintf(options.objName + ".setData(%d, 'dataRange', [%.15g %.15g]);\n", i, obj.data.varTable{i, 3}{:});
                end
                if ~isempty(obj.data.varTable{i, 4}{:})
                    script = script + sprintf(options.objName + ".setData(%d, 'simRange', [%.15g %.15g]);\n", i, obj.data.varTable{i, 4}{:});
                end

                script = script + newline;

            end

            % Now deal with background and resolutions, which have
            % subclasses
            stringClasses = ["background", "resolution"];
            stringSubclasses = ["backgrounds", "resolutions"];

            if isa(obj.layers, 'layersClass')
                stringClasses = ["layers", stringClasses];
                stringSubclasses = ["", stringSubclasses];
            end

            script = script + sprintf(options.objName + ".removeBackground(1);\n");
            script = script + sprintf(options.objName + ".removeResolution(1);\n");
            script = script + newline;

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
                    script = script + sprintf(stringSpec, stringTable);
                    script = script + newline;
                end

            end

            % Contrasts are a cell array rather than a table
            % Need to handle resample and model fields separately
            % Also need to do domain contrasts before experimental
            % contrasts
            if isprop(obj, 'domainContrasts') && isa(obj.domainContrasts, 'domainContrastsClass')
                for i=1:obj.domainContrasts.numberOfContrasts
                    
                    reducedStruct = rmfield(obj.domainContrasts.contrasts{i}, {'model'});
                    contrastParams = string(namedargs2cell(reducedStruct));
                    contrastSpec = options.objName + ".addDomainContrast(" + join(repmat("'%s'", 1, length(contrastParams)), ", ") + ");\n";
                    script = script + sprintf(contrastSpec, contrastParams);
                    if ~isempty(obj.domainContrasts.contrasts{i}.model)
                        script = script + sprintf(options.objName + ".setDomainContrast(%d, 'model', {" + join(repmat("'%s'", 1, length(obj.domainContrasts.contrasts{i}.model))) +"});\n", i, obj.domainContrasts.contrasts{i}.model{:});
                    end
                    script = script + newline;
                    
                end
            end

            for i=1:obj.contrasts.numberOfContrasts

                reducedStruct = rmfield(obj.contrasts.contrasts{i}, {'resample', 'repeatLayers', 'model'});
                contrastParams = string(namedargs2cell(reducedStruct));
                contrastSpec = options.objName + ".addContrast(" + join(repmat("'%s'", 1, length(contrastParams)), ", ") + ");\n";
                script = script + sprintf(contrastSpec, contrastParams);
                script = script + sprintf(options.objName + ".setContrast(%d, 'resample', %s);\n", i, string(obj.contrasts.contrasts{i}.resample));
                script = script + sprintf(options.objName + ".setContrast(%d, 'repeatLayers', %s);\n", i, string(obj.contrasts.contrasts{i}.repeatLayers));
                if ~isempty(obj.contrasts.contrasts{i}.model)
                    script = script + sprintf(options.objName + ".setContrast(%d, 'model', {" + join(repmat("'%s'", 1, length(obj.contrasts.contrasts{i}.model))) +"});\n", i, obj.contrasts.contrasts{i}.model{:});
                end
                script = script + newline;

            end
        end
    end

end
