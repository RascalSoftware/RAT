

data = dlmread('linearData.dat');
p = [2 0.2];

x = data(:,1);
y = data(:,2);
e = data(:,3);

line = (p(1)*x) + p(2);

fval = sum(((y-line).^2)./e)

figure(1)
clf;hold on
errorbar(x,y,e,'bo');
plot(x,line);

