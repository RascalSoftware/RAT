classdef testCreateProject < matlab.unittest.TestCase
%%
% testProjects Class based unit tests for the project routine used to set
% up calculations in RAT.
%
%% Declare properties and parameters

    properties (TestParameter)
        calculationType = {calculationTypes.Domains, ...
                           calculationTypes.Normal, ...
                           calculationTypes.Normal, ...
                           }
        SLDValues = {{'SLD'}, ...
                     {'SLD Real', 'SLD Imaginary'}, ...
                     {'SLD'}, ...
                     }
        domainsCalc = {true, false, false}
        absorption = {false, true, false}
    end

%% Test Project Classes

    methods (Test, ParameterCombination='sequential')

        function testProjectTypes(testCase, calculationType, SLDValues, domainsCalc, absorption)
            % Test setup
            project = createProject(calc=calculationType, absorption=absorption);

            testCase.verifyEqual(project.experimentName, '', 'project does not initialise correctly');
            testCase.verifyEqual(project.calculationType, calculationType.value, 'project does not initialise correctly');

            % Test for correct layers and contrasts
            layerColumns = [{'Name', 'Thickness'}, SLDValues, {'Roughness', 'Hydration', 'Hydrate with'}];
            testCase.verifyEqual(project.layers.varTable.Properties.VariableNames, layerColumns, 'project layers class does not initialise correctly');
            testCase.verifyEqual(project.contrasts.isDomains, domainsCalc, 'project contrasts class does not initialise correctly');

            % Test setting experiment name
            newName = 'New Project Name';
            project = createProject(name=newName, calc=calculationType, absorption=absorption);
            testCase.verifyEqual(project.experimentName, newName, 'project does not initialise correctly');
            testCase.verifyError(@() createProject(name=1), 'MATLAB:validators:mustBeTextScalar');
        end

        function testProtectedParameters(testCase)
            % Ensure errors are raised when attempting to remove protected
            % parameters
            project = createProject(calc=calculationTypes.Normal);
            testCase.verifyError(@() project.removeParameter(1), exceptions.invalidOption.errorID);
            testCase.verifyError(@() project.removeParameter("Substrate Roughness"), exceptions.invalidOption.errorID);
        end

    end
end
