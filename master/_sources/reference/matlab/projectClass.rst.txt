=============
Project Class
=============
Project Class is all about data. It contains the very data user wants to work with. It stores all the data required for reflectivity calculations. 
Everything in RAT comes from projectClass in one way or another. There are many functions that deal with breaking down the data from Project Class into smaller pieces 
so that they can be used in other parts of the software.


Project Class has lot of other classes that help create objects for inputs. They are : 

.. toctree::
    :maxdepth: 1

    parametersClass
    resolutionsClass
    backgroundsClass
    dataClass
    layersClass
    customFileClass
    contrastsClass


.. note::
    Most of these classes have the following in common:

    1. They are all called from Project Class.
    2. Methods to add or remove or change an attribute depending on the class.
    3. Methods to find the location based on input value. Finding row when given an attribute's name or vice versa (Not all of them though).
    4. Display methods.
    5. A 'toStruct' method which output the class parameters as a struct.


.. list-table:: The methods on the left call the methods on the right in the table.
    :widths: 50 50
    :header-rows: 1

    * - Method in Project Class
      - Method in Parameter Class 
    * - projectClass.addBulkIn/addBulkOut()
      - parametersClass.addParameter() 
    * - projectClass.removeBulkIn/removeBulkOut()
      - parametersClass.removeParameter()
    * - projectClass.setBulkIn/setBulkOut()
      - parametersClass.setParameter()

Although, Project class provides one level higher interface so that one can use `addBulkIn` and `addBulkOut` methods from projectClass to set these parameters.

.. code-block:: MATLAB
    :caption: Adding Bulk Out. Can set to a class using projectClass.addBulkOut(BulkIn)

        %                   Name       min     val   max  fit?
        problem.addBulkOut({'SLD SMW',2e-6,2.073e-6,3e-6,true});

*************
Domains Class
*************
RAT currently supports two calculation types (nonPolarised and Domains). The Domains Class is a project class with extra parameters (domainRatio, domainContrasts) for the Domains calculation.

.. note::
    It is recommended to use `API.createProject` instead of creating a Project or Domains object directly.

*********
Reference
*********
.. default-domain:: mat
.. autofunction:: API.createProject

.. autoclass:: API.projectClass.projectClass
    :members:

.. autoclass:: API.projectClass.domainsClass
    :members:
