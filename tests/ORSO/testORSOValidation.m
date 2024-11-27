classdef testORSOValidation < matlab.unittest.TestCase
%%
% Runs ORSO Validations.
% (For now, we exclude test 4 and test 5, as these test resolution
% functions which will diverge until phase 2 of the resolution calculations
% is implemented)

    properties
        orsoTolerance = 1.0e-10;
    end

    properties (TestParameter)
        layersFile = {'test0.layers', 'test1.layers', 'test2.layers', 'test3.layers', 'test6.layers', 'test7.layers'}
        dataFile = {'test0.dat', 'test1.dat', 'test2.dat', 'test3.dat', 'test6.dat', 'test7.dat'}
        % layersFile = {'test0.layers', 'test1.layers', 'test2.layers', 'test3.layers', 'test0.layers', 'test1.layers', 'test6.layers', 'test7.layers'}
        % dataFile = {'test0.dat', 'test1.dat', 'test2.dat', 'test3.dat', 'test4.dat', 'test5.dat', 'test6.dat', 'test7.dat'}
    end

    methods (Test, ParameterCombination='sequential')

        function testORSO(testCase, layersFile, dataFile)
            testCase.verifyLessThanOrEqual(testORSOValidation.orsoTest(layersFile, dataFile), testCase.orsoTolerance, 'ORSO test has failed');
        end

    end

    methods (TestClassTeardown)
       function clear(~)
           close all  % Close figure after run
       end
    end
    
    methods (Static)

        function out = orsoTest(layersFile, dataFile)

            layers = dlmread(layersFile);
    
            % Change the units to Å
            layers(:,2) = layers(:,2) .* 1e-6;
            layers(:,3) = layers(:,3) .* 1e-6;
    
            % Read in the data.....
            data = dlmread(dataFile);
    
            % Group the Layers
            thick = layers(:,1);
            sld = complex(layers(:,2),layers(:,3));
            rough = layers(:,4);
    
            % Calculate reflectivity...
            q = data(:,1);
            N = size(layers,1);
            ref = abelesSingle(q,N,thick,sld,rough);
    
            % Plot the comparison....
            figure(1); clf
            semilogy(q,ref,'k-','LineWidth',2)
            hold on
            plot(data(:,1),data(:,2),'r.')
    
            % Calculate the output....
            out = sum(sum((data(:,2) - ref).^2));

        end
    end
end