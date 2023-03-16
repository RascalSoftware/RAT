% Test all the common functions in RAT

% Paul Sharp 20/01/23 - Fixed and restored some commented out tests.

classdef testCommonFunctions < matlab.unittest.TestCase 
    properties
        backSortInputs;
        backSortOutputs;
        chiSquaredInputs;
        chiSquaredOutputs;
        shiftDataInputs;
        shiftDataOutputs;
        callMatlabCustomLayersInputs;
        callMatlabCustomLayersOutputs;

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

        makeSLDProfilesInputs;
        makeSLDProfilesOutputs;
        
        makeSLDProfileXYInputs;
        makeSLDProfileXYOutputs;
        
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
        
        function loadBackSort(testCase)
            inputs = load('backSortInputs.mat');
            outputs = load('backSortOutputs.mat');
            testCase.backSortInputs = inputs.inputs; % cell array
            testCase.backSortOutputs = outputs.outputs; % field 
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

        function loadApplyBackgroundCorrection(testCase)
            inputs = load('applyBackgroundCorrectionInputs.mat');
            outputs = load('applyBackgroundCorrectionOutputs.mat');
            % input is a 1 x 1 struct containing 5 arguments. Convert it into cell array so
            % we can pass multiple values instead of one struct into testCase.applyB
            s = inputs.ans(1:end);
   
            inputs = {s.reflect,s.Simul,s.shifted_dat,s.backg,s.backsType};

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

        function loadMakeSLDProfiles(testCase)
            inputs = load('makeSLDProfilesInputs.mat');
            outputs = load('makeSLDProfilesOutputs.mat');
            testCase.makeSLDProfilesInputs = inputs.inputs;
            testCase.makeSLDProfilesOutputs = outputs.outputs;
        end

        function loadMakeSLDProfileXY(testCase)
            inputs = load('makeSLDProfileXYInputs.mat');
            outputs = load('makeSLDProfileXYOutputs.mat');
            testCase.makeSLDProfileXYInputs = inputs.inputs;
            testCase.makeSLDProfileXYOutputs = outputs.outputs;
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
%{
        function loadData_resolutionPollyParallelPoints(testCase)
            inputs = load('dataResolutionPollyParallelPoints.mat');
            testCase.dataResolutionPollyParallelPoints = inputs.dataResolutionPollyParallelPoints;
        end

        function loadData_resolutionPolly(testCase)
            inputs = load('dataResolutionPolly.mat');
            testCase.dataResolutionPolly = inputs.dataResolutionPolly;
        end
        function loadresolutionPollyParallelPoints(testCase) 
            inputs = load('resolutionPollyParallelPoints.mat');
            testCase.resolutionPollyParallelPoints = inputs.resolutionPollyParallelPoints;
        end
%}
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
            % testChiSqaured

            outputs = chiSquared(testCase.chiSquaredInputs{1:end});
            testCase.verifyEqual(testCase.chiSquaredOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);
        end

        function testShiftData(testCase)
            %testShiftData
            out1 = shiftData(testCase.shiftDataInputs{:});
            outputs = {out1};
            testCase.verifyEqual(testCase.shiftDataOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);
        end

        function testCallMatlabCustomLayers(testCase)
            % testCallMatlabCustomLayers
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none

            [output1, output2] = callMatlabCustomLayers(testCase.callMatlabCustomLayersInputs{:});
            outputs = {output1, output2};
            testCase.verifyEqual(testCase.callMatlabCustomLayersOutputs, outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);
        end

        function testApplyBackgroundCorrection(testCase)
            % testApplyBackgroundCorrection

            [out1,out2,out3] = applyBackgroundCorrection(testCase.applyBackgroundCorrectionInputs{:});
            outputs = {out1,out2,out3};
            testCase.verifyEqual(testCase.applyBackgroundCorrectionOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);

        end

        function testCallReflectivity(testCase)
            % testCallReflectivity from orsoDSPCStandardLayers
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            
            [out1,out2]= callReflectivity(testCase.callReflectivityInputs{1:end});
            outputs = {out1,out2};
            testCase.verifyEqual(testCase.callReflectivityOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);

        end

        function testAllocateLayersForContrast(testCase)
            % testAllocateLayersForContrast from orsoDSPCStandardLayers
            % 
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            
            out1 = allocateLayersForContrast(testCase.allocateLayersForContrastsInputs{1:end});
            outputs= {out1};
            testCase.verifyEqual(testCase.allocateLayersForContrastsOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);
        end

        function testAllocatedParamsToLayers(testCase)
            % testAllocatedParamsToLayers
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            
            out1 = allocateParamsToLayers(testCase.allocateParamsToLayersInputs{1:end});
            outputs = {out1};
            testCase.verifyEqual(testCase.allocateParamsToLayersOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);
        end

        function testGroupLayersMod(testCase)
            % testGroupLayersMod
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   groupLayersMod(testCase)
           
            [out1,out2] = groupLayersMod(testCase.groupLayersModInputs{1:end});
            outputs = {out1,out2};
            testCase.verifyEqual(testCase.groupLayersModOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);
        end
 
%        function testJacobianEstimate(testCase)
            % testJacobianEstimate
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   jacobianEstimate(testCase)
            
%            firstArg = testCase.jacobianEstimateInputs{1};
%            secondArg = testCase.jacobianEstimateInputs{2};
%             
%            outputs = jacobianEstimate(firstArg,secondArg);
%
%            testCase.verifyEqual(testCase.jacobianEstimateOutputs,outputs);
%        end

        function testMakeSLDProfiles(testCase)
            % testMakeSLDProfiles
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   makeSLDProfiles(testCase)
            
            
            out1 = makeSLDProfiles(testCase.makeSLDProfilesInputs{1:end});
            outputs = {out1};
            testCase.verifyEqual(testCase.makeSLDProfilesOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);
        end

        function testMakeSLDProfileXY(testCase)
            % testMakeSLDProfileXY
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   makeSLDProfileXY(testCase)

            out1 = makeSLDProfileXY(testCase.makeSLDProfileXYInputs{1:end});
            outputs = {out1};

            testCase.verifyEqual(testCase.makeSLDProfileXYOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);
        end

        function testAbelesParallelPoints(testCase)
            % testAbelesParallelPoints
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   abelesParallelPoints(testCase)

            out1 = abelesParallelPoints(testCase.abelesParallelPointsInputs{1:end});
            outputs = {out1};

            testCase.verifyEqual(testCase.abelesParallelPointsOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);

        end

        function testAbelesSingle(testCase)
            % testAbelesSingle
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   abelesSingle(testCase)
            
            out1 = abelesSingle(testCase.abelesSingleInputs{1:end});
            outputs = {out1};
            testCase.verifyEqual(testCase.abelesSingleOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);

        end

        function testAdaptive(testCase)
            % testAdaptive
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   adaptive(testCase)
 
            [out1] = adaptive(testCase.adaptiveInputs{1:end});
            outputs = out1; %INTENTIONAL
            testCase.verifyEqual(testCase.adaptiveOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);
        end

        function testResampleLayers(testCase)
            % testResampleLayers
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   resampleLayers(testCase)

            out1 = resampleLayers(testCase.resampleLayersInputs{1:end});
            testCase.verifyEqual(testCase.resampleLayersOutputs,out1, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);
        end

        function testSLDFunction(testCase)
            % testSLDFunction
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   SLDFunction(testCase)
            
            out1 = SLDFunction(testCase.SLDFunctionInputs{1:end});
            outputs = {out1};
            testCase.verifyEqual(testCase.SLDFunctionOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);

        end
%{
        function testDataResolutionPollyParallelPoints(testCase)
            % test tetsDataResolutionPollyParallelPoints
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   dataResolutionPollyParallelPoints(testCase)
            
            %
            firstArg = testCase.dataResolutionPollyParallelPointsInputs{1};
            secondArg = testCase.dataResolutionPollyParallelPointsInputs{2};
            thirdArg = testCase.dataResolutionPollyParallelPointsInputs{3};
            fourthArg = testCase.dataResolutionPollyParallelPointsInputs{4};
            
            outputs = dataResolutionPollyParallelPoints(firstArg,secondArg,thirdArg,fourthArg);

            testCase.verifyEqual(testCase.dataResolutionPollyParallelPointsOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);

        end

%         function testDataResolutionPollyparallel(testCase)
            % test dataResolutionPolly
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   dataResolutionPolly(testCase)
            
            %
            firstArg = testCase.dataResolutionPollyInputs{1};
            secondArg = testCase.dataResolutionPollyInputs{2};
            thirdArg = testCase.dataResolutionPollyInputs{3};
            fourthArg = testCase.dataResolutionPollyInputs{4};
            
            outputs = dataResolutionPolly(firstArg,secondArg,thirdArg,fourthArg);

            testCase.verifyEqual(testCase.dataResolutionPollyOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);

        end
    
        function resolutionPollyParallelPoints(testCase)
            % test resolutionPollyParallelPoints
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none

            outputs = resolutionPollyParallelPoints(testCase.resolutionPollyParallelPointsInputs{1:end});

            testCase.verifyEqual(testCase.resolutionPollyParallelPointsOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);

        end
 %}    

        function testResolutionPolly(testCase)
            % testResolutionPolly
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   resolutionPolly(testCase)
            
            out1 = resolutionPolly(testCase.resolutionPollyInputs{1:end});
            outputs = {out1};
            testCase.verifyEqual(testCase.resolutionPollyOutputs,outputs, 'RelTol', testCase.tolerance, 'AbsTol', testCase.abs_tolerance);

        end        

    end
end
