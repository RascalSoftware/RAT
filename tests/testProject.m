classdef testProject < matlab.unittest.TestCase
%%
% testProjects Class based unit tests for the project routine used to set
% up calculations in RAT.
%
% Paul Sharp 11/04/23
%
%% Declare properties and parameters

    properties (TestParameter)
        calculationType = {calculationTypes.Absorption, ...
                           calculationTypes.Domains, ...
                           calculationTypes.Magnetic, ...
                           calculationTypes.MagneticDomains, ...
                           calculationTypes.NonPolarised, ...
                           calculationTypes.OilWater ...
                           }
        SLDValues = {{'SLD Real', 'SLD Imaginary'}, ...
                     {'SLD'}, ...
                     {'SLD Real', 'SLD Imaginary', 'SLD Magnetic Real', 'SLD Magnetic Imaginary'}, ...
                     {'SLD Real', 'SLD Imaginary', 'SLD Magnetic Real', 'SLD Magnetic Imaginary'}, ...
                     {'SLD'}, ...
                     {'SLD'} ...
                     }
        domainsCalc = {false, true, false, true, false, false}
    end

%% Test Project Classes

    methods (Test, ParameterCombination='sequential')

        function testProjectTypes(testCase, calculationType, SLDValues, domainsCalc)
            % Test setup
            problem = project(type=calculationType);

            testCase.verifyEqual(problem.experimentName, '', 'project does not initialise correctly');
            testCase.verifyEqual(problem.calculationType, calculationType.value, 'project does not initialise correctly');

            % Test for correct layers and contrasts
            layerColumns = [{'Name', 'Thickness'}, SLDValues, {'Roughness', 'Hydration', 'Hydrate with'}];
            testCase.verifyEqual(problem.layers.layersTable.Properties.VariableNames, layerColumns, 'project layers class does not initialise correctly');
            testCase.verifyEqual(problem.contrasts.domainsCalc, domainsCalc, 'project contrasts class does not initialise correctly');

            % Test setting experiment name
            newName = 'New Project Name';
            problem = project(name=newName, type=calculationType);
            testCase.verifyEqual(problem.experimentName, newName, 'project does not initialise correctly');
            testCase.verifyError(@() project(name=1), 'MATLAB:validators:mustBeTextScalar');
        end

        function testProtectedParameters(testCase)
            % Ensure errors are raised when attempting to remove protected
            % parameters
            problem = project(type=calculationTypes.OilWater);
            testCase.verifyError(@() problem.removeParam(2), invalidOption.errorID);
            testCase.verifyError(@() problem.removeParam("Oil Roughness"), invalidOption.errorID);
        end

    end
end
