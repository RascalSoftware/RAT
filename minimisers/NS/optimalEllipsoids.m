function [Bs, mus, VEs, ns] = optimalEllipsoids(u, VS)

% function [Bs, mus, VEs, ns] = optimalEllipsoids(u, VS)
%
% This function attempts to optimally partition the multi-dimensional
% samples u (uniformly distributed within the sample volume VS), into
% a set of subclusters enclosed by bounding ellipsoids.  The algorithm 
% is based on Algorithm 1 of the MULTINEST paper by Feroz, Hobson, 
% and Bridges, MNRAS, 398, 1601-1614 (2009).
%
% Output:
%   Bs:  an array of bounding matrices for the ellipsoids enclosing
%        the subclusters, scaled to have at least the minimum volume
%        required by the subclusters. ( (K x ndims) x ndims )
%   mus: an array of centroids for the bounding ellipsoids (K x ndims)
%   VEs: an array of volumes for the bounding ellipsoids   (K x 1)
%   ns:  an array containing the number of points for each subcluster (K x 1)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
N = size(u,1); % number of samples in multi-dimensional space
ndims = size(u,2); % number of dimensions
K = 1;

mus = [1 1];
coder.varsize('mus',[1e4 1e4],[1 1]);

ns = [1 ; 1];
coder.varsize('ns',[1e4 1e4],[1 1]);

% calculate bounding matrix, etc. for bounding ellipsoid associated
% with the original set of points u
[B, mu, VE, flag] = calcEllipsoid(u, VS);
if flag
  coderException(coderEnums.errorCodes.domainError, 'NS Error: Failed to calculate bounding ellipsoid. Consider increasing nLive.')
end

% attempt to split u into two subclusters
[u1, u2, VE1, VE2, nosplit] = splitEllipsoid(u, VS);
n1 = size(u1,1);
n2 = size(u2,1);

if nosplit || n1<ndims+1 || n2<ndims+1
    % couldn't split the cluster
    Bs = B;
    mus = mu;
    VEs = VE;
    ns = N;
else
    % check if we should keep the partitioning of S
    %if (all(VE1 + VE2 < VE) || all(VE > 2*VS)) 
    test1 = all(VE1 + VE2 < VE); 
    test2 = all(VE > 2*VS);
    if  all(test1) || all(test2) 
        K = K + 1;
        VS1 = n1 * VS / N;
        VS2 = n2 * VS / N;

        [B1, mu1, VE1, n1] = optimalEllipsoids(u1, VS1);
        [B2, mu2, VE2, n2] = optimalEllipsoids(u2, VS2);

        Bs =  [B1 ; B2];
        mus = [mu1 ; mu2];
        VEs = [VE1 ; VE2];
        ns =  [n1 ; n2];
    else
        Bs = B;
        mus = mu;
        VEs = VE;
        ns = N;
    end

end

return

