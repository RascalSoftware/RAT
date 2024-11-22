function ymod = refModel_scaled(data,problem,theta,varargin)

% Returns the reflectivity profile. Need to do some extra work because
% 'reflectivity-calculation' adjusts the data according to scalefactor.
% We need to reverse this correction, and actually return the simulation
% corrected for the scalefactor. We have to do this because the scalefactor 
% is in itself one of our fitting parameters (no need to correct the data -
% problem.shiftedData contains the corrected data, but
% problem.data is a record of the original). Also, in this version the
% input parameters are scaled, so they need to be unscaled befor the
% calculation

if isempty(varargin)
    contrast = 1;
else
    contrast = varargin{1};
end

if iscell(data)
    thisData = data{contrast};%.ydata;
    %problem = data{contrast}.problem;
else
    thisData = data;%.ydata;
    %problem = data.problem;
end

%if nargin == 4
%    debugPlot = varargin{2};
%else
    debugPlot = 0;
%end




problemStruct = problem{1};
controls = problem{2};
problemLimits = problem{3};
problemCells = problem{4};

pars = theta;
constr = problemStruct.fitLimits;
pars = unscalePars(pars,constr);

problemStruct.fitParams = pars;
problemStruct = unpackParams(problemStruct,controls.checks);
result = reflectivityCalculation(problemStruct,problemCells,problemLimits,controls);

ySim = result.reflectivity{contrast};

% Need to correct the simulation for the scalefactor (i.e. move the sim to
% the data, unlike what we normally do)
scale = problem.scalefactors(contrast);        
ymod = ySim(:,2).*scale;        % Do something more flashy here for multiple contrasts

% Debug plot to check that everything works..
%debugPlot = 0;
if debugPlot
    plot(thisData(:,1),thisData(:,2),'o');
    hold on
    plot(ySim(:,1),ymod,'-');
    hold off
end

end