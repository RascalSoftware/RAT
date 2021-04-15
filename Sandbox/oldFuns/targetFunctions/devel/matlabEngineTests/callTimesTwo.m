function answer = callTimesTwo(a)

persistent engOpen

if engOpen == 0
   engOpen = 1;
end

answer = timesTwo(a);


end

