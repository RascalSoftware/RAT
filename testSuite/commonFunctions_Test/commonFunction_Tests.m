% Test all the common functions in RAT

% declare a class and inherit from matlab.unit.TestCase

classdef commonFunction_Tests < matlab.unittest.TestCase 
    properties
        backSort;
        chiSquared;
        shiftData;
        customLayers2;
        callMatlabCustomLayers;
        applyBackgroundCorrection;
        callReflectivity;
        allocateLayersForConstrasts;
        allocateParamsToLayers;
        groupLayers_Mod;
        jacobianEst;
        makeSLDProfiles;
        makeSLDProfileXY;
        abeles_paraPoints;
        abeles_single;
        adaptive;
        resampleLayers;
        sldFunc;
        data_resolution_polly_paraPoints;
        data_resolution_polly;
        resolution_polly_paraPoints;
        resolution_polly;
  
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
            inputs = load('backSortInOuts.mat');
            testCase.backSort = inputs.backSort;
        end

        function loadChiSqaured(testCase)
            inputs = load('chiSquared.mat');
            testCase.chiSquared = inputs.chiSquared;
        end

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
        
    end 
    methods(Test)
        
        
        
    end
end