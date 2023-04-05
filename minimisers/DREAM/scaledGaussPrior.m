function pVal2 = scaledGaussPrior(m,extras)


problem = extras.problemDef;
% problemDef_cells = extras{2};
% problemDef_limits = extras{3};
% controls = extras{4};
priorList = extras.priors;

% All are in range, so check for Gaussian priors....
% We pick out any priors that are Gaussians and calculate the mvnpdf
usedPriorInd = find(strcmpi(priorList(:,1),'gaussian'));

% if ~isempty(gaussPriors)    % There may be no Gaussian priors defined!
%     mus = [priorList{gaussPriors,2}];
%     sigs = [priorList{gaussPriors,3}];
%     pdf = mvnorpf(m(gaussPriors),mus,sigs);
%     %pdf = mvnpdf(m(gaussPriors),mus,sigs);
%     logPrior = pdf;%log(pdf);
% else
%     logPrior = 0;
% end

priorfun = @(th,mu,sig) sum(((th-mu)./sig).^2);
fitConstr = problem.fitconstr;

usedPriors = priorList(usedPriorInd,:);
usedConstr = fitConstr(usedPriorInd,:);
usedVals = m(usedPriorInd)';


if ~isempty(usedPriorInd)    % There may be no Gaussian priors defined!
    %     mus = [priorList{usedPriorInd,2}];
    %     sigs = [priorList{usedPriorInd,3}];
    %     x = m(usedPriorInd);
    %     for i = 1:length(x)
    %         p(i) = normpdf(x(i),mus(i),sigs(i));
    %     end
    %     prior = sum(p);

    mu = [usedPriors{:,2}]';
    sig = [usedPriors{:,3}]';
    sigAdd = sig + usedConstr(:,1); % Scale (minVal+prior) will give scaled sigma since minVal goes to 0...

    muSc = rescale(mu,'InputMin',usedConstr(:,1),'InputMax',usedConstr(:,2));
    sigSc = rescale(sigAdd,'InputMin',usedConstr(:,1),'InputMax',usedConstr(:,2));
    valsSc = rescale(usedVals,'InputMin',usedConstr(:,1),'InputMax',usedConstr(:,2));

    pVal2 = priorfun(valsSc,muSc,sigSc);

    pVal2 = -pVal2;

else
    pVal2 = 0;
end