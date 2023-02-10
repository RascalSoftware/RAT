classdef testCustomFileClass < matlab.unittest.TestCase
%%
% testCustomFileClass Class based unit tests for the customFileClass
% used within the Project Class in RAT.
%
% In this class, we test:
%
% We use an example custom file class combining the custom file classes
% from the example calculations "DPPC_customXY.m" and
% "orsoDSPC_custLay_script.m"
%
% Paul Sharp 10/02/23
%
%% Declare properties and parameters

    properties (TestParameter)
        fileInput = {{'New Entry'},...
                     {'Row and file name', 'file.m'},...
                     {'Full entry', 'otherFile.m', 'matlab', 'pwd'}
                    }
        addedRow = {{'New Entry','','matlab','pwd'},...
                    {'Row and file name','file.m','octave','pwd'},...
                    {'Full entry', 'otherFile.m', 'matlab', 'pwd'}
                   }
        testRow = {1, 1, 2, 2}
        inputData = {{'DPPC Model', 'name', 'New Model'},...
                     {1, 'filename', 'model.m'},...
                     {'DSPC Model', 'language', 'octave'},...
                     {2, 'language', 'octave', 'filename', 'model.m', 'name', 'New Model'},...
                    }
        expectedRow = {["New Model", "DPPC_customXY.m", "matlab", "../../"],...
                       ["DPPC Model", "model.m", "matlab", "../../"],...
                       ["DSPC Model", "customBilayer.m", "octave", "../../"],...
                       ["New Model", "model.m", "octave", "../../"],...
                      }
        invalidInputData = {{'DPPC Model', 'name', 42},...
                            {1, 'filename', datetime('today')},...
                            {'DSPC Model', 'language', table()},...
                            {2, 'path', {'path', 'to', 'file'}}
                           }

    end

    properties
        exampleClass;           % Example custom file class for testing
        initialFileTableEmpty   % Empty table to compare to initialisation
        initialFileTableOneRow  % Table with one row to compare to initialisation
        numRows                 % Number of rows in exampleClass.fileTable
        numCols                 % Number of columns in exampleClass.fileTable
    end

%% Set up test data

    methods (TestClassSetup)

        function initialiseFileTable(testCase)
            % Set up an empty file table and a table with one row
            tableTypes = {'string','string','string','string'};
            tableNames = {'Name','Filename','Language','Path'};

            testCase.initialFileTableEmpty = table('Size',[0 4],'VariableTypes',tableTypes,'VariableNames',tableNames);

            testCase.initialFileTableOneRow = table('Size',[1 4],'VariableTypes',tableTypes,'VariableNames',tableNames);
            testCase.initialFileTableOneRow{1, :} = {'DPPC Model', 'DPPC_customXY.m', 'matlab', '../../'};
        end

    end

    methods (TestMethodSetup)

        function initialiseCustomFileClass(testCase)
            % Set up an example custom file class for testing
            % These examples are used in the example calculations
            % "DPPC_customXY.m" and "orsoDSPC_custLay_script.m"
            testCase.exampleClass = customFileClass();

            testCase.exampleClass.fileTable(1,:) = {'DPPC Model', 'DPPC_customXY.m', 'matlab', '../../'};
            testCase.exampleClass.fileTable(2,:) = {'DSPC Model', 'customBilayer.m', 'matlab', '../../'};

            testCase.numRows = height(testCase.exampleClass.fileTable);
            testCase.numCols = width(testCase.exampleClass.fileTable);
        end

    end

%% Test Layers Real SLD Class Routines

    methods (Test, ParameterCombination="sequential")

        function testInitialiseCustomFileClassEmpty(testCase)
            % On initialisation we set up a custom file class with an
            % either an empty file table, or a table with a single row
            testClass = customFileClass();

            testCase.verifySize(testClass.fileTable, [0 4], "customFileClass does not initialise correctly");
            testCase.verifyEqual(testClass.fileTable, testCase.initialFileTableEmpty, "customFileClass does not initialise correctly");
        end

        function testInitialiseCustomFileClassOneRow(testCase)
            % On initialisation we set up a custom file class with an
            % either an empty file table, or a table with a single row
            testClass = customFileClass({'DPPC Model', 'DPPC_customXY.m', 'matlab', '../../'});

            testCase.verifySize(testClass.fileTable, [1 4], "customFileClass does not initialise correctly");
            testCase.verifyEqual(testClass.fileTable, testCase.initialFileTableOneRow, "customFileClass does not initialise correctly");
        end

        function testAddFile(testCase, fileInput, addedRow)
            % Test adding a custom file entry to the custom file class.
            % We can add a custom file entry with no parameters, just a
            % custom object name, a custom object name with the filename,
            % and a fully defined custom file entry consisting of: a
            % custom object name, a filename, language and file path.  
            expectedTable = [testCase.exampleClass.fileTable; addedRow];

            testCase.exampleClass.addFile(fileInput);

            testCase.verifyEqual(testCase.exampleClass.fileTable, expectedTable, "addFile does not work correctly");
        end

        function testAddFileEmpty(testCase)
            % Test adding a custom file entry to the custom file class.
            % We can add a custom file entry with no parameters, just a
            % custom object name, a custom object name with the filename,
            % and a fully defined custom file entry consisting of: a
            % custom object name, a filename, language and file path.
            newRow = {'New custom file 1', '', 'Octave', 'pwd'};
            expectedTable = [testCase.exampleClass.fileTable; newRow];

            testCase.exampleClass.addFile();

            testCase.verifyEqual(testCase.exampleClass.fileTable, expectedTable, "addFile does not work correctly");
        end

        function testAddFileInvalid(testCase)
            % Test adding a custom file entry to the custom file class.
            % If we use an invalid set of custom file parameters it should
            % raise an error

            % Invalid length for custom file parameters
            testCase.verifyError(@() testCase.exampleClass.addFile({}), 'customFileClass:addFile:InvalidInput')
            testCase.verifyError(@() testCase.exampleClass.addFile({'Invalid Entry', 'matlab', 'pwd'}), 'customFileClass:addFile:InvalidInput')
            testCase.verifyError(@() testCase.exampleClass.addFile({'Invalid Entry', 'invalid.m', 'matlab', 'pwd', 'other'}), 'customFileClass:addFile:InvalidInput')

            % Invalid types
            testCase.verifyError(@() testCase.exampleClass.addFile({42}), 'customFileClass:addFile:InvalidType')
            % Unreachable without testing appendNewRow directly
            % (but method is (~will be) private)
            %testCase.verifyError(@() testCase.exampleClass.addFile({'Invalid file', 42}), 'customFileClass:appendNewRow:InvalidType')
            %testCase.verifyError(@() testCase.exampleClass.addFile({'Invalid file', 'file.m', 'matlab', 42}), 'customFileClass:appendNewRow:InvalidType')

            % Unrecognised language
            testCase.verifyError(@() testCase.exampleClass.addFile({'Unrecognised language', 'file.m', 'fortran', 'pwd'}), 'customFileClass:appendNewRow:InvalidOption')

            % Duplicate custom object names
            testCase.verifyError(@() testCase.exampleClass.addFile({'DPPC Model'}), 'customFileClass:appendNewRow:DuplicateName')
        end

        function testSetCustomFile(testCase, testRow, inputData, expectedRow)
            testCase.exampleClass.setCustomFile(inputData);
            testCase.verifyEqual(testCase.exampleClass.fileTable{testRow, :}, expectedRow, "setCustomFile does not work correctly");
        end

        function testSetCustomFileInvalidType(testCase, invalidInputData)
            testCase.verifyError(@() testCase.exampleClass.setCustomFile(invalidInputData), 'MATLAB:InputParser:ArgumentFailedValidation');
        end

        function testSetCustomFileInvalidInput(testCase)
            % Test setting values in the files table
            % If the inputs are invalid, it should raise an error

            % Invalid row
            testCase.verifyError(@() testCase.exampleClass.setCustomFile({0, 'Name', 'Invalid'}), 'customFileClass:setCustomFile:IndexOutOfRange');
            testCase.verifyError(@() testCase.exampleClass.setCustomFile({testCase.numRows+1, 'Name', 'Invalid'}), 'customFileClass:setCustomFile:IndexOutOfRange');
            testCase.verifyError(@() testCase.exampleClass.setCustomFile({'Undefined row', 'Name', 'Invalid'}), 'customFileClass:setCustomFile:NameNotRecognised');

            % Unrecognised language
            testCase.verifyError(@() testCase.exampleClass.setCustomFile({1, 'Language', 'Fortran'}), 'customFileClass:setCustomLanguage:InvalidOption')

            % Duplicate custom object names
            testCase.verifyError(@() testCase.exampleClass.setCustomFile({2, 'Name', 'DPPC Model'}), 'customFileClass:setCustomName:DuplicateName')

            % !!!! THIS IS A BUG !!!!
            % Use a string rather than char for the name
            testCase.verifyError(@() testCase.exampleClass.setCustomFile({1, 'Name', "String Name"}), 'customFileClass:setCustomName:InvalidType')
            testCase.verifyError(@() testCase.exampleClass.setCustomFile({2, 'Filename', "String Name"}), 'customFileClass:setFileName:InvalidType')

        end

        function testSetCustomFileTooFewParams(testCase)
            % If we call "setCustomFile" with a cell array containing
            % fewer than three values it should raise an error
            testCase.verifyError(@() testCase.exampleClass.setCustomFile({1}), 'customFileClass:setCustomFile:TooFewInputs');
            testCase.verifyError(@() testCase.exampleClass.setCustomFile({1, 1}), 'customFileClass:setCustomFile:TooFewInputs');
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
            varString = strip(strjoin(string(testCase.exampleClass.fileTable.Properties.VariableNames)));
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
                rowString = strip(strjoin(testCase.exampleClass.fileTable{i,:}));
                testCase.verifyEqual(outRow, rowString, "Row does not contain the correct data");

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
            varString = strip(strjoin(string(emptyClass.fileTable.Properties.VariableNames)));
            testCase.verifyEqual(outVars, varString, 'Table headers do not match variable names');

            % Make sure the output has the right number of rows before
            % continuing
            testCase.assertSize(displayedTable, [4, 1], 'Table does not have the right number of rows');

            % Replace multiple spaces in output table with a single
            % space using regular expressions
            outRow = strip(regexprep(displayedTable(4), '\s+', ' '));
            rowString = string('"" "" "" ""');
            testCase.verifyEqual(outRow, rowString, "Row does not contain the correct data");
        end

        function testDisplayCustomFileObjectEmptyRow(testCase)
            % Test the routine to display the file table of a custom file
            % class with empty row entries by capturing the output and
            % comparing with the table headers and data
            emptyRowClass = customFileClass({'Test Row', '', '', ''});

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
            varString = strip(strjoin(string(emptyRowClass.fileTable.Properties.VariableNames)));
            testCase.verifyEqual(outVars, varString, 'Table headers do not match variable names');

            % Make sure the output has the right number of rows before
            % continuing
            testCase.assertSize(displayedTable, [4, 1], 'Table does not have the right number of rows');

            % Replace multiple spaces in output table with a single
            % space using regular expressions, and remove '"' characters
            outRow = strip(replace(regexprep(displayedTable(4), '\s+', ' '), '"', ''));
            rowString = "Test Row No File - pwd";
            testCase.verifyEqual(outRow, rowString, "Row does not contain the correct data");
        end

        function testToStruct(testCase)
            fileStruct = testCase.exampleClass.toStruct();
            testCase.verifyClass(fileStruct, 'struct');
            for i = 1:testCase.numRows
                testCase.verifyEqual(string(fileStruct.files{i}), testCase.exampleClass.fileTable{i, 2:end});
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
            emptyClass = customFileClass({'Test pwd', 'file.m', 'matlab', 'pwd'});
            fileStruct = emptyClass.toStruct();
            testCase.verifyClass(fileStruct, 'struct');
            testCase.verifyEqual(string(fileStruct.files{:}), ["file.m" "matlab" pwd]);
        end



    end

end
