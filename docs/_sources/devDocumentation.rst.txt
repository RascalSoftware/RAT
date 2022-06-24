.. _devDocs:

========================
Developer Documentation
========================

This documentation is intented towards developers who wish to understand how RAT's core workflow works and all the different components of the software. 
The following picture shows the core workflow of RAT.

.. image:: ./toolbox.png
   :alt: RAT's core workflow

Unit Testing 
==============

Unit Testing is the process of testing multiple individual pieces/features of the software. It helps to find bugs easily and quickly since each individual feature is tested 
independently.


RAT's unit tests are written in MATLAB using :code:`matlab.unittest` framework. 
These unit tests are written to test the following set of functions:

1. :ref:`CommonFunctions`

2. :ref:`StandardTF_reflectivityCalculation`

3. :ref:`ProjectClass`

4. :ref:`controlsDef`

.. note::
      All the common function tests compare the **stable output** against the **on-demand output** of a function. This is done to make sure that the current function is behaving 
      as expected. On the contrary, all the standard_TF tests compare the MATLAB output against the MEX output. This is done to make sure and catch any unseen errors during
      compiling the MEX file by MATLAB Coder.

**Stable output** = This is the output of a certain function obtained when the function is working as expected.

**On-demand output** = This is the output of a certain function at the moment. So, that current function can be tested against the stable one.

.. note::
      Despite tests being written in MATLAB, RAT's unit tests also test the C++ code of RAT in a way.
      This is acheieved through comparing the outputs of mex and matlab versions of all the possible parallelizations of standardTF_reflectivityCalculation.
      This includes the following:

        1. standardTF_customLayers (Single,Points and Contrast)
        2. standard_TF_customXY (Single,Points and Contrast)
        3. standardTF_standardLayers (Single,Points and Contrast)




Custom Layers Functionality
-----------------------------

RAT allows users to create their own custom models and use them in the reflectivity calculations. RAT currently supports C++ and MATLAB custom models meaning users can upload
their model in the form of a function in MATLAB. However, there is a slight complication with the C++. 

Inorder, to use the custom C++ model, the user needs to compile the function into a shared library (preferably using GCC) and then provide the path and name of the function inside the shared library to RAT. 
The following guide will help the user to do this.


How does C++ custom model work?
-------------------------------
The implementation of the custom C++ model functionality is bit complicated but the idea is simple. For sake of explanation, DLL and dynamic library are interchangeably used here. 

1. The user submits a DLL file that has the custom C++ model in the form of a function. Our job is to get that function so we can run with the arguments from RAT. Inorder to *get*
   the file we used an open-source project called `dylib`_. dylib helps us extract the function from the DLL at runtime which means we can use the function at runtime. 


2. When the users makes the DLL, they put the *DYLIB_API* macro at the beginning of the function which exports the function.


3. There is a class called *libManager.h* in *RAT/targetFunctions/common/loopCppCustlayWrapper* directory which opens a DLL and extracts the function when given the 
   path to the DLL. Then runs the function with the arguments from RAT. This the C++ side of the implementation


4. We need a gateway that allows MATLAB inputs to go into the C++ side of the code. This is done by creating a MEX function using MATLAB Coder. The file *testDLL.m* is compiled by 
   Matlab Coder. 
   
   This file basically passes the inputs from MATALB Workspace to the function from *libManager.h* which runs those inputs/arguments on the function from the DLL.


5. As soon the we pass and compute the results comeback into the MATLAB workspace. 

The above explanation holds true for the case of MATLAB version of RAT. If this feature is being used in the compiled version of RAT (i.e setting reflectivity_calculation_wrappper case to **mex**),
there's a case statement that will treat testDLL_mex as an extrinisic function and not a MEX function as per the guidelines of MATLAB Coder.


How to create a custom C++ model
---------------------------------

1. First Step is to make sure your cpp file is error-free and follow the guidelines mentioned in this step. Your cpp file should contain your custom model and 
custom model should be a function. Inorder for RAT to fetch your custom model/function, it needs to be exported. So, you have to get `dylib.hpp`_ here and put **DYLIB_API** 
macro infront of the function name.

.. _dylib.hpp: https://github.com/martin-olivier/dylib/releases/download/v1.8.2/dylib.hpp

.. _dylib: https://github.com/martin-olivier/dylib/

.. code-block::

        DYLIB_API void myCustomFunction(double *params...etc....)


2. Now that you have put DYLIB_API infront of the dependencies. It is time to make a dynamic library of your model. To do this, you must follow platform specific instructions below.

Lets say your file is called **myModel.cpp** and your function is called **myCustomFunction**

.. dropdown:: How to compile a shared library on Windows

    
    **Windows - DLL**
    

    **Prerequites**: MinGW or Microsoft Visual Studio Compiler (MSVC) but GCC is strongly suggested

    **GCC**

    .. code-block:: bash

            g++ -c myModel.cpp -o myModel.o   Generate an object file
            g++ -shared myModel.o -o myModel.dll  outputs a DLL named myModel.dll

    **MSVC (Microsoft Visual Studio Compiler)**

    Open *Developer Command Prompt for Visual Studio*

    .. code-block:: bash

            cl.exe /LD myModel.cpp /EHsc   You should see myModel.dll in the current directory

.. dropdown:: How to compile a shared library on Linux/IDAAS

    **Linux/IDAAS  - .so**
    

    .. code-block:: bash

            g++ -c myModel.cpp -o myModel.o -std=c++11  Generate an object file
            g++ -shared myModel.o -o myModel.so  outputs a .so named myModel.so




Additional Documentation
========================

This documentation is very detailed interms of code. It contains direct links to definitions of functions involved and is helpful for developers
who want to understand how RAT works in more detail.


The following documentation shows code along with visualizations.
Click on the link below to see the code.

`Additional Documentation`_

.. _Additional Documentation: ../m2htmlGeneratedDocs/index.html

Dependency Graph
-----------------
The following picture shows the dependency graph of RAT. The dependency graph is a graph that shows how the different components of RAT work together. 
Click on the nodes to see the documentation of the component. 

Click on the "Graph" to see the dependency graph.

`Graph`_

.. _Graph: ../m2htmlGeneratedDocs/graph.html





DevOps 
======
DevOps is extremely important for any software that needs faster deployments and easier maintaince of existing deployments and RAT is exactly that. 


Jenkins
--------

.. put an image of jenkins logo here

.. image:: https://th.bing.com/th/id/OIP.GKIe0tehC6rMKoG86wMkewHaFb?w=266&h=193&c=7&r=0&o=5&pid=1.7


.. _Jenkins: https://jenkins.io/


`Jenkins`_ is a famous automation tool that automates building, testing and deploying. At the moment, it is used for building and testing but the deployments could be automated as well.
At STFC, there is a platform called Anvil (not be confused with Anvil the web development tool). Anvil is a service that hosts Jenkins instances for various teams across the STFC's intranet. 
This is managed by **Alan Kyffin**. 

STFC Cloud
-----------

RAT owns two nodes/machines( Windows and Linux) in the cloud which are connected to Anvil. They help build,test the RAT in different operating systems.

.. warning::
    These nodes must be manually logged in if there's any disruption in the STFC network (happens usually during updates/network-wide shutdowns).
    Inorder to connect the nodes to Anvil, a command is used. This command can be obtained from Arwel Hughes.

Contacts 
^^^^^^^^^

1. Issues with Linux node - Alexander Dibbo
2. Issues with Windows node - Simon Hodder (usually someone on his team will help)


Work Flow 
---------

This section details how everything works together in the DevOps department.

1. First, there is GitHub repository at `RAT`_ which is source for all of the DevOps. Everytime, there's a Pull Request (PR) or a push, Jenkins gets triggered. This is achieved
   using the Anvil Github App that recogines these changes and initiates builds.
2. When Jenkins gets triggered, usually it builds according to the "Jenkinsfile" in the repository."Jenkinsfile" is a file that contains the instructions for Jenkins to build the project. Jenkins sends these commands to the nodes in the cloud and build/tests the project.
   If the build/test is successful, the PR or push is successful and the PR/push is merged. If the build/test is unsuccessful, the PR/push must be reviewed. 

.. _RAT: https://github.com/arwelHughes/RAT






References for Devs 
----------------------------
1. Checkout the Architectural Desicion Record (ADR) for RAT. This document contains all the decisions made in the past and why they were made.
   This can be found in RasCal Planner in Microsoft Planner.

2. 






































.. GHOST CODE ___________________________________________________________________________________
.. High Level Components
.. =========================
.. At a high level, RAT only contains two components. These are really important and makes up the core of RAT.

.. 1. Project Class
.. 2. ControlsDef Class


.. .. _ProjectClass:

.. .. Project Class
.. .. --------------
.. .. Project Class is all about data. It contains the very data user wants to work with. It stores all the data required for reflectivity calculations. 
.. .. Everything in RAT comes from RAT in one way or another. There are many functions that deal with breaking down the data from Project Class into smaller pieces 
.. .. so that they can be used in other parts of the software.

.. .. .. automodule:: API.projectClass
.. .. .. autoclass:: projectClass

.. .. **Important Methods:**
.. .. ^^^^^^^^^^^^^^^^^^^^^^^
.. .. The following are some of the most used methods in the Project Class.

.. .. .. dropdown:: Show important methods of Project Class

.. ..     **addContrast**

.. ..     This function adds a contrast to the project.

.. ..     .. automodule:: API.projectClass
.. ..     .. automethod:: projectClass.addContrast
        
.. ..     **addBackground**
   
.. ..     This function adds a background to the project.

.. ..     .. automodule:: API.projectClass
.. ..     .. automethod:: projectClass.addBackground

.. ..     **addBulkOut**
   
.. ..     This function adds a bulk out to the project.

.. ..     .. automodule:: API.projectClass
.. ..     .. automethod:: projectClass.addBulkOut

.. ..     **setModelType**
    
.. ..     This function sets the model type of the project. It can be "custom layers" or "standard layers" or "custom XY".

.. ..     .. automodule:: API.projectClass
.. ..     .. automethod:: projectClass.setModelType

.. ..     **addCustomFile**
   
.. ..     This function adds a custom file to the project. This is really useful if the user want to use their own custom model.
.. ..     Currently, RAT supports MATLAB and C++ custom models.

.. ..     .. automodule:: API.projectClass
.. ..     .. automethod:: projectClass.addCustomFile








.. .. **All methods**
.. .. ^^^^^^^^^^^^^^^^

.. .. .. dropdown:: Show all methods of Project Class


.. ..     .. automodule:: API.projectClass
.. ..     .. autoclass:: projectClass
.. ..         :show-inheritance:
.. ..         :members:

        

.. .. _ControlsDef:

.. ControlsDef Class
.. -----------------
.. .. ControlsDef Class is all about control. It is neccessary in determine the way RAT works. It deals with how the user interacts with the software. From type of parallelization
.. .. to whether the users wants to calculate SLD during fit and even how many iteration an algorithm should do ..etc.

.. .. .. dropdown:: Show all methods of ControlsDef Class

.. ..     .. automodule:: API.controlsDef
.. ..     .. autoclass:: controlsDef
.. ..         :show-inheritance:
.. ..         :members:
