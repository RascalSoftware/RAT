//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: groupLayers_Mod.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 15-Apr-2021 10:46:16
//

// Include Files
#include "groupLayers_Mod.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arrange layers according to geometry and apply any coverage correction.
//
// [outLayers, outSsubs] = groupLayers_Mod(allLayers,allRoughs,numberOfContrasts,geometry,nbairs,nbsubs)
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
// Arguments    : const coder::array<double, 2U> *allLayers
//                double allRoughs
//                const coder::array<char, 2U> *geometry
//                double nbair
//                double nbsubs
//                coder::array<double, 2U> *outLayers
//                double *outSsubs
// Return Type  : void
//
void groupLayers_Mod(const coder::array<double, 2U> &allLayers, double allRoughs,
                     const coder::array<char, 2U> &geometry, double nbair,
                     double nbsubs, coder::array<double, 2U> &outLayers, double *
                     outSsubs)
{
  unsigned int unnamed_idx_0;
  coder::array<double, 2U> layers;
  int loop_ub;
  int i;
  int kstr;
  static const char cv[128] = { '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e',
    '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
    '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!',
    '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?',
    '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']',
    '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{',
    '|', '}', '~', '\x7f' };

  static const char cv1[13] = { 'a', 'i', 'r', '/', 's', 'u', 'b', 's', 't', 'r',
    'a', 't', 'e' };

  // outLayers = cell(1,numberOfContrasts);
  // outSsubs = zeros(1,numberOfContrasts);
  // for i = 1:numberOfContrasts
  *outSsubs = allRoughs;
  unnamed_idx_0 = static_cast<unsigned int>(allLayers.size(0));
  layers.set_size((static_cast<int>(unnamed_idx_0)), 5);
  loop_ub = static_cast<int>(unnamed_idx_0) * 5;
  for (i = 0; i < loop_ub; i++) {
    layers[i] = 0.0;
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
          if (cv[static_cast<unsigned char>(geometry[kstr]) & 127] != cv[
              static_cast<int>(cv1[kstr])]) {
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
      loop_ub = allLayers.size(0) * allLayers.size(1);
      for (i = 0; i < loop_ub; i++) {
        layers[i] = allLayers[i];
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
        layers[(i + layers.size(0) * 2) + 1] = allLayers[i + allLayers.size(0) *
          2];
      }

      for (i = 0; i < c_loop_ub; i++) {
        layers[i + layers.size(0) * 3] = allLayers[i + allLayers.size(0) * 3];
      }
    }

    // Deal with the %coverage if present
    i = allLayers.size(0);
    for (kstr = 0; kstr < i; kstr++) {
      double this_pcw;
      double pc_add;
      this_pcw = allLayers[kstr + allLayers.size(0) * 3];
      if (allLayers[kstr + allLayers.size(0) * 4] == 1.0) {
        pc_add = nbair;
      } else {
        pc_add = nbsubs;
      }

      if (!rtIsNaN(this_pcw)) {
        layers[kstr + layers.size(0)] = pc_add * (this_pcw / 100.0) + (1.0 -
          this_pcw / 100.0) * layers[kstr + layers.size(0)];
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
        outLayers[kstr + outLayers.size(0) * i] = layers[kstr + layers.size(0) *
          i];
      }
    }
  } else {
    outLayers.set_size(1, 3);
    outLayers[0] = 0.0;
    outLayers[1] = 0.0;
    outLayers[2] = 0.0;
  }

  // end
}

//
// File trailer for groupLayers_Mod.cpp
//
// [EOF]
//
