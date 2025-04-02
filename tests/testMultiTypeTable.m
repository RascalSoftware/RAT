classdef testMultiTypeTable < matlab.unittest.TestCase
%%
% testMultiTypeTable Class based unit tests for the multiTypeTable Class
% used within the Project Class in RAT.
%
% We use an example multi-type table from the backgrounds class for the
% example calculation "DPPCStandardLayers.m"
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
                    {'Seven params', allowedTypes.Constant.value, 'Back Par 1', 'Back Par 2', 'Back Par 3', 'Back Par 4',  'Back Par 5'},...
                    {'Full background', allowedTypes.Data.value, 'Back Par 1', 'Back Par 2', 'Back Par 3', 'Back Par 4', 'Back Par 5', 'Back Par 6'},...
                    {'Overfilled background', allowedTypes.Function.value, 'Back Par 1', 'Back Par 2', 'Back Par 3', 'Back Par 4', 'Back Par 5', 'Back Par 6', 'Back Par 7'}} % Inputs for "addRow"

        addedRow = {{'New background 1',allowedTypes.Constant.value,'','','','','',''},...
                    {'Added background',allowedTypes.Constant.value,'','','','','',''},...
                    {'Name and Type',allowedTypes.Data.value,'','','','','',''},...
                    {'Three params',allowedTypes.Function.value,'Back Par 1','','','','',''},...
                    {'Four params',allowedTypes.Constant.value,'Back Par 1','Back Par 2','','','',''},...
                    {'Five params',allowedTypes.Data.value,'Back Par 1','Back Par 2','Back Par 3','','',''},...
                    {'Six params',allowedTypes.Function.value,'Back Par 1','Back Par 2','Back Par 3','Back Par 4','',''},...
                    {'Seven params',allowedTypes.Constant.value,'Back Par 1','Back Par 2','Back Par 3','Back Par 4','Back Par 5',''},...
                    {'Full background', allowedTypes.Data.value, 'Back Par 1', 'Back Par 2','Back Par 3', 'Back Par 4', 'Back Par 5', 'Back Par 6'},...
                    {'Overfilled background', allowedTypes.Function.value, 'Back Par 1', 'Back Par 2','Back Par 3', 'Back Par 4', 'Back Par 5', 'Back Par 6'}} % Resulting additional rows from "addRow"
    end

    properties
        exampleTable            % Example Multi-Type Table for testing
        initialTable
        initialTypesAutoNameString = 'Row'
        numRows                 % Number of rows in exampleTable
        numCols                 % Number of columns in exampleTable
    end

%% Set up test data

    methods (TestClassSetup)

        function initialiseTable(testCase)
            % Set up a types table with a single row of empty strings
            sz = [0 8];
            tableTypes = {'string','string','string','string','string','string','string','string'};
            tableNames = {'Name','Type','Source','Value 1','Value 2','Value 3','Value 4','Value 5'};

            testCase.initialTable = table('Size',sz,'VariableTypes',tableTypes,'VariableNames',tableNames);
        end

    end

    methods (TestMethodSetup)

        function initialiseMultiTypeTable(testCase)
            % Set up an example multi-type table for testing
            % This example is used in the backgrounds class for the
            % example calculation "DPPCStandardLayers.m"
            testCase.exampleTable = multiTypeTable();
            testCase.exampleTable.varTable(1,:) = {'Background D2O',allowedTypes.Constant.value,'Backs par 1','','','','',''};
            testCase.exampleTable.varTable(2,:) = {'Background SMW',allowedTypes.Constant.value,'Backs par SMW','','','','',''};
            testCase.exampleTable.varTable(3,:) = {'Background H2O',allowedTypes.Constant.value,'Backs par H2O','','','','',''};
            testCase.exampleTable.typesAutoNameString = 'New background';

            testCase.numRows = height(testCase.exampleTable.varTable);
            testCase.numCols = length(testCase.exampleTable.varTable.Properties.VariableNames);
        end
        
    end

%% Test Multi-Type Table Class Routines

    methods (Test, ParameterCombination='sequential')

        function testInitialiseMultiTypeTable(testCase)
            % Tests Multi-Type Table object can be created
            testTable = multiTypeTable();

            testCase.verifySize(testTable.varTable, [0 8], 'multiTypeTable does not initialise correctly');

            testCase.verifyEqual(testTable.varTable, testCase.initialTable, 'multiTypeTable does not initialise correctly');
            testCase.verifyEqual(testTable.typesAutoNameString, testCase.initialTypesAutoNameString, 'multiTypeTable does not initialise correctly');
        end

        function testAddRow(testCase, rowInput, addedRow)
            % Test adding a row to a multi-type table. We can add a row
            % using a cell array of any length, with the specified
            % parameters filling the first set of variables in the table,
            % and empty strings filling and unspecified values.
            expectedTable = [testCase.exampleTable.varTable; addedRow];

            testCase.exampleTable.addRow(rowInput{:});

            testCase.verifyEqual(testCase.exampleTable.varTable, expectedTable, 'addRow does not work correctly');
        end

        function testAddRowInvalidType(testCase)
            % Test adding a row to a multi type table.
            % If we use an invalid type it should raise an error
            testCase.verifyError(@() testCase.exampleTable.addRow('Invalid Row', 'Invalid Type'), exceptions.invalidOption.errorID);
        end

        function testAddRowDuplicateName(testCase)
            % Test adding a row to a multi type table.
            % If we use a duplicate name it should raise an error
            testCase.verifyError(@() testCase.exampleTable.addRow('Background D2O'), exceptions.duplicateName.errorID);
        end

        function testSetValue(testCase)
            % Test setting values in the multi-type table using both names
            % and indices to refer to rows and columns.
            % Note that the routine requires a single cell array rather
            % than a variable number of arguments.

            % Row and column indices
            testCase.exampleTable.setValue(1, 8, 'Added');
            expectedRow = ["Background D2O" "constant" "Backs par 1" "" "" "" "" "Added"];
            testCase.verifyEqual(testCase.exampleTable.varTable{1, :}, expectedRow, 'setValue does not work correctly');

            % Row name and column index
            testCase.exampleTable.setValue('Background SMW', 8, 'Added');
            expectedRow = ["Background SMW" "constant" "Backs par SMW" "" "" "" "" "Added"];
            testCase.verifyEqual(testCase.exampleTable.varTable{2, :}, expectedRow, 'setValue does not work correctly');

            % Row index and column name
            testCase.exampleTable.setValue(3, 'Source', 'Changed');
            expectedRow = ["Background H2O" "constant" "Changed" "" "" "" "" ""];
            testCase.verifyEqual(testCase.exampleTable.varTable{3, :}, expectedRow, 'setValue does not work correctly');

            % Row and column names
            testCase.exampleTable.setValue('Background D2O', 'Value 5', 'Changed');
            expectedRow = ["Background D2O" "constant" "Backs par 1" "" "" "" "" "Changed"];
            testCase.verifyEqual(testCase.exampleTable.varTable{1, :}, expectedRow, 'setValue does not work correctly');

            % Use name to change name
            testCase.exampleTable.setValue('Background D2O', 'Name', 'New Name');
            expectedRow = ["New Name" "constant" "Backs par 1" "" "" "" "" "Changed"];
            testCase.verifyEqual(testCase.exampleTable.varTable{1, :}, expectedRow, 'setValue does not work correctly');
        end

        function testSetValueInvalid(testCase)
            % Test setting values in the multi-type table using invalid
            % values of both names and indices to refer to rows and columns
            % Note that the routine requires a single cell array rather
            % than a variable number of arguments

            % Row indices
            testCase.verifyError(@() testCase.exampleTable.setValue(0, testCase.numCols, 'Added'), exceptions.indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleTable.setValue(testCase.numRows+1, testCase.numCols, 'Added'), exceptions.indexOutOfRange.errorID);

            % Column indices
            testCase.verifyError(@() testCase.exampleTable.setValue(1, 0, 'Added'), exceptions.indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleTable.setValue(1, testCase.numCols+1, 'Added'), exceptions.indexOutOfRange.errorID);

            % Row name
            testCase.verifyError(@() testCase.exampleTable.setValue('Invalid Name', testCase.numCols, 'Added'), exceptions.nameNotRecognised.errorID);

            % Column name
            testCase.verifyError(@() testCase.exampleTable.setValue(1, 'Invalid Name', 'Added'), exceptions.nameNotRecognised.errorID);

            % Float values within range
            testCase.verifyError(@() testCase.exampleTable.setValue(1, 2.5, 'Added'), 'MATLAB:badsubscript');
            testCase.verifyError(@() testCase.exampleTable.setValue(2.5, 1, 'New Name'), 'MATLAB:badsubscript');

            % Invalid data types
            testCase.verifyError(@() testCase.exampleTable.setValue(testCase.initialTable, testCase.numCols, 'Added'), exceptions.invalidType.errorID);
            testCase.verifyError(@() testCase.exampleTable.setValue(1, datetime('today'), 'Added'), exceptions.invalidType.errorID);
        end

        function testDisplayTable(testCase)
            % Test the routine to display the types table by capturing the
            % output and comparing with the table headers and data 

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display = textscan(evalc('testCase.exampleTable.displayTable()'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};

            % Check headers
            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove "<strong>" tags
            outVars = eraseBetween(strip(regexprep(displayedTable(1), '\s+', ' ')), '<', '>','Boundaries','inclusive');

            % Convert multi-type table variable names to a string array,
            % join into a single string, and then prepend an extra header
            % used for the row index
            varString = "p " + strip(strjoin(string(testCase.exampleTable.varTable.Properties.VariableNames)));
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
                rowString = string(i) + " " + strip(strjoin(testCase.exampleTable.varTable{i,:}));
                testCase.verifyEqual(outRow, rowString, 'Row does not contain the correct data');

            end

        end
    end
end
