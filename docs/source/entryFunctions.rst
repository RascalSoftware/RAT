===================
RAT Entry Functions
===================
The user should begin by creating a project and controls object, then the user can run RAT like shown below

.. code-block:: MATLAB
    :caption: Sample usage of RAT class.

        % Initialize the project class
        problem = createProject();

        % Initialize the controls class
        controls = controlsClass();

        % call the RAT function
        [problem,results] = RAT(problem,controls);


When the RAT function is called, the classes are passed into internal functions like `parseClassToStructs` which takes the classes and breaks them down into cells, 
limits, priors and more importantly converts the project class to struct. 

Then, the `RATMain` function redirects the control flow based on what procedure is selected in controlsClass. One of the redirecting functions will call the reflectivityCalculation
which starts the reflectivity calculation.

Some interesting data type changes are needed because of how things work with coder. Coder wont accept variable sized cell arrays contains variable sized arrays (strings for eg) 
in a field of a struct. So, look at `parseClassToStructs` function to understand how the data is converted.

.. autofunction:: API.RAT


.. autofunction:: API.RATMain


.. autofunction:: API.parseClassToStructs