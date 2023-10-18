function fn = chainFilt(h)

m = mean(h);
s = 2*std(h);

fn = h(1);
for i = 2:length(h)
    thisVal = h(i);
    if (thisVal < m+s) && (thisVal > m-s)
        fn(end+1) = thisVal;
    else
        fprintf('Removing point %d \n',i);
    end
end

end