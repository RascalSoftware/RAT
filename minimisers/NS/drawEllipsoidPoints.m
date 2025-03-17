function pnts = drawEllipsoidPoints(B, mu, N )
% Draw points uniformly from an ellipsoid.
% 
% Parameters
% ----------
% B : array
%     The bounding matrix for the ellipsoid.
% mu : float
%     The centroid of the ellipsoid.
% N : int
%     The number of points to draw.
%
% Returns
% -------
% pnts : array
%     An array of N points drawn from the N-dimensional ellipsoid defined
%     by bounding matrix B and centroid mu.

% get number of dimensions from the bounding matrix B
ndims = size(B,1);

% calculate eigenvalues and vectors of the bounding matrix
[V, E] = eig(B);
D = sqrt(diag(E));

% check size of mu and transpose if necessary
if size(mu,1) > 1
    mu = mu';
end 

% generate radii of hyperspheres
rs = rand(N,1);

% generate points
pt = randn(N,ndims);

% get scalings for each point onto the surface of a unit hypersphere
fac = sum(pt.^2, 2);

% calculate scaling for each point to be within the unit hypersphere
% with radii rs
fac = (rs.^(1/ndims)) ./ sqrt(fac);

pnts = zeros(N,ndims);

% scale points to the ellipsoid using the eigenvalues and rotate with
% the eigenvectors and add centroid
for i=1:N
    % scale points to a uniform distribution within unit hypersphere
    pnts(i,:) = fac(i)*pt(i,:);

    % scale and rotate to ellipsoid
    % ('real' needed for compile....)
    pnts(i,:) = real((pnts(i,:) .* D' * V') + mu);
end

return
