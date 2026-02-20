
function resultsToJson(results,filename)

% Encodes the results into a json file...
tmpResults = struct();
for fn = fieldnames(results)'
   tmpResults.(fn{1}) = results.(fn{1});
end

tmpResults.reflectivity = correctCellArray(tmpResults.reflectivity, false);
tmpResults.simulation = correctCellArray(tmpResults.simulation, false);
tmpResults.shiftedData = correctCellArray(tmpResults.shiftedData, false);
tmpResults.backgrounds = correctCellArray(tmpResults.backgrounds, false);
tmpResults.resolutions = correctCellArray(tmpResults.resolutions, false);
tmpResults.sldProfiles = correctCellArray(tmpResults.sldProfiles, true);
tmpResults.layers = correctCellArray(tmpResults.layers, true);
tmpResults.resampledLayers = correctCellArray(tmpResults.resampledLayers, true);

encoded = jsonencode(tmpResults,ConvertInfAndNaN=false);

[path,filename,~] = fileparts(filename);
fid = fullfile(path, append(filename, '.json'));
fid = fopen(fid,'w');
fprintf(fid,'%s',encoded);
fclose(fid);

end


function cellArray = correctCellArray(cellArray, domain)
% Corrects array with single row so its written as 2D array in json 
    [row, col] = size(cellArray, [1, 2]);
    for i=1:row
        for j=1:col
            if size(cellArray{i, j}, 1) == 1
               cellArray{i, j} = {cellArray{i, j}};
            end
        end
    end
    if domain && size(cellArray, 2) == 1
        for i=1:row
            cellArray{i, 1} = {cellArray{i, 1}};
        end
    end
    if domain && size(cellArray, 1) == 1
        cellArray = {cellArray};
    end
end