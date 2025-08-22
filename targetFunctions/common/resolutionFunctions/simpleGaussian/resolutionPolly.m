function simulation = resolutionPolly(xdata,rawSimulation,resolutionValues,points)
% Apply resolution correction

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
