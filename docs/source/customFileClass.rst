.. _table: https://uk.mathworks.com/help/matlab/tables.html

=================
Custom File Class
=================

RAT enables users to define their own custom files. They can be linked to RAT through Custom File class. Like other classes, the inputs are checked for
the right order and type. Also, it uses `table`_ data type to store the custom files. Custom files can be added or removed using the methods this class provides. 

The custom file table has the following columns:

1. Name of the row in the Custom File table
2. Name of the custom file
3. Language of the custom file
4. Path of the custom file

If all of the 4 columns are supplied, a new row (cell array of strings) is made using the supplied inputs. Then, `addCustomFile` method is used to append the row to the object.
This method takes care of the error checking and incrementing the count of the custom files. It also makes a table of the row supplied. This table helps with displaying it 
properly on terminal.

.. code-block:: MATLAB
    :caption: Adding MATLAB custom file.

        %                       Row Name   Custom File Name  Language   Path
        problem.addCustomFile('DSPC Model','customBilayer.m','matlab','pwd');

.. code-block:: MATLAB
    :caption: Adding C++ custom file.

            % For C++, function name of the cpp file is supplied
            %                       Row Name        DLL/function Name  Language   Path
            problem.addCustomFile('DSPC CPP Model','customBilayer','c++','pwd');


.. warning::
    RAT only supports C++, MATLAB, and Python.



Reference
---------
.. autoclass:: API.projectClass.customFileClass
    :members: