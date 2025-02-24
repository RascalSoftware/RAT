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
  void groupLayersModImaginary(const ::coder::array<double, 2U> &resampledLayers,
    double subRoughs, const char geometry_data[], const int geometry_size[2],
    double bulkIns, double bulkOuts, ::coder::array<double, 2U> &outLayers,
    double *ssubs)
  {
    ::coder::array<double, 2U> layers;
    ::coder::array<double, 2U> sldss;
    ::coder::array<double, 1U> b_resampledLayers;
    ::coder::array<double, 1U> c_resampledLayers;
    ::coder::array<double, 1U> roughs;
    int b_loop_ub;
    int i;
    int i1;
    int loop_ub;
    unsigned int unnamed_idx_0;

    //  Arrange layers according to geometry and apply any coverage correction. The paratt calculation proceeds through the
    //  z,rho,rough stack, and the parameter 'ssub' is the final roughness encountered.
    //
    //  * For air liquid 'ssub' is therefore the substrate roughness.
    //  * For solid liquid, the substrate roughness is the first roughness encountered, and 'ssub' is then the roughness of the outermost layer
    //
    //  USAGE::
    //
    //      [outLayers, ssubs] = groupLayersModImaginary(resampledLayers,subRoughs,geometry,bulkIns,bulkOuts)
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
    //      * ssubs: vector of ssub values.
    *ssubs = subRoughs;
    unnamed_idx_0 = static_cast<unsigned int>(resampledLayers.size(0));
    layers.set_size(resampledLayers.size(0), resampledLayers.size(1));
    loop_ub = resampledLayers.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = static_cast<int>(unnamed_idx_0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        layers[i1 + layers.size(0) * i] = 0.0;
      }
    }

    if ((resampledLayers.size(0) != 0) && (resampledLayers.size(1) != 0)) {
      if (coder::internal::p_strcmp(geometry_data, geometry_size)) {
        layers.set_size(resampledLayers.size(0), resampledLayers.size(1));
        loop_ub = resampledLayers.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = resampledLayers.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            layers[i1 + layers.size(0) * i] = resampledLayers[i1 +
              resampledLayers.size(0) * i];
          }
        }
      } else {
        loop_ub = resampledLayers.size(0);
        sldss.set_size(resampledLayers.size(0), 2);
        for (i = 0; i < 2; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            sldss[i1 + sldss.size(0) * i] = resampledLayers[i1 +
              resampledLayers.size(0) * (i + 1)];
          }
        }

        *ssubs = resampledLayers[(resampledLayers.size(0) + resampledLayers.size
          (0) * 3) - 1];
        if (resampledLayers.size(0) > 1) {
          loop_ub = resampledLayers.size(0);
          roughs.set_size(resampledLayers.size(0));
          roughs[0] = subRoughs;
          for (i = 0; i <= loop_ub - 2; i++) {
            roughs[i + 1] = resampledLayers[i + resampledLayers.size(0) * 3];
          }
        } else {
          roughs.set_size(1);
          roughs[0] = subRoughs;
        }

        if (resampledLayers.size(1) == 5) {
          int result_idx_0;
          b_loop_ub = resampledLayers.size(0);
          loop_ub = resampledLayers.size(0);
          b_resampledLayers.set_size(resampledLayers.size(0));
          for (i = 0; i < loop_ub; i++) {
            b_resampledLayers[i] = resampledLayers[i];
          }

          result_idx_0 = resampledLayers.size(0);
          loop_ub = resampledLayers.size(0);
          c_resampledLayers.set_size(resampledLayers.size(0));
          for (i = 0; i < loop_ub; i++) {
            c_resampledLayers[i] = resampledLayers[i + resampledLayers.size(0) *
              4];
          }

          layers.set_size(resampledLayers.size(0), 5);
          for (i = 0; i < 1; i++) {
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              layers[i1] = b_resampledLayers[i1];
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
              layers[i1 + layers.size(0) * 4] = c_resampledLayers[i1];
            }
          }
        } else {
          int result_idx_0;
          b_loop_ub = resampledLayers.size(0);
          loop_ub = resampledLayers.size(0);
          b_resampledLayers.set_size(resampledLayers.size(0));
          for (i = 0; i < loop_ub; i++) {
            b_resampledLayers[i] = resampledLayers[i];
          }

          result_idx_0 = resampledLayers.size(0);
          layers.set_size(resampledLayers.size(0), 4);
          for (i = 0; i < 1; i++) {
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              layers[i1] = b_resampledLayers[i1];
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

      //  Deal with the %coverage if present
      if (resampledLayers.size(1) == 6) {
        i = resampledLayers.size(0);
        for (int j{0}; j < i; j++) {
          double pc_add;
          double this_pcw;
          this_pcw = resampledLayers[j + resampledLayers.size(0) * 4];
          if (resampledLayers[j + resampledLayers.size(0) * 5] == 1.0) {
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
