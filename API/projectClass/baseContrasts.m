classdef (Abstract) baseContrasts < handle

    % This class holds the common routines for the subclasses
    % "contrastsClass.m" and "domainContrastsClass.m"
    
    properties
        contrasts = {}
    end

    properties (Access = protected)
        contrastAutoNameCounter
    end

    properties (SetAccess = immutable)
        domainsCalc
        oilWaterCalc
        rowHeaders = struct('key', ["Name"; "Data"; "Background"; "Bulk in"; "Bulk out"; "Scalefactor"; "Resolution"; "Resample"; "Domain Ratio"; "Model"], ...
                            'field', ["name"; "data"; "background"; "nba"; "nbs"; "scalefactor"; "resolution"; "resample"; "domainRatio"; "model"])
    end

    properties (Dependent, SetAccess = private)
        numberOfContrasts
        displayNames
    end

    properties(Access = protected, Constant, Hidden)
        invalidTypeMessage = sprintf('Model type must be a modelTypes enum or one of the following strings (%s)', ...
                                     strjoin(modelTypes.values(), ', '))
    end

    methods (Abstract)
        parseContrastInput
        getDisplayNames
    end

    methods
        
        function obj = baseContrasts(domainsCalc, oilWaterCalc)
            % Class Constructor
            % The only (optional) input is a logical flag to state whether
            % or not this is a domains calculation.
            %
            % contrasts = contrastsClass()
            arguments
                domainsCalc {mustBeA(domainsCalc,'logical')} = false
                oilWaterCalc {mustBeA(oilWaterCalc,'logical')} = false
            end

            obj.domainsCalc = domainsCalc;
            obj.oilWaterCalc = oilWaterCalc;
            obj.contrastAutoNameCounter = 1;
        end

        function count = get.numberOfContrasts(obj)
            count = length(obj.contrasts);
        end
        
        function names = get.displayNames(obj)
            names = obj.getDisplayNames();
        end

        function obj = addContrast(obj, allowedNames, varargin)
            % Add a contrast to the class
            % A class can be added with no input parameters, just a class
            % name, or a set of key-value pairs.
            %
            % contrasts.addContrast()
            % contrasts.addContrast('New Contrast')
            % contrasts.addContrast('name', 'new contrast', ... 
            %                       'background', 'Background H2O')
            if isempty(varargin)
                % No input at all
                contrastName = sprintf('New contrast %d', obj.contrastAutoNameCounter);
                inputVals = {'name', contrastName};
                
            elseif length(varargin) == 1
                % Just name of contrast
                thisName = varargin{1};
                inputVals = {'name', thisName};
                
            else
                % Everything else
                inputVals = varargin;
            end
            
            thisContrast = obj.parseContrastInput(allowedNames, obj.domainsCalc, obj.oilWaterCalc, inputVals);
            thisContrast.model = '';
            obj.contrasts{end+1} = thisContrast;
            obj.contrastAutoNameCounter = obj.contrastAutoNameCounter + 1;
        
        end

        function obj = removeContrast(obj, row)
            % Removes a contrast from the list.
            % The contrast can be specified either by name or by index, but
            % only one contrast can be removed at a time.
            %
            % contrasts.removeContrast('Named Contrast')
            % contrasts.removeContrast(1)

            % First determine if contrast is being referenced by name or
            % number...

            % If the input is a string, find the index of the relevant
            % contrast...
            if isText(row)
                contrastNames = getAllContrastNames(obj);
                row = find(strcmp(contrastNames,row));
                
                % Throw an error if the name is not matched
                if isempty(row)
                    throw(nameNotRecognised('Contrast name not found'));
                end
            end
           
            % Check to make sure the number is in range
            if row < 1 || row > obj.numberOfContrasts
                throw(indexOutOfRange(sprintf('Specified contrast %d is not in range 1 - %d', row, obj.numberOfContrasts)));
            end

            % Remove the contrast from the contrasts cell array
            obj.contrasts(row) = [];

        end

        function obj = setContrastModel(obj, row, modelType, allowedNames, model)
            % Set the value of the model parameter in a contrast.
            % The expected input is the contrast (specified either by name
            % or index), the model type, the allowed values (either layers
            % for standard layers or custom files for custom models) and
            % either a string or cell array for the model itself.
            % Note that the model can only be set here, and not in
            % "addContrast" or "setContrast".
            %
            % contrasts.setContrastModel(1, 'standard layers', allowedNames, 'Oxide Model')
            
            % Find if we are referencing an existing contrast
            if isnumeric(row)
                if (row < 1 || row > obj.numberOfContrasts)
                    throw(indexOutOfRange(sprintf('Contrast number %d is out of range 1 - %d', row, obj.numberOfContrasts)));
                end
                contrastIndex = row; 
            elseif isText(row)
                [present,idx] = ismember(row, obj.getAllContrastNames());
                if ~present
                    throw(nameNotRecognised(sprintf('Contrast %s is not recognised', row)));
                end
                contrastIndex = idx;
            end

            % Determine which contrast is being set
            thisContrast = obj.contrasts{contrastIndex};
            modelArray = cellstr(model);

            % Check the input is as expected
            modelType = validateOption(modelType, 'modelTypes', obj.invalidTypeMessage).value;
            if any(strcmpi(modelType, {modelTypes.CustomLayers.value, modelTypes.CustomXY.value}))
                if length(modelArray) > 1
                    throw(invalidValue('Only 1 model value allowed for ''custom'''));
                end
            end

            for i = 1:length(modelArray)
                if ~strcmpi(modelArray{i}, allowedNames)
                    throw(nameNotRecognised(sprintf('Layer/Custom Name %s is not recognised', modelArray{i})));
                end
            end

            thisContrast.model = modelArray;
            obj.contrasts{contrastIndex} = thisContrast;

        end

        function obj = setContrast(obj, row, allowedNames, varargin)
            % Set a value within a contrast.
            % The expected input is the contrast (specified either by name
            % or index), the allowed values for all parameters and a
            % set of key-value pairs for the parameter values to be
            % changed.
            %
            % contrasts.setContrast(1, allowedNames, ...
            %                       'name', 'New contrast name', ... 
            %                       'background', 'New Background')

            % Find if we are referencing an existing contrast
            if isnumeric(row)
                if (row < 1 || row > obj.numberOfContrasts)
                    throw(indexOutOfRange(sprintf('Contrast number %d is out of range 1 - %d', row, obj.numberOfContrasts)));
                end
                contrastIndex = row;
                
            elseif isText(row)
                [present,idx] = ismember(row, obj.getAllContrastNames());
                if ~present
                    throw(nameNotRecognised(sprintf('Contrast %s is not recognised',row)));
                end
                contrastIndex = idx;
                
            end

            thisContrast = obj.contrasts{contrastIndex};

            % Check to see if the inputs are valid
            % Raise a warning if we try to set the model as this should be
            % done elsewhere
            inputBlock = obj.parseContrastInput(allowedNames, obj.domainsCalc, obj.oilWaterCalc, varargin);
            
            if isfield(inputBlock, 'name') && ~isempty(inputBlock.name)
                thisContrast.name = inputBlock.name;
            end

            if isfield(inputBlock, 'data') && ~isempty(inputBlock.data)
                thisContrast.data = inputBlock.data;
            end

            if isfield(inputBlock, 'oilData') && ~isempty(inputBlock.oilData)
                thisContrast.oilData = inputBlock.oilData;
            end
            
            if isfield(inputBlock, 'background') && ~isempty(inputBlock.background)
                thisContrast.background = inputBlock.background;
            end
            
            if isfield(inputBlock, 'nba') && ~isempty(inputBlock.nba)
                thisContrast.nba = inputBlock.nba;
            end
            
            if isfield(inputBlock, 'nbs') && ~isempty(inputBlock.nbs)
                thisContrast.nbs = inputBlock.nbs;
            end

            if isfield(inputBlock, 'scalefactor') && ~isempty(inputBlock.scalefactor)
                thisContrast.scalefactor = inputBlock.scalefactor;
            end
            
            if isfield(inputBlock, 'resolution') && ~isempty(inputBlock.resolution)
                thisContrast.resolution = inputBlock.resolution;
            end
            
            if isfield(inputBlock, 'resample') && ~isempty(inputBlock.resample)
                thisContrast.resample = inputBlock.resample;
            end
            
            if isfield(inputBlock, 'domainRatio') && ~isempty(inputBlock.domainRatio)
                thisContrast.domainRatio = inputBlock.domainRatio;
            end

            obj.contrasts{contrastIndex} = thisContrast;
            
        end

        function contrastNames = getAllContrastNames(obj)
            % Get the names of all contrasts defined in the class.
            %
            % contrasts.getAllContrastNames()
            nContrasts = obj.numberOfContrasts;
            contrastNames = cell(1,nContrasts);
                        
            for i = 1:nContrasts
                thisContrast = obj.contrasts{i};
                contrastNames{i} = thisContrast.name;
            end
        end

        function contrastStruct = toStruct(obj, allowedNames, modelType)
            % Convert the contrasts class to a struct.
            % This routine deals with properties common to all contrast
            % classes. The expected input is the allowed names for each
            % parameter, the model type and the data table from the data class.
            %
            % contrasts.toStruct(allowedNames, 'standard layers', dataTable)
            nContrasts = obj.numberOfContrasts;
            contrastLayers = cell(1,nContrasts);
            contrastNbas = ones(1,nContrasts);
            contrastNbss = ones(1,nContrasts);
            contrastCustomFile = ones(1,nContrasts);
            
            contrastNames = cell(1,nContrasts);
            contrastRepeatSLDs = cell(1,nContrasts);
            
            for i = 1:nContrasts

                thisContrast = obj.contrasts{i};
                
                contrastNbas(i) = find(strcmpi(thisContrast.nba,allowedNames.bulkInNames));
                contrastNbss(i) = find(strcmpi(thisContrast.nbs,allowedNames.bulkOutNames));
                contrastRepeatSLDs{i} = [0 1]; % todo
                contrastNames{i} = thisContrast.name;

                modelType = validateOption(modelType, 'modelTypes', obj.invalidTypeMessage).value;
                switch modelType
                    case modelTypes.StandardLayers.value
                        thisModel = thisContrast.model;
                        thisLayerArray = ones(1, length(thisModel));
                        for n = 1:length(thisModel)
                            thisLayer = thisModel{n};
                            thisLayerNum = find(strcmpi(thisLayer, allowedNames.layersNames));
                            thisLayerArray(n) = thisLayerNum;
                        end
                        contrastLayers{i} = thisLayerArray;
                        contrastCustomFile(i) = NaN;
                    otherwise
                        contrastLayers{i} = {};
                        whichFile = thisContrast.model;
                        thisContrastFileNum = find(strcmpi(whichFile, allowedNames.customNames));
                        contrastCustomFile(i) = thisContrastFileNum;
                end
                
            end

            contrastStruct.contrastNames = contrastNames;
            contrastStruct.numberOfContrasts = nContrasts;
            contrastStruct.contrastNbas = contrastNbas;
            contrastStruct.contrastNbss = contrastNbss;
            contrastStruct.contrastLayers = contrastLayers;
            contrastStruct.contrastRepeatSLDs = contrastRepeatSLDs;
            contrastStruct.contrastCustomFile = contrastCustomFile;
            
        end

        function displayContrastsObject(obj)
            % Display the contrasts object as a table.
            % The subclass routine needs to pass in the rowNames for it's
            % particular properties.
            %
            % contrasts.displayContrastsObject()         
            rowNames = obj.displayNames;
            nContrasts = obj.numberOfContrasts;
            maxModelSize = 1;
            
            for i = 1:nContrasts
                thisContrast = obj.contrasts{i};
                thisModel = thisContrast.model;
                if length(thisModel) > maxModelSize
                    maxModelSize = length(thisModel);
                end
            end

            numNamedRows = length(rowNames);
            modelRows = cell((maxModelSize-1),1);
            if ~isempty(modelRows)
                for n = 1:length(modelRows)
                    modelRows{n} = '';
                end
            end

            p = [rowNames ; modelRows];
            totalRows = length(p);
            contrastsCell = cell(totalRows,nContrasts);
            
            for i = 1:nContrasts
                thisContrast = obj.contrasts{i};
                n = 1;

                % Loop over all fields excluding the model
                for j = 1:length(rowNames)-1
                    field = obj.rowHeaders.field(obj.rowHeaders.key == rowNames{j});
                    contrastsCell(n,i) = {thisContrast.(field)};
                    n = n + 1;
                end
                
                % Deal with the model explicitly
                thisModel = thisContrast.model;
                if isempty(thisModel)
                    contrastsCell(numNamedRows,i) = {' '};
                else
                    for n = 1:length(thisModel)
                        contrastsCell(numNamedRows+(n-1),i) = {thisModel(n)};
                    end
                end

            end
            
            sz = size(contrastsCell);
            varTypes = cell(1,nContrasts);
            varNames = cell(1,nContrasts);
            for i = 1:nContrasts
                varNames{i} = num2str(i);
                varTypes{i} = 'string';
            end

            thisTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
            
            % Make sure that there are no empty cells - make them empty
            % char arrays or they will not be valid table elements
            for n = 1:sz(1)
                for m = 1:sz(2)
                    if (isempty(contrastsCell{n,m}))
                        contrastsCell{n,m} = '';
                    end
                end
            end
            thisTable(:,:) = contrastsCell;
            valTable = table(p);
            totalTable = [valTable thisTable];
            disp(totalTable);
        end

    end
end


