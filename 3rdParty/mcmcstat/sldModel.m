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

problemStruct = problem{1};
controls = problem{2};
controls.calcSldDuringFit = true;

problemStruct.fitParams = pars;
problemStruct = unpackParams(problemStruct);
result = reflectivityCalculation(problemStruct,controls);

sld = result.sldProfiles{contrast};

end