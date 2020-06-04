function refCalc_spTest()
global RAT_DEBUG DEBUGVARS

RAT_DEBUG = 0;
DEBUGVARS = 0;


%callParams = load('callParams.mat');

callParams = load('newInputs_AL.mat');
callParams = callParams.newInputs;

problemDef = callParams.problemDef;
problemDef_cells = callParams.problemDef_cells;
problemDef_limits = callParams.problemDef_limits;
controls = callParams.controls;

N = 3;
tot = 200;

controls.Para = 'multi';
for contrasts = 1:7
    [newProblemDef,newProblemDef_cells] = reduceNContrasts(problemDef,problemDef_cells,N);
    tic
    for l = 1:tot
        [problem,result] = reflectivity_calculation(newProblemDef,newProblemDef_cells,problemDef_limits,controls);
    end
    sTime(contrasts) = toc;
end

controls.Para = 'multi';
for contrasts = 1:7
    [newProblemDef,newProblemDef_cells] = reduceNContrasts(problemDef,problemDef_cells,N);
    tic
    for l = 1:tot
        [problem,result] = reflectivity_calculation(newProblemDef,newProblemDef_cells,problemDef_limits,controls);
    end
    mTime(contrasts) = toc;
end

figure(1); clf; hold on
x = 1:7;
plot(x,sTime,'bo');
plot(x,mTime,'ro');

disp('debug');

end




function [problemDef,problemDef_cells] = reduceNContrasts(problemDef,problemDef_cells,contrasts);

problemDef.numberOfContrasts = contrasts;

problemDef.resample = problemDef.resample(1:contrasts);
problemDef.dataPresent = problemDef.dataPresent(1:contrasts);
problemDef.contrastBacks = problemDef.contrastBacks(1:contrasts);
problemDef.contrastShifts = problemDef.contrastShifts(1:contrasts);
problemDef.contrastScales = problemDef.contrastScales(1:contrasts);
problemDef.contrastNbas = problemDef.contrastNbas(1:contrasts);
problemDef.contrastNbss = problemDef.contrastNbss(1:contrasts);
problemDef.contrastRes = problemDef.contrastRes(1:contrasts);

for n = 1:5
    a = problemDef_cells{n};
    a = a(1:contrasts);
    problemDef_cells{n} = a;
end



end