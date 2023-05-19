function ref = abelesReflectSingle(q,N,layers_thick,layers_rho,layers_sig)

% New Matlab version of reflectivity
% with complex rho...

% Pre-allocation
tiny = 1e-30;
ci = complex(0,1);
c0 = complex(0,0);
M_tot = [c0 c0 ; c0 c0];
M_n = [c0 c0 ; c0 c0];
M_res = [c0 c0 ; c0 c0];
kn_ptr = c0;
ref = zeros(length(q),1);

for points = 1:length(q)

    Q = q(points);
    bulk_in_SLD = complex(layers_rho(1),tiny);
    k0 = Q/2;

    for n = 1:N-1

        if n == 1

            % Find k1..
            sld_1 = layers_rho(n+1) - bulk_in_SLD;
            k1 = findkn(k0, sld_1);

            % Find r01
            nom1 = k0 - k1;
            denom1 = k0 + k1;
            sigmasqrd = layers_sig(n + 1) ^ 2;
            err1 = exp(-2 * k1 * k0 * sigmasqrd);
            r01 = (nom1 / denom1) * err1;

            % Generate the M1 matrix:
            M_tot(1,1) = complex(1,0);
            M_tot(1,2) = r01;
            M_tot(2,1) = r01;
            M_tot(2,2) = complex(1,0);

            kn_ptr = k1;

        else

            % Find kn and k_n+1 (ex. k1 and k2 for n=1): */
            sld_np1 = layers_rho(n + 1);
            sld_np1 = sld_np1 - bulk_in_SLD;

            if isreal(sld_np1)  % This check may not be necessary
                sld_np1 = complex(sld_np1,eps);
            end

            kn = kn_ptr;
            knp1 = findkn(k0, sld_np1);

            % Find r_n,n+1:
            nom_n = kn - knp1;
            denom_n = kn + knp1;
            sigmasqrd = layers_sig(n + 1)^2;
            err_n = exp(-2 * kn * knp1 * sigmasqrd);
            r_n_np1 = (nom_n / denom_n) * err_n;

            % Find the Phase Factor = (k_n * d_n)
            beta = kn * layers_thick(n) * ci;

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

    end
    R = abs(M_res(2,1)/M_res(1,1));
    ref(points) = R^2;
end

end

function kn = findkn(k0,sld)

subtr = k0^2 - 4 * pi * sld;
kn = sqrt(subtr);

end


