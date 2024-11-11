.. _table: https://uk.mathworks.com/help/matlab/tables.html

.. _backgroundsClass:

=================
Backgrounds Class
=================

This class makes the backgrounds in RAT. Backgrounds are defined in a two stage process. Firstly we define the actual fitted parameters. 
These are held in a 'ParametersClass' table. Then, we group these into the backgrounds themselves using a multiTypeTable(`table`_). So, we can then use the 
background parameters to either define background as constant, data or a function.

.. list-table:: The methods on the left call the methods on the right in the table.
    :widths: 50 50
    :header-rows: 1

    * - Method in Project Class
      - Method in backgroundsClass 
    * - projectClass.addBackgroundParam()
      - backgroundsClass.backgroundParams.addParameter() 
    * - projectClass.removeBackgroundParam()
      - backgroundsClass.backgroundParams.removeParameter()
    * - projectClass.setBackgroundParamValue()
      - backgroundsClass.backgroundParams.setValue()
    * - projectClass.addBackground()
      - backgroundsClass.addBackground()
    * - projectClass.removeBackground()
      - backgroundsClass.removeBackground()

.. note::
 1. For constant, only one parameter is supplied to multi type table. 
 2. For data, only the data itself is supplied as a cell. 
 3. For function, the function name is supplied, along with up to three parameters (from the parameters table) which are then supplied to the function to
    calculate the background. 
    
In each case, the background can either be added to the simulation or subtracted from the data.

.. code-block:: MATLAB
    :caption: Example showing how backgroundsClass methods are called.

        % Change the name of the existing parameters to refer to D2O
        problem.setBacksPar(1,'name','Backs par D2O','fit',true,'min',1e-8,'max',1e-5);

        % Add a new constant background
        problem.addBackground('Background SMW','constant','Backs par SMW');

*********
Reference
*********
.. default-domain:: mat
.. autoclass:: API.projectClass.backgroundsClass
    :members: