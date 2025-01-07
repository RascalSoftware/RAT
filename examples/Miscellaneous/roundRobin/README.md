## Round Robin Sample

This is an analysis of the ORSO 'round Robin' sample on ISIS instruments. 
There is data collected on Inter, PolRef and CRISP

The complete worksheet is in 'roundRobin.mlx'. This code:
- Makes a 1 layer model, applies it to the Inter data.
- Runs a Bayesian analysis of this
- Uses the Nested Sampler to screen between the 1 layer and 2 layer problem.
- Runs the 1 layer model on the other data, compares the results.
- Runs a full Bayesian analysis of the three datasets simultaneously. 
 