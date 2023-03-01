classdef controlsDef < matlab.mixin.CustomDisplay
    
    
    properties
        
        parallel = 'single'
        procedure = 'calculate'
        calcSldDuringFit = 'no'
        resamPars = [0.9 50];
        
        %Algargs (varies with procedure)
        %(1) Simplex
        display = 'iter'
        tolX = 1e-6
        tolFun = 1e-6
        maxFunEvals = 10000
        maxIter = 1000
        updateFreq = -1;
        updatePlotFreq = -1;
        
        %(2) Differential Evolution
        populationSize = 20
        F_weight = 0.5
        crossoverProbability = 0.8;
        strategy = 4;
        targetValue = 1;
        numGenerations = 500;

        %(3) Nested Sampler (for Matlab version. There will be more options
        %with the C version)
        Nlive = 150
        Nmcmc = 0
        propScale = 0.1     %Used if MCMC is used
        nsTolerance = 0.1     %Target stopping tolerance
        
        %(4) Bayes MCMC
%         method = 'dram';
%         nsimu = 1000;
%         adaptint = 100;
%         burnin = 100;
%         repeats = 1; 

        %(5) DREAM
        nSamples = 50000;          % Total number of samples
        nChains = 10;               % Number of MCMC chains..
        lambda = 0.5;               % Jump probabilities
        p_unit_gamma = 0.2;
        boundHandling = 'fold';     % Boundary handling
        % prior = true;

    end
    
    %------------------------- Set and Get ------------------------------
    methods
        function obj = set.parallel(obj,val)
            if ~strcmpi(val,{'single', 'points', 'contrasts', 'all'})
                error('Type must be ''single'', ''points'', ''contrasts'', ''all'' ');
            end

            obj.parallel = val;
        end
        
        function obj = set.procedure(obj,val)
            if ~strcmpi(val,{'calculate','simplex','DE', 'NS','dream'})
                error('Type must be ''calculate'', ''simplex'', ''DE'', ''dream'' or ''NS'' ');
            end
            
            obj.procedure = val;
        end
        
        
        function obj = set.calcSldDuringFit(obj,val)
            if ~strcmpi(val,{'yes','no'})
                error('Type must be ''yes'' or ''no'' ');
            end
            
%             if strcmpi(val,'no')
%                 warning('Will automatically default to ''yes'' if resample is set in problemDef')
%             end
            obj.calcSldDuringFit = val;
        end
        
        
         %Simplex control methods
         function obj = set.display(obj,val)
             if ~strcmpi(val,{'off','iter','notify','final'})
                 error('Display must be set to ''off'', ''iter'', ''notify'' or ''final'' ');
             end
             obj.display = val;
         end
         
         function obj = set.tolX(obj,val)
             if ~isnumeric(val)
                 error('tolX must be numeric');
             end
             obj.tolX = val;
         end
         
         function obj = set.tolFun(obj,val)
             if ~isnumeric(val)
                 error('tolFun must be numeric');
             end
             obj.tolFun = val;
         end
         
         function obj = set.maxFunEvals(obj,val)
             if ~isnumeric(val)
                 error('maxFunEvals must be numeric');
             end
             obj.maxFunEvals = val;
         end
         
         function obj = set.maxIter(obj,val)
             if ~isnumeric(val)
                 error('maxIter must be numeric');
             end
             obj.maxIter = val;
         end
         
         %DE controls methods
         function obj = set.populationSize(obj,val)
             if (~isnumeric(val) || val < 1)
                 error('populationSize must be numeric and >1');
             end
             obj.populationSize = val;
         end
         
         function obj = set.F_weight(obj,val)
             if ~isnumeric(val)
                 error('F_weight must be numeric');
             end
             obj.F_weight = val;
         end
         
         function obj = set.crossoverProbability(obj,val)
             if (~isnumeric(val) || val < 0 || val > 1)
                 error('crossoverProbability must be between 0 and 1');
             end
             obj.crossoverProbability = val;
         end
         
         function obj = set.strategy(obj,val)
             if (~isnumeric(val) || val < 1 || val > 6)
                 error('strategy must be 1 - 6')
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
                     otherwise
                         error('Unrecognised DE strategy');
                 end
                 disp(message);
             
             obj.strategy = val;
         end
         
         function obj = set.targetValue(obj,val)
             if (~isnumeric(val) || val < 1 )
                 error('Target value must be > 1')
             end 
         obj.targetValue = val;
         end
         
         function obj = set.numGenerations(obj,val)
             if (~isnumeric(val) || val < 1 )
                 error('numGenerations value must be > 1')
             end 
         obj.numGenerations = val;
         end
         
         

        %NS control methods
        function obj = set.Nlive(obj,val)
             if (~isnumeric(val) || val < 1)
                 error('Nlive must be a positive number');
             end
             obj.Nlive = val;
        end
        
        function obj = set.Nmcmc(obj,val)
            if (~isnumeric(val) || val < 0)
                error('Nmcmc must be 0 or positive integer')
            end
            obj.Nmcmc = val;
        end
        
        function obj = set.propScale(obj,val)
             if (~isnumeric(val) || val < 0 || val > 1)
                 error('propscale must be between 0 and 1');
             end
             obj.propScale = val;
        end
        
        function obj = set.nsTolerance(obj,val)
             if (~isnumeric(val) || val < 0 )
                 error('Stopping tolerance must be a positive number');
             end
             obj.nsTolerance = val;
        end
        
        % Bayes control methods. 
%         function obj = set.method(obj,val)
%              if ~strcmpi(val,{'DRAM','Delayed Rejection','Adaptive Metropolis','Metropolis Hastings'})
%                  error('Display must be set to ''DRAM'',''Delayed Rejection'',''Adaptive Metropolis'' or ''Metropolis Hastings'' ');
%              end
%              obj.method = val;
%         end
%              
%         function obj = set.nsimu(obj,val)
%              if (~isnumeric(val) || val < 0 )
%                  error('nsumu must be a positive number');
%              end
%              obj.nsimu = val;
%         end
%         
%         function obj = set.adaptint(obj,val)
%              if (~isnumeric(val) || val < 0 )
%                  error('adaptint must be a positive number');
%              end
%              obj.adaptint = val;
%         end
%             
%         function obj = set.burnin(obj,val)
%              if (~isnumeric(val) || val < 0 )
%                  error('burnin must be a positive number');
%              end
%              obj.burnin = val;
%         end
%         
%          
%         function obj = set.repeats(obj,val)
%              if (~isnumeric(val) || val < 1 )
%                  error('burnin must be a positive number > 1');
%              end
%              obj.repeats = val;
%         end

        % DREAM methods
        function obj = set.nSamples(obj,val)
             if (~isnumeric(val) || val < 0 )
                 error('nsumu must be a positive number');
             end
             obj.nSamples = val;
        end 

        function obj = set.nChains(obj,val)
             if ~(round(val) == val) || val <= 0 || isnan(val) || isinf(val)
                 error('nChains must be a positive integer > 0');
             end
             obj.nChains = val;
        end 

        function obj = set.lambda(obj,val)
             if (val < 0 || val > 1)
                 error('Jump probability lambda must be a fraction betweem 0 and 1');
             end
             obj.lambdA = val;
        end 

        function obj = set.p_unit_gamma(obj,val)
             if (val < 0 || val > 1)
                 error('P_unit_gamma must be a fraction betweem 0 and 1');
             end
             obj.p_unit_gamma = val;
        end 

        function obj = set.boundHandling(obj,val)
             if ~strcmpi(val{'none','reflect','bound','fold'})
                 error('Boundary handling must be ''none'', ''reflect'', ''bound'' or ''none''');
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
                'F_weight', {obj.F_weight},...
                'crossoverProbability', {obj.crossoverProbability},...
                'strategy', {obj.strategy},...
                'targetValue', {obj.targetValue},...
                'numGenerations', {obj.numGenerations},...
                'Nlive', {obj.Nlive},...
                'Nmcmc', {obj.Nmcmc'},...
                'propScale', {obj.propScale},...
                'nsTolerance', {obj.nsTolerance},...
                'resamPars', {obj.resamPars},...
                'nSamples', {obj.nSamples},...          
                'nChains', {obj.nChains},...
                'lambda', {obj.lambda},...
                'p_unit_gamma', {obj.p_unit_gamma},...
                'boundHandling', {obj.boundHandling});
 
            simplexCell = {'tolX',...
                'tolFun',...
                'maxFunEvals',...
                'maxIter'};
            
            DECell = {'populationSize',...
                'F_weight',...
                'crossoverProbability',...
                'strategy',...
                'targetValue',...
                'numGenerations'};

            NSCell = {'Nlive',...
                'Nmcmc',...
                'propScale',...
                'nsTolerance'}; 
            
%             BayesCell = {'method',...
%                 'nsimu',...
%                 'adaptint',...
%                 'burnin',...
%                 'repeats'};

            DreamCell = {'nSamples',...          
                'nChains',...
                'lambda',...
                'p_unit_gamma',...
                'boundHandling'};
            
            if isscalar(obj)
                if strcmpi(obj.procedure,'calculate')
                    dispPropList = rmfield(masterPropList,[DECell simplexCell NSCell DreamCell]);
                elseif strcmpi(obj.procedure,'simplex')
                    dispPropList = rmfield(masterPropList,[DECell NSCell DreamCell]);
                elseif strcmpi(obj.procedure,'DE')
                    dispPropList = rmfield(masterPropList,[simplexCell NSCell DreamCell]);
                elseif strcmpi(obj.procedure,'NS')
                    dispPropList = rmfield(masterPropList,[simplexCell DECell DreamCell]);
%                 elseif strcmpi(obj.procedure,'Bayes')
%                     dispPropList = rmfield(masterPropList,[simplexCell DECell NSCell DreamCell]);
                elseif strcmpi(obj.procedure,'dream')
                    dispPropList = rmfield(masterPropList,[DECell simplexCell NSCell]);

                end
                
                if ~isempty(dispPropList)
                    groups = matlab.mixin.util.PropertyGroup(dispPropList);
                else
                    groups = matlab.mixin.util.PropertyGroup(masterPropList);
                end
                
            else
                groups = getPropertyGroups@matlab.mixin.CustomDisplay(obj);
            end
            
        end
  
    end
end
