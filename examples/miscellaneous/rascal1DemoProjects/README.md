## Rascal 1 Demo Projects

This shows examples ported from the RasCAL1 demo projects. The following projects were ported over 

- monolayerVolumeModel (monolayerVolumeModel.m)
- Monolayer_8_contrasts (monolayer7Contrast.m)

Other RasCAL1 projects can be converted using the `r1ToProjectClass` utility function. Look at 
the **convertRascal1Project** example for a demonstration of converting a RasCAL1 project to a 
RAT project object. 

A script can be generated from the converted project if needed using the **writeScript** method  


``` matlab
problem = r1ToProjectClass('monolayerVolumeModel.mat');
problem.writeScript();

```