% Class based unit tests for the DomainsClass

classdef testDomainsClass < matlab.unittest.TestCase
        
    properties
        project
        parameters
        layers
    end

    methods(TestMethodSetup)
        function initialiseProject(testCase)
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
            varTable = testCase.project.parameters.varTable;
            testCase.project.parameters.varTable = [varTable; vertcat(testCase.parameters{:})];
        end
        
        function populateProject(testCase)
            % Populates project class properties for the tests
            testCase.addParameters()
            varTable = testCase.project.layers.varTable;
            testCase.project.layers.varTable = [varTable; vertcat(testCase.layers{1:2})];
            testCase.project.resolution.resolutions.varTable{1, 1} = "Resolution 2";
            testCase.project.background.backgrounds.varTable{1, 1} = "Background H2O";
            testCase.project.data.varTable{1, 1} = "Sim 1";
            
            varTable = testCase.project.background.backgrounds.varTable;
            testCase.project.background.backgrounds.varTable = [varTable; varTable];
            testCase.project.background.backgrounds.varTable{2, 1} = "Background D2O";

            varTable = testCase.project.bulkOut.varTable;
            testCase.project.bulkOut.varTable = [varTable; varTable];
            testCase.project.bulkOut.varTable{2, 1} = "SLD H2O";
            
            varTable = testCase.project.bulkIn.varTable;
            testCase.project.bulkIn.varTable = [varTable; varTable];
            testCase.project.bulkIn.varTable{2, 1} = "Silicon";

            varTable = testCase.project.data.varTable;
            testCase.project.data.varTable = [varTable; varTable];
            testCase.project.data.varTable{2, 1} = "Sim 2";
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

        function testConversion(testCase)
            % Tests domains class can be converted to project class and
            % the properties are copied over
            testCase.verifyClass(testCase.project, 'domainsClass')
            testCase.verifyEqual(testCase.project.calculationType, calculationTypes.Domains.value, 'Calculation Type not set correctly');
            testCase.verifyTrue(testCase.project.contrasts.isDomains, 'Calculation Type not set correctly')

            normal = testCase.project.toProjectClass();
            testCase.verifyClass(normal, 'projectClass')
            testCase.verifyEqual(normal.experimentName, testCase.project.experimentName, 'Experiment name not copied correctly');
            testCase.verifyEqual(normal.calculationType, calculationTypes.Normal.value, 'Calculation Type not set correctly');
            testCase.verifyFalse(normal.contrasts.isDomains, 'Calculation Type not set correctly')
            testCase.verifyEqual(normal.parameters, testCase.project.parameters, 'Parameters not copied correctly');
            testCase.verifyEqual(normal.layers, testCase.project.layers, 'Layers not copied correctly');

            normal2 = projectClass(testCase.project);
            testCase.verifyClass(normal2, 'projectClass')
        end

        function testModelType(testCase)
            varTable = testCase.project.layers.varTable;
            testCase.project.layers.varTable = [varTable; vertcat(testCase.layers{1:2})];
            testCase.project.addDomainContrast('name', 'Bilayer / H2O');
            % Test default model type
            testCase.verifyEqual(testCase.project.modelType, modelTypes.StandardLayers.value, 'Model type not set correctly');
            testCase.verifyClass(testCase.project.layers, 'layersClass', 'Layers class not initialised correctly')
            testCase.verifyClass(testCase.project.domainContrasts, 'domainContrastsClass', 'Domain Contrasts class not initialised correctly')
            % Test resetting retains layers and domain contrasts
            testCase.project.modelType = 'standard layers';
            testCase.verifyEqual(testCase.project.modelType, modelTypes.StandardLayers.value, 'Model type not set correctly');
            testCase.verifyClass(testCase.project.layers, 'layersClass', 'Layers class not initialised correctly')
            testCase.verifyEqual(testCase.project.layers.rowCount, 2, 'Layers object wrongly reset');
            testCase.verifyEqual(testCase.project.domainContrasts.numberOfContrasts, 1, 'DomainContrasts object wrongly reset');
            % Test possible model type with varied case
            testCase.project.modelType = modelTypes.CustomLayers;
            testCase.verifyEqual(testCase.project.modelType, modelTypes.CustomLayers.value, 'Model type not set correctly');
            testCase.verifyThat(testCase.project.layers, ~matlab.unittest.constraints.IsOfClass('layersClass'), 'Layers class not initialised correctly');
            testCase.verifyThat(testCase.project.domainContrasts, ~matlab.unittest.constraints.IsOfClass('domainContrastsClass'), 'Domain Contrasts class not initialised correctly');
            testCase.project.modelType = 'Custom XY';
            testCase.verifyEqual(testCase.project.modelType, modelTypes.CustomXY.value, 'Model type not set correctly');
            testCase.verifyThat(testCase.project.layers, ~matlab.unittest.constraints.IsOfClass('layersClass'), 'Layers class not initialised correctly');
            testCase.verifyThat(testCase.project.domainContrasts, ~matlab.unittest.constraints.IsOfClass('domainContrastsClass'), 'Domain Contrasts class not initialised correctly');
            testCase.project.modelType = 'STANDARD LAYERS';
            testCase.verifyEqual(testCase.project.modelType, modelTypes.StandardLayers.value, 'Model type not set correctly');
            testCase.verifyClass(testCase.project.layers, 'layersClass', 'Layers class not initialised correctly')
            % Test bad inputs 
            testCase.verifyError(@() setModelType('anything'), exceptions.invalidOption.errorID)
            testCase.verifyError(@() setModelType(2), exceptions.invalidOption.errorID)
            function setModelType(value)
                testCase.project.modelType = value;
            end
        end

        function testDomainRatio(testCase)
            % Checks the default domain ratios
            testCase.verifySize(testCase.project.domainRatio.varTable, [1, 8], 'domain ratio has wrong dimension');
            testCase.verifyEqual(string(testCase.project.domainRatio.varTable{1, :}),...
                                    string({'Domain Ratio 1', 0.4, 0.5, 0.6, false, 'uniform', 0, Inf}), 'default domain ratio is not correct');
            % Checks that domain ratios can be added
            testCase.project.addDomainRatio('Domain Ratio 2', 0.4, 0.69, 1.0, true);
            testCase.project.addDomainRatio('Domain Ratio 3', 0.17, 0.2, 1.1, false);
            testCase.verifySize(testCase.project.domainRatio.varTable, [3, 8], 'domain ratio has wrong dimension');
            testCase.verifyEqual(testCase.project.domainRatio.varTable{end,1}, "Domain Ratio 3", 'addDomainRatio method not working');
            % Checks that domain ratios can be removed
            testCase.project.removeDomainRatio(2);
            testCase.verifySize(testCase.project.domainRatio.varTable, [2, 8], 'domain ratio has wrong dimension');
            testCase.verifyEqual(testCase.project.domainRatio.varTable{:, 1}, ["Domain Ratio 1"; "Domain Ratio 3"], 'removeDomainRatio method not working');
            % Checks that domain ratios can be modified
            testCase.project.setDomainRatio(1, 'name','Domain Ratio 1','min',0.1,'value',0.23251,'max',0.4,'fit',true);
            testCase.verifyEqual(string(testCase.project.domainRatio.varTable{1, :}),...
                                    string({'Domain Ratio 1', 0.1, 0.23251, 0.4, true, priorTypes.Uniform.value, 0, Inf}), 'domainRatio method not working');
            testCase.project.addDomainRatio();
            testCase.verifyEqual(string(testCase.project.domainRatio.varTable{end, 1}), "new parameter 4"); 
            testCase.project.setDomainRatio(3, 'min', -0.5);
            testCase.verifyEqual(testCase.project.domainRatio.varTable{3, 2:4}, [-0.5, 0, 0]);
            
        end
        
        function testSetContrast(testCase)
            % Populates project properties for the tests
            testCase.populateProject();
            testCase.project.addDomainContrast('name', 'Domains 1');
            testCase.project.addDomainContrast('name', 'Domains 2');
            testCase.project.addContrast('name', 'Bilayer / H2O');
            testCase.project.addContrast('name', 'Bilayer / D2O');
            testCase.project.setContrastModel(1:2,  {'Domains 1', 'Domains 2'});
            testCase.verifyLength(testCase.project.contrasts.contrasts, 2, 'contrast has wrong dimension');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{1}.model, {'Domains 1', 'Domains 2'}, 'addContrast method not working');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{2}.model, {'Domains 1', 'Domains 2'}, 'setContrastModel method not working');            
        end

        function testDomainContrast(testCase)
            % Populates project properties for the tests
            testCase.populateProject();
            % Checks the default contrast
            testCase.verifyEmpty(testCase.project.domainContrasts.contrasts, 'contrast has wrong dimension');
            % Checks that contrast can be added
            testCase.project.addDomainContrast('name', 'Bilayer / H2O');
            testCase.verifyLength(testCase.project.domainContrasts.contrasts, 1, 'contrast has wrong dimension');
            testCase.verifyEqual(testCase.project.domainContrasts.contrasts{1}.name, 'Bilayer / H2O', 'addContrast method not working');

            testCase.project.addDomainContrast('name', 'Another Bilayer');
            testCase.verifyLength(testCase.project.domainContrasts.contrasts, 2, 'contrast has wrong dimension');
            testCase.verifyEqual(testCase.project.domainContrasts.contrasts{2}.name, 'Another Bilayer', 'addContrast method not working');
            % Checks that contrast can be modified
            testCase.verifyError(@() testCase.project.setDomainContrast(3, 'name', 'First Bilayer'), exceptions.indexOutOfRange.errorID)
            testCase.verifyError(@() testCase.project.setDomainContrast('Bilayer', 'name', 'First Bilayer'), exceptions.nameNotRecognised.errorID)
            testCase.project.setDomainContrast(1, 'name', 'First Bilayer');
            testCase.verifyLength(testCase.project.domainContrasts.contrasts, 2, 'contrast has wrong dimension');
            testCase.verifyEqual(testCase.project.domainContrasts.contrasts{1}.name, 'First Bilayer', 'setContrast method not working');
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
            testCase.verifyError(@() testCase.project.setDomainContrastModel(3, {}), exceptions.indexOutOfRange.errorID)
            testCase.verifyError(@() testCase.project.setDomainContrastModel('Bilayer', {}), exceptions.nameNotRecognised.errorID);
        end

        function testDomainContrastExceptions(testCase)
            % Ensure a domains contrast is not defined for a custom model,
            % and the routines modifying the domains contrast raise an
            % error
            customProject = domainsClass('custom project', modelTypes.CustomLayers);
            testCase.verifyEmpty(customProject.domainContrasts);
            testCase.verifyError(@() customProject.addDomainContrast('name', 'Bilayer / H2O'), exceptions.invalidProperty.errorID)
            testCase.verifyError(@() customProject.removeDomainContrast(1), exceptions.invalidProperty.errorID)
            testCase.verifyError(@() customProject.setDomainContrast(1, 'name', 'First Bilayer'), exceptions.invalidProperty.errorID)
            testCase.verifyError(@() customProject.setDomainContrastModel(1, {'Hydrogenated Heads', 'Deuterated Heads'}), exceptions.invalidProperty.errorID)
        end

        function testToStruct(testCase)
            projectStruct = testCase.project.toStruct();
            testCase.verifyEqual(projectStruct.experimentName, testCase.project.experimentName, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.geometry, testCase.project.geometry, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.TF, calculationTypes.Domains.value, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.paramNames, {'Substrate Roughness'}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.backgroundNames, testCase.project.background.backgrounds.varTable{:, 1}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.backgroundTypes, testCase.project.background.backgrounds.varTable{:, 2}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.backgroundParamNames, ...
                                 {convertStringsToChars(testCase.project.background.backgroundParams.varTable{:, 1})}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.resolutionNames, testCase.project.resolution.resolutions.varTable{:, 1}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.resolutionTypes, testCase.project.resolution.resolutions.varTable{:, 2}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.resolutionParamNames, ...
                                 {convertStringsToChars(testCase.project.resolution.resolutionParams.varTable{:, 1})}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.resolutionNames, testCase.project.resolution.resolutions.varTable{:, 1}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.scalefactorNames, {convertStringsToChars(testCase.project.scalefactors.varTable{:, 1})}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.bulkInNames, {convertStringsToChars(testCase.project.bulkIn.varTable{:, 1})}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.bulkOutNames, {convertStringsToChars(testCase.project.bulkOut.varTable{:, 1})}, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.layerNames, testCase.project.layers.varTable{:, 1}, 'toStruct method not working');

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

            testCase.verifyEqual(projectStruct.domainRatioNames, {convertStringsToChars(testCase.project.domainRatio.varTable{:, 1})}, 'toStruct method not working');
        end

        function testObjectDisplay(testCase)
            % Check that the content of the project are printed 
            display = evalc('disp(testCase.project)');
            testCase.verifyNotEmpty(display, 'displayScalarObject method not working')
            testCase.verifySubstring(display, "experimentName: 'example'", 'displayScalarObject method not working')
        end
    end
end