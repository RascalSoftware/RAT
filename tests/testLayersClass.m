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
% Paul Sharp 02/02/23
%
%% Declare properties and parameters

    properties
        exampleClass;           % Example layers class for testing
        initialLayersTable      % Empty table to compare to initialisation
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

    end

    methods (TestMethodSetup)

        function initialiseLayersClass(testCase)
            % Set up an example layers class for testing
            % This example is used in the example calculation
            % "DPPC_standard_layers.m"
            testCase.exampleClass = layersClassRealSLD();

            testCase.exampleClass.layersTable(1,:) = {'Oxide Layer', 'Oxide thick', 'Oxide SLD', 'Substrate Roughness', 'Oxide Hydration', 'bulk out'};
            testCase.exampleClass.layersTable(2,:) = {'Water Layer', 'Water thick', 'Water SLD', 'Bilayer heads rough', 'Water hydr', 'Bulk out'};
            testCase.exampleClass.layersTable(3,:) = {'Bil inner head', 'Bilayer heads thick', 'Bilayer heads SLD', 'Bilayer heads rough', 'Bilayer heads hydr', 'Bulk out'};
            testCase.exampleClass.layersTable(4,:) = {'Bil tail', 'Bilayer tails thick', 'Bilayer tails SLD', 'Bilayer heads rough', 'Bilayer tails hydr', 'bulk out'};
            testCase.exampleClass.layersTable(5,:) = {'Bil outer head', 'Bilayer heads thick', 'Bilayer heads SLD', 'Bilayer heads rough', 'Bilayer heads hydr', 'Bulk out'};

            testCase.numRows = height(testCase.exampleClass.layersTable);
            testCase.numCols = width(testCase.exampleClass.layersTable);
        end

    end

%% Test Layers Real SLD Class Routines

    methods (Test)

        function testInitialiseLayersClass(testCase)
            % On initialisation we set up a layers class with an empty
            % layers table
            testClass = layersClassRealSLD();

            testCase.verifySize(testClass.layersTable, [0 6], "layerClassRealSLD does not initialise correctly");
            testCase.verifyEqual(testClass.layersTable, testCase.initialLayersTable, "layerClassRealSLD does not initialise correctly");
        end

    end

end