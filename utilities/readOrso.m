function outputData = readOrso(filename)
% Read data from an .ort file.
%
% Parameters
% ----------
% filename : string
%   The path to the .ort file.
%
% Returns
% -------
% output_data : array
%   The data array from the .ort file.

f = fopen(filename);

outputData = {};
currentlyReading = false;
currentData = "";

while ~feof(f)
    line = fgetl(f);
    if startsWith(line, '#')
        if currentlyReading && currentData ~= ""
            outputData{length(outputData) + 1} = str2num(currentData);
            currentData = "";
        end
        currentlyReading = false;
    else
        if ~currentlyReading
            currentData = line;
        else
            currentData = append(currentData, newline, line);
        end
        currentlyReading = true;
    end
end
outputData{length(outputData) + 1} = str2num(currentData);
end