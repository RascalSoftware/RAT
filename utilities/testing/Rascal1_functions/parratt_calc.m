function problem = parratt_calc(problem);

number_of_contrasts = problem.numberOfContrasts;
for i = 1:number_of_contrasts;
    problem.which_contrast = i;
    switch problem.module.type
        case 'Standard Layers'
            [output,s_sub] = standard_box_new(problem);
            if problem.repeatLayers{i}(1) == 1
                repeats = problem.repeatLayers{i}(2);
                if ((repeats==0) || ~isfinite(repeats) || ~isnumeric(repeats))
                    repeats = 1;
                    addInfoText(sprintf('Warining. Strange value for repeats on contrast %d',i));
                end
            else
                repeats = 1;
            end
        case 'Custom Layers'
            extens = findstr(problem.module.name,'.m');
            if ~isempty(extens)
                name = problem.module.name(1:extens-1);
            else
                name = problem.module.name;
            end
            eval(['[output,s_sub] = ' name '(problem.params,problem.nbairs,problem.nbsubs,i);']);
            repeats = 1;
    end
    nbsub = problem.nbsubs(i);
    nbair = problem.nbairs(i);

    %Calculate all the necessary params...
    if ~isempty(output)
        switch problem.module.experiment_type
            case 'Air / Liquid (or solid)'
                layers = output;
            case 'Solid / Liquid'
                roughs = output(:,3);
                slds = output(:,2);
                thicks = output(:,1);
                rsub = roughs(end);
                roughs = [s_sub ; roughs(1:end-1)];
                n = size(output);
                if n(2) == 5;
                    cov = output(:,4);
                    layers = [thicks(:) slds(:) roughs(:) cov(:)];
                else
                    layers = [thicks(:) slds(:) roughs(:)];
                end
                s_sub = rsub;
            otherwise
                errordlg(['Unknown experiment type   ' problem.module.experiment_type]);
                break;
        end

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
    
        
    this_data = problem.shifted_data{i};
    xdata = this_data(:,1);
    %and the reflectivity...
    points = length(xdata);
    if isempty(output)
        slds = [0 nbair 0];
        lays = 0;
    else
        slds = layers(:,1:3);
        lays = size(slds,1);
    end
    
    
    resol = problem.resolutions(i);
    resolType = problem.resolType;

    if resol == 0;
        resolType = 2;
    end
    layers = size(slds,1);
    Ref = abeles_new_2(xdata,slds,nbair,nbsub,s_sub,repeats,resolType,resol);

    simXLo = problem.simLimits{i}(1);
    simXHi = problem.simLimits{i}(2);
    
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
    
    %step = 5e-4;
    %simXdata = [simXLo:step:simXHi];
    simRef = abeles_new_2(simXdata(:),slds,nbair,nbsub,s_sub,repeats,resolType,resol);
    %simRef = resolutionTest(simXdata,simRef,resol);
    
    SLD = makeSLDProfileMultu(nbair,nbsub,s_sub,slds,lays,repeats);
    
%     switch problem.module.experiment_type
%         case 'Air / Liquid (or solid)'
%             SLD = makeSLDProfileAl(nbair,nbsub,s_sub,slds,lays);
%         case {'Solid / Liquid'};
%             SLD = makeSLDProfileAl(nbair,nbsub,s_sub,slds,lays);
%     end

    switch problem.q4
        case 'yes'
            simFres = abeles_new_2(simXdata(:),[0 0 0],nbair,nbsub,0,1,resolType,resol);
        otherwise
            simFres = ones(length(simXdata),1);
    end

    
    %Store all this....
    problem.calculations.reflectivity{i} = [xdata(:) Ref(:)];
    problem.calculations.Simulation{i} = [simXdata(:) simRef(:)];
    problem.calculations.simFresnel{i} = [simXdata(:) simFres];
    problem.calculations.slds{i} = SLD;
end