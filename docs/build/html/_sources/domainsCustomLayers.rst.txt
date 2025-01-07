.. _domainsCustomLayers:


Custom Models with Domains
..........................

For custom layers models with domains, in the spirit of RAT custom models, all the work regarding domain construction is left to the user from within the custom model.
In the custom model itself, there is an extra input parameter for the custom model:

.. code-block:: MATLAB

    function [output,subRough] = myCustomModel(params,bulkIN,bulkOut,contrast,domainNumber)


The first four parameters are the same as for a normal custom model. The final *'domainNumber'* parameter is an integer with a value which is either 1 or 2. Then, it is up
to the user to build the correct domain. So for example, within the custom model:

.. code-block:: MATLAB

    switch(domainNumber)
        case 1
            % <Build structure for domain 1>
        otherwise
            % <Build structure for domain 2>
    end

