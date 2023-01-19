.. _userDocs:

====================
User Documentation
====================

*Many pieces of user instructions go here but this is one piece I have. Should be organized when other pieces from Arwel come*

How to create a custom C++ model
---------------------------------



1. First Step is to make sure your cpp file is error-free and follow the guidelines mentioned in this step. Your cpp file should contain your custom model and 
custom model should be a function. In order for RAT to fetch your custom model/function, it needs to be exported. So, you have to get `dylib.hpp`_ here and put **DYLIB_API** 
macro in front of the function name.

.. _dylib.hpp: https://github.com/martin-olivier/dylib/releases/download/v1.8.2/dylib.hpp

.. _dylib: https://github.com/martin-olivier/dylib/

.. code-block::

        DYLIB_API void myCustomFunction(double *params...etc....)


2. Now that you have put DYLIB_API in front of the dependencies. It is time to make a dynamic library of your model. To do this, you must follow platform specific instructions below.

Lets say your file is called **myModel.cpp** and your function is called **myCustomFunction**

.. dropdown:: How to compile a shared library on Windows

    
    **Windows - DLL**
    

    **Prerequisites**: MinGW or Microsoft Visual Studio Compiler (MSVC) but GCC is strongly suggested

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

