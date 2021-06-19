% -----------------------------------------------------------------

function res = sld_convolute(signal,filter)

% This function convolutes the signal (in our case the bilayer SLD or volume) with a
% filter (in our case a Gaussian). Broadly speaking, the procedure is to
% take the Fourier transform of both curves, multiply those together, and
% inverse fourier transform the result, although there are a number of
% numerical correction steps that are required first:
%
%   1. Interpolate both curves onto the same x 'grid'
%   2. Ensure that both curves are zero at each end (called 'normalisation'
%   here)
%   3. Pad each curve with zeros at each end, the length of which is equal
%   to the sum of the lengths of both curves.
%   4. Do the convolution usign Matlab's 'conv' function.
%   5. Undo the corrections done in steps 1 to 3 on the convoluted curve to get the final result. 
 
debug = 0;          % flag for debug plot if required

%Interpolate signals onto uniform grid....
%sld....
sld_x = signal(:,1);
sld_y = signal(:,2);

st = sld_x(1);
en = sld_x(end);
newSldX = linspace(st,en,length(sld_y));
newSldY = interp1(sld_x,sld_y,newSldX);
new_sld = [newSldX(:) newSldY(:)];

%also filter....
filt_x = filter(:,1);
filt_y = filter(:,2);

st = filt_x(1);
en = filt_y(end);
newFiltX = linspace(st,en,length(filt_y));
newFiltY = interp1(filt_x,filt_y,newSldX);
new_filt = [newFiltX(:) newFiltY(:)];

%Need to pad the edge of the signal with zeros. Do this by padding out
%initially with the values at the edges, then 'normalise' the
%water regions to zero buy subtraction...
yStart = newSldY(1);
xStep = abs(newSldX(2)-newSldX(1));

%Do the zero padding.... 
padLength = (length(filter) + length(newSldX));
padStartX = (padLength*(-xStep))+newSldX(1);
padLeftX = linspace(padStartX,(newSldX(1)-xStep),padLength);
padEndX = padLength*(xStep)+newSldX(end);
padRightX = linspace((newSldX(end)+xStep),padEndX,padLength);
yPad = ones(1,padLength)*yStart;

%Make the 'spliced' data
padNewX = [padLeftX newSldX padRightX];
padNewY = [yPad newSldY yPad];

%....'normalise' to give zero edges...
yDivFactor = newSldY(1);
padNewY = padNewY - newSldY(1);

sigFactor = sum(newFiltY);
yFactor = sum(padNewY);
newFilter = newFiltY ./ sigFactor;
padNewY = padNewY ./ yFactor; 

%Then convolute... 
fConv = conv(padNewY,newFilter,'same');
fConv_preNorm = fConv;

%Finally 'denormalise' to get the result.... 
%padNewY = (padNewY.*yFactor) + yDivFactor;
fConv = (fConv.*yFactor) + yDivFactor;

switch debug
    case 1
        figure(100)
        clf
        plot(padNewX,fConv,'k--')
        hold on
        plot(newSldX,newSldY);
end

%Trim back to original size
stPoint = padLength;
endPoint = length(padNewX)-(padLength-1);

offset = 2;

finalX = padNewX(stPoint:endPoint) - offset;  %Not sure where this offset comes from - bug with the padding somewhere..
finalY = fConv(stPoint:endPoint);
res = [finalX(:) finalY(:)];

end

% ---------------------------------------------------------------------------------------------------


function f = Gaussian(z,Z,N,A)
%f(z) = gaussian(z,Z,N,A)
%
%	produces a gaussian at centre Z, of height
%	N and 1/e half width of A.

f = (N/(A*sqrt(pi)))*exp(-0.5*((z-Z).^2)/(A^2));

end

% ---------------------------------------------------------------------------------------------------

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