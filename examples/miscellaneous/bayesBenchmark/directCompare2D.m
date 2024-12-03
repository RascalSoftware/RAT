%Comparison of MCMC, NS and direct calculation.
clear

%Do the direct calculation first.
%Start by converting the R1 project to 
%the R2 case...
root = getappdata(0, 'root');
d2oproblem = r1ToProjectClass(fullfile(root, 'utilities', 'misc', 'defaultR1ProjectTemplate.mat'));

controls = controlsClass();
controls.calcSldDuringFit = true;
controls.nsTolerance = 1;
controls.nLive = 500;
d2oProblem.fitScalefactor = 0;


% Run nested sampler
controls.procedure = 'ns';
[NSProb,NSResults] = RAT(d2oproblem,controls);


%Use a 30 x 30 grid.
%Make an array for the results...
gridSize = 30;
probArray = zeros(gridSize, gridSize);

%Make a vector of roughness values..
paramsTable = NSProb.parameters.varTable;
minRough = paramsTable{1,2};
maxRough = paramsTable{1,4};
roughVector = linspace(minRough, maxRough, gridSize);

%Also background...
backParsTable = NSProb.background.backgroundParams.varTable;
minBack = backParsTable{1,2};
maxBack = backParsTable{1,4};
backsVector = linspace(minBack, maxBack, gridSize);

% %..and scalefactor
% scalefactorTable = NSProb.scalefactors.varTable;
% minScale = scalefactorTable{1,2};
% maxScale = scalefactorTable{1,4};
% scaleVector = linspace(minScale, maxScale, gridSize);


NSRes = NSResults.chain;%NSResults.post_samples;
figure(3); clf; hold on
roughs = NSRes(:,1);
[n,x] = hist(roughs,20,'Normalization','probability');
subplot(1,2,1); hold on
bar(x,n,'w');

backs = NSRes(:,2);
[n,x] = hist(backs,20,'Normalization','probability');
subplot(1,2,2); hold on;
bar(x,n,'w');


%Now for the calculation.
counter = 1;
totalGrid = gridSize^2;
controls.procedure = 'calculate';
controls.display = 'off';

for r = 1:gridSize
    for b = 1:gridSize
        thisRough = roughVector(r);
        thisBack =  backsVector(b);
        
        NSProb.setParameter(1,'value',thisRough);
        NSProb.setBackgroundParam(1,'value',thisBack);
        
        [outProblem,results] = RAT(d2oproblem,controls);
        thisChi = results.calculationResults.sumChi;
        probArray(r,b) = exp(-thisChi/2);
        percent = (counter/totalGrid)*100;
        fprintf('Calculated %1.1f percent \n',percent);
        counter = counter + 1;
    end
end


%setappdata(0,'probArray',probArray);
%save('probArray','probArray');
%probArray = getappdata(0,'probArray');

figure(2); clf
contour(backsVector,roughVector,probArray,'k-');
hold on

NSdist = NSResults.chain;
rough = NSdist(:,1);
back = NSdist(:,2);
plot(back,rough,'.');

% %Marginalise the dirtributions...
roughDist = sum(probArray,[3 2]);
roughDist = [roughVector(:) roughDist(:)];
figure(3); subplot(1,3,1); hold on
plot(roughDist(:,1),roughDist(:,2),'linewidth',2);


backDist = sum(probArray,1);
backDist = sum(backDist,3);
%backDist = backDist ./ sum(backDist);
backDist = [backsVector(:) backDist(:)];
figure(3); subplot(1,2,2); hold on
plot(backDist(:,1), backDist(:,2),'linewidth',2);
% 
scaleDist = sum(probArray,2);
scaleDist = squeeze(scaleDist);
%figure(2); clf; contour(backsVector, scaleVector, scaleDist)
scaleDist = sum(scaleDist,2);
% scaleDist = [scaleVector(:) scaleDist(:)];
% figure(3); subplot(1,2,3); hold on
% plot(scaleDist(:,1), scaleDist(:,2),'linewidth',2);
% % scaleDist = [scaleVector(:) scaleDist(:)];
% 
% 
% 
% 
