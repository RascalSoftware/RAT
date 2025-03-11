function chi2 = chiSquared(thisData,thisFit,P)
% Chi-squared function is used to evaluate the goodness of fit.
% It is a measure of the difference between the observed and expected.

    y = thisData(:,2);
    eb = thisData(:,3);
    fit = thisFit(:,2);
    
    N = max(size(y));
    if N <= P
        N = (P + 1);
    end
    terms = ((y-fit)./eb).^2;
    n = find(terms == Inf);
    if ~isempty(n)
        terms(n) = 0;
    end
    chi2 = sum(terms)/(N-P);

end