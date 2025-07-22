
function results = jsonToResults(filename)

% Loads in the results from a json results file, and converts it so the
% format required for matlabRAT. The conversion mainly means convertinf
% flattened array back to cells..

% Load in the json array
jsonRes = jsondecode(fileread(filename));

% Go through converting all arrays to cells.....
results.reflectivity = simArray2Cells(jsonRes.reflectivity);
results.simulation = simArray2Cells(jsonRes.simulation);
results.shiftedData = dataArray2Cells(jsonRes.shiftedData);
results.backgrounds = array2Cells(jsonRes.backgrounds);
results.resolutions = array2Cells(jsonRes.resolutions);
results.sldProfiles = sldArray2Cells(jsonRes.sldProfiles);
results.layers = sldArray2Cells(jsonRes.layers);    % Layers array is in the same format as the SLDs
results.resampledLayers = sldArray2Cells(jsonRes.resampledLayers);

% These correctly load in as structs or arrays....
results.calculationResults = jsonRes.calculationResults;
results.contrastParams = jsonRes.contrastParams;
results.fitParams = jsonRes.fitParams';
results.fitNames = jsonRes.fitNames;

end

% --------------------------------------------------------------

function outCell = array2Cells(inArray)

% Get 3rd dimension of array...
dims = size(inArray,3);

for i = 1:dims
    outCell{i,1} = inArray(:,:,i)';
end

end

% ----------------------------------------------------------

function outCell = sldArray2Cells(inArray)

% Get number of profiles...
nProfiles = size(inArray,1);

for i = 1:nProfiles
    thisSLD = inArray(i,1,:,:);
    thisSLD = squeeze(thisSLD); % Collapse singleton dims....
    outCell{i,1} = thisSLD;
end

end

% --------------------------------------------------------------

function outCell = dataArray2Cells(inArray)

% Get number of profiles...
nProfiles = size(inArray,1);

for i = 1:nProfiles
    thisDat = inArray(i,:,:,:);
    thisDat = squeeze(thisDat); % Collapse singleton dims....
    outCell{i,1} = thisDat;
end

end

% --------------------------------------------------------------

function outCell = simArray2Cells(inArray)

% Get 3rd dimension of array...
dims = size(inArray,1);

for i = 1:dims
    thisArray = inArray(i,:,:);
    outCell{i,1} = squeeze(thisArray);
end

end

% ----------------------------------------------------------