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

%outLayers = cell(1,numberOfContrasts);
%outSsubs = zeros(1,numberOfContrasts);


coder.varsize('layers',[Inf,6],[1 1]);

%for i = 1:numberOfContrasts
    output = resampledLayers;
    ssub = subRoughs;
    layers = zeros(size(output));
    if ~isempty(output)
        if strcmpi(geometry, coderEnums.geometryOptions.AirSubstrate)
                layers = output;
                %ssub = rsub;
        else
                roughs = output(:,4);
                sldss = output(:,2:3);
                thicks = output(:,1);
                rsub = roughs(end);
                if length(roughs) > 1
                    roughs = [ssub ; roughs(1:end-1)];
                else
                    roughs = ssub;
                end
                n = size(output,2);
                if n == 5
                    cov = output(:,5);
                    layers = [thicks sldss roughs cov];
                else
                    layers = [thicks sldss roughs];
                end
                ssub = rsub;
        end
        
        %Deal with the %coverage if present
        n = size(output,2);
        l = size(output,1);
        if n == 6
            for j = 1:l
                this_pcw = output(j,5);
                if output(j,5) == 1
                    pc_add = bulkIns;
                else
                    pc_add = bulkOuts;
                end
                if ~isnan(this_pcw)
                    layers(j,2) = pc_add*(this_pcw/100) + (1-(this_pcw/100))*layers(j,2);
                    %layers(j,3) = pc_add*(this_pcw/100) + (1-(this_pcw/100))*layers(j,3);
                end
            end
        end 
    end

if ~isempty(layers)
    outLayers = layers(:,1:4);
else
    outLayers = zeros(1,4);
end
outSsubs = ssub;


end


%end
    