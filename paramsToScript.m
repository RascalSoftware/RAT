function params = paramsToScript(problem)

% Converts the parameters table to a printed table for a script

format short
paramsTable = problem.parameters.paramsTable;

[nParams,~] = size(paramsTable);

%Print the params definition:
fprintf('params = { \n');

% Print the table contents row by row:
for i = 1:nParams
    thisName = paramsTable{i,1};
    thisMin = paramsTable{i,2};
    thisVal = paramsTable{i,3};
    thisMax = paramsTable{i,4};
    thisFit = paramsTable{i,5};
    
    if thisFit == 1
        thisFit = 'true';
    else
        thisFit = 'false';
    end
    
    fprintf('{ ''%s'' \t %g \t %g \t %g \t %s \t}; \n',...
        thisName, thisMin, thisVal, thisMax, thisFit)
end

fprintf('};');

end
