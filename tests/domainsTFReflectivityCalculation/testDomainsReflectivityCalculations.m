classdef testDomainsReflectivityCalculations < matlab.unittest.TestCase
%%
% testReflectivityCalculations Class based unit tests for RAT API, the
% reflectivity calculation and pre- and post-processing routines.
%
% We are using the test cases for a domains reflectivity calculation
% to test the routines. We consider standard layers, custom layers and
% custom XY examples. For the reflectivity calculation itself, we consider
% the serial and parallel versions (both points and contrasts), using both
% the MATLAB and compiled (MEX) versions.

%% Declare properties and parameters

    properties (ClassSetupParameter)
        inputsFile = {'domainsStandardLayersInputs.mat', 'domainsCustomXYInputs.mat', 'domainsCustomLayersInputs.mat'}
        outputsFile = {'domainsStandardLayersOutputs.mat', 'domainsCustomXYOutputs.mat', 'domainsCustomLayersOutputs.mat'}
        TFFile = {'domainsStandardLayersTFParams.mat', 'domainsCustomXYTFParams.mat', 'domainsCustomLayersTFParams.mat'} % TF Params test data
    end

    properties (TestParameter)    
        whichParallel = {'single', 'points', 'contrasts'} % How the reflectivity calculation is parallelised
        useCompiled = {false, true}                       % Choose either the MATLAB or MEX version
    end

    properties
        inputs                   % Test input parameters read from file
        outputs                  % Test output parameters read from file
        TFParams                 % Test TF Parameters read from file
        problemDefInput          % Input domainsClass object
        problemDefStruct         % Input parameters for the test problem
        problemDefCells          % Input cell arays for the test problem
        problemDefLimits         % Input limits for the test problem
        priors                   % Input priors for the test problem
        controlsInput            % Instrument controls class for the input problem
        controls                 % Instrument controls struct for the input problem
        expectedProblem          % Expected output value of the problem struct
        expectedProblemMain      % Expected output value of the problem struct from RATMain
        expectedProblemDefOutput % Expected output value of the domainsClass object
        expectedProblemDefStruct % Expected output value of the problemDefStruct struct
        expectedResultCells      % Expected output value of the results cell array
        expectedResultCellsMain  % Expected output value of the results cell array from RATMain
        expectedResultStruct     % Expected output value of the initial results struct
        expectedResult           % Expected output value of the final results struct
        expectedBayesResults     % Expected output value of the bayes results struct
        TFReflectivity
        TFSimulation
        TFShiftedData
        TFLayerSLDs
        TFSLDProfiles
        TFAllLayers
        TFOutSsubs
        TFBackgroundParams
        TFQzshifts
        TFScalefactors
        TFBulkIn
        TFBulkOut
        TFResolutionParams
        TFChis
        TFAllRoughs
        tolerance = 1.0e-12     % Relative tolerance for equality of floats
        absTolerance = 1.0e-5   % Absolute tolerance for equality of floats
    end

%% Read in test data

    methods (TestClassSetup, ParameterCombination='sequential')

        function loadTestDataInputs(testCase, inputsFile)
            testCase.inputs = load(inputsFile);

            testCase.problemDefInput = testCase.inputs.inputs.problemDefInput;
            testCase.problemDefStruct = testCase.inputs.inputs.problemDefStruct;
            testCase.problemDefCells = testCase.inputs.inputs.problemDefCells;
            testCase.problemDefLimits = testCase.inputs.inputs.problemDefLimits;
            testCase.priors = testCase.inputs.inputs.priors;
            testCase.controlsInput = testCase.inputs.inputs.controlsInput;
            testCase.controls = testCase.inputs.inputs.controls;
        end
        
        function loadTestDataOutputs(testCase, outputsFile)
            testCase.outputs = load(outputsFile);

            testCase.expectedProblem = testCase.outputs.outputs.problem;
            testCase.expectedProblemMain = testCase.outputs.outputs.problemMain;
            testCase.expectedProblemDefOutput = testCase.outputs.outputs.problemDefOutput;
            testCase.expectedProblemDefStruct = testCase.outputs.outputs.problemDefStruct;
            testCase.expectedResult = testCase.outputs.outputs.result;
            testCase.expectedResultStruct = testCase.outputs.outputs.resultStruct;
            testCase.expectedResultCells = testCase.outputs.outputs.resultCells;
            testCase.expectedResultCellsMain = testCase.outputs.outputs.resultCellsMain;
            testCase.expectedBayesResults = testCase.outputs.outputs.bayesResults;
        end

        function loadTFParams(testCase, TFFile)
            testCase.TFParams = load(TFFile);

            testCase.TFReflectivity = testCase.TFParams.TFParams.reflectivity;
            testCase.TFSimulation = testCase.TFParams.TFParams.simulation;
            testCase.TFShiftedData = testCase.TFParams.TFParams.shiftedData;
            testCase.TFLayerSLDs = testCase.TFParams.TFParams.layerSlds;
            testCase.TFSLDProfiles = testCase.TFParams.TFParams.sldProfiles;
            testCase.TFAllLayers = testCase.TFParams.TFParams.allLayers;

            testCase.TFOutSsubs = testCase.TFParams.TFParams.outSsubs;
            testCase.TFBackgroundParams = testCase.TFParams.TFParams.backgroundParams;
            testCase.TFQzshifts = testCase.TFParams.TFParams.qzshifts;
            testCase.TFScalefactors = testCase.TFParams.TFParams.scalefactors;
            testCase.TFBulkIn = testCase.TFParams.TFParams.bulkIn;
            testCase.TFBulkOut = testCase.TFParams.TFParams.bulkOut;
            testCase.TFResolutionParams = testCase.TFParams.TFParams.resolutionParams;
            testCase.TFChis = testCase.TFParams.TFParams.chis;
            testCase.TFAllRoughs = testCase.TFParams.TFParams.allRoughs;
        end
        
    end

%%
    methods (Test, ParameterCombination='exhaustive')
%% Test High Level RAT Routines

        function testRAT(testCase)
            [problemDefOutput, result] = RAT(testCase.problemDefInput,testCase.controlsInput);

            testCase.verifyEqual(problemDefOutput, testCase.expectedProblemDefOutput, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(result, testCase.expectedResult, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

        function testRATMain(testCase)
            % Test the routine that determines the calculation RAT will perform
            % Note that we test only a single reflectivity calculation at
            % present

            [testProblemDefStruct, problem, resultCells, bayesResults] = RATMain(testCase.problemDefStruct,testCase.problemDefCells,testCase.problemDefLimits,testCase.controls,testCase.priors);

            testCase.verifyEqual(testProblemDefStruct, testCase.expectedProblemDefStruct, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(problem, testCase.expectedProblemMain, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resultCells, testCase.expectedResultCellsMain, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(bayesResults, testCase.expectedBayesResults, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

%% Test Reflectivity Calculation Routines

        function testReflectivityCalculation(testCase, whichParallel, useCompiled)
            % Test the reflectivity calculation.
            % We will test the serial and parallel (over both points and
            % contrasts) versions of the calculation, using both the MATLAB
            % and compiled (MEX) versions of each.
            
            if useCompiled
                % Skip the mex tests if coder is not installed. These tests will be marked as incomplete
                testCase.assumeEqual(license('test', 'MATLAB_Coder'), 1, 'MATLAB Coder is not installed');
            end
            
            testCase.controls.parallel = whichParallel;
            if useCompiled
                [problem, resultCells] = reflectivityCalculation_mex(testCase.problemDefStruct, testCase.problemDefCells, testCase.controls);
            else        
                [problem, resultCells] = reflectivityCalculation(testCase.problemDefStruct, testCase.problemDefCells, testCase.controls);
            end
            testCase.verifyEqual(problem, testCase.expectedProblem, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resultCells, testCase.expectedResultCells, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

        function testDomainsTFReflectivityCalculation(testCase)
            [problem, reflectivity, simulation, shiftedData, layerSLDs, SLDProfiles, allLayers] = domainsTF.reflectivityCalculation(testCase.problemDefStruct, testCase.problemDefCells, testCase.controls);

            testCase.verifyEqual(problem, testCase.expectedProblem, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(reflectivity, testCase.TFReflectivity, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(simulation, testCase.TFSimulation, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(shiftedData, testCase.TFShiftedData, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(layerSLDs, testCase.TFLayerSLDs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(SLDProfiles, testCase.TFSLDProfiles, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(allLayers, testCase.TFAllLayers, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

        function testDomainsTFLayersReflectivityCalculation(testCase, TFFile)
            % Choose the appropriate routine for each test case
            switch TFFile
                case 'domainsStandardLayersTFParams.mat'
                    [problem, reflectivity, simulation, shiftedData, layerSLDs, SLDProfiles, allLayers] = domainsTF.standardLayers.calculate(testCase.problemDefStruct, testCase.problemDefCells,  testCase.controls);
                case 'domainsCustomLayersTFParams.mat'
                    [problem, reflectivity, simulation, shiftedData, layerSLDs, SLDProfiles, allLayers] = domainsTF.customLayers.calculate(testCase.problemDefStruct, testCase.problemDefCells,  testCase.controls);
                case 'domainsCustomXYTFParams.mat'
                    [problem, reflectivity, simulation, shiftedData, layerSLDs, SLDProfiles, allLayers] = domainsTF.customXY.calculate(testCase.problemDefStruct, testCase.problemDefCells,  testCase.controls);
            end

            testCase.verifyEqual(problem, testCase.expectedProblem, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(reflectivity, testCase.TFReflectivity, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(simulation, testCase.TFSimulation, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(shiftedData, testCase.TFShiftedData, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(layerSLDs, testCase.TFLayerSLDs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(SLDProfiles, testCase.TFSLDProfiles, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(allLayers, testCase.TFAllLayers, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

        function testDomainsTFLayersSerialReflectivityCalculation(testCase, TFFile)
            % Choose the appropriate routine for each test case
            switch TFFile
                case 'domainsStandardLayersTFParams.mat'
                    [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = domainsTF.standardLayers.single(testCase.problemDefStruct,testCase.problemDefCells,...
                    testCase.controls);
                case 'domainsCustomLayersTFParams.mat'
                    [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = domainsTF.customLayers.single(testCase.problemDefStruct,testCase.problemDefCells,...
                    testCase.controls);
                case 'domainsCustomXYTFParams.mat'
                    [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = domainsTF.customXY.single(testCase.problemDefStruct,testCase.problemDefCells,...
                    testCase.controls);
            end

            testCase.verifyEqual(outSsubs, testCase.TFOutSsubs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(backgroundParams, testCase.TFBackgroundParams, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(qzshifts, testCase.TFQzshifts, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(scalefactors, testCase.TFScalefactors, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(bulkIn, testCase.TFBulkIn, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(bulkOut, testCase.TFBulkOut, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resolutionParams, testCase.TFResolutionParams, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(chis, testCase.TFChis, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(reflectivity, testCase.TFReflectivity, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(simulation, testCase.TFSimulation, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(shiftedData, testCase.TFShiftedData, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(layerSLDs, testCase.TFLayerSLDs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(SLDProfiles, testCase.TFSLDProfiles, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(allLayers, testCase.TFAllLayers, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(allRoughs, testCase.TFAllRoughs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

        function testDomainsTFLayersParallelContrastsReflectivityCalculation(testCase, TFFile)
            % Choose the appropriate routine for each test case
            switch TFFile
                case 'domainsStandardLayersTFParams.mat'
                    [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = domainsTF.standardLayers.parallelContrasts(testCase.problemDefStruct,testCase.problemDefCells,...
                    testCase.controls);
                case 'domainsCustomLayersTFParams.mat'
                    [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = domainsTF.customLayers.parallelContrasts(testCase.problemDefStruct,testCase.problemDefCells,...
                    testCase.controls);
                case 'domainsCustomXYTFParams.mat'
                    [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = domainsTF.customXY.parallelContrasts(testCase.problemDefStruct,testCase.problemDefCells,...
                    testCase.controls);
            end

            testCase.verifyEqual(outSsubs, testCase.TFOutSsubs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(backgroundParams, testCase.TFBackgroundParams, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(qzshifts, testCase.TFQzshifts, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(scalefactors, testCase.TFScalefactors, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(bulkIn, testCase.TFBulkIn, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(bulkOut, testCase.TFBulkOut, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resolutionParams, testCase.TFResolutionParams, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(chis, testCase.TFChis, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(reflectivity, testCase.TFReflectivity, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(simulation, testCase.TFSimulation, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(shiftedData, testCase.TFShiftedData, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(layerSLDs, testCase.TFLayerSLDs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(SLDProfiles, testCase.TFSLDProfiles, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(allLayers, testCase.TFAllLayers, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(allRoughs, testCase.TFAllRoughs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

        function testDomainsTFLayersParallelPointsReflectivityCalculation(testCase, TFFile)
            % Choose the appropriate routine for each test case
            switch TFFile
                case 'domainsStandardLayersTFParams.mat'
                    [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = domainsTF.standardLayers.parallelPoints(testCase.problemDefStruct,testCase.problemDefCells,...
                    testCase.controls);
                case 'domainsCustomLayersTFParams.mat'
                    [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = domainsTF.customLayers.parallelPoints(testCase.problemDefStruct,testCase.problemDefCells,...
                    testCase.controls);
                case 'domainsCustomXYTFParams.mat'
                    [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = domainsTF.customXY.parallelPoints(testCase.problemDefStruct,testCase.problemDefCells,...
                    testCase.controls);
            end

            testCase.verifyEqual(outSsubs, testCase.TFOutSsubs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(backgroundParams, testCase.TFBackgroundParams, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(qzshifts, testCase.TFQzshifts, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(scalefactors, testCase.TFScalefactors, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(bulkIn, testCase.TFBulkIn, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(bulkOut, testCase.TFBulkOut, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resolutionParams, testCase.TFResolutionParams, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(chis, testCase.TFChis, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(reflectivity, testCase.TFReflectivity, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(simulation, testCase.TFSimulation, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(shiftedData, testCase.TFShiftedData, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(layerSLDs, testCase.TFLayerSLDs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(SLDProfiles, testCase.TFSLDProfiles, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(allLayers, testCase.TFAllLayers, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(allRoughs, testCase.TFAllRoughs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

%% Test Pre- and Post-Processing Routines

        function testParseClasstoStructs(testCase)
            [testProblemDefStruct, testProblemDefCells, testProblemDefLimits, testPriors, testControls] = parseClassToStructs(testCase.problemDefInput, testCase.controlsInput);

            testCase.verifyEqual(testProblemDefStruct, testCase.problemDefStruct, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(testProblemDefCells, testCase.problemDefCells, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(testProblemDefLimits, testCase.problemDefLimits, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(testPriors, testCase.priors, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(testControls, testCase.controls, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

        function testParseCells(testCase)
            [repeatLayers,allData,dataLimits,simLimits,contrastLayers,layersDetails,customFiles] = parseCells(testCase.problemDefCells);

            testCase.verifyEqual(repeatLayers, testCase.problemDefCells{1}, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(allData, testCase.problemDefCells{2}, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(dataLimits, testCase.problemDefCells{3}, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(simLimits, testCase.problemDefCells{4}, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastLayers, testCase.problemDefCells{5}, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(layersDetails, testCase.problemDefCells{6}, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(customFiles, testCase.problemDefCells{14}, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end        

        function testExtractProblemParams(testCase)
            [numberOfContrasts, geometry, contrastBackgrounds, contrastQzshifts, contrastScalefactors, contrastBulkIns, contrastBulkOuts,...
            contrastResolutions, backgroundParams, qzshifts, scalefactors, bulkIn, bulkOut, resolutionParams, dataPresent, nParams, params,...
            numberOfLayers, resample, backgroundParamsType, contrastCustomFiles] =  extractProblemParams(testCase.problemDefStruct);

            testCase.verifyEqual(numberOfContrasts, testCase.problemDefStruct.numberOfContrasts, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(geometry, testCase.problemDefStruct.geometry, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastBackgrounds, testCase.problemDefStruct.contrastBackgrounds, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastQzshifts, testCase.problemDefStruct.contrastQzshifts, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastScalefactors, testCase.problemDefStruct.contrastScalefactors, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastBulkIns, testCase.problemDefStruct.contrastBulkIns, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastBulkOuts, testCase.problemDefStruct.contrastBulkOuts, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastResolutions, testCase.problemDefStruct.contrastResolutions, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(backgroundParams, testCase.problemDefStruct.backgroundParams, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(qzshifts, testCase.problemDefStruct.qzshifts, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(scalefactors, testCase.problemDefStruct.scalefactors, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(bulkIn, testCase.problemDefStruct.bulkIn, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(bulkOut, testCase.problemDefStruct.bulkOut, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resolutionParams, testCase.problemDefStruct.resolutionParams, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(dataPresent, testCase.problemDefStruct.dataPresent, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(nParams, length(testCase.problemDefStruct.params), 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(params, testCase.problemDefStruct.params, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(numberOfLayers, testCase.problemDefStruct.numberOfLayers, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resample, testCase.problemDefStruct.resample, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(backgroundParamsType, testCase.problemDefStruct.contrastBackgroundsType, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastCustomFiles, testCase.problemDefStruct.contrastCustomFiles, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

        function testParseResultToStruct(testCase)
            resultStruct = parseResultToStruct(testCase.expectedProblem, testCase.expectedResultCells);
            testCase.verifyEqual(resultStruct, testCase.expectedResultStruct, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);

            testCase.verifyEqual(resultStruct.reflectivity, testCase.expectedResultCells{1}, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resultStruct.simulation, testCase.expectedResultCells{2}, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resultStruct.shiftedData, testCase.expectedResultCells{3}, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resultStruct.layerSlds, testCase.expectedResultCells{4}, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resultStruct.sldProfiles, testCase.expectedResultCells{5}, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resultStruct.allLayers, testCase.expectedResultCells{6}, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resultStruct.calculationResults, testCase.expectedProblem.calculations, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

        function testParseOutToProjectClass(testCase)
            problemOut = parseOutToProjectClass(testCase.problemDefInput, testCase.expectedProblemDefStruct);
            testCase.verifyEqual(problemOut, testCase.expectedProblemDefOutput, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

    end
end