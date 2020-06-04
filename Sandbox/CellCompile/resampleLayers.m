function newSLD = resampleLayers(layerSLD)

[xn,yn] = resample_sld(layerSLD,1);
[nx,ny] = groupSamples(xn(:),yn(:),1e-8);
newSld = [nx(:) ny(:)];
allNonZero = find(newSld(:,1));
maxIndex = allNonZero(end);
xn = ones(maxIndex,1);
yn = ones(maxIndex,1);
xn = newSld(1:maxIndex,1);
yn = newSld(1:maxIndex,2);
rrr = ones(length(xn),1)*1e-20;
newSLD = [xn(:) yn(:) rrr(:)];

end