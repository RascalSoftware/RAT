//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// processCustomFunction1.cpp
//
// Code generation for function 'processCustomFunction1'
//

// Include files
#include "processCustomFunction1.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "callCppFunction.h"
#include "rt_nonfinite.h"
#include "str2double.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace nonPolarisedTF
  {
    namespace customXY
    {
      void processCustomFunction(const ::coder::array<real_T, 2U>
        &contrastBulkIns, const ::coder::array<real_T, 2U> &contrastBulkOuts,
        const ::coder::array<real_T, 2U> &bulkInArray, const ::coder::array<
        real_T, 2U> &bulkOutArray, const ::coder::array<real_T, 2U> &cCustFiles,
        real_T numberOfContrasts, const ::coder::array<cell_wrap_1, 2U>
        &customFiles, const ::coder::array<real_T, 2U> &params, ::coder::array<
        cell_wrap_56, 1U> &slds, ::coder::array<real_T, 1U> &subRoughs)
      {
        ::coder::array<real_T, 2U> b_bulkOuts;
        ::coder::array<real_T, 2U> b_params;
        ::coder::array<real_T, 2U> bulkOuts;
        ::coder::array<real_T, 2U> r;
        int32_T iv[2];
        int32_T i;
        int32_T i1;
        int32_T loop_ub;

        //  Top-level function for processing custom XY profiles for all the
        //  contrasts.
        //  Do some pre-definitions to keep the compiler happy...
        i = static_cast<int32_T>(numberOfContrasts);
        subRoughs.set_size(i);

        //  3 columns to allow for potential imaginary curve
        bulkOuts.set_size(1, contrastBulkOuts.size(1));
        loop_ub = contrastBulkOuts.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          bulkOuts[i1] = bulkOutArray[static_cast<int32_T>(contrastBulkOuts[i1])
            - 1];
        }

        slds.set_size(i);
        for (int32_T b_i{0}; b_i < i; b_i++) {
          creal_T x;
          real_T d;

          //  TODO - the ambition is for parfor here, but would fail for Matlab and Python CM's..
          //  Choose which custom file is associated with this contrast
          //  Find values of 'bulkIn' and 'bulkOut' for this
          //  contrast...
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
            callCppFunction((const char_T *)((::coder::array<char_T, 2U> *)
              &customFiles[static_cast<int32_T>(d) - 1].f1)->data(), iv,
                            b_params, bulkInArray[static_cast<int32_T>
                            (contrastBulkIns[b_i]) - 1], b_bulkOuts, (
              static_cast<real_T>(b_i) + 1.0) - 1.0, r, &subRoughs[b_i]);
            loop_ub = r.size(1);
            slds[b_i].f1.set_size(r.size(0), r.size(1));
            for (i1 = 0; i1 < loop_ub; i1++) {
              int32_T b_loop_ub;
              b_loop_ub = r.size(0);
              for (int32_T i2{0}; i2 < b_loop_ub; i2++) {
                slds[b_i].f1[i2 + slds[b_i].f1.size(0) * i1] = r[i2 + r.size(0) *
                  i1];
              }
            }
          }
        }
      }
    }
  }
}

// End of code generation (processCustomFunction1.cpp)
