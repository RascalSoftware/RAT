function simulation = resolutionExpansionWithPoints(xdata,rawSimulation,resolutionValues,points) %#codegen
% Apply resolution correction
arguments
    xdata (1,:) double
    rawSimulation (1,:) double
    resolutionValues (1,:) double
    points (1,1) double
end
%persistent exps
%persistent sigma
% np0 = floor(numel(xdata)/2);
% if isempty(exps) || sigma ~= resolutionValues(1)
%     ii = -10:+10;
%     exps = exp(-((xdata(np0+ii)/xdata(np0)-1)/resolutionValues(1)).^2);
%     sexps = sum(exps);
%     exps = exps/sexps;
%     sigma = resolutionValues(1);
% end

width = 10;
LOG_RESLIMIT = -6.907755278982137;
fhhw = sqrt(-LOG_RESLIMIT);
simulation = zeros(points,1);

sq2 = sqrt(2);
for j = 1:points
    %width = max()
    ilow = max(-width, -j + 1);
    ihi = min(width, points- j - 1);


    sq2Sigma = sq2*resolutionValues(j);
    gauss_spawn = fhhw*sq2Sigma;
    x0 = xdata(j);
    x_min =x0 - gauss_spawn;
    x_max =x0 + gauss_spawn;
    sumg = 0;
    if x_min<xdata(1)
        x_min = xdata(1);
    end
    if x_max>xdata(end)
        x_max = xdata(end);
    end
    for i = ilow:ihi
        xi = xdata(j+i);
        if xi<x_min || xi>x_max; continue; end
        [avrg,g] = gauss_convolute(x0,sq2Sigma,j+i,x_min,x_max,xdata,rawSimulation);
        simulation(j) =simulation(j) + avrg;
        sumg = sumg + g;
    end
    simulation(j) = simulation(j) / sumg;
    %simulationf(j) = avrd/sumf;
end
end

function [avrg,g] = gauss_convolute(x0,sq2Sigma,ix,x_min,x_max,x_theory,y_theory)
li_min = x_theory(ix);
if li_min<x_min; li_min = x_min;end
li_max = x_theory(ix+1);
if li_max>x_max; li_max = x_max;end

u_min = (li_min-x0)/sq2Sigma;
u_max = (li_max-x0)/sq2Sigma;

g = (sq2Sigma*sqrt(pi)/2)*(erf(u_max)-erf(u_min));
alpha = (y_theory(ix+1)-y_theory(ix))/(x_theory(ix+1)-x_theory(ix));
avrg = g*(y_theory(ix)+alpha*(x0-x_theory(ix)));

avrg2 = 0.5*alpha*sq2Sigma*sq2Sigma*(exp(-u_max*u_max)-exp(-u_min*u_min));

avrg = avrg - avrg2;
end
