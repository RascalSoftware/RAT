function convertTest()

% Coversion from R1 to a script for rascal
clear

% Start by converting this to an R2 Class.....
r2Problem = r1ToProjectClass('Monolayer_8_contrasts.mat');
newFileName = 'newTestFile.m';
FID = fopen(newFileName,'w');


%% 1 - Intro part and setting the scene..

% Get the relevant initial object types from the r2Problem
ModelType  = r2Problem.ModelType;
experimentName = r2Problem.experimentName;
Geometry = r2Problem.Geometry;

% Make the class, ans add these experiment parameters
modelTypeSet = sprintf('problem.ModelType = ''%s''; \n',ModelType);
geometryTypeSet = sprintf('problem.Geometry = ''%s''; \n',Geometry);

writeReturns(2,FID);

initialTest = {sprintf('%% RAT Model File for %s \n',experimentName); ...
               sprintf('%% Created by RasCAL %s \n',datestr(date))...
               };
           
rows = size(initialTest,1);
for i = 1:rows
    fwrite(FID,initialTest{i,1});
end

fwrite(FID,sprintf('problem = projectClass(''%s''); \n\n',experimentName));
fwrite(FID,modelTypeSet);
fwrite(FID,geometryTypeSet);
writeReturns(3,FID);


%% 1 - Parameters
fwrite(FID,'%% Setting of Parameters Block');

writeReturns(2,FID);

% Get the parameters table from the projectClass....
paramsTable = r2Problem.parameters.paramsTable;
paramsCell = table2cell(paramsTable);

for n = 2:height(paramsTable)
    thisRow = paramsCell(n,:);
    if thisRow{5}
        thisRow{5} = 'true';
    else
        thisRow{5} = 'false';
    end
    thisAddedRow = sprintf('problem.addParam({''%s'',\t%0.4g,\t%0.4g,\t%0.4g,\t%s}); \n',...
        thisRow{1},thisRow{2},thisRow{3},thisRow{4},thisRow{5});
    fwrite(FID,thisAddedRow);
end
    
writeReturns(3,FID);

%% 2. If present, add layers....
fwrite(FID,'%% Setting of Layers Block');

writeReturns(2,FID);

if strcmpi(ModelType,'standard layers')
   layersTable = r2Problem.layers.layersTable;
   numberOfLayers = height(layersTable);
   
   for i = 1:numberOfLayers
      thisLayer = layersTable{i,:};
      name = thisLayer{1};
      thick = thisLayer{2};
      SLD = thisLayer{3};
      rough = thisLayer{4};
      hydr = string(thisLayer(5));
      if ismissing(thisLayer(5))
          hydr = NaN;
      end
      hydrWhat = thisLayer{6};
      
      % Make layers in a tidy looking way....
      fwrite(FID,sprintf('Layer%d = {  \n',i));
      fwrite(FID,sprintf('\t''%s'',...\t%%Layer Name \n',name));
      fwrite(FID,sprintf('\t''%s'',...\n',thick));
      fwrite(FID,sprintf('\t''%s'',...\n',SLD));
      fwrite(FID,sprintf('\t''%s'',...\n',rough));
      if isnumeric(hydr)
        fwrite(FID,sprintf('\t %d,...\n',NaN));
      else
        fwrite(FID,sprintf('\t''%s'',...\n',hydr));
      end
      fwrite(FID,sprintf('\t''%s'',...\n',hydrWhat));
      fwrite(FID,sprintf('\t}; \n'));
      writeReturns(2,FID);
   end
end

% Now make the layers group...
fwrite(FID,'LayersGroup = {');

for i = 1:numberOfLayers
    thisLayer = sprintf('Layer%d;\t',i);
    fwrite(FID,thisLayer);
end
    
fwrite(FID,sprintf('};\n'));

fwrite(FID,'problem.addLayerGroup(LayersGroup)');
writeReturns(2,FID);

%% Now we set bulk in..
fwrite(FID,'%% Setting of BulkIn Block');

writeReturns(2,FID);

bulkInTable = r2Problem.bulkIn.paramsTable;
numberOfBulkIn = height(bulkInTable);

% For the first one, we just set the existing bulk in that appears by
% default in projectClass
in1 = bulkInTable{1,:};
setString = sprintf('problem.setBulkIn(1,''name'',''%s'',''min'',%d,''value'',%d,''max'',%d,''fit'',%s); \n',...
    in1{1},str2double(in1{2}),str2double(in1{3}),str2double(in1{4}),in1{5});
fwrite(FID,setString);

% If there is more than one 'bulk in', then we need to create the rest
if numberOfBulkIn > 1
    
    for i = 2:numberOfBulkIn
        thisBIn = bulkInTable{i,:};
        setString = sprintf('problem.addBulkIn(%s,%d,%d,%d,%s); \n',...
            thisBIn{1},thisBIn{2},thisBIn{3},thisBIn{4},thisBIn{5});
        fwrite(FID,setString);
    end

end

writeReturns(2,FID);


%% Bulk Out.....

fwrite(FID,'%% Setting of BulkOut Block');

writeReturns(2,FID);

bulkOutTable = r2Problem.bulkOut.paramsTable;
numberOfBulkOut = height(bulkOutTable);

% For the first one, we just set the existing bulk Out that appears by
% default in projectClass
in1 = bulkOutTable{1,:};
setString = sprintf('problem.setBulkOut(1,''name'',''%s'',''min'',%g,''value'',%g,''max'',%g,''fit'',%s); \n',...
    in1{1},str2double(in1{2}),str2double(in1{3}),str2double(in1{4}),in1{5});
fwrite(FID,setString);

% If there is more than one 'bulk in', then we need to create the rest
if numberOfBulkOut > 1
    
    for i = 2:numberOfBulkOut
        thisBOut = bulkOutTable{i,:};
        setString = sprintf('problem.addBulkOut(''%s'',%g,%g,%g,%s); ',...
            thisBOut{1},str2double(thisBOut{2}),str2double(thisBOut{3}),...
            str2double(thisBOut{4}),thisBOut{5});
        fwrite(FID,setString);
    end

end

writeReturns(2,FID);


%% Scalefactors

fwrite(FID,'%% Setting of Scalefactors Block');

writeReturns(2,FID);

scalesTable = r2Problem.scalefactors.paramsTable;
numberOfScales = height(scalesTable);

% For the first one, we just set the existing bulk Out that appears by
% default in projectClass
in1 = scalesTable{1,:};
setString = sprintf('problem.setScalefactor(1,''name'',''%s'',''min'',%g,''value'',%g,''max'',%g,''fit'',%s); \n',...
    in1{1},str2double(in1{2}),str2double(in1{3}),str2double(in1{4}),in1{5});
fwrite(FID,setString);

% If there is more than one scalefactor, then we need to create the rest
if numberOfScales > 1
    
    for i = 2:numberOfScales
        thisScale = scalesTable{i,:};
        setString = sprintf('problem.addScalefactor(''%s'',%g,%g,%g,%s); ',...
            thisScale{1},str2double(thisScale{2}),str2double(thisScale{3}),...
            str2double(thisScale{4}),thisScale{5});
        fwrite(FID,setString);
    end

end

writeReturns(2,FID);

%% Backgrounds

fwrite(FID,'%% Setting of Backgrounds Block');

writeReturns(2,FID);

backs = r2Problem.background;
backParsTable = backs.backPars.paramsTable;
backgroundTable = backs.backgrounds.typesTable;


% Set backsPar table
% Again there is one by default, so we set this first, then add any others
% as for the previous two blocks...

numberOfBackpars = height(backParsTable);
in1 = backParsTable{1,:};
setString = sprintf('problem.setBacksPar(1,''name'',''%s'',''min'',%g,''value'',%g,''max'',%g,''fit'',%s); \n',...
    in1{1},str2double(in1{2}),str2double(in1{3}),str2double(in1{4}),in1{5});
fwrite(FID,setString);

% If there is more than one, add the rest....
if numberOfBackpars > 1

    for i = 2:numberOfBackpars
        thisBackpar = backParsTable{i,:};
        setString = sprintf('problem.addBacksPar(''%s'',%g,%g,%g,%s); ',...
            thisBackpar{1},str2double(thisBackpar{2}),str2double(thisBackpar{3}),...
            str2double(thisBackpar{4}),thisBackpar{5});
        fwrite(FID,setString);
    end

end



% Now we need to make the 'backgrounds' table
writeReturns(2,FID);

numberOfBackgrounds = height(backgroundTable);
in1 = backgroundTable{1,:};
%setString = sprintf('problem.setBackground(1,
        
        


%% Close everything down
fclose(FID);









end


%%
function writeReturns(howMany,FID)

    for n = 1:howMany
        fwrite(FID,sprintf('\n'));
    end
    
end
