classdef multiTypeTable < tableUtilities
    % A multi-type table, used in backgrounds and resolution tables.    
    properties
        typesAutoNameString = 'Row'
    end

    methods
       
        function obj = multiTypeTable()
            % Initialises a multi-type table.
            %
            % Examples
            % --------
            % >>> multiTable = multiTypeTable();
            %
            sz = [0 8];
            varTypes = {'string','string','string','string','string','string','string','string'};
            varNames = {'Name','Type','Source','Value 1','Value 2','Value 3','Value 4','Value 5'};
            obj.varTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
        end

        function obj = addRow(obj, varargin)
            % Adds a row to the multi-type table. The row can be specified
            % with up to seven parameters, with empty strings used for
            % values that are not specified.
            %
            % Parameters
            % ----------
            % varargin : keyword arguments
            %     The parameters to add to the row.
            %
            % Examples
            % --------
            % >>> multiTable.addRow({'New Row'});
            %
            switch length(varargin)

                case 0
                    % No Parameter. Add empty row
                    thisName = char(obj.typesAutoNameString);
                    thisNum = obj.autoNameCounter;
                    name = sprintf('%s %d', thisName, thisNum);
                    newRow = [name, allowedTypes.Constant.value, repmat({''}, 1, width(obj.varTable)-2)];
                    
                case 1
                    % One parameter: assume this is a name
                    newRow = [varargin, allowedTypes.Constant.value, repmat({''}, 1, width(obj.varTable)-2)];

                otherwise
                    % Two or more parameters are specified. 
                    % Assume the specified parameters refer to each table
                    % entry in order, then pad the row with empty
                    % characters if necessary
                    newRow = [varargin, repmat({''}, 1, width(obj.varTable)-length(varargin))];

                    % Check type is one of the allowed types
                    invalidTypeMessage = sprintf('Allowed type must be a allowedTypes enum or one of the following strings (%s)', ...
                                                 strjoin(allowedTypes.values(), ', '));
                    newRow{2} = validateOption(newRow{2}, 'allowedTypes', invalidTypeMessage).value;
            end

            % Pass in only enough values to fit in the table
            addRow@tableUtilities(obj, newRow{1:width(obj.varTable)});

        end
        
        function obj = setValue(obj, row, col, value)
            % Change the value of a given parameter in the table. 
            %
            % Both the row and column of the parameter can both be specified by either
            % name or index.
            %
            % Parameters
            % ----------
            % row : string or int
            %     The name or index of the row.
            % col : string or int
            %     The name or index of the column.
            % value : any
            %     The value to change the parameter to.
            %
            % Examples
            % --------
            % >>> multiTable.setValue(1, 1, 'origin');
            % 
            row = obj.getValidRow(row);
            colNames = obj.varTable.Properties.VariableNames;

            if isText(col)
                col = obj.findRowIndex(col,colNames, 'Unrecognised column name');
            elseif isnumeric(col) && all(mod(col, 1) == 0)
                if (col < 1) || (col > length(colNames))
                    throw(exceptions.indexOutOfRange(sprintf('The column index %d is not within the range 1 - %d', col, length(colNames))));
                end
            else
                throw(exceptions.invalidType('Column type should be a text or whole number.'));
            end
            
            % Set the value
            if col == 1
                obj.setRowName(row, value);
            else
                obj.varTable(row, col) = {value};
            end
        end

    end
end
