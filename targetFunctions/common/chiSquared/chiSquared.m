function chi2 = chiSquared(thisData,thisFit,P)
%chi_squared(func,data,numparams,errors)

%allChis = zeros(1,numberOfContrasts);

%     thisData = allData{i};
%     thisFit = allFits{i};
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
    chi2 = 1/(N-P)*sum(terms);
    
    %allChis(i) = chi2;

end