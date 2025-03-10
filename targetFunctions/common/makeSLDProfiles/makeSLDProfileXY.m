function SLDProfile = makeSLDProfileXY(bulkIn,bulkOut,ssub,layers,numberOfLayers,nrepeats)

if numberOfLayers>0
    layerThicks = sum(layers(:,1));
    totalRange = (layerThicks*nrepeats) + 150;  
    x = 0:totalRange;
    Lays = zeros(length(x),(numberOfLayers*nrepeats)+2);
    boxCen = 0;
    boxWidth = 100;
    nextLayerRoughness = layers(1,3);
    airBox = asymconvstep(x,boxWidth,boxCen,nextLayerRoughness,nextLayerRoughness,bulkIn);
    lastBoxEdge = boxCen + (boxWidth/2);
    for n = 1:nrepeats
        for i = 1:numberOfLayers
            layerThickness = layers(i,1);
            layerSLD = layers(i,2);
            layerRoughness = layers(i,3);
            if i<numberOfLayers
                nextLayerRoughness = layers(i+1,3);
            else
                nextLayerRoughness = ssub;
            end
            thisBoxCentre = lastBoxEdge + (layerThickness/2);
            thisBox = asymconvstep(x,layerThickness,thisBoxCentre,layerRoughness,nextLayerRoughness,layerSLD);
            Lays(:,i+(numberOfLayers*(n-1))) = thisBox;
            lastBoxEdge = thisBoxCentre + (layerThickness/2);
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




