classdef projectParametersMixin < handle
    properties
        parameters
        bulkIn
        bulkOut
        scalefactors
    end
    
    properties (SetAccess = immutable)
        protectedParameters
    end
    methods
        function obj = projectParametersMixin()
            % Initialise parameters objects
            obj.parameters = parametersClass('Substrate Roughness',1,3,5,true,priorTypes.Uniform,0,Inf);
            obj.protectedParameters = cellstr(obj.parameters.getNames');

            % Initialise bulkIn objects
            obj.bulkIn = parametersClass('SLD Air',0,0,0,false,priorTypes.Uniform,0,Inf);
            
            % Initialise bulkOut objects
            obj.bulkOut = parametersClass('SLD D2O',6.2e-6,6.35e-6,6.35e-6,false,priorTypes.Uniform,0,Inf);
            
            % Initialise scalefactors objects
            obj.scalefactors = parametersClass('Scalefactor 1',0.02,0.23,0.25,false,priorTypes.Uniform,0,Inf);
        end
        
        %----------------------------------------------------------------------------
        % Editing Parameters Block
        %----------------------------------------------------------------------------
        
        function obj = addParameterGroup(obj, paramGroup)
            % Adds a group of parameters to the project.
            %
            % Examples
            % --------
            % To add 2 new parameters with names only.
            % 
            % >>> project.addParameterGroup({{'Tails'}, {'Heads'}});
            % 
            % To add 2 parameters with more properties.
            % 
            % >>> group = {{'Tails', 20, 50, 60, true, 'gaussian', 1, 5};
            % >>>          {'Heads', 20, 50, 60, true, 'uniform'}};
            % >>> 
            % >>> project.addParameterGroup(group);
            % 
            % Parameters
            % ----------
            % paramGroup : cell of cell arrays
            %     The inner cells should contain the properties of the parameters to add. 
            for i = 1:length(paramGroup)
                if iscell(paramGroup{i})
                    obj.addParameter(paramGroup{i}{:});
                else
                    throw(exceptions.invalidType('Expecting a cell array of parameters in ''addParameterGroup'''));
                end
            end
        end
        
        function obj = addParameter(obj, name, min, value, max, fit, priorType, mu, sigma)
            % Adds an new parameter to the project. 
            %
            % Examples
            % --------
            % To add a new parameter with no properties and an autogenerated name.
            % 
            % >>> project.addParameter();
            % 
            % To add a parameter with all available properties.
            % 
            % >>> project.addParameter('Tails', 20, 50, 60, true, 'gaussian', 1, 5);
            % 
            % Other examples of adding parameters with a subset of properties.
            % 
            % >>> project.addParameter('Tails');  % Parameter name only with others set to default
            % >>> project.addParameter('Tails', 23);  % Parameter name and min only. Value and max will be set to 23 to keep limits valid
            % >>> project.addParameter('Tails', 23, 24, 25, true);  % priors will be default
            % 
            % Parameters
            % ----------
            % name : string or char array, default: auto-generated name
            %     The name of the parameter. 
            % min : double, default: 0.0
            %     The minimum value that the parameter could take when fitted.
            % value : double, default: 0.0
            %     The value of the parameter, default will be equal to ``min`` if this is not set.
            % max : double, default: 0.0
            %     The maximum value that the parameter could take when fitted, default will be equal to ``value`` if this is not set.
            % fit : logical, default: false
            %     Whether the parameter should be fitted in a calculation.
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
            obj.parameters.addParameter(name, min, value, max, fit, priorType, mu, sigma); 
        end
                
        function obj = removeParameter(obj, row)
            % Removes a parameter from the project. 
            %
            % Examples
            % --------
            % To remove the second parameter in the table (parameter in row 2).  
            % 
            % >>> project.removeParameter(2);
            % 
            % To remove parameter with a specific name.
            % 
            % >>> project.removeParameter('Tails');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the parameter to remove. If it is text, 
            %     it is the name of the parameter to remove.
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
            end
            
        end
        
        function obj = setParameter(obj, row, options)
            % General purpose method for updating properties of an existing parameter. 
            % Any unset property will remain unchanged.
            %
            % Examples
            % --------
            % To change the name and value of the second parameter in the table (parameter in row 2).
            % 
            % >>> project.setParameter(2, 'name', 'Heads', 'value', 50);
            % 
            % To change the all properties of a parameter called 'Tails'.
            % 
            % >>> project.setParameter('Tails', 'name', 'Heads', 'min', 20, 'value', 50, 'max', 60, ...
            % >>>                      'fit', true, 'priorType', 'gaussian', 'mu', 1, 'sigma', 5);
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the parameter to update. If it is text, 
            %     it is the name of the parameter to update.
            % options
            %    Keyword/value pair to properties to update for the specific parameter.
            %       * name (char array or string, default: '') the new name of the parameter.
            %       * min (double, default: []) the new minimum value of the parameter.
            %       * value (double, default: []) the new value of the parameter.
            %       * max (double, default: []) the new maximum value of the parameter.
            %       * fit (logical, default: logical.empty()) the new fit flag of the parameter.
            %       * priorTypes (priorTypes, default: priorTypes.empty()) the new prior type of the parameter.            
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
            % Make sure we don't remove any protected parameters
            if ~isempty(options.name) && ((isnumeric(row) && row <= length(obj.protectedParameters)) || any((strcmpi(row, obj.protectedParameters))))
                throw(exceptions.invalidOption(sprintf('Can''t remove protected parameters')));
            end

            obj.parameters.setParameter(row, 'name', options.name, 'min', options.min, 'value', options.value, ... 
                                        'max', options.max, 'fit', options.fit, 'priorType', options.priorType, ...
                                        'mu', options.mu, 'sigma', options.sigma);
        end

        %----------------------------------------------------------------------------
        %   Editing of Bulk out block
        %----------------------------------------------------------------------------
        
        function obj = addBulkOut(obj, name, min, value, max, fit, priorType, mu, sigma)
            % Adds a new bulk-out parameter to project. 
            %
            % Examples
            % --------
            % To add a new bulk-out with no properties and an autogenerated name.
            % 
            % >>> project.addBulkOut();
            % 
            % To add a bulk-out with all available properties.
            % 
            % >>> project.addBulkOut('SLD ACMW', -1e-6, 0.0, 1e-6, true, 'gaussian', 1, 5);
            % 
            % Other examples of adding bulk-out with a subset of properties.
            % 
            % >>> project.addBulkOut('SLD ACMW');  % Bulk-out name only with others set to default
            % >>> project.addBulkOut('SLD ACMW', 23);  % Bulk-out name and min only. Value and max will be set to 23 to keep limits valid
            % >>> project.addBulkOut('SLD ACMW', 23, 24, 25, true);  % priors will be default
            % 
            % Parameters
            % ----------
            % name : string or char array, default: auto-generated name
            %     The name of the bulk-out parameter. 
            % min : double, default: 0.0
            %     The minimum value that the bulk-out parameter could take when fitted.
            % value : double, default: 0.0
            %     The value of the bulk-out parameter, default will be equal to ``min`` if this is not set.
            % max : double, default: 0.0
            %     The maximum value that the bulk-out parameter could take when fitted, default will be equal to ``value`` if this is not set.
            % fit : logical, default: false
            %     Whether the bulk-out parameter should be fitted in a calculation.
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
            obj.bulkOut.addParameter(name, min, value, max, fit, priorType, mu, sigma);
        end
        
        function obj = removeBulkOut(obj, row)
            % Removes specified bulk-out parameter from the project. 
            %
            % Examples
            % --------
            % To remove the second bulk-out in the table (parameter in row 2).  
            % 
            % >>> project.removeBulkOut(2);
            % 
            % To remove bulk-out with a specific name.
            % 
            % >>> project.removeBulkOut('SLD H2O');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the bulk-out parameter to remove. If it is text, 
            %     it is the name of the bulk-out parameter to remove.
            obj.bulkOut.removeParameter(row);
        end
        
        function obj = setBulkOut(obj, row, options)
            % General purpose method for updating properties of an existing bulk-out parameter. 
            % Any unset property will remain unchanged.
            %
            % Examples
            % --------
            % To change the name and value of the second bulk-out parameter in the table (parameter in row 2).
            % 
            % >>> project.setParameter(2, 'name', 'SLD H2O', 'value', 50);
            % 
            % To change the all properties of a bulk-out parameter called 'SLD H2O'.
            % 
            % >>> project.setParameter('SLD H2O', 'name', 'SLD D2O', 'min', 20, 'value', 50, 'max', 60, ...
            % >>>                      'fit', true, 'priorType', 'gaussian', 'mu', 1, 'sigma', 5);
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the bulk-out parameter to update. If it is text, 
            %     it is the name of the bulk-out parameter to update.
            % options
            %    Keyword/value pair to properties to update for the specific parameter.
            %       * name (char array or string, default: '') the new name of the bulk-out parameter.
            %       * min (double, default: []) the new minimum value of the bulk-out parameter.
            %       * value (double, default: []) the new value of the bulk-out parameter.
            %       * max (double, default: []) the new maximum value of the bulk-out parameter.
            %       * fit (logical, default: logical.empty()) the new fit flag of the bulk-out parameter.
            %       * priorTypes (priorTypes, default: priorTypes.empty()) the new prior type of the bulk-out parameter.            
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
            obj.bulkOut.setParameter(row, 'name', options.name, 'min', options.min, 'value', options.value, ... 
                                     'max', options.max, 'fit', options.fit, 'priorType', options.priorType, ...
                                     'mu', options.mu, 'sigma', options.sigma);
        end
        
        
        %----------------------------------------------------------------------------
        % Editing of bulk in block
        %----------------------------------------------------------------------------
        
        function obj = addBulkIn(obj, name, min, value, max, fit, priorType, mu, sigma)
            % Adds a new bulk-in parameter to project. 
            %
            % Examples
            % --------
            % To add a new bulk-in parameter with no properties and an autogenerated name.
            % 
            % >>> project.addBulkIn();
            % 
            % To add a bulk-in parameter with all available properties.
            % 
            % >>> project.addBulkIn('Silicon', -1e-6, 0.0, 1e-6, true, 'gaussian', 1, 5);
            % 
            % Other examples of adding bulk-in parameter with a subset of properties.
            % 
            % >>> project.addBulkIn('Silicon');  % Bulk-in name only with others set to default
            % >>> project.addBulkIn('Silicon', 23);  % Bulk-in name and min only. Value and max will be set to 23 to keep limits valid
            % >>> project.addBulkIn('Silicon', 23, 24, 25, true);  % priors will be default
            % 
            % Parameters
            % ----------
            % name : string or char array, default: auto-generated name
            %     The name of the bulk-in parameter. 
            % min : double, default: 0.0
            %     The minimum value that the bulk-in parameter could take when fitted.
            % value : double, default: 0.0
            %     The value of the bulk-in parameter, default will be equal to ``min`` if this is not set.
            % max : double, default: 0.0
            %     The maximum value that the bulk-in parameter could take when fitted, default will be equal to ``value`` if this is not set.
            % fit : logical, default: false
            %     Whether the bulk-in parameter should be fitted in a calculation.
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
            obj.bulkIn.addParameter(name, min, value, max, fit, priorType, mu, sigma);
        end
        
        function obj = removeBulkIn(obj, row)
            % Removes specified bulk-in parameter from the project. 
            %
            % Examples
            % --------
            % To remove the second bulk-in in the table (parameter in row 2).  
            % 
            % >>> project.removeBulkIn(2);
            % 
            % To remove bulk-in with a specific name.
            % 
            % >>> project.removeBulkIn('Silicon');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the bulk-in parameter to remove. If it is text, 
            %     it is the name of the bulk-in parameter to remove.
            obj.bulkIn.removeParameter(row);
        end
        
        function obj = setBulkIn(obj, row, options)
            % General purpose method for updating properties of an existing bulk-in parameter. 
            % Any unset property will remain unchanged.
            %
            % Examples
            % --------
            % To change the name and value of the second bulk-in parameter in the table (parameter in row 2).
            % 
            % >>> project.setParameter(2, 'name', 'Silicon', 'value', 50);
            % 
            % To change the all properties of a parameter called 'Silicon'.
            % 
            % >>> project.setParameter('Silicon', 'name', 'Air', 'min', 20, 'value', 50, 'max', 60, ...
            % >>>                      'fit', true, 'priorType', 'gaussian', 'mu', 1, 'sigma', 5);
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the bulk-in parameter to update. If it is text, 
            %     it is the name of the bulk-in parameter to update.
            % options
            %    Keyword/value pair to properties to update for the specific parameter.
            %       * name (char array or string, default: '') the new name of the bulk-in parameter.
            %       * min (double, default: []) the new minimum value of the bulk-in parameter.
            %       * value (double, default: []) the new value of the bulk-in parameter.
            %       * max (double, default: []) the new maximum value of the bulk-in parameter.
            %       * fit (logical, default: logical.empty()) the new fit flag of the bulk-in parameter.
            %       * priorTypes (priorTypes, default: priorTypes.empty()) the new prior type of the bulk-in parameter.            
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
            obj.bulkIn.setParameter(row, 'name', options.name, 'min', options.min, 'value', options.value, ... 
                                    'max', options.max, 'fit', options.fit, 'priorType', options.priorType, ...
                                    'mu', options.mu, 'sigma', options.sigma);
        end
        
        %----------------------------------------------------------------------------
        % Editing of scalefactors block
        %----------------------------------------------------------------------------
        
        function obj = addScalefactor(obj, name, min, value, max, fit, priorType, mu, sigma)
            % Adds a new scalefactor parameter to project. 
            %
            % Examples
            % --------
            % To add a new scalefactor with no properties and an autogenerated name.
            % 
            % >>> project.addScalefactor();
            % 
            % To add a scalefactor with all available properties.
            % 
            % >>> project.addScalefactor('Scalefactor 2', -1e-6, 0.0, 1e-6, true, 'gaussian', 1, 5);
            % 
            % Other examples of adding scalefactor with a subset of properties.
            % 
            % >>> project.addScalefactor('Scalefactor 2');  % Scalefactor name only with others set to default
            % >>> project.addScalefactor('Scalefactor 2', 23);  % Scalefactor name and min only. Value and max will be set to 23 to keep limits valid
            % >>> project.addScalefactor('Scalefactor 2', 0.1, 0.19, 1.0, true;  % priors will be default
            % 
            % Parameters
            % ----------
            % name : string or char array, default: auto-generated name
            %     The name of the scalefactor parameter. 
            % min : double, default: 0.0
            %     The minimum value that the scalefactor parameter could take when fitted.
            % value : double, default: 0.0
            %     The value of the scalefactor parameter, default will be equal to ``min`` if this is not set.
            % max : double, default: 0.0
            %     The maximum value that the scalefactor parameter could take when fitted, default will be equal to ``value`` if this is not set.
            % fit : logical, default: false
            %     Whether the scalefactor parameter should be fitted in a calculation.
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
            obj.scalefactors.addParameter(name, min, value, max, fit, priorType, mu, sigma);
        end
        
        function obj = removeScalefactor(obj, row)
            % Removes specified scalefactor parameter from the project. 
            %
            % Examples
            % --------
            % To remove the second scalefactor in the table (parameter in row 2).  
            % 
            % >>> project.removeScalefactor(2);
            % 
            % To remove scalefactor with a specific name.
            % 
            % >>> project.removeScalefactor('Scalefactor 2');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the parameter to remove. If it is text, 
            %     it is the name of the parameter to remove.
           obj.scalefactors.removeParameter(row); 
        end
        
        function obj = setScalefactor(obj, row, options)
            % General purpose method for updating properties of an existing scalefactor parameter. 
            % Any unset property will remain unchanged.
            %
            % Examples
            % --------
            % To change the name and value of the second scalefactor parameter in the table (parameter in row 2).
            % 
            % >>> project.setParameter(2, 'name', 'Scalefactor 1', 'value', 50);
            % 
            % To change the all properties of a parameter called 'Scalefactor 1'.
            % 
            % >>> project.setParameter('Scalefactor 1', 'name', 'Scalefactor 2', 'min', 20, 'value', 50, 'max', 60, ...
            % >>>                      'fit', true, 'priorType', 'gaussian', 'mu', 1, 'sigma', 5);
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the scalefactor parameter to update. If it is text, 
            %     it is the name of the scalefactor parameter to update.
            % options
            %    Keyword/value pair to properties to update for the specific parameter.
            %       * name (char array or string, default: '') the new name of the scalefactor parameter.
            %       * min (double, default: []) the new minimum value of the scalefactor parameter.
            %       * value (double, default: []) the new value of the scalefactor parameter.
            %       * max (double, default: []) the new maximum value of the scalefactor parameter.
            %       * fit (logical, default: logical.empty()) the new fit flag of the scalefactor parameter.
            %       * priorTypes (priorTypes, default: priorTypes.empty()) the new prior type of the scalefactor parameter.            
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
            obj.scalefactors.setParameter(row, 'name', options.name, 'min', options.min, 'value', options.value, ... 
                                    'max', options.max, 'fit', options.fit, 'priorType', options.priorType, ...
                                    'mu', options.mu, 'sigma', options.sigma);
        end      
    end
end
