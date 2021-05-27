classdef multiTypeTable < handle
    
    
    % This is the class definition for
    % the backgrounds table.
    
    properties
        typesTable = table;
        allowedTypes = {'constant','data','function'};
        allowedActions = {'add','subtract'};
        typesCount;
        typesAutoNameCounter
        typesAutoNameString
    end
    
    methods
       
        function obj = multiTypeTable(startCell)
        % Constructor
            sz = [1 7];
            varTypes = {'string','string','string','string','string','string','string'};
            varNames = {'Name','Type','Value 1','Value 2','Value 3','Value 4','Value 5'};
            obj.typesTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
            obj.typesTable(1,:) = startCell;
            obj.typesCount = 1;
            obj.typesAutoNameCounter = 1;
        end
        
        function obj = addRow(obj,addParams)
            
            switch length(addParams)
                case 0
                    % No Parameter. Add empty row
                    thisName = char(obj.typesAutoNameString);
                    thisNum = obj.typesAutoNameCounter;
                    name = sprintf('%s %d',thisName,thisNum);
                    newRow = {name,'constant','','','','',''};
                    appendNewRow(obj,newRow);
                    
                case 1
                    % One parameter: assume this is a name
                    newRow = {addParams,'constant','','','','',''};
                    appendNewRow(obj,newRow);
                    
                otherwise
                    % More than one parameter. Parsed externally in call so just build
                    % the row
                    newRow = addParams;
                    appendNewRow(obj,newRow);
            end
        end
        
        function obj = setValue(obj,varargin)
            
            in = varargin{:};
            tab = obj.typesTable;
            
            % First parameter needs to be either a row name or number
            rowNames = obj.typesTable{:,1};
            rowPar = in{1};
            
            if ischar(rowPar)
                row = findIndex(rowPar, rowNames);
            elseif isnumeric(rowPar)
                if (rowPar < 1) || (rowPar > length(rowNames))
                   error('Row number out of range')  
                else
                    row = rowPar;
                end
            else
                error('Unrecognised row index');
            end
            
            % Second parameter needs to be either a column name or
            % number.
            colPar = in{2};
            colNames = obj.typesTable.Properties.VariableNames;

            if ischar(colPar)
                col = findIndex(colPar,colNames);
            elseif isnumeric(colPar)
                if (colPar < 1) || (colPar > length(colNames))
                    error('Column number out out of range');
                else
                    col = colPar;
                end
            else
                error('Unrecognised column index');
            end
            
           % Set the value
            tab(row,col) = in(3);
            obj.typesTable = tab;

        end
  
        
        function appendNewRow(obj,row)
            tab = obj.typesTable;
            newName = row{1};
            if any(strcmp(newName,tab{:,1}))
                error('Duplicate parameter names not allowed');
            end
            tab = [tab ; row];
            obj.typesTable = tab;
            obj.typesCount = obj.typesCount + 1;
            obj.typesAutoNameCounter = obj.typesAutoNameCounter + 1;
        end
        
        function removeRow(obj,row)
            tab = obj.typesTable;
            thisRow = row{:};
            tab(thisRow,:) = [];
            obj.typesTable = tab;
            obj.typesCount = obj.typesCount - 1;
        end
        
        function displayTypesTable(obj)
            
            array = obj.typesTable;
            p = [1:size(array,1)];
            p = p(:);
            p = table(p);
            all = [p array];
            disp(all);

        end
    
    end
    
end

function row = findIndex(name, namesList)

    % Strip leading or trailing whitaspaces from names..
    namesList = strip(namesList);
    name = strip(name);
    
    % Compare 'name' to list ignoring case
    index = strcmpi(name, namesList);
    if isempty(index)
        error('Unrecognised parameter name');
    end
    
    % Non-zero value in array is the row index
    row = find(index);

end


%function con = findColIndex(name, namesList)


