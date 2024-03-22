function [repeatLayers,data,dataLimits,simLimits,contrastLayers,layersDetails,customFiles] = parseCells(problemCells)
% Splits up the master input list of all arrays into separate arrays
% 
% INPUTS:
%     * problemCells: cell array where all the project data is grouped together.
%
% OUTPUTS:
%     * repeatLayers: controls repeating of the layers stack.
%     * data: Array of all the data arrays.
%     * dataLimits: Min max limits in q for the data arrays.
%     * simLimits: Limits in Q for the reflectivity simulations.
%     * layersDetails: Master array of all available layers.
%     * contrastLayers: Which specific combination of arrays are needed for each contrast.
%     * customFiles:Filenames and path for any custom files used.


repeatLayers = problemCells{1};
data = problemCells{2};
dataLimits = problemCells{3};
simLimits = problemCells{4};
contrastLayers = problemCells{5};
layersDetails = problemCells{6};
customFiles = problemCells{14};

end