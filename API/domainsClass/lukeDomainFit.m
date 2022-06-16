% Luke Domains Fit.
addpath('lukeTest');
clear

% First start by maing a domainClass object from the R1 model...
problem = r1ToDomainsClass('Si2 PyAu HSC11EG3OH POPC.mat');


% Need to set the domainRatio for each contrast
numberOfContrasts = problem.reflContrast.numberOfContrasts;
for i = 1:numberOfContrasts
    problem.setReflContrast(i,'domainRatio','Domain Ratio 1');
end


% Set up the controls class
controls = controlsDef();

% Send this to RAT
[problem,results] = RAT(problem,controls);

