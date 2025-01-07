============
Installation
============
RAT can be used either by running the m-files directly or using a compiled mex file. 
RAT ships with a pre-compiled MEX file which is available to download from the |release| page. 
To use the mex do the following:

1. Download the source code and the pre-compiled mex for your operating system.
2. Extract the source code and the mex files.
3. Replace the **compile** folder in the RAT source code with the one from the extracted mex folder.
4. Open MATLAB and navigate to the folder containing the RAT source code.
5. Run *addPaths.m* which will add the necessary paths
6. Run your script.

However, if you want to build RAT on your local machine, you need to follow the steps below.

Build the MEX on your local machine 
-----------------------------------
A C/C++ compiler and MATLAB (2021 or later) is required for building the mex. The following MATLAB toolboxes are also required:

- MATLAB Coder
- MATLAB Compiler
- Parallel Computing Toolbox
- Statistics and Machine Learning Toolbox (for DREAM Minimizer)

To build the mex, do the following:

1. Download the RAT source code from the |release| page.
2. Open MATLAB and navigate to the folder containing the RAT source code.
3. Run *addPaths.m* then run *buildScript.m* in MATLAB. This will add the necessary paths and builds the MEX file. 
   This could take several minutes depending on your machine.
4. The MEX files will be created in the **RAT/compile** folder.

If no error shows up, you should be able to run the MEX file.


.. |release| raw:: html

   <a href="https://github.com/RascalSoftware/RAT/releases/latest" target="_blank">Github Release</a>
