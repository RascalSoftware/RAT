classdef controlsClass < matlab.mixin.CustomDisplay
     
    properties
        parallel = 'single'
        procedure = 'calculate'
        calcSldDuringFit = false
        resamPars = [0.9 50]
        display = 'iter'
        
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
        boundHandling = 'fold'     % Boundary handling
    end
    
    %------------------------- Set and Get ------------------------------
    methods
        function obj = set.parallel(obj,val)
            if ~strcmpi(val,{'single', 'points', 'contrasts', 'all'})
                throw(invalidOption('Type must be ''single'', ''points'', ''contrasts'', ''all'''));
            end
            obj.parallel = val;
        end
        
        function obj = set.procedure(obj,val)
            if ~strcmpi(val,{'calculate','simplex','DE', 'NS','dream'})
                throw(invalidOption('Type must be ''calculate'', ''simplex'', ''DE'', ''dream'' or ''NS'''));
            end
            obj.procedure = val;
        end
        
        function obj = set.calcSldDuringFit(obj,val)
            if ~islogical(val)
                throw(invalidValue('Type must be logical ''true'' or ''false'''));
            end
            obj.calcSldDuringFit = val;
        end

        function obj = set.display(obj,val)
            if ~strcmpi(val,{'off','iter','notify','final'})
                throw(invalidOption('Display must be set to ''off'', ''iter'', ''notify'' or ''final'' '));
            end
            obj.display = val;
        end 

        function obj = set.resamPars(obj,val)
            if length(val) ~= 2
                throw(invalidValue('resamPars must have length of 2'));
            end
            if (~isnumeric(val(1)) || val(1) < 0 || val(1) > 1)
                throw(invalidValue('resamPars(0) must be between 0 and 1'));
            end
            if (~isnumeric(val(2)) || val(2) <= 0)
                throw(invalidValue('resamPars(1) must be a number greater than 0'));
            end
            obj.resamPars = val;
        end  

        % Simplex control methods        
        function obj = set.tolX(obj,val)
            if ~isnumeric(val)
                throw(invalidValue('tolX must be number'));
            end
            obj.tolX = val;
        end
         
        function obj = set.tolFun(obj,val)
            if ~isnumeric(val)
                throw(invalidValue('tolFun must be number'));
            end
            obj.tolFun = val;
        end
        
        function obj = set.maxFunEvals(obj,val)
            if ~isnumeric(val)
                throw(invalidValue('maxFunEvals must be number'));
            end
            obj.maxFunEvals = val;
        end
        
        function obj = set.maxIter(obj,val)
            if ~isnumeric(val)
                throw(invalidValue('maxIter must be number'));
            end
            obj.maxIter = val;
        end
        
        % DE controls methods
        function obj = set.populationSize(obj,val)
            if (~isnumeric(val) || val < 1)
                throw(invalidValue('populationSize must be a number greater or equal to 1'));
            end
            obj.populationSize = val;
        end
        
        function obj = set.fWeight(obj,val)
            if ~isnumeric(val)
                throw(invalidValue('fWeight must be number'));
            end
            obj.fWeight = val;
        end
        
        function obj = set.crossoverProbability(obj,val)
            if (~isnumeric(val) || val < 0 || val > 1)
                throw(invalidValue('crossoverProbability must be a number between 0 and 1'));
            end
            obj.crossoverProbability = val;
        end
        
        function obj = set.strategy(obj,val)
            if (~isnumeric(val) || ~(round(val) == val) || val < 1 || val > 6)
                throw(invalidValue('strategy must be an integer between 1 and 6'));
            end
            switch val
                case 1
                    message = 'Selecting DE/rand/1';
                case 2
                    message = 'Selecting DE/local-to-best/1';
                case 3
                    message = 'Selecting DE/best/1 with jitter';
                case 4
                    message = 'Selecting DE/rand/1 with per-vector-dither';
                case 5
                    message = 'Selecting DE/rand/1 with per-generation-dither';
                case 6
                    message = 'Selecting DE/rand/1 either-or-algorithm';
            end
            disp(message);   
            obj.strategy = val;
        end
        
        function obj = set.targetValue(obj,val)
            if (~isnumeric(val) || val < 1 )
                throw(invalidValue('Target value must be a number greater or equal to 1'));
            end 
        obj.targetValue = val;
        end
        
        function obj = set.numGenerations(obj,val)
            if (~isnumeric(val) || val < 1 )
                throw(invalidValue('numGenerations value must be a number greater or equal to 1'));
            end 
        obj.numGenerations = val;
        end
         
        % NS control methods
        function obj = set.Nlive(obj,val)
            if (~isnumeric(val) || val < 1)
                throw(invalidValue('Nlive must be a number greater or equal to 1'));
            end
            obj.Nlive = val;
        end
        
        function obj = set.Nmcmc(obj,val)
            if (~isnumeric(val) || val < 0)
                throw(invalidValue('Nmcmc must be a number greater or equal than 0'));
            end
            obj.Nmcmc = val;
        end
        
        function obj = set.propScale(obj,val)
             if (~isnumeric(val) || val < 0 || val > 1)
                throw(invalidValue('propScale must be a number between 0 and 1'));
             end
             obj.propScale = val;
        end
        
        function obj = set.nsTolerance(obj,val)
             if (~isnumeric(val) || val < 0 )
                throw(invalidValue('nsTolerance must be a number greater or equal to 0'));
             end
             obj.nsTolerance = val;
        end

        % DREAM methods
        function obj = set.nSamples(obj,val)
            if (~isnumeric(val) || val < 0)
                throw(invalidValue('nSample must be a number greater oe equal to 0'));
            end
            obj.nSamples = val;
        end 

        function obj = set.nChains(obj,val)
            if (~isnumeric(val) || ~(round(val) == val) || val <= 0 || isnan(val) || isinf(val))
                throw(invalidValue('nChains must be a finite integer greater than 0'));
            end
            obj.nChains = val;
        end 

        function obj = set.lambda(obj,val)
            if (~isnumeric(val) || val < 0 || val > 1)
                throw(invalidValue('Jump probability lambda must be a fraction between 0 and 1'));
            end
            obj.lambda = val;
        end 

        function obj = set.pUnitGamma(obj,val)
            if (~isnumeric(val) || val < 0 || val > 1)
                throw(invalidValue('P_unit_gamma must be a fraction between 0 and 1'));
            end
            obj.pUnitGamma = val;
        end 

        function obj = set.boundHandling(obj,val)
            if ~strcmpi(val, {'none','reflect','bound','fold'})
                throw(invalidOption('Boundary handling must be ''none'', ''reflect'', ''bound'' or ''none'''));
            end
            obj.boundHandling = val;
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
