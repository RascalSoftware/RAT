
function controlsToJson(controls,filename)

% Saves the current controls block as a json..
encoded = jsonencode(controls,ConvertInfAndNaN=false);
encoded = replace(encoded,'Infinity','Inf');

[path,filename,~] = fileparts(filename);
fid = fullfile(path, append(filename, '.json'));
fid = fopen(fid,'w');
fprintf(fid,'%s',encoded);
fclose(fid);

end