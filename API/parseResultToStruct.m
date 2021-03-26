function result = parseResultToStruct(problem,results)

result.reflectivity = results{1};
result.Simulation = results{2};
result.shifted_data = results{3};
result.layerSlds = results{4};
result.sldProfiles = results{5};
result.allLayers = results{6};

result.calculationResults = problem.calculations;
problem = rmfield(problem,'calculations');
result.contrastParams = problem;

end