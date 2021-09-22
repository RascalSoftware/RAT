function problem = applyRoiMask(problem)

%problem = getappdata(0,'problem');

rois = problem.calculations.rois;
data = problem.shifted_data;


%Eventually move this mask creation to the startup
for n = 1:length(data)
    roiMasks{n} = ones(size(data{n},1),1);
end

for n = 1:size(rois,1);
    thisRoi = rois(n,:);
    if thisRoi(1)
        whichData = thisRoi(2);
        thisData = data{whichData};
        minRange = find(thisData(:,1)>=thisRoi(3));
        maxRange = find(thisData(:,1)<=thisRoi(4));
        thisRoiMask = roiMasks{whichData};
        thisRoiMask(minRange(1):maxRange(end)) = thisRoiMask(minRange(1):maxRange(end)) * thisRoi(5);
        roiMasks{whichData} = thisRoiMask;
    end
end
    

problem.calculations.roiMasks = roiMasks;

%setappdata(0,'problem',problem);

end


