classdef testLayersClass < matlab.unittest.TestCase
%%
% testLayersClass Class based unit tests for the layersClassRealSLD
% used within the Project Class in RAT.
%
% In this class, we test:
%
% We use an example layers class from example calculation
% "DPPC_standard_layers.m"
%
% Paul Sharp 03/02/23
%
%% Declare properties and parameters

    properties (TestParameter)
        % Cell arrays for initialising a multi type table
        layerInput = {{'empty'},...
                      {'empty named', {{'Named Layer'}}},...
                      {'full layer', {{'Oxide Names Layer',...
                                       'Oxide thick',...
                                       'Oxide SLD',...
                                       'Substrate Roughness'}}},...
                      {'full layer', {{'Water Names Layer',...
                                       'Water thick',...
                                       'Water SLD',...
                                       'Bilayer heads rough',...
                                       'Water hydr',...
                                       'bulk out'}}},...
                      {'full layer', {{'Oxide Indices Layer', 2, 3, 1}}},...
                      {'full layer', {{'Water Indices Layer',...
                                       13, 14, 8, 15,... 
                                       'bulk out'}}}
                       }
        addedLayer = {{'Layer 1','','','','','bulk out'},...
                      {'Named Layer','','','','','bulk out'},...
                      {'Oxide Names Layer',...
                       'Oxide thick',...
                       'Oxide SLD',...
                       'Substrate Roughness',...
                       NaN,...
                       'bulk in'},...
                      {'Water Names Layer',...
                       'Water thick',...
                       'Water SLD',...
                       'Bilayer heads rough',...
                       'Water hydr',...
                       'bulk out'},...
                      {'Oxide Indices Layer',...
                       'Oxide thick',...
                       'Oxide SLD',...
                       'Substrate Roughness',...
                       NaN,...
                       'bulk in'},...
                      {'Water Indices Layer',...
                       'Water thick',...
                       'Water SLD',...
                       'Bilayer heads rough',...
                       'Water hydr',...
                       'bulk out'}
                       }
        invalidOption = {'invalid option', 'Empty', 'EMPTY NAMED'}
    end

    properties
        exampleClass;           % Example layers class for testing
        initialLayersTable      % Empty table to compare to initialisation
        parameters              % Example parameters class used in "addLayer"
        numParams               % Number of parameters in the example class
        numRows                 % Number of rows in exampleClass.layersTable
        numCols                 % Number of columns in exampleClass.layersTable
    end

%% Set up test data

    methods (TestClassSetup)

        function initialiselayersTable(testCase)
            % Set up an empty layers table 
            sz = [0 6];
            tableTypes = {'string','string','string','string','string','string'};
            tableNames = {'Name','Thickness','SLD','Roughness','Hydration','Hydrate with'};

            testCase.initialLayersTable = table('Size',sz,'VariableTypes',tableTypes,'VariableNames',tableNames);
        end

        function initialiseParameters(testCase)
            % Set up an example parameters class. This example is used in
            % the example calculation "DPPC_standard_layers.m"
            testParams = {
                %       Name           min      val     max   fit? 'Prior Type' 'mu' 'sigma'
                'Substrate Roughness', 1,        3,       5,   true, 'uniform',  0,   Inf;
                'Oxide thick',         5,       20,      60,   true, 'uniform',  0,   Inf;
                'Oxide SLD',           3e-6,  3.41e-6,  4e-6, false, 'uniform',  0,   Inf;
                'Oxide Hydration'      0,       20,      30,   true, 'uniform',  0,   Inf;
                'Bilayer heads thick', 5,       10,      15,   true, 'uniform',  0,   Inf;
                'Bilayer heads SLD',   1e-6,  1.47e-6,  3e-6,  true, 'uniform',  0,   Inf;
                'Bilayer heads hydr',  20,      30,      50,   true, 'uniform',  0,   Inf;
                'Bilayer heads rough'  5,        7,      15,   true, 'uniform',  0,   Inf;
                'Bilayer tails thick', 10,      10,      20,   true, 'uniform',  0,   Inf;
                'Bilayer tails SLD',   -5e-7, -4e-7,   -1e-7, false, 'uniform',  0,   Inf;
                'Bilayer tails hydr',  0,       10,      20,   true, 'uniform',  0,   Inf;
                'Bilayer tails rough', 5,        9,      15,   true, 'uniform',  0,   Inf;
                'Water thick',         0,        1,      15,   true, 'uniform',  0,   Inf;
                'Water SLD',           0,        0,       0,  false, 'uniform',  0,   Inf;
                'Water hydr',          100,    100,     100,  false, 'uniform',  0,   Inf;
                };

            testCase.parameters = parametersClass(testParams(1, :));
            testCase.parameters.paramsTable = [testCase.parameters.paramsTable; vertcat(testParams(2:end, :))];
            testCase.numRows = length(testParams);
        end

    end

    methods (TestMethodSetup)

        function initialiseLayersClass(testCase)
            % Set up an example layers class for testing
            % This example is used in the example calculation
            % "DPPC_standard_layers.m"
            testCase.exampleClass = layersClassRealSLD();

            %testCase.exampleClass.layersTable(1,:) = {'Oxide Layer', 'Oxide thick', 'Oxide SLD', 'Substrate Roughness', 'Oxide Hydration', 'bulk out'};
            %testCase.exampleClass.layersTable(2,:) = {'Water Layer', 'Water thick', 'Water SLD', 'Bilayer heads rough', 'Water hydr', 'bulk out'};
            testCase.exampleClass.layersTable(1,:) = {'Bil inner head', 'Bilayer heads thick', 'Bilayer heads SLD', 'Bilayer heads rough', 'Bilayer heads hydr', 'bulk out'};
            testCase.exampleClass.layersTable(2,:) = {'Bil tail', 'Bilayer tails thick', 'Bilayer tails SLD', 'Bilayer heads rough', 'Bilayer tails hydr', 'bulk out'};
            testCase.exampleClass.layersTable(3,:) = {'Bil outer head', 'Bilayer heads thick', 'Bilayer heads SLD', 'Bilayer heads rough', 'Bilayer heads hydr', 'bulk out'};

            testCase.numRows = height(testCase.exampleClass.layersTable);
            testCase.numCols = width(testCase.exampleClass.layersTable);
        end

    end

%% Test Layers Real SLD Class Routines

    methods (Test, ParameterCombination="sequential")

        function testInitialiseLayersClass(testCase)
            % On initialisation we set up a layers class with an empty
            % layers table
            testClass = layersClassRealSLD();

            testCase.verifySize(testClass.layersTable, [0 6], "layerClassRealSLD does not initialise correctly");
            testCase.verifyEqual(testClass.layersTable, testCase.initialLayersTable, "layerClassRealSLD does not initialise correctly");
        end

        function testAddLayer(testCase, layerInput, addedLayer)
            % Test adding a layer to the layers class.
            % We can add a layer with no parameters, just a layer name, or
            % a fully defined layer.
            % The first parameter should be either "empty", "empty named",
            % or "full layer" to determine how many parameters will then be
            % specified: none for "empty", one for "empty named", and
            % either a length four or length six cell array for "full
            % layer"             
            expectedTable = [testCase.exampleClass.layersTable; addedLayer];

            testCase.exampleClass.addLayer(layerInput, testCase.parameters.paramsTable);

            testCase.verifyEqual(testCase.exampleClass.layersTable, expectedTable, "addLayer does not work correctly");
        end

        function testAddRowInvalidOption(testCase, invalidOption)
            % Test adding a layer to the layers class.
            % If we use an invalid option the code does nothing.
            % !!!! THIS IS A BUG - it should raise an error !!!!
            testCase.exampleClass.addLayer({invalidOption}, testCase.parameters.paramsTable);
            testCase.verifySize(testCase.exampleClass.layersTable, [testCase.numRows testCase.numCols], "Layer table parameters have changed despite no rows being added");
        end

        function testAddRowInvalidNamedLayer(testCase)
            % Test adding a layer to the layers class.
            % If we use an invalid input for the layer name it should
            % raise an error
            testCase.verifyError(@() testCase.exampleClass.addLayer({'empty named', {{'Named Layer', 'extra param'}}}), 'MATLAB:table:vertcat:VertcatMethodFailed');
        end

        function testAddRowInvalidFullLayer(testCase)
            % Test adding a layer to the layers class.
            % If we use an invalid set of layer parameters when adding a
            % "full layer" it should raise an error

            % Invalid length for full layer parameters
            testCase.verifyError(@() testCase.exampleClass.addLayer({'full layer', {{'Incomplete Oxide', 2}}}, testCase.parameters.paramsTable), ?MException)
            testCase.verifyError(@() testCase.exampleClass.addLayer({'full layer', {{'Incomplete Oxide', 2, 3}}}, testCase.parameters.paramsTable), ?MException)
            testCase.verifyError(@() testCase.exampleClass.addLayer({'full layer', {{'Incomplete Oxide', 2, 3, 1, 4}}}, testCase.parameters.paramsTable), ?MException)
            testCase.verifyError(@() testCase.exampleClass.addLayer({'full layer', {{'Incomplete Oxide', 2, 3, 1, 4, 'none', 5}}}, testCase.parameters.paramsTable), ?MException)

            % Invalid hydrate type
            testCase.verifyError(@() testCase.exampleClass.addLayer({'full layer', {{'Oxide Layer', 2, 3, 1, 4, 'surface'}}}, testCase.parameters.paramsTable), ?MException)

            % Invalid parameter names
            testCase.verifyError(@() testCase.exampleClass.addLayer({'full layer', {{'Oxide Layer','Substrate thick','Substrate SLD','Substrate Roughness'}}}, testCase.parameters.paramsTable), ?MException)

            % Invalid parameter indices
            testCase.verifyError(@() testCase.exampleClass.addLayer({'full layer', {{'Oxide Layer', 2, 3, 0}}}, testCase.parameters.paramsTable), ?MException)
            testCase.verifyError(@() testCase.exampleClass.addLayer({'full layer', {{'Oxide Layer', 2, 3, testCase.numParams+1}}}, testCase.parameters.paramsTable), ?MException)
            testCase.verifyError(@() testCase.exampleClass.addLayer({'full layer', {{'Oxide Layer', NaN ,3, 0}}}, testCase.parameters.paramsTable), ?MException)
            testCase.verifyError(@() testCase.exampleClass.addLayer({'full layer', {{'Oxide Layer', 2, NaN, 0}}}, testCase.parameters.paramsTable), ?MException)
            testCase.verifyError(@() testCase.exampleClass.addLayer({'full layer', {{'Oxide Layer', 2, 3, NaN}}}, testCase.parameters.paramsTable), ?MException)          
        end

        function testSetLayerValue(testCase)
            % Test setting values in the layers class table using both
            % names and indices to refer to rows. Columns can be referred
            % to only by index.
            % Note that the routine requires a single cell array rather
            % than a variable number of arguments.

            % Row and column indices
            testCase.exampleClass.setLayerValue({1, 5, 'Changed'});
            expectedRow = ["Bil inner head", "Bilayer heads thick", "Bilayer heads SLD", "Bilayer heads rough", "Changed", "bulk out"];
            testCase.verifyEqual(testCase.exampleClass.layersTable{1, :}, expectedRow, "setValue does not work correctly");

            % Row name and column index
            testCase.exampleClass.setLayerValue({'Bil Tail', 3, 'Changed'});
            expectedRow = ["Bil tail", "Bilayer tails thick", "Changed", "Bilayer heads rough", "Bilayer tails hydr", "bulk out"];
            testCase.verifyEqual(testCase.exampleClass.layersTable{2, :}, expectedRow, "setValue does not work correctly");

            % Change hydration type
            testCase.exampleClass.setLayerValue({3, 6, 'bulk in'});
            expectedRow = ["Bil outer head", "Bilayer heads thick", "Bilayer heads SLD", "Bilayer heads rough", "Bilayer heads hydr", "bulk in"];
            testCase.verifyEqual(testCase.exampleClass.layersTable{3, :}, expectedRow, "setValue does not work correctly");
        end

        function testSetLayerValueInvalid(testCase)
            % Test setting values in the layers class table using invalid
            % values of both names and indices to refer to rows and columns
            % Note that the routine requires a single cell array rather
            % than a variable number of arguments

            % Row indices
            testCase.verifyError(@() testCase.exampleClass.setValue({0, testCase.numCols, 'Changed'}), ?MException)
            testCase.verifyError(@() testCase.exampleClass.setValue({testCase.numRows+1, testCase.numCols, 'Changed'}), ?MException)

            % Column indices
            testCase.verifyError(@() testCase.exampleClass.setValue({1, 0, 'Changed'}), ?MException)
            testCase.verifyError(@() testCase.exampleClass.setValue({1, 1, 'Changed'}), ?MException)
            testCase.verifyError(@() testCase.exampleClass.setValue({1, testCase.numCols+1, 'Changed'}), ?MException)

            % Row name
            testCase.verifyError(@() testCase.exampleClass.setValue({'Invalid Name', testCase.numCols, 'none'}), ?MException)

            % Column name - not accepted whether valid or not
            testCase.verifyError(@() testCase.exampleClass.setValue({1, 'SLD', 'Changed'}), ?MException)
            testCase.verifyError(@() testCase.exampleClass.setValue({1, 'Invalid Name', 'Changed'}), ?MException)

            % Invalid data types
            testCase.verifyError(@() testCase.exampleClass.setValue({testCase.initialLayersTable, testCase.numCols, 'Changed'}), ?MException)
            testCase.verifyError(@() testCase.exampleClass.setValue({1, datetime('today'), 'Changed'}), ?MException)
        end

        function testSetLayerValueTooFewParams(testCase)
            % If we call "setLayerValue" with a cell array containing
            % fewer than three values it should raise an error
            testCase.verifyError(@() testCase.exampleClass.setLayerValue({1}), 'MATLAB:badsubscript');
            testCase.verifyError(@() testCase.exampleClass.setLayerValue({1, 6}), 'MATLAB:badsubscript');
        end

        function testGetLayersNames(testCase)
            layersNames = testCase.exampleClass.layersTable{:,1};
            testCase.verifyEqual(testCase.exampleClass.getLayersNames(), layersNames)
        end

        function testtoStruct(testCase)
            testCase.verifyEqual(testCase.exampleClass.toStruct(), string(testCase.exampleClass.layersTable{:,:}))
        end

        function testDisplayLayersTable(testCase)
            % Test the routine to display the layers table by capturing
            % the output and comparing with the table headers and data 

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display = textscan(evalc('testCase.exampleClass.displayLayersTable()'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};

            % Check headers
            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove "<strong>" tags
            outVars = eraseBetween(strip(regexprep(displayedTable(1), '\s+', ' ')), '<', '>','Boundaries','inclusive');

            % Convert table variable names to a string array, join into a
            % single string, and then prepend an extra header used for the
            % row index
            varString = "p " + strip(strjoin(string(testCase.exampleClass.layersTable.Properties.VariableNames)));
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
                rowString = string(i) + " " + strip(strjoin(strcat('"',testCase.exampleClass.layersTable{i,:},'"')));
                testCase.verifyEqual(outRow, rowString, "Row does not contain the correct data");

            end

        end

        function testDisplayLayersTableEmpty(testCase)
            % Test the routine to display the layers table of an empty
            % layers class by capturing the output and comparing with the
            % table headers and data
            emptyClass = layersClassRealSLD();

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display = textscan(evalc('emptyClass.displayLayersTable()'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};

            % Check headers
            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove "<strong>" tags
            outVars = eraseBetween(strip(regexprep(displayedTable(1), '\s+', ' ')), '<', '>','Boundaries','inclusive');

            % Convert table variable names to a string array, join into a
            % single string, and then prepend an extra header used for the
            % row index
            varString = strip(strjoin(string(emptyClass.layersTable.Properties.VariableNames)));
            testCase.verifyEqual(outVars, varString, 'Table headers do not match variable names');

            % Make sure the output has the right number of rows before
            % continuing
            testCase.assertSize(displayedTable, [3, 1], 'Table does not have the right number of rows');

            % Replace multiple spaces in output table with a single
            % space using regular expressions
            outRow = strip(regexprep(displayedTable(3), '\s+', ' '));
            rowString = "0 0 0 0 0 0";
            testCase.verifyEqual(outRow, rowString, "Row does not contain the correct data");

        end

        function testFindRowIndex(testCase)
            % Test that the correct row number is returned for a valid row,
            % and an error is raised for invalid options
            tableRows = testCase.exampleClass.layersTable{:,1};

            testCase.verifyEqual(multiTypeTable.findRowIndex("Bil Tail", tableRows), 2);

            % Check whitespace still matches
            testCase.verifyEqual(multiTypeTable.findRowIndex(" Bil Inner Head", tableRows), 1);

            testCase.verifyError(@() multiTypeTable.findRowIndex("Invalid Row", tableRows), ?MException)
            testCase.verifyError(@() multiTypeTable.findRowIndex("Thickness", tableRows), ?MException)
        end

    end

end