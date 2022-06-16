function [output,sub_rough] = alloy_gold_twoGaussSam_non_polarised(params,bulk_in,bulk_out,contrast)
%CUSTOM_LAYER_THIOL_BILAYER  RASCAL Custom Layer Model File.
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
Oxide_thick = params(2);
Alloy_thick = params(3);
Alloy_rough = params(4); 
Alloy_SLD = params(5);
Gold_Thick = params(6);
Gold_SLD = params(7);
Gold_rough = params(8);
SAM_APM = params(9);
SAM_Rough = params(10);
SAM_coverage = params(11);
Acg = params(12);
Apc = params(13);
Zpc = params(14);
Tail_thick = params(15);

% Make the alloy boxes
z = 0:500;%        Range of model

% Substrate box....
sub_cen = 0;
sub_thick = 100;
VF_subs = asymconvstep(z,sub_thick,sub_cen,sub_rough,sub_rough,1);
sub_surf = sub_cen + (sub_thick/2);

% Oxide Layer
ox_cen = sub_surf + (Oxide_thick/2);
VF_ox = asymconvstep(z,Oxide_thick,ox_cen,sub_rough,sub_rough,1);
ox_surf = ox_cen + (Oxide_thick/2); 

% Alloy layer...
alloy_cen = ox_surf + (Alloy_thick/2);
VF_alloy = asymconvstep(z,Alloy_thick,alloy_cen,sub_rough,Alloy_rough,1);
alloy_surf = alloy_cen + (Alloy_thick / 2);

% Gold layers
gold_cen = alloy_surf + (Gold_Thick / 2);
VF_gold = asymconvstep(z,Gold_Thick,gold_cen,Alloy_rough,Gold_rough,1);
gold_surf = gold_cen + (Gold_Thick / 2);

% Make the sam.
SAMparams.APM = SAM_APM; 
SAMparams.Roughness = SAM_Rough;
SAMparams.coverage = SAM_coverage;
SAMparams.Position = gold_surf;
SAMparams.subRough = Gold_rough;
SAMparams.Acg = Acg;
SAMparams.Apc = Apc;
SAMparams.Zcg = 0;
SAMparams.Zpc = Zpc;
SAMparams.thickness = Tail_thick;

[sldSam,samVF,~] = SAM_twoGauss_model(z,SAMparams);

% Make the toal VF
vfTot = VF_subs + VF_ox + VF_alloy + VF_gold + samVF;

% Find the resulting water VF
vfWat = 1 - vfTot;

% Now make the SLD's
sldSub = VF_subs * 2.073e-6;
sldOx = VF_ox * 3.41e-6;
sldAlloy = VF_alloy * Alloy_SLD;
sldGold = VF_gold * Gold_SLD;
sldWater = vfWat * bulk_out(contrast);

% Find the total SLD
totSLD = sldSub + sldOx + sldAlloy + sldGold + sldSam +  sldWater;

% Put this together into an output
output = [z(:) totSLD(:)];


end

    