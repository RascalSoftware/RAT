classdef testProjectClassToR1 < matlab.unittest.TestCase

    properties
        inputStandardProjectClass
        inputStandardStruct
        outputStandardStruct
        defaultProject
        outputCustomStruct
        inputCustomProjectClass
        outputStandardStructWithR1Input
        modelFile
        tolerance = 1.0e-12     % Relative tolerance for equality of floats
        absTolerance = 1.0e-5   % Absolute tolerance for equality of floats
    end

    methods(TestClassSetup)
        function defineVariables(testCase)
            testCase.inputStandardProjectClass = 'DSPCBilayerProjectClass.mat';
            testCase.inputStandardStruct = 'DSPCBilayerStructInput.mat';
            testCase.outputStandardStruct = 'DSPCBilayerStructOutput.mat';
            testCase.defaultProject = 'defaultProject.mat';
            testCase.outputCustomStruct = 'monolayerVolumeModel.mat';
            testCase.inputCustomProjectClass = 'monolayerVolumeModelProjectClass.mat';
            testCase.modelFile = 'monolayerVolumeCustomLayerModel.m';
            testCase.outputStandardStructWithR1Input = 'DSPCBilayerStructOutputWithR1Input.mat';
        end
    end

    methods(TestMethodSetup)
        function setWorkingFolder(testCase)
            import matlab.unittest.fixtures.WorkingFolderFixture;
            testCase.applyFixture(WorkingFolderFixture);
        end
    end 

    methods (Test)

        function testCompareProjectClassToR1(testCase)
            expected = load(testCase.outputStandardStruct).problem;
            pClass = load(testCase.inputStandardProjectClass).thisProjectClass; 
            result = projectClassToR1(pClass, 'saveProject', false);
            testCase.verifyEqual(result, expected, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

        function testProjectClassConversionWithModification(testCase)
            pClass = load(testCase.inputStandardProjectClass).thisProjectClass;
            pClass.layers.paramTable.('Hydrate with')(1) = hydrationTypes.BulkIn.value;
            pClass.contrasts.contrasts{1}.data = 'Simulation';
            result = projectClassToR1(pClass, 'saveProject', false);
            testCase.verifyEqual(result.layersDetails{1}{6}, char(pClass.layers.paramTable.('Hydrate with')(1)));
            testCase.verifyEqual(result.contrastTypes{1}, pClass.contrasts.contrasts{1}.data);
        end

        function testR1ProblemInput(testCase)
            input = load(testCase.inputStandardStruct).problem;
            pClass = load(testCase.inputStandardProjectClass).thisProjectClass;
            result = projectClassToR1(pClass, 'r1Problem', input, 'saveProject', false);
            expected = load(testCase.outputStandardStructWithR1Input).problem;
            testCase.verifyEqual(result, expected, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

        function testR1ProblemException(testCase)
            expected = load(testCase.outputStandardStruct).problem; % wrong r1 format
            pClass = load(testCase.inputStandardProjectClass).thisProjectClass;
            testCase.verifyError(@() projectClassToR1(pClass, 'r1Problem', expected, 'saveProject', false), unrecognizedR1Problem.errorID);
        end

        function testR1ProblemExtension(testCase)
            pClass = load(testCase.inputStandardProjectClass).thisProjectClass;
            projectClassToR1 (pClass, 'fileName', 'testProject');

            import matlab.unittest.constraints.IsFile
            testCase.verifyThat(fullfile('newDirectory', 'testProject.mat'), IsFile);
            testCase.verifyThat(fullfile('newDirectory', 'datafiles', 'testProjectDatafile1'), IsFile);
            testCase.verifyThat(fullfile('newDirectory', 'datafiles', 'testProjectDatafile2'), IsFile);
        end

        function testR1ProblemWithCustomLayers(testCase)
            pClass = load(testCase.inputCustomProjectClass).thisProjectClass;
            
            testModel = fopen('monolayerVolumeCustomLayerModel.m','w'); 
            fprintf(testModel, ['function [output,sub_rough] = monolayerVolumeCustomLayerModel(params,bulk_in,bulk_out,contrast)\n' ...
                'output = [18.8615    0.0000    2.6509;\n'...
                          '12.8479    0.0000    2.6509;];\n'...
                 'sub_rough = 2.6509;\n'...
                'end\n']);
            fclose(testModel);
            
            filename = 'testCustomProject';
            projectClassToR1(pClass, 'saveProject', true, 'fileName', filename);

            import matlab.unittest.constraints.IsFile
            testCase.verifyThat(fullfile('newDirectory', [filename '.mat']), IsFile);

            for i = 1:7
                testCase.verifyThat(fullfile('newDirectory', 'datafiles', [filename 'Datafile' num2str(i)]), IsFile);
            end
        end
    end
end




