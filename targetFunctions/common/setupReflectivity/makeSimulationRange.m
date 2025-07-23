function [simulationXdata, splits] = makeSimulationRange(data, simulationLimits)
% Construct the x data for the simulation. This consists of the x data from
% the supplied data, plus additional points above and below the data range
% as necessary.

lowSimulationLimit = simulationLimits(1);
highSimulationLimit = simulationLimits(2);
xData = data(:,1);

if lowSimulationLimit < xData(1)
    step = (xData(2)-xData(1));
    firstSection = lowSimulationLimit:step:(xData(1)-step);
else
    firstSection = ones(1,0);
end

if highSimulationLimit > xData(end)
    step = (xData(end)-xData(end-1,1));
    lastSection = xData(end,1)+step:step:highSimulationLimit;
else
    lastSection = ones(1,0);
end

simulationXdata = [firstSection(:); xData(:); lastSection(:)];
splits = [(length(firstSection)+1) ((length(firstSection))+length(xData))];

end
