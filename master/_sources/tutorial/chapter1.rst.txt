.. _chapter1:

============
Introduction
============

When we are at the calculations point our data analysis - that the data has been properly reduced, and we have some idea of a
modelling strategy, we can still then split the problem specification into two parts.

* The **Model Definition** describes our data, our model, the various parameters we may have along with their limits or priors,
  and other quantities such as bulk SLD's or backgrounds.

* The **Controls Block** summarises the actions which we want to do with our model. So it specifies which algorithm we
  might want to apply to improve our model fit, along with algorithm parameters such as maximum function evaluations or gradients etc.

Keeping these two separate gives a high degree of flexibility as to how we can approach a data analysis problem. For example,
suppose we have defined a Model Definition block which contains the data and model details for a given fitting problem, we
then decide that we would like to optimise this first using a genetic algorithm, and then run a Bayesian analysis to
obtain the parameter posterior distributions. To do all this we only need to define our model once, and run it twice
whilst simply modifying the Controls Block to tweak the algorithm that is run in each case. Also, once we are satisfied with
our model, we can save it or export it, and re-use this basic pattern for subsequent analysis with different,
related data sets. Keeping the Model and Controls separate gives a high degree of flexibility as to how tasks can be
formulated and run.

So, an input into RAT always conforms to this picture: a model definition class to specify the problem, and a controls definition class that tells RAT what analysis task you would like to do:

.. image:: ../images/ratInput.png
    :alt: RAT input model

The outputs are always another *problemDef* class, and a results block. The new *problemDef* class is identical to the inputted one, except with updated values of the fitted parameters (e.g. after running a fit). The results block as a set of arrays containing the results of the calculations, such as simulated reflectivities, SLD profiles or parameter distributions. 
We will discuss more about these in :ref:`next Section<chapter2>` where we look at the inputs and outputs in more detail.

In the next section, we will look at an example calculation, in order to introduce the basics of the RAT toolbox. Before we proceed, it is useful to keep a couple of things in mind:


* **Different model types** - There are many possible types of model, and this is done by having more than one version of
    the *problemDef* class:

    * Standard Problem: Problem types which are well described by a non-polarised beam, with no absorption (i.e., real refractive index only).
    * Standard Problem with imaginary refractive index.
    * Domains Problem Type ('incoherent summing').

..  * *Oil/Water problem type (phase 2)*
    * *Polarised problem type (phase 2)*

Within each problem class, there is the option of *Custom Layer* or *Custom XY* model definitions. These will be discussed in more detail in a later section.

In this section we'll look at the project definition class in more detail, we'll see how we can use the class methods to build and modify a model, and how to carry out the analysis.

.. note::
    If you are a RasCAL1 user, you probably have existing RasCAL models that you would like to analyse using RAT. If so, there is no need to re-make the model from scratch. Instead, there are
    conversion utilities (:ref:`conversionFuncs`). In fact, for those who prefer a graphical model builder, using the RasCAL1 GUI to build a basic model and then converting to RAT is a viable workflow.


********************************************
An example - A simple model of a lipid layer
********************************************

**(a) Specifying the Model.**

In the next section, we'll look in detail how to set up the problem definition for a given situation. Initially though, it is
useful to take a pre-prepared problem definition, and to see how this is then used in RAT. As an example, we'll use some
neutron reflectivity data for a lipid monolayer, collected at various deuterations, which we want to analyse simultaneously.

In terms of reflectivity, the interface we want to model (i.e. a monolayer at an air-water interface) is usually well modelled
by two layers: the hydrophobic tail regions of the lipids, which locate outside the bulk water interface, and the hydrophilic
heads which are adjacent (or embedded) in the bulk aqueous phase.

In our example, the layers can be either deuterated of hydrogenated, and the bulk water can either be D2O or ACMW.

.. image:: ../images/userManual/chapter1/lipidMonolayer.png
    :width: 300
    :alt: The lipid monolayer example

We are going to analyze our monolayer data using a RasCAL type *standard layers* model, in that we identify which parameters we
need to describe the model, group these into layers (which are defined as a thickness, roughness, SLD and hydration), and then
group the layers along with data into contrasts. The advantage of this approach is that it is simple to share parameters between
layers, so a layer representing deuterated headgroups should share the same thickness and roughness parameters as a
layer representing hydrogenated heads, but they should differ from each other in their SLD.

The problem definition in RAT is done by making an instance of a project class object, and then using the class methods to
set up the parameters, layers and so on this instance. The details of setting up a *projectClass* object is
discussed in :ref:`next Section<chapter2>`, but for now, we'll look at a pre-prepared example.

.. tab-set-code::
    .. code-block:: Matlab

        % Load in a pre-made problem Definition class
        problem = load('twoContrastExample.mat');
        problem = problem.problem;

        % Have a look at what we have
        disp(problem)

    .. code-block:: Python

        # TODO update with data
        problem = get_problem()
        print(problem)


.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem = load('source/tutorial/data/twoContrastExample.mat');
            problem = problem.problem;
            disp(problem)

    .. tab-item:: Python 
        :sync: Python

        .. output:: Python
            
            # replace with a better project reading method when we have one...
            with open('source/tutorial/data/two_contrast_example.py', "r") as f:
                script = f.read()
            locals = {}
            exec(script, None, locals)
            problem = locals['problem']
            print(problem)

This may initially look quite complicated, but it is fairly self-explanatory in terms of representing a typical RasCAL
model (and should make sense to anyone familiar to the RasCAL gui, with some thought). The various aspects of the model
definition are grouped together, then eventually combined to make our contrasts. These groups are:

1. **The Parameters Group -** This block defines all the parameters that we need to specify our model. In our layers case, we
need 10 parameters to define our system: A bulk interface roughness, thickness and roughness for the headgroups and tails, and
SLD values for the layers, depending on whether they are deuterated or not. In this block we also define the parameter values
and their allowed ranges, and specify if they are included in the fit:-

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem.parameters.displayTable()

    .. tab-item:: Python 
        :sync: Python

        .. output:: Python

            print(problem.parameters)

2. **The Layers Group -** Once we have our parameters, we then need to group these into layers, in traditional RasCAL style.
For our model, we always have two layers - a headgroup and the associated tails. Each of which can be deuterated, so we set up
4 layers in total, sharing the parameters between the layers as necessary:

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            problem.layers.displayTable()

    .. tab-item:: Python 
        :sync: Python

        .. output:: Python

            print(problem.layers)

3. **'Instrument' Parameters: (Backgrounds, scalefactors and resolutions) -** These are necessary to specify our model, and are 
specified in much the same way as the parameters. The background and resolutions blocks have a more complicated format to allow 
flexibility in how these are specified, which will be discussed further in a later section. These are the parameters that appear 
in the *experimental Parameters* tab of the RasCAL model builder, and are subsequently included in the definitions of the contrasts 
at the end of the worksheet.

4. **Data -** Each contrast has to have a dataset associated with it, whether or not it contains data or not. An empty data object 
(i.e. containing no data and just simulation ranges), means RAT will calculate the reflectivity only. When data is present, chi-squared 
will also be calculated. For our problem, we have two datasets and these are coded in to the data block ready to be incorporated into contrasts:

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

5. **Contrasts -** Once we have defined all the components of our model, we need to group them together into contrasts. We have two datasets 
we want to consider, so two contrasts. We have the relevant instrument parameters, and also we specify which layers are included in each contrast (*model*). 

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

**(b) Running our Model.**

As implied from figure (1), running RAT requires not only our input model specification, but also a controls block telling RAT what to do. We 
will discuss the controls block in more detail in :ref:`controlsInfo`, but for this demo we will just make an instance 
of the controls block and modify a few parameters to run the demo:

.. tab-set-code::
    .. code-block:: Matlab

        % Make an instance of controls class
        controls = controlsClass();
        disp(controls)

    .. code-block:: Python

        # Make an instance of controls class
        controls = RAT.Controls()
        print(controls)

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            controls = controlsClass();
            disp(controls)

    .. tab-item:: Python 
        :sync: Python
        
        .. output:: Python

            controls = RAT.Controls()
            print(controls)

This makes an instance of the controls Class we have called **controls**. The various properties of the class allow the type of calculation 
to be specified, in terms of parallelisation, choice of algorithm to be applied and so on. Here we are specifying a single threaded calculation 
of our reflectivities only (the default) - in other words we are not asking RAT to do any kind of fit with our parameters. We can now send our 
problem definition and controls classes to the RAT toolbox:


.. tab-set-code::
    .. code-block:: Matlab

        [problem, results] = RAT(problem, controls);
        disp(results)

    .. code-block:: Python

        problem, results = RAT.run(problem, controls);
        print(results)

.. tab-set::
    :class: tab-label-hidden
    :sync-group: code

    .. tab-item:: Matlab
        :sync: Matlab

        .. output:: Matlab

            [problem, results] = RAT(problem, controls);

    .. tab-item:: Python 
        :sync: Python

        .. output:: Python

            problem, results = RAT.run(problem, controls)

It is worth noticing here that this is always the general format for calling RAT. There are two inputs - a problem definition and a controls block, and the result is two outputs - another copy of the problem, and a new, *results* block. 

The problem that returns is a copy of our input, except that the parameter values will be changed by any procedure done. So, if we run a simple fit, then the output *problemDef* will have the values of the best-fit parameters. Here, we are not doing any fitting yet, and so the output is an exact copy. Also, we overwrite our original input class with the output by using the same name ('problem') as an input and an output, but you don’t have to do it this way.

Once we've run our model through RAT, then the second output (we call *results* here) is an array which contains the output of the calculation :


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

This contains the results of our calculations, so for us including the SLD profiles and reflectivities calculated from our *problemDef* class. We can now plot the output, either manually (by taking the relevant parts from the *results* array), or using one of the supplied plotting utilities:

.. tab-set-code::
    .. code-block:: Matlab

        fig(1); clf;
        plotRefSLD(problem, results)

    .. code-block:: Python

        RAT.plotting.plot_ref_sld(problem, results)

.. image:: ../images/userManual/chapter1/plots.png
    :alt: reflectivity and SLD plots

We can see that our model is looking fairly sensible, but that our guess values for the parameters are pretty wide off the mark.






