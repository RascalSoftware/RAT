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
                           }
        identifier = {'RAT:DuplicateName',...
                      'RAT:IndexOutOfRange',...
                      }
        defaultMessage = {'The given name has already been used',...
                          'The given index is out of range',...
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