classdef testCustomFileClass < matlab.unittest.TestCase
%%
% testCustomFileClass Class based unit tests for the customFileClass
% used within the Project Class in RAT.
%
% In this class, we test:
%
% We use an example custom file class from example calculation
% "DPPC_customXY.m"
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
        inputData = {{'DPPC Model', 'name', 'New Model'},...
                     {1, 'filename', 'model.m'},...
                     {'DPPC Model', 'language', 'octave'},...
                     {1, 'language', 'octave', 'filename', 'model.m', 'name', 'New Model'},...
                    }
        expectedRow = {["New Model", "DPPC_customXY.m", "matlab", "../../"],...
                       ["DPPC Model", "model.m", "matlab", "../../"],...
                       ["DPPC Model", "DPPC_customXY.m", "octave", "../../"],...
                       ["New Model", "model.m", "octave", "../../"],...
                      }
        invalidInputData = {{'DPPC Model', 'name', 42},...
                            {1, 'filename', datetime('today')},...
                            {'DPPC Model', 'language', table()},...
                            {1, 'path', {'path', 'to', 'file'}}
                           }

    end

    properties
        exampleClass;           % Example custom file class for testing
        initialFileTable        % Empty table to compare to initialisation
        numRows                 % Number of rows in exampleClass.fileTable
        numCols                 % Number of columns in exampleClass.fileTable
    end

%% Set up test data

    methods (TestClassSetup)

        function initialiseFileTable(testCase)
            % Set up an empty file table 
            sz = [0 4];
            tableTypes = {'string','string','string','string'};
            tableNames = {'Name','Filename','Language','path'};

            testCase.initialFileTable = table('Size',sz,'VariableTypes',tableTypes,'VariableNames',tableNames);
        end

    end

    methods (TestMethodSetup)

        function initialiseCustomFileClass(testCase)
            % Set up an example custom file class for testing
            % This example is used in the example calculation
            % "DPPC_customXY.m"
            testCase.exampleClass = customFileClass();

            testCase.exampleClass.fileTable(1,:) = {'DPPC Model', 'DPPC_customXY.m', 'matlab', '../../'};

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
            testCase.verifyEqual(testClass.fileTable, testCase.initialFileTable, "customFileClass does not initialise correctly");
        end

        function testInitialiseCustomFileClassOneRow(testCase)
            % On initialisation we set up a custom file class with an
            % either an empty file table, or a table with a single row
            testClass = customFileClass({'DPPC Model', 'DPPC_customXY.m', 'matlab', '../../'});

            testCase.verifySize(testClass.fileTable, [1 4], "customFileClass does not initialise correctly");
            testCase.verifyEqual(testClass.fileTable, testCase.exampleClass.fileTable, "customFileClass does not initialise correctly");
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

        function testSetCustomFile(testCase, inputData, expectedRow)
            testCase.exampleClass.setCustomFile(inputData);
            testCase.verifyEqual(testCase.exampleClass.fileTable{1, :}, expectedRow, "setCustomFile does not work correctly");
        end

        function testSetCustomFileInvalidType(testCase, invalidInputData)
            testCase.verifyError(@() testCase.exampleClass.setCustomFile(invalidInputData), 'MATLAB:InputParser:ArgumentFailedValidation');
        end

        function testSetCustomFileInvalidInput(testCase)
            % Test setting values in the files table
            % If the inputs are invalid, it should raise an error

            %Invalid row
            testCase.verifyError(@() testCase.exampleClass.setCustomFile({0, 'Name', 'Invalid'}), 'customFileClass:setCustomFile:IndexOutOfRange');
            testCase.verifyError(@() testCase.exampleClass.setCustomFile({testCase.numRows+1, 'Name', 'Invalid'}), 'customFileClass:setCustomFile:IndexOutOfRange');
            testCase.verifyError(@() testCase.exampleClass.setCustomFile({'Undefined row', 'Name', 'Invalid'}), 'customFileClass:setCustomFile:NameNotRecognised');




        end

        function testSetCustomFileTooFewParams(testCase)
            % If we call "setCustomFile" with a cell array containing
            % fewer than three values it should raise an error
            testCase.verifyError(@() testCase.exampleClass.setCustomFile({1}), 'customFileClass:setCustomFile:TooFewInputs');
            testCase.verifyError(@() testCase.exampleClass.setCustomFile({1, 1}), 'customFileClass:setCustomFile:TooFewInputs');
        end

    end

end
