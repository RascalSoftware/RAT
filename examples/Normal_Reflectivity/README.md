

## 'Standard Target Functions' Examples

This folder contains examples of how to use RAT to analyse what are referred
to and 'Standard TF' Samples. This refers to reflectivity data that does not use
absorption (i.e. an imaginary SLD), in not analysed as magnetic, polarised or
oil-water data. 

As is the case for RasCAL1, it is possible to use either 'Standard Layers', in
which case the model is defined as [d, rho, sigma] layers, or to use an external function
to define the model with any parameterisation using Custom Models. These can either
be as Custom Layers, where the model ultimately outputs [d, rho, sig] layers
regardless of the parameterisation, or a 'Custom XY' profile, where the model
outputs a continuous SLD profile for each contrast.

The examples in the sub-directories are as follows:

- Standard Layers:  This contains an analysis of a DSPC floating bilayer, on
                    a Silane SAM. 

- Custom Layers:    Analysis of the DSPC bilayer supported on a Silicon substrate.

- CustomXY:         An analysis of the same data as in Custom Layers, but using a continuous
                    distribution made up of Volume Fractions rather than layers.




===

