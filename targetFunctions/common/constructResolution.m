function resolution = constructResolution(resolutionType,resolutionParamIndex,shiftedData,customFiles,resolutionParamArray,simLimits)

% Apply resolution parameters to the resolution.
%
% For data and constant resolution, this means taking any predefined
% resolution data and adding any supplied poarameters.

% Define the resolution over the simulation range, making sure to include
% any predefined data.
[simulationXData, dataIndices] = makeSimulationRange(shiftedData, simLimits);

resolution = zeros(length(simulationXData),1);

% If we are using data resolutions, then we also need to adjust the length
% of the resolution column. We do this by just extending with the resolution
% values at the ends of the curve.
if strcmpi(resolutionType, coderEnums.allowedTypes.Data)
    thisDataResol = shiftedData(:,4);
    startResol = ones((dataIndices(1)-1),1) .* thisDataResol(1);
    endResol = ones((length(simulationXData)-dataIndices(2)),1) .* thisDataResol(end);
    resolution = [startResol(:) ; thisDataResol(:) ; endResol(:)];
else
    % WHY ON EARTH IS THE +0.0001 THERE ???????????????????
    resolutionParameter = resolutionParamArray(resolutionParamIndex);
    resolution = resolution + (resolutionParameter + 0.0001);
end

end
