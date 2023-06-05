 classdef testBackgroundsClass < matlab.unittest.TestCase   
    
   properties
      parameters
      backgrounds
      background
   end

   methods(TestMethodSetup)
      function createBackground(testCase)
         params = parametersClass(testCase.parameters{1, :});
         testCase.background = backgroundsClass(params, testCase.backgrounds(1, :));
      end
   end

   methods(TestClassSetup)
      function createBackgrounds(testCase)
         testCase.parameters = {
                  % Name               min   val   max  fit? 'Prior Type','mu','sigma'
                  'background par 1', 0.01, 0.03, 0.05, false, priorTypes.Uniform.value, 0, Inf;
                  'background par 2', 0.1, 0.19, 1.0, true, priorTypes.Gaussian.value, -1, 1;
                  'background par 3', 0.2, 0.17, 1.1, false, priorTypes.Uniform.value, 0, Inf;
                  };
         testCase.backgrounds = {
                  'background 1', allowedTypes.Constant.value, 'background par 1', '', '', '', '';
                  'background 2', allowedTypes.Constant.value, 'background par 2', '', '', '', '';
                  'background 3', allowedTypes.Function.value, 'function_name', 'background par 1', 'background par 2', '', '';
                  'background 4', allowedTypes.Data.value, '', '', '', '', '';
                  };
      end
   end

   methods (Test)
      function testCreation(testCase)
         % Tests background class can be created and the start parameters is set correctly
         params = parametersClass(testCase.parameters{1, :});
         params.varTable = [params.varTable; vertcat(testCase.parameters(2:end, :))];
         
         background = backgroundsClass(params, testCase.backgrounds(1, :));
         
         testCase.verifyEqual(string(background.backPars.varTable{1, :}), ...
                              string(testCase.parameters(1, :)), 'Start background parameter not set correctly');
         testCase.verifySize(background.backPars.varTable, [3, 8], 'background Parameters has wrong dimension');
         
         testCase.verifyEqual(string(background.backgrounds.varTable{1, :}), ...
                              string(testCase.backgrounds(1, :)), 'Start background parameter not set correctly');
         testCase.verifySize(background.backgrounds.varTable, [1, 7], 'backgrounds has wrong dimension');
      end

      function testShowPrior(testCase)
         % Tests showPrior property
         testCase.verifyFalse(testCase.background.showPriors);
         testCase.verifyFalse(testCase.background.backPars.showPriors);
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

         testCase.background.backgrounds.varTable = [testCase.background.backgrounds.varTable; vertcat(testCase.backgrounds(2:end, :))];
         names = testCase.background.getBackgroundNames();
         testCase.verifyEqual(names, convertCharsToStrings(testCase.backgrounds(:, 1)), 'getBackgroundNames method not working');
         testCase.verifySize(names, [size(testCase.backgrounds, 1), 1], 'background names has wrong dimension');
      end

      function testAddBackground(testCase)
         % Checks that background can be added
         testCase.background.backPars.varTable = [testCase.background.backPars.varTable; vertcat(testCase.parameters(2:end, :))];
         
         testCase.background.addBackground();
         testCase.verifyEqual(string(testCase.background.backgrounds.varTable{end, :}),...
                              string({'New background 2', allowedTypes.Constant.value, '', '', '', '', ''}), 'addBackground method not working');
         testCase.background.addBackground('New Back');
         testCase.verifyEqual(string(testCase.background.backgrounds.varTable{end, :}),...
                              string({'New Back', allowedTypes.Constant.value, '', '', '', '', ''}), 'addBackground method not working');
         testCase.background.addBackground(testCase.backgrounds{3, 1:5});
         testCase.verifyEqual(string(testCase.background.backgrounds.varTable{end, :}),...
                              string(testCase.backgrounds(3, :)), 'addBackground method not working');
         testCase.background.addBackground(testCase.backgrounds{4, :});
         testCase.verifyEqual(string(testCase.background.backgrounds.varTable{end, :}),...
                              string(testCase.backgrounds(4, :)), 'addBackground method not working');
         testCase.background.addBackground('background 5', allowedTypes.Function, 'function_name', 1, 3);
         testCase.verifyEqual(string(testCase.background.backgrounds.varTable{end, :}),...
                              ["background 5", string(allowedTypes.Function.value), "function_name", "background par 1", "background par 3", "", ""], ...
                              'addBackground method not working');
         testCase.verifyError(@() testCase.background.addBackground('New', 'fixed'), invalidOption.errorID);
         testCase.verifyError(@() testCase.background.addBackground('New', allowedTypes.Constant), invalidNumberOfInputs.errorID);
         testCase.verifyError(@() testCase.background.addBackground('New', allowedTypes.Constant.value, 6), indexOutOfRange.errorID);
      end

      function testRemoveBackground(testCase)
         % Checks that background can be removed
         testCase.background.backgrounds.varTable = [testCase.background.backgrounds.varTable; vertcat(testCase.backgrounds(2:end, :))];

         testCase.background.removeBackground(3);
         testCase.verifyEqual(testCase.background.backgrounds.varTable{:, 1}, ...
                              ["background 1"; "background 2"; "background 4"], 'removeBacksPar method not working');
         testCase.background.removeBackground([1, 3]);
         testCase.verifyEqual(testCase.background.backgrounds.varTable{:, 1}, "background 2", 'removeBacksPar method not working');  
      end

      function testSetBackgroundName(testCase)
         % Checks that background name can be modified
         testCase.background.backgrounds.varTable = [testCase.background.backgrounds.varTable; vertcat(testCase.backgrounds(2:end, :))];
         testCase.background.setBackgroundName(1, 'background one');
         testCase.verifyEqual(testCase.background.backgrounds.varTable{1, 1}, ...
                              "background one", 'setBackgroundName method not working');
         testCase.background.setBackgroundName(3, 'background three');
         testCase.verifyEqual(testCase.background.backgrounds.varTable{3, 1}, ...
                              "background three", 'setBackgroundName method not working');
         testCase.verifyError(@() testCase.background.setBackgroundName(2, 2), invalidType.errorID);
      end

      function testSetBackground(testCase)
         % Checks that background can be modified
         testCase.background.backgrounds.varTable = [testCase.background.backgrounds.varTable; vertcat(testCase.backgrounds(2:end, :))];
         testCase.background.backPars.varTable = [testCase.background.backPars.varTable; vertcat(testCase.parameters(2:end, :))];
         
         testCase.background.setBackground('Background 1', 'name', 'Back 1');
         testCase.verifyEqual(testCase.background.backgrounds.varTable{1, 1}, "Back 1", 'setBackground method not working');
         testCase.background.setBackground(1, 'name', 'Background 1');
         testCase.verifyEqual(testCase.background.backgrounds.varTable{1, 1}, "Background 1", 'setBackground method not working');

         testCase.background.setBackground(1, 'type', allowedTypes.Constant.value);
         testCase.verifyEqual(testCase.background.backgrounds.varTable{1, 2}, string(allowedTypes.Constant.value), 'setBackground method not working');
         testCase.background.setBackground('Background 1', 'type', allowedTypes.Function); 
         testCase.verifyEqual(testCase.background.backgrounds.varTable{1, 2}, string(allowedTypes.Function.value), 'setBackground method not working');
         testCase.verifyError(@() testCase.background.setBackground(2, 'type', 'random'), invalidOption.errorID);
         
         testCase.background.setBackground(3, 'Value1', 'random');
         testCase.verifyEqual(testCase.background.backgrounds.varTable{3, 3}, "random", 'setBackground method not working');
         testCase.background.setBackground('Background 3', 'Value1', 'Background par 1');
         testCase.verifyEqual(testCase.background.backgrounds.varTable{3, 3}, "Background par 1", 'setBackground method not working');
         
         testCase.background.setBackground(2, 'Value2', 'Background par 1');
         testCase.verifyEqual(testCase.background.backgrounds.varTable{2, 4}, "Background par 1", 'setBackground method not working');
         testCase.verifyError(@() testCase.background.setBackground(2, 'Value2', 'random'), nameNotRecognised.errorID);
         testCase.verifyError(@() testCase.background.setBackground(5, 'Value2', 'random'), indexOutOfRange.errorID);
         testCase.verifyError(@() testCase.background.setBackground(true, 'Value2', 'random'), invalidType.errorID);
         
         testCase.background.setBackground(3, 'name', 'New Name', 'type', allowedTypes.Constant, 'value1', 'Background par 3', 'value2', '');
         testCase.verifyEqual(testCase.background.backgrounds.varTable{3, 1}, "New Name", 'setBackground method not working');
         testCase.verifyEqual(testCase.background.backgrounds.varTable{3, 2}, string(allowedTypes.Constant.value), 'setBackground method not working');
         testCase.verifyEqual(testCase.background.backgrounds.varTable{3, 3}, "Background par 3", 'setBackground method not working');
         testCase.verifyEqual(testCase.background.backgrounds.varTable{3, 4}, "", 'setBackground method not working');
      end

      function testDisplayBackgroundsObject(testCase)
         % Check that the contents of the background are printed
         paramHeader = {'p', 'Name', 'Min', 'Value', 'Max', 'Fit?'};
         display = evalc('testCase.background.displayBackgroundsObject()');
         testCase.verifyNotEmpty(display, 'displayBackgroundsObject method not working');
         display = split(display, ["(a)", "(b)"]);  % splits background parameter table from background table
         testCase.verifyLength(display, 3);

         displayArray = textscan(display{2},'%s','Delimiter','\r','TextType','string');
         displayArray = strip(displayArray{1});
         % display table should be height of backPars table plus header and divider row
         testCase.verifyLength(displayArray, height(testCase.background.backPars.varTable) + 3);
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
         testCase.verifyLength(displayArray, height(testCase.background.backgrounds.varTable) + 3);
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
         expected.backsPriors= {{'background par 1', priorTypes.Uniform.value, 0, Inf}};
         expected.backgroundNames = "background 1";
         expected.backgroundTypes = string(allowedTypes.Constant.value);
         expected.backgroundValues = {"background par 1", "", "", "", ""};
         testCase.verifyEqual(testCase.background.toStruct(), expected, 'toStruct method not working');

         testCase.background.backgrounds.varTable = [testCase.background.backgrounds.varTable; vertcat(testCase.backgrounds(2:3, :))];
         testCase.background.backPars.varTable = [testCase.background.backPars.varTable; vertcat(testCase.parameters(2:3, :))];

         expected.backParNames =  {'background par 1', 'background par 2', 'background par 3'};
         expected.backParConstr = {[0.0100 0.0500], [0.1000 1], [0.2000 1.1000]};
         expected.backParVals = [0.0300, 0.1900, 0.1700];
         expected.backParFitYesNo = [0, 1, 0];
         expected.nBackPars = 3;
         expected.backsPriors= {{'background par 1', priorTypes.Uniform.value, 0, Inf};... 
                                {'background par 2', priorTypes.Gaussian.value, -1, 1};... 
                                {'background par 3', priorTypes.Uniform.value, 0, Inf}};
         expected.backgroundNames = ["background 1"; "background 2"; "background 3"];
         expected.backgroundTypes = [string(allowedTypes.Constant.value); string(allowedTypes.Constant.value); 
                                     string(allowedTypes.Function.value)];
         expected.backgroundValues = {"background par 1", "", "", "", ""; "background par 2", "", "", "", "";...
                                    "function_name", "background par 1", "background par 2", "", ""};
         testCase.verifyEqual(testCase.background.toStruct(), expected, 'toStruct method not working');
      end
   end
end
