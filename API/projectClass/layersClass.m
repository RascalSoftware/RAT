classdef layersClass < tableUtilities
    % ``layersClass`` manages the layers for the project. It provides methods to add, update and remove layers. 
    % Each layer is stored as a row in a table and consists of a name, the thickness, the SLD, 
    % the roughness, the percent hydration, and whether the layer is hydrated with "bulk" in or "bulk out". If the 
    % absorption is set to true, the SLD column is broken into a 'SLD Imaginary', and 'SLD Real'.
    % 
    % Parameters
    % ----------
    % SLDValues : cell str, default: 'SLD'
    %     The name of the SLD column(s). 
    %
    % Attributes
    % ----------
    % varTable : table
    %     The table which contains the properties for each parameter. 

    properties(Access = private, Constant, Hidden)
        invalidTypeMessage = sprintf('Hydration type must be a HydrationTypes enum or one of the following strings (%s)', ...
                                     strjoin(hydrationTypes.values(), ', '))
    end
    
    properties (Dependent, SetAccess = private)
        varCount
    end
    
    methods
        
        function obj = layersClass(SLDValues)
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
            % Adds a new layer to the layers table. This method can be called in 2 ways. The first for when ``absorption`` is false  
            %
            % ``addLayer(paramNames, name, thickness, realSLD, roughness, hydration, hydrateWith)``
            % 
            % and the second includes an extra argument imaginarySLD for when ``absorption`` is true.
            % 
            % ``addLayer(paramNames, name, thickness, realSLD, imaginarySLD, roughness, hydration, hydrateWith)``
            %
            % Examples
            % --------
            % To add a new layer with name only.
            % 
            % >>> parameterNames = project.getAllAllowedNames().paramNames;
            % >>> layers.addLayer(parameterNames, 'New layer');
            % 
            % To add a new layer when ``absorption`` is false.
            % 
            % >>> layers.addLayer(parameterNames, 'Water Layer', 'Water thickness', 'Water SLD', 'Bilayer heads roughness', 'Water hydration', 'Bulk out');
            % 
            % To add a new layer when ``absorption`` is false.
            % 
            % >>> layers.addLayer(parameterNames, 'Layer 1', 'Layer thickness', 'Layer Real SLD', 'Layer Imaginary SLD', 'Layers roughness, 'Layer hydration', 'Bulk in');
            %  
            % Parameters
            % ----------
            % paramNames: cell
            %     A cell array which contains the valid names of parameters.
            % name : string or char array, default: auto-generated name
            %     The name of this layer.
            % thickness : string or char array or whole number, default: ''
            %     The name (or the row index) of the parameter describing the thickness of this layer.
            % realSLD : string or char array or whole number, default: ''
            %     The name (or the row index) of the parameter describing the real (scattering) term
            %     for the scattering length density of this layer.
            % imaginarySLD : string or char array or whole number, default: ''
            %     The name (or the row index) of the parameter describing the imaginary (``absorption``) term
            %     for the scattering length density of this layer.
            % roughness : string or char array or whole number, default: ''
            %     The name (or the row index) of the parameter describing the roughness of this layer.
            % hydration : string or char array or whole number, default: ''
            %     The name (or the row index) of the parameter describing the percent hydration for the layer
            % hydrateWith : hydrationTypes, default: hydrationTypes.BulkOut
            %     Whether the layer is hydrated with the "bulk in" or "bulk out".

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
                newRow{i} = validateParameter(layerDetails{i}, paramNames);
            end

            %  . . . (apart from the penultimate column which can also be empty or NaN)
            if ~(strcmpi(layerDetails{obj.varCount - 1}, '') || any(isnan(layerDetails{obj.varCount - 1})))
                newRow{obj.varCount - 1} = validateParameter(layerDetails{obj.varCount - 1}, paramNames);
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
            % Change the value of a given layer parameter in the table (excluding the layer name).
            %
            % Examples
            % --------
            % To update the thickness of the second layer in the table (layer in row 2).
            % 
            % >>> parameterNames = project.getAllAllowedNames().paramNames;
            % >>> layers.setLayerValue(2, 2, 'New thickness', paramNames);
            % 
            % The same can be achieved using names, to change the 'Thickness' of 'Layer 1'.
            % 
            % >>> layers.setLayerValue('Layer 1', 'Thickness', 'New thickness', paramNames);
            % 
            % Note that the number of columns change depending on whether ``absorption`` is true or false so the column indices will change also. 
            % For example, the code below will update 'Roughness' if ``absorption`` is false, otherwise it will update the Imaginary SLD. So it is 
            % recommended to use column names to ensure the correct change.
            % 
            % >>> layers.setLayerValue(2, 4, 'New Roughness', paramNames); 
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row of the layer to update. If it is text, 
            %     it is the name of the layer to update.
            % col : string or char array or whole number
            %     If ``col`` is an integer, it is the column of layer to update. If it is text, 
            %     it is the name of the column to update. The column names are the following: 'Name', 'Thickness', 
            %     'SLD', 'Roughness', 'Hydration', 'Hydrate with'. If ``absorption`` is true, the 'SLD' column is replaced 
            %     with 'SLD Imaginary', and 'SLD Real'.
            % inputValue : string or char array or whole number
            %     The name (or row index) of a parameter to replace the one in specified row and column 
            % paramNames: cell
            %     A cell array which contains the valid names of parameters.

            colNames = obj.varTable.Properties.VariableNames;
            row = obj.getValidRow(row);
            
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
                val = validateParameter(inputValue, paramNames);
            end
                
            obj.varTable(row,col) = {val};
            
        end
        
        function layerStruct = toStruct(obj, paramNames)
            % Converts the layersClass content into a structure array.
            % 
            % Examples
            % --------
            % >>> parameterNames = project.parameters.getNames();
            % >>> layerStruct = layers.toStruct(parameterNames);
            %  
            % Parameters
            % ----------
            % paramNames : cell
            %    A cell array which contains the names of available parameters.
            % 
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
