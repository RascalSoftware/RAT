|RAT banner|

============
Installation
============

Link to the latest release: *linkwillbehere*


RAT can be used either from MATLAB or C++ (Using MEX). If you want to use RAT in C++ on IDAAS, you can just change a variable. To do this check :ref:`usingMex` section. 

However, if you want to use RAT on your local machine(Outside IDAAS) in C++/MATLAB, you need to build the MEX. To do that, you need to follow the steps below.

Build the MEX on your local machine 
---------------------------------------

RAT usually is shipped with a working pre-compiled MEX file that can be used directly on Linux but if you still want to build yourself,
To do so, you need to follow the instructions below: 

**Requirements**

1. A C/C++ compiler.
2. MATLAB 2019 or later.
3. MATLAB Coder 
4. Parallel Computing Toolbox


**Process**

1. Download the RAT source code from https://github.com/arwelHughes/RAT and extract the zip to a folder.

2. Open MATLAB and navigate to the folder containing the RAT source code.

3. Run the file "buildScript.m" in MATLAB.
   This will add the necessary paths and builds the MEX file.
 
4. The MEX file will be created in the "RAT/compile/reflectivity_calculation_compile_new/codegen" folder.



After following the above step and if no error shows up, you must be able to run the MEX file. Do check the following section if your "type" is not set 'mex'

.. _usingMex:

Using the MEX version of RAT 
-----------------------------

If you are on IDAAS or have already compiled the MEX file and want to use RAT in C++, do the following:

1. In MATLAB, Open the file  "reflectivity_calculation_wrapper.m" in the folder "RAT/targetFunctions/reflectivity_calculation/"

2. Change the variable "type = 'm'; " to " type = 'mex'; "

3. If you run any script from the test/examples folder, it will use the MEX version of RAT.


|RasCAL banner|






