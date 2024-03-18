function plotRefSLD(problem, result)
    % Convert the problem class to a struct.
    controls = controlsClass();
    data.modelType = problem.modelType;
    [problemStruct,~,~,~,~] = parseClassToStructs(problem,controls);
    
    data.reflectivity = result.reflectivity;
    data.shiftedData = result.shiftedData;
    data.sldProfiles = result.sldProfiles;
    data.resampledLayers = result.resampledLayers;
    data.dataPresent = problemStruct.dataPresent;
    data.allSubRough = result.contrastParams.allSubRough;
    data.resample = problemStruct.resample;
    
    plotRefSLDHelper(data, false);
end
