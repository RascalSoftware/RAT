% download m2html and place it in matlabroot

% so that the matlabroot dir has a folder called m2html 

% if windows set slash = '\' else set slash = '/'
if ispc
    slash = '\';
else
    slash = '/';
end

path  = [matlabroot,slash,'m2html'];

addpath(path)

m2html('mfiles',{'./targetFunctions','./API'},'htmldir','./docs/source/api_reference', 'recursive','on',... 
'global','on','template','frame', 'index','menu','ignoredDir',{'docs','Docs_old','tests','testSuite','domainsClass'},...
'graph','on','source','on');

% Docs are in the docs folder
disp('The m2html docs are in ./docs/source/api_reference')