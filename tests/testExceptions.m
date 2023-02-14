classdef testExceptions < matlab.unittest.TestCase
%%
% testExceptions Class based unit tests for the custom exceptions defined
% in the RAT utilities.
%
% In this class, we test:
% duplicateName, indexOutofRange, invalidInput, invalidNumberofInputs,
% invalidOption, invalidType, nameNotRecognised
%
% Paul Sharp 14/02/23
%
%% Declare properties and parameters

    properties (TestParameter)
        customException = {@duplicateName,...
                           @indexOutOfRange,...
                           @invalidInput,...
                           @invalidNumberOfInputs,...
                           @invalidOption,...
                           @invalidType,...
                           @nameNotRecognised
                           }
        identifier = {'RAT:DuplicateName',...
                      'RAT:IndexOutOfRange',...
                      'RAT:InvalidInput',...
                      'RAT:InvalidNumberOfInputs',...
                      'RAT:InvalidOption',...
                      'RAT:InvalidType',...
                      'RAT:NameNotRecognised'
                      }
        defaultMessage = {'The given name has already been used',...
                          'The given index is out of range',...
                          'The input to this routine is invalid',...
                          'Invalid number of inputs for this routine',...
                          'The given value is not supported',...
                          'The given value is not a valid type for this variable',...
                          'The given name is not recognised'
                          }
    end

%% Test Exception Classes

    methods (Test, ParameterCombination="sequential")

        function testException(testCase, customException, identifier, defaultMessage)

            % Check default
            ME = customException();
            testCase.verifyEqual(ME.identifier, identifier);
            testCase.verifyEqual(ME.message, defaultMessage);

            testCase.verifyError(@() throw(ME), identifier);

            % Check custom message
            ME = customException('Message from the test suite');
            testCase.verifyEqual(ME.identifier, identifier);
            testCase.verifyEqual(ME.message, 'Message from the test suite');

            % A non-text message should raise an error
            testCase.verifyError(@() duplicateName(42), 'MATLAB:validators:mustBeTextScalar');

        end

    end

end