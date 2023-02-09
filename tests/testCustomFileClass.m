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
% Paul Sharp 09/02/23
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
    end

    properties
        exampleClass;           % Example layers class for testing
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
            testCase.verifyError(@() testCase.exampleClass.addFile({}), ?MException)
            testCase.verifyError(@() testCase.exampleClass.addFile({'Invalid Entry', 'matlab', 'pwd'}), ?MException)
            testCase.verifyError(@() testCase.exampleClass.addFile({'Invalid Entry', 'invalid.m', 'matlab', 'pwd', 'other'}), ?MException)

            % Duplicate custom object names
            testCase.verifyError(@() testCase.exampleClass.addFile({'DPPC Model'}), ?MException)        
        end

    end

end