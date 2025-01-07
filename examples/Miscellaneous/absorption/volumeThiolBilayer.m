function [output,subRough] = volumeThiolBilayer(params,bulkIn,bulkOut,contrast)
% volumeThiolBilayer  RASCAL Custom Layer Model File. 
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


subRough = params(1);
alloyThick = params(2); 
alloySLDUp = params(3);
alloyISLDUp = params(4);
alloySLDDown = params(5);
alloyISLDDown = params(6);
alloyRough = params(7);
goldThick = params(8); 
goldRough = params(9);	
goldSLD = params(10);
goldISLD = params(11);
thiolAPM = params(12);
thiolHeadHydr = params(13);
thiolCoverage = params(14);
cwThick = params(15);
bilayerAPM = params(16);
bilHeadHydr = params(17);
bilayerRough = params(18);
bilayerCoverage = params(19);

% Make the metal layers
GOLD = [goldThick goldSLD goldISLD goldRough];
alloyUp = [alloyThick alloySLDUp alloyISLDUp alloyRough];
alloyDown = [alloyThick alloySLDDown alloyISLDDown alloyRough];

%Neutron b's..
%define all the neutron b's.
bc = 0.6646e-4;     %Carbon
bo = 0.5843e-4;     %Oxygen
bh = -0.3739e-4;    %Hydrogen
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
vCHCH = 42.14;

vHead = vCHOL + vPO4 + vGLYC + 2*vCOO;
vTail = (28*vCH2) + (1*vCHCH) + (2*vCH3);  % Tail_volume;

% %Calculate mole fraction of D2O from the bulk SLD..
% Rho_d2o = 6.35e-6;
% Rho_h2o = -0.56e-6;
% Rho_this = bulkOut(contrast);
% d2o_molfr = (Rho_this-Rho_h2o)/(Rho_d2o-Rho_h2o);
% 
% %..so use this to calculate 'average' sum_b per water molecule in bulk
% sumb_Water = (d2o_molfr * D2O) + ((1-d2o_molfr)*H2O);

%Calculate sum_b's for other fragments
sumbHead = CHOL + PO4 + GLYC + 2*COO;
sumbTail = (28*CH2) + (2*CH) + 2*CH3;

%Calculate SLD's and Thickness'
sldHead = sumbHead/vHead;
thickHead = vHead/thiolAPM;

sldTail = sumbTail/vTail;
thickTail = vTail/thiolAPM;

% Correct head SLD based on hydration
thiolHeadHydr = thiolHeadHydr/100;
sldHead = (sldHead * (1 - thiolHeadHydr) +  (thiolHeadHydr * bulkOut(contrast)));

%Now correct both the SLD's for the coverage parameter
sldTail = (thiolCoverage*sldTail) + ((1-thiolCoverage) * bulkOut(contrast));
sldHead = (thiolCoverage*sldHead) + ((1-thiolCoverage) * bulkOut(contrast));

SAMTAILS = [thickTail sldTail 0 goldRough];
SAMHEAD = [thickHead sldHead 0 goldRough];

%Now do the same for the bilayer
vHead = vCHOL + vPO4 + vGLYC + 2*vCOO;
vTail = (28*vCH2);% + (2*vCH3);%Tail_volume;
vMe = (2*vCH3);

sumbHead = CHOL + PO4 + GLYC + 2*COO;
sumbTail = (28*CH2);% + 2*CH3;
sumbMe = 2*CH3;

% total_sumb_water = sumb_Water * Bilayer_wph;
% totalVolWater = vWAT * Bilayer_wph;
% 
% vHead = vHead + totalVolWater;
% sumbHead = sumbHead + total_sumb_water;


sldHead = sumbHead/vHead;
thickHead = vHead/bilayerAPM;
bilHeadHydr = bilHeadHydr / 100;
sldHead = (sldHead * (1 - bilHeadHydr) +  (bilHeadHydr * bulkOut(contrast)));

sldTail = sumbTail/vTail;
thickTail = vTail/bilayerAPM;
%thickTail = thickTail*cosd(tilt);

sldMe = sumbMe/vMe;
thickMe = vMe/bilayerAPM;

sldTail = (bilayerCoverage*sldTail) + ((1-bilayerCoverage) * bulkOut(contrast));
sldHead = (bilayerCoverage*sldHead) + ((1-bilayerCoverage) * bulkOut(contrast));
sldMe = (bilayerCoverage*sldMe) + ((1-bilayerCoverage) * bulkOut(contrast));

BILTAILS = [thickTail sldTail 0 bilayerRough];
BILHEAD = [thickHead sldHead 0 bilayerRough];
BILME = [thickMe sldMe 0 bilayerRough];

BILAYER = [BILHEAD ; BILTAILS ; BILME; BILME ; BILTAILS ; BILHEAD];

CW = [cwThick bulkOut(contrast) 0 bilayerRough];


switch contrast
    case{2,4}
        output = [alloyUp; GOLD; SAMTAILS; SAMHEAD ; CW ; BILAYER];
    otherwise
        output = [alloyDown; GOLD; SAMTAILS; SAMHEAD ; CW ; BILAYER];
end
end
