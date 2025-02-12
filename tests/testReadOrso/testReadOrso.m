classdef testReadOrso < matlab.unittest.TestCase

    properties
        input
        expected
    end

    properties (TestParameter)
        file = {'prist5_10K_m_025.Rqz', 'polref_data'}
    end

    methods(TestClassSetup)
        function addDataPath(testCase)
            import matlab.unittest.fixtures.PathFixture
            path = fullfile(getappdata(0, 'root'), 'tests', 'testReadOrso');
            testCase.applyFixture(PathFixture(path))  
        end
        function setWorkingFolder(testCase)
            import matlab.unittest.fixtures.WorkingFolderFixture;
            testCase.applyFixture(WorkingFolderFixture);
        end
    end

    methods (Test, ParameterCombination='exhaustive')
        function testOrsoReader(testCase, file)
            expected_data = load(append(file, ".mat")).arr;
            result = readOrso(append(file, ".ort"));
            for i=1:length(expected_data)
                testCase.verifyEqual(expected_data{i}, result{i})
            end
        end
    end

end