function [outLayers, outSsubs] = groupLayersMod(allLayers,allRoughs,geometry,nbair,nbsubs)
%Arrange layers according to geometry and apply any coverage correction.
%
% USAGE::
%
%     [outLayers, outSsubs] = groupLayersMod(allLayers,allRoughs,numberOfContrasts,geometry,nbairs,nbsubs)
%
% INPUTS:
%
%     * allLayers =         cell array, one for each contrast. Each cell is the list of layer values for each contrast.
%     * allRoughs =         Double of substrate roughness for each contrast.
%     * numberOfContrasts = double.
%     * geometry =          'Air / Liquid (or solid)' or 'Solid / Liquid'
%     * nbairs =            vector of nbair values.
%     * nbsubs =            vector of nbsub values.
%
%     The paratt calculation procedds through the 
%     z,rho,rough stack, and the parameter 'ssub' in
%     callParatt is the final roughness encountered. 
%
%     * For air liquid 'ssub' is therefore the substrate roughness.
%
%     * For solid liquid, the substrate roughness is the first roughness encountered, and 'ssub' is then the roughness of the outermost layer
%
% Outputs:
%
%     * outLayers = cell array of layers param values for each contrast.
%
%     * outSsubs =  vector of substrate roughness values.
%


%outLayers = cell(1,numberOfContrasts);
%outSsubs = zeros(1,numberOfContrasts);


coder.varsize('layers',[Inf,5],[1 1]);

%for i = 1:numberOfContrasts
    output = allLayers;
    s_sub = allRoughs;
    layers = zeros(size(output));
    if ~isempty(output)
        if strcmpi(geometry,'air/substrate')
                layers = output;
                %s_sub = rsub;
        else
                roughs = output(:,3);
                sldss = output(:,2);
                thicks = output(:,1);
                rsub = roughs(end);
                if length(roughs) > 1
                    roughs = [s_sub ; roughs(1:end-1)];
                else
                    roughs = s_sub;
                end
                n = size(output,2);
                if n == 5
                    cov = output(:,4);
                    layers = [thicks(:) sldss(:) roughs(:) cov(:)];
                else
                    layers = [thicks(:) sldss(:) roughs(:)];
                end
                s_sub = rsub;
        end
        
        %Deal with the %coverage if present
        n = size(output,2);
        l = size(output,1);
        if n == 5
            for j = 1:l
                this_pcw = output(j,4);
                if output(j,5) == 1
                    pc_add = nbair;
                else
                    pc_add = nbsubs;
                end
                if ~isnan(this_pcw)
                    layers(j,2) = pc_add*(this_pcw/100) + (1-(this_pcw/100))*layers(j,2);
                end
            end
        end 
    end
%     problem.layers{i} = layers;
%     problem.ssubs(i) = s_sub;
if ~isempty(layers)
    outLayers = layers(:,1:3);
else
    outLayers = zeros(1,3);
end
outSsubs = s_sub;


end


%end
    