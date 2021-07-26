function layersTest();

clear

figure(1); clf; hold on


Layers = [50    2e-6    10;
    100   4e-6    5];

sub_rough = 5;

% Air Liquid example...
bulkIn = 2.073e-6;
bulkOut = 6.35e-6;


newLayers = [
    50  2e-6   5
    50 4e-6   sub_rough];


qz = [0.005:0.002:0.4];
nlayers = size(newLayers,1);
npoints = length(qz);

for i = 1:10:50
    newLayers(1,3) = i;
    Ref = abeles_single(qz,newLayers,bulkIn,bulkOut,1,sub_rough,nlayers,npoints);
    figure(1); 
    plot(qz,Ref);
    set(gca,'YScale','log')
end


end



