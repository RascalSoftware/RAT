function [out,subRough] = domainsXYModel(params,bulkIn,bulkOut,contrast,domain)


% {'Oxide thick',   10,         20,     50,     true}
%           {'Layer thick',   150,         300,    500,    true}
%           {'Layer SLD',     1e-6,       2e-6,   4e-6,   true}
%           {'Layer rough',   5,          10,     20,     true}
%           {'Domain d L1',   10,         200,     300,     true}
%           {'Domain rho l1', 1e-6,       2e-6,   3e-6,   true}

subRough = params(1);
dOx = params(2);
dLayer = params(3);
sldLayer = params(4);
sigLayer = params(5);
domThick = params(6);
domRho = params(7);

% Make air layer....
z = 0:800;
air = asymconvstep(z,100,0,subRough,subRough,0);
airSurf = (0 + 100/2);

% Domains.....
switch domain
    case 1
        layCen = airSurf + (dLayer / 2);
        lay = asymconvstep(z,dLayer,layCen,subRough,sigLayer,1);
        laySurf = layCen + (dLayer / 2);
        laySld = lay * sldLayer;
    case 2
        layCen = airSurf + (domThick / 2);
        lay = asymconvstep(z,domThick,layCen,subRough,sigLayer,1);
        laySurf = layCen + (domThick / 2);
        laySld = lay * domRho;
end

% End....
siThick = max(z) - laySurf;
si = asymconvstep(z,siThick,max(z),sigLayer,sigLayer,1);
silicon = si * bulkOut;

sldTot = air + laySld + silicon;

out = [z(:) sldTot(:)];

end

function f = asymconvstep(z,zw,zcen,s1,s2,h)
% Produces a step function convoluted with differnt error functions
% on each side.
%
% AsymConvstep (z,zw,xcen,s1,s2,h)
%       z = vector of x values
%      zw = Width of step function
%    zcen = Centre point of step function
%       s1 = Roughness parameter of left side
%       s2 = Roughness parameter of right side
%       h = Height of step function.

% Since the step is defined in terms of it's centre
% and its width, we find the edges as centre +/- 0.5 width.
r = zcen + (zw/2);          % Right edge
l = zcen - (zw/2);          % Left edge

% Make the box
a = (z-l)./((2^0.5)*s1);
b = (z-r)./((2^0.5)*s2);
f = (h/2)*(erf(a)-erf(b));

end