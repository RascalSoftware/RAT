function kn = findkn(k0, sld)

subtr = k0^2 - 4*pi*sld;

% This is the sqrt function with branch cut in subtr from 0 to infinity
% along a ray at angle theta = pi/2
kn = exp(-0.25i*pi) * sqrt(subtr*exp(0.5i*pi));

end
