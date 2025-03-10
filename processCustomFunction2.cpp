//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// processCustomFunction2.cpp
//
// Code generation for function 'processCustomFunction2'
//

// Include files
#include "processCustomFunction2.h"
#include "RATMain_data.h"
#include "RATMain_types.h"
#include "applyHydrationImag.h"
#include "applyHydrationReal.h"
#include "callCppFunction.h"
#include "rt_nonfinite.h"
#include "str2double.h"
#include "coderException.hpp"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace domainsTF
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
        ::coder::array<double, 2U> b_thisContrastLayers1;
        ::coder::array<double, 2U> bulkOuts;
        ::coder::array<double, 2U> thisContrastLayers1;
        int i;
        int loop_ub;

        //  Top-level function for processing custom layers for all the
        //  contrasts.
        i = static_cast<int>(numberOfContrasts);
        subRoughs.set_size(i);
        bulkOuts.set_size(1, contrastBulkOuts.size(1));
        loop_ub = contrastBulkOuts.size(1);
        for (int i1{0}; i1 < loop_ub; i1++) {
          bulkOuts[i1] = bulkOutArray[static_cast<int>(contrastBulkOuts[i1]) - 1];
        }

        resampledLayers.set_size(i, 2);
        for (int b_i{0}; b_i < i; b_i++) {
          creal_T x;
          double d;
          int iv[2];
          int b_loop_ub;

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
            for (int i1{0}; i1 < 22; i1++) {
              b_cv[i1] = cv1[i1];
            }

            coderException(0.0, &b_cv[0]);
          } else {
            double d1;
            d1 = bulkInArray[static_cast<int>(contrastBulkIns[b_i]) - 1];
            iv[0] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                      static_cast<int>(d) - 1].f1)->size())[0];
            iv[1] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                      static_cast<int>(d) - 1].f1)->size())[1];
            subRoughs[b_i] = b_callCppFunction((const char *)((::coder::array<
              char, 2U> *)&customFiles[static_cast<int>(d) - 1].f1)->data(), iv,
              params, d1, bulkOuts, (static_cast<double>(b_i) + 1.0) - 1.0,
              thisContrastLayers1);
            loop_ub = thisContrastLayers1.size(1);
            b_thisContrastLayers1.set_size(thisContrastLayers1.size(0),
              thisContrastLayers1.size(1));
            for (int i1{0}; i1 < loop_ub; i1++) {
              b_loop_ub = thisContrastLayers1.size(0);
              for (int i2{0}; i2 < b_loop_ub; i2++) {
                b_thisContrastLayers1[i2 + b_thisContrastLayers1.size(0) * i1] =
                  thisContrastLayers1[i2 + thisContrastLayers1.size(0) * i1];
              }
            }

            iv[0] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                      static_cast<int>(cCustFiles[b_i]) - 1].f1)->size())[0];
            iv[1] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                      static_cast<int>(cCustFiles[b_i]) - 1].f1)->size())[1];
            c_callCppFunction((const char *)((::coder::array<char, 2U> *)
              &customFiles[static_cast<int>(cCustFiles[b_i]) - 1].f1)->data(),
                              iv, params, d1, bulkOuts, (static_cast<double>(b_i)
              + 1.0) - 1.0, thisContrastLayers1);
          }

          //  If the output layers has 5 columns, then we need to do
          //  the hydration correction (the user has not done it in the
          //  custom function).
          if (!useImaginary) {
            d = bulkInArray[static_cast<int>(contrastBulkIns[b_i]) - 1];
            applyHydrationReal(b_thisContrastLayers1, d, bulkOuts[b_i]);
            applyHydrationReal(thisContrastLayers1, d, bulkOuts[b_i]);
          } else {
            d = bulkInArray[static_cast<int>(contrastBulkIns[b_i]) - 1];
            applyHydrationImag(b_thisContrastLayers1, d, bulkOuts[b_i]);
            applyHydrationImag(thisContrastLayers1, d, bulkOuts[b_i]);
          }

          resampledLayers[b_i].f1.set_size(b_thisContrastLayers1.size(0),
            b_thisContrastLayers1.size(1));
          loop_ub = b_thisContrastLayers1.size(1);
          for (int i1{0}; i1 < loop_ub; i1++) {
            b_loop_ub = b_thisContrastLayers1.size(0);
            for (int i2{0}; i2 < b_loop_ub; i2++) {
              resampledLayers[b_i].f1[i2 + resampledLayers[b_i].f1.size(0) * i1]
                = b_thisContrastLayers1[i2 + b_thisContrastLayers1.size(0) * i1];
            }
          }

          loop_ub = thisContrastLayers1.size(1);
          resampledLayers[b_i + resampledLayers.size(0)].f1.set_size
            (thisContrastLayers1.size(0), thisContrastLayers1.size(1));
          for (int i1{0}; i1 < loop_ub; i1++) {
            b_loop_ub = thisContrastLayers1.size(0);
            for (int i2{0}; i2 < b_loop_ub; i2++) {
              resampledLayers[b_i + resampledLayers.size(0)].f1[i2 +
                resampledLayers[b_i + resampledLayers.size(0)].f1.size(0) * i1] =
                thisContrastLayers1[i2 + thisContrastLayers1.size(0) * i1];
            }
          }
        }
      }
    }
  }
}

// End of code generation (processCustomFunction2.cpp)
