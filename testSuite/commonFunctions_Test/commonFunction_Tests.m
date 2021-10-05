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
        customLayers2Inputs;
        customLayers2Outputs;
        callMatlabCustomLayersInputs;
        callMatlabCustomLayersOutputs;

        applyBackgroundCorrectionInputs;
        applyBackgroundCorrectionOutputs;
        callReflectivityInputs;
        callReflectivityOutputs;

        allocateLayersForConstrastsInputs;
        allocateLayersForConstrastsOutputs;
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
        abelese_singleOutputs;
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
  
    end

    methods(TestMethodSetup)
        % Function to load inputs
%         function loadInputsForaProperty(testCase,prop,file)
%             % load inputs for a property
%             %
%             % Inputs:
%             %   testCase - class instance
%             %   prop - property name
%             %   file - file name
%             %   
%             %
%             % Outputs:
%             %   none but it loads properties
%             %
%             % Example:
%             %   loadInputsForaProperty(testCase,backSort,'backSort.mat')
%             %
%             inputs = load(file);
%             testCase.prop = inputs.prop; %make sure the var inside .mat is the same as property to aviod conflict
%         end
        
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
        %{
        function loadshiftData(testCase)
            inputs = load('shiftData.mat');
            testCase.shiftData = inputs.shiftData;
        end

        % legacyChanges?
        function loadcall_customLayers2(testCase)
            inputs = load('customLayers2.mat');
            testCase.customLayers2 = inputs.customLayers2;
        end

        function loadcallMatlabCustomLayers(testCase)
            inputs = load('callMatlabCustomLayers.mat');
            testCase.callMatlabCustomLayers = inputs.callMatlabCustomLayers;
        end

        %matlabFunctionalWrapper?

        function loadApplyBackgroundCorrection(testCase)
            inputs = load('applyBackgroundCorrection.mat');
            testCase.applyBackgroundCorrection = inputs.applyBackgroundCorrection;
        end

        function loadcallReflectivity(testCase)
            inputs = load('callReflectivity.mat');
            testCase.callReflectivity = inputs.callReflectivity;
        end

        function loadallocateLayersForConstrasts(testCase)
            inputs = load('allocateLayersForConstrasts.mat');
            testCase.allocateLayersForConstrasts = inputs.allocateLayersForConstrasts;
        end

        function loadallocateParamsToLayers(testCase)
            inputs = load('allocateParamsToLayers.mat');
            testCase.allocateParamsToLayers = inputs.allocateParamsToLayers;
        end

        function loadgroupLayers_Mod(testCase)
            inputs = load('groupLayers_Mod.mat');
            testCase.groupLayers_Mod = inputs.groupLayers_Mod;
        end

        function loadjacobianEst(testCase)
            inputs = load('jacobianEst.mat');
            testCase.jacobianEst = inputs.jacobianEst;
        end

        function loadMakeSLDProfiles(testCase)
            inputs = load('makeSLDProfiles.mat');
            testCase.makeSLDProfiles = inputs.makeSLDProfiles;
        end

        function loadMakeSLDProfileXY(testCase)
            inputs = load('makeSLDProfileXY.mat');
            testCase.makeSLDProfileXY = inputs.makeSLDProfileXY;
        end

        function loadabeles_paraPoints(testCase)
            inputs = load('abeles_paraPoints.mat');
            testCase.abeles_paraPoints = inputs.abeles_paraPoints;
        end

        function loadabeles_single(testCase)
            inputs = load('abeles_single.mat');
            testCase.abeles_single = inputs.abeles_single;
        end

        function loadadaptive(testCase)
            inputs = load('adaptive.mat');
            testCase.adaptive = inputs.adaptive;
        end

        function loadresampleLayers(testCase)
            inputs = load('resampleLayers.mat');
            testCase.resampleLayers = inputs.resampleLayers;
        end

        function loadsldFunc(testCase)
            inputs = load('sldFunc.mat');
            testCase.sldFunc = inputs.sldFunc;
        end

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
        function loadresolution_polly(testCase)
            inputs = load('resolution_polly.mat');
            testCase.resolution_polly = inputs.resolution_polly;
        end 
        %}

        
    end 
    methods(Test)
        % Verify backSort
        %{
            function backSort(testCase)
            % test backSort
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   backSort(testCase)
            
            %
            firstArg = testCase.backSortInputs{1};
            secondArg = testCase.backSortInputs{2};
            thirdArg = testCase.backSortInputs{3};
            fourthArg = testCase.backSortInputs{4};
            fifithArg = testCase.backSortInputs{5};
            sixthArg = testCase.backSortInputs{6};
            seventhArg = testCase.backSortInputs{7};
            eighthArg = testCase.backSortInputs{8};
            ninethArg = testCase.backSortInputs{9};
            tenthArg = testCase.backSortInputs{10};
            eleventhArg = testCase.backSortInputs{11};
            twelthArg = testCase.backSortInputs{12};
            outputs = backSort(firstArg,secondArg,thirdArg,fourthArg,fifithArg,sixthArg,seventhArg,eighthArg,ninethArg,tenthArg,eleventhArg,twelthArg);
            testCase.verifyEqual(testCase.backSortOutputs,outputs);
        end

            %}
            

        function chiSquared(testCase)
            % test chiSqaured

            outputs = chiSquared(testCase.chiSquaredInputs{1},testCase.chiSquaredInputs{2},testCase.chiSquaredInputs{3});
            testCase.verifyEqual(testCase.chiSquaredOutputs,outputs);
        end

        %{

        function shiftData_test(testCase)
            % test shiftData
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   shiftData(testCase)
            
            %
            firstArg = testCase.shiftDataInputs{1};
            secondArg = testCase.shiftDataInputs{2};
            thirdArg = testCase.shiftDataInputs{3};
            fourthArg = testCase.shiftDataInputs{4};
            fifithArg = testCase.shiftDataInputs{5};
            sixthArg = testCase.shiftDataInputs{6};
            outputs = shiftData(firstArg,secondArg,thirdArg,fourthArg,fifithArg,sixthArg)
            testCase.verifyEqual(testCase.shiftDataOutputs,outputs);
        end


        function callCustom_Layers2_test(testCase)
            % test callCustom_Layers2
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   callCustom_Layers(testCase)
            
            %
            firstArg = testCase.callCustom_Layers2Inputs{1};
            secondArg = testCase.callCustom_Layers2Inputs{2};
            thirdArg = testCase.callCustom_Layers2Inputs{3};
            fourthArg = testCase.callCustom_Layers2Inputs{4};
            fifithArg = testCase.callCustom_Layers2Inputs{5};
            sixthArg = testCase.callCustom_Layers2Inputs{6};
            outputs = call_customLayers(firstArg,secondArg,thirdArg,fourthArg,fifithArg,sixthArg)
            testCase.verifyEqual(testCase.callCustom_Layers2Outputs,outputs);
        end


        function callMatlabCustomLayers_test(testCase)
            % test callMatlabCustomLayers
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   callMatlabCustomLayers(testCase)
            
            %
            firstArg = testCase.callMatlabCustomLayersInputs{1};
            secondArg = testCase.callMatlabCustomLayersInputs{2};
            thirdArg = testCase.callMatlabCustomLayersInputs{3};
            fourthArg = testCase.callMatlabCustomLayersInputs{4};
            fifithArg = testCase.callMatlabCustomLayersInputs{5};
            sixthArg = testCase.callMatlabCustomLayersInputs{6};
            seventhArg = testCase.callMatlabCustomLayersInputs{7};

            outputs = callMatlabCustomLayers(firstArg,secondArg,thirdArg,fourthArg,fifithArg,sixthArg,seventhArg)
            testCase.verifyEqual(testCase.callMatlabCustomLayersOutputs,outputs);
        end

        function applyBackgroundCorretion_test(testCase)
            % test applyBackgroundCorretion
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   applyBackgroundCorretion(testCase)
            
            %
            firstArg = testCase.applyBackgroundCorretionInputs{1};
            secondArg = testCase.applyBackgroundCorretionInputs{2};
            thirdArg = testCase.applyBackgroundCorretionInputs{3};
            fourthArg = testCase.applyBackgroundCorretionInputs{4};
            fifithArg = testCase.applyBackgroundCorretionInputs{5};
            
            outputs = applyBackgroundCorretion(firstArg,secondArg,thirdArg,fourthArg,fifithArg)
            testCase.verifyEqual(testCase.applyBackgroundCorretionOutputs,outputs);

        end

        function callReflectivity_test(testCase)
            % test callReflectivity
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   callReflectivity(testCase)
            
            %
            firstArg = testCase.callReflectivityInputs{1};
            secondArg = testCase.callReflectivityInputs{2};
            thirdArg = testCase.callReflectivityInputs{3};
            fourthArg = testCase.callReflectivityInputs{4};
            fifithArg = testCase.callReflectivityInputs{5};
            sixthArg = testCase.callReflectivityInputs{6};
            seventhArg = testCase.callReflectivityInputs{7};
            eighthArg = testCase.callReflectivityInputs{8};
            ninethArg = testCase.callReflectivityInputs{9};
            tenthArg = testCase.callReflectivityInputs{10};
            

            outputs= callReflectivity(firstArg,secondArg,thirdArg,fourthArg,fifithArg,sixthArg,seventhArg,eighthArg,ninethArg,tenthArg)
            testCase.verifyEqual(testCase.callReflectivityOutputs,outputs);

        end

        

        function allocateLayersForContrast_test(testCase)
            % test allocateLayersForContrast
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   allocateLayersForContrast(testCase)
            
            %
            firstArg = testCase.allocateLayersForContrastInputs{1};
            secondArg = testCase.allocateLayersForContrastInputs{2};
            
            outputs = allocateLayersForContrast(firstArg,secondArg)
            testCase.verifyEqual(testCase.allocateLayersForContrastOutputs,outputs);
        end

        function allocatedParamsToLayers_test(testCase)
            % test allocatedParamsToLayers
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   allocatedParamsToLayers(testCase)
            
            %
            firstArg = testCase.allocatedParamsToLayersInputs{1};
            secondArg = testCase.allocatedParamsToLayersInputs{2};
            
            outputs = allocatedParamsToLayers(firstArg,secondArg)
            testCase.verifyEqual(testCase.allocatedParamsToLayersOutputs,outputs);
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
            firstArg = testCase.groupLayers_ModInputs{1};
            secondArg = testCase.groupLayers_ModInputs{2};
            thirdArg = testCase.groupLayers_ModInputs{3};
            fourthArg = testCase.groupLayers_ModInputs{4};
            fifithArg = testCase.groupLayers_ModInputs{5};
            
            outputs = groupLayers_Mod(firstArg,secondArg,thirdArg,fourthArg,fifithArg)

            testCase.verifyEqual(testCase.groupLayers_ModOutputs,outputs);

        end

        function jacobianEst_test(testCase)
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
            
            %
            firstArg = testCase.jacobianEstInputs{1};
            secondArg = testCase.jacobianEstInputs{2};
            
            outputs = jacobianest(firstArg,secondArg)

            testCase.verifyEqual(testCase.jacobianEstOutputs,outputs);
        end

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
            
            %
            firstArg = testCase.makeSLDProfilesInputs{1};
            secondArg = testCase.makeSLDProfilesInputs{2};
            thirdArg = testCase.makeSLDProfilesInputs{3};
            fourthArg = testCase.makeSLDProfilesInputs{4};
            fifithArg = testCase.makeSLDProfilesInputs{5};
            
            outputs = makeSLDProfiles(firstArg,secondArg,thirdArg,fourthArg,fifithArg)

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
            
            %
            firstArg = testCase.makeSLDProfileXYInputs{1};
            secondArg = testCase.makeSLDProfileXYInputs{2};
            thirdArg = testCase.makeSLDProfileXYInputs{3};
            fourthArg = testCase.makeSLDProfileXYInputs{4};
            fifithArg = testCase.makeSLDProfileXYInputs{5};
            sixthArg = testCase.makeSLDProfileXYInputs{6};

            outputs = makeSLDProfileXY(firstArg,secondArg,thirdArg,fourthArg,fifithArg,sixthArg)

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
            
            %
            firstArg = testCase.abeles_paraPointsInputs{1};
            secondArg = testCase.abeles_paraPointsInputs{2};
            thirdArg = testCase.abeles_paraPointsInputs{3};
            fourthArg = testCase.abeles_paraPointsInputs{4};
            fifithArg = testCase.abeles_paraPointsInputs{5};
            sixthArg = testCase.abeles_paraPointsInputs{6};
            seventhArg = testCase.abeles_paraPointsInputs{7};
            eighthArg = testCase.abeles_paraPointsInputs{8};

            outputs = abeles_paraPoints(firstArg,secondArg,thirdArg,fourthArg,fifithArg,sixthArg,seventhArg,eighthArg)

            testCase.verifyEqual(testCase.abeles_paraPointsOutputs,outputs);

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
            
            %
            firstArg = testCase.abeles_singleInputs{1};
            secondArg = testCase.abeles_singleInputs{2};
            thirdArg = testCase.abeles_singleInputs{3};
            fourthArg = testCase.abeles_singleInputs{4};
            fifithArg = testCase.abeles_singleInputs{5};
            sixthArg = testCase.abeles_singleInputs{6};
            seventhArg = testCase.abeles_singleInputs{7};
            eighthArg = testCase.abeles_singleInputs{8};
            
            outputs = abeles_single(firstArg,secondArg,thirdArg,fourthArg,fifithArg,sixthArg,seventhArg,eighthArg)
            testCase.verifyEqual(testCase.abeles_singleOutputs,outputs);

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
            firstArg = testCase.adaptiveInputs{1};
            secondArg = testCase.adaptiveInputs{2};
            thirdArg = testCase.adaptiveInputs{3};

            outputs = adaptive_new(firstArg,secondArg,thirdArg);

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
            
            %
            firstArg = testCase.resampleLayersInputs{1};
            secondArg = testCase.resampleLayersInputs{2};
            
            outputs = resampleLayers(firstArg,secondArg);

            testCase.verifyEqual(testCase.resampleLayersOutputs,outputs);
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
            
            %
            firstArg = testCase.sldFuncInputs{1};
            secondArg = testCase.sldFuncInputs{2};
            
            outputs = sldFunc(firstArg,secondArg);
            testCase.verifyEqual(testCase.sldFuncOutputs,outputs);

        end

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

        function resolution_polly_test(testCase)
            % test resolution_polly
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none
            %
            % Example:
            %   resolution_polly(testCase)
            
            %
            firstArg = testCase.resolution_pollyInputs{1};
            secondArg = testCase.resolution_pollyInputs{2};
            thirdArg = testCase.resolution_pollyInputs{3};
            fourthArg = testCase.resolution_pollyInputs{4};
            
            outputs = resolution_polly(firstArg,secondArg,thirdArg,fourthArg);

            testCase.verifyEqual(testCase.resolution_pollyOutputs,outputs);

        end

        function resolution_polly_paraPoints(testCase)
            % test resolution_polly_paraPoints
            %
            % Inputs:
            %   testCase - class instance
            %
            % Outputs:
            %   none


            firstArg = testCase.resolution_polly_paraPointsInputs{1};
            secondArg = testCase.resolution_polly_paraPointsInputs{2};
            thirdArg = testCase.resolution_polly_paraPointsInputs{3};
            fourthArg = testCase.resolution_polly_paraPointsInputs{4};
            
            outputs = resolution_polly_paraPoints(firstArg,secondArg,thirdArg,fourthArg);

            testCase.verifyEqual(testCase.resolution_polly_paraPointsOutputs,outputs);

        end
        %}




        
        

        
        
    end
end