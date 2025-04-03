classdef testContrastsClass < matlab.unittest.TestCase
%%
% testContrastsClass Class based unit tests for the contrastsClass
% used within the Project Class in RAT.
%
% We use an example contrasts class from the example calculation
% "DPPC_standard_layers.m", with some elements from the example
% calculations "orsoDSPC_custLay_script.m" and "DPPC_customXY.m"
%
%% Declare properties and parameters

    properties (TestParameter)
        contrastInput = {{}, ...
                         {'name', 'Few params', ...
                          'background', 'Background D2O', ...
                          'resolution', 'Resolution 1'}, ...
                         {'name', 'All params', ...
                          'data', 'Simulation', ...
                          'background', 'Background H2O', ...
                          'backgroundAction', backgroundActions.Subtract, ...
                          'bulkIn', 'Silicon', ...
                          'bulkOut', 'SLD H2O', ...
                          'scalefactor', 'Scalefactor 1', ...
                          'resolution', 'Resolution 1', ...
                          'resample', true, ...
                          'repeatLayers', 2, ...
                          'model', {'Domain Contrast 1', 'Domain Contrast 2'}}, ...
                          }
        invalidInput = {{'background', 'Invalid'}, ...
                        {'data', 'Invalid'}, ...
                        {'bulkIn', 'Invalid'}, ...
                        {'bulkOut', 'Invalid'}, ...
                        {'resolution', 'Invalid'}, ...
                        {'scalefactor', 'Invalid'}
                        }
        removeInput = {1, 'bilayer / d2o'}
        changedFields = {{{'name', 'New contrast 1'}}, ...
                         {{'name', 'Few params'}, ...
                          {'background', 'Background D2O'}, ...
                          {'resolution', 'Resolution 1'}
                         }, ...
                         {{'name', 'All params'}, ...
                          {'data', 'Simulation'}, ...
                          {'background', 'Background H2O'}, ...
                          {'backgroundAction', 'subtract'}, ...
                          {'bulkIn', 'Silicon'}, ...
                          {'bulkOut', 'SLD H2O'}, ...
                          {'scalefactor', 'Scalefactor 1'}, ...
                          {'resolution', 'Resolution 1'}, ...
                          {'resample', true}, ...
                          {'repeatLayers', 2}, ...
                          {'model', {'Domain Contrast 1', 'Domain Contrast 2'}}, ...
                         }, ...
                        }
    end

    properties
        allowedNames            % Full set of ALL parameter names in the project
        varTable                % Example data table needed when converting to a struct
        defaultContrastParams   % Default values for contrasts
        exampleClass            % Example contrasts class for testing
        exampleStruct           % The example class converted to a struct
        newValues               % New set of values for contrasts
        numContrasts            % Number of Contrasts defined in exampleClass

        % Define the layers from "DPPC_standard_layers.m"
        layerNames = ["Oxide Layer" "Water Layer" "Bil inner head" "Bil tail" "Bil outer head"]
        % Define the custom files from "orsoDSPC_custLay_script.m" and
        % "DPPC_customXY.m" 
        customNames = ["DSPC Model" "DPPC Model"]
        domainContrastNames = ["Domain Contrast 1", "Domain Contrast 2", "Test Domain Contrast"]

        % Data from data class
        D2OData
        SMWData
        H2OData
    end

%% Set up test data

    methods (TestClassSetup)
        function readClassData(testCase)    
            import matlab.unittest.fixtures.PathFixture
            path = fullfile(getappdata(0, 'root'), 'tests', 'normalTFReflectivityCalculation');
            testCase.applyFixture(PathFixture(path))
            
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
            % "DPPC_custXY_script.m" and an extra scalefactor and
            % resolution and domain ratios
            testCase.allowedNames = struct( ...
                'backgroundNames', ["Background D2O" "Background SMW" "Background H2O"], ...
                'bulkInNames', 'Silicon', ...
                'bulkOutNames', ["SLD D2O" "SLD SMW" "SLD H2O"], ...
                'resolutionNames', ["Resolution 1" "Test Resolution"], ...
                'layerNames',  testCase.layerNames, ...
                'dataNames',  ["Simulation" "Bilayer / D2O" "Bilayer / SMW" "Bilayer / H2O"], ...
                'scalefactorNames', ["Scalefactor 1" "Test Scalefactor"], ...
                'customFileNames',  testCase.customNames, ...
                'domainRatioNames', ["Domain Ratio 1", "Test Domain Ratio"], ...
                'domainContrastNames', testCase.domainContrastNames, ...
                'modelNames', testCase.domainContrastNames ...
                );
        end

        function initialiseDataTable(testCase)
            % The data table defined in "DPPC_standard_layers.m" which is
            % required when converting a contrast class to a struct
            varTypes = {'string','cell','cell','cell'};
            varNames = {'Name','Data','Data Range','Simulation Range'};
            testCase.varTable = table('Size',[4 4],'VariableTypes',varTypes,'VariableNames',varNames); 

            testCase.varTable(1,:) = {'Simulation', [], [], {[0.0050 0.7000]}};
            testCase.varTable(2,:) = {'Bilayer / D2O', testCase.D2OData(:,1:3), {[0.0130 0.3500]}, {[0.0057 0.3961]}};
            testCase.varTable(3,:) = {'Bilayer / SMW', testCase.SMWData(:,1:3), {[0.0130 0.3500]}, {[0.0076 0.3300]}};
            testCase.varTable(4,:) = {'Bilayer / H2O', testCase.H2OData(:,1:3), {[0.0130 0.3500]}, {[0.0063 0.3305]}};
        end

        function initialiseDefaultContrastParams(testCase)
            % Create a struct used in the contrasts class with the default
            % values for each parameter
            testCase.defaultContrastParams = struct( ...
                'name', '', ...
                'data', '', ...
                'background', '', ...
                'backgroundAction', backgroundActions.Add.value, ...
                'bulkIn', '', ...
                'bulkOut', '', ...
                'scalefactor', '', ...
                'resolution', '', ...
                'resample', false, ...
                'repeatLayers', 1, ...
                'domainRatio', '', ...
                'model', '' ...
                );
        end

        function initialiseNewValues(testCase)
            % Create a new set of values for each contrast parameter
            testCase.newValues = {
                'name', 'New Contrast', ...
                'data', 'Simulation', ...
                'background', 'Background SMW', ...
                'backgroundAction', backgroundActions.Subtract, ...
                'bulkIn', 'Silicon', ...
                'bulkOut', 'SLD SMW', ...
                'scalefactor', 'Test Scalefactor', ...
                'resolution', 'Test Resolution', ...
                'resample', true, ...
                'repeatLayers', 2, ...
                'domainRatio', 'Test Domain Ratio', ...
                'model', {'Domain Contrast 1', 'Test Domain Contrast'} ...
                };
        end

    end

    methods (TestMethodSetup)

        function initialiseContrastsClass(testCase)
            % Set up an example contrasts class for testing
            % This example is used in the example calculation
            % "DPPC_standard_layers.m"
            testCase.exampleClass = contrastsClass(domains=true);

            testCase.exampleClass.contrasts(1) = {struct( ...
                'name', 'Bilayer / D2O', ...
                'data', 'Bilayer / D2O', ...
                'background', 'Background D2O', ...
                'backgroundAction', backgroundActions.Add.value, ...
                'bulkIn', 'Silicon', ...
                'bulkOut', 'SLD D2O', ...
                'scalefactor', 'Scalefactor 1', ...
                'resolution', 'Resolution 1', ...
                'resample', 0, ...
                'repeatLayers', 1, ...
                'domainRatio', 'Domain Ratio 1', ...
                'model', {{'Domain Contrast 1', 'Domain Contrast 2'}} ...
                )};
           
            testCase.exampleClass.contrasts(2) = {struct( ...
                'name', 'Bilayer / SMW', ...
                'data', 'Bilayer / SMW', ...
                'background', 'Background SMW', ...
                'backgroundAction', backgroundActions.Add.value, ...
                'bulkIn', 'Silicon', ...
                'bulkOut', 'SLD SMW', ...
                'scalefactor', 'Scalefactor 1', ...
                'resolution', 'Resolution 1', ...
                'resample', 0, ...
                'repeatLayers', 1, ...
                'domainRatio', 'Domain Ratio 1', ...
                'model', {{'Domain Contrast 1', 'Domain Contrast 2'}} ...
                )};
            
            testCase.exampleClass.contrasts(3) = {struct( ...
                'name', 'Bilayer / H2O', ...
                'data', 'Bilayer / H2O', ...
                'background', 'Background H2O', ...
                'backgroundAction', backgroundActions.Add.value, ...
                'bulkIn', 'Silicon', ...
                'bulkOut', 'SLD H2O', ...
                'scalefactor', 'Scalefactor 1', ...
                'resolution', 'Resolution 1', ...
                'resample', 0, ...
                'repeatLayers', 1, ...
                'domainRatio', 'Domain Ratio 1', ...
                'model', {{'Domain Contrast 1', 'Domain Contrast 2'}} ...
                )};

            testCase.numContrasts = length(testCase.exampleClass.contrasts);
        end

        function initialiseContrastsStruct(testCase)
            % The contrast class from the example calculation
            % "DPPC_standard_layers.m" converted to a struct
            % We need to define it in this way to avoid setting the struct
            % as a 1x3 struct array . . .
            testCase.exampleStruct = struct( ...
                'numberOfContrasts', 3, ...
                'contrastBackgrounds', [1 2 3], ...
                'contrastScalefactors', [1 1 1], ...
                'contrastBulkIns', [1 1 1], ...
                'contrastBulkOuts', [1 2 3], ...
                'contrastDomainRatios', [1 1 1], ...
                'contrastResolutions', [1 1 1], ...
                'resample', [0 0 0], ...
                'repeatLayers', [1 1 1], ...
                'dataPresent', [1 1 1], ...
                'contrastCustomFile', [NaN NaN NaN] ...
                );

            testCase.exampleStruct.contrastNames = {'Bilayer / D2O', 'Bilayer / SMW', 'Bilayer / H2O'};
            testCase.exampleStruct.contrastBackgroundActions = {'add', 'add', 'add'};
            testCase.exampleStruct.contrastLayers = {[1 2] [1 2] [1 2]};
            testCase.exampleStruct.dataLimits = {[0.0130 0.3500] [0.0130 0.3500] [0.0130 0.3500]};
            testCase.exampleStruct.simulationLimits = {[0.0057 0.3961] [0.0076 0.3300] [0.0063 0.3305]};
            testCase.exampleStruct.contrastData = {testCase.D2OData(:,1:3) testCase.SMWData(:,1:3) testCase.H2OData(:,1:3)};
        end

    end

%% Test Contrasts Class Routines

    methods (Test, ParameterCombination='sequential')

        function testInitialiseContrastsClass(testCase)
            % Standard calculation
            testClass = contrastsClass();
            testCase.verifyEqual(testClass.contrasts, {}, 'contrastsClass does not initialise correctly');
            testCase.verifyFalse(testClass.isDomains);

            % Domains Calculation
            testDomainsClass = contrastsClass(domains=true);
            testCase.verifyEqual(testDomainsClass.contrasts, {}, 'contrastsClass does not initialise correctly');
            testCase.verifyTrue(testDomainsClass.isDomains);
        end

        function testInitialiseContrastsClassIllogical(testCase)
            % If we initialise a contrasts class with a non-logical
            % variable we should fail validation
            testCase.verifyError(@() contrastsClass(domains=0), 'MATLAB:validators:mustBeA');
        end
        
        function testAddContrast(testCase, contrastInput, changedFields)
            % Test adding a contrast to the contrasts class.
            % We can add a contrast with no parameters, just a
            % contrast name, or a set of name-value pairs

            % Set the expected contrasts struct
            addedContrast = testCase.defaultContrastParams();
            
            for i=1:length(changedFields)
                addedContrast = setfield(addedContrast, changedFields{i}{:});
            end

            expectedContrasts = [testCase.exampleClass.contrasts, addedContrast];

            testCase.exampleClass.addContrast(testCase.allowedNames, contrastInput{:});
            testCase.verifyEqual(testCase.exampleClass.contrasts, expectedContrasts, 'addContrast does not work correctly');
        end

        function testAddContrastInvalid(testCase)
            % Test adding a contrast to the contrasts class.
            % If the "backgroundAction" input is not a member of the enum
            % we should raise an error
            testCase.verifyError(@() testCase.exampleClass.addContrast(testCase.allowedNames, 'backgroundAction', 'random'), exceptions.invalidOption.errorID);
        end

        function testRemoveContrast(testCase, removeInput)
            % Test removing a contrast from the contrasts class.
            % Contrasts can be specified either by name or by index, but
            % only one contrast can be removed at a time.
            remainingContrasts = testCase.exampleClass.contrasts(2:end);
            testCase.exampleClass.removeContrast(removeInput);

            testCase.verifyEqual(testCase.exampleClass.contrasts, remainingContrasts, 'removeContrast does not work correctly');
        end

        function testRemoveContrastInvalid(testCase)
            % Test removing a contrast from the contrasts class.
            % If contrast names or indices are invalid, we should raise an
            % error
            testCase.verifyError(@() testCase.exampleClass.removeContrast(0), exceptions.indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleClass.removeContrast(testCase.numContrasts+1), exceptions.indexOutOfRange.errorID);

            testCase.verifyError(@() testCase.exampleClass.removeContrast('Unrecognised Name'), exceptions.nameNotRecognised.errorID);
        end

        function testSetContrastModelStandardLayersDomains(testCase)
            % Test setting a model for a contrast from the contrasts class
            % for a "standard layers" model type
            contrastIndex = 1;
            testModel = {'Domain Contrast 1', 'Test Domain Contrast'};

            testCase.exampleClass.setContrastModel(contrastIndex, testCase.allowedNames, testModel);
            testCase.verifyEqual(testCase.exampleClass.contrasts{contrastIndex}.model, testModel, 'setContrastModel does not work correctly');
        end
        
        function testSetContrastModelStandardLayers(testCase)
            % Test setting a model for a contrast from the contrasts class
            % for a "standard layers" model type
            noDomainsClass = contrastsClass();
            noDomainsClass.addContrast(testCase.allowedNames);

            testModel = {'Oxide Layer', 'Water Layer'};
            testCase.allowedNames.modelNames = testCase.layerNames;

            noDomainsClass.setContrastModel(1, testCase.allowedNames, testModel);
            testCase.verifyEqual(noDomainsClass.contrasts{1}.model, testModel, 'setContrastModel does not work correctly');

            testCase.allowedNames.layerNames = {};
            testCase.verifyError(@() testCase.exampleClass.setContrastModel(1, testCase.allowedNames, {'Oxide Layer'}), exceptions.invalidValue.errorID);
            testCase.verifyError(@() testCase.exampleClass.setContrastModel(1, testCase.allowedNames, {'DPPC Model'}), exceptions.invalidValue.errorID);

        end

        function testSetContrastModelCustomLayers(testCase)
            % Test setting a model for a contrast from the contrasts class
            % for a "custom XY" model type
            noDomainsClass = contrastsClass();
            testCase.allowedNames = rmfield(testCase.allowedNames, 'layerNames');
            noDomainsClass.addContrast(testCase.allowedNames);

            testModel = {'DPPC Model'};
            testCase.allowedNames.modelNames = testCase.customNames;

            testCase.exampleClass.setContrastModel(1, testCase.allowedNames, testModel);
            testCase.verifyEqual(testCase.exampleClass.contrasts{1}.model, testModel, 'setContrastModel does not work correctly');

            % only one model value is allowed
            testCase.verifyError(@() testCase.exampleClass.setContrastModel(1, testCase.allowedNames, {'DPPC Model', 'DSPC Model'}), exceptions.invalidValue.errorID);

            testCase.allowedNames.customFileNames = {};
            testCase.verifyError(@() testCase.exampleClass.setContrastModel(1, testCase.allowedNames, {'DPPC Model'}), exceptions.invalidValue.errorID);
        end

        function testSetContrastModelInvalid(testCase)
            % Test setting a model for a contrast from the contrasts class
            % If the input is invalid we should raise an error

            % Contrast must be recognisable by name or index
            testCase.verifyError(@() testCase.exampleClass.setContrastModel(0, testCase.allowedNames, {'Oxide Layer'}), exceptions.indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleClass.setContrastModel(testCase.numContrasts+1, testCase.allowedNames, {'Oxide Layer'}), exceptions.indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleClass.setContrastModel('Invalid Contrast', testCase.allowedNames, {'Oxide Layer'}), exceptions.nameNotRecognised.errorID);

            % Contrast models must be defined in allowed values, and only
            % one model is allowed for "custom layers" and "custom XY"
            testModel = {'Domain Contrast 1', 'Invalid Domain Contrast'};
            testCase.verifyError(@() testCase.exampleClass.setContrastModel(1, testCase.allowedNames, testModel), exceptions.nameNotRecognised.errorID);

            % Only two contrast models are allowed for "standard layers"
            % with domains
            testModel = {'Domain Contrast 1', 'Domain Contrast 2', 'Test Domain Contrast'};
            testCase.verifyError(@() testCase.exampleClass.setContrastModel(1, testCase.allowedNames, testModel), exceptions.invalidValue.errorID);

            % Partial matches must be disallowed
            testCase.verifyError(@() testCase.exampleClass.setContrastModel('Oxide Lay', testCase.allowedNames, {'Oxide Layer'}), exceptions.nameNotRecognised.errorID);
        end

        function testSetContrast(testCase)
            contrastIndex = 1;

            expectedContrast = struct( ...
                'name', 'New Contrast', ...
                'data', 'Simulation', ...
                'background', 'Background SMW', ...
                'backgroundAction', backgroundActions.Subtract.value, ...
                'bulkIn', 'Silicon', ...
                'bulkOut', 'SLD SMW', ...
                'scalefactor', 'Test Scalefactor', ...
                'resolution', 'Test Resolution', ...
                'resample', true, ...
                'repeatLayers', 2, ...
                'domainRatio', 'Test Domain Ratio', ...
                'model', {{'Domain Contrast 1', 'Test Domain Contrast'}} ...
                );

            testCase.exampleClass.setContrast(contrastIndex, testCase.allowedNames, testCase.newValues{:});
            testCase.verifyEqual(testCase.exampleClass.contrasts{contrastIndex}, expectedContrast, 'setContrast does not work correctly');

            % Addresses bug where resample was reset due to non-empty
            % default value
            checkName = 'Check New Contrast';
            expectedContrast.name = checkName;
            testCase.exampleClass.setContrast(contrastIndex, testCase.allowedNames, 'name', checkName);
            testCase.verifyEqual(testCase.exampleClass.contrasts{contrastIndex}, expectedContrast, 'setContrast does not work correctly');
        end

        function testSetContrastNoDomains(testCase)
            contrastIndex = 1;

            noDomainsInput = {
                'name', 'No Domains Contrast', ...
                'data', 'Simulation', ...
                'background', 'Background SMW', ...
                'backgroundAction', backgroundActions.Add, ...
                'bulkIn', 'Silicon', ...
                'bulkOut', 'SLD SMW', ...
                'scalefactor', 'Test Scalefactor', ...
                'resolution', 'Test Resolution', ...
                'resample', true ...
                'repeatLayers', 2, ...
                };

            expectedContrast = struct( ...
                'name', 'No Domains Contrast', ...
                'data', 'Simulation', ...
                'background', 'Background SMW', ...
                'backgroundAction', backgroundActions.Add.value, ...
                'bulkIn', 'Silicon', ...
                'bulkOut', 'SLD SMW', ...
                'scalefactor', 'Test Scalefactor', ...
                'resolution', 'Test Resolution', ...
                'resample', true, ...
                'repeatLayers', 2, ...
                'model', '' ...
                );

            noDomainsClass = contrastsClass();
            noDomainsClass.addContrast(testCase.allowedNames);

            % If we include "domainRatio" here, we should encounter an error
            testCase.verifyError(@() noDomainsClass.setContrast(contrastIndex, testCase.allowedNames, testCase.newValues{:}), 'MATLAB:InputParser:UnmatchedParameter');

            noDomainsClass.setContrast(contrastIndex, testCase.allowedNames, noDomainsInput{:});
            testCase.verifyEqual(noDomainsClass.contrasts{contrastIndex}, expectedContrast, 'setContrast does not work correctly');
        end

        function testSetContrastInvalid(testCase)
            % Test setting parameter values within a contrast
            % Contrast must be recognisable by name or index
            testCase.verifyError(@() testCase.exampleClass.setContrast(0, testCase.allowedNames, testCase.newValues{:}), exceptions.indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleClass.setContrast(testCase.numContrasts+1, testCase.allowedNames, testCase.newValues{:}), exceptions.indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleClass.setContrast('Invalid Contrast', testCase.allowedNames, testCase.newValues{:}), exceptions.nameNotRecognised.errorID);

            % "backgroundAction" should be a value of the "actions" enum
            testCase.verifyError(@() testCase.exampleClass.setContrast(1, testCase.allowedNames, 'backgroundAction', 'random'), exceptions.invalidOption.errorID);

            % Partial matches of fields names and parameter values should
            % be disallowed
            testCase.verifyError(@() testCase.exampleClass.setContrast(1, testCase.allowedNames, 'backgr', 'Background H2O'), 'MATLAB:functionValidation:AmbiguousInputName');
            testCase.verifyError(@() testCase.exampleClass.setContrast(1, testCase.allowedNames, 'background', 'Background H'), exceptions.nameNotRecognised.errorID);
        end

        function testSetContrastWarning(testCase)
            % Test setting repeatLayer values within a contrast for a
            % non-standard layers model raises a warning
            testCase.allowedNames = rmfield(testCase.allowedNames, 'layerNames');
            testCase.verifyWarning(@() testCase.exampleClass.setContrast(1, testCase.allowedNames, 'repeatLayers', 2), '', 'repeatLayers model warning should be triggered');
        end


        function testGetAllContrastNames(testCase)
            testCase.verifyEqual(testCase.exampleClass.getNames, {'Bilayer / D2O'; 'Bilayer / SMW'; 'Bilayer / H2O'}, 'getAllContrastNames does not work correctly');
        end

        function testUpdateDataName(testCase)
            % Test the routine that updates the data entry of the contrast
            % as data names are changed.
            nameChanged = struct('oldName', 'Bilayer / H2O', 'newName', 'Test Data Name');
            testCase.exampleClass.updateDataName(nameChanged);

            % Get the updated data names
            dataNames = cell(1, testCase.numContrasts);
            for i=1:testCase.numContrasts
                dataNames{i} = testCase.exampleClass.contrasts{i}.data;
            end

            testCase.verifyEqual(dataNames, {'Bilayer / D2O', 'Bilayer / SMW', 'Test Data Name'}, 'updateDataNames does not work correctly');
        end

        function testUpdateDataNameNotFound(testCase)
            % Test the routine that updates the data entry of the contrast
            % as data names are changed. If the old name is not found,
            % nothing should happen.

            % Get the original data names
            oldDataNames = cell(1, testCase.numContrasts);
            for i=1:testCase.numContrasts
                oldDataNames{i} = testCase.exampleClass.contrasts{i}.data;
            end

            nameChanged = struct('oldName', 'Unused Data Name', 'newName', 'Test Data Name');
            testCase.exampleClass.updateDataName(nameChanged);

            % Get the updated data names
            dataNames = cell(1, testCase.numContrasts);
            for i=1:testCase.numContrasts
                dataNames{i} = testCase.exampleClass.contrasts{i}.data;
            end

            testCase.verifyEqual(dataNames, oldDataNames, 'updateDataNames does not work correctly');
        end

        function testToStructStandardLayers(testCase)
            % Test converting the contrasts class to a struct
            % Here we use a "standard layers" model type
            testCase.verifyEqual(testCase.exampleClass.toStruct(testCase.allowedNames, 'standard layers', testCase.varTable), testCase.exampleStruct);
        end

        function testToStructCustomLayers(testCase)
            % Test converting the contrasts class to a struct
            % Here we use a "custom layers" model type

            % Modify exampleClass and exampleStruct to be valid for a
            % custom layers model - the differences are that there can
            % only be one entry for model and we check for custom files
            % rather than layers
            for i=1:testCase.numContrasts
                testCase.exampleClass.contrasts{i}.model = {'DSPC Model'};
            end
            testCase.exampleStruct.contrastLayers = {[] [] []};
            testCase.exampleStruct.contrastCustomFile = [1 1 1];

            testCase.verifyEqual(testCase.exampleClass.toStruct(testCase.allowedNames, 'custom layers', testCase.varTable), testCase.exampleStruct);
        end

        function testToStructDisallowedData(testCase)
            % Test converting the contrasts class to a struct
            % If the data parameter is not in the allowed names, set some
            % dummy values in the struct
            contrastIndex = 2;

            % Modify exampleClass and exampleStruct to remove a data entry
            % and insert the expected dummy values in the struct
            testCase.exampleClass.contrasts{contrastIndex}.data = 'Disallowed data name';

            testCase.exampleStruct.dataPresent(contrastIndex) = 0;
            testCase.exampleStruct.dataLimits{contrastIndex} = [0 0];
            testCase.exampleStruct.simulationLimits{contrastIndex} = [0 0];
            testCase.exampleStruct.contrastData{contrastIndex} = [0 0 0];

            testCase.verifyEqual(testCase.exampleClass.toStruct(testCase.allowedNames, 'standard layers', testCase.varTable), testCase.exampleStruct);
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
            outVars = eraseBetween(strip(regexprep(displayedTable(1), '\s+', ' ')), '<', '>','Boundaries','inclusive');
            headerString = "p 1 2 3";
            testCase.verifyEqual(outVars, headerString, 'Table headers do not match variable names');

            % Make sure the output has the right number of rows before
            % continuing - output consists of table header, divider row,
            % a row for each of the parameters and an extra row for
            % additional model parameters
            expectedRows = 14 + length(testCase.exampleClass.contrasts{1}.model) - 1;
            testCase.assertSize(displayedTable, [expectedRows, 1], 'Table does not have the right number of rows');

            % Construct string array of contrast parameters to compare
            % with the rows of the displayed table
            rowString(1) = strjoin(["Name", ...
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

            rowString(4) = strjoin(["Background Action", ...
                                    testCase.exampleClass.contrasts{1}.backgroundAction, ...
                                    testCase.exampleClass.contrasts{2}.backgroundAction, ...
                                    testCase.exampleClass.contrasts{3}.backgroundAction]);

            rowString(5) = strjoin(["Bulk in", ...
                                    testCase.exampleClass.contrasts{1}.bulkIn, ...
                                    testCase.exampleClass.contrasts{2}.bulkIn, ...
                                    testCase.exampleClass.contrasts{3}.bulkIn]);

            rowString(6) = strjoin(["Bulk out", ...
                                    testCase.exampleClass.contrasts{1}.bulkOut, ...
                                    testCase.exampleClass.contrasts{2}.bulkOut, ...
                                    testCase.exampleClass.contrasts{3}.bulkOut]);

            rowString(7) = strjoin(["Scalefactor", ...
                                    testCase.exampleClass.contrasts{1}.scalefactor, ...
                                    testCase.exampleClass.contrasts{2}.scalefactor, ...
                                    testCase.exampleClass.contrasts{3}.scalefactor]);

            rowString(8) = strjoin(["Resolution", ...
                                    testCase.exampleClass.contrasts{1}.resolution, ...
                                    testCase.exampleClass.contrasts{2}.resolution, ...
                                    testCase.exampleClass.contrasts{3}.resolution]);

            rowString(9) = strjoin(["Resample", ...
                                    testCase.exampleClass.contrasts{1}.resample, ...
                                    testCase.exampleClass.contrasts{2}.resample, ...
                                    testCase.exampleClass.contrasts{3}.resample]);

            rowString(10) = strjoin(["Repeat Layers", ...
                                    testCase.exampleClass.contrasts{1}.repeatLayers, ...
                                    testCase.exampleClass.contrasts{2}.repeatLayers, ...
                                    testCase.exampleClass.contrasts{3}.repeatLayers]);

            rowString(11) = strjoin(["Domain Ratio", ...
                                    testCase.exampleClass.contrasts{1}.domainRatio, ...
                                    testCase.exampleClass.contrasts{2}.domainRatio, ...
                                    testCase.exampleClass.contrasts{3}.domainRatio]);

            rowString(12) = strjoin(["Model", ...
                                    testCase.exampleClass.contrasts{1}.model{1}, ...
                                    testCase.exampleClass.contrasts{2}.model{1}, ...
                                    testCase.exampleClass.contrasts{3}.model{1}]);

            rowString(13) = strjoin({testCase.exampleClass.contrasts{1}.model{2}, ...
                                     testCase.exampleClass.contrasts{2}.model{2}, ...
                                     testCase.exampleClass.contrasts{3}.model{2}});

            % Check table contents - when displayed, row 2 is a set of
            % lines, so row 3 is the first line of data
            for i = 3:expectedRows
                
                % Replace multiple spaces in output table with a single
                % space using regular expressions, and remove '"'
                % characters
                outRow = strip(replace(regexprep(displayedTable(i), '\s+', ' '), '"', ''));

                testCase.verifyEqual(outRow, rowString(i-2), 'Row does not contain the correct data');

            end
        end

        function testDisplayContrastsObjectEmpty(testCase)
            % Test the routine to display the a table of an empty
            % contrasts object by capturing the output and comparing with
            % the expected table headers and contrasts data

            % Make an empty contrast object
            emptyContrasts = contrastsClass();

            emptyContrasts.contrasts = {testCase.defaultContrastParams};
            emptyContrasts.contrasts{1}.backgroundAction = '';
            emptyContrasts.contrasts{1}.resample = '';
            emptyContrasts.contrasts{1}.repeatLayers = '';

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display = textscan(evalc('emptyContrasts.displayContrastsObject()'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};

            % Check headers
            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove "<strong>" tags
            outVars = eraseBetween(strip(regexprep(displayedTable(1), '\s+', ' ')), '<', '>','Boundaries','inclusive');
            headerString = "p 1";
            testCase.verifyEqual(outVars, headerString, 'Table headers do not match variable names');

            % Make sure the output has the right number of rows before
            % continuing - output consists of table header, divider row,
            % a row for each of the nine parameters and an extra row for
            % additional model parameters
            expectedRows = 13;
            testCase.assertSize(displayedTable, [expectedRows, 1], 'Table does not have the right number of rows');

            % Construct string array of contrast parameters to compare
            % with the rows of the displayed table
            rowString = ["Name" "Data" "Background" "Background Action" "Bulk in"...
                "Bulk out" "Scalefactor" "Resolution" "Resample" "Repeat Layers" "Model"];

            % Check table contents - when displayed, row 2 is a set of
            % lines, so row 3 is the first line of data
            for i = 3:expectedRows
                
                % Replace multiple spaces in output table with a single
                % space using regular expressions, and remove '"'
                % characters
                outRow = strip(replace(regexprep(displayedTable(i), '\s+', ' '), '"', ''));

                testCase.verifyEqual(outRow, rowString(i-2), 'Row does not contain the correct data');

            end
        end

        function testParseContrastInput(testCase)
            expectedContrast = struct( ...
                'name', 'New Contrast', ...
                'data', 'Simulation', ...
                'background', 'Background SMW', ...
                'backgroundAction', backgroundActions.Subtract, ...
                'bulkIn', 'Silicon', ...
                'bulkOut', 'SLD SMW', ...
                'scalefactor', 'Test Scalefactor', ...
                'resolution', 'Test Resolution', ...
                'resample', true, ...
                'repeatLayers', 2, ...
                'domainRatio', 'Test Domain Ratio', ...
                'model', {{'Domain Contrast 1', 'Test Domain Contrast'}} ...
                );

            % If we are not running a domains calculation, raise an error
            testCase.verifyError(@() contrastsClass().parseContrastInput(testCase.allowedNames, testCase.newValues), 'MATLAB:InputParser:UnmatchedParameter');

            contrastStruct = testCase.exampleClass.parseContrastInput(testCase.allowedNames, testCase.newValues);
            testCase.verifyEqual(contrastStruct, expectedContrast, 'parseContrastInput does not work correctly');
        end

        function testParseContrastInputEmpty(testCase)
            % Test parsing input data for a contrast within the contrasts
            % class.
            % If the input is empty, we should return the default values
            emptyContrasts = contrastsClass(domains=true);

            % Need to change default contrast fields to empty defaults used
            % in parser
            expectedInputBlock = testCase.defaultContrastParams;
            expectedInputBlock.backgroundAction = '';
            expectedInputBlock.resample = [];
            expectedInputBlock.repeatLayers = [];

            testCase.verifyEqual(emptyContrasts.parseContrastInput(testCase.allowedNames, {}), expectedInputBlock);
        end

        function testParseContrastInputInvalidOption(testCase, invalidInput)
            % Test parsing input data for a contrast within the contrasts
            % class.
            % If values for each parameter are not valid options, we
            % should raise an error
            testCase.verifyError(@() testCase.exampleClass.parseContrastInput(testCase.allowedNames, invalidInput), 'RAT:NameNotRecognised');
        end

        function testParseContrastInputInvalidType(testCase)
            % Test parsing input data for a contrast within the contrasts
            % class.
            % If values for the name, resample and repeatLayers parameters
            % are an invalid type, we should raise an error
            testCase.verifyError(@() testCase.exampleClass.parseContrastInput(testCase.allowedNames, {'name', 42}), 'MATLAB:InputParser:ArgumentFailedValidation');
            testCase.verifyError(@() testCase.exampleClass.parseContrastInput(testCase.allowedNames, {'resample', datetime('today')}), 'MATLAB:InputParser:ArgumentFailedValidation');
            testCase.verifyError(@() testCase.exampleClass.parseContrastInput(testCase.allowedNames, {'repeatLayers', 'one'}), 'MATLAB:InputParser:ArgumentFailedValidation');
        end

        function testInvalidRepeatLayers(testCase)           
            % For repeatLayers, the type must be numeric, but also a
            % positive whole number
            testCase.verifyError(@() testCase.exampleClass.parseContrastInput(testCase.allowedNames, {'repeatLayers', [1 1]}), 'RAT:InvalidValue');
            testCase.verifyError(@() testCase.exampleClass.parseContrastInput(testCase.allowedNames, {'repeatLayers', 0}), 'RAT:InvalidValue');
            testCase.verifyError(@() testCase.exampleClass.parseContrastInput(testCase.allowedNames, {'repeatLayers', 1.5}), 'RAT:InvalidValue');
        end

    end

end
