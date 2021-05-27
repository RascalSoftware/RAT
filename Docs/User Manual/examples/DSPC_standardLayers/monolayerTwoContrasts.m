% Analysis of DSPC monolayers Data - two contrasts example

% First make an instance of the project class
problem = projectClass('DSPC monolayers');

% Define the parameters:
Parameters = {
    %       Name                min     val     max     fit? 
    {'Tails Thickness',         10,     20,     30,     true};
    {'Heads Thickness',          3,     11,     16,     true};
    {'Tails Roughness',          2,     5,      9,      true};
    {'Heads Roughness',          2,     5,      9,      true};
    {'Deuterated Tails SLD',    4e-6,   6e-6,   2e-5,   true};
    {'Hydrogenated Tails SLD', -0.6e-6, -0.4e-6, 0,     true};
    {'Deuterated Heads SLD',    1e-6,   3e-6,   8e-6,   true};
    {'Hydrogenated Heads SLD',  0.1e-6,   1.4e-6, 3e-6,   true};
    {'Heads Hydration',         0,      0.3,   0.5,    true};
    };