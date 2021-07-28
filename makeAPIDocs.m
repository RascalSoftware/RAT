addpath('/Users/arwel/Documents/coding/RAT/Docs/m2html');

rootDir = '/Users/arwel/Documents/coding/RAT/API';
ratRoot = '/Users/arwel/Documents/coding/RAT';

dirs = {'minimisers';
    'DE';
    'mcmcstat_new';
    'NSMain';
    'simplex';
    'DE';
    };

docDir = fullfile(ratRoot,'Docs','MinimisersDocs');

m2html('mfiles',dirs,'htmldir',docDir,'recursive','on','global','on',... 
          'template','frame', 'index','menu','graph','on','source','on');