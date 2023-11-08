classdef controlsClass < matlab.mixin.CustomDisplay

    properties
        parallel = parallelOptions.Single.value
        procedure = procedures.Calculate.value
        calcSldDuringFit = false
        resamPars = [0.9 50]
        display = displayOptions.Iter.value

        %Procedure arguments
        %(1) Simplex
        tolX = 1e-6
        tolFun = 1e-6
        maxFunEvals = 10000
        maxIter = 1000
        updateFreq = -1
        updatePlotFreq = -1

        %(2) Differential Evolution
        populationSize = 20
        fWeight = 0.5
        crossoverProbability = 0.8
        strategy = 4
        targetValue = 1
        numGenerations = 500

        %(3) Nested Sampler (for Matlab version. There will be more options
        % with the C version)
        Nlive = 150
        Nmcmc = 0
        propScale = 0.1     % Used if MCMC is used
        nsTolerance = 0.1     % Target stopping tolerance

        %(4) DREAM
        nSamples = 50000;          % Total number of samples
        nChains = 10               % Number of MCMC chains..
        lambda = 0.5               % Jump probabilities
        pUnitGamma = 0.2
        boundHandling = boundHandlingOptions.Fold.value     % Boundary handling
        adaptPCR = false;
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

        function obj = set.resamPars(obj,val)
            if length(val) ~= 2
                throw(invalidValue('resamPars must have length of 2'));
            end

            validateNumber(val, 'resamPars must be a number array');

            if (val(1) < 0 || val(1) > 1)
                throw(invalidValue('resamPars(0) must be between 0 and 1'));
            end
            if val(2) <= 0
                throw(invalidValue('resamPars(1) must be greater than 0'));
            end
            obj.resamPars = val;
        end

        % Simplex control methods
        function obj = set.tolX(obj, val)
            obj.tolX = validateNumber(val, 'tolX must be a number');
        end

        function obj = set.tolFun(obj, val)
            obj.tolFun = validateNumber(val, 'tolFun must be a number');
        end

        function obj = set.maxFunEvals(obj, val)
            obj.maxFunEvals = validateNumber(val, 'maxFunEvals must be a number');
        end

        function obj = set.maxIter(obj, val)
            obj.maxIter = validateNumber(val, 'maxIter must be a number');
        end

        % DE controls methods
        function obj = set.populationSize(obj, val)
            validateNumber(val, 'populationSize must be a number');
            if val < 1
                throw(invalidValue('populationSize must be greater or equal to 1'));
            end
            obj.populationSize = val;
        end

        function obj = set.fWeight(obj,val)
            obj.fWeight = validateNumber(val,'fWeight must be a number');
        end

        function obj = set.crossoverProbability(obj,val)
            validateNumber(val, 'crossoverProbability must be a number');
            if (val < 0 || val > 1)
                throw(invalidValue('crossoverProbability must be between 0 and 1'));
            end
            obj.crossoverProbability = val;
        end

        function obj = set.strategy(obj,val)
            message = sprintf('strategy must be a strategyOptions enum or one of the following integers (%s)', ...
                strjoin(string(strategyOptions.values()), ', '));

            obj.strategy = validateOption(val, 'strategyOptions', message).value;
        end

        function obj = set.targetValue(obj,val)
            validateNumber(val, 'targetValue must be a number');
            if val < 1
                throw(invalidValue('targetValue must be greater or equal to 1'));
            end
            obj.targetValue = val;
        end

        function obj = set.numGenerations(obj, val)
            validateNumber(val, 'numGenerations value must be a number');
            if val < 1
                throw(invalidValue('numGenerations must be greater or equal to 1'));
            end
            obj.numGenerations = val;
        end

        % NS control methods
        function obj = set.Nlive(obj, val)
            validateNumber(val, 'Nlive must be a number');
            if val < 1
                throw(invalidValue('Nlive must be greater or equal to 1'));
            end
            obj.Nlive = val;
        end

        function obj = set.Nmcmc(obj, val)
            validateNumber(val, 'Nmcmc must be a number');
            if val < 0
                throw(invalidValue('Nmcmc must be greater or equal than 0'));
            end
            obj.Nmcmc = val;
        end

        function obj = set.propScale(obj, val)
            validateNumber(val, 'propScale must be a number');
            if (val < 0 || val > 1)
                throw(invalidValue('propScale must be between 0 and 1'));
            end
            obj.propScale = val;
        end

        function obj = set.nsTolerance(obj,val)
            validateNumber(val, 'nsTolerance must be a number ');
            if val < 0
                throw(invalidValue('nsTolerance must be greater or equal to 0'));
            end
            obj.nsTolerance = val;
        end

        % DREAM methods
        function obj = set.nSamples(obj,val)
            validateNumber(val, 'nSample must be a number ');
            if val < 0
                throw(invalidValue('nSample must be greater or equal to 0'));
            end
            obj.nSamples = val;
        end

        function obj = set.nChains(obj,val)
            validateNumber(val, 'nChains must be a number ');
            if (~(round(val) == val) || val <= 0 || isnan(val) || isinf(val))
                throw(invalidValue('nChains must be a finite integer greater than 0'));
            end
            obj.nChains = val;
        end

        function obj = set.lambda(obj,val)
            validateNumber(val, 'lambda must be a number');
            if (val < 0 || val > 1)
                throw(invalidValue('Jump probability lambda must be a fraction between 0 and 1'));
            end
            obj.lambda = val;
        end

        function obj = set.pUnitGamma(obj,val)
            validateNumber(val, 'pUnitGamma must be a number');
            if (val < 0 || val > 1)
                throw(invalidValue('pUnitGamma must be a fraction between 0 and 1'));
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
            % obj.setProcedure(procedure, varargin)
            %
            % Usage Examples:
            % obj.setProcedure('simplex',...
            %                   {'tolX', 1e-6,...
            %                   'tolFun', 1e-6,...
            %                   'maxFunEvals', 1000})
            % obj.setProcedure('dream')
            % obj.setProcedure('ns',
            %                  {'Nlive', 150,...
            %                  'Nmcmc', 0,...
            %                  'propScale', 0.1,...
            %                  'nsTolerance', 0.1})

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
                    throw(invalidValue(sprintf('%s is not a supported procedure. The procedure must be a procedures enum or one of the following strings (%s)', procedure, strjoin(procedures.values(), ', '))));

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
                'tolX', {obj.tolX},...
                'tolFun', {obj.tolFun},...
                'maxFunEvals', {obj.maxFunEvals},...
                'maxIter', {obj.maxIter},...
                'updateFreq', {obj.updateFreq},...
                'updatePlotFreq', {obj.updatePlotFreq},...
                'populationSize', {obj.populationSize},...
                'fWeight', {obj.fWeight},...
                'crossoverProbability', {obj.crossoverProbability},...
                'strategy', {obj.strategy},...
                'targetValue', {obj.targetValue},...
                'numGenerations', {obj.numGenerations},...
                'Nlive', {obj.Nlive},...
                'Nmcmc', {obj.Nmcmc},...
                'propScale', {obj.propScale},...
                'nsTolerance', {obj.nsTolerance},...
                'resamPars', {obj.resamPars},...
                'nSamples', {obj.nSamples},...
                'nChains', {obj.nChains},...
                'lambda', {obj.lambda},...
                'pUnitGamma', {obj.pUnitGamma},...
                'boundHandling', {obj.boundHandling},...
                'adaptPCR', {obj.adaptPCR});

            simplexCell = {'tolX',...
                'tolFun',...
                'maxFunEvals',...
                'maxIter',...
                'updateFreq',...
                'updatePlotFreq'};

            deCell = {'populationSize',...
                'fWeight',...
                'crossoverProbability',...
                'strategy',...
                'targetValue',...
                'numGenerations'};

            nsCell = {'Nlive',...
                'Nmcmc',...
                'propScale',...
                'nsTolerance'};

            dreamCell = {'nSamples',...
                'nChains',...
                'lambda',...
                'pUnitGamma',...
                'boundHandling',...
                'adaptPCR'};

            if isscalar(obj)
                dispPropList = masterPropList;
                if strcmpi(obj.procedure, 'calculate')
                    dispPropList = rmfield(masterPropList, [deCell, simplexCell, nsCell, dreamCell]);
                elseif strcmpi(obj.procedure, 'simplex')
                    dispPropList = rmfield(masterPropList, [deCell, nsCell, dreamCell]);
                elseif strcmpi(obj.procedure, 'de')
                    dispPropList = rmfield(masterPropList, [simplexCell, nsCell, dreamCell]);
                elseif strcmpi(obj.procedure, 'ns')
                    dispPropList = rmfield(masterPropList, [simplexCell, deCell, dreamCell]);
                elseif strcmpi(obj.procedure, 'dream')
                    dispPropList = rmfield(masterPropList, [simplexCell, deCell, nsCell]);
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
            % 3) resamPars
            % 4) display

            % The default values for Calculate
            defaultParallel = parallelOptions.Single.value;
            defaultCalcSldDuringFit = false;
            defaultResamPars = [0.9 50];
            defaultDisplay = displayOptions.Iter.value;

            % Creates the input parser for the calculate parameters
            p = inputParser;
            addParameter(p,'parallel',  defaultParallel,   @(x) isText(x) || isenum(x));
            addParameter(p,'calcSldDuringFit',   defaultCalcSldDuringFit,    @islogical);
            addParameter(p,'resamPars', defaultResamPars,  @isnumeric);
            addParameter(p,'display',   defaultDisplay,    @(x) isText(x) || isenum(x));
            properties = varargin{:};

            % Parses the input or raises invalidOption error
            errorMsg = 'Only parallel, calcSldDuringFit, resamPars and display can be set while using the Calculate procedure';
            inputBlock = obj.parseInputs(p, properties, errorMsg);

            % Sets the values the for Calculate parameters
            obj.parallel = inputBlock.parallel;
            obj.calcSldDuringFit = inputBlock.calcSldDuringFit;
            obj.resamPars = inputBlock.resamPars;
            obj.display = inputBlock.display;
        end

        function obj = processSimplexInput(obj, varargin)
            % Parses simplex keyword/value pairs and sets the properties of the class.
            %
            % obj.parseSimplexInput('param', 'value')
            %
            % The parameters that can be set when using simplex procedure are
            % 1) tolX
            % 2) tolFun
            % 3) maxFunEvals
            % 4) maxIter
            % 5) updateFreq
            % 6) updatePlotFreq
            % 7) parallel
            % 8) calcSldDuringFit
            % 9) resamPars
            % 10) display

            % The simplex default values
            defaultTolX = 1e-6;
            defaultTolFun = 1e-6;
            defaultMaxFunEvals = 10000;
            defaultMaxIter = 1000;
            defaultUpdateFreq = -1;
            defaultUpdatePlotFreq = -1;
            defaultParallel = parallelOptions.Single.value;
            defaultCalcSldDuringFit = false;
            defaultResamPars = [0.9 50];
            defaultDisplay = displayOptions.Iter.value;

            % Parses the input for simplex parameters
            p = inputParser;
            addParameter(p,'tolX',  defaultTolX,   @isnumeric);
            addParameter(p,'tolFun',   defaultTolFun,    @isnumeric);
            addParameter(p,'maxFunEvals', defaultMaxFunEvals,  @isnumeric);
            addParameter(p,'maxIter',   defaultMaxIter,    @isnumeric);
            addParameter(p,'updateFreq',   defaultUpdateFreq,    @isnumeric);
            addParameter(p,'updatePlotFreq',   defaultUpdatePlotFreq,    @isnumeric);
            addParameter(p,'parallel',  defaultParallel,   @(x) isText(x) || isenum(x));
            addParameter(p,'calcSldDuringFit',   defaultCalcSldDuringFit,    @islogical);
            addParameter(p,'resamPars', defaultResamPars,  @isnumeric);
            addParameter(p,'display',   defaultDisplay,    @(x) isText(x) || isenum(x));
            properties = varargin{:};

            % Parses the input or raises invalidOption error
            errorMsg = 'Only tolX, tolFun, maxFunEvals, maxIter, updateFreq, updatePlotFreq, parallel, calcSldDuringFit, resamPars and display can be set while using the Simplex procedure.';
            inputBlock = obj.parseInputs(p, properties, errorMsg);

            % Sets the values the for simplex parameters
            obj.tolX = inputBlock.tolX;
            obj.tolFun = inputBlock.tolFun;
            obj.maxFunEvals = inputBlock.maxFunEvals;
            obj.maxIter = inputBlock.maxIter;
            obj.updateFreq = inputBlock.updateFreq;
            obj.updatePlotFreq = inputBlock.updatePlotFreq;
            obj.parallel = inputBlock.parallel;
            obj.calcSldDuringFit = inputBlock.calcSldDuringFit;
            obj.resamPars = inputBlock.resamPars;
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
            % 9) resamPars
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
            defaultResamPars = [0.9 50];
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
            addParameter(p,'resamPars', defaultResamPars,  @isnumeric);
            addParameter(p,'display',   defaultDisplay,    @(x) isText(x) || isenum(x));
            properties = varargin{:};

            % Parses the input or raises invalidOption error
            errorMsg = 'Only populationSize, fWeight, crossoverProbability, strategy, targetValue, numGenerations, parallel, calcSldDuringFit, resamPars and display can be set while using the Differential Evolution procedure';
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
            obj.resamPars = inputBlock.resamPars;
            obj.display = inputBlock.display;
        end

        function obj = processNSInput(obj, varargin)
            % Parses nested sampler keyword/value pairs and sets the properties of the class.
            %
            % obj.processNSInput('param', 'value')
            %
            % The parameters that can be set when using nested sampler procedure are
            % 1) Nlive
            % 2) Nmcmc
            % 3) propScale
            % 4) nsTolerance
            % 5) parallel
            % 6) calcSldDuringFit
            % 7) resamPars
            % 8) display

            % The default values for NS
            defaultNlive = 150;
            defaultNmcmc = 0;
            defaultPropScale = 0.1;
            defaultNsTolerance = 0.1;
            defaultParallel = parallelOptions.Single.value;
            defaultCalcSldDuringFit = false;
            defaultResamPars = [0.9 50];
            defaultDisplay = displayOptions.Iter.value;

            % Creates the input parser for the NS parameters
            p = inputParser;
            addParameter(p,'Nlive',  defaultNlive,   @isnumeric);
            addParameter(p,'Nmcmc',   defaultNmcmc,    @isnumeric);
            addParameter(p,'propScale', defaultPropScale,  @isnumeric);
            addParameter(p,'nsTolerance',   defaultNsTolerance,    @isnumeric);
            addParameter(p,'parallel',  defaultParallel,   @(x) isText(x) || isenum(x));
            addParameter(p,'calcSldDuringFit',   defaultCalcSldDuringFit,    @islogical);
            addParameter(p,'resamPars', defaultResamPars,  @isnumeric);
            addParameter(p,'display',   defaultDisplay,    @(x) isText(x) || isenum(x));
            properties = varargin{:};

            % Parses the input or raises invalidOption error
            errorMsg = 'Only Nlive, Nmcmc, propScale, nsTolerance, parallel, calcSldDuringFit, resamPars and display can be set while using the Nested Sampler procedure';
            inputBlock = obj.parseInputs(p, properties, errorMsg);

            % Sets the values the for NS parameters
            obj.Nlive = inputBlock.Nlive;
            obj.Nmcmc = inputBlock.Nmcmc;
            obj.propScale = inputBlock.propScale;
            obj.nsTolerance = inputBlock.nsTolerance;
            obj.parallel = inputBlock.parallel;
            obj.calcSldDuringFit = inputBlock.calcSldDuringFit;
            obj.resamPars = inputBlock.resamPars;
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
            % 3) lambda
            % 4) pUnitGamma
            % 5) boundHandling
            % 6) adaptPCR
            % 7) parallel
            % 8) calcSldDuringFit
            % 9) resamPars
            % 10) display

            % The default values for Dream
            defaultNSamples = 50000;
            defaultNChains = 10;
            defaultLambda = 0.5;
            defaultPUnitGamma = 0.2;
            defaultBoundHandling = boundHandlingOptions.Fold.value;
            defaultAdaptPCR = false;
            defaultParallel = parallelOptions.Single.value;
            defaultCalcSldDuringFit = false;
            defaultResamPars = [0.9 50];
            defaultDisplay = displayOptions.Iter.value;

            % Creates the input parser for the Dream parameters
            p = inputParser;
            addParameter(p,'nSamples',  defaultNSamples,   @isnumeric);
            addParameter(p,'nChains',   defaultNChains,    @isnumeric);
            addParameter(p,'lambda', defaultLambda,  @isnumeric);
            addParameter(p,'pUnitGamma',   defaultPUnitGamma,    @isnumeric);
            addParameter(p,'boundHandling',   defaultBoundHandling, @(x) isText(x) || isenum(x));
            addParameter(p,'adaptPCR', defaultAdaptPCR, @islogical);
            addParameter(p,'parallel',  defaultParallel,   @(x) isText(x) || isenum(x));
            addParameter(p,'calcSldDuringFit',   defaultCalcSldDuringFit,    @islogical);
            addParameter(p,'resamPars', defaultResamPars,  @isnumeric);
            addParameter(p,'display',   defaultDisplay,    @(x) isText(x) || isenum(x));
            properties = varargin{:};

            % Parses the input or raises invalidOption error
            errorMsg = 'Only nSamples, nChains, lambda, pUnitGamma, boundHandling, adaptPCR, parallel, calcSldDuringFit, resamPars and display can be set while using the DREAM procedure';
            inputBlock = obj.parseInputs(p, properties, errorMsg);

            % Sets the values the for Dream parameters
            obj.nSamples = inputBlock.nSamples;
            obj.nChains = inputBlock.nChains;
            obj.lambda = inputBlock.lambda;
            obj.pUnitGamma = inputBlock.pUnitGamma;
            obj.boundHandling = inputBlock.boundHandling;
            obj.adaptPCR = inputBlock.adaptPCR;
            obj.parallel = inputBlock.parallel;
            obj.calcSldDuringFit = inputBlock.calcSldDuringFit;
            obj.resamPars = inputBlock.resamPars;
            obj.display = inputBlock.display;
        end

        function inputBlock = parseInputs(~, p, properties, errorMsg)
            % Parses the input or raises invalidOption error
            try
                parse(p, properties{:});
                inputBlock = p.Results;
            catch ME
                if (strcmp(ME.identifier,'MATLAB:InputParser:UnmatchedParameter'))
                    throw(invalidOption(errorMsg));
                else
                    rethrow(ME)
                end
            end
        end

    end
end
