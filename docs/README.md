Documentation
=============
The documentation is in the **docs** folder. This consist of the developer documentation, m2html generated docs, and 
user manual.

Build developer docs
--------------------
The documentation should be built using the provided Sphinx make file. The reStructuredText source is in the docs/source 
folder while the build will be placed in the docs/build. The build requires a python executable and the python packages 
in the requirements.txt 

    conda create -n RAT python=3.9
    conda activate RAT
    pip install -r requirements.txt

In the terminal with access to the the python executable 

    cd docs
    make html

Build with m2html
-----------------
The m2html documentation is built using the m2html MATLAB toolbox available in the 3rdParty folder. In the MATLAB 
terminal (use 'runMATLABCommand' in any other terminal)

    cd docs
    buildM2htmlDocs


Build user manual
-----------------
The user manual is still in MS word document and will be converted to restructuredText later.
 