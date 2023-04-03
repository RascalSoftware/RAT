classdef testR1ToProjectClass < matlab.unittest.TestCase

    properties
        input
        output
    end

    methods(TestClassSetup)
        function defineIO(testCase)
            testCase.input = "originalDSPCBilayerStructInput.mat";
            testCase.output = "originalDSPCBilayerProjectClass.mat";
        end

        function setWorkingFolder(testCase)
            import matlab.unittest.fixtures.WorkingFolderFixture;
            testCase.applyFixture(WorkingFolderFixture);
        end
    end

    methods (Test)

        function testFilesExist(testCase)
            testCase.verifyEqual(exist(testCase.input,'file'), 2);
            testCase.verifyEqual(exist(testCase.output,'file'), 2);
        end

        function testCompareR1AndProjectClass(testCase)
            expected = load(testCase.output).thisProjectClass;
            result = r1ToProjectClass(testCase.input);

            testCase.verifyEqual(result.experimentName, expected.experimentName);

            testCase.verifyEqual(result.geometry, expected.geometry);

            testCase.verifyEqual(result.parameters.paramCount, expected.parameters.paramCount);
            testCase.verifyEqual(result.parameters.showPriors, expected.parameters.showPriors);
            testCase.verifyEqual(result.parameters.paramsTable, expected.parameters.paramsTable);

            testCase.verifyEqual(result.layers.layersCount, expected.layers.layersCount);
            testCase.verifyEqual(result.layers.layersTable, expected.layers.layersTable);

            testCase.verifyEqual(result.bulkIn.paramCount, expected.bulkIn.paramCount);
            testCase.verifyEqual(result.bulkIn.showPriors, expected.bulkIn.showPriors);
            testCase.verifyEqual(result.bulkIn.paramsTable, expected.bulkIn.paramsTable);

            testCase.verifyEqual(result.bulkOut.paramCount, expected.bulkOut.paramCount);
            testCase.verifyEqual(result.bulkOut.showPriors, expected.bulkOut.showPriors);
            testCase.verifyEqual(result.bulkOut.paramsTable, expected.bulkOut.paramsTable);

            testCase.verifyEqual(result.background.showPriors, expected.background.showPriors);

            testCase.verifyEqual(result.background.backPars.paramCount, expected.background.backPars.paramCount);
            testCase.verifyEqual(result.background.backPars.showPriors, expected.background.backPars.showPriors);
            testCase.verifyEqual(result.background.backPars.paramsTable, expected.background.backPars.paramsTable);

            testCase.verifyEqual(result.background.backgrounds.typesCount, expected.background.backgrounds.typesCount);
            testCase.verifyEqual(result.background.backgrounds.typesAutoNameString, expected.background.backgrounds.typesAutoNameString);
            testCase.verifyEqual(result.background.backgrounds.allowedActions, expected.background.backgrounds.allowedActions);
            testCase.verifyEqual(result.background.backgrounds.typesTable, expected.background.backgrounds.typesTable);

            testCase.verifyEqual(result.scalefactors.paramCount, expected.scalefactors.paramCount);
            testCase.verifyEqual(result.scalefactors.showPriors, expected.scalefactors.showPriors);
            testCase.verifyEqual(result.scalefactors.paramsTable, expected.scalefactors.paramsTable);

            testCase.verifyEqual(result.qzshifts.paramCount, expected.qzshifts.paramCount);
            testCase.verifyEqual(result.qzshifts.showPriors, expected.qzshifts.showPriors);
            testCase.verifyEqual(result.qzshifts.paramsTable, expected.qzshifts.paramsTable);

            testCase.verifyEqual(result.resolution.showPriors, expected.resolution.showPriors);

            testCase.verifyEqual(result.resolution.resolPars.paramCount, expected.resolution.resolPars.paramCount);
            testCase.verifyEqual(result.resolution.resolPars.showPriors, expected.resolution.resolPars.showPriors);
            testCase.verifyEqual(result.resolution.resolPars.paramsTable, expected.resolution.resolPars.paramsTable);

            testCase.verifyEqual(result.resolution.resolutions.typesCount, expected.resolution.resolutions.typesCount);
            testCase.verifyEqual(result.resolution.resolutions.typesAutoNameString, expected.resolution.resolutions.typesAutoNameString);
            testCase.verifyEqual(result.resolution.resolutions.allowedActions, expected.resolution.resolutions.allowedActions);
            testCase.verifyEqual(result.resolution.resolutions.typesTable, expected.resolution.resolutions.typesTable);

            testCase.verifyEqual(result.contrasts.contrasts, expected.contrasts.contrasts);
            testCase.verifyEqual(result.contrasts.numberOfContrasts, expected.contrasts.numberOfContrasts);

            testCase.verifyEqual(result.data.dataCount, expected.data.dataCount);
            testCase.verifyEqual(result.data.dataTable, expected.data.dataTable);

            testCase.verifyEqual(result.customFile.fileCount, expected.customFile.fileCount);
            testCase.verifyEqual(result.customFile.fileTable, expected.customFile.fileTable);

            testCase.verifyEqual(result.usePriors, expected.usePriors);

            testCase.verifyEqual(result.modelType, expected.modelType);

        end

        function testR1ConversionWithModification(testCase)
            problem = load(testCase.input).problem;

            problem.name = 'original_dspc_bilayer';
            problem.module.type = 'Custom Layers';
            problem.module.experiment_type = 'Air / Liquid (or solid)';
            save("tempStruct", "problem");

            result = r1ToProjectClass("tempStruct.mat");

            testCase.verifyEqual(result.experimentName, 'original_dspc_bilayer');
            testCase.verifyEqual(result.modelType, modelTypes.CustomLayers.value);
            testCase.verifyEqual(result.geometry, geometryOptions.AirSubstrate.value);

            problem.module.type = 'Custom XY';
            save("tempStruct", "problem");

            result = r1ToProjectClass("tempStruct.mat");

            testCase.verifyEqual(result.modelType, modelTypes.CustomXY.value);
        end

        function testStrToDoubleConversions(testCase)
            problem = load(testCase.input).problem;

            problem.layersDetails{1}{1} = '2'; % Thickness
            problem.layersDetails{1}{2} = '3'; % SLD
            problem.layersDetails{1}{3} = '1'; % Roughness
            problem.layersDetails{1}{4} = '21'; % Roughness
            save("tempStruct", "problem");

            result = r1ToProjectClass("tempStruct.mat");

            testCase.verifyEqual(result.layers.layersTable.Thickness(1), convertCharsToStrings(problem.paramnames{2}));
            testCase.verifyEqual(result.layers.layersTable.SLD(1), convertCharsToStrings(problem.paramnames{3}));
            testCase.verifyEqual(result.layers.layersTable.Roughness(1), convertCharsToStrings(problem.paramnames{1}));
            testCase.verifyEqual(result.layers.layersTable.Hydration(1), convertCharsToStrings(problem.paramnames{21}));
        end

        function testEmptyStrs(testCase)
            problem = load(testCase.input).problem;

            problem.layersDetails{1}{4} = ''; % Empty Hydration
            save("tempStruct", "problem");

            result = r1ToProjectClass("tempStruct.mat");

            testCase.verifyEqual(result.layers.layersTable.Hydration(1), missing);
        end
    end
end




