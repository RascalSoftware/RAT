classdef testMultiTypeTable < matlab.unittest.TestCase
%%
% testMultiTypeTable Class based unit tests for the multiTypeTable Class
% used within the Project Class in RAT.
%
% In this class, we test:
% multiTypeTable, addRow, setValue, appendNewRow, removeRow,
% displayTypesTable, findRowIndex
%
% We use an example multi-type table from the backgrounds class for the
% example calculation "DPPC_standard_layers.m"
%
% Paul Sharp 01/02/23
%
%% Declare properties and parameters

    properties (TestParameter)
        % Cell arrays for initialising a multi type table
        inputCell = {{},...
                     {'Row 0'},...
                     {'Row 0', 'constant'},...
                     [{'Row 0', 'constant'}, repmat({''}, 1, 1)],...
                     [{'Row 0', 'constant'}, repmat({''}, 1, 2)],...
                     [{'Row 0', 'constant'}, repmat({''}, 1, 3)],...
                     [{'Row 0', 'constant'}, repmat({''}, 1, 4)],...
                     [{'Row 0', 'constant'}, repmat({''}, 1, 5)],...
                     [{'Row 0', 'constant'}, repmat({''}, 1, 6)]}

        rowInput = {{},...
                    {'Added background'},...
                    {'Name and Type', 'data'},...
                    {'Three params', 'function', 'Back Par 1'},...
                    {'Four params', 'constant', 'Back Par 1', 'Back Par 2'},...
                    {'Five params', 'data', 'Back Par 1', 'Back Par 2', 'Back Par 3'},...
                    {'Six params', 'function', 'Back Par 1', 'Back Par 2', 'Back Par 3', 'Back Par 4'},...
                    {'Full background', 'data', 'Back Par 1', 'Back Par 2', 'Back Par 3', 'Back Par 4', 'Back Par 5'},...
                    {'Overfilled background', 'constant', 'Back Par 1', 'Back Par 2', 'Back Par 3', 'Back Par 4', 'Back Par 5', 'Back Par 6'}} % Inputs for "addRow"

        addedRow = {{'New background 3','constant','','','','',''},...
                    {'Added background','constant','','','','',''},...
                    {'Name and Type','data','','','','',''},...
                    {'Three params','function','Back Par 1','','','',''},...
                    {'Four params','constant','Back Par 1','Back Par 2','','',''},...
                    {'Five params','data','Back Par 1','Back Par 2','Back Par 3','',''},...
                    {'Six params','function','Back Par 1','Back Par 2','Back Par 3','Back Par 4',''},...
                    {'Full background', 'data', 'Back Par 1', 'Back Par 2','Back Par 3', 'Back Par 4', 'Back Par 5'},...
                    {'Overfilled background', 'constant', 'Back Par 1', 'Back Par 2','Back Par 3', 'Back Par 4', 'Back Par 5'}} % Resulting additional rows from "addRow"
    end

    properties
        exampleTable;           % Example Multi-Type Table for testing
        initialTypesTable;
        initialAllowedTypes = {'constant'  'data'  'function', 'gaussian'};
        initialAllowedActions = {'add'  'subtract'};
        initialTypesCount = 1;
        initialTypesAutoNameCounter = 1;
        initialTypesAutoNameString = 'Row';
        numRows                 % Number of rows in exampleTable
        numCols                 % Number of columns in exampleTable
    end

%% Set up test data

    methods (TestClassSetup)

        function initialiseTypesTable(testCase)
            % Set up a types table with a single row of empty strings
            sz = [1 7];
            tableTypes = {'string','string','string','string','string','string','string'};
            tableNames = {'Name','Type','Value 1','Value 2','Value 3','Value 4','Value 5'};

            testCase.initialTypesTable = table('Size',sz,'VariableTypes',tableTypes,'VariableNames',tableNames);
            testCase.initialTypesTable(1,:) = {'Row 0','constant','','','','',''};
        end

    end

    methods (TestMethodSetup)

        function initialiseMultiTypeTable(testCase)
            % Set up an example multi-type table for testing
            % This example is used in the backgrounds class for the
            % example calculation "DPPC_standard_layers.m"
            testCase.exampleTable = multiTypeTable({'Background D2O', 'constant', 'Backs par 1','','','',''});
            
            testCase.exampleTable.typesTable(2,:) = {'Background SMW','constant','Backs par SMW','','','',''};
            testCase.exampleTable.typesTable(3,:) = {'Background H2O','constant','Backs par H2O','','','',''};

            testCase.exampleTable.allowedTypes = {'constant', 'data', 'function'};
            testCase.exampleTable.allowedActions = {'add','subtract'};
            testCase.exampleTable.typesCount = 3;
            testCase.exampleTable.typesAutoNameCounter = 3;
            testCase.exampleTable.typesAutoNameString = 'New background';

            testCase.numRows = height(testCase.exampleTable.typesTable);
            testCase.numCols = length(testCase.exampleTable.typesTable.Properties.VariableNames);
        end
        
    end

%% Test Multi-Type Table Class Routines

    methods (Test, ParameterCombination="sequential")

        function testInitialiseMultiTypeTable(testCase, inputCell)
            % A multi-type table can be initialised using a cell array of
            % any length, with the values in the cell array filling
            % the table variables in order.
            testTable = multiTypeTable(inputCell);

            testCase.verifySize(testTable.typesTable, [1 7], "multiTypeTable does not initialise correctly");

            testCase.verifyEqual(testTable.typesTable, testCase.initialTypesTable, "multiTypeTable does not initialise correctly");
            testCase.verifyEqual(testTable.allowedTypes, testCase.initialAllowedTypes, "multiTypeTable does not initialise correctly");
            testCase.verifyEqual(testTable.allowedActions, testCase.initialAllowedActions, "multiTypeTable does not initialise correctly");
            testCase.verifyEqual(testTable.typesCount, testCase.initialTypesCount, "multiTypeTable does not initialise correctly");
            testCase.verifyEqual(testTable.typesAutoNameCounter, testCase.initialTypesAutoNameCounter, "multiTypeTable does not initialise correctly");
            testCase.verifyEqual(testTable.typesAutoNameString, testCase.initialTypesAutoNameString, "multiTypeTable does not initialise correctly");
        end

        function testAddRow(testCase, rowInput, addedRow)
            % Test adding a row to a multi-type table. We can add a row
            % using a cell array of any length, with the specified
            % parameters filling the first set of variables in the table,
            % and empty strings filling and unspecified values.
            expectedTable = [testCase.exampleTable.typesTable; addedRow];

            testCase.exampleTable.addRow(rowInput);

            testCase.verifyEqual(testCase.exampleTable.typesTable, expectedTable, "addRow does not work correctly");
            testCase.verifyEqual(testCase.exampleTable.typesCount, height(testCase.exampleTable.typesTable), "addRow does not work correctly");
            testCase.verifyEqual(testCase.exampleTable.typesAutoNameCounter, height(testCase.exampleTable.typesTable), "addRow does not work correctly");
        end

        function testAddRowInvalidType(testCase)
            % Test adding a row to a multi type table. If we use an
            % invalid type it should raise an error
            testCase.verifyError(@() testCase.exampleTable.addRow({'Invalid Row', 'Invalid Type'}), ?MException);
        end

        function testSetValue(testCase)
            % Test setting values in the multi-type table using both names
            % and indices to refer to rows and columns.
            % Note that the routine requires a single cell array rather
            % than a variable number of arguments.

            % Row and column indices
            testCase.exampleTable.setValue({1, 7, 'Added'});
            expectedRow = ["Background D2O" "constant" "Backs par 1" "" "" "" "Added"];
            testCase.verifyEqual(testCase.exampleTable.typesTable{1, :}, expectedRow, "setValue does not work correctly");

            % Row name and column index
            testCase.exampleTable.setValue({'Background SMW', 7, 'Added'});
            expectedRow = ["Background SMW" "constant" "Backs par SMW" "" "" "" "Added"];
            testCase.verifyEqual(testCase.exampleTable.typesTable{2, :}, expectedRow, "setValue does not work correctly");

            % Row index and column name
            testCase.exampleTable.setValue({3, 'Value 1', 'Changed'});
            expectedRow = ["Background H2O" "constant" "Changed" "" "" "" ""];
            testCase.verifyEqual(testCase.exampleTable.typesTable{3, :}, expectedRow, "setValue does not work correctly");

            % Row and column names
            testCase.exampleTable.setValue({'Background D2O', 'Value 5', 'Changed'});
            expectedRow = ["Background D2O" "constant" "Backs par 1" "" "" "" "Changed"];
            testCase.verifyEqual(testCase.exampleTable.typesTable{1, :}, expectedRow, "setValue does not work correctly");

            % Use name to change name
            testCase.exampleTable.setValue({'Background D2O', 'Name', 'New Name'});
            expectedRow = ["New Name" "constant" "Backs par 1" "" "" "" "Changed"];
            testCase.verifyEqual(testCase.exampleTable.typesTable{1, :}, expectedRow, "setValue does not work correctly");
        end

        function testSetValueInvalid(testCase)
            % Test setting values in the multi-type table using invalid
            % values of both names and indices to refer to rows and columns
            % Note that the routine requires a single cell array rather
            % than a variable number of arguments

            % Row indices
            testCase.verifyError(@() testCase.exampleTable.setValue({0, testCase.numCols, 'Added'}), ?MException)
            testCase.verifyError(@() testCase.exampleTable.setValue({testCase.numRows+1, testCase.numCols, 'Added'}), ?MException)

            % Column indices
            testCase.verifyError(@() testCase.exampleTable.setValue({1, 0, 'Added'}), ?MException)
            testCase.verifyError(@() testCase.exampleTable.setValue({1, testCase.numCols+1, 'Added'}), ?MException)

            % Row name
            testCase.verifyError(@() testCase.exampleTable.setValue({'Invalid Name', testCase.numCols, 'Added'}), ?MException)

            % Column name
            testCase.verifyError(@() testCase.exampleTable.setValue({1, 'Invalid Name', 'Added'}), ?MException)

            % Invalid data types
            testCase.verifyError(@() testCase.exampleTable.setValue({testCase.initialTypesTable, testCase.numCols, 'Added'}), ?MException)
            testCase.verifyError(@() testCase.exampleTable.setValue({1, datetime('today'), 'Added'}), ?MException)
        end

        function testSetValueTooFewParams(testCase)
            % If we call "setValue" with a cell array containing fewer
            % than three values it should raise an error
            testCase.verifyError(@() testCase.exampleTable.setValue({1}), 'MATLAB:badsubscript');
            testCase.verifyError(@() testCase.exampleTable.setValue({1, 1}), 'MATLAB:badsubscript');
        end

        function testAppendNewRow(testCase)
            newRow = {'New Row','constant','','','','',''};
            expectedTable = [testCase.exampleTable.typesTable; newRow];

            testCase.exampleTable.appendNewRow(newRow);

            testCase.verifyEqual(testCase.exampleTable.typesTable, expectedTable, "appendNewRow does not work correctly");
            testCase.verifyEqual(testCase.exampleTable.typesCount, height(testCase.exampleTable.typesTable), "appendNewRow does not work correctly");
            testCase.verifyEqual(testCase.exampleTable.typesAutoNameCounter, height(testCase.exampleTable.typesTable), "appendNewRow does not work correctly");
        end

        function testAppendNewRowDuplicateName(testCase)
            % Test that appending a new row with a duplicate name raises
            % an error
            newRow = {'Background D2O','constant','','','','',''};

            testCase.verifyError(@() testCase.exampleTable.appendNewRow(newRow), ?MException);

            testCase.verifySize(testCase.exampleTable.typesTable, [testCase.numRows testCase.numCols], "Table parameters have changed despite duplicate names");
            testCase.verifyEqual(testCase.exampleTable.typesCount, height(testCase.exampleTable.typesTable), "Table parameters have changed despite duplicate names");
            testCase.verifyEqual(testCase.exampleTable.typesAutoNameCounter, height(testCase.exampleTable.typesTable), "Table parameters have changed despite duplicate names");
        end

        function testRemoveRow(testCase)
            % Note that the routine requires a single cell array as input
            remainingRows = testCase.exampleTable.typesTable(2:end,:);
            testCase.exampleTable.removeRow({1});

            testCase.verifyEqual(testCase.exampleTable.typesTable, remainingRows, "removeRow does not work correctly");
            testCase.verifyEqual(testCase.exampleTable.typesCount, height(testCase.exampleTable.typesTable), "removeRow does not work correctly");
            
            % Note that "typesAutoNameCounter" should not be reduced.
            % This is to prevent the possibility of duplicate row names
            testCase.verifyEqual(testCase.exampleTable.typesAutoNameCounter, testCase.numRows, "removeRow does not work correctly");
        end

        function testRemoveRowMultiple(testCase)
            % Test removing multuple rows from a multi-type table
            % Note that the routine requires a single cell array as input
            remainingRows = testCase.exampleTable.typesTable(2,:);
            testCase.exampleTable.removeRow({[1 3]});

            testCase.verifyEqual(testCase.exampleTable.typesTable, remainingRows, "removeRow does not work correctly");
            testCase.verifyEqual(testCase.exampleTable.typesCount, height(testCase.exampleTable.typesTable), "removeRow does not work correctly");

            % Note that "typesAutoNameCounter" should not be reduced.
            % This is to prevent the possibility of duplicate row names
            testCase.verifyEqual(testCase.exampleTable.typesAutoNameCounter, testCase.numRows, "removeRow does not work correctly");
        end

        function testRemoveRowInvalid(testCase)
            % Test using invalid row indices to remove rows from a
            % multi-type table.
            % Note that the routine requires a single cell array as input.
            testCase.verifyError(@() testCase.exampleTable.removeRow({0}), 'MATLAB:badsubscript');
            testCase.verifyError(@() testCase.exampleTable.removeRow({1.5}), 'MATLAB:badsubscript');
            testCase.verifyError(@() testCase.exampleTable.removeRow({testCase.numRows+1}), 'MATLAB:table:RowIndexOutOfRange');

            testCase.verifySize(testCase.exampleTable.typesTable, [testCase.numRows testCase.numCols], "Table parameters have changed despite no rows being removed");
            testCase.verifyEqual(testCase.exampleTable.typesCount, height(testCase.exampleTable.typesTable), "Table parameters have changed despite no rows being removed");
        end

        function testDisplayTypesTable(testCase)
            % Test the routine to display the types table by capturing the
            % output and comparing with the table headers and data 

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display = textscan(evalc('testCase.exampleTable.displayTypesTable()'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};

            % Check headers
            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove "<strong>" tags
            outVars = eraseBetween(strip(regexprep(displayedTable(1), '\s+', ' ')), '<', '>','Boundaries','inclusive');

            % Convert multi-type table variable names to a string array,
            % join into a single string, and then prepend an extra header
            % used for the row index
            varString = "p " + strip(strjoin(string(testCase.exampleTable.typesTable.Properties.VariableNames)));
            testCase.verifyEqual(outVars, varString, 'Table headers do not match variable names');

            % Make sure the output has the right number of rows before
            % continuing
            testCase.assertSize(displayedTable, [testCase.numRows+2, 1], 'Table does not have the right number of rows');

            % Check table contents - when displayed, row 2 is a set of
            % lines, so row 3 is the first line of data
            for i = 1:testCase.numRows

                % Replace multiple spaces in output table with a single
                % space using regular expressions
                outRow = strip(regexprep(displayedTable(i+2), '\s+', ' '));

                % Get data from this row, add '"' characters to
                % match output, join into a single string, and then
                % prepend the row index
                rowString = string(i) + " " + strip(strjoin(strcat('"',testCase.exampleTable.typesTable{i,:},'"')));
                testCase.verifyEqual(outRow, rowString, "Row does not contain the correct data");

            end

        end

        function testFindRowIndex(testCase)
            % Test that the correct row number is returned for a valid row
            % or column, and an error is raised for invalid options
            tableRows = testCase.exampleTable.typesTable{:,1};
            tableCols = testCase.exampleTable.typesTable.Properties.VariableNames;

            testCase.verifyEqual(multiTypeTable.findRowIndex("Background SMW", tableRows), 2);
            testCase.verifyEqual(multiTypeTable.findRowIndex("Value 3", tableCols), 5);

            % Check whitespace still matches
            testCase.verifyEqual(multiTypeTable.findRowIndex(" Background D2O", tableRows), 1);
            testCase.verifyEqual(multiTypeTable.findRowIndex(" Type ", tableCols), 2);

            testCase.verifyError(@() multiTypeTable.findRowIndex("Invalid Row", tableRows), ?MException)
            testCase.verifyError(@() multiTypeTable.findRowIndex("Value 3", tableRows), ?MException)
            testCase.verifyError(@() multiTypeTable.findRowIndex("Value 6", tableCols), ?MException)
        end

    end
end
