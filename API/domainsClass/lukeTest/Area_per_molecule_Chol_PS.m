function [output,sub_rough] = Area_per_molecule_trial(params,bulk_in,bulk_out,contrast)
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

SiO2_thickness = params(2);
SiO2_SLD = params(3);
SiO2_roughness = params(4);

Permalloy_thickness = params (5);
Permalloy_SLD = params(6);
Permalloy_roughness = params(7);

Gold_thickness = params(8);
Gold_roughness = params (9);
	
Thiol_APM = params(10);
Thiol_coverage = params(11);
Thiol_rough = params(12);

Central_water_thickness = params(13);
Central_water_roughness = params(14);

Lipid_APM = params(15);
Head_bound_waters = params(16);
Bilayer_coverage = params (17);
Bilayer_roughness = params (18);

%Known SLDs
Gold_SLD = 4.62e-6;
Central_water_SLD = 0;
Central_water_hydration = 100;

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
CH3 = (1*bc) + (1*bh);             
PO4 = (1*bp) + (4*bo);
CH2 = (1*bc) + (2*bh);
CH = (1*bc) + (1*bh);
CHOL = (5*bc) + (12*bh) + (1*bn);
H2O = (2*bh) + (1*bo);
D2O = (2*bd) + (1*bo);
OG = (2*bc) + (1*bo) + (4*bh);
OCH2 = (1*bc) + (1*bo) + (2*bh);
NH2 =  (1*bn) + (2*bh);
OH = bo + bh;
h_SER = 21.42e-5;
d_SER = 42.24e-5;
GLY_PG = GLYC + (2*bo);


%And also volumes....
vCH3 = (52.7/2);        %CH3 volume in the paper appears to be for 2* CH3's
vCH2 = 28.1;
vCOO = 39.0;
vGLYC = 68.8;
vPO4 = 53.7;
vCHOL = 120.4;
vWAT = 30.4;
vCH_CH = 42.14;
vOG = 66.4;
vOCH2 = 38.4;
vNH2 = 26; %used same as Methyl until I can find an accurate value
vSER = 99.1; % From perkins ppaers on mol vol
vOH = 22.8; %volume of water divided by the ration of water to OH to JACS 1983 105 5220 
vGLY_PG = vGLYC + (2*OH);

%SLD_chol

SLD_Cholesterol = 0.157e-6;

%Calculated Volumes from components

vSAM = (11*vCH2)+(3*vOG)+ vOH;

vHead = (0.0*(vSER + vPO4 + vGLYC + 2*vCOO))+(1.0*(vCHOL + vPO4 + vGLYC + 2*vCOO));
vTail = (28*vCH2) + vCH_CH + (2*vCH3);%Tail_volume;

%Calculate mole fraction of D2O from the bulk SLD..
Rho_d2o = 6.35e-6;
Rho_h2o = -0.56e-6;
Rho_this = bulk_out(contrast);
d2o_molfr = (Rho_this-Rho_h2o)/(Rho_d2o-Rho_h2o);

%..so use this to calculat 'average' sum_b per water molecule in bulk
sumb_Water = (d2o_molfr * D2O) + ((1-d2o_molfr)*H2O);

%Calculate sum_b's for other fragments

sumb_SAM = (11 * CH2) + (3 * OG) + OH;

sumb_Head = (1.0*(CHOL + PO4 + GLYC + 2*COO))+(0.0*(h_SER + PO4 + GLYC + 2*COO));
sumb_Tail = (28*CH2) + (2*CH) + (2*CH3);

%Need to include the number of hydrating water molecules in head sum_b
%and head volume.

%total_sumb_water = sumb_Water * Thiol_wph;
%total_vol_water = vWAT * Thiol_wph;

lipid_total_sumb_water = sumb_Water * Head_bound_waters;
lipid_total_vol_water = vWAT * Head_bound_waters;

vHead = vHead + lipid_total_vol_water;
sumb_Head = sumb_Head + lipid_total_sumb_water;

%vSAM = vSAM + total_vol_water;
%sumb_SAM = sumb_SAM + total_sumb_water; 

%Calculate SLD's and Thickness'
sldSAM = sumb_SAM/vSAM;
thickSAM = vSAM/Thiol_APM;

sldSAM = (Thiol_coverage*sldSAM) + ((1-Thiol_coverage) * bulk_out(contrast));

sldHead = sumb_Head/vHead;
thickHead = vHead/Lipid_APM;

sldTail = sumb_Tail/vTail;
thickTail = vTail/Lipid_APM;

%Now correct both the SLD's for the coverage parameter
sldTail = (Bilayer_coverage*((1.0*(sldTail))+(0.0*(SLD_Cholesterol)))) + ((1-Bilayer_coverage) * bulk_out(contrast));
sldHead = (Bilayer_coverage*sldHead) + ((1-Bilayer_coverage) * bulk_out(contrast));

% Pre-Layers

SiO2 = [SiO2_thickness SiO2_SLD SiO2_roughness 0 1];
PY = [Permalloy_thickness Permalloy_SLD Permalloy_roughness 0 1];
GOLD = [Gold_thickness Gold_SLD Gold_roughness 0 1];

% SAM
SAM = [thickSAM sldSAM Gold_roughness 0 1];

% Central water
CW = [Central_water_thickness Central_water_SLD Bilayer_roughness Central_water_hydration 1];

%Bilayer
HG = [thickHead sldHead Bilayer_roughness 0 1];
TAILS = [thickTail sldTail Bilayer_roughness 0 1];

%Bilayer



switch contrast
    case {1}
        output = [SiO2; PY; GOLD;  SAM];
    case {2}
        output = [SiO2; PY; GOLD;  SAM];  
    case {3}
        output = [SiO2; PY; GOLD;  SAM; CW; HG; TAILS;TAILS; HG];
    case {4}
        output = [SiO2; PY; GOLD;  SAM; CW; HG; TAILS;TAILS; HG];
    case {5}
        output = [SiO2; PY; GOLD;  SAM; CW; HG; TAILS;TAILS; HG];
    case {6}
        output = [SiO2; PY; GOLD;  SAM; CW; HG; TAILS;TAILS; HG];
end

sub_rough = Substrate_Roughness;
  

% resamp = 1;
% 
% switch resamp
%     case 1
%         
%         
%         if size(output,2) == 5
%             for i = 1:size(output,1);
%                 thisSLD = output(i,2);
%                 thisHydr = output(i,4)/100;
%                 thisSLD = (thisHydr*bulk_out(contrast)) + (1-thisHydr)* thisSLD;
%                 thisRough = output(i,3);
%                 newOutput(i,:) = [output(i,1) thisSLD thisRough];
%             end
%         end
%         
%         output = newOutput;
%         
%         
%         
%         [prof,subs_surface] = makeSLDProfile(bulk_in(contrast),bulk_out(contrast),Substrate_Roughness,output,size(output,1),1);
%         [xn,yn] = resample_sld(prof,1);
%         [xn,yn] = groupSamples(xn,yn,1e-9);
%         rrr = ones(length(xn),1)*1e-9;
%         output = [xn' yn' rrr];
%         
% end
% 
% sub_rough = Substrate_Roughness;
% 
% end
% %-------------------------------------------------------------------------
% function [x, y] = groupSamples(x,y,tolerance)
% 
% 
% debug = 0;
% 
% numberOfLayers = length(x);
% count = 1;
% newX = [];
% newY = [];
% 
% thisLayerx = [x(1)];
% thisLayery = [y(1)];
% try
% for i = 1:numberOfLayers-1;
%     %debug
%     diff = abs(y(i+1) - y(i));
%     if debug; fprintf('Diff:- %5.5g  y(i):- %5.3g   pos:-  %5.2f \n',diff,y(i),i);end
%     if diff <= tolerance ;
%         thisLayerx = [thisLayerx x(i)];
%         thisLayery = [thisLayery (y(i)+(diff/2))];
%     else
%         if debug; disp('grouping \n'); end
%         newX = [newX sum(thisLayerx)];
%         newY = [newY mean(thisLayery)];
%         thisLayerx = [x(i)];
%         thisLayery = [y(i)];
%     end
% end
% catch
%     [a,b] = lasterr;
%     disp('debug');
% end
% 
%     
% newX = [newX sum(thisLayerx)];
% newY = [newY mean(thisLayery)];  
%     
% x = newX;
% y = newY;
% end
% 
% %-------------------------------------------------------------------------
% 
% function [out,subs_surface] = makeSLDProfile(nbair,nbsub,ssub,layers,numberOfLayers,nrepeats);
% 
% 
% layerThicks = sum(layers(:,1));
% totalRange = layerThicks + 100;
% x = 0:totalRange;
% boxCen = 0;
% boxWidth = 100;
% boxRough = ssub;%layers(1,3);
% subBox = asymconvstep(x,boxWidth,boxCen,boxRough,boxRough,nbair);
% lastBoxEdge = boxCen + (boxWidth/2);
% lastLayRough = ssub;
% subs_surface = lastBoxEdge;
% for i = 1:numberOfLayers;
%     thisLayThick = layers(i,1);
%     thisLaySLD = layers(i,2);
%     thisLayRough = layers(i,3);
%     %             if i<numberOfLayers
%     %                 nextLayRough = layers(i+1,3);
%     %             elseif (i == numberOfLayers)
%     %                 nextLayRough = layers(i,3);
%     %             end
%     thisBoxCentre = lastBoxEdge + (thisLayThick/2);
%     Lays(:,i) = asymconvstep(x,thisLayThick,thisBoxCentre,lastLayRough,thisLayRough,thisLaySLD);
%     lastBoxEdge = thisBoxCentre + (thisLayThick/2);
%     lastLayRough = thisLayRough;
% end
% thisLayThick = (x(end)-lastBoxEdge)*2;
% thisLaySLD = nbsub;
% thisLayRough = lastLayRough;
% nextLayRough = lastLayRough;
% thisBoxCentre = x(end);
% Lays(:,(numberOfLayers+1)) = asymconvstep(x,thisLayThick,thisBoxCentre,thisLayRough,nextLayRough,thisLaySLD);
% 
% SLD = sum(Lays,2);
% 
% SLD = SLD(:) + subBox(:);
% 
% out = [x(:),SLD(:)];
% 
% 
% end
% 
% 
% function [x_new_tot,y_new_tot] = resample_sld(sld,y_min_step);
% 
% x = sld(:,1);
% prof = sld(:,2);
% 
% 
% thisx = x(1);
% count = 1;
% i = 2;
% while i < length(x);
%     this_step = prof(i) - prof(i-1);
%     if abs(this_step) < y_min_step;
%         %Keep original points
%         x_new(count) = x(i);
%         y_new(count) = prof(i);
%         count = count + 1;
%         i = i + 1;
%     else
%         if this_step > 0
%             newsteps = prof(i-1):y_min_step:prof(i);
%         else
%             newsteps = prof(i-1):-y_min_step:prof(i);
%         end
%         new_xs = interp1(prof(i-1:i),x(i-1:i),newsteps);
%         x_new = [x_new new_xs];
%         y_new = [y_new newsteps];
%         count = length(x_new);
%         i = i + 1;
%     end
% end
% %x_new_tot = x_new(:);
% %y_new_tot = y_new(:);
% 
% %Make it into a 'histogram'
% for i =1:length(x_new)-1;
%     x_new_tot(i) = x_new(i + 1) - x_new(i);
%     y_new_tot(i) = y_new(i);
% end
% 
% 
% %Remove any zero thickness layers...
% good_layers = find(x_new_tot ~= 0);
% x_new_tot = x_new_tot(good_layers);
% y_new_tot = y_new_tot(good_layers);
% 
% 
% end
%     
