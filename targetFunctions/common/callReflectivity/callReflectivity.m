function [reflectivity, Simulation] = callReflectivity(nbairs,nbsubs,simLimits,repeatLayers,this_data,layers,ssubs,res,parallel,refType,useImaginary)

xdata = this_data(:,1);


repeatFlag = repeatLayers(1);
if repeatFlag
    nRepeats = repeatLayers(2);
else
    nRepeats = 1;
end


% Build the input arrays for thick, sld and rough.....
 
if isempty(layers)
    % No layers defined. Make a zeros dummy zero layer 
    layers = [0 nbairs 0];
end

nLayers = size(layers,1);

% Number of layers (including repeats)
nLayersTot = (nLayers * nRepeats) + 2;

% Make arrays for thick, sld, rough
thicks = zeros(nLayersTot,1);
sldArray = zeros(nLayersTot,1);
roughs = zeros(nLayersTot,1);

if useImaginary
    slds = complex(sldArray,sldArray);
else
    slds = sldArray;
end

% Populate the d,rho,sig arrays...
layerCount = 2;
for m = 1:nRepeats
    for n = 1:nLayers
        thisLayer = layers(n,:);
        if ~useImaginary
            thicks(layerCount) = thisLayer(1);
            slds(layerCount) = thisLayer(2);
            roughs(layerCount) = thisLayer(3);
        else
            thicks(layerCount) = thisLayer(1);
            slds(layerCount) = complex(thisLayer(2),thisLayer(3));
            roughs(layerCount) = thisLayer(4);
        end
        layerCount = layerCount + 1;
    end
end

% Add the air and substrate parameters
slds(1) = nbairs;
slds(end) = nbsubs;
roughs(end) = ssubs;

simXLo = simLimits(1);
simXHi = simLimits(2);
middleSection = this_data(:,1);
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

Simulation = zeros(length(simXdata),2);
Simulation(:,1) = simXdata;

% If we are using data resolutions, then we also need to adjust the length
% of the reolution column. We do thit by just extending with the rosolution
% values at the ends of the curve.
simResolData = 0;
if res == -1
    thisDataResol = this_data(:,4);
    minVal = thisDataResol(1);
    maxVal = thisDataResol(end);
    startResol = ones((length(firstSection)),1) .* minVal;
    endResol = ones((length(lastSection)),1) .* maxVal;
    simResolData = [startResol(:) ; thisDataResol(:) ; endResol(:)];
end

switch refType
    case 'standardAbeles'
        switch parallel
            case 'points'
                % Parallelise over points
                
                % Calculate reflectivity....
                simRef = abelesParallelPoints(simXdata,nLayersTot,thicks,slds,roughs);

                % Apply resolution              
                % Note: paraPoints gives an error during valifation, so use
                % single cored resolution as a workaround for now.
                if res == -1
                    %simRef = dataResolutionPollyParallelPoints(simXdata,simRef,simResolData,length(simXdata));
                    simRef = dataResolutionPolly(simXdata,simRef,simResolData,length(simXdata));
                else
                    %simRef = resolutionPollyParallelPoints(simXdata,simRef,res,length(simXdata));
                    simRef = resolutionPolly(simXdata,simRef,res,length(simXdata));
                end
                
            otherwise
                % Single cored over points
                
                % Calculate reflectivity.....
                simRef = abelesSingle(simXdata,nLayersTot,thicks,slds,roughs);
                
                % Apply resolution correction...
                if res == -1
                    simRef = dataResolutionPolly(simXdata,simRef,simResolData,length(simXdata));
                else
                    simRef = resolutionPolly(simXdata,simRef,res,length(simXdata));
                end
        end
end

Simulation(:,2) = simRef(:);
reflectivity = Simulation(splits(1):splits(2),:);

end
