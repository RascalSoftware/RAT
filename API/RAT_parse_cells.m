function [repeatLayers,allData,dataLimits,simLimits,contrastLayers,layersDetails,customFiles] = RAT_parse_cells(problemDef_cells)

% Splits up the master input list of all arrays into separate arrays
% The min input array 'problemDef_cells' is a master array where
% all the cell arrays are grouped together. There are
% repeatLayers      - controls repeating of the layers stack
% allData           - Array of all the data arrays
% dataLimits        - Min max limits in q for the data arrays
% simLimits         - Limits in Q for the reflkectivity simulations
% Layers details    - Master array of all available layers
% contrastLayers    - Which specific combination of arrays are needed for
%                     each contrast.
% Custom files      - Filenames and path for any custom files used


repeatLayers = problemDef_cells{1};
allData = problemDef_cells{2};
dataLimits = problemDef_cells{3};
simLimits = problemDef_cells{4};
contrastLayers = problemDef_cells{5};
layersDetails = problemDef_cells{6};
customFiles = problemDef_cells{14};

end