function N = inEllipsoids(pnt, Bs, mus)
% Calculate how many of the ellipsoids contain the point ``pnt``. 
%
% Parameters
% ----------
% pnt : array
%     The point to calculate ellipsoid membership for.
% Bs : array
%     The bounding matrices of the ellipsoids.
% mus : array
%     The centroids of the ellipsoids.
%
% Returns
% -------
% N : int
%     The number of ellipsoids containing ``pnt``.
%
N = 0;

% total number of ellipsoids and number of dimensions
K = size(mus,1);
ndims = size(mus,2);

% loop over number of ellipsiods and work out whether it contains the point
for k=1:K
    % set the point to have the same origin as the ellipsoid
    pntnew = pnt - mus(k,:);
    
    % extract the bounding matrix
    B = Bs((k-1)*ndims+1:k*ndims,:);

    % get the eigenvalues and eigenvectors of the ellipsoid
    [V, E] = eig(B); % V is matrix of eigenvectors (as columns)
    D = sqrt(diag(E));

    % rotate points to be on coordinate axes of the ellipsiod
    pntnew = pntnew * V;
    
    % scale points so that it's equivalent to having unit hyper-spheroids 
    % rather than ellipsiods
    pntnew = pntnew ./ D';
    
    % get distance to point from centre of hyper-sphere
    dpnt = sqrt(sum(pntnew.^2));
    
    if dpnt <= 1
        % values is within the ellipsiod
        N = N + 1;
    end
end

return

