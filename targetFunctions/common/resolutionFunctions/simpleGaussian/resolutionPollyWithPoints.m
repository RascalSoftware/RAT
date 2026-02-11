function simulation = resolutionPollyWithPoints(xdata,rawSimulation,resolutionValues,points,thick,re_sld,img_sld,rough) %#codegen
% Apply resolution correction
arguments
    xdata (1,:) double
    rawSimulation (1,:) double
    resolutionValues (1,:) double
    points (1,1) double
    thick  (:,1) double
    re_sld (:,1) double
    img_sld (:,1) double
    rough  (:,1) double
end

sld = complex(re_sld,img_sld);
%width = 10;
LOG_RESLIMIT = -6.907755278982137;
fhhw = sqrt(-LOG_RESLIMIT);
simulation = zeros(points,1);
sq2 = sqrt(2);
for j = 1:points
    %width = max()
    %ilow = max(-width, -j + 1);
    %ihi = min(width, points- j - 1);


    sq2Sigma = sq2*resolutionValues(j);
    gauss_spawn = fhhw*sq2Sigma;
    x0 = xdata(j);
    x_min =x0 - gauss_spawn;
    x_max =x0 + gauss_spawn;
    %sumg = 0;
    if x_min<xdata(1)
        x_min = xdata(1);
    end
    if x_max>xdata(end)
        x_max = xdata(end);
    end
    %sumg = integral(@(x)norm_fun(x,x0,sq2Sigma),x_min ,x_max,'RelTol',0,'AbsTol',1e-12 );
    u_min = (x_min-x0)/sq2Sigma;
    u_max = (x_max-x0)/sq2Sigma;

    sumg = (sq2Sigma*sqrt(pi)/2)*(erf(u_max)-erf(u_min));
    avrd = integral(@(x)res_fun(x,x0,sq2Sigma,xdata,rawSimulation,thick,sld,rough),x_min ,x_max,'RelTol',0,'AbsTol',1e-12 );
    % for i = ilow:ihi
    %     xi = xdata(j+i);
    %     if xi<x_min || xi>x_max; continue; end
    %     [avrg,g] = gauss_convolute(x0,sq2Sigma,j+i,x_min,x_max,xdata,rawSimulation);
    %     simulation(j) =simulation(j) + avrg;
    %     sumg = sumg + g;
    % end
    simulation(j) = avrd / sumg;
end
end
function norm_val = norm_fun(x,x0,sig)
    norm_val = exp(-((x-x0)/sig).^2);
end
function av = res_fun(x,x0,sig,x_data,y_data,thick,sld,rough)
    exp_val = exp(-((x-x0)/sig).^2);
    N = numel(rough);
    res_val= abelesSingle(x,N,thick,sld,rough)';
    
    %res_val = interp1(x_data,y_data,x,'spline');
    av  = exp_val.*res_val;
end
