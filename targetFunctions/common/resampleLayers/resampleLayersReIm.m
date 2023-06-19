function newSLD = resampleLayersReIm(sldProfile,sldProfileIm,resamPars)

% Resample the SLD profile. In this case we have an imaginary SLD also, and
% so we resample that onto the same points as the real one.. 

% Function handle for adaptive resampling
% f = @(x) SLDFunction(x);
% 
x = sldProfile(:,1);
prof = sldProfile(:,2);

xstart = x(1);
xend = x(end);

% Keep points and minangle as constants for now
% will fix later
minAngle = resamPars(1);
nPoints = resamPars(2);

%newX = linspace(xstart,xend,100);
out = adaptive(sldProfile, [xstart xend], minAngle*pi, nPoints);
yy = out{1};

newX = yy(:,1);
newY = yy(:,2);

% Now interpolate the imaginary profile so that it is on the same x points
% as the resampled real one....
newYIm = interp1(sldProfileIm(:,1),sldProfileIm(:,2),newX);

layers = zeros(length(newX)-1,4);

% Now build a layer model from these resampled points
for n = 1:length(newX)-1
    thisX = newX(n);
    nextX = newX(n+1);
    thisY = newY(n);
    nextY = newY(n+1);
    thisYIm = newYIm(n);
    nextYIm = newYIm(n+1);
    
    thisLayThick = nextX - thisX;
    if nextY > thisY
        thisLayRho = ((nextY - thisY)/2) + thisY;
    else
        thisLayRho = ((thisY - nextY)/2) + nextY;
    end
    
    if nextYIm > thisYIm
        thisLayRhoIm = ((nextYIm - thisYIm)/2) + thisYIm;
    else
        thisLayRhoIm = ((thisYIm - nextYIm)/2) + nextYIm;
    end

    
    layers(n,:) = [thisLayThick thisLayRho thisLayRhoIm eps];
end
newSLD = layers;

end