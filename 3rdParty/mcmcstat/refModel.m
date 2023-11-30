function ymod = refModel(data,problem,theta,varargin)

% Returns the reflectivity profile. Need to do some extra work because
% 'reflectivity-calculation' adjusts the data according to scalefactor.
% We need to reverse this correction, and actually return the simulation
% corrected for the scalefactor. We have to do this because the scalefactor 
% is in itself one of our fitting parameters (no need to correct the data -
% problem.shifted_data contains the corrected data, but
% problem.data is a record of the original).

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

pars = theta;

problemDef = problem{1};
controls = problem{2};
problemDefLimits = problem{3};
problemDefCells = problem{4};

problemDef.fitpars = pars;
problemDef = unpackParams(problemDef,controls);
[problem,result] = reflectivityCalculation(problemDef,problemDefCells,controls);

ySim = result{1}{contrast};

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