classdef layersClassRealSLD < handle
    
    % This is the class definition for the layers block.

    properties
        layersTable = table
        numValues
        varNames
    end
    
    properties (Access = private)
        layersAutoNameCounter
    end

    properties(Access = private, Constant, Hidden)
        invalidTypeMessage = sprintf('Hydration type must be a HydrationTypes enum or one of the following strings (%s)', ...
                                     strjoin(hydrationTypes.values(), ', '))
    end
    
    properties (Dependent, SetAccess = private)
        layersCount
    end
    
    methods
        
        function obj = layersClassRealSLD(SLDValues)
            % Construct a layers class including an empty layers table
            % The optional input is a cell array of the required SLD
            % parameters.
            %
            % layers = layersClassRealSLD();
            arguments
                SLDValues {mustBeText} = 'SLD'
            end

            obj.varNames = [{'Name', 'Thickness'}, SLDValues, {'Roughness','Hydration','Hydrate with'}];
            obj.numValues = length(obj.varNames);

            sz = [0 obj.numValues];
            varTypes = repmat({'string'}, 1, obj.numValues);
            obj.layersTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',obj.varNames);
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
            % layer, which consists of either all except two parameters
            % (no hydration) or all parameters.
            % Parameters can be specified either by name or by index.
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
                newRow = [{layerName}, repmat({''}, 1, obj.numValues - 2), {hydrationTypes.BulkOut.value}];
                
            elseif length(layerDetails) == 1 && isText(layerDetails{1})
                % Add an empty named layer
                newRow = [layerDetails(1), repmat({''}, 1, obj.numValues - 2), {hydrationTypes.BulkOut.value}];
            
            else
                % Add a layer that is fully defined
                if length(layerDetails) == (obj.numValues - 2)
                    % No hydration
                    layerDetails = [layerDetails, {NaN, hydrationTypes.BulkIn.value}];
                elseif length(layerDetails) ~= obj.numValues
                    throw(invalidNumberOfInputs(sprintf('Incorrect number of parameters for layer definition. Either 0, 1, %d, or %d inputs are required.', obj.numValues - 2, obj.numValues)));
                end
                
                name = layerDetails{1};
                hydration = validateOption(layerDetails{end}, 'hydrationTypes', obj.invalidTypeMessage).value;
                
                % Check that the parameter names given are real
                % parameters or numbers
                newRow = {name};
                
                % Must be a parameter name or number . . .
                for i = 2:(obj.numValues - 2)
                    newRow{i} = obj.findParameter(layerDetails{i}, paramNames);
                end

                %  . . . (unless p=5 which can also be Nan)
                if isnan(layerDetails{obj.numValues - 1})
                    newRow{obj.numValues - 1} = NaN;
                else
                    newRow{obj.numValues - 1} = obj.findParameter(layerDetails{obj.numValues - 1}, paramNames);
                end
                
                newRow = [newRow hydration];

            end

            appendNewRow(obj, newRow);

        end
        
        function obj = setLayerValue(obj, row, col, inputValue, paramNames)
            % Change the value of a given layer parameter in the table
            % (excluding the layer name). The row and column of the
            % parameter can both be specified by either name or index.
            % The expected input is a row parameter (name or index), a
            % column parameter (name or index), the new value to be set at
            % that row and column, and a string array of parameter names
            % defined in the project's parameter class.
            %
            % layers.setLayerValue(1, 1, 'origin', parameters.paramsTable{:, 1});
            layerNames = obj.layersTable{:,1};
            colNames = obj.layersTable.Properties.VariableNames;
            
            % Find the row index if we have a layer name
            if isText(row)
                row = obj.findRowIndex(row, layerNames);
            elseif isnumeric(row)
                if (row < 1) || (row > obj.layersCount)
                    throw(indexOutOfRange(sprintf('The row index %d is not within the range 1 - %d', row, obj.layersCount)));
                end
            else
                throw(invalidType('Layer type not recognised'));
            end
            
            % Find the column index if we have a column name
            if isText(col)
                col = obj.findRowIndex(col, colNames);
            elseif isnumeric(col)
                if (col < 1) || (col > length(colNames))
                    throw(indexOutOfRange(sprintf('The column index %d is not within the range 1 - %d', col, length(colNames))));
                end
            else
                throw(invalidType('Layer table column type not recognised'));
            end

            if ~isnumeric(col) || col < 2  || col > length(colNames)
                throw(indexOutOfRange(sprintf('Column index should be a number between 2 and %d', length(colNames))));
            end

            if col == length(colNames)
                val = validateOption(inputValue, 'hydrationTypes', obj.invalidTypeMessage).value;
            else
                val = obj.findParameter(inputValue, paramNames);
            end
                
            obj.layersTable(row,col) = {val};
            
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
                sz = [1 obj.numValues];
                varTypes = repmat({'double'}, 1, obj.numValues);
                dummyTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',obj.varNames);
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
        
        function appendNewRow(obj, row)
            % Appends a row to the layers table. The expected input is
            % cell array of length equal to the number of table values.
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

        function row = findRowIndex(name, rowNames)
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

            if isText(inputVal)
                if ~any(strcmpi(inputVal, paramNames))
                    throw(nameNotRecognised(sprintf('Parameter %s not recognized', inputVal)));
                end
                param = inputVal;

            elseif isnumeric(inputVal)
                paramIndex = floor(inputVal);
                if paramIndex < 1 || paramIndex > length(paramNames)
                    throw(indexOutOfRange(sprintf('Parameter ''%d'' is out of range 1 - %d', paramIndex, length(paramNames))));
                end
                param = paramNames{paramIndex};

            else
                throw(invalidType(sprintf('Parameter %s is not in a recognizable format', inputVal)));
                
            end
        end

    end
end




