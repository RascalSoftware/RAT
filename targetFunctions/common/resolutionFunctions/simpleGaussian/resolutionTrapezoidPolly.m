function simulation = resolutionTrapezoidPolly(xdata,rawSimulation,resolutionValues,points) %#codegen
% Apply resolution correction
% Trapezoid integration. (refl1D algorithm)
arguments
    xdata (1,:) double
    rawSimulation (1,:) double
    resolutionValues (1,:) double
    points (1,1) double
end


width = 10;
LOG_RESLIMIT = -6.907755278982137;
fhhw = sqrt(-LOG_RESLIMIT);
sq2 = sqrt(2);
simulation = zeros(points,1);
exp_values = zeros(1,2*width+1);
fun_values = zeros(1,2*width+1);
dx = zeros(1,2*width+1);
x_expanded = [xdata,xdata(end)];
for j = 1:points

    ilow = max(-width, -j + 1);
    ihi = min(width, points - j);
    sq2Sigma = sq2*resolutionValues(j);
    gauss_spawn = fhhw*sq2Sigma;    
    x0 = xdata(j);
    x_min =x0 - gauss_spawn;
    x_max =x0 + gauss_spawn;

    ic = 0;    
    for i = ilow:ihi
        xi = x_expanded(j+i);
        if xi<x_min || xi>x_max; continue; end
        g = exp(-((xi - x0)/sq2Sigma).^2);
        ic = ic+1;
        dx(ic)  = x_expanded(j+i+1)-xi;
        exp_values(ic) = g;
        fun_values(ic) = rawSimulation(i+j) * g;
    end
    int_exp = 0.5*dx(1:ic-1).*(exp_values(1:ic-1)+exp_values(2:ic));
    int_fun = 0.5*dx(1:ic-1).*(fun_values(1:ic-1)+fun_values(2:ic));    
    simulation(j) = sum(int_fun)/ sum(int_exp);
end

end
