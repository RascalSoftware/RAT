classdef testUtilities < matlab.unittest.TestCase   

    methods (Test)
        function testIsText(testCase)
            testCase.verifyTrue(isText('character'), 'isText function is not working');
            testCase.verifyTrue(isText("string"), 'isText function is not working');
            testCase.verifyTrue(isText(["string", "array"]), 'isText function is not working');
            testCase.verifyFalse(isText(2), 'isText function is not working');
            testCase.verifyFalse(isText({'cell', 'array'}), 'isText function is not working');
        end

        function testValidateLogical(testCase)
            testCase.verifyTrue(validateLogical(true), 'validateLogical function is not working');
            testCase.verifyFalse(validateLogical(false), 'validateLogical function is not working');
            testCase.verifyError(@() validateLogical('a'), exceptions.invalidType.errorID);
            testCase.verifyError(@() validateLogical(0), exceptions.invalidType.errorID);
        end

        function testValidateNumber(testCase)
            testCase.verifyEqual(validateNumber(3), 3, 'validateNumber function is not working');
            testCase.verifyEqual(validateNumber(-1.6), -1.6, 'validateNumber function is not working');
            testCase.verifyEqual(validateNumber([1, 2, 3]), [1, 2, 3], 'validateNumber function is not working');
            testCase.verifyError(@() validateNumber('a'), exceptions.invalidType.errorID);
            testCase.verifyError(@() validateNumber(false), exceptions.invalidType.errorID);
            testCase.verifyEqual(validateNumber(-1.6, '', false), -1.6, 'validateNumber function is not working');
            testCase.verifyError(@() validateNumber(-1.6, '', true), exceptions.invalidValue.errorID);
        end

        function testValidateOption(testCase)
            testCase.verifyEqual(validateOption('UniForm', 'priorTypes'), priorTypes.Uniform, ...
                                 'validateOption function is not working');
            testCase.verifyEqual(validateOption(priorTypes.Gaussian, 'priorTypes'), priorTypes.Gaussian, ...
                                 'validateOption function is not working');
            testCase.verifyEqual(validateOption(searchStrategy.Random.value, 'searchStrategy', 'a error'), ...
                                 searchStrategy.Random, 'validateOption function is not working');
            testCase.verifyEqual(validateOption(searchStrategy.LocalToBest, 'searchStrategy', 'new error'), ...
                                 searchStrategy.LocalToBest, 'validateOption function is not working');
            testCase.verifyError(@() validateOption('a', 'priorTypes'), exceptions.invalidOption.errorID);
            testCase.verifyError(@() validateOption(false, 'priorTypes'), exceptions.invalidOption.errorID);
            testCase.verifyError(@() validateOption('uniform', 'priors'), exceptions.invalidValue.errorID);
            testCase.verifyError(@() validateOption('uniform', 2), exceptions.invalidType.errorID);
        end

        function testCustomEnum(testCase)
            enum = customEnum('any');
            testCase.verifyEqual(enum.value, 'any');
            testCase.verifyEqual(enum.values('allowedTypes'), allowedTypes.values(), 'customEnum.values is not working');
            testCase.verifyEqual(enum.values('calculationTypes'), calculationTypes.values(), 'customEnum.values is not working');
            testCase.verifyEqual(enum.values('hydrationTypes'), hydrationTypes.values(), 'customEnum.values is not working');
            testCase.verifyEqual(enum.values('priorTypes'), priorTypes.values(), 'customEnum.values is not working');
            testCase.verifyEqual(enum.values('supportedLanguages'), supportedLanguages.values(), 'customEnum.values is not working');
            testCase.verifyEqual(enum.fromValue('hydrationTypes', 'bulk in'), hydrationTypes.BulkIn, 'customEnum.fromValue is not working');
            testCase.verifyEmpty(enum.fromValue('priorTypes', 'jeff'), 'customEnum.fromValue is not working');
            testCase.verifyEqual(enum.values('eventTypes'), eventTypes.values(), 'customEnum.values is not working');
            testCase.verifyEmpty(enum.fromValue('eventTypes', -1), 'customEnum.fromValue is not working');
            testCase.verifyEqual(customEnum.toStruct('eventTypes'), struct('Message', 0, 'Plot', 1, 'Progress', 2), 'customEnum.toStruct is not working')
            props = properties(coderEnums);
            for i = 1:length(props)
                testCase.verifyEqual(coderEnums.(props{i}), eval([props{i},'.toStruct()']), 'customEnum.toStruct is not working')
            end
        end

        function testCopyProperties(testCase)
            initialProject = createProject(name='copyPropertiesTest', absorption=true);
            initialProject.addParameter('Test Param');

            copiedProject = copyProperties(initialProject, createProject(absorption=true));

            testCase.verifyEqual(copiedProject.experimentName, 'copyPropertiesTest');
            testCase.verifyEqual(copiedProject.layers, initialProject.layers);
            testCase.verifyEqual(copiedProject.parameters.getNames, ["Substrate Roughness"; "Test Param"]);
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
            mock.exceptionID = exceptions.invalidType.errorID;
            testCase.verifyError(@() randomName(), exceptions.invalidType.errorID);
            testCase.assertEqual(mock.callCount, 3);
            mock.reset()
            testCase.assertEqual(mock.callCount, 0);
            testCase.assertEqual(mock.arguments, {});
            testCase.assertEqual(mock.returnValues, {2});
            testCase.assertEqual(mock.exceptionID, exceptions.invalidType.errorID);

            mock = mockFunction(testCase, 'newFunction', 'returnValues', {1, 2});
            [a, b] = newFunction(1, 2, 3);
            testCase.assertEqual({a, b}, {1, 2});
            testCase.assertEqual(mock.arguments, {{1, 2, 3}});
            newFunction('a', 'b');
            testCase.assertEqual(mock.arguments, {{1, 2, 3}, {'a', 'b'}});

            mock = mockFunction(testCase, 'lastFunction', 'exceptionID', exceptions.invalidOption.errorID);
            testCase.assertEqual(mock.exceptionID, exceptions.invalidOption.errorID);
            testCase.verifyError(@() lastFunction(), exceptions.invalidOption.errorID);
        end

        function testWrappers(testCase)
            addPathMock = mockFunction(testCase, 'addpath');
            wrapper = pythonWrapper('demo.py', 'python_func');
            testCase.assertEqual(addPathMock.callCount, 1);
            delete(addPathMock);
            testCase.assertEqual(wrapper.functionName, 'python_func');
            testCase.assertEqual(wrapper.libPath, 'demo.py');
            testCase.assertEqual(wrapper.getHandle(), wrapper.tempName);
            display = evalc('disp(wrapper)');
            testCase.assertEqual(strtrim(display), 'Python wrapper for python_func function in demo.py');
            tempFolder = wrapper.tempFolder;
            testCase.assertEqual(exist(tempFolder, 'dir'), 7);
            rmPathMock = mockFunction(testCase, 'rmpath');
            delete(wrapper);
            testCase.assertEqual(rmPathMock.callCount, 1);
            testCase.assertEqual(exist(tempFolder, 'dir'), 0);
            
            fakeID = '123456789';
            mock = mockFunction(testCase, 'wrapperMex', 'returnValues', {fakeID});
            wrapper = dyLibWrapper('demo.dll', 'dylib_func');
            testCase.assertEqual(mock.callCount, 1);
            testCase.assertEqual(wrapper.functionName, 'dylib_func');
            testCase.assertEqual(wrapper.libPath, 'demo.dll');
            testCase.assertEqual(wrapper.getHandle(), fakeID);
            display = evalc('disp(wrapper)');
            testCase.assertEqual(strtrim(display), 'Dynamic library wrapper for dylib_func function in demo.dll');
            testCase.assertEqual(mock.arguments{end}, {'new', wrapper.libPath, wrapper.functionName});
            delete(wrapper);
            testCase.assertEqual(mock.callCount, 2);
            testCase.assertEqual(mock.arguments{end}, {'delete', fakeID});
        end

        function testCornerPlot(testCase)
            results = struct();
            results.chain = zeros(3);
            results.fitNames = ["A", "B", "C"];
            
            testCase.verifyError(@() cornerPlot(results, 'params', "D"), exceptions.invalidValue.errorID);
            testCase.verifyError(@() cornerPlot(results, 'params', [1.2, 3]), exceptions.invalidValue.errorID);
            testCase.verifyError(@() cornerPlot(results, 'params', [-1, 4]), exceptions.invalidValue.errorID);
            testCase.verifyError(@() cornerPlot(results, 'params', {'a', "B"}), exceptions.invalidValue.errorID);
            h1 = figure();
            cornerPlot(results, 'figure', h1, 'params', [1, 3]);
            testCase.verifyLength(findall(h1,'type','axes'), 4, 'cornerPlot did not create correct number of axes')
            cornerPlot(results, 'figure', h1, 'params', ["C", "B", "A"]);
            testCase.verifyLength(findall(h1,'type','axes'), 7, 'cornerPlot did not create correct number of axes')
            cornerPlot(results, 'figure', h1, 'params', {'C'});
            testCase.verifyLength(findall(h1,'type','axes'), 2, 'cornerPlot did not create correct number of axes')
            close(h1);
        end
    end
end