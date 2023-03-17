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
            if ~islogical(val)
                throw(invalidType('Type must be logical ''true'' or ''false'''));
            end
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
                'boundHandling', {obj.boundHandling});
 
            simplexCell = {'tolX',...
                'tolFun',...
                'maxFunEvals',...
                'maxIter'};
            
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
                'boundHandling'};
            
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
end
