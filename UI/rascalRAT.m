function rascalRAT(varargin)

% Start by adding the relevant paths 
addRascalPaths;
rascalPath = getappdata(0,'rascalPath');

startPath = fullfile(rascalPath,'defaultProject');
%startName = 'defaultProject.mat';
startName = 'monolayersExample.mat';
inputProblem = rLoadProblem(startPath,startName);

% Make a controls block
controls = controlsDef();

% Call RAT
[calcProblem,results] = RAT(inputProblem,controls);

% Put everything together
problem.problem = calcProblem();
problem.results = results;

setappdata(0,'problem',problem);
setappdata(0,'controls',controls);

% Make the UI
rascal_initfigs();

end

