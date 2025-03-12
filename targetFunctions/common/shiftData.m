function shiftedData = shiftData(scalefactor,qzshift,dataPresent,data,dataLimits,simulationLimits)
% Shifts the data according to scale factor. If there is no data, makes 
% x-data over the simulation range.
%
% INPUTS:
%     * scalefactor: problemStruct.scalefactors
%     * qzshift: problemStruct.qzshifts
%     * dataPresent: problemStruct.dataPresent
%     * data: problemStruct.data
%     * dataLimits: problemStruct.dataLimits
%     * simulationLimits: problemStruct.simulationLimits
%
% OUTPUTS:
%     * shiftedData: Data shifted using given scale factor

if dataPresent
    
    if scalefactor == 0
        scalefactor = eps;
    end
    data(:,1) = data(:,1) + qzshift;
    data(:,2) = data(:,2) ./ scalefactor;
    data(:,3) = data(:,3) ./ scalefactor;
    
    lowLimit = dataLimits(1);
    hiLimit = dataLimits(2);
    
        lowIndex = find(data(:,1) < lowLimit);
        if ~isempty(lowIndex)
            lowIndex = lowIndex(end);
        else
            lowIndex = 1;
        end
    
        hiIndex = find(data(:,1) > hiLimit);
        if ~isempty(hiIndex)
            hiIndex = hiIndex(1);
        else
            hiIndex = length(data(:,1));
        end
    
    shiftedData = data(lowIndex:hiIndex, :);

else

    simPoints = 500;
    simLo = simulationLimits(1);
    simHi = simulationLimits(2);
    simXData = linspace(simLo,simHi,simPoints);
    shiftedData = zeros(length(simXData), 6);
    shiftedData(:, 1) = linspace(simLo,simHi,simPoints);

end

end
