classdef testParametersClass < matlab.unittest.TestCase   
    
    properties
        parameters
    end

    methods(TestMethodSetup)
        function createParameters(testCase)
            testCase.parameters = {
                    %       Name                min     val     max  fit? 'Prior Type','mu','sigma'
                    'Tails Thickness',         10,     20,     30,  true, 'uniform', 0, Inf;
                    'Heads Thickness',          3,     11,     16,  false, 'gaussian', -1, 1;
                    'Tails Roughness',          2,     5,      9,   true, 'uniform', 0, Inf;
                    'Heads Roughness',          2,     7,      9,   true, 'uniform', 0, Inf;
                    'Deuterated Tails SLD',    4e-6,   6e-6,   2e-5, true, 'uniform', 0, Inf;
                    'Hydrogenated Tails SLD', -0.6e-6, -0.4e-6, 0,  true, 'uniform', 0, Inf;
                    'Deuterated Heads SLD',    1e-6,   3e-6,   8e-6, true, 'gaussian', 1, 2;
                    'Hydrogenated Heads SLD',  0.1e-6,1.4e-6, 3e-6, true, 'uniform', 0, Inf;
                    'Heads Hydration',         0,      10,   0.5,  true, 'uniform', 0, Inf;
                };
        end
    end

    methods (Test)
        function testCreation(testCase)
            % Tests parameters class can be created and the start parameters is set correctly  
            params = parametersClass(testCase.parameters(1, :));
            testCase.verifyEqual(string(params.paramsTable{1, :}), ...
                                 string(testCase.parameters(1, :)), 'Start parameter not set correctly');
            testCase.verifySize(params.paramsTable, [1, 8], 'Parameters has wrong dimension');
            
            % bad start type
            testCase.verifyError(@() parametersClass({2, 10, 20, 30, true, 'fred', 0, Inf}), ?MException);
        end

        function testGetNames(testCase)
            % Tests getParamNames returns correctly  
            params = parametersClass(testCase.parameters(1, :));
            names = params.getParamNames();
            testCase.verifyEqual(names, string(testCase.parameters(1, 1)), 'Start parameter not set correctly');
            testCase.verifySize(names, [1, 1], 'Parameters has wrong dimension');

            params.paramsTable = [params.paramsTable; vertcat(testCase.parameters(2:end, :))];
            names = params.getParamNames();
            testCase.verifyEqual(names, convertCharsToStrings(testCase.parameters(:, 1)), 'Start parameter not set correctly');
            testCase.verifySize(names, [length(testCase.parameters), 1], 'Parameters has wrong dimension');
        end

        function testAddParams(testCase)
            params = parametersClass(testCase.parameters(1, :));
            % Checks that parameter can be added
            params.addParam();
            testCase.verifyEqual(params.paramsTable{end, 1}, "new parameter 1", 'addParam method not working');
            testCase.verifySize(params.paramsTable, [2, 8], 'Parameters has wrong dimension');
            params.addParam({'NewParam2'});
            testCase.verifyEqual(params.paramsTable{end, 1}, "NewParam2", 'addParam method not working');
            testCase.verifySize(params.paramsTable, [3, 8], 'Parameters has wrong dimension');
            testCase.verifyError(@() params.addParam({6.7}), ?MException)  % first value must be a char
            testCase.verifyError(@() params.addParam({'c', '1'}), ?MException)  % 2 value should be number
            params.addParam({'Another Param', 6.7});
            testCase.verifyEqual(params.paramsTable{end, 1}, "Another Param", 'addParam method not working');
            testCase.verifyEqual(params.paramsTable{end, 2:4}, [6.7, 6.7, 6.7], 'addParam method not working');
            testCase.verifySize(params.paramsTable, [4, 8], 'Parameters has wrong dimension');
            testCase.verifyError(@() params.addParam({'c', 1, 6.7}), ?MException);  % 3 values not accepted
            testCase.verifyError(@() params.addParam({'Another Param'}), ?MException);  % duplicate names not accepted
            testCase.verifyError(@() params.addParam({'c', '1', '2', 3}), ?MException);  % value 2-4 should be number
            params.addParam({'Param 5', 0, 6.7, 10});
            testCase.verifyEqual(params.paramsTable{end, 1}, "Param 5", 'addParam method not working');
            testCase.verifyEqual(params.paramsTable{end, 2:4}, [0, 6.7, 10], 'addParam method not working');
            testCase.verifySize(params.paramsTable, [5, 8], 'Parameters has wrong dimension'); 
            testCase.verifyError(@() params.addParam({'Param 6', 0, 1, 2, 'false'}), ?MException) % bad fit type
            params.addParam({'Param 6', 0, 1, 2, true});
            testCase.verifyEqual(params.paramsTable{end, 1}, "Param 6", 'addParam method not working');
            testCase.verifyEqual(params.paramsTable{end, 2:4}, [0, 1, 2], 'addParam method not working');
            testCase.verifyTrue(params.paramsTable{end, 5}, 'addParam method not working');
            testCase.verifySize(params.paramsTable, [6, 8], 'Parameters has wrong dimension');          
            testCase.verifyError(@() params.addParam({'c', 1, 1, 1, true, 'u'}), ?MException);  % 6 values not accepted
            testCase.verifyError(@() params.addParam({'c', 1, 1, 1, true, 'u', 1}), ?MException);  % 7 values not accepted
            testCase.verifyError(@() params.addParam({'Param 7', 0, 1, 2, false, 'jeff', -1, 1}), ?MException); % bad prior type
            testCase.verifyError(@() params.addParam({'Param 7', 0, 1, 2, false, 'uniform', '-1', 1}), ?MException); % bad prior value
            params.addParam({'Param 7', 0, 1, 2, false, 'jeffreys', -1, 1});
            testCase.verifyEqual(params.paramsTable{end, 1}, "Param 7", 'addParam method not working');
            testCase.verifyEqual(params.paramsTable{end, 2:4}, [0, 1, 2], 'addParam method not working');
            testCase.verifyFalse(params.paramsTable{end, 5}, 'addParam method not working');
            testCase.verifyEqual(params.paramsTable{end, 6}, "jeffreys", 'addParam method not working');
            testCase.verifyEqual(params.paramsTable{end, 7:8}, [-1, 1], 'addParam method not working');
            testCase.verifySize(params.paramsTable, [7, 8], 'Parameters has wrong dimension');
            params.addParam({'Param 8', 0, 1, 2, false, 'gaussian', -1, 1});
            testCase.verifyEqual(params.paramsTable{end, 6}, "gaussian", 'addParam method not working');
        end

        function testRemoveParams(testCase) 
            params = parametersClass(testCase.parameters(1, :));
            params.paramsTable = [params.paramsTable; vertcat(testCase.parameters(2:end, :))];
            paramNames = convertCharsToStrings(testCase.parameters(:, 1));
            % Checks that parameter can be removed
            testCase.verifyError(@() params.removeParam(), ?MException);
            testCase.verifyError(@() params.removeParam('bad name'), ?MException);
            params.removeParam(1);
            testCase.verifySize(params.paramsTable, [8, 8], 'Parameters has wrong dimension');
            testCase.verifyEqual(params.paramsTable{:, 1}, paramNames(2:end, 1), 'removeParam method not working');
            params.removeParam(6, 7, 8);
            testCase.verifySize(params.paramsTable, [5, 8], 'Parameters has wrong dimension');
            testCase.verifyEqual(params.paramsTable{:, 1}, paramNames(2:6, 1), 'removeParam method not working');
            params.removeParam('Tails Roughness');
            testCase.verifySize(params.paramsTable, [4, 8], 'Parameters has wrong dimension');
            testCase.verifyEqual(params.paramsTable{:, 1}, paramNames([2, 4, 5, 6], 1), 'removeParam method not working');
            testCase.verifyError(@() params.removeParam(11), ?MException);
        end

        function testSetParams(testCase)
            params = parametersClass(testCase.parameters(1, :));
            params.paramsTable = [params.paramsTable; vertcat(testCase.parameters(2:end, :))];
            % Checks that parameter can be modified
            testCase.verifyError(@() params.setParameter({0, 'Tails', 2}), ?MException);
            params.setParameter({1, 'name', 'Heads'});
            testCase.verifyEqual(params.paramsTable{1, 1}, "Heads", 'setParameter method not working');
            params.setParameter({'Tails Roughness', 'name', 'Tails?', 'min', 1, 'value', 1, 'max', 1, 'fit', false});
            testCase.verifyEqual(params.paramsTable{3, 1:5}, ["Tails?", 1, 1, 1, false], 'setParameter method not working');
            % Checks that parameter name can be modified
            testCase.verifyError(@() params.setName({1, 'Tails', 2}), ?MException);
            testCase.verifyError(@() params.setName({1, 2}), ?MException);
            params.setName({1, 'Tails'});
            testCase.verifyEqual(params.paramsTable{1, 1}, "Tails", 'setParameter method not working');
            params.setName({'Tails', 'Heads'});
            testCase.verifyEqual(params.paramsTable{1, 1}, "Heads", 'setParameter method not working');
            % Checks that parameter value can be modified
            testCase.verifyError(@() params.setValue({1, 'Tails', 2}), ?MException);
            testCase.verifyError(@() params.setValue({1, '2'}), ?MException);
            params.setValue({1, 15});
            testCase.verifyEqual(params.paramsTable{1, 3}, 15, 'setParameter method not working');
            params.setValue({'Heads', 20});
            testCase.verifyEqual(params.paramsTable{1, 3}, 20, 'setParameter method not working');
            % Checks that parameter constraints can be modified
            testCase.verifyError(@() params.setConstr({1}), ?MException);
            testCase.verifyError(@() params.setConstr({1, '3', '4'}), ?MException);
            params.setConstr({1, 1, 45});
            testCase.verifyEqual(params.paramsTable{1, [2, 4]}, [1, 45], 'setParameter method not working');
            params.setConstr({'Heads', 10, 30});
            testCase.verifyEqual(params.paramsTable{1, [2, 4]}, [10, 30], 'setParameter method not working');  
            % Checks that parameter fit can be modified
            testCase.verifyError(@() params.setFit({1}), ?MException);
            testCase.verifyError(@() params.setFit({1, '2'}), ?MException);
            params.setFit({1, false});
            testCase.verifyFalse(params.paramsTable{1, 5}, 'setParameter method not working');
            params.setFit({'Heads', true});
            testCase.verifyTrue(params.paramsTable{1, 5}, 'setParameter method not working');   
            testCase.verifyError(@() params.setFit({'Not present', false}), ?MException)
            % Checks that parameter priors can be modified
            testCase.verifyError(@() params.setPrior({1, '2'}), ?MException);
            params.setPrior({1, 'gaussian', 1, 2});
            testCase.verifyEqual(params.paramsTable{1, 6:8}, ["gaussian", 1, 2], 'setParameter method not working');
            params.setPrior({'Heads', 'uniform'});
            testCase.verifyEqual(params.paramsTable{1, 6:8}, ["uniform", 0, Inf], 'setParameter method not working');
            params.setPrior({'Heads', 'jeffreys'});
            % testCase.verifyEqual(params.paramsTable{1, 6}, "jeffries", 'setParameter method not working');
        end

        function testDisplayTable(testCase)
            import matlab.unittest.constraints.ContainsSubstring
            % Check that the content of the parameter table are printed
            actualHeader = {'Name', 'Min', 'Value', 'Max', 'Fit?', 'Prior Type', 'mu', 'sigma'};
            
            params = parametersClass(testCase.parameters(1, :));
            display = evalc('params.displayParametersTable()');
            testCase.verifyNotEmpty(display, 'displayParametersTable method not working');
            
            displayArray = textscan(display,'%s','Delimiter','\r','TextType','string');
            displayArray = strip(displayArray{1});
            % display table should be height of parameter table plus header and divider row
            testCase.verifyLength(displayArray, height(params.paramsTable) + 2)
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
                   
            % Change showPrior to show the full table
            params.paramsTable = [params.paramsTable; vertcat(testCase.parameters(2:3, :))];
            testCase.verifyError(@setShowPriors, ?MException);  % showPrior should be logical 
            function setShowPriors
                params.showPriors = 'a';
            end
            params.showPriors = true;

            display = evalc('params.displayParametersTable()');
            displayArray = textscan(display,'%s','Delimiter','\r','TextType','string');
            displayArray = strip(displayArray{1});
            testCase.verifyLength(displayArray, height(params.paramsTable) + 2)
            displayHeader = eraseBetween(displayArray{1}, '<', '>', 'Boundaries','inclusive');
            displayHeader = regexp(displayHeader, '\s{2,}', 'split');
            % display header should be width of parameters table plus index column
            testCase.verifyLength(displayHeader, width(params.paramsTable)+1)
            testCase.verifyEqual(displayHeader(2:end), actualHeader(1:end))
	        
            for i=1:height(params.paramsTable)-2
                row = regexp(displayArray{i+2}, '\s{2,}', 'split');
                row = string(replace(row, '"', ''));
                testCase.verifyLength(row, width(params.paramsTable)+1)
                testCase.verifyEqual(row(2:end), string(testCase.parameters(i, 1:end)))
            end
        end

        function testToStruct(testCase)
            % Checks that class to struct works correctly
            params = parametersClass(testCase.parameters(1, :));
            paramsStruct =   params.toStruct();
            
            testCase.verifyEqual(paramsStruct.paramNames, testCase.parameters(1, 1), 'toStruct method not working');
            testCase.verifyEqual(paramsStruct.nParams, 1, 'toStruct method not working');
            testCase.verifyEqual(paramsStruct.paramConstr, {[10 30]}, 'toStruct method not working');
            testCase.verifyEqual(paramsStruct.params, 20, 'toStruct method not working');
            testCase.verifyEqual(paramsStruct.fitYesNo, 1, 'toStruct method not working');
            testCase.verifyEqual(paramsStruct.priors, {{'Tails Thickness', 'uniform', 0, Inf}}, 'toStruct method not working');

            params.paramsTable = [params.paramsTable; vertcat(testCase.parameters(2:3, :))];
            paramsStruct = params.toStruct();
            testCase.verifyEqual(paramsStruct.paramNames, testCase.parameters(1:3, 1)', 'toStruct method not working');
            testCase.verifyEqual(paramsStruct.nParams, 3, 'toStruct method not working');
            testCase.verifyEqual(paramsStruct.paramConstr, {[10, 30], [3, 16], [2, 9]}, 'toStruct method not working');
            testCase.verifyEqual(paramsStruct.params, [20, 11, 5], 'toStruct method not working');
            testCase.verifyEqual(paramsStruct.fitYesNo, [1, 0, 1], 'toStruct method not working');   
            testCase.verifyEqual(paramsStruct.priors, {{'Tails Thickness', 'uniform', 0, Inf}; ...
                                {'Heads Thickness', 'gaussian', -1, 1}; {'Tails Roughness', 'uniform', 0, Inf}}, 'toStruct method not working');
        end
    end
end
