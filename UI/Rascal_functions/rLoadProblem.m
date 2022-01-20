function problem = rLoadProblem(path,name)

cd(path);
problem = load(name);
problem = problem.problem;

% Check that this is an R2 problem...
thisClass = class(problem);
if ~strcmpi(thisClass,'projectClass');
    error('%s is not a RAT projectClass');
end

%rascalMemoryCleanup();