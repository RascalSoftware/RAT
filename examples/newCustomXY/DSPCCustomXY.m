function [outSLD,sub_rough] = DSPCCustomXY(params,bulkIn,bulkOut,contrast)

% Gaussian model of DPPC....

sub_rough = params(1);
oxideThickness = params(2);
oxideCoverage = params(3);
waterThick = params(4);
headThick = params(5);
headSLD = params(6);
tailsThick = params(7);
tailsSLD = params(8);
meThick = params(9);
bilayerRough = params(10);
headHydration = params(11);
bilayerCoverage = params(12);

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
oxSurf = siSurf + oxideThickness;

% Make volume fractions of the bilayer components.....

% Water Layer.....
% waterCentre = oxSurf + (waterThick /2);
% watVF  = asymconvstep(z,waterThick,waterCentre,oxRough,bilayerRough,1);
watSurf = oxSurf + waterThick;

% Lower head
lowHeadCen = watSurf + (headThick / 2);
lowHeadVF = asymconvstep(z,headThick,lowHeadCen,bilayerRough,bilayerRough,1);
lowHeadSurf = watSurf + headThick;

% Lower Tails
lowTailsCen = lowHeadSurf + (tailsThick/2);
lowTailsVF = asymconvstep(z,tailsThick,lowTailsCen,bilayerRough,bilayerRough,1);
lowTailsSurf = lowHeadSurf + tailsThick;

% Methyl....
meSLD = tailsSLD - 0.5e-6;
meCen = lowTailsSurf + (meThick / 2);
meVF = asymconvstep(z,meThick,meCen,bilayerRough,bilayerRough,1);
meSurf = lowTailsSurf + lowTailsSurf;

% Upper Tails....
upTailsCen = meSurf + (tailsThick/2);
upTailsVF = asymconvstep(z,tailsThick,upTailsCen,bilayerRough,bilayerRough,1);
upTailsSurf = lowHeadSurf + tailsThick;

% Upper head
upHeadCen = upTailsSurf + (headThick / 2);
upHeadVF = asymconvstep(z,headThick,upHeadCen,bilayerRough,bilayerRough,1);
upHeadSurf = upTailsSurf + headThick;


% Group the bilayer components together (in order to apply an overall
% coverage)
% 1. First deal with the head hydration....
lowHeadVF = lowHeadVF * (1 - headHydration);
upHeadVF = upHeadVF * (1 - headHydration);

% Make the bilayer group.....
bilayerVF = lowHeadVF + lowTailsVF + meVF + upTailsVF + upHeadVF;

% Correct for coverage.....
bilayerVF = bilayerVF .* bilayerCoverage;

% Work out the total volume fraction accross the model....
totalVF = siVF + oxVF + bilayerVF;

% The water VF is 1 - the toal
waterVF = 1 - totalVF;

% No deal with the SLD's
siSLD = siVF * 2.073e-6;
oxSLD = oxVF * 3.41e-6;
waterSLD = waterVF * bulkOut(contrast);
lHeadSLD = lowHeadVF .* headSLD;
uHeadSLD = upHeadVF .* headSLD;
meSLD = meVF .* meSLD;
lTailsSLD = lowTailsVF .* tailsSLD;
uTailsSLD = upTailsVF .* tailsSLD;

totalSLD = siSLD + oxSLD + lHeadSLD + lTailsSLD + meSLD + uTailsSLD + uHeadSLD +  waterSLD;
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
