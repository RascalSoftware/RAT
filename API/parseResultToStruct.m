function result = parseResultToStruct(problem,resultCells)

result.reflectivity = resultCells{1};   % Reflectivity art points
result.simulation = resultCells{2};     % Reflectivity between sim limits    
result.shiftedData = resultCells{3};    % Data corrected for sfs
result.layerSlds = resultCells{4};      % Layers if defined (i.e. not customXY)
result.sldProfiles = resultCells{5};    % Calculated SLD profiles
result.allLayers = resultCells{6};      % Resampled layers

result.calculationResults = problem.calculations;

% For compile, we can't remove a field, so just clear it for now...
%problem = rmfield(problem,'calculations');
result.contrastParams = problem;

end
