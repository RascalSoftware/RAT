classdef testResolutionsClass < matlab.unittest.TestCase   
    
    properties
        parameters
        resolutions
        resolution
    end

    methods(TestMethodSetup)
        function createResolution(testCase)
            testCase.resolution = resolutionsClass(testCase.parameters(1, :), testCase.resolutions(1, :));
        end
    end

    methods(TestClassSetup)
        function createResolutions(testCase)
            testCase.parameters = {
                    % Name               min   val   max  fit? 'Prior Type','mu','sigma'
                    'Resolution par 1', 0.01, 0.03, 0.05, false, 'uniform', 0, Inf;
                    'Resolution par 2', 0.1, 0.19, 1.0, true, 'gaussian', -1, 1;
                    'Resolution par 3', 0.2, 0.17, 1.1, false, 'uniform', 0, Inf;
                    };
            testCase.resolutions = {
                    'Resolution 1', 'gaussian', 'Resolution par 1', '', '', '', '';
                    'Resolution 2', 'constant', 'Resolution par 2', '', '', '', '';
                    'Resolution 3', 'function', 'function_name', 'Resolution par 1', 'Resolution par 2', '', '';
                    'Resolution 4', 'data', '', '', '', '', '';
                    };
        end
    end

    methods (Test)
        function testCreation(testCase)
            % Tests resolution class can be created and the start parameters is set correctly  
            resolution = resolutionsClass(testCase.parameters(1, :), testCase.resolutions(1, :));
            testCase.verifyEqual(string(resolution.resolPars.paramsTable{1, :}), ...
                                 string(testCase.parameters(1, :)), 'Start resolution parameter not set correctly');
            testCase.verifySize(resolution.resolPars.paramsTable, [1, 8], 'Resolution Parameters has wrong dimension');
            
            testCase.verifyEqual(string(resolution.resolutions.typesTable{1, :}), ...
                                 string(testCase.resolutions(1, :)), 'Start resolution parameter not set correctly');
            testCase.verifySize(resolution.resolutions.typesTable, [1, 7], 'Resolutions has wrong dimension');
        end
        
        function testShowPrior(testCase)
            % Tests showPrior property
            testCase.verifyFalse(testCase.resolution.showPriors);
            testCase.resolution.showPriors = true;
            testCase.verifyTrue(testCase.resolution.showPriors);
            testCase.verifyTrue(testCase.resolution.resolPars.showPriors);
            testCase.verifyError(@setShowPriors, invalidType.errorID);  % showPrior should be logical 
            function setShowPriors
                testCase.resolution.showPriors = 'a';
            end
        end
        
        function testGetResolNames(testCase)
            % Tests getResolNames returns correctly
            names = testCase.resolution.getResolNames();
            testCase.verifyEqual(names, string(testCase.resolutions(1, 1)), 'getResolNames method not working');
            testCase.verifySize(names, [1, 1], 'Resolution names has wrong dimension');

            testCase.resolution.resolutions.typesTable = [testCase.resolution.resolutions.typesTable; vertcat(testCase.resolutions(2:end, :))];
            names = testCase.resolution.getResolNames();
            testCase.verifyEqual(names, convertCharsToStrings(testCase.resolutions(:, 1)), 'getResolNames method not working');
            testCase.verifySize(names, [size(testCase.resolutions, 1), 1], 'Resolution names has wrong dimension');
        end

         function testGetResolParNames(testCase)
            % Tests getResolParNames returns correctly
            names = testCase.resolution.getResolParNames();
            testCase.verifyEqual(names, string(testCase.parameters(1, 1)), 'getResolParNames method not working');
            testCase.verifySize(names, [1, 1], 'Resolution parameters names has wrong dimension');

            testCase.resolution.resolPars.paramsTable = [testCase.resolution.resolPars.paramsTable; vertcat(testCase.parameters(2:end, :))];
            names = testCase.resolution.getResolParNames();
            testCase.verifyEqual(names, convertCharsToStrings(testCase.parameters(:, 1)), 'getResolParNames method not working');
            testCase.verifySize(names, [size(testCase.parameters, 1), 1], 'Resolution parameters names has wrong dimension');
         end

         function testAddResolPar(testCase)
            % Checks that resolution parameter can be added
            testCase.resolution.addResolPar(testCase.parameters{2, :});
            testCase.resolution.addResolPar(testCase.parameters{3, :});
            testCase.verifySize(testCase.resolution.resolPars.paramsTable, size(testCase.parameters), 'resolution parameter has wrong dimension');
            testCase.verifyEqual(testCase.resolution.resolPars.paramsTable{:, 1}, ...
                                 convertCharsToStrings(testCase.parameters(:, 1)), 'addResolPar method not working');
         end

         function testSetResolPar(testCase)
            % Checks that resolution parameters can be modified
            testCase.resolution.resolPars.paramsTable = [testCase.resolution.resolPars.paramsTable; vertcat(testCase.parameters(2:end, :))];
            
            % Checks that resolution parameter value can be modified
            testCase.resolution.setResolParValue('Resolution par 1', 0.2325);
            testCase.verifyEqual(testCase.resolution.resolPars.paramsTable{1, 3}, 0.2325, 'setResolParValue method not working');
            testCase.resolution.setResolParValue(2, 0.4);
            testCase.verifyEqual(testCase.resolution.resolPars.paramsTable{2, 3}, 0.4, 'setResolParValue method not working');
            
            % Checks that resolution parameter name can be modified
            testCase.resolution.setResolParConstr('Resolution par 1', 1, 2);
            testCase.verifyEqual(testCase.resolution.resolPars.paramsTable{1, 2}, 1, 'setResolParConstr method not working');
            testCase.verifyEqual(testCase.resolution.resolPars.paramsTable{1, 4}, 2, 'setResolParConstr method not working');
            testCase.resolution.setResolParConstr(2, -0.2, 0.6);
            testCase.verifyEqual(testCase.resolution.resolPars.paramsTable{2, 2}, -0.2, 'setResolParConstr method not working');
            testCase.verifyEqual(testCase.resolution.resolPars.paramsTable{2, 4}, 0.6, 'setResolParName method not working');
                 
            % Checks that resolution parameter name can be modified
            testCase.resolution.setResolParName('Resolution par 1', 'Resol par 1');
            testCase.verifyEqual(testCase.resolution.resolPars.paramsTable{1, 1}, "Resol par 1", 'setResolParName method not working');
            testCase.resolution.setResolParName(2, 'Resol par 2');
            testCase.verifyEqual(testCase.resolution.resolPars.paramsTable{2, 1}, "Resol par 2", 'setResolParName method not working');      

            % Checks that other resolution parameters can be modified
            testCase.resolution.setResolPar(1, 'name', 'New resol par', 'fit', true);
            testCase.verifyTrue(testCase.resolution.resolPars.paramsTable{1, 5}, 'setResolPar method not working');
            testCase.verifyEqual(testCase.resolution.resolPars.paramsTable{1, 1}, "New resol par", 'setResolPar method not working');    
         end

         function testRemoveResolPar(testCase)
            % Checks that resolution parameters can be removed
            testCase.resolution.resolPars.paramsTable = [testCase.resolution.resolPars.paramsTable; vertcat(testCase.parameters(2:end, :))];

            testCase.resolution.removeResolPar(2);
            testCase.verifySize(testCase.resolution.resolPars.paramsTable, [2, 8], 'resolution parameter has wrong dimension');
            testCase.verifyEqual(testCase.resolution.resolPars.paramsTable{:, 1}, ["Resolution par 1"; "Resolution par 3"], 'removeResolPar method not working');

            testCase.resolution.resolPars.paramsTable = [testCase.resolution.resolPars.paramsTable; vertcat(testCase.parameters(2, :))];
            testCase.resolution.removeResolPar(1, 3);
            testCase.verifySize(testCase.resolution.resolPars.paramsTable, [1, 8], 'resolution parameter has wrong dimension');
            testCase.verifyEqual(testCase.resolution.resolPars.paramsTable{:, 1}, "Resolution par 3", 'removeResolPar method not working');
         end

         function testAddResolution(testCase)
            % Checks that resolution can be added
            testCase.resolution.resolPars.paramsTable = [testCase.resolution.resolPars.paramsTable; vertcat(testCase.parameters(2:end, :))];
            
            testCase.resolution.addResolution();
            testCase.verifyEqual(string(testCase.resolution.resolutions.typesTable{end, :}),...
                                 string({'New Resolution 1', 'constant', '', '', '', '', ''}), 'addResolution method not working');
            testCase.resolution.addResolution('New Res');
            testCase.verifyEqual(string(testCase.resolution.resolutions.typesTable{end, :}),...
                                 string({'New Res', 'constant', '', '', '', '', ''}), 'addResolution method not working');
            testCase.resolution.addResolution(testCase.resolutions{3, 1:5});
            testCase.verifyEqual(string(testCase.resolution.resolutions.typesTable{end, :}),...
                                 string(testCase.resolutions(3, :)), 'addResolution method not working');
            testCase.resolution.addResolution(testCase.resolutions{4, :});
            testCase.verifyEqual(string(testCase.resolution.resolutions.typesTable{end, :}),...
                                 string(testCase.resolutions(4, :)), 'addResolution method not working');
            testCase.resolution.addResolution('Resolution 5', 'function', 'function_name', 1, 3);
            testCase.verifyEqual(string(testCase.resolution.resolutions.typesTable{end, :}),...
                                 ["Resolution 5", "function", "function_name", "Resolution par 1", "Resolution par 3", "", ""], ...
                                 'addResolution method not working');
            testCase.verifyError(@() testCase.resolution.addResolution('New', 'fixed'), invalidOption.errorID);
            testCase.verifyError(@() testCase.resolution.addResolution('New', 'constant', 6), indexOutOfRange.errorID);
         end

         function testRemoveResolution(testCase)
            % Checks that resolution can be removed
            testCase.resolution.resolutions.typesTable = [testCase.resolution.resolutions.typesTable; vertcat(testCase.resolutions(2:end, :))];

            testCase.resolution.removeResolution(3);
            testCase.verifyEqual(testCase.resolution.resolutions.typesTable{:, 1}, ...
                                 ["Resolution 1"; "Resolution 2"; "Resolution 4"], 'removeResolPar method not working');
            testCase.resolution.removeResolution([1, 3]);
            testCase.verifyEqual(testCase.resolution.resolutions.typesTable{:, 1}, "Resolution 2", 'removeResolPar method not working');  
         end
         
         function testSetResolution(testCase)
            % Checks that resolution can be modified
            testCase.resolution.resolutions.typesTable = [testCase.resolution.resolutions.typesTable; vertcat(testCase.resolutions(2:end, :))];

            testCase.resolution.setResolutionValue(1, 1, 'Resol 1');
            testCase.verifyEqual(testCase.resolution.resolutions.typesTable{1, 1}, "Resol 1", 'setResolutionValue method not working');
            testCase.resolution.setResolutionValue('Resol 1', 'name', 'Resolution 1');
            testCase.verifyEqual(testCase.resolution.resolutions.typesTable{1, 1}, "Resolution 1", 'setResolutionValue method not working');

            testCase.resolution.setResolutionValue(1, 'type', 'constant');
            testCase.verifyEqual(testCase.resolution.resolutions.typesTable{1, 2}, "constant", 'setResolutionValue method not working');
            testCase.resolution.setResolutionValue('Resolution 1', 2, 'gaussian'); 
            testCase.verifyEqual(testCase.resolution.resolutions.typesTable{1, 2}, "gaussian", 'setResolutionValue method not working');
            testCase.verifyError(@() testCase.resolution.setResolutionValue(2, 'type', 'random'), invalidOption.errorID);
            
            testCase.resolution.setResolutionValue(2, 'Value 1', 'random');
            testCase.verifyEqual(testCase.resolution.resolutions.typesTable{2, 3}, "random", 'setResolutionValue method not working');
            testCase.resolution.setResolutionValue('Resolution 2', 3, 'Resolution par 1');
            testCase.verifyEqual(testCase.resolution.resolutions.typesTable{2, 3}, "Resolution par 1", 'setResolutionValue method not working');
            
            testCase.resolution.setResolutionValue(2, 'Value 2', 'Resolution par 1');
            testCase.verifyEqual(testCase.resolution.resolutions.typesTable{2, 4}, "Resolution par 1", 'setResolutionValue method not working');
            testCase.verifyError(@() testCase.resolution.setResolutionValue(2, 'Value 2', 'random'), nameNotRecognised.errorID);
         end

         function testDisplayResolutionsObject(testCase)
            import matlab.unittest.constraints.ContainsSubstring
            % Check that the contents of the resolution are printed
            paramHeader = {'p', 'Name', 'Min', 'Value', 'Max', 'Fit?'};
            display = evalc('testCase.resolution.displayResolutionsObject()');
            testCase.verifyNotEmpty(display, 'displayResolutionsObject method not working');
            display = split(display, ["(a)", "(b)"]);  % splits resolution parameter table from resolution table
            testCase.verifyLength(display, 3);

            displayArray = textscan(display{2},'%s','Delimiter','\r','TextType','string');
            displayArray = strip(displayArray{1});
            % display table should be height of resolPars table plus header and divider row
            testCase.verifyLength(displayArray, height(testCase.resolution.resolPars.paramsTable) + 3);
            % Remove html tags used to format header then split table when
            % 2 or more spaces are found to avoid splitting names with single space
            displayHeader = eraseBetween(displayArray{2}, '<', '>', 'Boundaries','inclusive');
            displayHeader = regexp(displayHeader, '\s{2,}', 'split');
            testCase.verifyEqual(displayHeader, paramHeader);
            row = regexp(displayArray{4}, '\s{2,}', 'split');
            row = string(replace(row, '"', ''));
            testCase.verifyLength(row, length(paramHeader));
            testCase.verifyEqual(row, string({1, testCase.parameters{1, 1:5}}), 'displayResolutionsObject method not working')

            paramHeader = {'p', 'Name', 'Type', 'Value 1', 'Value 2', 'Value 3', 'Value 4', 'Value 5'};
            displayArray = textscan(display{3},'%s','Delimiter','\r','TextType','string');
            displayArray = strip(displayArray{1});
            % display table should be height of resolution table plus header and divider row
            testCase.verifyLength(displayArray, height(testCase.resolution.resolutions.typesTable) + 3);
            displayHeader = eraseBetween(displayArray{2}, '<', '>', 'Boundaries','inclusive');
            displayHeader = regexp(displayHeader, '\s{2,}', 'split');
            testCase.verifyEqual(displayHeader, paramHeader);
            row = regexp(displayArray{4}, '\s{2,}', 'split');
            row = string(replace(row, '"', ''));
            testCase.verifyLength(row, length(paramHeader));
            testCase.verifyEqual(row, string({1, testCase.resolutions{1, :}}), 'displayResolutionsObject method not working')

            paramHeader = {'p', 'Name', 'Min', 'Value', 'Max', 'Fit?', 'Prior Type', 'mu', 'sigma'};
            testCase.resolution.showPriors = true;
            display = evalc('testCase.resolution.displayResolutionsObject()');
            display = split(display, ["(a)", "(b)"]); 
            displayArray = textscan(display{2},'%s','Delimiter','\r','TextType','string');
            displayArray = strip(displayArray{1});
            displayHeader = eraseBetween(displayArray{2}, '<', '>', 'Boundaries','inclusive');
            displayHeader = regexp(displayHeader, '\s{2,}', 'split');
            testCase.verifyEqual(displayHeader, paramHeader);
            row = regexp(displayArray{4}, '\s{2,}', 'split');
            row = string(replace(row, '"', ''));
            testCase.verifyLength(row, length(paramHeader));
            testCase.verifyEqual(row, string({1, testCase.parameters{1, :}}), 'displayResolutionsObject method not working')
         end
         
         function testToStruct(testCase)
            % Checks that class to struct works correctly
            expected.resolParNames =  {'Resolution par 1'};
            expected.resolParConstr = {[0.0100 0.0500]};
            expected.resolPars = 0.0300;
            expected.resolFitYesNo = 0;
            expected.nResolPars = 1;
            expected.resolParPriors= {{'Resolution par 1', 'uniform', 0, Inf}};
            expected.resolutionNames = "Resolution 1";
            expected.resolutionTypes = "gaussian";
            expected.resolutionValues = {"Resolution par 1", "", "", "", ""};
            testCase.verifyEqual(testCase.resolution.toStruct(), expected, 'toStruct method not working');

            testCase.resolution.resolutions.typesTable = [testCase.resolution.resolutions.typesTable; vertcat(testCase.resolutions(2:3, :))];
            testCase.resolution.resolPars.paramsTable = [testCase.resolution.resolPars.paramsTable; vertcat(testCase.parameters(2:3, :))];

            expected.resolParNames =  {'Resolution par 1', 'Resolution par 2', 'Resolution par 3'};
            expected.resolParConstr = {[0.0100 0.0500], [0.1000 1], [0.2000 1.1000]};
            expected.resolPars = [0.0300, 0.1900, 0.1700];
            expected.resolFitYesNo = [0, 1, 0];
            expected.nResolPars = 3;
            expected.resolParPriors= {{'Resolution par 1', 'uniform', 0, Inf};... 
                                      {'Resolution par 2', 'gaussian', -1, 1};... 
                                      {'Resolution par 3', 'uniform', 0, Inf}};
            expected.resolutionNames = ["Resolution 1"; "Resolution 2"; "Resolution 3"];
            expected.resolutionTypes = ["gaussian"; "constant"; "function"];
            expected.resolutionValues = {"Resolution par 1", "", "", "", ""; "Resolution par 2", "", "", "", "";...
                                         "function_name", "Resolution par 1", "Resolution par 2", "", ""};
            testCase.verifyEqual(testCase.resolution.toStruct(), expected, 'toStruct method not working');
         end
    end
end
