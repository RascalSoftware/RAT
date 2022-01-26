function desktop = SetupPlotsAndMainGuiWindows(desktop,problem)

%main Gui Window
internalFrame = javaObjectEDT(mainParamsGuiFrame());
internalFrame.setDefaultCloseOperation(javax.swing.JFrame.DISPOSE_ON_CLOSE);
mainPane = javaObjectEDT(internalFrame.getJTabbedPane1());

problemClass = problem.problem;
problemStruct = problemClass.toStruct();

%Add the relevant panels......
paramsPanel = mainGuiParamsPanelSetup();
type = problemStruct.ModelType;
switch lower(type)
    case 'layers'
        layersPanel = mainLayersPanelSetup();
end

experimentParams = mainExpParamsSetup();
mainPane.addTab('Parameters',paramsPanel);
switch lower(type)
    case 'layers'
        mainPane.addTab('Layers',layersPanel);
end
mainPane.addTab('Experimental Params',experimentParams);

allManiGuiContrastPanels = {[]};
for i = 1:problemStruct.numberOfContrasts
    thisContrastPanel = mainGuiContrastPanelSetup(problem,i);
    allMainGuiContrastPanels{i} = thisContrastPanel;
    mainPane.addTab(sprintf('Contrast %d',i),thisContrastPanel);
end

nameBox = javaObjectEDT(internalFrame.getProjectNameBox());
nameBox.setText(java.lang.String('Name TODO'));
typeBox = javaObjectEDT(internalFrame.getTypeBox());
typeBox.setText(java.lang.String(problemStruct.ModelType));
geomBox = javaObjectEDT(internalFrame.getGeometryBox());
geomBox.setText(java.lang.String(problemStruct.geometry));

desktop.add(internalFrame);
drawnow limitrate;

%Plotting window
% [iframePlots, refChartPanel, sldChartPanel] = makePlottingWindow(problem);
% desktop.add(iframePlots);
% drawnow limitrate;

%setappdata(0,'iframePlots',iframePlots);
%setappdata(0,'refChartPanel',refChartPanel);
%setappdata(0,'sldChartPanel',sldChartPanel);
setappdata(0,'allMainGuiContrastPanels',allMainGuiContrastPanels);
setappdata(0,'mainGuiFrame',internalFrame);
