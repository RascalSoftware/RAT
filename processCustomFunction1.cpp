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

// Function Declarations
namespace RAT
{
  static void cast(const ::coder::array<cell_wrap_40, 1U> &b, ::coder::array<
                   cell_wrap_10, 1U> &c);
}

// Function Definitions
namespace RAT
{
  static void cast(const ::coder::array<cell_wrap_40, 1U> &b, ::coder::array<
                   cell_wrap_10, 1U> &c)
  {
    int32_T i;
    c.set_size(b.size(0));
    i = b.size(0);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = b[i1].f1.size(1);
      c[i1].f1.set_size(b[i1].f1.size(0), b[i1].f1.size(1));
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = b[i1].f1.size(0);
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          c[i1].f1[i3 + c[i1].f1.size(0) * i2] = b[i1].f1[i3 + b[i1].f1.size(0) *
            i2];
        }
      }
    }
  }

  namespace nonPolarisedTF
  {
    namespace customXY
    {
      void processCustomFunction(const ::coder::array<real_T, 2U>
        &contrastBulkIns, const ::coder::array<real_T, 2U> &contrastBulkOuts,
        const ::coder::array<real_T, 2U> &bulkIn, const ::coder::array<real_T,
        2U> &bulkOut, const ::coder::array<real_T, 2U> &cCustFiles, real_T
        numberOfContrasts, const ::coder::array<cell_wrap_1, 2U> &customFiles,
        const ::coder::array<real_T, 2U> &params, ::coder::array<cell_wrap_10,
        1U> &allSLDs, ::coder::array<real_T, 1U> &allRoughs)
      {
        ::coder::array<cell_wrap_40, 1U> tempAllSLDs;
        ::coder::array<real_T, 2U> allBulkOuts;
        ::coder::array<real_T, 2U> b_allBulkOuts;
        ::coder::array<real_T, 2U> b_params;
        ::coder::array<real_T, 2U> r;
        int32_T iv[2];
        int32_T i;
        int32_T i1;
        int32_T loop_ub;

        //  Top-level function for processing custom XY profiles for all the
        //  contrasts.
        //  Do some pre-definitions to keep the compiler happy...
        i = static_cast<int32_T>(numberOfContrasts);
        allRoughs.set_size(i);

        //  3 columns to allow for potential imaginary curve
        allBulkOuts.set_size(1, contrastBulkOuts.size(1));
        loop_ub = contrastBulkOuts.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          allBulkOuts[i1] = bulkOut[static_cast<int32_T>(contrastBulkOuts[i1]) -
            1];
        }

        tempAllSLDs.set_size(i);
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

            b_allBulkOuts.set_size(1, allBulkOuts.size(1));
            loop_ub = allBulkOuts.size(1) - 1;
            for (i1 = 0; i1 <= loop_ub; i1++) {
              b_allBulkOuts[i1] = allBulkOuts[i1];
            }

            iv[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                      &customFiles[static_cast<int32_T>(d) - 1].f1)->size())[0];
            iv[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                      &customFiles[static_cast<int32_T>(d) - 1].f1)->size())[1];
            callCppFunction((const char_T *)((::coder::array<char_T, 2U> *)
              &customFiles[static_cast<int32_T>(d) - 1].f1)->data(), iv,
                            b_params, bulkIn[static_cast<int32_T>
                            (contrastBulkIns[b_i]) - 1], b_allBulkOuts, (
              static_cast<real_T>(b_i) + 1.0) - 1.0, r, &allRoughs[b_i]);
            loop_ub = r.size(1);
            tempAllSLDs[b_i].f1.set_size(r.size(0), r.size(1));
            for (i1 = 0; i1 < loop_ub; i1++) {
              int32_T b_loop_ub;
              b_loop_ub = r.size(0);
              for (int32_T i2{0}; i2 < b_loop_ub; i2++) {
                tempAllSLDs[b_i].f1[i2 + tempAllSLDs[b_i].f1.size(0) * i1] =
                  r[i2 + r.size(0) * i1];
              }
            }
          }
        }

        cast(tempAllSLDs, allSLDs);
      }
    }
  }
}

// End of code generation (processCustomFunction1.cpp)
