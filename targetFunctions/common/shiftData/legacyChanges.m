function problem = legacyChanges(problem)



layersDetails = problem.layersDetails;

for i = 1:length(layersDetails)
    thisLayer = layersDetails{i};
    for n = 1:4
        thisVal = str2num(thisLayer{n});
        if isempty(thisVal)
            thisVal = NaN;
        end
        newLayer(n) = thisVal;
    end
    if strcmp(thisLayer{end},'bulk in')
        newLayer(5) = 1;
    else
        newLayer(5) = 2;
    end
    layersDetails{i} = newLayer;
end
problem.layersDetails = layersDetails;


contrastLayers = problem.contrastLayers;
numberOfContrasts = length(contrastLayers);

for n = 1:numberOfContrasts;
        thisContrast = contrastLayers{n};
        numLays = length(strfind(thisContrast,','));
        a = zeros(1,numLays);
        count = 1;
        this = '';
        for i = 1:length(thisContrast)
            if thisContrast(i) ~= ','
                this = [this thisContrast(i)];
            elseif thisContrast(i) == ','
                a(count) = str2double(this);
                count = count + 1;
                this = '';
            end
        end
        edited{n} = a;
end

problem.contrastLayers_new = edited;

disp('debug!');








end