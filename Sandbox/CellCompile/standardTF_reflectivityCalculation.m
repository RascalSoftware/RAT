function [problem,result] = standardTF_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls)

%Decide what kind of calculation it is and call the appropriate one
type = controls.tfType;
numberOfContrasts = problemDef.numberOfContrasts;
preAlloc = zeros(numberOfContrasts,1);

result = cell(6,1);

problem = struct('ssubs',preAlloc,...
                 'backgrounds',preAlloc,...
                 'qshifts',preAlloc,...
                 'scalefactors',preAlloc,...
                 'nbairs',preAlloc,...
                 'nbsubs',preAlloc,...
                 'resolutions',preAlloc,...
                 'calculations',struct('all_chis',preAlloc,'sum_chi',0),...
                 'allSubRough',preAlloc);

                 
coder.varsize('problem.backgrounds',[Inf,1],[1 0]); 
coder.varsize('problem.qshifts',[Inf,1],[1 0]); 
coder.varsize('problem.scalefactors',[Inf,1],[1 0]);   
coder.varsize('problem.nbairs',[Inf,1],[1 0]);   
coder.varsize('problem.nbsubs',[Inf,1],[1 0]);   
coder.varsize('problem.resolutions',[Inf,1],[1 0]);   
coder.varsize('problem.allSubRough',[Inf,1],[1 0]);  
                 
switch type
    case 'stanLay'
        [problem,result] = standardTF_stanLay_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);
    case 'custLay'
        %problem = standardTF_custLay_reflectivityCalculation(problemDef,problemDef_cells,controls);
    case 'custXY'
        %problem = standardTF_custXY_reflectivityCalculation(problemDef,problemDef_cells,controls);
end

end