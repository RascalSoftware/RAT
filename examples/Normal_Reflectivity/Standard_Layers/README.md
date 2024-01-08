

## Standard Layers Example

This shows an example of using a 'standard layers' model to analyse reflectivity
from a floating bilayer of DSPC. The model is set up in 'dspc_standard_layers.m'

To run it it's then necessary to make a controls block, choose and algorithm
and run it. In 'runMain.m', we do this, run a differential algorithm, and 
the carry out a Bayesian analysis using 'DREAM'.

In the set up of the model, we set Gaussian priors on some of the parameters,
then print the results.

Alternatively, you can see this all together in the 'dspc_bilayer_sheet' Matlab
Live worksheet.

===

