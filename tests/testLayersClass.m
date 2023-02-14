classdef testLayersClass < matlab.unittest.TestCase
%%
% testLayersClass Class based unit tests for the layersClassRealSLD
% used within the Project Class in RAT.
%
% In this class, we test:
% layersClassRealSLD, addLayer, setLayerValue, removeLayer,
% getLayersNames, toStruct, displayLayersTable, findRowIndex, findParameter
%
% We use an example layers class from example calculation
% "DPPC_standard_layers.m"
%
% Paul Sharp 08/02/23
%
%% Declare properties and parameters

    properties (TestParameter)
        % Cell arrays for adding layers
        layerInput = {'Named Layer',...
                      {'Oxide Names Layer',...
                        'Oxide thick',...
                        'Oxide SLD',...
                        'Substrate Roughness'},...
                      {'Water Names Layer',...
                        'Water thick',...
                        'Water SLD',...
                        'Bilayer heads rough',...
                        'Water hydr',...
                        'bulk out'},...
                      {'Oxide Indices Layer', 2, 3, 1},...
                      {'Water Indices Layer', 13, 14, 8, 15, 'bulk out'}
                       }
        addedLayer = {{'Named Layer','','','','','bulk out'},...
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
    end

    properties
        exampleClass            % Example layers class for testing
        initialLayersTable      % Empty table to compare to initialisation
        parameters              % Example parameters class used in "addLayer"
        parameterNames          % Names of parameters inthe example class
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

            testCase.parameterNames = testCase.parameters.paramsTable{:, 1};
            testCase.numParams = length(testParams);
        end

    end

    methods (TestMethodSetup)

        function initialiseLayersClass(testCase)
            % Set up an example layers class for testing
            % This example is used in the example calculation
            % "DPPC_standard_layers.m"
            testCase.exampleClass = layersClassRealSLD();

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
            % a fully defined layer, which consists of either a length
            % four or length six cell array     
            expectedTable = [testCase.exampleClass.layersTable; addedLayer];

            testCase.exampleClass.addLayer(testCase.parameterNames, layerInput);

            testCase.verifyEqual(testCase.exampleClass.layersTable, expectedTable, "addLayer does not work correctly");
        end

        function testAddLayerEmpty(testCase)
            % Test adding a layer to the layers class, with no input
            % parameters.
            % We can add a layer with no parameters, just a layer name, or
            % a fully defined layer, which consists of either a length
            % four or length six cell array
            newLayer = {'Layer 1','','','','','bulk out'};
            expectedTable = [testCase.exampleClass.layersTable; newLayer];

            testCase.exampleClass.addLayer(testCase.parameterNames);

            testCase.verifyEqual(testCase.exampleClass.layersTable, expectedTable, "addLayer does not work correctly");
        end

        function testAddLayerInvalidFullLayer(testCase)
            % Test adding a layer to the layers class.
            % If we use an invalid set of layer parameters it should raise
            % an error

            % Invalid length for layer parameters
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, {'Incomplete Oxide', 2}), invalidNumberOfInputs.errorID);
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, {'Incomplete Oxide', 2, 3}), invalidNumberOfInputs.errorID);
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, {'Incomplete Oxide', 2, 3, 1, 4}), invalidNumberOfInputs.errorID);
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, {'Incomplete Oxide', 2, 3, 1, 4, 'none', 5}), invalidNumberOfInputs.errorID);

            % Invalid hydrate type
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, {'Oxide Layer', 2, 3, 1, 4, 'surface'}), invalidOption.errorID);

            % Invalid parameter names
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, {'Oxide Layer','Substrate thick','Substrate SLD','Substrate Roughness'}), nameNotRecognised.errorID);

            % Duplicate layer names
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, {'Bil inner head', 'Bilayer heads thick', 'Bilayer heads SLD', 'Bilayer heads rough', 'Bilayer heads hydr', 'bulk out'}), duplicateName.errorID);

            % Invalid parameter indices
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, {'Oxide Layer', 2, 3, 0}), indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, {'Oxide Layer', 2, 3, testCase.numParams+1}), indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, {'Oxide Layer', NaN ,3, 0}), 'MATLAB:badsubscript');
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, {'Oxide Layer', 2, NaN, 0}), 'MATLAB:badsubscript');
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, {'Oxide Layer', 2, 3, NaN}), 'MATLAB:badsubscript');         
        end

        function testSetLayerValue(testCase)
            % Test setting values in the layers class table using both
            % names and indices to refer to rows and columns.

            % Row and column indices
            testCase.exampleClass.setLayerValue(1, 5, 'Water hydr', testCase.parameterNames);
            expectedRow = ["Bil inner head", "Bilayer heads thick", "Bilayer heads SLD", "Bilayer heads rough", "Water hydr", "bulk out"];
            testCase.verifyEqual(testCase.exampleClass.layersTable{1, :}, expectedRow, "setValue does not work correctly");

            % Row name and column index
            testCase.exampleClass.setLayerValue('Bil Tail', 3, 'Water SLD', testCase.parameterNames);
            expectedRow = ["Bil tail", "Bilayer tails thick", "Water SLD", "Bilayer heads rough", "Bilayer tails hydr", "bulk out"];
            testCase.verifyEqual(testCase.exampleClass.layersTable{2, :}, expectedRow, "setValue does not work correctly");

            % Row index and column name
            testCase.exampleClass.setLayerValue(1, 'Roughness', 'Substrate Roughness', testCase.parameterNames);
            expectedRow = ["Bil inner head", "Bilayer heads thick", "Bilayer heads SLD", "Substrate Roughness", "Water hydr", "bulk out"];
            testCase.verifyEqual(testCase.exampleClass.layersTable{1, :}, expectedRow, "setValue does not work correctly");

            % Row and column names
            testCase.exampleClass.setLayerValue('Bil Tail', 'Thickness', 'Water thick', testCase.parameterNames);
            expectedRow = ["Bil tail", "Water thick", "Water SLD", "Bilayer heads rough", "Bilayer tails hydr", "bulk out"];
            testCase.verifyEqual(testCase.exampleClass.layersTable{2, :}, expectedRow, "setValue does not work correctly");

            % Change hydration type
            testCase.exampleClass.setLayerValue(3, 6, 'bulk in', testCase.parameterNames);
            expectedRow = ["Bil outer head", "Bilayer heads thick", "Bilayer heads SLD", "Bilayer heads rough", "Bilayer heads hydr", "bulk in"];
            testCase.verifyEqual(testCase.exampleClass.layersTable{3, :}, expectedRow, "setValue does not work correctly");
        end

        function testSetLayerValueInvalid(testCase)
            % Test setting values in the layers class table using invalid
            % values of both names and indices to refer to rows and columns

            % Row indices
            testCase.verifyError(@() testCase.exampleClass.setLayerValue(0, testCase.numCols, 'Substrate Roughness', testCase.parameterNames), indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleClass.setLayerValue(testCase.numRows+1, testCase.numCols, 'Substrate Roughness', testCase.parameterNames), indexOutOfRange.errorID);

            % Column indices
            testCase.verifyError(@() testCase.exampleClass.setLayerValue(1, 0, 'Substrate Roughness', testCase.parameterNames), indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleClass.setLayerValue(1, 1, 'Changed', testCase.parameterNames), indexOutOfRange.errorID); % Can't change name
            testCase.verifyError(@() testCase.exampleClass.setLayerValue(1, testCase.numCols+1, 'Substrate Roughness', testCase.parameterNames), indexOutOfRange.errorID);

            % Row name
            testCase.verifyError(@() testCase.exampleClass.setLayerValue('Invalid Name', testCase.numCols, 'Substrate Roughness', testCase.parameterNames), nameNotRecognised.errorID);

            % Column name
            testCase.verifyError(@() testCase.exampleClass.setLayerValue(1, 'Invalid Name', 'Substrate Roughness', testCase.parameterNames), nameNotRecognised.errorID);

            % Invalid hydrate type
            testCase.verifyError(@() testCase.exampleClass.setLayerValue(1, 6, 'Invalid hydrate', testCase.parameterNames), invalidOption.errorID);

            % Float values within range
            testCase.verifyError(@() testCase.exampleClass.setLayerValue(3, 2.5, 'Substrate Roughness', testCase.parameterNames), 'MATLAB:badsubscript');
            testCase.verifyError(@() testCase.exampleClass.setLayerValue(2.5, 3, 'Substrate Roughness', testCase.parameterNames), 'MATLAB:badsubscript');
            
            % Invalid data types
            testCase.verifyError(@() testCase.exampleClass.setLayerValue(testCase.initialLayersTable, testCase.numCols, 'Substrate Roughness', testCase.parameterNames), invalidType.errorID);
            testCase.verifyError(@() testCase.exampleClass.setLayerValue(1, datetime('today'), 'Substrate Roughness', testCase.parameterNames), invalidType.errorID);
        end

        function testRemoveLayer(testCase)
            % Note that the routine requires a single cell array as input
            remainingRows = testCase.exampleClass.layersTable(2:end,:);
            testCase.exampleClass.removeLayer(1);

            testCase.verifyEqual(testCase.exampleClass.layersTable, remainingRows, "removeLayer does not work correctly");
        end

        function testRemoveLayerMultiple(testCase)
            % Test removing multiple rows from a layers table
            % Note that the routine requires a single cell array as input
            remainingRows = testCase.exampleClass.layersTable(2,:);
            testCase.exampleClass.removeLayer([1 3]);

            testCase.verifyEqual(testCase.exampleClass.layersTable, remainingRows, "removeLayer does not work correctly");
        end

        function testGetLayersNames(testCase)
            testCase.verifyEqual(testCase.exampleClass.getLayersNames(), testCase.exampleClass.layersTable{:,1});
        end

        function testToStruct(testCase)
            testCase.verifyEqual(testCase.exampleClass.toStruct(), string(testCase.exampleClass.layersTable{:,:}));
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
                rowString = string(i) + " " + strip(strjoin(testCase.exampleClass.layersTable{i,:}));
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
            tableRows = testCase.exampleClass.layersTable{:, 1};

            testCase.verifyEqual(layersClassRealSLD.findRowIndex("Bil Tail", tableRows), 2);

            % Check whitespace still matches
            testCase.verifyEqual(layersClassRealSLD.findRowIndex(" Bil Inner Head", tableRows), 1);

            testCase.verifyError(@() layersClassRealSLD.findRowIndex("Invalid Row", tableRows), nameNotRecognised.errorID);
            testCase.verifyError(@() layersClassRealSLD.findRowIndex("Thickness", tableRows), nameNotRecognised.errorID);
        end

        function testFindParameter(testCase)
            % Test that the correct parameter is returned for a valid
            % input name or index, and an error is raised for invalid options
            outParam = layersClassRealSLD.findParameter('Oxide Hydration', testCase.parameterNames);
            testCase.verifyEqual(outParam, 'Oxide Hydration');

            outParam = layersClassRealSLD.findParameter(10, testCase.parameterNames);
            testCase.verifyEqual(outParam, 'Bilayer tails SLD');

            testCase.verifyError(@() layersClassRealSLD.findParameter('Invalid Param', testCase.parameterNames), nameNotRecognised.errorID);
            testCase.verifyError(@() layersClassRealSLD.findParameter(0, testCase.parameterNames), indexOutOfRange.errorID);
            testCase.verifyError(@() layersClassRealSLD.findParameter(testCase.numParams+1, testCase.parameterNames), indexOutOfRange.errorID);
            testCase.verifyError(@() layersClassRealSLD.findParameter(datetime('today'), testCase.parameterNames), invalidType.errorID);
        end


    end

end