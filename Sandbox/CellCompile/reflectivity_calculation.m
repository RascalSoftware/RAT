function [problem,result] = reflectivity_calculation(problemDef,problemDef_cells,problemDef_limits,controls)

global RAT_DEBUG DEBUGVARS

%Preallocatin of outputs
problem.ssubs = 0;
problem.backgrounds = 0;
problem.qshifts = 0;
problem.scalefactors = 0;
problem.nbairs = 0;
problem.nbsubs = 0;
problem.resolutions = 0;
problem.calculations.all_chis = 0;
problem.calculations.sum_chi = 0;
problem.allSubRough = 0;

 result = cell(1,6);
% %Result coder definitions....
%  coder.varsize('result{1}',[Inf 1],[1 0]);           %Reflectivity
%  coder.varsize('result{1}{:}',[Inf 2],[1 0]);        
% % 
%  coder.varsize('result{2}',[Inf 1],[1 0]);           %Simulatin
%  coder.varsize('result{2}{:}',[Inf 2],[1 0]);
% % 
%  coder.varsize('result{3}',[Inf 1],[1 0]);           %Shifted data
%  coder.varsize('result{3}{:}',[Inf 3],[1 0]);
% % 
%  coder.varsize('result{4}',[Inf 1],[1 0]);           %Layers slds
%  coder.varsize('result{4}{:}',[Inf 3],[1 0]);
% % 
%  coder.varsize('result{5}',[Inf 1],[1 0]);           %Sld profiles
%  coder.varsize('results{5}{:}',[Inf 2],[1 0]);
% % 
%  coder.varsize('result{6}',[Inf 1],[1 0]);           %All layers 
%  coder.varsize('result{6}{:}',[Inf 1],[1 0]);



%Decide which target function we are calling
whichTF = controls.TF;
switch whichTF
    case 'standardTF'
        [problem,result] = standardTF_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);
    case 'oilWaterTF'
        %problem = oilWaterTF_reflectivityCalculation(problemDef,problemDef_cells,controls);    
    case 'polarisedTF'
        %problem = polarisedTF_reflectivityCalculation(problemDef,problemDef_cells,controls);
    case 'domainsTF'
        %problem = domainsTF_reflectivityCalculation(problemDef,problemDef_cells,controls);
end




coder.varsize('problem.ssubs',[Inf 1],[1 0]);
coder.varsize('problem.backgrounds',[Inf 1],[1 0]);
coder.varsize('problem.qshifts',[Inf 1],[1 0]);
coder.varsize('problem.scalefactors',[Inf 1],[1 0]);
coder.varsize('problem.nbairs',[Inf 1],[1 0]);
coder.varsize('problem.nbsubs',[Inf 1],[1 0]);
coder.varsize('problem.resolutions',[Inf 1],[1 0]);
coder.varsize('problem.ssubs',[Inf 1],[1 0]);
coder.varsize('problem.calculations.all_chis',[Inf 1],[1 0]);
coder.varsize('problem.calculations.sum_chi',[1 1],[0 0]);
coder.varsize('problem.allSubRough',[Inf 1],[1 0]);


if coder.target('MATLAB')
    if RAT_DEBUG
        DEBUGVARS.reflectivity_calculation.problem = problem;
        DEBUGVARS.reflectivity_calculation.result = result;
    end
end
end