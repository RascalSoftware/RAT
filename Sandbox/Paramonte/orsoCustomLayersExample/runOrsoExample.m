%clear

problemDefInput = orsoDSPC_custLay_script();
controls = controlsDef();

tic
[chainTable,logFunc,outProblem] = runParamonte_scaled(problemDefInput,controls);
toc

chain = chainTable{:,8:end};
parNames = chainTable.Properties.VariableNames(8:end);

% Need to unscale the parameters before we plot them
problemDef = outProblem{1};%logFunc.problemDef;
limits = problemDef.fitconstr;
problemDef_cells = outProblem{4};

% Unscale the samples..
numberOfParameters = size(chain,2);
for i = 1:numberOfParameters
    theseLims = limits(i,:);
    chain(:,i) = (chain(:,i).*(theseLims(:,2)-theseLims(:,1)))+theseLims(:,1);
end

figure(1); clf
cols = 4;
rows = ceil(numberOfParameters/cols);

for i = 1:numberOfParameters
    thisParam = chain(:,i);
    subplot(rows,cols,i);
    hold on
    histogram(thisParam,'Normalization','pdf');
    title(parNames{i});
end

% Put everything into the correct format for processBayes to work....
numberOfContrasts = problemDef.numberOfContrasts;

data = cell(1,numberOfContrasts);
for i = 1:numberOfContrasts
    thisData = problemDef_cells{2}{i};
    data{i} = [thisData(:,1:2)];
    %data{i}.problem = problem;
end

output.s2chain = [];
output.sschain = [];
output.data = data;
output.chain = chain;
output.results.mean = mean(chain,1);
output.results.parind = 1:numberOfParameters;
output.results.local = zeros(1,numberOfParameters);
output.results.theta = chain(end,:);
output.results.nsimu  = size(chain,1);
output.results.nbatch = 3;

[problem,result,bayesResults] = processBayes(output,parNames,outProblem);

result = parseResultToStruct(problem,result);

result = mergeStructs(result,bayesResults);
result.bestFitPars = bayesResults.bestPars_Max;
result.fitNames = parNames;

outProblemDef = RATparseOutToProjectClass(problemDefInput,problemDef,problem,result);


