//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// simplexIntrafun.cpp
//
// Code generation for function 'simplexIntrafun'
//

// Include files
#include "simplexIntrafun.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "reflectivityCalculation.h"
#include "rt_nonfinite.h"
#include "simplexXTransform.h"
#include "unpackParams.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void simplexIntrafun(const ::coder::array<real_T, 1U> &x, d_struct_T
                       *problemStruct, const cell_12 *problemCells, const
                       struct1_T *problemLimits, const struct2_T *controls,
                       const n_struct_T *params, real_T *fval, e_struct_T
                       *result)
  {
    //  transform variables, then call original function
    simplexXTransform(x, params->LB, params->UB, params->BoundClass,
                      problemStruct->fitParams);

    // Unpck the params..
    unpackParams(problemStruct, controls->checks.fitParam,
                 controls->checks.fitBackgroundParam,
                 controls->checks.fitQzshift, controls->checks.fitScalefactor,
                 controls->checks.fitBulkIn, controls->checks.fitBulkOut,
                 controls->checks.fitResolutionParam,
                 controls->checks.fitDomainRatio);
    reflectivityCalculation(problemStruct, problemCells, problemLimits, controls,
      result);
    *fval = result->calculationResults.sumChi;
  }
}

// End of code generation (simplexIntrafun.cpp)
