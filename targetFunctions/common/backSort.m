function [outBackgroundParam,outQzshift,outScalefactor,outBulkIn,outBulkOut,outResolutionParam] = backSort(contrastBackgroundParams,contrastQzshifts,contrastScalefactors,contrastBulkIns,contrastBulkOuts,contrastResolutionParams,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams)
    % Distributes the background and shift values among the different contrasts
    %
    % USAGE::
    %
    %    [backgroundParams,qzshift,scalefactor,bulkIn,bulkOut,resolutionParams] = backsort(contrastBackgrounds,contrastQzshifts,contrastScalefactors,contrastBulkIns,contrastBulkOuts,contrastResolutions,backs,qzshifts,scalefactor,bulkIn,bulkOut,res)
    %
    % INPUTS:
    %    * contrastBackgroundParams: Which background value is associated with each contrast
    %    * contrastQzshifts: Which qz_shift value is associated with each contrast
    %    * contrastScalefactors: Which scalefactor value is associated with each contrast
    %    * contrastBulkIns: Which BulkIn value is associated with each contrast
    %    * contrastBulkOuts: Which BulkOut value is associated with each contrast
    %    * contrastResolutionParams: Which resolution value is associated with each contrast
    %    * backgroundParams: List of all background parameter values.
    %    * qzshifts: List of all qzshift values
    %    * scalefactors: List of all scalefactor values
    %    * bulkIn: List of all bulkIn values
    %    * bulkOut: List of all bulkOut values
    %    * resolutionParams: List of all resolution parameter values
    % 
    % OUTPUTS:
    %    * outBackground: list of actual background parameter values for each contrast
    %    * outQzshift: list of actual qzshift values for each contrast      
    %    * outScalefactor: list of actual scalefactor values for each contrast     
    %    * outBulkIn: list of actual bulkIn values for each contrast     
    %    * outBulkOut: list of actual bulkOut values for each contrast
    %    * outResolution: list of actual resolution parameter for each contrast  
    
        thisType = contrastBackgroundParams(1);         % What type of background is it?
        thisArray = contrastBackgroundParams(2:end);    % Any associated values...
        switch thisType
            case 0    
                % Constant background. We only need the second
                % value. But we want to preserve the flag as the first
                % value of 'outBackgroundParam', so that downstream knows what to do.
                % The second value of
                % outBackgroundParam should be the actual background
                % value..
                thisValue = thisArray(1);
                if thisValue ~= -Inf
                    outBackgroundParam = [thisType backgroundParams(thisValue)];
                else
                    outBackgroundParam = [thisType thisValue];
                end

           case -1    
                % Data background. We need the second value, which is the
                % data entry, and the third value which is an optional offset parameter.
                % But we want to preserve the flag as the first
                % value of 'outBackgroundParam', so that downstream knows what to do.
                thisData = thisArray(1);
                thisOffset = thisArray(2);
                if thisOffset ~= -Inf
                    outBackgroundParam = [thisType backgroundParams(thisOffset)];
                else
                    outBackgroundParam = [thisType thisOffset];
                end

            case -2     % Function Background
                % The relevant background in in the data, so just output
                % the type again - although it'll never be used, not
                % assigning anything will throw an error...
                outBackgroundParam = thisType;
        end

        % if contrastBackgroundParams(1) ~= -1
        % 
        %     outBackgroundParam = backgroundParams(contrastBackgroundParams);
        % else
        %     outBackgroundParam = -1;     % Negative value means we have a data background.
        % end

        outQzshift = qzshifts(contrastQzshifts);
        
        outScalefactor = scalefactors(contrastScalefactors);
        
        outBulkIn = bulkIn(contrastBulkIns);
        
        outBulkOut = bulkOut(contrastBulkOuts);
        
        if contrastResolutionParams ~= -1
            outResolutionParam = resolutionParams(contrastResolutionParams);
        else
            outResolutionParam = -1;     % Negative value means we have a data resolution.
        end

end
