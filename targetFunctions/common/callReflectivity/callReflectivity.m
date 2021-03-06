function [reflectivity, Simulation] = callReflectivity(nbairs,nbsubs,simLimits,repeatLayers,this_data,layers,ssubs,res,para,refType)


% nbairs = problem.nbairs;
% nbsubs = problem.nbsubs;
% simLimits = problem.simLimits;
% repeatLayers = problem.repeatLayers;
% allData = problem.shifted_data;
% layers = problem.layers;
% ssubs = problem.ssubs;
% numberOfContrasts = problem.numberOfContrasts;

% reflectivity = cell(numberOfContrasts,1);
% Simulation = cell(numberOfContrasts,1);
% 
% parfor i = 1:numberOfContrasts

%this_data = allData{i};
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

repeats = repeatLayers(2);

switch refType
    case 'standardAbeles_realOnly'
        switch para
            case 'points'
                % Parallelise over points
                simRef = abeles_paraPoints(simXdata, slds, nbairs, nbsubs, repeats, ssubs, lays, length(simXdata)); %(x,sld,nbair,nbsub,nrepeats,ssub,layers,points)
                simRef = resolution_polly_paraPoints(simXdata,simRef,res,length(simXdata));
                
            otherwise
                % Single cored over points
                simRef = abeles_single(simXdata, slds, nbairs,nbsubs,repeats,ssubs,lays,length(simXdata));
                simRef = resolution_polly(simXdata,simRef,res,length(simXdata));
        end
end


Simulation(:,2) = simRef(:);
reflectivity = Simulation(splits(1):splits(2),:);

end
