function parseTest()

c = makeContrast('Name','Hello');
disp(c);

c = makeContrast('background','Background 1');
disp(c);


end

function out = makeContrast(varargin)

defaultName = 'Contrast';
defaultBack = '';
defaultData = '';
defaultNba = '';
defaultNbs = '';
defaultResol = '';
defaultModel = {};

expectedBacks = {'Background 1', 'Background 2'};


p = inputParser;

addParameter(p,'name',defaultName,@ischar);
addParameter(p,'background',defaultBack,@(x) any(validatestring(x,expectedBacks)));
addParameter(p,'data',defaultData,@ischar);
addParameter(p,'nba',defaultNba,@ischar);
addParameter(p,'nbs',defaultNbs,@ischar);
addParameter(p,'resolution',defaultResol,@ischar);
addParameter(p,'model',defaultModel,@iscell);

parse(p,varargin{:});

out = p.Results;


end