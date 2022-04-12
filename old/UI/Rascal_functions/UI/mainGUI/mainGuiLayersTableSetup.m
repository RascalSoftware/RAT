function table = mainGuiLayersTableSetup()

import javax.swing.table.DefaultTableModel;
import javax.swing.JTable;

problem = getappdata(0,'problem');
problemClass = problem.problem;
problemStruct = problemClass.toStruct;

headings = {'Layer Name','Thickness','SLD','Roughness','%Hydr','Hydrate with'};
rows = problemStruct.numberOfLayers;
names = problemStruct.paramNames;

layersDetails = problemStruct.layersDetails;
layersNames = problemStruct.layersnames;

%Put all the values into an array
Vals = {};
for r = 1:rows
        Vals{r,1} = layersNames{r};

        Vals{r,2} = names{layersDetails{r}(1)};
        Vals{r,3} = names{layersDetails{r}(2)};
        Vals{r,4} = names{layersDetails{r}(3)};
        
        if ~isnan(layersDetails{r}(4))
            Vals{r,5} = names{layersDetails{r}(4)};
            if layersDetails{r}(5) == 2
                Vals{r,6} = 'Bulk Out';
            else
                Vals{r,6} = 'Bulk In';
            end
        else
            Vals{r,5} = '';
            Vals{r,6} = '';
        end
end

%Apply the TableModel to the JTable
model = javaObjectEDT(mainGuiLayersDefaultTableModel(Vals,headings));
table = javaObjectEDT(JTable(model));

setappdata(0,'mainGuiLayersTable',table);

end