function [reflectivity, simulation] = callReflectivity(bulkIn,bulkOut,simLimits,repeatLayers,thisData,layers,ssubs,resolution,parallel,refType,useImaginary)

xdata = thisData(:,1);


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

simXLo = simLimits(1);
simXHi = simLimits(2);
middleSection = thisData(:,1);
split = [0 0];

if simXLo < xdata(1)
    step = (xdata(2)-xdata(1));
    firstSection = simXLo:step:(xdata(1)-step);
else
    firstSection = ones(1,0);
end

if simXHi > xdata(end)
    step = (xdata(end)-xdata(end-1,1));
    lastSection = xdata(end,1)+step:step:simXHi;
else
    lastSection = ones(1,0);
end

simXdata = [firstSection(:) ; middleSection(:) ; lastSection(:)];
splits = [(length(firstSection)+1) ((length(firstSection))+length(middleSection))];

simulation = zeros(length(simXdata),2);
simulation(:,1) = simXdata;

% If we are using data resolutions, then we also need to adjust the length
% of the resolution column. We do this by just extending with the resolution
% values at the ends of the curve.
simResolData = 0;
if resolution == -1
    thisDataResol = thisData(:,4);
    minVal = thisDataResol(1);
    maxVal = thisDataResol(end);
    startResol = ones((length(firstSection)),1) .* minVal;
    endResol = ones((length(lastSection)),1) .* maxVal;
    simResolData = [startResol(:) ; thisDataResol(:) ; endResol(:)];
end

switch refType
    case 'standardAbeles'
        switch parallel
            case coderEnums.parallelOptions.Points
                % Parallelise over points
                
                % Calculate reflectivity....
                simRef = abelesParallelPoints(simXdata,nLayersTot,thicks,slds,roughs);

                % Apply resolution              
                % Note: paraPoints gives an error during validation, so use
                % single cored resolution as a workaround for now.
                if resolution == -1
                    %simRef = dataResolutionPollyParallelPoints(simXdata,simRef,simResolData,length(simXdata));
                    simRef = dataResolutionPolly(simXdata,simRef,simResolData,length(simXdata));
                else
                    %simRef = resolutionPollyParallelPoints(simXdata,simRef,res,length(simXdata));
                    simRef = resolutionPolly(simXdata,simRef,resolution,length(simXdata));
                end
                
            otherwise
                % Single cored over points
                
                % Calculate reflectivity.....
                simRef = abelesSingle(simXdata,nLayersTot,thicks,slds,roughs);
                
                % Apply resolution correction...
                if resolution == -1
                    simRef = dataResolutionPolly(simXdata,simRef,simResolData,length(simXdata));
                else
                    simRef = resolutionPolly(simXdata,simRef,resolution,length(simXdata));
                end
        end
    otherwise
        error('The reflectivity type "%s" is not supported', refType);
end

simulation(:,2) = simRef(:);
reflectivity = simulation(splits(1):splits(2),:);

end
