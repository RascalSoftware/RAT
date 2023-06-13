function thisContrastLayers = applyHydrationReal(thisContrastLayers,bulkIn,bulkOut,useImaginary)

% Applies the hydration correction to real value of layers
% if it is necessary..

% Pick correct column for hydration
if useImaginary
    hydrCol = 5;
else
    hydrCol = 4;
end

% The only guidance we have to whether the user is using hydration
% in their custom model is the numbre of columns of the output
outSize = size(thisContrastLayers);     % [nlayers x nCols] 

if (useImaginary && outSize(2) == 6) || (~useImaginary && outSize(2) == 5)   % we need to calculate the hydrated SLD

    newOutLayers = zeros(outSize(1),3);
    newOutLayers(:,1) = thisContrastLayers(:,1);               % Thickness'
    newOutLayers(:,3) = thisContrastLayers(:,3);               % Roughness

    for n = 1:outSize(1)
        thisSLD = thisContrastLayers(n,2);
        thisHydration = thisContrastLayers(n,hydrCol) / 100;   % Assume percent for backwards compatability
        thisHydrWhat = thisContrastLayers(n,hydrCol + 1);
        if thisHydrWhat == 0                            
            thisBulkHydr = bulkIn;
        else
            thisBulkHydr = bulkOut;
        end
        newSld = (thisHydration * thisBulkHydr) + ((1-thisHydration) * thisSLD);
        thisSldVal = newSld(1,1);                        % Reassignment to keep codegen happy
        newOutLayers(n,2) = thisSldVal;
    end
    thisContrastLayers = newOutLayers;
end


