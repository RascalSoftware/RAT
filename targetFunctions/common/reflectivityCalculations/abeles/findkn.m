function kn = findkn(k0, sld)

subtr = k0^2 - 4*pi*sld;
kn = exp(-0.25i*pi) * sqrt(subtr*exp(0.5i*pi));

end
