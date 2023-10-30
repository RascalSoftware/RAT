function x = makeCell(m, n, vals)
    % Creates a m by n cell array and initialise each cell with given
    % value
    %
    % array = makeCell(5, 2, [1, 1])
    x = cell(m, n);   
    for i = 1:m
        for j = 1:n
            x{i, j} = vals;
        end
    end
end