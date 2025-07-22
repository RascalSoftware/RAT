function results = makeUnevenResults(results)

% Make a debug version of results where arrays are not equal in length

% extend some arrays...
results.reflectivity{1} = [results.reflectivity{1} ; results.reflectivity{1}(end-3:end,:)];
results.sldProfiles{1} = [results.sldProfiles{1} ; results.sldProfiles{1}(end-3:end,:)];

end