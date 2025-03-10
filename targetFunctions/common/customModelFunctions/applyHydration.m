function contrastLayers = applyHydration(contrastLayers,bulkIn,bulkOut)

% Applies the hydration correction to real value of the SLD of the layers
% if it is necessary.

% The only guidance we have to whether the user is using hydration
% in their custom model is the number of columns of the output
outSize = size(contrastLayers);     % [nlayers x nCols] 

if  outSize(2) == 6   % we need to calculate the hydrated SLD

    for n = 1:outSize(1)
        SLD = contrastLayers(n,2);
        hydration = 0.01 * contrastLayers(n,5);   % Assume percent for backwards compatability

        % Index 6 determines what we hydrate with
        if contrastLayers(n,6) == 0                            
            bulkHydration = bulkIn;
        else
            bulkHydration = bulkOut;
        end

        %newSld = (hydration * bulkHydration) + ((1 - hydration) * SLD);
        %thisSldVal = newSld(1,1);                        % Reassignment to keep codegen happy

        % Hydrate the real component of the SLD.
        % Note that we never hydrate the imaginary component of the SLD.
        contrastLayers(n,2) = (hydration * bulkHydration) + ((1 - hydration) * SLD);

    end

end