classdef multiTypeTable < tableUtilities
    
    % This is the class definition for the backgrounds and resolutions
    % tables.
    
    properties
        typesAutoNameString = 'Row'
    end

    methods
       
        function obj = multiTypeTable()
            % Initialises a multi-type table.
            %
            % multiTable = multiTypeTable();
            sz = [0 7];
            varTypes = {'string','string','string','string','string','string','string'};
            varNames = {'Name','Type','Value 1','Value 2','Value 3','Value 4','Value 5'};
            obj.varTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
        end

        function obj = addRow(obj, varargin)
            % Adds a row to the multi-type table. The row can be specified
            % with up to seven parameters, with empty strings used for
            % values that are not specified.
            %
            % multiTable.addRow({'New Row'});
            switch length(varargin)

                case 0
                    % No Parameter. Add empty row
                    thisName = char(obj.typesAutoNameString);
                    thisNum = obj.autoNameCounter;
                    name = sprintf('%s %d', thisName, thisNum);
                    newRow = [name, allowedTypes.Constant.value, repmat({''}, 1, 5)];
                    
                case 1
                    % One parameter: assume this is a name
                    newRow = [varargin, allowedTypes.Constant.value, repmat({''}, 1, 5)];

                otherwise
                    % Two or more parameters are specified. 
                    % Assume the specified parameters refer to each table
                    % entry in order, then pad the row with empty
                    % characters if necessary
                    newRow = [varargin, repmat({''}, 1, 7-length(varargin))];

                    % Check type is one of the allowed types
                    invalidTypeMessage = sprintf('Allowed type must be a allowedTypes enum or one of the following strings (%s)', ...
                                                 strjoin(allowedTypes.values(), ', '));
                    newRow{2} = validateOption(newRow{2}, 'allowedTypes', invalidTypeMessage).value;
            end

            % Pass in only the first seven values to ensure input is not too long
            addRow@tableUtilities(obj, newRow{1:7});

        end
        
        function obj = setValue(obj, row, col, value)
            % Change the value of a given parameter in the table. The row
            % and column of the parameter can both be specified by either
            % name or index. The expected input is three values: row,
            % column, value
            %
            % multiTable.setValue(1, 1, 'origin');
            % First parameter needs to be either a row name or number
            rowNames = obj.varTable{:,1};
            
            if isText(row)
                row = obj.findRowIndex(row, rowNames, 'Unrecognised parameter name');
            elseif isnumeric(row)
                if (row < 1) || (row > obj.rowCount)
                    throw(exceptions.indexOutOfRange(sprintf('The row index %d is not within the range 1 - %d', row, obj.rowCount)));
                end
            else
                throw(exceptions.invalidType('Unrecognised row'));
            end
            
            % Second parameter needs to be either a column name or
            % number.
            colNames = obj.varTable.Properties.VariableNames;

            if isText(col)
                col = obj.findRowIndex(col,colNames, 'Unrecognised column name');
            elseif isnumeric(col)
                if (col < 1) || (col > length(colNames))
                    throw(exceptions.indexOutOfRange(sprintf('The column index %d is not within the range 1 - %d', col, length(colNames))));
                end
            else
                throw(exceptions.invalidType('Unrecognised column'));
            end
            
            % Set the value
            obj.varTable(row, col) = {value};
        end

    end

end
