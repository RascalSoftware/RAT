classdef pmLogFunction

    properties 
        
        problemDef;
        problemDefCells;
        problemDefLimits;
        priors;
        controls;
        scaled;
        NDIM;

    end
    
    methods 
        
        function logFuncVal = get(obj,pars)
            
            problem = obj.problemDef;            
            problem.fitpars = pars;
            
            if obj.scaled
                problem = unscalePars(problem);
            end

            problem = unpackparams(problem,obj.controls);
            
            [outProblem,~] = reflectivityCalculation_mex(problem,obj.problemDefCells,obj.controls);
            chi = outProblem.calculations.sum_chi;
            logFuncVal = -chi/2;
            
            % Check to catch any strange NaNs
            if isnan(logFuncVal) || isinf(logFuncVal)
                disp('Strange output value here');
            end
            
            % Now apply the priors where necessary. 
            priorfun = @(th,mu,sig) sum(((th-mu)./sig).^2);

            val = priorfun(problem.fitpars,obj.priors(:,1),obj.priors(:,2));

            logFuncVal = logFuncVal + val;           

        end   
    end
end
