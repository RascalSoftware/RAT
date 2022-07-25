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
            
            % Now apply the priors where necessary. Try multiplying by the
            % prior for each parameter
            for i = 1:obj.NDIM
                
                
            end
            

        end   
    end
end
    
