% Class based unit tests for the DomainsClass

classdef testDomainsClass < matlab.unittest.TestCase
        
    properties
        project
        parameters
        layers
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
            testCase.verifyEqual(newProject.calculationType, calculationTypes.Domains.value, 'Calculation Type not set correctly');
            newProject = domainsClass('New experiment');
            testCase.verifyEqual(newProject.experimentName, 'New experiment', 'Experiment name not set correctly');
            testCase.verifyEqual(newProject.calculationType, calculationTypes.Domains.value, 'Calculation Type not set correctly');
            testCase.verifyError(@() domainsClass(1), 'MATLAB:validators:mustBeTextScalar')
        end
        
        function testDomainRatio(testCase)
            % Checks the default domain ratios
            testCase.verifySize(testCase.project.domainRatio.paramsTable, [1, 8], 'domain ratio has wrong dimension');
            testCase.verifyEqual(string(testCase.project.domainRatio.paramsTable{1, :}),...
                                    string({'Domain Ratio 1', 0.4, 0.5, 0.6, false, 'uniform', 0, Inf}), 'default domain ratio is not correct');
            % Checks that domain ratios can be added
            testCase.project.addDomainRatio('Domain Ratio 2', 0.4, 0.69, 1.0, true);
            testCase.project.addDomainRatio('Domain Ratio 3', 0.2, 0.17, 1.1, false);
            testCase.verifySize(testCase.project.domainRatio.paramsTable, [3, 8], 'domain ratio has wrong dimension');
            testCase.verifyEqual(testCase.project.domainRatio.paramsTable{end,1}, "Domain Ratio 3", 'addDomainRatio method not working');
            % Checks that domain ratios can be removed
            testCase.project.removeDomainRatio(2);
            testCase.verifySize(testCase.project.domainRatio.paramsTable, [2, 8], 'domain ratio has wrong dimension');
            testCase.verifyEqual(testCase.project.domainRatio.paramsTable{:, 1}, ["Domain Ratio 1"; "Domain Ratio 3"], 'removeDomainRatio method not working');
            % Checks that domain ratios can be modified
            testCase.project.setDomainRatio(1, 'name','Domain Ratio 1','min',0.1,'value',0.23251,'max',0.4,'fit',true);
            testCase.verifyEqual(string(testCase.project.domainRatio.paramsTable{1, :}),...
                                    string({'Domain Ratio 1', 0.1, 0.23251, 0.4, true, priorTypes.Uniform.value, 0, Inf}), 'domainRatio method not working');
        end

        function testDomainContrast(testCase)
            % Populates project properties for the tests
            testCase.populateProject()
            % Checks the default contrast
            testCase.verifyEmpty(testCase.project.domainContrasts.contrasts, 'contrast has wrong dimension');
            % Checks that contrast can be added
            testCase.project.addDomainContrast('name', 'Bilayer / H2O', 'nbs', 'SLD D2O', 'nba', 'SLD Air');
            testCase.verifyLength(testCase.project.domainContrasts.contrasts, 1, 'contrast has wrong dimension');
            testCase.verifyEqual(testCase.project.domainContrasts.contrasts{1}.name, 'Bilayer / H2O', 'addContrast method not working');

            testCase.project.addDomainContrast('name', 'Another Bilayer', 'nbs', 'SLD H2O', 'nba', 'Silicon');
            testCase.verifyLength(testCase.project.domainContrasts.contrasts, 2, 'contrast has wrong dimension');
            testCase.verifyEqual(testCase.project.domainContrasts.contrasts{2}.name, 'Another Bilayer', 'addContrast method not working');
            % Checks that contrast can be modified
            testCase.verifyError(@() testCase.project.setDomainContrast(3, 'name', 'First Bilayer'), indexOutOfRange.errorID)
            testCase.verifyError(@() testCase.project.setDomainContrast('Bilayer', 'name', 'First Bilayer'), nameNotRecognised.errorID)
            testCase.project.setDomainContrast(1, 'name', 'First Bilayer', 'nbs', 'SLD H2O');
            testCase.verifyLength(testCase.project.domainContrasts.contrasts, 2, 'contrast has wrong dimension');
            testCase.verifyEqual(testCase.project.domainContrasts.contrasts{1}.name, 'First Bilayer', 'setContrast method not working');
            testCase.verifyEqual(testCase.project.domainContrasts.contrasts{1}.nbs, 'SLD H2O', 'setContrast method not working');
            testCase.verifyEqual(testCase.project.domainContrasts.contrasts{1}.nba, 'SLD Air', 'setContrast method not working');
            testCase.project.setDomainContrast('First Bilayer', 'nba', 'Silicon');
            testCase.verifyEqual(testCase.project.domainContrasts.contrasts{1}.name, 'First Bilayer', 'setContrast method not working');
            testCase.verifyEqual(testCase.project.domainContrasts.contrasts{1}.nbs, 'SLD H2O', 'setContrast method not working');
            testCase.verifyEqual(testCase.project.domainContrasts.contrasts{1}.nba, 'Silicon', 'setContrast method not working');
            % Checks that contrast can be removed
            testCase.project.removeDomainContrast(1);
            testCase.verifyLength(testCase.project.domainContrasts.contrasts, 1, 'contrast has wrong dimension');
            testCase.verifyEqual(testCase.project.domainContrasts.contrasts{1}.name, 'Another Bilayer', 'addContrast method not working');
            % Checks the contrast model can be modified
            testCase.verifyLength(testCase.project.domainContrasts.contrasts{1}.model, 0, 'contrast model has wrong dimension');       
            testCase.project.setDomainContrastModel(1, {'Hydrogenated Heads', 'Deuterated Heads'});
            testCase.verifyEqual(testCase.project.domainContrasts.contrasts{1}.model, {'Hydrogenated Heads', 'Deuterated Heads'}, 'setContrastModel method not working');
            testCase.project.setDomainContrastModel('Another Bilayer', {'Deuterated Heads', 'Hydrogenated Heads'});
            testCase.verifyEqual(testCase.project.domainContrasts.contrasts{1}.model, {'Deuterated Heads', 'Hydrogenated Heads'}, 'setContrastModel method not working');
            testCase.verifyError(@() testCase.project.setDomainContrastModel(3, {}), indexOutOfRange.errorID)
            testCase.verifyError(@() testCase.project.setDomainContrastModel('Bilayer', {}), nameNotRecognised.errorID);
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

            nContrasts = testCase.project.contrasts.numberOfContrasts;
            contrastNames = cell(1,nContrasts);
            for i = 1:nContrasts
                contrastNames{i} = testCase.project.contrasts.contrasts{i}.name;
            end
            testCase.verifyEqual(projectStruct.contrastNames, contrastNames, 'toStruct method not working');

            nDomainContrasts = testCase.project.domainContrasts.numberOfContrasts;
            domainContrastNames = cell(1,nDomainContrasts);
            for i = 1:nDomainContrasts
                domainContrastNames{i} = testCase.project.domainContrasts.contrasts{i}.name;
            end
            testCase.verifyEqual(projectStruct.domainContrastNames, domainContrastNames, 'toStruct method not working');

            testCase.verifyEqual(projectStruct.domainRatioNames, {convertStringsToChars(testCase.project.domainRatio.paramsTable{:, 1})}, 'toStruct method not working');
        end

        function testObjectDisplay(testCase)
            % Check that the content of the project are printed 
            display = evalc('disp(testCase.project)');
            testCase.verifyNotEmpty(display, 'displayScalarObject method not working')
            testCase.verifySubstring(display, "experimentName: 'example'", 'displayScalarObject method not working')
        end
    end
end