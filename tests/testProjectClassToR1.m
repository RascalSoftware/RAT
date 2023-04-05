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
        fullPath
    end

    methods(TestClassSetup)
        function defineVariables(testCase)
            testCase.inputStandardProjectClass = "originalDSPCBilayerProjectClass.mat";
            testCase.inputStandardStruct = "originalDSPCBilayerStructInput.mat";
            testCase.outputStandardStruct = "originalDSPCBilayerStructOutput.mat";
            testCase.defaultProject = "defaultProject.mat";
            testCase.outputCustomStruct = "monolayerVolumeModel.mat";
            testCase.inputCustomProjectClass = "monolayerVolumeModelProjectClass.mat";
            testCase.modelFile = "monolayerVolumeCustomLayerModel.m";
            testCase.outputStandardStructWithR1Input = "originalDSPCBilayerStructOutputWithR1Input.mat";
        end
    end

    methods(TestMethodSetup)
        function setWorkingFolder(testCase)
            root = getappdata(0,'root');
            testCase.fullPath = fullfile(root, 'tests', 'testProjectConversion');
            import matlab.unittest.fixtures.CurrentFolderFixture
            testCase.applyFixture(CurrentFolderFixture(testCase.fullPath))
        end
    end 

     methods(TestMethodTeardown)
        function testCleanUp(testCase)
            cd (testCase.fullPath)
            if exist('newDirectory','dir')
                rmdir('newDirectory', 's')
            end
        end
    end 

    methods (Test)

        function testCompareProjectClassToR1(testCase)
            expected = load(testCase.outputStandardStruct).problem;
            pClass = load(testCase.inputStandardProjectClass).thisProjectClass; 
            result = projectClassToR1(pClass, "saveProject", false);
            testCase.verifyEqual(result, expected);
        end

        function testProjectClassConversionWithModification(testCase)
            pClass = load(testCase.inputStandardProjectClass).thisProjectClass;
            pClass.layers.layersTable.("Hydrate with")(1) = hydrationTypes.BulkIn.value;
            pClass.contrasts.contrasts{1}.data = 'Simulation';
            result = projectClassToR1(pClass, "saveProject", false);
            testCase.verifyEqual(result.layersDetails{1}{6}, char(pClass.layers.layersTable.("Hydrate with")(1)));
            testCase.verifyEqual(result.contrastTypes{1}, pClass.contrasts.contrasts{1}.data);
        end

        function testR1ProblemInput(testCase)
            input = load(testCase.inputStandardStruct).problem;
            pClass = load(testCase.inputStandardProjectClass).thisProjectClass;
            result = projectClassToR1(pClass, "r1Problem", input, "saveProject", false);
            expected = load(testCase.outputStandardStructWithR1Input).problem;
            testCase.verifyEqual(result, expected);
        end

        function testR1ProblemException(testCase)
            expected = load(testCase.outputStandardStruct).problem; % wrong r1 format
            pClass = load(testCase.inputStandardProjectClass).thisProjectClass;
            testCase.verifyError(@() projectClassToR1(pClass, "r1Problem", expected, "saveProject", false), unrecognizedR1Problem.errorID);
        end

        function testR1ProblemExtension(testCase)
            pClass = load(testCase.inputStandardProjectClass).thisProjectClass;
            projectClassToR1 (pClass, "fileName", 'testProject');

            import matlab.unittest.constraints.IsFile
            testCase.verifyThat(fullfile('newDirectory', 'testProject.mat'), IsFile);
            testCase.verifyThat(fullfile('newDirectory', 'datafiles', 'testProjectDatafile1'), IsFile);
            testCase.verifyThat(fullfile('newDirectory', 'datafiles', 'testProjectDatafile2'), IsFile);
        end

        function testR1ProblemWithCustomLayers(testCase)
            pClass = load(testCase.inputCustomProjectClass).thisProjectClass;
            filename = 'testCustomProject';
            projectClassToR1(pClass, "saveProject", true, "fileName", filename);

            import matlab.unittest.constraints.IsFile
            testCase.verifyThat(fullfile('newDirectory', [filename '.mat']), IsFile);

            for i = 1:7
                testCase.verifyThat(fullfile('newDirectory', 'datafiles', [filename 'Datafile' num2str(i)]), IsFile);
            end
        end
    end
end




