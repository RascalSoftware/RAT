function sldProfile= makeSLDProfiles(bulkIn,bulkOut,sld,ssub,repeats)


lays = size(sld,1);
if repeats(1) == 0
    reps = 1;
else
    reps = repeats(2);
end


sldProfile = makeSLDProfileXY(bulkIn,bulkOut,ssub,sld,lays,reps);

end