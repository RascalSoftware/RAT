classdef domainsClass < projectClass
    % ``domainsClass`` stores all the information that describes a domains experiment which is essential for running a RAT domains calculation. 
    % The ``domainsClass`` contains similar components to a normal project such as the parameters, backgrounds, resolutions, custom files, 
    % data, contrast etc, but also stores the domains ratio and domains contrast which are unique to a domains calculation. The 
    % ``domainsClass`` provides a number of methods to add, remove, and update these components. For example, for domain ratio, the 
    % ``addDomainsRatio``, ``removeDomainsRatio``, and ``setDomainsRatio`` methods are available for adding, removing, and updating parameters.
    % 
    % Examples
    % --------
    % >>> domains = domainsClass();
    % >>> domains = domainsClass("Example Project");
    % >>> domains = domainsClass("Example Project", 'custom layers', 'substrate/liquid', true);
    % 
    % Parameters
    % ---------- 
    % experimentName : string or char array, default: ''
    %     The name of the domains project.
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
    % domainRatio : parametersClass
    %     The domain ratio parameters.
    % domainContrasts : domainContrastsClass
    %     An object which contains domain contrast information.
    properties
        domainRatio          % Class for specifying the ratio between domains
        domainContrasts      % Modified contrast class with no data for domains
    end

    methods

        function obj = domainsClass(experimentName, modelType, geometry, absorption)
            arguments
                experimentName {mustBeTextScalar} = ''
                modelType = modelTypes.StandardLayers
                geometry = geometryOptions.AirSubstrate
                absorption {mustBeA(absorption,'logical')} = false
            end
            
            % Call projectClass constructor
            obj@projectClass(experimentName, modelType, geometry, absorption);
            obj.calculationType = calculationTypes.Domains.value;

            % Create a contrasts class for a domains calculation
            obj.contrasts = contrastsClass(true);

            % For a domains calculation, initialise domain ratio parameter
            % class and, for a standard layers model, secondary contrasts
            % object
            obj.domainRatio = parametersClass('Domain Ratio 1',0.4,0.5,0.6,false,'uniform',0,Inf);
            if strcmpi(obj.modelType, modelTypes.StandardLayers.value)
                obj.domainContrasts = domainContrastsClass();
            end
        end

        function projectObj = toProjectClass(obj)
            % Creates a new projectClass object and copies the properties from current domainsClass. 
            %
            % Examples
            % --------
            % >>> normalProject = domains.toProjectClass();
            %
            % Returns
            % -------
            % projectObj : projectClass
            %     An instance of projectClass with the common properties copied from the domainsClass.
            projectObj = obj.projectClass();
        end

        function names = getAllAllowedNames(obj)           
            % Returns a struct with all currently set names of normal parameters, background and resolution 
            % parameters, backgrounds, resolutions, bulk-ins, bulk-outs, scalefactors, data, custom files, 
            % contrast model, domain ratios, and domain contrasts for the project.
            % 
            % Returns
            % -------
            % names : struct
            %     A struct with names of all the normal parameters, background and resolution 
            %     parameters, backgrounds, resolutions, bulk-ins, bulk-outs, scalefactors, data, custom files, 
            %     contrast model, domain ratios, and domain contrasts entries in the project.
            names = getAllAllowedNames@projectClass(obj);
            names.domainRatioNames = obj.domainRatio.getNames();
            if isa(obj.domainContrasts, 'domainContrastsClass')
                names.domainContrastNames = obj.domainContrasts.getNames();
                names.domainModelNames = obj.layers.getNames();
            end
        end
    
        % ----------------------------------------------------------------
        % Editing of Contrasts Block

        function obj = addContrast(obj, options)
            % Add a new contrast to the project.
            %
            % Examples
            % --------
            % To add a new contrast with name only.
            % 
            % >>> domains.addContrast(name='new contrast');
            % 
            % To add a new contrast with other properties.
            % 
            % >>> domains.addContrast(name='new contrast', bulkIn='Silicon', bulkOut='D2O', background='D2O Background', ...
            %                         resolution='Resolution 1', scalefactor='Scalefactor 1', data='DSPC Bilayer D2O', ...
            %                         domainRatio='Domain Ratio 1', model={'Domains 1', 'Domains 2'});
            %  
            % Parameters
            % ----------
            % options
            %    Keyword/value pair to properties to update for the specific contrast.
            %       * name (char array or string, default: '') the name of the contrast.
            %       * data (char array or string, default: '') the name of the dataset parameter used by the contrast.
            %       * background (char array or string, default: '') the name of the background for the contrast.
            %       * backgroundAction (backgroundActions, default: backgroundActions.Add) whether the background should be added to the simulation ('add') or subtracted from the data('subtract').
            %       * bulkIn (char array or string, default: '') the name of the bulk-in parameter which defines the SLD of the interface between the first layer and the environment.
            %       * bulkOut (char array or string, default: '') the name of the bulk-out parameter which defines the SLD of the interface between the last layer and the environment.
            %       * scalefactor (char array or string, default: '') the name of the scalefactor parameter which defines how much the data for this contrast should be scaled.
            %       * resolution (char array or string, default: '') the name of the instrument resolution for this contrast.
            %       * resample (logical, default: false) whether adaptive resampling should be used for interface microslicing.
            %       * repeatLayers (whole number, default: 1) indicates the number of times the layers should be repeated, this is only supported for standard layers.
            %       * domainRatio (char array or string, default: '') the name of the domain ratio parameter.
            %       * model (cell) if this is a standard layers model, this should be a list of domain contrast names for this contrast.
            %                      For custom models, this should be a single custom file name for the custom model function.
            arguments
                obj
                options.name
                options.data
                options.background
                options.backgroundAction
                options.bulkIn
                options.bulkOut
                options.scalefactor
                options.resolution
                options.resample
                options.repeatLayers
                options.domainRatio
                options.model
            end
            args = namedargs2cell(options);
            obj.contrasts.addContrast(obj.getAllAllowedNames(), args{:});
        end

        function obj = setContrast(obj, row, options)   
            % General purpose method for updating properties of an existing contrast.
            %
            % Examples
            % --------
            % To change the properties of the second contrast in the object.
            % 
            % >>> domains.setContrast(2, name='new contrast', bulkIn='Silicon', bulkOut='D2O', background='D2O Background', ...
            %                         resolution='Resolution 1', scalefactor='Scalefactor 1', data='DSPC Bilayer D2O', model={'Domains 1', 'Domains 2'}});
            %
            % To change the properties of a contrast called 'Contrast 1'.
            % 
            % >>> domains.setContrast('Contrast 1', name='new contrast', domainRatio='Domain Ratio 1', model={'Domains 1', 'Domains 2'});
            %  
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the contrast to update. If it is text, 
            %     it is the name of the contrast to update.
            % options
            %    Keyword/value pair to properties to update for the specific contrast.
            %       * name (char array or string, default: '') the name of the contrast.
            %       * data (char array or string, default: '') the name of the dataset parameter used by the contrast.
            %       * background (char array or string, default: '') the name of the background for the contrast.
            %       * backgroundAction (backgroundActions, default: backgroundActions.Add) whether the background should be added to the simulation ('add') or subtracted from the data('subtract').
            %       * bulkIn (char array or string, default: '') the name of the bulk-in parameter which defines the SLD of the interface between the first layer and the environment.
            %       * bulkOut (char array or string, default: '') the name of the bulk-out parameter which defines the SLD of the interface between the last layer and the environment.
            %       * scalefactor (char array or string, default: '') the name of the scalefactor parameter which defines how much the data for this contrast should be scaled.
            %       * resolution (char array or string, default: '') the name of the instrument resolution for this contrast.
            %       * resample (logical, default: false) whether adaptive resampling should be used for interface microslicing.
            %       * repeatLayers (whole number, default: 1) indicates the number of times the layers should be repeated, this is only supported for standard layers.
            %       * domainRatio (char array or string, default: '') the name of the domain ratio parameter.
            %       * model (char array or string or cell string) if this is a standard layers model, this should be a list of domain contrast names for this contrast.
            %                      For custom models, this should be a single custom file name for the custom model function.
            arguments
                obj
                row
                options.name
                options.data
                options.background
                options.backgroundAction
                options.bulkIn
                options.bulkOut
                options.scalefactor
                options.resolution
                options.resample
                options.repeatLayers
                options.domainRatio
                options.model
            end
            args = namedargs2cell(options);       
            obj.contrasts.setContrast(row, obj.getAllAllowedNames(), args{:});
        end
        
        function obj = setContrastModel(obj, row, model)
            % Updates the model of an existing contrast.
            %
            % Examples
            % --------
            % To change the model of the second contrast in the project.
            % 
            % >>> domains.setContrastModel(2, {'Domains 1', 'Domains 2'});
            %
            % To change the properties of a contrast called 'Contrast 1'.
            % 
            % >>> domains.setContrastModel('Contrast 1', {'Domains 1', 'Domains 2'});
            % 
            % To change multiple contrasts at once. The snippet below will change 1, 2, and 3.
            % 
            % >>> domains.setContrastModel(1:3, {'Domains 1', 'Domains 2'});  
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the contrast to update. If it is text, 
            %     it is the name of the contrast to update.
            % model: char array or string or cell string
            %     If this is a standard layers model, this should be a list of domain contrast names for this contrast.
            %     For custom models, this should be a single custom file name for the custom model function.
            setContrastModel@projectClass(obj, row, model);
        end

        % -------------------------------------------------------------------
        % Editing of Domain Ratio block
        
        function obj = addDomainRatio(obj, name, min, value, max, fit, priorType, mu, sigma)
            % Adds a new domain ratio parameter. Expects the name
            % of domain ratio, min, value, max, and if fit is off or on
            % 
            % project.addDomainRatio('Domain Ratio 2', 0.4, 0.5, 0.6, true);
            % Adds an new domain ratio to the project. 
            %
            % Examples
            % --------
            % To add a new domain ratio with no properties and an autogenerated name.
            % 
            % >>> domains.addDomainRatio();
            % 
            % To add a domain ratio with all available properties.
            % 
            % >>> domains.addDomainRatio('New Domain Ratio', 0.4, 0.5, 0.6, true, 'gaussian', 1, 5);
            % 
            % Other examples of adding domain ratios with a subset of properties.
            % 
            % >>> domains.addDomainRatio('New Domain Ratio');  % Domain ratio name only with others set to default
            % >>> domains.addDomainRatio('New Domain Ratio', 0.4);  % Domain ratio name and min only. Value and max will be set to 0.4 to keep limits valid
            % >>> domains.addDomainRatio('New Domain Ratio', 0.4, 0.5, 0.6, true);  % priors will be default
            % 
            % Parameters
            % ----------
            % name : string or char array, default: auto-generated name
            %     The name of the domain ratio. 
            % min : double, default: 0.0
            %     The minimum value that the domain ratio could take when fitted.
            % value : double, default: 0.0
            %     The value of the domain ratio, default will be equal to ``min`` if this is not set.
            % max : double, default: 0.0
            %     The maximum value that the domain ratio could take when fitted, default will be equal to ``value`` if this is not set.
            % fit : logical, default: false
            %     Whether the domain ratio should be fitted in a calculation.
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
            obj.domainRatio.addParameter(name, min, value, max, fit, priorType, mu, sigma);
        end
        
        function obj = removeDomainRatio(obj, row)
            % Removes a domain ratio from the project. 
            %
            % Examples
            % --------
            % To remove the second domain ratio in the table (domain ratio in row 2).  
            % 
            % >>> domains.removeDomainRatio(2);
            % 
            % To remove domain ratio with a specific name.
            % 
            % >>> domains.removeDomainRatio('Domain Ratio 2');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the domain ratio to remove. If it is text, 
            %     it is the name of the domain ratio to remove.
           obj.domainRatio.removeParameter(row); 
        end
        
        function obj = setDomainRatio(obj, row, options)
            % General purpose method for updating properties of an existing domain ratio. 
            % Any unset property will remain unchanged.
            %
            % Examples
            % --------
            % To change the name and value of the second domain ratio in the table (domain ratio in row 2).
            % 
            % >>> domains.setDomainRatio(2, name='Domain Ratio 1', value=0.55);
            % 
            % To change the all properties of a domain ratio called 'Domain Ratio 1'.
            % 
            % >>> domains.setDomainRatio('Domain Ratio 1', name='New Domain Ratio', min=0.4, value=0.5, max=0.6, ...
            % >>>                        fit=true, priorType=gaussian, mu=1, sigma=5);
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the domain ratio to update. If it is text, 
            %     it is the name of the domain ratio to update.
            % options
            %    Keyword/value pair to properties to update for the specific domain ratio.
            %       * name (char array or string, default: '') the new name of the domain ratio.
            %       * min (double, default: []) the new minimum value of the domain ratio.
            %       * value (double, default: []) the new value of the domain ratio.
            %       * max (double, default: []) the new maximum value of the domain ratio.
            %       * fit (logical, default: logical.empty()) the new fit flag of the domain ratio.
            %       * priorTypes (priorTypes, default: priorTypes.empty()) the new prior type of the domain ratio.            
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
            args = namedargs2cell(options);
            obj.domainRatio.setParameter(row, args{:});
        end
    
        % ----------------------------------------------------------------
        % Editing of Domains Contrasts Block
        
        function obj = addDomainContrast(obj, options)
            % Add a new domain contrast to the project.
            %
            % Examples
            % --------
            % To add a new domain contrast with name only.
            % 
            % >>> domains.addDomainContrast(name='new domain contrast');
            % 
            % To add a new domain contrast with model.
            % 
            % >>> domains.addDomainContrast(name='new domain contrast', model='Oxide');
            % >>> domains.addDomainContrast(name='new domain contrast', model={'Oxide', 'Bilayer tails'});
            % 
            % Parameters
            % ----------
            % options
            %    Keyword/value pair to properties to update for the specific domain contrast.
            %       * name (char array or string, default: '') the name of the domain contrast.
            %       * model (cell) this should be a list of layer names that make up the slab model for this domain contrast.
            arguments
                obj
                options.name
                options.model
            end
            if isa(obj.domainContrasts, 'domainContrastsClass')
                args = namedargs2cell(options);
                obj.domainContrasts.addContrast(obj.getAllAllowedNames(), args{:});
            else
                throw(exceptions.invalidProperty(sprintf('Domain Contrasts are not defined for the model type: %s', obj.modelType)));
            end
        end

        function obj = removeDomainContrast(obj, row)
            % Removes a given domain contrast from the project.
            %
            % Examples
            % --------
            % To remove the second domain contrast in the table (domain contrast in row 2).  
            % 
            % >>> domains.removeDomainContrast(2);
            % 
            % To remove domain contrast with a specific name.
            % 
            % >>> domains.removeDomainContrast('domain contrast 1');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the domain contrast to remove. If it is text, 
            %     it is the name of the domain contrast to remove.
            if isa(obj.domainContrasts, 'domainContrastsClass')
                obj.domainContrasts.removeContrast(row);
            else
                throw(exceptions.invalidProperty(sprintf('Domain Contrasts are not defined for the model type: %s', obj.modelType)));
            end
        end
 
        function obj = setDomainContrast(obj, row, options)   
            % General purpose method for updating properties of an existing domain contrast.
            %
            % Examples
            % --------
            % To change the properties of the second domain contrast in the object.
            % 
            % >>> domains.setDomainContrast(2, name='new domain contrast', model='Oxide Model'});
            %
            % To change the properties of a domain contrast called 'Domain Contrast 1'.
            % 
            % >>> domains.setDomainContrast('Domain Contrast 1', name='new domain contrast', model={'Oxide', 'Bilayer tails'});
            %  
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the domain contrast to update. If it is text, 
            %     it is the name of the domain contrast to update.
            % options
            %    Keyword/value pair to properties to update for the specific domain contrast.
            %       * name (char array or string, default: '') the name of the domain contrast.
            %       * model (char array or string or cell string) this should be a list of layer names that make up the slab model for this contrast.
            arguments
                obj
                row
                options.name
                options.model
            end
            if isa(obj.domainContrasts, 'domainContrastsClass')
                args = namedargs2cell(options); 
                obj.domainContrasts.setContrast(row, obj.getAllAllowedNames(), args{:});
            else
                throw(exceptions.invalidProperty(sprintf('Domain Contrasts are not defined for the model type: %s', obj.modelType)));
            end
        end
        
        function obj = setDomainContrastModel(obj, row, model)
            % Updates the model of an existing domain contrast.
            %
            % Examples
            % --------
            % To change the model of the second domain contrast in the project.
            % 
            % >>> domains.setDomainContrastModel(2, 'Oxide Model'});
            %
            % To change the properties of a domain contrast called 'Contrast 1'.
            % 
            % >>> domains.setDomainContrastModel('Contrast 1', {'Domains 1', 'Domains 2'});
            % 
            % To change multiple domain contrasts at once. The snippet below will change 1, 2, and 3.
            % 
            % >>> domains.setDomainContrastModel(1:3, {'Layer 1'});
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the domain contrast to update. If it is text, 
            %     it is the name of the domain contrast to update.
            % model: char array or string or cell string
            %     This should be a list of layer names that make up the slab model for this domain contrast.
            if isa(obj.domainContrasts, 'domainContrastsClass')
                obj.setDomainContrast(row, model=model);
            else
                throw(exceptions.invalidProperty(sprintf('Domain Contrasts are not defined for the model type: %s', obj.modelType)));
            end
        end

        % ----------------------------------------------------------------

        function outStruct = toStruct(obj)    
            % Converts the domainsClass into a structure array.
            %
            % Returns
            % -------
            % outStruct : struct
            %     A struct which contains the properties from the domainsClass.

            mainStruct = toStruct@projectClass(obj);

            if isa(obj.domainContrasts, 'domainContrastsClass')
                domainContrastStruct = obj.domainContrasts.toStruct(obj.getAllAllowedNames(), obj.modelType);
                domainContrastStruct = cell2struct(struct2cell(domainContrastStruct), ...
                                                    {'domainContrastNames', ...
                                                     'numberOfDomainContrasts', ...
                                                     'domainContrastLayers'});
            end

            domainRatioStruct = obj.domainRatio.toStruct();
            domainRatioStruct = cell2struct(struct2cell(domainRatioStruct), ...
                                            {'domainRatioNames', ...
                                             'domainRatioLimits', ...
                                             'domainRatioValues', ...
                                             'fitDomainRatio', ...
                                             'domainRatioPriors'});

            if isa(obj.domainContrasts, 'domainContrastsClass')
                outStruct = mergeStructs(mainStruct, ...
                                         domainContrastStruct, ...
                                         domainRatioStruct);
            else
                outStruct = mergeStructs(mainStruct, ...
                                         domainRatioStruct);
            end

        end

    end
    
    % ------------------------------------------------------------------

    methods (Access = protected)

        function obj = setLayersAndContrasts(obj, oldModel)
            % Adjust layers and contrast objects when the model type is
            % changed.
            %
            % Parameters
            % ----------
            % oldModel : modelTypes
            %     The model type of the project before it was changed.
            setLayersAndContrasts@projectClass(obj, oldModel);

            % Also need to define domain contrasts as necessary
            if strcmpi(obj.modelType, modelTypes.StandardLayers.value)
                if ~isa(obj.domainContrasts, 'domainContrastsClass')
                    obj.domainContrasts = domainContrastsClass();
                end
            else
                obj.domainContrasts = [];
            end
        end

    end

    methods (Hidden)

        function projectObj = projectClass(obj)
            % Object Converter method to convert to projectClass 
            % https://uk.mathworks.com/help/matlab/matlab_oop/converting-objects-to-another-class.html. 
            %
            % Examples
            % --------
            % >>> domains = domainsClass();
            % >>> normalProject = projectClass(domains);
            %
            % Returns
            % -------
            % projectObj : projectClass
            %     An instance of projectClass with the common properties copied from the domainsClass.
            projectObj = projectClass(obj.experimentName, obj.modelType, obj.geometry, obj.absorption);
            projectObj = copyProperties(obj, projectObj);

            % Need to treat contrasts separately due to changes in the
            % class for domains calculations
            projectObj.contrasts = copyProperties(obj.contrasts, contrastsClass(false));
        end

    end
    
end

