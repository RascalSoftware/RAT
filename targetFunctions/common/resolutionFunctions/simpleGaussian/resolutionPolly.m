function simulation = resolutionPolly(xdata,rawSimulation,resolutionValues,points) %#codegen
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


n_points = zeros(1,points);
sum_d    = zeros(1,points);
for j = 1:points
    ilow = max(-width, -j + 1);
    ihi = min(width, points - j);
    % idx = j+ilow:j+ihi;
    % sumg = exp(-((xdata(idx)/xdata(j)-1)/resolutionValues(j)).^2);
    % simulation(j) = sum(rawSimulation(idx).*sumg)/sum(sumg);
    n_points(j) = ihi-ilow;
    sumg = 0;
    for i = ilow:ihi
        g = exp(-((xdata(j+i)/xdata(j)-1)/resolutionValues(j))^2);
        sumg = sumg + g;
    end
    sum_d(j) = sumg;
end
simulation = zeros(points,1);
for j = 1:points

    ilow = max(-width, -j + 1);
    ihi = min(width, points - j);
    % idx = j+ilow:j+ihi;
    % sumg = exp(-((xdata(idx)/xdata(j)-1)/resolutionValues(j)).^2);
    % simulation(j) = sum(rawSimulation(idx).*sumg)/sum(sumg);
    sumg = 0;
    for i = ilow:ihi
        g = exp(-((xdata(j+i)/xdata(j)-1)/resolutionValues(j))^2);
        sumg = sumg + g;
        %simulation(j) = simulation(j) + rawSimulation(i+j) * exps(11+i);
        simulation(j) = simulation(j) + rawSimulation(i+j) * g;
    end
    simulation(j) = simulation(j) / sumg;
end

end
