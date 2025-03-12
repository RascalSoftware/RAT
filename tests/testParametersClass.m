classdef testParametersClass < matlab.unittest.TestCase   
    
    properties
        parameters
    end

    methods(TestMethodSetup)
        function createParameters(testCase)
            testCase.parameters = {
                    %       Name                min     val     max  fit? 'Prior Type','mu','sigma'
                    'Tails Thickness',         10,     20,     30,  true, priorTypes.Uniform.value, 0, Inf;
                    'Heads Thickness',          3,     11,     16,  false, priorTypes.Gaussian.value, -1, 1;
                    'Tails Roughness',          2,     5,      9,   true, priorTypes.Uniform.value, 0, Inf;
                    'Heads Roughness',          2,     7,      9,   true, priorTypes.Uniform.value, 0, Inf;
                    'Deuterated Tails SLD',    4e-6,   6e-6,   2e-5, true, priorTypes.Uniform.value, 0, Inf;
                    'Hydrogenated Tails SLD', -0.6e-6, -0.4e-6, 0,  true, priorTypes.Uniform.value, 0, Inf;
                    'Deuterated Heads SLD',    1e-6,   3e-6,   8e-6, true, priorTypes.Gaussian.value, 1, 2;
                    'Hydrogenated Heads SLD',  0.1e-6,1.4e-6, 3e-6, true, priorTypes.Uniform.value, 0, Inf;
                    'Heads Hydration',         0,      10,   0.5,  true, priorTypes.Uniform.value, 0, Inf;
                };
        end
    end

    methods (Test)
        function testCreation(testCase)
            % Tests parameters class can be created and the start parameters is set correctly
            params = parametersClass();
            testCase.verifyEqual(params.varTable{end, 1}, "new parameter 1", 'addParameter method not working');
            params = parametersClass(testCase.parameters{1, :});
            testCase.verifyEqual(string(params.varTable{1, :}), ...
                                 string(testCase.parameters(1, :)), 'Start parameter not set correctly');
            testCase.verifySize(params.varTable, [1, 8], 'Parameters has wrong dimension');
            
            % bad start type
            testCase.verifyError(@() parametersClass(2, 10, 20, 30, true, 'fred', 0, Inf), 'MATLAB:validators:mustBeTextScalar');
        end

        function testGetNames(testCase)
            % Tests getNames returns correctly  
            params = parametersClass(testCase.parameters{1, :});
            names = params.getNames();
            testCase.verifyEqual(names, string(testCase.parameters(1, 1)), 'Start parameter not set correctly');
            testCase.verifySize(names, [1, 1], 'Parameters has wrong dimension');

            params.varTable = [params.varTable; vertcat(testCase.parameters(2:end, :))];
            names = params.getNames();
            testCase.verifyEqual(names, convertCharsToStrings(testCase.parameters(:, 1)), 'Start parameter not set correctly');
            testCase.verifySize(names, [size(testCase.parameters, 1), 1], 'Parameters has wrong dimension');
        end

        function testAddParams(testCase)
            import matlab.unittest.fixtures.SuppressedWarningsFixture
            testCase.applyFixture(SuppressedWarningsFixture('warnings:nonGaussianPriors'))

            params = parametersClass(testCase.parameters{1, :});
            % Checks that parameter can be added
            params.addParameter();
            testCase.verifyEqual(params.varTable{end, 1}, "new parameter 2", 'addParameter method not working');
            testCase.verifySize(params.varTable, [2, 8], 'Parameters has wrong dimension');
            params.addParameter('NewParam2');
            testCase.verifyEqual(params.varTable{end, 1}, "NewParam2", 'addParameter method not working');
            testCase.verifySize(params.varTable, [3, 8], 'Parameters has wrong dimension');
            testCase.verifyError(@() params.addParameter(6.7), 'MATLAB:validators:mustBeTextScalar')  % first value must be a char
            testCase.verifyError(@() params.addParameter('c', '1'), 'MATLAB:validators:mustBeNumeric')  % 2 value should be number
            testCase.verifyError(@() params.addParameter('newParam2'), exceptions.duplicateName.errorID);
            params.addParameter('Another Param', 6.7);
            testCase.verifyEqual(params.varTable{end, 1}, "Another Param", 'addParameter method not working');
            testCase.verifyEqual(params.varTable{end, 2:4}, [6.7, 6.7, 6.7], 'addParameter method not working');
            testCase.verifySize(params.varTable, [4, 8], 'Parameters has wrong dimension');
            testCase.verifyError(@() params.addParameter('Another Param'), exceptions.duplicateName.errorID);  % duplicate names not accepted
            testCase.verifyError(@() params.addParameter('c', '1', '2', 3), 'MATLAB:validators:mustBeNumeric');  % value 2-4 should be number
            testCase.verifyError(@() params.addParameter('c', 30, 20, 10), exceptions.invalidValue.errorID);  % lower limit should be less than upper
            testCase.verifyError(@() params.addParameter('c', 10, 0, 30), exceptions.invalidValue.errorID);  % value outside of limits - too low
            testCase.verifyError(@() params.addParameter('c', 10, 40, 30), exceptions.invalidValue.errorID);  % value outside of limits - too high
            params.addParameter('Param 5', 0, 6.7, 10);
            testCase.verifyEqual(params.varTable{end, 1}, "Param 5", 'addParameter method not working');
            testCase.verifyEqual(params.varTable{end, 2:4}, [0, 6.7, 10], 'addParameter method not working');
            testCase.verifySize(params.varTable, [5, 8], 'Parameters has wrong dimension'); 
            testCase.verifyError(@() params.addParameter('Param 6', 0, 1, 2, 'false'), 'MATLAB:validators:mustBeA') % bad fit type
            params.addParameter('Param 6', 0, 1, 2, true);
            testCase.verifyEqual(params.varTable{end, 1}, "Param 6", 'addParameter method not working');
            testCase.verifyEqual(params.varTable{end, 2:4}, [0, 1, 2], 'addParameter method not working');
            testCase.verifyTrue(params.varTable{end, 5}, 'addParameter method not working');
            testCase.verifySize(params.varTable, [6, 8], 'Parameters has wrong dimension');
            testCase.verifyError(@() params.addParameter('Param 7', 0, 1, 2, false, 'jeff', -1, 1), exceptions.invalidOption.errorID); % bad prior type
            testCase.verifyError(@() params.addParameter('Param 7', 0, 1, 2, false, priorTypes.Uniform, '-1', 1), 'MATLAB:validators:mustBeNumeric'); % bad prior value
            params.addParameter('Param 7', 0, 1, 2, false, priorTypes.Jeffreys, -1, 1);
            testCase.verifyEqual(params.varTable{end, 1}, "Param 7", 'addParameter method not working');
            testCase.verifyEqual(params.varTable{end, 2:4}, [0, 1, 2], 'addParameter method not working');
            testCase.verifyFalse(params.varTable{end, 5}, 'addParameter method not working');
            testCase.verifyEqual(params.varTable{end, 6}, string(priorTypes.Jeffreys.value), 'addParameter method not working');
            testCase.verifyEqual(params.varTable{end, 7:8}, [0, Inf], 'addParameter method not working');
            testCase.verifySize(params.varTable, [7, 8], 'Parameters has wrong dimension');
            params.addParameter('Param 8', 0, 1, 2, false, priorTypes.Gaussian, -1, 1);
            testCase.verifyEqual(params.varTable{end, 6}, string(priorTypes.Gaussian.value), 'addParameter method not working');
        end

        function testRemoveParams(testCase) 
            params = parametersClass(testCase.parameters{1, :});
            params.varTable = [params.varTable; vertcat(testCase.parameters(2:end, :))];
            paramNames = convertCharsToStrings(testCase.parameters(:, 1));
            % Checks that parameter can be removed
            testCase.verifyError(@() params.removeParameter('bad name'), exceptions.nameNotRecognised.errorID);
            params.removeParameter(1);
            testCase.verifySize(params.varTable, [8, 8], 'Parameters has wrong dimension');
            testCase.verifyEqual(params.varTable{:, 1}, paramNames(2:end, 1), 'removeParameter method not working');
            params.removeParameter([6, 7, 8]);
            testCase.verifySize(params.varTable, [5, 8], 'Parameters has wrong dimension');
            testCase.verifyEqual(params.varTable{:, 1}, paramNames(2:6, 1), 'removeParameter method not working');
            params.removeParameter('Tails Roughness');
            testCase.verifySize(params.varTable, [4, 8], 'Parameters has wrong dimension');
            testCase.verifyEqual(params.varTable{:, 1}, paramNames([2, 4, 5, 6], 1), 'removeParameter method not working');
            testCase.verifyError(@() params.removeParameter(11), exceptions.indexOutOfRange.errorID);
            testCase.verifyError(@() params.removeParameter(true), exceptions.invalidType.errorID);
        end

        function testSetParameter(testCase)
            params = parametersClass(testCase.parameters{1, :});
            params.varTable = [params.varTable; vertcat(testCase.parameters(2:end, :))];
            % Checks that parameter can be modified
            params.setParameter(1, 'name', 'Heads');
            testCase.verifyEqual(params.varTable{1, 1}, "Heads", 'setParameter method not working');
            params.setParameter('Tails Roughness', 'name', 'Tails?', 'min', 1, 'value', 1, 'max', 1, 'fit', false);
            testCase.verifyEqual(params.varTable{3, 1:5}, ["Tails?", 1, 1, 1, false], 'setParameter method not working');
            params.setParameter(1, 'min', 5, 'max', 25);
            testCase.verifyEqual(params.varTable{1, 2}, 5, 'setParameter method not working');
            testCase.verifyEqual(params.varTable{1, 4}, 25, 'setParameter method not working');
            params.setParameter(1, 'min', 30, 'value', 40, 'max', 50);
            testCase.verifyEqual(params.varTable{1, 2:4}, [30. 40, 50], 'setParameter method not working');
            params.setParameter(1, 'min', 10, 'value', 20, 'max', 30);
            testCase.verifyError(@() params.setParameter(1, 'min', 30), exceptions.invalidValue.errorID);  % lower limit should be less than upper
            testCase.verifyError(@() params.setParameter(1, 'max', 0), exceptions.invalidValue.errorID);  % lower limit should be less than upper
            testCase.verifyError(@() params.setParameter(1, 'value', 0), exceptions.invalidValue.errorID);  % value outside of limits - too low
            testCase.verifyError(@() params.setParameter(1, 'value', 50), exceptions.invalidValue.errorID);  % value outside of limits - too high
            params.setParameter('Tails?', 'priorType', priorTypes.Gaussian);
            testCase.verifyEqual(params.varTable{3, 6:8}, [string(priorTypes.Gaussian.value), 0, Inf], 'setParameter method not working');
            params.setParameter('Tails?', 'mu', 1, 'sigma', 5);
            testCase.verifyEqual(params.varTable{3, 6:8}, [string(priorTypes.Gaussian.value), 1, 5], 'setParameter method not working');
            testCase.verifyWarning(@() params.setParameter('Tails?', 'priorType', priorTypes.Uniform.value), 'warnings:nonGaussianPriors');
            testCase.verifyEqual(params.varTable{3, 6:8}, [string(priorTypes.Uniform.value), 0, inf], 'setParameter method not working');
            testCase.verifyWarning(@() params.setParameter('Tails?', 'sigma', 6), 'warnings:nonGaussianPriors');
            testCase.verifyEqual(params.varTable{3, 6:8}, [string(priorTypes.Uniform.value), 0, inf], 'setParameter method not working');
        end

        function testOtherSetFunctions(testCase)
            params = parametersClass(testCase.parameters{1, :});
            params.varTable = [params.varTable; vertcat(testCase.parameters(2:end, :))];          
            % Checks that parameter name can be modified
            testCase.verifyError(@() params.setName(1, 2), 'MATLAB:validators:mustBeTextScalar');
            params.setName(1, 'Tails');
            testCase.verifyEqual(params.varTable{1, 1}, "Tails", 'setParameter method not working');
            params.setName('Tails', 'Heads');
            testCase.verifyEqual(params.varTable{1, 1}, "Heads", 'setParameter method not working');
            % Checks that parameter value can be modified
            testCase.verifyError(@() params.setValue(1, '2'), 'MATLAB:validators:mustBeNumeric');
            params.setValue(1, 15);
            testCase.verifyEqual(params.varTable{1, 3}, 15, 'setParameter method not working');
            params.setValue('Heads', 20);
            testCase.verifyEqual(params.varTable{1, 3}, 20, 'setParameter method not working');
            testCase.verifyError(@() params.setValue(1, 0), exceptions.invalidValue.errorID);  % value outside of limits - too low
            testCase.verifyError(@() params.setValue(1, 50), exceptions.invalidValue.errorID);  % value outside of limits - too high            
            % Checks that parameter limits can be modified
            testCase.verifyError(@() params.setLimits(1, '3', '4'), 'MATLAB:validators:mustBeNumeric');
            params.setLimits(1, 1, 45);
            testCase.verifyEqual(params.varTable{1, [2, 4]}, [1, 45], 'setParameter method not working');
            params.setLimits('Heads', 10, 30);
            testCase.verifyEqual(params.varTable{1, [2, 4]}, [10, 30], 'setParameter method not working');
            testCase.verifyError(@() params.setLimits(1, 30, 10), exceptions.invalidValue.errorID);  % lower limit should be less than upper
            % Checks that parameter fit can be modified
            testCase.verifyError(@() params.setFit(1, '2'), 'MATLAB:validators:mustBeA');
            params.setFit(1, false);
            testCase.verifyFalse(params.varTable{1, 5}, 'setParameter method not working');
            params.setFit('Heads', true);
            testCase.verifyTrue(params.varTable{1, 5}, 'setParameter method not working');   
            testCase.verifyError(@() params.setFit('Not present', false), exceptions.nameNotRecognised.errorID)
            % Checks that parameter priors can be modified
            testCase.verifyError(@() params.setPrior(1, '2'), exceptions.invalidOption.errorID);
            params.setPrior(1, priorTypes.Gaussian, 1, 2);
            testCase.verifyEqual(params.varTable{1, 6:8}, [string(priorTypes.Gaussian.value), 1, 2], 'setPrior method not working');
            % setPriors changes mu and sigma from [1, 2] to [0, Inf] and throws warning
            testCase.verifyWarning(@() params.setPrior('Heads', priorTypes.Uniform), 'warnings:nonGaussianPriors');
            testCase.verifyEqual(params.varTable{1, 6:8}, [string(priorTypes.Uniform.value), 0, Inf], 'setPrior method not working');
            params.setPrior('Heads', priorTypes.Jeffreys);
            % testCase.verifyEqual(params.varTable{1, 6}, string(priorTypes.Jeffreys.value), 'setParameter method not working');
            params.setPrior(3, 'gaussian', 2);
            testCase.verifyEqual(params.varTable{3, 6:8}, [string(priorTypes.Gaussian.value), 2, Inf], 'setPrior method not working');
        end

        function testDisplayTable(testCase)
            % Check that the content of the parameter table are printed
            actualHeader = {'Name', 'Min', 'Value', 'Max', 'Fit?', 'Prior Type', 'mu', 'sigma'};
            
            params = parametersClass(testCase.parameters{1, :});
            display = evalc('params.displayTable()');
            testCase.verifyNotEmpty(display, 'displayTable method not working');
            
            displayArray = textscan(display,'%s','Delimiter','\r','TextType','string');
            displayArray = strip(displayArray{1});
            % display table should be height of parameter table plus header and divider row
            testCase.verifyLength(displayArray, height(params.varTable) + 2)
            % Remove html tags used to format header then split table when
            % 2 or more spaces are found to avoid splitting param names with
            % single space
            displayHeader = eraseBetween(displayArray{1}, '<', '>', 'Boundaries','inclusive');
            displayHeader = regexp(displayHeader, '\s{2,}', 'split');
            % display header should be first 5 parameters plus index column
            testCase.verifyLength(displayHeader, 6)
            testCase.verifyEqual(displayHeader(2:6), actualHeader(1:5))
	        row = regexp(displayArray{3}, '\s{2,}', 'split');
            row = string(replace(row, '"', ''));
            testCase.verifyLength(row, 6)
            testCase.verifyEqual(row(2:end), string(testCase.parameters(1, 1:5)))

            display = evalc('params.displayTable(true)');
            displayArray = textscan(display,'%s','Delimiter','\r','TextType','string');
            displayArray = strip(displayArray{1});
            testCase.verifyLength(displayArray, height(params.varTable) + 2)
            displayHeader = eraseBetween(displayArray{1}, '<', '>', 'Boundaries','inclusive');
            displayHeader = regexp(displayHeader, '\s{2,}', 'split');
            % display header should be width of parameters table plus index column
            testCase.verifyLength(displayHeader, width(params.varTable)+1)
            testCase.verifyEqual(displayHeader(2:end), actualHeader(1:end))
	        
            for i=1:height(params.varTable)-2
                row = regexp(displayArray{i+2}, '\s{2,}', 'split');
                row = string(replace(row, '"', ''));
                testCase.verifyLength(row, width(params.varTable)+1)
                testCase.verifyEqual(row(2:end), string(testCase.parameters(i, 1:end)))
            end
        end

        function testDisplayTableEmpty(testCase)
            % Check that the empty parameter table is printed correctly
            emptyClass = parametersClass();
            emptyClass.removeParameter(1);

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display = textscan(evalc('emptyClass.displayTable(true)'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};

            outVars = eraseBetween(strip(regexprep(displayedTable(1), '\s+', ' ')), '<', '>','Boundaries','inclusive');
            varString = strip(strjoin(string(emptyClass.varTable.Properties.VariableNames)));
            testCase.verifyEqual(outVars, varString, 'Table headers do not match variable names');
            testCase.assertSize(displayedTable, [3, 1], 'Table does not have the right number of rows');

            outRow = strip(regexprep(displayedTable(3), '\s+', ' '));
            rowString = """"" """" """" """" """" """" """" """"";
            testCase.verifyEqual(outRow, rowString, 'Row does not contain the correct data');

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display = textscan(evalc('emptyClass.displayTable(false)'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};
            outRow = strip(regexprep(displayedTable(3), '\s+', ' '));
            rowString = """"" """" """" """" """"";
            testCase.verifyEqual(outRow, rowString, 'Row does not contain the correct data');
        end
        
        function testToStruct(testCase)
            % Checks that class to struct works correctly
            params = parametersClass(testCase.parameters{1, :});
            paramsStruct = params.toStruct();
            
            testCase.verifyEqual(paramsStruct.names, testCase.parameters(1, 1), 'toStruct method not working');
            testCase.verifyEqual(paramsStruct.limits, {[10 30]}, 'toStruct method not working');
            testCase.verifyEqual(paramsStruct.values, 20, 'toStruct method not working');
            testCase.verifyEqual(paramsStruct.fit, 1, 'toStruct method not working');
            testCase.verifyEqual(paramsStruct.priors, {{'Tails Thickness', priorTypes.Uniform.value, 0, Inf}}, 'toStruct method not working');

            params.varTable = [params.varTable; vertcat(testCase.parameters(2:3, :))];
            paramsStruct = params.toStruct();
            testCase.verifyEqual(paramsStruct.names, testCase.parameters(1:3, 1)', 'toStruct method not working');
            testCase.verifyEqual(paramsStruct.limits, {[10, 30], [3, 16], [2, 9]}, 'toStruct method not working');
            testCase.verifyEqual(paramsStruct.values, [20, 11, 5], 'toStruct method not working');
            testCase.verifyEqual(paramsStruct.fit, [1, 0, 1], 'toStruct method not working');   
            testCase.verifyEqual(paramsStruct.priors, {{'Tails Thickness', priorTypes.Uniform.value, 0, Inf}; ...
                                {'Heads Thickness', priorTypes.Gaussian.value, -1, 1}; {'Tails Roughness', priorTypes.Uniform.value, 0, Inf}}, 'toStruct method not working');
        end
    end
end
