## Standard Layers Example

This shows an example of using a 'standard layers' model to analyse reflectivity
from a floating bilayer of DSPC. The model is set up in 'standardLayersDSPCScript.m'

To run it, create a controls block, choose an algorithm and run it. In 'runMain.m', we do this, run a differential algorithm, and then carry out a Bayesian analysis using 'DREAM'.

In the set up of the model, we set Gaussian priors on some of the parameters,
then print the results.

Alternatively, you can see this all together in the 'standardLayersDSPCSheet' Matlab
Live worksheet.
