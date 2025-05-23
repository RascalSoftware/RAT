% This example compares three Bayesian posteriors for a low-dimensional
% example: a posterior generated by DREAM, one generated by NS, and
% one calculated directly.
% 
% In this 3D case, we calculate the posterior for a fit over substrate
% roughness, a background parameter, and a scalefactor.
%
% The likelihood of the parameters being equal to a certain value is proportional
% to exp(-chi^2 / 2) [1], so for a low-dimensional example we can calculate this directly
% for a sample of parameter values.
% 
% Citation:
% [1] D. S. Sivia, J. R. P. Webster,
%     "The Bayesian approach to reflectivity data",
%     Physica B: Condensed Matter,
%     Volume 248, June 1998, pages 327-337
%     DOI: 10.1016/S0921-4526(98)00259-2
%     URL: https://bayes.wustl.edu/sivia/98_20feb03.pdf
clear

%Do the direct calculation first.
%Our project is a bare D2O substrate: this is the default RasCAL-1 project.
root = getappdata(0, 'root');
d2oproblem = r1ToProjectClass(fullfile(root, 'utilities', 'misc', 'defaultR1ProjectTemplate.mat'));

controls = controlsClass();
controls.calcSldDuringFit = true;
controls.nsTolerance = 1;
controls.nLive = 500;

%We create a 30x30x30 array to hold our results for all samples.
gridSize = 30;
probArray = zeros(gridSize, gridSize, gridSize);

%Make a vector of roughness values..
paramsTable = d2oproblem.parameters.varTable;
minRough = paramsTable{1,2};
maxRough = paramsTable{1,4};
roughVector = linspace(minRough, maxRough, gridSize);

%Also background...
backParsTable = d2oproblem.background.backgroundParams.varTable;
minBack = backParsTable{1,2};
maxBack = backParsTable{1,4};
backsVector = linspace(minBack, maxBack, gridSize);

%and scalefactor:
scaleFacTable = d2oproblem.scalefactors.varTable;
minScale = scaleFacTable{1, 2};
maxScale = scaleFacTable{1, 4};
scaleVector = linspace(minScale, maxScale, gridSize);

%Now for the calculation. We calculate likelihood for every point on a
%30x30x30 grid.
counter = 1;
totalGrid = gridSize^3;
controls.procedure = 'calculate';
controls.display = 'off';

for r = 1:gridSize
    for b = 1:gridSize
        for s = 1:gridSize
            thisRough = roughVector(r);
            thisBack = backsVector(b);
            thisScale = scaleVector(s);

            d2oproblem.setParameter(1,'value',thisRough);
            d2oproblem.setBackgroundParam(1,'value',thisBack);
            d2oproblem.setScalefactor(1,'value',thisScale);

            [outProblem,results] = RAT(d2oproblem,controls);
            thisChi = results.calculationResults.sumChi;
            probArray(r,b,s) = exp(-thisChi/2);
            percent = (counter/totalGrid)*100;
            fprintf('Calculated %1.1f percent \n',percent);
            counter = counter + 1;
        end
    end
end

% now we calculate for NS:
controls.procedure = 'ns';
[~,NSResults] = RAT(d2oproblem,controls);

% and create histograms for the posteriors:
NSRes = NSResults.chain;
figure(3); clf; hold on
roughs = NSRes(:,1);
[n,x] = hist(roughs,20,'Normalization','probability');
subplot(1,3,1); hold on
bar(x,n,'w');

backs = NSRes(:,2);
[n,x] = hist(backs,20,'Normalization','probability');
subplot(1,3,2); hold on;
bar(x,n,'w');

scales = NSRes(:,3);
[n,x] = hist(scales,20,'Normalization','probability');
subplot(1,3,3); hold on;
bar(x,n,'w');

% and for DREAM:
controls.procedure = 'dream';
[~,DResults] = RAT(d2oproblem,controls);

DRes = DResults.chain;
figure(3); clf; hold on
roughs = DRes(:,1);
[n,x] = hist(roughs,20,'Normalization','probability');
subplot(1,3,1); hold on
bar(x,n,'w');

backs = DRes(:,2);
[n,x] = hist(backs,20,'Normalization','probability');
subplot(1,3,2); hold on;
bar(x,n,'w');

scales = DRes(:,3);
[n,x] = hist(scales,20,'Normalization','probability');
subplot(1,3,3); hold on;
bar(x,n,'w');

% Marginalise the distributions for the direct calculation and plot:
roughDist = sum(probArray,[2 3]);
roughDist = roughDist ./ sum(roughDist);
roughDist = [roughVector(:) roughDist(:)];
figure(3); subplot(1,3,1); hold on
plot(roughDist(:,1),roughDist(:,2),'linewidth',2);

backDist = sum(probArray,[1 3]);
backDist = backDist ./ sum(backDist);
backDist = [backsVector(:) backDist(:)];
figure(3); subplot(1,3,2); hold on
plot(backDist(:,1),backDist(:,2),'linewidth',2);

scaleDist = sum(probArray,[1 2]);
scaleDist = scaleDist ./ sum(scaleDist);
scaleDist = [scaleVector(:) scaleDist(:)];
figure(3); subplot(1,3,3); hold on
plot(scaleDist(:,1),scaleDist(:,2),'linewidth',2);

