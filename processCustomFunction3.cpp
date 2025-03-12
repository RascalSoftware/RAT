//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// processCustomFunction3.cpp
//
// Code generation for function 'processCustomFunction3'
//

// Include files
#include "processCustomFunction3.h"
#include "RATMain_data.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
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
    namespace customXY
    {
      void processCustomFunction(const ::coder::array<double, 2U>
        &contrastBulkIns, const ::coder::array<double, 2U> &contrastBulkOuts,
        const ::coder::array<double, 2U> &bulkInArray, const ::coder::array<
        double, 2U> &bulkOutArray, const ::coder::array<double, 2U> &cCustFiles,
        double numberOfContrasts, const ::coder::array<cell_wrap_10, 2U>
        &customFiles, const ::coder::array<double, 2U> &params, boolean_T
        useImaginary, ::coder::array<cell_wrap_33, 2U> &slds, ::coder::array<
        double, 1U> &subRoughs)
      {
        ::coder::array<double, 2U> bulkOuts;
        ::coder::array<double, 2U> sld1;
        ::coder::array<double, 2U> sld2;
        int i;
        int loop_ub;

        //  Top-level function for processing custom XY profiles for all the
        //  contrasts.
        i = static_cast<int>(numberOfContrasts);
        subRoughs.set_size(i);

        //  3 columns to allow for potential imaginary curve
        bulkOuts.set_size(1, contrastBulkOuts.size(1));
        loop_ub = contrastBulkOuts.size(1);
        for (int i1{0}; i1 < loop_ub; i1++) {
          bulkOuts[i1] = bulkOutArray[static_cast<int>(contrastBulkOuts[i1]) - 1];
        }

        slds.set_size(i, 2);
        for (int b_i{0}; b_i < i; b_i++) {
          creal_T x;
          double d;
          int iv[2];

          //  TODO - the ambition is for parfor here, but would fail for Matlab and Python CM's..
          //  Choose which custom file is associated with this contrast
          //  Find values of 'bulkIn' and 'bulkOut' for this contrast...
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
              params, d1, bulkOuts, (static_cast<double>(b_i) + 1.0) - 1.0, sld1);
            iv[0] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                      static_cast<int>(d) - 1].f1)->size())[0];
            iv[1] = (*(int (*)[2])((::coder::array<char, 2U> *)&customFiles[
                      static_cast<int>(d) - 1].f1)->size())[1];
            c_callCppFunction((const char *)((::coder::array<char, 2U> *)
              &customFiles[static_cast<int>(d) - 1].f1)->data(), iv, params, d1,
                              bulkOuts, (static_cast<double>(b_i) + 1.0) - 1.0,
                              sld2);
          }

          //  If SLD is real, add dummy imaginary column
          if (!useImaginary) {
            int b_loop_ub;
            int result;
            signed char i3;
            boolean_T b;
            boolean_T empty_non_axis_sizes;
            b = ((sld1.size(0) != 0) && (sld1.size(1) != 0));
            if (b) {
              result = sld1.size(0);
            } else if (sld1.size(0) != 0) {
              result = sld1.size(0);
            } else {
              result = sld1.size(0);
            }

            empty_non_axis_sizes = (result == 0);
            if (empty_non_axis_sizes || b) {
              loop_ub = sld1.size(1);
            } else {
              loop_ub = 0;
            }

            if (empty_non_axis_sizes || (sld1.size(0) != 0)) {
              i3 = 1;
            } else {
              i3 = 0;
            }

            slds[b_i].f1.set_size(result, loop_ub + i3);
            for (int i1{0}; i1 < loop_ub; i1++) {
              for (int i2{0}; i2 < result; i2++) {
                slds[b_i].f1[i2 + slds[b_i].f1.size(0) * i1] = sld1[i2 + result *
                  i1];
              }
            }

            b_loop_ub = i3;
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              for (int i2{0}; i2 < result; i2++) {
                slds[b_i].f1[i2 + slds[b_i].f1.size(0) * loop_ub] = 0.0;
              }
            }

            b = ((sld2.size(0) != 0) && (sld2.size(1) != 0));
            if (b) {
              result = sld2.size(0);
            } else if (sld2.size(0) != 0) {
              result = sld2.size(0);
            } else {
              result = sld2.size(0);
            }

            empty_non_axis_sizes = (result == 0);
            if (empty_non_axis_sizes || b) {
              loop_ub = sld2.size(1);
            } else {
              loop_ub = 0;
            }

            if (empty_non_axis_sizes || (sld2.size(0) != 0)) {
              b_loop_ub = 1;
            } else {
              b_loop_ub = 0;
            }

            slds[b_i + slds.size(0)].f1.set_size(result, loop_ub + b_loop_ub);
            for (int i1{0}; i1 < loop_ub; i1++) {
              for (int i2{0}; i2 < result; i2++) {
                slds[b_i + slds.size(0)].f1[i2 + slds[b_i + slds.size(0)].
                  f1.size(0) * i1] = sld2[i2 + result * i1];
              }
            }

            for (int i1{0}; i1 < b_loop_ub; i1++) {
              for (int i2{0}; i2 < result; i2++) {
                slds[b_i + slds.size(0)].f1[i2 + slds[b_i + slds.size(0)].
                  f1.size(0) * loop_ub] = 0.0;
              }
            }
          } else {
            int b_loop_ub;
            loop_ub = sld1.size(1);
            slds[b_i].f1.set_size(sld1.size(0), sld1.size(1));
            for (int i1{0}; i1 < loop_ub; i1++) {
              b_loop_ub = sld1.size(0);
              for (int i2{0}; i2 < b_loop_ub; i2++) {
                slds[b_i].f1[i2 + slds[b_i].f1.size(0) * i1] = sld1[i2 +
                  sld1.size(0) * i1];
              }
            }

            loop_ub = sld2.size(1);
            slds[b_i + slds.size(0)].f1.set_size(sld2.size(0), sld2.size(1));
            for (int i1{0}; i1 < loop_ub; i1++) {
              b_loop_ub = sld2.size(0);
              for (int i2{0}; i2 < b_loop_ub; i2++) {
                slds[b_i + slds.size(0)].f1[i2 + slds[b_i + slds.size(0)].
                  f1.size(0) * i1] = sld2[i2 + sld2.size(0) * i1];
              }
            }
          }
        }
      }
    }
  }
}

// End of code generation (processCustomFunction3.cpp)
