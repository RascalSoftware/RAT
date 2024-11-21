classdef testExamples < matlab.unittest.TestCase

    properties
        tolerance = 1.0e-12;     % Relative tolerance for equality of floats
        abs_tolerance = 1.0e-12;  % Absolute tolerance for equality of floats
    end

    properties (TestParameter)
        exampleFolder = {['normalReflectivity' filesep 'standardLayers'],...
                         ['normalReflectivity' filesep 'customLayers'],...
                         ['normalReflectivity' filesep 'customXY'],...
                         ['domains' filesep 'standardLayers'],...
                         ['domains' filesep 'customLayers'],...
                         ['domains' filesep 'customXY'],...
                         ['miscellaneous' filesep 'absorption'],...
                         ['miscellaneous' filesep 'backgroundTypes'],...
                         ['miscellaneous' filesep 'bayesBenchmark'],...
                         ['miscellaneous' filesep 'roundRobin'],...
                         ['miscellaneous' filesep 'convertRasCAL1Project']};
        exampleLiveScriptFile = {'domainsStandardLayersSheet', 'domainsCustomLayersSheet',... 
                                 'domainsCustomXYSheet', 'bayesBenchmark', 'convertRascal'}
        % exampleLiveScriptFile = {'domainsStandardLayersSheet', 'domainsCustomLayerSheet', 'domainsCustomXYSheet',... 
        %                          'customLayersDSPCSheet', 'standardLayersDSPCSheet', 'customXYDSPCSheet',...
        %                          'roundRobin', 'bayesBenchmark', 'convertRascal'}
        exampleScriptFile = {'standardLayersDSPCScript',...
                             'DSPCScriptWithDataBackground',...
                             'DSPCScriptWithFunctionBackground',...
                             'customLayersDSPCScript',...
                             'orsoCustomXYDSPC',...
                             'domainsStandardLayersScript', ...
                             'domainsCustomLayersScript',...
                             'domainsCustomXYScript',...
                             'absorptionDPPC50'};
        exampleName = {'original_dspc_bilayer', 'original_dspc_bilayer', 'original_dspc_bilayer',...
            'Orso lipid example - custom layers', 'Orso lipid example - custom XY',...
            '', '', '', 'DPPC_50_3pcBins'};
        exampleModel = {modelTypes.StandardLayers.value, modelTypes.StandardLayers.value,...
                        modelTypes.StandardLayers.value,modelTypes.CustomLayers.value,... 
                        modelTypes.CustomXY.value, modelTypes.StandardLayers.value,... 
                        modelTypes.CustomLayers.value, modelTypes.CustomXY.value,... 
                        modelTypes.CustomLayers.value};
        exampleContrastCount = {2, 2, 2, 3, 3, 1, 1, 3, 4};
        exampleLayerCount = {6, 6, 6, 0, 0, 3, 0, 0, 0};
        exampleGeometry = {geometryOptions.SubstrateLiquid.value,...
                           geometryOptions.SubstrateLiquid.value,...
                           geometryOptions.SubstrateLiquid.value,...
                           geometryOptions.SubstrateLiquid.value,...
                           geometryOptions.SubstrateLiquid.value,...
                           geometryOptions.AirSubstrate.value,...
                           geometryOptions.SubstrateLiquid.value,...
                           geometryOptions.SubstrateLiquid.value,...
                           geometryOptions.SubstrateLiquid.value};
        exampleParameterRowCount = {21, 21, 21, 8, 7, 13, 8, 6, 19};
        exampleBulkOutRowCount = {2, 2, 2, 3, 3, 1, 1, 3, 2};
        exampleBackgroundsTypesCount = {2, 2, 2, 3, 3, 1, 1, 1, 4};
        exampleDataCount = {3, 4, 3, 4, 4, 1, 1, 1, 5};
        exampleScalefactorRowCount = {2, 2, 2, 1, 1, 1, 1, 1, 4};
    end

    methods(TestClassSetup)
        function addExamplePaths(testCase)
            import matlab.unittest.fixtures.WorkingFolderFixture;
            testCase.applyFixture(WorkingFolderFixture);
            copyfile(fullfile(getappdata(0, 'root'), 'examples'), fullfile(pwd, 'examples'))
            for i = 1:length(testCase.exampleFolder)
                addpath(fullfile(pwd, 'examples', testCase.exampleFolder{1,i}));
            end
        end
    end

    methods(TestClassTeardown)
        function testCleanUp(testCase)
            for i = 1:length(testCase.exampleFolder)
                rmpath(fullfile(pwd, 'examples', testCase.exampleFolder{1,i}));
            end
        end
    end

    methods (Test,ParameterCombination="sequential")
        % Runs the different examples sequentially
        function testScriptExamples(testCase, ...
                exampleScriptFile, ...
                exampleName, ...
                exampleModel, ...
                exampleContrastCount, ...
                exampleLayerCount, ...
                exampleGeometry, ...
                exampleParameterRowCount, ...
                exampleBulkOutRowCount, ...
                exampleBackgroundsTypesCount, ...
                exampleDataCount, ...
                exampleScalefactorRowCount)

            % verifies example exists with .m extension
            testCase.verifyEqual(exist(exampleScriptFile,'file'), 2);
            import matlab.unittest.fixtures.CurrentFolderFixture

            [pwdPath, ~, ~] = fileparts(which(exampleScriptFile));
            testCase.applyFixture(CurrentFolderFixture(pwdPath))  

            % runs the example file
            evalc(exampleScriptFile);

            % verifies the problem name, model type and geometry
            testCase.verifyEqual(problem.experimentName, exampleName);
            testCase.verifyEqual(problem.modelType, exampleModel);
            testCase.verifyEqual(problem.geometry, exampleGeometry);

            % verifies the count of problem properties
            testCase.verifyEqual(problem.contrasts.numberOfContrasts, exampleContrastCount);
            testCase.verifyEqual(problem.parameters.rowCount, exampleParameterRowCount);
            testCase.verifyEqual(problem.bulkOut.rowCount, exampleBulkOutRowCount);
            testCase.verifyEqual(problem.background.backgrounds.rowCount, exampleBackgroundsTypesCount);
            testCase.verifyEqual(problem.data.rowCount, exampleDataCount);
            testCase.verifyEqual(problem.scalefactors.rowCount, exampleScalefactorRowCount);
            if isa(problem.layers, 'layersClass')
                testCase.verifyEqual(problem.layers.rowCount, exampleLayerCount);
            end

            % Problem properties that are consistent across examples
            testCase.verifyEqual(problem.bulkIn.rowCount, 1);
            testCase.verifyEqual(problem.qzshifts.rowCount, 1);
            %testCase.verifyEqual(problem.resolution.resolutions.rowCount, 1);

            % closes all the figures generated by the examples
            close all;
        end

        function testLiveScriptExamples(~, exampleLiveScriptFile)
            % runs the example live script file
            evalc(exampleLiveScriptFile);
            close all;
        end

        function testWriteScript(testCase, exampleScriptFile)
            % Test that a the example projectClass objects can be written
            % to a script that can regenerate the object
            % verifies example exists with .m extension
            testCase.verifyEqual(exist(exampleScriptFile,'file'), 2);
            import matlab.unittest.fixtures.CurrentFolderFixture

            [pwdPath, ~, ~] = fileparts(which(exampleScriptFile));
            testCase.applyFixture(CurrentFolderFixture(pwdPath))  

            % runs the example file
            evalc(exampleScriptFile);

            % closes all the figures generated by the examples
            close all;

            % Write the script using a deep copy of the project 
            clonedProblem = problem.clone();
            testCase.verifyNotEqual(clonedProblem, problem);
            clonedProblem.writeScript(objName="scriptProblem", script="projectScript");
            run("projectScript.m");

            % Test general properties
            testCase.verifyEqual(problem.experimentName, scriptProblem.experimentName, 'experimentName is not correctly regenerated by the script')
            testCase.verifyEqual(problem.calculationType, scriptProblem.calculationType, 'calculationType is not correctly regenerated by the script')
            testCase.verifyEqual(problem.modelType, scriptProblem.modelType, 'modelType is not correctly regenerated by the script')
            testCase.verifyEqual(problem.geometry, scriptProblem.geometry, 'geometry is not correctly regenerated by the script')
            testCase.verifyEqual(problem.absorption, scriptProblem.absorption, 'absorption is not correctly regenerated by the script')
            testCase.verifyEqual(problem.showPriors, scriptProblem.showPriors, 'showPriors is not correctly regenerated by the script')

            % Test properties
            testCase.verifyEqual(problem.parameters.varTable, scriptProblem.parameters.varTable, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance, 'parameters are not correctly regenerated by the script')
            testCase.verifyEqual(problem.bulkIn.varTable, scriptProblem.bulkIn.varTable, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance, 'bulkIn parameters are not correctly regenerated by the script')
            testCase.verifyEqual(problem.bulkOut.varTable, scriptProblem.bulkOut.varTable, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance, 'bulkOut parameters are not correctly regenerated by the script')
            testCase.verifyEqual(problem.scalefactors.varTable, scriptProblem.scalefactors.varTable, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance, 'scalefactors are not correctly regenerated by the script')
            testCase.verifyEqual(problem.qzshifts.varTable, scriptProblem.qzshifts.varTable, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance, 'qz shifts are not correctly regenerated by the script')

            % Test backgrounds and resolutions
            testCase.verifyEqual(problem.background.backgroundParams.varTable, scriptProblem.background.backgroundParams.varTable, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance, 'background parameters are not correctly regenerated by the script')
            testCase.verifyEqual(problem.background.backgrounds.varTable, scriptProblem.background.backgrounds.varTable, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance, 'backgrounds are not correctly regenerated by the script')
            testCase.verifyEqual(problem.resolution.resolutionParams.varTable, scriptProblem.resolution.resolutionParams.varTable, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance, 'resolution parameters not correctly regenerated by the script')
            testCase.verifyEqual(problem.resolution.resolutions.varTable, scriptProblem.resolution.resolutions.varTable, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance, 'resolutions are not correctly regenerated by the script')

            % Test string classes and data
            if isa(problem.layers, 'layersClass')
                testCase.verifyEqual(problem.layers.varTable, scriptProblem.layers.varTable, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance, 'layers are not correctly regenerated by the script')
            end
            testCase.verifyEqual(problem.customFile.varTable, scriptProblem.customFile.varTable, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance, 'custom files are not correctly regenerated by the script')
            testCase.verifyEqual(problem.data.varTable, scriptProblem.data.varTable, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance, 'data are not correctly regenerated by the script')

            % Test contrasts
            testCase.assertEqual(problem.contrasts.numberOfContrasts, scriptProblem.contrasts.numberOfContrasts, 'numberOfContrasts is not correctly regenerated by the script')
            for i=1:length(problem.contrasts.contrasts)
                testCase.verifyEqual(problem.contrasts.contrasts{i}, scriptProblem.contrasts.contrasts{i}, sprintf('contrast %d is not correctly regenerated by the script', i))
            end

            testCase.verifyEqual(problem.contrasts.domainsCalc, scriptProblem.contrasts.domainsCalc, 'contrasts domainsCalc is not correctly regenerated by the script')
            testCase.verifyEqual(problem.contrasts.oilWaterCalc, scriptProblem.contrasts.oilWaterCalc, 'contrasts oilWaterCalc is not correctly regenerated by the script')
            testCase.verifyEqual(problem.contrasts.displayNames, scriptProblem.contrasts.displayNames, 'contrasts displayNames is not correctly regenerated by the script')
        end
    end
end
