%function out = comp(x,sld,nbair,nbsub,nrepeats,ssub,layers,points)


x = linspace(0.01,0.6)';
nbair = 0;
nbsub = 6.35e-6;
repeats = 1;
ssub = 3;
layers = 3;
points = length(x);
sld = [100 4e-6 3 ;
    200 1e-6 3];

out = justParatt(x,sld,nbair,nbsub,repeats,ssub,layers,points);