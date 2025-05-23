function [B, mu, VE, flag] = calcEllipsoid(u, VS)
% Calculate a bounding ellipsoid for a set of points u. 
%
% Parameters
% ----------
% u : array 
%     Array of points to contain in the ellipsoid.
%     Nxndims array where N is the number point and ndims is the
%     number of dimensions.
% VS : float
%     The minimum volume that the bounding ellipsoid should have.
%
% Returns
% -------
% B : array
%     Bounding matrix for ellipsoid including scale factor for minimum volume.
% mu : float
%     The centroid of the ellipsoid.
% VE : float
%     The volume of the ellipsoid.
% flag : bool
%     Equals 1 if the ellipsoid cannot be drawn (too few points or bad condition number).

% default values
B = [];
mu = [];
VE = [];
flag = 0;

% extract number of points and number of dimensions
N = size(u, 1);
ndims = size(u, 2);

% check that total number of points is large enough
if N < ndims+1
  flag = 1;
  return;
end

% constant factor for volume of ellipsoid
const = pi^(0.5*ndims)/gamma(0.5*ndims + 1);

% calculate covariance matrix and centroid
C = cov(u);
mu = mean(u);

% check condition number of C (eps = 2.2204e-16)
if rcond(C)<eps || isnan(rcond(C))
  flag = 1;
  return;
end

% find scale factor for bounding ellipsoid E
fB = 0;
for i=1:N
    f = ( (u(i,:)-mu) / C ) * (u(i,:)-mu)';
    if f > fB
        fB = f(1);
    end
end

% calculate volume of bounding ellipsoid E
VE = const*sqrt(det( fB * C ));

% expand volume of bounding ellipsoid to VS if necessary
fV = 1;
if VE < VS

    
    % the original implementation calculates this as
    %fV = (VS/VE)^(2/ndims);
    % however when compiled to C++,
    % MATLAB Coder does not compile the code for fractional powers of matrices.
    % so we must replace it with the explicit calculation:
    x = 2/ndims;
    A = log(VS/VE) * x;
    fV = exp(A);

    VE = VS;
end

% scale C to get bounding matrix B

% Again emphasise the scalar for the inner mutiplication
% matlab error in compiled code.....
% 
% Error using eml_mtimes_helper>dynamic_size_checks
% Inner dimensions must agree. Generated code for a general matrix multiplication at this call site. If this should have been a scalar times a variable-size matrix, the
% scalar input must be fixed-size.
% 
% Error in eml_mtimes_helper (line 69)
%     dynamic_size_checks(a, b, innerDimA, innerDimB);
% 
% Error in calcEllipsoid (line 73)
% B = fV * fB * C;

% B = fV * fB * C;
B = fV(1) * fB(1) * C;

return
