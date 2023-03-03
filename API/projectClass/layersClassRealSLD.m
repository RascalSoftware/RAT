classdef layersClassRealSLD < handle
    
    % This is the class definition for the layers block with no absorption.

    properties
        layersTable = table
    end
    
    properties (Access = private)
        layersAutoNameCounter
        allowedHydration = {'bulk in', 'bulk out', 'none'} 
    end

    properties (Dependent, SetAccess = private)
        layersCount
    end
    
    methods
        
        function obj = layersClassRealSLD()
            % Construct a layers class including an empty layers table
            %
            % layers = layersClassRealSLD();          
            sz = [0 6];
            varTypes = {'string','string','string','string','string','string'};
            varNames = {'Name','Thickness','SLD','Roughness','Hydration','Hydrate with'};
            obj.layersTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
            %obj.layersTable(1,:) = {'Layer 1','', '', '', '','bulk out'};
            obj.layersAutoNameCounter = 1;
            
        end

        function count = get.layersCount(obj)
            count = height(obj.layersTable);
        end

        function obj = addLayer(obj, paramNames, varargin)
            % Add a layer to the layers table
            % The expected input is a string array of parameter names
            % defined in the project's parameter class and a variable
            % number of layer parameters. The layer can be specified with
            % no parameters, just a layer name (char), or a fully defined
            % layer, which consists of either four (no hydration) or six
            % parameters. Parameters can be specified either by name or
            % by index.
            %
            % layers.addLayer(parameters.paramsTable{:, 1});
            % layers.addLayer(parameters.paramsTable{:, 1}, 'New layer');
            % layers.addLayer(parameters.paramsTable{:, 1},...
            %                 'Another layer', 1, 2, 3);
            layerDetails = varargin;

            if isempty(layerDetails)
                % Add an empty layer
                layerNum = obj.layersAutoNameCounter;
                layerName = sprintf('Layer %d',layerNum);
                newRow = {layerName,'','','','','bulk out'};
                appendNewRow(obj,newRow);
                
            elseif length(layerDetails) == 1 && ischar(layerDetails{1})
                % Add an empty named layer
                newRow = {varargin{1},'','','','','bulk out'};
                appendNewRow(obj,newRow);
            
            else
                % Add a layer that is fully defined
                if length(layerDetails) == 4
                    % No hydration
                    layerDetails = {layerDetails{1},layerDetails{2},layerDetails{3},layerDetails{4},NaN,'bulk in'};
                elseif length(layerDetails) ~= 6
                    throw(invalidNumberOfInputs('Incorrect number of parameters for layer definition. Either 0, 1, 4, or 6 inputs are required.'));
                end
                
                name = layerDetails{1};
                hydrateWhat = layerDetails{end};
                
                if ~strcmpi(hydrateWhat,obj.allowedHydration)
                    throw(invalidOption(sprintf('Hydrate type is ''%s'', but it must be ''bulk in'', ''bulk out'' or ''none''', hydrateWhat)));
                end
                
                % Check that the parameter names given are real
                % parameters or numbers
                thisRow = {name};
                
                % Must be a parameter name or number . . .
                for i = 2:4                       
                    thisRow{i} = obj.findParameter(layerDetails{i}, paramNames);
                end

                %  . . . (unless p=5 which can also be Nan)
                if isnan(layerDetails{5})
                    thisRow{5} = NaN;
                else
                    thisRow{5} = obj.findParameter(layerDetails{5}, paramNames);
                end
                
                thisRow = [thisRow hydrateWhat];
                appendNewRow(obj,thisRow);
                    
            end
            
        end
        
        function obj = setLayerValue(obj, rowPar, colPar, inputValue, paramNames)
            % Change the value of a given layer parameter in the table
            % (excluding the layer name). The row and column of the
            % parameter can both be specified by either name or index.
            % The expected input is a row parameter (name or index), a
            % column parameter (name or index), the new value to be set at
            % that row and column, and a string array of parameter names
            % defined in the project's parameter class.
            %
            % layers.setLayerValue(1, 1, "origin", parameters.paramsTable{:, 1});
            layerNames = obj.layersTable{:,1};
            colNames = obj.layersTable.Properties.VariableNames;
            
            % Find the row index if we have a layer name
            if ischar(rowPar)
                row = obj.findRowIndex(rowPar,layerNames);
            elseif isnumeric(rowPar)
                if (rowPar < 1) || (rowPar > obj.layersCount)
                    throw(indexOutOfRange(sprintf('The row index %d is not within the range 1 - %d', rowPar, obj.layersCount)));
                else
                    row = rowPar;
                end
            else
                throw(invalidType('Layer type not recognised'));
            end
            
            % Find the column index if we have a column name
            if ischar(colPar)
                col = obj.findRowIndex(colPar,colNames);
            elseif isnumeric(colPar)
                if (colPar < 1) || (colPar > length(colNames))
                    throw(indexOutOfRange(sprintf('The column index %d is not within the range 1 - %d', colPar, length(colNames))));
                else
                    col = colPar;
                end
            else
                throw(invalidType('Layer table column type not recognised'));
            end

            if ~isnumeric(col) || col < 2  || col > 6
                throw(indexOutOfRange('Column index should be a number between 2 and 6'));
            end

            if col == 6
                if ~(strcmpi(inputValue,obj.allowedHydration))
                    throw(invalidOption(sprintf('Column 6 of layer is ''%s'', but must be ''bulk in'', ''bulk out'' or ''none''', inputValue)));
                end
                val = inputValue;
            else
                val = obj.findParameter(inputValue, paramNames);
            end
                
            obj.layersTable(row,col) = {string(val)};
            
        end

        function removeLayer(obj, layer)
            % Removes a layer from the layers table. The expected input is
            % an integer or array of integers, i.e., an input such as
            % [1 3] leads to multiple rows being removed from the table
            %
            % layers.removeLayer(2)
            tab = obj.layersTable;
            tab(layer,:) = [];
            obj.layersTable = tab;
        end
 
        function layersNames = getLayersNames(obj)
            % Get a string array of the names of each of the layers defined
            % in the class.
            %
            % layers.getLayersNames()
            layersNames = obj.layersTable{:,1};  
        end
        
        function outStruct = toStruct(obj)
            % Convert the layers class to a struct.
            %
            % layers.toStruct()            
            %outStruct = table2cell(obj.layersTable);
            outStruct = obj.layersTable{:,:};
        end
        

        function displayLayersTable(obj)
            % Displays the layers table with numbered rows
            %
            % layers.displayLayersTable()
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
            % Appends a row to the layers table. The expected input is
            % a length six cell array.
            %
            % layers.appendNewRow({'New Row','','','','','bulk out'});
            tab = obj.layersTable;
            newName = row{1};
            if any(strcmp(newName,tab{:,1}))
                throw(duplicateName('Duplicate layer names are not allowed'));
            end
            tab = [tab ; row];
            obj.layersTable = tab;
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
                throw(nameNotRecognised('Layer name not found'));
            end
        end

        function param = findParameter(inputVal, paramNames)
            % Find whether or not a proposed layer parameter is included
            % in a list of parameters, or obtain a parameter by index.
            % The expected inputs are the potential layer parameter value
            % (either name or index) and a list of parameter names.

            if ischar(inputVal)
                if ~any(strcmpi(inputVal, paramNames))
                    throw(nameNotRecognised(sprintf('Parameter %s not recognized', inputVal)));
                end
                param = inputVal;

            elseif isnumeric(inputVal)
                paramIndex = floor(inputVal);
                if paramIndex < 1 || paramIndex > length(paramNames)
                    throw(indexOutOfRange(sprintf('Parameter "%d" is out of range 1 - %d', paramIndex, length(paramNames))));
                end
                param = paramNames{paramIndex};

            else
                throw(invalidType(sprintf('Parameter %s is not in a recognizable format', inputVal)));
                
            end
        end

    end
end




