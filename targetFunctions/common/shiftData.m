function shiftedData = shiftData(scalefactor,qzshift,dataPresent,data,dataLimits,simLimits)
% Shifts the data according to scale factor. If there is no data, makes 
% x-data over the simulation range.
%
% INPUTS:
%     * scalefactor: problemDefStruct.scalefactors
%     * qzshift: problemDefStruct.qzhifts
%     * dataPresent: problemDefStruct.dataPresent
%     * data: problemDefStruct.data
%     * dataLimits: problemDefStruct.dataLimits
%     * simLimits: problemDefStruct.simLimits
%
% OUTPUTS:
%     * shiftedData: Data shifted using given scale factor

switch dataPresent

    case 1
        
        if scalefactor == 0
            scalefactor = 1e-30;
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
        if  ~isempty(hiIndex)
            hiIndex = hiIndex(1);
        else
            hiIndex = length(data(:,1));
        end
        
        shiftedData = data(lowIndex:hiIndex,:);

    otherwise

        simPoints = 500;
        simLo = simLimits(1);
        simHi = simLimits(2);
        simXData = linspace(simLo,simHi,simPoints);
        simYData = zeros(length(simXData),1);
        shiftedData = [simXData(:) simYData(:) simYData(:)];

end
 