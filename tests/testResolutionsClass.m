classdef testResolutionsClass < matlab.unittest.TestCase   
    
    properties
        parameters
        resolutions
        resolution
        names
    end

    methods(TestMethodSetup)
        function createResolution(testCase)
            params = parametersClass(testCase.parameters{1, :});
            testCase.resolution = resolutionsClass(params, testCase.resolutions(1, :));
        end
    end

    methods(TestClassSetup)
        function createResolutions(testCase)
            testCase.parameters = {
                    % Name               min   val   max  fit? 'Prior Type','mu','sigma'
                    'Resolution param 1', 0.01, 0.03, 0.05, false, priorTypes.Uniform.value, 0, Inf;
                    'Resolution param 2', 0.1, 0.19, 1.0, true, priorTypes.Gaussian.value, -1, 1;
                    'Resolution param 3', 0.2, 0.17, 1.1, false, priorTypes.Uniform.value, 0, Inf;
                    };
            testCase.resolutions = {
                    'Resolution 1', allowedTypes.Constant.value, 'Resolution param 1', '', '', '', '', '';
                    'Resolution 2', allowedTypes.Constant.value, 'Resolution param 2', '', '', '', '', '';
                    % Restore this when function resolutions are implemented
                    %'Resolution 3', allowedTypes.Function.value, 'function_name', 'Resolution param 1', 'Resolution param 2', '', '', '';
                    'Resolution 3', allowedTypes.Data.value, '', '', '', '', '', '';
                    };
        end

        function createTestNames(testCase)
          testCase.names.customFileNames = 'function_name';
          testCase.names.dataNames = '';
        end
    end

    methods (Test)
        function testCreation(testCase)
            % Tests resolution class can be created and the start parameters is set correctly
            params = parametersClass(testCase.parameters{1, :});
            params.varTable = [params.varTable; vertcat(testCase.parameters(2:end, :))];
            
            testResolution = resolutionsClass(params, testCase.resolutions(1, :));
            testCase.verifyEqual(string(testResolution.resolutionParams.varTable{1, :}), ...
                                 string(testCase.parameters(1, :)), 'Start resolution parameter not set correctly');
            testCase.verifySize(testResolution.resolutionParams.varTable, [3, 8], 'Resolution Parameters has wrong dimension');
            
            testCase.verifyEqual(string(testResolution.resolutions.varTable{1, :}), ...
                                 string(testCase.resolutions(1, :)), 'Start resolution parameter not set correctly');
            testCase.verifySize(testResolution.resolutions.varTable, [1, 8], 'Resolutions has wrong dimension');
        end
        
        function testGetNames(testCase)
            % Tests getNames returns correctly
            resolutionNames = testCase.resolution.getNames();
            testCase.verifyEqual(resolutionNames, string(testCase.resolutions(1, 1)), 'getNames method not working');
            testCase.verifySize(resolutionNames, [1, 1], 'Resolution names has wrong dimension');

            testCase.resolution.resolutions.varTable = [testCase.resolution.resolutions.varTable; vertcat(testCase.resolutions(2:end, :))];
            resolutionNames = testCase.resolution.getNames();
            testCase.verifyEqual(resolutionNames, convertCharsToStrings(testCase.resolutions(:, 1)), 'getNames method not working');
            testCase.verifySize(resolutionNames, [size(testCase.resolutions, 1), 1], 'Resolution names has wrong dimension');
        end

        function testAddResolution(testCase)
            % Checks that resolution can be added
            testCase.resolution.resolutionParams.varTable = [testCase.resolution.resolutionParams.varTable; vertcat(testCase.parameters(2:end, :))];
            
            testCase.resolution.addResolution();
            testCase.verifyEqual(string(testCase.resolution.resolutions.varTable{end, :}),...
                                    string({'New Resolution 2', allowedTypes.Constant.value, '', '', '', '', '', ''}), 'addResolution method not working');
            testCase.resolution.addResolution('New Resolution');
            testCase.verifyEqual(string(testCase.resolution.resolutions.varTable{end, :}),...
                                    string({'New Resolution', allowedTypes.Constant.value, '', '', '', '', '', ''}), 'addResolution method not working');
            testCase.resolution.addResolution(testCase.resolutions{3, 1:5});
            testCase.verifyEqual(string(testCase.resolution.resolutions.varTable{end, :}),...
                                    string(testCase.resolutions(3, :)), 'addResolution method not working');
            % testCase.resolution.addResolution(testCase.resolutions{4, :});
            % testCase.verifyEqual(string(testCase.resolution.resolutions.varTable{end, :}),...
            %                         string(testCase.resolutions(4, :)), 'addResolution method not working');
            % testCase.resolution.addResolution('Resolution 5', allowedTypes.Function, 'function_name', 1, 3);
            % testCase.verifyEqual(string(testCase.resolution.resolutions.varTable{end, :}),...
            %                         ["Resolution 5", string(allowedTypes.Function.value), "function_name", "Resolution param 1", "Resolution param 3", "", "", ""], ...
            %                         'addResolution method not working');
            testCase.verifyWarning(@() testCase.resolution.addResolution("New Resolution 6", allowedTypes.Constant.value, "Resolution param 1", "extra_value", '', '', '', ''), 'warnings:invalidNumberOfInputs');
            testCase.verifyWarning(@() testCase.resolution.addResolution("New Resolution 7", allowedTypes.Data.value, "Resolution param 1", "Resolution param 2", "extra_value", '', '', ''), 'warnings:invalidNumberOfInputs');
            testCase.verifyError(@() testCase.resolution.addResolution('New', 'fixed'), exceptions.invalidOption.errorID);
            testCase.verifyError(@() testCase.resolution.addResolution('New', allowedTypes.Constant), exceptions.invalidNumberOfInputs.errorID);           
            testCase.verifyError(@() testCase.resolution.addResolution('New', allowedTypes.Constant.value, 6), exceptions.indexOutOfRange.errorID);
        end

        function testRemoveResolution(testCase)
            % Checks that resolution can be removed
            testCase.resolution.resolutions.varTable = [testCase.resolution.resolutions.varTable; vertcat(testCase.resolutions(2:end, :))];

            testCase.resolution.removeResolution(3);
            testCase.verifyEqual(testCase.resolution.resolutions.varTable{:, 1}, ...
                                    ["Resolution 1"; "Resolution 2"], 'removeResolution method not working');

            testCase.resolution.resolutions.varTable = [testCase.resolution.resolutions.varTable; vertcat(testCase.resolutions(end, :))];
            testCase.resolution.removeResolution([1, 3]);
            testCase.verifyEqual(testCase.resolution.resolutions.varTable{:, 1}, "Resolution 2", 'removeResolution method not working');  
        end

        function testSetResolutionName(testCase)
         % Checks that resolution name can be modified
         testCase.resolution.resolutions.varTable = [testCase.resolution.resolutions.varTable; vertcat(testCase.resolutions(2:end, :))];
         testCase.resolution.setResolutionName(1, 'resolution one');
         testCase.verifyEqual(testCase.resolution.resolutions.varTable{1, 1}, ...
                              "resolution one", 'setResolutionName method not working');
         testCase.resolution.setResolutionName(3, 'resolution three');
         testCase.verifyEqual(testCase.resolution.resolutions.varTable{3, 1}, ...
                              "resolution three", 'setResolutionName method not working');
         testCase.verifyError(@() testCase.resolution.setResolutionName(2, 2), exceptions.invalidType.errorID);
        end   

        function testSetResolution(testCase)
            import matlab.unittest.fixtures.SuppressedWarningsFixture
            testCase.applyFixture(SuppressedWarningsFixture('warnings:invalidNumberOfInputs'))
            testCase.applyFixture(SuppressedWarningsFixture('warnings:fieldsCleared'))

            % Checks that resolution can be modified
            testCase.resolution.resolutions.varTable = [testCase.resolution.resolutions.varTable; vertcat(testCase.resolutions(2:end, :))];
            testCase.resolution.resolutionParams.varTable = [testCase.resolution.resolutionParams.varTable; vertcat(testCase.parameters(2:end, :))];
            
            testCase.resolution.setResolution('Resolution 1', 'name', 'Resol 1');
            testCase.verifyEqual(testCase.resolution.resolutions.varTable{1, 1}, "Resol 1", 'setResolutionValue method not working');
            testCase.resolution.setResolution(1, 'name', 'Resolution 1');
            testCase.verifyEqual(testCase.resolution.resolutions.varTable{1, 1}, "Resolution 1", 'setResolutionValue method not working');
 
            testCase.resolution.setResolution(1, 'type', allowedTypes.Constant.value);
            testCase.verifyEqual(testCase.resolution.resolutions.varTable{1, 2}, string(allowedTypes.Constant.value), 'setResolutionValue method not working');
            testCase.resolution.setResolution('Resolution 1', 'type', allowedTypes.Function.value); 
            testCase.verifyEqual(testCase.resolution.resolutions.varTable{1, 2}, string(allowedTypes.Function.value), 'setResolutionValue method not working');
            testCase.verifyError(@() testCase.resolution.setResolution(2, 'type', 'random'), exceptions.invalidOption.errorID);
            
            testCase.resolution.setResolution('Resolution 2', 'Source', 'Resolution param 1');
            testCase.verifyEqual(testCase.resolution.resolutions.varTable{2, 3}, "Resolution param 1", 'setResolutionValue method not working');
            
            testCase.resolution.setResolution(2, 'Value2', 'Resolution param 1');
            testCase.verifyEqual(testCase.resolution.resolutions.varTable{2, 5}, "Resolution param 1", 'setResolutionValue method not working');
            testCase.verifyError(@() testCase.resolution.setResolution(2, 'Value2', 'random'), exceptions.nameNotRecognised.errorID);
            testCase.verifyError(@() testCase.resolution.setResolution(5, 'Value2', 'random'), exceptions.indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.resolution.setResolution(true, 'Value2', 'random'), exceptions.invalidType.errorID);
            
            testCase.resolution.setResolution(3, 'name', 'New Name', 'type', allowedTypes.Constant.value, 'source', 'Resolution param 3', 'value1', '');
            testCase.verifyEqual(testCase.resolution.resolutions.varTable{3, 1}, "New Name", 'setResolutionValue method not working');
            testCase.verifyEqual(testCase.resolution.resolutions.varTable{3, 2}, string(allowedTypes.Constant.value), 'setResolutionValue method not working');
            testCase.verifyEqual(testCase.resolution.resolutions.varTable{3, 3}, "Resolution param 3", 'setResolutionValue method not working');
            testCase.verifyEqual(testCase.resolution.resolutions.varTable{3, 4}, "", 'setResolutionValue method not working');
        end

        function testSetResolutionWarnings(testCase)
            testCase.resolution.resolutions.varTable = [testCase.resolution.resolutions.varTable; vertcat(testCase.resolutions(2:end, :))];
            testCase.resolution.resolutionParams.varTable = [testCase.resolution.resolutionParams.varTable; vertcat(testCase.parameters(2:end, :))];

            testCase.verifyWarning(@() testCase.resolution.setResolution(1, "Value1", "Resolution param 1"), 'warnings:invalidNumberOfInputs');
            testCase.verifyWarning(@() testCase.resolution.setResolution(3, "Value2", "Resolution param 1"), 'warnings:invalidNumberOfInputs');
        end

        function testDisplayResolutionsObject(testCase)
            % Check that the contents of the resolution are printed
            paramHeader = {'p', 'Name', 'Min', 'Value', 'Max', 'Fit?'};
            display = evalc('testCase.resolution.displayResolutionsObject()');
            testCase.verifyNotEmpty(display, 'displayResolutionsObject method not working');
            display = split(display, ["(a)", "(b)"]);  % splits resolution parameter table from resolution table
            testCase.verifyLength(display, 3);

            displayArray = textscan(display{2},'%s','Delimiter','\r','TextType','string');
            displayArray = strip(displayArray{1});
            % display table should be height of resolutionParams table plus header and divider row
            testCase.verifyLength(displayArray, height(testCase.resolution.resolutionParams.varTable) + 3);
            % Remove html tags used to format header then split table when
            % 2 or more spaces are found to avoid splitting names with single space
            displayHeader = eraseBetween(displayArray{2}, '<', '>', 'Boundaries','inclusive');
            displayHeader = regexp(displayHeader, '\s{2,}', 'split');
            testCase.verifyEqual(displayHeader, paramHeader);
            row = regexp(displayArray{4}, '\s{2,}', 'split');
            row = string(replace(row, '"', ''));
            testCase.verifyLength(row, length(paramHeader));
            testCase.verifyEqual(row, string({1, testCase.parameters{1, 1:5}}), 'displayResolutionsObject method not working')

            paramHeader = {'p', 'Name', 'Type', 'Source', 'Value 1', 'Value 2', 'Value 3', 'Value 4', 'Value 5'};
            displayArray = textscan(display{3},'%s','Delimiter','\r','TextType','string');
            displayArray = strip(displayArray{1});
            % display table should be height of resolution table plus header and divider row
            testCase.verifyLength(displayArray, height(testCase.resolution.resolutions.varTable) + 3);
            displayHeader = eraseBetween(displayArray{2}, '<', '>', 'Boundaries','inclusive');
            displayHeader = regexp(displayHeader, '\s{2,}', 'split');
            testCase.verifyEqual(displayHeader, paramHeader);
            row = regexp(displayArray{4}, '\s{2,}', 'split');
            row = string(replace(row, '"', ''));
            testCase.verifyLength(row, length(paramHeader));
            testCase.verifyEqual(row, string({1, testCase.resolutions{1, :}}), 'displayResolutionsObject method not working')

            paramHeader = {'p', 'Name', 'Min', 'Value', 'Max', 'Fit?', 'Prior Type', 'mu', 'sigma'};
            display = evalc('testCase.resolution.displayResolutionsObject(true)');
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
            expected.resolutionParamNames = {'Resolution param 1'};
            expected.resolutionParamLimits = {[0.0100 0.0500]};
            expected.resolutionParamValues = 0.0300;
            expected.fitResolutionParam = 0;
            expected.resolutionParamPriors = {{'Resolution param 1', priorTypes.Uniform.value, 0, Inf}};
            expected.resolutionNames = "Resolution 1";
            expected.resolutionTypes = string(allowedTypes.Constant.value);
            expected.resolutionValues = {"Resolution param 1", "", "", "", "", ""};
            testCase.verifyEqual(testCase.resolution.toStruct(), expected, 'toStruct method not working');

            testCase.resolution.resolutions.varTable = [testCase.resolution.resolutions.varTable; vertcat(testCase.resolutions(2:3, :))];
            testCase.resolution.resolutionParams.varTable = [testCase.resolution.resolutionParams.varTable; vertcat(testCase.parameters(2:3, :))];

            expected.resolutionParamNames = {'Resolution param 1', 'Resolution param 2', 'Resolution param 3'};
            expected.resolutionParamLimits = {[0.0100 0.0500], [0.1000 1], [0.2000 1.1000]};
            expected.resolutionParamValues = [0.0300, 0.1900, 0.1700];
            expected.fitResolutionParam = [0, 1, 0];
            expected.resolutionParamPriors = {{'Resolution param 1', priorTypes.Uniform.value, 0, Inf};... 
                                        {'Resolution param 2', priorTypes.Gaussian.value, -1, 1};... 
                                        {'Resolution param 3', priorTypes.Uniform.value, 0, Inf}};
            expected.resolutionNames = ["Resolution 1"; "Resolution 2"; "Resolution 3"];
            expected.resolutionTypes = [string(allowedTypes.Constant.value); string(allowedTypes.Constant.value); 
                                        string(allowedTypes.Data.value)];
            expected.resolutionValues = {"Resolution param 1", "", "", "", "", ""; "Resolution param 2", "", "", "", "", "";...
                                         "", "", "", "", "", ""};
            testCase.verifyEqual(testCase.resolution.toStruct(), expected, 'toStruct method not working');
        end
    end
end
