function result = varCellCompileTest()


%Make the 'master' cell
%result = cell(1,3);
result = {{[1] ; [1]} {[1] ; [1]} {[1] ; [1]}};

%First cell array
cell1Length = randi(5,1,1);
Cell1 = cell(cell1Length,1);
for i = 1:length(Cell1)
    thisDouble = ones(randi(10,1,1),3);
    result{1}{i} = thisDouble;
end
coder.varsize('result{1}',[Inf 1],[1 0]);
coder.varsize('result{1}{:}',[Inf 3],[1 0]);

%Second cell array
cell2Length = randi(5,1,1);
Cell2 = cell(cell2Length,1);
for i = 1:length(Cell2)
    thisDouble = ones(randi(10,1,1),3);
    result{2}{i} = thisDouble;
end
result{2} = Cell2;
coder.varsize('result{2}',[Inf 1],[1 0]);
coder.varsize('result{2}{:}',[Inf Inf],[1 1]);

%Third cell array
cell3Length = randi(5,1,1);
Cell3 = cell(cell3Length,1);
for i = 1:length(Cell3)
    thisDouble = ones(randi(10,1,1),3);
    result{3}{i} = thisDouble;
end
result{3} = Cell3;
coder.varsize('result{3}',[Inf 1],[1 0]);
coder.varsize('result{3}{:}',[Inf Inf],[1 1]);

end