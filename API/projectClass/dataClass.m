classdef dataClass < handle
    
    % A container class for holding data
    properties
        
        dataTable;
        dataCount = 0;
        autoDataNameCounter;
        defaultSimMin = 0.005;
        defaultSimMax = 0.7;
        
    end
    
    methods
        
        function obj = dataClass(startCell)
            
            sz = [1 4];
            varTypes = {'string','cell','cell','cell'};
            varNames = {'Name','Data','Data Range','Simulation Range'};
            obj.dataTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
            
            if isempty(startCell{4}{:})
                startCell{4} = {[obj.defaultSimMin obj.defaultSimMax]};
            end
            
            obj.dataTable(1,:) = startCell;%{'Substrate Roughness',1 3 5,true,'uniform',0,Inf};
            obj.dataCount = 1;
            obj.autoDataNameCounter = 1;
            
        end
        
        function obj = addData(obj,varargin)
            
            if isempty(varargin{:})
                
                % Nothing supplied - add empty data row
                nameVal = obj.autoDataNameCounter();
                newName = sprintf('New data %d', nameVal);
                
                newDataRange = [];
                newSimRange = [obj.defaultSimMin, obj.defaultSimMax];
                
                newRow = {newName, [], newDataRange, newSimRange};
                appendNewRow(obj,newRow);
            else
                
                inputs = varargin{:};
                
                % Check length of added data
                switch length(inputs)
                    
                    case 1
                        
                        % One input supplied - assume just name provided
                        newName = inputs{1};
                        if ~ischar(newName)
                            error('Single input is expected to be a data name');
                        end
                        
                        newDataRange = [];
                        newSimRange = [obj.defaultSimMin, obj.defaultSimMax];
                        
                        newRow = {newName, [], newDataRange, newSimRange};
                        %newUserDataRow = {'none',[0,0],[obj.defaultSimMin,obj.defaultSimMax]};
                        appendNewRow(obj,newRow);%,newUserDataRow);
                        
                    case 2
                        
                        % Two inputs supplied - assume both name and data
                        % supplied;
                        newName = inputs{1};
                        newData = inputs{2};
                        
                        newDataX = newData(:,1);
                        newMin = newDataX(1);
                        newMax = newDataX(end);
                        
                        newDataRange = [newMin newMax];
                        newSimRange = [newMin newMax];
                        
                        newRow = {newName, newData, newDataRange, newSimRange};
                        %newUserDataRow = {'data',[newMin,newMax],[newMin,newMax]};
                        appendNewRow(obj,newRow);% ,newUserDataRow);
                        
                    case 4
                        
                        % Four inputs = assume data and simulation ranges also
                        % supplied
                        disp('todo');
                        
                    otherwise
                        
                        % Other length of inputs is not recognised
                        error('Unrecognised input into addData');
                        
                end
            end
            
        end
        
        function nameChanged = setData(obj, varargin)
           
            % Set the value of an existing data object
            inputs = varargin{:};
            dataNames = obj.dataTable{:,1};
            
            % Always need three or more inputs to set data value
            if length(inputs) < 3
                error('At least three inputs expected into ''setData''');
            end
                
            % First input needs to be a data number or name
            whichData = inputs{1};
            if isnumeric(whichData)
                if (whichData > obj.dataCount) || (whichData < 1)
                    error('Data %d is not recognised', whichData);
                end
            elseif ischar(whichData)
                if ~strcmpi(whichData,dataNames)
                    error('Data name %s not recognised', whichData);
                end
            end
            
            % Parse the remaining name value pairs to see what is 
            % being set and make sure the data is of the correct size
            % and type.
            toBeParsed = inputs(2:end);

            % Make an 'inputParser' object...
            p = inputParser;
            
            % dataRange and simRange need to be [1 x 2] arrays
            isDimsRanges = @(x)all(size(x) == [1,2]);
            
            % Data needs to be an [n x >3] array
            isDimsData = @(x) size(x,2) >= 3;

            addParameter(p,'name','', @(x) ischar(x))
            addParameter(p,'data',[], @(x) isnumeric(x) && isDimsData(x))
            addParameter(p,'dataRange',[], @(x) isnumeric(x) && isDimsRanges(x))
            addParameter(p,'simRange', [], @(x) isnumeric(x) && isDimsRanges(x)) 
            parse(p,toBeParsed{:});
                
            results = p.Results;
            
            % Any fields in results that are not empty are being set,
            % so call the relevant set method for these (which will carry
            % out some additional checks)
            
            nameChanged = []; % Flag wich is passed up to the calling function (to change contrasts if necessary)
            
            % Pass numeric identifyer for data into subfunctions
            if ~isnumeric(whichData)
                whichData = find(strcmpi(whichData,dataNames));
            end
            
            if ~isempty(results.name)
                nameChanged = obj.setDataName(whichData,results.name);
            end
            
            
            if ~isempty(results.data)
                obj.setDataValues(whichData,results.data);
            end
            
            if ~isempty(results.dataRange)
                obj.setDataRange(whichData,results.dataRange);
            end
            
            if ~isempty(results.simRange)
                obj.setSimRange(whichData,results.simRange);
            end

        end
        
        function obj = setDataRange(obj,whichData,range)
            
            r = [range(1) range(2)];
            obj.dataTable{whichData,3} = {range};
        
        end
        
        function obj = setSimRange(obj,whichData,range)
            
            r = [range(1) range(2)];
            obj.dataTable{whichData,4} = {range};           
            
            
        end

        
        function nameChanged = setDataName(obj,whichData,name)
            
            % Name must be a char and not an existing name
            if ~ischar(name)
                nameChanged = [];
                error('Name must be a string / character array');
            end
            
            existingNames = obj.getDataNames;
            if strcmpi(name,existingNames)
                nameChanged = [];
                error('Duplicate data names are not allowed');
            end
            
            % Set the relevant name
            nameChanged.oldName = obj.dataTable{whichData,1};
            nameChanged.newName = name;
            obj.dataTable{whichData,1} = {name};
            
        end
        
        
        function names = getDataNames(obj)
            
           names = obj.dataTable{:,1}; 
            
        end
        
        function obj = setDataValues(obj,whichData,data)
            
            obj.dataTable{whichData,2} = {data};
   
        end
        
        
        
        function displayDataObject(obj)
            
            % Display the table object. The actual obj.dataTable has the 
            % format {string, cell, double, double}, but for display we 
            % make a table that is all strings.
            
            fprintf('    Data: ------------------------------------------------------------------------------------------------------ \n\n');
            
            tab = obj.dataTable;
            
            sz = [1,4];
            displayVarTypes = {'string','string','string','string'}; 
            displayVarNames = {'Name','Data','Data Range','Simulation Range'};
            displayTable = table('Size',sz,'VariableTypes',displayVarTypes,'VariableNames',displayVarNames);
            
            tableSize = size(tab);
            
            for i = 1:tableSize(1)
                thisRow = tab(i,:);
                
                nameString = thisRow{1,1};
                
                thisData = thisRow{1,2}{:};
                if isempty(thisData)
                    dataString = "No Data";
                else
                    dataSize = size(thisData);
                    dataString = sprintf('Data array: [%d x %d]',dataSize(1),dataSize(2));
                end
                
                thisDataRange = thisRow{1,3}{:};
                if isempty(thisDataRange)
                    dataRangeString = "-";
                else
                    dataRangeString = sprintf('[ %1.4f , %1.4f ]', thisDataRange(1), thisDataRange(2));
                end
                
                thisSimRange = thisRow{1,4}{:};
                if isempty(thisSimRange)
                    simRangeString = "-";
                else
                    simRangeString = sprintf('[ %1.4f , %1.4f ]', thisSimRange(1), thisSimRange(2));
                end   
                
                newDisplayRow = {nameString, dataString, dataRangeString, simRangeString};
                displayTable(i,:) = newDisplayRow;
                
            end

            disp(displayTable);
            fprintf('\n');
 
        end
       
        
        function obj = appendNewRow(obj,newRow)
            
            tab = obj.dataTable;
            newName = newRow{1};
            if any(strcmpi(newName,tab{:,1}))
                error('Duplicate data names not allowed');
            end
            
            % Carry out checks of Data type and ranges
            data = newRow{2};
            dataRange = newRow{3};
            simRange = newRow{4};
            
            if ~isempty(data)   % Data supplied
                
                if ~isnumeric(data)
                    error('Data must be a numeric array');
                end
                
                if ((~isnumeric(dataRange)) || any(size(dataRange) ~= [1,2]) || any(size(simRange) ~= [1,2]))
                    error('Data range and sim range must be [1 x 2] numeric arrays');
                end

                dataX = data(:,1);              % First column is always Q
                realDataRange = [dataX(1),dataX(end)];
                
                if dataRange(1) < realDataRange(1)
                    warning('Data range can''t be less than data min - resetting');
                    dataRange(1) = realDataRange(1);
                end
                
                if dataRange(2) > realDataRange(2)
                    warning('Data range can''t be more than data max - resetting');
                end
                
                if simRange(1) > realDataRange(1)
                    warning('Sim min range must be inside data range - resetting');
                    simRange(1) = realDataRange(1);
                end
                
                if simRange(2) < realDataRange(2)
                    warning('Sim max range must be inside data range - resetting');
                    simRange(2) = realDataRange(2);
                end
                
            end
            
            row = {{newName}, {data}, {dataRange}, {simRange}};
            tab = [tab ; row];
            obj.dataTable = tab;
            obj.dataCount = obj.dataCount + 1;
            obj.autoDataNameCounter = obj.autoDataNameCounter + 1;
            
        end
        
    end
    
end

function inputBlock = parseDataInput(inputVals)

    defaultName = '';
    defaultData = [];
    defaultRange = [obj.defaultSimMin obj.defaultSimMax];
    defaultSimRange = [obj.defaultSimMin obj.defaultSimMax];

    p = inputParser;
    addParameter(p,'name', defaultName, @ischar);
    addParameter(p,'data', defaultData, @isnumeric);
    addParameter(p,'data range', defaultRange, @(a) validateattributes(a,{'double'},{'size',[1 2]}));
    addParameter(p,'sim range', defaultSimRange, @(a) validateattributes(a,{'double'},{'size',[1 2]}));

    parse(p,inputVals{:});
    inputBlock = p.Results;

end

    
