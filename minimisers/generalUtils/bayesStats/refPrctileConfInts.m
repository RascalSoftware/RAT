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
numberOfContrasts = size(thisRef);

for i = 1:numberOfContrasts
    ref_xVals{i} = thisRef{i}(:,1)';        % Transpose these into rows for storage
    ref_yVals{i} = thisRef{i}(:,2)';
    
    if ~domains
        sld_xVals{i} = thisSld{i}(:,1)';
        sld_yVals{i} = thisSld{i}(:,2)';
    else
        for m = 1:2
            sld_xVals{i}{m} = thisSld{i}{m}(:,1)';
            sld_yVals{i}{m} = thisSld{i}{m}(:,2)';
        end
    end
end

% Loop over the whole chain, collecting the Sld's and Refs together into
% one array for each contrast.
numberOfSims = size(chain,1);   %will be = nsimu

% To speed things up, we'll take a random sample of the chain, rather than
% calculating 20000 reflectivities...
nsample = 1000;
isample = ceil(rand(nsample,1)*numberOfSims);


for i = 2:nsample

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
        thisYval = interp1(thisRef{n}(:,1),thisRef{n}(:,2),thisXval);
        ref_yVals{n}(i,:) = thisYval';
        
        if ~domains
            this_sldXVal = sld_xVals{n};
            thisSLDYval = interp1(thisSld{n}(:,1),thisSld{n}(:,2),this_sldXVal);
            sld_yVals{n}(i,:) = thisSLDYval';
        else
            for m = 1:2
                this_sldXVal = sld_xVals{n}{m};
                thisSLDYval = interp1(thisSld{n}{m}(:,1),thisSld{n}{m}(:,2),this_sldXVal);
                sld_yVals{n}{m}(i,:) = thisSLDYval';
            end
        end

    end
end
    

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

% TODO: need to fix this for domains....
sld_Errors = 0;
% sld_Errors = cell(numberOfContrasts(1),1);
% for i = 1:numberOfContrasts
%     thisSldXval = sld_xVals{i};
%     thisSldYvals = sld_yVals{i};
%     
%     cols = size(thisSldYvals,2);
%     sldArray = zeros(5,cols);
%     for points = 1:cols
%         thisCol = thisSldYvals(:,points);
%         CI_95 = CIFn(thisCol,95);
%         CI_65 = CIFn(thisCol,65);
%         meanSld = mean(thisCol);
%         sldArray(:,points) = [CI_95(1) CI_65(1) meanSld CI_65(2) CI_95(2)]';
%     end
%     sld_Errors{i} = sldArray;
% end

allPredInts.refPredInts = ref_Errors;
allPredInts.sldPredInts = sld_Errors;
allPredInts.refXdata = ref_xVals;
allPredInts.sldXdata = sld_xVals;
allPredInts.sampleChi = sampleChi;

end