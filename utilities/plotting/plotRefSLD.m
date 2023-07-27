function plotRefSLD(problem, result)

    % Convert the problem class to a struct.
    controls = controlsClass();
    data.modelType = problem.modelType;
    [problemDef,~,~,~,~] = parseClassToStructs(problem,controls);
    
    data.reflectivity = result.reflectivity;
    data.shifted_data = result.shifted_data;
    data.sldProfiles = result.sldProfiles;
    data.allLayers = result.allLayers;
    data.dataPresent = problemDef.dataPresent;
    data.ssubs = result.contrastParams.ssubs;
    data.resample = problemDef.resample;

    switch problemDef.TF
        case 'domains'
            plotDomainsRefSLDHelper(data,false);
        otherwise
            plotRefSLDHelper(data, false);
    end

end
