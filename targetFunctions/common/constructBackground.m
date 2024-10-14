function data = constructBackground(contrastBackgroundParams,data,customFiles,backgroundParamArray)

% This is a placeholder function to calculate the background function
% for any function that needs it. Any backgrounds that use a background 
% function have a -2 flag as the first parameter in backgroundParams. 
% This function identifies which backgrounds are functions, calculates the
% background and adds this as the 5th coulmn to the datafile of this contrast.

if contrastBackgroundParams(1) == -2

    % Find the name of the custom function...
    funcName = customFiles{contrastBackgroundParams(2)};

    % The rest of the params are indicies to backgroundParams, or -Inf
    % if unused....
    funcBackParams = contrastBackgroundParams(3:end);

    % Strip out the unused ones (-Infs)....
    funcBackParams = funcBackParams(funcBackParams ~= -Inf);

    % Make an array of real params....
    paramsArray = zeros(1,length(funcBackParams));
    for n = 1:length(funcBackParams)
        paramsArray(n) = backgroundParamArray(funcBackParams(n));
    end

    % Evaluate the background function with these params...
    % Use a feval for now, but ultimately we will need to do the same
    % as the ususal custom file evaluation...
    thisBack = data(:,2); % This is the correct type - for compilation

    if coder.target('MATLAB')
        fileHandle = str2func(funcName);
        thisBack = fileHandle(data(:,1),paramsArray);
    elseif coder.target('MEX')        
        % 'feval' generates an automatic coder.extrinsic call.
        thisBack = feval(funcName, data(:,1),paramsArray);
    end

    % Add this background as column 5 of this data. Note that Matlab
    % will extend with no complaints (with zeros in col 4 if this is absent), 
    % but for Coder we will probably have to have made the data 5 column in
    % parseClassToStructs before calling RATMain...
    data(:,5) = thisBack;

else

    % We have either a constant background, or data background with
    % offset. In either case we add the parameter to column 5 of the
    % data.
    %
    % NOTE - This parameter is optional for data backgrounds, need to
    % account for this later
    backgroundParameter = backgroundParamArray(contrastBackgroundParams(2));
    data(:,5) = data(:,5) + backgroundParameter;

end

end
