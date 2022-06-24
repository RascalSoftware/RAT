============
Installation
============

You can use RAT either from MATLAB or C++ (through MEX). RAT usually comes with the compiled platform specific MEX file (maxmaci or mexa or mexw).



Build the MEX yourself
-----------------------

RAT can be built from source. To do so, you need to have the following: 

1. A C/C++ compiler.
2. MATLAB 2019 or later.
2. MATLAB Coder 
3. Parallel Computing Toolbox


1. Download the RAT source code from https://github.com/arwelHughes/RAT and extract the zip to a folder.

2. Open MATLAB and navigate to the folder containing the RAT source code.

3. Run the file "buildScript.m" in MATLAB.
   This will add the neccessary paths and builds the MEX file.
 
4. The MEX file will be created in the "RAT/compile/reflectivity_calculation_compile_new/codegen" folder.


Using the MEX version of RAT 
-----------------------------

Doing this will take a while but once, it is done. You can do the following to use the MEX version of RAT:

1. In MATLAB, Open the file  "reflectivity_calculation_wrappper.m" in the folder "RAT/targetFunctions/reflectivity_calculation/"

2. Change the variable "type = 'm'; " to " type = 'mex'; "

3. If you run any script from the test/examples folder, it will use the MEX version of RAT.


.. gotta check if the compilation is working on mac and windows



