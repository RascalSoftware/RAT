classdef testLayersClass < matlab.unittest.TestCase
%%
% testLayersClass Class based unit tests for the layersClassRealSLD
% used within the Project Class in RAT.
%
% In this class, we test:
%
% We use an example layers class from example calculation
% "DPPC_standard_layers.m"
%
% Paul Sharp 03/02/23
%
%% Declare properties and parameters

    properties (TestParameter)
        % Cell arrays for initialising a multi type table
        LayerInput = {{'empty'},...
                      {'empty named', 'Named Layer'},...
                      {'full layer', {{'Water Layer',...
                                       'Water thick',...
                                       'Water SLD',...
                                       'Bilayer heads rough',...
                                       'Water hydr',...
                                       'Bulk out'}}}
                      }
        addedLayer = {{'Layer 1','','','','','bulk out'},...
                      {'Named Layer','','','','','bulk out'},...
                      {'Water Layer',...
                       'Water thick',...
                       'Water SLD',...
                       'Bilayer heads rough',...
                       'Water hydr',...
                       'Bulk out'}}
    end

    properties
        exampleClass;           % Example layers class for testing
        initialLayersTable      % Empty table to compare to initialisation
        parameters              % Example parameters class used in "addLayer"
        numRows                 % Number of rows in exampleClass.layersTable
        numCols                 % Number of columns in exampleClass.layersTable
    end

%% Set up test data

    methods (TestClassSetup)

        function initialiselayersTable(testCase)
            % Set up an empty layers table 
            sz = [0 6];
            tableTypes = {'string','string','string','string','string','string'};
            tableNames = {'Name','Thickness','SLD','Roughness','Hydration','Hydrate with'};

            testCase.initialLayersTable = table('Size',sz,'VariableTypes',tableTypes,'VariableNames',tableNames);
        end

        function initialiseParameters(testCase)
            % Set up an example parameters class. This example is used in
            % the example calculation "DPPC_standard_layers.m"
            testParams = {
                %       Name           min      val     max   fit? 'Prior Type' 'mu' 'sigma'
                'Oxide thick',         5,       20,      60,   true, 'uniform',  0,   Inf;
                'Oxide SLD',           3e-6,  3.41e-6,  4e-6, false, 'uniform',  0,   Inf;
                'Oxide Hydration'      0,       20,      30,   true, 'uniform',  0,   Inf;
                'Bilayer heads thick', 5,       10,      15,   true, 'uniform',  0,   Inf;
                'Bilayer heads SLD',   1e-6,  1.47e-6,  3e-6,  true, 'uniform',  0,   Inf;
                'Bilayer heads hydr',  20,      30,      50,   true, 'uniform',  0,   Inf;
                'Bilayer heads rough'  5,        7,      15,   true, 'uniform',  0,   Inf;
                'Bilayer tails thick', 10,      10,      20,   true, 'uniform',  0,   Inf;
                'Bilayer tails SLD',   -5e-7, -4e-7,   -1e-7, false, 'uniform',  0,   Inf;
                'Bilayer tails hydr',  0,       10,      20,   true, 'uniform',  0,   Inf;
                'Bilayer tails rough', 5,        9,      15,   true, 'uniform',  0,   Inf;
                'Water thick',         0,        1,      15,   true, 'uniform',  0,   Inf;
                'Water SLD',           0,        0,       0,  false, 'uniform',  0,   Inf;
                'Water hydr',          100,    100,     100,  false, 'uniform',  0,   Inf;
                };

            testCase.parameters = parametersClass(testParams(1, :));
            testCase.parameters.paramsTable = [testCase.parameters.paramsTable; vertcat(testParams(2:end, :))];
        end

    end

    methods (TestMethodSetup)

        function initialiseLayersClass(testCase)
            % Set up an example layers class for testing
            % This example is used in the example calculation
            % "DPPC_standard_layers.m"
            testCase.exampleClass = layersClassRealSLD();

            %testCase.exampleClass.layersTable(1,:) = {'Oxide Layer', 'Oxide thick', 'Oxide SLD', 'Substrate Roughness', 'Oxide Hydration', 'bulk out'};
            %testCase.exampleClass.layersTable(2,:) = {'Water Layer', 'Water thick', 'Water SLD', 'Bilayer heads rough', 'Water hydr', 'Bulk out'};
            testCase.exampleClass.layersTable(1,:) = {'Bil inner head', 'Bilayer heads thick', 'Bilayer heads SLD', 'Bilayer heads rough', 'Bilayer heads hydr', 'Bulk out'};
            testCase.exampleClass.layersTable(2,:) = {'Bil tail', 'Bilayer tails thick', 'Bilayer tails SLD', 'Bilayer heads rough', 'Bilayer tails hydr', 'bulk out'};
            testCase.exampleClass.layersTable(3,:) = {'Bil outer head', 'Bilayer heads thick', 'Bilayer heads SLD', 'Bilayer heads rough', 'Bilayer heads hydr', 'Bulk out'};

            testCase.numRows = height(testCase.exampleClass.layersTable);
            testCase.numCols = width(testCase.exampleClass.layersTable);
        end

    end

%% Test Layers Real SLD Class Routines

    methods (Test, ParameterCombination="sequential")

        function testInitialiseLayersClass(testCase)
            % On initialisation we set up a layers class with an empty
            % layers table
            testClass = layersClassRealSLD();

            testCase.verifySize(testClass.layersTable, [0 6], "layerClassRealSLD does not initialise correctly");
            testCase.verifyEqual(testClass.layersTable, testCase.initialLayersTable, "layerClassRealSLD does not initialise correctly");
        end

        function testAddLayer(testCase, LayerInput, addedLayer)
            % Test adding a layer to the layers class.
            % We can add a layer with no parameters, just a layer name, or
            % a fully defined layer.
            % The first parameter should be either "empty", "empty named",
            % or "full layer" to determine how many parameters will then be
            % specified: none for "empty", one for "empty named", and
            % either a length four or length six cell array for "full
            % layer"             
            expectedTable = [testCase.exampleClass.layersTable; addedLayer];

            testCase.exampleClass.addLayer(LayerInput, testCase.parameters.paramsTable);

            testCase.verifyEqual(testCase.exampleClass.layersTable, expectedTable, "addLayer does not work correctly");
        end


        


    end

end