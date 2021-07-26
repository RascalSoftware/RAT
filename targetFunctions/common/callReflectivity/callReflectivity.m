function [reflectivity, Simulation] = callReflectivity(nbairs,nbsubs,simLimits,repeatLayers,this_data,layers,ssubs,res,para,refType)

xdata = this_data(:,1);
output = layers;

if isempty(output)
    slds = [0 nbairs 0];
    lays = 0;
else
    slds = output(:,1:3);
    lays = size(slds,1);
end

simXLo = simLimits(1);
simXHi = simLimits(2);
middleSection = this_data(:,1);
split = [0 0];

if simXLo < xdata(1)
    step = (xdata(2)-xdata(1));
    firstSection = [simXLo:step:(xdata(1)-step)];
else
    firstSection = [];
end

if simXHi > xdata(end)
    step = (xdata(end)-xdata(end-1,1));
    lastSection = [xdata(end,1)+step:step:simXHi];
else
    lastSection = [];
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

repeats = repeatLayers(2);

switch refType
    case 'standardAbeles_realOnly'
        switch para
            case 'points'
                % Parallelise over points
                
                % Calculate reflectivity....
                simRef = abeles_paraPoints(simXdata, slds, nbairs, nbsubs, repeats, ssubs, lays, length(simXdata)); %(x,sld,nbair,nbsub,nrepeats,ssub,layers,points)
                
                % Apply resolution
                if res == -1
                    simRef = data_resolution_polly_paraPoints(simXdata,simRef,simResolData,length(simXdata));
                else
                    simRef = resolution_polly_paraPoints(simXdata,simRef,res,length(simXdata));
                end
                
            otherwise
                % Single cored over points
                
                % Calculate reflectivity.....
                simRef = abeles_single(simXdata, slds, nbairs,nbsubs,repeats,ssubs,lays,length(simXdata));
                
                % Apply resolution correction...
                if res == -1
                    simRef = data_resolution_polly(simXdata,simRef,simResolData,length(simXdata));
                else
                    simRef = resolution_polly(simXdata,simRef,res,length(simXdata));
                end
        end
end

Simulation(:,2) = simRef(:);
reflectivity = Simulation(splits(1):splits(2),:);

end
