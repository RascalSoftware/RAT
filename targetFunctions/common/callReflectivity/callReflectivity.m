function [reflectivity,simulation] = callReflectivity(bulkIn,bulkOut,simulationXData,dataIndices,repeatLayers,layers,ssubs,resolution,parallel,refType)

repeatFlag = repeatLayers(1);
if repeatFlag
    nRepeats = repeatLayers(2);
else
    nRepeats = 1;
end

% Build the input arrays for thick, sld and rough

if isempty(layers)
    % No layers defined. Make a zeros dummy zero layer 
    layers = [0 bulkIn 0 0];
end

nLayers = size(layers,1);

% Number of layers (including repeats)
nLayersTot = (nLayers * nRepeats) + 2;

% Make arrays for thick, sld, rough
thicknesses = zeros(nLayersTot,1);
sldArray = zeros(nLayersTot,1);
slds = complex(sldArray,sldArray);
roughnesses = zeros(nLayersTot,1);

% Populate the d,rho,sig arrays...
layerCount = 2;
for m = 1:nRepeats
    for n = 1:nLayers
        thisLayer = layers(n,:);
        thicknesses(layerCount) = thisLayer(1);
        slds(layerCount) = complex(thisLayer(2), thisLayer(3));
        roughnesses(layerCount) = thisLayer(4);
        layerCount = layerCount + 1;
    end
end

% Add the air and substrate parameters
slds(1) = complex(bulkIn, eps);
slds(end) = complex(bulkOut, eps);
roughnesses(end) = ssubs;

simulation = zeros(length(simulationXData),2);
simulation(:,1) = simulationXData;

switch refType
    case 'standardAbeles'
        switch parallel
            case coderEnums.parallelOptions.Points
                % Parallelise over points
                
                % Calculate reflectivity
                simRef = abelesParallelPoints(simulationXData,nLayersTot,thicknesses,slds,roughnesses);

            otherwise
                % Calculate reflectivity
                simRef = abelesSingle(simulationXData,nLayersTot,thicknesses,slds,roughnesses);
                
        end

        % Apply resolution correction
        simulation(:,2) = resolutionPolly(simulationXData,simRef,resolution(:,2),length(simulationXData));

    otherwise
        coderException(coderEnums.errorCodes.invalidOption, 'The reflectivity type "%s" is not supported', refType);
end

reflectivity = simulation(dataIndices(1):dataIndices(2),:);

end
