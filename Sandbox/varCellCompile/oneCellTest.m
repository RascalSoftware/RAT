function outResult = oneCellTest(cell1Length)


c = cell(1,cell1Length);
Cell1 = coder.nullcopy(c);
for i = 1:length(Cell1)
    thisDouble = ones(randi(10,1,1),3);
    Cell1{i} = thisDouble;
end
outResult = Cell1;

end