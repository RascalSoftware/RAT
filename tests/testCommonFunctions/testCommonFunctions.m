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
        
        abelesParaPointsInputs;
        abelesParaPointsOutputs;
        abelesSingleInputs;
        abelesSingleOutputs;
        
        adaptiveInputs;
        adaptiveOutputs;
        resampleLayersInputs;
        resampleLayersOutputs;
        SLDFunctionInputs;
        SLDFunctionOutputs;

        data_resolution_polly_paraPointsInputs;
        data_resolution_polly_paraPointsOutputs;
        
        data_resolution_pollyInputs;
        data_resolution_pollyOutputs;
        
        resolution_polly_paraPointsInputs;
        resolution_polly_paraPointsOutputs;
        
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

        function loadabelesParallelPoints(testCase)
            inputs = load('abelesParallelPointsInputs.mat');
            outputs = load('abelesParallelPointsOutputs.mat');
            testCase.abelesParaPointsInputs = inputs.inputs;
            testCase.abelesParaPointsOutputs = outputs.outputs;
        end

        function loadabelesSingle(testCase)
            inputs = load('abelesSingleInputs.mat');
            outputs = load('abelesSingleOutputs.mat');
            testCase.abelesSingleInputs = inputs.inputs;
            testCase.abelesSingleOutputs = outputs.outputs;
        end

        function loadadaptive(testCase)
            inputs = load('adaptiveInputs.mat');
            outputs = load('adaptiveOutputs.mat');
            testCase.adaptiveInputs = inputs.adaptiveInputs;
            testCase.adaptiveOutputs = outputs.adaptiveOutputs; 
        end

        function loadresampleLayers(testCase)
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
        function loadData_resolution_polly_paraPoints(testCase)
            inputs = load('data_resolution_polly_paraPoints.mat');
            testCase.data_resolution_polly_paraPoints = inputs.data_resolution_polly_paraPoints;
        end

        function loadData_resolution_polly(testCase)
            inputs = load('data_resolution_polly.mat');
            testCase.data_resolution_polly = inputs.data_resolution_polly;
        end
        function loadresolution_polly_paraPoints(testCase) 
            inputs = load('resolution_polly_paraPoints.mat');
            testCase.resolution_polly_paraPoints = inputs.resolution_polly_paraPoints;
        end
%}
        function loadresolution_polly(testCase)
            inputs = load('resolution_pollyInputs.mat');
            outputs = load('resolution_pollyOutputs.mat');
            testCase.resolutionPollyInputs = inputs.inputs;
            testCase.resolutionPollyOutputs = outputs.outputs;
        end 
        
    end

%%

    methods(Test)

        function testChiSquared(testCase)
            % testChiSqaured

            outputs = chiSquared(testCase.chiSquaredInputs{1:end});
            testCase.verifyEqual(testCase.chiSquaredOutputs,outputs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

        function testShiftData(testCase)
            %testShiftData
            out1 = shiftData(testCase.shiftDataInputs{:});
            outputs = {out1};
            testCase.verifyEqual(testCase.shiftDataOutputs,outputs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
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
            testCase.verifyEqual(testCase.callMatlabCustomLayersOutputs, outputs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

        function testApplyBackgroundCorrection(testCase)
            % testApplyBackgroundCorrection

            [out1,out2,out3] = applyBackgroundCorrection(testCase.applyBackgroundCorrectionInputs{:});
            outputs = {out1,out2,out3};
            testCase.verifyEqual(testCase.applyBackgroundCorrectionOutputs,outputs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);

        end

        function testCallReflectivity(testCase)
            % testCallReflectivity from orsoDSPC_stanLay_script
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            
            [out1,out2]= callReflectivity(testCase.callReflectivityInputs{1:end});
            outputs = {out1,out2};
            testCase.verifyEqual(testCase.callReflectivityOutputs,outputs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);

        end

        function testAllocateLayersForContrast(testCase)
            % testAllocateLayersForContrast from orsoDSPC_stanLay_script
            % 
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            
            out1 = allocateLayersForContrast(testCase.allocateLayersForContrastsInputs{1:end});
            outputs= {out1};
            testCase.verifyEqual(testCase.allocateLayersForContrastsOutputs,outputs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
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
            testCase.verifyEqual(testCase.allocateParamsToLayersOutputs,outputs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
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
            testCase.verifyEqual(testCase.groupLayersModOutputs,outputs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end
 
%        function testJacobianEst(testCase)
            % testJacobianEst
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   jacobianEst(testCase)
            
%            firstArg = testCase.jacobianEstInputs{1};
%            secondArg = testCase.jacobianEstInputs{2};
%             
%            outputs = jacobianest(firstArg,secondArg);
%
%            testCase.verifyEqual(testCase.jacobianEstOutputs,outputs);
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
            testCase.verifyEqual(testCase.makeSLDProfilesOutputs,outputs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
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

            testCase.verifyEqual(testCase.makeSLDProfileXYOutputs,outputs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

        function testAbelesParaPoints(testCase)
            % testAbelesParaPoints
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   abelesParallelPoints(testCase)

            out1 = abelesParallelPoints(testCase.abelesParaPointsInputs{1:end});
            outputs = {out1};

            testCase.verifyEqual(testCase.abelesParaPointsOutputs,outputs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);

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
            testCase.verifyEqual(testCase.abelesSingleOutputs,outputs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);

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
            testCase.verifyEqual(testCase.adaptiveOutputs,outputs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
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
            testCase.verifyEqual(testCase.resampleLayersOutputs,out1, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

        function testSLDFunc(testCase)
            % testSLDFunc
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
            testCase.verifyEqual(testCase.SLDFunctionOutputs,outputs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);

        end
%{
        function data_resolution_polly_paraPoints_test(testCase)
            % test data_resolution_polly_paraPoints
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   data_resolution_polly_paraPoints(testCase)
            
            %
            firstArg = testCase.data_resolution_polly_paraPointsInputs{1};
            secondArg = testCase.data_resolution_polly_paraPointsInputs{2};
            thirdArg = testCase.data_resolution_polly_paraPointsInputs{3};
            fourthArg = testCase.data_resolution_polly_paraPointsInputs{4};
            
            outputs = data_resolution_polly_paraPoints(firstArg,secondArg,thirdArg,fourthArg);

            testCase.verifyEqual(testCase.data_resolution_polly_paraPointsOutputs,outputs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);

        end

        function data_resolution_polly_test(testCase)
            % test data_resolution_polly
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   data_resolution_polly(testCase)
            
            %
            firstArg = testCase.data_resolution_pollyInputs{1};
            secondArg = testCase.data_resolution_pollyInputs{2};
            thirdArg = testCase.data_resolution_pollyInputs{3};
            fourthArg = testCase.data_resolution_pollyInputs{4};
            
            outputs = data_resolution_polly(firstArg,secondArg,thirdArg,fourthArg);

            testCase.verifyEqual(testCase.data_resolution_pollyOutputs,outputs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);

        end
    
        function resolution_polly_paraPoints(testCase)
            % test resolution_polly_paraPoints
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none

            outputs = resolution_polly_paraPoints(testCase.resolution_polly_paraPointsInputs{1:end});

            testCase.verifyEqual(testCase.resolution_polly_paraPointsOutputs,outputs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);

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
            %   resolution_polly(testCase)
            
            out1 = resolution_polly(testCase.resolutionPollyInputs{1:end});
            outputs = {out1};
            testCase.verifyEqual(testCase.resolutionPollyOutputs,outputs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);

        end        

    end
end
