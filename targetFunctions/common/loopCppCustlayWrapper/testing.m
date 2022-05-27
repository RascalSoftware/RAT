params = [1,2,3,4,5,6,7,8];
nba = 2;
nbs = 3;
numberOfContrasts = int32(3);
libName = "customBilayer";
functionName = "customBilayer";
output = zeros(1,10);
subrough = 1;

% roughness = 1;
[output,subrough] = testDLL_mex(params,nba,nbs,numberOfContrasts,libName,functionName);