function [SLD, subRough] = domainsXY(params,bulk_in,bulk_out,contrast,domain)

debugPlot = false;      % optional debug plot

% Split up the parameters for convenience...
subRough = params(1);
oxideThick = params(2);
layerThick = params(3);
layerSLD = params(4);
layerRough = params(5);
domainSLD = params(6);

% Make an array of z values for our model...
z = 0:1:140;

% Make the volume fraction distribution for our Silicon substrate....
[vfSilicon, siSurf] = makeLayer(z,-25,50,1,subRough,subRough);

% ..and the Oxide....
[vfOxide, oxSurface] = makeLayer(z,siSurf,oxideThick,1,subRough,subRough);

% ..also our layer.
[vfLayer, laySurface] = makeLayer(z,oxSurface,layerThick,1,subRough,layerRough);

% Evereything that is not already occupied will be filled will water..
totalVF = vfSilicon + vfOxide + vfLayer;
vfWater = 1 - totalVF;

% Now convert the Volume Fractions to SLD's...
siSLD = vfSilicon * bulk_in;
oxSLD = vfOxide * 3.41e-6;

% Layer SLD depends on whether we are calculating the domain or not...
switch domain
    case 1
        laySLD = vfLayer * layerSLD;
    otherwise
        laySLD = vfLayer * domainSLD;
end

%...finally the water.
waterSLD = vfWater * bulk_out(contrast);

% Make the total SLD by just adding them all up..
totalSLD = siSLD + oxSLD + laySLD + waterSLD;

% The output is just a [n x 2] array of z against SLD..
SLD = [z(:) totalSLD(:)];

% (optional debug plot.....)
if debugPlot
    figure(1); clf;
    subplot(2,1,1);
    plot(z,vfSilicon(:));
    hold on
    plot(z,vfOxide(:));
    plot(z,vfLayer(:));
    plot(z,vfWater(:));
    title('Volume Fractions')

    subplot(2,1,2)
    plot(z,siSLD(:));
    hold on
    plot(z,oxSLD(:));
    plot(z,laySLD(:));
    plot(z,waterSLD(:));
    hold on
    plot(z,totalSLD,'k-','LineWidth',2);
    title('SLDs')
end

end

% -------------------------------------------------------------------------

function [VF, thisLaySurf] = makeLayer(z, prevLaySurf, thickness,....
                                 height, Sigma_L, Sigma_R)

% This procudes a layer, with a defined thickness, height and roughness.
% Each side of the layer has it's own roughness value

% Find the edges.....
l = prevLaySurf;
r = prevLaySurf + thickness;

% Make our heaviside
a = (z-l)./((2^0.5) * Sigma_L);
b = (z-r)./((2^0.5) * Sigma_R);
VF = (height/2)*(erf(a)-erf(b));

thisLaySurf = r;

end