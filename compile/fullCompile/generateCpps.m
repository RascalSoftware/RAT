% Save this path
curPath = pwd;

[compilePath, ~, ~] = fileparts(mfilename("fullpath"));

cd(compilePath);
ratMainMexBuild;
ratMainCodeGen;
cppDeploy;

% Return to initial directory
cd(curPath);
