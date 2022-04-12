function updateReflectivityChart()

problem = getappdata(0,'problem');
myCharts = getappdata(0,'myCharts');
myUtils = getappdata(0,'myUtils');
numberOfContrasts = problem.numberOfContrasts;
shiftValue = problem.dataShiftValue;
useQ4 = problem.q4;

switch useQ4
    case 'yes'
        [allData,allSims] = applyQ4(problem);
    otherwise
        allData = problem.shifted_data;
        allSims = problem.calculations.Simulation;
end

pointsSeriesCounter = 0;
for i = 1:numberOfContrasts
    %thisData = problem.calculations.Simulation{i};
    thisSimData = allSims{i};
    if i>1
        mult = 10.^((i/100)*shiftValue);
    else
        mult=1;
    end

    thisSimData(:,2) = thisSimData(:,2)./mult;
    points = size(thisSimData,1);
    thisDoubleSimData = myUtils.convertArray(thisSimData,points);
    javaMethodEDT('updateTheReflSims',myCharts,thisDoubleSimData,points-1,i-1);
    
    switch problem.dataPresent(i)
        case 1
            thisData = allData{i};
            thisData(:,2) = thisData(:,2)./mult;
            points = size(thisData,1);
            thisDoubleData = myUtils.convertArray(thisData,points); 
            %thisDoubleData = thisData();
            javaMethodEDT('updateTheReflData',myCharts,thisDoubleData,points-1,pointsSeriesCounter);
            pointsSeriesCounter = pointsSeriesCounter + 1;
    end
end

drawnow;

end

% -------------------------------------------------------------------------

% function [allData, allSims] = applyQ4(problem)
% 
% warning('off','MATLAB:Axes:NegativeDataInLogAxis');
% 
% debugPlot = 0;
% 
% allData = problem.shifted_data;
% allSims = problem.calculations.Simulation;
% numberOfContrasts = problem.numberOfContrasts;
% 
% switch debugPlot
%     case 1
%         figure(1);
%         clf
%         subplot(2,1,1)
%         for i = 1:numberOfContrasts
%             errorbar(allData{i}(:,1),allData{i}(:,2),allData{i}(:,3),'.');
%             hold on;
%             plot(allSims{i}(:,1),allSims{i}(:,2));
%         end
%         set(gca,'YScale','log','XScale','log');   
% end
% 
% for i = 1:numberOfContrasts
%     thisData = allData{i};
%     thisBackground = problem.backgrounds(i);
%     q4 = thisData(:,1).^4;
%     thisData(:,2) = thisData(:,2)-thisBackground;
%     thisData(:,3) = thisData(:,3)-thisBackground;
%     thisData(:,2) = thisData(:,2) .* q4;
%     thisData(:,3) = thisData(:,3) .* q4;
%     allData{i} = thisData;
%     
%     thisSim = allSims{i};
%     q4 = thisSim(:,1).^4;
%     thisSim(:,2) = thisSim(:,2)-thisBackground;
%     thisSim(:,2) = thisSim(:,2) .* q4;
%     allSims{i} = thisSim;
% end
% 
% switch debugPlot
%     case 1
%         subplot(2,1,2)
%         for i = 1:numberOfContrasts
%             errorbar(allData{i}(:,1),allData{i}(:,2),allData{i}(:,3),'.');
%             hold on;
%             plot(allSims{i}(:,1),allSims{i}(:,2));
%         end
%         set(gca,'YScale','log','XScale','log');
% end
% 
% end