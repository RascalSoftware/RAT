classdef testReadOrso < matlab.unittest.TestCase

    properties
        input
        expected
    end

    methods(TestClassSetup)
        function addDataPath(testCase)
            import matlab.unittest.fixtures.PathFixture
            path = fullfile(getappdata(0, 'root'), 'tests', 'testProjectConversion');
            testCase.applyFixture(PathFixture(path))  
        end

        function defineIO(testCase)
            testCase.input = 'prist5_10K_m_025.Rqz.ort';
            testCase.expected = 'expectedOrsoData.mat';
        end

        function setWorkingFolder(testCase)
            import matlab.unittest.fixtures.WorkingFolderFixture;
            testCase.applyFixture(WorkingFolderFixture);
        end
    end

    methods (Test)
        function testOrsoReader(testCase)
            expected_data = load('orsoData.mat').arr;
            result = readOrso(testCase.input);
            testCase.verifyEqual(expected_data, result)
        end
    end

end