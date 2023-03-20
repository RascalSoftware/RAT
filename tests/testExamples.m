classdef testExamples < matlab.unittest.TestCase
 
    properties (TestParameter)
        examplePath = {'orsoDSPCStandardLayers',...
            'DPPCCustomXYScript',...
            'testCppCustomLayers',...
            'DSPCMonolayerStandardLayers',...
            'DSPCMonolayerTwoContrasts',...
            'DSPCMonolayerCustomLayers'};
    end


    methods (Test,ParameterCombination="sequential")
        % Runs the different examples sequentially 
        function testExample(testCase, examplePath)
                testCase.verifyEqual(exist(examplePath,'file'), 2);
                run(examplePath);
                close all;
        end
    end
end



