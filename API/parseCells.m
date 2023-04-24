function [repeatLayers,allData,dataLimits,simLimits,contrastLayers,layersDetails,customFiles] = parseCells(problemDefCells)

% Splits up the master input list of all arrays into separate arrays
% The min input array 'problemDefCells' is a master array where
% all the cell arrays are grouped together. There are
% repeatLayers      - controls repeating of the layers stack
% allData           - Array of all the data arrays
% dataLimits        - Min max limits in q for the data arrays
% simLimits         - Limits in Q for the reflkectivity simulations
% Layers details    - Master array of all available layers
% contrastLayers    - Which specific combination of arrays are needed for
%                     each contrast.
% Custom files      - Filenames and path for any custom files used


repeatLayers = problemDefCells{1};
allData = problemDefCells{2};
dataLimits = problemDefCells{3};
simLimits = problemDefCells{4};
contrastLayers = problemDefCells{5};
layersDetails = problemDefCells{6};
customFiles = problemDefCells{14};

end