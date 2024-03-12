.. _Parallelisation:

Parallelising Calculations with MPI
...................................

RAT has in-built parallelisation for speeding up calculations. It will either parallelise over points or contrasts as follows....

* **points** - In this case, each reflectivity curve is split into a number of sections, and the reflectivity for each set of points is calculated by an individual thread. Only the reflectivity calculation itself is parallelised, and the rest runs sequentially on a single thread.
* **contrasts** - Each contrast *in its entirety* gets it's own calculation thread.

The parallelisation scheme is chosen from the controls class:

.. code:: MATLAB

    controls = controlsClass()

    % Choose no parallelisation..
    controls.parallel = 'single';

    % Parallelise over points...
    controls.parallel = 'points'

    % Parallelise over contrasts...
    controls.parallel = 'contrasts'


Generally speaking, unless you have an inordinate amount of points in your datafiles, the greatest speed increase always results from parallelising over contrasts.

