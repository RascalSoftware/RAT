function table = mainGuiContrastLayersDetailsTable(problemStruct,contrast);

import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

numberOfLayers = length(problemStruct.contrastLayers{contrast});
layers = problemStruct.contrastLayers{contrast};
%lays = str2num(layers{:});

rows = numberOfLayers+2;
nba = problemStruct.nbairNames;
nbs = problemStruct.nbsubNames;

headings = {'','Layers'};
Vals = {};

whichBulkIn = problemStruct.contrastNbas(contrast);
Vals{1,1} = 'Bulk In';
Vals{1,2} = nba{whichBulkIn};

for i = 2:rows-1
    Vals{i,1} = ' ';
    thisLayName = problemStruct.layersnames(layers(i-1));
    Vals{i,2} = thisLayName;
end

whichBulkOut = problemStruct.contrastNbss(contrast);
Vals{rows,1} = 'Bulk Out';
Vals{rows,2} = nbs{whichBulkOut};

model = javaObjectEDT(mainGuiLayersDefaultTableModel(Vals,headings));
table = javaObjectEDT(JTable(model));

for i = 1:2
    column = javaObjectEDT(table.getColumnModel().getColumn(i-1));
    column.setCellRenderer(javaObjectEDT(CentreRenderer()));
end

end