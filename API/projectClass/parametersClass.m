classdef parametersClass < handle
    % This is the class definition for
    % the parameters block.
    
    properties
        paramsTable = table
        showPriors = false
    end

    properties(Access = private, Constant, Hidden)
        invalidPriorsMessage = sprintf('Prior type must be a priorTypes enum or one of the following strings (%s)', ...
                                       strjoin(priorTypes.values(), ', '))
    end

    properties (Access = private)   
        paramAutoNameCounter=1
    end
    
    properties (Dependent)
        paramCount
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
            obj.paramsTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
            if isempty(varargin)
                obj.addParam();
            else
                obj.addParam(varargin{:});
            end
        end
        
        function count = get.paramCount(obj)
            count = height(obj.paramsTable);
        end
        
        function names = getParamNames(obj)
            % Returns a N x 1 cell array of names of the parameter 
            % in the object. 
            % 
            % names = params.getParamNames();
            names = obj.paramsTable{:,1}; 
        end
        
        function obj = addParam(obj, varargin)
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
            % params.addParam('Tails Roughness');  
            if isempty(varargin)
                % No input parameter
                % Add an empty parameter row
                name = sprintf('new parameter %d',obj.paramAutoNameCounter);
                newRow = {name,0,0,0,false,priorTypes.Uniform.value,0,Inf};
                appendNewRow(obj,newRow);
            end
            
            if iscell(varargin) && ~isempty(varargin)
                inputCell = varargin;
                
                % First input must be a parameter name
                if ~ischar(inputCell{1})
                    throw(invalidType('First value must be param name (char)'));
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
                        throw(invalidNumberOfInputs('Unrecognised inputs to ''addParam'''));
                end
                
                % Type validation
                if ~isnumeric(values)
                    throw(invalidType('Expecting numeric values as params 2 - 4'));
                end
                
                if ~islogical(fit)
                    throw(invalidType('Expecting logical value for param 5'));
                end
                
                priorType = validateOption(priorType, 'priorTypes', obj.invalidPriorsMessage).value;
                               
                if ~isnumeric(priorValues)
                    throw(invalidType('Prior values must be numeric'));
                end
                    
                newRow = {name, values(1), values(2), values(3), fit, priorType, priorValues(1), priorValues(2)};
                appendNewRow(obj, newRow);
            end
        end
        
        function obj = removeParam(obj, row)
            % Removes a parameter from the parameters table. 
            % Expects a single parameter name or index/array of parameter
            % names or indices to remove
            %
            % params.removeParam(2);
            if isa(row, 'double')
                row = num2cell(sort(row, 'descend'));
            elseif ischar(row) || isstring(row)
                row = cellstr(row);
            elseif iscell(row)
            else
                throw(invalidType('Unrecognised Row'))
            end

            for i = 1:length(row)
                obj.removeRow(row{i});
            end
        end
        
        function obj = setParameter(obj, row, varargin)
            % General purpose set parameter method. Expects index or name
            % of parameter and keyword/value pairs to set
            %
            % params.setParameter(2, 'value', 50);

            % Always need three or more inputs to set parameter value
            if length(varargin) < 2 || mod(length(varargin), 2) ~= 0
                throw(invalidNumberOfInputs('The input to ''setParameter'' should be a index/parameter name and a set of name-value pairs'));
            end

            row = obj.getValidRow(row);
            inputBlock = obj.parseParameterInput(varargin{:});
            
            if ~isempty(inputBlock.name)
                obj.setName(row, inputBlock.name);
            end
            
            if ~isempty(inputBlock.min)
                max = obj.paramsTable{row, 4};
                obj.setConstr(row, inputBlock.min, max);
            end
            
            if ~isempty(inputBlock.max)
                min = obj.paramsTable{row, 2};
                obj.setConstr(row, min, inputBlock.max);
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
            tab = obj.paramsTable;
            
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
    
            obj.paramsTable = tab;
            
        end
        
        function obj = setValue(obj, row, value)
            % Sets the value of an existing parameter. Expects index or
            % name of parameter and the new value
            %
            % params.setValue(2, 3.4);
            tab = obj.paramsTable;           
            row = obj.getValidRow(row);

            if ~isnumeric(value)
                throw(invalidType('Value must be numeric'));
            end

            tab(row,3) = {value};
            obj.paramsTable = tab;
        end
        
        function obj = setName(obj, row, name)
            % Sets the name of an existing parameter.
            % Expects index or name of parameter and the new name
            %
            % params.setName(2, 'new name');
            tab = obj.paramsTable;           
            row = obj.getValidRow(row);

            if ~ischar(name)
                throw(invalidType('New name must be char'));
            end

            tab(row, 1) = {name};
            obj.paramsTable = tab;
        end
        
        function obj = setConstr(obj, row, min, max)
            % Sets the constraints of an existing parameter. Expects index
            % or name of parameter and new min and max of the parameter's
            % value
            %
            % params.setConstr({2, 0, 100});
            tab = obj.paramsTable;
            row = obj.getValidRow(row);

            if ~(isnumeric(min) && isnumeric(max))
                throw(invalidType('min and max need to be numeric'));
            end
            
            tab(row, 2) = {min};
            tab(row, 4) = {max};
            obj.paramsTable = tab;
        end
                
        function obj = setFit(obj, row, fitFlag)
            % Sets the 'fit' to off or on for parameter.
            % Expects index or name of parameter and new fit flag
            %
            % params.setFit(2, true);           
            tab = obj.paramsTable;
            row = obj.getValidRow(row);

            if ~islogical(fitFlag)
                throw(invalidType('Need true or false for Fit? value'));
            end
           
            tab(row, 5) = {fitFlag};
            obj.paramsTable = tab;
        end
        
        function set.showPriors(obj, flag)
            % Setter for the showPriors property
            if ~islogical(flag)
                throw(invalidType('Show priors must be true or false'));
            end
            obj.showPriors = flag;
        end
        
        function displayParametersTable(obj)
            % Displays the parameter table
            array = obj.paramsTable;
            p = 1:size(array,1);
            p = p(:);
            p = table(p);
            if ~obj.showPriors
                array = array(:,1:5);
            end
            all = [p array];
            disp(all);
        end
        
        
        function outStruct = toStruct(obj)
            % Converts the class parameters into a structure array.
            paramNames = table2cell(obj.paramsTable(:,1));
            
            % Want these to be class 'char' rather than 'string'
            for n = 1:length(paramNames)
                paramNames{n} = char(paramNames{n});
            end
            outStruct.paramNames = paramNames;
            
            outStruct.nParams = size(obj.paramsTable,1);
            
            mins = obj.paramsTable{:,2};
            maxs = obj.paramsTable{:,4};
            constr = cell([1, length(mins)]);
            for i = 1:length(mins)
                constr{i} = [mins(i) maxs(i)];
            end
            
            %constr = [mins maxs];
            outStruct.paramConstr = constr;
            
            outStruct.params = obj.paramsTable{:,3};
            
            outStruct.fitYesNo = double(obj.paramsTable{:,5});
            
            priors = table2cell(obj.paramsTable(:,6:8));
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
            %outStruct.paramConstr = outStruct.paramConstr;
            outStruct.params = outStruct.params';
            outStruct.fitYesNo = outStruct.fitYesNo';
            
            % Fields order needs to be...
            
            % paramNames
            % nParams
            % paramConstr
            % params
            % fitYesNo
            % priors    
        end
        
    end
    
    
    methods (Access = protected)
        
        function appendNewRow(obj, row)
            % Appends a new row to the table. Expects a cell array  
            % with row values to append
            % 
            % obj.appendNewRow({'Tails', 10, 20, 30, true, 'uniform' 0, Inf})
            tab = obj.paramsTable;
            newName = row{1};
            if any(strcmp(newName,tab{:,1}))
                throw(duplicateName('Duplicate parameter names not allowed'));
            end
            tab = [tab ; row];
            obj.paramsTable = tab;
            obj.paramAutoNameCounter = obj.paramAutoNameCounter + 1;
        end
        
        function removeRow(obj, row)
            % Removes a specified row of the table. Expects
            % index or name of row to remove
            %
            % obj.removeRow(1)
            tab = obj.paramsTable;
            
            if ischar(row)
                % Assume a row name
                index = strcmp(row, tab{:,1});
                if ~any(index)
                    throw(nameNotRecognised('Unrecognised parameter name'));
                end
                row = find(index);
            end
            
            if (row < 1) || (row > obj.paramCount)
                throw(indexOutOfRange(sprintf('Row index out out of range 1 - %d', obj.paramCount)));
            end
            
            tab(row, :) = [];
            obj.paramsTable = tab;   
        end
        
        function index = getValidRow(obj, row)
            % Gets valid row with given name or index  
            %
            % obj.getValidRow('param name')
            if ischar(row)
                name = string(row);
                index = obj.findRowIndex(name, obj.paramsTable);
            else
                index = row;
                if (index < 1) || (index > obj.paramCount)
                    throw(indexOutOfRange(sprintf('Row index out out of range 1 - %d', obj.paramCount)));
                end     
            end
        end
    end

    methods (Static)
        function row = findRowIndex(name, tab)
            % Gets index with given row name from table.
            %
            % obj.findRowIndex('param')
            namesList = tab{:,1};
            
            % Strip leading or trailing white spaces from names and name
            namesList = strip(namesList);
            name = strip(name);
            
            % Compare 'name' to list ignoring case
            index = strcmpi(name, namesList);
            if ~any(index)
                throw(nameNotRecognised('Unrecognised parameter name'));
            end
            
            % Non-zero value in array is the row index
            row = find(index);
        end
        
        
        function inputBlock = parseParameterInput(varargin)
            % Parses parameter keyword/value pairs into a structure.
            %
            % obj.parseParameterInput('name', 'param')
            defaultName = '';
            defaultMin = [];
            defaultMax = [];   
            defaultValue = [];
            defaultFit = [];
        
            p = inputParser;
            addParameter(p,'name',  defaultName,   @ischar);
            addParameter(p,'min',   defaultMin,    @isnumeric);
            addParameter(p,'value', defaultValue,  @isnumeric);
            addParameter(p,'max',   defaultMax,    @isnumeric);
            addParameter(p,'fit',   defaultFit,    @islogical);
                       
            parse(p, varargin{:});
            inputBlock = p.Results;
        end
        
    end

end
