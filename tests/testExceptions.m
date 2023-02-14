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


%% Set up test data


%% Test Exception Classes

    methods (Test, ParameterCombination="sequential")

        function testException(testCase)

            % Check default
            ME = duplicateName();
            testCase.verifyEqual(ME.identifier, 'RAT:DuplicateName');
            testCase.verifyEqual(ME.message, 'The given name has already been used');

            % Check custom message
            ME = duplicateName('Message from the test suite');
            testCase.verifyEqual(ME.identifier, 'RAT:DuplicateName');
            testCase.verifyEqual(ME.message, 'Message from the test suite');

            % A non-text message should raise an error
            testCase.verifyError(@() duplicateName(42), 'MATLAB:validators:mustBeTextScalar');

        end

    end

end