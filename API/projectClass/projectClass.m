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

    methods

        function obj = projectClass(experimentName, calculationType, geometry, absorption)
            % Creates a Project object. The input arguments are the
            % experiment name which is a char array; the calculation type,
            % which is a calculationTypes enum; the geometry, which is a
            % geometryOptions enum; and a logical to state whether or not
            % absorption terms are included in the refractive index.
            % All of the arguments are optional.
            %
            % problem = projectClass('New experiment');
            arguments
                experimentName {mustBeTextScalar} = ''
                calculationType = calculationTypes.NonPolarised
                geometry = geometryOptions.AirSubstrate
                absorption {mustBeA(absorption,'logical')} = false
            end

            invalidTypeMessage = sprintf('calculationType must be a calculationTypes enum or one of the following strings (%s)', ...
                                 strjoin(calculationTypes.values(), ', '));

            obj.calculationType = validateOption(calculationType, 'calculationTypes', invalidTypeMessage).value;

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
            addlistener(obj, 'absorption', 'PostSet', @obj.modifyLayersTable);
            obj.layers = layersClass();
            obj.absorption = absorption;
            
            % Initialise bulkIn table
            obj.bulkIn = parametersClass('SLD Air',0,0,0,false,priorTypes.Uniform,0,Inf);
            
            % Initialise bulkOut table
            obj.bulkOut = parametersClass('SLD D2O',6.2e-6,6.35e-6,6.35e-6,false,priorTypes.Uniform,0,Inf);
            
            % Initialise scalefactors table
            obj.scalefactors = parametersClass('Scalefactor 1',0.02,0.23,0.25,false,priorTypes.Uniform,0,Inf);
            
            % Initialise qzshifts table
            obj.qzshifts = parametersClass('Qz shift 1',-1e-4,0,1e-4,false,priorTypes.Uniform,0,Inf);
            
            % Initialise backs object
            backPars = parametersClass('Backs par 1',1e-7,1e-6,1e-5,false,priorTypes.Uniform,0,Inf);
            backgrounds = {'Background 1',allowedTypes.Constant.value,'Backs Par 1','','','',''};
            obj.background = backgroundsClass(backPars, backgrounds);
            
            % Initialise resolution object
            resolPars = parametersClass('Resolution par 1',0.01,0.03,0.05,false,priorTypes.Uniform,0,Inf);
            resolutions = {'Resolution 1',allowedTypes.Constant.value,'Resolution par 1','','','',''};
            obj.resolution = resolutionsClass(resolPars, resolutions);
            
            % Initialise data object
            obj.data = dataClass('Simulation', [], [], []);

            % Initialise custom file object
            obj.customFile = customFileClass();

            % Initialise contrasts object
            obj.contrasts = contrastsClass();               
        end
        
        function domainsObj = domainsClass(obj)
            % Converter routine from projectClass to domainsClass.
            % This routine takes the currently defined project and
            % converts it to a domains calculation, preserving all
            % currently defined properties.
            %
            % domainsProblem = problem.domainsClass();
            domainsObj = domainsClass(obj.experimentName, calculationTypes.Domains, obj.geometry, obj.absorption);
            domainsObj = copyProperties(obj, domainsObj);

            % Need to treat contrasts separately due to changes in the
            % class for domains calculations
            domainsObj.contrasts = copyProperties(obj.contrasts, contrastsClass(domains=true, oilWater=obj.contrasts.oilWaterCalc));
            for i=1:domainsObj.contrasts.numberOfContrasts
                domainsObj.contrasts.contrasts{i}.domainRatio = '';
            end
        end

        function obj = setUsePriors(obj, showFlag)
            % Sets the use priors flag. The showFlag should be a boolean/logical.
            %
            % problem.setUsePriors(true); 
            if ~islogical(showFlag)
                throw(invalidType('usePriors must be logical ''true'' or ''false'''));
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
            obj.background.backPars.showPriors = showFlag;
            
            % (7) Resolutions (parameters table)
            obj.resolution.resolPars.showPriors = showFlag;
            
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
            % either "standard layers", "custom layers", or "custom xy" is permitted.
            %
            % problem.setModelType('Custom Layers');
            invalidTypeMessage = sprintf('Experiment type must be a modelTypes enum or one of the following strings (%s)', ...
                                         strjoin(modelTypes.values(), ', '));
            obj.modelType = validateOption(modelType, 'modelTypes', invalidTypeMessage).value;
        end
        

        function names = getAllAllowedNames(obj)           
            % Returns a cell array of all currently
            % set parameter names for the project.
            names.paramNames = obj.parameters.getNames();
            names.backsNames = obj.background.getBackgroundNames();
            names.backParNames = obj.background.backPars.getNames();
            names.bulkInNames = obj.bulkIn.getNames();
            names.bulkOutNames = obj.bulkOut.getNames();
            names.resolsNames = obj.resolution.getResolNames();
            names.resolParNames = obj.resolution.resolPars.getNames();
            names.layersNames = obj.layers.getNames();
            names.dataNames = obj.data.getNames();
            names.scalefacNames = obj.scalefactors.getNames();
            names.qzShiftNames = obj.qzshifts.getNames();
            names.customNames = obj.customFile.getNames(); 
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
                    throw(invalidType('Expecting a cell array of parameters in ''addParameterGroup'''));
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
                throw(invalidType('Unrecognised Row'))
            end

            for i = 1:length(row)
                thisParam = row{i};
                
                % Make sure we don't remove any protected parameters
                if (isnumeric(thisParam) && thisParam <= length(obj.protectedParameters)) || any((strcmpi(thisParam, obj.protectedParameters)))
                    throw(invalidOption(sprintf('Can''t remove protected parameters')));
                end
                
                % No need to check validity of the parameter
                % as this is done in the parameters class
                obj.parameters.removeParameter(thisParam);
                
                % Need to check if it is used in the layers
                % array and remove it if so. Should be able
                % to do this with array indexing, but can't quite figure
                % that out atm, so just use a (dirty) loop over all
                % the elements for now..
                
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
        
        function obj = setParameterConstraint(obj, row, min, max)
            % Sets the constraints of an existing parameter.
            % Expects index or name of parameter and new min 
            % and max of the parameter's value
            %
            % problem.setParameterConstraint(2, 0, 100);
            obj.parameters.setConstraint(row, min, max);
        end
        
        function obj = setParameterName(obj, row, name)
            % Sets the name of an existing parameter
            % Expects index or name of parameter and the
            % new name
            %
            % problem.setParameterName(2, 'new name');
            if (isnumeric(row) && row <= length(obj.protectedParameters)) || any((strcmpi(row, obj.protectedParameters)))
                throw(invalidOption('Can''t rename protected parameters'));
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
            for i = 1:length(layerGroup)
                if iscell(layerGroup{i})
                    obj = addLayer(obj, layerGroup{i});
                else
                    throw(invalidType('Expecting a cell array of parameters in ''addLayerGroup'''));
                end
            end  
        end
        
        function obj = addLayer(obj, varargin)
            % Adds a single layer to the layers object. Expects layer
            % details which are name, thickness, SLD, roughness,
            % hydration, and hydrate with, or provide with no details,
            % or just a name, to create an empty layer.
            %
            % problem.addLayer('New Layer');
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
        end

        function obj = removeLayer(obj, layer)
            % Removes layer(s) from the layers object. Expects
            % index of layer(s) to remove.
            %
            % problem.removeLayer(1);
            obj.layers.removeRow(layer);
        end

        function obj = setLayerValue(obj, row, col, value)
            % Sets a value of a given layer. Expects the row/name and
            % column of layer value to set, then the name/index of the 
            % parameter to set the value to.
            % 
            % problem.setLayerValue(1, 2, 'Tails Thickness');
            obj.layers.setLayerValue(row, col, value, obj.parameters.varTable{:,1});           
        end
        
        % ---------------------------------------------------------------
        
        % Editing of Backgrounds block
        
        
        %(1) Background Parameters
        function obj = addBacksPar(obj, varargin)
            % Adds a new background parameter. A parameter consists 
            % of a name, min, value, max, fit flag, prior type', mu,
            % and sigma
            %
            % problem.addBacksPar('Backs Value D2O', 1e-8, 2.8e-6, 1e-5);
            obj.background.backPars.addParameter(varargin{:});
        end
        
        function obj = removeBacksPar(obj, varargin)
            % Removes a given background parameter.
            % Expects index or name of parameter to remove
            % 
            % problem.removeBacksPar(2);
            obj.background.backPars.removeParameter(varargin{:});
        end
        
        function obj = setBacksParValue(obj, row, value)
            % Sets the value of existing background            
            % parameter. Expects index or name of parameter 
            % and new value to set
            %
            % problem.setBacksParValue(1, 5.5e-6);
            obj.background.backPars.setValue(row, value);
        end
        
        function obj = setBacksParConstr(obj, row, min, max)
            % Sets the constraints of existing background
            % parameter. Expects index or name of parameter 
            % and new min and max of the parameter's value
            %
            % problem.setBacksParConstr(1, 0, 1);
            obj.background.backPars.setConstraint(row, min, max);
        end
        
        function obj = setBacksParName(obj, row, name)
            % Sets the name of an existing background 
            % parameter. Expects index or name of parameter 
            % and the new name
            %
            % problem.setBacksParName(2, 'new name');
            obj.background.backPars.setName(row, name);
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
        
        function obj = setBacksPar(obj, varargin)
            % Sets the value of an existing background parameter. Expects
            % index or name of parameter and keyword/value pairs to set
            %
            % problem.setBacksPar(1, 'name', 'Backs Value H2O');
            obj.background.backPars.setParameter(varargin{:});
        end
        
        % -------------------------------------------------------------
        %   Editing of Resolutions block
        
        % Resol Pars
        function obj = setResolParValue(obj, row, value)
            % Sets the value of existing resolution            
            % parameter. Expects index or name of parameter 
            % and new value to set
            %
            % problem.setResolParValue(1, 5.5e-6);
            obj.resolution.resolPars.setValue(row, value);
        end
        
        function obj = addResolPar(obj, varargin)
            % Adds a new resolution parameter. A parameter consists 
            % of a name, min, value, max, fit flag, prior type', mu,
            % and sigma
            %
            % problem.addResolPar('ResolPar 1', 1e-8, 2.8e-6, 1e-5);
            obj.resolution.resolPars.addParameter(varargin{:});
        end
        
        function obj = setResolPar(obj, varargin)
            % Sets the value of an existing resolution parameter. Expects
            % index or name of parameter and keyword/value pairs to set
            %
            % problem.setResolPar(1, 'name', 'ResolPar');
            obj.resolution.resolPars.setParameter(varargin{:});
        end
        
        function obj = removeResolPar(obj, varargin)
            % Removes a given resolution parameter.
            % Expects index or name of parameter to remove
            % 
            % problem.removeResolPar(2);
            obj.resolution.resolPars.removeParameter(varargin{:});
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
            % problem..addQzshift('Qz shift 2', -0.2e-4, 0, 2e-4, false);
            obj.qzshifts.addParameter(varargin{:}); 
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
            % problem.addContrast('contrast 1', 'nba', 'Silicon');
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
                'nScalefactors','scalefactorConstr','scalefactors','scalefactorFitYesNo','scalefactorPriors'});
            
            % Qzshifts
            qzshiftStruct = obj.qzshifts.toStruct();
            qzshiftStruct = cell2struct(struct2cell(qzshiftStruct),{'qzshiftNames',...
                'nQzshifts','qzshiftConstr','qzshifts','qzshiftFitYesNo','qzshiftPriors'});
            
            % Layers
            layersStruct = obj.layers.toStruct(paramStruct.paramNames, generalStruct.modelType);

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
            % the display of the layers table..
            
            % Display initial properties
            startProps = getPropertyGroup1(obj);
            matlab.mixin.CustomDisplay.displayPropertyGroups(obj,startProps);
            
            % Display the parameters table
            fprintf('\n    Parameters: ---------------------------------------------------------------------------------------------- \n\n');
            obj.parameters.displayTable;
            
            % Display the layers table if not a custom model
            val = obj.modelType;
            if ~any(strcmpi(val,{'custom layers','custom xy'}))
                fprintf('\n    Layers: -------------------------------------------------------------------------------------------------- \n\n');
                obj.layers.displayTable;
            end
            
            % Display the Bulk In table
            fprintf('\n    Bulk In: -------------------------------------------------------------------------------------------------- \n\n');
            obj.bulkIn.displayTable;
            
            % Display the Bulk Out table
            fprintf('\n    Bulk Out: ------------------------------------------------------------------------------------------------- \n\n');
            obj.bulkOut.displayTable;
            
            % Display the Scalefactors table
            fprintf('\n    Scalefactors: ------------------------------------------------------------------------------------------------- \n\n');
            obj.scalefactors.displayTable;

            % Display the backgrounds object
            fprintf('\n    Backgrounds: ----------------------------------------------------------------------------------------------- \n\n');
            obj.background.displayBackgroundsObject;
            
            % Display the resolutions object
            fprintf('\n    Resolutions: --------------------------------------------------------------------------------------------- \n\n');
            obj.resolution.displayResolutionsObject;
            
            % Display the data object
            fprintf('\n    Data: ------------------------------------------------------------------------------------------------------ \n\n');
            obj.data.displayTable;
            
            % Display custom files object
            fprintf('\n    Custom Files: ------------------------------------------------------------------------------------------------------ \n\n');
            obj.customFile.displayTable;
            
            % Display the contrasts object
            fprintf('\n   Contrasts: ----------------------------------------------------------------------------------------------- \n\n');
            obj.contrasts.displayContrastsObject;
            
        end
        
    end

    methods (Access = protected, Hidden)

        function modifyLayersTable(obj,~,~)
            % Add or remove a column from the layers table whenever the
            % "absorption" property is modified.
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
