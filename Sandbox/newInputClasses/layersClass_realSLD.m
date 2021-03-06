classdef layersClass_realSLD < handle
    
    % This is the class definition for the
    % layers block with no absorption.
    properties
        layersTable = table
    end
    
    properties (Access = private)
        layersCount
        layersAutoNameCounter
        allowedHydration = {'bulk in','bulk out','none'}; 
    end
    
    methods
        
        function obj = layersClass_realSLD()
            
            % Class constructor
            
            sz = [0 6];
            varTypes = {'string','string','string','string','string','string'};
            varNames = {'Name','Thickness','SLD','Roughness','Hydration','Hydrate with'};
            obj.layersTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
            %obj.layersTable(1,:) = {'Layer 1','', '', '', '','bulk out'};
            obj.layersCount = 0;
            obj.layersAutoNameCounter = 1;
            
        end
        
        function obj = addLayer(obj,varargin)
            
            whatToAdd = varargin{1}{1};
            
            switch whatToAdd
                case 'empty'
                    % Add an empty layer
                    layerNum = obj.layersAutoNameCounter;
                    layerName = sprintf('Layer %d',layerNum);
                    newRow = {layerName,'','','','','bulk out'};
                    appendNewRow(obj,newRow);
                    
                case 'empty named'
                    % Add an empty named layer 
                    layerName = varargin{1}{2};
                    newRow = {layerName{:},'','','','','bulk out'};
                    appendNewRow(obj,newRow);
                
                case 'full layer'
                    % add a layer that is fully defined
                    layerDetails = varargin{1}{2}{:};
                    
                    if length(layerDetails) ~= 6
                        error('Can''t define a layer from partial details')
                    end
                    
                    name = layerDetails{1};
                    hydrateWhat = layerDetails{end};
                    
                    if ~strcmpi(hydrateWhat,obj.allowedHydration)
                        error('Hydrate type must be ''bulk in'', ''bulk out'' or ''none''');
                    end
                    
                    % Check that the parameter names given are real
                    % parameters or numbers
                    paramNames = varargin{2}{:,1};
                    numPars = length(paramNames);
                    thisRow = {name};
                    
                    for i = 2:5
                        thisParam = layerDetails{i};
                        
                        if ischar(thisParam)
                            
                            % Must be a parameter name
                            if ~strcmp(thisParam,paramNames)
                                error('Unrecognised parameter %s in layers definition',thisParam)
                            end
                            thisRow{i} = thisParam;
                            
                        elseif isnumeric(thisParam)
                            
                            % Must be a parameter number
                            if (thisParam < 1) || (thisParam > numPars)
                                error('Parameter ''%d'' is out of range of params list')
                            end
                            thisRow{i} = paramNames{thisParam};
                        end 
                    end
                    
                    thisRow = [thisRow hydrateWhat];
                    appendNewRow(obj,thisRow);
                    
            end
            
        end
        
        function obj = setLayerValue(obj,varargin)
            
            % Sets a value in a  layer
            inputValues = varargin{1};
            layerNames = obj.layersTable{:,1};
            
            % Find the row index if we have a layer name
            if ischar(inputValues{1})
                row = findRowIndex(inputValues{1},layerNames);
            else
                row = inputValues{1};
            end
            
            if ~isnumeric(row)
                error('Layer not recognised');
            end
            
            col = inputValues{2};
            if ~isnumeric(col) || col < 2  || col > 6
                error('Parameter 2 should be a number between 2 and 5')
            end
            
            val = inputValues{3};
            if col == 6
                if ~(strcmpi(val,obj.allowedHydration))
                    error('Column 6 of layer must be ''bulk in'', ''bulk out'' or ''none''');
                end
            end
                
            obj.layersTable(row,col) = {string(val)};
            
        end

        
        function displayLayersTable(obj)
            
            % Displays the layers table with numbered rows
            array = obj.layersTable;
            len = size(array,1);
            if len == 0
                % Make an empty table for display
                sz = [1 6];
                varTypes = {'double','double','double','double','double','double'};
                varNames = {'Name','Thickness','SLD','Roughness','Hydration','Hydrate with'};
                dummyTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
                %dummyTable(:,1) = {[],[],[],[],[],[]};
                disp(dummyTable);
                fprintf('\n');
            end
            p = [1:len];
            p = p(:);
            p = table(p);
            all = [p array];
            disp(all);
            
        end
        
    end
    
    methods (Access = protected)
        
        function appendNewRow(obj,row)
            tab = obj.layersTable;
            newName = row{1};
            if any(strcmp(newName,tab{:,1}))
                error('Duplicate layer names are not allowed');
            end
            tab = [tab ; row];
            obj.layersTable = tab;
            obj.layersCount = obj.layersCount + 1;
            obj.layersAutoNameCounter = obj.layersAutoNameCounter + 1;
        end
        
    end
    
end

function row = findRowIndex(name,rowNames)
    index = find(strcmpi(name, rowNames));
    
    if isempty(index)
        error('Layer name not found');
    end
    
    row = index;

end




