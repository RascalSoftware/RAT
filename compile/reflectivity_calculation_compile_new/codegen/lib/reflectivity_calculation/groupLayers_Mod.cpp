//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// groupLayers_Mod.cpp
//
// Code generation for function 'groupLayers_Mod'
//

// Include files
#include "groupLayers_Mod.h"
#include "isnan.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"
#include <algorithm>

// Function Definitions
void groupLayers_Mod(const coder::array<double, 2U> &allLayers,
                     double allRoughs, const coder::array<char, 2U> &geometry,
                     double nbair, double nbsubs,
                     coder::array<double, 2U> &outLayers, double *outSsubs)
{
  coder::array<double, 2U> layers;
  int b_loop_ub;
  int i;
  int loop_ub;
  // Arrange layers according to geometry and apply any coverage correction.
  //
  // [outLayers, outSsubs] =
  // groupLayers_Mod(allLayers,allRoughs,numberOfContrasts,geometry,nbairs,nbsubs)
  //  Inputs:
  //      allLayers = cell array, one for each contrast. Each cell is the
  //                  list of layer values for each contrast.
  //                  e.g. allLayers{1} = [d1, rho1, r1, %hyd, hyd_which
  //                                       d2, rho2, r2, %hyd2, hyd_which_2..
  //                                       etc]
  //      allRoughs = Double of substrate roughness for each contrast.
  //      numberOfContrasts = double.
  //      geometry =  'Air / Liquid (or solid)' or 'Solid / Liquid'
  //      nbairs = vector of nbair values.
  //      nbsubs = vector of nbsub values.
  //
  //      The paratt calculation procedds through the
  //      z,rho,rough stack, and the parameter 'ssub' in
  //      callParatt is the final roughness encountered.
  //      For air liquid 'ssub' is therefore the substrate roughness.
  //      For solid liquid, the substrate roughness is the first roughness
  //      encountered, and 'ssub' is then the roughness of the outermost layer.
  //      The rougnesses need to be arranged accordingly.
  //
  //
  //  Outputs:
  //      outLayers = cell array of layers param values for each contrast.
  //                  e.g. outLayers{1} = [d1 rho1 r1;
  //                                       d2 rho2 r2
  //                                       ... etc   ]
  //      outSsubs = vector of substrate roughness values.
  //
  // outLayers = cell(1,numberOfContrasts);
  // outSsubs = zeros(1,numberOfContrasts);
  // for i = 1:numberOfContrasts
  *outSsubs = allRoughs;
  layers.set_size(allLayers.size(0), 5);
  loop_ub = allLayers.size(0) * 5;
  for (i = 0; i < loop_ub; i++) {
    layers[i] = 0.0;
  }
  if (allLayers.size(0) != 0) {
    if (coder::internal::i_strcmp(geometry)) {
      layers.set_size(allLayers.size(0), 5);
      loop_ub = allLayers.size(0) * 5;
      for (i = 0; i < loop_ub; i++) {
        layers[i] = allLayers[i];
      }
      // s_sub = rsub;
    } else {
      int c_loop_ub;
      int d_loop_ub;
      *outSsubs = allLayers[(allLayers.size(0) + allLayers.size(0) * 2) - 1];
      if (1 > allLayers.size(0) - 1) {
        loop_ub = -1;
      } else {
        loop_ub = allLayers.size(0) - 2;
      }
      b_loop_ub = allLayers.size(0);
      c_loop_ub = allLayers.size(0);
      d_loop_ub = allLayers.size(0);
      layers.set_size(allLayers.size(0), 4);
      for (i = 0; i < b_loop_ub; i++) {
        layers[i] = allLayers[i];
      }
      for (i = 0; i < c_loop_ub; i++) {
        layers[i + layers.size(0)] = allLayers[i + allLayers.size(0)];
      }
      layers[layers.size(0) * 2] = allRoughs;
      for (i = 0; i <= loop_ub; i++) {
        layers[(i + layers.size(0) * 2) + 1] =
            allLayers[i + allLayers.size(0) * 2];
      }
      for (i = 0; i < d_loop_ub; i++) {
        layers[i + layers.size(0) * 3] = allLayers[i + allLayers.size(0) * 3];
      }
    }
    // Deal with the %coverage if present
    i = allLayers.size(0);
    for (b_loop_ub = 0; b_loop_ub < i; b_loop_ub++) {
      double pc_add;
      double this_pcw;
      this_pcw = allLayers[b_loop_ub + allLayers.size(0) * 3];
      if (allLayers[b_loop_ub + allLayers.size(0) * 4] == 1.0) {
        pc_add = nbair;
      } else {
        pc_add = nbsubs;
      }
      if (!coder::b_isnan(this_pcw)) {
        layers[b_loop_ub + layers.size(0)] =
            pc_add * (this_pcw / 100.0) +
            (1.0 - this_pcw / 100.0) * layers[b_loop_ub + layers.size(0)];
      }
    }
  }
  //      problem.layers{i} = layers;
  //      problem.ssubs(i) = s_sub;
  if (layers.size(0) != 0) {
    loop_ub = layers.size(0);
    outLayers.set_size(layers.size(0), 3);
    for (i = 0; i < 3; i++) {
      for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
        outLayers[b_loop_ub + outLayers.size(0) * i] =
            layers[b_loop_ub + layers.size(0) * i];
      }
    }
  } else {
    outLayers.set_size(1, 3);
    outLayers[0] = 0.0;
    outLayers[1] = 0.0;
    outLayers[2] = 0.0;
  }
}

void groupLayers_Mod(const double allLayers[9],
                     const coder::array<char, 2U> &geometry,
                     double outLayers_data[], int outLayers_size[2],
                     double *outSsubs)
{
  double layers_data[15];
  double b_allLayers[9];
  // Arrange layers according to geometry and apply any coverage correction.
  //
  // [outLayers, outSsubs] =
  // groupLayers_Mod(allLayers,allRoughs,numberOfContrasts,geometry,nbairs,nbsubs)
  //  Inputs:
  //      allLayers = cell array, one for each contrast. Each cell is the
  //                  list of layer values for each contrast.
  //                  e.g. allLayers{1} = [d1, rho1, r1, %hyd, hyd_which
  //                                       d2, rho2, r2, %hyd2, hyd_which_2..
  //                                       etc]
  //      allRoughs = Double of substrate roughness for each contrast.
  //      numberOfContrasts = double.
  //      geometry =  'Air / Liquid (or solid)' or 'Solid / Liquid'
  //      nbairs = vector of nbair values.
  //      nbsubs = vector of nbsub values.
  //
  //      The paratt calculation procedds through the
  //      z,rho,rough stack, and the parameter 'ssub' in
  //      callParatt is the final roughness encountered.
  //      For air liquid 'ssub' is therefore the substrate roughness.
  //      For solid liquid, the substrate roughness is the first roughness
  //      encountered, and 'ssub' is then the roughness of the outermost layer.
  //      The rougnesses need to be arranged accordingly.
  //
  //
  //  Outputs:
  //      outLayers = cell array of layers param values for each contrast.
  //                  e.g. outLayers{1} = [d1 rho1 r1;
  //                                       d2 rho2 r2
  //                                       ... etc   ]
  //      outSsubs = vector of substrate roughness values.
  //
  // outLayers = cell(1,numberOfContrasts);
  // outSsubs = zeros(1,numberOfContrasts);
  // for i = 1:numberOfContrasts
  *outSsubs = 3.0;
  if (coder::internal::i_strcmp(geometry)) {
    std::copy(&allLayers[0], &allLayers[9], &layers_data[0]);
    // s_sub = rsub;
  } else {
    *outSsubs = allLayers[8];
    b_allLayers[0] = allLayers[0];
    b_allLayers[3] = allLayers[3];
    b_allLayers[1] = allLayers[1];
    b_allLayers[4] = allLayers[4];
    b_allLayers[2] = allLayers[2];
    b_allLayers[5] = allLayers[5];
    b_allLayers[6] = 3.0;
    b_allLayers[7] = allLayers[6];
    b_allLayers[8] = allLayers[7];
    std::copy(&b_allLayers[0], &b_allLayers[9], &layers_data[0]);
  }
  // Deal with the %coverage if present
  //      problem.layers{i} = layers;
  //      problem.ssubs(i) = s_sub;
  outLayers_size[0] = 3;
  outLayers_size[1] = 3;
  for (int i{0}; i < 3; i++) {
    int outLayers_data_tmp;
    outLayers_data[3 * i] = layers_data[3 * i];
    outLayers_data_tmp = 3 * i + 1;
    outLayers_data[outLayers_data_tmp] = layers_data[outLayers_data_tmp];
    outLayers_data_tmp = 3 * i + 2;
    outLayers_data[outLayers_data_tmp] = layers_data[outLayers_data_tmp];
  }
}

// End of code generation (groupLayers_Mod.cpp)
