function y = calculationFun(x,theta);
debug = 0;

%theta = [3; 3e-7; 0.08];

%x = data.xdata;
y = abeles(x,[0 0 0],0,6.35e-6,1,theta(1),1,length(x));
y = y .* theta(2);
y = y + 3e-7;


switch debug
    case 1
        data = getappdata(0,'refData');
        figure(2)
        clf
        semilogy(x,data(:,2),'o');
        hold on
        plot(x,y)
end
