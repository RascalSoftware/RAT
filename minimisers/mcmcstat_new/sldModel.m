function sld = sldModel(data,problem,theta,varargin)

% Returns the SLD profile for given values of theta 

if isempty(varargin)
    contrast = 1;
else
    contrast = varargin{1};
end

% if iscell(data)
%     thisData = data{contrast}.ydata;
%     %problem = data{contrast}.problem;
% else
%     thisData = data;%.ydata;
%     %problem = data.problem;
% end
% 
% % if nargin == 4
% %     debugPlot = varargin{2};
% % else
%     debugPlot = 0;
% %end

pars = theta;

problemDef = problem{1};
controls = problem{2};
problemDefLimits = problem{3};
problemDefCells = problem{4};
controls.calcSld = 1;

problemDef.fitpars = pars;
problemDef = unpackparams(problemDef,controls);
[~,result] = reflectivityCalculation(problemDef,problemDefCells,problemDefLimits,controls);

sld = result{5}{contrast};

end