sz = [1 5];
varTypes = {'string','double','double','double','logical'};
varNames = {'Name','Min','Value','Max','Fit?'};
T2 = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames)

v = {'substrate roughness', 3,4,5,true};

T2(end,:) = v