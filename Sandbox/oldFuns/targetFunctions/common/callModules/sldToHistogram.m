function boxes = sldToHistogram(sld_curve)

layers = 1;
for i = 1:(size(sld_curve,1))-1;
    point1 = sld_curve(i,1);
    point2 = sld_curve(i+1,1);
    sld1 = sld_curve(i,2);
    sld2 = sld_curve(i+1,2);
    box_width = point2 - point1;
    box_sld = (sld1 + sld2) / 2;
    boxes(layers,:) = [box_width, box_sld];
    layers = layers + 1;
end

roughs = ones(length(boxes),1)*1e-20;
boxes = [boxes(:,1) boxes(:,2) roughs];