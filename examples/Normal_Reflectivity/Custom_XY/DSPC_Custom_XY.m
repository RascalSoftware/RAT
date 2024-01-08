function [SLD, subRough, varargout] = DSPC_Custom_XY_2(params,bulk_in,bulk_out,contrast)

% This function makes a model of a supported DSPC bilayer using volume
% restricted distribution functions.


debug = false;      % controls.whether we make debug plot....

global outputVF;    % This is a flag which controls if we output our VF's.
                    % If this is set to 'false', then this function can be
                    % used as a RAT custom function (otherwise RAT will
                    % fail with 'too many outputs' error....). Set to
                    % 'true', the third (optional) output parameter is our
                    % Volume Fractions.

% Split up the parameters
subRough = params(1);
oxideThick = params(2);
oxideHydration = params(3);
waterThick = params(4);
lipidAPM = params(5);
lipidCoverage = params(6);
bilayerRough = params(7);

% We are going to need our Neutron scattering cross sections, plus the
% component volumes (the volumes are taken from Armen et al as ususal).
% Defien these first....

% define all the neutron b's.
bc = 0.6646e-4;     %Carbon
bo = 0.5843e-4;     %Oxygen
bh = -0.3739e-4;	%Hydrogen
bp = 0.513e-4;      %Phosphorus
bn = 0.936e-4;      %Nitrogen
bd = 0.6671e-4;     %Deuterium

% Now make the lipid groups..
COO = (4*bo) + (2*bc);
GLYC = (3*bc) + (5*bh);
CH3 = (2*bc) + (6*bh);             
PO4 = (1*bp) + (4*bo);
CH2 = (1*bc) + (2*bh);
CHOL = (5*bc) + (12*bh) + (1*bn);

% Group these into heads and tails:
Head = CHOL + PO4 + GLYC + COO;
Tails = (34*CH2) + (2*CH3);

% We need volumes for each.
% Use literature values:
vHead = 319;
vTail = 782;

% Start making our sections. For each we are using a roughened Heaviside to
% describe our groups. We will make these as Volume Fractions (i.e. with a
% height of 1 for full occupancy), which we will correct later for
% hydration.

% Make an array of z values for our model...
z = 0:1:140;

% Make our Silicon substrate....
[vfSilicon, siSurf] = layer(z,-25,50,1,subRough,subRough);

% add the Oxide....
[vfOxide, oxSurface] = layer(z,siSurf,oxideThick,1,subRough,subRough);

% We fill in the water at the end, but there may be a hydration layer
% beyween the bilayer and the oxide, so we start the bilayer stack an
% appropriate distance away...
watSurface = oxSurface + waterThick;

% Now make the first lipid head group....
% Work out the thickness...
headThick = vHead / lipidAPM;

% ...and make a box for the volume fraction (1 for now, we correct for
% coverage later)
[vfHeadL, headLSurface] = layer(z,watSurface,headThick,1,bilayerRough,bilayerRough);

% ... also do the same for the tails...
% We'll make both together, so the thickness will be twice the volume..
tailsThick = (2 * vTail) / lipidAPM;
[vfTails, tailsSurf] = layer(z,headLSurface,tailsThick,1,bilayerRough,bilayerRough);

% Finally the upper head.....
[vfHeadR, headSurface] = layer(z,tailsSurf,headThick,1,bilayerRough,bilayerRough);


%% Making the model....
% We've created the volume fraction profiles corresponding to each of the
% groups. We now convert them to SLD's, taking in account of the
% hydrations to scale the volume fractions.....

% 1. Oxide...
vfOxide = vfOxide * (1 - oxideHydration);

% 2. Lipid...
% Scale both the heads and tails according to overall coverage...
vfTails = vfTails .* lipidCoverage;
vfHeadL = vfHeadL .* lipidCoverage;
vfHeadR = vfHeadR .* lipidCoverage;

% Some extra work to deal with head hydration, which we take to be an additional 
% 30% always...
vfHeadL = vfHeadL .* 0.7;
vfHeadR = vfHeadR .* 0.7;

% Make a total Volume Fraction across the whole interface.....
vfTot = vfSilicon + vfOxide + vfHeadL + vfTails + vfHeadR;

% All the volume that's left, we will fill with water..
vfWat = 1 - vfTot;

% Now convert all the Volume Fractions to SLD's...
sld_Value_Tails = Tails / vTail;
sld_Value_Head = Head / vHead;

sldSilicon = vfSilicon .* 2.073e-6;
sldOxide = vfOxide .* 3.41e-6;

sldHeadL = vfHeadL .* sld_Value_Head;
sldHeadR = vfHeadR .* sld_Value_Head;
sldTails = vfTails .* sld_Value_Tails;
sldWat = vfWat .* bulk_out(contrast);

% Put this all together.....
totSLD = sldSilicon + sldOxide + sldHeadL + sldTails + sldHeadR + sldWat;

% Make the SLD array for output....
SLD = [z(:) totSLD(:)];

% If asked, make some debug plots.....
if debug
    figure(100); clf; hold on

    subplot(2,1,1);
    plot(z,vfSilicon);
    hold on
    plot(z,vfOxide);
    plot(z,vfHeadL);
    plot(z,vfTails);
    plot(z,vfHeadR);
    plot(z,vfWat);
    title('Volume Fractions');

    subplot(2,1,2)
    plot(z,sldSilicon);
    hold on
    plot(z,sldOxide);
    plot(z,sldHeadL);
    plot(z,sldTails);
    plot(z,sldHeadR);
    plot(z,sldWat);
    plot(z,totSLD,'k-','LineWidth',2.0)
end

% If asked, output our Volume Fractions as a third parameter....
if outputVF
    % Make one array of out VF's...
    allVFs = [z(:) vfSilicon(:) vfOxide(:) vfHeadL(:) vfTails(:) vfHeadR(:) vfWat(:)];
    
    % Assign this to our optional output....
    varargout = {allVFs};
end

end

% ------------------------------------------------------------------------

function [VF, r] = layer(z, prevLaySurf, thickness,....
                                 height, Sigma_L, Sigma_R)

% This procudes a layer, with a defined thickness, height and roughness'.
% Each side of the layer has it's own roughness value

% Find the edges.....
l = prevLaySurf;
r = prevLaySurf + thickness;

% Make our heaviside
a = (z-l)./((2^0.5) * Sigma_L);
b = (z-r)./((2^0.5) * Sigma_R);
VF = (height/2)*(erf(a)-erf(b));

end

% ------------------------------------------------------------------------


