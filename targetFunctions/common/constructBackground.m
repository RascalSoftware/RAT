function background = constructBackground(backgroundType,backgroundParamIndices,shiftedData,customFiles,backgroundParamArray,simLimits)

% This is a placeholder function to calculate the background function
% for any function that needs it. Any backgrounds that use a background 
% function have a -2 flag as the first parameter in backgroundParams. 
% This function identifies which backgrounds are functions, calculates the
% background and adds this as the 5th column to the datafile of this contrast.

[simulationXData, dataIndices] = makeSimulationRange(shiftedData, simLimits);

background = zeros(length(simulationXData),3);
background(:,1) = simulationXData;
background(dataIndices(1):dataIndices(2),2) = shiftedData(:,5);
background(dataIndices(1):dataIndices(2),3) = shiftedData(:,6);

if strcmpi(backgroundType, coderEnums.allowedTypes.Function)

    % For a function background, the first index is actually that of the
    % custom function
    funcName = customFiles{backgroundParamIndices(1)};

    % The rest of the backgroundParamIndices are indicies to
    % backgroundParams
    funcBackParams = backgroundParamIndices(2:end);

    % Make an array of real params
    paramsArray = zeros(1,length(funcBackParams));
    for i = 1:length(funcBackParams)
        paramsArray(i) = backgroundParamArray(funcBackParams(i));
    end

    % Evaluate the background function with these params...
    % Use a feval for now, but ultimately we will need to do the same
    % as the usual custom file evaluation...
    thisBack = zeros(length(background(:,2)), 1); % This is the correct type - for compilation

    if coder.target('MATLAB')
        fileHandle = str2func(funcName);
        thisBack = fileHandle(background(:,1), paramsArray);
    elseif coder.target('MEX')        
        % 'feval' generates an automatic coder.extrinsic call.
        thisBack = feval(funcName, background(:,1), paramsArray);
    end

    % Add this background as column 5 of this data. Note that Matlab
    % will extend with no complaints (with zeros in col 4 if this is absent), 
    % but for Coder we will probably have to have made the data 5 column in
    % parseClassToStructs before calling RATMain...
    background(:,2) = background(:,2) + thisBack;

else

    % We have either a constant background, or a data background with an
    % optional offset. In either case we add the parameter to column 5 of
    % the data. Hence we expect to run either zero or one iterations
    % of this loop.
    for i = 1:length(backgroundParamIndices)
        backgroundParameter = backgroundParamArray(backgroundParamIndices(i));
        background(:,2) = background(:,2) + backgroundParameter;
    end

end

end
