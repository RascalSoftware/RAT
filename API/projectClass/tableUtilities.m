 % This class holds the common routines for handling table entries
 
classdef (Abstract) tableUtilities < handle
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
            % Returns a N x 1 cell array of names in the first column of varTable. 
            % 
            % Returns
            % -------
            % names : cell
            %     A cell array which contains the names in the first column of varTable.
            names = obj.varTable{:,1};  
        end
        
        function addRow(obj, varargin)
            % Appends a new entry to the table.
            % 
            % Examples
            % -------- 
            % >>> obj.addRow({'Tails', 10, 20, 30, true, 'uniform', 0, Inf});
            % 
            % Parameters
            % ----------
            % varargin : cell
            %     A cell array with the contents to append.
            % 
            % Raises
            % ------
            % duplicateName
            %     If name of the entry (first column), is a duplicate.
            if any(strcmpi(varargin{1}, obj.varTable{:,1}))
                throw(exceptions.duplicateName('Duplicate row names not allowed'));
            end
            
            obj.varTable = [obj.varTable; varargin];
            obj.autoNameCounter = obj.autoNameCounter + 1;
        end

        function removeRow(obj, row)
            % Removes a given row from the table by index or name.
            %
            % Examples
            % --------
            % To remove the second row in the table.  
            % 
            % >>> obj.removeRow(2);
            % 
            % To remove row with a specific name.
            % 
            % >>> obj.removeData('Data D2O');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number to remove. If it is text, 
            %     it is the name of the row to remove.
            % 
            % Raises
            % ------
            % indexOutOfRange
            %     If ``row`` is an integer and it is less than 1 or more than the number of parameters.
            arguments
                obj
                row
            end
            if iscell(row)
                row = cellstr(row);
                indices = zeros(1, length(row));
                for i = 1:length(row)
                    indices(i) = obj.getValidRow(row{i});
                end
            else
                indices = obj.getValidRow(row);
            end
            
            obj.varTable(indices, :) = [];
        end

        function displayTable(obj)
            % Prints the varTable to the console.
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
            % invalidType
            %     If ``row`` is not a text or whole number.
            if isText(row)
                index = obj.findRowIndex(row, obj.getNames(), sprintf('The row name "%s" is not recognised.', row));
            elseif isnumeric(row) && all(mod(row, 1) == 0)
                index = row;
                for i = 1:length(row)    
                    if (row(i) < 1) || (row(i) > obj.rowCount)
                        throw(exceptions.indexOutOfRange(sprintf('Row index "%d" is out of range (1 - %d).', row(i), obj.rowCount)));
                    end
                end
            else
                throw(exceptions.invalidType('Row should be a text or whole number.'));
            end
        end 
    end

    methods(Access = protected)
        
        function index = findRowIndex(~, name, nameList, errorMessage)
            % Find the index of a name from a list of names.
            %
            % Examples
            % --------
            % >>> index = obj.findRowIndex('param', obj.getNames(), 'Error occurred');
            %
            % Parameters
            % ----------
            % row : string or char array
            %     The name to find.
            % nameList : cell
            %     A cell array containing a set of names.
            % errorMessage : string or char array
            %     Error message for when name is not found.
            % 
            % Raises
            % ------
            % nameNotRecognised
            %     If a name cannot be found in the given list of names.
            arguments
                ~
                name {mustBeTextScalar}
                nameList {mustBeText}
                errorMessage {mustBeTextScalar}
            end

            % Strip leading or trailing whitespaces from names
            nameList = strip(nameList);
            name = strip(name);

            % Compare 'name' to list ignoring case
            index = strcmpi(name, nameList);
            if any(index)
                % Non-zero value in array is the row index
                index = find(index);
            else
                throw(exceptions.nameNotRecognised(errorMessage));
            end
        end

    end
end
