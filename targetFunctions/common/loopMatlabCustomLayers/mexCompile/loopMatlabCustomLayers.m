
function [outLayers, allRoughs] = loopMatlabCustomLayers(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,shifts,sf,nba,...
    nbs,res,cCustFiles,numberOfContrasts,customFiles,params)

% This function excecutes in the base Matlab workspace.
outLayers = cell(numberOfContrasts,1);
allRoughs = zeros(numberOfContrasts,1);

parfor i = 1:numberOfContrasts
    % Extract the relevant parameter values for this contrast
    % from the input arrays.
    % First need to decide which values of the backrounds, scalefactors
    % data shifts and bulk contrasts are associated with this contrast
    [~,~,~,thisNba,thisNbs,~] = backSort(cBacks(i),cShifts(i),cScales(i),cNbas(i),cNbss(i),cRes(i),backs,shifts,sf,nba,nbs,res);
    
    thisCustomFile = customFiles{cCustFiles(i)};
    fName = thisCustomFile{1};
    
    % For backwards compatability, need an nbs array
    bulkOuts = zeros(numberOfContrasts,1);
    bulkOuts(i) = thisNbs;
    
    % Now call the customFile...
    [output,sRough] = feval(fName,params,thisNba,bulkOuts,i);
    
    % Deal with possible 5 column outLayers (i.e. need to calculate the
    % hydrated SLD manually)
    outSize = size(output);
    if outSize(2) == 5                           % we need to calculate the hydrated SLD
        newOutLayers = zeros(outSize(1),3);
        newOutLayers(:,1) = output(:,1);         % Thickness'
        newOutLayers(:,3) = output(:,3);
        
        for n = 1:outSize(1)
            thisSLD = output(n,2);
            thisHydration = output(n,4) / 100;   % Assume percent for backwards compatability
            thisHydrWhat = output(n,5);
            if thisHydrWhat == 0                 % Bulk out
                thisBulkHydr = bulkIn;
            else
                thisBulkHydr = bulkOut;
            end
            newSld = (thisHydration * thisBulkHydr) + ((1-thisHydration) * thisSLD);
            thisSldVal = newSld(1,1);   % Reassignment to keep codegen happy
            newOutLayers(n,2) = thisSldVal;
        end
        output = newOutLayers;
    end

    outLayers{i} = output;
    allRoughs(i) = sRough;
end
