classdef contrastsClass < handle
    
    properties
        contrastsTable
        contrasts = {}
    end

    properties (Access = private)
        contrastAutoNameCounter
    end

    properties (Dependent, SetAccess = private)
        numberOfContrasts
    end
    
    methods
        
        function  obj = contrastsClass()
            % Class Constructor
            obj.contrastAutoNameCounter = 1;
        end

        function count = get.numberOfContrasts(obj)
            count = length(obj.contrasts);
        end

        function obj = addContrast(obj, allowedNames, varargin)
            
            % Parsing Input Types....
            
            % 1 No input at all.
            % p.addContrast()
            % varargin =
            %     1×1 cell array
            %     {0×0 cell}
            %
            % -   length(varargin) = 1
            %     isempty(varargin) = logical 0
            %
            %     varargin{:} - 0x0 empty cell array
            %     length(varargin{:}) = 0
            %     isempty(varargin{:}) - logical 1
            %
            %
            %
            %  % 2. Just name string
            %  p.addContrast('my contrast')
            %  varargin =
            %     1×1 cell array
            %     {1×1 cell}
            %
            %     length(varargin) = 1
            %     isempty(varargin) = logical 0
            %
            %     varargin{:} - 1×1 cell array - {'my contrast'}
            %     length(varargin{:}) = 1
            %     isempty(varargin{:}) - logical 0
            %
            %
            %  % Longer input
            %  p.addContrast('name','my contrast','backround','background 1')
            %
            %  varargin =
            %     1×1 cell array
            %     {1×4 cell}
            %
            %     length(varargin) = 1
            %     isempty(varargin) = logical 0
            %
            %     varargin{:} = 1×4 cell array  - {'name'}    {'my contrast'}    {'backround'}    {'background 1'}
            %     length(varargin{:}) = 4
            %     isempty(varargin{:}) - logical 0

            if isempty(varargin{:})
                % No input at all
                contrastName = sprintf('New contrast %d', obj.contrastAutoNameCounter);
                inputVals = {'name', contrastName};
                
            elseif length(varargin{:}) == 1
                % Just name of contrast
                thisName = varargin{1}{:};
                inputVals = {'name', thisName};
                
            else
                % Everything else
                inputVals = varargin{:};
            end
            
            thisContrast = obj.parseContrastInput(allowedNames,inputVals);
            obj.contrasts{end+1} = thisContrast;
            obj.contrastAutoNameCounter = obj.contrastAutoNameCounter + 1;
        
        end

        function obj = removeContrast(obj, whichContrast)
        
            % Removes a contrast from the list.

            % First determine if contrast is being referenced by name or
            % number...

            % If the input is a string, find the index of the relevant
            % contrast...
            if ischar(whichContrast)
                contrastNames = getAllContrastNames(obj);
                whichContrast = find(strcmp(contrastNames,whichContrast));
                
                % Throw an error if the name is not matched
                if isempty(whichContrast)
                    throw(nameNotRecognised('Contrast name not found'));
                end
            end
           
            % Check to make sure the number is in range
            if whichContrast < 1 || whichContrast > obj.numberOfContrasts
                throw(indexOutOfRange(sprintf('Specified contrast %d is not in range 1 - %d', whichContrast, obj.numberOfContrasts)));
            end

            % Remove the contrast from the contrasts cell array
            obj.contrasts(whichContrast) = [];

        end


        function obj = setContrastModel(obj, contrastInput, modelType, allowedNames, varargin)
            
            % Find if we are referencing an existing contrast
            if isnumeric(contrastInput)
                if (contrastInput < 1 || contrastInput > obj.numberOfContrasts)
                    throw(indexOutOfRange(sprintf('Contrast number %d is out of range 1 - %d', contrastInput, obj.numberOfContrasts)));
                end
                contrastIndex = contrastInput;
                
            elseif ischar(contrastInput)
                [present,idx] = ismember(contrastInput, obj.getAllContrastNames());
                if ~present
                    throw(nameNotRecognised(sprintf('Contrast %s is not recognised', contrastInput)));
                end
                contrastIndex = idx;
                
            end

            % Determine which contrast is being set
            thisContrast = obj.contrasts{contrastIndex};
            modelArray = cellstr(varargin{:});

            if any(strcmpi(modelType, {'custom layers', 'custom xy'}))
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
        
        function obj = setContrast(obj, contrastInput, allowedNames, varargin)
            
            % Set a value within a contrast.

            % Find if we are referencing an existing contrast
            if isnumeric(contrastInput)
                if (contrastInput < 1 || contrastInput > obj.numberOfContrasts)
                    throw(indexOutOfRange(sprintf('Contrast number %d is out of range 1 - %d', contrastInput, obj.numberOfContrasts)));
                end
                contrastIndex = contrastInput;
                
            elseif ischar(contrastInput)
                [present,idx] = ismember(contrastInput, obj.getAllContrastNames());
                if ~present
                    throw(nameNotRecognised(sprintf('Contrast %s is not recognised',contrastInput)));
                end
                contrastIndex = idx;
                
            end

            thisContrast = obj.contrasts{contrastIndex};

            % Check to see if the inputs are valid
            % Do something slightly different if we are setting
            % model because we have to check a larger array
            %switch varargin{1}{1}
                
                %case 'model'
%                     modelArray = varargin{1}{2};
%                     modelArray = cellstr(modelArray);
%                     for i = 1:length(modelArray)
%                         if ~strcmpi(modelArray{i},allowedNames.layersNames)
%                             error('Layer %s is not recognised',modelArray{i});
%                         end
%                     end
%                     thisContrast.model = modelArray;
                %otherwise
                    
                    inputBlock = obj.parseContrastInput(allowedNames,varargin{:});
                    
                    if ~isempty(inputBlock.background)
                        thisContrast.background = inputBlock.background;
                    end
                    
                    if ~isempty(inputBlock.data)
                        thisContrast.data = inputBlock.data;
                    end
                    
                    if ~isempty(inputBlock.model)
                        thisContrast.model = {inputBlock.model};
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
                    
            %end
            
            obj.contrasts{contrastIndex} = thisContrast;
            
        end
        
        function contrastNames = getAllContrastNames(obj)
            nContrasts = obj.numberOfContrasts;
            contrastNames = cell(1,nContrasts);
            
            if nContrasts == 0
                throw(invalidValue('Can''t get contrast names when no contrasts defined'));
            end
            
            for i = 1:nContrasts
                thisContrast = obj.contrasts{i};
                contrastNames{i} = thisContrast.name;
            end
        end
        
        function obj = updateContrastName(obj,nameChange)
           
            % This function is only really called from 
            % projectClass if a data name has been updated.
            % Looks through the 'data' field of the contrasts
            % and if it matches nameChange.oldName then
            % this is updated to nameChange.newName
            
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

                switch modelType
                    case 'standard layers'
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
            makeContrastsTable(obj);
            fprintf('    Constrasts: ---------------------------------------------------------------------------------------------- \n\n');
            disp(obj.contrastsTable);
        end
        
        function obj = makeContrastsTable(obj)
            
            nContrasts = obj.numberOfContrasts;
            maxModelSize = 1;
            
            for i = 1:nContrasts
                thisContrast = obj.contrasts{i};
                thisModel = thisContrast.model;
                if length(thisModel) > maxModelSize
                    maxModelSize = length(thisModel);
                end
            end
                        
            val = ["name";"Data";"Background";"Bulk in";"Bulk out";"Scalefactor";"Resolution";"Resample";"Model"];
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
                
                thisModel = thisContrast.model;
                if isempty(thisModel)
                    contrastsCell(9,i) = {' '};
                else
                    for n = 1:length(thisModel)
                        contrastsCell(9+(n-1),i) = {thisModel(n)};
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
            obj.contrastsTable = totalTable;
            
        end

    end
    
    methods(Static)

        function inputBlock = parseContrastInput(allowedNames,inputVals)
        
            defaultName = '';
            defaultBack = '';
            defaultData = '';   
            defaultNba = '';
            defaultNbs = '';
            defaultScalefac = '';
            defaultResol = '';
            defaultResample = false;
            defaultModel = '';
        
            expectedBacks = cellstr(allowedNames.backsNames);
            expectedData = cellstr(allowedNames.dataNames);
            expectedBulkin = cellstr(allowedNames.bulkInNames);
            expectedBulkout = cellstr(allowedNames.bulkOutNames);
            expectedResols = cellstr(allowedNames.resolsNames);
            expectedLayers = cellstr(allowedNames.layersNames);
            expectedScalefac = cellstr(allowedNames.scalefacNames);
            expectedCustom = cellstr(allowedNames.customNames);
            
            expectedModel = [expectedLayers, expectedCustom];
        
            p = inputParser;
            addParameter(p,'name',          defaultName,        @ischar);
            addParameter(p,'background',    defaultBack,        @(x) any(validatestring(x,expectedBacks)));
            addParameter(p,'data',          defaultData,        @(x) any(validatestring(x,expectedData)));
            addParameter(p,'nba',           defaultNba,         @(x) any(validatestring(x,expectedBulkin)));
            addParameter(p,'nbs',           defaultNbs,         @(x) any(validatestring(x,expectedBulkout)));
            addParameter(p,'resolution',    defaultResol,       @(x) any(validatestring(x,expectedResols)));
            addParameter(p,'scalefactor',   defaultScalefac,    @(x) any(validatestring(x,expectedScalefac)));
            addParameter(p,'resample',      defaultResample,    @islogical);
            addParameter(p,'model',         defaultModel,       @(x) any(validatestring(x,expectedModel)));
                
            parse(p,inputVals{:});
            inputBlock = p.Results;
        
        end

    end
end


