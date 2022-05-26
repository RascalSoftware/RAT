function output = newModelBilayer(params,bulk_in,bulk_out,contrast)

bd = 0.6671e-4;	%Deuterium
bo = 0.5843e-4;	%Oxygen
bh = -0.3739e-4;	%Hydrogen
D2O = (2*bd) + (1*bo);
H2O = (2*bh) + (1*bo);

subrough = params(1);
ox_thick = params(2);
oxHydration = params(3);
samAPM = params(4);
samRough = params(5);
samLength = params(6);
bilayerPos = params(7);
bilayerAPM = params(8);
%bilayerLength = params(9);5
bilayerRough = params(10);
methylOffset = 3;%params(11);
bil_coverage = params(11);
sam_coverage = params(12);

sldwat = bulk_out(contrast);
d2o_molfr = (1/D2O-H2O)*((sldwat/0.036182336306)-H2O);

x = 1:200;
%Substrate and Oxide
%Make a substrate bit...
subcen = 0;
subs = convstep(x,50,0,subrough,1);
subs_edge = 25;
ox_surf = subs_edge + ox_thick;
ox = convstep(x,ox_thick,(subs_edge + (ox_thick/2)),subrough,1);

%monolayer
APM = samAPM; %48;
length = samLength;%16;
roughness = samRough;%3;
direction = 1;
carbons = 16;
[SLDmon,vfTotMon] = lipid(x,ox_surf,APM,length,roughness,direction,carbons,sam_coverage); %top lipid


%Bilayer
position = bilayerPos;%130;
APM = bilayerAPM;%68;
chainsVolume = 892.8;
length = chainsVolume/APM;
roughness = bilayerRough;%3;
direction = 1;
carbons = 16;

[SLD,vfTot] = lipid(x,position,APM,length,roughness,direction,carbons,bil_coverage); %top lipid
[SLD2,vfTot2] = lipid(x,position-methylOffset,APM,length,roughness,-direction,carbons,bil_coverage); %bottom lipid


%SLD
ox_scat_length = (oxHydration * sldwat) + ((1 - oxHydration) * 3.41e-6);
SLDox = ox * ox_scat_length;
SLDsub = subs * 2.07e-6;

vfWat = ones(size(vfTot,1),1);
vfWat = vfWat - vfTot - vfTot2 - subs - ox - vfTotMon;
ndWat = vfWat/30.13;
sldWat = ndWat * ((d2o_molfr * D2O) + (1 - d2o_molfr)*H2O);

% figure(2)
% hold off
% plot(x,SLDsub,'k-');
% hold on
% plot(x,SLDox,'r-');
% plot(x,SLDmon,'g-');
% plot(x,SLD,'m-');
% plot(x,SLD2,'m-');
% plot(x,sldWat,'b-');

less = sldWat < 0;
sldWat(less) = 0;

sldTot = SLD + SLD2 + SLDox + SLDsub + SLDmon + sldWat;

% figure (1);
% clf
% plot(x,sldTot,'k-');


output = [x(:) sldTot(:)];
% hold on
% plot(x,sldWat,'b-');
% hold off



%-------------------------------------------------------------------------

function [SLD,vfTot] = lipid(x,position,APM,alklength,Roughness,direction,carbons,coverage)


%define all the neutron b's.
bc = 0.6646e-4;	%Carbon
bo = 0.5843e-4;	%Oxygen
bh = -0.3739e-4;	%Hydrogen
bp = 0.513e-4;	%Phosphorus
bn = 0.936e-4;	%Nitrogen
bd = 0.6671e-4;	%Deuterium

%Work out the total scattering length in each fragment....
COO = (4*bo) + (2*bc);
GLYC = (3*bc) + (5*bh);
CH3 = (2*bc) + (6*bh);             
PO4 = (1*bp) + (4*bo);
CH2 = (2*bc) + (4*bh);
H2O = (2*bh) + (1*bo);
D2O = (2*bd) + (1*bo);
CHOL = (5*bc) + (13*bh) + (1*bn);

%Define volumes....
Vcoo = 44.09;		%Carboxy group..
Vglyc = 63.59;		%Glycerol group
Vpo4 = 65.63;		%Phospho group..
Vchol = 108.6;	%Choline group	
Vwat = 30.18;	%Water molecule
Vch3 = 53.6;      %Methyl group
Vch2 = 27.9;    %Methylene group

%and intrinsic roughness'
Ach3 = 2.95;
Acoo = 2.73;
Aglyc = 2.37;
Apo4 = 3.08;
Achol = 3.48;
Ach2 = 3;

%Include a general bilayer roughness
%Use R = sqrt(i2 + r2)
Roughness = Roughness^2;
Ach3 = sqrt(Ach3^2 + Roughness);
Acoo = sqrt(Acoo^2 + Roughness);
Aglyc = sqrt(Aglyc^2 + Roughness);
Apo4 = sqrt(Apo4^2 + Roughness);
Achol = sqrt(Achol^2 + Roughness);
Ach2 = sqrt(Ach2^2 + Roughness);

%Each gaussian has a height of 1...
ncoo = 1;	%i.e there's 1 coo fragment, 1 glyc fragment etc..
nglyc = 1;
npo4 = 1;
nchol = 1;
nch3 = 1; 


%-----------------------------------------------------
%
%                       Chains
%
%------------------------------------------------------

%construct the alkyl chain out of a series of Gaussians
nCh2 = carbons-2;  
step = alklength/nCh2;    
num = 1;
nAlks = alklength/step;
alk = zeros(length(x),nAlks);
for i = 1:step:alklength
    alk(:,num) = gssian(x,(position+(i*direction)),1,Ach2);
    num = num + 1;
end

%'alk' is the number of 'molecules' per unit
%length. To get per unit volume we divide by
%the APM. Number per unit volume will be
%the NUMBER DENSITY
nDalk = alk ./ APM;

%Now, we need to calculate a volume fraction
%i.e. a dimensionless quantity between 0 and 1.
%We just multiply the number density by the component vol
vfalk = nDalk .* (2*Vch2);    %Dimensionless since ≈3 * ≈-3

% %..can then calculate for water
% vfwat = ones(size(vfalk,1),1);
% for i = 1:size(alk,2)
%     vfwat = vfwat-vfalk(:,i);
% end;
% nDwat = vfwat / Vwat;


%***********************************************************%
%                                                           %
%                   Headgroup                               %
%                                                           %
%************************************************************

%Define centre positions
Zcoo = position + (alklength*direction);   
Zglyc = Zcoo + (2.7*direction);
Zpo4 = Zcoo + (4.22*direction);
Zchol = Zcoo + (5.96*direction); 
Zch3 = position;

%Make gaussians 
nGcoo = gssian(x,Zcoo,ncoo,Acoo);
nGglyc = gssian(x,Zglyc,nglyc,Aglyc);
nGpo4 = gssian(x,Zpo4,npo4,Apo4);
nGchol = gssian(x,Zchol,nchol,Achol);
nGch3 = gssian(x,Zch3,nch3,Ach3);

%Gaussians are number of 'molecules' per unit
%length. To get per unit volume we divide by
%the APM. Number per unit volume will be
%the NUMBER DENSITY
nDGcoo = nGcoo / APM;
nDGglyc = nGglyc / APM;
nDGpo4 = nGpo4 / APM;
nDGchol = nGchol / APM;
nDGch3 = nGch3 / APM;

%Now, we need to calculate a volume fraction
%i.e. a dimensionless quantity between 0 and 1.
%We just multiply by the component vols
vfGcoo = nDGcoo * Vcoo;    %...these are now dimensionless
vfGglyc = nDGglyc * Vglyc; %since ≈3 * ≈-3
vfGpo4 = nDGpo4 * Vpo4;
vfGchol = nDGchol * Vchol;
vfGch3 = nDGch3 * (2*Vch3);


%------------------------------------------------------------
%
%               Scattering Length Density
%
%-------------------------------------------------------------
%In each case, the SLD is the number density times sum b....
sld_coo = nDGcoo * COO;
sld_glyc = nDGglyc * GLYC;
sld_po4 = nDGpo4 * PO4;
sld_chol = nDGchol * CHOL;
sld_ch3 = nDGch3 * CH3;
sldAlk = nDalk .* CH2;
sldChain = sum(sldAlk,2);
SLD = sld_coo + sld_glyc + sld_po4 + sld_chol + sld_ch3 + sldChain';

%--------------------------------------------------------------
%
%               Free volume calculation
%
%---------------------------------------------------------------
vfHead = vfGcoo + vfGglyc + vfGpo4 + vfGchol + vfGch3; 
vfTail = sum(vfalk,2);
vfTot = vfHead + vfTail';
%Try scaling for coverage
vfTot = vfTot * coverage;
SLD = SLD * coverage;

%-------------------------------------------------------------------------
function f = gssian(z,Z,N,A)
%f(z) = gaussian(z,Z,N,A)
%
%	produces a gaussian at centre Z, of height
%	N and 1/e half width of A.

pi = 3.142;
%a = A*sqrt(2*pi);
f = (N/(A*sqrt(pi)))*exp(-((z-Z).^2)/(A^2));

%-------------------------------------------------------------------------

function f = convstep(x,xw,xcen,s,h)
% Produces a step function convoluted with an error function
% Convstep [x,xw,xcen,s,h]
%       x = vector of x values
%      xw = Width of step function
%    xcen = Centre point of step function
%       s = Roughness parameter
%       h = Height of step function.


r = xcen + (xw/2);
l = xcen - (xw/2);

a = (x-l)./((2^0.5)*s);
b = (x-r)./((2^0.5)*s);

f = (h/2)*(erf(a)-erf(b));
