function SLD = makeSLDProfile(bulkIn,bulkOut,layers,subRough,nRepeats)

    bulkIn = bulkIn * 1e6;
    bulkOut = bulkOut * 1e6;

if size(layers,1) > 0
    % Make a z range for the profile...
    % Find the maximum thickness, including any long roughness tail on final layer...
    totalThickness = sum(layers(:,1));
    outerLayerCentre = totalThickness - (layers(end,1)/2);

    % Find the point which covers 99% of the outer error function..
    outerLayerTailLim = (erfcinv(0.01) * sqrt(2) * layers(end,3)) + outerLayerCentre;

    % We need to make sure the total SLD range includes this...
    outerLayerTailExtension = outerLayerTailLim - outerLayerCentre;
    totalRange = ((totalThickness + outerLayerTailExtension)*nRepeats);

    % Add some extra range at the end...
    totalRange = totalRange + 100;
    z = 0:totalRange;

    % Scale the SLDs...
    layers(:,2) = layers(:,2) * 1e6;
    layers = repmat(layers,nRepeats,1);

    % Add an aditional 'layer' for the transition to bulk out...
    outLayer  = [0 bulkOut subRough];
    layers = [layers; outLayer];

    % Pre-definitions....
    nLayers = size(layers,1);
    allFuncs = zeros(length(z),nLayers);
    alpha = zeros(1,nLayers);

    lastLayerSLD = bulkIn;
    thisPos = 50;

    fullStack = [];
    fullAlpha = [];

    % Make the profile by adding an error function for each interface (we
    % use 'normcdf' because it scales more easily than 'erf'...)
    for n = 1:nRepeats
        for i = 1:nLayers
            nextRough = layers(i,3);
            nextLayerSLD = layers(i,2);
            diff = nextLayerSLD - lastLayerSLD;

            thisFun = normcdf(z,thisPos,nextRough);
            if diff < 0
                thisFun = -thisFun;
            end

            allFuncs(:,i) = thisFun(:);
            alpha(i) = abs(diff);
            thisPos = layers(i,1) + thisPos;
            lastLayerSLD = nextLayerSLD;
        end
        fullStack = [fullStack, allFuncs];
        fullAlpha = [fullAlpha, alpha];
    end
    totalFuncs = fullStack .* fullAlpha;
    total = sum(totalFuncs,2);
    
else
    % If we have no layers (i.e. just a bare interface), we only need one
    % cdf...
    z = 0:100;
    pos = 50;
    diff = bulkOut - bulkIn;
    thisFun = normcdf(z,pos,subRough);
    if diff < 1
        thisFun = -thisFun;
    end
    total = thisFun * abs(diff);
end

total = (total + bulkIn) * 1e-6;
SLD = [z(:) total(:)];

end