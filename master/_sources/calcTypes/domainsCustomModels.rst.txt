.. _domainsCustomModels:

==========================
Custom Models with Domains
==========================

For custom models with domains, in the spirit of RAT custom models, all the work regarding domain construction is left to the user from within the custom model.
In the custom model itself, there is an extra input parameter for the custom model:

.. tab-set-code::
    .. code-block:: Matlab

        function [output,subRough] = myCustomModel(params,bulkIN,bulkOut,contrast,domainNumber)

    .. code-block:: Python

        def myCustomModel(params, bulk_in, bulk_out, contrast, domain_number):
            # Do stuff

            return output, sub_rough


The first four parameters are the same as for a normal custom model. The final *'domainNumber'* parameter is an integer with a value which is either 1 or 2. Then, it is up
to the user to build the correct domain. So for example, within the custom model:

.. tab-set-code::
    .. code-block:: Matlab

        switch(domainNumber)
            case 1
                % <Build structure for domain 1>
            otherwise
                % <Build structure for domain 2>
        end

    .. code-block:: Python

        
        if domain_number == 0:
            # Build structure for domain 1
        else:
            # Build structure for domain 2
