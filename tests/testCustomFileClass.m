classdef testCustomFileClass < matlab.unittest.TestCase
%%
% testCustomFileClass Class based unit tests for the customFileClass
% used within the Project Class in RAT.
%
% In this class, we test:
% customFileClass, addCustomFile, setCustomFile, removeCustomFile,
% displayCustomFileObject, toStruct
%
% We use an example custom file class combining the custom file classes
% from the example calculations "DPPCCustomXY.m" and
% "orsoDSPCCustomLayers.m"
%
% Paul Sharp 10/02/23
%
%% Declare properties and parameters

    properties (TestParameter)
        fileInput = {{'New Entry'},...
                     {'Row and file name', 'file.m'},...
                     {'Full entry', 'otherFile.m', 'python', 'pwd'}
                    }
        addedRow = {{'New Entry', '', supportedLanguages.Matlab.value, 'pwd'},...
                    {'Row and file name', 'file.m', supportedLanguages.Matlab.value, 'pwd'},...
                    {'Full entry', 'otherFile.m', supportedLanguages.Python.value, 'pwd'}
                   }
        testRow = {1, 1, 2, 2}
        inputData = {{'DPPC Model', 'name', 'New Model'},...
                     {1, 'filename', 'model.m'},...
                     {'DSPC Model', 'language', upper(supportedLanguages.Python.value)},...
                     {2, 'language', supportedLanguages.Python, 'filename', 'model.m', 'name', 'New Model'},...
                    }
        expectedRow = {["New Model", "DPPCCustomXY.m", string(supportedLanguages.Matlab.value), "../../"],...
                       ["DPPC Model", "model.m", string(supportedLanguages.Matlab.value), "../../"],...
                       ["DSPC Model", "customBilayer.m", string(supportedLanguages.Python.value), "../../"],...
                       ["New Model", "model.m", string(supportedLanguages.Python.value), "../../"],...
                      }
        invalidInputData = {{'DPPC Model', 'name', 42},...
                            {1, 'filename', datetime('today')},...
                            {'DSPC Model', 'language', table()},...
                            {2, 'path', {'path', 'to', 'file'}}
                           }

    end

    properties
        exampleClass            % Example custom file class for testing
        initialFileTableEmpty   % Empty table to compare to initialisation
        initialFileTableOneRow  % Table with one row to compare to initialisation
        numRows                 % Number of rows in exampleClass.paramTable
        numCols                 % Number of columns in exampleClass.paramTable
    end

%% Set up test data

    methods (TestClassSetup)

        function initialiseFileTable(testCase)
            % Set up an empty file table and a table with one row
            tableTypes = {'string', 'string', 'string', 'string'};
            tableNames = {'Name', 'Filename', 'Language', 'Path'};

            testCase.initialFileTableEmpty = table('Size',[0 4],'VariableTypes',tableTypes,'VariableNames',tableNames);

            testCase.initialFileTableOneRow = table('Size',[1 4],'VariableTypes',tableTypes,'VariableNames',tableNames);
            testCase.initialFileTableOneRow{1, :} = {'DPPC Model', 'DPPCCustomXY.m', 'matlab', '../../'};
        end

    end

    methods (TestMethodSetup)

        function initialiseCustomFileClass(testCase)
            % Set up an example custom file class for testing
            % These examples are used in the example calculations
            % "DPPCCustomXY.m" and "orsoDSPCCustomLayers.m"
            testCase.exampleClass = customFileClass();

            testCase.exampleClass.paramTable(1,:) = {'DPPC Model', 'DPPCCustomXY.m', 'matlab', '../../'};
            testCase.exampleClass.paramTable(2,:) = {'DSPC Model', 'customBilayer.m', 'matlab', '../../'};

            testCase.numRows = height(testCase.exampleClass.paramTable);
            testCase.numCols = width(testCase.exampleClass.paramTable);
        end

    end

%% Test Custom File Class Routines

    methods (Test, ParameterCombination='sequential')

        function testInitialiseCustomFileClassEmpty(testCase)
            % On initialisation we set up a custom file class with an
            % either an empty file table, or a table with a single row
            testClass = customFileClass();

            testCase.verifySize(testClass.paramTable, [0 4], 'customFileClass does not initialise correctly');
            testCase.verifyEqual(testClass.paramTable, testCase.initialFileTableEmpty, 'customFileClass does not initialise correctly');
        end

        function testInitialiseCustomFileClassOneRow(testCase)
            % On initialisation we set up a custom file class with an
            % either an empty file table, or a table with a single row
            testClass = customFileClass('DPPC Model', 'DPPCCustomXY.m', 'matlab', '../../');

            testCase.verifySize(testClass.paramTable, [1 4], 'customFileClass does not initialise correctly');
            testCase.verifyEqual(testClass.paramTable, testCase.initialFileTableOneRow, 'customFileClass does not initialise correctly');
        end

        function testAddCustomFile(testCase, fileInput, addedRow)
            % Test adding a custom file entry to the custom file class.
            % We can add a custom file entry with no parameters, just a
            % custom object name, a custom object name with the filename,
            % and a fully defined custom file entry consisting of: a
            % custom object name, a filename, language and file path.  
            expectedTable = [testCase.exampleClass.paramTable; addedRow];

            testCase.exampleClass.addCustomFile(fileInput{:});

            testCase.verifyEqual(testCase.exampleClass.paramTable, expectedTable, 'addFile does not work correctly');
        end

        function testAddCustomFileEmpty(testCase)
            % Test adding a custom file entry to the custom file class.
            % We can add a custom file entry with no parameters, just a
            % custom object name, a custom object name with the filename,
            % and a fully defined custom file entry consisting of: a
            % custom object name, a filename, language and file path.
            newRow = {'New custom file 1', '', 'matlab', 'pwd'};
            expectedTable = [testCase.exampleClass.paramTable; newRow];

            testCase.exampleClass.addCustomFile();

            testCase.verifyEqual(testCase.exampleClass.paramTable, expectedTable, 'addFile does not work correctly');
        end

        function testAddCustomFileInvalid(testCase)
            % Test adding a custom file entry to the custom file class.
            % If we use an invalid set of custom file parameters it should
            % raise an error

            % Invalid length for custom file parameters
            testCase.verifyError(@() testCase.exampleClass.addCustomFile('Invalid Entry', 'matlab', 'pwd'), invalidNumberOfInputs.errorID);
            testCase.verifyError(@() testCase.exampleClass.addCustomFile('Invalid Entry', 'invalid.m', 'matlab', 'pwd', 'other'), invalidNumberOfInputs.errorID);

            % Invalid types
            testCase.verifyError(@() testCase.exampleClass.addCustomFile(42), invalidType.errorID);

            % Unrecognised language
            testCase.verifyError(@() testCase.exampleClass.addCustomFile('Unrecognised language', 'file.m', 'fortran', 'pwd'), invalidOption.errorID);

            % Duplicate custom object names
            testCase.verifyError(@() testCase.exampleClass.addCustomFile('DPPC Model'), duplicateName.errorID);
        end

        function testSetCustomFile(testCase, testRow, inputData, expectedRow)
            testCase.exampleClass.setCustomFile(inputData{:});
            testCase.verifyEqual(testCase.exampleClass.paramTable{testRow, :}, expectedRow, 'setCustomFile does not work correctly');
        end

        function testSetCustomFileInvalidType(testCase, invalidInputData)
            testCase.verifyError(@() testCase.exampleClass.setCustomFile(invalidInputData{:}), 'MATLAB:InputParser:ArgumentFailedValidation');
        end

        function testSetCustomFileInvalidInput(testCase)
            % Test setting values in the files table
            % If the inputs are invalid, it should raise an error

            % Invalid row
            testCase.verifyError(@() testCase.exampleClass.setCustomFile(0, 'Name', 'Invalid'), indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleClass.setCustomFile(testCase.numRows+1, 'Name', 'Invalid'), indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleClass.setCustomFile('Undefined row', 'Name', 'Invalid'), nameNotRecognised.errorID);

            % Unrecognised language
            testCase.verifyError(@() testCase.exampleClass.setCustomFile(1, 'Language', 'Fortran'), invalidOption.errorID)

            % Duplicate custom object names
            testCase.verifyError(@() testCase.exampleClass.setCustomFile(2, 'Name', 'DPPC Model'), duplicateName.errorID)
        end

        function testSetCustomFileInvalidNumberOfParams(testCase)
            % If we call "setCustomFile" with fewer than three values or
            % an even number of values (i.e., not name-value pairs) it
            % should raise an error
            testCase.verifyError(@() testCase.exampleClass.setCustomFile(1), invalidNumberOfInputs.errorID);
            testCase.verifyError(@() testCase.exampleClass.setCustomFile(1, 1), invalidNumberOfInputs.errorID);
            testCase.verifyError(@() testCase.exampleClass.setCustomFile(2, 'Name', 'New Model', 'Language'), invalidNumberOfInputs.errorID);
        end

        function testRemoveCustomFile(testCase)
            remainingRows = testCase.exampleClass.paramTable(2:end,:);
            testCase.exampleClass.removeRow(1);

            testCase.verifyEqual(testCase.exampleClass.paramTable, remainingRows, 'removeRow does not work correctly');
        end

        function testRemoveCustomFileMultiple(testCase)
            % Test removing multiple rows from a file table
            
            % Put dummy third row in table
            testCase.exampleClass.paramTable(3, :) = {'Test Row', '', '', ''};

            remainingRows = testCase.exampleClass.paramTable(2,:);
            testCase.exampleClass.removeRow([1 3]);

            testCase.verifyEqual(testCase.exampleClass.paramTable, remainingRows, 'removeRow does not work correctly');
        end

        function testRemoveCustomFileInvalid(testCase)
            % Test using invalid row indices to remove rows from a
            % file table.
            testCase.verifyError(@() testCase.exampleClass.removeRow(0), 'MATLAB:validators:mustBePositive');
            testCase.verifyError(@() testCase.exampleClass.removeRow(1.5), 'MATLAB:validators:mustBeInteger');
            testCase.verifyError(@() testCase.exampleClass.removeRow(testCase.numRows+1), 'RAT:IndexOutOfRange');

            testCase.verifySize(testCase.exampleClass.paramTable, [testCase.numRows testCase.numCols], 'Table parameters have changed despite no rows being removed');
        end

        function testDisplayCustomFileObject(testCase)
            % Test the routine to display the file table by capturing the
            % output and comparing with the table headers and data

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display = textscan(evalc('testCase.exampleClass.displayCustomFileObject()'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};

            % Check headers
            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove "<strong>" tags
            outVars = eraseBetween(strip(regexprep(displayedTable(2), '\s+', ' ')), '<', '>','Boundaries','inclusive');

            % Convert table variable names to a string array and join into
            % a single string
            varString = strip(strjoin(string(testCase.exampleClass.paramTable.Properties.VariableNames)));
            testCase.verifyEqual(outVars, varString, 'Table headers do not match variable names');

            % Make sure the output has the right number of rows before
            % continuing - output consists of "Custom Files" string,
            % table header, divider row and the defined table rows
            testCase.assertSize(displayedTable, [testCase.numRows+3, 1], 'Table does not have the right number of rows');

            % Check table contents - when displayed, row 3 is a set of
            % lines, so row 4 is the first line of data
            for i = 1:testCase.numRows
                
                % Replace multiple spaces in output table with a single
                % space using regular expressions, and remove '"'
                % characters
                outRow = strip(replace(regexprep(displayedTable(i+3), '\s+', ' '), '"', ''));

                % Get data from this row and join into a single string
                rowString = strip(strjoin(testCase.exampleClass.paramTable{i,:}));
                testCase.verifyEqual(outRow, rowString, 'Row does not contain the correct data');

            end
        end

        function testDisplayCustomFileObjectEmpty(testCase)
            % Test the routine to display the file table of an empty
            % custom file class by capturing the output and comparing with
            % the table headers and data
            emptyClass = customFileClass();

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display = textscan(evalc('emptyClass.displayCustomFileObject()'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};

            % Check headers
            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove "<strong>" tags
            outVars = eraseBetween(strip(regexprep(displayedTable(2), '\s+', ' ')), '<', '>','Boundaries','inclusive');

            % Convert table variable names to a string array and join into
            % a single string
            varString = strip(strjoin(string(emptyClass.paramTable.Properties.VariableNames)));
            testCase.verifyEqual(outVars, varString, 'Table headers do not match variable names');

            % Make sure the output has the right number of rows before
            % continuing
            testCase.assertSize(displayedTable, [4, 1], 'Table does not have the right number of rows');

            % Replace multiple spaces in output table with a single
            % space using regular expressions
            outRow = strip(regexprep(displayedTable(4), '\s+', ' '));
            rowString = string('"" "" "" ""');
            testCase.verifyEqual(outRow, rowString, 'Row does not contain the correct data');
        end

        function testDisplayCustomFileObjectEmptyRow(testCase)
            % Test the routine to display the file table of a custom file
            % class with empty row entries by capturing the output and
            % comparing with the table headers and data
            emptyRowClass = customFileClass();
            emptyRowClass.paramTable(1, :) = {'Test Row', '', '', ''};

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display = textscan(evalc('emptyRowClass.displayCustomFileObject()'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};

            % Check headers
            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove "<strong>" tags
            outVars = eraseBetween(strip(regexprep(displayedTable(2), '\s+', ' ')), '<', '>','Boundaries','inclusive');

            % Convert table variable names to a string array and join into
            % a single string
            varString = strip(strjoin(string(emptyRowClass.paramTable.Properties.VariableNames)));
            testCase.verifyEqual(outVars, varString, 'Table headers do not match variable names');

            % Make sure the output has the right number of rows before
            % continuing
            testCase.assertSize(displayedTable, [4, 1], 'Table does not have the right number of rows');

            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove '"' characters
            outRow = strip(replace(regexprep(displayedTable(4), '\s+', ' '), '"', ''));
            rowString = "Test Row No File - pwd";
            testCase.verifyEqual(outRow, rowString, 'Row does not contain the correct data');
        end

        function testDisplayCustomFileObjectLongPath(testCase)
            % Test the routine to display the file table of a custom file
            % class with a long file path by capturing the output and
            % comparing with the table headers and data
            longPathClass = customFileClass();
            longPathClass.paramTable(1, :) = {'Test Row', '', '', 'really/long/file/path'};

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display = textscan(evalc('longPathClass.displayCustomFileObject()'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};

            % Check headers
            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove "<strong>" tags
            outVars = eraseBetween(strip(regexprep(displayedTable(2), '\s+', ' ')), '<', '>','Boundaries','inclusive');

            % Convert table variable names to a string array and join into
            % a single string
            varString = strip(strjoin(string(longPathClass.paramTable.Properties.VariableNames)));
            testCase.verifyEqual(outVars, varString, 'Table headers do not match variable names');

            % Make sure the output has the right number of rows before
            % continuing
            testCase.assertSize(displayedTable, [4, 1], 'Table does not have the right number of rows');

            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove '"' characters
            outRow = strip(replace(regexprep(displayedTable(4), '\s+', ' '), '"', ''));
            rowString = "Test Row No File - ...g/file/path";
            testCase.verifyEqual(outRow, rowString, 'Row does not contain the correct data');
        end

        function testToStruct(testCase)
            fileStruct = testCase.exampleClass.toStruct();
            testCase.verifyClass(fileStruct, 'struct');
            for i = 1:testCase.numRows
                testCase.verifyEqual(string(fileStruct.files{i}), testCase.exampleClass.paramTable{i, 2:end});
            end
        end

        function testToStructEmpty(testCase)
            % Test converting an empty custom file class to a struct
            emptyClass = customFileClass();
            fileStruct = emptyClass.toStruct();
            testCase.verifyClass(fileStruct, 'struct');
            testCase.verifyEqual(fileStruct.files, {});
        end

        function testToStructPwd(testCase)
            % Test converting an custom file class to a struct correctly
            % interprets the present working directory
            pwdClass = customFileClass('Test pwd', 'file.m', 'matlab', 'pwd');
            fileStruct = pwdClass.toStruct();
            testCase.verifyClass(fileStruct, 'struct');
            testCase.verifyEqual(string(fileStruct.files{:}), ["file.m" "matlab" pwd]);
        end

    end

end
