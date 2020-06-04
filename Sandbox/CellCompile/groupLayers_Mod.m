function [outLayers, outSsubs] = groupLayers_Mod(allLayers,allRoughs,geometry,nbair,nbsubs)

%Arrange layers according to geometry and apply any coberage correction.
%
%[outLayers, outSsubs] = groupLayers_Mod(allLayers,allRoughs,numberOfContrasts,geometry,nbairs,nbsubs)
% Inputs:
%     allLayers = cell array, one for each contrast. Each cell is the 
%                 list of layer values for each contrast.
%                 e.g. allLayers{1} = [d1, rho1, r1, %hyd, hyd_which
%                                      d2, rho2, r2, %hyd2, hyd_which_2..
%                                      etc]
%     allRoughs = Double of substrate roughness for each contrast.
%     numberOfContrasts = double.
%     geometry =  'Air / Liquid (or solid)' or 'Solid / Liquid'
%     nbairs = vector of nbair values.
%     nbsubs = vector of nbsub values.
%
% Outputs:
%     outLayers = cell array of layers param values for each contrast.
%                 e.g. outLayers{1} = [d1 rho1 r1;
%                                      d2 rho2 r2
%                                      ... etc   ]
%     outSsubs = vector of substrate roughness values.
%

global RAT_DEBUG DEBUGVARS

%outLayers = cell(1,numberOfContrasts);
%outSsubs = zeros(1,numberOfContrasts);


%for i = 1:numberOfContrasts
    output = allLayers;
    s_sub = allRoughs;
    outSsubs = allRoughs;
    layers = [];
    if ~isempty(output)
        switch geometry
            case 'Air / Liquid (or solid)'
                layers = output;
                %s_sub = rsub;
            case 'Solid / Liquid'
                roughs = output(:,3);
                sldss = output(:,2);
                thicks = output(:,1);
                rsub = roughs(end);
                roughs = [s_sub ; roughs(1:end-1)];
                n = size(output);
                if n(2) == 5
                    cov = output(:,4);
                    layers = [thicks(:) sldss(:) roughs(:) cov(:)];
                else
                    layers = [thicks(:) sldss(:) roughs(:)];
                end
                s_sub = rsub;
        end
        
        %Deal with the %coverage if present
        n = size(output);
        if n(2) == 5
            for j = 1:n(1)
                this_pcw = output(j,4);
                if output(j,5) == 1
                    pc_add = nbsubs;
                else
                    pc_add = nbair;
                end
                if ~isnan(this_pcw)
                    layers(j,2) = pc_add*(this_pcw/100) + (1-(this_pcw/100))*layers(j,2);
                end
            end
        end 
    end
%     problem.layers{i} = layers;
%     problem.ssubs(i) = s_sub;
outLayers = layers(:,1:3);
outSsubs = s_sub;


end


%end
    