%Comparison of MCMC, NS and direct calculation.
clear 
%Do the direct calculation first.
%Start by converting the R1 project to 
%the R2 case...
[d2oproblem,controls] = r1ToProblemDef('defaultProject_D2O_bayesCompare_3D.mat');
[outProb,results] = RAT(d2oproblem,controls);
figure(1); clf
plotRefSLD(outProb, results);
thisChisq = results.calculationResults.sum_chi;
fprintf('Chi squared in %d \n',thisChisq);


%Use a 30 x 30 grid.
%Make an array for the results...
gridSize = 30;
probArray = zeros(gridSize);

%Make a vector of roughness values..
minRough = 0; %outProb.paramConstr{1}(1);
maxRough = 8; %outProb.paramConstr{1}(2);
roughVector = linspace(minRough, maxRough, gridSize);

%Also background...
minScale = 0.08; %outProb.backgroundConstr{1}(1);
maxScale = 0.11; %outProb.backgroundConstr{1}(2);
scaleVector = linspace(minScale, maxScale, gridSize);


%Now for the calculation.
counter = 1;
totalGrid = gridSize^2;

for r = 1:gridSize
    for s = 1:gridSize
        thisScale =  scaleVector(s);
        thisRough = roughVector(r);
        d2oproblem.params(1) = thisRough;
        d2oproblem.scalefactors(1) = thisScale;
        [outProblem,results] = RAT(d2oproblem,controls);
        thisChi = results.calculationResults.sum_chi;
        probArray(s,r) = exp(-thisChi/2);
        percent = (counter/totalGrid)*100;
        fprintf('Calculated %1.1f percent \n',percent);
        counter = counter + 1;
    end
end

figure(20); clf
contour(scaleVector,roughVector,probArray,'k-');

%Marginalise the dirtributions...
roughDist = sum(probArray,1);
roughDist = [roughVector(:) roughDist(:)];
figure(21); subplot(1,2,1)
plot(roughDist(:,1),roughDist(:,2));

scaleDist = sum(probArray,2);
scaleDist = [scaleVector(:) scaleDist(:)];
figure(21); subplot(1,2,2);
plot(scaleDist(:,1), scaleDist(:,2));


