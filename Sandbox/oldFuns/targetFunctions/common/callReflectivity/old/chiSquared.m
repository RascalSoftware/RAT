function chi2 = chi_squared(fit,y,P,eb)
%chi_squared(func,data,numparams,errors)


N = max(size(y));
if N <= P
    N = (P + 1);
end
terms = ((y-fit)./eb).^2;
n = find(terms == Inf);
if ~isempty(n)
    terms(n) = 0;
end
chi2 = 1/(N-P)*sum(terms);
end
