figure(3)
clf
hold on

b = load('timMulti');
a = load('timSingle');


plot(a(:,1),a(:,2),'bo','LineWidth',1.2);
plot(b(:,1),b(:,2),'ro','LineWidth',1.2);


y1 = 0.00072*a(:,1) + 0.0018;
plot(a(:,1),y1,'b-','LineWidth',1.2)

y2 = 1.1216e-05*b(:,1) + 0.0020097;
plot(a(:,1),y2,'r-','LineWidth',1.2)