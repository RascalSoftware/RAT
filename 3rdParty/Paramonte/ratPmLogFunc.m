classdef ratPmLogFunc

    properties 
        
        problemDef;
        problemDef_cells;
        problemDef_limits;
        priors;
        controls;
        scaled;
        NDIM;

    end
    
    methods 
        
        function logFuncVal = get(obj,pars)
            
            problem = obj.problemDef;
            control = obj.controls;
            cells = obj.problemDef_cells;
            limits = obj.problemDef_limits;
            priors = obj.priors;
            
            problem.fitpars = pars;
            
            if obj.scaled 
                problem = unscalePars(problem);
            end

            problem = unpackparams(problem,control);
            
            [outProblem,results] = reflectivity_calculation_wrapper(problem,cells,limits,control);
            chi = outProblem.calculations.sum_chi;
            logFuncVal = -chi/2;
            
            % Check to catch any strange NaNs
            if isnan(logFuncVal) || isinf(logFuncVal)
                disp('Strange output value here');
            end
            
            % Now apply the priors where necessary. 
            priorfun = @(th,mu,sig) sum(((th-mu)./sig).^2);

            val = priorfun(problem.fitpars,priors(:,1),priors(:,2));

            %logFuncVal = logFuncVal;% * val;

            %end
            

        end   
    end
end
    
