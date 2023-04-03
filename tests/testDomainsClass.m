% Class based unit tests for the DomainsClass

classdef testDomainsClass < matlab.unittest.TestCase
        
    properties
        project
        parameters
        layers
        customFile
    end

    methods(TestMethodSetup)
        function createProject(testCase)
            testCase.project = domainsClass('example');
            testCase.parameters = {
                    %       Name                min     val     max  fit? 'Prior Type','mu','sigma'
                    {'Tails Thickness',         10,     20,     30,  true, priorTypes.Uniform.value, 0, Inf};
                    {'Heads Thickness',          3,     11,     16,  true, priorTypes.Uniform.value, 0, Inf};
                    {'Tails Roughness',          2,     5,      9,   true, priorTypes.Uniform.value, 0, Inf};
                    {'Heads Roughness',          2,     7,      9,   true, priorTypes.Uniform.value, 0, Inf};
                    {'Deuterated Tails SLD',    4e-6,   6e-6,   2e-5, true, priorTypes.Uniform.value, 0, Inf};
                    {'Hydrogenated Tails SLD', -0.6e-6, -0.4e-6, 0,  true, priorTypes.Uniform.value, 0, Inf};
                    {'Deuterated Heads SLD',    1e-6,   3e-6,   8e-6, true, priorTypes.Uniform.value, 0, Inf};
                    {'Hydrogenated Heads SLD',  0.1e-6,1.4e-6, 3e-6, true, priorTypes.Uniform.value, 0, Inf};
                    {'Heads Hydration',         0,      10,   0.5,  true, priorTypes.Uniform.value, 0, Inf};
                    {'Domain Ratio 1',          0.4,    0.5,  0.6,  false, priorTypes.Uniform.value, 0, Inf};
                };
            testCase.layers = { 
                  {'Hydrogenated Heads', 'Heads Thickness', 'Hydrogenated Heads SLD',...
                   'Heads Roughness', 'Heads Hydration', hydrationTypes.BulkOut.value };      
                  {'Deuterated Heads', 'Heads Thickness', 'Deuterated Heads SLD',...
                   'Heads Roughness', 'Heads Hydration', hydrationTypes.BulkOut.value };
                  {'Deuterated Tails', 'Tails Thickness', 'Deuterated Tails SLD',...
                   'Tails Roughness'};
                  {'Hydrogenated Tails', 'Tails Thickness', 'Hydrogenated Tails SLD',...
                   'Tails Roughness'};
                };
            testCase.customFile = {{'DSPC Model','customDSPCMonolayer.m','matlab','pwd'}};

        end
    end

    methods
        function addParameters(testCase)
            % Adds parameters for the tests
            paramsTable = testCase.project.parameters.paramsTable;
            testCase.project.parameters.paramsTable = [paramsTable; vertcat(testCase.parameters{:})];
        end
        
        function populateProject(testCase)
            % Populates project class properties for the tests
            testCase.addParameters()
            paramsTable = testCase.project.layers.layersTable;
            testCase.project.layers.layersTable = [paramsTable; vertcat(testCase.layers{1:2})];
            paramsTable = testCase.project.customFile.fileTable;
            testCase.project.customFile.fileTable = [paramsTable; vertcat(testCase.customFile{1})];
            testCase.project.resolution.resolutions.typesTable{1, 1} = "Resolution 2";
            testCase.project.background.backgrounds.typesTable{1, 1} = "Background H2O";
            testCase.project.data.dataTable{1, 1} = "Sim 1";
            
            typesTable = testCase.project.background.backgrounds.typesTable;
            testCase.project.background.backgrounds.typesTable = [typesTable; typesTable];
            testCase.project.background.backgrounds.typesTable{2, 1} = "Background D2O";

            paramsTable = testCase.project.bulkOut.paramsTable;
            testCase.project.bulkOut.paramsTable = [paramsTable; paramsTable];
            testCase.project.bulkOut.paramsTable{2, 1} = "SLD H2O";
            
            paramsTable = testCase.project.bulkIn.paramsTable;
            testCase.project.bulkIn.paramsTable = [paramsTable; paramsTable];
            testCase.project.bulkIn.paramsTable{2, 1} = "Silicon";

            dataTable = testCase.project.data.dataTable;
            testCase.project.data.dataTable = [dataTable; dataTable];
            testCase.project.data.dataTable{2, 1} = "Sim 2";
        end
    end

    methods (Test)

        function testCreation(testCase)
            % Tests domains class can be created and the experiment name is set correctly
            newProject = domainsClass();
            testCase.verifyEqual(newProject.experimentName, '', 'Experiment name not set correctly');
            newProject = domainsClass('New experiment');
            testCase.verifyEqual(newProject.experimentName, 'New experiment', 'Experiment name not set correctly');
            testCase.verifyError(@() domainsClass(1), 'MATLAB:validators:mustBeTextScalar')
        end

        function testDomainsContrast(testCase)
            % Populates project properties for the tests
            testCase.populateProject()
            % Checks the default contrast
            testCase.verifyEmpty(testCase.project.domainsContrasts.contrasts, 'contrast has wrong dimension');
            % Checks that contrast can be added
            testCase.project.addDomainsContrast('name', 'Bilayer / H2O', 'nbs', 'SLD D2O', 'nba', 'SLD Air');
            testCase.verifyLength(testCase.project.domainsContrasts.contrasts, 1, 'contrast has wrong dimension');
            testCase.verifyEqual(testCase.project.domainsContrasts.contrasts{1}.name, 'Bilayer / H2O', 'addContrast method not working');

            testCase.project.addDomainsContrast('name', 'Another Bilayer', 'nbs', 'SLD H2O', 'nba', 'Silicon');
            testCase.verifyLength(testCase.project.domainsContrasts.contrasts, 2, 'contrast has wrong dimension');
            testCase.verifyEqual(testCase.project.domainsContrasts.contrasts{2}.name, 'Another Bilayer', 'addContrast method not working');
            % Checks that contrast can be modified
            testCase.verifyError(@() testCase.project.setDomainsContrast(3, 'name', 'First Bilayer'), indexOutOfRange.errorID)
            testCase.verifyError(@() testCase.project.setDomainsContrast('Bilayer', 'name', 'First Bilayer'), nameNotRecognised.errorID)
            testCase.project.setDomainsContrast(1, 'name', 'First Bilayer', 'nbs', 'SLD H2O');
            testCase.verifyLength(testCase.project.domainsContrasts.contrasts, 2, 'contrast has wrong dimension');
            testCase.verifyEqual(testCase.project.domainsContrasts.contrasts{1}.name, 'First Bilayer', 'setContrast method not working');
            testCase.verifyEqual(testCase.project.domainsContrasts.contrasts{1}.nbs, 'SLD H2O', 'setContrast method not working');
            testCase.verifyEqual(testCase.project.domainsContrasts.contrasts{1}.nba, 'SLD Air', 'setContrast method not working');
            testCase.project.setDomainsContrast('First Bilayer', 'nba', 'Silicon');
            testCase.verifyEqual(testCase.project.domainsContrasts.contrasts{1}.name, 'First Bilayer', 'setContrast method not working');
            testCase.verifyEqual(testCase.project.domainsContrasts.contrasts{1}.nbs, 'SLD H2O', 'setContrast method not working');
            testCase.verifyEqual(testCase.project.domainsContrasts.contrasts{1}.nba, 'Silicon', 'setContrast method not working');
            % Checks that contrast can be removed
            testCase.project.removeDomainsContrast(1);
            testCase.verifyLength(testCase.project.domainsContrasts.contrasts, 1, 'contrast has wrong dimension');
            testCase.verifyEqual(testCase.project.domainsContrasts.contrasts{1}.name, 'Another Bilayer', 'addContrast method not working');
            % Checks the contrast model can be modified
            testCase.verifyLength(testCase.project.domainsContrasts.contrasts{1}.model, 0, 'contrast model has wrong dimension');       
            testCase.project.setDomainsContrastModel(1, {'Hydrogenated Heads', 'Deuterated Heads'});
            testCase.verifyEqual(testCase.project.domainsContrasts.contrasts{1}.model, {'Hydrogenated Heads', 'Deuterated Heads'}, 'setContrastModel method not working');
            testCase.project.setDomainsContrastModel('Another Bilayer', {'Deuterated Heads', 'Hydrogenated Heads'});
            testCase.verifyEqual(testCase.project.domainsContrasts.contrasts{1}.model, {'Deuterated Heads', 'Hydrogenated Heads'}, 'setContrastModel method not working');
            testCase.verifyError(@() testCase.project.setDomainsContrastModel(3, {}), indexOutOfRange.errorID)
            testCase.verifyError(@() testCase.project.setDomainsContrastModel('Bilayer', {}), nameNotRecognised.errorID);
            
            % FIXME setContrastModel crashes if the model type is custom 
        end


        function testToStruct(testCase)

            projectStruct = testCase.project.toStruct();
            testCase.verifyEqual(projectStruct.experimentName, testCase.project.experimentName, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.geometry, testCase.project.geometry, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.TF, calculationTypes.Domains.value, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.paramNames, {'Substrate Roughness'}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.backgroundNames, testCase.project.background.backgrounds.typesTable{:, 1}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.backgroundTypes, testCase.project.background.backgrounds.typesTable{:, 2}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.backParNames, ...
                                 {convertStringsToChars(testCase.project.background.backPars.paramsTable{:, 1})}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.resolutionNames, testCase.project.resolution.resolutions.typesTable{:, 1}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.resolutionTypes, testCase.project.resolution.resolutions.typesTable{:, 2}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.resolParNames, ...
                                 {convertStringsToChars(testCase.project.resolution.resolPars.paramsTable{:, 1})}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.resolutionNames, testCase.project.resolution.resolutions.typesTable{:, 1}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.scalefactorNames, {convertStringsToChars(testCase.project.scalefactors.paramsTable{:, 1})}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.qzshiftNames, {convertStringsToChars(testCase.project.qzshifts.paramsTable{:, 1})}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.nbairNames, {convertStringsToChars(testCase.project.bulkIn.paramsTable{:, 1})}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.nbsubNames, {convertStringsToChars(testCase.project.bulkOut.paramsTable{:, 1})}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.nbsubNames, {convertStringsToChars(testCase.project.bulkOut.paramsTable{:, 1})}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.layersNames, testCase.project.layers.layersTable{:, 1}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.nbsubNames, {convertStringsToChars(testCase.project.bulkOut.paramsTable{:, 1})}, 'toStruct method not working');

            % Populates project properties for the tests
            testCase.populateProject();
            testCase.project.modelType = modelTypes.CustomXY.value;
            testCase.project.addDomainsContrast('name', 'Bilayer / H2O', 'nbs', 'SLD D2O', 'nba', 'SLD Air');
            testCase.project.setDomainsContrastModel(1, 'DSPC Model');
            % Test properties are written to struct
            projectStruct = testCase.project.toStruct();
            testCase.verifyEqual(projectStruct.experimentName, testCase.project.experimentName, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.geometry, testCase.project.geometry, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.TF, calculationTypes.Domains.value, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.paramNames, reshape(convertStringsToChars(testCase.project.parameters.paramsTable{:, 1}), 1, []), 'toStruct method not working');
            testCase.verifyEqual(projectStruct.backgroundNames, testCase.project.background.backgrounds.typesTable{:, 1}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.backgroundTypes, testCase.project.background.backgrounds.typesTable{:, 2}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.backParNames, ...
                                 {convertStringsToChars(testCase.project.background.backPars.paramsTable{:, 1})}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.resolutionNames, testCase.project.resolution.resolutions.typesTable{:, 1}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.resolutionTypes, testCase.project.resolution.resolutions.typesTable{:, 2}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.resolParNames, ...
                                 {convertStringsToChars(testCase.project.resolution.resolPars.paramsTable{:, 1})}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.resolutionNames, testCase.project.resolution.resolutions.typesTable{:, 1}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.scalefactorNames, {convertStringsToChars(testCase.project.scalefactors.paramsTable{:, 1})}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.qzshiftNames, {convertStringsToChars(testCase.project.qzshifts.paramsTable{:, 1})}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.nbairNames, reshape(convertStringsToChars(testCase.project.bulkIn.paramsTable{:, 1}), 1, []), 'toStruct method not working');
            testCase.verifyEqual(projectStruct.nbsubNames, reshape(convertStringsToChars(testCase.project.bulkOut.paramsTable{:, 1}), 1, []), 'toStruct method not working');
            testCase.verifyEqual(projectStruct.nbsubNames, reshape(convertStringsToChars(testCase.project.bulkOut.paramsTable{:, 1}), 1, []), 'toStruct method not working');
            testCase.verifyEqual(projectStruct.layersNames, testCase.project.layers.layersTable{:, 1}, 'toStruct method not working');
        end

        function testObjectDisplay(testCase)
            % Check that the content of the project are printed 
            display = evalc('disp(testCase.project)');
            testCase.verifyNotEmpty(display, 'displayScalarObject method not working')
            testCase.verifySubstring(display, "experimentName: 'example'", 'displayScalarObject method not working')
        end
    end
end