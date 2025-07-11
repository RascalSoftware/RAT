function resolution = constructResolution(resolutionType,resolutionParamIndex,shiftedData,customFiles,resolutionParamValues,simulationXData,dataIndices)

% Apply resolution parameters to the resolution.
%
% For data and constant resolutions, this means taking any predefined
% resolution data and adding any supplied parameters.

resolution = zeros(length(simulationXData),2);
resolution(:,1) = simulationXData;

if strcmpi(resolutionType, coderEnums.allowedTypes.Data)
    % If we are using data resolutions and the simulation range is larger
    % than the data range, we extend the data resolution to the simulation
    % range using the resolution values at the ends of the curve.
    resolution(1:dataIndices(1),2) = shiftedData(1,4);
    resolution(dataIndices(1):dataIndices(2),2) = shiftedData(:,4);
    resolution(dataIndices(2):end,2) = shiftedData(end,4);
else
    % For a constant resolution, we expect exactly one index here, but must
    % account for the case where resolutionParamIndex is empty.
    for i = 1:length(resolutionParamIndex)
        resolutionParameter = resolutionParamValues(resolutionParamIndex(i));
        resolution(:,2) = resolution(:,2) + resolutionParameter;
    end
end

% We must add eps (~10^-16) here in order to ensure we do not have any
% values identical to 0.0 in the resolution as this will cause a divide by
% zero error when the resolution correction is applied to the reflectivity.
resolution(:,2) = resolution(:,2) + eps;

end
