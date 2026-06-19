function SLD = makeSLDProfile(bulkIn,bulkOut,layers,lastRough,nRepeats)

% Scale the SLDs...
layers(:,2) = layers(:,2) * 1e6;
bulkIn = bulkIn * 1e6;
bulkOut = bulkOut * 1e6;

% Define cdf...
cdf = @(x,mu,r) 0.5*(erf((x-mu)/(sqrt(2)*r)) + 1);

if size(layers,1) > 0
    % Make a z range for the profile...
    % Find the maximum thickness, including any long roughness tail on final layer...
    totalThickness = sum(layers(:,1));

    % Find the point which covers 99% of the outer error function..
    % We need to make sure the total SLD range includes this...
    outerLayerTailExtension = (erfcinv(0.01) * sqrt(2) * layers(end,3));
    totalRange = ((totalThickness + outerLayerTailExtension) * nRepeats);

    % Add some extra range at the end for bulk_out...
    totalRange = totalRange + 100;
    z = 0:totalRange;

    % Repeat the stack according to 'nRepeats'...
    layers = repmat(layers,nRepeats,1);

    % Add an aditional 'layer' for the transition to bulk out...
    outLayer  = [0 bulkOut lastRough];
    layers = [layers; outLayer];

    % Pre-definitions....
    nLayers = size(layers,1);
    allFuncs = zeros(length(z),nLayers);
    alpha = zeros(1,nLayers);
    lastLayerSLD = bulkIn;
    thisPos = 50;

    % Make the profile by adding an error function for each interface
    % (we use 'cdf' because it scales more easily than 'erf'...)
    for i = 1:nLayers
        nextRough = layers(i,3);
        nextLayerSLD = layers(i,2);
        diff = nextLayerSLD - lastLayerSLD;

        thisFun = cdf(z,thisPos,nextRough);
        if diff < 0
            thisFun = -thisFun;
        end

        allFuncs(:,i) = thisFun(:);
        alpha(i) = abs(diff);
        thisPos = layers(i,1) + thisPos;
        lastLayerSLD = nextLayerSLD;
    end
    totalFuncs = allFuncs.* alpha;
    total = sum(totalFuncs,2);
else
    % If we have no layers (i.e. just a bare interface), we only need one
    % cdf...
    z = 0:100;
    pos = 50;
    diff = bulkOut - bulkIn;
    thisFun = cdf(z,pos,lastRough);
    if diff < 1
        thisFun = -thisFun;
    end
    total = thisFun * abs(diff);
end

% Scale the SLD's back to Angstroms...
total = (total + bulkIn) * 1e-6;
SLD = [z(:) total(:)];

end