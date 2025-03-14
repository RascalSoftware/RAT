function resampledLayers = resampleLayers(sldProfile, sldProfileIm, minAngle, nPoints)

% Resample the SLD profile. In this case we have an imaginary SLD also, and
% so we resample that onto the same points as the real one 

% Function handle for adaptive resampling
% f = @(x) SLDFunction(x);
% 
x = sldProfile(:,1);

xstart = x(1);
xend = x(end);

out = adaptive(sldProfile, [xstart xend], minAngle*pi, nPoints);
yy = out{1};

newX = yy(:,1);
newY = yy(:,2);

% Now interpolate the imaginary profile so that it is on the same x points
% as the resampled real one....
newYIm = interp1(sldProfileIm(:,1), sldProfileIm(:,2), newX, 'linear', 'extrap');

resampledLayers = zeros(length(newX)-1, 4);

% Now build a layer model from these resampled points
for i = 1:length(newX)-1
    thisX = newX(i);
    nextX = newX(i+1);

    thisY = newY(i);
    nextY = newY(i+1);

    thisYIm = newYIm(i);
    nextYIm = newYIm(i+1);
    
    layerThickness = nextX - thisX;
    if nextY > thisY
        layerRhoRe = (0.5 * (nextY - thisY)) + thisY;
    else
        layerRhoRe = (0.5 * (thisY - nextY)) + nextY;
    end
    
    if nextYIm > thisYIm
        layerRhoIm = (0.5 * (nextYIm - thisYIm)) + thisYIm;
    else
        layerRhoIm = (0.5 * (thisYIm - nextYIm)) + nextYIm;
    end
    
    resampledLayers(i,:) = [layerThickness layerRhoRe layerRhoIm eps];

end

end