.. _chapter2:

==================================
The Problem Definition Input Class
==================================
In the previous section, we saw an example of how we set up and run an analysis using the RAT toolbox. Every call to the toolbox has two parts: the **problem definition** class, where we define the model, add the data and define our contrasts, and the **controls class** where we
tell the toolbox what type of analysis we would like to do. The reason for splitting things up in this way is that once our model is defined, we can interact with it in various ways without needing to modify the model. So, we can experiment with our data, trying out different types of analysis, and explore the
landscape of solutions by simply modifying the *controls* class, leaving the *problem* class alone.

As well as having two inputs, RAT always provides two outputs, so the call to the toolbox is always of this form:-

.. tab-set-code::
    .. code-block:: Matlab

        [problem, results] = RAT(problem, controls)
    
    .. code-block:: Python

        problem, results = RAT.run(problem, controls)


In this case we have called our inputs *problem* and *controls*, but they can be called anything. Likewise, we have called our outputs *problem* and *results*, but we are free to call them anything we like. We will look at the outputs in more detail in the next section.

The first input, *problem*, is an instance of a class called project class:

.. tab-set-code::
    .. code-block:: Matlab

        >> problem = createProject(name='my project');
        >> class(problem)

        ans =
            'projectClass'
    
    .. code-block:: Python
        :force:

        >>> problem = RAT.Project(name='my project')
        >>> type(problem)

        <class 'RAT.project.Project'>

And if we take a look at it, we can see the class contains a series of sections, where we can define our parameters, make different kinds of model, load in our data and do everything we need to set up our model.

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem = createProject(name='my project');
            disp(problem)

    .. tab-item:: Python 
        :sync: Python
        
        .. output:: Python

            problem = RAT.Project(name='my project')
            print(problem)

We can see that the class has a number of attributes, defining all we need for our analysis. In the default case, we have no parameters or data, and have not defined any contrasts, so this will not do anything useful in RAT. 
Defining a model is a case of populating the sections in the project class, which we do using the methods in the **project Class**,:

In the following sections, we will look at each of these methods and see how they can be used to define our reflectivity analysis problem. (There is also a utility which will convert a RasCAL model into a *projectClass* for use in RAT.
This means that you can use the RasCAL GUI to set up your model if you like and then use the speed of RAT to conduct your analysis.)

In terms of the outputs, note that we have called the first output *problem*, but we don't need to do that. The first of the two outputs is another **project Class**, but updated with the results of the calculation.
So, if we run a fit, the fitted parameters will be updated with the best fit values of our procedure. In giving the output the same name as the input, we're overwriting our input with best fit values, but if you don't
want to do this, you can give the inputs and outputs different names TODO(e.g. '[outProblem,results] = RAT(problem,controls)'' or whatever you like). The second output can also be called whatever you like, and this is a struct
containing the simulated reflectivities, SLD's and so on from whatever procedure you have asked RAT to do:

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            controls = controlsClass;
            controls.display = 'off';
            [~, ~, results] = evalc('RAT(problem, controls);');
            disp(results)

    .. tab-item:: Python 
        :sync: Python

        .. output:: Python

            controls = RAT.Controls(display='off')
            p, results = RAT.run(problem, controls)
            print(results)

In the next sections, we will discuss the methods of the project class, and see how they allow us to build up a model by populating the various sections.

*******************************
The Components of Project Class
*******************************

Project Defining Methods
========================

The first step is always to create an instance of the project class to hold our model. This is always done by assigning **project Class** to our variable name (we will mostly use *problem* in this manual, but it can be anything), which always requires a name for our project as an input:

.. tab-set-code::
    .. code-block:: Matlab

        problem = createProject(name='My Problem');
    
    .. code-block:: Python
    
        problem = RAT.Project('my project')
    
This creates an instance of **project Class** and assigns it to the variable *problem*, and gives it the title 'My Problem'.

The first part of the created *problem* has two other settable fields: *modelType* and *Geometry*.

**Geometry -** This can be set to either *air/substrate* or *substrate/liquid* as below. 

.. tab-set-code::
    .. code-block:: Matlab

        problem.setGeometry('air/substrate');
        problem.setGeometry('substrate/liquid');
    
    .. code-block:: Python

        problem.geometry = 'air/substrate'
        problem.geometry = 'substrate/liquid'

The effect of this parameter is in the numbering of roughness's in layer models. In any model for n-layers,
there are always n+1 associated interfaces, and hence n+1 roughness parameters required. In RAT, the bulk interface roughness
is a protected parameter and always exists, and this parameter controls where this roughness is placed in the layer stack. So, for two layers defined with thickness,
SLD and roughness as [d\ :sub:`1`, :math:`\rho_\mathrm{1}`, r\ :sub:`1`] and [d\ :sub:`2`, :math:`\rho_\mathrm{2}`, r\ :sub:`2`], then for the *substrate/liquid* geometry
the substrate roughness is placed as the first roughness the beam meets, and the layer roughness's refer to the interface after the particular layer.
But in the *air/substrate* case, the opposite is true, and the substrate roughness is the last roughness in the stack, with the layer roughness referring to the interface before each layer.

ModelType - As is the case for RasCAL, there are three ways of defining models in RAT:-

* **Standard Layers** - The model is defined in terms of parameters, which are distributed into layers, and subsequently grouped into contrasts. No external functions are needed.
* **Custom Layers** - Parameters are again defined and grouped into layers, but this time the layer definitions come from a user model script. This then gives complete flexibility of how layers are defined, so allowing models to be written in terms of area per molecule or material density, for example. This custom script controls translating these input parameters into a [d, :math:`\rho`, r] model. This is probably the most useful operating mode for RasCAL.
* **Custom XY-Profile** - This modelling mode also relies on a custom model function, but in this case does away with [d, :math:`\rho`, r] layers completely. Instead, the custom function uses the parameters to define a continuous SLD profile, which RAT then uses to calculate the reflectivity.

The model type of the project can be changed as follows:

.. tab-set-code::
    .. code-block:: Matlab

        problem.setModelType('standard layers');
        problem.setModelType('custom layers');
        problem.setModelType('custom XY');
    
    .. code-block:: Python

        problem.model = 'standard layers'
        problem.model = 'custom layers'
        problem.model = 'custom XY'

Custom modelling is described in more depth in a :ref:`later section<customModels>`.

The Parameters Block
====================

Any model, whether it be layers or anything else is always defined by parameters. These appear in the parameters block and are specified by a name, a value, minimum and maximum ranges and a flag defining whether the parameter is fitted or fixed:


.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem = createProject(name='My Problem');
            problem.parameters.displayTable()

    .. tab-item:: Python 
        :sync: Python
        
        .. output:: Python

            problem = RAT.Project(name='my project')
            print(problem.parameters)

The substrate roughness is a protected parameter in all cases (it defines the Fresnel roughness) and cannot be renamed or deleted. Its values can be set to any numerical values however.

To add a parameter, you can just specify a name, in which case the parameter takes on default values, or specify the whole parameter at once:

.. tab-set-code::
    .. code-block:: Matlab

        problem.addParameter('My new param', 1, 2, 3);
        problem.addParameter('My other new param',10,20,30,false);

    .. code-block:: Python

        problem.parameters.append(name='My new param', min=1, value=2, max=3)
        problem.parameters.append(name='My other new param', min=10, value=20, max=30, fit=False)

To avoid having to make a whole load of statements for large projects with many parameters, you can define them at once in an array, and add them as a group: 

.. tab-set-code::
    .. code-block:: Matlab

        pGroup = {{'Layer thick', 10, 20, 30, true};
                {'Layer SLD', 1e-6, 3e-6 5e-6, true};
                {'Layer rough', 5, 7, 10, true}};
            
        problem.addParameterGroup(pGroup)
    
    .. code-block:: Python
        
        pGroup = [RAT.models.Parameter(name='Layer thick', min=10, value=20, max=30, fit=True),
                  RAT.models.Parameter(name='Layer SLD', min=1e-6, value=3e-6, max=5e-6, fit=True),
                  RAT.models.Parameter(name='Layer rough', min=5, value=7, max=10, fit=True)] 
 
        problem.parameters.extend(pGroup)

The resulting parameters block looks like this:

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem.addParameter('My new param', 1, 2, 3);
            problem.addParameter('My other new param',10,20,30,false);
            pGroup = {{'Layer thick', 10, 20, 30, true};
                    {'Layer SLD', 1e-6, 3e-6 5e-6, true};
                    {'Layer rough', 5, 7, 10, true}};
                
            problem.addParameterGroup(pGroup);
            problem.parameters.displayTable()

    .. tab-item:: Python 
        :sync: Python
        
        .. output:: Python

            problem.parameters.append(name='My new param', min=1, value=2, max=3)
            problem.parameters.append(name='My other new param', min=10, value=20, max=30, fit=False)
            pGroup = [RAT.models.Parameter(name='Layer thick', min=10, value=20, max=30, fit=True),
                    RAT.models.Parameter(name='Layer SLD', min=1e-6, value=3e-6, max=5e-6, fit=True),
                    RAT.models.Parameter(name='Layer rough', min=5, value=7, max=10, fit=True)] 
    
            problem.parameters.extend(pGroup)
            print(problem.parameters)

.. note::
    Parameters can't have duplicate names. Attempting to duplicate a name will throw an error. This can cause problems when loading in RasCAL1 projects
    where duplicate names are allowed.

To subsequently change the values of the parameters (including names), there are a few methods you can use. For each of the methods, you can refer to the parameter by its index number. In Matlab, you can refer to a parameter by name:

.. tab-set-code::
    .. code-block:: Matlab

        problem.setParameterName('My new param', 'My changed param');
        problem.setParameterLimits(2, 0.96, 3.62);
        problem.setParameterValue(4, 20.22);
        problem.setParameterFit('Layer rough', false);
    
    .. code-block:: Python

        problem.parameters[1].name = 'My changed param'
        problem.parameters[1].min = 0.96
        problem.parameters[1].max = 3.62
        problem.parameters[3].value = 20.22
        problem.parameters[5].fit = False

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem.setParameterName('My new param', 'My changed param');
            problem.setParameterLimits(2, 0.96, 3.62);
            problem.setParameterValue(4, 20.22);
            problem.setParameterFit('Layer rough', false);
            problem.parameters.displayTable()

    .. tab-item:: Python 
        :sync: Python
        
        .. output:: Python

            problem.parameters[1].name = 'My changed param'
            problem.parameters[1].min = 0.96
            problem.parameters[1].max = 3.62
            problem.parameters[3].value = 20.22
            problem.parameters[5].fit = False
            print(problem.parameters)

Alternatively, you can set a number of properties of a given parameter at once using name/value pairs.

.. tab-set-code::
    .. code-block:: Matlab

        problem.setParameter(4, 'name', 'thick', 'min', 5, 'max', 33, 'fit', false)
    
    .. code-block:: Python

        problem.parameters.set_fields(3, name='thick', min=15, max=33, fit=False)

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem.setParameter(4, 'name', 'thick', 'min', 5, 'max', 33, 'fit', false);
            problem.parameters.displayTable()

    .. tab-item:: Python 
        :sync: Python
        
        .. output:: Python

            problem.parameters.set_fields(3, name='thick', min=15, max=33, fit=False)
            print(problem.parameters)

You can remove a parameter from the block using its index number or name (Matlab only). Note that if you remove a parameter from the middle of the block, subsequent parameter index numbers will change. 
Also, if you try to remove the substrate roughness you will get an error:

.. tab-set-code::
    .. code-block:: Matlab

        problem.removeParameter(4);
    
    .. code-block:: Python

        del problem.parameters[3]


.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem.removeParameter(4);
            problem.parameters.displayTable()

    .. tab-item:: Python 
        :sync: Python
        
        .. output:: Python

            del problem.parameters[3]
            print(problem.parameters)

.. tab-set-code::
    .. code-block:: Matlab

        problem.removeParameter(1);
    
    .. code-block:: Python

        del problem.parameters[0]


.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            try
                problem.removeParameter(1);
            catch ERROR
                disp(getReport(ERROR))
            end

    .. tab-item:: Python 
        :sync: Python
        
        .. output:: Python

            try:
                del problem.parameters[0]
            except Exception as err:
                print(err)


The Layers Block (Standard Layers models only)
==============================================

For each of the custom models cases, the model building is done using a script (discussed in :ref:`customModels`). For standard layers models however, model building is done by grouping the parameters into layers, and then into contrasts (as is the case for RasCAL). The layers block is not visible when either of the two custom modes is selected. Again, layers are built using methods of the project class. As an example here, we make a new project class, add some parameters, and create some layers.

For this example, we will make two layers representing a deuterated and hydrogenated version of the same layer. So, the layers will share all their parameters except for the SLD.

Start by making a new project, and adding the parameters we will need:

.. tab-set-code::
    .. code-block:: Matlab

        problem = createProject(name='Layers Example');
    
        params = {{'Layer Thickness', 10, 20, 30, false};
                {'H SLD', -6e-6, -4e-6, -1e-6, false};
                {'D SLD', 5e-6, 7e-6, 9e-6, true};
                {'Layer rough', 3, 5, 7, true};
                {'Layer hydr', 0, 10, 20, true}};
            
        problem.addParameterGroup(params);
    
    .. code-block:: Python

        problem = RAT.Project(name='Layers Example')
        
        params = [RAT.models.Parameter(name='Layer Thickness', min=10, value=20, max=30, fit=False),
                  RAT.models.Parameter(name='H SLD', min=-6e-6, value=-4e-6, max=-1e-6, fit=False),
                  RAT.models.Parameter(name='D SLD', min=5e-6, value=7e-6, max=9e-6, fit=True),
                  RAT.models.Parameter(name='Layer rough', min=3, value=5, max=7, fit=True),
                  RAT.models.Parameter(name='Layer hydr', min=0, value=10, max=20, fit=True)] 
 
        problem.parameters.extend(params)

A layer is defined in terms of a name, thickness, SLD, roughness and (optional) hydration, along with details of which bulk phase is hydrating the layer. The easiest way to define these is to group the parameters into cell arrays, and then add them to the project as a layers group:

.. tab-set-code::
    .. code-block:: Matlab

        % Make the layers
        H_layer = {'H Layer','Layer Thickness','H SLD','Layer rough','Layer hydr','bulk out'};
        D_layer = {'D Layer','Layer Thickness','D SLD','Layer rough','Layer hydr','bulk out'};
        
        % Add them to the project - as a cell array{}
        problem.addLayerGroup({H_layer, D_layer});
    
    .. code-block:: Python

        problem.layers.append(name='H Layer', thickness='Layer Thickness', SLD='H SLD',
                              roughness='Layer rough', hydration='Layer hydr', hydrate_with='bulk out')
        problem.layers.append(name='D Layer', thickness='Layer Thickness', SLD='D SLD',
                              roughness='Layer rough', hydration='Layer hydr', hydrate_with='bulk out')


Our two layers now appear in the Layers block of the project:

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab 
        :sync: Matlab

        .. output:: Matlab

            problem = createProject(name='Layers Example');
        
            params = {{'Layer Thickness', 10, 20, 30, false};
                    {'H SLD', -6e-6, -4e-6, -1e-6, false};
                    {'D SLD', 5e-6, 7e-6, 9e-6, true};
                    {'Layer rough', 3, 5, 7, true};
                    {'Layer hydr', 0, 10, 20, true}};
                
            problem.addParameterGroup(params);

            % Make the layers
            H_layer = {'H Layer','Layer Thickness','H SLD','Layer rough','Layer hydr','bulk out'};
            D_layer = {'D Layer','Layer Thickness','D SLD','Layer rough','Layer hydr','bulk out'};
            
            % Add them to the project - as a cell array{}
            problem.addLayerGroup({H_layer, D_layer});

            problem.layers.displayTable()

    .. tab-item:: Python 
        :sync: Python

        .. output:: Python

            problem = RAT.Project(name='Layers Example')
            params = [RAT.models.Parameter(name='Layer Thickness', min=10, value=20, max=30, fit=False),
                    RAT.models.Parameter(name='H SLD', min=-6e-6, value=-4e-6, max=-1e-6, fit=False),
                    RAT.models.Parameter(name='D SLD', min=5e-6, value=7e-6, max=9e-6, fit=True),
                    RAT.models.Parameter(name='Layer rough', min=3, value=5, max=7, fit=True),
                    RAT.models.Parameter(name='Layer hydr', min=0, value=10, max=20, fit=True)]
            problem.parameters.extend(params)

            problem.layers.append(name='H Layer', thickness='Layer Thickness', SLD='H SLD',
                                roughness='Layer rough', hydration='Layer hydr', hydrate_with='bulk out')
            problem.layers.append(name='D Layer', thickness='Layer Thickness', SLD='D SLD',
                                roughness='Layer rough', hydration='Layer hydr', hydrate_with='bulk out')

            print(problem.layers)

Note that in RAT, hydration is percent hydration between 0 and 100. It is not necessary to define a hydration at all, and we can also make layers without this parameter:

.. tab-set-code::
    .. code-block:: Matlab

        % Non hydrated layer
        Dry_Layer = {'Dry Layer', 'Layer Thickness', 'D SLD', 'Layer rough'};
        problem.addLayer(Dry_Layer);
    
    .. code-block:: Python

        problem.layers.append(name='Dry Layer', thickness='Layer Thickness', SLD='D SLD', roughness='Layer rough')

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            Dry_Layer = {'Dry Layer', 'Layer Thickness', 'D SLD', 'Layer rough'};
            problem.addLayer(Dry_Layer);
            problem.layers.displayTable()

    .. tab-item:: Python 
        :sync: Python

        .. output:: Python

            problem.layers.append(name='Dry Layer', thickness='Layer Thickness', SLD='D SLD', roughness='Layer rough')
            print(problem.layers)


The value of an existing layer can be changed by specifying the layer number, layer parameter to be changed and the value to change to. So for example below, 
changes parameter 2 (Thickness) of Layer 1 (H Layer) to the 3rd Parameter of the parameter block (H SLD):

.. tab-set-code::
    .. code-block:: Matlab

        problem.setLayerValue(1, 2, 3);
        
        % Alternative: setLayerValue allows the use of names so the following is the same as the line above

        problem.setLayerValue('H Layer', 'Thickness', 'H SLD');

    .. code-block:: Python

        problem.layers.set_fields(0, thickness='H SLD') 

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem.setLayerValue('H Layer', 'Thickness', 'H SLD');
            problem.layers.displayTable()

    .. tab-item:: Python 
        :sync: Python

        .. output:: Python

            problem.layers.set_fields(0, thickness='H SLD') 
            print(problem.layers)


The layers are then used to set up the contrasts as usual with a standard layers model.

Bulk Phases
===========

These are treated in the same way as parameters e.g.

.. tab-set-code::
    .. code-block:: Matlab

        problem.addBulkIn('Silicon', 2.0e-6, 2.07e-6, 2.1e-6, false);
        problem.addBulkOut('H2O', -0.6e-6, -0.56e-6, -0.5e-6, false);
    
    .. code-block:: Python
        
        problem.bulk_in.append(name='Silicon', min=2.0e-06, value=2.073e-06, max=2.1e-06, fit=False)
        problem.bulk_out.append(name='D2O', min=-0.6e-6, value=-0.56e-6, max=-0.5e-6, fit=False)

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem.addBulkIn('Silicon', 2.0e-6, 2.07e-6, 2.1e-6, false);
            problem.addBulkOut('H2O', -0.6e-6, -0.56e-6, -0.5e-6, false);
            problem.bulkIn.displayTable()
            problem.bulkOut.displayTable()

    .. tab-item:: Python 
        :sync: Python

        .. output:: Python

            problem.bulk_in.append(name='Silicon', min=2.0e-06, value=2.073e-06, max=2.1e-06, fit=False)
            problem.bulk_out.append(name='D2O', min=-0.6e-6, value=-0.56e-6, max=-0.5e-6, fit=False)
            print(problem.bulk_in)
            print(problem.bulk_out)

The values of BulkIn and BulkOut can be modified as shown below:

.. tab-set-code::
    .. code-block:: Matlab

        problem.setBulkOut(1, 'value', 5.9e-6, 'fit', true);
        
        % Similarly BulkIn can be changed
        % problem.setBulkIn('Silicon', 'value', 5.9e-6, 'fit', true);

    .. code-block:: Python

        problem.bulk_out.set_fields(0, value=5.9e-6, fit=True)
        
        # similarly bulk in can be changed
        # problem.bulk_in.set_fields(0, value=5.9e-6, fit=True)


Scalefactors
============
The *scalefactors* are another parameters block like the bulk phases. You can add and modify *scalefactors* similar as with the previous blocks.

.. tab-set-code::
    .. code-block:: Matlab

        problem.addScalefactor('New Scalefactor',0.9,1.0,1.1,true);
        problem.setScalefactor(1,'value',1.01);
    
    .. code-block:: Python

        problem.scalefactors.append(name='New Scalefactor', min=0.9, value=1.0, max=1.1, fit=True)
        problem.scalefactors.set_fields(0, value=1.01)

Backgrounds
===========
The backgrounds block is used to define the type of background applied to each contrast, and the parameters used to define the backgrounds themselves. The fittable parameters are in the
'Background Params' block, and the backgrounds themselves are in the 'Backgrounds' block:


.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem.background.displayBackgroundsObject()

    .. tab-item:: Python 
        :sync: Python

        .. output:: Python
            
            print(problem.backgrounds)

The 'Background Parameters' is in fact another instance of the parametersClass, and there are corresponding methods to fit, set limits and so on for these.

The backgrounds can be one of three types: 'constant', 'function' or 'data'. The three types are discussed in more detail below:

.. note::
    Only 'constant' and 'data' are allowed in phase 1, and 'function' will be introduced in phase 2.

* **Constant** - This is the normal background type from RasCAL1. Each background requires one *and only one* Background Parameter associated with it, as follows:

.. tab-set-code::
    .. code-block:: Matlab

        problem.addBackgroundParam('My New BackPar', 1e-8, 1e-7, 1e-6, true);
        problem.addBackground('My New Background','constant','My New BackPar');

    .. code-block:: Python

        problem.background_parameters.append(name='My New BackPar', min=1e-8, value=1e-7, max=1e-6, fit=True)
        problem.backgrounds.append(name='My New Background', type='constant', value_1='My New BackPar')


With this code snippet we've made a new background, with the value taken from the (fittable) parameter called 'My New BackPar':

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem.addBackgroundParam('My New BackPar', 1e-8, 1e-7, 1e-6, true);
            problem.addBackground('My New Background','constant','My New BackPar');
            problem.background.displayBackgroundsObject()

    .. tab-item:: Python 
        :sync: Python

        .. output:: Python

            problem.background_parameters.append(name='My New BackPar', min=1e-8, value=1e-7, max=1e-6, fit=True)
            problem.backgrounds.append(name='My New Background', type='constant', value_1='My New BackPar')
            print(problem.background_parameters)
            print(problem.backgrounds)


This is then available to be used by any of our contrasts (see later).

* **Data** - This option is used when a measured data background is available. Suppose our measured data is in a datafile loaded into the data block (see later), and called 'My Background Data'. To define a data background, we simply specify this datafile in our background specification:

.. tab-set-code::
    .. code-block:: Matlab

        problem.addBackground('Data Background 1', 'data', 'My Background Data')
    
    .. code-block:: Python

        problem.backgrounds.append(name='Data Background 1', type='data', value_1='My Background Data')

.. .. tab-set::
..     :class: tab-label-hidden
..     :sync-group: code

..     .. tab-item:: Matlab
..         :sync: Matlab

..         .. output:: Matlab

..              problem.addBackground('Data Background 1', 'data', 'My Background Data')
..              problem.background.displayBackgroundsObject()

..     .. tab-item:: Python 
..         :sync: Python

..         .. output:: Python

..              problem.backgrounds.append(name='Data Background 1', type='data', value_1='My Background Data')
..              print(problem.backgrounds)

This is then used in the reflectivity calculation for any contrast in which it is specified.

.. note::
    No 'Background Parameters' are associated with data backgrounds. Also, take care to make sure that the background and data with which it is intended to be used *have the same q values*, otherwise an interpolation will be carried out which will be slower.

Resolutions
===========
As is the case for the backgrounds, the resolutions block is also split into two parts: a parameters block which defines the fittable parameters, and then the main Resolutions block which groups these as required into actual resolutions.
The three types are:

*   **Constant**: The default type. A resolutionParameter defines the width of a sliding Gaussian window convolution applied to the data.
*   **Function**: Convolution of the data with an arbitrary, user defined function (not yet implemented).
*   **Data**: Convolution with a sliding Gaussian defined by a fourth column of a datafile.


.. note::
    Only 'Constant' and 'Data' are implemented in phase 1. Convolution with an arbitrary function will be introduced in phase 2.

To define a resolution parameter, we use the addResolutionParam method:

.. tab-set-code::
    .. code-block:: Matlab

        problem.addResolutionParam('My Resolution Param', 0.02, 0.05, 0.08, true)

    .. code-block:: Python

        problem.resolution_parameters.append(name='My Resolution Param', min=0.02, value=0.05, max=0.08, fit=True)


.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem.resolution.displayResolutionsObject()

    .. tab-item:: Python 
        :sync: Python

        .. output:: Python

            print(problem.resolution_parameters)
            print(problem.resolutions)


Then, we make the actual resolution referring to whichever one of the resolution parameters:

.. tab-set-code::
    .. code-block:: Matlab

        problem.addResolution('My new resolution','constant','My Resolution Param')
        problem.addResolution('My Data Resolution','data')

    .. code-block:: Python
    
        problem.resolutions.append(name='My new resolution', type='constant', value_1='My Resolution Param')
        problem.resolutions.append(name='My Data Resolution', type='data')

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem.addResolutionParam('My Resolution Param', 0.02, 0.05, 0.08, true);
            problem.addResolution('My new resolution','constant','My Resolution Param');
            problem.addResolution('My Data Resolution','data');
            problem.resolution.displayResolutionsObject()

    .. tab-item:: Python 
        :sync: Python

        .. output:: Python

            problem.resolution_parameters.append(name='My Resolution Param', min=0.02, value=0.05, max=0.08, fit=True)
            problem.resolutions.append(name='My new resolution', type='constant', value_1='My Resolution Param')
            problem.resolutions.append(name='My Data Resolution', type='data')
            print(problem.resolutions)

.. note::
    There are no parameters with Data resolution. Instead this tells RAT to expect a fourth column in the datafile. If no fourth column exists in the data to which this is applied, RAT will throw an error at runtime.


Data
====
The data block contains the data which defines at which points in q the reflectivity is calculated at each contrast. By default, it initialises with a single 'Simulation' entry:

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem.data.displayTable()

    .. tab-item:: Python 
        :sync: Python

        .. output:: Python

            print(problem.data)


For each entry in the table there are four fields:

* **Name**: The name you choose to give the datafile (for reference in the contrasts block)
* **Data**: An array containing the data itself (empty for Simulation).
* **Data Range**: The min / max range of the data you wish to include in the fit. As is the case for RasCAL, you do not have to include all the data in the calculation of chi-squared. This range cannot lie outside the range of any data added to the second column.
* **Simulation Range**: The total range of the simulation to be calculated. This can lie outside the range of the data to allow for extrapolation, but must be >= the overall data range.

To add data, we first load it into Matlab, then create a new data entry containing it:

.. tab-set-code::
    .. code-block:: Matlab

        root = getappdata(0, 'root');
        myData = readmatrix(fullfile(root, '/examples/normalReflectivity/customXY/c_PLP0016596.dat'));
        problem.addData('My new datafile', myData)
    
    .. code-block:: Python

        import numpy as np
        myData = np.loadtxt('c_PLP0016596.dat', delimiter=",")
        problem.data.append(name='My new datafile', data=myData)

and out new dataset appears in the table:

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            root = getappdata(0, 'root');
            myData = readmatrix(fullfile(root, '/examples/normalReflectivity/customXY/c_PLP0016596.dat'));
            problem.addData('My new datafile', myData);
            problem.data.displayTable()

    .. tab-item:: Python 
        :sync: Python

        .. output:: Python

            from importlib.resources import files
            import numpy as np
            data_path =  files("RATapi.examples.data")
            myData = np.loadtxt(data_path / 'c_PLP0016596.dat', delimiter=',')
            problem.data.append(name='My new datafile', data=myData)
            print(problem.data)


Note that we did not specify data or simulation ranges, and so these default to the min / max values of the data added. To change these (or anything else about the data entry)
use the *'setData'* method. Also note that this data has a fourth column, and so can be used as a data resolution if you wish.

Putting it all together – defining contrasts
============================================

As is the case for RasCAL, once we have defined the various aspects of our project i.e. backgrounds, data and so on, we group these together into contrasts to make out fitting project. We can add a contrast using just its name, and edit it later, or we can specify which parts of our project we want to add to the contrast using name value pairs:

.. tab-set-code::
    .. code-block:: Matlab

        problem.addContrast('name', 'D-tail/H-Head/D2O',...
                            'background', 'Background D2O',...
                            'resolution', 'Resolution 1',...
                            'scalefactor', 'Scalefactor 1',...
                            'BulkOut', 'SLD D2O',...
                            'BulkIn', 'SLD Air',...
                            'data', 'D-tail / H-head / D2O');
        
    .. code-block:: Python

        problem.contrasts.append(name='D-tail/H-Head/D2O', background='Background D2O', resolution='Resolution 1', 
                                 scalefactor='Scalefactor 1', bulk_out='SLD D2O', bulk_in='SLD Air', data='D-tail / H-head / D2O')

The values which we add must refer to names within the other blocks of the project. So, if you try to add a *scalefactor* called 'scalefactor1' when this name doesn't exist in the *scalefactors* block, then an error will result.

Once we have added the contrasts, then we need to set the model, either by adding layers for a *standard layers* project, or a custom model file (we discuss these in :ref:`customModels`). 
In the case of layers, we give a list of layer names, in order from bulk in to bulk out. So for a monolayer for example, we would specify tails and then heads in as shown below:

.. tab-set-code::
    .. code-block:: Matlab

        problem.setContrastModel(1, {'Deuterated Tails','Hydrogenated heads'});
    
    .. code-block:: Python

        problem.contrasts.set_fields(0, model=['Deuterated Tails','Hydrogenated heads'])

The data can be either a datafile or the simulation object in the data block. Once we have defined our contrasts they appear in the *contrasts* block at the end of the project when it is displayed.

*****************************
The Monolayer Example In Full
*****************************
In the previous sections, we showed an example of a pre-loaded problem definition class, which we used to analyse data from two contrasts of a lipid monolayer. Now, rather than loading in a pre-defined version of this problem we can use our class methods to build this from scratch, and do the same analysis as we did there, but this time from a script.

To start, we first make an instance of the project class:

.. tab-set-code::
    .. code-block:: Matlab

        problem = createProject(name='DSPC monolayers');
    
    .. code-block:: Python

        import RATapi as RAT
        problem = RAT.Project(name='DSPC monolayers')

Then we need to define the parameters we need. We'll do this by making a parameters block, and adding these to project class:

.. tab-set-code::
    .. code-block:: Matlab

        % Define the parameters:
        Parameters = {
            %       Name                min     val     max      fit? 
            {'Tails Thickness',         10,     20,      30,     true};
            {'Heads Thickness',          3,     11,      16,     true};
            {'Tails Roughness',          2,     5,       9,      true};
            {'Heads Roughness',          2,     5,       9,      true};
            {'Deuterated Tails SLD',    4e-6,   6e-6,    2e-5,   true};
            {'Hydrogenated Tails SLD', -0.6e-6, -0.4e-6, 0,      true};
            {'Deuterated Heads SLD',    1e-6,   3e-6,    8e-6,   true};
            {'Hydrogenated Heads SLD',  0.1e-6, 1.4e-6,  3e-6,   true};
            {'Heads Hydration',         0,      0.3,     0.5,    true};
            };

        problem.addParameterGroup(Parameters);

    .. code-block:: Python
        
        parameters = [RAT.models.Parameter(name='Tails Thickness', min=10, value=20, max=30, fit=True),
                      RAT.models.Parameter(name='Heads Thickness', min=3, value=11, max=16, fit=True),
                      RAT.models.Parameter(name='Tails Roughness', min=2, value=5, max=9, fit=True),
                      RAT.models.Parameter(name='Heads Roughness', min=2, value=5, max=9, fit=True),
                      RAT.models.Parameter(name='Deuterated Tails SLD', min=4e-6, value=6e-6, max=2e-5, fit=True),
                      RAT.models.Parameter(name='Hydrogenated Tails SLD', min=-0.6e-6, value=-0.4e-6, max=0, fit=True),
                      RAT.models.Parameter(name='Deuterated Heads SLD', min=1e-6, value=3e-6, max=8e-6, fit=True),
                      RAT.models.Parameter(name='Hydrogenated Heads SLD', min=0.1e-6, value=1.4e-6, max=3e-6, fit=True),
                      RAT.models.Parameter(name='Heads Hydration', min=0, value=0.3, max=0.5, fit=True)] 
 
        problem.parameters.extend(parameters)

Next we need to group the parameters into our layers. We need four layers in all, representing deuterated and hydrogenated versions of the heads and tails:

.. tab-set-code::
    .. code-block:: Matlab

        H_Heads = {'Hydrogenated Heads',...
                'Heads Thickness',...
                'Hydrogenated Heads SLD',...
                'Heads Roughness',...
                'Heads Hydration',...
                'bulk out' };
                    
        D_Heads = {'Deuterated Heads',...
                'Heads Thickness',...
                'Deuterated Heads SLD',...
                'Heads Roughness',...
                'Heads Hydration',...
                'bulk out' };
                    
        D_Tails = {'Deuterated Tails',...
                'Tails Thickness',...
                'Deuterated Tails SLD',...
                'Tails Roughness'};

        H_Tails = {'Hydrogenated Tails',...
                'Tails Thickness',...
                'Hydrogenated Tails SLD',...
                'Tails Roughness'};
    
    .. code-block:: Python
        
        H_Heads = RAT.models.Layer(name='Hydrogenated Heads', thickness='Heads Thickness', 
                                   SLD='Hydrogenated Heads SLD', roughness='Heads Roughness', 
                                   hydration='Heads Hydration', hydrate_with='bulk out')
                    
        D_Heads = RAT.models.Layer(name='Deuterated Heads', thickness='Heads Thickness', 
                                   SLD='Deuterated Heads SLD', roughness='Heads Roughness',
                                   hydration='Heads Hydration', hydrate_with='bulk out')
                    
        D_Tails = RAT.models.Layer(name='Deuterated Tails', thickness='Tails Thickness',
                                   SLD='Deuterated Tails SLD', roughness='Tails Roughness')

        H_Tails = RAT.models.Layer(name='Hydrogenated Tails', thickness='Tails Thickness',
                                   SLD='Hydrogenated Tails SLD', roughness='Tails Roughness')
.. note:: 
    The headgroups are hydrated and so share a hydration parameter, whereas the tails are not. 

We now add our layers to the project:

.. tab-set-code::
    .. code-block:: Matlab

        problem.addLayerGroup({H_Heads; D_Heads; H_Tails; D_Tails});
    
    .. code-block:: Python

        problem.layers.extend([H_Heads, D_Heads, H_Tails, D_Tails])

We are using two different sub-phases: D2O and ACMW. We need a different constant background for each, so we need two bckground parameters. There is already one background parameter in the project as a default, so we rename this and add a second one:

.. tab-set-code::
    .. code-block:: Matlab

        problem.setBackgroundParamName(1, 'Backs Value ACMW'); % Use existing backsPar
        problem.setBackgroundParamValue(1, 5.5e-6);
        problem.addBackgroundParam('Backs Value D2O', 1e-8, 2.8e-6, 1e-5);
    
    .. code-block:: Python
        
        problem.background_parameters.set_fields(0, name='Backs Value ACMW')
        problem.background_parameters.set_fields(0, value=5.5e-6)
        problem.background_parameters.append(name='Backs Value D2O', min=1e-8, value=2.8e-6, max=1e-5)
       
Use these parameters to define two constant backgrounds, again using the existing default for one of them:

.. tab-set-code::
    .. code-block:: Matlab

        problem.addBackground('Background D2O', 'constant', 'Backs Value D2O');
        problem.setBackground(1, 'name', 'Background ACMW', 'value1', 'Backs Value ACMW');
    
    .. code-block:: Python

        problem.backgrounds.append(name='Background D2O', type='constant', value_1='Backs Value D2O')
        problem.backgrounds.set_fields(0, name='Background ACMW', value_1='Backs Value ACMW')

We need two sub-phases for our project. D2O is already in the project as a default, so we only need to add the bulk out for ACMW

.. tab-set-code::
    .. code-block:: Matlab

        problem.addBulkOut('SLD ACMW', -1e-6, 0.0, 1e-6, true);

    .. code-block:: Python

        problem.bulk_out.append(name='SLD ACMW', min=-0.6e-6, value=-0.56e-6, max=-0.3e-6, fit=True)

Now we need to add the data. We read in the two files into MATLAB, and put the data into the data block with appropriate names:

.. tab-set-code::
    .. code-block:: Matlab

        root = getappdata(0, 'root');
        dataPath = '/examples/miscellaneous/convertRasCAL1Project/';
        d13ACM = readmatrix(fullfile(root, dataPath, 'd13acmw20.dat'));
        d70d2O = readmatrix(fullfile(root, dataPath, 'd70d2o20.dat'));
        problem.addData('H-tail / D-head / ACMW', d13ACM);
        problem.addData('D-tail / H-head / D2O', d70d2O);
    
    .. code-block:: Python

        import numpy as np
        d13ACM = np.loadtxt('d13acmw20.dat', delimiter=",")
        d70d2O = np.loadtxt('d70d2o20.dat', delimiter=",")
        problem.data.append(name='H-tail / D-head / ACMW', data=d13ACM)
        problem.data.append(name='D-tail / H-head / D2O', data=d70d2O)

We have everything we need to now build our contrasts. We have two contrasts in all, and we build them using name / value pairs for all the different parts of the contrasts (i.e. selecting which background and bulk phases etc we need using the names we have given them.)

.. tab-set-code::
    .. code-block:: Matlab

        problem.addContrast('name', 'D-tail/H-Head/D2O',...
                            'background', 'Background D2O',...
                            'resolution', 'Resolution 1',...
                            'scalefactor', 'Scalefactor 1',...
                            'BulkOut', 'SLD D2O',...
                            'BulkIn', 'SLD Air',...
                            'data', 'D-tail / H-head / D2O'); 

        problem.addContrast('name', 'H-tail/D-Head/ACMW',...
                            'background', 'Background ACMW',...
                            'resolution', 'Resolution 1',...
                            'scalefactor', 'Scalefactor 1',...
                            'BulkOut', 'SLD ACMW',...
                            'BulkIn', 'SLD Air',...
                            'data', 'H-tail / D-head / ACMW');
    .. code-block:: Python

        problem.contrasts.append(name='D-tail/H-Head/D2O', background='Background D2O', resolution='Resolution 1', 
                                 scalefactor='Scalefactor 1', bulk_out='SLD D2O', bulk_in='SLD Air', data='D-tail / H-head / D2O')

        problem.contrasts.append(name='H-tail/D-Head/ACMW', background='Background ACMW', resolution='Resolution 1', 
                                 scalefactor='Scalefactor 1', bulk_out='SLD ACMW', bulk_in='SLD Air', data='D-tail / H-head / D2O')
    
To define the models for each contrast, we add the relevant layers as appropriate:

.. tab-set-code::
    .. code-block:: Matlab

        problem.setContrastModel(1, {'Deuterated Tails','Hydrogenated heads'});
        problem.setContrastModel(2, {'Hydrogenated Tails','Deuterated Heads'});
    
    .. code-block:: Python

        problem.contrasts.set_fields(0, model=['Deuterated Tails', 'Hydrogenated Heads'])
        problem.contrasts.set_fields(1, model=['Hydrogenated Tails', 'Deuterated Heads'])

We need to make sure that we are fitting the relevant backgrounds, scalefactors and bulk phase values:

.. tab-set-code::
    .. code-block:: Matlab

        problem.setBackgroundParam(1, 'fit', true);
        problem.setBackgroundParam(2, 'fit', true);
        problem.setScalefactor(1, 'fit', true);
        problem.setBulkOut(1, 'fit', true);

    .. code-block:: Python

        problem.background_parameters.set_fields(0, fit=True)
        problem.background_parameters.set_fields(1, fit=True)
        problem.scalefactors.set_fields(0, fit=True)
        problem.bulk_out.set_fields(0, fit=True)

Now have a look at our project, to make sure it all looks reasonable

.. tab-set-code::
    .. code-block:: Matlab

        disp(problem)

    .. code-block:: Python

        print(problem)

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem = load('source/tutorial/data/monolayerExample.mat');
            problem = problem.problem;
            disp(problem)

    .. tab-item:: Python 
        :sync: Python

        .. output:: Python

            # replace with a better project reading method when we have one...
            with open('source/tutorial/data/monolayer_example.py', "r") as f:
                script = f.read()
            locals = {}
            exec(script, None, locals)
            problem = locals['problem']
            print(problem)

Now we'll calculate this to check the agreement with the data. We need an instance of the controls class, with the procedure attribute set to *calculate* (the default):

.. tab-set-code::
    .. code-block:: Matlab

        controls = controlsClass();
        disp(controls)
    
    .. code-block:: Python

        controls = RAT.Controls();
        print(controls)

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            controls.display = 'iter';
            disp(controls)

    .. tab-item:: Python 
        :sync: Python
        
        .. output:: Python

            print(controls)

We then send all of this to RAT, and plot the output:

.. tab-set-code::
    .. code-block:: Matlab

        [problem,results] = RAT(problem,controls);
    
    .. code-block:: Python

        problem, results = RAT.run(problem, controls)

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            [problem,results] = RAT(problem,controls);

    .. tab-item:: Python 
        :sync: Python

        .. output:: Python

            problem, results = RAT.run(problem, controls)


.. tab-set-code::
    .. code-block:: Matlab

        figure(1); clf;
        plotRefSLD(problem, results)
    
    .. code-block:: Python

        

.. image:: ../images/userManual/chapter2/plot1.png
    :alt: Displays reflectivity and SLD plot

To do a fit, we change the *procedure* attribute of the controls class to **simplex**. We will also change the 'parallel' option to 'contrasts', so that each contrast gets its own calculation thread, 
and modify the output to only display the final result (rather than each iteration) and then run our fit and plot the results:

.. tab-set-code::
    .. code-block:: Matlab

        controls.procedure = 'simplex';
        controls.parallel = 'contrasts';
        controls.display = 'final';
        [problem, results] = RAT(problem, controls)
    
    .. code-block:: Python

        controls = RAT.Controls(procedure='simplex', parallel='contrasts', display='final')
        problem, results = RAT.run(problem, controls)

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            controls.procedure = 'simplex';
            controls.parallel = 'contrasts';
            controls.display = 'final';
            [problem,results] = RAT(problem,controls);

    .. tab-item:: Python 
        :sync: Python

        .. output:: Python

            controls = RAT.Controls(procedure='simplex', parallel='contrasts', display='final')
            problem, results = RAT.run(problem, controls)

.. tab-set-code::
    .. code-block:: Matlab

        disp(results)

    .. code-block:: Python

        print(results)

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            disp(results)

    .. tab-item:: Python 
        :sync: Python

        .. output:: Python

            print(results)

We can now plot the results of our fit:

.. tab-set-code::
    .. code-block:: Matlab

        figure; clf;
        plotRefSLD(out,results)
    
    .. code-block:: Python

        RAT.plotting.plot_ref_sld(problem, results)

.. image:: ../images/userManual/chapter2/plot2.png
    :alt: Displays reflectivity and SLD plot
