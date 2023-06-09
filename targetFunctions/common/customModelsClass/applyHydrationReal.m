function thisContrastLayers = applyHydrationReal(thisContrastLayers,useImaginary)

% Applies the hydration correction for real value of layers
% if it is necessary..


outSize = size(thisContrastLayers);
if (useImaginary && outSize(2) == 6) || (~useImaginary && outSize(2) == 5)                                     % we need to calculate the hydrated SLD
    newOutLayers = zeros(outSize(1),3);
    newOutLayers(:,1) = thisContrastLayers(:,1);         % Thickness'
    newOutLayers(:,3) = thisContrastLayers(:,3);         % Roughness

    for n = 1:outSize(1)
        thisSLD = thisContrastLayers(n,2);
        thisHydration = thisContrastLayers(n,4) / 100;   % Assume percent for backwards compatability
        thisHydrWhat = thisContrastLayers(n,5);
        if thisHydrWhat == 0                             % Bulk out
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


