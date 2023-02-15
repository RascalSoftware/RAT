.. image:: images/RATBanner.png
    :alt: RAT banner

|

.. _chapter2:

Chapter 2 - The Problem Definition Input Class.
...............................................

1. Basics
=========

In the previous chapter, we saw an example of how we set up and run an analysis using the RAT toolbox. Every call to the toolbox has two parts: the problem definition class, where we define the model, add the data and define our contrasts, and the Controls Class where we tell the toolbox what type of analysis we would like to do. The reason for splitting things up in this way is that once or model is defined, we can interact with it in various ways without needing to modify the model. So, we can experiment with our data, trying out different types of analysis (more of that in chapter 4), and explore the landscape of solutions by simply modifying the controls class, leaving the problem class alone. 

As well as having two inputs, RAT always provides two outputs, so the call to the toolbox is always of this form:-

.. code:: MATLAB

    [problem, results] = RAT(problem, controls)

In this case we have called our inputs ‘problem’ and ‘controls’, but they can be called anything. Likewise we have called our outputs ‘problem’ and ‘results’, but we are free to call them anything we like.  We will look at the outputs in more detail in the next section.

The first input, ‘problem’, is an instance of a class called ‘projectClass’:

.. code:: MATLAB

    >>> problem = projectClass('my project');
    >>> class(problem)

    ans =
         'projectClass'

And if we take a look at it, we can see the class contains a series of sections, where we can define our parameters, make different kinds of model, load in our data and do everything we need to set up our model.



