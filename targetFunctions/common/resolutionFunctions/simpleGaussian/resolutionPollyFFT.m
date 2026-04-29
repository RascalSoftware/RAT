function simulation = resolutionPollyFFT(xdata,rawSimulation,resolutionValues,points) %#codegen
% Apply resolution correction
arguments
    xdata (1,:) double
    rawSimulation (1,:) double
    resolutionValues (1,:) double
    points (1,1) double
end
persistent res_fun_fft;

res_fun_fft = false;
if isempty(res_fun_fft)
    calc_initial_fft = true;
end
if calc_initial_fft

end


simulation = zeros(points,1);
for j = 1:points

    sumg = 0;
    ilow = max(-10, -j + 1);
    ihi = min(10, points - j);

    for i = ilow:ihi
        g = exp(-((xdata(j+i)-xdata(j))/(resolutionValues(j)*xdata(j)))^2);
        sumg = sumg + g;
        simulation(j) = simulation(j) + rawSimulation(i+j) * g;
    end

    simulation(j) = simulation(j) / sumg;

end

end
