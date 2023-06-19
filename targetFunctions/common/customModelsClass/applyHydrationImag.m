function thisContrastLayers = applyHydrationImag(thisContrastLayers,bulkIn,bulkOut)

% Applies the hydration correction to real value of layers
% if it is necessary.. (This is for when im(SLD) is used) 


% The only guidance we have to whether the user is using hydration
% in their custom model is the number of columns of the output
outSize = size(thisContrastLayers);     % [nlayers x nCols] 

if  outSize(2) == 6   % we need to calculate the hydrated SLD

    newOutLayers = zeros(outSize(1),4);
    newOutLayers(:,1) = thisContrastLayers(:,1);               % Thickness'
    newOutLayers(:,3) = thisContrastLayers(:,3);               % We never hydrate im(SLD)
    newOutLayers(:,4) = thisContrastLayers(:,4);               % Roughness

    for n = 1:outSize(1)
        thisSLD = thisContrastLayers(n,2);
        thisHydration = thisContrastLayers(n,5) / 100;   % Assume percent for backwards compatability
        thisHydrWhat = thisContrastLayers(n,6);
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