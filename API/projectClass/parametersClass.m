classdef parametersClass < tableUtilities
    % This is the class definition for
    % the parameters block.
    
    properties
        showPriors = false
    end

    properties(Access = private, Constant, Hidden)
        invalidPriorsMessage = sprintf('Prior type must be a priorTypes enum or one of the following strings (%s)', ...
                                       strjoin(priorTypes.values(), ', '))
    end
    
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
            if isempty(varargin)
                % No input parameter
                % Add an empty parameter row
                name = sprintf('new parameter %d',obj.autoNameCounter);
                newRow = {name,0,0,0,false,priorTypes.Uniform.value,0,Inf};
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
                values = [1, 2, 3];
                fit = false;
                priorType = priorTypes.Uniform.value;
                priorValues = [0, Inf];
                
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
                
                % Type validation
                if ~isnumeric(values)
                    throw(exceptions.invalidType('Expecting numeric values as params 2 - 4'));
                end
                
                if ~islogical(fit)
                    throw(exceptions.invalidType('Expecting logical value for param 5'));
                end
                
                priorType = validateOption(priorType, 'priorTypes', obj.invalidPriorsMessage).value;
                               
                if ~isnumeric(priorValues)
                    throw(exceptions.invalidType('Prior values must be numeric'));
                end
                    
                newRow = {name, values(1), values(2), values(3), fit, priorType, priorValues(1), priorValues(2)};
                obj.addRow(newRow{:});
            end
        end
        
        function obj = removeParameter(obj, row)
            % Removes a parameter from the parameters table. 
            % Expects a single parameter name or index/array of parameter
            % names or indices to remove
            %
            % params.removeParameter(2);

            % Arrange parameters into a cell array
            if isa(row, 'double')
                row = num2cell(sort(row, 'descend'));
            elseif isText(row)
                row = cellstr(row);
            elseif iscell(row)
            else
                throw(exceptions.invalidType('Unrecognised Row'))
            end

            % Find index for each parameter and remove from table
            rowNames = obj.varTable{:,1};
            for i = 1:length(row)
                currentRow = row{i};

                if isText(currentRow)
                    currentRow = obj.findRowIndex(currentRow, rowNames, 'Unrecognised parameter name');
                end

                obj.removeRow(currentRow);
            end

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
            inputBlock = parseParameterInput(obj, varargin{:});
            
            if ~isempty(inputBlock.name)
                obj.setName(row, inputBlock.name);
            end
            
            if ~isempty(inputBlock.min)
                max = obj.varTable{row, 4};
                obj.setLimits(row, inputBlock.min, max);
            end
            
            if ~isempty(inputBlock.max)
                min = obj.varTable{row, 2};
                obj.setLimits(row, min, inputBlock.max);
            end
            
            if ~isempty(inputBlock.value)
                obj.setValue(row, inputBlock.value);
            end
            
            if ~isempty(inputBlock.fit)
                obj.setFit(row, inputBlock.fit);
            end

        end
        
        function obj = setPrior(obj, row, varargin)
            % Sets the prior of an existing parameter. Expects index or
            % name of parameter and the new prior type ('uniform',
            % 'gaussian', 'jeffreys') with mu and sigma value if applicable
            %
            % params.setPrior(2, priorTypes.Gaussian, 1, 2);
            inputValues = varargin;
            tab = obj.varTable;
            
            row = obj.getValidRow(row);
            priorType = validateOption(inputValues{1}, 'priorTypes', obj.invalidPriorsMessage).value;
            switch priorType
                case priorTypes.Uniform.value
                    tab(row,6) = {priorTypes.Uniform.value};
                    tab(row,7) = {0};
                    tab(row,8) = {Inf};
                    
                case priorTypes.Gaussian.value
                    tab(row,6) = {priorTypes.Gaussian.value};             
                    tab(row,7) = inputValues(2);
                    tab(row,8) = inputValues(3);
            end
    
            obj.varTable = tab;
            
        end
        
        function obj = setValue(obj, row, value)
            % Sets the value of an existing parameter. Expects index or
            % name of parameter and the new value
            %
            % params.setValue(2, 3.4);
            tab = obj.varTable;           
            row = obj.getValidRow(row);

            if ~isnumeric(value)
                throw(exceptions.invalidType('Value must be numeric'));
            end

            tab(row,3) = {value};
            obj.varTable = tab;
        end
        
        function obj = setName(obj, row, name)
            % Sets the name of an existing parameter.
            % Expects index or name of parameter and the new name
            %
            % params.setName(2, 'new name');
            tab = obj.varTable;           
            row = obj.getValidRow(row);

            if ~isText(name)
                throw(exceptions.invalidType('New name must be char'));
            end

            tab(row, 1) = {name};
            obj.varTable = tab;
        end
        
        function obj = setLimits(obj, row, min, max)
            % Sets the limits of an existing parameter. Expects index
            % or name of parameter and new min and max of the parameter's
            % value
            %
            % params.setLimits({2, 0, 100});
            tab = obj.varTable;
            row = obj.getValidRow(row);

            if ~(isnumeric(min) && isnumeric(max))
                throw(exceptions.invalidType('min and max need to be numeric'));
            end
            
            tab(row, 2) = {min};
            tab(row, 4) = {max};
            obj.varTable = tab;
        end
                
        function obj = setFit(obj, row, fitFlag)
            % Sets the 'fit' to off or on for parameter.
            % Expects index or name of parameter and new fit flag
            %
            % params.setFit(2, true);           
            tab = obj.varTable;
            row = obj.getValidRow(row);

            if ~islogical(fitFlag)
                throw(exceptions.invalidType('Need true or false for Fit? value'));
            end
           
            tab(row, 5) = {fitFlag};
            obj.varTable = tab;
        end
        
        function set.showPriors(obj, flag)
            % Setter for the showPriors property
            if ~islogical(flag)
                throw(exceptions.invalidType('Show priors must be true or false'));
            end
            obj.showPriors = flag;
        end
        
        function displayTable(obj)
            % Displays the parameter table
            array = obj.varTable;
            numParams = height(obj.varTable);
            if ~obj.showPriors
                array = array(:,1:5);
            end

            if numParams == 0
                array(1, :) = repmat({''}, 1, width(obj.varTable));
            else
                p = 1:numParams;
                p = p(:);
                p = table(p);
                array = [p array];
            end

            disp(array);
        end
        
        
        function outStruct = toStruct(obj)
            % Converts the class parameters into a structure array.
            paramNames = table2cell(obj.varTable(:,1));
            
            % Want these to be class 'char' rather than 'string'
            for n = 1:length(paramNames)
                paramNames{n} = char(paramNames{n});
            end
            outStruct.paramNames = paramNames;
            
            outStruct.nParams = size(obj.varTable,1);
            
            mins = obj.varTable{:,2};
            maxs = obj.varTable{:,4};
            limits = cell([1, length(mins)]);
            for i = 1:length(mins)
                limits{i} = [mins(i) maxs(i)];
            end
            
            outStruct.limits = limits;
            
            outStruct.params = obj.varTable{:,3};
            
            outStruct.fit = double(obj.varTable{:,5});
            
            priors = table2cell(obj.varTable(:,6:8));
            priors = [outStruct.paramNames priors];
            
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
            outStruct.paramNames = outStruct.paramNames';
            outStruct.params = outStruct.params';
            outStruct.fit = outStruct.fit';
            
            % Fields order needs to be...
            
            % paramNames
            % nParams
            % limits
            % params
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

        function inputBlock = parseParameterInput(~, varargin)
            % Parses parameter keyword/value pairs into a structure.
            %
            % obj.parseParameterInput('name', 'param')
            defaultName = '';
            defaultMin = [];
            defaultMax = [];   
            defaultValue = [];
            defaultFit = [];
        
            p = inputParser;
            addParameter(p,'name',  defaultName,   @isText);
            addParameter(p,'min',   defaultMin,    @isnumeric);
            addParameter(p,'value', defaultValue,  @isnumeric);
            addParameter(p,'max',   defaultMax,    @isnumeric);
            addParameter(p,'fit',   defaultFit,    @islogical);
                       
            parse(p, varargin{:});
            inputBlock = p.Results;
        end

    end

end
