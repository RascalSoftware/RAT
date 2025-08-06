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

        resultFile = {'result', ...
            'result_bayes'}
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
    methods (Test)
        function testJsonConversion(testCase, file)
            project = jsonToProject(append(file, ".json"));
            projectToJson(project, "test.json");
            project2 = jsonToProject("test.json");

            props = properties(project);
            for i = 1:length(props)
                testCase.verifyEqual(project.(props{i}), project2.(props{i}));
            end
        end

       function testJsonResultConversion(testCase, resultFile)
            result = jsonToResults(append(resultFile, ".json"));
            resultsToJson(result, "test.json");
            result2 = jsonToResults("test.json");

            props = properties(result);
            for i = 1:length(props)
                testCase.verifyEqual(result.(props{i}), result2.(props{i}));
            end
       end

       function testJsonControlsConversion(testCase)
            controls = controlsClass();
            controls.numSimulationPoints = 100;
            controls.xTolerance = 19;
            controls.populationSize = 200;
            controls.nLive = 140;
            controls.nSamples = 200;

            controlsToJson(controls, "test.json");
            controls2 = jsonToControls("test.json");

            props = properties(controls);
            for i = 1:length(props)
                testCase.verifyEqual(controls.(props{i}), controls2.(props{i}));
            end
        end
    end

end