classdef testUtilities < matlab.unittest.TestCase   

    methods (Test)
        function testValidateNumber(testCase)
            testCase.verifyEqual(validateNumber(3), 3, 'validateNumber function is not working');
            testCase.verifyEqual(validateNumber(-1.6), -1.6, 'validateNumber function is not working');
            testCase.verifyEqual(validateNumber([1, 2, 3]), [1, 2, 3], 'validateNumber function is not working');
            testCase.verifyError(@() validateNumber('a'), invalidType.errorID);
            testCase.verifyError(@() validateNumber(false), invalidType.errorID);
        end
    end
end