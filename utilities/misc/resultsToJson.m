
function resultsToJson(results,filename)

% Encodes the results into a json file...

encoded = jsonencode(results,ConvertInfAndNaN=false);
encoded = replace(encoded,'Infinity','Inf');

[path,filename,~] = fileparts(filename);
fid = fullfile(path,[filename '.json']);
fid = fopen(fid,'w');
fprintf(fid,'%s',encoded);
fclose(fid);

end