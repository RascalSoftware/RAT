function     thisContrastLayers = allocateLayersForContrast(contrastLayers,outParameterisedLayers,useImaginary)
% Decide which layers are needed for a particular contrast.
% This function takes the master array of all layers
% and extracts which parameters are required for 
% a particular contrast. 
%
% INPUTS:
%     outParameterisedLayers - List of all the available layers
%     thisContrastLayers     - Array detailing which layers are required for this contrast

coder.varsize('thisContrastLayers',[1000 6],[1 1]);

if useImaginary
    thisContrastLayers = zeros(length(contrastLayers),6);
else
    thisContrastLayers = zeros(length(contrastLayers),5);
end

 for i = 1:length(contrastLayers)
    if (contrastLayers(i) ~= 0)
        thisLayer = outParameterisedLayers{contrastLayers(i)};
        
%         % Check the length of thisLayer. If it's 6, then we have an
%         % imaginary SLD defined. Combile them into one complex number at
%         % this point.
%         if length(thisLayer) == 6
%             compSLD = complex(thisLayer(2),thisLayer(3));
%             thisLayer = [thisLayer(1) compSLD thisLayer(4:end)];
%         end

        thisContrastLayers(i,:) = thisLayer;
    else
        thisContrastLayers(1,:) = [];
    end
end

end