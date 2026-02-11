function ref = abelesSingle(q,N,layersThick,re_sld,img_sld,layersSigma)
arguments
    q(1,:) double
    N (1,1) double    
    layersThick(:,1) double
    re_sld (:,1) double
    img_sld (:,1) double
    layersSigma  (:,1) double
end
layersRho = complex(re_sld,img_sld);

% Vectorised version of reflectivity with complex rho

c1 = complex(1,0);
ref = zeros(length(q),1);

% SLD is always relative to bulk in value
sld = layersRho(2:end) - layersRho(1);

% Always need the next sigma squared value for layers 1:end-1
nextSigmaSquared = layersSigma(2:end).^2;

for points = 1:length(q)

    M = eye(2, 'like', c1);
    k0 = 0.5 * q(points);
    kn = complex(k0);

    for n = 1:N-1

        knp1 = findkn(k0, sld(n));

        % Find the Phase Factor = (k_n * d_n)
        beta = kn * layersThick(n);

        numerator = knp1 - kn;
        denominator = knp1 + kn;
        erf = exp(-2 * knp1 * kn * nextSigmaSquared(n));
        r_n = (numerator / denominator) * erf;

        % Multiply system transfer matrix by the layer transfer matrix
        % Coder behaves better if you just do it manually
        % rather than M = M * M_n;
        % we'll denote the entries M = [a b; c d]
        exp_beta = exp(1i*beta);
        inv_exp_beta = exp(-1i*beta);

        a_exp_beta = M(1,1) * exp_beta;
        b_inv_exp_beta = M(1,2) * inv_exp_beta;
        c_exp_beta = M(2,1) * exp_beta;
        d_inv_exp_beta = M(2,2) * inv_exp_beta;
 
        M = [a_exp_beta + r_n*b_inv_exp_beta r_n*a_exp_beta + b_inv_exp_beta;
             c_exp_beta + r_n*d_inv_exp_beta r_n*c_exp_beta + d_inv_exp_beta];

        % Set value of kn for the next layer
        kn = knp1;

    end

    R = abs(M(2,1) / M(1,1));
    ref(points) = R^2;

end

end
