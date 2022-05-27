function f = Asymconvstep(x,xw,xcen,s1,s2,h)
% Produces a step function convoluted with differnt error functions
% on each side.
% Convstep (x,xw,xcen,s1,s2,h)
%       x = vector of x values
%      xw = Width of step function
%    xcen = Centre point of step function
%       s1 = Roughness parameter of left side
%       s2 = Roughness parameter of right side
%       h = Height of step function.

% if length(xw) > 1
%     ME = MException('VerifyOutput:OutOfBounds', ...
%              'xw must be single value');
%     throw(ME);
% end
% 
% if length(xcen) > 1
%     ME = MException('VerifyOutput:OutOfBounds', ...
%              'xcen must be single value');
%     throw(ME);
% end
% 
% if length(s1) > 1
%     ME = MException('VerifyOutput:OutOfBounds', ...
%              's1 must be single value');
%     throw(ME);
% end
% 
% if length(s2) > 1
%     ME = MException('VerifyOutput:OutOfBounds', ...
%              's2 must be single value');
%     throw(ME);
% end

r = xcen + (xw/2);
l = xcen - (xw/2);

aFactor = (2^0.5)*s1;
bFactor = (2^0.5)*s2;

a = (x-l)/aFactor;
b = (x-r)/bFactor;

f = (h/2)*(erf(a)-erf(b));


