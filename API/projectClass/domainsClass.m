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

        function obj = domainsClass(experimentName)
            % Creates a Project object for a domains calculation.
            % The only argument is the experiment name which is a char
            % array, which is optional
            %
            % problem = domainsClass(''New experiment');
            arguments
                experimentName {mustBeTextScalar} = ''
            end
            
            % Call projectClass constructor
            obj@projectClass(experimentName);
            obj.calculationType = calculationTypes.Domains.value;

            % Create a contrasts class for a domains calculation
            obj.contrasts = contrastsClass(true);

            % For a domains calculation, initialise secondary contrasts
            % object and domain ratio parameter class
            obj.domainContrasts = domainContrastsClass();
            obj.domainRatio = parametersClass('Domain Ratio 1',0.4,0.5,0.6,false,'uniform',0,Inf);
        end

        function names = getAllAllowedNames(obj)           
            % Returns a cell array of all currently
            % set parameter names for the project.
            names = getAllAllowedNames@projectClass(obj);
            names.domainRatioNames = obj.domainRatio.getParamNames();
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
            allowedNames = obj.getAllAllowedNames();
            obj.domainContrasts.addContrast(allowedNames, varargin{:});  
        end

        function obj = removeDomainContrast(obj, row)
            % Removes a specified domainContrast parameter. Expects
            % index or name of resolution to remove
            %
            % problem.removeDomainContrast(1);
            obj.domainContrasts.removeContrast(row);
        end
 
        function obj = setDomainContrast(obj, row, varargin)   
            % Allow setting of all parameters in terms of name value pairs.
            % First input must be domainContrast number or name, subsequent
            % inputs are name / value pairs for the parts involved
            %
            % problem.setContrast(1, 'name', 'domainContrast')
                        
            % Get the list of allowed values depending on what is
            % set for the other contrasts.
            allowedValues = obj.getAllAllowedNames;
            
            % Call the setContrast method
            obj.domainContrasts.setContrast(row, allowedValues, varargin{:});
        end
        
        function obj = setDomainContrastModel(obj, row, model)
            % Edits the model of an existing contrast parameter. Expects
            % the index of contrast parameter and cell array of layer names
            %
            % problem.setDomainContrastModel(1, {'layer 1'})
                        
            % Make a different allowed list depending on whether 
            % it is custom or layers
            if strcmpi(obj.modelType, modelTypes.StandardLayers.value)
                % Standard Layers
                allowedValues = obj.layers.getLayersNames();
            else
                % Custom models
                allowedValues = obj.customFile.getCustomNames();
            end
            
            % Call the setContrastModel method
            obj.domainContrasts.setContrastModel(row, obj.modelType, allowedValues, model);
        end

        function [domainContrastsStruct, domainRatioStruct] = makeDomainsStructs(obj, allNames, modelType)    
            % Converts the domains class parameters into a struct array
            % for input into the RAT toolbox
            % The expected inputs are the list of allowed names and the
            % model type which are required to make a domainContrasts
            % struct.
            domainContrastsStruct = obj.domainContrasts.toStruct(allNames, modelType);
            domainRatioStruct = obj.domainRatio.toStruct();
        end

    end
    
    % ------------------------------------------------------------------
    
    methods (Access = protected)
        
        function displayScalarObject(obj)
            % Display the whole class. Call the display methods for
            % the sub-classes where appropriate
            
            % Display initial properties from superclass
            displayScalarObject@projectClass(obj);

            % Display the domains ratio contrast
            fprintf('   Domain Ratios: ----------------------------------------------------------------------------------------------- \n\n');
            obj.domainRatio.displayParametersTable;

            % Display the domainContrasts object
            fprintf('   Domains Contrasts: ----------------------------------------------------------------------------------------------- \n\n');
            obj.domainContrasts.displayContrastsObject; 
        end
        
    end
    
end

