

addpath('/Users/arwel/Documents/coding/RAT/Docs/m2html');

rootDir = '/Users/arwel/Documents/coding/RAT/targetFunctions';
ratRoot = '/Users/arwel/Documents/coding/RAT';

dirs = {fullfile(rootDir,'common');
    fullfile('common','backSorts');
    fullfile('common','callReflectivity');
    fullfile('common','reflectivityCalculations');
    %%fullfile('common','reflectivityCalculations','Abeles');
    fullfile('common','Resolution_Functions','Simple_Gaussian');
    fullfile('common','costFunctions','chiSquared');
    fullfile('common','groupLayers');
    fullfile('common','makeSLDProfiles');
    fullfile('common','shiftData');
    fullfile('common','standard_layers_mod');
    fullfile('common','resampleLayers');
    fullfile('common','callMatlabFunction');
    fullfile('common','jacobianEst');
    fullfile('reflectivity_calculation');
    fullfile('standard_TF');
    %fullfile('standard_TF','standardTF_stanLay');
    %fullfile('standard_TF','standardTF_custLay');
    %fullfile('standard_TF','standardTF_custXY'); 
    };

docDir = fullfile(ratRoot,'Docs','RefCalcDocs');

m2html_modified('mfiles',dirs,'htmldir',docDir,'recursive','on','global','on',... 
          'template','frame', 'index','menu','graph','on','source','on');




