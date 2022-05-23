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
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
void groupLayers_Mod(const coder::array<double, 2U> &allLayers,
                     double allRoughs, const coder::array<char, 2U> &geometry,
                     double nbair, double nbsubs,
                     coder::array<double, 2U> &outLayers, double *outSsubs)
{
  coder::array<double, 2U> layers;
  int i;
  int kstr;
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
  loop_ub = allLayers.size(0);
  for (i = 0; i < 5; i++) {
    for (kstr = 0; kstr < loop_ub; kstr++) {
      layers[kstr + layers.size(0) * i] = 0.0;
    }
  }
  if (allLayers.size(0) != 0) {
    boolean_T b_bool;
    b_bool = false;
    if (geometry.size(1) == 13) {
      kstr = 0;
      int exitg1;
      do {
        exitg1 = 0;
        if (kstr < 13) {
          if (cv[static_cast<unsigned char>(geometry[kstr]) & 127] !=
              cv[static_cast<int>(cv2[kstr])]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (b_bool) {
      layers.set_size(allLayers.size(0), 5);
      loop_ub = allLayers.size(0);
      for (i = 0; i < 5; i++) {
        for (kstr = 0; kstr < loop_ub; kstr++) {
          layers[kstr + layers.size(0) * i] =
              allLayers[kstr + allLayers.size(0) * i];
        }
      }
      // s_sub = rsub;
    } else {
      int b_loop_ub;
      int c_loop_ub;
      *outSsubs = allLayers[(allLayers.size(0) + allLayers.size(0) * 2) - 1];
      if (1 > allLayers.size(0) - 1) {
        loop_ub = -1;
      } else {
        loop_ub = allLayers.size(0) - 2;
      }
      kstr = allLayers.size(0);
      b_loop_ub = allLayers.size(0);
      c_loop_ub = allLayers.size(0);
      layers.set_size(allLayers.size(0), 4);
      for (i = 0; i < kstr; i++) {
        layers[i] = allLayers[i];
      }
      for (i = 0; i < b_loop_ub; i++) {
        layers[i + layers.size(0)] = allLayers[i + allLayers.size(0)];
      }
      layers[layers.size(0) * 2] = allRoughs;
      for (i = 0; i <= loop_ub; i++) {
        layers[(i + layers.size(0) * 2) + 1] =
            allLayers[i + allLayers.size(0) * 2];
      }
      for (i = 0; i < c_loop_ub; i++) {
        layers[i + layers.size(0) * 3] = allLayers[i + allLayers.size(0) * 3];
      }
    }
    // Deal with the %coverage if present
    i = allLayers.size(0);
    for (kstr = 0; kstr < i; kstr++) {
      double pc_add;
      double this_pcw;
      this_pcw = allLayers[kstr + allLayers.size(0) * 3];
      if (allLayers[kstr + allLayers.size(0) * 4] == 1.0) {
        pc_add = nbair;
      } else {
        pc_add = nbsubs;
      }
      if (!std::isnan(this_pcw)) {
        layers[kstr + layers.size(0)] =
            pc_add * (this_pcw / 100.0) +
            (1.0 - this_pcw / 100.0) * layers[kstr + layers.size(0)];
      }
    }
  }
  //      problem.layers{i} = layers;
  //      problem.ssubs(i) = s_sub;
  if (layers.size(0) != 0) {
    loop_ub = layers.size(0);
    outLayers.set_size(layers.size(0), 3);
    for (i = 0; i < 3; i++) {
      for (kstr = 0; kstr < loop_ub; kstr++) {
        outLayers[kstr + outLayers.size(0) * i] =
            layers[kstr + layers.size(0) * i];
      }
    }
  } else {
    outLayers.set_size(1, 3);
    outLayers[0] = 0.0;
    outLayers[outLayers.size(0)] = 0.0;
    outLayers[outLayers.size(0) * 2] = 0.0;
  }
}

// End of code generation (groupLayers_Mod.cpp)
