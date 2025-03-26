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
    nextSigmaSquared = layersSigma.^2;
    % Always need the next sigma squared value for layers 1:end-1
    nextSigmaSquared(1) = [];

    sld = layersRho(2:end) - layersRho(1);
    kn1 = findkn(k0, sld);
    kn = [k0; kn1];
       
    % Find the Phase Factors = (k_n * d_n)
    beta = kn .* layersThick;

    % Construct an array of kn(1:end-1) and kn(2:end) for parameters based
    % on combining consecutive values
    kn_np1 = [kn(2:end) kn(1:end-1)];

    numerator = diff(kn_np1, 1, 2);
    denominator = sum(kn_np1, 2);
    erf = exp(-2 * prod(kn_np1, 2) .* nextSigmaSquared);
    r = (numerator ./ denominator) .* erf;

    for n = 1:N-1

        % Create the M_n matrix
        M_n(1,1) = exp(1i * beta(n));
        M_n(1,2) = r(n) * exp(1i * beta(n));
        M_n(2,1) = r(n) * exp(-1i * beta(n));
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
