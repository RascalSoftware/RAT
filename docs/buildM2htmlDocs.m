% Download m2html and place it in 3rdParty
cd('..') 
path  = ['3rdParty', '/m2html'];
addpath(path)

m2html('mfiles',{'targetFunctions','API'},'htmldir','docs/build/html/api_reference', 'recursive','on',... 
'global','on','template','frame', 'index', 'menu', 'graph', 'on', 'source', 'on');

% Docs are in the docs folder
disp('The m2html docs are in docs/build/html/api_reference')
