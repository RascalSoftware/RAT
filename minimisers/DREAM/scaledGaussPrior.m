function pVal2 = scaledGaussPrior(m,extras)
% Scale a random value to a Gaussian prior.
% 
% Parameters
% ----------
% m : vector
%     The point in parameter space to scale.
% extras : struct
%     Additional problem information, including which dimensions of ``m`` need scaling.
%
% Returns
% -------
% pVal2 : vector
%     The parameter values rescaled to Gaussian priors.
%
    
    problemStruct = extras.problemStruct;
    priorList = extras.priors;
    
    % All are in range, so check for Gaussian priors....
    % We pick out any priors that are Gaussians and calculate the mvnpdf

    usedPriorInd = find(priorList(:,1) == 2);

    priorfun = @(th,mu,sig) sum(((th-mu)./sig).^2);
    fitConstr = problemStruct.fitLimits;
    
    usedPriors = priorList(usedPriorInd,:);
    usedConstr = fitConstr(usedPriorInd,:);
    
    if ~isempty(usedPriorInd)    % There may be no Gaussian priors defined!
        usedVals = m(usedPriorInd);
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
