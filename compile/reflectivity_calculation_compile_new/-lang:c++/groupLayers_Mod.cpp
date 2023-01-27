//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: groupLayers_Mod.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "groupLayers_Mod.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>

// Function Definitions
//
// Arrange layers according to geometry and apply any coverage correction.
//
//  USAGE::
//
//      [outLayers, outSsubs] = groupLayers_Mod(allLayers,allRoughs,numberOfContrasts,geometry,nbairs,nbsubs)
//
//  INPUTS:
//
//      * allLayers =         cell array, one for each contrast. Each cell is the list of layer values for each contrast.
//      * allRoughs =         Double of substrate roughness for each contrast.
//      * numberOfContrasts = double.
//      * geometry =          'Air / Liquid (or solid)' or 'Solid / Liquid'
//      * nbairs =            vector of nbair values.
//      * nbsubs =            vector of nbsub values.
//
//      The paratt calculation procedds through the
//      z,rho,rough stack, and the parameter 'ssub' in
//      callParatt is the final roughness encountered.
//
//      * For air liquid 'ssub' is therefore the substrate roughness.
//
//      * For solid liquid, the substrate roughness is the first roughness encountered, and 'ssub' is then the roughness of the outermost layer
//
//  Outputs:
//
//      * outLayers = cell array of layers param values for each contrast.
//
//      * outSsubs =  vector of substrate roughness values.
//
//
// Arguments    : const real_T allLayers_data[]
//                const int32_T allLayers_size[2]
//                real_T allRoughs
//                const char_T geometry_data[]
//                const int32_T geometry_size[2]
//                real_T nbair
//                real_T nbsubs
//                real_T outLayers_data[]
//                int32_T outLayers_size[2]
//                real_T *outSsubs
// Return Type  : void
//
namespace RAT
{
  void groupLayers_Mod(const real_T allLayers_data[], const int32_T
                       allLayers_size[2], real_T allRoughs, const char_T
                       geometry_data[], const int32_T geometry_size[2], real_T
                       nbair, real_T nbsubs, real_T outLayers_data[], int32_T
                       outLayers_size[2], real_T *outSsubs)
  {
    real_T layers_data[5000];
    int32_T i;
    int32_T layers_size_idx_0;
    int32_T layers_size_idx_0_tmp;

    // outLayers = cell(1,numberOfContrasts);
    // outSsubs = zeros(1,numberOfContrasts);
    // for i = 1:numberOfContrasts
    *outSsubs = allRoughs;
    layers_size_idx_0_tmp = static_cast<int16_T>(allLayers_size[0]);
    layers_size_idx_0 = static_cast<int16_T>(allLayers_size[0]);
    for (i = 0; i < 5; i++) {
      for (int32_T i1{0}; i1 < layers_size_idx_0_tmp; i1++) {
        layers_data[i1 + layers_size_idx_0_tmp * i] = 0.0;
      }
    }

    if (allLayers_size[0] != 0) {
      if (coder::internal::i_strcmp(geometry_data, geometry_size)) {
        int32_T loop_ub;
        layers_size_idx_0 = allLayers_size[0];
        loop_ub = allLayers_size[0];
        for (i = 0; i < 5; i++) {
          for (int32_T i1{0}; i1 < loop_ub; i1++) {
            layers_data[i1 + layers_size_idx_0 * i] = allLayers_data[i1 +
              allLayers_size[0] * i];
          }
        }

        // s_sub = rsub;
      } else {
        real_T roughs_data[1000];
        int32_T loop_ub;
        *outSsubs = allLayers_data[(allLayers_size[0] + allLayers_size[0] * 2) -
          1];
        if (allLayers_size[0] > 1) {
          layers_size_idx_0_tmp = allLayers_size[0];
          roughs_data[0] = allRoughs;
          loop_ub = allLayers_size[0];
          for (i = 0; i <= loop_ub - 2; i++) {
            roughs_data[i + 1] = allLayers_data[i + allLayers_size[0] * 2];
          }
        } else {
          layers_size_idx_0_tmp = 1;
          roughs_data[0] = allRoughs;
        }

        layers_size_idx_0 = allLayers_size[0];
        loop_ub = allLayers_size[0];
        std::copy(&allLayers_data[0], &allLayers_data[loop_ub], &layers_data[0]);
        loop_ub = allLayers_size[0];
        for (i = 0; i < loop_ub; i++) {
          layers_data[i + layers_size_idx_0] = allLayers_data[i +
            allLayers_size[0]];
        }

        for (i = 0; i < layers_size_idx_0_tmp; i++) {
          layers_data[i + layers_size_idx_0 * 2] = roughs_data[i];
        }

        loop_ub = allLayers_size[0];
        for (i = 0; i < loop_ub; i++) {
          layers_data[i + layers_size_idx_0 * 3] = allLayers_data[i +
            allLayers_size[0] * 3];
        }
      }

      // Deal with the %coverage if present
      i = allLayers_size[0];
      for (int32_T j{0}; j < i; j++) {
        real_T this_pcw;
        this_pcw = allLayers_data[j + allLayers_size[0] * 3];
        if (!std::isnan(this_pcw)) {
          real_T d;
          layers_size_idx_0_tmp = j + layers_size_idx_0;
          if (allLayers_data[j + allLayers_size[0] * 4] == 1.0) {
            d = nbair;
          } else {
            d = nbsubs;
          }

          layers_data[layers_size_idx_0_tmp] = d * (this_pcw / 100.0) + (1.0 -
            this_pcw / 100.0) * layers_data[layers_size_idx_0_tmp];
        }
      }
    }

    //      problem.layers{i} = layers;
    //      problem.ssubs(i) = s_sub;
    if (layers_size_idx_0 != 0) {
      outLayers_size[0] = layers_size_idx_0;
      outLayers_size[1] = 3;
      for (i = 0; i < 3; i++) {
        for (int32_T i1{0}; i1 < layers_size_idx_0; i1++) {
          outLayers_data[i1 + layers_size_idx_0 * i] = layers_data[i1 +
            layers_size_idx_0 * i];
        }
      }
    } else {
      outLayers_size[0] = 1;
      outLayers_size[1] = 3;
      outLayers_data[0] = 0.0;
      outLayers_data[1] = 0.0;
      outLayers_data[2] = 0.0;
    }
  }

  //
  // Arrange layers according to geometry and apply any coverage correction.
  //
  //  USAGE::
  //
  //      [outLayers, outSsubs] = groupLayers_Mod(allLayers,allRoughs,numberOfContrasts,geometry,nbairs,nbsubs)
  //
  //  INPUTS:
  //
  //      * allLayers =         cell array, one for each contrast. Each cell is the list of layer values for each contrast.
  //      * allRoughs =         Double of substrate roughness for each contrast.
  //      * numberOfContrasts = double.
  //      * geometry =          'Air / Liquid (or solid)' or 'Solid / Liquid'
  //      * nbairs =            vector of nbair values.
  //      * nbsubs =            vector of nbsub values.
  //
  //      The paratt calculation procedds through the
  //      z,rho,rough stack, and the parameter 'ssub' in
  //      callParatt is the final roughness encountered.
  //
  //      * For air liquid 'ssub' is therefore the substrate roughness.
  //
  //      * For solid liquid, the substrate roughness is the first roughness encountered, and 'ssub' is then the roughness of the outermost layer
  //
  //  Outputs:
  //
  //      * outLayers = cell array of layers param values for each contrast.
  //
  //      * outSsubs =  vector of substrate roughness values.
  //
  //
  // Arguments    : const ::coder::array<real_T, 2U> &allLayers
  //                real_T allRoughs
  //                const char_T geometry_data[]
  //                const int32_T geometry_size[2]
  //                ::coder::array<real_T, 2U> &outLayers
  //                real_T *outSsubs
  // Return Type  : void
  //
  void groupLayers_Mod(const ::coder::array<real_T, 2U> &allLayers, real_T
                       allRoughs, const char_T geometry_data[], const int32_T
                       geometry_size[2], ::coder::array<real_T, 2U> &outLayers,
                       real_T *outSsubs)
  {
    ::coder::array<real_T, 2U> layers;
    ::coder::array<real_T, 1U> roughs;
    int32_T b_loop_ub;
    int32_T loop_ub;
    uint32_T unnamed_idx_0;

    // outLayers = cell(1,numberOfContrasts);
    // outSsubs = zeros(1,numberOfContrasts);
    // for i = 1:numberOfContrasts
    *outSsubs = allRoughs;
    unnamed_idx_0 = static_cast<uint32_T>(allLayers.size(0));
    layers.set_size(allLayers.size(0), allLayers.size(1));
    loop_ub = allLayers.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      b_loop_ub = static_cast<int32_T>(unnamed_idx_0);
      for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
        layers[i1 + layers.size(0) * i] = 0.0;
      }
    }

    if (allLayers.size(0) != 0) {
      if (coder::internal::i_strcmp(geometry_data, geometry_size)) {
        layers.set_size(allLayers.size(0), allLayers.size(1));
        loop_ub = allLayers.size(1);
        for (int32_T i{0}; i < loop_ub; i++) {
          b_loop_ub = allLayers.size(0);
          for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
            layers[i1 + layers.size(0) * i] = allLayers[i1 + allLayers.size(0) *
              i];
          }
        }

        // s_sub = rsub;
      } else {
        *outSsubs = allLayers[(allLayers.size(0) + allLayers.size(0) * 2) - 1];
        if (allLayers.size(0) > 1) {
          roughs.set_size(allLayers.size(0));
          roughs[0] = allRoughs;
          loop_ub = allLayers.size(0);
          for (int32_T i{0}; i <= loop_ub - 2; i++) {
            roughs[i + 1] = allLayers[i + allLayers.size(0) * 2];
          }
        } else {
          roughs.set_size(1);
          roughs[0] = allRoughs;
        }

        layers.set_size(allLayers.size(0), 3);
        loop_ub = allLayers.size(0);
        for (int32_T i{0}; i < loop_ub; i++) {
          layers[i] = allLayers[i];
        }

        loop_ub = allLayers.size(0);
        for (int32_T i{0}; i < loop_ub; i++) {
          layers[i + layers.size(0)] = allLayers[i + allLayers.size(0)];
        }

        loop_ub = roughs.size(0);
        for (int32_T i{0}; i < loop_ub; i++) {
          layers[i + layers.size(0) * 2] = roughs[i];
        }
      }

      // Deal with the %coverage if present
    }

    //      problem.layers{i} = layers;
    //      problem.ssubs(i) = s_sub;
    if (layers.size(0) != 0) {
      outLayers.set_size(layers.size(0), 3);
      loop_ub = layers.size(0);
      for (int32_T i{0}; i < 3; i++) {
        for (int32_T i1{0}; i1 < loop_ub; i1++) {
          outLayers[i1 + outLayers.size(0) * i] = layers[i1 + layers.size(0) * i];
        }
      }
    } else {
      outLayers.set_size(1, 3);
      outLayers[0] = 0.0;
      outLayers[outLayers.size(0)] = 0.0;
      outLayers[outLayers.size(0) * 2] = 0.0;
    }
  }
}

//
// File trailer for groupLayers_Mod.cpp
//
// [EOF]
//
