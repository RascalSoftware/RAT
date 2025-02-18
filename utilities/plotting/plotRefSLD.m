function plotRefSLD(project, result, options)
    % Plots the reflectivity and SLD profiles
    %
    % Example Usage::
    % 
    %    plotRefSLD(problem, result, 'showGrid', true, 'q4', true);
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
    
    arguments
        project
        result
        options.linearX {logical} = false
        options.q4 {logical} = false
        options.showErrorBar {logical} = true
        options.showGrid {logical} = false
        options.showLegend {logical} = true
    end
    % Convert the project class to a struct.
    controls = controlsClass();
    data.modelType = project.modelType;
    [projectStruct,~,~] = parseClassToStructs(project,controls);
    
    data.reflectivity = result.reflectivity;
    data.shiftedData = result.shiftedData;
    data.sldProfiles = result.sldProfiles;
    data.resampledLayers = result.resampledLayers;
    data.dataPresent = projectStruct.dataPresent;
    data.subRoughs = result.contrastParams.subRoughs;
    data.resample = projectStruct.resample;
    data.contrastNames = projectStruct.names.contrasts;
    
    plotRefSLDHelper(data, false, options.linearX, options.q4, options.showErrorBar, ...
                     options.showGrid, options.showLegend);
end
