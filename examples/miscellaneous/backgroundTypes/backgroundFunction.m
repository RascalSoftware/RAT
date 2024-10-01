function background = backgroundFunction(xdata,params)

% Split up the params array....
Ao = params(1);
k = params(2);
backConst = params(3);

% Make an exponential decay background....
background = zeros(numel(xdata),1);
for i = 1:numel(xdata)
    background(i) = Ao*exp(-k*xdata(i)) + backConst;
end


end