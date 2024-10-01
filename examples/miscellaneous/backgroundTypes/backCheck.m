



% Get the xdata
dat = readmatrix('DSPC_D2O.dat');
xdata = dat(:,1);


% Make the background......
Ao = 8e-6;
k = 70;
const = 2e-7;
b = backgroundFunction(xdata,Ao,k,const);


% Plot it....
figure(2); clf
errorbar(dat(:,1),dat(:,2),dat(:,3));
hold on
plot(xdata,b);
set(gca,'YSCale','log');
