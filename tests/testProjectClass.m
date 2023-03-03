% Class based unit tests for the ProjectClass

classdef testProjectClass < matlab.unittest.TestCase
        
    properties
        project
        parameters
        layers
    end

    methods(TestMethodSetup)
        function createProject(testCase)
            testCase.project = projectClass('example');
            testCase.parameters = {
                    %       Name                min     val     max  fit? 'Prior Type','mu','sigma'
                    {'Tails Thickness',         10,     20,     30,  true, 'uniform', 0, Inf};
                    {'Heads Thickness',          3,     11,     16,  true, 'uniform', 0, Inf};
                    {'Tails Roughness',          2,     5,      9,   true, 'uniform', 0, Inf};
                    {'Heads Roughness',          2,     7,      9,   true, 'uniform', 0, Inf};
                    {'Deuterated Tails SLD',    4e-6,   6e-6,   2e-5, true, 'uniform', 0, Inf};
                    {'Hydrogenated Tails SLD', -0.6e-6, -0.4e-6, 0,  true, 'uniform', 0, Inf};
                    {'Deuterated Heads SLD',    1e-6,   3e-6,   8e-6, true, 'uniform', 0, Inf};
                    {'Hydrogenated Heads SLD',  0.1e-6,1.4e-6, 3e-6, true, 'uniform', 0, Inf};
                    {'Heads Hydration',         0,      10,   0.5,  true, 'uniform', 0, Inf};
                };
            testCase.layers = { 
                  {'Hydrogenated Heads', 'Heads Thickness', 'Hydrogenated Heads SLD',...
                   'Heads Roughness', 'Heads Hydration', 'bulk out' };      
                  {'Deuterated Heads', 'Heads Thickness', 'Deuterated Heads SLD',...
                   'Heads Roughness', 'Heads Hydration', 'bulk out' };
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
            % Tests project class can be created and the experiment name is set correctly
            newProject = projectClass();
            testCase.verifyEqual(newProject.experimentName, '', 'Experiment name not set correctly');
            newProject = projectClass('New experiment');
            testCase.verifyEqual(newProject.experimentName, 'New experiment', 'Experiment name not set correctly');
            testCase.verifyError(@() projectClass(1), invalidType.errorID)
        end

        function testGeometry(testCase)
            % Test default geometry
            testCase.verifyEqual(testCase.project.geometry, 'air/substrate', 'Geometry not set correctly');
            % Test possible model type with varied case
            testCase.project.setGeometry('Substrate/liquid');
            testCase.verifyEqual(testCase.project.geometry, 'substrate/liquid', 'Geometry not set correctly');
            testCase.project.setGeometry('aIr/SuBstRate');
            testCase.verifyEqual(testCase.project.geometry, 'air/substrate', 'Geometry not set correctly');
            % Test bad inputs 
            testCase.verifyError(@() testCase.project.setGeometry('anything'), invalidOption.errorID)
            testCase.verifyError(@() testCase.project.setGeometry(2), invalidType.errorID)
        end

        function testModelType(testCase)
            % Test default model type
            testCase.verifyEqual(testCase.project.modelType, 'standard layers', 'Model type not set correctly');
            % Test possible model type with varied case
            testCase.project.setModelType('custom Layers');
            testCase.verifyEqual(testCase.project.modelType, 'custom layers', 'Model type not set correctly');
            testCase.project.setModelType('Custom XY');
            testCase.verifyEqual(testCase.project.modelType, 'custom xy', 'Model type not set correctly');
            testCase.project.setModelType('STANDARD LAYERS');
            testCase.verifyEqual(testCase.project.modelType, 'standard layers', 'Model type not set correctly');
            % Test bad inputs 
            testCase.verifyError(@() testCase.project.setModelType('anything'), invalidOption.errorID)
            testCase.verifyError(@() testCase.project.setModelType(2), invalidType.errorID)
        end

        function testUsePriors(testCase)
            % Test default use prior value
            testCase.verifyFalse(testCase.project.usePriors, 'Use priors not set correctly');
            testCase.project.setUsePriors(true);
            testCase.verifyTrue(testCase.project.usePriors, 'Use priors not set correctly');
            % Changing usePriors also changes the showPriors value of the parameters
            testCase.verifyTrue(testCase.project.parameters.showPriors, 'Parameter show priors not set correctly');
            testCase.verifyTrue(testCase.project.bulkIn.showPriors, 'Parameter show priors not set correctly');
            testCase.verifyTrue(testCase.project.bulkOut.showPriors, 'Parameter show priors not set correctly');
            testCase.verifyTrue(testCase.project.scalefactors.showPriors, 'Parameter show priors not set correctly');
            testCase.verifyTrue(testCase.project.qzshifts.showPriors, 'Parameter show priors not set correctly');
            testCase.verifyTrue(testCase.project.background.backPars.showPriors, 'Parameter show priors not set correctly');
            testCase.verifyTrue(testCase.project.resolution.resolPars.showPriors, 'Parameter show priors not set correctly');
            testCase.project.setUsePriors(false);
            testCase.verifyFalse(testCase.project.usePriors, 'Use Priors type not set correctly');
            testCase.verifyFalse(testCase.project.parameters.showPriors, 'Parameter show priors not set correctly');
            testCase.verifyFalse(testCase.project.bulkIn.showPriors, 'Parameter show priors not set correctly');
            testCase.verifyFalse(testCase.project.bulkOut.showPriors, 'Parameter show priors not set correctly');
            testCase.verifyFalse(testCase.project.scalefactors.showPriors, 'Parameter show priors not set correctly');
            testCase.verifyFalse(testCase.project.qzshifts.showPriors, 'Parameter show priors not set correctly');
            testCase.verifyFalse(testCase.project.background.backPars.showPriors, 'Parameter show priors not set correctly');
            testCase.verifyFalse(testCase.project.resolution.resolPars.showPriors, 'Parameter show priors not set correctly');
            % Test bad inputs 
            testCase.verifyError(@() testCase.project.setUsePriors('anything'), invalidType.errorID);
            testCase.verifyError(@() testCase.project.setUsePriors(1), invalidType.errorID);
        end

        function testParameters(testCase)
            % Test default parameter
            testCase.verifySize(testCase.project.parameters.paramsTable, [1, 8], 'Parameters has wrong dimension');
            testCase.verifyEqual(string(testCase.project.parameters.paramsTable{1, :}), ...
                                    string({'Substrate Roughness', 1, 3, 5, true, 'uniform', 0, Inf}), 'Parameters default');

            testCase.verifyError(@() testCase.project.addParamGroup('parameters'), invalidType.errorID)
            testCase.project.addParamGroup(testCase.parameters);
            testCase.verifySize(testCase.project.parameters.paramsTable, [10, 8], 'Parameters has wrong dimension');
            for i = 1:length(testCase.parameters)
                testCase.verifyEqual(string(testCase.project.parameters.paramsTable{i+1, :}),...
                                        string(testCase.parameters{i}) , 'Parameters not set correctly');
            end
            
            % Test adding parameters
            testCase.project.addParam();
            testCase.verifyEqual(testCase.project.parameters.paramsTable{end, 1}, "new parameter 11", 'addParam method not working');
            testCase.verifySize(testCase.project.parameters.paramsTable, [11, 8], 'Parameters has wrong dimension');
            testCase.project.addParam('NewParam2');
            testCase.verifyEqual(testCase.project.parameters.paramsTable{end, 1}, "NewParam2", 'addParam method not working');
            testCase.verifySize(testCase.project.parameters.paramsTable, [12, 8], 'Parameters has wrong dimension');
            % Test removing parameters
            testCase.project.removeParam('NewParam2');
            testCase.verifyEqual(testCase.project.parameters.paramsTable{end, 1}, "new parameter 11", 'removeParam method not working');
            testCase.verifySize(testCase.project.parameters.paramsTable, [11, 8], 'Parameters has wrong dimension');
            testCase.verifyError(@() testCase.project.removeParam('Substrate Roughness'), invalidOption.errorID) % can't remove substrate roughness
            testCase.project.removeParam(11);
            testCase.verifyEqual(testCase.project.parameters.paramsTable{end, 1}, "Heads Hydration", 'removeParam method not working');
            testCase.verifySize(testCase.project.parameters.paramsTable, [10, 8], 'Parameters has wrong dimension');
             % Test setting the different parameter properties
            testCase.project.setParameter(2, 'value', 50);
            testCase.verifyEqual(testCase.project.parameters.paramsTable{2, 3}, 50, 'setParameter method not working');
            testCase.project.setParamValue(2, 13);
            testCase.verifyEqual(testCase.project.parameters.paramsTable{2, 3}, 13, 'setParamValue method not working');
            testCase.project.setParamConstr('Tails Thickness', 0, 100);
            testCase.verifyEqual(testCase.project.parameters.paramsTable{2, 2}, 0, 'setParamConstr method not working');
            testCase.verifyEqual(testCase.project.parameters.paramsTable{2, 4}, 100, 'setParamConstr method not working');
            testCase.project.setParamName(2, 'NewParam');
            testCase.verifyEqual(testCase.project.parameters.paramsTable{2, 1}, "NewParam", 'setParamName method not working');
            testCase.project.setParamName(2, 'Tails Thickness');
            testCase.verifyError(@() testCase.project.setParamName(1, 'name'), invalidOption.errorID) % can't rename substrate roughness
            testCase.project.setParamFit('Tails Thickness', false);
            testCase.verifyEqual(testCase.project.parameters.paramsTable{2, 5}, false, 'setParamFit method not working');
            testCase.project.setParamPrior(2, 'uniform');
            testCase.verifyEqual(testCase.project.parameters.paramsTable{2, 6}, "uniform", 'setParamPrior method not working');
        end

        function testLayers(testCase)
            % Adds parameters for the tests
            testCase.addParameters()
            % Test default layer
            testCase.verifySize(testCase.project.layers.layersTable, [0, 6], 'Layers has wrong dimension');
            % Test adding LayerGroup
            testCase.verifyError(@() testCase.project.addLayerGroup([]), invalidType.errorID)
            testCase.project.addLayerGroup(testCase.layers);
            testCase.verifySize(testCase.project.layers.layersTable, [4, 6], 'Layers has wrong dimension');
            for i = 1:length(testCase.layers)
                for j = 1:length(testCase.layers{i})
                    testCase.verifyEqual(testCase.project.layers.layersTable{i, j},...
                                            string(testCase.layers{i}{j}), 'addLayerGroup method not working');
                end
            end

            % Test adding single layer
            testCase.project.addLayer();  % Adds empty layer
            testCase.verifySize(testCase.project.layers.layersTable, [5, 6], 'Layers has wrong dimension');
            testCase.verifyEqual(testCase.project.layers.layersTable{5, 1}, "Layer 5", 'addLayer method not working');
            testCase.project.addLayer('New Layer');  % Adds layer with name only
            testCase.verifySize(testCase.project.layers.layersTable, [6, 6], 'Layers has wrong dimension');
            testCase.verifyEqual(testCase.project.layers.layersTable{6, 1}, "New Layer", 'addLayer method not working');
            layer = testCase.layers{1};
            layer{1} = 'Another Layer';
            testCase.project.addLayer(layer{:});  % Adds layer with full set of parameters
            testCase.verifySize(testCase.project.layers.layersTable, [7, 6], 'Layers has wrong dimension');
            testCase.verifyEqual(testCase.project.layers.layersTable{7, 1}, "Another Layer", 'addLayer method not working');
            % Test setting value in a layer
            testCase.verifyError(@() testCase.project.setLayerValue(1), invalidNumberOfInputs.errorID)  % not enough arguments
            testCase.verifyError(@() testCase.project.setLayerValue(1, 2, 'Tail'), nameNotRecognised.errorID)  % parameter does not exist
            testCase.verifyError(@() testCase.project.setLayerValue(1, 2, 11), indexOutOfRange.errorID)  % index greater than parameter table
            testCase.project.setLayerValue(1, 2, 'Tails Thickness');
            testCase.verifyEqual(testCase.project.layers.layersTable{1, 2}, "Tails Thickness", 'setLayerValue method not working');
            testCase.project.setLayerValue('Hydrogenated Tails', 4, 'Heads Roughness');
            testCase.verifyEqual(testCase.project.layers.layersTable{1, 4}, "Heads Roughness", 'setLayerValue method not working');
            testCase.project.setLayerValue(2, 3, 1);
            testCase.verifyEqual(testCase.project.layers.layersTable{2, 3}, "Substrate Roughness", 'setLayerValue method not working');
            % Check removing a parameter removes it from layer
            testCase.verifyEqual(testCase.project.layers.layersTable{2, 2}, "Heads Thickness", 'param not removed from layers');
            testCase.verifyEqual(testCase.project.layers.layersTable{7, 2}, "Heads Thickness", 'param not removed from layers');
            testCase.project.removeParam('Heads Thickness');
            testCase.verifyEqual(testCase.project.layers.layersTable{2, 2}, "", 'param not removed from layers');
            testCase.verifyEqual(testCase.project.layers.layersTable{7, 2}, "", 'param not removed from layers');
            % Test removing a layer
            testCase.project.removeLayer(1);
            testCase.verifySize(testCase.project.layers.layersTable, [6, 6], 'Layers has wrong dimension');
            testCase.verifyEqual(testCase.project.layers.layersTable{:, 1}, ["Deuterated Heads"; "Deuterated Tails"; "Hydrogenated Tails"; "Layer 5"; "New Layer"; "Another Layer"], 'removeLayer method not working');
        end

        function testData(testCase)
            % Checks the default data parameter
            testCase.verifySize(testCase.project.data.dataTable, [1, 4], 'data has wrong dimension');
            default = {"Simulation", {[]}, {[]}, {[0.0050, 0.7000]}};
            for i = 1:4
                testCase.verifyEqual(testCase.project.data.dataTable{1, i}, default{i}, 'data default');
            end
            % Test adding data
            data = ones(4, 3);                          
            testCase.project.addData('Sim 2', data);
            testCase.verifySize(testCase.project.data.dataTable, [2, 4], 'data has wrong dimension');
            testCase.verifyEqual(testCase.project.data.dataTable{:, 1}, ["Simulation"; "Sim 2"], 'addData method not working');
            % Test modifying data
            testCase.project.setData(1, 'name', 'Sim 1', 'data', zeros(4, 3), 'dataRange', [0, 1],'simRange', [1, 2]);
            expected = {"Sim 1", {zeros(4, 3)}, {[0, 1]}, {[1, 2]}};
            for i = 1:4
                testCase.verifyEqual(testCase.project.data.dataTable{1, i}, expected{i}, 'setData method not working');
            end
            testCase.verifyEqual(testCase.project.data.dataTable{2, 1}, "Sim 2", 'setData method not working');
            % Tests that data can be removed
            testCase.project.removeData(2);
            testCase.verifySize(testCase.project.data.dataTable, [1, 4], 'data has wrong dimension');
            testCase.verifyEqual(testCase.project.data.dataTable{:, 1}, "Sim 1", 'removeData method not working');
        end

        function testBulkIn(testCase)
            % Checks the default Bulk-in
            testCase.verifySize(testCase.project.bulkIn.paramsTable, [1, 8], 'BulkIn has wrong dimension');
            testCase.verifyEqual(string(testCase.project.bulkIn.paramsTable{1, :}),...
                                    string({'SLD Air', 0, 0, 0, false, 'uniform', 0, Inf}), 'BulkIn default');
            % Tests that Bulk-in can be added
            testCase.project.addBulkIn('Silicon', 2.07e-6, 2.073e-6, 2.08e-6, false);
            testCase.verifySize(testCase.project.bulkIn.paramsTable, [2, 8], 'BulkIn has wrong dimension');
            testCase.verifyEqual(testCase.project.bulkIn.paramsTable{end, 1}, "Silicon", 'addBulkIn method not working');
            % Tests that Bulk-in can be removed
            testCase.project.removeBulkIn(2);
            testCase.verifySize(testCase.project.bulkIn.paramsTable, [1, 8], 'BulkIn has wrong dimension');
            testCase.verifyEqual(testCase.project.bulkIn.paramsTable{:, 1}, "SLD Air", 'removeBulkIn method not working');
            % Tests that Bulk-in can be modified
            testCase.project.setBulkIn(1, 'name', 'Silicon', 'min', 2.07e-6, 'value',2.073e-6, 'max', 2.08e-6, 'fit', true);
            testCase.verifyEqual(string(testCase.project.bulkIn.paramsTable{1, :}),...
                                    string({'Silicon', 2.07e-6, 2.073e-6, 2.08e-6, true, 'uniform', 0, Inf}), 'setBulkIn method not working');
        end

        function testBulkOut(testCase)
            % Checks the default Bulk-out
            testCase.verifySize(testCase.project.bulkOut.paramsTable, [1, 8], 'BulkOut has wrong dimension');
            testCase.verifyEqual(string(testCase.project.bulkOut.paramsTable{1, :}),...
                                    string({'SLD D2O', 6.2e-6, 6.35e-6, 6.35e-6, false, 'uniform', 0, Inf}), 'BulkOut default');
            % Tests that Bulk-out can be added
            testCase.project.addBulkOut('SLD ACMW', -1e-6, 0.0, 1e-6, true);
            testCase.verifySize(testCase.project.bulkOut.paramsTable, [2, 8], 'BulkOut has wrong dimension');
            testCase.verifyEqual(testCase.project.bulkOut.paramsTable{end,1}, "SLD ACMW", 'addBulkOut method not working');
            testCase.project.addBulkOut('SLD H2O', -0.6e-6, -0.56e-6, -0.3e-6, true);
            testCase.verifySize(testCase.project.bulkOut.paramsTable, [3, 8], 'BulkOut has wrong dimension');
            % Tests that Bulk-out can be removed
            testCase.project.removeBulkOut(3);
            testCase.verifySize(testCase.project.bulkOut.paramsTable, [2, 8], 'BulkOut has wrong dimension');
            testCase.verifyEqual(testCase.project.bulkOut.paramsTable{:, 1}, ["SLD D2O"; "SLD ACMW"], 'removeBulkOut method not working');
            % Tests that Bulk-out can be modified
            testCase.project.setBulkOut(1, 'name', 'SLD H2O', 'min', 2.07e-6, 'value',2.073e-6, 'max', 2.08e-6, 'fit', true);
            testCase.verifyEqual(string(testCase.project.bulkOut.paramsTable{1, :}),...
                                    string({'SLD H2O', 2.07e-6, 2.073e-6, 2.08e-6, true, 'uniform', 0, Inf}), 'setBulkOut method not working');
        end
            
        function testScaleFactor(testCase)
            % Checks the default scale factors
            testCase.verifySize(testCase.project.scalefactors.paramsTable, [1, 8], 'scalefactors has wrong dimension');
            testCase.verifyEqual(string(testCase.project.scalefactors.paramsTable{1, :}),...
                                    string({'Scalefactor 1', 0.02, 0.23, 0.25, false, 'uniform', 0, Inf}), 'scalefactors default');
            % Checks that scale factors can be added
            testCase.project.addScalefactor({'Scalefactor 2', 0.1, 0.19, 1.0, true});
            testCase.project.addScalefactor({'Scalefactor 3', 0.2, 0.17, 1.1, false});
            testCase.verifySize(testCase.project.scalefactors.paramsTable, [3, 8], 'scalefactors has wrong dimension');
            testCase.verifyEqual(testCase.project.scalefactors.paramsTable{end,1}, "Scalefactor 3", 'addScalefactor method not working');
            % Checks that scale factors can be removed
            testCase.project.removeScalefactor(2);
            testCase.verifySize(testCase.project.scalefactors.paramsTable, [2, 8], 'scalefactors has wrong dimension');
            testCase.verifyEqual(testCase.project.scalefactors.paramsTable{:, 1}, ["Scalefactor 1"; "Scalefactor 3"], 'removeScalefactor method not working');
            % Checks that scale factors can be modified
            testCase.project.setScalefactor(1, 'name','Scalefactor 1','min',0.1,'value',0.23251,'max',0.4,'fit',true);
            testCase.verifyEqual(string(testCase.project.scalefactors.paramsTable{1, :}),...
                                    string({'Scalefactor 1', 0.1, 0.23251, 0.4, true, 'uniform', 0, Inf}), 'setBulkIn method not working');
        end
            
        function testQzShift(testCase)
            % Checks the default Qz shift
            testCase.verifySize(testCase.project.qzshifts.paramsTable, [1, 8], 'qzshifts has wrong dimension');
            testCase.verifyEqual(string(testCase.project.qzshifts.paramsTable{1, :}),...
                                    string({'Qz shift 1', -1e-4, 0, 1e-4, false, 'uniform', 0, Inf}), 'qzshifts default');
            % Checks that Qz shift can be added
            testCase.project.addQzshift({'Qz shift 2', -2e-4, 0, 2e-4, false});
            testCase.verifySize(testCase.project.qzshifts.paramsTable, [2, 8], 'qzshifts has wrong dimension');
            testCase.verifyEqual(testCase.project.qzshifts.paramsTable{end, 1}, "Qz shift 2", 'addQzshift method not working');
        end

        function testResolution(testCase)
            % Checks the default resolution parameter 
            testCase.verifySize(testCase.project.resolution.resolPars.paramsTable, [1, 8], 'resolution parameter has wrong dimension');
            testCase.verifyEqual(string(testCase.project.resolution.resolPars.paramsTable{1, :}),...
                                    string({'Resolution par 1', 0.01, 0.03, 0.05, false, 'uniform', 0, Inf}), 'resolution parameter default');
            % Checks that resolution parameter can be added
            testCase.project.addResolPar('Resolution par 2', 0.1, 0.19, 1.0, true);
            testCase.project.addResolPar('Resolution par 3', 0.2, 0.17, 1.1, false);
            testCase.verifySize(testCase.project.resolution.resolPars.paramsTable, [3, 8], 'resolution parameter has wrong dimension');
            testCase.verifyEqual(testCase.project.resolution.resolPars.paramsTable{end, 1}, "Resolution par 3", 'addResolPar method not working');
            % Checks that resolution parameter can be removed
            testCase.project.removeResolPar(2);
            testCase.verifySize(testCase.project.resolution.resolPars.paramsTable, [2, 8], 'resolution parameter has wrong dimension');
            testCase.verifyEqual(testCase.project.resolution.resolPars.paramsTable{:, 1}, ["Resolution par 1"; "Resolution par 3"], 'removeResolPar method not working');
            % Checks that resolution parameter can be modified
            testCase.project.setResolParValue('Resolution par 1', 0.2325);
            testCase.verifyEqual(testCase.project.resolution.resolPars.paramsTable{1, 3}, 0.2325, 'setResolParValue method not working with name value pair');
            testCase.project.setResolParValue(2, 0.4);
            testCase.verifyEqual(testCase.project.resolution.resolPars.paramsTable{2, 3}, 0.4, 'setResolParValue method not working with index value pair');
            testCase.project.setResolPar(2, 'name', 'ResolPar', 'min', 0, 'value', 0.5, 'max', 1,'fit',true);
            testCase.verifySize(testCase.project.resolution.resolPars.paramsTable, [2, 8], 'resolution parameter has wrong dimension');
            testCase.verifyEqual(string(testCase.project.resolution.resolPars.paramsTable{2, :}),...
                                    string({'ResolPar', 0, 0.5, 1, true, 'uniform', 0, Inf}), 'setResolPar method not working');
            % Checks the default resolution parameter 
            testCase.verifySize(testCase.project.resolution.resolutions.typesTable, [1, 7], 'resolution has wrong dimension');
            testCase.verifyEqual(string(testCase.project.resolution.resolutions.typesTable{1, :}),...
                                    string({'Resolution 1', 'constant', 'Resolution par 1', '', '', '', ''}), 'resolution default');
            % Checks that resolution can be added
            testCase.project.addResolution('Resolution 2', 'constant','Resolution par 1','','','','');
            testCase.verifySize(testCase.project.resolution.resolutions.typesTable, [2, 7], 'resolution has wrong dimension');
            testCase.verifyEqual(testCase.project.resolution.resolutions.typesTable{:, 1}, ["Resolution 1"; "Resolution 2"], 'addResolution method not working');
            % Checks that resolution can be removed
            testCase.project.removeResolution(1);
            testCase.verifySize(testCase.project.resolution.resolutions.typesTable, [1, 7], 'resolution has wrong dimension');
            testCase.verifyEqual(testCase.project.resolution.resolutions.typesTable{:, 1}, "Resolution 2", 'addResolution method not working');
        end

        function testBackground(testCase)
            % Checks the default background parameter 
            testCase.verifySize(testCase.project.background.backPars.paramsTable, [1, 8], 'background parameter has wrong dimension');
            testCase.verifyEqual(string(testCase.project.background.backPars.paramsTable{1, :}),...
                                    string({'Backs par 1', 1e-7, 1e-6, 1e-5, false, 'uniform', 0, Inf}), 'background parameter default');
            % Checks that background parameter can be added
            testCase.project.addBacksPar('Backs Value D2O', 1e-8, 2.8e-6, 1e-5, true);
            testCase.verifyEqual(testCase.project.background.backPars.paramsTable{end,1}, "Backs Value D2O", 'addBacksPar method not working');
            % Checks that background parameter can be modified
            testCase.project.setBacksPar(1, 'name', 'Backs Value H2O', 'min', 0.1, 'value', 0.23251, 'max', 0.4, 'fit', true);
            testCase.verifyEqual(string(testCase.project.background.backPars.paramsTable{1, :}),...
                                    string({'Backs Value H2O', 0.1, 0.23251, 0.4, true, 'uniform', 0, Inf}), 'setBacksPar method not working');
            % Checks that background parameter can be removed
            testCase.project.removeBacksPar(2);
            testCase.verifySize(testCase.project.background.backPars.paramsTable, [1, 8], 'background has wrong dimension');
            testCase.verifyEqual(testCase.project.background.backPars.paramsTable{:, 1}, "Backs Value H2O", 'removeBacksPar method not working');
            % Checks that background parameter value can be modified
            testCase.project.setBacksParValue(1, 5.5e-6);
            testCase.verifyEqual(testCase.project.background.backPars.paramsTable{1, 3}, 5.5e-6, 'setBacksParValue method not working');
            % Checks that background parameter name can be modified
            testCase.project.setBacksParName(1, 'Backs Value D2O');
            testCase.verifyEqual(testCase.project.background.backPars.paramsTable{1, 1}, "Backs Value D2O", 'setBacksParName method not working');
            % Checks that background parameter constraints can be modified
            testCase.project.setBacksParConstr(1, 0, 1);
            testCase.verifyEqual(testCase.project.background.backPars.paramsTable{1, 2}, 0, 'setBacksParConstr method not working');
            testCase.verifyEqual(testCase.project.background.backPars.paramsTable{1, 4}, 1, 'setBacksParConstr method not working');

            % Checks the default background parameter 
            testCase.verifySize(testCase.project.background.backgrounds.typesTable, [1, 7], 'background has wrong dimension');
            testCase.verifyEqual(string(testCase.project.background.backgrounds.typesTable{1, :}),...
                                      string({'Background 1', 'constant', 'Backs Par 1', '', '', '', ''}), 'background default');
            % Checks that background can be added
            testCase.project.addBackground('Background D2O','constant','Backs Value D2O');
            testCase.verifySize(testCase.project.background.backgrounds.typesTable, [2, 7], 'background has wrong dimension');
            testCase.verifyEqual(testCase.project.background.backgrounds.typesTable{:, 1}, ["Background 1"; "Background D2O"], 'addBackground method not working');
            % Checks that background can be removed
            testCase.project.removeBackground(1);
            testCase.verifySize(testCase.project.background.backgrounds.typesTable, [1, 7], 'background has wrong dimension');
            testCase.verifyEqual(testCase.project.background.backgrounds.typesTable{:, 1}, "Background D2O", 'addBackground method not working');
            % Checks that background value can be modified
            testCase.project.setBackground(1, 'name', 'Background ACMW');
            testCase.verifyEqual(testCase.project.background.backgrounds.typesTable{1, 1}, "Background ACMW", 'setBackground method not working');
            % Checks that background name can be modified
            testCase.project.setBackgroundName(1, 'Background H2O');
            testCase.verifyEqual(testCase.project.background.backgrounds.typesTable{1, 1}, "Background H2O", 'setBackgroundName method not working');
        end

        function testContrast(testCase)
            % Populates project properties for the tests
            testCase.populateProject()
            % Checks the default contrast
            testCase.verifyEmpty(testCase.project.contrasts.contrasts, 'contrast has wrong dimension');
            % Checks that contrast can be added
            testCase.project.addContrast('name', 'Bilayer / H2O', 'background', 'Background H2O', 'resolution', 'Resolution 2',...
                                         'scalefactor', 'Scalefactor 1', 'resample', false, 'nbs', 'SLD D2O', 'nba', 'SLD Air',...
                                         'data', 'Sim 1');
            testCase.verifyLength(testCase.project.contrasts.contrasts, 1, 'contrast has wrong dimension');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{1}.name, 'Bilayer / H2O', 'addContrast method not working');

            testCase.project.addContrast('name', 'Another Bilayer', 'background', 'Background H2O', 'resolution', 'Resolution 2',...
                                         'scalefactor', 'Scalefactor 1', 'resample', false, 'nbs', 'SLD H2O', 'nba', 'Silicon',...
                                         'data', 'Sim 2');
            testCase.verifyLength(testCase.project.contrasts.contrasts, 2, 'contrast has wrong dimension');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{2}.name, 'Another Bilayer', 'addContrast method not working');
            % Checks that contrast can be modified
            testCase.verifyError(@() testCase.project.setContrast(3, 'name', 'First Bilayer'), indexOutOfRange.errorID)
            testCase.verifyError(@() testCase.project.setContrast('Bilayer', 'name', 'First Bilayer'), nameNotRecognised.errorID)
            testCase.project.setContrast(1, 'name', 'First Bilayer', 'nbs', 'SLD H2O');
            testCase.verifyLength(testCase.project.contrasts.contrasts, 2, 'contrast has wrong dimension');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{1}.name, 'First Bilayer', 'setContrast method not working');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{1}.nbs, 'SLD H2O', 'setContrast method not working');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{1}.nba, 'SLD Air', 'setContrast method not working');
            testCase.project.setContrast('First Bilayer', 'nba', 'Silicon');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{1}.name, 'First Bilayer', 'setContrast method not working');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{1}.nbs, 'SLD H2O', 'setContrast method not working');
            testCase.verifyEqual(testCase.project.contrasts.contrasts{1}.nba, 'Silicon', 'setContrast method not working');
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
            testCase.verifyError(@() testCase.project.setContrastModel(3, {}), indexOutOfRange.errorID)
            testCase.verifyError(@() testCase.project.setContrastModel('Bilayer', {}), nameNotRecognised.errorID);
            
            % FIXME setContrastModel crashes if the model type is custom 
        end

        function testCustomFile(testCase)
            % Checks the default custom file
            testCase.verifySize(testCase.project.customFile.fileTable, [0, 4], 'custom file table has wrong dimension');
            % Checks that custom file can be added
            testCase.project.addCustomFile('model 1', 'custom.m', 'matlab', 'pwd');
            testCase.project.addCustomFile('model 2', 'custom.cpp', 'cpp', 'c:/temp');
            testCase.verifySize(testCase.project.customFile.fileTable, [2, 4], 'custom file table has wrong dimension');    
            testCase.verifyEqual(testCase.project.customFile.fileTable{:, 1}, ["model 1"; "model 2"], 'addCustomFile method not working');
            testCase.verifyEqual(testCase.project.customFile.fileTable{:, 2}, ["custom.m"; "custom.cpp"], 'addCustomFile method not working');
            testCase.verifyEqual(testCase.project.customFile.fileTable{:, 3}, ["matlab"; "cpp"], 'addCustomFile method not working');
            testCase.verifyEqual(testCase.project.customFile.fileTable{:, 4}, ["pwd"; "c:/temp"], 'addCustomFile method not working');
            % Checks that custom file can be modified
            % Cannot set path due to unimplemented field 'setCustomPath' for class 'customFileClass'.
            testCase.project.setCustomFile(2, 'filename', 'cust.m');  %, 'path', '/home/folder');
            testCase.verifyEqual(testCase.project.customFile.fileTable{2, 2}, "cust.m", 'setCustomFile method not working');
            % testCase.verifyEqual(testCase.project.customFile.fileTable{2, 4}, "/home/folder", 'setCustomFile method not working');
            testCase.project.setCustomFile('model 1', 'language', 'matlab');
            testCase.verifyEqual(testCase.project.customFile.fileTable{1, 3}, "matlab", 'setCustomFile method not working');
            % Test removing a row
            testCase.project.removeCustomFile(1);
            testCase.verifySize(testCase.project.customFile.fileTable, [1, 4], 'custom file table has wrong dimension');
            testCase.verifyEqual(testCase.project.customFile.fileTable{1, :}, ["model 2", "cust.m", "cpp", "c:/temp"], 'removeCustomFile method not working');

        end

        function testToStruct(testCase)
            % FIXME: toStruct carshes with the default
            % projectStruct = testCase.project.toStruct();
            % testCase.verifyEqual(projectStruct.experimentName, testCase.project.experimentName, 'toStruct method not working');
            % testCase.verifyEqual(projectStruct.geometry, testCase.project.geometry, 'toStruct method not working');
            % testCase.verifyEqual(projectStruct.TF, 'standardTF', 'toStruct method not working');
            % testCase.verifyEqual(projectStruct.paramNames, {'Substrate Roughness'}, 'toStruct method not working');
            % testCase.verifyEqual(projectStruct.backgroundNames, testCase.project.background.backgrounds.typesTable{:, 1}, 'toStruct method not working');
            % testCase.verifyEqual(projectStruct.backgroundTypes, testCase.project.background.backgrounds.typesTable{:, 2}, 'toStruct method not working');
            % testCase.verifyEqual(projectStruct.backParNames, ...
            %                      {convertStringsToChars(testCase.project.background.backPars.paramsTable{:, 1})}, 'toStruct method not working');
            % testCase.verifyEqual(projectStruct.resolutionNames, testCase.project.resolution.resolutions.typesTable{:, 1}, 'toStruct method not working');
            % testCase.verifyEqual(projectStruct.resolutionTypes, testCase.project.resolution.resolutions.typesTable{:, 2}, 'toStruct method not working');
            % testCase.verifyEqual(projectStruct.resolParNames, ...
            %                      {convertStringsToChars(testCase.project.resolution.resolPars.paramsTable{:, 1})}, 'toStruct method not working');
            % testCase.verifyEqual(projectStruct.resolutionNames, testCase.project.resolution.resolutions.typesTable{:, 1}, 'toStruct method not working');
            % testCase.verifyEqual(projectStruct.scalefactorNames, {convertStringsToChars(testCase.project.scalefactors.paramsTable{:, 1})}, 'toStruct method not working');
            % testCase.verifyEqual(projectStruct.qzshiftNames, {convertStringsToChars(testCase.project.qzshifts.paramsTable{:, 1})}, 'toStruct method not working');
            % testCase.verifyEqual(projectStruct.nbairNames, {convertStringsToChars(testCase.project.bulkIn.paramsTable{:, 1})}, 'toStruct method not working');
            % testCase.verifyEqual(projectStruct.nbsubNames, {convertStringsToChars(testCase.project.bulkOut.paramsTable{:, 1})}, 'toStruct method not working');
            % testCase.verifyEqual(projectStruct.nbsubNames, {convertStringsToChars(testCase.project.bulkOut.paramsTable{:, 1})}, 'toStruct method not working');
            % testCase.verifyEqual(projectStruct.layersnames, testCase.project.layers.layersTable{:, 1}, 'toStruct method not working');
            %testCase.verifyEqual(projectStruct.nbsubNames, {convertStringsToChars(testCase.project.bulkOut.paramsTable{:, 1})}, 'toStruct method not working');

            % Populates project properties for the tests
            testCase.populateProject()
            testCase.project.addContrast('name', 'Bilayer / H2O', 'background', 'Background H2O', 'resolution', 'Resolution 2',...
                             'scalefactor', 'Scalefactor 1', 'resample', false, 'nbs', 'SLD D2O', 'nba', 'SLD Air',...
                             'data', 'Sim 1');
            % Test properties are written to struct
            projectStruct = testCase.project.toStruct();
            testCase.verifyEqual(projectStruct.experimentName, testCase.project.experimentName, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.geometry, testCase.project.geometry, 'toStruct method not working');
            testCase.verifyEqual(projectStruct.TF, 'standardTF', 'toStruct method not working');
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
            testCase.verifyEqual(projectStruct.layersnames, testCase.project.layers.layersTable{:, 1}, 'toStruct method not working');
        end

        function testObjectDisplay(testCase)
            % Check that the content of the project are printed 
            display = evalc('disp(testCase.project)');
            testCase.verifyNotEmpty(display, 'displayScalarObject method not working')
            testCase.verifySubstring(display, "experimentName: 'example'", 'displayScalarObject method not working')
        end
    end
end