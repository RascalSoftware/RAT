.. _Parallelisation:

Parallelising Calculations
...................................

RAT has in-built parallelisation for speeding up calculations. It will either parallelise over points and this is easily selectable from the controls class. In addition, it is possible to use the external Paramonte sampler
to run Bayesian analysis in parallell using 'mpiexcec'

Internal Parallelisation
========================
The controls class allows selection of parallel calculations for all algorithms. The parallelisation can be either over 'contrasts' or 'points'...

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


Generally speaking, unless you have an inordinate amount of points in your datafiles, the greatest speed increase always results from parallelising over contrasts. In fact, if the number of points in your data
is relatively small, parallelising over points can even slow things down because of the extra calculation overhead! It's a good idea to verify which is fastest for a give problem at the start of an analysis.

Parallel Bayes with MIPEXCEC and Paramonte
==========================================



