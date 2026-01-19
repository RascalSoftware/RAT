function [outputLayers, ssubs] = groupLayersMod(layers,subRoughs,geometry)
% Arrange layers according to geometry.
% The paratt calculation proceeds through the z,rho,rough stack; and the
% parameter 'ssub' is the final roughness encountered.
%
% * For air/liquid 'ssub' is therefore the substrate roughness.
% * For solid/liquid, the substrate roughness is the first roughness
%   encountered, and 'ssub' is then the roughness of the outermost layer.
%
% USAGE::
%
%     [outLayers, ssubs] = groupLayersMod(resampledLayers,subRoughs,geometry)
%
% INPUTS:
%     * layers: List of layer values for this contrast.
%     * subRoughs:  Double of substrate roughness for this contrast.
%     * geometry: 'Air / Liquid (or solid)' or 'Solid / Liquid'
%
% Outputs:
%     * outputLayers: Layers parameter values for this contrast.
%     * ssubs: vector of ssub values.

ssubs = subRoughs;

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
            outputLayers = [layers(:, 1:3) roughnesses layers(:, 5:end)];
            ssubs = rsub;
    end

else

    outputLayers = zeros(0, 4);
    
end

end
    