function textOut(pct,iter,interval)

% interval = 1;
pct = pct * 100;

if ~mod(iter,interval)
    fprintf('Iter %g : %g %% complete \n',iter,pct);
end

end