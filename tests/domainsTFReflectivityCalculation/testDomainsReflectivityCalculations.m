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

%
%% Declare properties and parameters

    properties (ClassSetupParameter)
        inputsFile = {'domainsStandardLayersInputs.mat', 'domainsCustomXYInputs.mat', 'domainsCustomLayersInputs.mat'}      % Input test data
        outputsFile = {'domainsStandardLayersOutputs.mat', 'domainsCustomXYOutputs.mat', 'domainsCustomLayersOutputs.mat'}  % Output test data
        TFFile = {'domainsStandardLayersTFParams.mat', 'domainsCustomXYTFParams.mat', 'domainsCustomLayersTFParams.mat'}   % TF Params test data
    end

    properties (TestParameter)    
        whichParallel = {'single', 'points', 'contrasts'} % How the reflectivity calculation is parallelised
        useCompiled = {false, true}                       % Choose either the MATLAB or MEX version
    end

    properties
        inputs                   % Test input parameters read from file
        outputs                  % Test Output parameters read from file
        TFParams                 % Test TF Parameters read from file
        problemDefInput          % Full set of input parameters
        problemDef               % Input Parameters for the test problem
        problemDefCells          % Input cell arays for the test problem
        problemDefLimits         % Input limits for the test problem
        priors                   % Input priors for the test problem
        controlsInput            % Instrument controls class for the input problem
        controls                 % Instrument controls struct for the input problem
        expectedProblem          % Expected output value of the problem object
        expectedProblemOut       % Expected output value of the output problem object
        expectedProblemOutStruct % Expected output value of the output problem struct
        expectedResult           % Expected output value of the results object
        expectedResultOut        % Expected output value of the output results object
        expectedResultOutStruct  % Expected output value of the output results struct
        expectedBayesResults     % Expected output value of the results object
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
            testCase.problemDef = testCase.inputs.inputs.problemDef;
            testCase.problemDefCells = testCase.inputs.inputs.problemDefCells;
            testCase.problemDefLimits = testCase.inputs.inputs.problemDefLimits;
            testCase.priors = testCase.inputs.inputs.priors;
            testCase.controlsInput = testCase.inputs.inputs.controlsInput;
            testCase.controls = testCase.inputs.inputs.controls;
        end
        
        function loadTestDataOutputs(testCase, outputsFile)
            testCase.outputs = load(outputsFile);

            testCase.expectedProblem = testCase.outputs.outputs.problem;
            testCase.expectedProblemOut = testCase.outputs.outputs.problemOut;
            testCase.expectedProblemOutStruct = testCase.outputs.outputs.problemOutStruct;
            testCase.expectedResult = testCase.outputs.outputs.result;
            testCase.expectedResultOut = testCase.outputs.outputs.resultOut;
            testCase.expectedResultOutStruct = testCase.outputs.outputs.resultOutStruct;
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
            [problem, result] = RAT(testCase.problemDefInput,testCase.controlsInput);

            testCase.verifyEqual(problem, testCase.expectedProblemOut, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(result, testCase.expectedResultOut, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

        function testRATMain(testCase)
            % Test the routine that determines the calculation RAT will perform
            % Note that we test only a single reflectivity calculation at
            % present

            [outProblemDef, problem, result, bayesResults] = RATMain(testCase.problemDef,testCase.problemDefCells,testCase.problemDefLimits,testCase.controls,testCase.priors);

            testCase.verifyEqual(outProblemDef, testCase.expectedProblemOutStruct, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(problem, testCase.expectedProblem, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(result, testCase.expectedResult, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
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
                [problem, result] = reflectivityCalculation_mex(testCase.problemDef, testCase.problemDefCells, testCase.controls);
            else        
                [problem, result] = reflectivityCalculation(testCase.problemDef,testCase.problemDefCells,testCase.controls);
            end
            testCase.verifyEqual(problem, testCase.expectedProblem, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(result, testCase.expectedResult, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

        function testDomainsTFReflectivityCalculation(testCase)
            [problem, reflectivity, simulation, shiftedData, layerSLDs, SLDProfiles, allLayers] = domainsTF.reflectivityCalculation(testCase.problemDef, testCase.problemDefCells, testCase.controls);

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
                    [problem, reflectivity, simulation, shiftedData, layerSLDs, SLDProfiles, allLayers] = domainsTF.standardLayers.calculate(testCase.problemDef, testCase.problemDefCells,  testCase.controls);
                case 'domainsCustomLayersTFParams.mat'
                    [problem, reflectivity, simulation, shiftedData, layerSLDs, SLDProfiles, allLayers] = domainsTF.customLayers.calculate(testCase.problemDef, testCase.problemDefCells,  testCase.controls);
                case 'domainsCustomXYTFParams.mat'
                    [problem, reflectivity, simulation, shiftedData, layerSLDs, SLDProfiles, allLayers] = domainsTF.customXY.calculate(testCase.problemDef, testCase.problemDefCells,  testCase.controls);
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
                    allRoughs] = domainsTF.standardLayers.single(testCase.problemDef,testCase.problemDefCells,...
                    testCase.controls);
                case 'domainsCustomLayersTFParams.mat'
                    [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = domainsTF.customLayers.single(testCase.problemDef,testCase.problemDefCells,...
                    testCase.controls);
                case 'domainsCustomXYTFParams.mat'
                    [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = domainsTF.customXY.single(testCase.problemDef,testCase.problemDefCells,...
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
                    allRoughs] = domainsTF.standardLayers.parallelContrasts(testCase.problemDef,testCase.problemDefCells,...
                    testCase.controls);
                case 'domainsCustomLayersTFParams.mat'
                    [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = domainsTF.customLayers.parallelContrasts(testCase.problemDef,testCase.problemDefCells,...
                    testCase.controls);
                case 'domainsCustomXYTFParams.mat'
                    [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = domainsTF.customXY.parallelContrasts(testCase.problemDef,testCase.problemDefCells,...
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
                    allRoughs] = domainsTF.standardLayers.parallelPoints(testCase.problemDef,testCase.problemDefCells,...
                    testCase.controls);
                case 'domainsCustomLayersTFParams.mat'
                    [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = domainsTF.customLayers.parallelPoints(testCase.problemDef,testCase.problemDefCells,...
                    testCase.controls);
                case 'domainsCustomXYTFParams.mat'
                    [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = domainsTF.customXY.parallelPoints(testCase.problemDef,testCase.problemDefCells,...
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

        function testRatParseClasstoStructs(testCase)
            [problem, problem_cells, problem_limits, problem_priors, controls_struct] = parseClassToStructs(testCase.problemDefInput, testCase.controlsInput);

            testCase.verifyEqual(problem, testCase.problemDef, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(problem_cells, testCase.problemDefCells, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(problem_limits, testCase.problemDefLimits, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(problem_priors, testCase.priors, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(controls_struct, testCase.controls, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

        function testRATParseCells(testCase)
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
            contrastResolutions, backs, shifts, sf, nba, nbs, res, dataPresent, nParams, params,...
            numberOfLayers, resample, backsType, contrastCustomFiles] =  extractProblemParams(testCase.problemDef);

            testCase.verifyEqual(numberOfContrasts, testCase.problemDef.numberOfContrasts, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(geometry, testCase.problemDef.geometry, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastBackgrounds, testCase.problemDef.contrastBackgrounds, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastQzshifts, testCase.problemDef.contrastQzshifts, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastScalefactors, testCase.problemDef.contrastScalefactors, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastBulkIns, testCase.problemDef.contrastBulkIns, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastBulkOuts, testCase.problemDef.contrastBulkOuts, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastResolutions, testCase.problemDef.contrastResolutions, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(backs, testCase.problemDef.backgroundParams, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(shifts, testCase.problemDef.qzshifts, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(sf, testCase.problemDef.scalefactors, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(nba, testCase.problemDef.bulkIn, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(nbs, testCase.problemDef.bulkOut, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(res, testCase.problemDef.resolutionParams, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(dataPresent, testCase.problemDef.dataPresent, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(nParams, length(testCase.problemDef.params), 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(params, testCase.problemDef.params, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(numberOfLayers, testCase.problemDef.numberOfLayers, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resample, testCase.problemDef.resample, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(backsType, testCase.problemDef.contrastBackgroundsType, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastCustomFiles, testCase.problemDef.contrastCustomFiles, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

        function testParseResultToStruct(testCase)
            resultStruct = parseResultToStruct(testCase.expectedProblem, testCase.expectedResult);
            testCase.verifyEqual(resultStruct, testCase.expectedResultOutStruct, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);

            testCase.verifyEqual(resultStruct.reflectivity, testCase.expectedResult{1}, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resultStruct.Simulation, testCase.expectedResult{2}, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resultStruct.shifted_data, testCase.expectedResult{3}, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resultStruct.layerSlds, testCase.expectedResult{4}, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resultStruct.sldProfiles, testCase.expectedResult{5}, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resultStruct.allLayers, testCase.expectedResult{6}, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resultStruct.calculationResults, testCase.expectedProblem.calculations, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

        function testRATParseOutToProjectClass(testCase)
            problemOut = parseOutToProjectClass(testCase.problemDefInput, testCase.expectedProblemOutStruct);
            testCase.verifyEqual(problemOut, testCase.expectedProblemOut, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

    end
end