function allPredInts = refPercentileConfidenceIntervals(bayesOutputs,problemStruct,controls,results)
% Calculate the percentile confidence intervals for the reflectivity.
%
% Parameters
% ----------
% bayesOutputs : struct
%     The outputs of the Bayesian optimisation.
% problemStruct : struct
%     The struct for the project.
% controls : struct
%     The struct for the controls.
% results : struct
%     The results object from the optimisation.
%
% Returns
% -------
% allPredInts : array
%     The prediction intervals from the optimisation.

% Need to deal slightly differently with SLDs if there are domains
if strcmpi(problemStruct.TF, coderEnums.calculationTypes.Domains)
    domains = true;
else
    domains = false;
end

CIFn = @(x,p)prctile(x,abs([0,100]-0.5*(100-p)));
chain = bayesOutputs.chain;

% Prepare some arrays to hold the SLD's and Refs for all the chain, keeping only the Y values.
% We'll save x values in a separate array
numberOfContrasts = problemStruct.numberOfContrasts;

vals = zeros(1,3);
rowVals = zeros(1,3);

refXVals = makeCell(numberOfContrasts, 1, rowVals);
refYVals = makeCell(numberOfContrasts, 1, vals);


if ~domains
    sldXVals = makeCell(numberOfContrasts, 1, rowVals);
    sldYVals = makeCell(numberOfContrasts, 1, vals);
else
    sldXVals = makeCell(numberOfContrasts, 2, rowVals);
    sldYVals = makeCell(numberOfContrasts, 2, vals);
end

% We need to have the yvals interpolated onto the same xvals when we
% calculate the sample. So, take the input reflectivity and SLD values
% to get the 'base' x for ref and SLD, then all following
% interpolations are onto these x values....
for i = 1:numberOfContrasts
    refXVals{i} = results.reflectivity{i}(:,1)';        % Transpose these into rows for storage
    if ~domains
        sldXVals{i} = results.sldProfiles{i}(:,1)';
    else
        for m = 1:2
            sldXVals{i,m} = results.sldProfiles{i,m}(:,1)';
        end
    end
end

% Loop over the whole chain, collecting the Sld's and Refs together into
% one array for each contrast.
numberOfSims = size(chain,1);   %will be = nsimu

% To speed things up, we'll take a random sample of the chain, rather than
% calculating >20000 reflectivities...
nsample = 1000;
isample = ceil(rand(nsample,1)*numberOfSims);
sampleChi = zeros(nsample,1);

% First, we populate the yVals arrays with zero arrays of the correct size...
for i = 1:numberOfContrasts
    ref = results.reflectivity{i};
    nRefPoints = size(ref,1);
    emptyRefArray = zeros(nsample,nRefPoints);
    refYVals{i} = emptyRefArray;
    if ~domains
        sld = results.sldProfiles{i};
        nSldPoints = size(sld,1);
        emptySldArray = zeros(nsample,nSldPoints);
        sldYVals{i} = emptySldArray;
    else
        sld1 = results.sldProfiles{i,1};
        sld2 = results.sldProfiles{i,2};
        nSldPoints1 = size(sld1,1);
        nSldPoints2 = size(sld2,1);
        emptySldArray1 = zeros(nsample,nSldPoints1);
        emptySldArray2 = zeros(nsample,nSldPoints2);
        sldYVals{i,1} = emptySldArray1;
        sldYVals{i,2} = emptySldArray2;
    end
end

% Calculate all the samples....
for i = 1:nsample

    thisChain= chain(isample(i),:);

    problemStruct.fitParams = thisChain;
    problemStruct = unpackParams(problemStruct);

    % Calc the reflectivities....
    calcResult = reflectivityCalculation(problemStruct,controls);

    thisRef = calcResult.reflectivity;
    thisSld = calcResult.sldProfiles;
    sampleChi(i) = calcResult.calculationResults.sumChi;

    for n = 1:numberOfContrasts

        thisXval = refXVals{n};
        thisYval = interp1(thisRef{n}(:,1),thisRef{n}(:,2),thisXval,'linear','extrap');
        refYVals{n}(i,:) = thisYval;   % Automatically comes back as a row from interp1
        
        if ~domains
            thisSldXVal = sldXVals{n};
            thisSLDYval = interp1(thisSld{n}(:,1),thisSld{n}(:,2),thisSldXVal,'linear','extrap');
            sldYVals{n}(i,:) = thisSLDYval;
        else
            for m = 1:2
                thisSldXVal = sldXVals{n,m};
                thisSLDYval = interp1(thisSld{n,m}(:,1),thisSld{n,m}(:,2),thisSldXVal,'linear','extrap');
                sldYVals{n,m}(i,:) = thisSLDYval;
            end
        end

    end
end 

% Calculate the percentiles across all the calculated samples for each
% point in x... We calculate 95% and 65% CI's for each set of curves
% Reflectivity..
refErrors = cell(numberOfContrasts(1),1);
for i = 1:numberOfContrasts
    thisXval = refXVals{i};
    thisYvals = refYVals{i};
    
    cols = size(thisYvals,2);
    refArray = zeros(5,cols);
    
    % We could possibly use CIFn in one shot here (rather than loop over
    % points....)
    for points = 1:cols
        thisCol = thisYvals(:,points);
        ci95 = CIFn(thisCol,95);
        ci65 = CIFn(thisCol,65);
        meanRef = mean(thisCol);
        refArray(:,points) = [ci95(1) ci65(1) meanRef ci65(2) ci95(2)]';
    end
    refErrors{i} = refArray;
end

% Also the SLD's
if ~domains
    sldErrors = cell(numberOfContrasts(1),1);
    for i = 1:numberOfContrasts
        thisSldYvals = sldYVals{i};

        cols = size(thisSldYvals,2);
        sldArray = zeros(5,cols);
        for points = 1:cols
            thisCol = thisSldYvals(:,points);
            ci95 = CIFn(thisCol,95);
            ci65 = CIFn(thisCol,65);
            meanSld = mean(thisCol);
            sldArray(:,points) = [ci95(1) ci65(1) meanSld ci65(2) ci95(2)]';
        end
        sldErrors{i} = sldArray;
    end
else
    sldErrors = cell(numberOfContrasts(1),2);
    for i = 1:numberOfContrasts
        thisSldYvals1 = sldYVals{i,1};
        thisSldYvals2 = sldYVals{i,2};

        cols1 = size(thisSldYvals1,2);
        cols2 = size(thisSldYvals2,2);

        sldArray1 = zeros(5,cols1);
        sldArray2 = zeros(5,cols2);

        for points = 1:cols1
            thisCol1 = thisSldYvals1(:,points);
            ci951 = CIFn(thisCol1,95);
            ci651 = CIFn(thisCol1,65);
            meanSld1 = mean(thisCol1);
            sldArray1(:,points) = [ci951(1) ci651(1) meanSld1 ci651(2) ci951(2)]';
        end

        for points = 1:cols2
            thisCol2 = thisSldYvals2(:,points);
            ci952 = CIFn(thisCol2,95);
            ci652 = CIFn(thisCol2,65);
            meanSld2 = mean(thisCol2);
            sldArray2(:,points) = [ci952(1) ci652(1) meanSld2 ci652(2) ci952(2)]';
        end

        sldErrors{i,1} = sldArray1;
        sldErrors{i,2} = sldArray2;
    end
end

allPredInts.reflectivity = refErrors;
allPredInts.sld = sldErrors;
allPredInts.sampleChi = sampleChi;

end
