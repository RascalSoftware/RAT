function [sample, logL] = drawMultiNest(fracvol, Bs, mus, ... 
    logLmin, prior, data, likelihood, model, parnames, extraparvals)
    % This function draws a multi-dimensional sample from the prior volume
    % for use in the nested sampling algorithm. The new point will have a
    % likelihood greater than the value logLmin. The new point will be found by
    % drawing a random multi-dimensional sample from within the set of optimal
    % ellipsoids constructed using the MultiNest algorithm.  The bounding 
    % ellipsoids are defined by their bounding matrices Bs and centroids mus.
    % extraparvals is a vector of additional parameters needed by the model.
    %
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % extra number of ellipsoids, number of dimensions 
    K = size(mus, 1);
    ndims = size(mus,2);
    
    pnt = [1 1];
    coder.varsize('pnt',[1 1e5],[0 1]);
    
    sample = zeros(1,0);
    coder.varsize('sample',[1 1e5],[1 1]);
    
    while 1
        % find the ellipsoid from which to draw a new point
        rval = rand;
                
        k0 = 1;
        for k = 1:K
            k0 = k;
            if rval < fracvol(k)
                continue
            else
                break
            end
        end
        
        % extract bounding matrix and centroid for that ellipsoid
        B = Bs((k0-1)*ndims+1:k0*ndims,:);
        mu = mus(k0,:);
    
        % draw points from that ellipsoid until logL >= logLmin
        logL = -inf;
        while logL < logLmin
            in_range = 1; % default value
    
            % draw one point from the ellipsoid
            pnt = drawEllipsoidPoints(B, mu, 1);
    
            % make sure that the point lies in unit hypercube
            for ii=1:ndims
                 if pnt(ii)<0 || pnt(ii)>1
                     in_range = 0;
                 end
            end
                
            if in_range 
                % assign as candidate replacement live point
                sample = pnt;
                   
                % rescale point back to full range
                rescaledpnt = rescaleParameters(prior, pnt); 
                    
                % get new likelihood
                % logL = likelihood(data, model, parnames, loopCell(rescaledpnt));
                logL = likelihood(data,rescaledpnt);
            end
            
        end
           
        % check how many ellipsoids this point lies in
        inN = inEllipsoids(pnt, Bs, mus);
                
        % only accept sample with 1/inN probability
        if rand < 1/inN
            break
        end
    end
end
