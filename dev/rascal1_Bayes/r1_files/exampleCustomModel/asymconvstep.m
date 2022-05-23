function f = asymconvstep(z,zw,zcen,s1,s2,h)
% Produces a step function convoluted with differnt error functions
% on each side.
%
% AsymConvstep (z,zw,xcen,s1,s2,h)
%       z = vector of x values
%      zw = Width of step function
%    zcen = Centre point of step function
%       s1 = Roughness parameter of left side
%       s2 = Roughness parameter of right side
%       h = Height of step function.

% Since the step is defined in terms of it's centre
% and its width, we find the edges as centre +/- 0.5 width.
r = zcen + (zw/2);          % Right edge
l = zcen - (zw/2);          % Left edge

% Make the box
a = (z-l)./((2^0.5)*s1);
b = (z-r)./((2^0.5)*s2);
f = (h/2)*(erf(a)-erf(b));

end
