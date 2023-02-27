function shifted_data = shiftData(scalefac,horshift,dataPresent,data,dataLimits,simLimits)
% Shifts the data according to scale factor. If there is no data, makes 
% x-data over the simulation range.
%
% INPUTS:
%
%     * scalefac = problem.scalefactors;
%     * horshift = problem.qshifts;
%     * numberOfContrasts = problem.numberOfContrasts;
%     * dataPresent = problem.dataPresent;
%     * allData = problem.data;
%     * dataLimits = problem.dataLimits;


switch dataPresent
    case 1
        if scalefac == 0
            scalefac = 1e-30;
        end
        data(:,1) = data(:,1) + horshift;
        data(:,2) = data(:,2) ./ scalefac;
        data(:,3) = data(:,3) ./ scalefac;
        
        lowLimit = dataLimits(1);
        hiLimit = dataLimits(2);
        
        lowIndex = find(data(:,1) < lowLimit);
        if ~isempty(lowIndex)
            lowIndex = lowIndex(end);
        else
            lowIndex = 1;
        end
        
        hiIndex = find(data(:,1) > hiLimit);
        if  ~isempty(hiIndex)
            hiIndex = hiIndex(1);
        else
            hiIndex = length(data(:,1));
        end
        
        shifted_data = data(lowIndex:hiIndex,:);
    otherwise
        simPoints = 100;
        simLo = simLimits(1);
        simHi = simLimits(2);
        simXData = linspace(simLo,simHi,simPoints);
        simYData = zeros(length(simXData),1);
        shifted_data = [simXData(:) simYData(:) simYData(:)];
end







 

    