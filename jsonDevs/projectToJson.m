function encoded = projectToJson(problem,filename)

% Converts a projectClass to a json file...

% % For debug...
% debug_json_struct = jsondecode(fileread('DSPC_custom_layers.json'));

% General Params....
totalStruct.name = problem.experimentName;
totalStruct.calculation = 'normal'; % Will gove optio for magnetic etc...
totalStruct.model = problem.modelType;
totalStruct.geometry = problem.geometry;
totalStruct.absorption = problem.absorption;

% Global priors flag..
show_priors = problem.showPriors;

% Parameters...
paramsTable = problem.parameters.varTable;
nRows = problem.parameters.rowCount;
totalStruct.parameters = makeParamStruct(paramsTable,nRows,show_priors);

% % Sanity check....
% if ~(isequal(debug_json_struct.parameters,totalStruct.parameters))
%     warning('Parameters class check failed!');
% end

% Bulk in...
bulkInTable = problem.bulkIn.varTable;
nRows = problem.bulkIn.rowCount;
totalStruct.bulk_in = makeParamStruct(bulkInTable,nRows,show_priors);

% Bulk Out...
bulkOutTable = problem.bulkOut.varTable;
nRows = problem.bulkOut.rowCount;
totalStruct.bulk_out = makeParamStruct(bulkOutTable,nRows,show_priors);

% Scalefactors...
scalefactorTable = problem.scalefactors.varTable;
nRows = problem.scalefactors.rowCount;
totalStruct.scalefactors = makeParamStruct(scalefactorTable,nRows,show_priors);

% Domain ratios.... TODO
totalStruct.domain_ratios = [];

% Background 
backPars = problem.background.backgroundParams;
backs = problem.background.backgrounds;

backParsTable = backPars.varTable;
bp_nRows = backPars.rowCount;
totalStruct.background_parameters = makeParamStruct(backParsTable,bp_nRows,show_priors);

backsTable = backs.varTable;
totalStruct.backgrounds = makeTypeTableStruct(backsTable);

% % Backs table sanity check....
% if ~(isequal(debug_json_struct.backgrounds(1),totalStruct.backgrounds(1)))
%     warning('Types table conversion failed');
% end

% resolution...
resolPars = problem.resolution.resolutionParams;
resols = problem.resolution.resolutions;

resolParsTable = resolPars.varTable;
rp_nRows = resolPars.rowCount;
totalStruct.resolution_parameters = makeParamStruct(resolParsTable,rp_nRows,show_priors);

resolsTable = resols.varTable;  
totalStruct.resolutions = makeTypeTableStruct(resolsTable);

% Custom files..... TODO
customTable = problem.customFile.varTable;
totalStruct.custom_files = makeCustomFileStruct(customTable);

% Data...
dataTable = problem.data.varTable;
totalStruct.data = makeDataStruct(dataTable);

% Layers...
if ~isempty(problem.layers)
    layersTable = problem.layers.varTable;
    totalStruct.layers = makeLayersStruct(layersTable);
end

% Domains contrasts ........ TODO....
totalStruct.domain_contrasts = [];

% Contrasts....
contrastArray = problem.contrasts.contrasts;
totalStruct.contrasts = makeContrastsStruct(contrastArray);

% Save the file 
encoded = jsonencode(totalStruct,ConvertInfAndNaN=true);
encoded = replace(encoded,'null','Inf');

[path,filename,~] = fileparts(filename);
fid = fullfile(path,[filename '.json']);
fid = fopen(fid,'w');
fprintf(fid,'%s',encoded);
fclose(fid);

end

% ---------------------------------------

function paramStruct = makeParamStruct(paramsTable,nRows,show_priors)

% Takes a parameters table, adds the show priors column, changes the
% variable names to match python (mainly changing case), changes the contents
% of some columns to chars from strings and 
% then converts the table to a struct.....

% Add the show priors col...
paramsTable.('show_priors') = repmat(show_priors,nRows,1);

% Rename columns to match Python (mainly case)....
paramsTable.Properties.VariableNames = ["name", "min", "value", "max", "fit",...
                                        "prior_type", "mu", "sigma", "show_priors"];

% Columns that contain strings need to contain chars..
paramsTable.name = char(paramsTable.name);
paramsTable.prior_type = char(paramsTable.prior_type);

% Make the struct array..
paramStruct = table2struct(paramsTable);

% For some reason, we end up with trailing spaces in our chars after the 
% conversion, with the number of spaces added to match the longest char in
% the original table column. We have to loop over all of them to correct
% these... (running strtrim on the 'char' conversion above doesn't work - the
% padding seems to happen during table2array).
for i = 1:length(paramStruct)
    paramStruct(i).name = strtrim(paramStruct(i).name);
    paramStruct(i).prior_type = strtrim(paramStruct(i).prior_type);
end

end

% ------------------------------------------

function typeStruct = makeTypeTableStruct(typeTable)

% Rename columns to match Python (mainly case)....
typeTable.Properties.VariableNames = ["name", "type", "source", "value_1", "value_2",...
                                        "value_3", "value_4", "value_5"];

% Everything needs to be chars, not strings...
for i = 1:length(typeTable.Properties.VariableNames)
    % Seem to have to loop over rows (otherwise fails when only one row...)
    for n = 1:height(typeTable)
        typeTable.(i)(n) = char(typeTable.(i)(n));
    end
end

% Convert to a struct array..
typeStruct = table2struct(typeTable);

% Again, we have a problem with the conversion, with empty cells becoming
% [1x0] character arrays rather than [0x0] character arrays (!!?)...
fields = fieldnames(typeStruct);
for i = 1:length(typeStruct)
    for n = 1:length(fields)
        typeStruct(i).(fields{n}) = strtrim(typeStruct(i).(fields{n}));
    end
end

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

function newContrastStruct = makeContrastsStruct(contrastArray)

numberOfContrasts = length(contrastArray);

% Order of fields we need for the json...
jsonFields = ["name","data","background","background_action","bulk_in",...
              "bulk_out","scalefactor","resolution","resample","model"];

for i = 1:numberOfContrasts
    thisContrastStruct = contrastArray{i};
    
    % remove the repeats field...
    thisContrastStruct = rmfield(thisContrastStruct,'repeatLayers');

    % rename the fields...
    newFieldldNames = ["background",...
                "background_action",...
                "bulk_in"          ,...
                "bulk_out"         ,...
                "data"             ,...
                "model"            ,...
                "name"             ,...
                "resample"         ,...
                "resolution"       ,...
                "scalefactor"      ];

    thisContrastStruct = cell2struct(struct2cell(thisContrastStruct), newFieldldNames);

    % Order them according to the json requirements...
    thisContrastStruct = orderfields(thisContrastStruct,jsonFields);

    newContrastStruct(1,i) = thisContrastStruct; 
end

end

% ---------------------------------------------------------------------

function customFileStruct = makeCustomFileStruct(customTable)

% Rename columns to match Python (mainly case)....
varNames =  ["name","filename","function name","language","path"];
customTable.Properties.VariableNames = varNames;

% Everything needs to be chars, not strings...
for i = 1:length(customTable.Properties.VariableNames)
    customTable.(varNames(i)) = char(customTable.(varNames(i)));
end

customFileStruct = table2struct(customTable);

% Remove trailing spaces from chars...
customFileStruct = removeSpaces(customFileStruct);

end

% ----------------------------------------------------------------

function thisStruct = removeSpaces(thisStruct)
% Remove trailing spaces from all chars in structs...

fields = fieldnames(thisStruct);
for i = 1:length(thisStruct)
    for n = 1:length(fields)
        thisStruct(i).(fields{n}) = strtrim(thisStruct(i).(fields{n}));
    end
end

end

% ----------------------------------------------------------------