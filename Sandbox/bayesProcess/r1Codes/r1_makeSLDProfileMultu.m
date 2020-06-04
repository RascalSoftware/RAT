function out = makeSLDProfileMulti(nbair,nbsub,ssub,layers,numberOfLayers,nrepeats);

debug = 0;

if debug == 1;
    figure(1);
    clf
    hold on
end

if numberOfLayers>0
    layerThicks = sum(layers(:,1));
    totalRange = (layerThicks*nrepeats) + 150;  
    x = 0:totalRange;
    boxCen = 0;
    boxWidth = 100;
    boxRough = layers(1,3);
    airBox = r1_asymconvstep(x,boxWidth,boxCen,boxRough,boxRough,nbair);
    lastBoxEdge = boxCen + (boxWidth/2);
    for n = 1:nrepeats
        for i = 1:numberOfLayers;
            thisLayThick = layers(i,1);
            thisLaySLD = layers(i,2);
            thisLayRough = layers(i,3);
            if i<numberOfLayers
                nextLayRough = layers(i+1,3);
            elseif (i == numberOfLayers) && (n < nrepeats)
                nextLayRough = layers(1,3);
            %else
            %    nextLayRough = ssub;
            end
            thisBoxCentre = lastBoxEdge + (thisLayThick/2);
            Lays(:,i+(numberOfLayers*(n-1))) = r1_asymconvstep(x,thisLayThick,thisBoxCentre,thisLayRough,nextLayRough,thisLaySLD);
            lastBoxEdge = thisBoxCentre + (thisLayThick/2);
            switch debug
                case 1
                    plot(x,Lays(:,i+(numberOfLayers*(n-1))));
            end
        end
    end
    thisLayThick = (x(end)-lastBoxEdge)*2;
    thisLaySLD = nbsub;
    %thisLayRough = ssub;
    nextLayRough = ssub;
    thisBoxCentre = x(end);
    Lays(:,(numberOfLayers*nrepeats)+1) = r1_asymconvstep(x,thisLayThick,thisBoxCentre,thisLayRough,nextLayRough,thisLaySLD);
    Lays(:,(numberOfLayers*nrepeats)+2) = airBox;

    SLD = sum(Lays,2);
else
    x = 0:100;
    subsBoxCen = max(x);
    airBoxCen = 0;
    widths = max(x);
    airBox = r1_asymconvstep(x,widths,airBoxCen,ssub,ssub,nbair);
    subBox = r1_asymconvstep(x,widths,subsBoxCen,ssub,ssub,nbsub);
    SLD = airBox + subBox;
end

out = [x(:),SLD(:)];




