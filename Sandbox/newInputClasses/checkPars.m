

oldInputs = load('callVars_oldStyle.mat');
newInputs = load('callVars_newInputs.mat');

callVars_old = oldInputs.callVars;
callVars_new = newInputs.callVars_newInputs;

clc

n = 6
callVars_old.problemDef
callVars_new.problemDef

callVars_old.problemDef_cells{n}{1}
callVars_new.problemDef_cells{n}{1}

problemDef = callVars_new.problemDef;
problemDef_cells = callVars_new.problemDef_cells;
problemDef_limits = callVars_new.problemDef_limits;
controls = callVars_new.controls;

problemDef.geometry = 'air/substrate';


[outProblemStruct,problem,result] = RAT_main(problemDef,problemDef_cells,problemDef_limits,controls);

result = parseResultToStruct(outProblemStruct,problem,result);

n = 2;
figure(1); clf
ref = result.reflectivity{n};
dat = result.shifted_data{n};
subplot(1,2,1);
errorbar(dat(:,1),dat(:,2),dat(:,3),'.');
set(gca,'YScale','log','XScale','log');
hold on
plot(ref(:,1),ref(:,2))

subplot(1,2,2)
sld = result.sldProfiles{n};
plot(sld(:,1),sld(:,2))


