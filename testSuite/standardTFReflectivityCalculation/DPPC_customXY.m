function [outSLD,sub_rough] = DPPC_customXY(params,bulkIn,bulkOut,contrast)

% We need to load in the existing
% DPPC number densities and
% keep them in memory (so that the loading
% is not done at every iteration).

persistent dppc
if isempty(dppc)
    dppc = load('dppc.mat');
    dppc = dppc.dppc;
end

sub_rough = params(1);
oxideThickness = params(2);
oxideCoverage = params(3);
bilayerPosition = params(4);
bilayerCoverage = params(5);
bilayerRough = params(6);

% Start by defining a z-range for our whole model. 200 Angstroms should be
% fine:
z = 1:200;              % Range of model in angstroms

% Define the Silicon in terms of it's volume fraction, position, width and
% roughness.
bulk_si_VF = 1;         % Volume fraction of bulk Silicon        
siCentre = 0;           % Centre of Silicon box
siWidth = 50;           % Total Width of Silicon box

% Make the Silicon volume fraction box
siVF = asymconvstep(z,siWidth,siCentre,sub_rough,sub_rough,bulk_si_VF);

% Now make the oxide...
% We need it's centre relative to the Silicon surface
siSurf = siCentre + (siWidth/2);

% The centre of the oxide is 0.5 the total oxide width away
oxCentre = siSurf + (oxideThickness / 2);

% Then for full coverage, the Oxide layer box will be
oxVF = asymconvstep(z,oxideThickness,oxCentre,sub_rough,sub_rough,1);

%Adjust the oxide VF according to its coverage
oxVF = oxVF * oxideCoverage;

% Now deal with th Bilayer.
bilayerSLD = dppc.SLD;
bilayerVF = dppc.VF;

% Now deal with the Bilayer. Start by doing the convolution.
% We also need a Gaussian for the convolution 'filter'.
% Our bilayer is centred at zero in z, we need a Gaussian centred at the
% same value. We assume the fluctuation amplitude of the membrane is 2
% Angstroms (in reality this is another fitting parameter).

% First, make the Gaussian, with a width given by 'bilayerRough'..
filter = Gaussian(bilayerSLD(:,1),0,1,bilayerRough);
filter = [bilayerSLD(:,1),filter(:)];

% Now do the convolution...
bilayerSLD = sld_convolute(bilayerSLD,filter); 
bilayerVF = sld_convolute(bilayerVF ,filter);

% And deal with the bilayer coverage
bilayerSLD(:,2) = bilayerSLD(:,2) * bilayerCoverage;
bilayerVF(:,2) = bilayerVF(:,2) * bilayerCoverage;

% Locate the bilayer relative to the oxide..
oxideSurf = siSurf + oxideThickness;               % Pos Relative to oxide surface 
bilCentre = oxideSurf + bilayerPosition;           % Absolute position in z

% Because our bilayer is centered at zero, we just add this to the x fo our
% bilayer, both for the SLD and volume
bilayerSLD(:,1) = bilayerSLD(:,1) + bilCentre;
bilayerVF(:,1) = bilayerVF(:,1) + bilCentre;

% To Work out the total volume fraction including the bilayer,
% we first have to interpolate bilayer on the same scale as everything else
% (i.e. versus z). We also need to do the same thing with the SLD.
newBilVF = interpolateOnToZ(bilayerVF(:,1),bilayerVF(:,2),z);
newBilSLD = interpolateOnToZ(bilayerSLD(:,1),bilayerSLD(:,2),z);

% Now put everything together. The total VF is the sum of the VF of
% the individual components
totalVF = siVF + oxVF + newBilVF;

% The water VF is 1 - the toal
waterVF = 1 - totalVF;

% No deal with the SLD's
siSLD = siVF * 2.073e-6;
oxSLD = oxVF * 3.41e-6;
waterSLD = waterVF * bulkOut(contrast);

totalSLD = siSLD + oxSLD + newBilSLD + waterSLD;
outSLD = [z(:) totalSLD(:)];

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

% -----------------------------------------------------------------

function res = sld_convolute(signal,filter)

% This function convolutes the signal (in our case the bilayer SLD or volume) with a
% filter (in our case a Gaussian). Broadly speaking, the procedure is to
% take the Fourier transform of both curves, multiply those together, and
% inverse fourier transform the result, although there are a number of
% numerical correction steps that are required first:
%
%   1. Interpolate both curves onto the same x 'grid'
%   2. Ensure that both curves are zero at each end (called 'normalisation'
%   here)
%   3. Pad each curve with zeros at each end, the length of which is equal
%   to the sum of the lengths of both curves.
%   4. Do the convolution usign Matlab's 'conv' function.
%   5. Undo the corrections done in steps 1 to 3 on the convoluted curve to get the final result. 
 
debug = 0;          % flag for debug plot if required

%Interpolate signals onto uniform grid....
%sld....
sld_x = signal(:,1);
sld_y = signal(:,2);

st = sld_x(1);
en = sld_x(end);
newSldX = linspace(st,en,length(sld_y));
newSldY = interp1(sld_x,sld_y,newSldX);
new_sld = [newSldX(:) newSldY(:)];

%also filter....
filt_x = filter(:,1);
filt_y = filter(:,2);

st = filt_x(1);
en = filt_y(end);
newFiltX = linspace(st,en,length(filt_y));
newFiltY = interp1(filt_x,filt_y,newSldX);
new_filt = [newFiltX(:) newFiltY(:)];

%Need to pad the edge of the signal with zeros. Do this by padding out
%initially with the values at the edges, then 'normalise' the
%water regions to zero buy subtraction...
yStart = newSldY(1);
xStep = abs(newSldX(2)-newSldX(1));

%Do the zero padding.... 
padLength = (length(filter) + length(newSldX));
padStartX = (padLength*(-xStep))+newSldX(1);
padLeftX = linspace(padStartX,(newSldX(1)-xStep),padLength);
padEndX = padLength*(xStep)+newSldX(end);
padRightX = linspace((newSldX(end)+xStep),padEndX,padLength);
yPad = ones(1,padLength)*yStart;

%Make the 'spliced' data
padNewX = [padLeftX newSldX padRightX];
padNewY = [yPad newSldY yPad];

%....'normalise' to give zero edges...
yDivFactor = newSldY(1);
padNewY = padNewY - newSldY(1);

sigFactor = sum(newFiltY);
yFactor = sum(padNewY);
newFilter = newFiltY ./ sigFactor;
padNewY = padNewY ./ yFactor; 

%Then convolute... 
fConv = conv(padNewY,newFilter,'same');
fConv_preNorm = fConv;

%Finally 'denormalise' to get the result.... 
%padNewY = (padNewY.*yFactor) + yDivFactor;
fConv = (fConv.*yFactor) + yDivFactor;

switch debug
    case 1
        figure(100)
        clf
        plot(padNewX,fConv,'k--')
        hold on
        plot(newSldX,newSldY);
end

%Trim back to original size
stPoint = padLength;
endPoint = length(padNewX)-(padLength-1);

offset = 2;

finalX = padNewX(stPoint:endPoint) - offset;  %Not sure where this offset comes from - bug with the padding somewhere..
finalY = fConv(stPoint:endPoint);
res = [finalX(:) finalY(:)];

end

% ---------------------------------------------------------------------------------------------------


function f = Gaussian(z,Z,N,A)
%f(z) = gaussian(z,Z,N,A)
%
%	produces a gaussian at centre Z, of height
%	N and 1/e half width of A.

f = (N/(A*sqrt(pi)))*exp(-0.5*((z-Z).^2)/(A^2));

end

% ---------------------------------------------------------------------------------------------------

function [newY] = interpolateOnToZ(X,Y,z)

% Interpolates the curve given by [X Y] onto Z.
% It first extends the range of X and Y to cover the 
% whole range of z, otherwise Matlab's interp1 will
% return NaN when beyond the range of the original X

debug = 0;

% Pad out the lower end of X and Y
xLeftEdge = X(1);
xLeftPad = linspace(0,floor(xLeftEdge));
yLeftPad = zeros(length(xLeftPad),1);

% Do the same for the upper edge
xRightEdge = X(end);
if (max(z)-xRightEdge)<=10
    xRightPad = max(z);
else
    xRightPad = linspace(ceil(xRightEdge),max(z));
end
yRightPad = zeros(length(xRightPad),1);

extendedX = [xLeftPad(:) ; X(:) ; xRightPad(:)];
extendedY = [yLeftPad(:) ; Y(:) ; yRightPad(:)];

%Interpolate them onto z....
newY = interp1(extendedX,extendedY,z);

% Debug plot
if debug == 1
    figure(); clf
    clf
    plot(z,newY)
end

end