//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// customBilayer.cpp
//
// Code generation for function 'customBilayer'
//

// Include files
#include "customBilayer.h"

// Function Definitions
void customBilayer(const double params[8], double, double bulk_out, double,
                   double output[18], double *sub_rough)
{
  double head_idx_0;
  double head_idx_1;
  double tail_idx_0;
  double tail_idx_1;
  // CUSTOMBILAYER  RASCAL Custom Layer Model File.
  //
  //
  //  This file accepts 3 vectors containing the values for
  //  Params, bulk in and bulk out
  //  The final parameter is an index of the contrast being calculated
  //  The m-file should output a matrix of layer values, in the form..
  //  Output = [thick 1, SLD 1, Rough 1, Percent Hydration 1, Hydrate how 1
  //            ....
  //            thick n, SLD n, Rough n, Percent Hydration n, Hydration how n]
  //  The "hydrate how" parameter decides if the layer is hydrated with
  //  Bulk out or Bulk in phases. Set to 1 for Bulk out, zero for Bulk in.
  //  Alternatively, leave out hydration and just return..
  //  Output = [thick 1, SLD 1, Rough 1,
  //            ....
  //            thick n, SLD n, Rough n] };
  //  The second output parameter should be the substrate roughness
  *sub_rough = params[0];
  //  We have a constant SLD for the bilayer
  //  Now make the lipid layers..
  //  Use known lipid volume and compositions
  //  to make the layers
  //  define all the neutron b's.
  // Carbon
  // Oxygen
  // Hydrogen
  // Phosphorus
  // Nitrogen
  // Deuterium
  //  Now make the lipid groups..
  //  Group these into heads and tails:
  //  We need volumes for each.
  //  Use literature values:
  //  we use the volumes to calculate the SLD's
  //  We calculate the layer thickness' from
  //  the volumes and the APM...
  //  Manually deal with hydration for layers in
  //  this example.
  //  Make the layers
  head_idx_0 = 319.0 / params[3];
  head_idx_1 = params[4] * bulk_out + (1.0 - params[4]) * 2.0103761755485893E-6;
  tail_idx_0 = 782.0 / params[3];
  tail_idx_1 =
      params[5] * bulk_out + (1.0 - params[5]) * -5.9554987212276231E-7;
  output[0] = params[1];
  output[6] = params[2] * bulk_out + (1.0 - params[2]) * 3.41E-6;
  output[12] = params[0];
  output[1] = params[7];
  output[7] = bulk_out;
  output[13] = params[6];
  output[2] = head_idx_0;
  output[3] = tail_idx_0;
  output[4] = tail_idx_0;
  output[5] = head_idx_0;
  output[8] = head_idx_1;
  output[9] = tail_idx_1;
  output[10] = tail_idx_1;
  output[11] = head_idx_1;
  output[14] = params[6];
  output[15] = params[6];
  output[16] = params[6];
  output[17] = params[6];
}

// End of code generation (customBilayer.cpp)
