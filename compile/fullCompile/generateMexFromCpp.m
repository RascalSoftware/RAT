root = getappdata(0, 'root');
mex_path = [fullfile(root, 'compile', 'fullCompile', 'codegen', 'mex', 'RATMain'), filesep];
mex_interface_path = [fullfile(mex_path, 'interface'), filesep];

includeDirs = getappdata(0,'includeDirs');
includes = strcat(repmat({'-I'}, 1, length(includeDirs)), includeDirs);
includes{end+1} = ['-I', mex_path];
includes{end+1} = ['-I', fullfile(mex_path, 'interface')];

sources = {dir([mex_path, '*.cpp']).name};
sources = strcat(repmat({mex_path}, 1, length(sources)), sources);
sources{end+1} = [mex_interface_path, '_coder_RATMain_api.cpp'];
sources{end+1} = [mex_interface_path, '_coder_RATMain_info.cpp'];

main_file = [mex_interface_path, '_coder_RATMain_mex.cpp'];
if ismac
    if strcmp(computer('arch'), 'maci64')
        ompLib = {['-L', fullfile(matlabroot, 'sys', 'os', 'maci64')], '-liomp5'};
    else
        ompLib = {['-L', fullfile(matlabroot, 'toolbox', 'eml', 'externalDependency', 'omp', 'maca64', 'lib')], '-lomp'};
    end
    includes{end+1} = ['-I', fullfile(matlabroot, 'toolbox', 'eml', 'externalDependency', 'omp', computer('arch'), 'include')];
    mex(includes{:}, 'CXXFLAGS=$CXXFLAGS -fPIC -Xpreprocessor -fopenmp -fvisibility=default -ffp-contract=off -std=c++11 -stdlib=libc++', main_file, sources{:}, '-output', 'RATMain_mex', '-v', '-lemlrt', '-lmwmathutil', '-lmwblas', '-lmwlapack', ompLib{:}) 
elseif isunix
    mex(includes{:}, 'CXXFLAGS=$CXXFLAGS -fopenmp -fvisibility=default -std=c++11', main_file, sources{:}, '-output', 'RATMain_mex', '-v', '-lemlrt', '-lmwmathutil', '-lmwblas', '-lmwlapack', ['-L"', matlabroot, '/sys/os/glnxa64"'], '-liomp5') 
else
    mex(includes{:}, 'COMPFLAGS=$COMPFLAGS /openmp -DHAVE_LAPACK_CONFIG_H -DLAPACK_COMPLEX_STRUCTURE -DMW_HAVE_LAPACK_DECLS -DMW_NEEDS_VERSION_H', main_file, sources{:}, '-output', 'RATMain_mex', '-v', '-llibemlrt', '-llibmwmathutil', '-lmwblas', '-lmwlapack')
end

% Build custom file wrapper 
thisPath = pwd;
cd(fullfile(root,'compile','customWrapper'));
wrapperMexBuild;
cd(thisPath);
