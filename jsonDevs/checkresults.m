function checkResults(res1,res2)

names = fieldnames(res1);

for i = 1:numel(names)
    n = names{i};
    if isequal(res1.(n), res2.(n))
        fprintf('%s ok\n',n)
    else
        warning(sprintf('%s failed\n',n))
    end

end