% Save this path
curPath = pwd;

[compilePath, ~, ~] = fileparts(mfilename("fullpath"));

cd(compilePath);
ratMainMexBuild(true);
ratMainCodeGen;
cppDeploy;

% Return to initial directory
cd(curPath);
