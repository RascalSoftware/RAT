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
            testCase.controls.parallel = parallelOptions.Points;
            testCase.verifyEqual(testCase.controls.parallel, parallelOptions.Points.value, 'set.parallel method is not working')
            testCase.controls.parallel = parallelOptions.Contrasts;
            testCase.verifyEqual(testCase.controls.parallel, parallelOptions.Contrasts.value, 'set.parallel method is not working')
            testCase.controls.parallel = upper(parallelOptions.Single.value);
            testCase.verifyEqual(testCase.controls.parallel, parallelOptions.Single.value, 'set.parallel method is not working')
            testCase.verifyError(@setParallel, exceptions.invalidOption.errorID);  % bad parallel option
            function setParallel
                testCase.controls.parallel = 'random';
            end
        end
        
        function testProcedure(testCase)
            % Test if set.procedure method is working
            testCase.controls.procedure = procedures.Simplex;
            testCase.verifyEqual(testCase.controls.procedure, procedures.Simplex.value, 'set.procedure method is not working')
            testCase.controls.procedure = procedures.DE;
            testCase.verifyEqual(testCase.controls.procedure, procedures.DE.value, 'set.procedure method is not working')
            testCase.controls.procedure = procedures.Dream.value;
            testCase.verifyEqual(testCase.controls.procedure, procedures.Dream.value, 'set.procedure method is not working')
            testCase.controls.procedure = upper(procedures.NS.value);
            testCase.verifyEqual(testCase.controls.procedure, procedures.NS.value, 'set.procedure method is not working')
            testCase.controls.procedure = procedures.Calculate;
            testCase.verifyEqual(testCase.controls.procedure, procedures.Calculate.value, 'set.procedure method is not working')
            testCase.verifyError(@setProcedure, exceptions.invalidOption.errorID);  % bad procedure option
            function setProcedure
                testCase.controls.procedure = 'random';
            end
        end
        
        function testDisplay(testCase)
            % Test if set.display method is working
            testCase.controls.display = displayOptions.Final;
            testCase.verifyEqual(testCase.controls.display, displayOptions.Final.value, 'set.display method is not working')
            testCase.controls.display = upper(displayOptions.Off.value);
            testCase.verifyEqual(testCase.controls.display, displayOptions.Off.value, 'set.display method is not working')
            testCase.controls.display = displayOptions.Iter.value;
            testCase.verifyEqual(testCase.controls.display, displayOptions.Iter.value, 'set.display method is not working')
            testCase.controls.display = displayOptions.Notify;
            testCase.verifyEqual(testCase.controls.display, displayOptions.Notify.value, 'set.display method is not working')
            testCase.verifyError(@setDisplay, exceptions.invalidOption.errorID);  % bad display option
            function setDisplay
                testCase.controls.display = 'any';
            end
        end
        
        function testResampleMinAngle(testCase)
            % Test if set.resampleMinAngle method is working
            testCase.controls.resampleMinAngle = 0.8;
            testCase.verifyEqual(testCase.controls.resampleMinAngle, 0.8, 'set.resampleMinAngle method is not working')
            % bad resampleMinAngle option
            testCase.verifyError(@() setResampleMinAngle('ab'), exceptions.invalidType.errorID);
            testCase.verifyError(@() setResampleMinAngle(-1), exceptions.invalidValue.errorID);
            testCase.verifyError(@() setResampleMinAngle(0), exceptions.invalidValue.errorID);
            testCase.verifyError(@() setResampleMinAngle(12.3), exceptions.invalidValue.errorID);
            function setResampleMinAngle(value)
                testCase.controls.resampleMinAngle = value;
            end
        end
        
        function testResampleNPoints(testCase)
            % test if set.resampleNPoints is working
            testCase.controls.resampleNPoints = 10;
            testCase.verifyEqual(testCase.controls.resampleNPoints, 10, 'set.resampleNPoints method is not working')
            % bad option
            testCase.verifyError(@() setResampleNPoints('ab'), exceptions.invalidType.errorID);
            testCase.verifyError(@() setResampleNPoints(0.5), exceptions.invalidValue.errorID);
            testCase.verifyError(@() setResampleNPoints(-1), exceptions.invalidValue.errorID);
            function setResampleNPoints(value)
                testCase.controls.resampleNPoints = value;
            end
        end
        
        function testCalcSldDuringFit(testCase)
            % Test if set.calcSldDuringFit method is working
            testCase.controls.calcSldDuringFit = true;
            testCase.verifyTrue(testCase.controls.calcSldDuringFit, 'set.calcSldDuringFit method is not working')
            testCase.controls.calcSldDuringFit = false;
            testCase.verifyFalse(testCase.controls.calcSldDuringFit, 'set.calcSldDuringFit method is not working')
            testCase.verifyError(@setCalcSldDuringFit, exceptions.invalidType.errorID);  % bad calcSldDuringFit option
            function setCalcSldDuringFit
                testCase.controls.calcSldDuringFit = 2;
            end
        end
        
        function testUpdateFreq(testCase)
            % Test if UpdateFreq property is working
            testCase.controls.updateFreq = 5;
            testCase.verifyEqual(testCase.controls.updateFreq, 5, 'set.updateFreq method is not working')
            % bad updateFreq type
            testCase.verifyError(@() setUpdateFreq('a'), exceptions.invalidType.errorID);
            testCase.verifyError(@() setUpdateFreq(1.5), exceptions.invalidValue.errorID);
            testCase.verifyError(@() setUpdateFreq(0), exceptions.invalidValue.errorID);
            function setUpdateFreq(value)
                testCase.controls.updateFreq = value;
            end
        end

        function testUpdatePlotFreq(testCase)
            % Test if UpdatePlotFreq property is working
            testCase.controls.updatePlotFreq = 5;
            testCase.verifyEqual(testCase.controls.updatePlotFreq, 5, 'set.updatePlotFreq method is not working')
            % bad updatePlotFreq type
            testCase.verifyError(@() setUpdatePlotFreq('a'), exceptions.invalidType.errorID);
            testCase.verifyError(@() setUpdatePlotFreq(1.5), exceptions.invalidValue.errorID);
            testCase.verifyError(@() setUpdatePlotFreq(0), exceptions.invalidValue.errorID);
            function setUpdatePlotFreq(value)
                testCase.controls.updatePlotFreq = value;
            end
        end
        
        function testSimplexArguments(testCase)
            % Test if Simplex property setters are working
            testCase.controls.xTolerance = 5;
            testCase.verifyEqual(testCase.controls.xTolerance, 5, 'set.xTolerance method is not working')
            testCase.verifyError(@setXTolerance, exceptions.invalidType.errorID);  % bad xTolerance type
            function setXTolerance
                testCase.controls.xTolerance = 'a';
            end
            
            testCase.controls.funcTolerance = 2;
            testCase.verifyEqual(testCase.controls.funcTolerance, 2, 'set.funcTolerance method is not working')
            testCase.verifyError(@setFuncTolerance, exceptions.invalidType.errorID);  % bad funcTolerance type
            function setFuncTolerance
                testCase.controls.funcTolerance = 'a';
            end
            
            testCase.controls.maxFuncEvals = 123;
            testCase.verifyEqual(testCase.controls.maxFuncEvals, 123, 'set.maxFuncEvals method is not working')
            testCase.verifyError(@() setMaxFuncEvals('a'), exceptions.invalidType.errorID);  % bad maxFuncEvals type
            testCase.verifyError(@() setMaxFuncEvals(1.5), exceptions.invalidValue.errorID);
            function setMaxFuncEvals(value)
                testCase.controls.maxFuncEvals = value;
            end
            
            testCase.controls.maxIterations = 456;
            testCase.verifyEqual(testCase.controls.maxIterations, 456, 'set.maxIterations method is not working')
            testCase.verifyError(@() setMaxIterations('a'), exceptions.invalidType.errorID);  % bad maxIterations type
            testCase.verifyError(@() setMaxIterations(1.5), exceptions.invalidValue.errorID);
            function setMaxIterations(value)
                testCase.controls.maxIterations = value;
            end
        end
        
        function testDEArguments(testCase)
            % Test if DE property setters are working
            testCase.controls.populationSize = 5;
            testCase.verifyEqual(testCase.controls.populationSize, 5, 'set.populationSize method is not working')
            % bad populationSize type
            testCase.verifyError(@() setPopulationSize('a'), exceptions.invalidType.errorID);
            testCase.verifyError(@() setPopulationSize(0), exceptions.invalidValue.errorID);
            testCase.verifyError(@() setPopulationSize(1.5), exceptions.invalidValue.errorID);
            function setPopulationSize(value)
                testCase.controls.populationSize = value;
            end
            
            testCase.controls.fWeight = 0.2;
            testCase.verifyEqual(testCase.controls.fWeight, 0.2, 'set.fWeight method is not working')
            testCase.verifyError(@() setFWeight('a'), exceptions.invalidType.errorID);  % bad fWeight type
            testCase.verifyError(@() setFWeight(-3), exceptions.invalidValue.errorID);
            function setFWeight(value)
                testCase.controls.fWeight = value;
            end
            
            testCase.controls.crossoverProbability = 0.1;
            testCase.verifyEqual(testCase.controls.crossoverProbability, 0.1, 'set.crossoverProbability method is not working')
            % bad crossoverProbability type
            testCase.verifyError(@() setCrossoverProbability('a'), exceptions.invalidType.errorID);
            testCase.verifyError(@() setCrossoverProbability(-1), exceptions.invalidValue.errorID);
            testCase.verifyError(@() setCrossoverProbability(2), exceptions.invalidValue.errorID);
            function setCrossoverProbability(value)
                testCase.controls.crossoverProbability = value;
            end
            
            for i = 1:6
                testCase.controls.strategy = searchStrategy.fromValue(i);
                testCase.verifyEqual(testCase.controls.strategy, i, 'set.strategy method is not working')
            end
            % bad strategy type
            testCase.verifyError(@() setStrategy('a'), exceptions.invalidOption.errorID);
            testCase.verifyError(@() setStrategy(7), exceptions.invalidOption.errorID);
            testCase.verifyError(@() setStrategy(3.14), exceptions.invalidOption.errorID);
            testCase.verifyError(@() setStrategy(0), exceptions.invalidOption.errorID);
            function setStrategy(value)
                testCase.controls.strategy = value;
            end
            
            testCase.controls.targetValue = 4;
            testCase.verifyEqual(testCase.controls.targetValue, 4, 'set.targetValue method is not working')
            % bad targetValue type
            testCase.verifyError(@() setTargetValue('a'), exceptions.invalidType.errorID);
            testCase.verifyError(@() setTargetValue(0), exceptions.invalidValue.errorID);
            function setTargetValue(value)
                testCase.controls.targetValue = value;
            end
            
            testCase.controls.numGenerations = 6;
            testCase.verifyEqual(testCase.controls.numGenerations, 6, 'set.numGenerations method is not working')
            % bad numGenerations type
            testCase.verifyError(@() setNumGenerations('a'), exceptions.invalidType.errorID);
            testCase.verifyError(@() setNumGenerations(0), exceptions.invalidValue.errorID);
            testCase.verifyError(@() setNumGenerations(1.5), exceptions.invalidValue.errorID);
            function setNumGenerations(value)
                testCase.controls.numGenerations = value;
            end
        end
        
        function testNSArguments(testCase)
            % Test if NS property setters are working
            testCase.controls.nLive = 5;
            testCase.verifyEqual(testCase.controls.nLive, 5, 'set.nLive method is not working')
            % bad nLive type
            testCase.verifyError(@() setnLive('a'), exceptions.invalidType.errorID);
            testCase.verifyError(@() setnLive(0), exceptions.invalidValue.errorID);
            testCase.verifyError(@() setnLive(1.5), exceptions.invalidValue.errorID);
            function setnLive(value)
                testCase.controls.nLive = value;
            end
            
            testCase.controls.nMCMC = 5;
            testCase.verifyEqual(testCase.controls.nMCMC, 5, 'set.nMCMC method is not working')
            % bad nMCMC type
            testCase.verifyError(@() setnMCMC('a'), exceptions.invalidType.errorID);
            testCase.verifyError(@() setnMCMC(-1), exceptions.invalidValue.errorID);
            testCase.verifyError(@() setnMCMC(1.5), exceptions.invalidValue.errorID);
            function setnMCMC(value)
                testCase.controls.nMCMC = value;
            end
            
            testCase.controls.propScale = 0.1;
            testCase.verifyEqual(testCase.controls.propScale, 0.1, 'set.propScale method is not working')
            % bad propScale type
            testCase.verifyError(@() setPropScale('a'), exceptions.invalidType.errorID);
            testCase.verifyError(@() setPropScale(-1), exceptions.invalidValue.errorID);
            testCase.verifyError(@() setPropScale(2), exceptions.invalidValue.errorID);
            function setPropScale(value)
                testCase.controls.propScale = value;
            end
            
            testCase.controls.nsTolerance = 0;
            testCase.verifyEqual(testCase.controls.nsTolerance, 0, 'set.nsTolerance method is not working')
            % bad nsTolerance type
            testCase.verifyError(@() setNsTolerance('a'), exceptions.invalidType.errorID);
            testCase.verifyError(@() setNsTolerance(-1), exceptions.invalidValue.errorID);
            function setNsTolerance(value)
                testCase.controls.nsTolerance = value;
            end
        end
        
        function testDreamArguments(testCase)
            % Test if Dream property setters are working
            testCase.controls.nSamples = 289;
            testCase.verifyEqual(testCase.controls.nSamples, 289, 'set.nSamples method is not working')
            % bad nSamples type
            testCase.verifyError(@() setNSamples('a'), exceptions.invalidType.errorID);
            testCase.verifyError(@() setNSamples(-1), exceptions.invalidValue.errorID);
            testCase.verifyError(@() setNSamples(1.5), exceptions.invalidValue.errorID);
            function setNSamples(value)
                testCase.controls.nSamples = value;
            end
            
            testCase.controls.nChains = 20;
            testCase.verifyEqual(testCase.controls.nChains, 20, 'set.nChains method is not working')
            % bad nChains type
            testCase.verifyError(@() setNChains(Inf), exceptions.invalidValue.errorID);
            testCase.verifyError(@() setNChains(NaN), exceptions.invalidValue.errorID);
            testCase.verifyError(@() setNChains('a'), exceptions.invalidType.errorID);
            testCase.verifyError(@() setNChains(0), exceptions.invalidValue.errorID);
            testCase.verifyError(@() setNChains(20.1), exceptions.invalidValue.errorID);
            function setNChains(value)
                testCase.controls.nChains = value;
            end
            
            testCase.controls.jumpProbability = 0;
            testCase.verifyEqual(testCase.controls.jumpProbability, 0, 'set.jumpProbability method is not working')
            testCase.controls.jumpProbability = 1;
            testCase.verifyEqual(testCase.controls.jumpProbability, 1, 'set.jumpProbability method is not working')
            testCase.controls.jumpProbability = 0.5;
            testCase.verifyEqual(testCase.controls.jumpProbability, 0.5, 'set.jumpProbability method is not working')
            % bad jumpProbability type
            testCase.verifyError(@() setJumpProbability(1.1), exceptions.invalidValue.errorID);
            testCase.verifyError(@() setJumpProbability(-0.1), exceptions.invalidValue.errorID);
            testCase.verifyError(@() setJumpProbability('a'), exceptions.invalidType.errorID);
            function setJumpProbability(value)
                testCase.controls.jumpProbability = value;
            end
            
            testCase.controls.pUnitGamma = 0;
            testCase.verifyEqual(testCase.controls.pUnitGamma, 0, 'set.pUnitGamma method is not working')
            testCase.controls.pUnitGamma = 1;
            testCase.verifyEqual(testCase.controls.pUnitGamma, 1, 'set.pUnitGamma method is not working')
            testCase.controls.pUnitGamma = 0.5;
            testCase.verifyEqual(testCase.controls.pUnitGamma, 0.5, 'set.pUnitGamma method is not working')
            % bad pUnitGamma type
            testCase.verifyError(@() setJumpProbability(1.1), exceptions.invalidValue.errorID);
            testCase.verifyError(@() setPUnitGamma(-0.1), exceptions.invalidValue.errorID);
            testCase.verifyError(@() setPUnitGamma('a'), exceptions.invalidType.errorID);
            function setPUnitGamma(value)
                testCase.controls.pUnitGamma = value;
            end
            
            testCase.controls.boundHandling = boundHandlingOptions.None;
            testCase.verifyEqual(testCase.controls.boundHandling, boundHandlingOptions.None.value, 'set.boundHandling method is not working')
            testCase.controls.boundHandling = boundHandlingOptions.Reflect.value;
            testCase.verifyEqual(testCase.controls.boundHandling, boundHandlingOptions.Reflect.value, 'set.boundHandling method is not working')
            testCase.controls.boundHandling = upper(boundHandlingOptions.Bound.value);
            testCase.verifyEqual(testCase.controls.boundHandling, boundHandlingOptions.Bound.value, 'setboundHandling method is not working')
            testCase.controls.boundHandling = boundHandlingOptions.Fold;
            testCase.verifyEqual(testCase.controls.boundHandling, boundHandlingOptions.Fold.value, 'set.boundHandling method is not working')
            testCase.verifyError(@setBoundHandling, exceptions.invalidOption.errorID);  % bad method option
            function setBoundHandling
                testCase.controls.boundHandling = 'random';
            end
            
            % Test if set.calcSldDuringFit method is working
            testCase.controls.adaptPCR = true;
            testCase.verifyTrue(testCase.controls.adaptPCR, 'set.adaptPCR method is not working')
            testCase.controls.adaptPCR = false;
            testCase.verifyFalse(testCase.controls.adaptPCR, 'set.adaptPCR method is not working')
            testCase.verifyError(@setAdaptPCR, exceptions.invalidType.errorID);  % bad adaptPCR option
            function setAdaptPCR
                testCase.controls.adaptPCR = 2;
            end
        end
        
        function testDisplayGroups(testCase)
            import matlab.unittest.constraints.ContainsSubstring
            % Check that the content of the controlsClass are printed
            display = evalc('disp(testCase.controls)');
            testCase.verifyNotEmpty(display, 'getPropertyGroups method not working');
            testCase.verifySubstring(display, 'parallel: ''single''', 'getPropertyGroups method not working');
            testCase.verifySubstring(display, 'procedure: ''calculate''', 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring('xTolerance'), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring('method'), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring('propScale'), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring('strategy'), 'getPropertyGroups method not working');
            
            testCase.controls.procedure = 'dream';
            display = evalc('disp(testCase.controls)');
            testCase.verifySubstring(display, 'parallel: ''single''', 'getPropertyGroups method not working');
            testCase.verifySubstring(display, 'procedure: ''dream''', 'getPropertyGroups method not working');
            testCase.verifySubstring(display, 'nChains', 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring('xTolerance'), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring('propScale'), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring('strategy'), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring('xTolerance'), 'getPropertyGroups method not working');
            
            testCase.controls.procedure = procedures.NS;
            display = evalc('disp(testCase.controls)');
            testCase.verifySubstring(display, 'parallel: ''single''', 'getPropertyGroups method not working');
            testCase.verifySubstring(display, 'procedure: ''ns''', 'getPropertyGroups method not working');
            testCase.verifySubstring(display, 'propScale', 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring('xTolerance'), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring('method'), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring('strategy'), 'getPropertyGroups method not working');
            
            testCase.controls.procedure = upper(procedures.DE);
            testCase.controls.parallel = 'contrasts';
            display = evalc('disp(testCase.controls)');
            testCase.verifySubstring(display, 'parallel: ''contrasts''', 'getPropertyGroups method not working');
            testCase.verifySubstring(display, 'procedure: ''de''', 'getPropertyGroups method not working');
            testCase.verifySubstring(display, 'strategy', 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring('xTolerance'), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring('method'), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring('propScale'), 'getPropertyGroups method not working');
            
            
            testCase.controls.procedure = procedures.Simplex;
            display = evalc('disp(testCase.controls)');
            testCase.verifySubstring(display, 'parallel: ''contrasts''', 'getPropertyGroups method not working');
            testCase.verifySubstring(display, 'procedure: ''simplex''', 'getPropertyGroups method not working');
            testCase.verifySubstring(display, 'xTolerance', 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring('method'), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring('propScale'), 'getPropertyGroups method not working');
            testCase.verifyThat(display, ~ContainsSubstring('strategy'), 'getPropertyGroups method not working');
            
            testControls(1) = testCase.controls;
            testControls(2) = testCase.controls;
            display = eraseBetween(sprintf(evalc('disp(testControls)')), '<', '>','Boundaries','inclusive');
            testCase.verifySubstring(display, 'controlsClass array with properties', 'getPropertyGroups method not working');
        end
        
        function testSetProcedureWithDream(testCase)
            % Test default values for dream procedure
            testCase.controls = testCase.controls.setProcedure(procedures.Dream.value);
            testCase.verifyEqual(testCase.controls.procedure, procedures.Dream.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.nSamples, 20000, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.nChains, 10, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.jumpProbability, 0.5, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.pUnitGamma, 0.2, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.boundHandling, boundHandlingOptions.Reflect.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.adaptPCR, true, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.parallel, parallelOptions.Single.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.calcSldDuringFit, false, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.resampleMinAngle, 0.9, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.resampleNPoints, 50, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.display, displayOptions.Iter.value, 'setProcedure method is not working');
            
            % Test passing valid parameter values for dream procedure
            testCase.controls = testCase.controls.setProcedure(procedures.Dream.value,...
                                                               'nSamples', 70000,...
                                                               'nChains', 15,...
                                                               'jumpProbability', 0.8,...
                                                               'pUnitGamma', 0.5, ...
                                                               'boundHandling', boundHandlingOptions.Reflect.value,...
                                                               'adaptPCR', true,...
                                                               'parallel', parallelOptions.Contrasts.value,...
                                                               'calcSldDuringFit', true,...
                                                               'resampleMinAngle', 0.1,...
                                                               'resampleNPoints', 10,...
                                                               'display', displayOptions.Notify.value);
            testCase.verifyEqual(testCase.controls.procedure, procedures.Dream.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.nSamples, 70000, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.nChains, 15, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.jumpProbability, 0.8, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.pUnitGamma, 0.5, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.boundHandling, boundHandlingOptions.Reflect.value, 'setProcedure method is not working');
            testCase.verifyTrue(testCase.controls.adaptPCR, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.parallel, parallelOptions.Contrasts.value, 'setProcedure method is not working');
            testCase.verifyTrue(testCase.controls.calcSldDuringFit, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.resampleMinAngle, 0.1, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.resampleNPoints, 10, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.display, displayOptions.Notify.value, 'setProcedure method is not working');
            
            % Test passing invalid parameter values for dream procedure
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.Dream.value, 'boundHandling', 'invalid'), exceptions.invalidOption.errorID);
            
            % Test passing wrong parameter for dream procedure
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.Dream.value, 'xTolerance', 1e-6), exceptions.invalidOption.errorID); % Simplex Parameter
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.Dream.value, 'populationSize', 100000), exceptions.invalidOption.errorID); % DE Parameter
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.Dream.value, 'nLive', 10), exceptions.invalidOption.errorID); % NS Parameter
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.Dream.value, 'nChains', '0.5'), 'MATLAB:InputParser:ArgumentFailedValidation');
        end
        
        function testSetProcedureWithNS(testCase)
            % Test default values for NS procedure
            testCase.controls = testCase.controls.setProcedure(procedures.NS.value);
            testCase.verifyEqual(testCase.controls.procedure, procedures.NS.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.nLive, 150, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.nMCMC, 0, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.propScale, 0.1, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.nsTolerance, 0.1, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.parallel, parallelOptions.Single.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.calcSldDuringFit, false, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.resampleMinAngle, 0.9, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.resampleNPoints, 50, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.display, displayOptions.Iter.value, 'setProcedure method is not working');
            
            % Test passing valid parameter values for NS procedure
            testCase.controls = testCase.controls.setProcedure(procedures.NS.value,...
                                                               'nLive', 700,...
                                                               'nMCMC', 5,...
                                                               'propScale', 0.8,...
                                                               'nsTolerance', 0.5,...
                                                               'parallel', parallelOptions.Contrasts.value,...
                                                               'calcSldDuringFit', true,...
                                                               'resampleMinAngle', 0.1,...
                                                               'resampleNPoints', 10,...
                                                               'display', displayOptions.Notify.value);
            testCase.verifyEqual(testCase.controls.procedure, procedures.NS.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.nLive, 700, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.nMCMC, 5, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.propScale, 0.8, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.nsTolerance, 0.5, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.parallel, parallelOptions.Contrasts.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.calcSldDuringFit, true, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.resampleMinAngle, 0.1, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.resampleNPoints, 10, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.display, displayOptions.Notify.value, 'setProcedure method is not working');
            
            % Test passing wrong parameter for NS procedure
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.NS.value, 'funcTolerance', 1e-6), exceptions.invalidOption.errorID); % Simplex Parameter
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.NS.value, 'fWeight', 1), exceptions.invalidOption.errorID); % DE Parameter
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.NS.value, 'nSamples', 10), exceptions.invalidOption.errorID); % Dream Parameter
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.NS.value, 'propScale', '0.5'), 'MATLAB:InputParser:ArgumentFailedValidation');
        end
        
        function testSetProcedureWithDE(testCase)
            % Test default values for DE procedure
            testCase.controls = testCase.controls.setProcedure(procedures.DE.value);
            testCase.verifyEqual(testCase.controls.procedure, procedures.DE.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.populationSize, 20, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.fWeight, 0.5, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.crossoverProbability, 0.8, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.strategy, 4, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.targetValue, 1, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.numGenerations, 500, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.parallel, parallelOptions.Single.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.calcSldDuringFit, false, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.resampleMinAngle, 0.9, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.resampleNPoints, 50, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.display, displayOptions.Iter.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.updateFreq, 1, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.updatePlotFreq, 20, 'setProcedure method is not working');
            
            % Test passing valid parameter values for DE procedure
            testCase.controls = testCase.controls.setProcedure(procedures.DE.value,...
                                                               'populationSize', 30,...
                                                               'fWeight', 0.8,...
                                                               'crossoverProbability', 0.1,...
                                                               'strategy', 1,...
                                                               'targetValue', 2,...
                                                               'numGenerations', 3,...
                                                               'parallel', parallelOptions.Contrasts.value,...
                                                               'calcSldDuringFit', true,...
                                                               'resampleMinAngle', 0.1,...
                                                               'resampleNPoints', 10,...
                                                               'display', displayOptions.Notify.value,...
                                                               'updateFreq', 1,...
                                                               'updatePlotFreq', 4);
            testCase.verifyEqual(testCase.controls.procedure, procedures.DE.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.populationSize, 30, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.fWeight, 0.8, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.crossoverProbability, 0.1, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.strategy, 1, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.targetValue, 2, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.numGenerations, 3, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.parallel, parallelOptions.Contrasts.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.calcSldDuringFit, true, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.resampleMinAngle, 0.1, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.resampleNPoints, 10, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.display, displayOptions.Notify.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.updateFreq, 1, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.updatePlotFreq, 4, 'setProcedure method is not working');
            
            % Test passing wrong parameter for DE procedure
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.DE.value, 'funcTolerance', 1e-6), exceptions.invalidOption.errorID); % Simplex Parameter
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.DE.value, 'nMCMC', 1), exceptions.invalidOption.errorID); % NS Parameter
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.DE.value, 'nSamples', 10), exceptions.invalidOption.errorID); % Dream Parameter
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.DE.value, 'crossoverProbability', '0.5'), 'MATLAB:InputParser:ArgumentFailedValidation');
        end
        
        function testSetProcedureWithSimplex(testCase)
            % Test default values for Simplex procedure
            testCase.controls = testCase.controls.setProcedure(procedures.Simplex.value);
            testCase.verifyEqual(testCase.controls.procedure, procedures.Simplex.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.xTolerance, 1e-6, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.funcTolerance, 1e-6, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.maxFuncEvals, 10000, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.maxIterations, 1000, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.updateFreq, 1, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.updatePlotFreq, 20, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.parallel, parallelOptions.Single.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.calcSldDuringFit, false, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.resampleMinAngle, 0.9, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.resampleNPoints, 50, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.display, displayOptions.Iter.value, 'setProcedure method is not working');
            
            % Test passing valid parameter values for Simplex procedure
            testCase.controls = testCase.controls.setProcedure(procedures.Simplex.value,...
                                                               'xTolerance', 3e-6,...
                                                               'funcTolerance', 4e-6,...
                                                               'maxFuncEvals', 1000,...
                                                               'maxIterations', 100,...
                                                               'updateFreq', 1,...
                                                               'updatePlotFreq', 4, ...
                                                               'parallel', parallelOptions.Contrasts.value,...
                                                               'calcSldDuringFit', true,...
                                                               'resampleMinAngle', 0.1,...
                                                               'resampleNPoints', 10,...
                                                               'display', displayOptions.Notify.value);
            testCase.verifyEqual(testCase.controls.procedure, procedures.Simplex.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.xTolerance, 3e-6, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.funcTolerance, 4e-6, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.maxFuncEvals, 1000, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.maxIterations, 100, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.updateFreq, 1, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.updatePlotFreq, 4, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.parallel, parallelOptions.Contrasts.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.calcSldDuringFit, true, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.resampleMinAngle, 0.1, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.resampleNPoints, 10, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.display, displayOptions.Notify.value, 'setProcedure method is not working');
            
            % Test passing wrong parameter for Simplex procedure
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.Simplex.value, 'crossoverProbability', 0.7), exceptions.invalidOption.errorID); % DE Parameter
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.Simplex.value, 'nMCMC', 1), exceptions.invalidOption.errorID); % NS Parameter
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.Simplex.value, 'nSamples', 10), exceptions.invalidOption.errorID); % Dream Parameter
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.Simplex.value, 'maxIterations', '1'), 'MATLAB:InputParser:ArgumentFailedValidation');
        end
        
        function testSetProcedureWithCalculate(testCase)
            % Test default values for Calculate procedure
            testCase.controls = testCase.controls.setProcedure(procedures.Calculate.value);
            testCase.verifyEqual(testCase.controls.procedure, procedures.Calculate.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.parallel, parallelOptions.Single.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.calcSldDuringFit, false, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.resampleMinAngle, 0.9, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.resampleNPoints, 50, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.display, displayOptions.Iter.value, 'setProcedure method is not working');
            
            % Test passing valid parameter values for Calculate procedure
            testCase.controls = testCase.controls.setProcedure(procedures.Calculate.value,...
                                                               'parallel', parallelOptions.Contrasts.value,...
                                                               'calcSldDuringFit', true,...
                                                               'resampleMinAngle', 0.1,...
                                                               'resampleNPoints', 10,...
                                                               'display', displayOptions.Notify.value);
            testCase.verifyEqual(testCase.controls.procedure, procedures.Calculate.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.parallel, parallelOptions.Contrasts.value, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.calcSldDuringFit, true, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.resampleMinAngle, 0.1, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.resampleNPoints, 10, 'setProcedure method is not working');
            testCase.verifyEqual(testCase.controls.display, displayOptions.Notify.value, 'setProcedure method is not working');
            
            % Test passing wrong parameter for Calculate procedure
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.Calculate.value, 'maxIterations', 100), exceptions.invalidOption.errorID); % Simplex Parameter
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.Calculate.value, 'crossoverProbability', 0.7), exceptions.invalidOption.errorID); % DE Parameter
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.Calculate.value, 'nMCMC', 1), exceptions.invalidOption.errorID); % NS Parameter
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.Calculate.value, 'nSamples', 10), exceptions.invalidOption.errorID); % Dream Parameter
            testCase.verifyError(@() testCase.controls.setProcedure(procedures.Calculate.value, 'calcSldDuringFit', 1), 'MATLAB:InputParser:ArgumentFailedValidation');
            
            % Test exception
            testCase.verifyError(@() testCase.controls.setProcedure('bayes'), exceptions.invalidOption.errorID);
            
        end
        
    end
end
