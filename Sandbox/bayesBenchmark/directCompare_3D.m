%Comparison of MCMC, NS and direct calculation.
clear

%Do the direct calculation first.
%Start by converting the R1 project to 
%the R2 case...
[d2oproblem,controls] = r1ToProblemDef('defaultProject.mat');
controls.calcSldDuringFit = 'yes';
controls.nsTolerance = 0.1;
controls.Nlive = 100;
[outProb,results] = RAT(d2oproblem,controls);
figure(1); clf
plotRefSLD(outProb, results);
thisChisq = results.calculationResults.sum_chi;
fprintf('Chi squared in %d \n',thisChisq);

% Run nested sampler
controls.procedure = 'NS';
[NSProb,NSResults] = RAT(d2oproblem,controls);


%Use a 30 x 30 grid.
%Make an array for the results...
gridSize = 30;
probArray = zeros(gridSize, gridSize, gridSize);

%Make a vector of roughness values..
minRough = outProb.paramConstr{1}(1);
maxRough = outProb.paramConstr{1}(2);
roughVector = linspace(minRough, maxRough, gridSize);

%Also background...
minBack = outProb.backgroundConstr{1}(1);
maxBack = outProb.backgroundConstr{1}(2);
backsVector = linspace(minBack, maxBack, gridSize);

%..and scalefactor
minScale = outProb.scalefactorConstr{1}(1);
maxScale = outProb.scalefactorConstr{1}(2);
scaleVector = linspace(minScale, maxScale, gridSize);


NSRes = NSResults.post_samples;
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


%Now for the calculation.
counter = 1;
totalGrid = gridSize^3;

% for r = 1:gridSize
%     for b = 1:gridSize
%         for s = 1:gridSize
%             thisRough = roughVector(r);
%             thisBack =  backsVector(b);
%             thisScale = scaleVector(s);
%             d2oproblem.params(1) = thisRough;
%             d2oproblem.backgrounds(1) = thisBack;
%             d2oProblem.scalefactors(1) = thisScale;
%             [outProblem,results] = RAT(d2oproblem,controls);
%             thisChi = results.calculationResults.sum_chi;
%             probArray(r,b,s) = exp(-thisChi/2);
%             percent = (counter/totalGrid)*100;
%             fprintf('Calculated %1.1f percent \n',percent);
%             counter = counter + 1;
%         end
%     end
% end

%setappdata(0,'probArray',probArray);
%save('probArray','probArray');
probArray = getappdata(0,'probArray');

% figure(2); clf
% contour(backsVector,roughVector,probArray,'k-');

%Marginalise the dirtributions...
roughDist = sum(probArray,[3 2]);
roughDist = [roughVector(:) roughDist(:)];
figure(3); subplot(1,3,1); hold on
plot(roughDist(:,1),roughDist(:,2),'linewidth',2);


backDist = sum(probArray,1);
backDist = sum(backDist,3);
%backDist = backDist ./ sum(backDist);
backDist = [backsVector(:) backDist(:)];
figure(3); subplot(1,3,2); hold on
plot(backDist(:,1), backDist(:,2),'linewidth',2);
% 
scaleDist = sum(probArray,2);
scaleDist = squeeze(scaleDist);
%figure(2); clf; contour(backsVector, scaleVector, scaleDist)
scaleDist = sum(scaleDist,2);
scaleDist = [scaleVector(:) scaleDist(:)];
figure(3); subplot(1,3,3); hold on
plot(scaleDist(:,1), scaleDist(:,2),'linewidth',2);
% % scaleDist = [scaleVector(:) scaleDist(:)];




