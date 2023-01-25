classdef testMultiTypeTable < matlab.unittest.TestCase
%%
% testMultiTypeTable Class based unit tests for the Multi Type Table Class
% used within the Project Class in RAT.
%
% In this class, we test:
% ?????????????????
%
% We use an example
%
% Paul Sharp 24/01/23
%
%% Declare properties and parameters

    properties (ClassSetupParameter)
        inputsFile = {'standardLayersInputs.mat', 'customLayersInputs.mat', 'customXYInputs.mat'};     % Input test data
        outputsFile = {'standardLayersOutputs.mat', 'customLayersOutputs.mat', 'customXYOutputs.mat'}; % Output test data
        TFFile = {'standardLayersTFParams.mat', 'customLayersTFParams.mat',  'customXYTFParams.mat'};  % TF Params test data
    end

    properties (TestParameter)    
        whichParallel = {'single', 'points', 'contrasts'} % How the reflectivity calculation is parallelised
        useCompiled = {false, true}                       % Choose either the MATLAB or MEX version
        validInputCell = {{''},  {'','','','','','',''}}
        invalidInputCell = {{'',''}, {'','',''}, {'','','',''}, {'','','','',''}, {'','','','','',''}, {'','','','','','','',''}}
    end

    properties
        initialTypesTable;
        initialAllowedTypes = {'constant'  'data'  'function'};
        initialAllowedActions = {'add'  'subtract'};
        initialTypesCount = 1;
        initialTypesAutoNameCounter = 1;
        initialTypesAutoNameString = [];

        exampleTable;

        tolerance = 1.0e-12;     % Relative tolerance for equality of floats
        abs_tolerance = 1.0e-5;  % Absolute tolerance for equality of floats
    end

%% Set up test data

    methods (TestClassSetup)

        function initialiseTypesTable(testCase)
            % initialiseTypesTable Set up a types table with a single row
            % of empty strings

            sz = [1 7];
            tableTypes = {'string','string','string','string','string','string','string'};
            tableNames = {'Name','Type','Value 1','Value 2','Value 3','Value 4','Value 5'};

            testCase.initialTypesTable = table('Size',sz,'VariableTypes',tableTypes,'VariableNames',tableNames);
            testCase.initialTypesTable(1,:) = {'','','','','','',''};
        end

    end

    methods (TestMethodSetup)

        function initialiseMultiTypeTable(testCase)
            % initialiseTypesTable Set up an example multi type table
            % for testing
            % This example is used in the backgrounds class for the example
            % "DPPC_standard_layers.m"
            testCase.exampleTable = multiTypeTable({'Background D2O', 'constant', 'Backs par 1','','','',''});
            
            testCase.exampleTable.typesTable(2,:) = {'Background SMW','constant','Backs par SMW','','','',''};
            testCase.exampleTable.typesTable(3,:) = {'Background H2O','constant','Backs par H2O','','','',''};

            testCase.exampleTable.allowedTypes = {'constant', 'data', 'function'};
            testCase.exampleTable.allowedActions = {'add','subtract'};
            testCase.exampleTable.typesCount = 3;
            testCase.exampleTable.typesAutoNameCounter = 3;
            testCase.exampleTable.typesAutoNameString = 'New background';
        end
        
    end

%% Test Multi Type Table Class Routines
    methods (Test)

        function testInitialiseMultiTypeTable(testCase, validInputCell)
            % testInitialiseMultiTypeTable Test the routine to initialise
            % a multi-type table
            % The table can be initialised using a one-element cell array,
            % or a seven element cell array
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
            % testInitialiseEmptyMultiTypeTable Test the routine to
            % initialise a multi-type table
            % If we initialise without an input, it should raise an error
            testCase.verifyError(@() multiTypeTable(), 'MATLAB:minrhs');
        end

        function testInitialiseEmptyCellMultiTypeTable(testCase)
            % testInitialiseEmptyCellMultiTypeTable Test the routine to
            % initialise a multi-type table
            % If we initialise with an empty cell array, it should raise
            % an error
            testCase.verifyError(@() multiTypeTable({}), 'MATLAB:table:RowDimensionMismatch');
        end

        function testInitialiseInvalidMultiTypeTable(testCase, invalidInputCell)
            % testInitialiseInvalidMultiTypeTable Test the routine to
            % initialise a multi-type table
            % If we initialise with a cell array containing more than one
            % field (except for seven) it should raise an error
            testCase.verifyError(@() multiTypeTable(invalidInputCell), 'MATLAB:table:VarDimensionMismatch');
        end

        function testAddRow(testCase)
            % testAddRow Test adding a row to a multi type table

            % We can add a row using a cell array of length zero, one, or
            % seven only.
            origRows = height(testCase.exampleTable.typesTable);

            % Test a zero length cell array
            % The routine creates the following name for the row
            rowName = sprintf('%s %d', testCase.exampleTable.typesAutoNameString, testCase.exampleTable.typesAutoNameCounter);
            expectedRow = [rowName "constant" "" "" "" "" ""];

            testCase.exampleTable.addRow({});

            testCase.verifySize(testCase.exampleTable.typesTable, [origRows+1 7]);

            testCase.verifyEqual(testCase.exampleTable.typesTable{end, :}, expectedRow);
            testCase.verifyEqual(testCase.exampleTable.typesCount, height(testCase.exampleTable.typesTable));
            testCase.verifyEqual(testCase.exampleTable.typesAutoNameCounter, height(testCase.exampleTable.typesTable));

            % Test a length one cell array
            rowName = 'Link';
            expectedRow = [rowName "constant" "" "" "" "" ""];

            testCase.exampleTable.addRow({rowName});

            testCase.verifySize(testCase.exampleTable.typesTable, [origRows+2 7]);

            testCase.verifyEqual(testCase.exampleTable.typesTable{end, :}, expectedRow);
            testCase.verifyEqual(testCase.exampleTable.typesCount, height(testCase.exampleTable.typesTable));
            testCase.verifyEqual(testCase.exampleTable.typesAutoNameCounter, height(testCase.exampleTable.typesTable));

            % Test a length seven cell array
            rowData = {'Rauru', 'Saria', 'Darunia', 'Ruto', 'Impa', 'Nabooru', 'Zelda'};

            testCase.exampleTable.addRow(rowData);
            
            testCase.verifySize(testCase.exampleTable.typesTable, [origRows+3 7]);

            testCase.verifyEqual(testCase.exampleTable.typesTable{end, :}, string(rowData));
            testCase.verifyEqual(testCase.exampleTable.typesCount, height(testCase.exampleTable.typesTable));
            testCase.verifyEqual(testCase.exampleTable.typesAutoNameCounter, height(testCase.exampleTable.typesTable));
        end

        function testAddRowInvalid(testCase, invalidInputCell)
            % testAddRowInvalid Test adding a row to a multi type table
            % If we initialise with a cell array containing more than one
            % field (except for seven) it should raise an error
            %
            % !!! THIS IS A BUG !!!
            %
            testCase.verifyError(@() testCase.exampleTable.addRow(invalidInputCell), 'MATLAB:table:vertcat:SizeMismatchWithCell');
        end

        function testSetValue(testCase)
            % Test setting values in the multitype table using both names
            % and indices to refer to rows and columns
            % Note that the routine requires a single cell array rather
            % than a variable number of arguments

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
            % Test setting values in the multitype table using invalid
            % values of both names and indices to refer to rows and columns
            % Note that the routine requires a single cell array rather
            % than a variable number of arguments
            
            rows = height(testCase.exampleTable.typesTable);
            cols = length(testCase.exampleTable.typesTable.Properties.VariableNames);

            % Row indices
            testCase.verifyError(@() testCase.exampleTable.setValue({0, 7, 'Added'}), '')
            testCase.verifyError(@() testCase.exampleTable.setValue({rows+1, 7, 'Added'}), '')

            % Column indices
            testCase.verifyError(@() testCase.exampleTable.setValue({1, 0, 'Added'}), '')
            testCase.verifyError(@() testCase.exampleTable.setValue({1, cols+1, 'Added'}), '')

            % Row name
            %
            % !!! THIS IS A BUG !!! 
            % This should raise an error for being an invalid row name but
            % instead does nothing
            %
            %testCase.verifyError(@() testCase.exampleTable.setValue({'Invalid Name', 7, 'Added'}), '')
            testCase.verifyEqual(testCase.exampleTable.setValue({'Invalid Name', 7, 'Added'}), testCase.exampleTable);

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
            % If we initialise with a cell array containing fewer than
            % three values it should raise an error
            testCase.verifyError(@() testCase.exampleTable.setValue({1}), 'MATLAB:badsubscript');
            testCase.verifyError(@() testCase.exampleTable.setValue({1, 1}), 'MATLAB:badsubscript');
        end

        function testAppendNewRow(testCase)
            newRow = {'New Row','constant','','','','',''};
            newTable = [testCase.exampleTable.typesTable; newRow];
            testCase.exampleTable.appendNewRow(newRow);

            testCase.verifyEqual(testCase.exampleTable.typesTable, newTable);
            testCase.verifyEqual(testCase.exampleTable.typesCount, height(testCase.exampleTable.typesTable));
            testCase.verifyEqual(testCase.exampleTable.typesAutoNameCounter, height(testCase.exampleTable.typesTable));
        end

        function testAppendNewRowDuplicateName(testCase)
            % Test that appending a new row with a duplicate name raises an
            % error
            newRow = {'Background D2O','constant','','','','',''};
            testCase.verifyError(@() testCase.exampleTable.appendNewRow(newRow), '');

            testCase.verifyEqual(testCase.exampleTable.typesCount, height(testCase.exampleTable.typesTable));
            testCase.verifyEqual(testCase.exampleTable.typesAutoNameCounter, height(testCase.exampleTable.typesTable));
        end







    end
end