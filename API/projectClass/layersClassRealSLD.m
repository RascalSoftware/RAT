classdef layersClassRealSLD < handle
    
    % This is the class definition for the
    % layers block with no absorption.
    properties
        layersTable = table
    end
    
    properties (Access = private)
        layersCount
        layersAutoNameCounter
        allowedHydration = {'bulk in','bulk out','none'}; 
    end
    
    methods
        
        function obj = layersClassRealSLD()
            
            % Class constructor
            
            sz = [0 6];
            varTypes = {'string','string','string','string','string','string'};
            varNames = {'Name','Thickness','SLD','Roughness','Hydration','Hydrate with'};
            obj.layersTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
            %obj.layersTable(1,:) = {'Layer 1','', '', '', '','bulk out'};
            obj.layersCount = 0;
            obj.layersAutoNameCounter = 1;
            
        end
        
        function obj = addLayer(obj, whatToAdd, paramNames)

            switch length(whatToAdd)

                case 0
                    % Add an empty layer
                    layerNum = obj.layersAutoNameCounter;
                    layerName = sprintf('Layer %d',layerNum);
                    newRow = {layerName,'','','','','bulk out'};
                    appendNewRow(obj,newRow);
                    
                case 1
                    % Add an empty named layer
                    newRow = {whatToAdd{1},'','','','','bulk out'};
                    appendNewRow(obj,newRow);
                
                otherwise
                    % Add a layer that is fully defined
                    layerDetails = whatToAdd;

                    if length(layerDetails) == 4
                        % No hydration
                        layerDetails = {layerDetails{1},layerDetails{2},layerDetails{3},layerDetails{4},NaN,'bulk in'};
                    elseif length(layerDetails) ~= 6
                        error('Can''t define a layer from partial details')
                    end
                    
                    name = layerDetails{1};
                    hydrateWhat = layerDetails{end};
                    
                    if ~strcmpi(hydrateWhat,obj.allowedHydration)
                        error('Hydrate type must be ''bulk in'', ''bulk out'' or ''none''');
                    end
                    
                    % Check that the parameter names given are real
                    % parameters or numbers
                    numPars = length(paramNames);
                    thisRow = {name};
                    
                    for i = 2:5
                        thisParam = layerDetails{i};
                        if ischar(thisParam)
                            % Must be a parameter name
                            if ~strcmp(thisParam,paramNames)
                                error('Unrecognised parameter %s in layers definition',thisParam)
                            end
                            thisRow{i} = thisParam;
                            
                        elseif isnumeric(thisParam)
                            % Must be a parameter number (unless p=5 which
                            % can be Nan)
                            if isnan(thisParam) && i == 5
                                thisRow{i} = NaN;
                            elseif (thisParam < 1) || (thisParam > numPars)
                                error('Parameter ''%d'' is out of range of params list')
                            else
                                thisRow{i} = paramNames{thisParam};
                            end
                        end 
                        
                    end
                    
                    thisRow = [thisRow hydrateWhat];
                    appendNewRow(obj,thisRow);
                    
            end
            
        end
        
        function obj = setLayerValue(obj,varargin)
            
            % Sets a value in a  layer
            inputValues = varargin{1};

            rowPar = inputValues{1};
            layerNames = obj.layersTable{:,1};
            
            % Find the row index if we have a layer name
            if ischar(rowPar)
                row = obj.findRowIndex(rowPar,layerNames);
            elseif isnumeric(rowPar)
                % This rounds any float values down to an integer
                rowIndex = floor(rowPar);
                if (rowIndex < 1) || (rowIndex > length(layerNames))
                    error('Layer index out out of range');
                else
                    row = rowIndex;
                end
            else
                error('Layer not recognised');
            end
            
            colPar = inputValues{2};
            colNames = obj.layersTable.Properties.VariableNames;

            % Find the column index if we have a column name
            if ischar(colPar)
                col = obj.findRowIndex(colPar,colNames);
            elseif isnumeric(colPar)
                % This rounds any float values down to an integer
                colIndex = floor(colPar);
                if (colIndex < 1) || (colIndex > length(colNames))
                    error('Column number out out of range');
                else
                    col = colIndex;
                end
            else
                error('Unrecognised column index');
            end

            if ~isnumeric(col) || col < 2  || col > 6
                error('Parameter 2 should be a number between 2 and 6')
            end
            
            val = inputValues{3};
            if col == 6
                if ~(strcmpi(val,obj.allowedHydration))
                    error('Column 6 of layer must be ''bulk in'', ''bulk out'' or ''none''');
                end
            end
                
            obj.layersTable(row,col) = {string(val)};
            
        end
        
        function layersNames = getLayersNames(obj)
            
            layersNames = obj.layersTable{:,1};
            
        end
        
        function outStruct = toStruct(obj)
            
            %outStruct = table2cell(obj.layersTable);
            outStruct = obj.layersTable{:,:};
            
        end
        

        function displayLayersTable(obj)
            
            % Displays the layers table with numbered rows
            array = obj.layersTable;
            len = size(array,1);
            if len == 0
                % Make an empty table for display
                sz = [1 6];
                varTypes = {'double','double','double','double','double','double'};
                varNames = {'Name','Thickness','SLD','Roughness','Hydration','Hydrate with'};
                dummyTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
                %dummyTable(:,1) = {[],[],[],[],[],[]};
                disp(dummyTable);
                fprintf('\n');
            end
            p = 1:len;
            p = p(:);
            p = table(p);
            all = [p array];
            disp(all);
            
        end
        
    end
    
    methods (Access = protected)
        
        function appendNewRow(obj,row)
            tab = obj.layersTable;
            newName = row{1};
            if any(strcmp(newName,tab{:,1}))
                error('Duplicate layer names are not allowed');
            end
            tab = [tab ; row];
            obj.layersTable = tab;
            obj.layersCount = obj.layersCount + 1;
            obj.layersAutoNameCounter = obj.layersAutoNameCounter + 1;
        end
        
    end
    
    methods(Static)

        function row = findRowIndex(name,rowNames)
            % Find the index of a row in the layers class table given its
            % name. The expected inputs are the name of the row and the
            % full list of row names.

            % Strip leading or trailing whitespaces from names
            rowNames = strip(rowNames);
            name = strip(name);

            % Compare 'name' to list ignoring case
            index = strcmpi(name, rowNames);
            if any(index)
                % Non-zero value in array is the row index
                row = find(index);
            else
                error('Layer name not found');
            end
        end

        function param = findParameter(inputVal, paramNames)
            % Find whether or not a proposed layer parameter is included
            % in a list of parameters, or obtain a parameter by index.
            % The expected inputs are the potential layer parameter value
            % (either name or index) and a list of parameter names.

            if ischar(inputVal)
                if ~any(strcmpi(inputVal, paramNames))
                    error('Parameter %s not recognized', inputVal);
                end
                param = inputVal;
            elseif isnumeric(inputVal)
                paramIndex = floor(inputVal);
                if paramIndex < 1 || paramIndex > length(paramNames)
                    error('Parameter is out of range');
                end
                param = paramNames{paramIndex};
            end
        end

    end
end




