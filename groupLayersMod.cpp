//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
  double groupLayersMod(const ::coder::array<double, 2U> &resampledLayers,
                        double subRoughs, const char geometry_data[], const int
                        geometry_size[2], double bulkIns, double bulkOuts, ::
                        coder::array<double, 2U> &outLayers)
  {
    ::coder::array<double, 2U> layers;
    ::coder::array<double, 1U> roughs;
    double ssubs;
    int b_loop_ub;
    int i;
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
    //      [outLayers, ssubs] = groupLayersMod(resampledLayers,subRoughs,geometry,bulkIns,bulkOuts)
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
    ssubs = subRoughs;
    unnamed_idx_0 = static_cast<unsigned int>(resampledLayers.size(0));
    layers.set_size(resampledLayers.size(0), resampledLayers.size(1));
    loop_ub = resampledLayers.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = static_cast<int>(unnamed_idx_0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        layers[i1 + layers.size(0) * i] = 0.0;
      }
    }

    if ((resampledLayers.size(0) != 0) && (resampledLayers.size(1) != 0)) {
      if (coder::internal::q_strcmp(geometry_data, geometry_size)) {
        layers.set_size(resampledLayers.size(0), resampledLayers.size(1));
        loop_ub = resampledLayers.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = resampledLayers.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            layers[i1 + layers.size(0) * i] = resampledLayers[i1 +
              resampledLayers.size(0) * i];
          }
        }
      } else {
        ssubs = resampledLayers[(resampledLayers.size(0) + resampledLayers.size
          (0) * 2) - 1];
        if (resampledLayers.size(0) > 1) {
          roughs.set_size(resampledLayers.size(0));
          roughs[0] = subRoughs;
          loop_ub = resampledLayers.size(0);
          for (i = 0; i <= loop_ub - 2; i++) {
            roughs[i + 1] = resampledLayers[i + resampledLayers.size(0) * 2];
          }
        } else {
          roughs.set_size(1);
          roughs[0] = subRoughs;
        }

        if (resampledLayers.size(1) == 5) {
          layers.set_size(resampledLayers.size(0), 4);
          loop_ub = resampledLayers.size(0);
          for (i = 0; i < loop_ub; i++) {
            layers[i] = resampledLayers[i];
            layers[i + layers.size(0)] = resampledLayers[i +
              resampledLayers.size(0)];
          }

          loop_ub = roughs.size(0);
          for (i = 0; i < loop_ub; i++) {
            layers[i + layers.size(0) * 2] = roughs[i];
          }

          loop_ub = resampledLayers.size(0);
          for (i = 0; i < loop_ub; i++) {
            layers[i + layers.size(0) * 3] = resampledLayers[i +
              resampledLayers.size(0) * 3];
          }
        } else {
          layers.set_size(resampledLayers.size(0), 3);
          loop_ub = resampledLayers.size(0);
          for (i = 0; i < loop_ub; i++) {
            layers[i] = resampledLayers[i];
            layers[i + layers.size(0)] = resampledLayers[i +
              resampledLayers.size(0)];
          }

          loop_ub = roughs.size(0);
          for (i = 0; i < loop_ub; i++) {
            layers[i + layers.size(0) * 2] = roughs[i];
          }
        }
      }

      //  Deal with the %coverage if present
      if (resampledLayers.size(1) == 5) {
        i = resampledLayers.size(0);
        for (int j{0}; j < i; j++) {
          double this_pcw;
          this_pcw = resampledLayers[j + resampledLayers.size(0) * 3];
          if (!std::isnan(this_pcw)) {
            double d;
            if (resampledLayers[j + resampledLayers.size(0) * 4] == 1.0) {
              d = bulkIns;
            } else {
              d = bulkOuts;
            }

            layers[j + layers.size(0)] = d * (this_pcw / 100.0) + (1.0 -
              this_pcw / 100.0) * layers[j + layers.size(0)];
          }
        }
      }
    }

    if ((layers.size(0) != 0) && (layers.size(1) != 0)) {
      outLayers.set_size(layers.size(0), 3);
      loop_ub = layers.size(0);
      for (i = 0; i < 3; i++) {
        for (int i1{0}; i1 < loop_ub; i1++) {
          outLayers[i1 + outLayers.size(0) * i] = layers[i1 + layers.size(0) * i];
        }
      }
    } else {
      outLayers.set_size(1, 3);
      outLayers[0] = 0.0;
      outLayers[outLayers.size(0)] = 0.0;
      outLayers[outLayers.size(0) * 2] = 0.0;
    }

    return ssubs;
  }
}

// End of code generation (groupLayersMod.cpp)
