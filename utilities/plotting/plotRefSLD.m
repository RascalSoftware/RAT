function plotRefSLD(problem, result, options)
    arguments
        problem
        result
        options.linearX {logical} = false
        options.q4 {logical} = false
        options.showErrorBar {logical} = true
        options.showGrid {logical} = false
        options.showLegend {logical} = true
    end
    % Convert the problem class to a struct.
    controls = controlsClass();
    data.modelType = problem.modelType;
    [problemStruct,cells,~,~,~] = parseClassToStructs(problem,controls);
    
    data.reflectivity = result.reflectivity;
    data.shiftedData = result.shiftedData;
    data.sldProfiles = result.sldProfiles;
    data.resampledLayers = result.resampledLayers;
    data.dataPresent = problemStruct.dataPresent;
    data.subRoughs = result.contrastParams.subRoughs;
    data.resample = problemStruct.resample;
    data.contrastNames = cells{21};
    
    plotRefSLDHelper(data, false, options.linearX, options.q4, options.showErrorBar, ...
                     options.showGrid, options.showLegend);
end
