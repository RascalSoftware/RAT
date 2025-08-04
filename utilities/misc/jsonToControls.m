
function controls = jsonToControls(filename)

% Loads in a controls json, and contructs the controlsClass from it...

% Load the file...
jsonControls = jsondecode(fileread(filename));

% Make a controlsClass()
controls = controlsClass();

fieldNames = fieldnames(jsonControls);
for i = 1:length(fieldNames)
    controls.(fieldNames{i}) = jsonControls.(fieldNames{i});
end

end