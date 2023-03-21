classdef testUtilities < matlab.unittest.TestCase   

    methods (Test)
        function testIsText(testCase)
            testCase.verifyTrue(isText('character'), 'isText function is not working');
            testCase.verifyTrue(isText("string"), 'isText function is not working');
            testCase.verifyTrue(isText(["string", "array"]), 'isText function is not working');
            testCase.verifyFalse(isText(2), 'isText function is not working');
            testCase.verifyFalse(isText({'cell', 'array'}), 'isText function is not working');
        end

        function testValidateNumber(testCase)
            testCase.verifyEqual(validateNumber(3), 3, 'validateNumber function is not working');
            testCase.verifyEqual(validateNumber(-1.6), -1.6, 'validateNumber function is not working');
            testCase.verifyEqual(validateNumber([1, 2, 3]), [1, 2, 3], 'validateNumber function is not working');
            testCase.verifyError(@() validateNumber('a'), invalidType.errorID);
            testCase.verifyError(@() validateNumber(false), invalidType.errorID);
        end

        function testValidateOption(testCase)
            testCase.verifyEqual(validateOption('UniForm', 'priorTypes'), priorTypes.Uniform, ...
                                 'validateOption function is not working');
            testCase.verifyEqual(validateOption(priorTypes.Gaussian, 'priorTypes'), priorTypes.Gaussian, ...
                                 'validateOption function is not working');
            testCase.verifyEqual(validateOption(strategyOptions.Random.value, 'strategyOptions', 'a error'), ...
                                 strategyOptions.Random, 'validateOption function is not working');
            testCase.verifyEqual(validateOption(strategyOptions.LocalToBest, 'strategyOptions', 'new error'), ...
                                 strategyOptions.LocalToBest, 'validateOption function is not working');
            testCase.verifyError(@() validateOption('a', 'priorTypes'), invalidOption.errorID);
            testCase.verifyError(@() validateOption(false, 'priorTypes'), invalidType.errorID);
            testCase.verifyError(@() validateOption('uniform', 'priors'), invalidValue.errorID);
            testCase.verifyError(@() validateOption('uniform', 2), invalidType.errorID);
        end

        function testCustomEnum(testCase)
            enum = customEnum('any');
            testCase.verifyEqual(enum.value, 'any');
            testCase.verifyEqual(enum.values('allowedTypes'), allowedTypes.values(), 'customEnum.values is not working');
            testCase.verifyEqual(enum.values('hydrationTypes'), hydrationTypes.values(), 'customEnum.values is not working');
            testCase.verifyEqual(enum.values('priorTypes'), priorTypes.values(), 'customEnum.values is not working');
            testCase.verifyEqual(enum.values('supportedLanguages'), supportedLanguages.values(), 'customEnum.values is not working');
            testCase.verifyEqual(enum.fromValue('hydrationTypes', 'bulk in'), hydrationTypes.BulkIn, 'customEnum.forValues is not working');
            testCase.verifyEmpty(enum.fromValue('priorTypes', 'jeff'), 'customEnum.forValues is not working');
        end
    end
end