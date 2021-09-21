names = fitNames;
constr = problemDef.fitconstr;
vals = problemDef.fitpars;
titles = {'Name','Min','Value','Max'};

% For scaled....
mins = zeros(length(names),1);
maxs = ones(length(names),1);
constr = [mins maxs];


thisArray = [constr(:,1) , vals(:), constr(:,2)];

arrayTable = array2table(thisArray);

arrayTable.Properties.RowNames = names;
arrayTable.Properties.VariableNames = {'min','value','max'};
