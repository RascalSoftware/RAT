function problemDef = fitcontrol(problemDef,controls)

[problem,out] = fitsetup(problem);
if strcmp(out{1},'fail')
    return
end

controlsPanel = getappdata(0,'controlsPanel');
awtinvoke(controlsPanel,'changeIconToHourglass');
statusBox = getappdata(0,'statusBox');

%3 Decide what we're fitting and call
%the correct fitting algorithm
switch problem.algorithm
    case 'simplex'
        awtinvoke(statusBox,'setText','Running Simplex');
        problem.Update = 50;
        problem = rascal_simplex(problem);
    case 'cmaes';
        awtinvoke(statusBox,'setText','Running CMAES');
        problem = rascal_cmaes_scaled(problem,fitopts);
    case 'MCS';
        awtinvoke(statusBox,'setText','Running MCS');
        problem = rascal_mcs(problem);
    case 'DE'
        awtinvoke(statusBox,'setText', 'Running Differential Evolution');
        %problem = rascal_differential_evolution(problem);
        x = rascal_DE_new_test(problem);
        problem.fitpars = x;
end

%problem = hPSO(problem);

%Clean up after the fit.
problem = fitfinish(problem);
awtinvoke(statusBox,'setText','Ready');
awtinvoke(controlsPanel,'changeIconToReady');

%Save everything to memory
setappdata(0,'problem',problem);








