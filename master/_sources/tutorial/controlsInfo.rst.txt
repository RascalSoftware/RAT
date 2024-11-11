.. _controlsInfo:

===================================
A Closer Look at the Controls Class
===================================

We have already seen in previous sections that once the problem has been defined in the projectClass, it is necessary to define a controls
class which, as its name suggests, tells RAT what we want to do with the project.

Making an instance of the controls class is quite simple:-

.. tab-set-code::
    .. code-block:: Matlab
        
        controls = controlsClass();

    .. code-block:: Python
        
        controls = RAT.Controls()


This then creates an instance of controls class with a number of options defined:

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            controls = controlsClass();
            disp(controls)

    .. tab-item:: Python
        :sync: Python

        .. output:: Python

            controls = RAT.Controls()
            print(controls)

We will look at each of these in more detail below. Note that the options that are visible depend on
the algorithm selected. So, at the moment the controls are set to 'calculate', which will simply calculate the reflectivity and 
SLD with any associated problem. If we select 'simplex' as the algorithm, a different set of options appears:-

.. tab-set-code::
    .. code-block:: Matlab
        
        controls.procedure = 'simplex';

    .. code-block:: Python
        
        controls = RAT.Controls(procedure='simplex')


.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            controls = controlsClass();
            controls.procedure = 'simplex';
            disp(controls)

    .. tab-item:: Python
        :sync: Python

        .. output:: Python

            controls = RAT.Controls(procedure='simplex')
            print(controls)

which allow the user to set things such as tolerance targets and so on. There is a different set of options for each algorithm.
We will now look at each of the available options in turn.

******************************
Methods for the controls class
******************************

Parallel
========
TODO

Procedure
=========
TODO

calcSldDuringFit
================
TODO

display
=======
TODO

resamPars
=========
TODO
