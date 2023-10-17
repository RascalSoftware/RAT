function allPredInts = refPrctileConfInts(bayesOutputs,problemDef,problemDefCells,problemDefLimits,controlsStruct,result,parConfInts)

% Need to deal slightly differently with SLDs if there are domains
if strcmpi(problemDef.TF,'domains')
    domains = true;
else
    domains = false;
end

CIFn = @(x,p)prctile(x,abs([0,100]-(100-p)/2));
chain = bayesOutputs.chain;

% Calc the ref and SLD for the first row of the chain. This 'sticks' the x
% values of each that we then interpolate the values from the rest of the
% cain onto....
firstRow = chain(1,:); 
problemDef.fitpars = firstRow;
problemDef = unpackparams(problemDef,controlsStruct);

% Calc the reflectivities....
[calcProblem,calcResult] = reflectivityCalculationWrapper(problemDef,problemDefCells,problemDefLimits,controlsStruct);

% 'result' is currently a cell array. Convert this to a struct because it's
% easier to work with fieldnames...
calcResult = parseResultToStruct(calcProblem,calcResult);

thisRef = calcResult.reflectivity;
thisSld = calcResult.sldProfiles;

% so each is a {n x 1} cell array, because of n contrasts. 
% Prepare some arrays to hold the SLD's and Refs for all the chain, keeping only the Y vales.
% We'll save x values in a separate array
numberOfContrasts = problemDef.numberOfContrasts;

vals = zeros(1,3);
coder.varsize('vals',[1e4 1e4],[1 1]);

rowVals = zeros(1,3);
coder.varsize('rowVals',[1 1e4],[0 1]);

ref_xVals = makeCell(numberOfContrasts,rowVals); %cell(numberOfContrasts,1);
ref_yVals = makeCell(numberOfContrasts,vals); %cell(numberOfContrasts,1);

sld_xVals = makeCell(numberOfContrasts,rowVals);
if ~domains
    sld_yVals = makeCell(numberOfContrasts,vals);
else
    sld_yVals = makeCell2D(numberOfContrasts,vals);
end

% We need to have the yvals interpolated onto the same xvals when we
% calculate the sample. So, take the current reflectivity value from above
% to get the 'base' x for ref and SLD, then all following
% interpelations are onto these x values....
for i = 1:numberOfContrasts
    ref_xVals{i} = thisRef{i}(:,1)';        % Transpose these into rows for storage
    if ~domains
        sld_xVals{i} = thisSld{i}(:,1)';
    else
        for m = 1:2
            sld_xVals{i,m} = thisSld{i,m}(:,1)';
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
    ref = thisRef{i};
    nRefPoints = size(ref,1);
    emptyRefArray = zeros(nsample,nRefPoints);
    ref_yVals{i} = emptyRefArray;

    sld = thisSld{i};
    nSldPoints = size(sld,1);
    emptySldArray = zeros(nsample,nSldPoints);
    sld_yVals{i} = emptySldArray;
end

% Calculate all the samples....
for i = 1:nsample

    thisChain= chain(isample(i),:);

    problemDef.fitpars = thisChain;
    problemDef = unpackparams(problemDef,controlsStruct);

    % Calc the reflectivities....
    [calcProblem,calcResult] = reflectivityCalculationWrapper(problemDef,problemDefCells,problemDefLimits,controlsStruct);

    % 'result' is currently a cell array. Convert this to a struct because it's
    % easier to work with fieldnames...
    calcResult = parseResultToStruct(calcProblem,calcResult);
    
    thisRef = calcResult.reflectivity;
    thisSld = calcResult.sldProfiles;
    sampleChi(i) = calcResult.calculationResults.sum_chi;

    for n = 1:numberOfContrasts

        thisXval = ref_xVals{n};
        thisYval = interp1(thisRef{n}(:,1),thisRef{n}(:,2),thisXval,'linear','extrap');
        ref_yVals{n}(i,:) = thisYval;   % Automatically comes back as a row from inpterp1
        
        if ~domains
            this_sldXVal = sld_xVals{n};
            thisSLDYval = interp1(thisSld{n}(:,1),thisSld{n}(:,2),this_sldXVal);
            sld_yVals{n}(i,:) = thisSLDYval;
        else
            for m = 1:2
                this_sldXVal = sld_xVals{n,m};
                thisSLDYval = interp1(thisSld{n,m}(:,1),thisSld{n,m}(:,2),this_sldXVal);
                sld_yVals{n,m}(i,:) = thisSLDYval;
            end
        end

    end
end 

% Calculate the percentiles across all the calculated samples for each
% point in x... We calculate 95% and 65% CI's for each set of curves
ref_Errors = cell(numberOfContrasts(1),1);
for i = 1:numberOfContrasts
    thisXval = ref_xVals{i};
    thisYvals = ref_yVals{i};
    
    cols = size(thisYvals,2);
    refArray = zeros(5,cols);
    
    % We could possibly use CIFn in one shot here (rather than loop over
    % points....)
    for points = 1:cols
        thisCol = thisYvals(:,points);
        CI_95 = CIFn(thisCol,95);
        CI_65 = CIFn(thisCol,65);
        meanRef = mean(thisCol);
        refArray(:,points) = [CI_95(1) CI_65(1) meanRef CI_65(2) CI_95(2)]';
    end
    ref_Errors{i} = refArray;
end

% TODO: need to add domains here....
sld_Errors = cell(numberOfContrasts(1),1);
for i = 1:numberOfContrasts
    thisSldYvals = sld_yVals{i};
    
    cols = size(thisSldYvals,2);
    sldArray = zeros(5,cols);
    for points = 1:cols
        thisCol = thisSldYvals(:,points);
        CI_95 = CIFn(thisCol,95);
        CI_65 = CIFn(thisCol,65);
        meanSld = mean(thisCol);
        sldArray(:,points) = [CI_95(1) CI_65(1) meanSld CI_65(2) CI_95(2)]';
    end
    sld_Errors{i} = sldArray;
end

allPredInts.refPredInts = ref_Errors;
allPredInts.sldPredInts = sld_Errors;
allPredInts.refXdata = ref_xVals;
allPredInts.sldXdata = sld_xVals;
allPredInts.sampleChi = sampleChi;

end

function z = makeCell(n,vals)
%#codegen
% assert(n < 100);
x = cell(n,1);   
for i = 1:n
    x{i} = vals;
end
z = x;
end

function z = makeCell2D(n,vals)
%#codegen
% assert(n < 100);
x = cell(n,2);   
for i = 1:n
    x{i,1} = vals;
    x{i,2} = vals;
end
z = x;
end
