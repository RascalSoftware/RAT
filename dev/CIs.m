% x is a vector, matrix, or any numeric array of data. NaNs are ignored.
% p is a the confident level (ie, 95 for 95% CI)
% The output is 1x2 vector showing the [lower,upper] interval values.
CIFcn = @(x,p)std(x(:),'omitnan')/sqrt(sum(~isnan(x(:)))) * tinv(abs([0,1]-(1-p/100)/2),sum(~isnan(x(:)))-1) + mean(x(:),'omitnan'); 
% Demo
x = randn(100,1) + 5; 
p = 95; 
CI = CIFcn(x,p)

% x is a vector, matrix, or any numeric array of data. NaNs are ignored.
% p is the confidence level (ie, 95 for 95% CI)
% The output is 1x2 vector showing the [lower,upper] interval values.
CIFcn = @(x,p)prctile(x,abs([0,100]-(100-p)/2));

x = pearsrnd(0,1,1,4,100,1); 
histogram(x);  
CIFcn = @(x,p)std(x(:),'omitnan')/sqrt(sum(~isnan(x(:)))) * tinv(abs([0,1]-(1-p/100)/2),sum(~isnan(x(:)))-1) + mean(x(:),'omitnan'); 
CI = CIFcn(x,95); 
arrayfun(@(x)xline(x,'-k','tinv'),CI);
CIFcn = @(x,p)prctile(x,abs([0,100]-(100-p)/2));
CI = CIFcn(x,95); 
arrayfun(@(x)xline(x,'-m','prctile'),CI);
