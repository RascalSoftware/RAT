function testAbeles

q = linspace(0.001,0.3,500);

%      thick         sld               sigma
sld =   [50     complex(1e-6,1e-8)      5;
        150     complex(4e-6,1e-8)      5;
        50      complex(1e-6,0)         5];
    
nbair = complex(0,0);               % Bulk in SLD
nbsub = complex(2.073e-6,0);        % Bulk out sld
nrepeats = 1;                       % how many repeats of sld stack
ssub = 3;                           % Final layer roughness

layers = size(sld,1);
points = length(q);

tic
R = abeles(q,sld,nbair,nbsub,nrepeats,ssub,layers,points);
toc

tic
R = abeles_mex(q,sld,nbair,nbsub,nrepeats,ssub,layers,points);
toc

figure(1); clf
semilogy(q,R,'lineWidth',2.0);

end




