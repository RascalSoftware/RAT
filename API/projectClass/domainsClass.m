classdef domainsClass < projectClass
    
    % Class definition for Standard Layers with no absorption.
    % Layers defined in terms of thickness, roughness, real SLD and
    % hydration.
    %
    % Sub objects used are:
    % parametersClass      - parameter definition with priors
    % simContrastsClass    -
    
    properties
        domainRatio           % Class for specifying the ratio between domains
        simContrasts          % Modified contrast class with no data for domains
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
            obj.simContrasts = simContrastsClass();
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
        %   Editing of Sim Contrasts Block
        
        function obj = addSimContrast(obj, varargin)
            % Adds a new simContrast parameter. Expects a parameter name,
            % and with key-value pairs with one or more of the following
            % "bulk in", "bulk out", "model"
            % 
            % problem.addSimContrast('simContrast 1', 'nba', 'Silicon');
            allowedNames = obj.getAllAllowedNames();
            obj.simContrasts.addContrast(allowedNames, varargin{:});  
        end

        function obj = removeSimContrast(obj, row)
            % Removes a specified simContrast parameter. Expects
            % index or name of resolution to remove
            %
            % problem.removeSimContrast(1);
            obj.simContrasts.removeContrast(row);
        end
 
        function obj = setSimContrast(obj, row, varargin)   
            % Allow setting of all parameters in terms of name value pairs.
            % First input must be simContrast number or name, subsequent
            % inputs are name / value pairs for the parts involved
            %
            % problem.setContrast(1, 'name', 'simContrast')
                        
            % Get the list of allowed values depending on what is
            % set for the other contrasts.
            allowedValues = obj.getAllAllowedNames;
            
            % Call the setContrast method
            obj.simContrasts.setContrast(row, allowedValues, varargin{:});
        end
        
        function obj = setSimContrastModel(obj, row, model)
            % Edits the model of an existing contrast parameter. Expects
            % the index of contrast parameter and cell array of layer names
            %
            % problem.setSimContrastModel(1, {'layer 1'})
                        
            % Make a different allowed list depending on whether 
            % it is custom or layers
            if ~strcmpi(obj.modelType, {'custom layers','custom xy'})
                % Standard Layers
                allowedValues = obj.layers.getLayersNames();
            else
                % Custom models
                allowedValues = obj.customFile.getCustomNames();
            end
            
            % Call the setContrastModel method
            obj.simContrasts.setContrastModel(row, obj.modelType, allowedValues, model);
        end

    end
    
    % ------------------------------------------------------------------
    
    methods (Access = protected)
        
        function displayScalarObject(obj)
            % Display the whole class. Call the display methods for
            % the sub-classes where appropriate
            
            % There are two versions, depending on whether the model
            % is standard layers or custom, the difference being
            % the display of the layers table..
            
            % Display initial properties from superclass
            displayScalarObject@projectClass(obj);

            % Display the domains ratio contrast
            fprintf('   Domain Ratios: ----------------------------------------------------------------------------------------------- \n\n');
            obj.domainRatio.displayParametersTable;

            % Display the simContrasts object
            fprintf('   Sim Contrasts: ----------------------------------------------------------------------------------------------- \n\n');
            obj.simContrasts.displayContrastsObject; 
        end
        
    end
    
end
