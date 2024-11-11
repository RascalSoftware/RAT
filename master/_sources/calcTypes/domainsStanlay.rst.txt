.. _domainsStanlay:

=======================
Standard Layers Domains
=======================

.. note::
    See the */examples/domains/standardLayers/* folder for an example of standard layers with domains.

In order to use domains, we create a project of the correct type....

.. tab-set-code::
    .. code-block:: Matlab

        problem = createProject(calcType='domains');
    
    .. code-block:: Python

        problem = RAT.Project(calculation='domains')

The principle of setting up these calculations relies on firstly grouping the layers into domains, then grouping the defined domains intro contrasts, according to a 'domain ratio' parameter:

.. image:: ../images/domainsGraph.png
    :width: 800

The example (in the examples folder), we define the layers as for conventional Standard Layers projects:

.. tab-set-code::
    .. code-block:: Matlab

        Layer1 = {'Layer 1',...         % Name of the layer
            'L1 thick',...              % Layer thickness
            'L1 SLD',...                % Layer SLD
            'L1 Rough',...              % Layer roughness
            'L1 Hydr',...               % hydration (percent)
            'bulk out' };

        Layer2 = {'Layer 2',...         % Name of the layer
            'L2 thick',...              % Layer thickness
            'L2 SLD',...                % Layer SLD
            'L2 Rough',...              % Layer roughness
            'L2 Hydr',...               % hydration (percent)
            'bulk out' };

        Layer3 = {'Layer 3',...         % Name of the layer
            'L3 thick',...              % Layer thickness
            'L3 SLD',...                % Layer SLD
            'L3 Rough',...              % Layer roughness
            'L3 Hydr',...               % hydration (percent)
            'bulk out' };

        problem.addLayerGroup({Layer1, Layer2, Layer3});

    .. code-block:: Python

        # Now group these parameters into layers
        problem.layers.append(name='Layer 1', thickness='L1 Thickness', SLD='L1 SLD', roughness='L1 Roughness',
                            hydration='L1 Hydration', hydrate_with='bulk out')

        problem.layers.append(name='Layer 2', thickness='L2 Thickness', SLD='L2 SLD', roughness='L2 Roughness',
                            hydration='L2 Hydration', hydrate_with='bulk out')

        problem.layers.append(name='Layer 3', thickness='L3 Thickness', SLD='L3 SLD', roughness='L3 Roughness',
                              hydration='L3 Hydration', hydrate_with='bulk out')

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem = load('source/calcTypes/data/domains_example.mat');
            problem = problem.problem;
            problem.layers.displayTable()

    .. tab-item:: Python 
        :sync: Python

        .. output:: Python
            
            # replace with a better project reading method when we have one...
            with open('source/calcTypes/data/domains_example.py', "r") as f:
                script = f.read()
            locals = {}
            exec(script, None, locals)
            problem = locals['problem']
            print(problem.layers)


From this point, the model diverges from the usual Standard Layers case, in that these are grouped into 'domain contrasts', which appears in an additional table in the
printout of the project class. Domains contrasts consist of only layers, with no bulk phases etc..

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem.contrasts.displayContrastsObject()

    .. tab-item:: Python
        :sync: Python

        .. output:: Python

            print(problem.contrasts)


It is then these that are grouped into the final contrasts model. For each contrast, there must be two (*and only two*) domain contrasts. In addition, each contrast requires a
Domain Ratio parameter. This is a fittable parameter between 0 and 1, that appears in the Domain Ratio table:

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem.domainRatio.displayTable()

    .. tab-item:: Python
        :sync: Python

        .. output:: Python

            print(problem.domain_ratios)


leading to the final contrast structure of two domains, and one domain ratio:

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem.domainContrasts.displayContrastsObject()

    .. tab-item:: Python
        :sync: Python

        .. output:: Python

            print(problem.domain_contrasts)


.. note:: For domain ratio, a ratio of 0 means 100% Domain 1, whilst conversely a ratio of 1 means 100% Domain 2.
