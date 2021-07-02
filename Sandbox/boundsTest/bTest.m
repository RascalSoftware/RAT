
x = 1:20;
LB = 7;
UB = 15;

for i = 1:length(x)
    xtrans(i) = (sin(x(i))+1)/2;
    xtrans(i) = xtrans(i)*(UB - LB) + LB;
end

figure(1); clf
plot(i,xtrans)