function [reflectivity, simulation] = callReflectivity(bulkIn,bulkOut,simLimits,repeatLayers,data,layers,ssubs,resolution,parallel,refType,useImaginary)

repeatFlag = repeatLayers(1);
if repeatFlag
    nRepeats = repeatLayers(2);
else
    nRepeats = 1;
end

% Build the input arrays for thick, sld and rough.....

if isempty(layers)
    % No layers defined. Make a zeros dummy zero layer 
    layers = [0 bulkIn 0];
end

nLayers = size(layers,1);

% Number of layers (including repeats)
nLayersTot = (nLayers * nRepeats) + 2;

% Make arrays for thick, sld, rough
thicks = zeros(nLayersTot,1);
sldArray = zeros(nLayersTot,1);
slds = complex(sldArray,sldArray);
roughs = zeros(nLayersTot,1);

% Populate the d,rho,sig arrays...
layerCount = 2;
for m = 1:nRepeats
    for n = 1:nLayers
        thisLayer = layers(n,:);
        thicks(layerCount) = thisLayer(1);
        if ~useImaginary
            slds(layerCount) = complex(thisLayer(2), eps);
            roughs(layerCount) = thisLayer(3);
        else
            slds(layerCount) = complex(thisLayer(2),thisLayer(3));
            roughs(layerCount) = thisLayer(4);
        end
        layerCount = layerCount + 1;
    end
end

% Add the air and substrate parameters
slds(1) = complex(bulkIn, eps);
slds(end) = complex(bulkOut, eps);
roughs(end) = ssubs;

[simulationXData, dataIndices] = makeSimulationRange(data, simLimits);

simulation = zeros(length(simulationXData),2);
simulation(:,1) = simulationXData;

% If we are using data resolutions, then we also need to adjust the length
% of the resolution column. We do this by just extending with the resolution
% values at the ends of the curve.
simResolData = 0;
if resolution == -1
    thisDataResol = data(:,4);
    minVal = thisDataResol(1);
    maxVal = thisDataResol(end);
    startResol = ones((dataIndices(1)-1),1) .* minVal;
    endResol = ones((length(simulationXData)-dataIndices(2)),1) .* maxVal;
    simResolData = [startResol(:) ; thisDataResol(:) ; endResol(:)];
else
    % WHY ON EARTH IS THE +0.0001 THERE ???????????????????
    simResolData = ones(length(simulationXData),1) .* (resolution + 0.0001);
end

switch refType
    case 'standardAbeles'
        switch parallel
            case coderEnums.parallelOptions.Points
                % Parallelise over points
                
                % Calculate reflectivity....
                simRef = abelesParallelPoints(simulationXData,nLayersTot,thicks,slds,roughs);

                % Apply resolution
                % Note: paraPoints gives an error during validation, so use
                % single cored resolution as a workaround for now.
                simRef = resolutionPollyParallel(simulationXData,simRef,simResolData,length(simulationXData));
                %simRef = resolutionPolly(simulationXData,simRef,simResolData,length(simulationXData));
                
            otherwise
                % Single cored over points
                
                % Calculate reflectivity.....
                simRef = abelesSingle(simulationXData,nLayersTot,thicks,slds,roughs);
                
                % Apply resolution correction...
                simRef = resolutionPolly(simulationXData,simRef,simResolData,length(simulationXData));
        end
    otherwise
        coderException(coderEnums.errorCodes.invalidOption, 'The reflectivity type "%s" is not supported', refType);
end

simulation(:,2) = simRef(:);
reflectivity = simulation(dataIndices(1):dataIndices(2),:);

end
