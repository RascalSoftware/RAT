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

// Function Definitions
namespace RAT
{
  double groupLayersMod(const ::coder::array<double, 2U> &layers, double
                        subRoughs, const char geometry_data[], const int
                        geometry_size[2], ::coder::array<double, 2U>
                        &outputLayers)
  {
    ::coder::array<double, 2U> b_layers;
    ::coder::array<double, 2U> c_layers;
    ::coder::array<double, 1U> roughnesses;
    double ssubs;

    //  Arrange layers according to geometry.
    //  The paratt calculation proceeds through the z,rho,rough stack; and the
    //  parameter 'ssub' is the final roughness encountered.
    //
    //  * For air/liquid 'ssub' is therefore the substrate roughness.
    //  * For solid/liquid, the substrate roughness is the first roughness
    //    encountered, and 'ssub' is then the roughness of the outermost layer.
    //
    //  USAGE::
    //
    //      [outLayers, ssubs] = groupLayersMod(resampledLayers,subRoughs,geometry)
    //
    //  INPUTS:
    //      * layers: List of layer values for this contrast.
    //      * subRoughs:  Double of substrate roughness for this contrast.
    //      * geometry: 'Air / Liquid (or solid)' or 'Solid / Liquid'
    //
    //  Outputs:
    //      * outputLayers: Layers parameter values for this contrast.
    //      * ssubs: vector of ssub values.
    ssubs = subRoughs;
    if ((layers.size(0) != 0) && (layers.size(1) != 0)) {
      if (coder::internal::u_strcmp(geometry_data, geometry_size)) {
        int loop_ub;
        outputLayers.set_size(layers.size(0), layers.size(1));
        loop_ub = layers.size(1);
        for (int i{0}; i < loop_ub; i++) {
          int sizes_idx_1_tmp;
          sizes_idx_1_tmp = layers.size(0);
          for (int i1{0}; i1 < sizes_idx_1_tmp; i1++) {
            outputLayers[i1 + outputLayers.size(0) * i] = layers[i1 +
              layers.size(0) * i];
          }
        }
      } else {
        int b_sizes_idx_0;
        int i;
        int i1;
        int loop_ub;
        int sizes_idx_0;
        int sizes_idx_1_tmp;
        short b_sizes_idx_1_tmp;
        ssubs = layers[(layers.size(0) + layers.size(0) * 3) - 1];
        if (layers.size(0) > 1) {
          roughnesses.set_size(layers.size(0));
          roughnesses[0] = subRoughs;
          loop_ub = layers.size(0);
          for (i = 0; i <= loop_ub - 2; i++) {
            roughnesses[i + 1] = layers[i + layers.size(0) * 3];
          }
        } else {
          roughnesses.set_size(1);
          roughnesses[0] = subRoughs;
        }

        if (layers.size(1) < 5) {
          i = 0;
          i1 = 0;
        } else {
          i = 4;
          i1 = layers.size(1);
        }

        sizes_idx_1_tmp = i1 - i;
        if (sizes_idx_1_tmp != 0) {
          b_sizes_idx_1_tmp = static_cast<short>(sizes_idx_1_tmp);
        } else {
          b_sizes_idx_1_tmp = 0;
        }

        b_layers.set_size(layers.size(0), 3);
        loop_ub = layers.size(0);
        for (i1 = 0; i1 < 3; i1++) {
          for (int i2{0}; i2 < loop_ub; i2++) {
            b_layers[i2 + b_layers.size(0) * i1] = layers[i2 + layers.size(0) *
              i1];
          }
        }

        sizes_idx_0 = layers.size(0);
        b_sizes_idx_0 = layers.size(0);
        c_layers.set_size(layers.size(0), sizes_idx_1_tmp);
        for (i1 = 0; i1 < sizes_idx_1_tmp; i1++) {
          loop_ub = layers.size(0);
          for (int i2{0}; i2 < loop_ub; i2++) {
            c_layers[i2 + c_layers.size(0) * i1] = layers[i2 + layers.size(0) *
              (i + i1)];
          }
        }

        sizes_idx_1_tmp = layers.size(0);
        loop_ub = b_sizes_idx_1_tmp;
        outputLayers.set_size(layers.size(0), b_sizes_idx_1_tmp + 4);
        for (i = 0; i < 3; i++) {
          for (i1 = 0; i1 < sizes_idx_0; i1++) {
            outputLayers[i1 + outputLayers.size(0) * i] = b_layers[i1 +
              sizes_idx_0 * i];
          }
        }

        for (i = 0; i < b_sizes_idx_0; i++) {
          outputLayers[i + outputLayers.size(0) * 3] = roughnesses[i];
        }

        for (i = 0; i < loop_ub; i++) {
          for (i1 = 0; i1 < sizes_idx_1_tmp; i1++) {
            outputLayers[i1 + outputLayers.size(0) * (i + 4)] = c_layers[i1 +
              sizes_idx_1_tmp * i];
          }
        }
      }
    } else {
      outputLayers.set_size(0, 4);
    }

    return ssubs;
  }
}

// End of code generation (groupLayersMod.cpp)
