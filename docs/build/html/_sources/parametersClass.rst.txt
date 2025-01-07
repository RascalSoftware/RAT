.. _table: https://uk.mathworks.com/help/matlab/tables.html

================
Parameters Class
================

Parameters Class helps to add, set or remove parameters to the Project Class. The class has a constructor that gets initiated when Parameter class is called. This constructor 
sets important initial values to the class obj (object) like variable name, types. It also initiates a "table" that helps to store all the parameters. Table is a really useful 
data type provided by matlab. Check this link to know more about `table`_.

.. list-table:: The methods on the left call the methods on the right in the table.
    :widths: 25 25
    :header-rows: 1

    * - Method in Project Class
      - Method in Parameters Class 
    * - projectClass.addParameterGroup()
      - parametersClass.addParameter() 
    * - projectClass.addParameter()
      - parametersClass.addParameter()
    * - projectClass.removeParameter()
      - parametersClass.removeParameter()
    * - projectClass.setParameter()
      - parametersClass.setParameter()
    * - projectClass.setParameter()
      - parametersClass.setValue()
    
      
When adding parameters, they can be added individually or as a group (see below). When added as a group, `addParameterGroup` method in projectClass iterates over the 
list of parameters and adds them one by one using `addParameter` method which is used to add individual parameters.

.. code-block:: MATLAB 
    :caption: Adding parameters as a group. Can set to a class using projectClass.addParameterGroup(Parameters)

        Parameters = {
        %   Name                min         val         max     fit? 
        {'Oxide thick',         5,         20,         60,     true   };
        {'Oxide SLD',           3e-6,       3.41e-6,    4e-6,   false  };
        {'Oxide Hydration'      0,          20,         30,     true   }};


.. code-block:: MATLAB 
    :caption: Adding parameters individually. Can set to a class using projectClass.addParameter(Parameter)

        Oxide =     {'Oxide Layer',...          % Name of the layer
                    'Oxide thick',...           % Layer thickness
                    'Oxide SLD',...             % Layer SLD
                    'Substrate Roughness',...   % Layer roughness
                    'Oxide Hydration',...       % Oxide hydration (percent)
                    'bulk out' };               % Which bulk phase is hydrating the layer
            
    % Add this to the projectClass...
    projectClass.addLayer(Oxide);

When *addParameter* method is called, the method checks the input through a series of checks to find out
if there are any unexpected values at unexpected places. For example, having logical value in place of a numerical value argument. With *setParameter* method, 
one can set the value of any parameter independently. However, there are other methods that helps setting individual parameters. For example, *setName* method helps
to set the name of a parameter.

.. note::
    
    1. You can add Bulk in and Bulk out with this class 
    2. You can add scale factor with this class

Reference
---------
.. autoclass:: API.projectClass.parametersClass
    :members: