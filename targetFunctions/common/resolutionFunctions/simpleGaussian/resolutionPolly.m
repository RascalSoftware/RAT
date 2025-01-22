function resolutionCorrection = resolutionPolly(xdata,ydata,resolutionValues,points)
% Apply resolution correction

resolutionCorrection = zeros(points,1);

for j = 1:points

    sumg = 0;
    ilow = max(-10, -j + 1);
    ihi = min(10, points - j);

    for i = ilow:ihi
        g = exp(-1*((xdata(j+i)-xdata(j))/(resolutionValues(j)*xdata(j)))^2);
        sumg = sumg + g;
        resolutionCorrection(j) = resolutionCorrection(j) + ydata(i+j) * g;
    end
    
    if (sumg ~= 0)
        resolutionCorrection(j) = resolutionCorrection(j) / sumg;
    end

end

end
