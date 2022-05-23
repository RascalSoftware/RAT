
function newSLD = resampleLayers_new(sldProfile,resamPars)


% Function handle for adaptive resampling
% f = @(x) sldFunc(x);
% 
x = sldProfile(:,1);
prof = sldProfile(:,2);

xstart = x(1);
xend = x(end);

% Keep points and minangle as constants for now
% will fix later
minAngle = resamPars(1);
nPoints = resamPars(2);

newX = linspace(xstart,xend,100);
out = adaptive_new(sldProfile, [xstart xend], minAngle*pi, nPoints);
yy = out{1};

newX = yy(:,1);
newY = yy(:,2);
layers = zeros(length(newX)-1,3);

% Now build a layer model from these resampled points
for n = 1:length(newX)-1
    thisX = newX(n);
    nextX = newX(n+1);
    thisY = newY(n);
    nextY = newY(n+1);
    
    thisLayThick = nextX - thisX;
    if nextY > thisY
        thisLayRho = ((nextY - thisY)/2) + thisY;
    else
        thisLayRho = ((thisY - nextY)/2) + nextY;
    end
    
    layers(n,:) = [thisLayThick thisLayRho eps];
end
newSLD = layers;

end