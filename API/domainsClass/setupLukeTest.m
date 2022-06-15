clear
addpath('lukeTest');


problem = domainsClass('Luke Test');
problem.setModelType('custom layers');
problem.setGeometry('Substrate/liquid');

Parameters = {  
     {  'SiO2_thickness'                 5        28.163       70    true }; 
     {  'SiO2_SLD'                   2e-06    4.4148e-06    8e-06    true }; 
     {  'SiO2_roughness'                 2            10       10    true }; 
     {  'Permalloy_Thickness'          100        142.31      300    true }; 
     {  'Permalloy SLD'              5e-06    9.4718e-06    1e-05    true }; 
     {  'Permalloy roughness'            2        10.924       20    true }; 
     {  'Gold_thickness'                80        151.67      200    true }; 
     {  'Gold_roughness'                 2        6.0856       15    true }; 
     {  'Thiol_APM'                     15        27.862      300    true }; 
     {  'Thiol_Cov'                      0             1        1    true }; 
     {  'Thiol_roughness'                0        4.3098       10    true }; 
     {  'Central Water Thickness'        0        14.642       30    true }; 
     {  'Central Water Roughness'        2             5        8    true }; 
     {  'Lipid APM'                      0        61.957      200    true }; 
     {  'Head bound waters'              2             2       10    true }; 
     {  'BIlayer Coverage '              0       0.98771        1    true }; 
     {  'Bilayer roughness'              2        5.9934       30    true };
     {  'Pemalloy SLD up',            5e-6,       7e-6,     11e-6    true };    
     };
 
 problem.addParamGroup(Parameters);
 problem.setParameter(1,'min',1,'max',10);
 
 %%
 problem.setBulkIn(1,'name','Silicon','min',2.07e-6,'value',2.073e-6,'max',2.08e-6,'fit',false);

% Add two more values for bulk out....
problem.addBulkOut({'SLD SMW',1e-6,2.073e-6,3e-6,true});
problem.addBulkOut({'SLD H2O',-0.6e-6,-0.56e-6,-0.3e-6,true});
problem.addBulkOut({'SLD Aumw',4e-6,4.8e-6,5e-6,true});

problem.setBulkOut(1,'fit',true,'min',5e-6);
 
 
%%
d2oDat = dlmread('IvsQ_133408_133409_133410_script.dat');
problem.addData('D2O Contrast', d2oDat);


%%
problem.addCustomFile({'DSPC Model','customFileWrapper.m','matlab',fullfile(pwd,'lukeTest')});
 
 
 