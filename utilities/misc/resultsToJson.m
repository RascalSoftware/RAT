
function resultsToJson(results,filename)

% Encodes the results into a json file...

encoded = jsonencode(results,ConvertInfAndNaN=false);

[path,filename,~] = fileparts(filename);
fid = fullfile(path, append(filename, '.json'));
fid = fopen(fid,'w');
fprintf(fid,'%s',encoded);
fclose(fid);

end