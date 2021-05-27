function globalCellTest(nCells,arraySize)
%#codegen


% Check of sharing scope of variable sized cell
% array between an outer and inner function with Matlab Coder


% Make a variable sized homogenours cell
invR = cell(1,nCells);
for i = 1:nCells
    invR{i} = zeros(arraySize);
end
innerFunScopeTest();


function innerFunScopeTest()
    for n = 1:length(invR)
        fprintf('Cell %d \n', int16(n));
    end
end

end

