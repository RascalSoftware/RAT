function updateShiftsTable()

problem = getappdata(0,'problem');
table = getappdata(0,'mainGuiShiftsTable');
tableModel = getappdata(0,'mainGuiShiftsTableModel');

% Disable table callbacks until updates done
set(tableModel,'TableChangedCallback',[]);

% tableModel = javaObjectEDT(table.getModel());
% 
% setappdata(table,'UserData','Updating From Code');
% setappdata(0,'mainGuiShiftsTable', table);
check_on = java.lang.Boolean.TRUE;
check_off = java.lang.Boolean.FALSE;

%Get all the relevant values out of problem.
checks = problem.shifts_fityesno;
names = problem.shiftsNames;
min = problem.shifts_constr(:,1);
val = problem.shifts_horisontal;
max = problem.shifts_constr(:,2);
rows = length(val);


%Update any cells that have changed...
for r = 1:rows
    thisCheck = tableModel.getValueAt(r-1,0);
    if ~isequal(thisCheck,checks(r))
        if checks(r) == 1
            tableModel.setValueAt(check_on,r-1,0)
        else
            tableModel.setValueAt(check_off,r-1,0)
        end
    end
    
    thisName = tableModel.getValueAt(r-1,1);
    if ~isequal(thisName,names{r})
        tableModel.setValueAt(names{r},r-1,1);
    end
    
    thisMin = tableModel.getValueAt(r-1,2);
    if ~isequal(thisMin,min(r))
        tableModel.setValueAt(min(r),r-1,2);
    end
    
    thisVal = tableModel.getValueAt(r-1,3);
    if ~isequal(thisVal,val(r))
        tableModel.setValueAt(val(r),r-1,3);
    end
    
    thisMax = tableModel.getValueAt(r-1,4);
    if ~isequal(thisMax,max(r))
        tableModel.setValueAt(max(r),r-1,4);
    end
end

% Re enable callbacks
set(tableModel,'TableChangedCallback',@mainGuiShiftsTableEditedCallback);

setappdata(0,'mainGuiShiftsTable',table);
setappdata(0,'mainGuiShiftsTableModel',tableModel);