function ref = abelesParallelPoints(q,N,layersThick,layersRho,layersSigma)

tiny = 1e-30;
ci = complex(0,1);
c0 = complex(0,0);

ref = zeros(length(q),1);

layersRho1 = layersRho(1);
layersRho2 = layersRho(2);
layersSigma2 = layersSigma(2);

parfor points = 1:length(q)

    M_tot = [c0 c0 ; c0 c0];
    M_n = [c0 c0 ; c0 c0];
    M_res = [c0 c0 ; c0 c0];

    Q = q(points);

    bulkInSLD = layersRho1;
    bulkInSLD = bulkInSLD + complex(0,tiny);

    k0 = Q/2;

    % Find k1..
    sld_1 = layersRho2 - bulkInSLD;
    k1 = findkn(k0, sld_1);

    % Find r01
    nom1 = k0 - k1;
    denom1 = k0 + k1;
    sigmasqrd = layersSigma2 ^ 2;
    err1 = exp(-2 * k1 * k0 * sigmasqrd);
    r01 = (nom1 / denom1) * err1;

    % Generate the M1 matrix:
    M_tot(1,1) = complex(1,0);
    M_tot(1,2) = r01;
    M_tot(2,1) = r01;
    M_tot(2,2) = complex(1,0);

    kn_ptr = k1;

    for n = 2:N-1

        % Find kn and k_n+1 (ex. k1 and k2 for n=1): */
        sld_np1 = layersRho(n + 1);
        sld_np1 = sld_np1 - bulkInSLD;
    
        kn = kn_ptr;
        knp1 = findkn(k0, sld_np1);
    
        % Find r_n,n+1:
        nom_n = kn - knp1;
        denom_n = kn + knp1;
        sigmasqrd = layersSigma(n + 1)^2;
        err_n = exp(-2 * kn * knp1 * sigmasqrd);
        r_n_np1 = (nom_n / denom_n) * err_n;
    
        % Find the Phase Factor = (k_n * d_n)
        beta = kn * layersThick(n) * ci;
    
        % Create the M_n matrix: */
        M_n(1,1) = exp(beta);
        M_n(1,2) = r_n_np1 * exp(beta);
        M_n(2,1) = r_n_np1 * exp(-beta);
        M_n(2,2) = exp(-beta);
    
        % Multiply the matrices
        M_res = M_tot * M_n;
    
        % Reassign the values back to M_tot:
        M_tot = M_res;
    
        % Point to k_n+1 and sld_n+1 via kn_ptr sld_n_ptr:
        kn_ptr = knp1;

    end

    R = abs(M_res(2,1)/M_res(1,1));
    ref(points) = R^2;

end

end
