classdef contrastsClass < handle

    % This class holds the parameters for each contrast used in the
    % simulation
    
    properties
        contrasts = {}
    end

    properties (Access = private)
        contrastAutoNameCounter
    end

    properties (SetAccess = immutable)
        domainsCalc
    end

    properties (Dependent, SetAccess = private)
        numberOfContrasts
    end

    properties(Access = private, Constant, Hidden)
        invalidTypeMessage = sprintf('Model type must be a modelTypes enum or one of the following strings (%s)', ...
                                     strjoin(modelTypes.values(), ', '))
    end
            
    methods
        
        function obj = contrastsClass(domainsCalc)
            % Class Constructor
            % The only (optional) input is a logical flag to state whether
            % or not this is a domains calculation.
            %
            % contrasts = contrastsClass()
            arguments
                domainsCalc {mustBeA(domainsCalc,'logical')} = false
            end

            obj.domainsCalc = domainsCalc;
            obj.contrastAutoNameCounter = 1;
        end

        function count = get.numberOfContrasts(obj)
            count = length(obj.contrasts);
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
            
            thisContrast = obj.parseContrastInput(allowedNames, obj.domainsCalc, inputVals);
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
            inputBlock = obj.parseContrastInput(allowedNames, obj.domainsCalc, varargin);
            
            if ~isempty(inputBlock.background)
                thisContrast.background = inputBlock.background;
            end
            
            if ~isempty(inputBlock.data)
                thisContrast.data = inputBlock.data;
            end
            
            if ~isempty(inputBlock.name)
                thisContrast.name = inputBlock.name;
            end
            
            if ~isempty(inputBlock.nba)
                thisContrast.nba = inputBlock.nba;
            end
            
            if ~isempty(inputBlock.nbs)
                thisContrast.nbs = inputBlock.nbs;
            end
            
            if ~isempty(inputBlock.resolution)
                thisContrast.resolution = inputBlock.resolution;
            end
            
            if ~isempty(inputBlock.resample)
                thisContrast.resample = inputBlock.resample;
            end
            
            if ~isempty(inputBlock.scalefactor)
                thisContrast.scalefactor = inputBlock.scalefactor;
            end

            if obj.domainsCalc && ~isempty(inputBlock.domainRatio)
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
        
        function obj = updateDataName(obj, nameChange)
            % Update the "data" parameter in a contrast if the name is
            % changed in the data class.           
            % This function is only really called from projectClass if a
            % data name has been updated. It looks through the 'data'
            % field of the contrasts and if it matches nameChange.oldName
            % then this is updated to nameChange.newName
            %
            % contrasts.updateDataName(nameChange)            
            oldName = nameChange.oldName;
            newName = nameChange.newName;
            
            for i = 1:obj.numberOfContrasts
                thisContrast = obj.contrasts{i};
                if strcmpi(oldName,thisContrast.data)
                    obj.contrasts{i}.data = newName;
                end
            end
            
        end
        
        function contrastStruct = toStruct(obj,allowedNames,modelType,dataTable)
            % Convert the contrasts class to a struct.
            % The expected input is the allowed names for each parameter,
            % the model type and the data table from the data class.
            %
            % contrasts.toStruct(allowedNames, 'standard layers', dataTable)
            nContrasts = obj.numberOfContrasts;
            contrastBacks = cell(1,nContrasts);
            contrastLayers = cell(1,nContrasts);
            contrastShifts = ones(1,nContrasts);
            contrastScales = ones(1,nContrasts);
            contrastNbas = ones(1,nContrasts);
            contrastNbss = ones(1,nContrasts);
            contrastRes = ones(1,nContrasts);
            resample = ones(1,nContrasts);
            contrastCustomFile = ones(1,nContrasts);
            contrastNames = cell(1,nContrasts);
            contrastRepeatSLDs = cell(1,nContrasts);
            
            dataPresent = ones(1,nContrasts);
            dataLimits = cell(1,nContrasts);
            simLimits = cell(1,nContrasts);
            allData = cell(1,nContrasts);

            for i = 1:nContrasts

                thisContrast = obj.contrasts{i};
                
                contrastBacks{i} =  [find(strcmpi(thisContrast.background,allowedNames.backsNames)), 1];
                contrastShifts(i) = 1;  %Todo
                contrastScales(i) = find(strcmpi(thisContrast.scalefactor,allowedNames.scalefacNames));
                contrastNbas(i) = find(strcmpi(thisContrast.nba,allowedNames.bulkInNames));
                contrastNbss(i) = find(strcmpi(thisContrast.nbs,allowedNames.bulkOutNames));
                contrastRes(i) = find(strcmpi(thisContrast.resolution,allowedNames.resolsNames));
                resample(i) = thisContrast.resample;
                contrastRepeatSLDs{i} = [0 1]; % todo
                contrastNames{i} = thisContrast.name;

                modelType = validateOption(modelType, 'modelTypes', obj.invalidTypeMessage).value;
                switch modelType
                    case modelTypes.StandardLayers.value
                        thisModel = thisContrast.model;
                        thisLayerArray = ones(1,length(thisModel));
                        for n = 1:length(thisModel)
                            thisLayer = thisModel{n};
                            thisLayerNum = find(strcmpi(thisLayer,allowedNames.layersNames));
                            thisLayerArray(n) = thisLayerNum;
                        end
                        contrastLayers{i} = thisLayerArray;
                        contrastCustomFile(i) = NaN;
                    otherwise
                        contrastLayers{i} = {};
                        whichFile = thisContrast.model;
                        thisContrastFileNum = find(strcmpi(whichFile,allowedNames.customNames));
                        contrastCustomFile(i) = thisContrastFileNum;
                end
                
                thisDataVal = find(strcmpi(thisContrast.data,allowedNames.dataNames));
                if ~isempty(thisDataVal)
                    actualData = dataTable{thisDataVal,2}{:};
                    if isempty(actualData)
                        dataPresent(i) = 0;
                    end
                    thisDataLimit = dataTable{thisDataVal,3}{:};
                    if isempty(thisDataLimit)
                        thisDataLimit = [0 0];
                    end
                    dataLimits{i} = thisDataLimit;
                    simLimits{i} = dataTable{thisDataVal,4}{:};
                    allData{i} = dataTable{thisDataVal,2}{:};
                else
                    dataPresent(i) = 0;
                    dataLimits{i} = [0 0];
                    simLimits{i} = [0 0];
                    allData{i} = [0 0 0];
                end
            end
            
            contrastStruct.contrastBacks = contrastBacks;
            contrastStruct.contrastShifts = contrastShifts;
            contrastStruct.contrastScales = contrastScales;
            contrastStruct.contrastNbas = contrastNbas;
            contrastStruct.contrastNbss = contrastNbss;
            contrastStruct.contrastRes = contrastRes;
            contrastStruct.contrastLayers = contrastLayers;
            contrastStruct.resample = resample;
            contrastStruct.contrastRepeatSLDs = contrastRepeatSLDs;
            contrastStruct.dataPresent = dataPresent;
            contrastStruct.dataLimits = dataLimits;
            contrastStruct.simLimits = simLimits;
            contrastStruct.allData = allData;
            contrastStruct.contrastLayers = contrastLayers;
            contrastStruct.contrastCustomFile = contrastCustomFile;
            contrastStruct.numberOfContrasts = nContrasts;
            
        end
        
        function displayContrastsObject(obj)
            % Display the contrasts object as a table.
            %
            % contrasts.displayContrastsObject()           
            nContrasts = obj.numberOfContrasts;
            maxModelSize = 1;
            
            for i = 1:nContrasts
                thisContrast = obj.contrasts{i};
                thisModel = thisContrast.model;
                if length(thisModel) > maxModelSize
                    maxModelSize = length(thisModel);
                end
            end

            if obj.domainsCalc
                val = ["name";"Data";"Background";"Bulk in";"Bulk out";"Scalefactor";"Resolution";"Resample";"Domain Ratio";"Model"];
            else
                val = ["name";"Data";"Background";"Bulk in";"Bulk out";"Scalefactor";"Resolution";"Resample";"Model"];
            end
            numNamedCols = length(val);
            modelRows = cell((maxModelSize-1),1);
            if ~isempty(modelRows)
                for n = 1:length(modelRows)
                    modelRows{n} = '';
                end
            end

            p = [val ; modelRows];
            totalRows = length(p);
            contrastsCell = cell(totalRows,nContrasts);
            
            for i = 1:nContrasts
                thisContrast = obj.contrasts{i};
                contrastsCell(1,i) = {thisContrast.name};
                contrastsCell(2,i) = {thisContrast.data};
                contrastsCell(3,i) = {thisContrast.background};
                contrastsCell(4,i) = {thisContrast.nba};
                contrastsCell(5,i) = {thisContrast.nbs};
                contrastsCell(6,i) = {thisContrast.scalefactor};
                contrastsCell(7,i) = {thisContrast.resolution};
                contrastsCell(8,i) = {thisContrast.resample};
                if obj.domainsCalc
                    contrastsCell(9,i) = {thisContrast.domainRatio};
                end
                
                thisModel = thisContrast.model;
                if isempty(thisModel)
                    contrastsCell(numNamedCols,i) = {' '};
                else
                    for n = 1:length(thisModel)
                        contrastsCell(numNamedCols+(n-1),i) = {thisModel(n)};
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
            fprintf('    Constrasts: ---------------------------------------------------------------------------------------------- \n\n');
            disp(totalTable);
        end

    end
    
    methods(Static)

        function inputBlock = parseContrastInput(allowedNames, domainsCalc, inputValues)
            % Parse the parameters given for the contrast, assigning
            % default values to those unspecified and ensuring specified
            % values are of the correct type, and included in the list of
            % allowed names where necessary.
            %
            % contrastsClass.parseContrastInput(allowedNames, ...
            %                                   domainsCalc, ...
            %                                   'name', 'Contrast Name', ...
            %                                   'background', 'Background H2O')        
            defaultName = '';
            defaultBack = '';
            defaultData = '';   
            defaultNba = '';
            defaultNbs = '';
            defaultScalefac = '';
            defaultResol = '';
            defaultResample = false;
        
            expectedBacks = cellstr(allowedNames.backsNames);
            expectedData = cellstr(allowedNames.dataNames);
            expectedBulkin = cellstr(allowedNames.bulkInNames);
            expectedBulkout = cellstr(allowedNames.bulkOutNames);
            expectedResols = cellstr(allowedNames.resolsNames);
            expectedScalefac = cellstr(allowedNames.scalefacNames);
        
            p = inputParser;
            addParameter(p,'name',          defaultName,        @isText);
            addParameter(p,'background',    defaultBack,        @(x) any(validatestring(x,expectedBacks)));
            addParameter(p,'data',          defaultData,        @(x) any(validatestring(x,expectedData)));
            addParameter(p,'nba',           defaultNba,         @(x) any(validatestring(x,expectedBulkin)));
            addParameter(p,'nbs',           defaultNbs,         @(x) any(validatestring(x,expectedBulkout)));
            addParameter(p,'resolution',    defaultResol,       @(x) any(validatestring(x,expectedResols)));
            addParameter(p,'scalefactor',   defaultScalefac,    @(x) any(validatestring(x,expectedScalefac)));
            addParameter(p,'resample',      defaultResample,    @islogical);

            if domainsCalc
                defaultDomainRatio = '';
                expectedDomainRatio = cellstr(allowedNames.domainRatioNames);
                addParameter(p,'domainRatio',   defaultDomainRatio, @(x) any(validatestring(x,expectedDomainRatio)));
            end
                
            parse(p, inputValues{:});
            inputBlock = p.Results;
        
        end

    end
end


