classdef parametersClass < handle
    % This is the class definition for
    % the parameters block.
    
    properties
        paramsTable = table;
        showPriors = false;
    end
    
    properties (Access = private)   
        paramAutoNameCounter;
    end
    
    properties (Dependent)
        paramCount;
    end
    
    methods
        function obj = parametersClass(startCell)
            % Class constructor.
            % Creates a Parameter object. The startCell argument should be 
            % a cell array with the content of the first parameter. A 
            % parameter consists of a name (string), min (double), value (double), 
            % max (double), fit flag (logical), prior type (string), mu (double), 
            % and sigma (double) values in that order.
            %
            % params = parametersClass({'Tails', 10, 20, 30, true, 'uniform', 0, Inf});
            sz = [0, 8];
            varTypes = {'string','double','double','double','logical','string','double','double'};
            varNames = {'Name','Min','Value','Max','Fit?','Prior Type','mu','sigma'};
            obj.paramsTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
            obj.paramAutoNameCounter = 0;
            obj.addParam(startCell);
           
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
        
        function obj = addParam(obj,varargin)
            % Adds an new parameter to the parameters table. Defaults 
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
                newRow = {name,0,0,0,false,'uniform',0,Inf};
                appendNewRow(obj,newRow);
            end
            
            if iscell(varargin) && ~isempty(varargin)
                inputCell = varargin{:};
                
                % First input must be a parameter name
                if ~ischar(inputCell{1})
                    error('First value must be param name (char)');
                end
                
                values = [1, 2, 3];
                fit = false;
                priorType = 'uniform';
                priorValues = [0, Inf];
                
                switch length(inputCell)     
                    % If length is 1, assume name only
                    % and fill in the rest with defaults
                    case 1
                        name = inputCell{1};
                        
                    % If length is 2, assume name an value
                    % pair. Fill in the rest automatically
                    case 2
                        name = inputCell{1};
                        values = [inputCell{2} inputCell{2} inputCell{2}];
                        
                    % If length is 4, assume we are getting the
                    % limits as well as the values
                    case 4
                        name = inputCell{1};
                        values = [inputCell{2} inputCell{3} inputCell{4}];
                        
                    % If length is 5, then assume we are setting
                    % everything except priors
                    case 5
                        name = inputCell{1};
                        values = [inputCell{2} inputCell{3} inputCell{4}];
                        fit = inputCell{5};
                        
                    % Case 8 must be everything including the prior
                    case 8
                        name = inputCell{1};
                        values = [inputCell{2} inputCell{3} inputCell{4}];
                        fit = inputCell{5};
                        priorType = inputCell{6};
                        priorValues = [inputCell{7} inputCell{8}];
                       
                    % If not one of these options, throw an error
                    otherwise
                        error('Unrecognised inputs to ''addParam''');    
                end
                
                % Type validation
                if ~isnumeric(values)
                    error('Expecting numeric values as params 2 - 4');
                end
                
                if ~islogical(fit)
                    error('Expecting logical value for param 5')
                end
                
                if ~strcmpi(priorType,{'uniform', 'gaussian', 'jeffreys'})
                    error('Prior type must be ''uniform'', ''gaussian'' or ''jeffreys''');
                end
                
                if ~isnumeric(priorValues)
                    error('Prior values must be numeric');
                end
                    
                newRow = {name, values(1), values(2), values(3), fit, priorType, priorValues(1), priorValues(2)};
                appendNewRow(obj, newRow);
            end
        end
        
        function obj = removeParam(obj,varargin)
            % Removes a parameter from the parameters table. 
            % Expects index or name of parameter to remove
            %
            % params.removeParam(2); 
            if isempty(varargin)
                error('Need to specify a parameter');
            end
            
            for i = 1:length(varargin)
                thisInput =  varargin{i};
                removeRow(obj,thisInput);
            end
        end
        
        function obj = setParameter(obj,varargin)
            % General purpose set parameter method. Expects a cell array with
            % index or name of parameter and keyword/value pairs to set
            %
            % params.setParameter({2, 'value', 50});
            inputValues = varargin{:};
            tab = obj.paramsTable;
            
            if ischar(inputValues{1})
                name = string(inputValues{1});
                row = obj.findRowIndex(name,tab);
            else
                row = inputValues{1};
            end
           
            inputBlock = obj.parseParameterInput(inputValues(2:end));
            
            if ~isempty(inputBlock.name)
                obj.setName({row,inputBlock.name});
            end
            
            if ~isempty(inputBlock.min)
                max = obj.paramsTable{row,4};
                obj.setConstr({row,inputBlock.min,max});
            end
            
            if ~isempty(inputBlock.max)
                min = obj.paramsTable{row,2};
                obj.setConstr({row,min,inputBlock.max});
            end
            
            if ~isempty(inputBlock.value)
                obj.setValue({row,inputBlock.value});
            end
            
            if ~isempty(inputBlock.fit)
                obj.setFit(row,inputBlock.fit);
            end

        end
        
        function obj = setPrior(obj,varargin)
            % Sets the prior of an existing parameter. Expects a cell array with
            % index or name of parameter and the new prior type ('uniform',
            % 'gaussian', 'jeffreys') with mu and sigma value if applicable
            %
            % params.setPrior(2, 'gaussian', 1, 2);
            inputValues = varargin{:};
            tab = obj.paramsTable;
            
            if ischar(inputValues{1})
                name = string(inputValues{1});
                row = obj.findRowIndex(name,tab);
            else
                row = inputValues{1};
            end
            
            priorType = inputValues{2};
            if ~strcmpi(priorType,{'uniform','gaussian','jeffreys'})
                error('Prior needs to be ''uniform'',''gaussian'', or ''jeffreys''');
            end
            
            priorType = lower(priorType);
            switch priorType
                case 'uniform'
                    tab(row,6) = {'uniform'};
                    tab(row,7) = {0};
                    tab(row,8) = {Inf};
                    
                case 'gaussian'
                    tab(row,6) = {'gaussian'};             
                    tab(row,7) = inputValues(3);
                    tab(row,8) = inputValues(4);
            end
    
            obj.paramsTable = tab;
            
        end
        
        function obj = setValue(obj,varargin)
            % Sets the value of an existing parameter. Expects a cell array with
            % index or name of parameter and the new value
            %
            % params.setValue({2, 3.4});
            inputValues = varargin{:};
            tab = obj.paramsTable;
            if length(inputValues) ~= 2
                error('Need p (or name) / value pair to set');
            end
            
            if ischar(inputValues{1})
                name = string(inputValues{1});
                row = obj.findRowIndex(name,tab);
            else
                row = inputValues{1};
            end
            
            if ~isnumeric(inputValues{2})
                error('Value must be numeric');
            end
            value = inputValues{2};
            tab(row,3) = {value};
            obj.paramsTable = tab;
        end
        
        function obj = setName(obj,varargin)
            % Sets the name of an existing parameter. Expects a cell array with
            % index or name of parameter and the new name
            %
            % params.setName({2, 'new name'});
            tab = obj.paramsTable;
            inputValues = varargin{:};
            if length(inputValues) ~= 2
                error('Wrong number of values for setName');
            end
            
            if ischar(inputValues{1})
                name = string(inputValues{1});
                row = obj.findRowIndex(name,tab);
            else
                row = inputValues{1};
            end
            
            if ~ischar(inputValues{2})
                error('New name must be char');
            end
            name = inputValues{2};
            tab(row,1) = {name};
            obj.paramsTable = tab;
        end
        
        function obj = setConstr(obj, varargin)
            % Sets the constraints of an existing parameter. Expects a cell array with 
            % index or name of parameter and new min and max of the parameter's value
            %
            % params.setConstr({2, 0, 100});
            tab = obj.paramsTable;
            inputValues = varargin{:};
            if length(inputValues) ~= 3
                error('Need p (or name) / min / max set');
            end
            
            min = inputValues{2};
            max = inputValues{3};
            if ~(isnumeric(min) && isnumeric(max))
                error('min and max need to be numeric');
            end
            
            if ischar(inputValues{1})
                name = string(inputValues{1});
                row = obj.findRowIndex(name,tab);
            else
                row = inputValues{1};
            end
            
            tab(row,2) = {min};
            tab(row,4) = {max};
            obj.paramsTable = tab;
        end
                
        function obj = setFit(obj, varargin)
            % Sets the 'fit' to off or on for parameter. Expects a cell array with 
            % index or name of parameter and new fit flag
            %
            % params.setFit({2, true});
            if iscell(varargin) && length(varargin) == 1
                varargin = varargin{:};
            end
            
            tab = obj.paramsTable;
            if length(varargin) ~= 2
                error('Need p (or name) / val pair set');
            end
            
            if ~islogical(varargin{2})
                error('Need true or false for Fit? value');
            end
            
            if ischar(varargin{1})
                name = string(varargin{1});
                row = obj.findRowIndex(name,tab);
            else
                row = varargin{1};
            end
            
            tab(row,5) = varargin(2);
            obj.paramsTable = tab;
        end
        
        function set.showPriors(obj,flag)
            % Setter for the showPriors property
            if ~islogical(flag)
                error('Show priors must be true or false');
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
            for i = 1:size(priors,1)
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
        
        function appendNewRow(obj,row)
            % Appends a new row to the table. Expects a cell array  
            % with row values to append
            % 
            % obj.appendNewRow({'Tails', 10, 20, 30, true, 'uniform', 0, Inf})
            tab = obj.paramsTable;
            newName = row{1};
            if any(strcmp(newName,tab{:,1}))
                error('Duplicate parameter names not allowed');
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
                    error('Unrecognised parameter name');
                end
                row = find(index);
            end
            
            if (row < 1) || (row > obj.paramCount)
                error('Row index out out of range');
            end
            
            tab(row, :) = [];
            obj.paramsTable = tab;   
        end
    end

    methods (Static)
        function row = findRowIndex(name,tab)
            % Gets index with given row name from table.
            %
            % obj.parseParameterInput({'name', 'param'})
            namesList = tab{:,1};
            
            % Strip leading or trailing white spaces from names and name
            namesList = strip(namesList);
            name = strip(name);
            
            % Compare 'name' to list ignoring case
            index = strcmpi(name, namesList);
            if ~any(index)
                error('Unrecognised parameter name');
            end
            
            % Non-zero value in array is the row index
            row = find(index);
        end
        
        
        function inputBlock = parseParameterInput(varargin)
            % Parses parameter keyword/value pairs in a cell array 
            % into a structure.
            %
            % obj.parseParameterInput({'name', 'param'})
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
            
            inputVals = varargin{:};
            
            parse(p,inputVals{:});
            inputBlock = p.Results;
        end
        
    end

end
