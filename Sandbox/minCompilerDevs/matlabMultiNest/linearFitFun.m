function fval = linesrFitFun(data,model,names,p);

%data, model, parnames, parvals
p = cell2mat(p);

x = data(:,1);
y = data(:,2);
e = data(:,3);

line = (p(1)*x) + p(2);

f = sum(((y-line).^2)./e);

fval = -f/2;


end
