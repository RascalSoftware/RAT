function f = Gaussian(z,Z,N,A)
%f(z) = gaussian(z,Z,N,A)
%
%	produces a gaussian at centre Z, of height
%	N and 1/e half width of A.

f = (N/(A*sqrt(pi)))*exp(-0.5*((z-Z).^2)/(A^2));

end