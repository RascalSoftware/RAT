function R1postProcess()

addpath('r1Codes');

R1results = load('R1_bayes_results.mat');
R1results = R1results.R1results;

results = R1results.results;
chain = R1results.chain;
problem = R1results.problem;
bestPars = R1results.bestPars;

setappdata(0,'problem',problem);




% %Diagnostics plot
% diagnosticsPlot(chain,results,bayesHandles.hDiag)
% 
% %Histogram Plot
% ret = makeHistsWindow(names,chain,length(names),bayesHandles.hHists);
% 
% %Parameters plot
% parsPlot(chain,results,names,bayesHandles.hVals);

% %Correlations plot
% corrPlot(chain,results,names,bayesHandles.hCorr);

%SLD and Reflectivity plots....
[refBounds,sldBounds,bestRefs,bestSlds,bestChi] = shading(chain,results,problem,bestPars,0.4);


end

function [refBounds,sldBounds,bestRef,bestSLD,bestChi] = shading(chain,results,problem,bestPars,factor)

res = [];
refMat = [];
sldMat = [];
sldPoints = [];
chi = [];
dispFreq = 200;
oldProblem = problem;
numberOfFits = size(chain,1);
confInt = 0.95;

loopNum = factor*numberOfFits;



%Pre-allocation
allData = problem.shifted_data;
allCurves = problem.calculations.slds;
for j = 1:length(allCurves)
    thesePoints(j) = length(allCurves{j});
end
sldPoints = max(thesePoints);

for i = 1:length(allData);
    thisData = allData{i};
    thisMem = zeros(loopNum,length(thisData));
    thisMem2 = zeros(loopNum,sldPoints);
    refMat{i} = thisMem;
    sldMat{i} = thisMem2;
end

figure(1); clf;

try
%sldPoints = 0;
for i = 1:loopNum
    if factor < 1
        try
            thisID = round(rand*numberOfFits);
            thesePars = chain(thisID,:);
        catch
            thesePars = chain(i,:);
        end
    else
        thesePars = chain(i,:);
    end
    
    problem.fitpars = thesePars;
    problem = r1_unpackparams(problem);
    setappdata(0,'problem',problem);
    r1_reflectivity_calculation;
    problem = getappdata(0,'problem');
    SLD{i} = problem.calculations.slds;
    REF{i} = problem.calculations.Simulation;
    chi(i) = problem.calculations.sum_chi;
%     if sldPoints == 0;
%        allCurves = SLD{:};
%        for j = 1:length(allCurves)
%            thesePoints(j) = length(allCurves{j});
%        end
%        sldPoints = max(thesePoints);
%     end
    
    for n = 1:size(problem.calculations.Simulation,2)
        if i == 1;
            l(n) = length(problem.shifted_data{n}(:,1));
        end
        thisRef = problem.calculations.Simulation{n}(:,:);
        thisDataX = problem.shifted_data{n}(:,1);
        
        minX = thisDataX(1);
        maxX = thisDataX(end);

        minSim = find(thisRef(:,1)==minX);
        maxSim = find(thisRef(:,1)==maxX);

        thisRef = thisRef(minSim:maxSim,2)';
        
        
        
        if (length(thisRef) < l(n))
            addPoints = l(n) - length(thisRef);
            addVector = ones(1,addPoints)*thisRef(end);
            thisRef = [thisRef addVector];
        end
        refMat{n}(i,:) =  thisRef;
        
        thisSLD = problem.calculations.slds{n}(:,2)';
        if (length(thisSLD) < sldPoints)
            addPoints = sldPoints - length(thisSLD);
            addVector = ones(1,addPoints)*thisSLD(end);
            thisSLD = [thisSLD addVector];
        elseif (length(thisSLD) > sldPoints)
                thisSLD = thisSLD(1:sldPoints);
        end
             
        
        sldMat{n}(i,:) = thisSLD(1:sldPoints);
    end
    if (rem(i,dispFreq) == 20);
        pc = (i/loopNum)*100;
        fprintf('Processing chain: %5.1f percent complete \n ',pc);
        drawnow
    end
end
catch
    disp('Debug');
end
res.refMat = refMat;
res.sldMat = sldMat;
res.chi = chi;
loopNum = numberOfFits;


cInterval = round(confInt * (loopNum * factor));

try
for n = 1:size(problem.calculations.Simulation,2)
    refAndChi = [chi' refMat{n}];
    sldAndChi = [chi' sldMat{n}];
    refAndChi = sort(refAndChi,1,'ascend');
    sldAndChi = sort(sldAndChi,1,'ascend');
    trRef = refAndChi(1:cInterval,2:end);
    trSLD = sldAndChi(1:cInterval,2:end);
    trimRefMat{n} = trRef;
    trimSldMat{n} = trSLD;
    drawnow
end
catch 
    disp('debug');
end


problem.fitpars = bestPars;
problem = r1_unpackparams(problem);
setappdata(0,'problem',problem);
r1_reflectivity_calculation;
problem = getappdata(0,'problem');
bestSLD = problem.calculations.slds;
bestRef = problem.calculations.Simulation;
bestChi = problem.calculations.sum_chi;

%First the Reflectivities.....
%work out min and maximum points for each curve
for n = 1:size(problem.calculations.Simulation,2);
    thisRef = trimRefMat{n};
    npoints = size(thisRef,2);
    minVal = zeros(npoints,1);maxVal = zeros(npoints,1);
    for m = 1:npoints;
      thisCol = thisRef(:,m);
      minVal(m) = min(thisCol);
      maxVal(m) = max(thisCol);
    end
    minRefPoints{n} = minVal;
    maxRefPoints{n} = maxVal;
end
        
res.minLine = minRefPoints{1};
res.maxLine = maxRefPoints{1};

allCurves = trimRefMat{1};

figure(1)
subplot(1,2,1); cla; 
set(gca,'YScale','log');
set(gca,'XScale','log');
axis([0.001 0.3 1e-7 5]);
hold on
numberOfContrasts = size(problem.calculations.Simulation,2);

for n = 1:numberOfContrasts;
    thisRef = bestRef{n};
    thisData = problem.shifted_data{n};
    thisRefMin = find(thisData(1,1)==thisRef(:,1));
    thisRefMax = find(thisData(end,1)==thisRef(:,1));
    thisRef = thisRef(thisRefMin:thisRefMax,:);
    thisMin = minRefPoints{n};
    thisMax = maxRefPoints{n};
    if (n-1) > 0
        if n == 2
            mult = 1000;
        else
            mult = 10^(2*n);
        end
        thisMin = thisMin ./ mult;
        thisMax = thisMax ./ mult;
        thisRef(:,2) = thisRef(:,2) ./mult;
    end
    cc = [0.6 0.6 0.6];
    points = length(thisRef(:,1));
    makePatch(thisRef(:,1),thisRef(:,2),thisMin(1:points),thisMax(1:points), cc);
end

problem = r1_shiftdata(problem);
data = problem.shifted_data;
ran = zeros(numberOfContrasts,4);
for i = 1:numberOfContrasts
    thisData = data{i};
    if (i-1) > 0
        if i == 2
            mult = 1000;
        else
            mult = 10^(2*i);
        end
        thisData(:,2) = thisData(:,2) ./ mult;
        thisData(:,3) = thisData(:,3) ./ mult;
    end
    h = errorbar(thisData(:,1),thisData(:,2),thisData(:,3),'k.');
    ran(i,:) = [min(thisData(:,1)) max(thisData(:,1)) min(thisData(:,2)) max(thisData(:,2))];
    set(h,'Markersize',7);
end
set(gca,'FontSize',20);
hh = xlabel('Qz(�^-^1)');
set(hh,'FontSize',20);
hh = ylabel('Reflectivity');
set(hh,'FontSize',20);
%Set axes to the min and max values plus 10%
minXValue = min(ran(:,1));
maxXValue = max(ran(:,2));
minYValue = min(ran(:,3));
maxYValue = max(ran(:,4));
xRangeBorder = (maxXValue - minXValue)/5;
yRangeBorder = (maxYValue - minYValue)/5;
if (minXValue-xRangeBorder) > 0;
    xLim = (minXValue-xRangeBorder);
else
    xLim = -inf;
end

if (minYValue-yRangeBorder) > 0;
    yLim = (minYValue-yRangeBorder);
else
    yLim = -inf;
end

axis([xLim (maxXValue+xRangeBorder) yLim (maxYValue+yRangeBorder)]);

%Now need to make the SLD plots...
%work out min and maximum points for each curve
for n = 1:size(problem.calculations.Simulation,2);
    thisSld = trimSldMat{n};
    npoints = size(thisSld,2);
    minVal = zeros(npoints,1);maxVal = zeros(npoints,1);
    for m = 1:npoints;
      thisCol = thisSld(:,m);
      minVal(m) = min(thisCol);
      maxVal(m) = max(thisCol);
    end
    minSldPoints{n} = minVal;
    maxSldPoints{n} = maxVal;
end
% 

% res.minRefPoints = minRefPoints;
% res.maxRefPoints = maxRefPoints;
% res.minSldPoints = minSldPoints;
% res.maxSldPoints = maxSldPoints;
% res.bestRef = bestRef;
% res.bestSLD = bestSLD;
% save('calcResults','res')

figure(1); subplot(1,2,2); cla; hold on
for n = 1:numberOfContrasts;
    thisSld = bestSLD{n};
    thisMin = minSldPoints{n};
    thisMax = maxSldPoints{n};
    thisy = thisSld(:,2);
    thisx = thisSld(:,1);
    if length(thisy) > length(thisMin)
        thisy = thisy(1:length(thisMin));
        thisx = thisx(1:length(thisMin));
    elseif length(thisy) < length(thisMin)
        thisMin = thisMin(1:length(thisy));
        thisMax = thisMax(1:length(thisy));
    end
    makePatchNeg(thisx,thisy,thisMin,thisMax,[0.6 0.6 0.6]);
end


set(gca,'FontSize',20);
hh = xlabel('Distance(�)');
set(hh,'FontSize',20);
hh = ylabel('SLD (�^-^2)');
set(hh,'FontSize',20);

refBounds = {minRefPoints; maxRefPoints};
sldBounds = {minSldPoints; maxSldPoints};

setappdata(0,'problem',oldProblem);

end
