classdef testReflectivityCalculations < matlab.unittest.TestCase
%%
% testReflectivityCalculations Class based unit tests for RAT API, the
% reflectivity calculation and pre- and post-processing routines.
%
% We are using the test cases for a normal TF reflectivity
% calculation to test the routines. We consider standard layers, custom
% layers and custom XY examples. For the reflectivity calculation itself,
% we consider the serial and parallel versions (both points and contrasts),
% using both the MATLAB and compiled (MEX) versions.

%% Declare properties and parameters

    properties (ClassSetupParameter)
        inputsFile = {'standardLayersInputs.mat', 'customLayersInputs.mat', 'customXYInputs.mat'}
        outputsFile = {'standardLayersOutputs.mat', 'customLayersOutputs.mat', 'customXYOutputs.mat'}
        TFFile = {'standardLayersTFParams.mat', 'customLayersTFParams.mat',  'customXYTFParams.mat'} % TF Params test data
    end

    properties (TestParameter)    
        parallel = {'single', 'points', 'contrasts'}      % How the reflectivity calculation is parallelised
        useCompiled = {false, true}                       % Choose either the MATLAB or MEX version
    end

    properties
        inputs                     % Test input parameters read from file
        outputs                    % Test output parameters read from file
        TFParams                   % Test TF Parameters read from file
        project                    % Input projectClass object
        problemStruct              % Input parameters for the test problem
        problemLimits              % Input limits for the test problem
        priors                     % Input priors for the test problem
        controlsInput              % Instrument controls class for the input problem
        controls                   % Instrument controls struct for the input problem
        expectedProblemStruct      % Expected output value of the problemStruct struct
        expectedProject            % Expected output value of the projectClass object
        expectedResultStructMain   % Expected output value of the results cell array from RATMain
        expectedResultStruct       % Expected output value of the initial results struct
        expectedResult             % Expected output value of the final results struct
        expectedBayesResults       % Expected output value of the bayes results struct
        TFReflectivity
        TFSimulation
        TFShiftedData
        TFBackgrounds
        TFLayerSLDs
        TFSLDProfiles
        TFResampledLayers
        TFQzshifts
        TFScalefactors
        TFBulkIn
        TFBulkOut
        TFResolutionParams
        TFChis
        TFSubRoughs
        tolerance = 1.0e-12     % Relative tolerance for equality of floats
        absTolerance = 1.0e-5   % Absolute tolerance for equality of floats
    end

%% Read in test data

    methods (TestClassSetup, ParameterCombination='sequential')
        function addDataPath(testCase)
            import matlab.unittest.fixtures.PathFixture
            path = fullfile(getappdata(0, 'root'), 'tests', 'normalTFReflectivityCalculation');
            testCase.applyFixture(PathFixture(path))  
        end

        function loadTestDataInputs(testCase, inputsFile)
            testCase.inputs = load(inputsFile);

            testCase.project = testCase.inputs.inputs.project;
            testCase.problemStruct = testCase.inputs.inputs.problemStruct;
            testCase.problemLimits = testCase.inputs.inputs.problemLimits;
            testCase.priors = testCase.inputs.inputs.priors;
            testCase.controlsInput = testCase.inputs.inputs.controlsInput;
            testCase.controls = testCase.inputs.inputs.controls;
        end
        
        function loadTestDataOutputs(testCase, outputsFile)
            testCase.outputs = load(outputsFile);

            testCase.expectedProject = testCase.outputs.outputs.project;
            testCase.expectedProblemStruct = testCase.outputs.outputs.problemStruct;
            testCase.expectedResult = testCase.outputs.outputs.result;
            testCase.expectedResultStruct = testCase.outputs.outputs.resultStruct;
            testCase.expectedResultStructMain = testCase.outputs.outputs.resultStructMain;
            testCase.expectedBayesResults = testCase.outputs.outputs.bayesResults;
        end

        function loadTFParams(testCase, TFFile)
            testCase.TFParams = load(TFFile);

            testCase.TFReflectivity = testCase.TFParams.TFParams.reflectivity;
            testCase.TFSimulation = testCase.TFParams.TFParams.simulation;
            testCase.TFShiftedData = testCase.TFParams.TFParams.shiftedData;
            testCase.TFBackgrounds = testCase.TFParams.TFParams.backgrounds;
            testCase.TFLayerSLDs = testCase.TFParams.TFParams.layerSlds;
            testCase.TFSLDProfiles = testCase.TFParams.TFParams.sldProfiles;
            testCase.TFResampledLayers = testCase.TFParams.TFParams.resampledLayers;

            testCase.TFQzshifts = testCase.TFParams.TFParams.qzshifts;
            testCase.TFScalefactors = testCase.TFParams.TFParams.scalefactors;
            testCase.TFBulkIn = testCase.TFParams.TFParams.bulkIn;
            testCase.TFBulkOut = testCase.TFParams.TFParams.bulkOut;
            testCase.TFResolutionParams = testCase.TFParams.TFParams.resolutionParams;
            testCase.TFChis = testCase.TFParams.TFParams.chis;
            testCase.TFSubRoughs = testCase.TFParams.TFParams.subRoughs;
        end
        
    end

%%
    methods (Test, ParameterCombination='exhaustive')
%% Test High Level RAT Routines

        function testRATEmpty(testCase)
            % Test that RAT runs for a project without any layers.
            emptyProject = projectClass();
            emptyProject.addContrast('data', 'Simulation',...
                                     'background', 'Background 1',...
                                     'bulkIn', 'SLD Air',...
                                     'bulkOut', 'SLD D2O',...
                                     'scalefactor', 'Scalefactor 1',...
                                     'resolution', 'Resolution 1');

            [~, ~] = RAT(emptyProject,testCase.controlsInput);
        end

        function testRAT(testCase)
            [projectOutput, result] = RAT(testCase.project,testCase.controlsInput);

            testCase.verifyEqual(projectOutput, testCase.expectedProject, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(result, testCase.expectedResult, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

        function testRATMain(testCase)
            % Test the routine that determines the calculation RAT will perform
            % Note that we test only a single reflectivity calculation at
            % present

            [testProblemStruct, result, bayesResults] = RATMain(testCase.problemStruct,testCase.problemLimits,testCase.controls,testCase.priors);

            testCase.verifyEqual(testProblemStruct, testCase.expectedProblemStruct, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(result, testCase.expectedResultStructMain, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(bayesResults, testCase.expectedBayesResults, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

%% Test Reflectivity Calculation Routines

        function testReflectivityCalculation(testCase, parallel, useCompiled)
            % Test the reflectivity calculation.
            % We will test the serial and parallel (over both points and
            % contrasts) versions of the calculation, using both the MATLAB
            % and compiled (MEX) versions of each.
            
            if useCompiled
                % Skip the mex tests if coder is not installed. These tests will be marked as incomplete
                testCase.assumeEqual(license('test', 'MATLAB_Coder'), 1, 'MATLAB Coder is not installed');
            end
            
            testCase.controls.parallel = parallel;
            if useCompiled
                result = reflectivityCalculation_mex(testCase.problemStruct, testCase.controls);
            else        
                result = reflectivityCalculation(testCase.problemStruct, testCase.controls);
            end

            testCase.verifyEqual(result, testCase.expectedResultStruct, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

        function testNormalTFReflectivityCalculation(testCase, parallel, TFFile)

            testCase.controls.parallel = parallel;
            % Choose the appropriate routine for each test case
            switch TFFile
                case 'standardLayersTFParams.mat'
                    [qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,chis,reflectivity,...
                    simulation,shiftedData,backgrounds,layerSLDs,SLDProfiles,resampledLayers,...
                    subRoughs] = normalTF.standardLayers(testCase.problemStruct,testCase.controls);
                case 'customLayersTFParams.mat'
                    [qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,chis,reflectivity,...
                    simulation,shiftedData,backgrounds,layerSLDs,SLDProfiles,resampledLayers,...
                    subRoughs] = normalTF.customLayers(testCase.problemStruct,testCase.controls);
                case 'customXYTFParams.mat'
                    [qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,chis,reflectivity,...
                    simulation,shiftedData,backgrounds,layerSLDs,SLDProfiles,resampledLayers,...
                    subRoughs] = normalTF.customXY(testCase.problemStruct,testCase.controls);
            end

            testCase.verifyEqual(qzshifts, testCase.TFQzshifts, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(scalefactors, testCase.TFScalefactors, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(bulkIn, testCase.TFBulkIn, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(bulkOut, testCase.TFBulkOut, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resolutionParams, testCase.TFResolutionParams, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(chis, testCase.TFChis, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(reflectivity, testCase.TFReflectivity, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(simulation, testCase.TFSimulation, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(shiftedData, testCase.TFShiftedData, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(backgrounds, testCase.TFBackgrounds, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(layerSLDs, testCase.TFLayerSLDs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(SLDProfiles, testCase.TFSLDProfiles, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resampledLayers, testCase.TFResampledLayers, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(subRoughs, testCase.TFSubRoughs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

%% Test Pre- and Post-Processing Routines

        function testParseClasstoStructs(testCase)
            [testProblemStruct, testProblemLimits, testPriors, testControls] = parseClassToStructs(testCase.project, testCase.controlsInput);

            testCase.verifyEqual(testProblemStruct, testCase.problemStruct, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(testProblemLimits, testCase.problemLimits, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(testPriors, testCase.priors, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(testControls, testCase.controls, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

        function testCheckIndices(testCase)
            
            % Test standard input passes
            testInput = testCase.problemStruct;
            customFiles = testCase.problemStruct.customFiles;
            checkIndices(testInput, customFiles);

            % Test Background Param Error
            testInput = testCase.problemStruct;
            testInput.contrastBackgroundParams{1} = 0;
            testCase.verifyError(@() checkIndices(testInput, customFiles), exceptions.indexOutOfRange.errorID);
            testInput = testCase.problemStruct;
            testInput.contrastBackgroundParams{1} = 4;
            testCase.verifyError(@() checkIndices(testInput, customFiles), exceptions.indexOutOfRange.errorID);

            testInput.contrastBackgroundParams{1} = [0 1 2 3];
            testCase.verifyError(@() checkIndices(testInput, customFiles), exceptions.indexOutOfRange.errorID);
            testInput = testCase.problemStruct;
            testInput.contrastBackgroundParams{1} = [4 1 2 3];
            testCase.verifyError(@() checkIndices(testInput, customFiles), exceptions.indexOutOfRange.errorID);

            % Test Qzshift Error
            testInput = testCase.problemStruct;
            testInput.contrastQzshifts(1) = 0;
            testCase.verifyError(@() checkIndices(testInput, customFiles), exceptions.indexOutOfRange.errorID);
            testInput = testCase.problemStruct;
            testInput.contrastQzshifts(1) = 4;
            testCase.verifyError(@() checkIndices(testInput, customFiles), exceptions.indexOutOfRange.errorID);

            % Test Scalefactor Error
            testInput = testCase.problemStruct;
            testInput.contrastScalefactors(1) = 0;
            testCase.verifyError(@() checkIndices(testInput, customFiles), exceptions.indexOutOfRange.errorID);
            testInput = testCase.problemStruct;
            testInput.contrastScalefactors(1) = 4;
            testCase.verifyError(@() checkIndices(testInput, customFiles), exceptions.indexOutOfRange.errorID);

            % Test Bulk In Error
            testInput = testCase.problemStruct;
            testInput.contrastBulkIns(1) = 0;
            testCase.verifyError(@() checkIndices(testInput, customFiles), exceptions.indexOutOfRange.errorID);
            testInput = testCase.problemStruct;
            testInput.contrastBulkIns(1) = 4;
            testCase.verifyError(@() checkIndices(testInput, customFiles), exceptions.indexOutOfRange.errorID);

            % Test Bulk Out Error
            testInput = testCase.problemStruct;
            testInput.contrastBulkOuts(1) = 0;
            testCase.verifyError(@() checkIndices(testInput, customFiles), exceptions.indexOutOfRange.errorID);
            testInput = testCase.problemStruct;
            testInput.contrastBulkOuts(1) = 4;
            testCase.verifyError(@() checkIndices(testInput, customFiles), exceptions.indexOutOfRange.errorID);

            % Test Resolution Param Error
            testInput = testCase.problemStruct;
            testInput.contrastResolutionParams(1) = 0;
            testCase.verifyError(@() checkIndices(testInput, customFiles), exceptions.indexOutOfRange.errorID);
            testInput = testCase.problemStruct;
            testInput.contrastResolutionParams(1) = 4;
            testCase.verifyError(@() checkIndices(testInput, customFiles), exceptions.indexOutOfRange.errorID);

            % Test Domain Ratio Error
            testInput = testCase.problemStruct;
            testInput.contrastDomainRatios(1) = 0;
            testCase.verifyError(@() checkIndices(testInput, customFiles), exceptions.indexOutOfRange.errorID);
            testInput = testCase.problemStruct;
            testInput.contrastDomainRatios(1) = 4;
            testCase.verifyError(@() checkIndices(testInput, customFiles), exceptions.indexOutOfRange.errorID);

        end      

        function testExtractProblemParams(testCase)
            [numberOfContrasts, geometry, contrastBackgroundParams, contrastQzshifts, contrastScalefactors, contrastBulkIns, contrastBulkOuts,...
            contrastResolutionParams, contrastDomainRatios, backgroundParams, qzshifts, scalefactors, bulkIns, bulkOuts, resolutionParams, domainRatios,...
            dataPresent, nParams, params, numberOfLayers, resample, backgroundTypes, backgroundActions, resolutionTypes, contrastCustomFiles, useImaginary,...
            repeatLayers, data, dataLimits, simLimits, contrastLayers, layersDetails, customFiles, domainContrastLayers] = extractProblemParams(testCase.problemStruct);

            testCase.verifyEqual(numberOfContrasts, testCase.problemStruct.numberOfContrasts, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(geometry, testCase.problemStruct.geometry, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastBackgroundParams, testCase.problemStruct.contrastBackgroundParams, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastQzshifts, testCase.problemStruct.contrastQzshifts, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastScalefactors, testCase.problemStruct.contrastScalefactors, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastBulkIns, testCase.problemStruct.contrastBulkIns, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastBulkOuts, testCase.problemStruct.contrastBulkOuts, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastResolutionParams, testCase.problemStruct.contrastResolutionParams, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastDomainRatios, testCase.problemStruct.contrastDomainRatios, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(backgroundParams, testCase.problemStruct.backgroundParams, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(qzshifts, testCase.problemStruct.qzshifts, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(scalefactors, testCase.problemStruct.scalefactors, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(bulkIns, testCase.problemStruct.bulkIns, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(bulkOuts, testCase.problemStruct.bulkOuts, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resolutionParams, testCase.problemStruct.resolutionParams, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(domainRatios, testCase.problemStruct.domainRatios, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(dataPresent, testCase.problemStruct.dataPresent, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(nParams, length(testCase.problemStruct.params), 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(params, testCase.problemStruct.params, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(numberOfLayers, testCase.problemStruct.numberOfLayers, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resample, testCase.problemStruct.resample, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(backgroundTypes, testCase.problemStruct.contrastBackgroundTypes, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(backgroundActions, testCase.problemStruct.contrastBackgroundActions, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(resolutionTypes, testCase.problemStruct.contrastResolutionTypes, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastCustomFiles, testCase.problemStruct.contrastCustomFiles, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(useImaginary, testCase.problemStruct.useImaginary, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(repeatLayers, testCase.problemStruct.repeatLayers, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(data, testCase.problemStruct.data, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(dataLimits, testCase.problemStruct.dataLimits, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(simLimits, testCase.problemStruct.simulationLimits, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(contrastLayers, testCase.problemStruct.contrastLayers, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(layersDetails, testCase.problemStruct.layersDetails, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(customFiles, testCase.problemStruct.customFiles, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
            testCase.verifyEqual(domainContrastLayers, testCase.problemStruct.domainContrastLayers, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

        function testParseOutToProjectClass(testCase)
            problemOut = parseOutToProjectClass(testCase.project, testCase.expectedProblemStruct);
            testCase.verifyEqual(problemOut, testCase.expectedProject, 'RelTol', testCase.tolerance, 'AbsTol', testCase.absTolerance);
        end

    end
end