 classdef testBackgroundsClass < matlab.unittest.TestCase   
    
    properties
        parameters
        backgrounds
        background
    end

    methods(TestMethodSetup)
        function createBackground(testCase)
            testCase.background = backgroundsClass(testCase.parameters(1, :), testCase.backgrounds(1, :));
        end
    end

    methods(TestClassSetup)
        function createBackgrounds(testCase)
            testCase.parameters = {
                    % Name               min   val   max  fit? 'Prior Type','mu','sigma'
                    'background par 1', 0.01, 0.03, 0.05, false, 'uniform', 0, Inf;
                    'background par 2', 0.1, 0.19, 1.0, true, 'gaussian', -1, 1;
                    'background par 3', 0.2, 0.17, 1.1, false, 'uniform', 0, Inf;
                    };
            testCase.backgrounds = {
                    'background 1', 'gaussian', 'background par 1', '', '', '', '';
                    'background 2', 'constant', 'background par 2', '', '', '', '';
                    'background 3', 'function', 'function_name', 'background par 1', 'background par 2', '', '';
                    'background 4', 'data', '', '', '', '', '';
                    };
        end
    end

    methods (Test)
        function testCreation(testCase)
            % Tests background class can be created and the start parameters is set correctly  
            background = backgroundsClass(testCase.parameters(1, :), testCase.backgrounds(1, :));
            testCase.verifyEqual(string(background.backPars.paramsTable{1, :}), ...
                                 string(testCase.parameters(1, :)), 'Start background parameter not set correctly');
            testCase.verifySize(background.backPars.paramsTable, [1, 8], 'background Parameters has wrong dimension');
            
            testCase.verifyEqual(string(background.backgrounds.typesTable{1, :}), ...
                                 string(testCase.backgrounds(1, :)), 'Start background parameter not set correctly');
            testCase.verifySize(background.backgrounds.typesTable, [1, 7], 'backgrounds has wrong dimension');
        end
        
        function testShowPrior(testCase)
            % Tests showPrior property
            testCase.verifyFalse(testCase.background.showPriors);
            testCase.background.showPriors = true;
            testCase.verifyTrue(testCase.background.showPriors);
            testCase.verifyTrue(testCase.background.backPars.showPriors);
            testCase.verifyError(@setShowPriors, invalidType.errorID);  % showPrior should be logical 
            function setShowPriors
                testCase.background.showPriors = 'a';
            end
        end
        
        function testGetBackgroundNames(testCase)
            % Tests getBackgroundNames returns correctly
            names = testCase.background.getBackgroundNames();
            testCase.verifyEqual(names, string(testCase.backgrounds(1, 1)), 'getBackgroundNames method not working');
            testCase.verifySize(names, [1, 1], 'background names has wrong dimension');

            testCase.background.backgrounds.typesTable = [testCase.background.backgrounds.typesTable; vertcat(testCase.backgrounds(2:end, :))];
            names = testCase.background.getBackgroundNames();
            testCase.verifyEqual(names, convertCharsToStrings(testCase.backgrounds(:, 1)), 'getBackgroundNames method not working');
            testCase.verifySize(names, [size(testCase.backgrounds, 1), 1], 'background names has wrong dimension');
        end

         function testGetBacksParNames(testCase)
            % Tests getBacksParNames returns correctly
            names = testCase.background.getBacksParNames();
            testCase.verifyEqual(names, string(testCase.parameters(1, 1)), 'getBacksParNames method not working');
            testCase.verifySize(names, [1, 1], 'background parameters names has wrong dimension');

            testCase.background.backPars.paramsTable = [testCase.background.backPars.paramsTable; vertcat(testCase.parameters(2:end, :))];
            names = testCase.background.getBacksParNames();
            testCase.verifyEqual(names, convertCharsToStrings(testCase.parameters(:, 1)), 'getBacksParNames method not working');
            testCase.verifySize(names, [size(testCase.parameters, 1), 1], 'background parameters names has wrong dimension');
         end

         function testAddBacksPar(testCase)
            % Checks that background parameter can be added
            testCase.background.addBacksPar(testCase.parameters{2, :});
            testCase.background.addBacksPar(testCase.parameters{3, :});
            testCase.verifySize(testCase.background.backPars.paramsTable, size(testCase.parameters), 'background parameter has wrong dimension');
            testCase.verifyEqual(testCase.background.backPars.paramsTable{:, 1}, ...
                                 convertCharsToStrings(testCase.parameters(:, 1)), 'addBacksPar method not working');
         end

         function testSetBacksPar(testCase)
            % Checks that background parameters can be modified
            testCase.background.backPars.paramsTable = [testCase.background.backPars.paramsTable; vertcat(testCase.parameters(2:end, :))];
            
            % Checks that background parameter value can be modified
            testCase.background.setBacksParValue('background par 1', 0.2325);
            testCase.verifyEqual(testCase.background.backPars.paramsTable{1, 3}, 0.2325, 'setBacksParValue method not working');
            testCase.background.setBacksParValue(2, 0.4);
            testCase.verifyEqual(testCase.background.backPars.paramsTable{2, 3}, 0.4, 'setBacksParValue method not working');
            
            % Checks that background parameter name can be modified
            testCase.background.setBacksParConstr('background par 1', 1, 2);
            testCase.verifyEqual(testCase.background.backPars.paramsTable{1, 2}, 1, 'setBacksParConstr method not working');
            testCase.verifyEqual(testCase.background.backPars.paramsTable{1, 4}, 2, 'setBacksParConstr method not working');
            testCase.background.setBacksParConstr(2, -0.2, 0.6);
            testCase.verifyEqual(testCase.background.backPars.paramsTable{2, 2}, -0.2, 'setBacksParConstr method not working');
            testCase.verifyEqual(testCase.background.backPars.paramsTable{2, 4}, 0.6, 'setBacksParName method not working');
                 
            % Checks that background parameter name can be modified
            testCase.background.setBacksParName('background par 1', 'back par 1');
            testCase.verifyEqual(testCase.background.backPars.paramsTable{1, 1}, "back par 1", 'setBacksParName method not working');
            testCase.background.setBacksParName(2, 'back par 2');
            testCase.verifyEqual(testCase.background.backPars.paramsTable{2, 1}, "back par 2", 'setBacksParName method not working');      

            % Checks that other background parameters can be modified
            testCase.background.setBacksPar(1, 'name', 'New back par', 'fit', true);
            testCase.verifyTrue(testCase.background.backPars.paramsTable{1, 5}, 'setBacksPar method not working');
            testCase.verifyEqual(testCase.background.backPars.paramsTable{1, 1}, "New back par", 'setBacksPar method not working');    
         end

         function testRemoveBacksPar(testCase)
            % Checks that background parameters can be removed
            testCase.background.backPars.paramsTable = [testCase.background.backPars.paramsTable; vertcat(testCase.parameters(2:end, :))];

            testCase.background.removeBacksPar(2);
            testCase.verifySize(testCase.background.backPars.paramsTable, [2, 8], 'background parameter has wrong dimension');
            testCase.verifyEqual(testCase.background.backPars.paramsTable{:, 1}, ["background par 1"; "background par 3"], 'removeBacksPar method not working');

            testCase.background.backPars.paramsTable = [testCase.background.backPars.paramsTable; vertcat(testCase.parameters(2, :))];
            testCase.background.removeBacksPar(1, 3);
            testCase.verifySize(testCase.background.backPars.paramsTable, [1, 8], 'background parameter has wrong dimension');
            testCase.verifyEqual(testCase.background.backPars.paramsTable{:, 1}, "background par 3", 'removeBacksPar method not working');
         end

         function testAddBackground(testCase)
            % Checks that background can be added
            testCase.background.backPars.paramsTable = [testCase.background.backPars.paramsTable; vertcat(testCase.parameters(2:end, :))];
            
            testCase.background.addBackground();
            testCase.verifyEqual(string(testCase.background.backgrounds.typesTable{end, :}),...
                                 string({'New background 1', 'constant', '', '', '', '', ''}), 'addBackground method not working');
            testCase.background.addBackground('New Res');
            testCase.verifyEqual(string(testCase.background.backgrounds.typesTable{end, :}),...
                                 string({'New Res', 'constant', '', '', '', '', ''}), 'addBackground method not working');
            testCase.background.addBackground(testCase.backgrounds{3, 1:5});
            testCase.verifyEqual(string(testCase.background.backgrounds.typesTable{end, :}),...
                                 string(testCase.backgrounds(3, :)), 'addBackground method not working');
            testCase.background.addBackground(testCase.backgrounds{4, :});
            testCase.verifyEqual(string(testCase.background.backgrounds.typesTable{end, :}),...
                                 string(testCase.backgrounds(4, :)), 'addBackground method not working');
            testCase.background.addBackground('background 5', 'function', 'function_name', 1, 3);
            testCase.verifyEqual(string(testCase.background.backgrounds.typesTable{end, :}),...
                                 ["background 5", "function", "function_name", "background par 1", "background par 3", "", ""], ...
                                 'addBackground method not working');
            testCase.verifyError(@() testCase.background.addBackground('New', 'fixed'), invalidOption.errorID);
            testCase.verifyError(@() testCase.background.addBackground('New', 'constant', 6), indexOutOfRange.errorID);
         end

         function testRemoveBackground(testCase)
            % Checks that background can be removed
            testCase.background.backgrounds.typesTable = [testCase.background.backgrounds.typesTable; vertcat(testCase.backgrounds(2:end, :))];

            testCase.background.removeBackground(3);
            testCase.verifyEqual(testCase.background.backgrounds.typesTable{:, 1}, ...
                                 ["background 1"; "background 2"; "background 4"], 'removeBacksPar method not working');
            testCase.background.removeBackground([1, 3]);
            testCase.verifyEqual(testCase.background.backgrounds.typesTable{:, 1}, "background 2", 'removeBacksPar method not working');  
         end

         function testSetBackgroundName(testCase)
            % Checks that background name can be modified
            testCase.background.backgrounds.typesTable = [testCase.background.backgrounds.typesTable; vertcat(testCase.backgrounds(2:end, :))];
            testCase.background.setBackgroundName(1, 'background one');
            testCase.verifyEqual(testCase.background.backgrounds.typesTable{1, 1}, ...
                                 "background one", 'setBackgroundName method not working');
            testCase.background.setBackgroundName(3, 'background three');
            testCase.verifyEqual(testCase.background.backgrounds.typesTable{3, 1}, ...
                                 "background three", 'setBackgroundName method not working');
            testCase.verifyError(@() testCase.background.setBackgroundName(2, 2), invalidType.errorID);
         end
         
         function testSetBackground(testCase)
            % Checks that background can be modified
            testCase.background.backgrounds.typesTable = [testCase.background.backgrounds.typesTable; vertcat(testCase.backgrounds(2:end, :))];

            testCase.background.setBackgroundValue(1, 1, 'back 1');
            testCase.verifyEqual(testCase.background.backgrounds.typesTable{1, 1}, "back 1", 'setBackgroundValue method not working');
            testCase.background.setBackgroundValue('back 1', 'name', 'background 1');
            testCase.verifyEqual(testCase.background.backgrounds.typesTable{1, 1}, "background 1", 'setBackgroundValue method not working');

            testCase.background.setBackgroundValue(1, 'type', 'constant');
            testCase.verifyEqual(testCase.background.backgrounds.typesTable{1, 2}, "constant", 'setBackgroundValue method not working');
            testCase.background.setBackgroundValue('background 1', 2, 'gaussian'); 
            testCase.verifyEqual(testCase.background.backgrounds.typesTable{1, 2}, "gaussian", 'setBackgroundValue method not working');
            testCase.verifyError(@() testCase.background.setBackgroundValue(2, 'type', 'random'), invalidOption.errorID);
            
            testCase.background.setBackgroundValue(2, 'Value 1', 'random');
            testCase.verifyEqual(testCase.background.backgrounds.typesTable{2, 3}, "random", 'setBackgroundValue method not working');
            testCase.background.setBackgroundValue('background 2', 3, 'background par 1');
            testCase.verifyEqual(testCase.background.backgrounds.typesTable{2, 3}, "background par 1", 'setBackgroundValue method not working');
            
            testCase.background.setBackgroundValue(2, 'Value 2', 'background par 1');
            testCase.verifyEqual(testCase.background.backgrounds.typesTable{2, 4}, "background par 1", 'setBackgroundValue method not working');
            testCase.verifyError(@() testCase.background.setBackgroundValue(2, 'Value 2', 'random'), nameNotRecognised.errorID);

         end

         function testDisplayBackgroundsObject(testCase)
            import matlab.unittest.constraints.ContainsSubstring
            % Check that the contents of the background are printed
            paramHeader = {'p', 'Name', 'Min', 'Value', 'Max', 'Fit?'};
            display = evalc('testCase.background.displayBackgroundsObject()');
            testCase.verifyNotEmpty(display, 'displayBackgroundsObject method not working');
            display = split(display, ["(a)", "(b)"]);  % splits background parameter table from background table
            testCase.verifyLength(display, 3);

            displayArray = textscan(display{2},'%s','Delimiter','\r','TextType','string');
            displayArray = strip(displayArray{1});
            % display table should be height of backPars table plus header and divider row
            testCase.verifyLength(displayArray, height(testCase.background.backPars.paramsTable) + 3);
            % Remove html tags used to format header then split table when
            % 2 or more spaces are found to avoid splitting names with single space
            displayHeader = eraseBetween(displayArray{2}, '<', '>', 'Boundaries','inclusive');
            displayHeader = regexp(displayHeader, '\s{2,}', 'split');
            testCase.verifyEqual(displayHeader, paramHeader);
            row = regexp(displayArray{4}, '\s{2,}', 'split');
            row = string(replace(row, '"', ''));
            testCase.verifyLength(row, length(paramHeader));
            testCase.verifyEqual(row, string({1, testCase.parameters{1, 1:5}}), 'displayBackgroundsObject method not working')

            paramHeader = {'p', 'Name', 'Type', 'Value 1', 'Value 2', 'Value 3', 'Value 4', 'Value 5'};
            displayArray = textscan(display{3},'%s','Delimiter','\r','TextType','string');
            displayArray = strip(displayArray{1});
            % display table should be height of background table plus header and divider row
            testCase.verifyLength(displayArray, height(testCase.background.backgrounds.typesTable) + 3);
            displayHeader = eraseBetween(displayArray{2}, '<', '>', 'Boundaries','inclusive');
            displayHeader = regexp(displayHeader, '\s{2,}', 'split');
            testCase.verifyEqual(displayHeader, paramHeader);
            row = regexp(displayArray{4}, '\s{2,}', 'split');
            row = string(replace(row, '"', ''));
            testCase.verifyLength(row, length(paramHeader));
            testCase.verifyEqual(row, string({1, testCase.backgrounds{1, :}}), 'displayBackgroundsObject method not working')

            paramHeader = {'p', 'Name', 'Min', 'Value', 'Max', 'Fit?', 'Prior Type', 'mu', 'sigma'};
            testCase.background.showPriors = true;
            display = evalc('testCase.background.displayBackgroundsObject()');
            display = split(display, ["(a)", "(b)"]); 
            displayArray = textscan(display{2},'%s','Delimiter','\r','TextType','string');
            displayArray = strip(displayArray{1});
            displayHeader = eraseBetween(displayArray{2}, '<', '>', 'Boundaries','inclusive');
            displayHeader = regexp(displayHeader, '\s{2,}', 'split');
            testCase.verifyEqual(displayHeader, paramHeader);
            row = regexp(displayArray{4}, '\s{2,}', 'split');
            row = string(replace(row, '"', ''));
            testCase.verifyLength(row, length(paramHeader));
            testCase.verifyEqual(row, string({1, testCase.parameters{1, :}}), 'displayBackgroundsObject method not working')
         end
         
         function testToStruct(testCase)
            % Checks that class to struct works correctly
            expected.backParNames =  {'background par 1'};
            expected.backParConstr = {[0.0100 0.0500]};
            expected.backParVals = 0.0300;
            expected.backParFitYesNo = 0;
            expected.nBackPars = 1;
            expected.backsPriors= {{'background par 1', 'uniform', 0, Inf}};
            expected.backgroundNames = "background 1";
            expected.backgroundTypes = "gaussian";
            expected.backgroundValues = {"background par 1", "", "", "", ""};
            testCase.verifyEqual(testCase.background.toStruct(), expected, 'toStruct method not working');

            testCase.background.backgrounds.typesTable = [testCase.background.backgrounds.typesTable; vertcat(testCase.backgrounds(2:3, :))];
            testCase.background.backPars.paramsTable = [testCase.background.backPars.paramsTable; vertcat(testCase.parameters(2:3, :))];

            expected.backParNames =  {'background par 1', 'background par 2', 'background par 3'};
            expected.backParConstr = {[0.0100 0.0500], [0.1000 1], [0.2000 1.1000]};
            expected.backParVals = [0.0300, 0.1900, 0.1700];
            expected.backParFitYesNo = [0, 1, 0];
            expected.nBackPars = 3;
            expected.backsPriors= {{'background par 1', 'uniform', 0, Inf};... 
                                      {'background par 2', 'gaussian', -1, 1};... 
                                      {'background par 3', 'uniform', 0, Inf}};
            expected.backgroundNames = ["background 1"; "background 2"; "background 3"];
            expected.backgroundTypes = ["gaussian"; "constant"; "function"];
            expected.backgroundValues = {"background par 1", "", "", "", ""; "background par 2", "", "", "", "";...
                                         "function_name", "background par 1", "background par 2", "", ""};
            testCase.verifyEqual(testCase.background.toStruct(), expected, 'toStruct method not working');
         end
    end
end
