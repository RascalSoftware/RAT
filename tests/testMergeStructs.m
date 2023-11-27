classdef testMergeStructs < matlab.unittest.TestCase   

    properties (TestParameter)
        s = {struct('s1', 1, 's2', 2),...
             struct('s1', 1),...
             struct('s1', 1, 's2', 2, 's3', 3)};
        d = {struct('d1', 1, 'd2', 2),...
             struct('d1', 1),...
             struct('d1', 1, 'd2', 2)};
        r = {struct('s1', 1, 's2', 2, 'd1', 1, 'd2', 2),...
             struct('s1', 1, 'd1', 1),...
             struct('s1', 1, 's2', 2, 's3', 3, 'd1', 1, 'd2', 2)};
    end

    methods (Test, ParameterCombination="sequential")
        function testMergeResults(testCase, s, d, r)
            result = mergeStructs(s, d);
            testCase.verifyEqual(result, r);
        end

        function testMergeError(testCase)
            s1 = struct('s', 1);
            s2 = struct('s', 3);
            testCase.verifyError(@() mergeStructs(s1, s2), 'MATLAB:DuplicateFieldName')
        end
    end
end