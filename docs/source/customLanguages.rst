.. _customLanguages:


Custom Models in Python or C++
..............................

Custom models are usually written in Matlab, but RAT allows alternative languages to be used. You can write your custom models either in Python or C++.
The reason for the Python functionality is mainly since this is the more natural choice when using RAT from Python with pythonRAT, but also because the user might choose to incorporate Python libraries into the custom models that are not available in Matlab.
The reason for C++ if for pure speed, where very computationally demanding custom models calculations are required. Both optios are easy to use in RAT.

.. note::
    Examples of using Python and C++ custom models can be found in the /examples/miscellaneous/alternativeLanguages folder

Python Custom Models
====================
.. note::
    Before you use Python from your Matlab session, please ensure that Python is `configured correctly on your system. <https://uk.mathworks.com/help/matlab/matlab_external/create-object-from-python-class.html>`_


Custom models in Python and Matlab are very similar in structure. The following Matlab custom model can easily be translated to the Python version:

.. code:: MATLAB

    %customBilayer.m
    function [output,sub_rough] = customBilayer(params,bulk_in,bulk_out,contrast)

        sub_rough = params(1);
        oxide_thick = params(2);
        oxide_hydration = params(3);
        lipidAPM = params(4);
        headHydration = params(5);
        bilayerHydration = params(6);
        bilayerRough = params(7);
        waterThick = params(8);


        % We have a constant SLD for the oxide..
        oxide_SLD = 3.41e-6;

        % Now make the lipid layers..
        % Use known lipid volume and compositions
        % to make the layers

        % define all the neutron b's.
        bc = 0.6646e-4;     %Carbon
        bo = 0.5843e-4;     %Oxygen
        bh = -0.3739e-4;	%Hydrogen
        bp = 0.513e-4;      %Phosphorus
        bn = 0.936e-4;      %Nitrogen
        bd = 0.6671e-4;     %Deuterium

        % Now make the lipid groups..
        COO = (4*bo) + (2*bc);
        GLYC = (3*bc) + (5*bh);
        CH3 = (2*bc) + (6*bh);
        PO4 = (1*bp) + (4*bo);
        CH2 = (1*bc) + (2*bh);
        CHOL = (5*bc) + (12*bh) + (1*bn);

        % Group these into heads and tails:
        Head = CHOL + PO4 + GLYC + COO;
        Tails = (34*CH2) + (2*CH3);

        % We need volumes for each.
        % Use literature values:
        vHead = 319;
        vTail = 782;

        % we use the volumes to calculate the SLD's
        SLDhead = Head / vHead;
        SLDtail = Tails / vTail;

        % We calculate the layer thickness' from
        % the volumes and the APM...
        headThick = vHead / lipidAPM;
        tailThick = vTail / lipidAPM;

        % Manually deal with hydration for layers in
        % this example.
        oxSLD = (oxide_hydration * bulk_out(contrast)) + ((1 - oxide_hydration) * oxide_SLD);
        headSLD = (headHydration * bulk_out(contrast)) + ((1 - headHydration) * SLDhead);
        tailSLD = (bilayerHydration * bulk_out(contrast)) + ((1 - bilayerHydration) * SLDtail);

        % Make the layers
        oxide = [oxide_thick oxSLD sub_rough];
        water = [waterThick bulk_out(contrast) bilayerRough];
        head = [headThick headSLD bilayerRough];
        tail = [tailThick tailSLD bilayerRough];

        output = [oxide ; water ; head ; tail ; tail ; head];
    end

A straight Python translation (into a Python module) is as follows:

.. code:: Python

    # customBilayer.py
    import numpy as np

    def customBilayer(params, bulk_in, bulk_out, contrast):
        params = np.array(params);
        bulk_in = np.array(bulk_in);
        bulk_out = np.array(bulk_out);

        sub_rough = params[0]
        oxide_thick = params[1]
        oxide_hydration = params[2]
        lipidAPM = params[3]
        headHydration = params[4]
        bilayerHydration = params[5]
        bilayerRough = params[6]
        waterThick = params[7]

        # We have a constant SLD for the oxide..
        oxide_SLD = 3.41e-6

        # Now make the lipid layers..
        # Use known lipid volume and compositions
        # to make the layers

        # define all the neutron b's.
        bc = 0.6646e-4     # Carbon
        bo = 0.5843e-4     # Oxygen
        bh = -0.3739e-4    # Hydrogen
        bp = 0.513e-4      # Phosphorus
        bn = 0.936e-4      # Nitrogen
        bd = 0.6671e-4     # Deuterium

        # Now make the lipid groups..
        COO = (4*bo) + (2*bc)
        GLYC = (3*bc) + (5*bh)
        CH3 = (2*bc) + (6*bh)
        PO4 = (1*bp) + (4*bo)
        CH2 = (1*bc) + (2*bh)
        CHOL = (5*bc) + (12*bh) + (1*bn)

        # Group these into heads and tails:
        Head = CHOL + PO4 + GLYC + COO
        Tails = (34*CH2) + (2*CH3)

        # We need volumes for each.
        # Use literature values:
        vHead = 319
        vTail = 782

        # we use the volumes to calculate the SLD's
        SLDhead = Head / vHead
        SLDtail = Tails / vTail

        # We calculate the layer thickness' from
        # the volumes and the APM...
        headThick = vHead / lipidAPM
        tailThick = vTail / lipidAPM

        # Manually deal with hydration for layers in
        # this example.
        oxSLD = (oxide_hydration * bulk_out[contrast]) + ((1 - oxide_hydration) * oxide_SLD)
        headSLD = (headHydration * bulk_out[contrast]) + ((1 - headHydration) * SLDhead)
        tailSLD = (bilayerHydration * bulk_out[contrast]) + ((1 - bilayerHydration) * SLDtail)

        # Make the layers
        oxide = [oxide_thick, oxSLD, sub_rough]
        water = [waterThick, bulk_out[contrast], bilayerRough]
        head = [headThick, headSLD, bilayerRough]
        tail = [tailThick, tailSLD, bilayerRough]

        output = np.array([oxide, water, head, tail, tail, head])

        return output, sub_rough


In order to use this custom model, we need a couple of extra steps. Firstly we need to ensure that the current folder is on the pythonpath. You can do this from the Matlab prompt..

.. code:: MATLAB

    if count(py.sys.path,pwd) == 0
        insert(py.sys.path,int32(0),pwd);
    end


To use this model from RAT, you need to add it to the current project, taking care to specify the language correctly..

.. code:: MATLAB

    problem.addCustomFile('myModel','customBilayer.py','python',pwd);

You can then use this in your calculations in the same way as a normal, Matlab custom model.

.. note::
    Remember if you change your Python module, the changes will not automatically be registered by Python and you will need to reload the module into Python. You can do this using the following Matlab function (call this after any edits to your module)..
.. code:: MATLAB

    function reloadPy(name)

        % Save the module name (so we can reload it after clear..)
        save('tempSave','name');

        % Clear all classes (scoping means that the base workspace is unaffected)
        warning('off','MATLAB:ClassInstanceExists')
        clear classes

        % Reload the name....
        name = load('tempSave');
        name = name.name;

        % Now reload the module....
        mod = py.importlib.import_module(name);
        py.importlib.reload(mod);

        % Get rid of our temporary file...
        delete('tempSave.mat');
    end


C++ Custom Models
=================
If Matlab or Python custom models are too slow, you also have the option of providing a C++ custom model. You then have to compile and build this into a shared library in order to use it with RAT.

Following on from our custom bilayer examples, the equivalent C++ custom model should follow this format..

.. code:: C++

    //customBilayer.cpp

    #include <vector>

    #if defined(_WIN32) || defined(_WIN64)
    #define LIB_EXPORT __declspec(dllexport)
    #else
    #define LIB_EXPORT
    #endif

    // We user extern "C" decorator to avoid name mangling....
    extern "C" {

        LIB_EXPORT void customBilayer(std::vector<double>& params, std::vector<double>& bulkIn, std::vector<double>& bulkOut, int contrast, std::vector<double>& output, double* outputSize, double* rough)
        {
            double subRough = params[0];
            double oxideThick = params[1];
            double oxideHydration = params[2];
            double lipidAPM = params[3];
            double headHydration = params[4];
            double bilayerHydration = params[5];
            double bilayerRough = params[6];
            double waterThick = params[7];

            // We have a constant SLD for the oxide
            double oxideSLD = 3.41e-6;

            // Now make the lipid layers..
            // Use known lipid volume and compositions
            // to make the layers

            // define all the neutron b's.
            double bc = 0.6646e-4;     //Carbon
            double bo = 0.5843e-4;     //Oxygen
            double bh = -0.3739e-4;	   //Hydrogen
            double bp = 0.513e-4;      //Phosphorus
            double bn = 0.936e-4;      //Nitrogen
            double bd = 0.6671e-4;     //Deuterium

            // Now make the lipid groups..
            double COO = (4*bo) + (2*bc);
            double GLYC = (3*bc) + (5*bh);
            double CH3 = (2*bc) + (6*bh);
            double PO4 = (1*bp) + (4*bo);
            double CH2 = (1*bc) + (2*bh);
            double CHOL = (5*bc) + (12*bh) + (1*bn);

            // Group these into heads and tails:
            double Head = CHOL + PO4 + GLYC + COO;
            double Tails = (34*CH2) + (2*CH3);

            // We need volumes for each.
            // Use literature values:
            double vHead = 319;
            double vTail = 782;

            // we use the volumes to calculate the SLD's
            double SLDhead = Head / vHead;
            double SLDtail = Tails / vTail;

            // We calculate the layer thickness' from
            // the volumes and the APM...
            double headThick = vHead / lipidAPM;
            double tailThick = vTail / lipidAPM;

            // Manually deal with hydration for layers in
            // this example.
            double oxSLD = (oxideHydration * bulkOut[contrast]) + ((1 - oxideHydration) * oxideSLD);
            double headSLD = (headHydration * bulkOut[contrast]) + ((1 - headHydration) * SLDhead);
            double tailSLD = (bilayerHydration * bulkOut[contrast]) + ((1 - bilayerHydration) * SLDtail);

            // Make the layers
            // oxide...
            output.push_back(oxideThick);
            output.push_back(oxSLD);
            output.push_back(subRough);

            // Water...
            output.push_back(waterThick);
            output.push_back(bulkOut[contrast]);
            output.push_back(bilayerRough);

            // Heads...
            output.push_back(headThick);
            output.push_back(headSLD);
            output.push_back(bilayerRough);

            // Tails...
            output.push_back(tailThick);
            output.push_back(tailSLD);
            output.push_back(bilayerRough);

            // Tails...
            output.push_back(tailThick);
            output.push_back(tailSLD);
            output.push_back(bilayerRough);

            // Heads...
            output.push_back(headThick);
            output.push_back(headSLD);
            output.push_back(bilayerRough);

            *rough = subRough;

            outputSize[0] = 6;     // row - Necessary to output how many layers in stack
            outputSize[1] = 3;
        }
    } // extern "C"


Before you can use this file, you need to compile and build it into a shared library. The details will vary according to you system, for example...

* Clang on Apple (OSX):
.. code:: Bash

    clang -c customBilayer.cpp -o customBilayer.o -std=c++11 -arch x86_64
    clang -shared customBilayer.o -o customBilayer.dylib -arch x86_64 -lc++

* GCC on Linux:
.. code:: Bash

    g++ -fPIC -c customBilayer.cpp -o customBilayer.o -std=c++11
    g++ -shared customBilayer.o -o customBilayer.so

* Windows (with MSVC):
    cl /EHsc /LD customBilayer.cpp

This will create either customBilayer.dylib (OSX), customBilayer.dll (Windows) or customBilayer.so (Linux).

To use this, we just add the relevant model to out project, in the same way as for Matlab and Python models:

.. code:: MATLAB

    problem.addCustomFile('DSPC Model','customBilayer.dylib','cpp',pwd);

You can then use your C++ custom model in your ptoject as normal.


Performance Comparisons
=======================






