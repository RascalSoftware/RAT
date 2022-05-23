function [totalSLD,totalProb,Zpc] = SAM_twoGauss_model(x,params)
% Gaussion model for the thiilipid SAM two Gaussians for the SAM headgroup.

debug = 0;

APM = params.APM; 
roughness = params.Roughness;
coverage = params.coverage;
position = params.Position;
subRough = params.subRough;
Acg = params.Acg;
Apc = params.Apc;
Zcg = 0;
Zpc = params.Zpc;
thickness = params.thickness;

Acg = sqrt(Acg^2 + roughness^2);
Apc = sqrt(Apc^2 + roughness^2);

ncg = 1;	
npc = 1;

%Define volumes....   Oxford.....
% Vcoo = 62.56;		%Carboxy group..
% Vglyc = 61.83;		%Glycerol group
% Vpo4 = 11.24;		%Phospho group..
% Vchol = 180.54;     %Choline group
% Vwat = 31.716;      %Water molecule
% Vch2 = 28.14;       %Methylene group
% Vch3 = 59.4;        %Methyl group
% Vcg = Vcoo + Vglyc;
% Vpc = Vpo4 + Vchol;

%Define volumes....   Armen.....
Vcoo = 39.4;		%Carboxy group..
Vglyc = 68.83;		%Glycerol group
Vpo4 = 53.7;		%Phospho group..
Vchol = 120.4;      %Choline group
Vwat = 31.716;      %Water molecule
Vch2 = 28.14;       %Methylene group
Vch3 = 59.4;        %Methyl group
Vcg = Vcoo + Vglyc;
Vpc = Vpo4 + Vchol;

%tail_thickness = (28 * Vch2)/APM;
%thickness = tail_thickness + (0.5*((ncg*Vcg)/APM));

Zcg = thickness + (0.25*((ncg*Vcg)/APM));%Zcg;
Zpc = Zpc + Zcg;

%Now make probabilities....
nCG = Gaussian(x,position+Zcg,ncg,Acg);
nPC = Gaussian(x,position+Zpc,npc,Apc);

%Number densities
ndCG = nCG / APM;
ndPC = nPC / APM;

%Probabilities
pCG = ndCG * Vcg;
pPC = ndPC * Vpc;

zAlkRight = (position+thickness) - 0.5*(Vcg/APM);
zAlkLeft = position;
alkWidth = zAlkRight - zAlkLeft;
pALK = asymconvstep(x,alkWidth,(position + alkWidth/2),subRough,Acg,1);
ndALK = pALK / Vch2;
totalProb = pCG + pPC + pALK;
pWAT = 1 - totalProb;


%Scattering length density
bc = 0.6646e-4;	%Carbon
bo = 0.5843e-4;	%Oxygen
bh = -0.3739e-4;	%Hydrogen
bp = 0.513e-4;	%Phosphorus
bn = 0.936e-4;	%Nitrogen
bd = 0.6671e-4;	%Deuterium

%Work out the total scattering length in each fragment....
COO = (2*bo) + (1*bc);
GLYC = (3*bc) + (5*bh);
CH3 = (1*bc) + (3*bh);              
PO4 = (1*bp) + (4*bo);
CH2 = (1*bc) + (2*bh);
H2O = (2*bh) + (1*bo);
D2O = (2*bd) + (1*bo);
CHOL = (5*bc) + (13*bh) + (1*bn);

CG = COO + GLYC;
PC = PO4 + CHOL;

sldCG = ((ncg * CG) * pCG) / (ncg * Vcg);
sldPC = ((npc * PC) * pPC) / (npc * Vpc);
sldALK = (CH2 * pALK) / Vch2;
totalSLD = sldCG + sldPC + sldALK;

totalSLD = totalSLD * coverage;
totalProb = totalProb * coverage;

% %Calculate the extra fitness....
% val_lowZ = Zcg - 10;
% val_hiZ = Zcg + 20;
% ranLo = find(x<val_lowZ, 1, 'last' );
% if isempty(ranLo)
%     ranLo = 1;
% end
% ranHi = find(x>val_hiZ, 1 );
% list = totalProb(ranLo:ranHi);
% over = find(list>1);
% if ~isempty(over)
%     totOver = sum(list(over)-1)^2;
% else
%     totOver = 0;
% end
% N = length(list);
% X = (1/N)*totOver;
% 
% D = 800;
% if X~=0
%     xtraF = exp(D*X);
% else
%     xtraF = 0;
% end

switch debug
    case 1
        figure(1)
        clf
        wid = 1.5;
        figure(1); hold on; 
        plot(x,pALK,'r--','LineWidth',wid)
        plot(x,pCG,'m--','LineWidth',wid);
        plot(x,pPC,'c--','LineWidth',wid);
       % plot(x,pWAT,'b-','LineWidth',wid);
        plot(x,totalProb,'k--','LineWidth',2.0);
        %xlim([0 60]);
        
        figure(2); clf; hold on   
        wid = 1;
        plot(x,sldALK,'r-','LineWidth',wid);
        plot(x,sldCG,'m-','LineWidth',wid);
        plot(x,sldPC,'c-','LineWidth',wid);
        plot(x,totalSLD,'k-','LineWidth',wid);  
end

end