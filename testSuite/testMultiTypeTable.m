classdef testMultiTypeTable < matlab.unittest.TestCase
%%
% testMultiTypeTable Class based unit tests for the Multi Type Table Class
% used within the Project Class in RAT.
%
% In this class, we test:
% multiTypeTable, addRow, setValue, appendNewRow, removeRow,
% displayTypesTable
%
% We use an example multi type table from the backgrounds class for the
% example calculation "DPPC_standard_layers.m"
%
% Paul Sharp 26/01/23
%
%% Declare properties and parameters

    properties (TestParameter)
        % Cell arrays of length one or length seven are valid, other
        % lengths (2--6, >8) are invalid. Zero length is a sepcific case.
        validInputCell = {{''},  {'','','','','','',''}}
        invalidInputCell = {{'',''}, {'','',''}, {'','','',''}, {'','','','',''}, {'','','','','',''}, {'','','','','','','',''}}
        rowInput = {{}, {'Link'}, {'Rauru', 'Saria', 'Darunia', 'Ruto', 'Impa', 'Nabooru', 'Zelda'}} % Inputs for "addRow"
        addedRow={{'New background 3','constant','','','','',''}, ...
                  {'Link','constant','','','','',''}, ...
                  {'Rauru', 'Saria', 'Darunia', 'Ruto', 'Impa', 'Nabooru', 'Zelda'}} % Resulting additional rows from "addRow"
    end

    properties
        exampleTable;           % Example Multi-Type Table for testing
        initialTypesTable;
        initialAllowedTypes = {'constant'  'data'  'function'};
        initialAllowedActions = {'add'  'subtract'};
        initialTypesCount = 1;
        initialTypesAutoNameCounter = 1;
        initialTypesAutoNameString = [];
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
            testCase.initialTypesTable(1,:) = {'','','','','','',''};
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

        function testInitialiseMultiTypeTable(testCase, validInputCell)
            % A multi-type table can be initialised using a one-element
            % cell array, or a seven element cell array
            testTable = multiTypeTable(validInputCell);

            testCase.verifySize(testTable.typesTable, [1 7]);

            testCase.verifyEqual(testTable.typesTable, testCase.initialTypesTable);
            testCase.verifyEqual(testTable.allowedTypes, testCase.initialAllowedTypes);
            testCase.verifyEqual(testTable.allowedActions, testCase.initialAllowedActions);
            testCase.verifyEqual(testTable.typesCount, testCase.initialTypesCount);
            testCase.verifyEqual(testTable.typesAutoNameCounter, testCase.initialTypesAutoNameCounter);
            testCase.verifyEqual(testTable.typesAutoNameString, testCase.initialTypesAutoNameString);
        end

        function testInitialiseEmptyMultiTypeTable(testCase)
            % If we initialise a multi-type table without an input, it
            % should raise an error
            testCase.verifyError(@() multiTypeTable(), 'MATLAB:minrhs');
        end

        function testInitialiseEmptyCellMultiTypeTable(testCase)
            % If we initialise a multi-type table with an empty cell array,
            % it should raise an error
            testCase.verifyError(@() multiTypeTable({}), 'MATLAB:table:RowDimensionMismatch');
        end

        function testInitialiseInvalidMultiTypeTable(testCase, invalidInputCell)
            % If we initialise a multi-type table with a cell array
            % containing more than one field (except for seven) it should
            % raise an error
            testCase.verifyError(@() multiTypeTable(invalidInputCell), 'MATLAB:table:VarDimensionMismatch');
        end

        function testAddRow(testCase, rowInput, addedRow)
            % Test adding a row to a multi-type table. We can add a row
            % using a cell array of length zero, one, or seven only.
            expectedTable = [testCase.exampleTable.typesTable; addedRow];

            testCase.exampleTable.addRow(rowInput);

            testCase.verifyEqual(testCase.exampleTable.typesTable, expectedTable);
            testCase.verifyEqual(testCase.exampleTable.typesCount, height(testCase.exampleTable.typesTable));
            testCase.verifyEqual(testCase.exampleTable.typesAutoNameCounter, height(testCase.exampleTable.typesTable));
        end

        function testAddRowInvalid(testCase, invalidInputCell)
            % Test adding a row to a multi type table. If we use an input
            % cell array containing more than one field (except for seven)
            % it should raise an error
            %
            % !!! THIS IS A BUG !!! - This should be handled in "addRow"
            %
            testCase.verifyError(@() testCase.exampleTable.addRow(invalidInputCell), 'MATLAB:table:vertcat:SizeMismatchWithCell');
        end

        function testSetValue(testCase)
            % Test setting values in the multi-type table using both names
            % and indices to refer to rows and columns.
            % Note that the routine requires a single cell array rather
            % than a variable number of arguments.

            % Row and column indices
            testCase.exampleTable.setValue({1, 7, 'Added'});
            expectedRow = ["Background D2O" "constant" "Backs par 1" "" "" "" "Added"];
            testCase.verifyEqual(testCase.exampleTable.typesTable{1, :}, expectedRow);

            % Row name and column index
            testCase.exampleTable.setValue({'Background SMW', 7, 'Added'});
            expectedRow = ["Background SMW" "constant" "Backs par SMW" "" "" "" "Added"];
            testCase.verifyEqual(testCase.exampleTable.typesTable{2, :}, expectedRow);

            % Row index and column name
            testCase.exampleTable.setValue({3, 'Value 1', 'Changed'});
            expectedRow = ["Background H2O" "constant" "Changed" "" "" "" ""];
            testCase.verifyEqual(testCase.exampleTable.typesTable{3, :}, expectedRow);

            % Row and column names
            testCase.exampleTable.setValue({'Background D2O', 'Value 5', 'Changed'});
            expectedRow = ["Background D2O" "constant" "Backs par 1" "" "" "" "Changed"];
            testCase.verifyEqual(testCase.exampleTable.typesTable{1, :}, expectedRow);

            % Use name to change name
            testCase.exampleTable.setValue({'Background D2O', 'Name', 'New Name'});
            expectedRow = ["New Name" "constant" "Backs par 1" "" "" "" "Changed"];
            testCase.verifyEqual(testCase.exampleTable.typesTable{1, :}, expectedRow);
        end

        function testSetValueInvalid(testCase)
            % Test setting values in the multi-type table using invalid
            % values of both names and indices to refer to rows and columns
            % Note that the routine requires a single cell array rather
            % than a variable number of arguments

            % Row indices
            testCase.verifyError(@() testCase.exampleTable.setValue({0, testCase.numCols, 'Added'}), '')
            testCase.verifyError(@() testCase.exampleTable.setValue({testCase.numRows+1, testCase.numCols, 'Added'}), '')

            % Column indices
            testCase.verifyError(@() testCase.exampleTable.setValue({1, 0, 'Added'}), '')
            testCase.verifyError(@() testCase.exampleTable.setValue({1, testCase.numCols+1, 'Added'}), '')

            % Row name
            %
            % !!! THIS IS A BUG !!! 
            % This should raise an error for being an invalid row name but
            % instead does nothing
            %
            %testCase.verifyError(@() testCase.exampleTable.setValue({'Invalid Name', cols, 'Added'}), '')
            testCase.verifyEqual(testCase.exampleTable.setValue({'Invalid Name', testCase.numCols, 'Added'}), testCase.exampleTable);

            % Column name
            %
            % !!! THIS IS A BUG !!! 
            % This should raise an error for being an invalid row name but
            % instead does nothing
            %
            %testCase.verifyError(@() testCase.exampleTable.setValue({1, 'Invalid Name', 'Added'}), '')
            testCase.verifyEqual(testCase.exampleTable.setValue({1, 'Invalid Name', 'Added'}), testCase.exampleTable);

            % Floats for row and column
            %
            % !!! THIS IS A BUG !!! 
            % These should raise an error for being non-integers rather
            % than bad subscripts
            %
            testCase.verifyError(@() testCase.exampleTable.setValue({1, 1.5, 'Added'}), 'MATLAB:badsubscript')
            testCase.verifyError(@() testCase.exampleTable.setValue({1.5, 1, 'Added'}), 'MATLAB:badsubscript')        
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

            testCase.verifyEqual(testCase.exampleTable.typesTable, expectedTable);
            testCase.verifyEqual(testCase.exampleTable.typesCount, height(testCase.exampleTable.typesTable));
            testCase.verifyEqual(testCase.exampleTable.typesAutoNameCounter, height(testCase.exampleTable.typesTable));
        end

        function testAppendNewRowDuplicateName(testCase)
            % Test that appending a new row with a duplicate name raises
            % an error
            newRow = {'Background D2O','constant','','','','',''};

            testCase.verifyError(@() testCase.exampleTable.appendNewRow(newRow), '');

            testCase.verifySize(testCase.exampleTable.typesTable, [testCase.numRows testCase.numCols]);
            testCase.verifyEqual(testCase.exampleTable.typesCount, height(testCase.exampleTable.typesTable));
            testCase.verifyEqual(testCase.exampleTable.typesAutoNameCounter, height(testCase.exampleTable.typesTable));
        end

        function testRemoveRow(testCase)
            % Note that the routine requires a single cell array as input
            remainingRows = testCase.exampleTable.typesTable(2:end,:);
            testCase.exampleTable.removeRow({1});

            testCase.verifyEqual(testCase.exampleTable.typesTable, remainingRows);
            testCase.verifyEqual(testCase.exampleTable.typesCount, height(testCase.exampleTable.typesTable));
        end

        function testRemoveRowMultiple(testCase)
            % Test removing multuple rows from a multi-type table
            % Note that the routine requires a single cell array as input
            remainingRows = testCase.exampleTable.typesTable(2,:);
            testCase.exampleTable.removeRow({[1 3]});

            testCase.verifyEqual(testCase.exampleTable.typesTable, remainingRows);
            % Should "typesCount" always equal the number of rows?
            testCase.verifyEqual(testCase.exampleTable.typesCount, testCase.numRows-1);
        end

        function testRemoveRowInvalid(testCase)
            % Test using invalid row indices to remove rows from a
            % multi-type table.
            % Note that the routine requires a single cell array as input.
            testCase.verifyError(@() testCase.exampleTable.removeRow({0}), 'MATLAB:badsubscript');
            testCase.verifyError(@() testCase.exampleTable.removeRow({0.5}), 'MATLAB:badsubscript');
            testCase.verifyError(@() testCase.exampleTable.removeRow({testCase.numRows+1}), 'MATLAB:table:RowIndexOutOfRange');

            testCase.verifySize(testCase.exampleTable.typesTable, [testCase.numRows testCase.numCols]);
            testCase.verifyEqual(testCase.exampleTable.typesCount, height(testCase.exampleTable.typesTable));
        end

        function testDisplayTypesTable(testCase)
            % Test the routine to display the types table by capturing the
            % output and checking the table headers and data are contained
            % within the correct rows

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display=textscan(evalc('testCase.exampleTable.displayTypesTable()'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};

            % Check headers
            % Convert multi-type table variable names to a string array
            varNames = string(testCase.exampleTable.typesTable.Properties.VariableNames);

            % The bold formatting used in the output means we cannot
            % compare the strings directly, so check that each variable
            % name is in the header
            for i = 1:testCase.numCols
                testCase.verifySubstring(displayedTable(1), varNames(i));
            end

            % Check table contents - when displayed, row 2 is a set of
            % lines, so row 3 is the first line of data
            % We need to include the '"' character around each string to
            % match the output
            for i = 1:testCase.numRows
                % Replace multiple spaces in output table with a single
                % space using regular expressions
                outRow = strip(regexprep(displayedTable(i+2), '\s+', ' '));

                % Get data from this row, add '"' characters to
                % match output, join into a single string, and then
                % prepend the row index
                rowString = string(i) + " " + strip(strjoin(strcat('"',testCase.exampleTable.typesTable{i,:},'"')));
                testCase.verifyEqual(outRow, rowString);
            end

        end

    end
end