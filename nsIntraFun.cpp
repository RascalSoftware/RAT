//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// nsIntraFun.cpp
//
// Code generation for function 'nsIntraFun'
//

// Include files
#include "nsIntraFun.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "reflectivityCalculation.h"
#include "rt_nonfinite.h"
#include "unpackParams.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  real_T nsIntraFun(const d_struct_T *data_f1, const struct2_T *data_f2, const
                    cell_11 *data_f4, const ::coder::array<real_T, 2U> &p)
  {
    cell_wrap_9 a__1[6];
    d_struct_T problemStruct;
    e_struct_T b_problemStruct;
    int32_T loop_ub;
    problemStruct = *data_f1;

    //  Removed use of cells....
    problemStruct.fitParams.set_size(1, p.size(1));
    loop_ub = p.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      problemStruct.fitParams[problemStruct.fitParams.size(0) * i] = p[i];
    }

    unpackParams(&problemStruct, data_f2->checks.fitParam,
                 data_f2->checks.fitBackgroundParam, data_f2->checks.fitQzshift,
                 data_f2->checks.fitScalefactor, data_f2->checks.fitBulkIn,
                 data_f2->checks.fitBulkOut, data_f2->checks.fitResolutionParam,
                 data_f2->checks.fitDomainRatio);
    reflectivityCalculation(&problemStruct, data_f4, data_f2, &b_problemStruct,
      a__1);
    return -b_problemStruct.calculations.sumChi / 2.0;
  }

  real_T nsIntraFun(const d_struct_T *data_f1, const struct2_T *data_f2, const
                    cell_11 *data_f4, const ::coder::array<real_T, 1U> &p)
  {
    cell_wrap_9 a__1[6];
    d_struct_T problemStruct;
    e_struct_T b_problemStruct;
    int32_T p_idx_0;
    problemStruct = *data_f1;

    //  Removed use of cells....
    p_idx_0 = p.size(0);
    problemStruct.fitParams.set_size(p.size(0), 1);
    for (int32_T i{0}; i < 1; i++) {
      for (int32_T i1{0}; i1 < p_idx_0; i1++) {
        problemStruct.fitParams[i1] = p[i1];
      }
    }

    unpackParams(&problemStruct, data_f2->checks.fitParam,
                 data_f2->checks.fitBackgroundParam, data_f2->checks.fitQzshift,
                 data_f2->checks.fitScalefactor, data_f2->checks.fitBulkIn,
                 data_f2->checks.fitBulkOut, data_f2->checks.fitResolutionParam,
                 data_f2->checks.fitDomainRatio);
    reflectivityCalculation(&problemStruct, data_f4, data_f2, &b_problemStruct,
      a__1);
    return -b_problemStruct.calculations.sumChi / 2.0;
  }
}

// End of code generation (nsIntraFun.cpp)
