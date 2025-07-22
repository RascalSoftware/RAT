



problem = jsonToProject('DSPC_standard_layers.json');
controls = controlsClass();

[problem,results] = RAT(problem,controls);

filename = 'resultsCheck.json';

encoded = jsonencode(results,ConvertInfAndNaN=false);
encoded = replace(encoded,'Infinity','Inf');

[path,filename,~] = fileparts(filename);
fid = fullfile(path,[filename '.json']);
fid = fopen(fid,'w');
fprintf(fid,'%s',encoded);
fclose(fid);



res_struct = jsondecode(fileread('resultsCheck.json'))
res_struct_2 = jsondecode(fileread('DSPC_standard_layers_results.json'))