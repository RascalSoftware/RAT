function plotRefSLD(project, result, options)
    % Plots the reflectivity and SLD profiles
    %
    % Examples
    % --------
    % >>> plotRefSLD(problem, result, 'showGrid', true, 'q4', true);
    % 
    % Parameters
    % ----------
    % project : projectClass
    %    An instance of the projectClass.
    % result : struct
    %    The result of the RAT calculation. 
    % options
    %    Keyword/value pairs to configure plotting, the following are allowed
    %       * linearX (logical, default: false) indicates if the X axis should be linear scale instead of log.
    %       * q4 (logical, default: false) indicates if the Y axis should plot Q^4.
    %       * showErrorBar (logical, default: true) indicates if the error bar should be shown.
    %       * showGrid (logical, default: false) indicates if the grid should be shown.
    %       * showLegend (logical, default: true) indicates if the legend should be shown.
    %       * shiftValue (float, default: 100) A value between 1 and 100 that controls the spacing between the reflectivity plots for each of the contrasts.   
    
    arguments
        project
        result
        options.linearX {mustBeA(options.linearX, 'logical')} = false
        options.q4 {mustBeA(options.q4, 'logical')} = false
        options.showErrorBar {mustBeA(options.showErrorBar, 'logical')} = true
        options.showGrid {mustBeA(options.showGrid, 'logical')} = false
        options.showLegend {mustBeA(options.showLegend, 'logical')} = true
        options.shiftValue {mustBeGreaterThanOrEqual(options.shiftValue, 1), mustBeLessThanOrEqual(options.shiftValue, 100)} = 100
    end
    % Convert the project class to a struct.
    controls = controlsClass();
    data.modelType = project.modelType;
    [projectStruct,~] = parseClassToStructs(project,controls);
    
    data.reflectivity = result.reflectivity;
    data.shiftedData = result.shiftedData;
    data.sldProfiles = result.sldProfiles;
    data.resampledLayers = result.resampledLayers;
    data.dataPresent = projectStruct.dataPresent;
    data.subRoughs = result.contrastParams.subRoughs;
    data.resample = projectStruct.resample;
    data.contrastNames = projectStruct.names.contrasts;

    % If we have air/substrate geometry, modify the SLD profiles slightly
    % so that the substrates line up (for custom XY the user does this
    % themselves)...
    if strcmpi(projectStruct.geometry,'air/substrate') && ~strcmpi(projectStruct.modelType,'custom xy')
        data = alignALProfiles(data);
    end
    
    plotRefSLDHelper(data, false, options.linearX, options.q4, options.showErrorBar, ...
                     options.showGrid, options.showLegend, options.shiftValue);
end


function data = alignALProfiles(data)
% Aligns the A/L SLD profiles so that the substrates line up by padding the
% start of any shorter than the longest profile..

% Get the sld profiles out of data
slds = data.sldProfiles;
resamLays = data.resampledLayers;

% Find the length of the longest profile...
f = @(x)size(x{:},1);
lengths = arrayfun(f,slds);
maxPos = find(lengths == max(lengths));

% If maxPos is an array we have many of equal (leng) length.
% We can just pick one of them...
if length(maxPos) > 1
    maxPos = maxPos(1);
end

maxLen = lengths(maxPos);
max_XValue = slds{maxPos}(end,1);

% Get the longest profile...
max_X = slds{maxPos}(:,1);

% Pad the start of any profiles that are shorter than this
for i = 1:length(slds)
    thisSLD = slds{i};
    thisLen = size(thisSLD,1);
    if thisLen < maxLen
        diffLen = maxLen - thisLen;
        pad = zeros(diffLen,1);
        newY = [pad ; thisSLD(:,2)];
        slds{i} = [max_X(:,1) newY(:)];
        
        % For resampled layers, the pad is just one big layer at the start
        thisResam = resamLays{i};
        if ~all(thisResam,'All')      % not all zeros
            totLength = sum(thisResam(:,1));
            padLength = max_XValue - totLength;
            resamPad = [padLength 0 0];
            resamLays{i} = [resamPad ; thisResam]; 
        end
    end
end

data.sldProfiles = slds;
data.resampledLayers = resamLays;

end