function SLDProfile = makeSLDProfile(bulkIn,bulkOut,layers,ssub,nrepeats)

numberOfLayers = size(layers,1);

if numberOfLayers>0
    totalThickness = sum(layers(:,1));
    totalRange = (totalThickness*nrepeats) + 150;
    x = 0:totalRange;
    Lays = zeros(length(x),(numberOfLayers*nrepeats)+2);
    boxCen = 0;
    boxWidth = 100;

    roughnessValues = layers(:,3)';
    roughnessValues(end+1) = ssub;

    nextLayerRoughness = roughnessValues(1);
    airBox = asymconvstep(x,boxWidth,boxCen,nextLayerRoughness,nextLayerRoughness,bulkIn);
    lastBoxEdge = boxCen + (0.5 * boxWidth);

    for n = 1:nrepeats
        for i = 1:numberOfLayers
            layerThickness = layers(i,1);
            layerSLD = layers(i,2);
            layerRoughness = roughnessValues(i);
            nextLayerRoughness = roughnessValues(i+1);
            thisBoxCentre = lastBoxEdge + (0.5 * layerThickness);
            thisBox = asymconvstep(x,layerThickness,thisBoxCentre,layerRoughness,nextLayerRoughness,layerSLD);
            Lays(:,i+(numberOfLayers*(n-1))) = thisBox;
            lastBoxEdge = thisBoxCentre + (0.5 * layerThickness);
        end
    end

    layerRoughness = nextLayerRoughness;
    layerThickness = (x(end)-lastBoxEdge)*2;
    layerSLD = bulkOut;
    nextLayerRoughness = ssub;
    thisBoxCentre = x(end);
    Lays(:,(numberOfLayers*nrepeats)+1) = asymconvstep(x,layerThickness,thisBoxCentre,layerRoughness,nextLayerRoughness,layerSLD);
    
    Lays(:,(numberOfLayers*nrepeats)+2) = airBox;
    SLD = sum(Lays,2);
else
    x = 0:100;
    subsBoxCen = max(x);
    airBoxCen = 0;
    widths = max(x);
    airBox = asymconvstep(x,widths,airBoxCen,ssub,ssub,bulkIn);
    subBox = asymconvstep(x,widths,subsBoxCen,ssub,ssub,bulkOut);
    SLD = airBox + subBox;
end

SLDProfile = [x(:), SLD(:)];

end
