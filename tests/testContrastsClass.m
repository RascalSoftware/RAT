classdef testContrastsClass < matlab.unittest.TestCase
%%
% testContrastsClass Class based unit tests for the contrastsClass
% used within the Project Class in RAT.
%
% In this class, we test:
%
% We use an example contrasts class from the example calculation
% "DPPC_standard_layers.m", with some elements from the example
% calculations "orsoDSPC_custLay_script.m" and "DPPC_customXY.m"
%
% Paul Sharp 21/02/23
%
%% Declare properties and parameters

    properties (TestParameter)
        contrastInput = {{}, ...
                         {'Named Contrast'}, ...
                         {'name', 'Few params', ...
                          'background', 'Background D2O', ...
                          'resolution', 'Resolution 1'}, ...
                         {'name', 'All params', ...
                          'background', 'Background H2O', ...
                          'data', 'Simulation', ...
                          'nba', 'Silicon', ...
                          'nbs', 'SLD H2O', ...
                          'resolution', 'Resolution 1', ...
                          'scalefactor', 'Scalefactor 1', ...
                          'resample', true}, ...
                          }
        invalidInput = {{'background', 'Invalid'}, ...
                        {'data', 'Invalid'}, ...
                        {'nba', 'Invalid'}, ...
                        {'nbs', 'Invalid'}, ...
                        {'resolution', 'Invalid'}, ...
                        {'scalefactor', 'Invalid'}, ...
                        {'model', 42}
                        }
        removeInput = {1, 'Bilayer / D2O'}
        changedFields = {{{'name', 'New contrast 1'}}, ...
                         {{'name', 'Named Contrast'}}, ...
                         {{'name', 'Few params'}, ...
                          {'background', 'Background D2O'}, ...
                          {'resolution', 'Resolution 1'}
                         }, ...
                         {{'name', 'All params'}, ...
                          {'background', 'Background H2O'}, ...
                          {'data', 'Simulation'}, ...
                          {'nba', 'Silicon'}, ...
                          {'nbs', 'SLD H2O'}, ...
                          {'resolution', 'Resolution 1'}, ...
                          {'scalefactor', 'Scalefactor 1'}, ...
                          {'resample', true}, ...
                         }, ...
                        }
    end

    properties
        allowedNames            % Full set of ALL parameter names in the project
        dataTable               % Example data table needed when converting to a struct
        defaultContrasts        % Contrasts struct with default values
        exampleClass            % Example contrasts class for testing
        exampleStruct           % The example class converted to a struct
        numContrasts            % Number of Contrasts defined in exampleClass

        % Define the layers from "DPPC_standard_layers.m"
        layerNames = ["Oxide Layer" "Water Layer" "Bil inner head" "Bil tail" "Bil outer head"]
        % Define the custom files from "orsoDSPC_custLay_script.m" and
        % "DPPC_customXY.m" 
        customNames = ["DSPC Model" "DPPC Model"]

        % Data from data class
        D2OData
        SMWData
        H2OData
    end

%% Set up test data

    methods (TestClassSetup)

        function readClassData(testCase)
            % Read in the data used in the example calculation
            % "DPPC_standard_layers.m"
            testCase.D2OData = readmatrix('c_PLP0016596.dat');
            testCase.SMWData = readmatrix('c_PLP0016601.dat');
            testCase.H2OData = readmatrix('c_PLP0016607.dat');
        end

        function initialiseAllowedNames(testCase)
            % The values for each parameter in the contrast class MUST
            % be defined in the corresponding parameters in this class
            % This example is a reduced version of the allowed names used
            % in the example calculation "DPPC_standard_layers.m", with
            % the customNames from "orsoDSPC_custLay_script.m" and
            % "DPPC_custXY_script.m"
            testCase.allowedNames = struct( ...
                'backsNames', ["Background D2O" "Background SMW" "Background H2O"], ...
                'bulkInNames', 'Silicon', ...
                'bulkOutNames', ["SLD D2O" "SLD SMW" "SLD H2O"], ...
                'resolsNames', 'Resolution 1', ...
                'layersNames',  testCase.layerNames, ...
                'dataNames',  ["Simulation" "Bilayer / D2O" "Bilayer / SMW" "Bilayer / H2O"], ...
                'scalefacNames', 'Scalefactor 1', ...
                'customNames',  testCase.customNames ...
                );
        end

        function initialiseDataTable(testCase)
            % The data table defined in "DPPC_standard_layers.m" which is
            % required when converting a contrast class to a struct
            varTypes = {'string','cell','cell','cell'};
            varNames = {'Name','Data','Data Range','Simulation Range'};
            testCase.dataTable = table('Size',[4 4],'VariableTypes',varTypes,'VariableNames',varNames); 

            testCase.dataTable(1,:) = {"Simulation", [], [], {[0.0050 0.7000]}};
            testCase.dataTable(2,:) = {"Bilayer / D2O", testCase.D2OData(:,1:3), {[0.0130 0.3500]}, {[0.0057 0.3961]}};
            testCase.dataTable(3,:) = {"Bilayer / SMW", testCase.SMWData(:,1:3), {[0.0130 0.3500]}, {[0.0076 0.3300]}};
            testCase.dataTable(4,:) = {"Bilayer / H2O", testCase.H2OData(:,1:3), {[0.0130 0.3500]}, {[0.0063 0.3305]}};
        end

    end

    methods (TestMethodSetup)

        function initialiseContrastsClass(testCase)
            % Set up an example contrasts class for testing
            % This example is used in the example calculation
            % "DPPC_standard_layers.m"
            testCase.exampleClass = contrastsClass();

            testCase.exampleClass.contrasts(1) = {struct( ...
                'name', 'Bilayer / D2O', ...
                'background', 'Background D2O', ...
                'data', 'Bilayer / D2O', ...
                'nba', 'Silicon', ...
                'nbs', 'SLD D2O', ...
                'resolution', 'Resolution 1', ...
                'scalefactor', 'Scalefactor 1', ...
                'resample', 0,...
                'model', {{'Oxide Layer', 'Water Layer', 'Bil inner head', 'Bil tail', 'Bil tail', 'Bil outer head'}} ...
                )};
           
            testCase.exampleClass.contrasts(2) = {struct( ...
                'name', 'Bilayer / SMW', ...
                'background', 'Background SMW', ...
                'data', 'Bilayer / SMW', ...
                'nba', 'Silicon', ...
                'nbs', 'SLD SMW', ...
                'resolution', 'Resolution 1', ...
                'scalefactor', 'Scalefactor 1', ...
                'resample', 0,...
                'model', {{'Oxide Layer', 'Water Layer', 'Bil inner head', 'Bil tail', 'Bil tail', 'Bil outer head'}} ...
                )};
            
            testCase.exampleClass.contrasts(3) = {struct( ...
                'name', 'Bilayer / H2O', ...
                'background', 'Background H2O', ...
                'data', 'Bilayer / H2O', ...
                'nba', 'Silicon', ...
                'nbs', 'SLD H2O', ...
                'resolution', 'Resolution 1', ...
                'scalefactor', 'Scalefactor 1', ...
                'resample', 0,...
                'model', {{'Oxide Layer', 'Water Layer', 'Bil inner head', 'Bil tail', 'Bil tail', 'Bil outer head'}} ...
                )};

            testCase.numContrasts = length(testCase.exampleClass.contrasts);

        end

        function initialiseDefaultContrastsStruct(testCase)
            % Create a struct used in the contrasts class with the default
            % values for each parameter
            testCase.defaultContrasts = struct( ...
                'name', '', ...
                'background', '', ...
                'data', '', ...
                'nba', '', ...
                'nbs', '', ...
                'resolution', '', ...
                'scalefactor', '', ...
                'resample', false,...
                'model', '' ...
                );
        end

        function initialiseContrastsStruct(testCase)
            % The contrast class from the example calculation
            % "DPPC_standard_layers.m" converted to a struct
            % We need to define it in this way to avoid setting the struct
            % as a 1x3 struct array . . .
            testCase.exampleStruct = struct( ...
                'contrastShifts', [1 1 1], ...
                'contrastScales', [1 1 1], ...
                'contrastNbas', [1 1 1], ...
                'contrastNbss', [1 2 3], ...
                'contrastRes', [1 1 1], ...
                'resample', [0 0 0], ...
                'dataPresent', [1 1 1], ...
                'contrastCustomFile', [NaN NaN NaN], ...
                'numberOfContrasts', 3 ...
                );

            testCase.exampleStruct.contrastBacks = {[1 1] [2 1] [3 1]};
            testCase.exampleStruct.contrastLayers = {[1 2 3 4 4 5] [1 2 3 4 4 5] [1 2 3 4 4 5]};
            testCase.exampleStruct.contrastRepeatSLDs = {[0 1] [0 1] [0 1]};
            testCase.exampleStruct.dataLimits = {[0.0130 0.3500] [0.0130 0.3500] [0.0130 0.3500]};
            testCase.exampleStruct.simLimits = {[0.0057 0.3961] [0.0076 0.3300] [0.0063 0.3305]};
            testCase.exampleStruct.allData = {testCase.D2OData(:,1:3) testCase.SMWData(:,1:3) testCase.H2OData(:,1:3)};

        end

    end

%% Test Contrasts Class Routines

    methods (Test, ParameterCombination="sequential")

        function testInitialiseContrastsClass(testCase)
            testClass = contrastsClass();

            testCase.verifyEqual(testClass.contrasts, {}, "contrastsClass does not initialise correctly");
            testCase.verifyEqual(testClass.contrastsTable, [], "contrastsClass does not initialise correctly");
        end

        function testAddContrast(testCase, contrastInput, changedFields)
            % Test adding a contrast to the contrasts class.
            % We can add a contrast with no parameters, just a
            % contrast name, or a set of name-value pairs

            % Set the expected contrasts struct
            addedContrast = testCase.defaultContrasts();
            
            for i=1:length(changedFields)
                addedContrast = setfield(addedContrast, changedFields{i}{:});
            end

            expectedContrasts = [testCase.exampleClass.contrasts, addedContrast];

            testCase.exampleClass.addContrast(testCase.allowedNames, contrastInput);
            testCase.verifyEqual(testCase.exampleClass.contrasts, expectedContrasts, "addContrast does not work correctly");
        end

        function testAddContrastInvalidOption(testCase, invalidInput)
            % Test adding a contrast to the contrasts class.
            % If values for each parameter are not valid options, we
            % should raise an error
            testCase.verifyError(@() testCase.exampleClass.addContrast(testCase.allowedNames, invalidInput), 'MATLAB:unrecognizedStringChoice');
        end

        function testAddContrastInvalidType(testCase)
            % Test adding a contrast to the contrasts class.
            % If values for the name an logical parameters are an invalid
            % type, we should raise an error
            testCase.verifyError(@() testCase.exampleClass.addContrast(testCase.allowedNames, {'name', 42}), 'MATLAB:InputParser:ArgumentFailedValidation');
            testCase.verifyError(@() testCase.exampleClass.addContrast(testCase.allowedNames, {'resample', datetime('today')}), 'MATLAB:InputParser:ArgumentFailedValidation');
        end

        function testRemoveContrast(testCase, removeInput)
            % Test removing a contrast from the contrasts class.
            % Contrasts can be specified either by name or by index, but
            % only one contrast can be removed at a time.
            remainingContrasts = testCase.exampleClass.contrasts(2:end);
            testCase.exampleClass.removeContrast(removeInput);

            testCase.verifyEqual(testCase.exampleClass.contrasts, remainingContrasts, "removeContrast does not work correctly");
        end

        function testRemoveContrastInvalid(testCase)
            % Test removing a contrast from the contrasts class.
            % If contrast names or indices are invalid, we should raise an
            % error
            testCase.verifyError(@() testCase.exampleClass.removeContrast(0), indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleClass.removeContrast(testCase.numContrasts+1), indexOutOfRange.errorID);

            testCase.verifyError(@() testCase.exampleClass.removeContrast('Unrecognised Name'), nameNotRecognised.errorID);
        end

        function testSetContrastModelStandard(testCase)
            % Test setting a model for a contrast from the contrasts class
            % when the model type is "standard layers"
            contrastIndex = 1;
            testModel = {'Oxide Layer', 'Water Layer'};

            testCase.exampleClass.setContrastModel(contrastIndex, 'standard layers', testCase.layerNames, testModel);
            testCase.verifyEqual(testCase.exampleClass.contrasts{contrastIndex}.model, testModel, "setContrastModel does not work correctly");
        end

        function testSetContrastModelCustom(testCase)
            % Test setting a model for a contrast from the contrasts class
            % for a "custom" model type
            contrastIndex = 2;
            testModel = {'DPPC Model'};

            testCase.exampleClass.setContrastModel(contrastIndex, 'custom XY', testCase.customNames, testModel);
            testCase.verifyEqual(testCase.exampleClass.contrasts{contrastIndex}.model, testModel, "setContrastModel does not work correctly");
        end

        function testSetContrastModelInvalid(testCase)
            % Test setting a model for a contrast from the contrasts class
            % If the input is invalid we should raise an error
            testModel = {'Oxide Layer', 'Carbide Layer'};

            testCase.verifyError(@() testCase.exampleClass.setContrastModel(1, 'standard layers', testCase.layerNames, testModel), nameNotRecognised.errorID);
            testCase.verifyError(@() testCase.exampleClass.setContrastModel(1, 'custom layers', testCase.layerNames, testModel), invalidValue.errorID); % More than one input not allowed for non-standard layers

            testCase.verifyError(@() testCase.exampleClass.setContrastModel(1, 'custom layers', testCase.layerNames, {'Carbide Layer'}), nameNotRecognised.errorID);
        end

        function testSetContrast(testCase)
            contrastIndex = 1;

            setContrastInput = {
                'name', 'New Contrast', ...
                'background', 'Background SMW', ...
                'data', 'Simulation', ...
                'nbs', 'SLD SMW', ...
                'resample', true, ...
                'model', 'Water Layer'};

            testContrast = struct( ...
                'name', 'New Contrast', ...
                'background', 'Background SMW', ...
                'data', 'Simulation', ...
                'nba', 'Silicon', ...
                'nbs', 'SLD SMW', ...
                'resolution', 'Resolution 1', ...
                'scalefactor', 'Scalefactor 1', ...
                'resample', true,...
                'model', {{'Water Layer'}} ...
                );

            testCase.exampleClass.setContrast(contrastIndex, testCase.allowedNames, setContrastInput);
            testCase.verifyEqual(testCase.exampleClass.contrasts{contrastIndex}, testContrast, "setContrast does not work correctly");
        end

        function testGetAllContrastNames(testCase)
            testCase.verifyEqual(testCase.exampleClass.getAllContrastNames, {'Bilayer / D2O', 'Bilayer / SMW', 'Bilayer / H2O'}, "getAllContrastNames does not work correctly");
        end

        function testGetAllContrastNamesInvalid(testCase)
            % If we try to get contrast names when no contrasts are
            % defined we should raise an error
            emptyContrasts = contrastsClass();
            testCase.verifyError(@() emptyContrasts.getAllContrastNames, invalidValue.errorID);
        end

        function testUpdateContrastName(testCase)
            % Test the rouitine that updates the data entry of the
            % contrast as data names are changed.

            nameChanged = struct('oldName', 'Bilayer / H2O', 'newName', 'Test Data Name');
            testCase.exampleClass.updateContrastName(nameChanged);

            % Get the updated data names
            dataNames = cell(1, testCase.numContrasts);
            for i=1:testCase.numContrasts
                dataNames{i} = testCase.exampleClass.contrasts{i}.data;
            end

            testCase.verifyEqual(dataNames, {'Bilayer / D2O', 'Bilayer / SMW', 'Test Data Name'}, "updateContrastNames does not work correctly");
        end

        function testUpdateContrastNameNotFound(testCase)
            % Test the routine that updates the data entry of the contrast
            % as data names are changed. If the old name is not found,
            % nothing should happen.

            % Get the original data names
            oldDataNames = cell(1, testCase.numContrasts);
            for i=1:testCase.numContrasts
                oldDataNames{i} = testCase.exampleClass.contrasts{i}.data;
            end

            nameChanged = struct('oldName', 'Unused Data Name', 'newName', 'Test Data Name');
            testCase.exampleClass.updateContrastName(nameChanged);

            % Get the updated data names
            dataNames = cell(1, testCase.numContrasts);
            for i=1:testCase.numContrasts
                dataNames{i} = testCase.exampleClass.contrasts{i}.data;
            end

            testCase.verifyEqual(dataNames, oldDataNames, "updateContrastNames does not work correctly");
        end

        function testToStruct(testCase)
            testCase.verifyEqual(testCase.exampleClass.toStruct(testCase.allowedNames, 'standard layers', testCase.dataTable), testCase.exampleStruct);

            % Modify exampleClass and exampleStruct to be valid for a
            % custom layers model - the differences are that there can
            % only be one entry for model and we check for custom files
            % rather than layers
            for i=1:testCase.numContrasts
                testCase.exampleClass.contrasts{i}.model = {'DSPC Model'};
            end
            testCase.exampleStruct.contrastLayers = {{} {} {}};
            testCase.exampleStruct.contrastCustomFile = [1 1 1];

            testCase.verifyEqual(testCase.exampleClass.toStruct(testCase.allowedNames, 'custom layers', testCase.dataTable), testCase.exampleStruct);
        end

        function testDisplayContrastsObject(testCase)
            % Test the routine to display the a table of the contrasts
            % object by capturing the output and comparing with the
            % expected table headers and contrasts data

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display = textscan(evalc('testCase.exampleClass.displayContrastsObject()'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};

            % Check headers
            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove "<strong>" tags
            outVars = eraseBetween(strip(regexprep(displayedTable(2), '\s+', ' ')), '<', '>','Boundaries','inclusive');
            headerString = "p 1 2 3";
            testCase.verifyEqual(outVars, headerString, 'Table headers do not match variable names');

            % Make sure the output has the right number of rows before
            % continuing - output consists of "Contrasts" string,
            % table header, divider row, a row for each of the nine
            % parameters and an extra row for additional model parameters
            expectedRows = 12 + length(testCase.exampleClass.contrasts{1}.model) - 1;
            testCase.assertSize(displayedTable, [expectedRows, 1], 'Table does not have the right number of rows');

            % Construct string array of contrast parameters to compare
            % with the rows of the displayed table
            rowString(1) = strjoin(["name", ...
                                    testCase.exampleClass.contrasts{1}.name, ...
                                    testCase.exampleClass.contrasts{2}.name, ...
                                    testCase.exampleClass.contrasts{3}.name]);

            rowString(2) = strjoin(["Data", ...
                                    testCase.exampleClass.contrasts{1}.data, ...
                                    testCase.exampleClass.contrasts{2}.data, ...
                                    testCase.exampleClass.contrasts{3}.data]);

            rowString(3) = strjoin(["Background", ...
                                    testCase.exampleClass.contrasts{1}.background, ...
                                    testCase.exampleClass.contrasts{2}.background, ...
                                    testCase.exampleClass.contrasts{3}.background]);

            rowString(4) = strjoin(["Bulk in", ...
                                    testCase.exampleClass.contrasts{1}.nba, ...
                                    testCase.exampleClass.contrasts{2}.nba, ...
                                    testCase.exampleClass.contrasts{3}.nba]);

            rowString(5) = strjoin(["Bulk out", ...
                                    testCase.exampleClass.contrasts{1}.nbs, ...
                                    testCase.exampleClass.contrasts{2}.nbs, ...
                                    testCase.exampleClass.contrasts{3}.nbs]);

            rowString(6) = strjoin(["Scalefactor", ...
                                    testCase.exampleClass.contrasts{1}.scalefactor, ...
                                    testCase.exampleClass.contrasts{2}.scalefactor, ...
                                    testCase.exampleClass.contrasts{3}.scalefactor]);

            rowString(7) = strjoin(["Resolution", ...
                                    testCase.exampleClass.contrasts{1}.resolution, ...
                                    testCase.exampleClass.contrasts{2}.resolution, ...
                                    testCase.exampleClass.contrasts{3}.resolution]);

            rowString(8) = strjoin(["Resample", ...
                                    testCase.exampleClass.contrasts{1}.resample, ...
                                    testCase.exampleClass.contrasts{2}.resample, ...
                                    testCase.exampleClass.contrasts{3}.resample]);

            rowString(9) = strjoin(["Model", ...
                                    testCase.exampleClass.contrasts{1}.model{1}, ...
                                    testCase.exampleClass.contrasts{2}.model{1}, ...
                                    testCase.exampleClass.contrasts{3}.model{1}]);

            rowString(10) = strjoin({testCase.exampleClass.contrasts{1}.model{2}, ...
                                     testCase.exampleClass.contrasts{2}.model{2}, ...
                                     testCase.exampleClass.contrasts{3}.model{2}});

            rowString(11) = strjoin({testCase.exampleClass.contrasts{1}.model{3}, ...
                                     testCase.exampleClass.contrasts{2}.model{3}, ...
                                     testCase.exampleClass.contrasts{3}.model{3}});

            rowString(12) = strjoin({testCase.exampleClass.contrasts{1}.model{4}, ...
                                     testCase.exampleClass.contrasts{2}.model{4}, ...
                                     testCase.exampleClass.contrasts{3}.model{4}});

            rowString(13) = strjoin({testCase.exampleClass.contrasts{1}.model{5}, ...
                                     testCase.exampleClass.contrasts{2}.model{5}, ...
                                     testCase.exampleClass.contrasts{3}.model{5}});

            rowString(14) = strjoin({testCase.exampleClass.contrasts{1}.model{6}, ...
                                     testCase.exampleClass.contrasts{2}.model{6}, ...
                                     testCase.exampleClass.contrasts{3}.model{6}});

            % Check table contents - when displayed, row 3 is a set of
            % lines, so row 4 is the first line of data
            for i = 4:expectedRows
                
                % Replace multiple spaces in output table with a single
                % space using regular expressions, and remove '"'
                % characters
                outRow = strip(replace(regexprep(displayedTable(i), '\s+', ' '), '"', ''));

                testCase.verifyEqual(outRow, rowString(i-3), "Row does not contain the correct data");

            end
        end

    end

end
