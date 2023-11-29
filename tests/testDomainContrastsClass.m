classdef testDomainContrastsClass < matlab.unittest.TestCase
%%
% testContrastsClass Class based unit tests for the domainContrastsClass
% used within the Project Class in RAT.
%
% We use an example contrasts class from the example calculation
% "DPPC_standard_layers.m".
%
% Paul Sharp 27/06/23
%
%% Declare properties and parameters

    properties
        allowedNames            % Full set of ALL parameter names in the project
        defaultContrastParams   % Default values for contrasts
        exampleClass            % Example contrasts class for testing
        exampleStruct           % The example class converted to a struct
        newValues               % New set of values for contrasts
        numContrasts            % Number of Contrasts defined in exampleClass
    end

%% Set up test data

    methods (TestClassSetup)

        function initialiseAllowedNames(testCase)
            % The values for each parameter in the contrast class MUST
            % be defined in the corresponding parameters in this class
            % This example is a reduced version of the allowed names used
            % in the example calculation "DPPC_standard_layers.m", with the
            % custom file names from "orsoDSPC_custLay_script.m" and
            % "DPPC_customXY.m"
            testCase.allowedNames = struct( ...
                'layerNames',  ["Oxide Layer" "Water Layer" "Bil inner head" "Bil tail" "Bil outer head"], ...
                'customFileNames',  ["DSPC Model" "DPPC Model"] ...
                );
        end

        function initialiseDefaultContrastParams(testCase)
            % Create a struct used in the contrasts class with the default
            % values for each parameter
            testCase.defaultContrastParams = struct( ...
                'name', '', ...
                'model', '' ...
                );
        end

        function initialiseNewValues(testCase)
            % Create a new set of values for each contrast parameter
            testCase.newValues = {'name', 'New Sim Contrast'};
        end

    end

    methods (TestMethodSetup)

        function initialiseContrastsClass(testCase)
            % Set up an example contrasts class for testing
            % This example is used in the example calculation
            % "DPPC_standard_layers.m"
            testCase.exampleClass = domainContrastsClass();

            testCase.exampleClass.contrasts(1) = {struct( ...
                'name', 'Bilayer / D2O', ...
                'model', {{'Oxide Layer', 'Water Layer', 'Bil inner head', 'Bil tail', 'Bil tail', 'Bil outer head'}} ...
                )};
           
            testCase.exampleClass.contrasts(2) = {struct( ...
                'name', 'Bilayer / SMW', ...
                'model', {{'Oxide Layer', 'Water Layer', 'Bil inner head', 'Bil tail', 'Bil tail', 'Bil outer head'}} ...
                )};
            
            testCase.exampleClass.contrasts(3) = {struct( ...
                'name', 'Bilayer / H2O', ...
                'model', {{'Oxide Layer', 'Water Layer', 'Bil inner head', 'Bil tail', 'Bil tail', 'Bil outer head'}} ...
                )};

            testCase.numContrasts = length(testCase.exampleClass.contrasts);
        end

        function initialiseContrastsStruct(testCase)
            % The contrast class from the example calculation
            % "DPPC_standard_layers.m" converted to a struct
            % We need to define it in this way to avoid setting the struct
            % as a 1x3 struct array . . .
            testCase.exampleStruct = struct( ...
                'numberOfContrasts', 3 ...
                );

            testCase.exampleStruct.contrastNames = {'Bilayer / D2O', 'Bilayer / SMW', 'Bilayer / H2O'};
            testCase.exampleStruct.contrastLayers = {[1 2 3 4 4 5] [1 2 3 4 4 5] [1 2 3 4 4 5]};
            testCase.exampleStruct.contrastRepeatSLDs = {[0 1] [0 1] [0 1]};
        end

    end

%% Test Contrasts Class Routines

    methods (Test, ParameterCombination='sequential')

        function testInitialiseDomainContrastsClass(testCase)
            testClass = domainContrastsClass();
            testCase.verifyEqual(testClass.contrasts, {}, 'domainContrastsClass does not initialise correctly');
            testCase.verifyFalse(testClass.domainsCalc);
            testCase.verifyFalse(testClass.oilWaterCalc);
        end

        function testToStruct(testCase)
            % Test converting the contrasts class to a struct
            % Here we use a "standard layers" model type as must be the
            % case for the domain contrasts to be defined.
            testCase.verifyEqual(testCase.exampleClass.toStruct(testCase.allowedNames, 'standard layers'), testCase.exampleStruct);
        end

        function testDisplayContrastsObject(testCase)
            % Test the routine to display the a table of the contrasts
            % object by capturing the output and comparing with the
            % expected table headers and contrasts data

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display = textscan(evalc('testCase.exampleClass.displayContrastsObject()'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};

            % Check headers
            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove "<strong>" tags
            outVars = eraseBetween(strip(regexprep(displayedTable(1), '\s+', ' ')), '<', '>','Boundaries','inclusive');
            headerString = "p 1 2 3";
            testCase.verifyEqual(outVars, headerString, 'Table headers do not match variable names');

            % Make sure the output has the right number of rows before
            % continuing - output consists of table header, divider row,
            % a row for each of the four parameters and an extra row for
            % additional model parameters
            expectedRows = 4 + length(testCase.exampleClass.contrasts{1}.model) - 1;
            testCase.assertSize(displayedTable, [expectedRows, 1], 'Table does not have the right number of rows');

            % Construct string array of contrast parameters to compare
            % with the rows of the displayed table
            rowString(1) = strjoin(["Name", ...
                                    testCase.exampleClass.contrasts{1}.name, ...
                                    testCase.exampleClass.contrasts{2}.name, ...
                                    testCase.exampleClass.contrasts{3}.name]);

            rowString(2) = strjoin(["Model", ...
                                    testCase.exampleClass.contrasts{1}.model{1}, ...
                                    testCase.exampleClass.contrasts{2}.model{1}, ...
                                    testCase.exampleClass.contrasts{3}.model{1}]);

            rowString(3) = strjoin({testCase.exampleClass.contrasts{1}.model{2}, ...
                                    testCase.exampleClass.contrasts{2}.model{2}, ...
                                    testCase.exampleClass.contrasts{3}.model{2}});

            rowString(4) = strjoin({testCase.exampleClass.contrasts{1}.model{3}, ...
                                    testCase.exampleClass.contrasts{2}.model{3}, ...
                                    testCase.exampleClass.contrasts{3}.model{3}});

            rowString(5) = strjoin({testCase.exampleClass.contrasts{1}.model{4}, ...
                                    testCase.exampleClass.contrasts{2}.model{4}, ...
                                    testCase.exampleClass.contrasts{3}.model{4}});

            rowString(6) = strjoin({testCase.exampleClass.contrasts{1}.model{5}, ...
                                    testCase.exampleClass.contrasts{2}.model{5}, ...
                                    testCase.exampleClass.contrasts{3}.model{5}});

            rowString(7) = strjoin({testCase.exampleClass.contrasts{1}.model{6}, ...
                                    testCase.exampleClass.contrasts{2}.model{6}, ...
                                    testCase.exampleClass.contrasts{3}.model{6}});

            % Check table contents - when displayed, row 2 is a set of
            % lines, so row 3 is the first line of data
            for i = 3:expectedRows
                
                % Replace multiple spaces in output table with a single
                % space using regular expressions, and remove '"'
                % characters
                outRow = strip(replace(regexprep(displayedTable(i), '\s+', ' '), '"', ''));

                testCase.verifyEqual(outRow, rowString(i-2), 'Row does not contain the correct data');

            end
        end

        function testDisplayContrastsObjectEmpty(testCase)
            % Test the routine to display the a table of an empty
            % contrasts object by capturing the output and comparing with
            % the expected table headers and contrasts data

            % Make an empty contrast object
            emptyContrasts = domainContrastsClass();

            emptyContrasts.contrasts = {testCase.defaultContrastParams};
            emptyContrasts.contrasts{1}.resample = '';

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display = textscan(evalc('emptyContrasts.displayContrastsObject()'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};

            % Check headers
            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove "<strong>" tags
            outVars = eraseBetween(strip(regexprep(displayedTable(1), '\s+', ' ')), '<', '>','Boundaries','inclusive');
            headerString = "p 1";
            testCase.verifyEqual(outVars, headerString, 'Table headers do not match variable names');

            % Make sure the output has the right number of rows before
            % continuing - output consists table header, divider row,
            % a row for each of the nine parameters and an extra row for
            % additional model parameters
            expectedRows = 4;
            testCase.assertSize(displayedTable, [expectedRows, 1], 'Table does not have the right number of rows');

            % Construct string array of contrast parameters to compare
            % with the rows of the displayed table
            rowString = ["Name" "Model"];

            % Check table contents - when displayed, row 2 is a set of
            % lines, so row 3 is the first line of data
            for i = 3:expectedRows
                
                % Replace multiple spaces in output table with a single
                % space using regular expressions, and remove '"'
                % characters
                outRow = strip(replace(regexprep(displayedTable(i), '\s+', ' '), '"', ''));

                testCase.verifyEqual(outRow, rowString(i-2), 'Row does not contain the correct data');

            end
        end

        function testParseContrastInput(testCase)
            expectedContrast = struct( ...
                'name', 'New Sim Contrast');

            contrastStruct = testCase.exampleClass.parseContrastInput(testCase.allowedNames, testCase.newValues);
            testCase.verifyEqual(contrastStruct, expectedContrast, 'parseContrastInput does not work correctly');
        end

    end

end
