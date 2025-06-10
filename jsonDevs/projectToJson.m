function projectToJson(problem,filename)

% Converts a projectClass to a json file...







% Start by converting the project to a struct...
problemStruct = problem.toStruct;


%%%-----------

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

% Make all the fields of the struct individually:

% General...
name = problemStruct.experimentName;
calculation = problemStruct.TF;
geometry = problemStruct.geometry;
absorption = problemStruct.useImaginary;
showPriors = problem.showPriors; 

% Parameters..
parameters = makeParamStruct(problemStruct.paramNames,...
                             problemStruct.paramLimits,...
                             problemStruct.paramValues,... 
                             problemStruct.fitParam,...
                             problemStruct.paramPriors,...
                             showPriors); 

% bulk in....
bulk_in = makeParamStruct(problemStruct.bulkInNames,...
                          problemStruct.bulkInLimits,...
                          problemStruct.bulkInValues,... 
                          problemStruct.fitBulkIn,...
                          problemStruct.bulkInPriors,...
                          showPriors); 

% bulk out....
bulk_out = makeParamStruct(problemStruct.bulkOutNames,...
                           problemStruct.bulkOutLimits,...
                           problemStruct.bulkOutValues,... 
                           problemStruct.fitBulkOut,...
                           problemStruct.bulkOutPriors,...
                           showPriors); 

% scalefactors....
scalefactors = makeParamStruct(problemStruct.scalefactorNames,...
                               problemStruct.scalefactorLimits,...
                               problemStruct.scalefactorValues,... 
                               problemStruct.fitScalefactor,...
                               problemStruct.scalefactorPriors,...
                               showPriors); 
% Domain ratios... TODO
domain_ratios = [];

% Background parameters...
background_parameters = makeParamStruct(problemStruct.backgroundParamNames,...
                                        problemStruct.backgroundParamLimits,...
                                        problemStruct.backgroundParamValues,... 
                                        problemStruct.fitBackgroundParam,...
                                        problemStruct.backgroundParamPriors,...
                                        showPriors); 

% Backgrounds
backgrounds = makeBackgroundStruct(problemStruct.backgroundNames,...
                                   problemStruct.backgroundTypes,...
                                   problemStruct.backgroundValues);

% Resolution parameters...
resolution_parameters = makeParamStruct(problemStruct.resolutionParamNames,...
                                        problemStruct.resolutionParamLimits,...
                                        problemStruct.resolutionParamValues,... 
                                        problemStruct.fitResolutionParam,...
                                        problemStruct.resolutionParamPriors,...
                                        showPriors); 

% Backgrounds
resolutions = makeBackgroundStruct(problemStruct.resolutionNames,...
                                   problemStruct.resolutionTypes,...
                                   problemStruct.resolutionValues);

% Custom Files.... TODO..
custom_files = [];

% Data....
% (We do this from the datatable, since 'toStruct' seems to lose some
% info..)
data = makeDataStruct(problem.data.varTable);


end

% -----------------------------------------------------------------------

function paramsArray = makeParamStruct(names,limits,values,fit,priors,showPriors)

nParams = length(names);

for i = 1:nParams
    thisName  = names{i};
    thisMin = limits{i}(1);
    thisVal = values(i);
    thisMax = limits{1}(2);
    thisFit = fit(i);
    thisPriorType = priors{i}{2};
    thisMu = priors{i}{3};
    thisSig = priors{i}{4};

    thisStruct = struct('name',thisName,'min',thisMin,'value',thisVal,...
                        'max',thisMax,'fit',thisFit,'prior_type',thisPriorType,...
                        'mu',thisMu,'sigma',thisSig,'show_priors',showPriors);
    paramsArray(i) = thisStruct;
end

end

% -----------------------------------------------------------------------

function backgroundStruct = makeBackgroundStruct(names,types,values)

nBacks = length(names);

for i = 1:nBacks
    thisName = names{i};
    thisType = types{i};
    theseVals = values{i};

    % 'Values' can have different lengths (up to 6..). Just making an empty
    % cell array of the maximum length makes populating the struct easier..
    vals = repmat({''},6,1);
    for n = 1:length(theseVals)
        vals{n} = theseVals{n};
    end

    thisStruct = struct('name',thisName,...
                        'type',thisType,...
                        'source',vals{1},...
                        'value_1',vals{2},...
                        'value_2',vals{3},...
                        'value_3',vals{4},...
                        'value_4',vals{5},...
                        'value_5',vals{5});
    backgroundStruct(i) = thisStruct;
end

end

% -----------------------------------------------------------------------

function dataStruct = makeDataStruct(dataTable)

nData = size(dataTable,1);

for i = 1:nData
    thisName = dataTable{i,1};
    thisData = dataTable{i,2}{:};
    thisDataRange = dataTable{i,3}{:};
    thisSimRange = dataTable{i,4}{:};
    dataStruct(i) = struct('name',thisName,...
                           'data',thisData,...
                           'data_range',thisDataRange,...
                           'simulation_range',thisSimRange);
end

end

% -----------------------------------------------------------------------


