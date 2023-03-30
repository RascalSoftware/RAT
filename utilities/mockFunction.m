classdef mockFunction < handle
    properties
       arguments;
       callCount; 
       exceptionID;
       returnValues;
       filename = '';     % path of function file
       functionName = ''; % Name of function
    end
    methods
        function obj = mockFunction(testCase, functionName, options)
            % Creates a mockFunction object. This creates a mock function with the given function name
            % in a temporary directory and add the directory to the path using a fixture. The mock can 
            % be set to return a given value or throw an exception with a given ID. This is based on this 
            % https://github.com/SpinW/spinw/blob/master/%2Bsw_tests/%2Butilities/mock_function.m 
            %
            % mock = mockFunction(testCase, 'randomName');
            % mock = mockFunction(testCase, 'randomName', 'returnValues', {2});
            % mock = mockFunction(testCase, 'randomName', 'exceptionID', 'invalidError');
            arguments
               testCase matlab.unittest.TestCase
               functionName {mustBeValidVariableName}
               options.returnValues cell = {[]} 
               options.exceptionID {mustBeTextScalar} = ''
            end
            import matlab.unittest.fixtures.TemporaryFolderFixture
            import matlab.unittest.fixtures.PathFixture;
            tempFolderFixture = testCase.applyFixture(TemporaryFolderFixture);
            testCase.applyFixture(PathFixture(tempFolderFixture.Folder));
                      
            fnstr = ['function varargout = %s(varargin)\n' ...
                     '    persistent callCount;\n' ...
                     '    persistent arguments;\n' ...
                     '    persistent returnValues;\n' ...
                     '    persistent exceptionID;\n' ...
                     '    if nargin > 0 && ischar(varargin{1}) && strcmp(varargin{1}, ''initializeMockVariables'')\n' ...
                     '        callCount = 0;\n' ...
                     '        arguments = {};\n' ...
                     '        returnValues = {[]};\n' ...
                     '        exceptionID = '''';\n' ...
                     '        return;\n' ...
                     '    end\n' ...
                     '    if nargin > 0 && ischar(varargin{1}) && strcmp(varargin{1}, ''getMockVariables'')\n' ...
                     '        varargout = {callCount arguments returnValues exceptionID};\n' ...
                     '        return;\n' ...
                     '    end\n' ...
                     '    if nargin == 2 && ischar(varargin{1})\n' ...
                     '        if strcmp(varargin{1}, ''setMockReturnValues'')\n' ...
                     '            returnValues = varargin{2};\n' ...
                     '            return;\n' ...
                     '        end\n' ...
                     '        if strcmp(varargin{1}, ''setMockExceptionID'')\n' ...
                     '            exceptionID = varargin{2};\n' ...
                     '            return;\n' ...
                     '        end\n' ...
                     '    end\n' ...
                     '    if isempty(callCount)\n' ...
                     '        callCount = 1;\n' ...
                     '        arguments = {varargin};\n' ...
                     '    else\n' ...
                     '        callCount = callCount + 1;\n' ...
                     '        arguments = [arguments {varargin}];\n' ...
                     '    end\n' ...
                     '    if ~isempty(exceptionID)\n' ...
                     '        throw(MException(exceptionID, ''error''));\n' ...
                     '    end\n' ...
                     '    if nargout > 0\n' ...
                     '        varargout = returnValues;\n' ...
                     '    end\n' ...
                     'end\n'];
            
            obj.functionName = functionName;
            obj.filename = fullfile(tempFolderFixture.Folder, sprintf('%s.m', functionName));
            fid = fopen(obj.filename, 'w');
            fprintf(fid, fnstr, functionName);
            fclose(fid);
            
            % Wait for file
            for i=1:3
                pause(0.01);
                if strcmp(which(functionName), obj.filename)
                    break;
                end
            end
            feval(obj.functionName, 'initializeMockVariables')
            obj.returnValues = options.returnValues;
            obj.exceptionID = options.exceptionID;
        end
        
        function delete(obj)
            delete(obj.filename);
        end

        function reset(obj)
            % Resets the call count and arguments of the mock. The returnValues and 
            % exceptionID are unchanged
            %
            % mock.reset()
            [~, ~, values, exception] = feval(obj.functionName, 'getMockVariables');
            feval(obj.functionName, 'initializeMockVariables')
            obj.returnValues =values;
            obj.exceptionID = exception;
        end

        function callCount = get.callCount(obj)
            % Gets the number of times the mock is called
            %
            % count = mock.callCount
            [callCount, ~, ~, ~] = feval(obj.functionName, 'getMockVariables');
        end
        
        function arguments = get.arguments(obj)
            % Gets the arguments passed to the mock function
            %
            % args = mock.arguments
            [~, arguments, ~, ~] = feval(obj.functionName, 'getMockVariables');
        end
        
        function exceptionID = get.exceptionID(obj)
            % Gets the ID of exception to throw
            %
            % exceptionID = mock.exceptionID
            [~, ~, ~, exceptionID] = feval(obj.functionName, 'getMockVariables');
        end

        function returnValues = get.returnValues(obj)
            % Gets the return values for the mock
            %
            % values = mock.returnValues
            [~, ~, returnValues, ~] = feval(obj.functionName, 'getMockVariables');
        end

        function set.exceptionID(obj, value)
            % Sets the exception ID for the mock. Expects a text value
            %
            % mock.exceptionID = 'invalidValue'
            arguments
               obj mockFunction
               value {mustBeTextScalar}
            end
            feval(obj.functionName, 'setMockExceptionID', value);
        end
        function set.returnValues(obj, value)
            % Sets the return values for the mock. Expects a cell array containing return values
            %
            % mock.returnValues = {2, 'name'}
            arguments
               obj mockFunction
               value cell
            end
            feval(obj.functionName, 'setMockReturnValues', value);
        end
    end
end
