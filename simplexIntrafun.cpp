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
  void simplexIntrafun(const ::coder::array<real_T, 1U> &x, e_struct_T
                       *problemStruct, const ::coder::array<real_T, 2U>
                       &problemLimits_param, const ::coder::array<real_T, 2U>
                       &problemLimits_backgroundParam, const ::coder::array<
                       real_T, 2U> &problemLimits_scalefactor, const ::coder::
                       array<real_T, 2U> &problemLimits_qzshift, const ::coder::
                       array<real_T, 2U> &problemLimits_bulkIn, const ::coder::
                       array<real_T, 2U> &problemLimits_bulkOut, const ::coder::
                       array<real_T, 2U> &problemLimits_resolutionParam, const ::
                       coder::array<real_T, 2U> &problemLimits_domainRatio,
                       const struct3_T *controls, const m_struct_T *params,
                       real_T *fval, f_struct_T *result)
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
    reflectivityCalculation(problemStruct, problemLimits_param,
      problemLimits_backgroundParam, problemLimits_scalefactor,
      problemLimits_qzshift, problemLimits_bulkIn, problemLimits_bulkOut,
      problemLimits_resolutionParam, problemLimits_domainRatio, controls, result);
    *fval = result->calculationResults.sumChi;
  }
}

// End of code generation (simplexIntrafun.cpp)
