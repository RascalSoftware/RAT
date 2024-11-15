function newData = applyBackgroundFunction(contrastBackgroundParams,data,customFiles,backgroundParamArray)

% This is a placeholder function to calculate the background function
% for any function that needs it. Any backgrounds that use a background 
% function have a -2 flag as the first parameter in backgroundParams. 
% This function identifies which backgrounds are functions, calculates the
% background and adds this as the 5th coulmn to the datafile of this contrast.

disp('debug');

for i = 1:size(contrastBackgroundParams,1)
    if contrastBackgroundParams(i,1) == -2
        
        % This is a function background...
        thisBackParams = contrastBackgroundParams(i,:); 

        % Find the name of the custom function...
        funcName = customFiles(thisBackParams(2));

        % The rest of the params are indicies to backgroundParams, or -Inf
        % if unused....
        funcBackParams = thisBackParams(3:end);

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
        thisData = data{i};
        thisHandle = str2func(funcName{:});
        thisBack = thisHandle(thisData(:,1),paramsArray);

        % Add this background as column 5 of this data. Note that Matlab
        % will extend with no complaints (with zeros in col 4 if this is absent), 
        % but for Coder we will probably have to have made the data 5 column in
        % parseClassToStructs before calling RATMain...
        thisData(:,5) = thisBack;

        % Put our modified data array back into data.
        data{i} = thisData;
    end
end

newData = data;

end
