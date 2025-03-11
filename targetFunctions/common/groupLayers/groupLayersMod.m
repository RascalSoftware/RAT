function [outputLayers, ssubs] = groupLayersMod(layers,subRoughs,geometry,bulkIns,bulkOuts)
% Arrange layers according to geometry and apply any coverage correction.
% The paratt calculation proceeds through the z,rho,rough stack; and the
% parameter 'ssub' is the final roughness encountered.
%
% * For air/liquid 'ssub' is therefore the substrate roughness.
% * For solid/liquid, the substrate roughness is the first roughness
%   encountered, and 'ssub' is then the roughness of the outermost layer.
%
% USAGE::
%
%     [outLayers, ssubs] = groupLayersMod(resampledLayers,subRoughs,geometry,bulkIns,bulkOuts)
%
% INPUTS:
%     * layers: List of layer values for this contrast.
%     * subRoughs:  Double of substrate roughness for this contrast.
%     * geometry: 'Air / Liquid (or solid)' or 'Solid / Liquid'
%     * bulkIns: Bulk In value.
%     * bulkOuts: Bulk Out value.
%
% Outputs:
%     * outputLayers: Layers parameter values for this contrast.
%     * ssubs: vector of ssub values.

ssubs = subRoughs;
outputLayers = zeros(size(layers));

if ~isempty(layers)
    if strcmpi(geometry, coderEnums.geometryOptions.AirSubstrate)
            outputLayers = layers;
    else
            roughnesses = layers(:,4);
            rsub = roughnesses(end);
            if length(roughnesses) > 1
                roughnesses = [ssubs ; roughnesses(1:end-1)];
            else
                roughnesses = ssubs;
            end
            n = size(layers,2);
            if n == 6
                outputLayers = [layers(:, 1:3) roughnesses layers(:, 5:6)];
            else
                outputLayers = [layers(:, 1:3) roughnesses];
            end
            ssubs = rsub;
    end
    
    % Deal with the %coverage if present
    if size(layers,2) == 6

        for i = 1:size(layers,1)
            this_pcw = layers(i,5);
            if layers(i,6) == 1
                pc_add = bulkIns;
            else
                pc_add = bulkOuts;
            end
            if ~isnan(this_pcw)
                outputLayers(i,2) = (pc_add * 0.01 * this_pcw) + (1 - (0.01 * this_pcw)) * outputLayers(i,2);
            end
        end

    end 
end

if ~isempty(outputLayers)
    outputLayers(:, 5:end) = [];
else
    outputLayers = zeros(1, 4);
end

end
    