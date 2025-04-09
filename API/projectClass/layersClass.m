classdef layersClass < tableUtilities
    % ``layersClass`` manages the layers for the project. It provides methods to add, update and remove layers. 
    % Each layer is stored as a row in a table and consists of a name, the thickness, the SLD, 
    % the roughness, the percent hydration, and whether the layer is hydrated with "bulk" in or "bulk out". If the 
    % absorption is set to true, the SLD column is split into 'SLD Imaginary', and 'SLD Real'.
    % 
    % Parameters
    % ----------
    % SLDValues : cell string, default: 'SLD'
    %     The name(s) of the SLD column(s). 
    %
    % Attributes
    % ----------
    % varTable : table
    %     The table which contains the properties for each layer. 

    properties(Access = private, Constant)
        invalidTypeMessage = sprintf('Hydration type must be a HydrationTypes enum or one of the following strings (%s)', ...
                                     strjoin(hydrationTypes.values(), ', '))
    end

    properties (Dependent, SetAccess = private)
        varCount
    end

    properties (Dependent)
        absorption
    end
    
    methods
        
        function obj = layersClass()
            varNames = {'Name', 'Thickness', 'SLD', 'Roughness', 'Hydration', 'Hydrate with'};

            sz = [0 length(varNames)];
            varTypes = repmat({'string'}, 1, length(varNames));
            obj.varTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
        end

        function count = get.varCount(obj)
            count = length(obj.varTable.Properties.VariableNames);
        end

        function set.absorption(obj, value)
            % Add or remove a column from the layers table whenever the
            % "absorption" property is modified.
            if value == obj.absorption
                return
            end
            if value
                newCol = repmat("", height(obj.varTable), 1);
                obj.varTable = addvars(obj.varTable, newCol, 'After', 'SLD', 'NewVariableNames', 'SLD Imaginary');
                obj.varTable = renamevars(obj.varTable, 'SLD', 'SLD Real');
            else
                obj.varTable = removevars(obj.varTable, 'SLD Imaginary');
                obj.varTable = renamevars(obj.varTable, 'SLD Real', 'SLD');
            end
        end

        function value = get.absorption(obj)
            value = width(obj.varTable) == 7;
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
            % To add a new layer when ``absorption`` is true.
            % 
            % >>> layers.addLayer(parameterNames, 'Layer 1', 'Layer thickness', 'Layer Real SLD', 'Layer Imaginary SLD', 'Layers roughness, 'Layer hydration', 'Bulk in');
            %  
            % Parameters
            % ----------
            % paramNames: cell
            %     A cell array which contains the names of available parameters.
            % name : string or char array, default: auto-generated name
            %     The name of this layer.
            % thickness : string or char array or whole number, default: ''
            %     The name (or the row index) of the parameter describing the thickness of this layer.
            % realSLD : string or char array or whole number, default: ''
            %     The name (or the row index) of the parameter describing the real (scattering) term
            %     for the scattering length density of this layer.
            % imaginarySLD : string or char array or whole number, default: ''
            %     The name (or the row index) of the parameter describing the imaginary (absorption) term
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
        
        function obj = setLayer(obj, row, paramNames, options)
            % Update properties of an existing layer. 
            % Any unset property will remain unchanged.
            %
            % Examples
            % --------
            % To update the thickness of the second layer in the table (layer in row 2).
            % 
            % >>> parameterNames = project.getAllAllowedNames().paramNames;
            % >>> layers.setLayer(2, paramNames, thickness='New thickness');
            % 
            % To change the properties of a layer called 'Layer 1'.
            % 
            % >>> layers.setLayer('Layer 1', paramNames, name='new layer', thickness='New thickness', sld='Layer SLD');
            % 
            % To change the imaginary SLD when absorption is true.
            % 
            % >>> layers.setLayer('Layer 1', paramNames, name='new layer', thickness='New thickness', realSLD='Layer SLD', imaginarySLD='Layer Imaginary SLD');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row of the layer to update. If it is text, 
            %     it is the name of the layer to update.
            % paramNames: cell
            %     A cell array which contains the names of available parameters.
            % options
            %    Keyword/value pair to properties to update for the specific parameter.
            %       * name (string or char array or whole number, default: '') the new name of the layer.
            %       * thickness (string or char array or whole number, default: '') The name (or the row index) of the parameter describing the thickness of this layer.
            %       * sld, realSLD (string or char array or whole number, default: '') The name (or the row index) of the parameter describing the real (scattering) term.
            %       * imaginarySLD (string or char array or whole number, default: '') the new name (or the row index) of the parameter describing the imaginary (absorption) term.
            %       * roughness (string or char array or whole number, default: '') the new name (or the row index) of the parameter describing the roughness of this layer.           
            %       * hydration (string or char array or whole number, default: '') the new name (or the row index) of the parameter describing the percent hydration for the layer           
            %       * hydrateWith (hydrationTypes, default: hydrationTypes.empty()) whether the layer is hydrated with the "bulk in" or "bulk out". 
            arguments
                obj
                row
                paramNames
                options.name {mustBeTextScalar, mustBeNonempty}
                options.thickness {mustBeNonempty}
                options.sld {mustBeNonempty}
                options.realSLD {mustBeNonempty}
                options.imaginarySLD {mustBeNonempty}
                options.roughness {mustBeNonempty}
                options.hydration
                options.hydrateWith {mustBeNonempty}
            end           
            
            row = obj.getValidRow(row);
            if isfield(options, 'sld') 
                if isfield(options, 'realSLD')
                    throw(exceptions.invalidOption('The "sld" and "realSLD" options cannot be set at the same time.'));
                end

                options.realSLD = options.sld;
            end
            
            if ~isfield(options, 'name')
                options.name = obj.varTable{row, 1}{:};
            end
            
            if ~isfield(options, 'thickness')
                options.thickness = obj.varTable{row, 2}{:};
            end
            
            if ~isfield(options, 'roughness')
                options.roughness = obj.varTable{row, end-2}{:};
            end

            if ~isfield(options, 'hydration')
                options.hydration = obj.varTable{row, end-1}{:};
            end
            
            if ~isfield(options, 'hydrateWith')
                options.hydrateWith = obj.varTable{row, end}{:};
            end
            
            if ~isfield(options, 'realSLD')
                options.realSLD = obj.varTable{row, 3}{:};
            end
            
            if obj.absorption
                if ~isfield(options, 'imaginarySLD')
                    options.imaginarySLD = obj.varTable{row, 4}{:};
                end
                values = {options.thickness, options.realSLD, options.imaginarySLD, options.roughness, options.hydration};
            else
                if isfield(options, 'imaginarySLD')
                    throw(exceptions.invalidOption('The imaginarySLD option cannot be set when absorption is false.'));
                end
                values = {options.thickness, options.realSLD, options.roughness, options.hydration};
            end

            for i=1:length(values)
                if ~isempty(values{i})
                    values{i} = validateParameter(values{i}, paramNames);        
                end
            end
            values{end + 1} = validateOption(options.hydrateWith, 'hydrationTypes', obj.invalidTypeMessage).value;
            
            obj.setRowName(row, options.name); 
            obj.varTable(row, 2:end) = values;
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
                    paramIndices(j) = findParameterIndex(thisLayer{j}, paramNames, 'layer');
                end

                if isempty(thisLayer{numCols-1})
                    hydr = NaN;
                else
                    hydr =  findParameterIndex(thisLayer{numCols-1}, paramNames, 'layer');
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
