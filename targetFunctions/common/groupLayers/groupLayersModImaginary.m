function [outLayers, outSsubs] = groupLayersModImaginary(resampledLayers,subRoughs,geometry,bulkIns,bulkOuts)
% Arrange layers according to geometry and apply any coverage correction. The paratt calculation proceeds through the 
% z,rho,rough stack, and the parameter 'ssub' in callParatt is the final roughness encountered. 
%
% * For air liquid 'ssub' is therefore the substrate roughness.
% * For solid liquid, the substrate roughness is the first roughness encountered, and 'ssub' is then the roughness of the outermost layer
%
% USAGE::
%
%     [outLayers, outSsubs] = groupLayersModImaginary(resampledLayers,subRoughs,geometry,bulkIns,bulkOuts)
%
% INPUTS:
%     * resampledLayers: cell array, one for each contrast. Each cell is the list of layer values for each contrast.
%     * subRoughs:  Double of substrate roughness for each contrast.
%     * geometry: 'Air / Liquid (or solid)' or 'Solid / Liquid'
%     * bulkIns: vector of bulkIn values.
%     * bulkOuts: vector of bulkOut values.
%
% Outputs:
%     * outLayers: cell array of layers param values for each contrast.
%     * outSsubs: vector of substrate roughness values.

outSsubs = subRoughs;
layers = zeros(size(resampledLayers));
if ~isempty(resampledLayers)
    if strcmpi(geometry, coderEnums.geometryOptions.AirSubstrate)
            layers = resampledLayers;
    else
            roughs = resampledLayers(:,4);
            sldss = resampledLayers(:,2:3);
            thicks = resampledLayers(:,1);
            rsub = roughs(end);
            if length(roughs) > 1
                roughs = [outSsubs ; roughs(1:end-1)];
            else
                roughs = outSsubs;
            end
            n = size(resampledLayers,2);
            if n == 5
                cov = resampledLayers(:,5);
                layers = [thicks sldss roughs cov];
            else
                layers = [thicks sldss roughs];
            end
            outSsubs = rsub;
    end
    
    %Deal with the %coverage if present
    n = size(resampledLayers,2);
    l = size(resampledLayers,1);
    if n == 6
        for j = 1:l
            this_pcw = resampledLayers(j,5);
            if resampledLayers(j,6) == 1
                pc_add = bulkIns;
            else
                pc_add = bulkOuts;
            end
            if ~isnan(this_pcw)
                layers(j,2) = pc_add*(this_pcw/100) + (1-(this_pcw/100))*layers(j,2);
            end
        end
    end 
end

if ~isempty(layers)
    outLayers = layers(:,1:4);
else
    outLayers = zeros(1,4);
end

end
    