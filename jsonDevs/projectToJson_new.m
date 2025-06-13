function projectToJson_new(problem,filename)

% Converts a projectClass to a json file...

% %%%%%%%%%
% Useful for debugging!
debug_json_struct = jsondecode(fileread('DSPC_standard_layers.json'));
%
%
% Need to match this struct:
%
% json_struct = jsondecode(fileread('DSPC_custom_layers.json'));
%
% json_struct = 
% 
%   struct with fields:
% 
%                      name: 'original_dspc_bilayer'
%               calculation: 'normal'
%                     model: 'standard layers'
%                  geometry: 'substrate/liquid'
%                absorption: 0
%                parameters: [21×1 struct]
%                   bulk_in: [1×1 struct]
%                  bulk_out: [2×1 struct]
%              scalefactors: [2×1 struct]
%             domain_ratios: []
%     background_parameters: [2×1 struct]
%               backgrounds: [2×1 struct]
%     resolution_parameters: [1×1 struct]
%               resolutions: [1×1 struct]
%              custom_files: []
%                      data: [3×1 struct]
%                    layers: [6×1 struct]
%          domain_contrasts: []
%                 contrasts: [2×1 struct]
%
% --------------------

% General Params....
name = problem.experimentName;
calculation = problem.modelType;
model = problem.modelType;
geometry = problem.geometry;
absorption = problem.absorption;
show_priors = problem.showPriors;

% Parameters...
paramsTable = problem.parameters.varTable;
nRows = problem.parameters.rowCount;
parameters = makeParamStruct(paramsTable,nRows,show_priors);

% Bulk in...
bulkInTable = problem.bulkIn.varTable;
nRows = problem.bulkIn.rowCount;
bulk_in = makeParamStruct(bulkInTable,nRows,show_priors);

% Bulk Out...
bulkOutTable = problem.bulkOut.varTable;
nRows = problem.bulkOut.rowCount;
bulk_out = makeParamStruct(bulkOutTable,nRows,show_priors);

% Scalefactors...
scalefactorTable = problem.scalefactors.varTable;
nRows = problem.scalefactors.rowCount;
scalefactors = makeParamStruct(scalefactorTable,nRows,show_priors);

% Domain ratios.... TODO
domain_ratios = [];

% Background 
backPars = problem.background.backgroundParams;
backs = problem.background.backgrounds;

backParsTable = backPars.varTable;
bp_nRows = backPars.rowCount;
background_parameters = makeParamStruct(backParsTable,bp_nRows,show_priors);

backsTable = backs.varTable;
backgrounds = makeTypeTableStruct(backsTable);

% resolution...
resolPars = problem.resolution.resolutionParams;
resols = problem.resolution.resolutions;

resolParsTable = resolPars.varTable;
rp_nRows = resolPars.rowCount;
resolution_parameters = makeParamStruct(resolParsTable,rp_nRows,show_priors);

resolsTable = resols.varTable;
resolutions = makeTypeTableStruct(resolsTable);

% Custom files..... TODO
custom_files = [];

% Data...
dataTable = problem.data.varTable;
data = makeDataStruct(dataTable);

% Layers...
layersTable = problem.layers.varTable;
layers = makeLayersStruct(layersTable);

% Domains contrasts ........ TODO....
domain_contrasts = [];

% Contrasts....

end

% ---------------------------------------

function paramStruct = makeParamStruct(paramsTable,nRows,show_priors)

% Takes a parameters table, adds the show priors column, changes the
% variable names to match python (mainly changing case) and converts the
% table to a struct.....

% Add the show priors col...
paramsTable.('show_priors') = repmat(show_priors,nRows,1);

% Rename columns to match Python (mainly case)....
paramsTable.Properties.VariableNames = ["name", "min", "value", "max", "fit",...
                                        "prior_type", "mu", "sigma", "show_priors"];

% Make struct..
paramStruct = table2struct(paramsTable);

end

% ------------------------------------------

function typeStruct = makeTypeTableStruct(typeTable)

% Rename columns to match Python (mainly case)....
typeTable.Properties.VariableNames = ["name", "type", "source", "value_1", "value_2",...
                                        "value_3", "value_4", "value_5"];

typeStruct = table2struct(typeTable);

end

% -----------------------------------------

function dataStruct = makeDataStruct(dataTable)

% Rename columns to match Python (case and underscores)....
dataTable.Properties.VariableNames = ["name", "data", "data_range", "simulation_range"]; 

dataStruct = table2struct(dataTable);

end

% ------------------------------------------

function layersStruct = makeLayersStruct(layersTable)

% Rename columns to match Python (case and underscores)....
layersTable.Properties.VariableNames = ["name", "thickness", "SLD", "roughness",...
                                        "hydration", "hydrate_with"]; 

layersStruct = table2struct(layersTable);

end

% -------------------------------------------