classdef testControlsClass < matlab.unittest.TestCase   

    properties
        controls
    end

    methods(TestMethodSetup)
        function createControlsClass(testCase)
            testCase.controls = controlsClass();
        end
    end

    methods (Test)
        function testParallel(testCase)
            % Test if set.parallel method is working
            testCase.controls.parallel = 'points';
            testCase.verifyEqual(testCase.controls.parallel, 'points', 'set.parallel method is not working')
            testCase.controls.parallel = 'contrasts';
            testCase.verifyEqual(testCase.controls.parallel, 'contrasts', 'set.parallel method is not working')
            testCase.controls.parallel = 'all';
            testCase.verifyEqual(testCase.controls.parallel, 'all', 'set.parallel method is not working')
            testCase.controls.parallel = 'single';
            testCase.verifyEqual(testCase.controls.parallel, 'single', 'set.parallel method is not working')
            testCase.verifyError(@setParallel, invalidOption.errorID);  % bad parallel option 
            function setParallel
                testCase.controls.parallel = 'random';
            end
        end

        function testProcedure(testCase)
            % Test if set.procedure method is working
            testCase.controls.procedure = 'simplex';
            testCase.verifyEqual(testCase.controls.procedure, 'simplex', 'set.procedure method is not working')
            testCase.controls.procedure = 'de';
            testCase.verifyEqual(testCase.controls.procedure, 'de', 'set.procedure method is not working')
            testCase.controls.procedure = 'dream';
            testCase.verifyEqual(testCase.controls.procedure, 'dream', 'set.procedure method is not working')
            testCase.controls.procedure = 'ns';
            testCase.verifyEqual(testCase.controls.procedure, 'ns', 'set.procedure method is not working')
            testCase.controls.procedure = 'calculate';
            testCase.verifyEqual(testCase.controls.procedure, 'calculate', 'set.procedure method is not working')
            testCase.verifyError(@setProcedure, invalidOption.errorID);  % bad procedure option 
            function setProcedure
                testCase.controls.procedure = 'random';
            end
        end

        function testDisplay(testCase)
            % Test if set.display method is working
            testCase.controls.display = 'final';
            testCase.verifyEqual(testCase.controls.display, 'final', 'set.display method is not working')            
            testCase.controls.display = 'off';
            testCase.verifyEqual(testCase.controls.display, 'off', 'set.display method is not working')
            testCase.controls.display = 'iter';
            testCase.verifyEqual(testCase.controls.display, 'iter', 'set.display method is not working')
            testCase.controls.display = 'notify';
            testCase.verifyEqual(testCase.controls.display, 'notify', 'set.display method is not working')
            testCase.verifyError(@setDisplay, invalidOption.errorID);  % bad display option 
            function setDisplay
                testCase.controls.display = 'any';
            end
        end

        function testResamPars(testCase)
            % Test if set.resamPars method is working
            testCase.controls.resamPars = [0, 100];
            testCase.verifyEqual(testCase.controls.resamPars, [0, 100], 'set.resamPars method is not working')
            testCase.controls.resamPars = [0.9, 10.2];
            testCase.verifyEqual(testCase.controls.resamPars, [0.9, 10.2], 'set.resamPars method is not working')            
            % bad resamPar option 
            testCase.verifyError(@() setResamPars('ab'), invalidValue.errorID);
            testCase.verifyError(@() setResamPars([0.5, 6, 7]), invalidValue.errorID);            
            testCase.verifyError(@() setResamPars([-1, 4]), invalidValue.errorID);
            testCase.verifyError(@() setResamPars([0, 0]), invalidValue.errorID);
            testCase.verifyError(@() setResamPars([12, 13]), invalidValue.errorID);
            function setResamPars(value)
                testCase.controls.resamPars = value;
            end
        end

        function testCalcSldDuringFit(testCase)
            % Test if set.calcSldDuringFit method is working
            testCase.controls.calcSldDuringFit =  true;
            testCase.verifyTrue(testCase.controls.calcSldDuringFit, 'set.calcSldDuringFit method is not working')
            testCase.controls.calcSldDuringFit = false;
            testCase.verifyFalse(testCase.controls.calcSldDuringFit, 'set.calcSldDuringFit method is not working')
            testCase.verifyError(@setCalcSldDuringFit, invalidValue.errorID);  % bad calcSldDuringFit option 
            function setCalcSldDuringFit
                testCase.controls.calcSldDuringFit = 2;
            end
        end

        function testSimplexArguments(testCase)
            % Test if Simplex property setters are working
            testCase.controls.tolX = 5;
            testCase.verifyEqual(testCase.controls.tolX, 5, 'set.tolX method is not working')
            testCase.verifyError(@setTolX, invalidValue.errorID);  % bad tolX type 
            function setTolX
                testCase.controls.tolX = 'a';
            end

            testCase.controls.tolFun = 2;
            testCase.verifyEqual(testCase.controls.tolFun, 2, 'set.tolFun method is not working')
            testCase.verifyError(@setTolFun, invalidValue.errorID);  % bad tolFun type 
            function setTolFun
                testCase.controls.tolFun = 'a';
            end

            testCase.controls.maxFunEvals = 123;
            testCase.verifyEqual(testCase.controls.maxFunEvals, 123, 'set.maxFunEvals method is not working')
            testCase.verifyError(@setMaxFunEvals, invalidValue.errorID);  % bad maxFunEvals type 
            function setMaxFunEvals
                testCase.controls.maxFunEvals = 'a';
            end

            testCase.controls.maxIter = 456;
            testCase.verifyEqual(testCase.controls.maxIter, 456, 'set.maxIter method is not working')
            testCase.verifyError(@setMaxIter, invalidValue.errorID);  % bad maxIter type 
            function setMaxIter
                testCase.controls.maxIter = 'a';
            end
        end

        function testDEArguments(testCase)
            % Test if DE property setters are working
            testCase.controls.populationSize = 5;
            testCase.verifyEqual(testCase.controls.populationSize, 5, 'set.populationSize method is not working')
            % bad populationSize type
            testCase.verifyError(@() setPopulationSize('a'), invalidValue.errorID);
            testCase.verifyError(@() setPopulationSize(0), invalidValue.errorID);
            function setPopulationSize(value)
                testCase.controls.populationSize = value;
            end

            testCase.controls.fWeight = 0.2;
            testCase.verifyEqual(testCase.controls.fWeight, 0.2, 'set.fWeight method is not working')
            testCase.verifyError(@setFWeight, invalidValue.errorID);  % bad fWeight type 
            function setFWeight
                testCase.controls.fWeight = 'a';
            end

            testCase.controls.crossoverProbability = 0.1;
            testCase.verifyEqual(testCase.controls.crossoverProbability, 0.1, 'set.crossoverProbability method is not working')
            % bad crossoverProbability type
            testCase.verifyError(@() setCrossoverProbability('a'), invalidValue.errorID);  
            testCase.verifyError(@() setCrossoverProbability(-1), invalidValue.errorID);
            testCase.verifyError(@() setCrossoverProbability(2), invalidValue.errorID);
            function setCrossoverProbability(value)
                testCase.controls.crossoverProbability = value;
            end
            
            for i = 1:6
                testCase.controls.strategy = i;
                testCase.verifyEqual(testCase.controls.strategy, i, 'set.strategy method is not working')
            end
            % bad strategy type 
            testCase.verifyError(@() setStrategy('a'), invalidValue.errorID);  
            testCase.verifyError(@() setStrategy(7), invalidValue.errorID);
            testCase.verifyError(@() setStrategy(3.14), invalidValue.errorID);
            testCase.verifyError(@() setStrategy(0), invalidValue.errorID);
            function setStrategy(value)
                testCase.controls.strategy = value;
            end

            testCase.controls.targetValue = 4;
            testCase.verifyEqual(testCase.controls.targetValue, 4, 'set.targetValue method is not working')
            % bad targetValue type
            testCase.verifyError(@() setTargetValue('a'), invalidValue.errorID);
            testCase.verifyError(@() setTargetValue(0), invalidValue.errorID); 
            function setTargetValue(value)
                testCase.controls.targetValue = value;
            end

            testCase.controls.numGenerations = 6;
            testCase.verifyEqual(testCase.controls.numGenerations, 6, 'set.numGenerations method is not working')
            % bad numGenerations type 
            testCase.verifyError(@() setNumGenerations('a'), invalidValue.errorID);
            testCase.verifyError(@() setNumGenerations(0), invalidValue.errorID);
            function setNumGenerations(value)
                testCase.controls.numGenerations = value;
            end
        end

        function testNSArguments(testCase)   
            % Test if NS property setters are working
            testCase.controls.Nlive = 5;
            testCase.verifyEqual(testCase.controls.Nlive, 5, 'set.Nlive method is not working')
            % bad Nlive type
            testCase.verifyError(@() setNlive('a'), invalidValue.errorID);
            testCase.verifyError(@() setNlive(0), invalidValue.errorID);
            function setNlive(value)
                testCase.controls.Nlive = value;
            end

            testCase.controls.Nmcmc = 5;
            testCase.verifyEqual(testCase.controls.Nmcmc, 5, 'set.Nmcmc method is not working')
            % bad Nmcmc type
            testCase.verifyError(@() setNmcmc('a'), invalidValue.errorID);
            testCase.verifyError(@() setNmcmc(-1), invalidValue.errorID);
            function setNmcmc(value)
                testCase.controls.Nmcmc = value;
            end

            testCase.controls.propScale = 0.1;
            testCase.verifyEqual(testCase.controls.propScale, 0.1, 'set.propScale method is not working')
            % bad propScale type
            testCase.verifyError(@() setPropScale('a'), invalidValue.errorID);
            testCase.verifyError(@() setPropScale(-1), invalidValue.errorID);
            testCase.verifyError(@() setPropScale(2), invalidValue.errorID);
            function setPropScale(value)
                testCase.controls.propScale = value;
            end

            testCase.controls.nsTolerance = 0;
            testCase.verifyEqual(testCase.controls.nsTolerance, 0, 'set.nsTolerance method is not working')
            % bad nsTolerance type
            testCase.verifyError(@() setNsTolerance('a'), invalidValue.errorID);
            testCase.verifyError(@() setNsTolerance(-1), invalidValue.errorID);
            function setNsTolerance(value)
                testCase.controls.nsTolerance = value;
            end
        end 
 
         function testDreamArguments(testCase)   
            % Test if Dream property setters are working
            testCase.controls.nSamples = 289;
            testCase.verifyEqual(testCase.controls.nSamples, 289, 'set.nSamples method is not working')
            % bad nSamples type
            testCase.verifyError(@() setNSamples('a'), ?MException);
            testCase.verifyError(@() setNSamples(-1), ?MException);
            function setNSamples(value)
                testCase.controls.nSamples = value;
            end

            testCase.controls.nChains = 20;
            testCase.verifyEqual(testCase.controls.nChains, 20, 'set.nChains method is not working')
            % bad nChains type
            testCase.verifyError(@() setNChains(Inf), invalidValue.errorID);
            testCase.verifyError(@() setNChains(NaN), invalidValue.errorID);
            testCase.verifyError(@() setNChains('a'), invalidValue.errorID);
            testCase.verifyError(@() setNChains(0), invalidValue.errorID);
            testCase.verifyError(@() setNChains(20.1), invalidValue.errorID);
            function setNChains(value)
                testCase.controls.nChains = value;
            end

            testCase.controls.lambda = 0;
            testCase.verifyEqual(testCase.controls.lambda, 0, 'set.lambda method is not working')
            testCase.controls.lambda = 1;
            testCase.verifyEqual(testCase.controls.lambda, 1, 'set.lambda method is not working')
            testCase.controls.lambda = 0.5;
            testCase.verifyEqual(testCase.controls.lambda, 0.5, 'set.lambda method is not working')
            % bad lambda type 
            testCase.verifyError(@() setLambda(1.1), invalidValue.errorID);  
            testCase.verifyError(@() setLambda(-0.1), invalidValue.errorID);
            testCase.verifyError(@() setLambda('a'), invalidValue.errorID);
            function setLambda(value)
                testCase.controls.lambda = value;
            end

            testCase.controls.pUnitGamma = 0;
            testCase.verifyEqual(testCase.controls.pUnitGamma, 0, 'set.pUnitGamma method is not working')
            testCase.controls.pUnitGamma = 1;
            testCase.verifyEqual(testCase.controls.pUnitGamma, 1, 'set.pUnitGamma method is not working')
            testCase.controls.pUnitGamma = 0.5;
            testCase.verifyEqual(testCase.controls.pUnitGamma, 0.5, 'set.pUnitGamma method is not working')
            % bad pUnitGamma type 
            testCase.verifyError(@() setLambda(1.1), invalidValue.errorID);
            testCase.verifyError(@() setPUnitGamma(-0.1), invalidValue.errorID);
            testCase.verifyError(@() setPUnitGamma('a'), invalidValue.errorID);
            function setPUnitGamma(value)
                testCase.controls.pUnitGamma = value;
            end

            testCase.controls.boundHandling = 'none';
            testCase.verifyEqual(testCase.controls.boundHandling, 'none', 'set.boundHandling method is not working')
            testCase.controls.boundHandling = 'reflect';
            testCase.verifyEqual(testCase.controls.boundHandling, 'reflect', 'set.boundHandling method is not working')
            testCase.controls.boundHandling = 'Bound';
            testCase.verifyEqual(testCase.controls.boundHandling, 'Bound', 'setboundHandling method is not working')
            testCase.controls.boundHandling = 'fold';
            testCase.verifyEqual(testCase.controls.boundHandling, 'fold', 'set.boundHandling method is not working')
            testCase.verifyError(@setBoundHandling, invalidOption.errorID);  % bad method option 
            function setBoundHandling
                testCase.controls.boundHandling = 'random';
            end
        end

        function testDisplayGroups(testCase)
            import matlab.unittest.constraints.ContainsSubstring
            % Check that the content of the controlsClass are printed
            display = evalc('disp(testCase.controls)');
            testCase.verifyNotEmpty(display, 'getPropertyGroups method not working');
            testCase.verifySubstring(display, "parallel: 'single'", 'getPropertyGroups method not working');
            testCase.verifySubstring(display, "procedure: 'calculate'", 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring("tolX"), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring("method"), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring("propScale"), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring("strategy"), 'getPropertyGroups method not working');

            testCase.controls.procedure = 'dream';
            display = evalc('disp(testCase.controls)');
            testCase.verifySubstring(display, "parallel: 'single'", 'getPropertyGroups method not working');
            testCase.verifySubstring(display, "procedure: 'dream'", 'getPropertyGroups method not working');
            testCase.verifySubstring(display, "nChains", 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring("tolX"), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring("propScale"), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring("strategy"), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring("tolX"), 'getPropertyGroups method not working');
            
            testCase.controls.procedure = 'ns';
            display = evalc('disp(testCase.controls)');
            testCase.verifySubstring(display, "parallel: 'single'", 'getPropertyGroups method not working');
            testCase.verifySubstring(display, "procedure: 'ns'", 'getPropertyGroups method not working');
            testCase.verifySubstring(display, "propScale", 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring("tolX"), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring("method"), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring("strategy"), 'getPropertyGroups method not working');
            
            testCase.controls.procedure = 'de';
            testCase.controls.parallel = 'contrasts';
            display = evalc('disp(testCase.controls)');
            testCase.verifySubstring(display, "parallel: 'contrasts'", 'getPropertyGroups method not working');
            testCase.verifySubstring(display, "procedure: 'de'", 'getPropertyGroups method not working');
            testCase.verifySubstring(display, "strategy", 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring("tolX"), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring("method"), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring("propScale"), 'getPropertyGroups method not working');
            

            testCase.controls.procedure = 'simplex';
            display = evalc('disp(testCase.controls)');
            testCase.verifySubstring(display, "parallel: 'contrasts'", 'getPropertyGroups method not working');
            testCase.verifySubstring(display, "procedure: 'simplex'", 'getPropertyGroups method not working');
            testCase.verifySubstring(display, "tolX", 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring("method"), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring("propScale"), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring("strategy"), 'getPropertyGroups method not working');
            
            controls(1) = testCase.controls;
            controls(2) = testCase.controls;
            display = eraseBetween(sprintf(evalc('disp(controls)')), '<', '>','Boundaries','inclusive');
            testCase.verifySubstring(display, "controlsClass array with properties", 'getPropertyGroups method not working');
        end
    end
end
