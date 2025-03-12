function kn = findkn(k0,sld)

subtr = k0^2 - 4 * pi * sld;
kn = sqrtbc(pi/2,subtr);

end

function y = sqrtbc(theta,zarg)
% sqrt function with branch cut in zarg from 0 to infinity along a ray 
% at angle theta (in radians) measured from the +x axis in the usual way,  
% with -pi<=theta<=pi.  theta = pi is the usual square root.
% for zarg on the +x axis, sqrt behavior is conserved,
% i.e. sqrtbc(theta,zarg) is positive and real for any theta.
%
% y = sqrtbc(theta,zarg)
if theta==0
    phi = pi;
else
    phi = theta -pi*sign(theta);
end
y = exp(1i*phi/2)*sqrt(zarg*exp(-1i*phi));
% translations:  sqrtbc(theta, z-b) has branch cut in the z plane from
% branch point z = b out to infinity, along a ray at angle theta. 
%
% for the usual square root with branch cut along -x,
% the real part of sqrt(z) is positive (or 0) for all z.
% for the modified square root with branch cut along +x,
% the imaginary part of sqrt(z) is positive (or 0) for all z.

end