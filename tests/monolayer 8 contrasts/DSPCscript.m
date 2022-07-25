% Analysis of DSPC monolayers Data

% First make an instance of the project class
problem = projectClass('DSPC monolayers');

problem.setGeometry('substrate/liquid');


% Define the parameters:
Parameters = {
    %       Name                min     val     max     fit? 
    {'Tails Thickness',         10,     20,     30,     true};
    {'Heads Thickness',          3,     11,     16,     true};
    {'Tails Roughness',          2,     5,      9,      true};
    {'Heads Roughness',          2,     7,      9,      true};
    {'Deuterated Tails SLD',    4e-6,   6e-6,   2e-5,   true};
    {'Hydrogenated Tails SLD', -0.6e-6, -0.4e-6, 0,     true};
    {'Deuterated Heads SLD',    1e-6,   3e-6,   8e-6,   true};
    {'Hydrogenated Heads SLD',  0.1e-6,   1.4e-6, 3e-6,   true};
    {'Heads Hydration',         0,      10,   0.5,    true};
    };

problem.setParameter(1,'value',3);     % Sub rough

% Group these into layers:
H_Heads = {'Hydrogenated Heads',...
                'Heads Thickness',...
                'Hydrogenated Heads SLD',...
                'Heads Roughness',...
                'Heads Hydration',...
                'bulk out' };
            
D_Heads = {'Deuterated Heads',...
                'Heads Thickness',...
                'Deuterated Heads SLD',...
                'Heads Roughness',...
                'Heads Hydration',...
                'bulk out' };
            
            
D_Tails = {'Deuterated Tails',...
                'Tails Thickness',...
                'Deuterated Tails SLD',...
                'Tails Roughness'};%,...
                %'Tails Hydration',...
                %'bulk in'};

H_Tails = {'Hydrogenated Tails',...
                'Tails Thickness',...
                'Hydrogenated Tails SLD',...
                'Tails Roughness'};%,...
                %'Tails Hydration',...
                %'bulk in'};

% Add the parameters and Layers to the project:
problem.addParamGroup(Parameters);
problem.addLayerGroup({H_Heads; D_Heads; H_Tails; D_Tails});

% Increase the constr range for Substrate Roughness (param 1)
problem.setParamConstr(1,2,13);

% Use priors in the project
problem.setUsePriors(true);

% Need two backgrounds - one for D2O and for H2O
% Change the name of the first and add a new one for the second
% Also need a new backsPar
problem.setBacksParName(1,'Backs value ACMW');
problem.setBacksParValue(1,5.5e-6);
problem.addBacksPar('Backs Value D2O',1e-8,2.8e-6,1e-5);

problem.addBackground('Background D2O','constant','Backs Value D2O');
problem.setBackgroundValue(1,'name','Background ACMW');
problem.setBackgroundValue(1,3,'Backs Value ACMW');

% Also need an additional bulk out
problem.addBulkOut('SLD ACMW',-1e-6,0.0,1e-6,true);

% Add the data files
hD2O = dlmread('hd2o20.dat');
d13D2O = dlmread('d13d2o20.dat');
d83D2O = dlmread('d83d2o20.dat');
d13ACM = dlmread('d13acmw20.dat');
d70ACM = dlmread('d70acmw20.dat');

problem.addData('H-tail / H-head / D2O', hD2O);
problem.addData('H-tail / D-head / D2O', d13D2O);
problem.addData('D-tail / D-head / D2O', d83D2O);
problem.addData('H-tail / D-head / ACMW', d13ACM);
problem.addData('D-tail / H-head / ACMW', d70ACM);

% Add the 7 contrasts
problem.addContrast('name','H-tail/H-Head/D2O',...
    'background','Background D2O',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'nbs', 'SLD D2O',...
    'nba', 'SLD air',...
    'data', 'H-tail / H-head / D2O');
problem.setContrastModel(1,{'Hydrogenated tails','Hydrogenated heads'});

problem.addContrast('name','D-tail/H-Head/ACMW',...
    'background','Background ACMW',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'nbs', 'SLD ACMW',...
    'nba', 'SLD air',...
    'data', 'D-tail / H-head / ACMW');
problem.setContrastModel(2,{'deuterated tails','hydrogenated heads'});

problem.addContrast('name','H-tail/D-Head/D2O',...
    'background','Background D2O',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'nbs', 'SLD D2O',...
    'nba', 'SLD air',...
    'data', 'H-tail / D-head / D2O');
problem.setContrastModel(3,{'hydrogenated tails','deuterated heads'});

% problem.addContrast('name','D-tail/D-Head/D2O',...
%     'background','Background D2O',...
%     'resolution','Resolution 1',...
%     'scalefactor', 'Scalefactor 1',...
%     'nbs', 'SLD D2O',...
%     'nba', 'SLD air',...
%     'data', 'D-tail / D-head / D2O');
% problem.setContrast(4,'model',{'deuterated tails','deuterated heads'});
% 
problem.addContrast('name','H-tail/D-Head/ACMW',...
    'background','Background ACMW',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'nbs', 'SLD ACMW',...
    'nba', 'SLD air',...
    'data', 'H-tail / D-head / ACMW');
problem.setContrastModel(4,{'hydrogenated tails','deuterated heads'})

% Set the fitting fitting flag on some parameters we need to fit
problem.setBacksPar(1,'fit',true);
problem.setBacksPar(2,'fit',true);
problem.setScalefactor(1,'fit',true);

% Display problem
% problem
% 
% % Make the controls class...
% controls = controlsDef();
% % controls.calcSldDuringFit = 'no';
% controls.procedure = 'bayes';
% %controls.parallel = 'contrasts';
% % controls.maxIter = 1e9;
% % controls.repeats = 3;
% % controls.nsimu = 5000;
% % controls.burnin = 1000;
% 
% [problem,results] = RAT(problem,controls);
% % 
% % figure(2); clf; drawnow
% % plotmatrix(results.chain)
% 
% % controls.procedure = 'calculate';
% % [problem,results] = RAT(problem,controls);
% chiSq = results.calculationResults.sum_chi;
% % 
% figure(1); clf
% plotRefSLD(problem,results)
% 
% % for i = 1:4
% %     problem.setContrast(i,'resample',false);
% % end
% 
% % controls.procedure = 'calculate';
% % [problem,results] = RAT(problem,controls);
% % resChiSq = results.calculationResults.sum_chi;
% % 
% % fprintf('Normal Chi Squared is %f \n', chiSq);
% % fprintf('Resampled Ch Squared is %f \n', resChiSq);
% 
% figure(1); clf
% plotRefSLD(problem,results);
% 
% % layerSLDs = results.layerSlds;
% % sldProfiles = results.sldProfiles;
% % ssub = results.contrastParams.ssubs(1);
% 
% % figure(2); clf; hold on
% % for i = 1:length(sldProfiles)
% %     thisSld = sldProfiles{i};
% %     
% %     thisLayers = layerSLDs{i};
% %     nbair = thisLayers(1,2);
% %     nbsub = thisLayers(end,2);
% %     numberOfLayers = size(thisLayers,1);
% %     nrepeats = 1;
% %     
% %     newProf = makeSLDProfileXY(nbair,nbsub,ssub,thisLayers,numberOfLayers,nrepeats);
% %     
% %     plot(thisSld(:,1),thisSld(:,2));
% %     plot(newProf(:,1)-50,newProf(:,2));
% %     
% % end
% % xlim([0 150]);
% 
% 
% 
% 
