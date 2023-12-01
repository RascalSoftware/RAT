============
Layers Class
============
Layers can be added as a group or individually. When added as a group, `addLayerGroup` method in projectClass iterates over the list of layers and
adds them one by one using `addLayer` method which is used to add individual layers.

.. list-table:: The methods on the left call the methods on the right in the table.
    :widths: 25 25
    :header-rows: 1

    * - Method in Project Class
      - Method in Layers Class 
    * - projectClass.addLayerGroup()
      - layersClass_realSLD.addLayer() 
    * - projectClass.addLayer()
      - layersClass_realSLD.addLayer()
    * - projectClass.setLayerValue()
      - layersClass_realSLD.setLayerValue()


.. code-block:: MATLAB
    :caption: Adding layers as a group. Can set to a class using projectClass.addLayerGroup(Layers)

        projectClass.addLayerGroup({waterLayer ; bilInnerHead ; bilTails ; bilOuterHead})


.. code-block:: MATLAB
    :caption: Adding layers individually. Can set to a class using projectClass.addLayer(Layer)

        waterLayer = {
            'Water Layer',...           % Layer name
            'Water thick',...
            'Water SLD',...
            'Bilayer heads rough',...    % Outer interface of the water layer is a bilayer headgroup
            'Water hydr',...
            'Bulk out'
        };

        projectClass.addLayer(waterLayer);

Reference
---------
.. autoclass:: API.projectClass.layersClass
    :members: