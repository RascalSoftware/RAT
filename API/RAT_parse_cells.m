function [repeatLayers,allData,dataLimits,simLimits,contrastLayers,layersDetails,customFiles] = RAT_parse_cells(problemDef_cells)

repeatLayers = problemDef_cells{1};
allData = problemDef_cells{2};
dataLimits = problemDef_cells{3};
simLimits = problemDef_cells{4};
contrastLayers = problemDef_cells{5};
layersDetails = problemDef_cells{6};
customFiles = problemDef_cells{14};

end