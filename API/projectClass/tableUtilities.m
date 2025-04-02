classdef (Abstract) tableUtilities < handle

    % This class holds the common routines for handling table entries

    properties
        varTable = table
    end

    properties (GetAccess = protected, SetAccess = private)
        autoNameCounter = 1
    end

    properties (Dependent, SetAccess = private)
        rowCount
    end

    methods

        function count = get.rowCount(obj)
           count = height(obj.varTable);
        end

        function names = getNames(obj)
            % Get a string array of the names of each of the objects
            % defined in the class.
            %
            % customFiles.getNames()
            names = obj.varTable{:,1};  
        end
        
        function addRow(obj, varargin)
            % Appends a new row to the table. Expects a cell array  
            % with the row to append
            % 
            % obj.addRow('Tails', 10, 20, 30, true, 'uniform', 0, Inf)
            % Ensure no duplicate names
            if any(strcmpi(varargin{1}, obj.varTable{:,1}))
                throw(exceptions.duplicateName('Duplicate row names not allowed'));
            end
            
            obj.varTable = [obj.varTable; varargin];
            obj.autoNameCounter = obj.autoNameCounter + 1;
        end

        function removeRow(obj, row)
            % Removes a row from the table. The expected input is an
            % integer/string or integer/string array.
            % NOTE that an input such as [1 3] leads to multiple rows
            % being removed from the table
            %
            % varTable.removeRow(2);
            arguments
                obj
                row
            end

            % Arrange parameters into a cell array
            if isa(row, 'double')

                indices = row;

            elseif isText(row) || iscell(row)

                row = cellstr(row);
                indices = zeros(1, length(row));

                rowNames = obj.getNames;
                for i = 1:length(row)
                    currentRow = row{i};
                    indices(i) = obj.findRowIndex(currentRow, rowNames, 'Unrecognised parameter name');
                end

            else

                throw(exceptions.invalidType('Unrecognised Row'))

            end

            for i = 1:length(indices)
                if indices(i) < 1 || indices(i) > obj.rowCount
                    throw(exceptions.indexOutOfRange(sprintf('Row index %d out of range 1 - %d', indices(i), obj.rowCount)));
                end
            end

            obj.varTable(indices, :) = [];
        end

        function displayTable(obj)
            % Displays the param table with numbered rows
            %
            % layers.displayTable()
            numParams = height(obj.varTable);
            dim = [1, width(obj.varTable)];
            
            if numParams == 0    
                varNames = obj.varTable.Properties.VariableNames(1:dim(2));
                newTable = table('Size', dim, 'VariableTypes', repmat({'string'}, dim), 'VariableNames', varNames);
                newTable(1, :) = repmat({''}, 1, dim(2));
            else
                p = 1:height(obj.varTable);
                p = p(:);
                p = table(p);
                newTable = [p obj.varTable(:, 1:dim(2))];
            end         
            disp(newTable);
        end

        function index = getValidRow(obj, row)
            % Gets a valid row index from varTable, if ``row`` is a name; or validates the index, if ``row`` is an integer.
            % 
            % Examples
            % --------
            % To validate a row index is in table bounds.
            % 
            % >>> index = obj.getValidRow(2);
            % 
            % To find the index for a name.
            % 
            % >>> index = obj.getValidRow('Tails');
            %
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the parameter to update. If it is text, 
            %     it is the name of the parameter to update.
            % 
            % Returns
            % -------
            % index : whole number
            %     A valid row index.
            %
            % Raises
            % ------
            % indexOutOfRange
            %     If ``row`` is an integer and it is less than 1 or more than the number of parameters.
            % nameNotRecognised
            %     If ``row`` is a parameter name and it cannot be found in the table.
            if isText(row)
                index = obj.findRowIndex(row, obj.getNames(), 'Unrecognised row name');
            elseif isnumeric(row)
                index = row;
                if (index < 1) || (index > obj.rowCount)
                    throw(exceptions.indexOutOfRange(sprintf('Row index out out of range 1 - %d', obj.rowCount)));
                end
            else
                throw(exceptions.invalidType('Unrecognised row'));
            end
        end 
    end

    methods(Access = protected)
        
        function row = findRowIndex(~, name, rowNames, errorMessage)
            % Find the index of a row in the table given its name.
            % The expected inputs are the name of the row, the
            % full list of row names, and, optionally, an error message.
            %
            % obj.findRowIndex('param')
            arguments
                ~
                name {mustBeTextScalar}
                rowNames {mustBeText}
                errorMessage {mustBeTextScalar}
            end

            % Strip leading or trailing whitespaces from names
            rowNames = strip(rowNames);
            name = strip(name);

            % Compare 'name' to list ignoring case
            index = strcmpi(name, rowNames);
            if any(index)
                % Non-zero value in array is the row index
                row = find(index);
            else
                throw(exceptions.nameNotRecognised(errorMessage));
            end
        end

    end
end
