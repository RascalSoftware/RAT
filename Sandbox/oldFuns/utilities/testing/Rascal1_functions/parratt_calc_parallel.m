function problem = parratt_calc_parallel(problem);


number_of_contrasts = problem.numberOfContrasts;

%Divide everything up before entering the calculation...
nbairs = problem.nbairs;
nbsubs = problem.nbsubs;
params = problem.params;
geometry = problem.module.experiment_type;
simLimits = problem.simLimits;
resolutions = problem.resolutions;
resolTypes = problem.resolType;
allData = problem.shifted_data;
switch problem.module.type
    case 'Custom Layers'
        extens = strfind(problem.module.name,'.m');
        if ~isempty(extens)
            name = problem.module.name(1:extens-1);
        else
            name = problem.module.name;
        end
end



for i = 1:number_of_contrasts;
   eval(['[out,s_sub] = ' name '(params,nbairs,nbsubs,i);']); 
   outputs{i} = out;
   ssubs(i) = s_sub;
end

parfor i = 1:number_of_contrasts
     output = outputs{i};
     ssub = ssubs(i);
    
    %Group the layers according to geometry
    if ~isempty(output)
        switch geometry
            case 'Air / Liquid (or solid)'
                layers = output;
            case 'Solid / Liquid'
                roughs = output(:,3);
                sldss = output(:,2);
                thicks = output(:,1);
                rsub = roughs(end);
                roughs = [ssub ; roughs(1:end-1)];
                n = size(output);
                if n(2) == 5;
                    cov = output(:,4);
                    layers = [thicks(:) sldss(:) roughs(:) cov(:)];
                else
                    layers = [thicks(:) sldss(:) roughs(:)];
                end
                s_sub = rsub;
        end
        repeats = 1;
        
        %Deal with the %coverage if present
        n = size(output);
        if n(2) == 5;
            for j = 1:n(1);
                this_pcw = output(j,4);
                if output(j,5) == 1
                    pc_add = nbsub;
                else
                    pc_add = nbair;
                end
                if ~isnan(this_pcw)
                    layers(j,2) = pc_add*(this_pcw/100) + (1-(this_pcw/100))*layers(j,2);
                end
            end
        end
    end
    
    this_data = allData{i};
    xdata = this_data(:,1);
    points = length(xdata);
    if isempty(output)
        slds = [0 nbair 0];
        lays = 0;
    else
        slds = layers(:,1:3);
        lays = size(slds,1);
    end
    resol = resolutions(i);
    resolType = resolTypes;
    
    if resol == 0;
        resolType = 2;
    end
    layers = size(slds,1);

    simXLo = simLimits{i}(1);
    simXHi = simLimits{i}(2);
    
    middleSection = xdata;
    
    if simXLo < xdata(1);
        step = (xdata(2)-xdata(1));
        firstSection = [simXLo:step:(xdata(1)-step)];
    else
        firstSection = [];
    end
    
    if simXHi > xdata(end);
        step = (xdata(end)-xdata(end-1));
        lastSection = [xdata(end)+step:step:simXHi];
    else
        lastSection = [];
    end
    
    simXdata = [firstSection(:) ; middleSection(:) ; lastSection(:)];
    simRef = abeles_new_2(simXdata(:),slds,nbairs(i),nbsubs(i),s_sub,repeats,resolType,resol);
    Ref = simRef((length(firstSection)+1):(length(firstSection)+length(middleSection)));
    %SLD = makeSLDProfileMultu(nbairs(i),nbsubs(i),s_sub,slds,lays,repeats);
    
    reflectivity{i} = [xdata(:) Ref(:)];
    Simulation{i} = [simXdata(:) simRef(:)];
    %simFresnel{i} = [simXdata(:) simFres];
    %slds{i} = SLD;
end

calculations.reflectivity = reflectivity;
calculations.Simulation = Simulation;
%calculations.simFresnel = simFresnel;
%calculations.slds = slds;

end
