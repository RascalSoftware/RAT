function [outSsubs,...
            backgs,...
            qshifts,...
            sfs,...
            nbas,...
            nbss,...
            resols,...
            chis,...
            reflectivity,...
            Simulation,...
            shifted_data,...
            layerSlds,...
            sldProfiles,...
            allLayers,...
            allRoughs] = standardTF_stanlay_parallel(resample, ...
            numberOfContrasts, ...
            geometry, ...
            repeatLayers , ...
            cBacks , ...
            cShifts , ...
            cScales , ...
            cNbas , ...
            cNbss, ...
            cRes , ...
            backs , ...
            shifts , ...
            sf, ...
            nba , ...
            nbs , ...
            res , ...
            dataPresent , ...
            allData , ...
            dataLimits , ...
            simLimits , ...
            nParams , ...
            params , ...
            contrastLayers , ...
            numberOfLayers , ...
            layersDetails,...
            problemDef_limits, ...
            backsType)


        
%global RAT_DEBUG DEBUGVARS        
%coder.extrinsic('callModules');  
% coder.varsize('backgs',[Inf,1],[1 0]); 
% coder.varsize('shifted_dat',[Inf 3],[1 0]);

            
%Pre-Allocation...
backgs = zeros(numberOfContrasts,1);
backgTypes = zeros(numberOfContrasts,1);
qshifts = zeros(numberOfContrasts,1);
sfs = zeros(numberOfContrasts,1);
nbas = zeros(numberOfContrasts,1);
nbss = zeros(numberOfContrasts,1);
resols = zeros(numberOfContrasts,1);
allRoughs = zeros(numberOfContrasts,1);
outSsubs = zeros(numberOfContrasts,1);
chis =  zeros(numberOfContrasts,1);
allLayers = cell(numberOfContrasts,1); 
layerSlds = cell(numberOfContrasts,1);
sldProfiles = cell(numberOfContrasts,1);
shifted_data = cell(numberOfContrasts,1);
% 
reflectivity = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    reflectivity{i} = [1 1 ; 1 1];
end
%coder.varsize('reflectivity{:}',[Inf 2],[1 0]);
% 
Simulation = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    Simulation{i} = [1 1 ; 1 1];
end
%coder.varsize('Simulation{:}',[Inf 2],[1 0]);
% 
allLayers = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    allLayers{i} = [1 ; 1];
end
% coder.varsize('allLayers{:}',[Inf 3],[1 1]);


boxes = cell(1,1);

outParameterisedLayers = allocateParamsToLayers(params, layersDetails);

parfor i = 1:numberOfContrasts
    [backgs(i),qshifts(i),sfs(i),nbas(i),nbss(i),resols(i)] = backSort(cBacks(i),cShifts(i),cScales(i),cNbas(i),cNbss(i),cRes(i),backs,shifts,sf,nba,nbs,res);

    allRoughs(i) = params(1);
    thisContrastLayers = allocateLayersForContrast(contrastLayers{i},outParameterisedLayers);
    [outLayers, outSsubs(i)] = groupLayers_Mod(thisContrastLayers,allRoughs(i),geometry,nbas(i),nbss(i));
    
    sldProfile = makeSLDProfiles(nbas(i),nbss(i),outLayers,outSsubs(i),repeatLayers{i});
    sldProfiles{i} = sldProfile;

    if resample(i) == 1
        layerSld = resampleLayers(sldProfile);
        layerSlds{i} = layerSld;
    else
        layerSld = outLayers;
        layerSlds{i} = layerSld;
    end
   
    shifted_dat = shiftdata(sfs(i),qshifts(i),dataPresent(i),allData{i},dataLimits{i});

    
    [reflect,Simul] = callReflectivity(nbas(i),nbss(i),simLimits{i},repeatLayers{i},shifted_dat,layerSld,outSsubs(i),backgs(i),resols(i));
    
    [reflect,Simul,shifted_dat] = applyBackgroundCorrection(reflect,Simul,shifted_dat,backgs(i),backsType(i));
    
    reflectivity{i} = reflect;
    Simulation{i} = Simul;
    shifted_data{i} = shifted_dat;
    
    chis(i) = chiSquared(shifted_dat,reflect,nParams);
end



% if coder.target('MATLAB')
%     if RAT_DEBUG
%         DEBUGVARS.standardTF_stanlay_single.outSsubs = outSsubs;
%         DEBUGVARS.standardTF_stanlay_single.backgs = backgs;
%         DEBUGVARS.standardTF_stanlay_single.qshifts = qshifts;
%         DEBUGVARS.standardTF_stanlay_single.sfs = sfs;
%         DEBUGVARS.standardTF_stanlay_single.nbas = nbas;
%         DEBUGVARS.standardTF_stanlay_single.nbss = nbss;
%         DEBUGVARS.standardTF_stanlay_single.resols = resols;
%         DEBUGVARS.standardTF_stanlay_single.chis = chis;
%         DEBUGVARS.standardTF_stanlay_single.reflectivity = reflectivity;
%         DEBUGVARS.standardTF_stanlay_single.Simulation = Simulation;
%         DEBUGVARS.standardTF_stanlay_single.shifted_data = shifted_data;
%         DEBUGVARS.standardTF_stanlay_single.layerSlds = layerSlds;
%         DEBUGVARS.standardTF_stanlay_single.sldProfiles = sldProfiles;
%         DEBUGVARS.standardTF_stanlay_single.allLayers = allLayers;
%         DEBUGVARS.standardTF_stanlay_single.allRoughs = allRoughs;
%     end
% end

end

