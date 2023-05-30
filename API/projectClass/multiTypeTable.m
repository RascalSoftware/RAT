classdef multiTypeTable < tableUtilities
    
    % This is the class definition for the backgrounds and resolutions
    % tables.
    
    properties
        typesTable = table
        allowedActions = {'add', 'subtract'}
        typesAutoNameString = 'Row'
    end

    properties (Access = private)
        typesAutoNameCounter
    end

    properties (Dependent, SetAccess = private)
        typesCount
    end

    methods
       
        function obj = multiTypeTable()
            % Initialises a multi-type table.
            %
            % multiTable = multiTypeTable();
            sz = [0 7];
            varTypes = {'string','string','string','string','string','string','string'};
            varNames = {'Name','Type','Value 1','Value 2','Value 3','Value 4','Value 5'};
            obj.typesTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
            obj.typesAutoNameCounter = 0;
        end

        function count = get.typesCount(obj)
           count = height(obj.typesTable);
        end

        function obj = addRow(obj, addParams)
            % Adds a row to the multi-type table. The row can be specified
            % with up to seven parameters, with empty strings used for
            % values that are not specified.
            %
            % multiTable.addRow('New Row');
            switch length(addParams)

                case 0
                    % No Parameter. Add empty row
                    thisName = char(obj.typesAutoNameString);
                    thisNum = obj.typesAutoNameCounter;
                    name = sprintf('%s %d',thisName,thisNum);
                    newRow = {name,allowedTypes.Constant.value,'','','','',''};
                    
                case 1
                    % One parameter: assume this is a name
                    newRow = {addParams,allowedTypes.Constant.value,'','','','',''};

                otherwise
                    % Two or more parameters are specified. 
                    % Assume the specified parameters refer to each table
                    % entry in order, then pad the row with empty
                    % characters if necessary
                    newRow = [addParams, repmat({''}, 1, 7-length(addParams))];

                    % Check type is one of the allowed types
                    invalidTypeMessage = sprintf('Allowed type must be a allowedTypes enum or one of the following strings (%s)', ...
                                                 strjoin(allowedTypes.values(), ', '));
                    newRow{2} = validateOption(newRow{2}, 'allowedTypes', invalidTypeMessage).value;
            end

            % Pass in only the first seven values to ensure input is not too long
            appendNewRow(obj, newRow(1:7));

        end
        
        function obj = setValue(obj, row, col, value)
            % Change the value of a given parameter in the table. The row
            % and column of the parameter can both be specified by either
            % name or index. The expected input is three values: row,
            % column, value
            %
            % multiTable.setValue(1, 1, 'origin');
            tab = obj.typesTable;
            
            % First parameter needs to be either a row name or number
            rowNames = obj.typesTable{:,1};
            
            if isText(row)
                row = obj.findRowIndex(row, rowNames, 'Unrecognised parameter name');
            elseif isnumeric(row)
                if (row < 1) || (row > obj.typesCount)
                    throw(indexOutOfRange(sprintf('The row index %d is not within the range 1 - %d', row, obj.typesCount)));
                end
            else
                throw(invalidType('Unrecognised row'));
            end
            
            % Second parameter needs to be either a column name or
            % number.
            colNames = obj.typesTable.Properties.VariableNames;

            if isText(col)
                col = obj.findRowIndex(col,colNames, 'Unrecognised column name');
            elseif isnumeric(col)
                if (col < 1) || (col > length(colNames))
                    throw(indexOutOfRange(sprintf('The column index %d is not within the range 1 - %d', col, length(colNames))));
                end
            else
                throw(invalidType('Unrecognised column'));
            end
            
            % Set the value
            tab(row, col) = {value};
            obj.typesTable = tab;

        end

        function removeRow(obj, row)
            % Removes a row from the multi-type table. The expected
            % input is an integer or integer array.
            % NOTE that an input such as [1 3] leads to multiple rows
            % being removed from the table
            %
            % multiTable.removeRow(2);
            tab = obj.typesTable;
            tab(row, :) = [];
            obj.typesTable = tab;
        end
        
        function displayTypesTable(obj)
            % Display the multi-type Table in the terminal.
            %
            % multiTable.displayTypesTable();
            array = obj.typesTable;
            p = 1:size(array,1);
            p = p(:);
            p = table(p);
            all = [p array];
            disp(all);
        end

        function appendNewRow(obj, row)
            % Appends a row to the multi-type table. The expected input is
            % a length seven cell array.
            %
            % multiTable.appendNewRow({'New Row','','','','','',''});
            tab = obj.typesTable;
            newName = row{1};
            if any(strcmp(newName,tab{:,1}))
                throw(duplicateName('Duplicate parameter names not allowed'));
            end
            tab = [tab ; row];
            obj.typesTable = tab;
            obj.typesAutoNameCounter = obj.typesAutoNameCounter + 1;

        end

    end

end
