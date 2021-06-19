function [newY] = interpolateOnToZ(X,Y,z)

% Interpolates the curve given by [X Y] onto Z.
% It first extends the range of X and Y to cover the 
% whole range of z, otherwise Matlab's interp1 will
% return NaN when beyond the range of the original X

debug = 0;

% Pad out the lower end of X and Y
xLeftEdge = X(1);
xLeftPad = linspace(0,floor(xLeftEdge));
yLeftPad = zeros(length(xLeftPad),1);

% Do the same for the upper edge
xRightEdge = X(end);
if (max(z)-xRightEdge)<=10
    xRightPad = max(z);
else
    xRightPad = linspace(ceil(xRightEdge),max(z));
end
yRightPad = zeros(length(xRightPad),1);

extendedX = [xLeftPad(:) ; X(:) ; xRightPad(:)];
extendedY = [yLeftPad(:) ; Y(:) ; yRightPad(:)];

%Interpolate them onto z....
newY = interp1(extendedX,extendedY,z);

% Debug plot
if debug == 1
    figure(); clf
    clf
    plot(z,newY)
end

end