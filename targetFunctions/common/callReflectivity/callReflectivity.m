function [reflectivity, simulation] = callReflectivity(bulkIn,bulkOut,simulationXData,dataIndices,repeatLayers,layers,ssubs,resolution,parallel,refType,useImaginary)

repeatFlag = repeatLayers(1);
if repeatFlag
    nRepeats = repeatLayers(2);
else
    nRepeats = 1;
end

% Build the input arrays for thick, sld and rough

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

simulation = zeros(length(simulationXData),2);
simulation(:,1) = simulationXData;

switch refType
    case 'standardAbeles'
        switch parallel
            case coderEnums.parallelOptions.Points
                % Parallelise over points
                
                % Calculate reflectivity
                simRef = abelesParallelPoints(simulationXData,nLayersTot,thicks,slds,roughs);

                % Apply resolution
                simRef = resolutionPollyParallel(simulationXData,simRef,resolution(:,2),length(simulationXData));
                
            otherwise
                % Single cored over points
                
                % Calculate reflectivity
                simRef = abelesSingle(simulationXData,nLayersTot,thicks,slds,roughs);
                
                % Apply resolution correction
                simRef = resolutionPolly(simulationXData,simRef,resolution(:,2),length(simulationXData));
        end
    otherwise
        coderException(coderEnums.errorCodes.invalidOption, 'The reflectivity type "%s" is not supported', refType);
end

simulation(:,2) = simRef(:);
reflectivity = simulation(dataIndices(1):dataIndices(2),:);

end
