classdef orsoLogFunc

    properties 
        
        problemDef;
        problemDef_cells;
        problemDef_limits;
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
            
            [problem,~] = reflectivity_calculation_wrapper(problem,cells,limits,control);
            chi = problem.calculations.sum_chi;
            logFuncVal = -chi/2;
            
        end   
    end
end
    
