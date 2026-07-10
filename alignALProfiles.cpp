//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// alignALProfiles.cpp
//
// Code generation for function 'alignALProfiles'
//

// Include files
#include "alignALProfiles.h"
#include "RATMain_types.h"
#include "any1.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "sum.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void alignALProfiles(const char geometry_data[], const int geometry_size[2],
                       const char modelType_data[], const int modelType_size[2],
                       ::coder::array<cell_wrap_7, 2U> &sldProfiles, ::coder::
                       array<cell_wrap_9, 2U> &resampledLayers)
  {
    ::coder::array<double, 2U> b_maxX;
    ::coder::array<double, 2U> b_maxXValue;
    ::coder::array<double, 2U> lengths;
    ::coder::array<double, 1U> b_resampledLayers;
    ::coder::array<double, 1U> maxX;
    int iindx;

    //  Aligns the A/L SLD profiles so that the substrates line up by padding the
    //  start of any shorter than the longest profile. Also adjusts resampled
    //  layers and prediction interval slds as necessary.
    //
    //  Parameters
    //  ----------
    //  geometry : geometryOptions
    //     The geometry.
    //  modelType : modelTypes
    //     The model type.
    //  sldProfiles : cell
    //     The sld profiles.
    //  resampledLayers : cell
    //     The resampled layers.
    //  pIntervals : cell
    //     The slds in the prediction intervals.
    //
    //  Returns
    //  -------
    //  sldProfiles : cell
    //     The sld profiles, adjusted if necessary.
    //  resampledLayers : cell
    //     The resampled layers, adjusted if necessary.
    //  pIntervals : cell
    //     The slds in the prediction intervals, adjusted if necessary.
    if (coder::internal::u_strcmp(geometry_data, geometry_size) && (!coder::
         internal::l_strcmp(modelType_data, modelType_size))) {
      double maxLen;
      double maxXValue;
      int i;
      int loop_ub;
      unsigned int unnamed_idx_0;
      unsigned int unnamed_idx_1;

      //  Find the length of the longest profile.
      unnamed_idx_0 = static_cast<unsigned int>(sldProfiles.size(0));
      unnamed_idx_1 = static_cast<unsigned int>(sldProfiles.size(1));
      lengths.set_size(static_cast<int>(unnamed_idx_0), static_cast<int>
                       (unnamed_idx_1));
      loop_ub = static_cast<int>(unnamed_idx_1);
      for (i = 0; i < loop_ub; i++) {
        iindx = static_cast<int>(unnamed_idx_0);
        for (int i1{0}; i1 < iindx; i1++) {
          lengths[i1 + lengths.size(0) * i] = 0.0;
        }
      }

      i = sldProfiles.size(0) * sldProfiles.size(1);
      for (int b_i{0}; b_i < i; b_i++) {
        lengths[b_i] = sldProfiles[b_i].f1.size(0);
      }

      //  Get max length and its index
      maxLen = coder::internal::maximum(lengths, iindx);
      maxXValue = sldProfiles[iindx - 1].f1[sldProfiles[iindx - 1].f1.size(0) -
        1];

      //  Get the longest profile...
      loop_ub = sldProfiles[iindx - 1].f1.size(0);
      maxX.set_size(loop_ub);
      for (int i1{0}; i1 < loop_ub; i1++) {
        maxX[i1] = sldProfiles[iindx - 1].f1[i1];
      }

      //  Pad the start of any profiles that are shorter than this
      for (int b_i{0}; b_i < i; b_i++) {
        if (sldProfiles[b_i].f1.size(0) < maxLen) {
          double diffLen;
          int input_sizes_idx_0;
          diffLen = maxLen - static_cast<double>(sldProfiles[b_i].f1.size(0));
          input_sizes_idx_0 = sldProfiles[b_i].f1.size(0) - 1;
          loop_ub = maxX.size(0);
          b_maxX.set_size(maxX.size(0), 2);
          for (int i1{0}; i1 < loop_ub; i1++) {
            b_maxX[i1] = maxX[i1];
          }

          iindx = static_cast<int>(diffLen);
          for (int i1{0}; i1 < iindx; i1++) {
            b_maxX[i1 + b_maxX.size(0)] = 0.0;
          }

          for (int i1{0}; i1 <= input_sizes_idx_0; i1++) {
            b_maxX[(i1 + static_cast<int>(diffLen)) + b_maxX.size(0)] =
              sldProfiles[b_i].f1[i1 + sldProfiles[b_i].f1.size(0)];
          }

          sldProfiles[b_i].f1.set_size(b_maxX.size(0), 2);
          loop_ub = b_maxX.size(0);
          for (int i1{0}; i1 < 2; i1++) {
            for (iindx = 0; iindx < loop_ub; iindx++) {
              sldProfiles[b_i].f1[iindx + sldProfiles[b_i].f1.size(0) * i1] =
                b_maxX[iindx + b_maxX.size(0) * i1];
            }
          }

          //  For resampled layers, the pad is just one big layer at the start
          if (coder::any(resampledLayers[b_i].f1)) {
            //  not all zeros
            if ((resampledLayers[b_i].f1.size(0) != 0) && (resampledLayers[b_i].
                 f1.size(1) != 0)) {
              input_sizes_idx_0 = resampledLayers[b_i].f1.size(0);
            } else {
              input_sizes_idx_0 = 0;
            }

            iindx = resampledLayers[b_i].f1.size(0);
            b_resampledLayers.set_size(iindx);
            for (int i1{0}; i1 < iindx; i1++) {
              b_resampledLayers[i1] = resampledLayers[b_i].f1[i1];
            }

            b_maxXValue.set_size(input_sizes_idx_0 + 1, 3);
            b_maxXValue[0] = maxXValue - coder::sum(b_resampledLayers);
            b_maxXValue[b_maxXValue.size(0)] = 0.0;
            b_maxXValue[b_maxXValue.size(0) * 2] = 0.0;
            for (int i1{0}; i1 < 3; i1++) {
              for (iindx = 0; iindx < input_sizes_idx_0; iindx++) {
                b_maxXValue[(iindx + b_maxXValue.size(0) * i1) + 1] =
                  resampledLayers[b_i].f1[iindx + input_sizes_idx_0 * i1];
              }
            }

            resampledLayers[b_i].f1.set_size(b_maxXValue.size(0), 3);
            loop_ub = b_maxXValue.size(0);
            for (int i1{0}; i1 < 3; i1++) {
              for (iindx = 0; iindx < loop_ub; iindx++) {
                resampledLayers[b_i].f1[iindx + resampledLayers[b_i].f1.size(0) *
                  i1] = b_maxXValue[iindx + b_maxXValue.size(0) * i1];
              }
            }
          }
        }
      }
    }
  }
}

// End of code generation (alignALProfiles.cpp)
