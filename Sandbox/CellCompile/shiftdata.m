function shifted_data = shiftdata(scalefac,horshift,dataPresent,data,dataLimits)

%Shifts the data according to scale factor
% scalefac = problem.scalefactors;
% horshift = problem.qshifts;
% numberOfContrasts = problem.numberOfContrasts;
% dataPresent = problem.dataPresent;
% allData = problem.data;
% dataLimits = problem.dataLimits;
%shifted_data = cell(1,numberOfContrasts);

switch dataPresent
    case 1
        if scalefac == 0
            scalefac = 1e-30;
        end
        data(:,1) = data(:,1) + horshift;
        data(:,2) = data(:,2) ./ scalefac;
        data(:,3) = data(:,3) ./ scalefac;
        
        lowLimit = dataLimits(1);
        hiLimit = dataLimits(2);
        
        lowIndex = find(data(:,1) < lowLimit);
        if ~isempty(lowIndex)
            lowIndex = lowIndex(end);
        else
            lowIndex = 1;
        end
        
        hiIndex = find(data(:,1) > hiLimit);
        if  ~isempty(hiIndex)
            hiIndex = hiIndex(1);
        else
            hiIndex = length(data(:,1));
        end
        
        shifted_data = data(lowIndex:hiIndex,:);
    otherwise
        shifted_data = data;
end

 

% function Ref = makeFresnelData(problem,contrast)
% 
%     this_data = problem.shifted_data{contrast};
%     xdata = this_data(:,1);
%     nbair = problem.nbairs(contrast);
%     nbsub = problem.nbsubs(contrast);
%     slds = [0 0 0];
%     resol = problem.resolution;
%     resolType = problem.resolType;
%     %abeles(xdata,SLDs,nbair,nbsub,ssub,nrepeats,sinter,resol)
%     %Ref = abeles_new_2(xdata,slds,nbair,nbsub,s_sub,repeats,
%     Ref = abeles_new_2(xdata,slds,nbair,nbsub,0,1,resolType,resol);





 

    