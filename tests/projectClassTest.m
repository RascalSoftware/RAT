% Write Unit tests for Project class
% Test each method of the class Project 
% under the following conditions:
% 1. The problem has correct name and has a method that assigns an object to the class





% Create a project
%problem = projectClass('somename');
control = controlsDef();
control.procedure = 'bayes';
control.parallel = 'contrasts';




%initialize the projectClass
obj = projectClass('something');

% Test if the experiment name is set correctly
assert(isequal(obj.experimentName, 'something'), 'Experiment name not set correctly');


% Test if setModelType method works
obj.setModelType('Standard Layers');
assert(isequal(obj.ModelType, 'Standard Layers'), 'setModelType method not working');

%Test if setGeometry method works
obj.setGeometry('air/substrate');
assert(isequal(obj.Geometry, 'air/substrate'), 'setGeometry method not working');


% Test if addParamGroup method works
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
obj.addParamGroup(Parameters);
assert(isequal(obj.parameters.paramsTable{2,2}, 10), 'addParamGroup method not working. Tip: Make sure it is a cell array of parameters');

% Test if addParam method works 
%what it does is add a parameter to the parameter table with some default values
obj.addParam('NewParam2');
assert(isequal(obj.parameters.paramsTable{end,1}, 'NewParam2'), 'addParam method not working');


% Test if removeParam method works
%what it does is remove a parameter from the parameter table along with the default values
obj.removeParam('NewParam2');
assert(~isequal(obj.parameters.paramsTable{2,1}, 'NewParam2'), 'removeParam method not working');

% Test if setParameter method works
%what it does is set a parameter in the parameter table to a new value like this
% obj.setParameter($row_number,'$column_name', $how_much));
obj.setParameter(2, 'value', 50);
assert(isequal(obj.parameters.paramsTable{2,3}, 50), 'setParameter method not working');

% Test if setParamValue method works
% what it does is set the  'parameter' col in the parameter  to a new value like this
% obj.setParamValue($row_number, $how_much));
obj.setParamValue(2, 13);
assert(isequal(obj.parameters.paramsTable{2,3}, 13), 'setParamValue method not working');

%Test if setParamConstr method works
%what it does is set the constraints of a parameter like this
% obj.setParamConstr($row_number, '$min', $max));
obj.setParamConstr(2, 0, 100);
assert(isequal(obj.parameters.paramsTable{2,2}, 0), 'setParamConstr method not working');
assert(isequal(obj.parameters.paramsTable{2,4}, 100), 'setParamConstr method not working');

%Test if setParamName method works  
%what it does is set the name of a parameter like this
% obj.setParamName($row_number, '$new_name'));
obj.setParamName(2, 'NewParam');
assert(isequal(obj.parameters.paramsTable{2,1}, 'NewParam'), 'setParamName method not working');

%Test if setParamFit method works
%what it does is set the fit of a parameter like this
% obj.setParamFit($row_number, $fit_value));
obj.setParamFit(2, false);
assert(isequal(obj.parameters.paramsTable{2,5}, false), 'setParamFit method not working');

%Test if setParamPrior method works
%what it does is set the prior of a parameter like this
% obj.setParamPrior($row_number, $prior_value));
obj.setParamPrior(2, 'uniform');
assert(isequal(obj.parameters.paramsTable{2,6}, 'uniform'), 'setParamPrior method not working');

%Test if addLayerGroup method works
%what it does is add a layer group to the layer table[name col] and expects a cell array of layers
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

%obj.addLayerGroup({H_Heads; D_Heads; H_Tails; D_Tails});
%assert(isequal(obj.layers.layersTable{2,1}, D_Heads), 'addLayerGroup method not working');

% Test if setUsePrior method works
% Set priors flag TRUE OR FALSE
obj.setUsePriors(true);
assert(isequal(obj.UsePriors, true), 'setUsePrior method not working');


% Test if setLayerValue method works
% what it does is set the value of a layer like this with 3 parameters
% WRITE CODE HERE



% Test if setBacksParValue method works
%set the value in background parameters table
% obj.setBacksParValue($row_number, $how_much));
%obj.setBacksParValue(1, 5.5e-6);
%assert(isequal(obj.background.backPars.paramsTable{1,3}, 5.5e-6), 'setBacksParValue method not working');



% Test if addBacksPar method works
%what it does is add a parameter to the background parameters table with some default values
obj.addBacksPar('Backs Value D2O',1e-8,2.8e-6,1e-5);
assert(isequal(obj.background.backPars.paramsTable{end,1}, 'Backs Value D2O'), 'addBacksPar method not working');



% Test if addBackground method works
% what it does is add a background layer to the layer table

obj.addBackground('Background D2O','constant','Backs Value D2O');
assert(isequal(obj.background.backgrounds.typesTable{end,1}, 'Background D2O'), 'addBackground method not working');

% Test if setBackgroundValue method works
% what it does is set the value of a background like this with 3 parameters
obj.setBackgroundValue(1,'name','Background ACMW');
assert(isequal(obj.background.backgrounds.typesTable{1,1}, 'Background ACMW'), 'setBackgroundValue method not working');

% Test if addBulkOut method works
% what it does is add a bulk out layer to the layer table

obj.addBulkOut('SLD ACMW',-1e-6,0.0,1e-6,true);
assert(isequal(obj.bulkOut.paramsTable{end,1}, 'SLD ACMW'), 'addBulkOut method not working');

% Test if addContrast method works
% what it does is add a contrast layer to the layer table























