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

            varNames = [{'Name', 'Thickness'}, SLDValues, {'Roughness', 'Hydration', 'Hydrate with'}];

            sz = [0 length(varNames)];
            varTypes = repmat({'string'}, 1, length(varNames));
            obj.varTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
        end

        function count = get.varCount(obj)
            count = length(obj.varTable.Properties.VariableNames);
        end

        function obj = addLayer(obj, paramNames, varargin)
            % Adds a new layer to the table. 
            %
            % Examples
            % --------
            % To add a new constant background with name only.
            % 
            % >>> allowedNames = project.getAllAllowedNames();
            % >>> background.addBackground(allowedNames, 'New Background');
            % 
            % To add a constant background.
            % 
            % >>> background.addBackground(allowedNames, 'New Background', 'constant', 'param name');
            % 
            % To add a function background with 2 parameters.
            % 
            % >>> background.addBackground(allowedNames, 'New Background', 'function', 'function name', 'param name', 'param name 2');    
            %
            % To add a data background with an offset.
            % 
            % >>> background.addBackground(allowedNames, 'New Background', 'data', 'data name', 'offset param name');
            % 
            % Parameters
            % ----------
            % name : str
            %     The name of this layer.
            % thickness : str
            %     The name of the parameter describing the thickness of this layer.
            % SLD_real : str
            %     The name of the parameter describing the real (scattering) term
            %     for the scattering length density of this layer.
            % SLD_imaginary : str
            %     The name of the parameter describing the imaginary (absorption) term
            %     for the scattering length density of this layer.
            % roughness : str
            %     The name of the parameter describing the roughness of this layer.
            % hydration : str
            % hydrate_with : str
            
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
            % layers.addLayer(parameters.varTable{:, 1}, 'Another layer', 1, 2, 3);
            layerDetails = varargin;

            % Layers must be fully defined
            if length(layerDetails) == (obj.varCount - 2)
                % No hydration
                layerDetails = [layerDetails, {'', hydrationTypes.BulkOut.value}];
            elseif length(layerDetails) ~= obj.varCount
                throw(exceptions.invalidNumberOfInputs(sprintf('Incorrect number of parameters for layer definition. Either %d or %d inputs are required.', obj.varCount - 2, obj.varCount)));
            end
            
            name = layerDetails{1};
            hydration = validateOption(layerDetails{end}, 'hydrationTypes', obj.invalidTypeMessage).value;
            
            % Check that the parameter names given are real
            % parameters or numbers
            newRow = [name, repmat({''}, 1, obj.varCount - 2), hydration];
            
            % Must be a parameter name or number
            for i = 2:(obj.varCount - 2)
                newRow{i} = obj.validateParameter(layerDetails{i}, paramNames);
            end

            %  . . . (apart from the penultimate column which can also be empty or NaN)
            if ~(strcmpi(layerDetails{obj.varCount - 1}, '') || any(isnan(layerDetails{obj.varCount - 1})))
                newRow{obj.varCount - 1} = obj.validateParameter(layerDetails{obj.varCount - 1}, paramNames);
            end

            obj.addRow(newRow{:});

        end

        function obj = removeLayer(obj, row)
            % Removes a given layer from the table.
            %
            % Examples
            % --------
            % To remove the second layer in the table (layer in row 2).  
            % 
            % >>> layers.removeLayer(2);
            % 
            % To remove layer with a specific name.
            % 
            % >>> layers.removeLayer('D2O');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the layer to remove. If it is text, 
            %     it is the name of the layer to remove.
            obj.removeRow(row);
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
                    throw(exceptions.indexOutOfRange(sprintf('The row index %d is not within the range 1 - %d', row, obj.rowCount)));
                end
            else
                throw(exceptions.invalidType('Unrecognised layer type'));
            end
            
            % Find the column index if we have a column name
            if isText(col)
                col = obj.findRowIndex(col, colNames, 'Unrecognised column name');
            elseif isnumeric(col)
                if (col < 1) || (col > length(colNames))
                    throw(exceptions.indexOutOfRange(sprintf('The column index %d is not within the range 1 - %d', col, length(colNames))));
                end
            else
                throw(exceptions.invalidType('Unrecognised layer table column type'));
            end

            if ~isnumeric(col) || col < 2  || col > length(colNames)
                throw(exceptions.indexOutOfRange(sprintf('Column index should be a number between 2 and %d', length(colNames))));
            end

            if col == length(colNames)
                val = validateOption(inputValue, 'hydrationTypes', obj.invalidTypeMessage).value;
            else
                val = obj.validateParameter(inputValue, paramNames);
            end
                
            obj.varTable(row,col) = {val};
            
        end
        
        function layerStruct = toStruct(obj, paramNames)
            % Converts the layersClass content into a structure array.
            %TODO
            % Returns
            % -------
            % layerStruct : struct
            %     A struct which contains the properties for all the layers.    
            layersCell = obj.varTable{:,:};

            layerStruct.numberOfLayers = size(layersCell, 1);
            layerStruct.layerNames = layersCell(:,1);
            
            % parse the layers details
            layerValues = layersCell(:,2:end);         
            layerDetails = cell([1, layerStruct.numberOfLayers]);

            for i = 1:layerStruct.numberOfLayers

                thisLayer = layerValues(i,:);
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
                layerDetails{i} = [paramIndices hydr hydrWhat];
                
            end

            if layerStruct.numberOfLayers > 0
                layerStruct.layerDetails = layerDetails(:);
            else
                layerStruct.layerDetails = {};
            end
            
        end
    end     
end
