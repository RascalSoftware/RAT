function bayesShadedPlot(project, result, options)
% Plots the shaded reflectivities from Bayes output from RAT
%
% Example Usage::
% 
%    bayesShadedPlot(project, result, 'interval', 65, 'q4', true);
%
% Parameters
% ----------
% project : projectClass
%    An instance of the projectClass.
% result : struct
%    The result of the RAT Bayesian calculation. 
% options
%    Keyword/value pair to configure plotting, the following are allowed
%       * q4 (logical, default: false) indicates if the Y axis should plot Q^4
%       * keepAxes (logical, default: false) indicates if the figure should be used without clearing axes.
%       * interval (65 or 95, default: 95) Bayesian confidence interval to shade in the plot.
%       * showLegend (logical, default: false) indicates if the legend should be shown.

arguments
    project
    result
    options.q4 {mustBeA(options.q4, 'logical')} = false
    options.keepAxes {mustBeA(options.keepAxes, 'logical')} = false
    options.interval {mustBeMember(options.interval, [65, 95])} = 95
    options.showLegend {mustBeA(options.showLegend, 'logical')} = true
end

if isa(project,'domainsClass')
    isDomains = true;
else
    isDomains = false;
end

if ~options.keepAxes
    clf; hold on; box on
end

switch options.interval
    case 95
        vals = [1 5];
    case 65
        vals = [2 4];
end

fillColor = [0.7 0.7 0.7];
fillType = [1 2; 2 1];
fillAlpha = 0.3;

controls = controlsClass();
[projectStruct,~,~] = parseClassToStructs(project,controls);

% Get the reflectivities and SLDs
reflectivityValues = result.predictionIntervals.reflectivity;
sldValues = result.predictionIntervals.sld;

shiftedData = result.shiftedData;
numberOfContrasts = length(shiftedData);

% Calculate the best fits depending on the selected options
subplot(1,2,1)
set(gca,'YScale','log','XScale','log');
hold on; box on
xlabel('$\textrm{Q}_{z} (\AA^{-1})$', 'Interpreter', 'Latex') 
ylabel('Reflectivity', 'Interpreter', 'Latex')
lines = cell(numberOfContrasts, 1);

for i = 1:numberOfContrasts
    
    thisData = shiftedData{i};
    reflectivity = reflectivityValues{i}(3,:)';
    
    mult = 2^(4*i);
    switch options.q4
        case true
            thisQ4 = thisData(:,1).^4;
        case false
            if i == 1
                mult = 1;
            end
    end
        
    % Get the limits and fits
    limits = reflectivityValues{i};
    
    min = limits(vals(1),:)'./mult;
    max = limits(vals(2),:)'./mult;
        
    reflectivity = reflectivity./mult;
    
    dataX = thisData(:,1);
    dataY = thisData(:,2)./mult;
    dataErr = thisData(:,3)./mult;
    
    refXValues = result.reflectivity{i}(:,1);
    thisSimQ4 = refXValues.^4;

    switch options.q4
        case true
            min = min .* thisSimQ4;
            max = max .* thisSimQ4;
            reflectivity = reflectivity .* thisQ4;
            dataY = dataY(:) .* thisQ4;
            dataErr = dataErr(:) .* thisQ4;
    end
    
    errorbar(dataX,dataY,dataErr,'.');
    lines{i} = plot(refXValues,reflectivity,'-');
    shade(refXValues,min,refXValues,max,'FillColor',fillColor,'FillType',fillType,'FillAlpha',fillAlpha);

end
if options.showLegend
    legend([lines{:}], projectStruct.names.contrasts{:});
end

% Now plot the SLDs
subplot(1,2,2); hold on; box on
xlabel('$\textrm{Z} (\AA)$','Interpreter','Latex')
ylabel('$\textrm{SLD} (\AA^{-2})$','Interpreter','Latex')
nColumns = size(result.sldProfiles, 2);
lines = cell(numberOfContrasts * nColumns, 1);
names = cell(numberOfContrasts * nColumns, 1);

if ~isDomains

    for i = 1:numberOfContrasts

        sld = sldValues{i}(3,:);
        limits = sldValues{i};
        sldXValues = result.sldProfiles{i}(:,1);

        min = limits(vals(1),:);
        max = limits(vals(2),:);

        names{i} = projectStruct.names.contrasts{i};
        lines{i} = plot(sldXValues,sld,'-');
        shade(sldXValues,min,sldXValues,max,'FillColor',fillColor,'FillType',fillType,'FillAlpha',fillAlpha);

    end

else

    for i = 1:numberOfContrasts

        sld = sldValues(i,:);
        limits = sldValues(i,:);
        sldXValues = result.sldProfiles(i,:);

        for j = 1:2
            min = limits{j}(vals(1),:);
            max = limits{j}(vals(2),:);
            index = nColumns*(i-1)+j;

            thisDomainSldXValues = sldXValues{j}(:,1);

            names{index} = sprintf("%s Domain %d", projectStruct.names.contrasts{i}, j);
            lines{index} = plot(thisDomainSldXValues,sld{j}(3,:),'-');
            shade(thisDomainSldXValues,min,thisDomainSldXValues,max,'FillColor',fillColor,'FillType',fillType,'FillAlpha',fillAlpha);
        end
    end

end

if options.showLegend
    legend([lines{:}], names{:});
end

end
