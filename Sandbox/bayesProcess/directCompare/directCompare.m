%Comparison of MCMC, NS and direct calculation.

%Do the direct calculation first.
%Start by converting the R1 project to 
%the R2 case...
[d2oproblem,controls] = r1ToProblemDef('defaultProject_D2O_bayesCompare_3D.mat');
[outProb,results] = RAT(d2oproblem,controls);
figure(1); clf
plotRefSLD(outProb, results);
thisChisq = results.calculationResults.sum_chi;
fprintf('Chi squared in %d \n',thisChisq);


%Start with a 2D calculation. Use a 30 x 30 grid.
%Make an array for the results...
gridSize = 30;
probArray = zeros(gridSize);

%Make a vector of roughness values..
minRough = 0; %outProb.paramConstr{1}(1);
maxRough = 8; %outProb.paramConstr{1}(2);
roughVector = linspace(minRough, maxRough, gridSize);

%Also background...
minBack = 1e-7; %outProb.backgroundConstr{1}(1);
maxBack = 1e-5; %outProb.backgroundConstr{1}(2);
backsVector = linspace(minBack, maxBack, gridSize);


%Now for the calculation.
counter = 1;
totalGrid = gridSize^2;

for r = 1:gridSize
    for b = 1:gridSize
        thisBack =  backsVector(b);
        thisRough = roughVector(r);
        d2oproblem.params(1) = thisRough;
        d2oproblem.backgrounds(1) = thisBack;
        [outProblem,results] = RAT(d2oproblem,controls);
        thisChi = results.calculationResults.sum_chi;
        probArray(r,b) = exp(-thisChi/2);
        percent = (counter/totalGrid)*100;
        fprintf('Calculated %1.1f percent \n',percent);
        counter = counter + 1;
    end
end

figure(2); clf
contour(backsVector,roughVector,probArray,'k-');

%Marginalise the dirtributions...
roughDist = sum(probArray,2);
roughDist = [roughVector(:) roughDist(:)];
figure(3); subplot(1,2,1)
plot(roughDist(:,1),roughDist(:,2));

backDist = sum(probArray,1);
backDist = [backsVector(:) backDist(:)];
figure(3); subplot(1,2,2);
plot(backDist(:,1), backDist(:,2));


