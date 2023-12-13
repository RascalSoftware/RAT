function result = parseResultToStruct(problem,results)

result.reflectivity = results{1};   % Reflectivity art points
result.simulation = results{2};     % Reflectivity between sim limits    
result.shiftedData = results{3};    % Data corrected for sfs
result.layerSlds = results{4};      % Layers if defined (i.e. not custolXY)
result.sldProfiles = results{5};    % Calculated SLD profiles
result.allLayers = results{6};      % Resampled layers

result.calculationResults = problem.calculations;

% For compile, we can't remove a field, so just clear it for now...
%problem = rmfield(problem,'calculations');
result.contrastParams = problem;

end
