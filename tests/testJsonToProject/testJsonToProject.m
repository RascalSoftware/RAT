classdef testJsonToProject < matlab.unittest.TestCase

    properties
        input
        expected
    end

    properties (TestParameter)
        file = {'absorption', ...
            'domains_custom_layers', ...
            'domains_custom_XY', ...
            'domains_standard_layers', ...
            'DSPC_custom_layers', ...
            'DSPC_custom_XY', ...
            'DSPC_standard_layers'}
    end

    methods(TestClassSetup)
        function addDataPath(testCase)
            import matlab.unittest.fixtures.PathFixture
            path = fullfile(getappdata(0, 'root'), 'tests', 'testJsonToProject');
            testCase.applyFixture(PathFixture(path))  
        end
        function setWorkingFolder(testCase)
            import matlab.unittest.fixtures.WorkingFolderFixture;
            testCase.applyFixture(WorkingFolderFixture);
        end
    end

    % test that JSON to Project successfully converts projects
    methods (Test, ParameterCombination='exhaustive')
        function testJsonConversion(testCase, file)
            jsonToProject(append(file, ".json"));
        end
    end

end