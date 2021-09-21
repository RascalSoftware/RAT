function mainRat()


% Try to run the ORSO example using paramonte
clear

% Make problem from the script
problem = orsoDSPC_custLay_script();
controls = controlsDef();

% Split problem using the routines from RAT..
[problemDef,problemDef_cells,problemDef_limits,priors,controls] = RatParseClassToStructs_new(problem,controls);

% Make an instance of the paramonte objective function class
logFunc = orsoLogFunc();

[problemDef,fitNames] = packparams(problemDef,problemDef_cells,problemDef_limits,controls.checks);
nDims = length(problemDef.fitpars);

% Scale the parameters
problemDef = scalePars(problemDef);


logFunc.problemDef = problemDef;
logFunc.problemDef_cells = problemDef_cells;
logFunc.problemDef_limits = problemDef_limits;
logFunc.controls = controls;
logFunc.NDIM = nDims;

% Make sure this runs and we get a sensible answer
testPars = problemDef.fitpars;
val = logFunc.get(testPars);

% Try to calculate the hessian,,,
hess = hessian_test(@chiFunc,problemDef.fitpars);
covMat = inv(hess);

logFunc.COVMAT = covMat;

% Create a laraMonte object
pm = paramonte();

% create a ParaDRAM simulation object
pmpd = pm.ParaDRAM();
          
pmpd.spec.outputFileName = "./out/"; 
pmpd.spec.startPointVec = problemDef.fitpars;
pmpd.spec.domainLowerLimitVec = problemDef.fitconstr(:,1);
pmpd.spec.domainUpperLimitVec = problemDef.fitconstr(:,2);
pmpd.spec.overwriteRequested = true;
pmpd.spec.scaleFactor = 1e-6;
pmpd.spec.adaptiveUpdatePeriod = 8*nDims;
pmpd.spec.outputFileName = fullfile(pwd,'out','pdramRun');
pdram.spec.overwriteRequested = true;

%pmpd.spec.mpiEnabled = true;
pmpd.spec.parallelizationModel = 'singleChain';

pmpd.runSampler ( logFunc.NDIM  ... number of dimensions of the objective function
                , @logFunc.get  ... the objective function
                );
            
           
    function chi = chiFunc(params)
        
        chi = abs(logFunc.get(params))*2;
        
    end

end







