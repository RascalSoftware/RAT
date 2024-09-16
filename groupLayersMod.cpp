//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// groupLayersMod.cpp
//
// Code generation for function 'groupLayersMod'
//

// Include files
#include "groupLayersMod.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void groupLayersMod(const ::coder::array<real_T, 2U> &resampledLayers, real_T
                      subRoughs, const char_T geometry_data[], const int32_T
                      geometry_size[2], real_T bulkIns, real_T bulkOuts, ::coder::
                      array<real_T, 2U> &outLayers, real_T *outSsubs)
  {
    ::coder::array<real_T, 2U> layers;
    ::coder::array<real_T, 1U> roughs;
    int32_T b_loop_ub;
    int32_T c_loop_ub;
    int32_T i;
    int32_T loop_ub;
    uint32_T unnamed_idx_0;

    //  Arrange layers according to geometry and apply any coverage correction. The paratt calculation proceeds through the
    //  z,rho,rough stack, and the parameter 'ssub' in callParatt is the final roughness encountered.
    //
    //  * For air liquid 'ssub' is therefore the substrate roughness.
    //  * For solid liquid, the substrate roughness is the first roughness encountered, and 'ssub' is then the roughness of the outermost layer
    //
    //  USAGE::
    //
    //      [outLayers, outSsubs] = groupLayersMod(resampledLayers,subRoughs,geometry,bulkIns,bulkOuts)
    //
    //  INPUTS:
    //      * resampledLayers: cell array, one for each contrast. Each cell is the list of layer values for each contrast.
    //      * subRoughs:  Double of substrate roughness for each contrast.
    //      * geometry: 'Air / Liquid (or solid)' or 'Solid / Liquid'
    //      * bulkIns: vector of bulkIn values.
    //      * bulkOuts: vector of bulkOut values.
    //
    //  Outputs:
    //      * outLayers: cell array of layers param values for each contrast.
    //      * outSsubs: vector of substrate roughness values.
    *outSsubs = subRoughs;
    unnamed_idx_0 = static_cast<uint32_T>(resampledLayers.size(0));
    layers.set_size(resampledLayers.size(0), resampledLayers.size(1));
    loop_ub = resampledLayers.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = static_cast<int32_T>(unnamed_idx_0);
      for (c_loop_ub = 0; c_loop_ub < b_loop_ub; c_loop_ub++) {
        layers[c_loop_ub + layers.size(0) * i] = 0.0;
      }
    }

    if ((resampledLayers.size(0) != 0) && (resampledLayers.size(1) != 0)) {
      if (coder::internal::n_strcmp(geometry_data, geometry_size)) {
        layers.set_size(resampledLayers.size(0), resampledLayers.size(1));
        loop_ub = resampledLayers.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = resampledLayers.size(0);
          for (c_loop_ub = 0; c_loop_ub < b_loop_ub; c_loop_ub++) {
            layers[c_loop_ub + layers.size(0) * i] = resampledLayers[c_loop_ub +
              resampledLayers.size(0) * i];
          }
        }
      } else {
        *outSsubs = resampledLayers[(resampledLayers.size(0) +
          resampledLayers.size(0) * 2) - 1];
        if (resampledLayers.size(0) > 1) {
          loop_ub = resampledLayers.size(0);
          roughs.set_size(resampledLayers.size(0));
          roughs[0] = subRoughs;
          for (i = 0; i <= loop_ub - 2; i++) {
            roughs[i + 1] = resampledLayers[i + resampledLayers.size(0) * 2];
          }
        } else {
          roughs.set_size(1);
          roughs[0] = subRoughs;
        }

        if (resampledLayers.size(1) == 5) {
          loop_ub = resampledLayers.size(0);
          b_loop_ub = resampledLayers.size(0);
          c_loop_ub = resampledLayers.size(0);
          layers.set_size(resampledLayers.size(0), 4);
          for (i = 0; i < loop_ub; i++) {
            layers[i] = resampledLayers[i];
          }

          for (i = 0; i < b_loop_ub; i++) {
            layers[i + layers.size(0)] = resampledLayers[i +
              resampledLayers.size(0)];
          }

          loop_ub = roughs.size(0);
          for (i = 0; i < loop_ub; i++) {
            layers[i + layers.size(0) * 2] = roughs[i];
          }

          for (i = 0; i < c_loop_ub; i++) {
            layers[i + layers.size(0) * 3] = resampledLayers[i +
              resampledLayers.size(0) * 3];
          }
        } else {
          loop_ub = resampledLayers.size(0);
          b_loop_ub = resampledLayers.size(0);
          layers.set_size(resampledLayers.size(0), 3);
          for (i = 0; i < loop_ub; i++) {
            layers[i] = resampledLayers[i];
          }

          for (i = 0; i < b_loop_ub; i++) {
            layers[i + layers.size(0)] = resampledLayers[i +
              resampledLayers.size(0)];
          }

          loop_ub = roughs.size(0);
          for (i = 0; i < loop_ub; i++) {
            layers[i + layers.size(0) * 2] = roughs[i];
          }
        }
      }

      // Deal with the %coverage if present
      if (resampledLayers.size(1) == 5) {
        i = resampledLayers.size(0);
        for (int32_T j{0}; j < i; j++) {
          real_T pc_add;
          real_T this_pcw;
          this_pcw = resampledLayers[j + resampledLayers.size(0) * 3];
          if (resampledLayers[j + resampledLayers.size(0) * 4] == 1.0) {
            pc_add = bulkIns;
          } else {
            pc_add = bulkOuts;
          }

          if (!std::isnan(this_pcw)) {
            layers[j + layers.size(0)] = pc_add * (this_pcw / 100.0) + (1.0 -
              this_pcw / 100.0) * layers[j + layers.size(0)];
          }
        }
      }
    }

    if ((layers.size(0) != 0) && (layers.size(1) != 0)) {
      loop_ub = layers.size(0);
      outLayers.set_size(layers.size(0), 3);
      for (i = 0; i < 3; i++) {
        for (c_loop_ub = 0; c_loop_ub < loop_ub; c_loop_ub++) {
          outLayers[c_loop_ub + outLayers.size(0) * i] = layers[c_loop_ub +
            layers.size(0) * i];
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

// End of code generation (groupLayersMod.cpp)
