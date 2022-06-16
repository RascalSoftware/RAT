

addpath('/Users/arwel/Dropbox/ALC_project_Hub/New_Stuff/MD_bilayers_work/Fits_and_Sims/Fits/functions');

sub_rough = 3;
Oxide_thick = 10;
Oxide_hydr = 0.3;
Alloy_thick = 150;
Alloy_rough = 5; 
Alloy_SLD_up = 9e-6;
Gold_Thick = 150;
Gold_SLD = 4.5e-6;
Gold_rough = 5;
SAM_APM = 60;
SAM_Rough = 3;
SAM_coverage = 1;
Acg = 3;
Apc = 3;
Zpc = 5;
Tail_thick = 18;
Alloy_SLD_down = 7e-6;

params = [sub_rough;
Oxide_thick;
Oxide_hydr;
Alloy_thick;
Alloy_rough; 
Alloy_SLD_up;
Gold_Thick;
Gold_SLD;
Gold_rough;
SAM_APM;
SAM_Rough;
SAM_coverage;
Acg;
Apc;
Zpc;
Tail_thick;
Alloy_SLD_down];


bulk_in = 2.073e-6;
bulk_out = -0.56e-6;
contrast = 1;

sld_d1 = customModelWrapper(params,bulk_in,bulk_out,contrast,1);
sld_d2 = customModelWrapper(params,bulk_in,bulk_out,contrast,2);



figure(1); clf;
plot(sld_d1(:,1),sld_d1(:,2));
hold on
plot(sld_d2(:,1),sld_d2(:,2));



