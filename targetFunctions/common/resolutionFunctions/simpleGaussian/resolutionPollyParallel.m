function out = resolutionPollyParallel(xdata,ydata,resData,points)
% Apply resolution correction

dummydata = zeros(points,1);

parfor j = 1:points
    sumg = 0;
    dummydata(j) = 0;
    res = resData(j);
    
    if (j>10)
        ilow = -10;
    else
        ilow = -j + 1;
    end
    
    if (j < (points - 10))
        ihi = 10;
    else
        ihi = points - j;
    end
    
    for i = ilow:ihi
        g = exp(-1*((xdata(j+i)-xdata(j))/(res*xdata(j)))^2);
        sumg = sumg + g;
        dummydata(j) = dummydata(j) + ydata(i+j) * g;
    end
    if (sumg ~= 0)
        dummydata(j) = dummydata(j) / sumg;
    end
end

out = dummydata;

end