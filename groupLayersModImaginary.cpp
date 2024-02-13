//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// groupLayersModImaginary.cpp
//
// Code generation for function 'groupLayersModImaginary'
//

// Include files
#include "groupLayersModImaginary.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void groupLayersModImaginary(const ::coder::array<real_T, 2U> &allLayers,
    real_T allRoughs, const char_T geometry_data[], const int32_T geometry_size
    [2], real_T bulkIns, real_T bulkOuts, ::coder::array<real_T, 2U> &outLayers,
    real_T *outSsubs)
  {
    ::coder::array<real_T, 2U> layers;
    ::coder::array<real_T, 2U> sldss;
    ::coder::array<real_T, 1U> b_allLayers;
    ::coder::array<real_T, 1U> c_allLayers;
    ::coder::array<real_T, 1U> roughs;
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
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
    //      [outLayers, outSsubs] = groupLayersModImaginary(allLayers,allRoughs,geometry,bulkIns,bulkOuts)
    //
    //  INPUTS:
    //      * allLayers: cell array, one for each contrast. Each cell is the list of layer values for each contrast.
    //      * allRoughs:  Double of substrate roughness for each contrast.
    //      * geometry: 'Air / Liquid (or solid)' or 'Solid / Liquid'
    //      * bulkIns: vector of bulkIn values.
    //      * bulkOuts: vector of bulkOut values.
    //
    //  Outputs:
    //      * outLayers: cell array of layers param values for each contrast.
    //      * outSsubs: vector of substrate roughness values.
    // outLayers = cell(1,numberOfContrasts);
    // outSsubs = zeros(1,numberOfContrasts);
    // for i = 1:numberOfContrasts
    *outSsubs = allRoughs;
    unnamed_idx_0 = static_cast<uint32_T>(allLayers.size(0));
    layers.set_size(allLayers.size(0), allLayers.size(1));
    loop_ub = allLayers.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = static_cast<int32_T>(unnamed_idx_0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        layers[i1 + layers.size(0) * i] = 0.0;
      }
    }

    if ((allLayers.size(0) != 0) && (allLayers.size(1) != 0)) {
      if (coder::internal::p_strcmp(geometry_data, geometry_size)) {
        layers.set_size(allLayers.size(0), allLayers.size(1));
        loop_ub = allLayers.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = allLayers.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            layers[i1 + layers.size(0) * i] = allLayers[i1 + allLayers.size(0) *
              i];
          }
        }

        // s_sub = rsub;
      } else {
        loop_ub = allLayers.size(0);
        sldss.set_size(allLayers.size(0), 2);
        for (i = 0; i < 2; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            sldss[i1 + sldss.size(0) * i] = allLayers[i1 + allLayers.size(0) *
              (i + 1)];
          }
        }

        *outSsubs = allLayers[(allLayers.size(0) + allLayers.size(0) * 3) - 1];
        if (allLayers.size(0) > 1) {
          loop_ub = allLayers.size(0);
          roughs.set_size(allLayers.size(0));
          roughs[0] = allRoughs;
          for (i = 0; i <= loop_ub - 2; i++) {
            roughs[i + 1] = allLayers[i + allLayers.size(0) * 3];
          }
        } else {
          roughs.set_size(1);
          roughs[0] = allRoughs;
        }

        if (allLayers.size(1) == 5) {
          int32_T result_idx_0;
          b_loop_ub = allLayers.size(0);
          loop_ub = allLayers.size(0);
          b_allLayers.set_size(allLayers.size(0));
          for (i = 0; i < loop_ub; i++) {
            b_allLayers[i] = allLayers[i];
          }

          result_idx_0 = allLayers.size(0);
          loop_ub = allLayers.size(0);
          c_allLayers.set_size(allLayers.size(0));
          for (i = 0; i < loop_ub; i++) {
            c_allLayers[i] = allLayers[i + allLayers.size(0) * 4];
          }

          layers.set_size(allLayers.size(0), 5);
          for (i = 0; i < 1; i++) {
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              layers[i1] = b_allLayers[i1];
            }
          }

          for (i = 0; i < 2; i++) {
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              layers[i1 + layers.size(0) * (i + 1)] = sldss[i1 + result_idx_0 *
                i];
            }
          }

          for (i = 0; i < 1; i++) {
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              layers[i1 + layers.size(0) * 3] = roughs[i1];
            }
          }

          for (i = 0; i < 1; i++) {
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              layers[i1 + layers.size(0) * 4] = c_allLayers[i1];
            }
          }
        } else {
          int32_T result_idx_0;
          b_loop_ub = allLayers.size(0);
          loop_ub = allLayers.size(0);
          b_allLayers.set_size(allLayers.size(0));
          for (i = 0; i < loop_ub; i++) {
            b_allLayers[i] = allLayers[i];
          }

          result_idx_0 = allLayers.size(0);
          layers.set_size(allLayers.size(0), 4);
          for (i = 0; i < 1; i++) {
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              layers[i1] = b_allLayers[i1];
            }
          }

          for (i = 0; i < 2; i++) {
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              layers[i1 + layers.size(0) * (i + 1)] = sldss[i1 + result_idx_0 *
                i];
            }
          }

          for (i = 0; i < 1; i++) {
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              layers[i1 + layers.size(0) * 3] = roughs[i1];
            }
          }
        }
      }

      // Deal with the %coverage if present
      if (allLayers.size(1) == 6) {
        i = allLayers.size(0);
        for (int32_T j{0}; j < i; j++) {
          real_T d;
          real_T pc_add;
          d = allLayers[j + allLayers.size(0) * 4];
          if (d == 1.0) {
            pc_add = bulkIns;
          } else {
            pc_add = bulkOuts;
          }

          if (!std::isnan(d)) {
            layers[j + layers.size(0)] = pc_add * (d / 100.0) + (1.0 - d / 100.0)
              * layers[j + layers.size(0)];

            // layers(j,3) = pc_add*(this_pcw/100) + (1-(this_pcw/100))*layers(j,3);
          }
        }
      }
    }

    if ((layers.size(0) != 0) && (layers.size(1) != 0)) {
      loop_ub = layers.size(0);
      outLayers.set_size(layers.size(0), 4);
      for (i = 0; i < 4; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          outLayers[i1 + outLayers.size(0) * i] = layers[i1 + layers.size(0) * i];
        }
      }
    } else {
      outLayers.set_size(1, 4);
      outLayers[0] = 0.0;
      outLayers[outLayers.size(0)] = 0.0;
      outLayers[outLayers.size(0) * 2] = 0.0;
      outLayers[outLayers.size(0) * 3] = 0.0;
    }
  }
}

// End of code generation (groupLayersModImaginary.cpp)
