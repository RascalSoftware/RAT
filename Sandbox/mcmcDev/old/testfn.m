function y = modelfun(x,theta);
debug = 1;

theta = [3; 3e-7; 0.08];

x = data.xdata;
y = abeles(x,[0 0 0],0,6.35e-6,1,theta(1),1,length(x));
y = y .* theta(3);
y = y + theta(2);


switch debug
    case 1
        figure(2)
        clf
        semilogy(data.xdata,data.ydata,'o');
        hold on
        plot(data.xdata,y)
end
