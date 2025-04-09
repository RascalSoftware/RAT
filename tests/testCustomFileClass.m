classdef testCustomFileClass < matlab.unittest.TestCase
%%
% testCustomFileClass Class based unit tests for the customFileClass
% used within the Project Class in RAT.
%
% We use an example custom file class combining the custom file classes
% from the example calculations "DPPCCustomXY.m" and
% "orsoDSPCCustomLayers.m"
%
%% Declare properties and parameters

    properties (TestParameter)
        fileInput = {{'New Entry'},...
                     {'Row and file name', 'file'},...
                     {'Nearly Full entry', 'otherFile', 'python', pwd},...
                     {'Full entry', 'anotherFile.py', 'python', pwd, 'function_name'}
                    }
        addedRow = {{'New Entry', '', '', supportedLanguages.Matlab.value, ''},...
                    {'Row and file name', 'file.m', 'file', supportedLanguages.Matlab.value, ''},...
                    {'Nearly Full entry', 'otherFile.py', 'otherFile', supportedLanguages.Python.value, pwd},...
                    {'Full entry', 'anotherFile.py', 'function_name', supportedLanguages.Python.value, pwd}
                   }
        testRow = {1, 1, 2, 2}
        inputData = {{'DPPC Model', 'name', 'New Model', 'path', '../../'},...
                     {1, 'filename', 'model.m', 'functionName', 'model'},...
                     {'DSPC Model', 'language', upper(supportedLanguages.Python.value)},...
                     {2, 'language', supportedLanguages.Python, 'filename', 'model.m', 'functionName', 'modelFunc', 'name', 'New Model', 'path', pwd},...
                    }
        expectedRow = {["New Model", "DPPCCustomXY.m", "DPPCCustomXY", string(supportedLanguages.Matlab.value), "../../"],...
                       ["DPPC Model", "model.m", "model", string(supportedLanguages.Matlab.value), "tests/normalTFReflectivityCalculation/"],...
                       ["DSPC Model", "customBilayer.m", "customBilayer", string(supportedLanguages.Python.value), "tests/normalTFReflectivityCalculation/"],...
                       ["New Model", "model.m", "modelFunc", string(supportedLanguages.Python.value), pwd],...
                      }
        invalidInputData = {{'DPPC Model', 'name', 42},...
                            {1, 'filename', datetime('today')},...
                            {2, 'path', {'path', 'to', 'file'}}
                           }

    end

    properties
        exampleClass            % Example custom file class for testing
        initialFileTableEmpty   % Empty table to compare to initialisation
        initialFileTableOneRow  % Table with one row to compare to initialisation
        numRows                 % Number of rows in exampleClass.varTable
        numCols                 % Number of columns in exampleClass.varTable
    end

%% Set up test data

    methods (TestClassSetup)
        function addDataPath(testCase)
            import matlab.unittest.fixtures.PathFixture
            path = fullfile(getappdata(0, 'root'), 'tests', 'normalTFReflectivityCalculation');
            testCase.applyFixture(PathFixture(path))  
        end

        function initialiseFileTable(testCase)
            % Set up an empty file table and a table with one row
            tableTypes = {'string', 'string', 'string', 'string', 'string'};
            tableNames = {'Name', 'Filename', 'Function Name', 'Language', 'Path'};

            testCase.initialFileTableEmpty = table('Size',[0 5],'VariableTypes',tableTypes,'VariableNames',tableNames);

            testCase.initialFileTableOneRow = table('Size',[1 5],'VariableTypes',tableTypes,'VariableNames',tableNames);
            testCase.initialFileTableOneRow{1, :} = {'DPPC Model', 'DPPCCustomXY.m', 'DPPCCustomXY', 'matlab', '../../'};
        end

    end

    methods (TestMethodSetup)

        function initialiseCustomFileClass(testCase)
            % Set up an example custom file class for testing
            % These examples are used in the example calculations
            % "DPPCCustomXY.m" and "orsoDSPCCustomLayers.m"
            testCase.exampleClass = customFileClass();

            testCase.exampleClass.varTable(1,:) = {'DPPC Model', 'DPPCCustomXY.m', 'DPPCCustomXY', 'matlab', 'tests/normalTFReflectivityCalculation/'};
            testCase.exampleClass.varTable(2,:) = {'DSPC Model', 'customBilayer.m', 'customBilayer', 'matlab', 'tests/normalTFReflectivityCalculation/'};

            testCase.numRows = height(testCase.exampleClass.varTable);
            testCase.numCols = width(testCase.exampleClass.varTable);
        end

    end

%% Test Custom File Class Routines

    methods (Test, ParameterCombination='sequential')

        function testInitialiseCustomFileClassEmpty(testCase)
            % On initialisation we set up a custom file class with an
            % either an empty file table, or a table with a single row
            testClass = customFileClass();

            testCase.verifySize(testClass.varTable, [0 5], 'customFileClass does not initialise correctly');
            testCase.verifyEqual(testClass.varTable, testCase.initialFileTableEmpty, 'customFileClass does not initialise correctly');
        end

        function testInitialiseCustomFileClassOneRow(testCase)
            % On initialisation we set up a custom file class with an
            % either an empty file table, or a table with a single row
            testClass = customFileClass('DPPC Model', 'DPPCCustomXY.m', 'matlab', '../../');

            testCase.verifySize(testClass.varTable, [1 5], 'customFileClass does not initialise correctly');
            testCase.verifyEqual(testClass.varTable, testCase.initialFileTableOneRow, 'customFileClass does not initialise correctly');
        end

        function testAddCustomFile(testCase, fileInput, addedRow)
            % Test adding a custom file entry to the custom file class.
            % We can add a custom file entry with no parameters, just a
            % custom object name, a custom object name with the filename,
            % and a fully defined custom file entry consisting of: a
            % custom object name, a filename, language and file path.  
            expectedTable = [testCase.exampleClass.varTable; addedRow];

            testCase.exampleClass.addCustomFile(fileInput{:});

            testCase.verifyEqual(testCase.exampleClass.varTable, expectedTable, 'addFile does not work correctly');
        end

        function testAddCustomFileEmpty(testCase)
            % Test adding a custom file entry to the custom file class.
            % We can add a custom file entry with no parameters, just a
            % custom object name, a custom object name with the filename,
            % and a fully defined custom file entry consisting of: a
            % custom object name, a filename, language and file path.
            newRow = {'New custom file 1', '', '', 'matlab', ''};
            expectedTable = [testCase.exampleClass.varTable; newRow];

            testCase.exampleClass.addCustomFile();

            testCase.verifyEqual(testCase.exampleClass.varTable, expectedTable, 'addFile does not work correctly');
        end

        function testAddCustomFileInvalid(testCase)
            % Test adding a custom file entry to the custom file class.
            % If we use an invalid set of custom file parameters it should
            % raise an error

            % Invalid length for custom file parameters
            testCase.verifyError(@() testCase.exampleClass.addCustomFile('Invalid Entry', 'invalid.m', '', 'matlab', '', 'other'), 'MATLAB:TooManyInputs');
           
            % Invalid types
            testCase.verifyError(@() testCase.exampleClass.addCustomFile(42), 'MATLAB:validators:mustBeTextScalar');
            testCase.verifyError(@() testCase.exampleClass.addCustomFile('Invalid Entry', 42), 'MATLAB:validators:mustBeTextScalar');
            testCase.verifyError(@() testCase.exampleClass.addCustomFile('Invalid Entry', 'invalid.m', 42), 'RAT:InvalidOption');
            testCase.verifyError(@() testCase.exampleClass.addCustomFile('Invalid Entry', 'invalid.m', 'matlab', 42, 'other'), 'MATLAB:validators:mustBeTextScalar');
            testCase.verifyError(@() testCase.exampleClass.addCustomFile('Invalid Entry', 'invalid.m', 'matlab', '', 42), 'MATLAB:validators:mustBeTextScalar');

            % Unrecognised language
            testCase.verifyError(@() testCase.exampleClass.addCustomFile('Unrecognised language', 'file.m', 'fortran', ''), exceptions.invalidOption.errorID);

            % Duplicate custom object names
            testCase.verifyError(@() testCase.exampleClass.addCustomFile('DPPC Model'), exceptions.duplicateName.errorID);
        end

        function testSetCustomFile(testCase, testRow, inputData, expectedRow)
            testCase.exampleClass.setCustomFile(inputData{:});
            testCase.verifyEqual(testCase.exampleClass.varTable{testRow, :}, expectedRow, 'setCustomFile does not work correctly');
        end

        function testSetCustomFileInvalidType(testCase, invalidInputData)
            testCase.verifyError(@() testCase.exampleClass.setCustomFile(invalidInputData{:}), 'MATLAB:validators:mustBeTextScalar');
        end

        function testSetCustomFileInvalidInput(testCase)
            % Test setting values in the files table
            % If the inputs are invalid, it should raise an error

            % Invalid row
            testCase.verifyError(@() testCase.exampleClass.setCustomFile(0, 'Name', 'Invalid'), exceptions.indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleClass.setCustomFile(testCase.numRows+1, 'Name', 'Invalid'), exceptions.indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleClass.setCustomFile('Undefined row', 'Name', 'Invalid'), exceptions.nameNotRecognised.errorID);
            
            % Invalid path
            testCase.verifyError(@() testCase.exampleClass.setCustomFile(1, 'Path', 'Fortran'), exceptions.invalidPath.errorID)

            % Unrecognised language
            testCase.verifyError(@() testCase.exampleClass.setCustomFile(1, 'Language', 'Fortran'), exceptions.invalidOption.errorID)

            % Duplicate custom object names
            testCase.verifyError(@() testCase.exampleClass.setCustomFile(2, 'Name', 'DPPC Model'), exceptions.duplicateName.errorID)
            % Bad function name
            testCase.verifyWarning(@() testCase.exampleClass.setCustomFile(2, 'FunctionName', 'newModel'), '');
            testCase.verifyEqual(testCase.exampleClass.varTable{2, 3}, "customBilayer", 'setCustomFile does not work correctly');
            testCase.verifyError(@() testCase.exampleClass.setCustomFile(2, 'name', 'DPPC Model'), exceptions.duplicateName.errorID)
        end

        function testSetCustomFileInvalidNumberOfParams(testCase)
            % If we call "setCustomFile" with fewer than three values or
            % an even number of values (i.e., not name-value pairs) it
            % should raise an error
            %testCase.verifyError(@() testCase.exampleClass.setCustomFile(1), 'MATLAB:TooManyInputs');
            testCase.verifyError(@() testCase.exampleClass.setCustomFile(1, 1), 'MATLAB:TooManyInputs');
            testCase.verifyError(@() testCase.exampleClass.setCustomFile(2, 'Name', 'New Model', 'Language'), 'MATLAB:TooManyInputs');      
        end

        function testRemoveCustomFile(testCase)
            remainingRows = testCase.exampleClass.varTable(2:end,:);
            testCase.exampleClass.removeCustomFile(1);

            testCase.verifyEqual(testCase.exampleClass.varTable, remainingRows, 'removeCustomFile does not work correctly');
        end

        function testRemoveCustomFileName(testCase)
            remainingRows = testCase.exampleClass.varTable(2:end,:);
            testCase.exampleClass.removeCustomFile('DPPC Model');

            testCase.verifyEqual(testCase.exampleClass.varTable, remainingRows, 'removeCustomFile does not work correctly');
        end

        function testRemoveCustomFileMultiple(testCase)
            % Test removing multiple rows from a file table
            
            % Put dummy third row in table
            testCase.exampleClass.varTable(3, :) = {'Test Row', '', '', '', ''};

            remainingRows = testCase.exampleClass.varTable(2,:);
            testCase.exampleClass.removeCustomFile([1 3]);

            testCase.verifyEqual(testCase.exampleClass.varTable, remainingRows, 'removeCustomFile does not work correctly');
        end

        function testRemoveCustomFileMultipleCell(testCase)
            % Test removing multiple rows from a file table by name
            
            % Put dummy third row in table
            testCase.exampleClass.varTable(3, :) = {'Test Row', '', '', '', ''};

            remainingRows = testCase.exampleClass.varTable(2,:);
            testCase.exampleClass.removeCustomFile({'DPPC Model', 'Test Row'});

            testCase.verifyEqual(testCase.exampleClass.varTable, remainingRows, 'removeCustomFile does not work correctly');
        end

        function testDisplayTable(testCase)
            % Test the routine to display the file table by capturing the
            % output and comparing with the table headers and data

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display = textscan(evalc('testCase.exampleClass.displayTable()'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};

            % Check headers
            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove "<strong>" tags
            outVars = eraseBetween(strip(regexprep(displayedTable(1), '\s+', ' ')), '<', '>','Boundaries','inclusive');

            % Convert table variable names to a string array and join into
            % a single string
            varString = strip(strjoin(string(testCase.exampleClass.varTable.Properties.VariableNames)));
            testCase.verifyEqual(outVars, varString, 'Table headers do not match variable names');

            % Make sure the output has the right number of rows before
            % continuing - output table header, divider row and the
            % defined table rows
            testCase.assertSize(displayedTable, [testCase.numRows+2, 1], 'Table does not have the right number of rows');

            % Check table contents - when displayed, row 2 is a set of
            % lines, so row 3 is the first line of data
            for i = 1:testCase.numRows
                
                % Replace multiple spaces in output table with a single
                % space using regular expressions, and remove '"'
                % characters
                outRow = strip(replace(regexprep(displayedTable(i+2), '\s+', ' '), '"', ''));
                testCase.exampleClass.varTable{i, 3} = {'-'};
                % Get data from this row and join into a single string
                rowString = strip(strjoin(testCase.exampleClass.varTable{i,:}));
                testCase.verifyEqual(outRow, rowString, 'Row does not contain the correct data');

            end
        end

        function testDisplayTableEmpty(testCase)
            % Test the routine to display the file table of an empty
            % custom file class by capturing the output and comparing with
            % the table headers and data
            emptyClass = customFileClass();

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display = textscan(evalc('emptyClass.displayTable()'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};

            % Check headers
            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove "<strong>" tags
            outVars = eraseBetween(strip(regexprep(displayedTable(1), '\s+', ' ')), '<', '>','Boundaries','inclusive');

            % Convert table variable names to a string array and join into
            % a single string
            varString = strip(strjoin(string(emptyClass.varTable.Properties.VariableNames)));
            testCase.verifyEqual(outVars, varString, 'Table headers do not match variable names');

            % Make sure the output has the right number of rows before
            % continuing
            testCase.assertSize(displayedTable, [3, 1], 'Table does not have the right number of rows');

            % Replace multiple spaces in output table with a single
            % space using regular expressions
            outRow = strip(regexprep(displayedTable(3), '\s+', ' '));
            rowString =""""" """" """" """" """"";
            testCase.verifyEqual(outRow, rowString, 'Row does not contain the correct data');
        end

        function testDisplayTableEmptyRow(testCase)
            % Test the routine to display the file table of a custom file
            % class with empty row entries by capturing the output and
            % comparing with the table headers and data
            emptyRowClass = customFileClass();
            emptyRowClass.varTable(1, :) = {'Test Row', '', '', '', ''};

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display = textscan(evalc('emptyRowClass.displayTable()'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};

            % Check headers
            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove "<strong>" tags
            outVars = eraseBetween(strip(regexprep(displayedTable(1), '\s+', ' ')), '<', '>','Boundaries','inclusive');

            % Convert table variable names to a string array and join into
            % a single string
            varString = strip(strjoin(string(emptyRowClass.varTable.Properties.VariableNames)));
            testCase.verifyEqual(outVars, varString, 'Table headers do not match variable names');

            % Make sure the output has the right number of rows before
            % continuing
            testCase.assertSize(displayedTable, [3, 1], 'Table does not have the right number of rows');

            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove '"' characters
            outRow = strip(replace(regexprep(displayedTable(3), '\s+', ' '), '"', ''));
            rowString = "Test Row No File - - pwd";
            testCase.verifyEqual(outRow, rowString, 'Row does not contain the correct data');
        end

        function testDisplayTableLongPath(testCase)
            % Test the routine to display the file table of a custom file
            % class with a long file path by capturing the output and
            % comparing with the table headers and data
            longPathClass = customFileClass();
            longPath = 'C:\Documents\MATLAB\RAT\examples\miscellaneous\alternativeLanguages';
            longPathClass.varTable(1, :) = {'Test Row', '', '', '', longPath};

            % Capture the standard output and format into string array -
            % one element for each row of the output
            display = textscan(evalc('longPathClass.displayTable()'),'%s','Delimiter','\r','TextType','string');
            displayedTable = display{:};

            % Check headers
            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove "<strong>" tags
            outVars = eraseBetween(strip(regexprep(displayedTable(1), '\s+', ' ')), '<', '>','Boundaries','inclusive');

            % Convert table variable names to a string array and join into
            % a single string
            varString = strip(strjoin(string(longPathClass.varTable.Properties.VariableNames)));
            testCase.verifyEqual(outVars, varString, 'Table headers do not match variable names');

            % Make sure the output has the right number of rows before
            % continuing
            testCase.assertSize(displayedTable, [3, 1], 'Table does not have the right number of rows');

            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove '"' characters
            outRow = strip(replace(regexprep(displayedTable(3), '\s+', ' '), '"', ''));
            rowString = "Test Row No File - - ...LAB\RAT\examples\miscellaneous\alternativeLanguages";
            testCase.verifyEqual(outRow, rowString, 'Row does not contain the correct data');
        end

        function testToStruct(testCase)
            fileStruct = testCase.exampleClass.toStruct();
            testCase.verifyClass(fileStruct, 'struct');
            for i = 1:testCase.numRows
                [~, handle, ~] = fileparts(testCase.exampleClass.varTable{i, 2});
                testCase.verifyEqual(string(fileStruct.files{i}), handle);
            end
            import matlab.unittest.fixtures.TemporaryFolderFixture
            import matlab.unittest.fixtures.CurrentFolderFixture
            fixture = testCase.applyFixture(TemporaryFolderFixture);
            filename = fullfile(fixture.Folder, 'DPPCCustomXY.m');
            fid = fopen(filename, 'w');
            testCase.addTeardown(@fclose, fid)
            
            old = testCase.exampleClass.varTable{1, 5};  
            testCase.exampleClass.setCustomFile(1, 'path', fixture.Folder);
            testCase.verifyWarning(@() testCase.exampleClass.toStruct(), '', 'CustomFile conflict warning should be triggered');
            testCase.verifyWarningFree(@() testCase.exampleClass.toStruct(), 'CustomFile conflict warning should be triggered only once');
            testCase.exampleClass.varTable{1, 5} = old;
            testCase.exampleClass.varTable{1, 3} = {'randomName'};
            testCase.verifyError(@() testCase.exampleClass.toStruct(), exceptions.invalidPath.errorID);
        end

        function testToStructEmpty(testCase)
            % Test converting an empty custom file class to a struct
            emptyClass = customFileClass();
            fileStruct = emptyClass.toStruct();
            testCase.verifyClass(fileStruct, 'struct');
            testCase.verifyEmpty(fileStruct.files);
        end

        function testToStructWrapper(testCase)
            % Test converting an custom file class to a struct correctly
            % interprets the present working directory
            import matlab.unittest.fixtures.TemporaryFolderFixture
            import matlab.unittest.fixtures.CurrentFolderFixture
            fixture = testCase.applyFixture(TemporaryFolderFixture);
            
            filename = fullfile(fixture.Folder, 'file.py');
            fid = fopen(filename, 'w');
            testCase.addTeardown(@fclose, fid)

            customClass = customFileClass('Test python', 'file.py', 'python');
            testCase.verifyError(@() customClass.toStruct(), exceptions.invalidPath.errorID);

            customClass.varTable(1,:) = {'Test python', 'file.py', '', 'python', fixture.Folder};
            addPathMock = mockFunction(testCase, 'addpath');
                        
            fileStruct = customClass.toStruct();
            wrapper = customClass.wrappers{1};
            testCase.verifyClass(fileStruct, 'struct');
            testCase.verifyEqual(wrapper.libPath, filename);
            testCase.verifyEqual(fileStruct.files{:}, wrapper.getHandle());
            delete(addPathMock)

            filename = fullfile(fixture.Folder, 'customBilayer.dll');
            fid = fopen(filename, 'w');
            testCase.addTeardown(@fclose, fid)

            testCase.applyFixture(CurrentFolderFixture(fixture.Folder))
            fakeID = '123456789';
            wrapperMexMock = mockFunction(testCase, 'wrapperMex', 'returnValues', {fakeID});
            rmPathMock = mockFunction(testCase, 'rmpath');
            customClass.varTable(2,:) = {'DSPC Model', 'customBilayer.dll', '', 'cpp', ''};
            fileStruct = customClass.toStruct();
            wrapper2 = customClass.wrappers{2};
            testCase.verifyEqual(wrapper2.libPath, filename);
            testCase.verifyEqual(fileStruct.files, {wrapper.getHandle(); fakeID});
            delete(customClass);
            testCase.assertEqual(wrapperMexMock.callCount, 2);   
        end

    end

end
