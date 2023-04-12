classdef testR1ToProjectClass < matlab.unittest.TestCase

    properties
        input
        output
    end

    methods(TestClassSetup)
        function defineIO(testCase)
            testCase.input = 'originalDSPCBilayerStructInput.mat';
            testCase.output = 'originalDSPCBilayerProjectClass.mat';
        end

        function setWorkingFolder(testCase)
            import matlab.unittest.fixtures.WorkingFolderFixture;
            testCase.applyFixture(WorkingFolderFixture);
        end
    end

    methods (Test)

        function testCompareR1AndProjectClass(testCase)
            expected = load(testCase.output).thisProjectClass;
            result = r1ToProjectClass(testCase.input);
            testCase.verifyEqual(result, expected);
        end

        function testR1ConversionWithModification(testCase)
            problem = load(testCase.input).problem;

            problem.name = 'original_dspc_bilayer';
            problem.module.type = 'Custom Layers';
            problem.module.experiment_type = 'Air / Liquid (or solid)';
            save('tempStruct', 'problem');

            result = r1ToProjectClass('tempStruct.mat');

            testCase.verifyEqual(result.experimentName, 'original_dspc_bilayer');
            testCase.verifyEqual(result.modelType, modelTypes.CustomLayers.value);
            testCase.verifyEqual(result.geometry, geometryOptions.AirSubstrate.value);

            problem.module.type = 'Custom XY';
            save('tempStruct', 'problem');

            result = r1ToProjectClass('tempStruct.mat');

            testCase.verifyEqual(result.modelType, modelTypes.CustomXY.value);
        end

        function testStrToDoubleConversions(testCase)
            problem = load(testCase.input).problem;

            problem.layersDetails{1}{1} = '2'; % Thickness
            problem.layersDetails{1}{2} = '3'; % SLD
            problem.layersDetails{1}{3} = '1'; % Roughness
            problem.layersDetails{1}{4} = '21'; % Roughness
            save('tempStruct', 'problem');

            result = r1ToProjectClass('tempStruct.mat');

            testCase.verifyEqual(result.layers.layersTable.Thickness(1), convertCharsToStrings(problem.paramnames{2}));
            testCase.verifyEqual(result.layers.layersTable.SLD(1), convertCharsToStrings(problem.paramnames{3}));
            testCase.verifyEqual(result.layers.layersTable.Roughness(1), convertCharsToStrings(problem.paramnames{1}));
            testCase.verifyEqual(result.layers.layersTable.Hydration(1), convertCharsToStrings(problem.paramnames{21}));
        end

        function testEmptyStrs(testCase)
            problem = load(testCase.input).problem;

            problem.layersDetails{1}{4} = ''; % Empty Hydration
            save('tempStruct', 'problem');

            result = r1ToProjectClass('tempStruct.mat');

            testCase.verifyEqual(result.layers.layersTable.Hydration(1), missing);
        end
    end
end




