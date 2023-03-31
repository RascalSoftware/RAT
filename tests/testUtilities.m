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

        function testMockFunction(testCase)
            mock = mockFunction(testCase, 'randomName');
            testCase.verifyEqual(mock.functionName, 'randomName');
            testCase.assertEqual(which(mock.functionName), mock.filename);
            testCase.assertEqual(mock.callCount, 0);
            testCase.assertEqual(mock.arguments, {});
            testCase.assertEqual(mock.exceptionID, '');
            testCase.assertEqual(mock.returnValues, {[]});
            testCase.verifyEmpty(randomName());
            testCase.assertEqual(mock.callCount, 1);
            mock.returnValues = {2};
            testCase.verifyEqual(randomName(), 2);
            testCase.assertEqual(mock.callCount, 2);
            mock.exceptionID = invalidType.errorID;
            testCase.verifyError(@() randomName(), invalidType.errorID);
            testCase.assertEqual(mock.callCount, 3);
            mock.reset()
            testCase.assertEqual(mock.callCount, 0);
            testCase.assertEqual(mock.arguments, {});
            testCase.assertEqual(mock.returnValues, {2});
            testCase.assertEqual(mock.exceptionID, invalidType.errorID);

            mock = mockFunction(testCase, 'newFunction', 'returnValues', {1, 2});
            [a, b] = newFunction(1, 2, 3);
            testCase.assertEqual({a, b}, {1, 2});
            testCase.assertEqual(mock.arguments, {{1, 2, 3}});
            newFunction('a', 'b');
            testCase.assertEqual(mock.arguments, {{1, 2, 3}, {'a', 'b'}});

            mock = mockFunction(testCase, 'lastFunction', 'exceptionID', invalidOption.errorID);
            testCase.assertEqual(mock.exceptionID, invalidOption.errorID);
            testCase.verifyError(@() lastFunction(), invalidOption.errorID);
        end
    end
end