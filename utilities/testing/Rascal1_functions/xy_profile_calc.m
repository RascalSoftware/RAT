function problem = xy_profile_calc(problem);

number_of_contrasts = problem.numberOfContrasts;
for loop = 1:number_of_contrasts;
    problem.which_contrast = loop;
    params = problem.params;
    bulk_in = problem.nbairs;
    bulk_out= problem.nbsubs;
    name = problem.module.name;
    point = findstr(name,'.');
    if ~isempty(point)
        name = name(1:point-1);
    end
    a = ['[output] = ' name '(params,bulk_in,bulk_out,loop);'];
    eval(a);

    if (size(output,2) ~= 2)
        addInfoText('For this type of problem, module output needs to be SLD profile as two columns of z-values(in Å) and SLD');
        return
    end
    problem.calculations.slds{loop} = output;
    %Calculate all the necessary params...
    %First change the reflectivity curve into boxes...
    output = curve_to_boxes(output);

  
     nbsub = problem.nbsubs(loop);
     nbair = problem.nbairs(loop);
%     
% 
    this_data = problem.shifted_data{loop};
    xdata = this_data(:,1);
    %and the reflectivity...
    thicks = output(:,1);
    slds = output(:,2);
    points = length(xdata);
    layers = length(slds);
    roughs = zeros(layers,1);
    slds = [thicks(:) slds(:) roughs(:)];
    resol = problem.resolution;
    resolType = problem.resolType;
    %abeles(xdata,SLDs,nbair,nbsub,ssub,nrepeats,sinter,resol)
    %Ref = abeles_new_2(xdata,slds,nbair,nbsub,s_sub,repeats,
    Ref = abeles_new_2(xdata,slds,nbair,nbsub,0,1,resolType,resol);
% 
    simXLo = problem.simLimits{loop}(1);
    simXHi = problem.simLimits{loop}(2);
    
    middleSection = xdata;
    
    if simXLo < xdata(1);
        step = xdata(2)-xdata(1);
        firstSection = [simXLo:step:(xdata(1)-step)];
    else
        firstSection = [];
    end
    
    if simXHi > xdata(end);
        step = xdata(end)-xdata(end-1);
        lastSection = [xdata(end)+step:step:simXHi];
    else
        lastSection = [];
    end
    
    simXdata = [firstSection(:) ; middleSection(:) ; lastSection(:)];
    
    s_sub = 0;
    simRef = abeles_new_2(simXdata(:),slds,nbair,nbsub,0,1,resolType,resol);
    switch problem.q4
        case 'yes'
            simFres = abeles_new_2(simXdata(:),[0 0 0],nbair,nbsub,0,1,resolType,resol);
        otherwise
            simFres = ones(length(simXdata),1);
    end
    problem.calculations.reflectivity{loop} = [xdata Ref];
    problem.calculations.Simulation{loop} = [simXdata(:) simRef(:)];
    problem.calculations.simFresnel{loop} = [simXdata(:) simFres];
    %problem.calculations.slds{i} = SLD;



end

        