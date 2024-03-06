|RAT banner|

.. _RAT: 


RAT is an acronym for Reflectivity Algorithms Toolbox, which is the calculation engine for the forthcoming RasCAL2. As
with the original RasCAL, RAT is a toolbox for analysising neutron reflectivity data at multiple contrasts. It is designed
to be flexible, allowing analysis using traditional layer models, but also using user defined custom models. These models
do not assume any prerequisite, but instead allow complete freedom to the user to specify and parameterise their model
however they wish, either as an array of layers, or as a continuous SLD profile.
The original RasCAL was written in Matlab, and RAT is too. However RAT is then converted to native C++ using Matlab Coder .
This has the advantage of the ease of use of Matlab for development, combined with the power and speed of C++. In addition,
because the engine is in C++ it can be called from other languages other than just Matlab. There is a Python interface under development
(although not yet functional).

The Matlab Interface described in this documentation means that for the first time RasCAL projects are fully scriptable,
meaning that full analyses can be provided via a script for publications for example, or analyses using RAT incorporated
into jupyter notebooks and so on.

RAT contains a number of enhancements as compared to legacy rascal, including:

*   Automatic paralellisation (MPI) either over contrasts or points using a simple flag
*   Advanced interface microslicing using adaptive resampling
*   Option to write custom models in Matlab, Python or C++
*   Custom models for background and resolution functions (not yet functional)
*   Fast Bayesian analysis using DREAM or the external Paramonte Sampler
*   Parallel Bayes using Paramonte via 'mpiexcec'
*   An integrated Nested sampler for Bayesian model selection
*   Fully validated against ORSO examples
*   Ability to load and run RasCAL1 projects (usually) without modification
*   Plotting routines for easy visualisation of data and fits

…. and more!

As well as this documentation, there are extensive examples in the RAT/examples folder.


Index
#####

.. toctree::
   :maxdepth: 2
   
   install
   tutorial
   algorithms
   advanced
   calcTypes
   utilities
   reference
   support


Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
