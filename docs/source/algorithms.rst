.. _algorithms:

==========
Algorithms
==========

RAT has 4 built-in algorithms for data fitting and analysis. The Nelder-Mead Simplex and Differential Evolution 
are traditional minimisers, whereas the other two (DREAM and Nested Sampling) are Bayes samplers. The use
of an external library (`Paramonte`_.) for Bayesian sampling is also supported.


.. toctree::
   :maxdepth: 2

   simplex
   DE
   DREAM
   nestedSampling
   paramonte

.. _Paramonte: https://www.cdslab.org/paramonte/