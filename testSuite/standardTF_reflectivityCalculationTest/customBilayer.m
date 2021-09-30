function [output,sub_rough] = customBilayer(params,bulk_in,bulk_out,contrast)
%CUSTOMBILAYER  RASCAL Custom Layer Model File.
%
%
% This file accepts 3 vectors containing the values for
% Params, bulk in and bulk out
% The final parameter is an index of the contrast being calculated
% The m-file should output a matrix of layer values, in the form..
% Output = [thick 1, SLD 1, Rough 1, Percent Hydration 1, Hydrate how 1
%           ....
%           thick n, SLD n, Rough n, Percent Hydration n, Hydration how n]
% The "hydrate how" parameter decides if the layer is hydrated with
% Bulk out or Bulk in phases. Set to 1 for Bulk out, zero for Bulk in.
% Alternatively, leave out hydration and just return..
% Output = [thick 1, SLD 1, Rough 1,
%           ....
%           thick n, SLD n, Rough n] };
% The second output parameter should be the substrate roughness

sub_rough = params(1);
oxide_thick = params(2);
oxide_hydration = params(3);
lipidAPM = params(4);
headHydration = params(5);
bilayerHydration = params(6);
bilayerRough = params(7);
waterThick = params(8);


% We have a constant SLD for the bilayer
oxide_SLD = 3.41e-6;

% Now make the lipid layers..
% Use known lipid volume and compositions
% to make the layers

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

% we use the volumes to calculate the SLD's
SLDhead = Head / vHead;
SLDtail = Tails / vTail;

% We calculate the layer thickness' from
% the volumes and the APM...
headThick = vHead / lipidAPM;
tailThick = vTail / lipidAPM;

% Manually deal with hydration for layers in
% this example.
oxSLD = (oxide_hydration * bulk_out(contrast)) + ((1 - oxide_hydration) * oxide_SLD);
headSLD = (headHydration * bulk_out(contrast)) + ((1 - headHydration) * SLDhead);
tailSLD = (bilayerHydration * bulk_out(contrast)) + ((1 - bilayerHydration) * SLDtail);

% Make the layers
oxide = [oxide_thick oxSLD sub_rough];
water = [waterThick bulk_out(contrast) bilayerRough];
head = [headThick headSLD bilayerRough];
tail = [tailThick tailSLD bilayerRough];

output = [oxide ; water ; head ; tail ; tail ; head];



