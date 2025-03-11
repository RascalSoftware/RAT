function layers = applyHydration(layers,bulkIn,bulkOut)

% Applies the hydration correction to real value of the SLD of the layers
% if it is necessary.

% The only guidance we have to whether the user is using hydration
% in their custom model is the number of columns of the output
layersSize = size(layers);     % [nlayers x nCols] 

if  layersSize(2) == 6   % we need to calculate the hydrated SLD

    for i = 1:layersSize(1)
        hydration = 0.01 * layers(i,5);   % Assume percent for backwards compatability

        % Index 6 determines what we hydrate with
        if layers(i,6) == 1
            bulkHydration = bulkIn;
        else
            bulkHydration = bulkOut;
        end

        % Hydrate the real component of the SLD.
        % Note that we never hydrate the imaginary component of the SLD.
        layers(i,2) = (hydration * bulkHydration) + ((1 - hydration) * layers(i,2));

    end

    % Remove hydration columns
    layers(:,5:end) = [];

end