function out = resolution4Column(xdata,ydata,res)


points = length(xdata);

findZeros = (res == 0);
res(findZeros) = eps;

dummydata = zeros(points,1);
dummyref = ydata;

for j = 1:points
    sumg = 0;
    dummydata(j) = 0;
    
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
        thisRes = res(j+i);
        g = exp(-1*((xdata(j+i)-xdata(j))/(thisRes*xdata(j)))^2);
        sumg = sumg + g;
        dummydata(j) = dummydata(j) + dummyref(i+j) * g;
    end
    if (sumg ~= 0)
        dummydata(j) = dummydata(j) / sumg;
    end

end

out = dummydata;

end