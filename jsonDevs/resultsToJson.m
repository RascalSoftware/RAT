
function resultsToJson(results,filename)

% Just a simple encode and save...(?)
% sldProfiles and layers encode in the wrong way...
% debugResults = jsondecode(fileread('DSPC_standard_layers_results.json'));

encoded = jsonencode(results,ConvertInfAndNaN=false);
encoded = replace(encoded,'Infinity','Inf');

[path,filename,~] = fileparts(filename);
fid = fullfile(path,[filename '.json']);
fid = fopen(fid,'w');
fprintf(fid,'%s',encoded);
fclose(fid);

end