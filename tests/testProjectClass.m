% Class based unit tests for the ProjectClass

classdef testProjectClass < matlab.unittest.TestCase
        
    properties
        project
        parameters
        layers
    end

    methods(TestMethodSetup)
        function setWorkingFolder(testCase)
            % Makes a temporary folder the current working directory so
            % file written by the example are deleted
            import matlab.unittest.fixtures.WorkingFolderFixture;
            testCase.applyFixture(WorkingFolderFixture);
        end

        function initialiseProject(testCase)
            testCase.project = projectClass('example');
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
                    {'Heads Hydration',         0,      0.5,   10,  true, priorTypes.Uniform.value, 0, Inf};
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
            % Tests project class can be created and the experiment name is set correctly
            newProject = projectClass();
            testCase.verifyEqual(newProject.experimentName, '', 'Experiment name not set correctly');
            testCase.verifyEqual(newProject.calculationType, calculationTypes.Normal.value, 'Calculation Type not set correctly');
            newProject = projectClass('New experiment');
            testCase.verifyEqual(newProject.experimentName, 'New experiment', 'Experiment name not set correctly');
            testCase.verifyEqual(newProject.calculationType, calculationTypes.Normal.value, 'Calculation Type not set correctly');
            testCase.verifyError(@() projectClass(1), 'MATLAB:validators:mustBeTextScalar')
        end
        
        function testClone(testCase)
            % Tests clone project is different from original
            newProject = projectClass();
            clonedProject = newProject.clone();
            testCase.verifyEqual(newProject.experimentName, clonedProject.experimentName, 'clone not working correctly');
            clonedProject.experimentName = 'project';
            testCase.verifyNotEqual(newProject.experimentName, 'project', 'clone not working correctly');

            varTable = newProject.parameters.varTable;
            newProject.parameters.varTable = [varTable; vertcat(testCase.parameters{:})];
            testCase.verifySize( newProject.parameters.varTable, [10, 8], 'Parameters has wrong dimension');
            testCase.verifySize( clonedProject.parameters.varTable, [1, 8], 'Parameters has wrong dimension')  
        end

        function testConversion(testCase)
            % Tests project class can be converted to domains class and
            % the properties are copied over
            testCase.verifyClass(testCase.project, 'projectClass')
            testCase.verifyEqual(testCase.project.calculationType, calculationTypes.Normal.value, 'Calculation Type not set correctly');
            testCase.verifyFalse(testCase.project.contrasts.domainsCalc, 'Calculation Type not set correctly')

            domains = testCase.project.toDomainsClass();
            testCase.verifyClass(domains, 'domainsClass')
            testCase.verifyEqual(domains.experimentName, testCase.project.experimentName, 'Experiment name not copied correctly');
            testCase.verifyEqual(domains.calculationType, calculationTypes.Domains.value, 'Calculation Type not set correctly');
            testCase.verifyTrue(domains.contrasts.domainsCalc, 'Calculation Type not set correctly')
            testCase.verifyEqual(domains.parameters, testCase.project.parameters, 'Parameters not copied correctly');
            testCase.verifyEqual(domains.layers, testCase.project.layers, 'Layers not copied correctly');

            % Ensure that the additional domain ratio field is defined
            for i=1:domains.contrasts.numberOfContrasts
                testCase.verifyTrue(isfield(domains.contrasts.contrasts{i}, 'domainRatio'))
            end
        end
        
        function testAbsorption(testCase)
            % Tests absorption can be turned on and off with the layers
            % table modified accordingly
            varTable = testCase.project.layers.varTable;
            testCase.project.layers.varTable = [varTable; vertcat(testCase.layers{1:2})];

            testCase.verifyFalse(testCase.project.absorption, 'Absorption not set correctly')
            testCase.verifyEqual(testCase.project.layers.varCount, 6, 'Incorrect number of columns in layers table')
            testCase.verifyEqual(testCase.project.layers.varTable{:,4}, ["Heads Roughness"; "Heads Roughness"], '')

            testCase.project.absorption = true;
            testCase.verifyTrue(testCase.project.absorption, 'Absorption not set correctly')
            testCase.verifyEqual(testCase.project.layers.varCount, 7, 'Incorrect number of columns in layers table')
            testCase.verifyEqual(testCase.project.layers.varTable{:,4}, [""; ""], '')

            testCase.project.absorption = false;
            testCase.verifyFalse(testCase.project.absorption, 'Absorption not set correctly')
            testCase.verifyEqual(testCase.project.layers.varCount, 6, 'Incorrect number of columns in layers table')
            testCase.verifyEqual(testCase.project.layers.varTable{:,4}, ["Heads Roughness"; "Heads Roughness"], '')
        end

        function testGeometry(testCase)
            % Test default geometry
            testCase.verifyEqual(testCase.project.geometry, geometryOptions.AirSubstrate.value, 'Geometry not set correctly');
            % Test possible model type with varied case
            testCase.project.geometry = geometryOptions.SubstrateLiquid;
            testCase.verifyEqual(testCase.project.geometry, geometryOptions.SubstrateLiquid.value, 'Geometry not set correctly');
            testCase.project.geometry = 'aIr/SuBstRate';
            testCase.verifyEqual(testCase.project.geometry, geometryOptions.AirSubstrate.value, 'Geometry not set correctly');
            % Test bad inputs 
            testCase.verifyError(@() setGeometry('anything'), exceptions.invalidOption.errorID)
            testCase.verifyError(@() setGeometry(2), exceptions.invalidOption.errorID)
            function setGeometry(value)
                testCase.project.geometry = value;
            end
        end

        function testModelType(testCase)
            varTable = testCase.project.layers.varTable;
            testCase.project.layers.varTable = [varTable; vertcat(testCase.layers{1:2})];
            % Test default model type
            testCase.verifyEqual(testCase.project.modelType, modelTypes.StandardLayers.value, 'Model type not set correctly');
            testCase.verifyClass(testCase.project.layers, 'layersClass', 'Layers class not initialised correctly')
            % Test resetting retains layers
            testCase.project.modelType = 'standard layers';
            testCase.verifyEqual(testCase.project.modelType, modelTypes.StandardLayers.value, 'Model type not set correctly');
            testCase.verifyClass(testCase.project.layers, 'layersClass', 'Layers class not initialised correctly')
            testCase.verifyEqual(testCase.project.layers.rowCount, 2, 'Layers object wrongly reset');
            % Test possible model type with varied case
            testCase.project.modelType = modelTypes.CustomLayers;
            testCase.verifyEqual(testCase.project.modelType, modelTypes.CustomLayers.value, 'Model type not set correctly');
            testCase.verifyThat(testCase.project.layers, ~matlab.unittest.constraints.IsOfClass('layersClass'), 'Layers class not initialised correctly');
            testCase.project.modelType = 'Custom XY';
            testCase.verifyEqual(testCase.project.modelType, modelTypes.CustomXY.value, 'Model type not set correctly');
            testCase.verifyThat(testCase.project.layers, ~matlab.unittest.constraints.IsOfClass('layersClass'), 'Layers class not initialised correctly');
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

        function testShowPriors(testCase)
            % Test default use prior value
            testCase.verifyFalse(testCase.project.showPriors, 'Use priors not set correctly');
            testCase.project.showPriors = true;
            testCase.verifyTrue(testCase.project.showPriors, 'Use priors not set correctly');
            testCase.project.showPriors = false;
            testCase.verifyFalse(testCase.project.showPriors, 'Use Priors type not set correctly');
            % Test bad inputs 
            testCase.verifyError(@() setShowPriors('anything'), exceptions.invalidType.errorID);
            testCase.verifyError(@() setShowPriors(1), exceptions.invalidType.errorID);
            function setShowPriors(value)
                testCase.project.showPriors = value;
            end
        end

        function testParameters(testCase)
            % Test default parameter
            testCase.verifySize(testCase.project.parameters.varTable, [1, 8], 'Parameters has wrong dimension');
            testCase.verifyEqual(string(testCase.project.parameters.varTable{1, :}), ...
                                    string({'Substrate Roughness', 1, 3, 5, true, priorTypes.Uniform.value, 0, Inf}), 'Parameters default');

            testCase.project.addParameterGroup(testCase.parameters);
            testCase.verifySize(testCase.project.parameters.varTable, [10, 8], 'Parameters has wrong dimension');
            for i = 1:length(testCase.parameters)
                testCase.verifyEqual(string(testCase.project.parameters.varTable{i+1, :}),...
                                        string(testCase.parameters{i}) , 'Parameters not set correctly');
            end
            testCase.verifyError(@() testCase.project.addParameterGroup(testCase.parameters{1}), exceptions.invalidType.errorID);
            
            % Test adding parameters
            testCase.project.addParameter();
            testCase.verifyEqual(testCase.project.parameters.varTable{end, 1}, "new parameter 11", 'addParameter method not working');
            testCase.verifySize(testCase.project.parameters.varTable, [11, 8], 'Parameters has wrong dimension');
            testCase.project.addParameter('NewParam2');
            testCase.verifyEqual(testCase.project.parameters.varTable{end, 1}, "NewParam2", 'addParameter method not working');
            testCase.verifySize(testCase.project.parameters.varTable, [12, 8], 'Parameters has wrong dimension');
            % Test removing parameters
            testCase.project.removeParameter('NewParam2');
            testCase.verifyEqual(testCase.project.parameters.varTable{end, 1}, "new parameter 11", 'removeParameter method not working');
            testCase.verifySize(testCase.project.parameters.varTable, [11, 8], 'Parameters has wrong dimension');
            testCase.verifyError(@() testCase.project.removeParameter('Substrate Roughness'), exceptions.invalidOption.errorID) % can't remove substrate roughness
            testCase.verifyError(@() testCase.project.removeParameter(true), exceptions.invalidType.errorID) % invalid input
            testCase.project.removeParameter(11);
            testCase.verifyEqual(testCase.project.parameters.varTable{end, 1}, "Heads Hydration", 'removeParameter method not working');
            testCase.verifySize(testCase.project.parameters.varTable, [10, 8], 'Parameters has wrong dimension');
             % Test setting the different parameter properties
            testCase.project.setParameter(2, 'value', 15);
            testCase.verifyEqual(testCase.project.parameters.varTable{2, 3}, 15, 'setParameter method not working');
            testCase.project.setParameterValue(2, 13);
            testCase.verifyEqual(testCase.project.parameters.varTable{2, 3}, 13, 'setParameterValue method not working');
            testCase.project.setParameterLimits('Tails Thickness', 0, 100);
            testCase.verifyEqual(testCase.project.parameters.varTable{2, 2}, 0, 'setParameterLimits method not working');
            testCase.verifyEqual(testCase.project.parameters.varTable{2, 4}, 100, 'setParameterLimits method not working');
            testCase.project.setParameterName(2, 'NewParam');
            testCase.verifyEqual(testCase.project.parameters.varTable{2, 1}, "NewParam", 'setParameterName method not working');
            testCase.project.setParameterName(2, 'Tails Thickness');
            testCase.verifyError(@() testCase.project.setParameterName(1, 'name'), exceptions.invalidOption.errorID) % can't rename substrate roughness
            testCase.project.setParameterFit('Tails Thickness', false);
            testCase.verifyEqual(testCase.project.parameters.varTable{2, 5}, false, 'setParameterFit method not working');
            testCase.project.setParameterPrior(2, priorTypes.Uniform);
            testCase.verifyEqual(testCase.project.parameters.varTable{2, 6}, "uniform", 'setParameterPrior method not working');
        end

        function testLayers(testCase)
            % Adds parameters for the tests
            testCase.addParameters()
            % Test default layer
            testCase.verifySize(testCase.project.layers.varTable, [0, 6], 'Layers has wrong dimension');
            % Test adding LayerGroup
            testCase.project.addLayerGroup(testCase.layers);
            testCase.verifySize(testCase.project.layers.varTable, [4, 6], 'Layers has wrong dimension');
            for i = 1:length(testCase.layers)
                for j = 1:length(testCase.layers{i})
                    testCase.verifyEqual(testCase.project.layers.varTable{i, j},...
                                            string(testCase.layers{i}{j}), 'addLayerGroup method not working');
                end
            end
            testCase.verifyError(@() testCase.project.addLayerGroup(testCase.layers{1}), exceptions.invalidType.errorID);

            % Test adding single layer
            layer = testCase.layers{1};
            layer{1} = 'Another Layer';
            testCase.project.addLayer(layer{:});  % Adds layer with full set of parameters
            testCase.verifySize(testCase.project.layers.varTable, [5, 6], 'Layers has wrong dimension');
            testCase.verifyEqual(testCase.project.layers.varTable{5, 1}, "Another Layer", 'addLayer method not working');
            % Test setting value in a layer
            testCase.verifyError(@() testCase.project.setLayerValue(1, 2, 'Tail'), exceptions.nameNotRecognised.errorID)  % parameter does not exist
            testCase.verifyError(@() testCase.project.setLayerValue(1, 2, 11), exceptions.indexOutOfRange.errorID)  % index greater than parameter table
            testCase.project.setLayerValue(1, 2, 'Tails Thickness');
            testCase.verifyEqual(testCase.project.layers.varTable{1, 2}, "Tails Thickness", 'setLayerValue method not working');
            testCase.project.setLayerValue('Hydrogenated Tails', 4, 'Heads Roughness');
            testCase.verifyEqual(testCase.project.layers.varTable{1, 4}, "Heads Roughness", 'setLayerValue method not working');
            testCase.project.setLayerValue(2, 3, 1);
            testCase.verifyEqual(testCase.project.layers.varTable{2, 3}, "Substrate Roughness", 'setLayerValue method not working');
            % Check removing a parameter removes it from layer
            testCase.verifyEqual(testCase.project.layers.varTable{2, 2}, "Heads Thickness", 'param not removed from layers');
            testCase.verifyEqual(testCase.project.layers.varTable{5, 2}, "Heads Thickness", 'param not removed from layers');
            testCase.project.removeParameter('Heads Thickness');
            testCase.verifyEqual(testCase.project.layers.varTable{2, 2}, "", 'param not removed from layers');
            testCase.verifyEqual(testCase.project.layers.varTable{5, 2}, "", 'param not removed from layers');
            % Test removing a layer
            testCase.project.removeLayer(1);
            testCase.verifySize(testCase.project.layers.varTable, [4, 6], 'Layers has wrong dimension');
            testCase.verifyEqual(testCase.project.layers.varTable{:, 1}, ["Deuterated Heads"; "Deuterated Tails"; "Hydrogenated Tails"; "Another Layer"], 'removeLayer method not working');
        end

        function testLayersExceptions(testCase)
            % Ensure layers are not defined for a custom model,
            % and the routines modifying the layers raise an error
            customProject = projectClass('custom project', modelTypes.CustomLayers);
            testCase.verifyEmpty(customProject.layers);
            testCase.verifyError(@() customProject.addLayerGroup({{'New Layer'}, {'Another Layer'}}), exceptions.invalidProperty.errorID)
            testCase.verifyError(@() customProject.addLayer('New Layer'), exceptions.invalidProperty.errorID)
            testCase.verifyError(@() customProject.removeLayer(1), exceptions.invalidProperty.errorID)
            testCase.verifyError(@() customProject.setLayerValue(1, 2, 'Tails Thickness'), exceptions.invalidProperty.errorID)
        end

        function testData(testCase)
            % Checks the default data parameter
            testCase.verifySize(testCase.project.data.varTable, [1, 4], 'data has wrong dimension');
            default = {"Simulation", {[]}, {[]}, {[0.0050, 0.7000]}};
            for i = 1:4
                testCase.verifyEqual(testCase.project.data.varTable{1, i}, default{i}, 'data default');
            end
            % Test adding data
            data = ones(4, 3);                          
            testCase.project.addData('Sim 2', data);
            testCase.verifySize(testCase.project.data.varTable, [2, 4], 'data has wrong dimension');
            testCase.verifyEqual(testCase.project.data.varTable{:, 1}, ["Simulation"; "Sim 2"], 'addData method not working');
            % Test modifying data
            testCase.project.setData(1, 'name', 'Sim 1', 'data', zeros(4, 3), 'dataRange', [0, 0],'simRange', [0, 2]);
            expected = {"Sim 1", {zeros(4, 3)}, {[0, 0]}, {[0, 2]}};
            for i = 1:4
                testCase.verifyEqual(testCase.project.data.varTable{1, i}, expected{i}, 'setData method not working');
            end
            testCase.verifyEqual(testCase.project.data.varTable{2, 1}, "Sim 2", 'setData method not working');
            % Tests that data can be removed
            testCase.project.removeData(2);
            testCase.verifySize(testCase.project.data.varTable, [1, 4], 'data has wrong dimension');
            testCase.verifyEqual(testCase.project.data.varTable{:, 1}, "Sim 1", 'removeData method not working');
        end

        function testBulkIn(testCase)
            % Checks the default Bulk-in
            testCase.verifySize(testCase.project.bulkIn.varTable, [1, 8], 'BulkIn has wrong dimension');
            testCase.verifyEqual(string(testCase.project.bulkIn.varTable{1, :}),...
                                    string({'SLD Air', 0, 0, 0, false, priorTypes.Uniform.value, 0, Inf}), 'BulkIn default');
            % Tests that Bulk-in can be added
            testCase.project.addBulkIn('Silicon', 2.07e-6, 2.073e-6, 2.08e-6, false);
            testCase.verifySize(testCase.project.bulkIn.varTable, [2, 8], 'BulkIn has wrong dimension');
            testCase.verifyEqual(testCase.project.bulkIn.varTable{end, 1}, "Silicon", 'addBulkIn method not working');
            % Tests that Bulk-in can be removed
            testCase.project.removeBulkIn(2);
            testCase.verifySize(testCase.project.bulkIn.varTable, [1, 8], 'BulkIn has wrong dimension');
            testCase.verifyEqual(testCase.project.bulkIn.varTable{:, 1}, "SLD Air", 'removeBulkIn method not working');
            % Tests that Bulk-in can be modified
            testCase.project.setBulkIn(1, 'name', 'Silicon', 'min', 2.07e-6, 'value',2.073e-6, 'max', 2.08e-6, 'fit', true);
            testCase.verifyEqual(string(testCase.project.bulkIn.varTable{1, :}),...
                                    string({'Silicon', 2.07e-6, 2.073e-6, 2.08e-6, true, priorTypes.Uniform.value, 0, Inf}), 'setBulkIn method not working');
        end

        function testBulkOut(testCase)
            % Checks the default Bulk-out
            testCase.verifySize(testCase.project.bulkOut.varTable, [1, 8], 'BulkOut has wrong dimension');
            testCase.verifyEqual(string(testCase.project.bulkOut.varTable{1, :}),...
                                    string({'SLD D2O', 6.2e-6, 6.35e-6, 6.35e-6, false, priorTypes.Uniform.value, 0, Inf}), 'BulkOut default');
            % Tests that Bulk-out can be added
            testCase.project.addBulkOut('SLD ACMW', -1e-6, 0.0, 1e-6, true);
            testCase.verifySize(testCase.project.bulkOut.varTable, [2, 8], 'BulkOut has wrong dimension');
            testCase.verifyEqual(testCase.project.bulkOut.varTable{end,1}, "SLD ACMW", 'addBulkOut method not working');
            testCase.project.addBulkOut('SLD H2O', -0.6e-6, -0.56e-6, -0.3e-6, true);
            testCase.verifySize(testCase.project.bulkOut.varTable, [3, 8], 'BulkOut has wrong dimension');
            % Tests that Bulk-out can be removed
            testCase.project.removeBulkOut(3);
            testCase.verifySize(testCase.project.bulkOut.varTable, [2, 8], 'BulkOut has wrong dimension');
            testCase.verifyEqual(testCase.project.bulkOut.varTable{:, 1}, ["SLD D2O"; "SLD ACMW"], 'removeBulkOut method not working');
            % Tests that Bulk-out can be modified
            testCase.project.setBulkOut(1, 'name', 'SLD H2O', 'min', 2.07e-6, 'value',2.073e-6, 'max', 2.08e-6, 'fit', true);
            testCase.verifyEqual(string(testCase.project.bulkOut.varTable{1, :}),...
                                    string({'SLD H2O', 2.07e-6, 2.073e-6, 2.08e-6, true, priorTypes.Uniform.value, 0, Inf}), 'setBulkOut method not working');
        end
            
        function testScaleFactor(testCase)
            % Checks the default scale factors
            testCase.verifySize(testCase.project.scalefactors.varTable, [1, 8], 'scalefactors has wrong dimension');
            testCase.verifyEqual(string(testCase.project.scalefactors.varTable{1, :}),...
                                    string({'Scalefactor 1', 0.02, 0.23, 0.25, false, priorTypes.Uniform.value, 0, Inf}), 'scalefactors default');
            % Checks that scale factors can be added
            testCase.project.addScalefactor('Scalefactor 2', 0.1, 0.19, 1.0, true);
            testCase.project.addScalefactor('Scalefactor 3', 0.17, 0.2, 1.1, false);
            testCase.verifySize(testCase.project.scalefactors.varTable, [3, 8], 'scalefactors has wrong dimension');
            testCase.verifyEqual(testCase.project.scalefactors.varTable{end,1}, "Scalefactor 3", 'addScalefactor method not working');
            % Checks that scale factors can be removed
            testCase.project.removeScalefactor(2);
            testCase.verifySize(testCase.project.scalefactors.varTable, [2, 8], 'scalefactors has wrong dimension');
            testCase.verifyEqual(testCase.project.scalefactors.varTable{:, 1}, ["Scalefactor 1"; "Scalefactor 3"], 'removeScalefactor method not working');
            % Checks that scale factors can be modified
            testCase.project.setScalefactor(1, 'name','Scalefactor 1','min',0.1,'value',0.23251,'max',0.4,'fit',true);
            testCase.verifyEqual(string(testCase.project.scalefactors.varTable{1, :}),...
                                    string({'Scalefactor 1', 0.1, 0.23251, 0.4, true, priorTypes.Uniform.value, 0, Inf}), 'setScalefactor method not working');
        end

        function testResolution(testCase)
            % Checks the default resolution parameter 
            testCase.verifySize(testCase.project.resolution.resolutionParams.varTable, [1, 8], 'resolution parameter has wrong dimension');
            testCase.verifyEqual(string(testCase.project.resolution.resolutionParams.varTable{1, :}),...
                                    string({'Resolution par 1', 0.01, 0.03, 0.05, false, priorTypes.Uniform.value, 0, Inf}), 'resolution parameter default');
            % Checks that resolution parameter can be added
            testCase.project.addResolutionParam('Resolution par 2', 0.1, 0.19, 1.0, true);
            testCase.project.addResolutionParam('Resolution par 3', 0.17, 0.2, 1.1, false);
            testCase.verifySize(testCase.project.resolution.resolutionParams.varTable, [3, 8], 'resolution parameter has wrong dimension');
            testCase.verifyEqual(testCase.project.resolution.resolutionParams.varTable{end, 1}, "Resolution par 3", 'addResolutionParam method not working');
            % Checks that resolution parameter can be removed
            testCase.project.removeResolutionParam(2);
            testCase.verifySize(testCase.project.resolution.resolutionParams.varTable, [2, 8], 'resolution parameter has wrong dimension');
            testCase.verifyEqual(testCase.project.resolution.resolutionParams.varTable{:, 1}, ["Resolution par 1"; "Resolution par 3"], 'removeResolutionParam method not working');
            % Checks that resolution parameter can be modified
            testCase.project.setResolutionParam(2, 'name', 'ResolutionParam', 'min', 0, 'value', 0.5, 'max', 1,'fit',true);
            testCase.verifySize(testCase.project.resolution.resolutionParams.varTable, [2, 8], 'resolution parameter has wrong dimension');
            testCase.verifyEqual(string(testCase.project.resolution.resolutionParams.varTable{2, :}),...
                                    string({'ResolutionParam', 0, 0.5, 1, true, priorTypes.Uniform.value, 0, Inf}), 'setResolutionParam method not working');
            % Checks that resolution parameter value can be modified
            testCase.project.setResolutionParamValue('Resolution par 1', 0.02325);
            testCase.verifyEqual(testCase.project.resolution.resolutionParams.varTable{1, 3}, 0.02325, 'setResolutionParamValue method not working with name value pair');
            testCase.project.setResolutionParamValue(2, 0.4);
            testCase.verifyEqual(testCase.project.resolution.resolutionParams.varTable{2, 3}, 0.4, 'setResolutionParamValue method not working with index value pair');    
            % Checks that resolution parameter name can be modified
            testCase.project.setResolutionParamName(2, 'Resolution par 2');
            testCase.verifyEqual(testCase.project.resolution.resolutionParams.varTable{2, 1}, "Resolution par 2", 'setResolutionParamName method not working');
            % Checks that resolution parameter limits can be modified
            testCase.project.setResolutionParamLimits(1, 0, 1);
            testCase.verifyEqual(testCase.project.resolution.resolutionParams.varTable{1, 2}, 0, 'setResolutionParamLimits method not working');
            testCase.verifyEqual(testCase.project.resolution.resolutionParams.varTable{1, 4}, 1, 'setResolutionParamLimits method not working');
            % Checks the default resolution parameter 
            testCase.verifySize(testCase.project.resolution.resolutions.varTable, [1, 8], 'resolution has wrong dimension');
            testCase.verifyEqual(string(testCase.project.resolution.resolutions.varTable{1, :}),...
                                    string({'Resolution 1', allowedTypes.Constant.value, 'Resolution par 1', '', '', '', '', ''}), 'resolution default');
            % Checks that resolution can be added
            testCase.project.addResolution('Resolution 2', allowedTypes.Constant,'Resolution par 1','','','','','');
            testCase.verifySize(testCase.project.resolution.resolutions.varTable, [2, 8], 'resolution has wrong dimension');
            testCase.verifyEqual(testCase.project.resolution.resolutions.varTable{:, 1}, ["Resolution 1"; "Resolution 2"], 'addResolution method not working');
            % Checks that resolution can be removed
            testCase.project.removeResolution(1);
            testCase.verifySize(testCase.project.resolution.resolutions.varTable, [1, 8], 'resolution has wrong dimension');
            testCase.verifyEqual(testCase.project.resolution.resolutions.varTable{:, 1}, "Resolution 2", 'addResolution method not working');
            % Checks that resolution value can be modified
            testCase.project.setResolution(1, 'name', 'New Resolution Name');
            testCase.verifyEqual(testCase.project.resolution.resolutions.varTable{1, 1}, "New Resolution Name", 'setResolution method not working');
            % Checks that resolution name can be modified
            testCase.project.setResolutionName(1, 'Resolution 1');
            testCase.verifyEqual(testCase.project.resolution.resolutions.varTable{1, 1}, "Resolution 1", 'setResolutionName method not working');
        end

        function testBackground(testCase)
            % Checks the default background parameter 
            testCase.verifySize(testCase.project.background.backgroundParams.varTable, [1, 8], 'background parameter has wrong dimension');
            testCase.verifyEqual(string(testCase.project.background.backgroundParams.varTable{1, :}),...
                                    string({'Background Param 1', 1e-7, 1e-6, 1e-5, false, priorTypes.Uniform.value, 0, Inf}), 'background parameter default');
            % Checks that background parameter can be added
            testCase.project.addBackgroundParam('Backs Value D2O', 1e-8, 2.8e-6, 1e-5, true);
            testCase.verifyEqual(testCase.project.background.backgroundParams.varTable{end,1}, "Backs Value D2O", 'addBackgroundParam method not working');
            % Checks that background parameter can be modified
            testCase.project.setBackgroundParam(1, 'name', 'Backs Value H2O', 'min', 0.1, 'value', 0.23251, 'max', 0.4, 'fit', true);
            testCase.verifyEqual(string(testCase.project.background.backgroundParams.varTable{1, :}),...
                                    string({'Backs Value H2O', 0.1, 0.23251, 0.4, true, priorTypes.Uniform.value, 0, Inf}), 'setBackgroundParam method not working');
            % Checks that background parameter can be removed
            testCase.project.removeBackgroundParam(2);
            testCase.verifySize(testCase.project.background.backgroundParams.varTable, [1, 8], 'background has wrong dimension');
            testCase.verifyEqual(testCase.project.background.backgroundParams.varTable{:, 1}, "Backs Value H2O", 'removeBackgroundParam method not working');
            % Checks that background parameter value can be modified
            testCase.project.setBackgroundParamValue(1, 0.15232);
            testCase.verifyEqual(testCase.project.background.backgroundParams.varTable{1, 3}, 0.15232, 'setBackgroundParamValue method not working');
            % Checks that background parameter name can be modified
            testCase.project.setBackgroundParamName(1, 'Backs Value D2O');
            testCase.verifyEqual(testCase.project.background.backgroundParams.varTable{1, 1}, "Backs Value D2O", 'setBackgroundParamName method not working');
            % Checks that background parameter limits can be modified
            testCase.project.setBackgroundParamLimits(1, 0, 1);
            testCase.verifyEqual(testCase.project.background.backgroundParams.varTable{1, 2}, 0, 'setBackgroundParamLimits method not working');
            testCase.verifyEqual(testCase.project.background.backgroundParams.varTable{1, 4}, 1, 'setBackgroundParamLimits method not working');
            % Checks the default background parameter 
            testCase.verifySize(testCase.project.background.backgrounds.varTable, [1, 8], 'background has wrong dimension');
            testCase.verifyEqual(string(testCase.project.background.backgrounds.varTable{1, :}),...
                                      string({'Background 1', allowedTypes.Constant.value, 'Background Param 1', '', '', '', '', ''}), 'background default');
            % Checks that background can be added
            testCase.project.addBackground('Background D2O',allowedTypes.Constant.value,'Backs Value D2O');
            testCase.verifySize(testCase.project.background.backgrounds.varTable, [2, 8], 'background has wrong dimension');
            testCase.verifyEqual(testCase.project.background.backgrounds.varTable{:, 1}, ["Background 1"; "Background D2O"], 'addBackground method not working');
            % Checks that background can be removed
            testCase.project.removeBackground(1);
            testCase.verifySize(testCase.project.background.backgrounds.varTable, [1, 8], 'background has wrong dimension');
            testCase.verifyEqual(testCase.project.background.backgrounds.varTable{:, 1}, "Background D2O", 'addBackground method not working');
            % Checks that background value can be modified
            testCase.project.setBackground(1, 'name', 'Background ACMW');
            testCase.verifyEqual(testCase.project.background.backgrounds.varTable{1, 1}, "Background ACMW", 'setBackground method not working');
            % Checks that background name can be modified
            testCase.project.setBackgroundName(1, 'Background H2O');
            testCase.verifyEqual(testCase.project.background.backgrounds.varTable{1, 1}, "Background H2O", 'setBackgroundName method not working');
        end

        function testContrast(testCase)
            % Populates project properties for the tests
            testCase.populateProject();
            % Checks the default contrast
            testCase.verifyEmpty(testCase.project.contrasts.contrasts, 'contrast has wrong dimension');
            % Checks that contrast can be added
            testCase.project.addContrast('name', 'Bilayer / H2O', 'background', 'Background H2O', 'resolution', 'Resolution 2',...
                                         'scalefactor', 'Scalefactor 1', 'resample', false, 'bulkOut', 'SLD D2O', 'bulkIn', 'SLD Air',...
                                         'data', 'Sim 1');
            testCase.verifyLength(testCase.project.contrasts.contrasts, 1, 'contrast has wrong dimension');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{1}.name, 'Bilayer / H2O', 'addContrast method not working');

            testCase.project.addContrast('name', 'Another Bilayer', 'background', 'Background H2O', 'resolution', 'Resolution 2',...
                                         'scalefactor', 'Scalefactor 1', 'resample', false, 'bulkOut', 'SLD H2O', 'bulkIn', 'Silicon',...
                                         'data', 'Sim 2');
            testCase.verifyLength(testCase.project.contrasts.contrasts, 2, 'contrast has wrong dimension');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{2}.name, 'Another Bilayer', 'addContrast method not working');
            % Checks that contrast can be modified
            testCase.verifyError(@() testCase.project.setContrast(3, 'name', 'First Bilayer'), exceptions.indexOutOfRange.errorID)
            testCase.verifyError(@() testCase.project.setContrast('Bilayer', 'name', 'First Bilayer'), exceptions.nameNotRecognised.errorID)
            testCase.project.setContrast(1, 'name', 'First Bilayer', 'bulkOut', 'SLD H2O');
            testCase.verifyLength(testCase.project.contrasts.contrasts, 2, 'contrast has wrong dimension');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{1}.name, 'First Bilayer', 'setContrast method not working');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{1}.bulkOut, 'SLD H2O', 'setContrast method not working');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{1}.bulkIn, 'SLD Air', 'setContrast method not working');
            testCase.project.setContrast('First Bilayer', 'bulkIn', 'Silicon');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{1}.name, 'First Bilayer', 'setContrast method not working');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{1}.bulkOut, 'SLD H2O', 'setContrast method not working');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{1}.bulkIn, 'Silicon', 'setContrast method not working');
            % Checks that contrast can be removed
            testCase.project.removeContrast(1);
            testCase.verifyLength(testCase.project.contrasts.contrasts, 1, 'contrast has wrong dimension');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{1}.name, 'Another Bilayer', 'addContrast method not working');
            % Checks the contrast model can be modified
            testCase.verifyLength(testCase.project.contrasts.contrasts{1}.model, 0, 'contrast model has wrong dimension');       
            testCase.project.setContrastModel(1, {'Hydrogenated Heads', 'Deuterated Heads'});
            testCase.verifyEqual(testCase.project.contrasts.contrasts{1}.model, {'Hydrogenated Heads', 'Deuterated Heads'}, 'setContrastModel method not working');
            testCase.project.setContrastModel('Another Bilayer', {'Deuterated Heads', 'Hydrogenated Heads'});
            testCase.verifyEqual(testCase.project.contrasts.contrasts{1}.model, {'Deuterated Heads', 'Hydrogenated Heads'}, 'setContrastModel method not working');
            testCase.project.addContrast('First Bilayer');
            testCase.project.setContrastModel(1:2, {'Deuterated Heads'});
            testCase.verifyEqual(testCase.project.contrasts.contrasts{1}.model, {'Deuterated Heads'}, 'setContrastModel method not working');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{2}.model, {'Deuterated Heads'}, 'setContrastModel method not working');
            testCase.project.setContrastModel({'First Bilayer', 'Another Bilayer'}, {'Hydrogenated Heads'});
            testCase.verifyEqual(testCase.project.contrasts.contrasts{1}.model, {'Hydrogenated Heads'}, 'setContrastModel method not working');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{2}.model, {'Hydrogenated Heads'}, 'setContrastModel method not working');
            testCase.verifyError(@() testCase.project.setContrastModel(3, {}), exceptions.indexOutOfRange.errorID)
            testCase.verifyError(@() testCase.project.setContrastModel('Bilayer', {}), exceptions.nameNotRecognised.errorID);
        end

        function testCustomFile(testCase)
            import matlab.unittest.fixtures.TemporaryFolderFixture
            fixture = testCase.applyFixture(TemporaryFolderFixture);

            % Checks the default custom file
            testCase.verifySize(testCase.project.customFile.varTable, [0, 5], 'custom file table has wrong dimension');
            % Checks that custom file can be added
            testCase.project.addCustomFile('model 1', 'custom.m', 'matlab');
            testCase.project.addCustomFile('model 2', 'custom.cpp', 'cpp', fixture.Folder);
            testCase.verifySize(testCase.project.customFile.varTable, [2, 5], 'custom file table has wrong dimension');    
            testCase.verifyEqual(testCase.project.customFile.varTable{:, 1}, ["model 1"; "model 2"], 'addCustomFile method not working');
            testCase.verifyEqual(testCase.project.customFile.varTable{:, 2}, ["custom.m"; "custom.cpp"], 'addCustomFile method not working');
            testCase.verifyEqual(testCase.project.customFile.varTable{:, 3}, ["custom"; "custom"], 'addCustomFile method not working');
            testCase.verifyEqual(testCase.project.customFile.varTable{:, 4}, ["matlab"; "cpp"], 'addCustomFile method not working');
            testCase.verifyEqual(testCase.project.customFile.varTable{:, 5}, [""; fixture.Folder], 'addCustomFile method not working');
            % Checks that custom file can be modified
            testCase.project.setCustomFile(2, 'filename', 'cust.m');
            testCase.verifyEqual(testCase.project.customFile.varTable{2, 2}, "cust.m", 'setCustomFile method not working');
            testCase.project.setCustomFile('model 1', 'language', 'matlab');
            testCase.verifyEqual(testCase.project.customFile.varTable{1, 4}, "matlab", 'setCustomFile method not working');
            % Test removing a row
            testCase.project.removeCustomFile(1);
            testCase.verifySize(testCase.project.customFile.varTable, [1, 5], 'custom file table has wrong dimension');
            testCase.verifyEqual(testCase.project.customFile.varTable{1, :}, ["model 2", "cust.m", "custom", "cpp", fixture.Folder], 'removeCustomFile method not working');

        end

        function testToStruct(testCase)
            projectStruct = testCase.project.toStruct();
            testCase.verifyEqual(projectStruct.experimentName, testCase.project.experimentName, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.geometry, testCase.project.geometry, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.TF, calculationTypes.Normal.value, 'toStruct method not working');
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
        end

        function testWriteScript(testCase)
            % Test that a projectClass object can be written to a script
            % that can regenerate the object

            % Populates project properties for the tests
            testCase.populateProject();

            % Verify error for invalid input and write the script
            testCase.verifyError(@() testCase.project.writeScript(script="invalid.txt"), exceptions.invalidValue.errorID);
            testCase.project.writeScript(objName="problem", script="newScript");
            run("newScript.m");
    
            % Test general properties
            testCase.verifyEqual(testCase.project.experimentName, problem.experimentName, 'experimentName is not correctly regenerated by the script');
            testCase.verifyEqual(testCase.project.calculationType, problem.calculationType, 'calculationType is not correctly regenerated by the script');
            testCase.verifyEqual(testCase.project.modelType, problem.modelType, 'modelType is not correctly regenerated by the script');
            testCase.verifyEqual(testCase.project.geometry, problem.geometry, 'geometry is not correctly regenerated by the script');
            testCase.verifyEqual(testCase.project.absorption, problem.absorption, 'absorption is not correctly regenerated by the script');
            testCase.verifyEqual(testCase.project.showPriors, problem.showPriors, 'usePriors is not correctly regenerated by the script');

            % Test properties
            testCase.verifyEqual(testCase.project.parameters.varTable, problem.parameters.varTable, 'parameters are not correctly regenerated by the script');
            testCase.verifyEqual(testCase.project.bulkIn.varTable, problem.bulkIn.varTable, 'bulkIn parameters are not correctly regenerated by the script');
            testCase.verifyEqual(testCase.project.bulkOut.varTable, problem.bulkOut.varTable, 'bulkOut parameters are not correctly regenerated by the script');
            testCase.verifyEqual(testCase.project.scalefactors.varTable, problem.scalefactors.varTable, 'scalefactors are not correctly regenerated by the script');
            
            % Test backgrounds and resolutions
            testCase.verifyEqual(testCase.project.background.backgroundParams.varTable, problem.background.backgroundParams.varTable, 'background parameters are not correctly regenerated by the script');
            testCase.verifyEqual(testCase.project.background.backgrounds.varTable, problem.background.backgrounds.varTable, 'backgrounds are not correctly regenerated by the script');
            testCase.verifyEqual(testCase.project.resolution.resolutionParams.varTable, problem.resolution.resolutionParams.varTable, 'resolution parameters not correctly regenerated by the script');
            testCase.verifyEqual(testCase.project.resolution.resolutions.varTable, problem.resolution.resolutions.varTable, 'resolutions are not correctly regenerated by the script');

            % Test string classes and data
            testCase.verifyEqual(testCase.project.layers.varTable, problem.layers.varTable, 'layers are not correctly regenerated by the script');
            testCase.verifyEqual(testCase.project.customFile.varTable, problem.customFile.varTable, 'custom files are not correctly regenerated by the script');
            testCase.verifyEqual(testCase.project.data.varTable, problem.data.varTable, 'data are not correctly regenerated by the script');

            % Test contrasts
            testCase.assertEqual(testCase.project.contrasts.numberOfContrasts, problem.contrasts.numberOfContrasts, 'numberOfContrasts is not correctly regenerated by the script');
            for i=1:length(testCase.project.contrasts.contrasts)
                testCase.verifyEqual(testCase.project.contrasts.contrasts{i}, problem.contrasts.contrasts{i}, sprintf('contrast %d is not correctly regenerated by the script', i));
            end

            testCase.verifyEqual(testCase.project.contrasts.domainsCalc, problem.contrasts.domainsCalc, 'contrasts domainsCalc is not correctly regenerated by the script');
            testCase.verifyEqual(testCase.project.contrasts.displayNames, problem.contrasts.displayNames, 'contrasts displayNames is not correctly regenerated by the script');
        end

        function testObjectDisplay(testCase)
            % Check that the content of the project are printed 
            display = evalc('disp(testCase.project)');
            testCase.verifyNotEmpty(display, 'displayScalarObject method not working');
            testCase.verifySubstring(display, "experimentName: 'example'", 'displayScalarObject method not working');
        end
    end
end