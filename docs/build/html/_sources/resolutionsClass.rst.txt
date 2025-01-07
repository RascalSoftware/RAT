.. _table: https://uk.mathworks.com/help/matlab/tables.html

=================
Resolutions Class
=================

Resolutions are defined in a two stage process. Firstly, actual fitted parameters are defined. These are held in a 'Parameter Class' table (referring to data type).
Then, these are grouped into the resolutions themselves using a multi-type table. Then the resolution parameters can be used to either define resolution as 
constant, data, or a function. 

The constructor is called with the parameters and resolutions as input. The parameters are stored in the resolPars table whereas the resolutions are stored in 
the resolutions table and the allowed types are defined in the allowedTypes variable.

.. note::

    1. For constant only one parameter is supplied to multi-type table. 
    2. For data, the name is supplied, along with name of the data in the data table. 
    3. For function, the function name is supplied, along with up to three parameters (from the parameters table) which are then supplied to the function to calculate the resolution. 

In each case, the Resolutions can either be added to or subtracted from the data.


Reference
---------
.. autoclass:: API.projectClass.resolutionsClass
    :members:
