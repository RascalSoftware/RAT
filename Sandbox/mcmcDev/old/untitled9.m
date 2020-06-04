clear

problem = load('defaultProject.mat');
problem = problem.problem;
thisData = problem.data{1};
data.xdata = thisData(:,1);
data.ydata = thisData(:,2);
data.sigma = thisData(:,3);

modelfun = @(x,theta)calculationFun(x,theta);
ssfun = @(theta,data) sum((data.ydata - modelfun(data.xdata,theta)).^2);

gridSize = 30;
probArray = zeros(gridSize);

%Make a vector of roughness values..
minRough = 1; 
maxRough = 10;
roughVector = linspace(minRough, maxRough, gridSize);

%Also scalefactor...
minScale = 0.07; 
maxScale = 0.11; 
scaleVector = linspace(minScale, maxScale, gridSize);

%Now for the calculation.....
%Now for the calculation.
counter = 1;
totalGrid = gridSize^2;

for r = 1:gridSize
    for s = 1:gridSize
        thisScale =  scaleVector(s);
        thisRough = roughVector(r);
        theta(1) = thisRough;
        theta(2) = thisScale;
        ref = modelfun(data.xdata,theta);
        thisChi = [];
        for i = 1:length(data.xdata)
            thisChi(i) = ((data.ydata(i)-ref(i))./data.sigma(i))^2;
        end
        %red_ss = ((ref-data.ydata)./data.sigma).^2;
        chisq = sum(thisChi);
        probArray(r,s) = exp(-chisq/2);
        percent = (counter/totalGrid)*100;
        fprintf('Calculated %1.1f percent \n',percent);
        counter = counter + 1;
    end
end
%Plot the array....
clf
contour(roughVector,scaleVector,probArray,'k-');