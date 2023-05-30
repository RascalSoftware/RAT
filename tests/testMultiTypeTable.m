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
% example calculation "DPPCStandardLayers.m"
%
% Paul Sharp 01/02/23
%
%% Declare properties and parameters

    properties (TestParameter)
        % Cell arrays for initialising a multi type table

        rowInput = {{},...
                    {'Added background'},...
                    {'Name and Type', allowedTypes.Data},...
                    {'Three params', allowedTypes.Function, 'Back Par 1'},...
                    {'Four params', allowedTypes.Constant, 'Back Par 1', 'Back Par 2'},...
                    {'Five params', allowedTypes.Data.value, 'Back Par 1', 'Back Par 2', 'Back Par 3'},...
                    {'Six params', allowedTypes.Function.value, 'Back Par 1', 'Back Par 2', 'Back Par 3', 'Back Par 4'},...
                    {'Full background', allowedTypes.Data.value, 'Back Par 1', 'Back Par 2', 'Back Par 3', 'Back Par 4', 'Back Par 5'},...
                    {'Overfilled background', allowedTypes.Constant.value, 'Back Par 1', 'Back Par 2', 'Back Par 3', 'Back Par 4', 'Back Par 5', 'Back Par 6'}} % Inputs for "addRow"

        addedRow = {{'New background 0',allowedTypes.Constant.value,'','','','',''},...
                    {'Added background',allowedTypes.Constant.value,'','','','',''},...
                    {'Name and Type',allowedTypes.Data.value,'','','','',''},...
                    {'Three params',allowedTypes.Function.value,'Back Par 1','','','',''},...
                    {'Four params',allowedTypes.Constant.value,'Back Par 1','Back Par 2','','',''},...
                    {'Five params',allowedTypes.Data.value,'Back Par 1','Back Par 2','Back Par 3','',''},...
                    {'Six params',allowedTypes.Function.value,'Back Par 1','Back Par 2','Back Par 3','Back Par 4',''},...
                    {'Full background', allowedTypes.Data.value, 'Back Par 1', 'Back Par 2','Back Par 3', 'Back Par 4', 'Back Par 5'},...
                    {'Overfilled background', allowedTypes.Constant.value, 'Back Par 1', 'Back Par 2','Back Par 3', 'Back Par 4', 'Back Par 5'}} % Resulting additional rows from "addRow"
    end

    properties
        exampleTable            % Example Multi-Type Table for testing
        initialTypesTable
        initialAllowedActions = {'add'  'subtract'}
        initialTypesAutoNameString = 'Row'
        numRows                 % Number of rows in exampleTable
        numCols                 % Number of columns in exampleTable
    end

%% Set up test data

    methods (TestClassSetup)

        function initialiseTypesTable(testCase)
            % Set up a types table with a single row of empty strings
            sz = [0 7];
            tableTypes = {'string','string','string','string','string','string','string'};
            tableNames = {'Name','Type','Value 1','Value 2','Value 3','Value 4','Value 5'};

            testCase.initialTypesTable = table('Size',sz,'VariableTypes',tableTypes,'VariableNames',tableNames);
        end

    end

    methods (TestMethodSetup)

        function initialiseMultiTypeTable(testCase)
            % Set up an example multi-type table for testing
            % This example is used in the backgrounds class for the
            % example calculation "DPPCStandardLayers.m"
            testCase.exampleTable = multiTypeTable();
            testCase.exampleTable.paramTable(1,:) = {'Background D2O', allowedTypes.Constant.value, 'Backs par 1','','','',''};
            testCase.exampleTable.paramTable(2,:) = {'Background SMW',allowedTypes.Constant.value,'Backs par SMW','','','',''};
            testCase.exampleTable.paramTable(3,:) = {'Background H2O',allowedTypes.Constant.value,'Backs par H2O','','','',''};
            testCase.exampleTable.allowedActions = {'add','subtract'};
            testCase.exampleTable.typesAutoNameString = 'New background';

            testCase.numRows = height(testCase.exampleTable.paramTable);
            testCase.numCols = length(testCase.exampleTable.paramTable.Properties.VariableNames);
        end
        
    end

%% Test Multi-Type Table Class Routines

    methods (Test, ParameterCombination='sequential')

        function testInitialiseMultiTypeTable(testCase)
            % Tests Multi-Type Table object can be created
            testTable = multiTypeTable();

            testCase.verifySize(testTable.paramTable, [0 7], 'multiTypeTable does not initialise correctly');

            testCase.verifyEqual(testTable.paramTable, testCase.initialTypesTable, 'multiTypeTable does not initialise correctly');
            testCase.verifyEqual(testTable.allowedActions, testCase.initialAllowedActions, 'multiTypeTable does not initialise correctly');
            testCase.verifyEqual(testTable.typesAutoNameString, testCase.initialTypesAutoNameString, 'multiTypeTable does not initialise correctly');
        end

        function testAddRow(testCase, rowInput, addedRow)
            % Test adding a row to a multi-type table. We can add a row
            % using a cell array of any length, with the specified
            % parameters filling the first set of variables in the table,
            % and empty strings filling and unspecified values.
            expectedTable = [testCase.exampleTable.paramTable; addedRow];

            testCase.exampleTable.addRow(rowInput);

            testCase.verifyEqual(testCase.exampleTable.paramTable, expectedTable, 'addRow does not work correctly');
        end

        function testAddRowInvalidType(testCase)
            % Test adding a row to a multi type table.
            % If we use an invalid type it should raise an error
            testCase.verifyError(@() testCase.exampleTable.addRow({'Invalid Row', 'Invalid Type'}), invalidOption.errorID);
        end

        function testSetValue(testCase)
            % Test setting values in the multi-type table using both names
            % and indices to refer to rows and columns.
            % Note that the routine requires a single cell array rather
            % than a variable number of arguments.

            % Row and column indices
            testCase.exampleTable.setValue(1, 7, 'Added');
            expectedRow = ["Background D2O" "constant" "Backs par 1" "" "" "" "Added"];
            testCase.verifyEqual(testCase.exampleTable.paramTable{1, :}, expectedRow, 'setValue does not work correctly');

            % Row name and column index
            testCase.exampleTable.setValue('Background SMW', 7, 'Added');
            expectedRow = ["Background SMW" "constant" "Backs par SMW" "" "" "" "Added"];
            testCase.verifyEqual(testCase.exampleTable.paramTable{2, :}, expectedRow, 'setValue does not work correctly');

            % Row index and column name
            testCase.exampleTable.setValue(3, 'Value 1', 'Changed');
            expectedRow = ["Background H2O" "constant" "Changed" "" "" "" ""];
            testCase.verifyEqual(testCase.exampleTable.paramTable{3, :}, expectedRow, 'setValue does not work correctly');

            % Row and column names
            testCase.exampleTable.setValue('Background D2O', 'Value 5', 'Changed');
            expectedRow = ["Background D2O" "constant" "Backs par 1" "" "" "" "Changed"];
            testCase.verifyEqual(testCase.exampleTable.paramTable{1, :}, expectedRow, 'setValue does not work correctly');

            % Use name to change name
            testCase.exampleTable.setValue('Background D2O', 'Name', 'New Name');
            expectedRow = ["New Name" "constant" "Backs par 1" "" "" "" "Changed"];
            testCase.verifyEqual(testCase.exampleTable.paramTable{1, :}, expectedRow, 'setValue does not work correctly');
        end

        function testSetValueInvalid(testCase)
            % Test setting values in the multi-type table using invalid
            % values of both names and indices to refer to rows and columns
            % Note that the routine requires a single cell array rather
            % than a variable number of arguments

            % Row indices
            testCase.verifyError(@() testCase.exampleTable.setValue(0, testCase.numCols, 'Added'), indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleTable.setValue(testCase.numRows+1, testCase.numCols, 'Added'), indexOutOfRange.errorID);

            % Column indices
            testCase.verifyError(@() testCase.exampleTable.setValue(1, 0, 'Added'), indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleTable.setValue(1, testCase.numCols+1, 'Added'), indexOutOfRange.errorID);

            % Row name
            testCase.verifyError(@() testCase.exampleTable.setValue('Invalid Name', testCase.numCols, 'Added'), nameNotRecognised.errorID);

            % Column name
            testCase.verifyError(@() testCase.exampleTable.setValue(1, 'Invalid Name', 'Added'), nameNotRecognised.errorID);

            % Float values within range
            testCase.verifyError(@() testCase.exampleTable.setValue(1, 2.5, 'Added'), 'MATLAB:badsubscript');
            testCase.verifyError(@() testCase.exampleTable.setValue(2.5, 1, 'New Name'), 'MATLAB:badsubscript');

            % Invalid data types
            testCase.verifyError(@() testCase.exampleTable.setValue(testCase.initialTypesTable, testCase.numCols, 'Added'), invalidType.errorID);
            testCase.verifyError(@() testCase.exampleTable.setValue(1, datetime('today'), 'Added'), invalidType.errorID);
        end

        function testAppendNewRow(testCase)
            newRow = {'New Row',allowedTypes.Constant.value,'','','','',''};
            expectedTable = [testCase.exampleTable.paramTable; newRow];

            testCase.exampleTable.appendNewRow(newRow);
            testCase.verifyEqual(testCase.exampleTable.paramTable, expectedTable, 'appendNewRow does not work correctly');
        end

        function testAppendNewRowDuplicateName(testCase)
            % Test that appending a new row with a duplicate name raises
            % an error
            newRow = {'Background D2O',allowedTypes.Constant.value,'','','','',''};

            testCase.verifyError(@() testCase.exampleTable.appendNewRow(newRow), duplicateName.errorID);
            testCase.verifySize(testCase.exampleTable.paramTable, [testCase.numRows testCase.numCols], 'Table parameters have changed despite duplicate names');
        end

        function testRemoveRow(testCase)
            % Note that the routine requires a single cell array as input
            remainingRows = testCase.exampleTable.paramTable(2:end,:);
            testCase.exampleTable.removeRow(1);

            testCase.verifyEqual(testCase.exampleTable.paramTable, remainingRows, 'removeRow does not work correctly');
        end

        function testRemoveRowMultiple(testCase)
            % Test removing multiple rows from a multi-type table
            % Note that the routine requires a single cell array as input
            remainingRows = testCase.exampleTable.paramTable(2,:);
            testCase.exampleTable.removeRow([1 3]);

            testCase.verifyEqual(testCase.exampleTable.paramTable, remainingRows, 'removeRow does not work correctly');
        end

        function testRemoveRowInvalid(testCase)
            % Test using invalid row indices to remove rows from a
            % multi-type table.
            % Note that the routine requires a single cell array as input.
            testCase.verifyError(@() testCase.exampleTable.removeRow(0), 'MATLAB:validators:mustBePositive');
            testCase.verifyError(@() testCase.exampleTable.removeRow(1.5), 'MATLAB:validators:mustBeInteger');
            testCase.verifyError(@() testCase.exampleTable.removeRow(testCase.numRows+1), 'RAT:IndexOutOfRange');

            testCase.verifySize(testCase.exampleTable.paramTable, [testCase.numRows testCase.numCols], 'Table parameters have changed despite no rows being removed');
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
            varString = "p " + strip(strjoin(string(testCase.exampleTable.paramTable.Properties.VariableNames)));
            testCase.verifyEqual(outVars, varString, 'Table headers do not match variable names');

            % Make sure the output has the right number of rows before
            % continuing - output consists of table header, divider row
            % and the defined table rows
            testCase.assertSize(displayedTable, [testCase.numRows+2, 1], 'Table does not have the right number of rows');

            % Check table contents - when displayed, row 2 is a set of
            % lines, so row 3 is the first line of data
            for i = 1:testCase.numRows

                % Replace multiple spaces in output table with a single
                % space using regular expressions, and remove '"'
                % characters
                outRow = strip(replace(regexprep(displayedTable(i+2), '\s+', ' '), '"', ''));                

                % Get data from this row, join into a single string, and
                % then prepend the row index
                rowString = string(i) + " " + strip(strjoin(testCase.exampleTable.paramTable{i,:}));
                testCase.verifyEqual(outRow, rowString, 'Row does not contain the correct data');

            end

        end

        function testFindRowIndex(testCase)
            % Test that the correct row number is returned for a valid row
            % or column, and an error is raised for invalid options
            tableRows = testCase.exampleTable.paramTable{:,1};
            tableCols = testCase.exampleTable.paramTable.Properties.VariableNames;

            testCase.verifyEqual(multiTypeTable.findRowIndex('Background SMW', tableRows), 2);
            testCase.verifyEqual(multiTypeTable.findRowIndex('Value 3', tableCols), 5);

            % Check whitespace still matches
            testCase.verifyEqual(multiTypeTable.findRowIndex(' Background D2O', tableRows), 1);
            testCase.verifyEqual(multiTypeTable.findRowIndex(' Type ', tableCols), 2);

            testCase.verifyError(@() multiTypeTable.findRowIndex('Invalid Row', tableRows), nameNotRecognised.errorID);
            testCase.verifyError(@() multiTypeTable.findRowIndex('Value 3', tableRows), nameNotRecognised.errorID);
            testCase.verifyError(@() multiTypeTable.findRowIndex('Value 6', tableCols), nameNotRecognised.errorID);
        end

    end
end
