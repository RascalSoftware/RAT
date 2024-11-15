===============
Contrasts Class
===============
Contrast Class is a class to responsible to manipulate contrasts. While adding the contrast, the input(cell array) goes through some checks and if no input is given, the contrast is 
automatically named and counter is incremented. If only name was given, contrast is incremented and the cell array's name is set to current name.

The cell array of contrasts is sent to Contrast Class to get converted to a struct `parseContrastInput` method which gets attached to the class object.

.. code-block:: MATLAB
    :caption: Adding a contrast (D20 Contrast)

        problem.addContrast('name','Bilayer / D2O',...
            'background','Background D2O',...
            'resolution','Resolution 1',...
            'scalefactor', 'Scalefactor 1',...
            'resample',false,....
            'bulkOut', 'SLD D2O',... 
            'bulkIn', 'Silicon',...
            'data', 'Bilayer / D2O');


While setting contrasts to a model, `setContrastModel` method is called. This method is called with a cell array of a { number , cell array }. The number being what contrast 
is and the cell array containing the information about the model. The main purpose of this method is to set the contrast to a model based on specified type of model. Based 
on the type of model, the code checks whether some of the contrast names are allowed or not. If not, it throws an error.


.. code-block:: MATLAB
    :caption: Setting a contrast to a model

        % 1 refers to the contrast number and the rest Layer information
        problem.setContrastModel(1,{'Oxide Layer',...
              'Water Layer',...
              'Bil inner head',...
              'Bil tail',...
              'Bil tail',...
              'Bil outer head'});

***********************
Domains Contrasts Class
***********************
The Domains Contrasts Class is a simplified model only contrasts class for the Domains calculation.

*********
Reference
*********
.. default-domain:: mat
.. autoclass:: API.projectClass.contrastsClass
    :members:

.. autoclass:: API.projectClass.domainContrastsClass
    :members:
