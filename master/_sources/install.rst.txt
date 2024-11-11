============
Installation
============
This section provides more detailed information about installing RAT for Matlab and Python users

.. tab-set::
    :sync-group: code

    .. tab-item:: For Matlab
        :sync: Matlab

        RAT can be used either by running the m-files directly or using a compiled mex file. 
        RAT ships with a pre-compiled MEX file which is available to download from the |release| page. 
        To use the mex do the following:

        1. Download the source code and the pre-compiled mex for your operating system.
        2. Extract the source code and the mex files.
        3. Open MATLAB and navigate to the folder containing the RAT source code.
        4. Run *addPaths.m* which will add the necessary paths
        5. Run your script.

        However, if you want to build RAT on your local machine, you need to follow the steps below.

        **Build the MEX on your local machine**
        
        A C/C++ compiler and MATLAB (2021 or later) is required for building the mex. The following MATLAB toolboxes are also required:

        - MATLAB Coder
        - MATLAB Compiler
        - Parallel Computing Toolbox
        - Statistics and Machine Learning Toolbox (for DREAM Minimizer)

        To build the mex, do the following:

        1. Download the RAT source code from the |release| page.
        2. Open MATLAB and navigate to the folder containing the RAT source code.
        3. Run *addPaths.m* then run *buildScript.m* in MATLAB. This will add the necessary paths and builds the MEX file. This could take several minutes depending on your machine.
        4. The MEX files will be created in the **RAT/compile** folder.

        If no error shows up, you should be able to run the MEX file.

    .. tab-item:: For Python  
        :sync: Python

        The RAT API for Python can be installed from PyPI as follows

        .. code-block:: console

            pip install RATapi

        matlabengine is an optional dependency only required for Matlab related action such as running Matlab custom functions and converting RasCAL1 projects.
        The version of matlabengine should match the version of Matlab installed on the computer. For example, if Matlab 2023a is installed on the computer, 
        matlabengine can be installed as shown below:

        .. code-block:: console

            pip install RATapi[Matlab-2023a]


.. |release| raw:: html

   <a href="https://github.com/RascalSoftware/RAT/releases/latest" target="_blank">Github Release</a>
