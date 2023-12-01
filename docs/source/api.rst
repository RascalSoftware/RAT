:orphan:

=====
API
=====

API is the folder that contains the two main classes of RAT are. They are **Project Class** and **Controls Class** and these are the classes user interacts with.  

.. note::
  The "API" name comes from the generalized view how APIs work. In this case, the API sends the information back and forth from the top level classes to targetFunctions. 


.. _ProjectClass:

Project Class
==============
Project Class is all about data. It contains the very data user wants to work with. It stores all the data required for reflectivity calculations. 
Everything in RAT comes from projectClass in one way or another. There are many functions that deal with breaking down the data from Project Class into smaller pieces 
so that they can be used in other parts of the software.


Project Class has lot of other classes that help create objects for inputs. They are : 

1. Parameter Class 
2. Resolution Class 
3. Data Class 
4. Contrasts Class 
5. Custom File Class 

.. note::
    Most of these classes have the following in common:

    1. They are all called from Project Class.
    2. Methods to add or remove or change an attribute depending on the class.
    3. Methods to find the location based on input value. Finding row when given an attribute's name or vice versa (Not all of them though).
    4. Display methods.
    5. A 'toStruct' method which output the class parameters as a struct.


Parameters Class 
-----------------

Parameters Class helps to add,set or remove parameters to the Project Class. The class has a constructor that gets initiated when Parameter class is called. This constructor 
sets important initial values to the class obj (object) like variable name, types. It also initiates a "table" that helps to store all the parameters. Table is a really useful 
data type provided by matlab. Check this link to know more about `table`_.

.. list-table:: The methods on the left call the methods on the right in the table.
    :widths: 25 25
    :header-rows: 1

    * - Method in Project Class
      - Method in Parameters Class 
    * - projectClass.addParamGroup()
      - parametersClass.addParam() 
    * - projectClass.addParam()
      - parametersClass.addParam()
    * - projectClass.removeParam()
      - parametersClass.removeParam()
    * - projectClass.setParameter()
      - parametersClass.setParameter()
    * - projectClass.setParameter()
      - parametersClass.setValue()
    
      
When adding parameters, they can be added individually or as a group (see below). When added as a group, `addParamGroup` method in projectClass iterates over the 
list of parameters and adds them one by one using `addParam` method which is used to add individual parameters.

.. code-block:: MATLAB 
    :caption: Adding parameters as a group. Can set to a class using projectClass.addParamGroup(Parameters)

        Parameters = {
        %   Name                min         val         max     fit? 
        {'Oxide thick',         5,         20,         60,     true   };
        {'Oxide SLD',           3e-6,       3.41e-6,    4e-6,   false  };
        {'Oxide Hydration'      0,          20,         30,     true   }};


.. code-block:: MATLAB 
    :caption: Adding parameters individually. Can set to a class using projectClass.addParam(Parameter)

        Oxide =     {'Oxide Layer',...          % Name of the layer
                    'Oxide thick',...           % Layer thickness
                    'Oxide SLD',...             % Layer SLD
                    'Substrate Roughness',...   % Layer roughness
                    'Oxide Hydration',...       % Oxide hydration (percent)
                    'bulk out' };               % Which bulk phase is hydrating the layer
            
    % Add this to the projectClass...
    projectClass.addLayer(Oxide);

.. _table: https://uk.mathworks.com/help/matlab/tables.html

When *addParam* method is called, the method checks the input through a series of checks to find out
if there are any unexpected values at unexpected places. For example, having logical value in place of a numerical value argument. With *setParameter* method, 
one can set the value of any parameter independently. However, there are other methods that helps setting individual parameters. For example, *setName* method helps
to set the name of a parameter.

.. note::
    
    1. You can add Bulk in and Bulk out with this class 
    2. You can add scale factor with this class 



Layers in Project Class
------------------------------
Like Parameters, Layers can be added as a group or individually. When added as a group, `addLayerGroup` method in projectClass iterates over the list of layers and
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


Bulk In and Bulk Out 
---------------------
Bulk In and Bulk Out are ........................to be added. They are set using the `addParam` method in parameter class since they have the same columns in the table.

.. list-table:: The methods on the left call the methods on the right in the table.
    :widths: 50 50
    :header-rows: 1

    * - Method in Project Class
      - Method in Parameter Class 
    * - projectClass.addBulkIn/addBulkOut()
      - parametersClass.addParam() 
    * - projectClass.removeBulkIn/removeBulkOut()
      - parametersClass.removeParam()
    * - projectClass.setBulkIn/setBulkOut()
      - parametersClass.setParameter()

Although, Project class provides one level higher interface so that one can use `addBulkIn` and `addBulkOut` methods from projectClass to set these parameters.

.. code-block:: MATLAB
    :caption: Adding Bulk Out. Can set to a class using projectClass.addBulkOut(BulkIn)

        %                   Name       min     val   max  fit?
        problem.addBulkOut({'SLD SMW',2e-6,2.073e-6,3e-6,true});

 

`setParameter` or `setBulk(In/Out)` does the same thing which is converting cell array to struct. 

Background Class 
----------------

This class makes the backgrounds in RAT. Backgrounds are defined in a two stage process. Firstly we define the actual fitted parameters. 
These are held in a 'ParametersClass' table. Then, we group these into the backgrounds themselves using a multiTypeTable(`table`_). So, we can then use the 
background parameters to either define background as constant, data or a function.

.. list-table:: The methods on the left call the methods on the right in the table.
    :widths: 50 50
    :header-rows: 1

    * - Method in Project Class
      - Method in backgroundsClass 
    * - projectClass.addBacksPar()
      - backgroundsClass.addBacksPar() 
    * - projectClass.removeBacksPar()
      - backgroundsClass.removeBacksPar()
    * - projectClass.setBacksPar()
      - backgroundsClass.setBacksPar()
    * - projectClass.addBackground()
      - backgroundsClass.addBackground()
    * - projectClass.removeBackground()
      - backgroundsClass.removeBackground()
    * - projectClass.setBackground{Value/Name}()
      - backgroundsClass.setBackground{Value/Name}()

Some of the methods of Background Class are:

1. `addBacksPar` - This method adds the parameter to the back parameter table.
2. `setBacksParValue` - Set a parameter value in the back parameter table.
3. `removeBacksPar` - Remove a parameter from the backsPar/ back parameter table.
4. `addBackground` - Add a background to the background table. 
5. `setBackground` - Set a background value in the background table. (Based on row)


.. note::
 1. For constant, only one parameter is supplied to multi type table. 
 2. For data, only the data itself is supplied as a cell. 
 3. For function, the function name is supplied, along with up to three parameters (from the parameters table) which are then supplied to the function to
    calculate the background. 
    
In each case, the background can either be added to the simulation or subtracted from the data.

.. code-block:: MATLAB
    :caption: Example showing how backgroundsClass methods are called.

        % Change the name of the existing parameters to refer to D2O
        problem.setBacksPar(1,'name','Backs par D2O','fit',true,'min',1e-8,'max',1e-5);

        % Add a new constant background
        problem.addBackground('Background SMW','constant','Backs par SMW');


Multi-Type Table
#################
Multi-type Table is a custom table type. It is a general type of table that can altered to one's needs by taking advantage of methods that allow 
adding rows, setting values of an element, etc. This class is used in Background Class.


Data Class 
-----------

Data Class is a class to helps add or set data. Data can be addded using `addData` method. The `addData` method expects a cell array of cell array. Like other methods there's
a check that directs different cases based on the length of inputs (1 meaning only name or data entered. If only name is entered, error prompted saying 'Single input is expected 
to be data name'. Case 2 being both name and data supplied and data is added accordingly). It uses `table`_ data type to do that. 
The dataTable is a `table`_ with 4 columns. The following are the 4 columns:

1. Name of the data
2. Second column is the data itself
3. Data range. The data range is a cell array with two elements, the first element is the minimum value of the data, and 
   the second element is the maximum value of the data. (optional)
4. Simulation range. The simulation range is a cell array with two elements, the first element is the minimum value of the 
   simulation, and the second element is the maximum value of the simulation. (optional)


.. list-table:: The methods on the left call the methods on the right in the table.
    :widths: 25 25
    :header-rows: 1

    * - Method in Project Class
      - Method in Data Class 
    * - projectClass.addData()
      - dataClass.addData() 
    * - projectClass.setData()
      - dataClass.setData()


Like other classes, it has methods to setData, setDataRange or any individual column/parameter. It also checks if the data given is in the right format, 
and if so, it stores it. If not, it has proper conditional statements to pinpoint the error. Like warning about duplicate names, number of inputs, type of an
input .. etc. 

.. code-block:: MATLAB
    :caption: Adding data. Usually, the data is in .dat files. So, `dlmread` built-in method is used to read the data into a variable.

        D2O_data = dlmread('c_PLP0016596.dat');
        % Add the data to the project
        projectClass.addData('Bilayer / D2O', D2O_data(:,1:3));

.. code-block:: MATLAB
    :caption: Setting data range. (Min and Max values)

        problem.setData(2,'dataRange',[0.013 0.35]);


Custom File Class
-----------------
RAT enables users to define their own custom files. They can be linked to RAT through Custom File class. Like other classes, the inputs are checked for
the right order and type. Also, it uses `table`_ data type to store the custom files. Custom files can be added or removed using the methods this class provides. 

The custom file table has the following columns:

1. Name of the row in the Custom File table
2. Name of the custom file
3. Language of the custom file
4. Path of the custom file

If all of the 4 columns are supplied, a new row (cell array of strings) is made using the supplied inputs. Then, `appendNewRow` method is used to append the row to the obj.
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
    RAT only supports C++, MATLAB, Octave and potentially Python.


Contrast Class
---------------
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
            'nbs', 'SLD D2O',...        % This is bulk out ('Nb Subs')
            'nba', 'Silicon',...        % This is bulk in ('Nb Air')
            'data', 'Bilayer / D2O');


While setting contrasts to a model, `setContrastModel` method is called. This method is called with a cell array of a { number , cell array }. The number being what contrast 
is and the cell array containing the information about the model. The main purpose of this method is to set the contrast to a model based on specified type of model. Based 
on the type of model, the code checks whether some of contrast names are allowed or not. If not, it throws an error.


.. code-block:: MATLAB
    :caption: Setting a contrast to a model

        % 1 refers to the contrast number and the rest Layer information
        problem.setContrastModel(1,{'Oxide Layer',...
              'Water Layer',...
              'Bil inner head',...
              'Bil tail',...
              'Bil tail',...
              'Bil outer head'});


Resolution Class
----------------

Resolutions are defined in a two stage process. Firstly, actual fitted parameters are defined. These are held in a 'Parameter Class' table (referring to data type).
Then,these are grouped into the resolutions themselves using a multi-type table. Then the resolution parameters can be used to either define resolution as 
constant, data, or a function. 

The constructor is called with the parameters and resolutions as input. The parameters are stored in the resolPars table whereas the resolutions are stored in 
the resolutions table and the allowed types are defined in the allowedTypes variable.

.. note::

    1. For constant only one parameter is supplied to multi-type table. 
    2. For data, the name is supplied, along with name of the data in the data table. 
    3. For function, the function name is supplied, along with up to three parameters (from the parameters table) which are then supplied to the function to calculate the resolution. 

In each case, the Resolutions can either be added to or subtracted from the data.


.. _controlsClass:

Controls Class
==============

ControlsClass is all about control. It is necessary in determine the way RAT works. It deals with how the user interacts with the software. From type of parallelization
to whether the users wants to calculate SLD during fit and even how many iteration an algorithm should do ..etc.


There are 5 different `controlsClass.procedures` that can be used with RAT. They are:

1. **Simplex** 
2. **Differential Evolution** - Optimizes a problem by iteratively improving a candidate solution based on an evolutionary process
3. **Nested Sampler** -  Estimates directly how the likelihood function relates to prior mass
4. **DREAM**
5. **Calculate** 

Each of them has their own unique set of options. The fields in class object of controlsClass are 
automatically updated based on the procedure selected.

RAT uses parallelization to speed up the calculation. This is achieved using Parallel Computing Toolbox. The user can choose to use the parallelization or not and 
if yes, what to parallelize on. (Points or Contrasts or all)

.. code-block:: MATLAB
    :caption: Sample usage of controlsClass.

        controls = controlsClass();
        controls.calcSldDuringFit = false;
        controls.nsimu = 7000;
        controls.repeats = 3;
        controls.parallel = 'contrasts';

.. code-block:: MATLAB
    :caption: Alternate usage of controlsClass.

        controls = controlsClass();
        controls = controls.setProcedure('dream',...
                                         {'nSamples', 6000,...
                                          'nChains', 10,...
                                          'parallel', 'contrasts'})

RAT 
====

After the user has defined the projectClass and controlsClass, the user can run RAT like shown below

.. code-block:: MATLAB
    :caption: Sample usage of RAT class.

        % Initialize the project class
        problem = projectClass();

        % Initialize the controls class
        controls = controlsClass();

        % call the RAT function
        [problem,results] = RAT(problem,controls);


When the RAT function is called, the classes are passed into internal functions like `RatParseClassToStructs_new` which takes the classes and breaks them down into cells, 
limits,prior and more importantly converts the project class to struct. 

Then, the `RATMain` function redirects the control flow based on what procedure is selected in controlsClass. One of the redirecting functions will call the reflectivityCalculation
which starts the reflectivity calculation.


Some interesting data type changes are needed because of how things work with coder. Coder wont accept variable sized cell arrays contains variable sized arrays (strings for eg) 
in a field of a struct. So, look at `RatParseClassToStructs_new` function to understand how the data is converted.
