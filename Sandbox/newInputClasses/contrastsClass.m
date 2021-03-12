classdef contrastsClass < handle
    
    properties
        numberOfContrasts = 0
        contrastsTable
        contrasts = {};
        contrastAutoNameCounter = 1;
    end
    
    methods
        
        function  obj = contrastsClass()
            % Class Constructor
            %obj.addContrast({},{'name','Contrast 1'});
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
                disp('no Input');
                contrastNumber = obj.contrastAutoNameCounter;
                contrastName = sprintf('New contrast %d',contrastNumber);
                inputVals = {'name', contrastName};
                
            elseif length(varargin{:}) == 1
                % Just name of contrast
                disp('just contrast name');
                thisName = varargin{1}{:};
                inputVals = {'name', thisName};
                
            else
                % Evereything else
                inputVals = varargin{:};
            end
            
            inputBlock = parseContrastInput(allowedNames,inputVals);
            thisContrast = inputBlock;
            
            obj.contrasts{end+1} = thisContrast;
            obj.numberOfContrasts = obj.numberOfContrasts + 1;
            obj.contrastAutoNameCounter = obj.contrastAutoNameCounter + 1;
        
        end

        
        function obj = setContrast(obj, whichContrast, allowedNames, varargin)
            
            % Set a value within a contrast.

            % Determine which contrast is being set
            thisContrast = obj.contrasts{whichContrast};

            % Check to see if the inputs are valid
            % Do something slightly different if we are setting
            % model because we have to check a larger array
            switch varargin{1}{1}
                
                case 'model'
                    modelArray = varargin{1}{2};
                    modelArray = cellstr(modelArray);
                    for i = 1:length(modelArray)
                        if ~strcmpi(modelArray{i},allowedNames.layersNames)
                            error('Layer %s is not recognised',modelArray{i});
                        end
                    end
                    thisContrast.model = modelArray;
                otherwise
                    
                    inputBlock = parseContrastInput(allowedNames,varargin{:});
                    
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
                    
            end
            
            obj.contrasts{whichContrast} = thisContrast;
            
            disp('debug');
            
        end
        
        function contrastNames = getAllContrastNames(obj)
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
        
        function obj = updateContrastName(obj,nameChange)
           
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
        
        
        function displayContrastsObject(obj)
            makeContrastsTable(obj);
            fprintf('    Constrasts: ---------------------------------------------------------------------------------------------- \n\n');
            disp(obj.contrastsTable);
        end
        
    end
    
    methods (Access = protected)
        
        function contrast = makeEmptyContrastStruct(obj)
            
            contrast = struct('name','',...
                'Data',...
                'Background',...
                'Bulk in',...
                'Bulk out',...
                'Resolution',...
                'Model');
            
        end
        
        function obj = makeContrastsTable(obj)
            
            nContrasts = obj.numberOfContrasts;
            maxModelSize = 1;
            
            for i = 1:nContrasts
                thisContrast = obj.contrasts{i};%{:};
                thisModel = thisContrast.model;
                if length(thisModel) > maxModelSize
                    maxModelSize = length(thisModel);
                end
            end
            
            sz = [(maxModelSize+6) nContrasts];
            varTypes = cell(1,nContrasts);
            varNames = cell(1,nContrasts);
            for i = 1:nContrasts
                thisContrast = obj.contrasts{i};%{:};
                varNames{i} = num2str(i);
                varTypes{i} = 'string';
            end
            
            %obj.paramsTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
            
            val = ["name";"Data";"Background";"Bulk in";"Bulk out";"Resolution";"Model"];
            modelRows = cell((maxModelSize-1),1);
            if ~isempty(modelRows)
                modelRows{:} = '';
            end
            p = [val ; modelRows];
            totalRows = length(p);
            contrastsCell = cell(totalRows,nContrasts);
            %contrastsCell(:,1) = column1;
            
            for i = 1:nContrasts
                thisContrast = obj.contrasts{i};%{:};
                contrastsCell(1,i) = {thisContrast.name};
                contrastsCell(2,i) = {thisContrast.data};
                contrastsCell(3,i) = {thisContrast.background};
                contrastsCell(4,i) = {thisContrast.nba};
                contrastsCell(5,i) = {thisContrast.nbs};
                contrastsCell(6,i) = {thisContrast.resolution};
                
                thisModel = thisContrast.model;
                if isempty(thisModel)
                    contrastsCell(7,i) = {' '};
                else
                    for n = 1:length(thisModel)
                        contrastsCell(7+(n-1),i) = {thisModel(n)};
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
        
    end       % End protected methods

end    % End classdef

function inputBlock = parseContrastInput(allowedNames,inputVals)

    defaultName = '';
    defaultBack = '';
    defaultData = '';   
    defaultNba = '';
    defaultNbs = '';
    defaultResol = '';
    defaultModel = '';

    expectedBacks = cellstr(allowedNames.backsNames);
    expectedData = cellstr(allowedNames.dataNames);
    expectedBulkin = cellstr(allowedNames.bulkInNames);
    expectedBulkout = cellstr(allowedNames.bulkOutNames);
    expectedResols = cellstr(allowedNames.resolsNames);
    expectedLayers = cellstr(allowedNames.layersNames);

    p = inputParser;
    addParameter(p,'name',          defaultName,    @ischar);
    addParameter(p,'background',    defaultBack,    @(x) any(validatestring(x,expectedBacks)));
    addParameter(p,'data',          defaultData,    @(x) any(validatestring(x,expectedData)));
    addParameter(p,'nba',           defaultNba,     @(x) any(validatestring(x,expectedBulkin)));
    addParameter(p,'nbs',           defaultNbs,     @(x) any(validatestring(x,expectedBulkout)));
    addParameter(p,'resolution',    defaultResol,   @(x) any(validatestring(x,expectedResols)));
    addParameter(p,'model',         defaultModel,   @(x) any(validatestring(x,expectedLayers)));
        
    parse(p,inputVals{:});
    inputBlock = p.Results;

end


