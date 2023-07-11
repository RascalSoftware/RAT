classdef layersClass < tableUtilities
    
    % This is the class definition for the layers block.

    properties(Access = private, Constant, Hidden)
        invalidTypeMessage = sprintf('Hydration type must be a HydrationTypes enum or one of the following strings (%s)', ...
                                     strjoin(hydrationTypes.values(), ', '))
    end
    
    properties (Dependent, SetAccess = private)
        varCount
    end
    
    methods
        
        function obj = layersClass(SLDValues)
            % Construct a layers class including an empty layers table
            % The optional input is a cell array of the required SLD
            % parameters.
            %
            % layers = layersClass();
            arguments
                SLDValues {mustBeText} = 'SLD'
            end

            varNames = [{'Name', 'Thickness'}, SLDValues, {'Roughness','Hydration','Hydrate with'}];

            sz = [0 length(varNames)];
            varTypes = repmat({'string'}, 1, length(varNames));
            obj.varTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
        end

        function count = get.varCount(obj)
            count = length(obj.varTable.Properties.VariableNames);
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
            % layers.addLayer(parameters.varTable{:, 1});
            % layers.addLayer(parameters.varTable{:, 1}, 'New layer');
            % layers.addLayer(parameters.varTable{:, 1},...
            %                 'Another layer', 1, 2, 3);
            layerDetails = varargin;

            if isempty(layerDetails)
                % Add an empty layer
                layerNum = obj.autoNameCounter;
                layerName = sprintf('Layer %d',layerNum);
                newRow = [{layerName}, repmat({''}, 1, obj.varCount - 2), {hydrationTypes.BulkOut.value}];
                
            elseif length(layerDetails) == 1 && isText(layerDetails{1})
                % Add an empty named layer
                newRow = [layerDetails(1), repmat({''}, 1, obj.varCount - 2), {hydrationTypes.BulkOut.value}];
            
            else
                % Add a layer that is fully defined
                if length(layerDetails) == (obj.varCount - 2)
                    % No hydration
                    layerDetails = [layerDetails, {'', hydrationTypes.BulkOut.value}];
                elseif length(layerDetails) ~= obj.varCount
                    throw(invalidNumberOfInputs(sprintf('Incorrect number of parameters for layer definition. Either 0, 1, %d, or %d inputs are required.', obj.varCount - 2, obj.varCount)));
                end
                
                name = layerDetails{1};
                hydration = validateOption(layerDetails{end}, 'hydrationTypes', obj.invalidTypeMessage).value;
                
                % Check that the parameter names given are real
                % parameters or numbers
                newRow = [name, repmat({''}, 1, obj.varCount - 2), hydration];
                
                % Must be a parameter name or number . . .
                for i = 2:(obj.varCount - 2)
                    newRow{i} = obj.findParameter(layerDetails{i}, paramNames);
                end

                %  . . . (apart from the penultimate column which can also be empty or NaN)
                if ~(strcmpi(layerDetails{obj.varCount - 1}, '') || any(isnan(layerDetails{obj.varCount - 1})))
                    newRow{obj.varCount - 1} = obj.findParameter(layerDetails{obj.varCount - 1}, paramNames);
                end

            end

            obj.addRow(newRow{:});

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
            % layers.setLayerValue(1, 1, 'origin', parameters.varTable{:, 1});
            layerNames = obj.varTable{:,1};
            colNames = obj.varTable.Properties.VariableNames;
            
            % Find the row index if we have a layer name
            if isText(row)
                row = obj.findRowIndex(row, layerNames, 'Unrecognised layer name');
            elseif isnumeric(row)
                if (row < 1) || (row > obj.rowCount)
                    throw(indexOutOfRange(sprintf('The row index %d is not within the range 1 - %d', row, obj.rowCount)));
                end
            else
                throw(invalidType('Unrecognised layer type'));
            end
            
            % Find the column index if we have a column name
            if isText(col)
                col = obj.findRowIndex(col, colNames, 'Unrecognised column name');
            elseif isnumeric(col)
                if (col < 1) || (col > length(colNames))
                    throw(indexOutOfRange(sprintf('The column index %d is not within the range 1 - %d', col, length(colNames))));
                end
            else
                throw(invalidType('Unrecognised layer table column type'));
            end

            if ~isnumeric(col) || col < 2  || col > length(colNames)
                throw(indexOutOfRange(sprintf('Column index should be a number between 2 and %d', length(colNames))));
            end

            if col == length(colNames)
                val = validateOption(inputValue, 'hydrationTypes', obj.invalidTypeMessage).value;
            else
                val = obj.findParameter(inputValue, paramNames);
            end
                
            obj.varTable(row,col) = {val};
            
        end
        
        function outStruct = toStruct(obj, paramNames)
            % Convert the layers class to a struct.
            %
            % layers.toStruct()            
            layersCell = obj.varTable{:,:};

            outStruct.numberOfLayers = size(layersCell, 1);
            outStruct.layersNames = layersCell(:,1);
            
            % parse the layers details
            layersValues = layersCell(:,2:end);         
            layersDetails = cell([1, outStruct.numberOfLayers]);

            for i = 1:outStruct.numberOfLayers

                thisLayer = layersValues(i,:);
                numCols = length(thisLayer);
                paramIndices = zeros(1,numCols-2);
                for j = 1:numCols-2
                    paramIndices(j) = find(strcmpi(thisLayer{j},paramNames));
                end

                if strcmpi(thisLayer(numCols-1), "")
                    hydr = NaN;
                else
                    hydr = find(strcmpi(thisLayer{numCols-1},paramNames));
                end

                if strcmpi(thisLayer{numCols}, hydrationTypes.BulkIn.value)
                    hydrWhat = 1;
                else
                    hydrWhat = 2;
                end
                layersDetails{i} = [paramIndices hydr hydrWhat];
                
            end

            if outStruct.numberOfLayers > 0
                outStruct.layersDetails = layersDetails(:);
            else
                outStruct.layersDetails = {};
            end
            
        end

    end
        
    methods(Static)

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




