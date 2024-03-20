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
    Before you use Python from your Matlab session, please ensure that Python is `configured correctly on your system <https://uk.mathworks.com/help/matlab/matlab_external/create-object-from-python-class.html>`_
    These steps are necessary, since despite Python marketing itself as an everyday language for the people, it is an fact a general, continuing, versioning ballache that is no good for man nor beast.... but hey,
    people love their Python so go figure??

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

...which is a Python module, subject to the usual constraints of Python modules around correct indentation and so on.
(These constraints are obviously stupid, as they have always been, but hey... Python *shrug* )



C++ Custom Models
=================
tbc




Performance Comparisons
=======================






