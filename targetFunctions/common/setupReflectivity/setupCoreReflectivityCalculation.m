function [background,resolution,shiftedData,simulationXData,dataIndices...
    ] = setupCoreReflectivityCalculation(backgroundParamIndex,...
    resolutionParamIndex,backgroundParams,resolutionParams,backgroundType,...
    resolutionType,customFiles,qzshift,scalefactor,dataPresent,data,...
    dataLimits,simulationLimits,numSimulationPoints)
   
    % Apply scale factors and q shifts to the data
    fullShiftedData = shiftData(scalefactor,qzshift,dataPresent,data,dataLimits,simulationLimits,numSimulationPoints);
    
    [simulationXData, dataIndices] = makeSimulationRange(fullShiftedData, simulationLimits);

    background = constructBackground(backgroundType,backgroundParamIndex,...
        fullShiftedData,customFiles,backgroundParams,simulationXData,dataIndices);
    resolution = constructResolution(resolutionType,resolutionParamIndex,...
        fullShiftedData,customFiles,resolutionParams,simulationXData,dataIndices);

    % Reduce data to original three columns
    shiftedData = fullShiftedData(:,1:3);

end