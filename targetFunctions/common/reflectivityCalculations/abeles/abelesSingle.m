function ref = abelesSingle(q,N,layersThick,layersRho,layersSigma)

% New Matlab version of reflectivity
% with complex rho...

% Pre-allocation
c1 = complex(1,0);
c0 = complex(0,0);

ref = zeros(length(q),1);

for points = 1:length(q)

    M_tot = [c1 c0 ; c0 c1];
    M_n = [c1 c0 ; c0 c1];
    M_res = [c1 c0 ; c0 c1];

    Q = q(points);
    k0 = 0.5 * Q;

    % Compute parameters for each layer
    sigmaSquared = layersSigma.^2;
    sld = layersRho(2:end) - layersRho(1);
    kn1 = findkn(k0, sld);
    kn = [k0; kn1];
       
    % Find the Phase Factors = (k_n * d_n)
    beta = kn .* layersThick;

    for n = 1:N-1

        % Find r_n,n+1:
        nom_n = kn(n) - kn(n + 1);
        denom_n = kn(n) + kn(n + 1);
        err_n = exp(-2 * kn(n) * kn(n + 1) * sigmaSquared(n + 1));
        r_n_np1 = (nom_n / denom_n) * err_n;

        % Create the M_n matrix
        M_n(1,1) = exp(1i * beta(n));
        M_n(1,2) = r_n_np1 * exp(1i * beta(n));
        M_n(2,1) = r_n_np1 * exp(-1i * beta(n));
        M_n(2,2) = exp(-1i * beta(n));

        % Multiply the matrices
        M_res = M_tot * M_n;

        % Reassign the values back to M_tot
        M_tot = M_res;

    end

    R = abs(M_res(2,1) / M_res(1,1));
    ref(points) = R^2;

end

end
