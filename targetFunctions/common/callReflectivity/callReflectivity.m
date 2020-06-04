function [reflectivity, Simulation] = callReflectivity(nbairs,nbsubs,simLimits,repeatLayers,this_data,layers,ssubs,backgrounds,res,type)


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

if simXLo < xdata(1)
    step = (xdata(2)-xdata(1));
    firstSection = [simXLo:step:(xdata(1)-step)];
else
    firstSection = 0;
end

if simXHi > xdata(end)
    step = (xdata(end)-xdata(end-1,1));
    lastSection = [xdata(end,1)+step:step:simXHi];
else
    lastSection = 0;
end

simXdata = [firstSection(:) ; middleSection ; lastSection(:)]';
trueXdata = middleSection(:);
splits = [length(firstSection) length(middleSection(:,1)) length(lastSection)];
repeats = repeatLayers(2);

switch type
    case 'points'
        simRef = abeles_paraPoints(simXdata, slds, nbairs, nbsubs, repeats, ssubs, lays, length(simXdata)); %(x,sld,nbair,nbsub,nrepeats,ssub,layers,points)
        simRef = resolution_polly(simXdata,simRef,res,length(simXdata));
    
    otherwise
        %simRef = abeles_single(simXdata, slds, nbairs, nbsubs, repeats, ssubs, lays, length(simXdata)); %(x,sld,nbair,nbsub,nrepeats,ssub,layers,points)
        %function out = paratt(x,sld,nbair,nbsub,nrepeats,rfinal,layers,points)

        simRef = abeles_single(simXdata, slds, nbairs,nbsubs,repeats,ssubs,lays,length(simXdata));
        simRef = resolution_polly(simXdata,simRef,res,length(simXdata));
end

firstSection = splits(1);
middleSection = splits(2);
Ref = simRef;
Ref = Ref((firstSection+1):(firstSection+middleSection));
%Ref = Ref + backgrounds;
reflectivity = [trueXdata(:) Ref(:)];
%simRef = simRef + backgrounds;
Simulation = [simXdata' simRef];



end
