% Set up a fit for the c1 sam data using the new model

% Add function paths...
rootPath = '/Users/arwel/Dropbox/ALC_project_Hub/New Stuff/MD_bilayers_work/Fits and Sims';
addpath(fullfile(rootPath,'Fits','functions'));
addpath(fullfile(rootPath,'Fits','Gaussian Sam Only Compares','functions'));
addpath(fullfile(pwd,'dataFiles'));


% Make the project class
problem = projectClass('C1 fit');

% We need a custom XY model
problem.setModelType('Custom XY');
problem.setGeometry('substrate/liquid');

% Add the parameters
paramsGroup = {{'Oxide thick',  0,      24,      50,     true};
               {'Alloy thick',  20,     46,    100     true};
               {'Alloy rough',  1,      7,      10      true};
               {'Alloy SLD'  ,  6e-6,   10e-6,   12e-6  true};
               {'Gold Thick',   50,     188,    250     true};
               {'Gold SLD',     3e-6,   4e-6,   5e-6    true};
               {'Gold rough',   1,      5,      10      true};
               {'SAM APM',      45,     55,     75      true};
               {'SAM Rough',    1,      2.7,      10      true};
               {'SAM coverage', 0.75,   0.7,      1       true};
               {'Acg',          1,      3.3,      4       true};
               {'Apc',          1,      3.7,      4       true};
               {'Zpc',          2,      4,      6       true};
               {'Tail thick',   13,     16,     18      true}};
               
problem.addParamGroup(paramsGroup);
problem.setParameter(1,'max',10);

% Add nbsub
problem.addBulkIn({'Silicon',2.0e-6,2.073e-6,2.1e-6,false});

% And the Nbairs
problem.addBulkOut({'SLD SMW',1.0e-6,1.75e-6,3e-6,true});
problem.addBulkOut({'SLD 4MW',3.0e-6,3.65e-6,5.5e-6,true});
problem.addBulkOut({'SLD H2O',-0.5e-6,0,1e-6,true});
problem.setBulkOut(1,'min',5e-6','fit',true);

% Set the scalefactor 
problem.setScalefactor(1,'min',0.1,'max',1.0,'fit',true);
problem.setScalefactor(1,'value',0.19);

problem.addScalefactor({'Scalefactor 2',0.1,0.19,1.0,true});
problem.addScalefactor({'Scalefactor 3',0.1,0.17,1.0,true});
problem.addScalefactor({'Scalefactor 4',0.1,0.18,1.0,true});

% Now make the background parameters
problem.addBacksPar('Backs Val D2O',1e-8,1e-6,1e-4,true);
problem.addBacksPar('Backs Val 4MW',1e-8,1e-6,1e-4,true);
problem.addBacksPar('Backs Val SMW',1e-8,1e-6,1e-4,true);
problem.addBacksPar('Backs Val H2O',1e-8,1e-6,1e-4,true);

% Make the background.
problem.addBackground('Background D2O','constant','Backs Val D2O');
problem.addBackground('Background 4MW','constant','Backs Val SMW');
problem.addBackground('Background SMW','constant','Backs Val SMW');
problem.addBackground('Background H2O','constant','Backs Val H2O');

problem.setResolPar(1,'fit',true);

% add the custom file....
problem.addCustomFile({'two gauss sam','alloy_gold_twoGaussSam_non_polarised_mex.m','matlab','pwd'});

% Add the datafiles...
d2oDat = dlmread('gold_sam_d2o_inter.dat');
gmwDat = dlmread('gold_sam_4mw_inter.dat');
smwDat = dlmread('gold_sam_smw_inter.dat');
h2oDat = dlmread('gold_sam_h2o.dat');

problem.addData('D2O',d2oDat);
problem.addData('4MW',gmwDat);
problem.addData('SMW',smwDat);
problem.addData('H2O',h2oDat);
% 
% problem.setData(2,'dataRange',[0.0131 0.22]);
% problem.setData(3,'dataRange',[0.0131 0.22]);
% problem.setData(4,'dataRange',[0.0131 0.22]);

problem.addContrast('name','D2O Contrast',...
                    'Data','D2O',...
                    'Background','Background D2O',...
                    'nba','Silicon',...                    
                    'nbs','SLD D2O',...
                    'Scalefactor','Scalefactor 1',...
                    'Resolution','Resolution 1',...
                    'Resample',true);
                
problem.setContrastModel(1,'two gauss sam');

problem.addContrast('name','4MW Contrast',...
                    'Data','4MW',...
                    'Background','Background 4MW',...
                    'nba','Silicon',...
                    'nbs','SLD 4MW',...
                    'Scalefactor','Scalefactor 2',...
                    'Resolution','Resolution 1',...
                    'Resample',true);
                
problem.setContrastModel(2,'two gauss sam');

problem.addContrast('name','SMW Contrast',...
                    'Data','SMW',...
                    'Background','Background SMW',...
                    'nba','Silicon',...
                    'nbs','SLD SMW',...
                    'Scalefactor','Scalefactor 3',...
                    'Resolution','Resolution 1',...
                    'Resample',true);
                
problem.setContrastModel(3,'two gauss sam');

problem.addContrast('name','H2O Contrast',...
                    'Data','H2O',...
                    'Background','Background H2O',...
                    'nba','Silicon',...
                    'nbs','SLD H2O',...
                    'Scalefactor','Scalefactor 4',...
                    'Resolution','Resolution 1',...
                    'Resample',true);
                
problem.setContrastModel(4,'two gauss sam');




% controls = controlsDef();
% [problem,result] = RAT(problem,controls);
% 
% figure(1); clf
% plotRefSLD(problem,result);




               