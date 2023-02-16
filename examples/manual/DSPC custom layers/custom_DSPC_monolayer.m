function [output,subRough] = custom_DSPC_monolayer(params,bulkIn,bulkOut,contrast)


% Split up the input params array
% because it's convenient to do so
subRough = params(1);
lipidAPM = params(2);
Head_Hydration = params(3);
Head_roughness = params(4);
Tail_roughness = params(5);
tailThick = params(6);

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

% Now make the lipid groups (note that we need 
% both deuterated and hydrogenated versions)
COO = (4*bo) + (2*bc);
GLYC = (3*bc) + (5*bh);
dGLYC = (3*bc) + (5*bd);
CH3 = (2*bc) + (6*bh); 
dCH3 = (2*bc) + (6*bd); 
PO4 = (1*bp) + (4*bo);
CH2 = (1*bc) + (2*bh);
dCH2 = (1*bc) + (2*bd);
CHOL = (5*bc) + (12*bh) + (1*bn);
dCHOL = (5*bc) + (12*bd) + (1*bn);

% Group these into heads and tails:
Head = CHOL + PO4 + GLYC + COO;         % Hydrogenated head
dHead = dCHOL + PO4 + dGLYC + COO;      % Deuterated head
Tails = (34*CH2) + (2*CH3);             % Hydrogenated tail
dTails = (34*dCH2) + (2*dCH3);          % Deuterated tail

% We need volumes for each.
% Use literature values:
vHead = 320;
vTail = 1005;

% we use the volumes to calculate the SLD's
SLD_head = Head / vHead;
SLD_dHead = dHead / vHead;
SLD_tail = Tails / vTail;
SLD_dTail = dTails / vTail;

% We calculate the layer thickness' from
% the volumes and the APM...
headThick = vHead / lipidAPM;
%tailThick = vTail / lipidAPM;

% In this example we manually apply the head hydration 
% by correcting the SLD based on coverage. Coverage is
% a parameter between 0 and 1, so we can just scale the
% SLD linearly depending on coverage value, using 
% the appropriate value for bulk_out for each contrast
H_headSLD = (Head_Hydration * bulkOut(contrast)) + ((1 - Head_Hydration) * SLD_head);
D_headSLD = (Head_Hydration * bulkOut(contrast)) + ((1 - Head_Hydration) * SLD_dHead);

% Now we need to build up the layers. We use the 'contrast'
% input parameter to determine whether we need to use
% deuterated or hydrogenated versions of the two layers.
switch contrast
    case 1
        % Deuterated tail and hydrogenated head
        thisHeadSLD = H_headSLD;
        thisTailSLD = SLD_dTail;
    case 2
        % Hydrogenated tail and deuterated head
        thisHeadSLD = D_headSLD;
        thisTailSLD = SLD_tail;
end

% Put the layers together
head_layer = [headThick thisHeadSLD Head_roughness];
tail_layer = [tailThick thisTailSLD Tail_roughness];

output = [tail_layer ; head_layer];

end
