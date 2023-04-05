classdef testExceptions < matlab.unittest.TestCase
%%
% testExceptions Class based unit tests for the custom exceptions defined
% in the RAT utilities.
%
% In this class, we test:
% duplicateName, indexOutofRange, invalidInput, invalidNumberofInputs,
% invalidOption, invalidType, invalidValue, nameNotRecognised,
% routineNotSupported
%
% Paul Sharp 14/02/23
%
%% Declare properties and parameters

    properties (TestParameter)
        customException = {@duplicateName,...
                           @indexOutOfRange,...
                           @invalidNumberOfInputs,...
                           @invalidOption,...
                           @invalidType,...
                           @invalidValue,...
                           @nameNotRecognised,...
                           @unrecognizedR1Problem
                           @routineNotSupported
                           }
        identifier = {'RAT:DuplicateName',...
                      'RAT:IndexOutOfRange',...
                      'RAT:InvalidNumberOfInputs',...
                      'RAT:InvalidOption',...
                      'RAT:InvalidType',...
                      'RAT:InvalidValue',...
                      'RAT:NameNotRecognised',...
                      'RAT:unrecognizedR1Problem',...
                      'RAT:RoutineNotSupported'
                      }
        defaultMessage = {'The given name has already been used',...
                          'The given index is out of range',...
                          'Invalid number of inputs for this routine',...
                          'The given value is not supported',...
                          'The given value is not a valid type for this variable',...
                          'The input has a correct type but an incorrect value'...
                          'The given name is not recognised',...
                          'R1Problem does not have right format'
                          'This routine is not supported'
                          }
    end

%% Test Exception Classes

    methods (Test, ParameterCombination='sequential')

        function testException(testCase, customException, identifier, defaultMessage)

            % Check default
            ME = customException();
            testCase.verifyEqual(ME.identifier, identifier);
            testCase.verifyEqual(ME.message, defaultMessage);

            testCase.verifyError(@() throw(ME), identifier);

            % Check custom message
            customMessage = 'Message from the test suite';
            ME = customException(customMessage);
            testCase.verifyEqual(ME.identifier, identifier);
            testCase.verifyEqual(ME.message, customMessage);

            % A non-text message should raise an error
            testCase.verifyError(@() customException(42), 'MATLAB:validators:mustBeTextScalar');

        end

    end

end