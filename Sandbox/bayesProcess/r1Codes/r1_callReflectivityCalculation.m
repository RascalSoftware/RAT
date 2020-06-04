function problem = callReflectivityCalculation(problem);

number_of_contrasts = problem.numberOfContrasts;
resample = 0;

%Divide everything up before entering the calculation...
nbairs = problem.nbairs;
nbsubs = problem.nbsubs;
params = problem.params;
geometry = problem.module.experiment_type;
simLimits = problem.simLimits;
resolutions = problem.resolutions;
allData = problem.shifted_data;
switch problem.module.type
    case 'Standard Layers'
        name = 'standard_box_new';
        type = 1;
    case 'Custom Layers'
        extens = strfind(problem.module.name,'.m');
        if ~isempty(extens)
            name = problem.module.name(1:extens-1);
        else
            name = problem.module.name;
        end
        type = 2;
    case 1   
        name = 'standard_box_new';
        type = 1;
    case 2
        extens = strfind(problem.module.name,'.m');
        if ~isempty(extens)
            name = problem.module.name(1:extens-1);
        else
            name = problem.module.name;
        end
        type = 2;
    case 3
        extens = strfind(problem.module.name,'.m');
        if ~isempty(extens)
            name = problem.module.name(1:extens-1);
        else
            name = problem.module.name;
        end
        type = 3;
end

for i = 1:number_of_contrasts
    if (type == 2 || type == 3)
        eval(['[out,s_sub] = ' name '(params,nbairs,nbsubs,i);']);
    else
        [out,s_sub] = r1_standard_box_new(problem,i);
    end
    
    if type == 3
        curvesld = out;
        outC = curve_to_boxes(out);
        x = outC(:,1);
        y = outC(:,2);
        [xn,yn] = groupSamples(x,y,1e-9);
        rn = zeros(length(xn),1);
        out = [xn(:) yn(:) rn(:)];
    end
    
    outputs{i} = out;
    ssubs(i) = s_sub;
    output = outputs{i};
    
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
                roughs = [s_sub ; roughs(1:end-1)];
                n = size(output);
                if n(2) == 5
                    cov = output(:,4);
                    layers = [thicks(:) sldss(:) roughs(:) cov(:)];
                else
                    layers = [thicks(:) sldss(:) roughs(:)];
                end
                s_sub = rsub;
        end
        
        %Deal with the %coverage if present
        n = size(output);
        if n(2) == 5
            for j = 1:n(1)
                this_pcw = output(j,4);
                if output(j,5) == 1
                    pc_add = nbsubs(i);
                else
                    pc_add = nbairs(i);
                end
                if ~isnan(this_pcw)
                    layers(j,2) = pc_add*(this_pcw/100) + (1-(this_pcw/100))*layers(j,2);
                end
            end
        end
    end
    
    this_data = allData{i};
    xdata = this_data(:,1);

    if isempty(output)
        slds{i} = [0 problem.nbairs(i) 0];
        lays(i) = 0;
    else
        slds{i} = layers(:,1:3);
        lays(i) = size(slds{i},1);
    end
    
    simXLo = simLimits{i}(1);
    simXHi = simLimits{i}(2);
    
    middleSection = this_data(:,1);
    
    if simXLo < xdata(1)
        step = (xdata(2)-xdata(1));
        firstSection = [simXLo:step:(xdata(1)-step)];
    else
        firstSection = [];
    end
    
    if simXHi > xdata(end)
        step = (xdata(end)-xdata(end-1,1));
        lastSection = [xdata(end,1)+step:step:simXHi];
    else
        lastSection = [];
    end
    
    simXdata{i}= [firstSection(:) ; middleSection ; lastSection(:)]';
    trueXdata{i} = middleSection(:);
    simXdata_splits{i} = [length(firstSection) length(middleSection(:,1)) length(lastSection)];
    repeats(i) = problem.repeatLayers{i}(2);
    switch type
        case {1,2}
            sldProfiles{i} = r1_makeSLDProfileMultu(nbairs(i),nbsubs(i),ssubs(i),slds{i},lays(i),repeats(i));
        otherwise
            sldProfiles{i} = curvesld;
    end
end
    
    switch resample
        case 1
          [xn,yn] = resample_sld_mex(sldProfiles{i},1);
          [nx,ny] = groupSamples_mex(xn(:),yn(:),1e-8);
          newSld = [nx(:) ny(:)];
          maxIndex = find(newSld(:,1), 1, 'last' );
          xn = newSld(1:maxIndex,1);
          yn = newSld(1:maxIndex,2);
          rrr = ones(length(xn),1)*1e-9;
          resampled{i} = [xn(:) yn(:) rrr(:)];
    end

  
% if resample
%     slds = resampled;
% end

 
%res = abeles_loop(xdata, SLD, nbair, nbsub, repeat, resol, ssubs);
%tic
simRef = abeles_loop_2(simXdata(:),slds(:),nbairs(:),nbsubs(:), repeats(:), resolutions(:), ssubs(:));
%toc

for i = 1:number_of_contrasts
    splits = simXdata_splits{i};
    firstSection = splits(1);
    middleSection = splits(2);
    Ref = simRef{i};
    Ref = Ref((firstSection+1):(firstSection+middleSection));
    reflectivity{i} = [trueXdata{i} Ref(:)];
    Simulation{i} = [simXdata{i}' simRef{i}];
end

 problem.calculations.reflectivity = reflectivity;
 problem.calculations.Simulation = Simulation;
 problem.calculations.slds = sldProfiles;
 
%disp('debug!');

end