function directCompare3D(mcmcChains)

useSaved = true;

% Convert R1 project to R2....
d2oproblem = r1ToProjectClass('defaultProject.mat');

d2oproblem.setScalefactor(1,'min',0.07);
d2oproblem.setScalefactor(1,'max',0.13);

controls = controlsDef();
controls.calcSldDuringFit = 'yes';
[outProb,results] = RAT(d2oproblem,controls);
thisChisq = results.calculationResults.sum_chi;
fprintf('Chi squared in %d \n',thisChisq);

% % Run MCMC
% controls.procedure = 'bayes';
% controls.nsimu = 50000;
% controls.repeats = 3;
% [bayesProb,bayesResults] = RAT(d2oproblem,controls);

% Load in the MCMC results
% mcmcChains = load('mcmcChains.mat');
% bayesRes = mcmcChains.allChains;
bayesRes = mcmcChains;

%Use a 30 x 30 grid.
%Make an array for the results...
gridSize = 40;
probArray = zeros(gridSize, gridSize, gridSize);

[fitPars,fitNames,fitConstr] = getFitValues(d2oproblem,controls);

%Make a vector of roughness values..
minRough = 1; %fitConstr(1,1);
maxRough = fitConstr(1,2);
roughVector = linspace(minRough, maxRough, gridSize);

%Also background...
minBack = fitConstr(2,1);
maxBack = fitConstr(2,2);
backsVector = linspace(minBack, maxBack, gridSize);

%..and scalefactor
minScale = fitConstr(3,1);
maxScale = fitConstr(3,2);
scaleVector = linspace(minScale, maxScale, gridSize);

%bayesRes = bayesResults.chain;

figure(3); clf; hold on
roughs = bayesRes(:,1);
subplot(1,3,1); hold on
[n,x] = histcounts(roughs,70);
x = (x(1:end-1) + x(2:end))/2;
n = n ./ max(n); % * (x(2)-x(1)));
bar(x,n,'w','BarWidth',1);

%,'Normalization','countdensity');

backs = bayesRes(:,2);
subplot(1,3,2); hold on;
[n,x] = histcounts(backs,70);
x = (x(1:end-1) + x(2:end))/2;
n = n ./ max(n);% * (x(2)-x(1)));
bar(x,n,'w','BarWidth',1);

scales = bayesRes(:,3);
subplot(1,3,3); hold on;
[n,x] = histcounts(scales,70);
x = (x(1:end-1) + x(2:end))/2;
n = n ./ max(n);% * (x(2)-x(1)));
bar(x,n,'w','BarWidth',1);


%Now for the calculation.
counter = 1;
totalGrid = gridSize^3;

% Probaby better to do a lowe level call directly to
% reflectivity_calculation here...
controls.display = 'off';
controls.procedure = 'calculate';

%%
if useSaved
    probArray = load('probArray.mat');
    probArray = probArray.probArray;
else

    [problemDef,problemDef_cells,problemDef_limits,priors,controls] = parseClassToStructs(d2oproblem,controls);
    [problemDef,fitNames] = packparams(problemDef,problemDef_cells,problemDef_limits,controls.checks);

    for r = 1:gridSize
        for b = 1:gridSize
            for s = 1:gridSize
                thisRough = roughVector(r);
                thisBack =  backsVector(b);
                thisScale = scaleVector(s);

                %d2oproblem.params(1) = thisRough;
                %d2oproblem.backgrounds(1) = thisBack;
                %d2oProblem.scalefactors(1) = thisScale;

                problemDef.fitpars(1) = thisRough;
                problemDef.fitpars(2) = thisBack;
                problemDef.fitpars(3) = thisScale;
                problemDef = unpackparams(problemDef,controls);
                [problem,results] = reflectivityCalculationWrapper(problemDef,problemDef_cells,problemDef_limits,controls);

%                 d2oproblem.setParameter(1,'value',thisRough);
%                 d2oproblem.setBacksPar(1,'value',thisBack);
%                 d2oproblem.setScalefactor(1,'value',thisScale);
% 
%                 [outProblem,results] = RAT(d2oproblem,controls);

                thisChi = problem.calculations.sum_chi;
                probArray(r,b,s) = exp(-thisChi/2);
                percent = (counter/totalGrid)*100;
                fprintf('Calculated %1.1f percent \n',percent);
                counter = counter + 1;
            end
        end
    end
end

setappdata(0,'probArray',probArray);
save('probArray','probArray');
%probArray = getappdata(0,'probArray');

% figure(2); clf
% contour(backsVector,roughVector,probArray,'k-');

%%
%Marginalise the dirtributions...
roughDist = sum(probArray,[2 3]);
roughDist = roughDist ./ max(roughDist);
roughDist = [roughVector(:) roughDist(:)];
figure(3); subplot(1,3,1); hold on
plot(roughDist(:,1),roughDist(:,2),'linewidth',2);

backDist = sum(probArray,[1 3]);
backDist = backDist ./ max(backDist);
backDist = [backsVector(:) backDist(:)];
figure(3); subplot(1,3,2); hold on
plot(backDist(:,1),backDist(:,2),'linewidth',2);

scaleDist = sum(probArray,[1 2]);
scaleDist = scaleDist ./ max(scaleDist);
scaleDist = [scaleVector(:) scaleDist(:)];
figure(3); subplot(1,3,3); hold on
plot(scaleDist(:,1),scaleDist(:,2),'linewidth',2);

% roughDist = sum(probArray,3);
% roughDist = squeeze(roughDist);
% roughDist = sum(roughDist,2);
% dx = diff(roughVector(1:2));
% roughDist = roughDist ./ sum(roughDist) * dx;
% roughDist = [roughVector(:) roughDist(:)];
% figure(3); subplot(1,3,1); hold on
% plot(roughDist(:,1),roughDist(:,2),'linewidth',2);
% 
% 
% backDist = sum(probArray,1);
% backDist = squeeze(backDist);
% backDist = sum(backDist,2);
% dx = diff(backsVector(1:2));
% backDist = backDist ./ sum(backDist) * dx;
% backDist = [backsVector(:) backDist(:)];
% figure(3); subplot(1,3,2); hold on
% plot(backDist(:,1), backDist(:,2),'linewidth',2);
% % 
% scaleDist = sum(probArray,1);
% scaleDist = squeeze(scaleDist);
% %figure(2); clf; contour(backsVector, scaleVector, scaleDist)
% scaleDist = sum(scaleDist,1);
% dx = diff(scaleVector(1:2));
% scaleDist = scaleDist ./ sum(scaleDist) * dx;
% scaleDist = [scaleVector(:) scaleDist(:)];
% figure(3); subplot(1,3,3); hold on
% plot(scaleDist(:,1), scaleDist(:,2),'linewidth',2);
% % scaleDist = [scaleVector(:) scaleDist(:)];


end


function [fitPars,fitNames,fitConstr] = getFitValues(inputProblem,controls)

[problemDef,problemDef_cells,problemDef_limits,priors,controls] = parseClassToStructs(inputProblem,controls);

[problemDef,fitNames] = packparams(problemDef,problemDef_cells,problemDef_limits,controls.checks);

fitPars = problemDef.fitpars;
fitConstr = problemDef.fitconstr;


end


