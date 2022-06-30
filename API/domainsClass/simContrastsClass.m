classdef simContrastsClass < handle
    
    % A simplified version of the contrast class that allows specification
    % of the model only (i.e. with no data). This is used in domainsClass
    % and overloads the contrasts class in projectClass.
    
    properties
        numberOfContrasts = 0
        contrastsTable
        contrasts = {};
        contrastAutoNameCounter = 1;
    end
    
    methods
        
        function  obj = simContrastsClass()
            
        end
        
        function obj = addSimContrast(obj, allowedNames, varargin)
       
            if isempty(varargin{:})
                % No input 
                contrastNumber = obj.contrastAutoNameCounter;
                contrastName = sprintf('New sim contrast %d',contrastNumber);
                inputVals = {'name', contrastName};
                
            elseif length(varargin{:}) == 1
                % Just name of contrast
                thisName = varargin{1}{:};
                inputVals = {'name', thisName};
                
            else
                % Evereything else
                inputVals = varargin{:};
            end
            
            inputBlock = parseSimContrastInput(allowedNames,inputVals);
            thisContrast = inputBlock;
            
            obj.contrasts{end+1} = thisContrast;
            obj.numberOfContrasts = obj.numberOfContrasts + 1;
            obj.contrastAutoNameCounter = obj.contrastAutoNameCounter + 1;
        
        end
        
        function obj = setSimContrastModel(obj, whichContrast, modelType, allowedNames, varargin)
            
            % Determine which contrast is being set
            thisContrast = obj.contrasts{whichContrast};
            modelArray = varargin{:};
            
            switch modelType
                case 'standard'
                    modelArray = cellstr(modelArray);
                    for i = 1:length(modelArray)
                        if ~strcmpi(modelArray{i},allowedNames)
                            error('Layer %s is not recognised',modelArray{i});
                        end
                    end
                    
                case 'custom'
                    modelArray = cellstr(modelArray);
                    if length(modelArray) > 1
                        error('Only 1 model value allowed for ''custom''');
                    end
                    
                    if ~strcmpi(modelArray,allowedNames)
                        error('Custom name is not recognised');
                    end
            end
            thisContrast.model = modelArray;
            obj.contrasts{whichContrast} = thisContrast;
        end
        
        function obj = setSimContrast(obj, whichContrast, allowedNames, varargin)
            
            % Set a value within a contrast.
            
            % Determine which contrast is being set
            thisContrast = obj.contrasts{whichContrast};
            
            inputBlock = parseSimContrastInput(allowedNames,varargin{:});
            
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
            
            obj.contrasts{whichContrast} = thisContrast;
            
        end
        
        function contrastNames = getAllSimContrastNames(obj)
            nContrasts = obj.numberOfContrasts;
            contrastNames = cell(1,nContrasts);
            
            if nContrasts == 0
                error('Can''t get contrast names when no contrasts defined')
            end
            
            for i = 1:nContrasts
                thisContrast = obj.contrasts{i};
                contrastNames{i} = thisContrast.name;
            end
        end
        
        function obj = updateSimContrastName(obj,nameChange)
           
            % This function is only really called from 
            % projectClass if a data name has been updated.
            % Looks through the 'data' field of the contrasts
            % and if it maches nameChange.oldName then
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
        
        function contrastStruct = toStruct(obj,allowedNames,modelType)
            
            nContrasts = obj.numberOfContrasts;
            contrastLayers = cell(1,nContrasts);
            contrastNbas = ones(1,nContrasts);
            contrastNbss = ones(1,nContrasts);
            contrastRepeatSLDs = cell(1,nContrasts);
            
            for i = 1:nContrasts
                                
                thisContrast = obj.contrasts{i};
                
                contrastNbas(i) = find(strcmpi(thisContrast.nba,allowedNames.bulkInNames));
                contrastNbss(i) = find(strcmpi(thisContrast.nbs,allowedNames.bulkOutNames));
                contrastRepeatSLDs{i} = [0 1]; 
                
                switch modelType
                    case 'layers'
                        thisModel = thisContrast.model;
                        thisLayerArray = [];
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
                
            end
            
            contrastStruct.contrastNbas = contrastNbas;
            contrastStruct.contrastNbss = contrastNbss;
            contrastStruct.contrastLayers = contrastLayers;
            contrastStruct.contrastRepeatSLDs = contrastRepeatSLDs;
            contrastStruct.contrastCustomFile = contrastCustomFile;
            contrastStruct.numberOfContrasts = nContrasts;
            
        end
        
        function displaySimContrastsObject(obj)
            makeSimContrastsTable(obj);
            fprintf('    Sim Constrasts: ---------------------------------------------------------------------------------------------- \n\n');
            disp(obj.contrastsTable);
        end
        
        function obj = makeSimContrastsTable(obj)
            
            nContrasts = obj.numberOfContrasts;
            maxModelSize = 1;
            
            for i = 1:nContrasts
                thisContrast = obj.contrasts{i};%{:};
                thisModel = thisContrast.model;
                if length(thisModel) > maxModelSize
                    maxModelSize = length(thisModel);
                end
            end
            
            varTypes = cell(1,nContrasts);
            varNames = cell(1,nContrasts);
            for i = 1:nContrasts
                varNames{i} = num2str(i);
                varTypes{i} = 'string';
            end

            val = ["name";"Bulk in";"Bulk out";"Model"];
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
                contrastsCell(2,i) = {thisContrast.nba};
                contrastsCell(3,i) = {thisContrast.nbs};
                
                thisModel = thisContrast.model;
                if isempty(thisModel)
                    contrastsCell(4,i) = {' '};
                else
                    for n = 1:length(thisModel)
                        contrastsCell(4+(n-1),i) = {thisModel(n)};
                    end
                end
            end
            
            sz = size(contrastsCell);
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
    
    methods (Access = protected)
        
        function contrast = makeEmptyContrastStruct(obj)
            
            contrast = struct('name','',...
                'Bulk in',...
                'Bulk out',...
                'Model');
        end
        
    end       % End protected methods

end    % End classdef

function inputBlock = parseSimContrastInput(allowedNames,inputVals)

    defaultName = '';  
    defaultNba = '';
    defaultNbs = '';
    defaultModel = '';

    expectedBulkin = cellstr(allowedNames.bulkInNames);
    expectedBulkout = cellstr(allowedNames.bulkOutNames);
    expectedLayers = cellstr(allowedNames.layersNames);
    expectedCustom = cellstr(allowedNames.customNames);
    
    expectedModel = [expectedLayers ; expectedCustom];

    p = inputParser;
    addParameter(p,'name',          defaultName,        @ischar);
    addParameter(p,'nba',           defaultNba,         @(x) any(validatestring(x,expectedBulkin)));
    addParameter(p,'nbs',           defaultNbs,         @(x) any(validatestring(x,expectedBulkout)));
    addParameter(p,'model',         defaultModel,       @(x) any(validatestring(x,expectedModel)));
        
    parse(p,inputVals{:});
    inputBlock = p.Results;

end


