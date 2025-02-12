classdef parametersClass < tableUtilities
    % This is the class definition for
    % the parameters block.
    
    methods
        function obj = parametersClass(varargin)
            % Class constructor.
            % Creates a Parameter object. The arguments should be 
            % the content of the first parameter. A parameter consists of
            % a name (string), min (double), value (double), max (double),
            % fit flag (logical), prior type (string), mu (double), and
            % sigma (double) values in that order.
            % Default values are used when adding the parameter if no
            % arguments are provided, otherwise a subset of the arguments
            % can be provided.
            % The following are assumed from number of arguments: 
            % for 1 input, the name only is provided
            % for 2 inputs, the name and value are provided
            % for 4 inputs, the name, min, value, and max are provided
            % for 5 inputs, the name, min, value, max, and fit? are provided
            % for 8 inputs, all parameter properties are provided
            %
            % params = parametersClass('Tails', 10, 20, 30, true, priorTypes.Uniform.value, 0, Inf);
            sz = [0, 8];
            varTypes = {'string','double','double','double','logical','string','double','double'};
            varNames = {'Name','Min','Value','Max','Fit?','Prior Type','mu','sigma'};
            obj.varTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
            if isempty(varargin)
                obj.addParameter();
            else
                obj.addParameter(varargin{:});
            end
        end
        
        function obj = addParameter(obj, varargin)
            % Adds an new parameter to the parameters table. Default 
            % values are used when adding the parameter if no arguments are 
            % provided, otherwise a subset of the arguments can be provided.
            % The following are assumed from number of arguments: 
            % for 1 input, the name only is provided
            % for 2 inputs, the name and value are provided
            % for 4 inputs, the name, min, value, and max are provided
            % for 5 inputs, the name, min, value, max, and fit? are provided
            % for 8 inputs, all parameter properties are provided
            %
            % params.addParameter('Tails Roughness');  

            % Set the default parameters
            values = [0.0, 0.0, 0.0];
            fit = false;
            priorType = priorTypes.Uniform.value;
            priorValues = [0, Inf];

            if isempty(varargin)
                % No input parameter - create name and add defaults
                name = sprintf('new parameter %d',obj.autoNameCounter);
                newRow = {name, values(1), values(2), values(3), fit, priorType, priorValues(1), priorValues(2)};
                obj.addRow(newRow{:});
            end
            
            if iscell(varargin) && ~isempty(varargin)
                inputCell = varargin;
                
                % First input must be a parameter name
                if ~isText(inputCell{1})
                    throw(exceptions.invalidType('First value must be param name (text)'));
                end
                
                % If length is 1, assume name only
                % and fill in the rest with defaults
                name = inputCell{1};
                
                switch length(inputCell)
                    case 1                           
                    case 2
                        % If length is 2, assume name and value
                        % pair. Fill in the rest automatically
                        values = [inputCell{2} inputCell{2} inputCell{2}];
                    case 4
                        % If length is 4, assume we are getting the
                        % limits as well as the values
                        values = [inputCell{2} inputCell{3} inputCell{4}]; 
                    case 5
                         % If length is 5, then assume we are setting
                         % everything except priors
                        values = [inputCell{2} inputCell{3} inputCell{4}];
                        fit = inputCell{5};
                    case 8
                        % Case 8 must be everything including the prior
                        values = [inputCell{2} inputCell{3} inputCell{4}];
                        fit = inputCell{5};
                        priorType = inputCell{6};
                        priorValues = [inputCell{7} inputCell{8}];
                       
                    % If not one of these options, throw an error
                    otherwise
                        throw(exceptions.invalidNumberOfInputs('Unrecognised inputs to ''addParameter'''));
                end
                
                obj.validateLimits(values(1), values(2), values(3));

                if ~islogical(fit)
                    throw(exceptions.invalidType('Parameter "fit" must be a logical value i.e. true or false'));
                end
                
                priors = obj.validatePriors(priorType, priorValues(1), priorValues(2));
                newRow = {name, values(1), values(2), values(3), fit, priors{1}, priors{2}, priors{3}};
                obj.addRow(newRow{:});

            end
        end
        
        function obj = removeParameter(obj, row)
            % Removes a parameter from the parameters table. 
            % Expects a single parameter name or index/array of parameter
            % names or indices to remove
            %
            % params.removeParameter(2);
            obj.removeRow(row);
        end
        
        function obj = setParameter(obj, row, varargin)
            % General purpose set parameter method. Expects index or name
            % of parameter and keyword/value pairs to set
            %
            % params.setParameter(2, 'value', 50);

            % Always need three or more inputs to set parameter value
            if length(varargin) < 2 || mod(length(varargin), 2) ~= 0
                throw(exceptions.invalidNumberOfInputs('The input to ''setParameter'' should be a index/parameter name and a set of name-value pairs'));
            end

            row = obj.getValidRow(row);
            p = inputParser;
            p.PartialMatching = false;
            addParameter(p, 'name', obj.varTable{row, 1}{:}, @isText);
            addParameter(p, 'min', obj.varTable{row, 2}, @isnumeric);
            addParameter(p, 'value', obj.varTable{row, 3}, @isnumeric);
            addParameter(p, 'max', obj.varTable{row, 4}, @isnumeric);
            addParameter(p, 'fit', obj.varTable{row, 5}, @islogical);
            addParameter(p, 'priorType', obj.varTable{row, 6}{:}, @(x) isText(x) || isenum(x));
            addParameter(p, 'mu', obj.varTable{row, 7}, @isnumeric);
            addParameter(p, 'sigma', obj.varTable{row, 8}, @isnumeric);

            parse(p, varargin{:});
            inputs = p.Results;

            obj.validateLimits(inputs.min, inputs.value, inputs.max);
            % Apply values
            obj.setName(row, inputs.name);
            obj.varTable{row, 2} = inputs.min;
            obj.varTable{row, 3} = inputs.value;
            obj.varTable{row, 4} = inputs.max;
            obj.setFit(row, inputs.fit);
            obj.setPrior(row, inputs.priorType, inputs.mu, inputs.sigma);
        end
        
        function obj = setPrior(obj, row, varargin)
            % Sets the prior of an existing parameter. Expects index or
            % name of parameter and the new prior type ('uniform',
            % 'gaussian', 'jeffreys') with mu and sigma value if applicable
            %
            % params.setPrior(2, priorTypes.Gaussian, 1, 2);
            if isempty(varargin) || length(varargin) > 3
                throw(exceptions.invalidNumberOfInputs('''setPrior'' requires 1 to 3 arguments i.e. priorType then optional mu and sigma'));
            end
            
            row = obj.getValidRow(row);
            switch length(varargin)
                case 1
                    varargin{end + 1} = obj.varTable{row, 7};
                    varargin{end + 1} = obj.varTable{row, 8};
                case 2
                    varargin{end + 1} = obj.varTable{row, 8};
            end
            
            priors = obj.validatePriors(varargin{1}, varargin{2}, varargin{3});
            obj.varTable{row, 6} = priors(1);
            obj.varTable{row, 7} = priors{2};
            obj.varTable{row, 8} = priors{3};
        end
        
        function obj = setValue(obj, row, value)
            % Sets the value of an existing parameter. Expects index or
            % name of parameter and the new value
            %
            % params.setValue(2, 3.4);           
            row = obj.getValidRow(row);
            obj.validateLimits(obj.varTable{row, 2}, value, obj.varTable{row, 4});
            obj.varTable{row, 3} = value;
        end
        
        function obj = setName(obj, row, name)
            % Sets the name of an existing parameter.
            % Expects index or name of parameter and the new name
            %
            % params.setName(2, 'new name');          
            row = obj.getValidRow(row);

            if ~isText(name)
                throw(exceptions.invalidType('New name must be char'));
            end

            obj.varTable{row, 1} = {name};
        end
        
        function obj = setLimits(obj, row, minValue, maxValue)
            % Sets the limits of an existing parameter. Expects index
            % or name of parameter and new min and max of the parameter's
            % value
            %
            % params.setLimits({2, 0, 100});
            row = obj.getValidRow(row);
            obj.validateLimits(minValue, obj.varTable{row, 3}, maxValue);
       
            obj.varTable{row, 2} = minValue;
            obj.varTable{row, 4} = maxValue;
        end
                
        function obj = setFit(obj, row, fitFlag)
            % Sets the 'fit' to off or on for parameter.
            % Expects index or name of parameter and new fit flag
            %
            % params.setFit(2, true);
            row = obj.getValidRow(row);

            if ~islogical(fitFlag)
                throw(exceptions.invalidType('Parameter "fit" must be a logical value i.e. true or false'));
            end
           
            obj.varTable{row, 5} = fitFlag;
        end
        
        function displayTable(obj, showPriors)
            % Displays the parameter table. Optional showPriors to display
            % the priors default is false
            %
            % params.displayTable(true);
            arguments
                obj
                showPriors {logical} = false
            end

            numParams = height(obj.varTable);
            dim = [1, width(obj.varTable)];
                        
            if ~showPriors
                dim(2) = 5;
            end
            
            if numParams == 0    
                varNames = obj.varTable.Properties.VariableNames(1:dim(2));
                array = table('Size', dim, 'VariableTypes', repmat({'string'}, dim), 'VariableNames', varNames);
                array(1, :) = repmat({''}, 1, dim(2));
            else
                array = obj.varTable;
                p = 1:height(array);
                p = p(:);
                p = table(p);
                array = [p array(:, 1:dim(2))];
            end         
            disp(array);
        end
        
        function outStruct = toStruct(obj)
            % Converts the class parameters into a structure array.
            names = table2cell(obj.varTable(:,1));
            
            % Want these to be class 'char' rather than 'string'
            for n = 1:length(names)
                names{n} = char(names{n});
            end
            outStruct.names = names;
            
            mins = obj.varTable{:,2};
            maxs = obj.varTable{:,4};
            limits = cell([1, length(mins)]);
            for i = 1:length(mins)
                limits{i} = [mins(i) maxs(i)];
            end
            
            outStruct.limits = limits;
            
            outStruct.values = obj.varTable{:,3};
            
            outStruct.fit = double(obj.varTable{:,5});
            
            priors = table2cell(obj.varTable(:,6:8));
            priors = [outStruct.names priors];
            
            % Group each row into one cell. Should be a way of doing this
            % without a loop but I can't quite see it right now...
            pp = cell([1, size(priors, 1)]);
            for i = 1:size(priors, 1)
                thisPrior = priors(i,:);
                val2 = char(thisPrior{2});
                thisPrior{2} = val2;
                pp(i) = {thisPrior};
            end
            
            outStruct.priors = pp(:);
            
            
            % Need to force some of the outputs
            % to be row vectors, so transpose them
            outStruct.names = outStruct.names';
            outStruct.values = outStruct.values';
            outStruct.fit = outStruct.fit';
            
            % Fields order needs to be...
            
            % names
            % limits
            % values
            % fit
            % priors    
        end
        
    end
    
    methods (Access = protected)
        
        function index = getValidRow(obj, row)
            % Gets valid row with given name or index  
            %
            % obj.getValidRow('param name')
            if isText(row)
                index = obj.findRowIndex(row, obj.varTable{:,1}, 'Unrecognised row name');
            else
                index = row;
                if (index < 1) || (index > obj.rowCount)
                    throw(exceptions.indexOutOfRange(sprintf('Row index out out of range 1 - %d', obj.rowCount)));
                end     
            end
        end
    end

    methods (Static)
        function priors = validatePriors(priorType, muValue, sigmaValue)
            % Validate the prior types, mu and sigma variables
            invalidPriorsMessage = sprintf('Prior type must be a priorTypes enum or one of the following strings (%s)', ...
                                           strjoin(priorTypes.values(), ', '));
            priorType = validateOption(priorType, 'priorTypes', invalidPriorsMessage).value;
                               
            if ~isnumeric(muValue) || ~isnumeric(sigmaValue)
                throw(exceptions.invalidType('Prior values mu and sigma must be a number.'));
            end

            if strcmp(priorType, priorTypes.Uniform.value)
                if muValue ~= 0 
                    warning('mu cannot be %d when the prior types is uniform - resetting to 0', muValue);
                end
                if sigmaValue ~= Inf
                    warning('sigma cannot be %d when the prior types is uniform - resetting to Inf', sigmaValue);
                end
                muValue = 0;
                sigmaValue = Inf;
            end
            priors = {priorType, muValue, sigmaValue};
        end

        function validateLimits(minLimit, value, maxLimit)
            % Validate the value, lower and upper limit variables
            if ~(isnumeric(minLimit) && isnumeric(value) && isnumeric(maxLimit))
                throw(exceptions.invalidType('min, value, and max must be numbers'));
            end
                
            if minLimit > maxLimit
                throw(exceptions.invalidValue(sprintf('min limit %d must be less than or equal to max limit %d', minLimit, maxLimit)));
            end

            if value < minLimit || value > maxLimit
                throw(exceptions.invalidValue(sprintf('Parameter value %d must be within the limits %d to %d', value, minLimit, maxLimit)));
            end
        end

    end

end
