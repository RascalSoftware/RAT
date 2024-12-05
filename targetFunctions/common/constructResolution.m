function resolution = constructResolution(resolutionType,resolutionParamIndex,shiftedData,customFiles,resolutionParamArray,simLimits)

% Apply resolution parameters to the resolution.
%
% For data and constant resolutions, this means taking any predefined
% resolution data and adding any supplied parameters.

% Define the resolution over the simulation range, making sure to include
% any predefined data.
[simulationXData, dataIndices] = makeSimulationRange(shiftedData, simLimits);

resolution = zeros(length(simulationXData),2);
resolution(:,1) = simulationXData;

% If we are using data resolutions, then we also need to adjust the length
% of the resolution column. We do this by just extending with the resolution
% values at the ends of the curve.
if strcmpi(resolutionType, coderEnums.allowedTypes.Data)
    resolution(1:dataIndices(1),2) = shiftedData(1,4);
    resolution(dataIndices(1):dataIndices(2),2) = shiftedData(:,4);
    resolution(dataIndices(2):end,2) = shiftedData(end,4);
else
    % WHY ON EARTH IS THE +0.0001 THERE ???????????????????
    resolutionParameter = resolutionParamArray(resolutionParamIndex);
    resolution(:,2) = resolution(:,2) + (resolutionParameter + 0.0001);
end

% We must add eps (~10^-16) here in order to ensure we do not have any
% values identical to 0.0 in the resolution as this will cause a divide by
% zero error when the resolution correction is applied to the reflectivity.
% resolution(:,2) = resolution(:,2) + eps;

end
