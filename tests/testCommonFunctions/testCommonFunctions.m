% Test all the common functions in RAT

classdef testCommonFunctions < matlab.unittest.TestCase 
    properties
        chiSquaredInputs;
        chiSquaredOutputs;
        shiftDataInputs;
        shiftDataOutputs;
        callMatlabCustomLayersInputs;
        callMatlabCustomLayersOutputs;

        insertDataBackgroundBackgroundData
        insertDataBackgroundContrastData
        insertDataBackgroundOutputData
        applyBackgroundCorrectionInputs;
        applyBackgroundCorrectionOutputs;
        callReflectivityInputs;
        callReflectivityOutputs;

        allocateLayersForContrastsInputs;
        allocateLayersForContrastsOutputs;
        
        allocateParamsToLayersInputs;
        allocateParamsToLayersOutputs;
        
        groupLayersModInputs;
        groupLayersModOutputs;

        jacobianEstInputs;
        jacobianEstOutputs;

        makeSLDProfileInputs;
        makeSLDProfileOutputs;
        
        abelesParallelPointsInputs;
        abelesParallelPointsOutputs;
        abelesSingleInputs;
        abelesSingleOutputs;
        
        adaptiveInputs;
        adaptiveOutputs;
        resampleLayersInputs;
        resampleLayersOutputs;

        SLDFunctionInputs;
        SLDFunctionOutputs;

        dataResolutionPollyParallelPointsInputs;
        dataResolutionPollyParallelPointsOutputs;
        
        dataResolutionPollyInputs;
        dataResolutionPollyOutputs;
        
        resolutionPollyParallelPointsInputs;
        resolutionPollyParallelPointsOutputs;
        
        resolutionPollyInputs;
        resolutionPollyOutputs;
        
        tolerance = 1.0e-12;     % Relative tolerance for equality of floats
        abs_tolerance = 1.0e-5;  % Absolute tolerance for equality of floats
  
    end

%%

    methods(TestClassSetup)    
        function addDataPath(testCase)
            import matlab.unittest.fixtures.PathFixture
            path = fullfile(getappdata(0, 'root'), 'tests', 'testCommonFunctions');
            testCase.applyFixture(PathFixture(path))  
        end
        
        function loadChiSquared(testCase)
            inputs = load('chiSquaredInputs.mat');
            outputs = load('chiSquaredOutputs.mat');
            testCase.chiSquaredInputs = inputs.inputs;
            testCase.chiSquaredOutputs = outputs.outputs;   
        end
        
        function loadShiftData(testCase)
            inputs = load('shiftDataInputs.mat');
            outputs = load('shiftDataOutputs.mat');
            testCase.shiftDataInputs = inputs.inputs;
            testCase.shiftDataOutputs = outputs.outputs;
        end

        function loadCallMatlabCustomLayers(testCase)
            inputs = load('callMatlabCustomLayersInput.mat');
            outputs = load('callMatlabCustomLayersOutput.mat');
            testCase.callMatlabCustomLayersInputs = inputs.inputs;
            testCase.callMatlabCustomLayersOutputs = outputs.outputs;
        end

        function loadInsertDataBackgroundIntoContrastData(testCase)
            testCase.insertDataBackgroundBackgroundData = load('D2OBackgroundData.mat').d2obackgrounddata;
            testCase.insertDataBackgroundContrastData = load('D2OContrastData.mat').d2ocontrastdata;
            testCase.insertDataBackgroundOutputData = load('D2OOutputData.mat').d2ooutputdata;
        end

        function loadApplyBackgroundCorrection(testCase)
            inputs = load('applyBackgroundCorrectionInputs.mat');
            outputs = load('applyBackgroundCorrectionOutputs.mat');
            % input is a 1 x 1 struct containing 5 arguments.
            % Convert it into cell array so we can pass multiple values
            % instead of one struct into testCase.applyBackgroundCorrection
            s = inputs.ans(1:end);
   
            inputs = {s.reflect,s.Simul,s.shifted_dat,s.backg,s.action};

            s = outputs.applyBackgroundCorrectionOutputs.ans;
            outputs = {s.reflect,s.Simul,s.shifted_dat};

            testCase.applyBackgroundCorrectionInputs = inputs;
            testCase.applyBackgroundCorrectionOutputs = outputs;
        end

        function loadCallReflectivity(testCase)
            inputs = load('callReflectivityInputs.mat');
            outputs = load('callReflectivityOutputs.mat');
            testCase.callReflectivityInputs = inputs.inputs;
            testCase.callReflectivityOutputs = outputs.outputs;
        end

        function loadAllocateLayersForContrasts(testCase)
            inputs = load('allocateLayersForContrastsInputs.mat');
            outputs = load('allocateLayersForContrastsOutputs.mat');
            testCase.allocateLayersForContrastsInputs = inputs.inputs;
            testCase.allocateLayersForContrastsOutputs = outputs.outputs;
        end

        function loadAllocateParamsToLayers(testCase)
            inputs = load('allocateParamsToLayersInputs.mat');
            outputs = load('allocateParamsToLayersOutputs.mat');
            testCase.allocateParamsToLayersInputs = inputs.inputs;
            testCase.allocateParamsToLayersOutputs = outputs.outputs;
            
        end

        function loadGroupLayersMod(testCase)
            inputs = load('groupLayersModInputs.mat');
            outputs = load('groupLayersModOutputs.mat');
            testCase.groupLayersModInputs = inputs.inputs;
            testCase.groupLayersModOutputs = outputs.outputs;
        end

        function loadMakeSLDProfile(testCase)
            inputs = load('makeSLDProfileInputs.mat');
            outputs = load('makeSLDProfileOutputs.mat');
            testCase.makeSLDProfileInputs = inputs.inputs;
            testCase.makeSLDProfileOutputs = outputs.outputs;
        end

        function loadAbelesParallelPoints(testCase)
            inputs = load('abelesParallelPointsInputs.mat');
            outputs = load('abelesParallelPointsOutputs.mat');
            testCase.abelesParallelPointsInputs = inputs.inputs;
            testCase.abelesParallelPointsOutputs = outputs.outputs;
        end

        function loadAbelesSingle(testCase)
            inputs = load('abelesSingleInputs.mat');
            outputs = load('abelesSingleOutputs.mat');
            testCase.abelesSingleInputs = inputs.inputs;
            testCase.abelesSingleOutputs = outputs.outputs;
        end

        function loadAdaptive(testCase)
            inputs = load('adaptiveInputs.mat');
            outputs = load('adaptiveOutputs.mat');
            testCase.adaptiveInputs = inputs.adaptiveInputs;
            testCase.adaptiveOutputs = outputs.adaptiveOutputs; 
        end

        function loadResampleLayers(testCase)
            inputs = load('resampleLayersInputs.mat');
            outputs = load('resampleLayersOutputs.mat');
            testCase.resampleLayersInputs = inputs.inputs;
            testCase.resampleLayersOutputs = outputs.outputs;
        end

        function loadSLDFunction(testCase)
            inputs = load('SLDFunctionInputs.mat');
            outputs = load('SLDFunctionOutputs.mat');
            testCase.SLDFunctionInputs = inputs.inputs;
            testCase.SLDFunctionOutputs = outputs.outputs;
        end

        function loadResolutionPolly(testCase)
            inputs = load('resolutionPollyInputs.mat');
            outputs = load('resolutionPollyOutputs.mat');
            testCase.resolutionPollyInputs = inputs.inputs;
            testCase.resolutionPollyOutputs = outputs.outputs;
        end 
        
    end

%%

    methods(Test)

        function testChiSquared(testCase)
            outputs = chiSquared(testCase.chiSquaredInputs{1:end});
            testCase.verifyEqual(testCase.chiSquaredOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);
        end

        function testShiftData(testCase)
            out1 = shiftData(testCase.shiftDataInputs{:});
            outputs = {out1};
            testCase.verifyEqual(testCase.shiftDataOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);
        end

        function testInsertDataBackgroundIntoContrastData(testCase)         
            contrastData = testCase.insertDataBackgroundContrastData;
            backgroundData = testCase.insertDataBackgroundBackgroundData;

            outputData = insertDataBackgroundIntoContrastData(contrastData, backgroundData);
            testCase.verifyEqual(testCase.insertDataBackgroundOutputData,outputData, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);
        end

        function testApplyBackgroundCorrection(testCase)
            [out1,out2,out3] = applyBackgroundCorrection(testCase.applyBackgroundCorrectionInputs{:});
            outputs = {out1,out2,out3};
            testCase.verifyEqual(testCase.applyBackgroundCorrectionOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);
        end

        function testCallReflectivity(testCase)
            % test is from orsoDSPCStandardLayers
            [out1,out2]= callReflectivity(testCase.callReflectivityInputs{1:end});
            outputs = {out1,out2};
            testCase.verifyEqual(testCase.callReflectivityOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);

        end

        function testAllocateLayersForContrast(testCase)
            % test is from orsoDSPCStandardLayers           
            out1 = allocateLayersForContrast(testCase.allocateLayersForContrastsInputs{1:end});
            outputs= {out1};
            testCase.verifyEqual(testCase.allocateLayersForContrastsOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);
        end

        function testAllocatedParamsToLayers(testCase)
            out1 = allocateParamsToLayers(testCase.allocateParamsToLayersInputs{1:end});
            outputs = {out1};
            testCase.verifyEqual(testCase.allocateParamsToLayersOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);
        end

        function testGroupLayersMod(testCase)
            [out1,out2] = groupLayersMod(testCase.groupLayersModInputs{1:end});
            outputs = {out1,out2};
            testCase.verifyEqual(testCase.groupLayersModOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);
        end
 
%        function testJacobianEstimate(testCase)           
%            firstArg = testCase.jacobianEstimateInputs{1};
%            secondArg = testCase.jacobianEstimateInputs{2};
%             
%            outputs = jacobianEstimate(firstArg,secondArg);
%
%            testCase.verifyEqual(testCase.jacobianEstimateOutputs,outputs);
%        end

        function testMakeSLDProfile(testCase)
            out1 = makeSLDProfile(testCase.makeSLDProfileInputs{1:end});
            outputs = {out1};

            testCase.verifyEqual(testCase.makeSLDProfileOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);
        end

        function testAbelesParallelPoints(testCase)
            out1 = abelesParallelPoints(testCase.abelesParallelPointsInputs{1:end});
            outputs = {out1};

            testCase.verifyEqual(testCase.abelesParallelPointsOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);

        end

        function testAbelesSingle(testCase)
            out1 = abelesSingle(testCase.abelesSingleInputs{1:end});
            outputs = {out1};
            testCase.verifyEqual(testCase.abelesSingleOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);

        end

        function testAdaptive(testCase)
            [out1] = adaptive(testCase.adaptiveInputs{1:end});
            outputs = out1; %INTENTIONAL
            testCase.verifyEqual(testCase.adaptiveOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);
        end

        function testResampleLayers(testCase)
            out1 = resampleLayers(testCase.resampleLayersInputs{1:end});
            testCase.verifyEqual(testCase.resampleLayersOutputs,out1, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);
        end

        function testSLDFunction(testCase)
            out1 = SLDFunction(testCase.SLDFunctionInputs{1:end});
            outputs = {out1};
            testCase.verifyEqual(testCase.SLDFunctionOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);

        end

        function testResolutionPolly(testCase)
            out1 = resolutionPolly(testCase.resolutionPollyInputs{1:end});
            outputs = {out1};
            testCase.verifyEqual(testCase.resolutionPollyOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);

        end        

    end
end
