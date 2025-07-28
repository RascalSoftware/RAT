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
    %       * shiftValue (float, default: 100) A value between 1 and 100 that controls the spacing between the reflectivity plots for each contrasts.   
    
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
    
    plotRefSLDHelper(data, false, options.linearX, options.q4, options.showErrorBar, ...
                     options.showGrid, options.showLegend, options.shiftValue);
end
