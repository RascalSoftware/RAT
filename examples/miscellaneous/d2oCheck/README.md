## Bayesian Model Selection Example

This example shows how to use the Nested Sampler to check between two models. In this case, we check whether a D2O calibration is from a clean surface.

The file d2oCheck runs the nested sampler twice with two models. Firstly a 'clean' surface, so just the bulk phases with no 'model' set in the contrast. Then the calculation is repeated with a layer added.
Then the ratio of the 'logZ' values allows the likelihood of the two models to be compared.
 
