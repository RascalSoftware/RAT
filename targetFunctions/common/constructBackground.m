function background = constructBackground(backgroundType,backgroundParamIndices,shiftedData,customFiles,backgroundParamArray,simLimits)

% Apply background parameters to the background.
%
% For function backgrounds, this means running the function using the
% defined parameters. For data and constant backgrounds, this means taking
% any predefined background data and adding any supplied poarameters.

% Define the background over the simulation range, making sure to include
% any predefined data.
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
    thisBackground = zeros(length(background(:,2)), 1); % This is the correct type - for compilation

    if isnan(str2double(funcName))
        if coder.target('MATLAB')
            fileHandle = str2func(funcName);
            thisBackground = fileHandle(background(:,1), paramsArray);
        elseif coder.target('MEX')        
            % 'feval' generates an automatic coder.extrinsic call.
            thisBackground = feval(funcName, background(:,1), paramsArray);
        end
    else
        error('Background functions in languages other than MATLAB are not supported.');
    end

    background(:,2) = background(:,2) + thisBackground;

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
