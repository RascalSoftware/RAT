classdef testLayersClass < matlab.unittest.TestCase
%%
% testLayersClass Class based unit tests for the layersClass
% used within the Project Class in RAT.
%
% We use an example layers class from example calculation
% "DPPCStandardLayers.m"
%
% Paul Sharp 03/07/23
%
%% Declare properties and parameters

    properties (TestParameter)
        % Cell arrays for adding layers
        layerInput = {{'Oxide Names Layer',...
                        'OXIDE THICK',...
                        'Oxide SLD',...
                        'Substrate Roughness'},...
                      {'Water Names Layer',...
                        'Water thick',...
                        'Water SLD',...
                        'Bilayer heads rough',...
                        'Water hydr',...
                        hydrationTypes.BulkOut.value},...
                      {'Oxide Indices Layer', 2, 3, 1},...
                      {'Water Indices Layer', 13, 14, 8, 15, hydrationTypes.BulkOut.value}
                       }
        addedLayer = {{'Oxide Names Layer',...
                       'Oxide thick',...
                       'Oxide SLD',...
                       'Substrate Roughness',...
                       '',...
                       hydrationTypes.BulkOut.value},...
                      {'Water Names Layer',...
                       'Water thick',...
                       'Water SLD',...
                       'Bilayer heads rough',...
                       'Water hydr',...
                       hydrationTypes.BulkOut.value},...
                      {'Oxide Indices Layer',...
                       'Oxide thick',...
                       'Oxide SLD',...
                       'Substrate Roughness',...
                       '',...
                       hydrationTypes.BulkOut.value},...
                      {'Water Indices Layer',...
                       'Water thick',...
                       'Water SLD',...
                       'Bilayer heads rough',...
                       'Water hydr',...
                       hydrationTypes.BulkOut.value}
                       }
    end

    properties
        exampleClass            % Example layers class for testing
        initialLayersTable      % Empty table to compare to initialisation
        initialAbsorptionTable  % Empty table for an absorption problem to compare to initialisation
        parameters              % Example parameters class used in "addLayer"
        parameterNames          % Names of parameters in the example class
        numParams               % Number of parameters in the example class
        numRows                 % Number of rows in exampleClass.varTable
        numCols                 % Number of columns in exampleClass.varTable
    end

%% Set up test data

    methods (TestClassSetup)

        function initialiseVarTables(testCase)
            % Set up an empty layers table 
            sz = [0 6];
            tableTypes = {'string','string','string','string','string','string'};
            tableNames = {'Name','Thickness','SLD','Roughness','Hydration','Hydrate with'};

            testCase.initialLayersTable = table('Size',sz,'VariableTypes',tableTypes,'VariableNames',tableNames);

            sz = [0 7];
            tableTypes = {'string','string','string','string','string','string','string'};
            tableNames = {'Name','Thickness','SLDReal', 'SLDImag','Roughness','Hydration','Hydrate with'};

            testCase.initialAbsorptionTable = table('Size',sz,'VariableTypes',tableTypes,'VariableNames',tableNames);
        end

        function initialiseParameters(testCase)
            % Set up an example parameters class. This example is used in
            % the example calculation "DPPCStandardLayers.m"
            testParams = {
                %       Name           min      val     max   fit? 'Prior Type' 'mu' 'sigma'
                'Substrate Roughness', 1,        3,       5,   true, priorTypes.Uniform.value,  0,   Inf;
                'Oxide thick',         5,       20,      60,   true, priorTypes.Uniform.value,  0,   Inf;
                'Oxide SLD',           3e-6,  3.41e-6,  4e-6, false, priorTypes.Uniform.value,  0,   Inf;
                'Oxide Hydration'      0,       20,      30,   true, priorTypes.Uniform.value,  0,   Inf;
                'Bilayer heads thick', 5,       10,      15,   true, priorTypes.Uniform.value,  0,   Inf;
                'Bilayer heads SLD',   1e-6,  1.47e-6,  3e-6,  true, priorTypes.Uniform.value,  0,   Inf;
                'Bilayer heads hydr',  20,      30,      50,   true, priorTypes.Uniform.value,  0,   Inf;
                'Bilayer heads rough'  5,        7,      15,   true, priorTypes.Uniform.value,  0,   Inf;
                'Bilayer tails thick', 10,      10,      20,   true, priorTypes.Uniform.value,  0,   Inf;
                'Bilayer tails SLD',   -5e-7, -4e-7,   -1e-7, false, priorTypes.Uniform.value,  0,   Inf;
                'Bilayer tails hydr',  0,       10,      20,   true, priorTypes.Uniform.value,  0,   Inf;
                'Bilayer tails rough', 5,        9,      15,   true, priorTypes.Uniform.value,  0,   Inf;
                'Water thick',         0,        1,      15,   true, priorTypes.Uniform.value,  0,   Inf;
                'Water SLD',           0,        0,       0,  false, priorTypes.Uniform.value,  0,   Inf;
                'Water hydr',          100,    100,     100,  false, priorTypes.Uniform.value,  0,   Inf;
                };

            testCase.parameters = parametersClass(testParams{1, :});
            testCase.parameters.varTable = [testCase.parameters.varTable; vertcat(testParams(2:end, :))];

            testCase.parameterNames = testCase.parameters.varTable{:, 1};
            testCase.numParams = length(testParams);
        end

    end

    methods (TestMethodSetup)

        function initialiseLayersClass(testCase)
            % Set up an example layers class for testing
            % This example is used in the example calculation
            % "DPPCStandardLayers.m"
            testCase.exampleClass = layersClass();

            testCase.exampleClass.varTable(1,:) = {'Bil inner head', 'Bilayer heads thick', 'Bilayer heads SLD', 'Bilayer heads rough', 'Bilayer heads hydr', hydrationTypes.BulkOut.value};
            testCase.exampleClass.varTable(2,:) = {'Bil tail', 'Bilayer tails thick', 'Bilayer tails SLD', 'Bilayer tails rough', 'Bilayer tails hydr', hydrationTypes.BulkOut.value};
            testCase.exampleClass.varTable(3,:) = {'Bil outer head', 'Bilayer heads thick', 'Bilayer heads SLD', 'Bilayer heads rough', 'Bilayer heads hydr', hydrationTypes.BulkOut.value};

            testCase.numRows = height(testCase.exampleClass.varTable);
            testCase.numCols = width(testCase.exampleClass.varTable);
        end

    end

%% Test Layers Real SLD Class Routines

    methods (Test, ParameterCombination='sequential')

        function testInitialiseLayersClass(testCase)
            % On initialisation we set up a layers class with an empty
            % layers table
            testClass = layersClass();

            testCase.verifySize(testClass.varTable, [0 6], 'layersClass does not initialise correctly');
            testCase.verifyEqual(testClass.varTable, testCase.initialLayersTable, 'layersClass does not initialise correctly');

            % Adding the optional argument should give the same table
            testClass = layersClass();

            testCase.verifySize(testClass.varTable, [0 6], 'layersClass does not initialise correctly');
            testCase.verifyEqual(testClass.varTable, testCase.initialLayersTable, 'layersClass does not initialise correctly');
        end

        function testAddLayer(testCase, layerInput, addedLayer)
            % Test adding a layer to the layers class.
            % We can add a layer with no parameters, just a layer name, or
            % a fully defined layer, which consists of either a length
            % four or length six cell array     
            expectedTable = [testCase.exampleClass.varTable; addedLayer];

            testCase.exampleClass.addLayer(testCase.parameterNames, layerInput{:});

            testCase.verifyEqual(testCase.exampleClass.varTable, expectedTable, 'addLayer does not work correctly');
        end

        function testAddLayerInvalidFullLayer(testCase)
            % Test adding a layer to the layers class.
            % If we use an invalid set of layer parameters it should raise
            % an error

            % Invalid length for layer parameters
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, 'Incomplete Oxide', 2), exceptions.invalidNumberOfInputs.errorID);
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, 'Incomplete Oxide', 2, 3), exceptions.invalidNumberOfInputs.errorID);
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, 'Incomplete Oxide', 2, 3, 1, 4), exceptions.invalidNumberOfInputs.errorID);
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, 'Incomplete Oxide', 2, 3, 1, 4, hydrationTypes.BulkIn.value, 5), exceptions.invalidNumberOfInputs.errorID);

            % Invalid hydrate type
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, 'Oxide Layer', 2, 3, 1, 4, 'surface'), exceptions.invalidOption.errorID);

            % Invalid parameter names
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, 'Oxide Layer','Substrate thick','Substrate SLD','Substrate Roughness'), exceptions.nameNotRecognised.errorID);

            % Duplicate layer names
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, 'Bil inner head', 'Bilayer heads thick', 'Bilayer heads SLD', 'Bilayer heads rough', 'Bilayer heads hydr', hydrationTypes.BulkOut.value), exceptions.duplicateName.errorID);

            % Invalid parameter indices
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, 'Oxide Layer', 2, 3, 0), exceptions.indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, 'Oxide Layer', 2, 3, testCase.numParams+1), exceptions.indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, 'Oxide Layer', NaN ,3, 0), exceptions.invalidType.errorID);
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, 'Oxide Layer', 2, NaN, 0), exceptions.invalidType.errorID);
            testCase.verifyError(@() testCase.exampleClass.addLayer(testCase.parameterNames, 'Oxide Layer', 2, 3, NaN), exceptions.invalidType.errorID);         
        end

        function testSetLayer(testCase)
            % Test setting values in the layers class table using both
            % names and indices to refer to rows and columns.

            % Row and column indices
            testCase.exampleClass.setLayer(1, testCase.parameterNames, 'hydration', 'Water hydr');
            expectedRow = ["Bil inner head", "Bilayer heads thick", "Bilayer heads SLD", "Bilayer heads rough", "Water hydr", "bulk out"];
            testCase.verifyEqual(testCase.exampleClass.varTable{1, :}, expectedRow, 'setValue does not work correctly');

            % Row name and column index
            testCase.exampleClass.setLayer('Bil Tail', testCase.parameterNames, 'sld', 'Water SLD');
            expectedRow = ["Bil tail", "Bilayer tails thick", "Water SLD", "Bilayer tails rough", "Bilayer tails hydr", "bulk out"];
            testCase.verifyEqual(testCase.exampleClass.varTable{2, :}, expectedRow, 'setValue does not work correctly');

            % Row index and column name
            testCase.exampleClass.setLayer(1, testCase.parameterNames, 'roughness', 'Substrate Roughness');
            expectedRow = ["Bil inner head", "Bilayer heads thick", "Bilayer heads SLD", "Substrate Roughness", "Water hydr", "bulk out"];
            testCase.verifyEqual(testCase.exampleClass.varTable{1, :}, expectedRow, 'setValue does not work correctly');

            % Row and column names
            testCase.exampleClass.setLayer('Bil Tail', testCase.parameterNames, 'thickness', 'Water thick');
            expectedRow = ["Bil tail", "Water thick", "Water SLD", "Bilayer tails rough", "Bilayer tails hydr", "bulk out"];
            testCase.verifyEqual(testCase.exampleClass.varTable{2, :}, expectedRow, 'setValue does not work correctly');

            % Change hydration type
            testCase.exampleClass.setLayer(3, testCase.parameterNames, 'hydrateWith', hydrationTypes.BulkIn.value);
            expectedRow = ["Bil outer head", "Bilayer heads thick", "Bilayer heads SLD", "Bilayer heads rough", "Bilayer heads hydr", "bulk in"];
            testCase.verifyEqual(testCase.exampleClass.varTable{3, :}, expectedRow, 'setValue does not work correctly');
            
            testCase.exampleClass.absorption = true;
            testCase.exampleClass.setLayer(3, testCase.parameterNames, 'name', 'New Layer', 'realSLD', 'Water SLD', 'imaginarySLD', 'Bilayer heads SLD', 'hydrateWith', hydrationTypes.BulkIn.value);
            testCase.verifyEqual(testCase.exampleClass.varTable{3, :}, ["New Layer", "Bilayer heads thick", "Water SLD", "Bilayer heads SLD", ...
                                                                        "Bilayer heads rough", "Bilayer heads hydr", "bulk in"], 'setValue does not work correctly');

            testCase.exampleClass.setLayer(3, testCase.parameterNames, 'name', 'Another Layer');
            testCase.verifyEqual(testCase.exampleClass.varTable{3, 1}, "Another Layer", 'setValue does not work correctly');
        end

        function testSetLayerInvalid(testCase)
            % Test setting values in the layers class table using invalid
            % values of both names and indices to refer to rows and columns

            % Row indices
            testCase.verifyError(@() testCase.exampleClass.setLayer(0, testCase.parameterNames, 'roughness', 'Substrate Roughness'), exceptions.indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleClass.setLayer(testCase.numRows+1, testCase.parameterNames, 'roughness', 'Substrate Roughness'), exceptions.indexOutOfRange.errorID);

            % Row name
            testCase.verifyError(@() testCase.exampleClass.setLayer('Invalid Name', testCase.parameterNames, 'roughness', 'Substrate Roughness'), exceptions.nameNotRecognised.errorID);

            % Invalid hydrate type
            testCase.verifyError(@() testCase.exampleClass.setLayer(1, testCase.parameterNames, 'hydrateWith', 'Invalid hydrate'), exceptions.invalidOption.errorID);
            % float index
            testCase.verifyError(@() testCase.exampleClass.setLayer(2.5, testCase.parameterNames, 'roughness', 'Substrate Roughness'), exceptions.invalidType.errorID);
            
            % Invalid data types
            testCase.verifyError(@() testCase.exampleClass.setLayer(testCase.initialLayersTable, testCase.parameterNames, 'roughness', 'Substrate Roughness'), exceptions.invalidType.errorID);
            testCase.verifyError(@() testCase.exampleClass.setLayer(1, testCase.parameterNames, 'name', 1), 'MATLAB:validators:mustBeTextScalar');
            testCase.verifyError(@() testCase.exampleClass.setLayer(1, testCase.parameterNames, 'name', ''), 'MATLAB:validators:mustBeNonempty');
            testCase.verifyError(@() testCase.exampleClass.setLayer(1, testCase.parameterNames, 'realSLD', ''), 'MATLAB:validators:mustBeNonempty');
            testCase.verifyError(@() testCase.exampleClass.setLayer(1, testCase.parameterNames, 'imaginarySLD', ''), 'MATLAB:validators:mustBeNonempty');

            % Invalid option
            testCase.verifyError(@() testCase.exampleClass.setLayer(1, testCase.parameterNames, 'realSLD', 'SLDs', 'sld', 'SLDs'), exceptions.invalidOption.errorID);
            testCase.verifyError(@() testCase.exampleClass.setLayer(1, testCase.parameterNames, 'imaginarySLD', 'SLDs', 'sld', 'SLDs'), exceptions.invalidOption.errorID);
        end

        function testRemoveLayer(testCase)
            remainingRows = testCase.exampleClass.varTable(2:end,:);
            testCase.exampleClass.removeLayer(1);

            testCase.verifyEqual(testCase.exampleClass.varTable, remainingRows, 'removeLayer does not work correctly');
        end

        function testRemoveLayerName(testCase)
            remainingRows = testCase.exampleClass.varTable(2:end,:);
            testCase.exampleClass.removeLayer('Bil inner head');

            testCase.verifyEqual(testCase.exampleClass.varTable, remainingRows, 'removeLayer does not work correctly');
        end

        function testRemoveLayerMultiple(testCase)
            % Test removing multiple rows from a layers table
            remainingRows = testCase.exampleClass.varTable(2,:);
            testCase.exampleClass.removeLayer([1 3]);

            testCase.verifyEqual(testCase.exampleClass.varTable, remainingRows, 'removeLayer does not work correctly');
        end

        function testRemoveLayerMultipleCell(testCase)
            % Test removing multiple rows from a layers table by name
            remainingRows = testCase.exampleClass.varTable(2,:);
            testCase.exampleClass.removeLayer({'Bil inner head', 'Bil outer head'});

            testCase.verifyEqual(testCase.exampleClass.varTable, remainingRows, 'removeLayer does not work correctly');
        end

        function testToStructStandardLayers(testCase)
            % Test converting the layers class to a struct
            % Here we use a "standard layers" model type
            expectedStruct.numberOfLayers = 3;
            expectedStruct.layerNames = ["Bil inner head"; "Bil tail"; "Bil outer head"];
            expectedStruct.layerDetails = {[5 6 8 7 2]; [9 10 12 11 2]; [5 6 8 7 2]};

            testCase.verifyEqual(testCase.exampleClass.toStruct(testCase.parameterNames), expectedStruct);
        end

        function testDisplayTable(testCase)
            % Test the routine to display the layers table by capturing
            % the output and comparing with the table headers and data 

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display = textscan(evalc('testCase.exampleClass.displayTable()'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};

            % Check headers
            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove "<strong>" tags
            outVars = eraseBetween(strip(regexprep(displayedTable(1), '\s+', ' ')), '<', '>','Boundaries','inclusive');

            % Convert table variable names to a string array, join into a
            % single string, and then prepend an extra header used for the
            % row index
            varString = "p " + strip(strjoin(string(testCase.exampleClass.varTable.Properties.VariableNames)));
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
                rowString = string(i) + " " + strip(strjoin(testCase.exampleClass.varTable{i,:}));
                testCase.verifyEqual(outRow, rowString, 'Row does not contain the correct data');

            end
        end

        function testDisplayTableEmpty(testCase)
            % Test the routine to display the layers table of an empty
            % layers class by capturing the output and comparing with the
            % table headers and data
            emptyClass = layersClass();

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display = textscan(evalc('emptyClass.displayTable()'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};

            % Check headers
            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove "<strong>" tags
            outVars = eraseBetween(strip(regexprep(displayedTable(1), '\s+', ' ')), '<', '>','Boundaries','inclusive');

            % Convert table variable names to a string array, join into a
            % single string, and then prepend an extra header used for the
            % row index
            varString = strip(strjoin(string(emptyClass.varTable.Properties.VariableNames)));
            testCase.verifyEqual(outVars, varString, 'Table headers do not match variable names');

            % Make sure the output has the right number of rows before
            % continuing
            testCase.assertSize(displayedTable, [3, 1], 'Table does not have the right number of rows');

            % Replace multiple spaces in output table with a single
            % space using regular expressions
            outRow = strip(regexprep(displayedTable(3), '\s+', ' '));
            rowString = """"" """" """" """" """" """"";
            testCase.verifyEqual(outRow, rowString, 'Row does not contain the correct data');
        end

    end

end