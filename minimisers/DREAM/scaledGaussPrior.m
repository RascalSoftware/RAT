function pVal2 = scaledGaussPrior(m,extras)
    
    problemStruct = extras.problemStruct;
    priorList = extras.priors;
    
    % All are in range, so check for Gaussian priors....
    % We pick out any priors that are Gaussians and calculate the mvnpdf

    % Find all the Gaussian priors....
    % usedPriorInd = find(strcmpi(priorList(:,1),'gaussian'));

    usedPriorInd = find(priorList(:,1) == 2);

    priorfun = @(th,mu,sig) sum(((th-mu)./sig).^2);
    fitConstr = problemStruct.fitLimits;
    
    usedPriors = priorList(usedPriorInd,:);
    usedConstr = fitConstr(usedPriorInd,:);
    usedVals = m(usedPriorInd);
    
    if ~isempty(usedPriorInd)    % There may be no Gaussian priors defined!
        mu = [usedPriors(:,2)];
        sig = [usedPriors(:,3)];
        sigAdd = sig + usedConstr(:,1); % Scale (minVal+prior) will give scaled sigma since minVal goes to 0...
    
        muSc = rescale(mu,'InputMin',usedConstr(:,1),'InputMax',usedConstr(:,2));
        sigSc = rescale(sigAdd,'InputMin',usedConstr(:,1),'InputMax',usedConstr(:,2));
        valsSc = rescale(usedVals(:),'InputMin',usedConstr(:,1),'InputMax',usedConstr(:,2));
    
        pVal2 = priorfun(valsSc,muSc,sigSc);
    
        pVal2 = -pVal2;
    else
        pVal2 = 0;
    end
end
