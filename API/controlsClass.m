classdef controlsClass < matlab.mixin.CustomDisplay

    properties
        % Parallelisation Option (Default: parallelOptions.Single)
        parallel = parallelOptions.Single.value
        % Optimization procedure (Default: procedures.Calculate)
        procedure = procedures.Calculate.value
        % Indicates if SLD should be calculated (Default: false)
        calcSldDuringFit = false
        resampleParams = [0.9 50]
        % Display Option (Default: displayOptions.Iter)
        display = displayOptions.Iter.value
        updateFreq = 1
        updatePlotFreq = 20

        % optimization tolerance for simplex (Default: 1e-6)
        xTolerance = 1e-6    
        funcTolerance = 1e-6
        % Maximum number of function evaluations for simplex  (Default: 10000)
        maxFuncEvals = 10000
        % Maximum number of iterations for simplex  (Default: 1000)
        maxIterations = 1000
        
        % Differential Evolution population size (Default: 20)
        populationSize = 20
        % Differential weight (Default: 0.5)
        fWeight = 0.5
        % The crossover probability or recombination constant (Default: 0.8)
        crossoverProbability = 0.8
        % differential evolution strategy (Default: searchStrategy.RandomWithPerVectorDither)
        strategy = searchStrategy.RandomWithPerVectorDither.value
        % Target Value (Default: 1)
        targetValue = 1
        % Maximum number of generations (Default: 500)
        numGenerations = 500

        % Number of live points for Nested Sampler (Default: 150)
        nLive = 150
        nMCMC = 0
        propScale = 0.1     % Used if MCMC is used
        % Target stopping tolerance for Nested Sampler (Default: 0.1)
        nsTolerance = 0.1   

        % Total number of samples for DREAM (Default: 50000)
        nSamples = 20000;
        % Number of MCMC chains (Default: 10)       
        nChains = 10
        % Jump probabilities (Default: 0.5)          
        jumpProbability = 0.5      
        pUnitGamma = 0.2
        % Boundary handling
        boundHandling = boundHandlingOptions.Reflect.value     
        adaptPCR = true;
    end

    %------------------------- Set and Get ------------------------------
    methods
        function obj = set.parallel(obj,val)
            message = sprintf('parallel must be a parallelOptions enum or one of the following strings (%s)', ...
                strjoin(parallelOptions.values(), ', '));
            obj.parallel = validateOption(val, 'parallelOptions', message).value;
        end

        function obj = set.procedure(obj,val)
            message = sprintf('procedure must be a procedures enum or one of the following strings (%s)', ...
                strjoin(procedures.values(), ', '));
            obj.procedure = validateOption(val, 'procedures', message).value;
        end

        function obj = set.calcSldDuringFit(obj,val)
            validateLogical(val, 'calcSldDuringFit must be logical ''true'' or ''false''');
            obj.calcSldDuringFit = val;
        end

        function obj = set.display(obj,val)
            message = sprintf('display must be a displayOptions enum or one of the following strings (%s)', ...
                strjoin(displayOptions.values(), ', '));
            obj.display = validateOption(val, 'displayOptions', message).value;
        end

        function obj = set.updatePlotFreq(obj, val)
            validateNumber(val, 'updatePlotFreq must be a number');
            if val < 1
                throw(exceptions.invalidValue('updatePlotFreq must be greater or equal to 1'));
            end
            obj.updatePlotFreq = val;
        end

        function obj = set.resampleParams(obj,val)
            if length(val) ~= 2
                throw(exceptions.invalidValue('resampleParams must have length of 2'));
            end

            validateNumber(val, 'resampleParams must be a number array');

            if (val(1) < 0 || val(1) > 1)
                throw(exceptions.invalidValue('resampleParams(0) must be between 0 and 1'));
            end
            if val(2) <= 0
                throw(exceptions.invalidValue('resampleParams(1) must be greater than 0'));
            end
            obj.resampleParams = val;
        end

        % Simplex control methods
        function obj = set.xTolerance(obj, val)
            obj.xTolerance = validateNumber(val, 'xTolerance must be a number');
        end

        function obj = set.funcTolerance(obj, val)
            obj.funcTolerance = validateNumber(val, 'funcTolerance must be a number');
        end

        function obj = set.maxFuncEvals(obj, val)
            obj.maxFuncEvals = validateNumber(val, 'maxFuncEvals must be a number');
        end

        function obj = set.maxIterations(obj, val)
            obj.maxIterations = validateNumber(val, 'maxIterations must be a number');
        end

        % DE controls methods
        function obj = set.populationSize(obj, val)
            validateNumber(val, 'populationSize must be a number');
            if val < 1
                throw(exceptions.invalidValue('populationSize must be greater or equal to 1'));
            end
            obj.populationSize = val;
        end

        function obj = set.fWeight(obj,val)
            obj.fWeight = validateNumber(val,'fWeight must be a number');
        end

        function obj = set.crossoverProbability(obj,val)
            validateNumber(val, 'crossoverProbability must be a number');
            if (val < 0 || val > 1)
                throw(exceptions.invalidValue('crossoverProbability must be between 0 and 1'));
            end
            obj.crossoverProbability = val;
        end

        function obj = set.strategy(obj,val)
            message = sprintf('strategy must be a searchStrategy enum or one of the following integers (%s)', ...
                strjoin(string(searchStrategy.values()), ', '));

            obj.strategy = validateOption(val, 'searchStrategy', message).value;
        end

        function obj = set.targetValue(obj,val)
            validateNumber(val, 'targetValue must be a number');
            if val < 1
                throw(exceptions.invalidValue('targetValue must be greater or equal to 1'));
            end
            obj.targetValue = val;
        end

        function obj = set.numGenerations(obj, val)
            validateNumber(val, 'numGenerations value must be a number');
            if val < 1
                throw(exceptions.invalidValue('numGenerations must be greater or equal to 1'));
            end
            obj.numGenerations = val;
        end

        % NS control methods
        function obj = set.nLive(obj, val)
            validateNumber(val, 'nLive must be a number');
            if val < 1
                throw(exceptions.invalidValue('nLive must be greater or equal to 1'));
            end
            obj.nLive = val;
        end

        function obj = set.nMCMC(obj, val)
            validateNumber(val, 'nMCMC must be a number');
            if val < 0
                throw(exceptions.invalidValue('nMCMC must be greater or equal than 0'));
            end
            obj.nMCMC = val;
        end

        function obj = set.propScale(obj, val)
            validateNumber(val, 'propScale must be a number');
            if (val < 0 || val > 1)
                throw(exceptions.invalidValue('propScale must be between 0 and 1'));
            end
            obj.propScale = val;
        end

        function obj = set.nsTolerance(obj,val)
            validateNumber(val, 'nsTolerance must be a number ');
            if val < 0
                throw(exceptions.invalidValue('nsTolerance must be greater or equal to 0'));
            end
            obj.nsTolerance = val;
        end

        % DREAM methods
        function obj = set.nSamples(obj,val)
            validateNumber(val, 'nSample must be a number ');
            if val < 0
                throw(exceptions.invalidValue('nSample must be greater or equal to 0'));
            end
            obj.nSamples = val;
        end

        function obj = set.nChains(obj,val)
            validateNumber(val, 'nChains must be a number ');
            if (~(round(val) == val) || val <= 0 || isnan(val) || isinf(val))
                throw(exceptions.invalidValue('nChains must be a finite integer greater than 0'));
            end
            obj.nChains = val;
        end

        function obj = set.jumpProbability(obj,val)
            validateNumber(val, 'jumpProbability must be a number');
            if (val < 0 || val > 1)
                throw(exceptions.invalidValue('JumpProbability must be a fraction between 0 and 1'));
            end
            obj.jumpProbability = val;
        end

        function obj = set.pUnitGamma(obj,val)
            validateNumber(val, 'pUnitGamma must be a number');
            if (val < 0 || val > 1)
                throw(exceptions.invalidValue('pUnitGamma must be a fraction between 0 and 1'));
            end
            obj.pUnitGamma = val;
        end

        function obj = set.boundHandling(obj,val)
            message = sprintf('boundHandling must be a boundHandlingOptions enum or one of the following strings (%s)', ...
                strjoin(boundHandlingOptions.values(), ', '));
            obj.boundHandling = validateOption(val, 'boundHandlingOptions', message).value;
        end

        function obj = set.adaptPCR(obj,val)
            validateLogical(val, 'adaptPCR must be logical ''true'' or ''false''');
            obj.adaptPCR = val;
        end


        function obj = setProcedure(obj, procedure, varargin)
            % Method sets the properties of the class based on the selected procedures.
            %
            % USAGE: 
            %     obj.setProcedure(procedure, varargin)
            %
            % EXAMPLE: 
            %     * obj.setProcedure('simplex', {'xTolerance', 1e-6, 'funcTolerance', 1e-6,'maxFuncEvals', 1000})
            %     * obj.setProcedure('dream')
            %     * obj.setProcedure('ns', {'nLive', 150,'nMCMC', 0, 'propScale', 0.1, 'nsTolerance', 0.1})

            switch procedure

                case procedures.Calculate.value
                    % Parses the inputs and sets the object properties of
                    % the Calculate procedure
                    if ~isempty(varargin)
                        obj = obj.processCalculateInput(varargin{:});
                    end
                    obj.procedure = procedures.Calculate.value;

                case procedures.Simplex.value
                    % Parses the inputs and sets the object properties of
                    % the Simplex procedure
                    if ~isempty(varargin)
                        obj = obj.processSimplexInput(varargin{:});
                    end
                    obj.procedure = procedures.Simplex.value;

                case procedures.DE.value
                    % Parses the inputs and sets the object properties of
                    % the Differential Evolution procedure
                    if ~isempty(varargin)
                        obj = obj.processDEInput(varargin{:});
                    end
                    obj.procedure = procedures.DE.value;

                case procedures.NS.value
                    % Parses the inputs and sets the object properties of
                    % the Nested Sampler procedure
                    if ~isempty(varargin)
                        obj = obj.processNSInput(varargin{:});
                    end
                    obj.procedure = procedures.NS.value;

                case procedures.Dream.value
                    % Parses the inputs and sets the object properties of
                    % the DREAM procedure
                    if ~isempty(varargin)
                        obj = obj.processDreamInput(varargin{:});
                    end
                    obj.procedure = procedures.Dream.value;

                otherwise
                    % invalid procedure
                    throw(exceptions.invalidValue(sprintf('%s is not a supported procedure. The procedure must be a procedures enum or one of the following strings (%s)', procedure, strjoin(procedures.values(), ', '))));

            end

        end
    end

    %------------------------- Display Methods --------------------------
    methods (Access = protected)
        function groups = getPropertyGroups(obj)
            masterPropList = struct('parallel', {obj.parallel},...
                'procedure', {obj.procedure},...
                'calcSldDuringFit', {obj.calcSldDuringFit},...
                'display', {obj.display},...
                'xTolerance', {obj.xTolerance},...
                'funcTolerance', {obj.funcTolerance},...
                'maxFuncEvals', {obj.maxFuncEvals},...
                'maxIterations', {obj.maxIterations},...
                'updateFreq', {obj.updateFreq},...
                'updatePlotFreq', {obj.updatePlotFreq},...
                'populationSize', {obj.populationSize},...
                'fWeight', {obj.fWeight},...
                'crossoverProbability', {obj.crossoverProbability},...
                'strategy', {obj.strategy},...
                'targetValue', {obj.targetValue},...
                'numGenerations', {obj.numGenerations},...
                'nLive', {obj.nLive},...
                'nMCMC', {obj.nMCMC},...
                'propScale', {obj.propScale},...
                'nsTolerance', {obj.nsTolerance},...
                'resampleParams', {obj.resampleParams},...
                'nSamples', {obj.nSamples},...
                'nChains', {obj.nChains},...
                'jumpProbability', {obj.jumpProbability},...
                'pUnitGamma', {obj.pUnitGamma},...
                'boundHandling', {obj.boundHandling},...
                'adaptPCR', {obj.adaptPCR});

            simplexCell = {'xTolerance',...
                'funcTolerance',...
                'maxFuncEvals',...
                'maxIterations',...
                };

            deCell = {'populationSize',...
                'fWeight',...
                'crossoverProbability',...
                'strategy',...
                'targetValue',...
                'numGenerations'};

            nsCell = {'nLive',...
                'nMCMC',...
                'propScale',...
                'nsTolerance'};

            dreamCell = {'nSamples',...
                'nChains',...
                'jumpProbability',...
                'pUnitGamma',...
                'boundHandling',...
                'adaptPCR'};

            if isscalar(obj)
                dispPropList = masterPropList;
                if strcmpi(obj.procedure, 'calculate')
                    dispPropList = rmfield(masterPropList, [deCell, simplexCell, nsCell, dreamCell, {'updatePlotFreq','updateFreq'}]);
                elseif strcmpi(obj.procedure, 'simplex')
                    dispPropList = rmfield(masterPropList, [deCell, nsCell, dreamCell]);
                elseif strcmpi(obj.procedure, 'de')
                    dispPropList = rmfield(masterPropList, [simplexCell, nsCell, dreamCell]);
                    % Add the update back...
                elseif strcmpi(obj.procedure, 'ns')
                    dispPropList = rmfield(masterPropList, [simplexCell, deCell, dreamCell, {'updatePlotFreq','updateFreq'}]);
                elseif strcmpi(obj.procedure, 'dream')
                    dispPropList = rmfield(masterPropList, [simplexCell, deCell, nsCell, {'updatePlotFreq','updateFreq'}]);
                end
                groups = matlab.mixin.util.PropertyGroup(dispPropList);
            else
                groups = getPropertyGroups@matlab.mixin.CustomDisplay(obj);
            end
        end
    end

    %------------------------- Parsing Methods --------------------------
    methods (Access = private)

        function obj = processCalculateInput(obj, varargin)
            % Parses calculate keyword/value pairs and sets the properties of the class.
            %
            % obj.processCalculateInput('param', 'value')
            %
            % The parameters that can be set when using calculate procedure are
            % 1) parallel
            % 2) calcSldDuringFit
            % 3) resampleParams
            % 4) display

            % The default values for Calculate
            defaultParallel = parallelOptions.Single.value;
            defaultCalcSldDuringFit = false;
            defaultResampleParams = [0.9 50];
            defaultDisplay = displayOptions.Iter.value;

            % Creates the input parser for the calculate parameters
            p = inputParser;
            addParameter(p,'parallel',  defaultParallel,   @(x) isText(x) || isenum(x));
            addParameter(p,'calcSldDuringFit',   defaultCalcSldDuringFit,    @islogical);
            addParameter(p,'resampleParams', defaultResampleParams,  @isnumeric);
            addParameter(p,'display',   defaultDisplay,    @(x) isText(x) || isenum(x));
            properties = varargin{:};

            % Parses the input or raises invalidOption error
            errorMsg = 'Only parallel, calcSldDuringFit, resampleParams and display can be set while using the Calculate procedure';
            inputBlock = obj.parseInputs(p, properties, errorMsg);

            % Sets the values the for Calculate parameters
            obj.parallel = inputBlock.parallel;
            obj.calcSldDuringFit = inputBlock.calcSldDuringFit;
            obj.resampleParams = inputBlock.resampleParams;
            obj.display = inputBlock.display;
        end

        function obj = processSimplexInput(obj, varargin)
            % Parses simplex keyword/value pairs and sets the properties of the class.
            %
            % obj.parseSimplexInput('param', 'value')
            %
            % The parameters that can be set when using simplex procedure are
            % 1) xTolerance
            % 2) funcTolerance
            % 3) maxFuncEvals
            % 4) maxIterations
            % 5) updateFreq
            % 6) updatePlotFreq
            % 7) parallel
            % 8) calcSldDuringFit
            % 9) resampleParams
            % 10) display

            % The simplex default values
            defaultXTolerance = 1e-6;
            defaultFuncTolerance = 1e-6;
            defaultMaxFuncEvals = 10000;
            defaultMaxIterations = 1000;
            defaultUpdateFreq = -1;
            defaultUpdatePlotFreq = 1;
            defaultParallel = parallelOptions.Single.value;
            defaultCalcSldDuringFit = false;
            defaultResampleParams = [0.9 50];
            defaultDisplay = displayOptions.Iter.value;

            % Parses the input for simplex parameters
            p = inputParser;
            addParameter(p,'xTolerance',  defaultXTolerance,   @isnumeric);
            addParameter(p,'funcTolerance',   defaultFuncTolerance,    @isnumeric);
            addParameter(p,'maxFuncEvals', defaultMaxFuncEvals,  @isnumeric);
            addParameter(p,'maxIterations',   defaultMaxIterations,    @isnumeric);
            addParameter(p,'updateFreq',   defaultUpdateFreq,    @isnumeric);
            addParameter(p,'updatePlotFreq',   defaultUpdatePlotFreq,    @isnumeric);
            addParameter(p,'parallel',  defaultParallel,   @(x) isText(x) || isenum(x));
            addParameter(p,'calcSldDuringFit',   defaultCalcSldDuringFit,    @islogical);
            addParameter(p,'resampleParams', defaultResampleParams,  @isnumeric);
            addParameter(p,'display',   defaultDisplay,    @(x) isText(x) || isenum(x));
            properties = varargin{:};

            % Parses the input or raises invalidOption error
            errorMsg = 'Only xTolerance, funcTolerance, maxFuncEvals, maxIterations, updateFreq, updatePlotFreq, parallel, calcSldDuringFit, resampleParams and display can be set while using the Simplex procedure.';
            inputBlock = obj.parseInputs(p, properties, errorMsg);

            % Sets the values the for simplex parameters
            obj.xTolerance = inputBlock.xTolerance;
            obj.funcTolerance = inputBlock.funcTolerance;
            obj.maxFuncEvals = inputBlock.maxFuncEvals;
            obj.maxIterations = inputBlock.maxIterations;
            obj.updateFreq = inputBlock.updateFreq;
            obj.updatePlotFreq = inputBlock.updatePlotFreq;
            obj.parallel = inputBlock.parallel;
            obj.calcSldDuringFit = inputBlock.calcSldDuringFit;
            obj.resampleParams = inputBlock.resampleParams;
            obj.display = inputBlock.display;
        end

        function obj = processDEInput(obj, varargin)
            % Parses differential evolution keyword/value pairs and sets the properties of the class.
            %
            % obj.processDEInput('param', 'value')
            %
            % The parameters that can be set when using de procedure are
            % 1) populationSize
            % 2) fWeight
            % 3) crossoverProbability
            % 4) strategy
            % 5) targetValue
            % 6) numGenerations
            % 7) parallel
            % 8) calcSldDuringFit
            % 9) resampleParams
            % 10) display

            % The default values for DE
            defaultPopulationSize = 20;
            defaultFWeight = 0.5;
            defaultCrossoverProbability = 0.8;
            defaultStrategy = 4;
            defaultTargetValue = 1;
            defaultNumGenerations = 500;
            defaultParallel = parallelOptions.Single.value;
            defaultCalcSldDuringFit = false;
            defaultResampleParams = [0.9 50];
            defaultDisplay = displayOptions.Iter.value;

            % Creates the input parser for the DE parameters
            p = inputParser;
            addParameter(p,'populationSize',  defaultPopulationSize,   @isnumeric);
            addParameter(p,'fWeight',   defaultFWeight,    @isnumeric);
            addParameter(p,'crossoverProbability', defaultCrossoverProbability,  @isnumeric);
            addParameter(p,'strategy',   defaultStrategy,    @isnumeric);
            addParameter(p,'targetValue',   defaultTargetValue,    @isnumeric);
            addParameter(p,'numGenerations',   defaultNumGenerations,    @isnumeric);
            addParameter(p,'parallel',  defaultParallel,   @(x) isText(x) || isenum(x));
            addParameter(p,'calcSldDuringFit',   defaultCalcSldDuringFit,    @islogical);
            addParameter(p,'resampleParams', defaultResampleParams,  @isnumeric);
            addParameter(p,'display',   defaultDisplay,    @(x) isText(x) || isenum(x));
            properties = varargin{:};

            % Parses the input or raises invalidOption error
            errorMsg = 'Only populationSize, fWeight, crossoverProbability, strategy, targetValue, numGenerations, parallel, calcSldDuringFit, resampleParams and display can be set while using the Differential Evolution procedure';
            inputBlock = obj.parseInputs(p, properties, errorMsg);

            % Sets the values the for DE parameters
            obj.populationSize = inputBlock.populationSize;
            obj.fWeight = inputBlock.fWeight;
            obj.crossoverProbability = inputBlock.crossoverProbability;
            obj.strategy = inputBlock.strategy;
            obj.targetValue = inputBlock.targetValue;
            obj.numGenerations = inputBlock.numGenerations;
            obj.parallel = inputBlock.parallel;
            obj.calcSldDuringFit = inputBlock.calcSldDuringFit;
            obj.resampleParams = inputBlock.resampleParams;
            obj.display = inputBlock.display;
        end

        function obj = processNSInput(obj, varargin)
            % Parses nested sampler keyword/value pairs and sets the properties of the class.
            %
            % obj.processNSInput('param', 'value')
            %
            % The parameters that can be set when using nested sampler procedure are
            % 1) nLive
            % 2) nMCMC
            % 3) propScale
            % 4) nsTolerance
            % 5) parallel
            % 6) calcSldDuringFit
            % 7) resampleParams
            % 8) display

            % The default values for NS
            defaultnLive = 150;
            defaultnMCMC = 0;
            defaultPropScale = 0.1;
            defaultNsTolerance = 0.1;
            defaultParallel = parallelOptions.Single.value;
            defaultCalcSldDuringFit = false;
            defaultResampleParams = [0.9 50];
            defaultDisplay = displayOptions.Iter.value;

            % Creates the input parser for the NS parameters
            p = inputParser;
            addParameter(p,'nLive',  defaultnLive,   @isnumeric);
            addParameter(p,'nMCMC',   defaultnMCMC,    @isnumeric);
            addParameter(p,'propScale', defaultPropScale,  @isnumeric);
            addParameter(p,'nsTolerance',   defaultNsTolerance,    @isnumeric);
            addParameter(p,'parallel',  defaultParallel,   @(x) isText(x) || isenum(x));
            addParameter(p,'calcSldDuringFit',   defaultCalcSldDuringFit,    @islogical);
            addParameter(p,'resampleParams', defaultResampleParams,  @isnumeric);
            addParameter(p,'display',   defaultDisplay,    @(x) isText(x) || isenum(x));
            properties = varargin{:};

            % Parses the input or raises invalidOption error
            errorMsg = 'Only nLive, nMCMC, propScale, nsTolerance, parallel, calcSldDuringFit, resampleParams and display can be set while using the Nested Sampler procedure';
            inputBlock = obj.parseInputs(p, properties, errorMsg);

            % Sets the values the for NS parameters
            obj.nLive = inputBlock.nLive;
            obj.nMCMC = inputBlock.nMCMC;
            obj.propScale = inputBlock.propScale;
            obj.nsTolerance = inputBlock.nsTolerance;
            obj.parallel = inputBlock.parallel;
            obj.calcSldDuringFit = inputBlock.calcSldDuringFit;
            obj.resampleParams = inputBlock.resampleParams;
            obj.display = inputBlock.display;
        end

        function obj = processDreamInput(obj, varargin)
            % Parses Dream keyword/value pairs and sets the properties of the class.
            %
            % obj.processDreamInput('param', 'value')
            %
            % The parameters that can be set when using Dream procedure are
            % 1) nSamples
            % 2) nChains
            % 3) jumpProbability
            % 4) pUnitGamma
            % 5) boundHandling
            % 6) adaptPCR
            % 7) parallel
            % 8) calcSldDuringFit
            % 9) resampleParams
            % 10) display

            % The default values for Dream
            defaultNSamples = 50000;
            defaultNChains = 10;
            defaultJumpProbability = 0.5;
            defaultPUnitGamma = 0.2;
            defaultBoundHandling = boundHandlingOptions.Fold.value;
            defaultAdaptPCR = false;
            defaultParallel = parallelOptions.Single.value;
            defaultCalcSldDuringFit = false;
            defaultResampleParams = [0.9 50];
            defaultDisplay = displayOptions.Iter.value;

            % Creates the input parser for the Dream parameters
            p = inputParser;
            addParameter(p,'nSamples',  defaultNSamples,   @isnumeric);
            addParameter(p,'nChains',   defaultNChains,    @isnumeric);
            addParameter(p,'jumpProbability', defaultJumpProbability,  @isnumeric);
            addParameter(p,'pUnitGamma',   defaultPUnitGamma,    @isnumeric);
            addParameter(p,'boundHandling',   defaultBoundHandling, @(x) isText(x) || isenum(x));
            addParameter(p,'adaptPCR', defaultAdaptPCR, @islogical);
            addParameter(p,'parallel',  defaultParallel,   @(x) isText(x) || isenum(x));
            addParameter(p,'calcSldDuringFit',   defaultCalcSldDuringFit,    @islogical);
            addParameter(p,'resampleParams', defaultResampleParams,  @isnumeric);
            addParameter(p,'display',   defaultDisplay,    @(x) isText(x) || isenum(x));
            properties = varargin{:};

            % Parses the input or raises invalidOption error
            errorMsg = 'Only nSamples, nChains, jumpProbability, pUnitGamma, boundHandling, adaptPCR, parallel, calcSldDuringFit, resampleParams and display can be set while using the DREAM procedure';
            inputBlock = obj.parseInputs(p, properties, errorMsg);

            % Sets the values the for Dream parameters
            obj.nSamples = inputBlock.nSamples;
            obj.nChains = inputBlock.nChains;
            obj.jumpProbability = inputBlock.jumpProbability;
            obj.pUnitGamma = inputBlock.pUnitGamma;
            obj.boundHandling = inputBlock.boundHandling;
            obj.adaptPCR = inputBlock.adaptPCR;
            obj.parallel = inputBlock.parallel;
            obj.calcSldDuringFit = inputBlock.calcSldDuringFit;
            obj.resampleParams = inputBlock.resampleParams;
            obj.display = inputBlock.display;
        end

        function inputBlock = parseInputs(~, p, properties, errorMsg)
            % Parses the input or raises invalidOption error
            try
                parse(p, properties{:});
                inputBlock = p.Results;
            catch ME
                if (strcmp(ME.identifier,'MATLAB:InputParser:UnmatchedParameter'))
                    throw(exceptions.invalidOption(errorMsg));
                else
                    rethrow(ME)
                end
            end
        end

    end
end
