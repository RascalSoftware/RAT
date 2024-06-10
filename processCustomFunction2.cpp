//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// processCustomFunction2.cpp
//
// Code generation for function 'processCustomFunction2'
//

// Include files
#include "processCustomFunction2.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "applyHydrationImag.h"
#include "applyHydrationReal.h"
#include "callCppFunction.h"
#include "rt_nonfinite.h"
#include "str2double.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace domainsTF
  {
    namespace customLayers
    {
      void processCustomFunction(const ::coder::array<real_T, 2U>
        &contrastBulkIns, const ::coder::array<real_T, 2U> &contrastBulkOuts,
        const ::coder::array<real_T, 2U> &bulkInArray, const ::coder::array<
        real_T, 2U> &bulkOutArray, const ::coder::array<real_T, 2U> &cCustFiles,
        real_T numberOfContrasts, const ::coder::array<cell_wrap_1, 2U>
        &customFiles, const ::coder::array<real_T, 2U> &params, boolean_T
        useImaginary, ::coder::array<cell_wrap_39, 2U> &resampledLayers, ::coder::
        array<real_T, 1U> &subRoughs)
      {
        ::coder::array<real_T, 2U> b_bulkOuts;
        ::coder::array<real_T, 2U> b_params;
        ::coder::array<real_T, 2U> b_thisContrastLayers1;
        ::coder::array<real_T, 2U> bulkOuts;
        ::coder::array<real_T, 2U> thisContrastLayers1;
        ::coder::array<real_T, 2U> thisContrastLayers2;
        real_T a__2;
        int32_T iv[2];
        int32_T i;
        int32_T i1;
        int32_T loop_ub;

        //  Top-level function for processing custom layers for all the
        //  contrasts.
        //  Do some pre-definitions to keep the compiler happy...
        // totNumCalcs = numberOfContrasts * 2;
        i = static_cast<int32_T>(numberOfContrasts);
        subRoughs.set_size(i);
        bulkOuts.set_size(1, contrastBulkOuts.size(1));
        loop_ub = contrastBulkOuts.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          bulkOuts[i1] = bulkOutArray[static_cast<int32_T>(contrastBulkOuts[i1])
            - 1];
        }

        resampledLayers.set_size(i, 2);
        for (int32_T b_i{0}; b_i < i; b_i++) {
          creal_T x;
          real_T d;
          int32_T b_loop_ub;
          int32_T i2;

          //  Choose which custom file is associated with this contrast
          //  Find values of 'bulkIn' and 'bulkOut' for this
          //  contrast...
          //  typeDef
          //  typeDef
          d = cCustFiles[b_i];
          iv[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)&customFiles[
                    static_cast<int32_T>(d) - 1].f1)->size())[0];
          iv[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)&customFiles[
                    static_cast<int32_T>(d) - 1].f1)->size())[1];
          x = coder::str2double((const char_T *)((::coder::array<char_T, 2U> *)
            &customFiles[static_cast<int32_T>(d) - 1].f1)->data(), iv);
          if ((!std::isnan(x.re)) && (!std::isnan(x.im))) {
            b_params.set_size(1, params.size(1));
            loop_ub = params.size(1) - 1;
            for (i1 = 0; i1 <= loop_ub; i1++) {
              b_params[i1] = params[i1];
            }

            b_bulkOuts.set_size(1, bulkOuts.size(1));
            loop_ub = bulkOuts.size(1) - 1;
            for (i1 = 0; i1 <= loop_ub; i1++) {
              b_bulkOuts[i1] = bulkOuts[i1];
            }

            iv[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                      &customFiles[static_cast<int32_T>(d) - 1].f1)->size())[0];
            iv[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                      &customFiles[static_cast<int32_T>(d) - 1].f1)->size())[1];
            b_callCppFunction((const char_T *)((::coder::array<char_T, 2U> *)
              &customFiles[static_cast<int32_T>(d) - 1].f1)->data(), iv,
                              b_params, bulkInArray[static_cast<int32_T>
                              (contrastBulkIns[b_i]) - 1], b_bulkOuts, (
              static_cast<real_T>(b_i) + 1.0) - 1.0, b_thisContrastLayers1,
                              &subRoughs[b_i]);
            loop_ub = b_thisContrastLayers1.size(1);
            thisContrastLayers1.set_size(b_thisContrastLayers1.size(0),
              b_thisContrastLayers1.size(1));
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_loop_ub = b_thisContrastLayers1.size(0);
              for (i2 = 0; i2 < b_loop_ub; i2++) {
                thisContrastLayers1[i2 + thisContrastLayers1.size(0) * i1] =
                  b_thisContrastLayers1[i2 + b_thisContrastLayers1.size(0) * i1];
              }
            }

            b_params.set_size(1, params.size(1));
            loop_ub = params.size(1) - 1;
            for (i1 = 0; i1 <= loop_ub; i1++) {
              b_params[i1] = params[i1];
            }

            b_bulkOuts.set_size(1, bulkOuts.size(1));
            loop_ub = bulkOuts.size(1) - 1;
            for (i1 = 0; i1 <= loop_ub; i1++) {
              b_bulkOuts[i1] = bulkOuts[i1];
            }

            iv[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                      &customFiles[static_cast<int32_T>(cCustFiles[b_i]) - 1].f1)
                     ->size())[0];
            iv[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                      &customFiles[static_cast<int32_T>(cCustFiles[b_i]) - 1].f1)
                     ->size())[1];
            c_callCppFunction((const char_T *)((::coder::array<char_T, 2U> *)
              &customFiles[static_cast<int32_T>(cCustFiles[b_i]) - 1].f1)->data(),
                              iv, b_params, bulkInArray[static_cast<int32_T>
                              (contrastBulkIns[b_i]) - 1], b_bulkOuts, (
              static_cast<real_T>(b_i) + 1.0) - 1.0, b_thisContrastLayers1,
                              &a__2);
            loop_ub = b_thisContrastLayers1.size(1);
            thisContrastLayers2.set_size(b_thisContrastLayers1.size(0),
              b_thisContrastLayers1.size(1));
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_loop_ub = b_thisContrastLayers1.size(0);
              for (i2 = 0; i2 < b_loop_ub; i2++) {
                thisContrastLayers2[i2 + thisContrastLayers2.size(0) * i1] =
                  b_thisContrastLayers1[i2 + b_thisContrastLayers1.size(0) * i1];
              }
            }
          }

          //  If the output layers has 5 columns, then we need to do
          //  the hydration correction (the user has not done it in the
          //  custom function). Do that here....
          if (!useImaginary) {
            d = contrastBulkIns[b_i];
            applyHydrationReal(thisContrastLayers1, bulkInArray
                               [static_cast<int32_T>(d) - 1], bulkOuts[b_i]);
            applyHydrationReal(thisContrastLayers2, bulkInArray
                               [static_cast<int32_T>(d) - 1], bulkOuts[b_i]);
          } else {
            d = contrastBulkIns[b_i];
            applyHydrationImag(thisContrastLayers1, bulkInArray
                               [static_cast<int32_T>(d) - 1], bulkOuts[b_i]);
            applyHydrationImag(thisContrastLayers2, bulkInArray
                               [static_cast<int32_T>(d) - 1], bulkOuts[b_i]);
          }

          resampledLayers[b_i].f1.set_size(thisContrastLayers1.size(0),
            thisContrastLayers1.size(1));
          loop_ub = thisContrastLayers1.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = thisContrastLayers1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              resampledLayers[b_i].f1[i2 + resampledLayers[b_i].f1.size(0) * i1]
                = thisContrastLayers1[i2 + thisContrastLayers1.size(0) * i1];
            }
          }

          resampledLayers[b_i + resampledLayers.size(0)].f1.set_size
            (thisContrastLayers2.size(0), thisContrastLayers2.size(1));
          loop_ub = thisContrastLayers2.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = thisContrastLayers2.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              resampledLayers[b_i + resampledLayers.size(0)].f1[i2 +
                resampledLayers[b_i + resampledLayers.size(0)].f1.size(0) * i1] =
                thisContrastLayers2[i2 + thisContrastLayers2.size(0) * i1];
            }
          }
        }
      }
    }
  }
}

// End of code generation (processCustomFunction2.cpp)
