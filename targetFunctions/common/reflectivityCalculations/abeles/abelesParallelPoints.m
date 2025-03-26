function ref = abelesParallelPoints(q,N,layersThick,layersRho,layersSigma)

% Vectorised version of reflectivity with complex rho

c1 = complex(1,0);
ref = zeros(length(q),1);

% SLD is always relative to bulk in value
sld = layersRho(2:end) - layersRho(1);

% Always need the next sigma squared value for layers 1:end-1
nextSigmaSquared = layersSigma(2:end).^2;

parfor points = 1:length(q)

    M_n = eye(2, 'like', c1);
    M = eye(2, 'like', c1);
    k0 = 0.5 * q(points);

    % Compute parameters for each layer
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
        M = M * M_n;

    end

    R = abs(M(2,1) / M(1,1));
    ref(points) = R^2;

end

end
