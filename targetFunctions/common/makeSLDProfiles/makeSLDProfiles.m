function sldProfile= makeSLDProfiles(nbair,nbsub,sld,ssub,repeats)


lays = size(sld,1);
if repeats(1) == 0
    reps = 1;
else
    reps = repeats(2);
end


sldProfile = makeSLDProfileXY(nbair,nbsub,ssub,sld,lays,reps);

end