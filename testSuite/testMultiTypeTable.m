classdef testMultiTypeTable < matlab.unittest.TestCase
%%
% testMultiTypeTable Class based unit tests for the Multi Type Table Class
% used within the Project Class in RAT.
%
% In this class, we test:
% ?????????????????
%
% We use an example
%
% Paul Sharp 24/01/23
%
%% Declare properties and parameters

    properties (ClassSetupParameter)
        inputsFile = {'standardLayersInputs.mat', 'customLayersInputs.mat', 'customXYInputs.mat'};     % Input test data
        outputsFile = {'standardLayersOutputs.mat', 'customLayersOutputs.mat', 'customXYOutputs.mat'}; % Output test data
        TFFile = {'standardLayersTFParams.mat', 'customLayersTFParams.mat',  'customXYTFParams.mat'};  % TF Params test data
    end

    properties (TestParameter)    
        whichParallel = {'single', 'points', 'contrasts'} % How the reflectivity calculation is parallelised
        useCompiled = {false, true}                       % Choose either the MATLAB or MEX version
        validInputCell = {{''},  {'','','','','','',''}}
        invalidInputCell = {{'',''}, {'','',''}, {'','','',''}, {'','','','',''}, {'','','','','',''}, {'','','','','','','',''}}
    end

    properties
        initialTypesTable
        initialAllowedTypes = {'constant'  'data'  'function'};
        initialAllowedActions = {'add'  'subtract'};
        initialTypesCount = 1;
        initialTypesAutoNameCounter = 1;
        initialTypesAutoNameString = [];

        tolerance = 1.0e-12;     % Relative tolerance for equality of floats
        abs_tolerance = 1.0e-5;  % Absolute tolerance for equality of floats
    end

%% Read in test data

    methods (TestClassSetup, ParameterCombination="sequential")

        function initialiseTypesTable(testCase)
            % initialiseTypesTable Set up a types table with a single row
            % of empty strings

            sz = [1 7];
            tableTypes = {'string','string','string','string','string','string','string'};
            tableNames = {'Name','Type','Value 1','Value 2','Value 3','Value 4','Value 5'};

            testCase.initialTypesTable = table('Size',sz,'VariableTypes',tableTypes,'VariableNames',tableNames);
            testCase.initialTypesTable(1,:) = {'','','','','','',''};
        end
        
    end

%% Test Multi Type Table Class Routines
    methods (Test, ParameterCombination="exhaustive")

        function testInitialiseMultiTypeTable(testCase, validInputCell)
            % testInitialiseMultiTypeTable Test the routine to initialise
            % a multi-type table
            % The table can be initialised using a one-element cell array,
            % or a seven element cell array
            testTable = multiTypeTable(validInputCell);

            testCase.verifyEqual(testTable.typesTable, testCase.initialTypesTable);
            testCase.verifyEqual(testTable.allowedTypes, testCase.initialAllowedTypes);
            testCase.verifyEqual(testTable.allowedActions, testCase.initialAllowedActions);
            testCase.verifyEqual(testTable.typesCount, testCase.initialTypesCount, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(testTable.typesAutoNameCounter, testCase.initialTypesAutoNameCounter, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(testTable.typesAutoNameString, testCase.initialTypesAutoNameString);
        end

        function testInitialiseEmptyMultiTypeTable(testCase)
            % testInitialiseMultiTypeTable Test the routine to initialise
            % a multi-type table
            % If we initialise without an input, it should raise an error
            testCase.verifyError(@() multiTypeTable(), 'MATLAB:minrhs');
        end

        function testInitialiseEmptyCellMultiTypeTable(testCase)
            % testInitialiseMultiTypeTable Test the routine to initialise
            % a multi-type table
            % If we initialise with an empty cell array, it should raise
            % an error
            testCase.verifyError(@() multiTypeTable({}), 'MATLAB:table:RowDimensionMismatch');
        end

        function testInitialiseIncompleteMultiTypeTable(testCase, invalidInputCell)
            % testInitialiseMultiTypeTable Test the routine to initialise
            % a multi-type table
            % If we initialise with a cell array containing more than one
            % field (except for seven) it should raise an error
            testCase.verifyError(@() multiTypeTable(invalidInputCell), 'MATLAB:table:VarDimensionMismatch');
        end












    end
end