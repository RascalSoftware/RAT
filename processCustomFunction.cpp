//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// processCustomFunction.cpp
//
// Code generation for function 'processCustomFunction'
//

// Include files
#include "processCustomFunction.h"
#include "RATMain_data.h"
#include "RATMain_types.h"
#include "applyHydration.h"
#include "callCppFunction.h"
#include "rt_nonfinite.h"
#include "str2double.h"
#include "coderException.hpp"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace normalTF
  {
    namespace customLayers
    {
      void processCustomFunction(const ::coder::array<double, 2U>
        &contrastBulkIns, const ::coder::array<double, 2U> &contrastBulkOuts,
        const ::coder::array<double, 2U> &bulkInArray, const ::coder::array<
        double, 2U> &bulkOutArray, const ::coder::array<double, 2U> &cCustFiles,
        double numberOfContrasts, const ::coder::array<cell_wrap_10, 2U>
        &customFiles, const ::coder::array<double, 2U> &params, boolean_T
        useImaginary, ::coder::array<cell_wrap_9, 2U> &resampledLayers, ::coder::
        array<double, 1U> &subRoughs)
      {
        ::coder::array<double, 2U> b_thisContrastLayers;
        ::coder::array<double, 2U> bulkOuts;
        ::coder::array<double, 2U> d_thisContrastLayers;
        ::coder::array<double, 2U> thisContrastLayers;
        int i;
        int i1;
        int loop_ub;

        //  Top-level function for processing custom layers for all the
        //  contrasts.
        i = static_cast<int>(numberOfContrasts);
        subRoughs.set_size(i);
        bulkOuts.set_size(1, contrastBulkOuts.size(1));
        loop_ub = contrastBulkOuts.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          bulkOuts[i1] = bulkOutArray[static_cast<int>(contrastBulkOuts[i1]) - 1];
        }

        resampledLayers.set_size(i, 1);
        for (int b_i{0}; b_i < i; b_i++) {
          creal_T x;
          double d;
          int iv[2];
          int i2;
          int result;

          //  TODO - the ambition is for parfor here, but would fail for Matlab and Python CM's..
          //  Choose which custom file is associated with this contrast
          //  Find values of 'bulkIn' and 'bulkOut' for this
          //  contrast
          //  typeDef
          d = cCustFiles[b_i];
          iv[0] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                    static_cast<int>(d) - 1].f1)->size())[0];
          iv[1] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                    static_cast<int>(d) - 1].f1)->size())[1];
          x = coder::internal::str2double((const char *)((::coder::array<char,
            2U> *)&customFiles[static_cast<int>(d) - 1].f1)->data(), iv);
          if (std::isnan(x.re) || std::isnan(x.im)) {
            char b_cv[22];

            //  Excecute a custom model function in the base Matlab workspace.
            //  Calling matlab from other languages should be implemented in their wrapper
            //  Ensures a proper exception is thrown in the generated C++ code.
            //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
            //  and other parameters if message is a formatspec.
            //
            //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
            //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
            for (i1 = 0; i1 < 22; i1++) {
              b_cv[i1] = cv1[i1];
            }

            coderException(0.0, &b_cv[0]);
          } else {
            iv[0] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                      static_cast<int>(d) - 1].f1)->size())[0];
            iv[1] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                      static_cast<int>(d) - 1].f1)->size())[1];
            subRoughs[b_i] = callCppFunction((const char *)((::coder::array<char,
              2U> *)&customFiles[static_cast<int>(d) - 1].f1)->data(), iv,
              params, bulkInArray[static_cast<int>(contrastBulkIns[b_i]) - 1],
              bulkOuts, (static_cast<double>(b_i) + 1.0) - 1.0,
              thisContrastLayers);
          }

          //  If SLD is real, add dummy imaginary column
          if (!useImaginary) {
            int c_thisContrastLayers;
            int sizes_idx_1;
            signed char b_input_sizes_idx_1;
            signed char input_sizes_idx_1;
            boolean_T empty_non_axis_sizes;
            if (thisContrastLayers.size(1) < 3) {
              i1 = 0;
              i2 = 0;
            } else {
              i1 = 2;
              i2 = thisContrastLayers.size(1);
            }

            if (thisContrastLayers.size(0) != 0) {
              result = thisContrastLayers.size(0);
            } else if (static_cast<short>(thisContrastLayers.size(0)) != 0) {
              result = static_cast<short>(thisContrastLayers.size(0));
            } else {
              result = 0;
            }

            empty_non_axis_sizes = (result == 0);
            if (empty_non_axis_sizes || (thisContrastLayers.size(0) != 0)) {
              input_sizes_idx_1 = 2;
            } else {
              input_sizes_idx_1 = 0;
            }

            if (empty_non_axis_sizes || (static_cast<short>
                 (thisContrastLayers.size(0)) != 0)) {
              b_input_sizes_idx_1 = 1;
            } else {
              b_input_sizes_idx_1 = 0;
            }

            if (empty_non_axis_sizes || ((thisContrastLayers.size(0) != 0) &&
                 (i2 - i1 != 0))) {
              sizes_idx_1 = i2 - i1;
            } else {
              sizes_idx_1 = 0;
            }

            c_thisContrastLayers = thisContrastLayers.size(0);
            d_thisContrastLayers.set_size(thisContrastLayers.size(0), 2);
            for (int i3{0}; i3 < 2; i3++) {
              for (loop_ub = 0; loop_ub < c_thisContrastLayers; loop_ub++) {
                d_thisContrastLayers[loop_ub + d_thisContrastLayers.size(0) * i3]
                  = thisContrastLayers[loop_ub + thisContrastLayers.size(0) * i3];
              }
            }

            c_thisContrastLayers = thisContrastLayers.size(0);
            loop_ub = i2 - i1;
            b_thisContrastLayers.set_size(thisContrastLayers.size(0), loop_ub);
            for (i2 = 0; i2 < loop_ub; i2++) {
              for (int i3{0}; i3 < c_thisContrastLayers; i3++) {
                b_thisContrastLayers[i3 + b_thisContrastLayers.size(0) * i2] =
                  thisContrastLayers[i3 + thisContrastLayers.size(0) * (i1 + i2)];
              }
            }

            thisContrastLayers.set_size(result, (input_sizes_idx_1 +
              b_input_sizes_idx_1) + sizes_idx_1);
            loop_ub = input_sizes_idx_1;
            for (i1 = 0; i1 < loop_ub; i1++) {
              for (i2 = 0; i2 < result; i2++) {
                thisContrastLayers[i2 + thisContrastLayers.size(0) * i1] =
                  d_thisContrastLayers[i2 + result * i1];
              }
            }

            loop_ub = b_input_sizes_idx_1;
            for (i1 = 0; i1 < loop_ub; i1++) {
              for (i2 = 0; i2 < result; i2++) {
                thisContrastLayers[i2 + thisContrastLayers.size(0) *
                  input_sizes_idx_1] = 0.0;
              }
            }

            for (i1 = 0; i1 < sizes_idx_1; i1++) {
              for (i2 = 0; i2 < result; i2++) {
                thisContrastLayers[i2 + thisContrastLayers.size(0) * ((i1 +
                  input_sizes_idx_1) + b_input_sizes_idx_1)] =
                  b_thisContrastLayers[i2 + result * i1];
              }
            }
          }

          //  If the output layers has 6 columns, then we need to do
          //  the hydration correction (the user has not done it in the
          //  custom function).
          b_thisContrastLayers.set_size(thisContrastLayers.size(0),
            thisContrastLayers.size(1));
          loop_ub = thisContrastLayers.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            result = thisContrastLayers.size(0);
            for (i2 = 0; i2 < result; i2++) {
              b_thisContrastLayers[i2 + b_thisContrastLayers.size(0) * i1] =
                thisContrastLayers[i2 + thisContrastLayers.size(0) * i1];
            }
          }

          applyHydration(b_thisContrastLayers, bulkInArray[static_cast<int>
                         (contrastBulkIns[b_i]) - 1], bulkOuts[b_i]);
          resampledLayers[b_i].f1.set_size(b_thisContrastLayers.size(0),
            b_thisContrastLayers.size(1));
          loop_ub = b_thisContrastLayers.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            result = b_thisContrastLayers.size(0);
            for (i2 = 0; i2 < result; i2++) {
              resampledLayers[b_i].f1[i2 + resampledLayers[b_i].f1.size(0) * i1]
                = b_thisContrastLayers[i2 + b_thisContrastLayers.size(0) * i1];
            }
          }
        }
      }
    }
  }
}

// End of code generation (processCustomFunction.cpp)
