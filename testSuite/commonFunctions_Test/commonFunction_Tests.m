% Test all the common functions in RAT

% declare a class and inherit from matlab.unit.TestCase

classdef commonFunction_Tests < matlab.unittest.TestCase 
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
        
        groupLayers_ModInputs;
        groupLayers_ModOutputs;
    
        jacobianEstInputs;
        jacobianEstOutputs;

        makeSLDProfilesInputs;
        makeSLDProfilesOutputs;
        
        makeSLDProfileXYInputs;
        makeSLDProfileXYOutputs;
        
        abeles_paraPointsInputs;
        abeles_paraPointsOutputs;
        abeles_singleInputs;
        abeles_singleOutputs;
        
        adaptiveInputs;
        adaptiveOutputs;
        resampleLayersInputs;
        resampleLayersOutputs;
        sldFuncInputs;
        sldFuncOutputs;

        data_resolution_polly_paraPointsInputs;
        data_resolution_polly_paraPointsOutputs;
        
        data_resolution_pollyInputs;
        data_resolution_pollyOutputs;
        
        resolution_polly_paraPointsInputs;
        resolution_polly_paraPointsOutputs;
        
        resolution_pollyInputs;
        resolution_pollyOutputs;
        
        tolerance = 1e-12;
  
    end

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
        
        function loadshiftData(testCase)
            inputs = load('shiftDataInputs.mat');
            outputs = load('shiftDataOutputs.mat');
            testCase.shiftDataInputs = inputs.inputs;
            testCase.shiftDataOutputs = outputs.outputs;
        end

        function loadcallMatlabCustomLayers(testCase)
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

        function loadcallReflectivity(testCase)
            inputs = load('callReflectivityInputs.mat');
            outputs = load('callReflectivityOutputs.mat');

            testCase.callReflectivityInputs = inputs.inputs;
            testCase.callReflectivityOutputs = outputs.outputs;
        end

        function loadallocateLayersForContrasts(testCase)
            inputs = load('allocateLayersForContrastsInputs.mat');
            outputs = load('allocateLayersForContrastsOutputs.mat');

            testCase.allocateLayersForContrastsInputs = inputs.inputs;
            testCase.allocateLayersForContrastsOutputs = outputs.outputs;
        end

        function loadallocateParamsToLayers(testCase)
            inputs = load('allocateParamsToLayersInputs.mat');
            outputs = load('allocateParamsToLayersOutputs.mat');
            
            testCase.allocateParamsToLayersInputs = inputs.inputs;
            testCase.allocateParamsToLayersOutputs = outputs.outputs;
            
        end

        function loadgroupLayers_Mod(testCase)
            inputs = load('groupLayers_ModInputs.mat');
            outputs = load('groupLayers_ModOutputs.mat');
            
            testCase.groupLayers_ModInputs = inputs.inputs;
            testCase.groupLayers_ModOutputs = outputs.outputs;
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

        function loadabeles_paraPoints(testCase)
            inputs = load('abeles_paraPointsInputs.mat');
            outputs = load('abeles_paraPointsOutputs.mat');
            
            testCase.abeles_paraPointsInputs = inputs.inputs;
            testCase.abeles_paraPointsOutputs = outputs.outputs;
        end

        function loadabeles_single(testCase)
            inputs = load('abeles_singleInputs.mat');
            outputs = load('abeles_singleOutputs.mat');
            
            testCase.abeles_singleInputs = inputs.inputs;
            testCase.abeles_singleOutputs = outputs.outputs;
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

        function loadsldFunc(testCase)
            inputs = load('sldFuncInputs.mat');
            outputs = load('sldFuncOutputs.mat');
            
            testCase.sldFuncInputs = inputs.inputs;
            testCase.sldFuncOutputs = outputs.outputs;
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
%         function loadresolution_polly(testCase)
%             inputs = load('resolution_pollyInputs.mat');
%             outputs = load('resolution_pollyOutputs.mat');
%             testCase.resolution_pollyInputs = inputs.inputs;
%             testCase.resolution_pollyOutputs = outputs.outputs;
%         end 
       

        
    end 
    methods(Test)

        function chiSquared(testCase)
            % test chiSqaured

            outputs = chiSquared(testCase.chiSquaredInputs{1:end});
            testCase.verifyEqual(testCase.chiSquaredOutputs,outputs);
        end

        function shiftData_test(testCase)
            %test shiftData
            out1 = shiftdata(testCase.shiftDataInputs{:});
            outputs = {out1};
            testCase.verifyEqual(testCase.shiftDataOutputs,outputs);
        end

        function callMatlabCustomLayers_test(testCase)
            % test callMatlabCustomLayers
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none

            [output1, output2] = callMatlabCustomLayers(testCase.callMatlabCustomLayersInputs{:});
            outputs = {output1, output2};
            testCase.verifyEqual(testCase.callMatlabCustomLayersOutputs, outputs);
        end

        function applyBackgroundCorrection_test(testCase)
            % test applyBackgroundCorrection

            [out1,out2,out3] = applyBackgroundCorrection(testCase.applyBackgroundCorrectionInputs{:});
            outputs = {out1,out2,out3};
            testCase.verifyEqual(testCase.applyBackgroundCorrectionOutputs,outputs);

        end

        function callReflectivity_test(testCase)
            % test callReflectivity from orsoDSPC_stanLay_script
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            
            [out1,out2]= callReflectivity(testCase.callReflectivityInputs{1:end});
            outputs = {out1,out2};
            testCase.verifyEqual(testCase.callReflectivityOutputs,outputs,"RelTol",testCase.tolerance);

        end

        

        function allocateLayersForContrast_test(testCase)
            % test allocateLayersForContrast from orsoDSPC_stanLay_script
            % 
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            
            out1 = allocateLayersForContrast(testCase.allocateLayersForContrastsInputs{1:end});
            outputs= {out1};
            testCase.verifyEqual(testCase.allocateLayersForContrastsOutputs,outputs);
        end

        function allocatedParamsToLayers_test(testCase)
            % test allocatedParamsToLayers
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            
            out1 = allocateParamsToLayers(testCase.allocateParamsToLayersInputs{1:end});
            outputs = {out1};
            testCase.verifyEqual(testCase.allocateParamsToLayersOutputs,outputs);
        end

        function groupLayers_Mod_test(testCase)
            % test groupLayers_Mod
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   groupLayers_Mod(testCase)
            
            %
           
            [out1,out2] = groupLayers_Mod(testCase.groupLayers_ModInputs{1:end});
            outputs = {out1,out2};
            testCase.verifyEqual(testCase.groupLayers_ModOutputs,outputs);
        end
 
%        function jacobianEst_test(testCase)
            % test jacobianEst
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

        function makeSLDProfiles_test(testCase)
            % test makeSLDProfiles
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
            testCase.verifyEqual(testCase.makeSLDProfilesOutputs,outputs);
        end

        function makeSLDProfileXY_test(testCase)
            % test makeSLDProfileXY
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

            testCase.verifyEqual(testCase.makeSLDProfileXYOutputs,outputs);
        end

        function abeles_paraPoints_test(testCase)
            % test abeles_paraPoints
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   abeles_paraPoints(testCase)

            out1 = abeles_paraPoints(testCase.abeles_paraPointsInputs{1:end});
            outputs = {out1};

            testCase.verifyEqual(testCase.abeles_paraPointsOutputs,outputs,"RelTol",testCase.tolerance);

        end

        function abeles_single_test(testCase)
            % test abeles_single
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   abeles_single(testCase)
            
            out1 = abeles_single(testCase.abeles_singleInputs{1:end});
            outputs = {out1};
            testCase.verifyEqual(testCase.abeles_singleOutputs,outputs,"RelTol",testCase.tolerance);

        end

        function adaptive_test(testCase)
            % test adaptive
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   adaptive(testCase)
            
            %

 
            [out1] = adaptive_new(testCase.adaptiveInputs{1:end});
            outputs = out1; %INTENTIONAL

            testCase.verifyEqual(testCase.adaptiveOutputs,outputs);

        end

        function resampleLayers_test(testCase)
            % test resampleLayers
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
            

            testCase.verifyEqual(testCase.resampleLayersOutputs,out1);
        end

        function sldFunc_test(testCase)
            % test sldFunc
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   sldFunc(testCase)
            
            out1 = sldFunc(testCase.sldFuncInputs{1:end});
            outputs = {out1};
            testCase.verifyEqual(testCase.sldFuncOutputs,outputs);

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

            testCase.verifyEqual(testCase.data_resolution_polly_paraPointsOutputs,outputs);

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

            testCase.verifyEqual(testCase.data_resolution_pollyOutputs,outputs);

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

            testCase.verifyEqual(testCase.resolution_polly_paraPointsOutputs,outputs);

        end
  %}       
%         function resolution_polly_test(testCase)
%             % test resolution_polly
%             %
%             % Inputs:
%             %   testCase - class instance
%             %
%             % Outputs:
%             %   none
%             %
%             % Example:
%             %   resolution_polly(testCase)
%             
%             out1 = resolution_polly(testCase.resolution_pollyInputs{1:end});
%             outputs ={out1};
% 
%             testCase.verifyEqual(testCase.resolution_pollyOutputs,outputs);
% 
%         end
%        

    end
end
