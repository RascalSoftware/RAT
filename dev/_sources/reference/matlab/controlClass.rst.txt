==============
Controls Class
==============
ControlsClass is all about control. It is necessary in determining the way RAT works. It deals with how the user interacts with the software. From type of parallelization, 
to whether the users wants to calculate SLD during fit, and even how many iteration an algorithm should do etc.


There are 5 different `controlsClass.procedures` that can be used with RAT. They are:

1. **Simplex** 
2. **Differential Evolution (DE)** - Optimizes a problem by iteratively improving a candidate solution based on an evolutionary process
3. **Nested Sampler (NS)** - Estimates directly how the likelihood function relates to prior mass
4. **DREAM**
5. **Calculate** 

Each of them has their own unique set of options. The fields in class object of controlsClass are 
automatically updated based on the procedure selected.

RAT uses parallelization to speed up the calculation. This is achieved using Parallel Computing Toolbox. The user can choose to use the parallelisation or not and 
if yes, what to parallelize on. (Single, Points or Contrasts)

.. code-block:: MATLAB
    :caption: Sample usage of controlsClass.

        controls = controlsClass();
        controls.procedure = procedures.Dream;
        controls.nSamples = 6000;
        controls.nChains = 10;
        controls.parallel = parallelOptions.Contrasts;

.. code-block:: MATLAB
    :caption: Alternate usage of controlsClass.

        controls = controlsClass();
        controls = controls.setProcedure('dream',...
                                         {'nSamples', 6000,...
                                          'nChains', 10,...
                                          'parallel', 'contrasts'})

*********
Reference
*********
.. default-domain:: mat
.. autoclass:: API.controlsClass
    :members: