classdef testProjects < matlab.unittest.TestCase
%%
% testProjects Class based unit tests for the project routines used to set
% up calculations in RAT.
%
% In this class, we test:
% absorption, domains, magnetic, magneticDomains, nonPolarised, oilWater 
%
% Paul Sharp 05/04/23
%
%% Declare properties and parameters

    properties (TestParameter)
        project = {@absorption, ...
                   @domains, ...
                   @magnetic, ...
                   @magneticDomains, ...
                   @nonPolarised, ...
                   @oilWater ...
                   }
        calculationType = {calculationTypes.Absorption.value, ...
                           calculationTypes.Domains.value, ...
                           calculationTypes.Magnetic.value, ...
                           calculationTypes.MagneticDomains.value, ...
                           calculationTypes.Standard.value, ...
                           calculationTypes.OilWater.value ...
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

        function testProjectTypes(testCase, project, calculationType, SLDValues, domainsCalc)
            % Test setup
            problem = project();
            projectString = func2str(project);

            testCase.verifyEqual(problem.experimentName, '', sprintf('%s project does not initialise correctly', projectString));
            testCase.verifyEqual(problem.calculationType, calculationType, sprintf('%s project does not initialise correctly', projectString));

            % Test for correct layers and contrasts
            layerColumns = [{'Name', 'Thickness'}, SLDValues, {'Roughness', 'Hydration', 'Hydrate with'}];
            testCase.verifyEqual(problem.layers.layersTable.Properties.VariableNames, layerColumns, sprintf('%s project contrasts class does not initialise correctly', projectString));
            testCase.verifyEqual(problem.contrasts.domainsCalc, domainsCalc, sprintf('%s project contrasts class does not initialise correctly', projectString));

            % Test setting experiment name
            newName = 'New Project Name';
            problem = project(newName);
            testCase.verifyEqual(problem.experimentName, newName, sprintf('%s project does not initialise correctly', projectString));
            testCase.verifyError(@() project(1), 'MATLAB:validators:mustBeTextScalar');
        end

    end
end
