function [output,sub_rough] = volume_thiolsam_plus_DPPC_polarised_abs(params,bulk_in,bulk_out,contrast)
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


Substrate_Roughness	= params(1);
Alloy_Thick	 = params(2); 
Alloy_SLD_up = params(3);
Alloy_iSLD_up = params(4);
Alloy_SLD_down = params(5);
Alloy_iSLD_down = params(6);
Alloy_Rough = params(7);	
Gold_Thick = params(8); 	
Gold_Rough = params(9);	
Gold_SLD = params(10);
Gold_iSLD = params(11);
Thiol_APM = params(12);
Thiol_head_hydr = params(13);   
Thiol_coverage = params(14);
Cw_thick = params(15);
Bilayer_APM = params(16);
Bil_head_hydr = params(17);
Bilayer_rough = params(18);
Bilayer_coverage = params(19);

% Make the metal layers
GOLD = [Gold_Thick Gold_SLD Gold_iSLD Gold_Rough];
ALLOY_UP = [Alloy_Thick Alloy_SLD_up Alloy_iSLD_up Alloy_Rough];
ALLOY_DOWN = [Alloy_Thick Alloy_SLD_down Alloy_iSLD_down Alloy_Rough];

%Neutron b's..
%define all the neutron b's.
bc = 0.6646e-4;     %Carbon
bo = 0.5843e-4;     %Oxygen
bh = -0.3739e-4;	%Hydrogen
bp = 0.513e-4;      %Phosphorus
bn = 0.936e-4;      %Nitrogen
bd = 0.6671e-4;     %Deuterium

%Work out the total scattering length in each fragment....
%Define scattering lengths..
%Hydrogenated version....
COO = (2*bo) + (bc);
GLYC = (3*bc) + (5*bh);
CH3 = (1*bc) + (3*bh);             
PO4 = (1*bp) + (4*bo);
CH2 = (1*bc) + (2*bh);
CH = (1*bc) + (1*bh);
CHOL = (5*bc) + (12*bh) + (1*bn);
H2O = (2*bh) + (1*bo);
D2O = (2*bd) + (1*bo);

%And also volumes....
vCH3 = 52.7;        %CH3 volume in the paper appears to be for 2* CH3's
vCH2 = 28.1;
vCOO = 39.0;
vGLYC = 68.8;
vPO4 = 53.7;
vCHOL = 120.4;
vWAT = 30.4;
vCH_CH = 42.14;

vHead = vCHOL + vPO4 + vGLYC + 2*vCOO;
vTail = (28*vCH2) + (1*vCH_CH) + (2*vCH3);%Tail_volume;

% %Calculate mole fraction of D2O from the bulk SLD..
% Rho_d2o = 6.35e-6;
% Rho_h2o = -0.56e-6;
% Rho_this = bulk_out(contrast);
% d2o_molfr = (Rho_this-Rho_h2o)/(Rho_d2o-Rho_h2o);
% 
% %..so use this to calculat 'average' sum_b per water molecule in bulk
% sumb_Water = (d2o_molfr * D2O) + ((1-d2o_molfr)*H2O);

%Calculate sum_b's for other fragments
sumb_Head = CHOL + PO4 + GLYC + 2*COO;
sumb_Tail = (28*CH2) + (2*CH) + 2*CH3;

%Calculate SLD's and Thickness'
sldHead = sumb_Head/vHead;
thickHead = vHead/Thiol_APM;

sldTail = sumb_Tail/vTail;
thickTail = vTail/Thiol_APM;

% Correct head SLD based on hydration
Thiol_head_hydr = Thiol_head_hydr/100;
sldHead = (sldHead * (1 - Thiol_head_hydr) +  (Thiol_head_hydr * bulk_out(contrast)));

%Now correct both the SLD's for the coverage parameter
sldTail = (Thiol_coverage*sldTail) + ((1-Thiol_coverage) * bulk_out(contrast));
sldHead = (Thiol_coverage*sldHead) + ((1-Thiol_coverage) * bulk_out(contrast));

SAMTAILS = [thickTail sldTail 0 Gold_Rough];
SAMHEAD = [thickHead sldHead 0 Gold_Rough];

%Now do the same for the bilayer
vHead = vCHOL + vPO4 + vGLYC + 2*vCOO;
vTail = (28*vCH2);% + (2*vCH3);%Tail_volume;
vMe = (2*vCH3);

sumb_Head = CHOL + PO4 + GLYC + 2*COO;
sumb_Tail = (28*CH2);% + 2*CH3;
sumb_Me = 2*CH3;

% total_sumb_water = sumb_Water * Bilayer_wph;
% total_vol_water = vWAT * Bilayer_wph;
% 
% vHead = vHead + total_vol_water;
% sumb_Head = sumb_Head + total_sumb_water;


sldHead = sumb_Head/vHead;
thickHead = vHead/Bilayer_APM;
Bil_head_hydr = Bil_head_hydr / 100;
sldHead = (sldHead * (1 - Bil_head_hydr) +  (Bil_head_hydr * bulk_out(contrast)));

sldTail = sumb_Tail/vTail;
thickTail = vTail/Bilayer_APM;
%thickTail = thickTail*cosd(tilt);

sldMe = sumb_Me/vMe;
thickMe = vMe/Bilayer_APM;

sldTail = (Bilayer_coverage*sldTail) + ((1-Bilayer_coverage) * bulk_out(contrast));
sldHead = (Bilayer_coverage*sldHead) + ((1-Bilayer_coverage) * bulk_out(contrast));
sldMe = (Bilayer_coverage*sldMe) + ((1-Bilayer_coverage) * bulk_out(contrast));

BILTAILS = [thickTail sldTail 0 Bilayer_rough];
BILHEAD = [thickHead sldHead 0 Bilayer_rough];
BILME = [thickMe sldMe 0 Bilayer_rough];

BILAYER = [BILHEAD ; BILTAILS ; BILME; BILME ; BILTAILS ; BILHEAD];

CW = [Cw_thick bulk_out(contrast) 0 Bilayer_rough];


switch contrast
    case{2,4}
        output = [ALLOY_UP; GOLD; SAMTAILS; SAMHEAD ; CW ; BILAYER] ;
    otherwise
        output = [ALLOY_DOWN; GOLD; SAMTAILS; SAMHEAD ; CW ; BILAYER] ;
end

sub_rough = Substrate_Roughness;

