classdef pmLogFunction

    properties 
        
        problemStruct;
        problemCells;
        problemLimits;
        priors;
        controls;
        scaled;
        NDIM;

    end
    
    methods 
        
        function logFuncVal = get(obj,pars)
            
            problem = obj.problemStruct;            
            problem.fitParams = pars;
            
            if obj.scaled
                problem = unscalePars(problem);
            end

            problem = unpackParams(problem,obj.controls);
            
            [outProblem,~] = reflectivityCalculation_mex(problem,obj.problemCells,obj.controls);
            chi = outProblem.calculations.sumChi;
            logFuncVal = -chi/2;
            
            % Check to catch any strange NaNs
            if isnan(logFuncVal) || isinf(logFuncVal)
                disp('Strange output value here');
            end
            
            % Now apply the priors where necessary. 
            priorfun = @(th,mu,sig) sum(((th-mu)./sig).^2);

            val = priorfun(problem.fitParams,obj.priors(:,1),obj.priors(:,2));

            logFuncVal = logFuncVal + val;           

        end   
    end
end
