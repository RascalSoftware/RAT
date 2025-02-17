classdef testTableUtilities < matlab.unittest.TestCase
%%
% testTableUtilities Class based unit tests for the tableUtilites Class
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
                    {'Seven params', allowedTypes.Constant.value, 'Back Par 1', 'Back Par 2', 'Back Par 3', 'Back Par 4', 'Back Par 5'},...
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
                    {'Full background', allowedTypes.Data.value, 'Back Par 1', 'Back Par 2','Back Par 3', 'Back Par 4', 'Back Par 5','Back Par 6'},...
                    {'Overfilled background', allowedTypes.Function.value, 'Back Par 1', 'Back Par 2','Back Par 3', 'Back Par 4', 'Back Par 5', 'Back Par 6', 'Back Par 7'}} % Resulting additional rows from "addRow"
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
            testCase.exampleTable.varTable(1,:) = {'Background D2O', allowedTypes.Constant.value, 'Backs par 1','','','','',''};
            testCase.exampleTable.varTable(2,:) = {'Background SMW', allowedTypes.Constant.value, 'Backs par SMW','','','','',''};
            testCase.exampleTable.varTable(3,:) = {'Background H2O', allowedTypes.Constant.value, 'Backs par H2O','','','','',''};
            testCase.exampleTable.typesAutoNameString = 'New background';

            testCase.numRows = height(testCase.exampleTable.varTable);
            testCase.numCols = length(testCase.exampleTable.varTable.Properties.VariableNames);
        end
        
    end

%% Test Multi-Type Table Class Routines

    methods (Test, ParameterCombination='sequential')

        function testGetNames(testCase)
            testCase.verifyEqual(testCase.exampleTable.getNames(), testCase.exampleTable.varTable{:,1});
        end
        
        function testAddRow(testCase)
            newRow = {'New Row',allowedTypes.Constant.value,'','','','','',''};
            expectedTable = [testCase.exampleTable.varTable; newRow];

            testCase.exampleTable.addRow(newRow{:});
            testCase.verifyEqual(testCase.exampleTable.varTable, expectedTable, 'addRow does not work correctly');
        end

        function testAddRowDuplicateName(testCase)
            % Test that appending a new row with a duplicate name raises
            % an error
            newRow = {'Background D2O',allowedTypes.Constant.value,'','','','',''};

            testCase.verifyError(@() testCase.exampleTable.addRow(newRow{:}), exceptions.duplicateName.errorID);
            testCase.verifySize(testCase.exampleTable.varTable, [testCase.numRows testCase.numCols], 'Table parameters have changed despite duplicate names');
        end

        function testRemoveRow(testCase)
            % Test we can remove a single row from a multi-type table by
            % index
            remainingRows = testCase.exampleTable.varTable(2:end,:);
            testCase.exampleTable.removeRow(1);

            testCase.verifyEqual(testCase.exampleTable.varTable, remainingRows, 'removeRow does not work correctly');
        end

        function testRemoveRowName(testCase)
            % Test removing multiple rows from a multi-type table by name
            remainingRows = testCase.exampleTable.varTable(2:end,:);
            testCase.exampleTable.removeRow('Background D2O');

            testCase.verifyEqual(testCase.exampleTable.varTable, remainingRows, 'removeRow does not work correctly');
        end

        function testRemoveRowMultiple(testCase)
            % Test removing multiple rows from a multi-type table by
            % indices
            remainingRows = testCase.exampleTable.varTable(2,:);
            testCase.exampleTable.removeRow([1 3]);

            testCase.verifyEqual(testCase.exampleTable.varTable, remainingRows, 'removeRow does not work correctly');
        end

        function testRemoveRowMultipleCell(testCase)
            % Test removing multiple rows from a multi-type table by name
            remainingRows = testCase.exampleTable.varTable(2,:);
            testCase.exampleTable.removeRow({'Background D2O', 'Background H2O'});

            testCase.verifyEqual(testCase.exampleTable.varTable, remainingRows, 'removeRow does not work correctly');
        end

        function testRemoveRowInvalid(testCase)
            % Test using invalid row indices to remove rows from a
            % multi-type table.
            testCase.verifyError(@() testCase.exampleTable.removeRow(0), 'RAT:IndexOutOfRange');
            testCase.verifyError(@() testCase.exampleTable.removeRow(testCase.numRows+1), 'RAT:IndexOutOfRange');

            testCase.verifySize(testCase.exampleTable.varTable, [testCase.numRows testCase.numCols], 'Table parameters have changed despite no rows being removed');
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

        function testFindRowIndex(testCase)
            % Test that the correct row number is returned for a valid row
            % or column, and an error is raised for invalid options
            tableRows = testCase.exampleTable.varTable{:,1};
            tableCols = testCase.exampleTable.varTable.Properties.VariableNames;

            testCase.verifyEqual(multiTypeTable.findRowIndex('Background SMW', tableRows), 2);
            testCase.verifyEqual(multiTypeTable.findRowIndex('Value 3', tableCols), 6);

            % Check whitespace still matches
            testCase.verifyEqual(multiTypeTable.findRowIndex(' Background D2O', tableRows), 1);
            testCase.verifyEqual(multiTypeTable.findRowIndex(' Type ', tableCols), 2);

            testCase.verifyError(@() multiTypeTable.findRowIndex('Invalid Row', tableRows), exceptions.nameNotRecognised.errorID);
            testCase.verifyError(@() multiTypeTable.findRowIndex('Value 3', tableRows), exceptions.nameNotRecognised.errorID);
            testCase.verifyError(@() multiTypeTable.findRowIndex('Value 6', tableCols), exceptions.nameNotRecognised.errorID);
        end

    end
end
