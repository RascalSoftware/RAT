function plotRefSLD(problem, result)
    % Convert the problem class to a struct.
    controls = controlsClass();
    data.modelType = problem.modelType;
    [problemDefStruct,~,~,~,~] = parseClassToStructs(problem,controls);
    
    data.reflectivity = result.reflectivity;
    data.shiftedData = result.shiftedData;
    data.sldProfiles = result.sldProfiles;
    data.allLayers = result.allLayers;
    data.dataPresent = problemDefStruct.dataPresent;
    data.ssubs = result.contrastParams.ssubs;
    data.resample = problemDefStruct.resample;
    
    plotRefSLDHelper(data, false);
end
