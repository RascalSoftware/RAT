function result = reflectivityCalculation(problemStruct,problemCells,problemLimits,controls)
% Main entry point into the reflectivity calculation for the toolbox.
% This is the main function that is called by any of the minimisers or
% analysis tools from the rest of the toolbox. 
%
% *The main job of this function is to decide which type of calculation
% (i.e. 'Target function' is required, and call the relevant routines.
% The types of available target functions are:*
%
% * non polarised  - The main basic target function type, for non polarised neutrons (or x-rays) with non-absorbing samples. Different model types are specified in sub functions from here.
%
% * oil water      - Target function for oil-water samples
%
% * domains        - Target function for samples consisting of domains which are larger than the beam lateral coherence length.
%
% * magnetic       - Target function for cases for polarised neutrons with polarisation analysis.
%                       

% for compilation, we have to preallocate memory for the output arrays
% Setting these parameters in the struct defines them as doubles
contrastParams.ssubs = 0;
contrastParams.backgroundParams = 0;
contrastParams.qzshifts = 0;
contrastParams.scalefactors = 0;
contrastParams.bulkIn = 0;
contrastParams.bulkOut = 0;
contrastParams.resolutionParams = 0;
contrastParams.calculations.allChis = 0;
contrastParams.calculations.sumChi = 0;
contrastParams.allSubRough = 0;
contrastParams.resample = 0;

% We also fill the results arrays to define their
% type and size. (NOTE: at the moment we have a 'coder.varsize'
% pre-processor directives for the compiler here and at the 
% end for the results block. We are unlikely to need both
% TODO: Find out which is necessary and tidy this up.

numberOfContrasts = problemStruct.numberOfContrasts;
reflectivity = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    reflectivity{i} = [1 1 ; 1 1];
end
coder.varsize('reflectivity{:}',[10000 2],[1 0]);

simulation = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    simulation{i} = [1 1 ; 1 1];
end
coder.varsize('simulation{:}',[10000 2],[1 0]);

shiftedData = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    shiftedData{i} = [1 1 1 ; 1 1 1];
end
coder.varsize('shiftedData{:}',[10000 3],[1 0]);

layerSlds = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    layerSlds{i} = [1 1 1 ; 1 1 1];
end
coder.varsize('layerSlds{:}',[10000 6],[1 1]);

domainLayerSlds = cell(numberOfContrasts,2);
for i = 1:numberOfContrasts
    domainLayerSlds{i,1} = [1 1 1 ; 1 1 1];
    domainLayerSlds{i,2} = [1 1 1 ; 1 1 1];
end
coder.varsize('domainLayerSlds',[10000 2],[1 1]);
coder.varsize('domainLayerSlds{:}',[10000 6],[1 1]);

sldProfiles = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    sldProfiles{i,1} = [1 1 ; 1 1];
end
coder.varsize('sldProfiles{:}',[10000 2],[1 0]);

domainSldProfiles = cell(numberOfContrasts,2);
for i = 1:numberOfContrasts
    domainSldProfiles{i,1} = [1 1 ; 1 1];
    domainSldProfiles{i,2} = [1 1 ; 1 1];
end
coder.varsize('domainSldProfiles',[10000 2],[1 1]);
coder.varsize('domainSldProfiles{:}',[10000 Inf],[1 1]);

allLayers = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    allLayers{i} = [1 1 1; 1 1 1];
end
coder.varsize('allLayers{:}',[10000 3],[1 0]);

domainAllLayers = cell(numberOfContrasts,2);
for i = 1:numberOfContrasts
    domainAllLayers{i,1} = [1 1 1; 1 1 1];
    domainAllLayers{i,2} = [1 1 1; 1 1 1];
end
coder.varsize('domainAllLayers',[10000 2],[1 1]);
coder.varsize('domainAllLayers{:}',[10000 3],[1 0]);

% Decide which target function we are calling and call the relevant routines
whichTF = problemStruct.TF;
switch whichTF
    case 'non polarised'
        [contrastParams,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,allLayers] = nonPolarisedTF.reflectivityCalculation(problemStruct,problemCells,controls);
    %case 'oil water'
        %contrastParams = oilWaterTFReflectivityCalculation(problemStruct,problemCells,controls);    
    %case 'magnetic'
        %contrastParams = polarisedTFReflectivityCalculation(problemStruct,problemCells,controls);
    case 'domains'
        [contrastParams,reflectivity,simulation,shiftedData,domainLayerSlds,domainSldProfiles,domainAllLayers] = domainsTF.reflectivityCalculation(problemStruct,problemCells,controls);
%     otherwise
%         error('The calculation type "%s" is not supported', whichTF);

end

cell1 = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    cell1{i} = reflectivity{i};
end
result.reflectivity = cell1;

cell2 = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    cell2{i} = simulation{i};
end
result.simulation = cell2;

cell3 = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    cell3{i} = shiftedData{i}; 
end
result.shiftedData = cell3;


% The size of this array now varies depending on TF
switch whichTF
    case 'domains'

        cell4 = cell(numberOfContrasts,2);
        for i = 1:numberOfContrasts
            cell4{i,1} = domainLayerSlds{i,1};
            cell4{i,2} = domainLayerSlds{i,2};
        end
        result.layerSlds = cell4;

        cell5 = cell(numberOfContrasts,2);
        for i = 1:numberOfContrasts
            cell5{i,1} = domainSldProfiles{i,1};
            cell5{i,2} = domainSldProfiles{i,2};
        end
        result.sldProfiles = cell5;

        cell6 = cell(numberOfContrasts,2);
        for i = 1:numberOfContrasts
            cell6{i,1} = domainAllLayers{i,1}; 
            cell6{i,2} = domainAllLayers{i,2};
        end
        result.allLayers = cell6;

    otherwise

        cell4 = cell(numberOfContrasts,1);
        for i = 1:numberOfContrasts
            cell4{i} = layerSlds{i};
        end
        result.layerSlds = cell4;

        cell5 = cell(numberOfContrasts,1);
        for i = 1:numberOfContrasts
            cell5{i} = sldProfiles{i};
        end
        result.sldProfiles = cell5;

        cell6 = cell(numberOfContrasts,1);
        for i = 1:numberOfContrasts
            cell6{i} = allLayers{i}; 
        end
        result.allLayers = cell6;

end

% Pre-processor directives for Matlab Coder
% to define the size of the output array
coder.varsize('contrastParams.ssubs',[Inf 1],[1 0]);
coder.varsize('contrastParams.backgroundParams',[Inf 1],[1 0]);
coder.varsize('contrastParams.qzshifts',[Inf 1],[1 0]);
coder.varsize('contrastParams.scalefactors',[Inf 1],[1 0]);
coder.varsize('contrastParams.bulkIn',[Inf 1],[1 0]);
coder.varsize('contrastParams.bulkOut',[Inf 1],[1 0]);
coder.varsize('contrastParams.resolutionParams',[Inf 1],[1 0]);
coder.varsize('contrastParams.ssubs',[Inf 1],[1 0]);
coder.varsize('contrastParams.calculations.allChis',[Inf 1],[1 0]);
coder.varsize('contrastParams.calculations.sumChi',[1 1],[0 0]);
coder.varsize('contrastParams.allSubRough',[Inf 1],[1 0]);
coder.varsize('contrastParams.resample',[1 Inf],[0 1]);

% Complete the result struct
[~,fitNames] = packParams(problemStruct,problemCells,problemLimits,controls.checks);

result.calculationResults = contrastParams.calculations;
result.contrastParams = contrastParams;
result.bestFitPars = problemStruct.fitParams;
result.fitNames = fitNames;

end
