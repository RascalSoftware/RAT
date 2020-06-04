function problem = dealWithLegacyIssues(problem)


if strcmp(problem.module.type,'Standard Layers')
    if (~any(ismember(fields(problem),'repeatLayers')));
        for i = 1:problem.numberOfContrasts
            problem.repeatLayers{i} = [0 1];
        end
    end
    for i = 1:problem.numberOfContrasts
        if length(problem.repeatLayers{i}) < 2;
            problem.repeatLayers{i} = [0 1];
        end
    end
end

%Deal with the fact that fittable resolution may have been absent in previous
%versions
if ~any(ismember(fields(problem),'resolution_constr'))
    numberOfResolutions = length(problem.resolution);
    problem.numberOfResolutions = numberOfResolutions;
    for i = 1:numberOfResolutions
        problem.resolution_constr(i,1) = 0.01;
        problem.resolution_constr(i,2) = 0.05;
        problem.resolution_fityesno(i) = 0;
        problem.resolNames{i} = ['Resolution ' num2str(i)];
    end
    
    for i = 1:problem.numberOfContrasts
        problem.contrastResolutions(i) = 1;
    end
end

%Resolution type not saved in previous versions
if ~any(ismember(fields(problem),'resolType'))
    problem.resolType = 1;
end

%Deal with fact that file type was not saved in previous versions..
if ~any(ismember(fields(problem),'contrastFileTypes'))
    problem.contrastFileTypes = ones(problem.numberOfContrasts,1);
    problem.forceReload = zeros(problem.numberOfContrasts,1);
end

%Deal with the introduction of ROI's
if ~any(ismember(fields(problem.calculations),'rois'))
    problem.calculations.rois = {};
end


