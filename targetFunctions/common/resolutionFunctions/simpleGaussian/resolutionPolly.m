function simulation = resolutionPolly(xdata,rawSimulation,resolutionValues,points)
% Apply resolution correction

simulation = zeros(points,1);

for j = 1:points

    ilow = max(-10, -j + 1);
    ihi = min(10, points - j);

    g = exp(-1*((xdata(j+ilow:j+ihi)-xdata(j))/(resolutionValues(j)*xdata(j))).^2);
    sumg = sum(g);
    simulation(j) = sum(rawSimulation(j+ilow:j+ihi) .* g) / sumg;

end

end
