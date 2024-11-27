function [simXdata, splits] = makeSimulationRange(data, simulationLimits)
% Construct the x data for the simulation. This consists of the x data from
% the supplied data, plus additional points above and below the data range
% as necessary.

lowSimLimit = simulationLimits(1);
highSimLimit = simulationLimits(2);
xData = data(:,1);

if lowSimLimit < xData(1)
    step = (xData(2)-xData(1));
    firstSection = lowSimLimit:step:(xData(1)-step);
else
    firstSection = ones(1,0);
end

if highSimLimit > xData(end)
    step = (xData(end)-xData(end-1,1));
    lastSection = xData(end,1)+step:step:highSimLimit;
else
    lastSection = ones(1,0);
end

simXdata = [firstSection(:); xData(:); lastSection(:)];
splits = [(length(firstSection)+1) ((length(firstSection))+length(xData))];

end
