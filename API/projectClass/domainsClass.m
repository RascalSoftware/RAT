classdef domainsClass < projectClass
    
    % Class definition for Standard Layers with no absorption.
    % Layers defined in terms of thickness, roughness, real SLD and
    % hydration.
    %
    % Sub objects used are:
    % parametersClass         - parameter definition with priors
    % domainContrastsClass    - additional contrasts object for domains
    
    properties
        domainRatio          % Class for specifying the ratio between domains
        domainContrasts      % Modified contrast class with no data for domains
    end

    methods

        function obj = domainsClass(experimentName, calculationType, modelType, geometry, absorption)
            % Creates a Project object for a domains calculation.
            % The input arguments are the experiment name which is a char
            % array; the calculation type, which is a calculationTypes
            % enum; the model type, which is a modelTypes enum; the
            % geometry, which is a geometryOptions enum; and a logical to
            % state whether or not absorption terms are included in the
            % refractive index.
            % All of the arguments are optional.
            %
            % problem = domainsClass('New experiment');
            arguments
                experimentName {mustBeTextScalar} = ''
                calculationType = calculationTypes.Domains
                modelType = modelTypes.StandardLayers
                geometry = geometryOptions.AirSubstrate
                absorption {mustBeA(absorption,'logical')} = false
            end
            
            % Call projectClass constructor
            obj@projectClass(experimentName, calculationType, modelType, geometry, absorption);

            % Create a contrasts class for a domains calculation
            obj.contrasts = contrastsClass(domains=true);

            % For a domains calculation, initialise domain ratio parameter
            % class and, for a standard layers model, secondary contrasts
            % object
            obj.domainRatio = parametersClass('Domain Ratio 1',0.4,0.5,0.6,false,'uniform',0,Inf);
            if strcmpi(obj.modelType, modelTypes.StandardLayers.value)
                obj.domainContrasts = domainContrastsClass();
            end
        end

        function projectObj = toProjectClass(obj)
            % Alias of the converter routine from domainsClass to
            % projectClass.
            % This routine takes the currently defined project and
            % converts it to a nonPolarised calculation, preserving all
            % currently defined properties.
            %
            % nonPolarisedProblem = problem.toProjectClass();
            projectObj = obj.projectClass();
        end

        function obj = setModelType(obj, modelType)
            % Sets the experiment type. The type should be a string,  
            % either "standard layers", "custom layers", or "custom xy" is
            % permitted.
            %
            % problem.setModelType('Custom Layers');
            setModelType@projectClass(obj, modelType);

            % Also need to define domain contrasts as necessary
            if strcmpi(obj.modelType, modelTypes.StandardLayers.value)
                if ~isa(obj.domainContrasts, 'domainContrastsClass')
                    obj.domainContrasts = domainContrastsClass();
                end
            else
                obj.domainContrasts = [];
            end
        end

        function names = getAllAllowedNames(obj)           
            % Returns a cell array of all currently
            % set parameter names for the project.
            names = getAllAllowedNames@projectClass(obj);
            names.domainRatioNames = obj.domainRatio.getNames();
            if isa(obj.domainContrasts, 'domainContrastsClass')
                names.domainContrastsNames = obj.domainContrasts.getNames();
            end
        end
    
        % ----------------------------------------------------------------
        %
        %   Editing of Domains Contrasts Block

        function obj = setContrastModel(obj, row, model)
            % Edits the model of an existing contrast parameter. Expects
            % the index of contrast parameter and cell array of layer names
            %
            % problem.setContrastModel(1, {'layer 1'})
                        
            % Make a different allowed list depending on whether 
            % it is custom or layers
            if strcmpi(obj.modelType, modelTypes.StandardLayers.value)
                % Standard Layers
                allowedValues = obj.domainContrasts.getNames();
            else
                % Custom models
                allowedValues = obj.customFile.getNames();
            end
            
            % Call the setContrastModel method
            obj.contrasts.setContrastModel(row, obj.modelType, allowedValues, model);
        end

        % -------------------------------------------------------------------
        % Editing of Domain Ratio block
        
        function obj = addDomainRatio(obj, varargin)
            % Adds a new domain ratio parameter. Expects the name
            % of domain ratio, min, value, max, and if fit is off or on
            % 
            % problem.addDomainRatio('Domain Ratio 2', 0.4, 0.5, 0.6, true);
            obj.domainRatio.addParameter(varargin{:});
        end
        
        function obj = removeDomainRatio(obj, varargin)
            % Removes specified domain ratio parameter. Expects the
            % name/index of domain ratio to remove
            % 
            % problem.removeDomainRatio(2);
           obj.domainRatio.removeParameter(varargin{:}); 
        end
        
        function obj = setDomainRatio(obj, varargin)
            % Edits an existing domain ratio parameter. Expects the
            % index of domain ratio to edit and key-value pairs
            %
            % problem.setDomainRatio(1, 'name','Domain Ratio 1', 'value', 0.55);
            obj.domainRatio.setParameter(varargin{:});
        end
    
        % ----------------------------------------------------------------
        %
        %   Editing of Domains Contrasts Block
        
        function obj = addDomainContrast(obj, varargin)
            % Adds a new domainContrast parameter. Expects a parameter name,
            % and with key-value pairs with one or more of the following
            % "bulk in", "bulk out", "model"
            % 
            % problem.addDomainContrast('domainContrast 1', 'nba', 'Silicon');
            if isa(obj.domainContrasts, 'domainContrastsClass')
                allowedNames = obj.getAllAllowedNames();
                obj.domainContrasts.addContrast(allowedNames, varargin{:});
            else
                throw(invalidProperty(sprintf('Domain Contrasts are not defined for the model type: %s', obj.modelType)));
            end
        end

        function obj = removeDomainContrast(obj, row)
            % Removes a specified domainContrast parameter. Expects
            % index or name of resolution to remove
            %
            % problem.removeDomainContrast(1);
            if isa(obj.domainContrasts, 'domainContrastsClass')
                obj.domainContrasts.removeContrast(row);
            else
                throw(invalidProperty(sprintf('Domain Contrasts are not defined for the model type: %s', obj.modelType)));
            end
        end
 
        function obj = setDomainContrast(obj, row, varargin)   
            % Allow setting of all parameters in terms of name value pairs.
            % First input must be domainContrast number or name, subsequent
            % inputs are name / value pairs for the parts involved
            %
            % problem.setContrast(1, 'name', 'domainContrast')
            if isa(obj.domainContrasts, 'domainContrastsClass')
                % Get the list of allowed values depending on what is
                % set for the other contrasts.
                allowedValues = obj.getAllAllowedNames;
                
                % Call the setContrast method
                obj.domainContrasts.setContrast(row, allowedValues, varargin{:});
            else
                throw(invalidProperty(sprintf('Domain Contrasts are not defined for the model type: %s', obj.modelType)));
            end
        end
        
        function obj = setDomainContrastModel(obj, row, model)
            % Edits the model of an existing contrast parameter. Expects
            % the index of contrast parameter and cell array of layer names
            %
            % problem.setDomainContrastModel(1, {'layer 1'})
            if isa(obj.domainContrasts, 'domainContrastsClass')
                allowedValues = obj.layers.getNames();
                obj.domainContrasts.setContrastModel(row, obj.modelType, allowedValues, model);
            else
                throw(invalidProperty(sprintf('Domain Contrasts are not defined for the model type: %s', obj.modelType)));
            end
        end

        % ----------------------------------------------------------------

        function outStruct = toStruct(obj)    
            % Converts the domains class parameters into a struct array
            % for input into the RAT toolbox

            mainStruct = toStruct@projectClass(obj);

            if isa(obj.domainContrasts, 'domainContrastsClass')
                domainContrastStruct = obj.domainContrasts.toStruct(obj.getAllAllowedNames, obj.modelType);
                domainContrastStruct = cell2struct(struct2cell(domainContrastStruct), ...
                                                    {'domainContrastNames', ...
                                                     'numberOfDomainContrasts', ...
                                                     'domainContrastRepeatSLDs', ...
                                                     'domainContrastLayers'});
            end

            domainRatioStruct = obj.domainRatio.toStruct();
            domainRatioStruct = cell2struct(struct2cell(domainRatioStruct), ...
                                            {'domainRatioNames', ...
                                             'ndomainRatios', ...
                                             'domainRatioConstr', ...
                                             'domainRatios', ...
                                             'domainRatioFitYesNo', ...
                                             'domainRatioPriors'});

            outStruct = mergeStructs(mainStruct, ...
                                     domainContrastStruct, ...
                                     domainRatioStruct);

        end

    end
    
    % ------------------------------------------------------------------

    methods (Hidden)

        function projectObj = projectClass(obj)
            % Converter routine from domainsClass to projectClass.
            % This routine takes the currently defined project and
            % converts it to a nonPolarised calculation, preserving all
            % currently defined properties.
            %
            % nonPolarisedProblem = problem.projectClass();
            projectObj = projectClass(obj.experimentName, calculationTypes.NonPolarised, obj.modelType, obj.geometry, obj.absorption);
            projectObj = copyProperties(obj, projectObj);

            % Need to treat contrasts separately due to changes in the
            % class for domains calculations
            projectObj.contrasts = copyProperties(obj.contrasts, contrastsClass(oilWater=obj.contrasts.oilWaterCalc));
        end

    end
    
end

