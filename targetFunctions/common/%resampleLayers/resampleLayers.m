function newSLD = resampleLayers(layerSLD, threshold)

[xn,yn] = resample_sld(layerSLD,1);
[nx,ny] = groupSamples(xn(:),yn(:),threshold);
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