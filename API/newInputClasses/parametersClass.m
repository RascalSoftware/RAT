classdef parametersClass < handle
    
    % This is the class definition for
    % the parameters block.
    
    properties
        paramsTable = table;
        showPriors = false;
    end
    
    properties (Access = private)
        paramCount;
        paramAutoNameCounter
    end
    
    methods
        function obj = parametersClass(startCell)
            
            % Class constructor.
            sz = [1 8];
            varTypes = {'string','double','double','double','logical','string','double','double'};
            varNames = {'Name','Min','Value','Max','Fit?','Prior Type','mu','sigma'};
            obj.paramsTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
            obj.paramsTable(1,:) = startCell;%{'Substrate Roughness',1 3 5,true,'uniform',0,Inf};
            obj.paramCount = 1;
            obj.paramAutoNameCounter = 1;
        end
        
        function obj = setInitialValue(varargin)
            initialValue = varargin{2};
            obj.paramsTable(1,:) = initialValue;
            obj.paramCount = 1;
            obj.paramAutoNameCounter = 1;
        end
        
        function names = getParamNames(obj)
            
            names = obj.paramsTable{:,1}; 
            
        end
        
        function obj = addParam(obj,varargin)
            
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
                    error('First value must be param name');
                end
                
                inputLength = length(inputCell);
                
                switch inputLength
                    
                    % If length is 1, assume name only
                    % and fill in the rest with defaults
                    case 1
                        name = inputCell{1};
                        newRow = {name,1,2,3,false,'uniform',0,Inf};
                        appendNewRow(obj,newRow);
                        
                        % If length is 2, assume name an value
                        % pair. Fill in the rest automatically
                    case 2
                        name = inputCell{1};
                        value = inputCell{2};
                        if ~isnumeric(value)
                            error('Expecting numberic value as param 2');
                        end
                        newRow = {name,value,value,value,false,'uniform',0,Inf};
                        appendNewRow(obj,newRow);
                        
                        % If length is 4, assume we are getting the
                        % limits as well as the values
                    case 4
                        name = inputCell{1};
                        values = [inputCell{2} inputCell{3} inputCell{4}];
                        if ~isnumeric(values)
                            error('Expecting numberic valus as params 2 - 4');
                        end
                        newRow = {name,values(1),values(2),values(3),false,'uniform',0,Inf};
                        appendNewRow(obj,newRow);
                        
                        % If length is 5, then assume we are setting
                        % everything except priors
                    case 5
                        name = inputCell{1};
                        values = [inputCell{2} inputCell{3} inputCell{4}];
                        fit = inputCell{5};
                        if ~isnumeric(values)
                            error('Expecting numberic valus as params 2 - 4');
                        end
                        
                        if ~islogical(fit)
                            error('Expecting logical value for param 5')
                        end
                        newRow = {name,values(1),values(2),values(3),fit,'uniform',0,Inf};
                        appendNewRow(obj,newRow);
                        
                        % If not one of these options, throw an error
                    otherwise
                        error('Unrecognised inputs to ''addrow''');
                end
            end
        end
        
        function obj = removeParam(obj,varargin)
            if isempty(varargin)
                error('Need to specify a parameter');
            end
            
            for i = 1:length(varargin)
                thisInput =  varargin{i};
                removeRow(obj,thisInput);
            end
        end
        
        function obj = setParameter(obj,varargin)
            % General purpose set method using name value pairs
            
            inputValues = varargin{:};
            tab = obj.paramsTable;
            
            if ischar(inputValues{1})
                name = string(inputValues{1});
                row = findRowIndex(name,tab);
            else
                row = inputValues{1};
            end
           
            inputBlock = parseParameterInput(inputValues(2:end));
            
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
            
        function obj = setValue(obj,varargin)
            inputValues = varargin{:};
            tab = obj.paramsTable;
            if length(inputValues) ~= 2
                error('Need p (or name) / value pair to set');
            end
            
            if ischar(inputValues{1})
                name = string(inputValues{1});
                row = findRowIndex(name,tab);
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
            tab = obj.paramsTable;
            inputValues = varargin{:};
            if length(inputValues) ~= 2
                error('Wrong number of values for setName');
            end
            
            if ischar(inputValues{1})
                name = string(inputValues{1});
                row = findRowIndex(name,tab);
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
                row = findRowIndex(name,tab);
            else
                row = inputValues{1};
            end
            
            tab(row,2) = {min};
            tab(row,4) = {max};
            obj.paramsTable = tab;
        end
        
        
        function obj = setFit(obj, varargin)
            
            tab = obj.paramsTable;
            if length(varargin) ~= 2
                error('Need p (or name) / val pair set');
            end
            
            if ~islogical(varargin{2})
                error('Need true or false for Fit? value');
            end
            
            if ischar(varargin{1})
                name = string(varargin{1});
                row = findRowIndex(name,tab);
            else
                row = varargin{1};
            end
            
            tab(row,5) = varargin(2);
            obj.paramsTable = tab;
        end
        
        function set.paramsTable(obj,table)
            obj.paramsTable = table;
        end
        
        function set.showPriors(obj,flag)
            if ~islogical(flag)
                error('Show priors must be true or false');
            end
            obj.showPriors = flag;
        end
        
        function displayParametersTable(obj)
            array = obj.paramsTable;
            p = [1:size(array,1)];
            p = p(:);
            p = table(p);
            if ~obj.showPriors
                array = array(:,1:5);
            end
            all = [p array];
            disp(all);
        end
        
        
        function outStruct = toStruct(obj)
            
            % Convert the class parameters into
            % a structure array.
            
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
            
            outStruct.priors = table2cell(obj.paramsTable(:,6:8));
            
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
            tab = obj.paramsTable;
            newName = row{1};
            if any(strcmp(newName,tab{:,1}))
                error('Duplicate parameter names not allowed');
            end
            tab = [tab ; row];
            obj.paramsTable = tab;
            obj.paramCount = obj.paramCount + 1;
            obj.paramAutoNameCounter = obj.paramAutoNameCounter + 1;
        end
        
        function removeRow(obj, row)
            tab = obj.paramsTable;
            disp('debug');
            
            if ischar(row)
                % Assume a row name
                index = strcmp(row, tab{:,1});
                if isempty(index)
                    error('Unrecognised parameter name');
                end
                row = find(index);
            end
            
            numRows = size(tab,1);
            if row == numRows
                % Removing the last row
                newTab = tab(1:end-1,:);
                
            elseif row == 1
                newTab = tab(2:end,:);
                
            else
                % Removing a row somewhere in the centre
                tab1 = tab(1:row-1,:);
                tab2 = tab(row+1:end,:);
                newTab = [tab1 ; tab2];
            end
            
            obj.paramsTable = newTab;
            obj.paramCount = obj.paramCount - 1;
            
        end
        

    end

end


function row = findRowIndex(name,tab)
    % Get loist of rownames from table..
    namesList = tab{:,1};
    
    % Strip leading or trailing whitaspaces from names and name
    namesList = strip(namesList);
    name = strip(name);
    
    % Compare 'name' to list ignoring case
    index = strcmpi(name, namesList);
    if isempty(index)
        error('Unrecognised parameter name');
    end
    
    % Non-zero value in array is the row index
    row = find(index);
end


function inputBlock = parseParameterInput(varargin)

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


