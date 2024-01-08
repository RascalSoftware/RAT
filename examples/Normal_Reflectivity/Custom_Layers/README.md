

## Custom Layers Example

This shows an example of using a 'custom layers' model to analyse reflectivity
from a supported bilayer of DSPC. In essence, custom models allow you to parameterise
you model in any way you like, and then use a file to define the final layer structure.

The custom model used here is a Matlab model, which is in the file 'DSPC_Custom_Bilayer.m'.

For this sample, we can make use of the fact that the volumes, and of course the
atomistic composition are known. So, for lipid tails for example, then we can
take a literature value for the tails volume, have a fittable paramater for the
lipid area per molecule, and then the tail thickness will simply be 

Tail Thick = Tail Volume / Lipid APM.

Since the volume is known, then the SLD of the tails is also obviously easily calculable.

In addition, these datasets have a resolution (per point) in their fourth column.
We use this resolution in our analysis, rather than declaring a constant, fittable
one.

As with all the examples, there is an m-file ('orso_DSPC_Custom_Layers.m'), or
a more detailed worksheet ('orso_DSPC_Custom_Layers_Worksheet.mlx').


===

