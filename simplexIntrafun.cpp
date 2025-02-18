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
#include "coder_bounded_array.h"
#include <algorithm>

// Function Definitions
namespace RAT
{
  void simplexIntrafun(const ::coder::array<real_T, 1U> &x, e_struct_T
                       *problemStruct, const char_T controls_parallel_data[],
                       const int32_T controls_parallel_size[2], real_T
                       controls_resampleMinAngle, real_T
                       controls_resampleNPoints, boolean_T
                       controls_calcSldDuringFit, const ::coder::array<real_T,
                       1U> &params_LB, const ::coder::array<real_T, 1U>
                       &params_UB, const ::coder::array<real_T, 1U>
                       &params_BoundClass, real_T *fval, struct5_T *result)
  {
    ::coder::array<real_T, 1U> xtrans;
    struct4_T expl_temp;
    int32_T loop_ub;

    //  transform variables, then call original function
    simplexXTransform(x, params_LB, params_UB, params_BoundClass, xtrans);

    // Unpck the params..
    problemStruct->fitParams.set_size(1, xtrans.size(0));
    loop_ub = xtrans.size(0);
    for (int32_T i{0}; i < loop_ub; i++) {
      problemStruct->fitParams[i] = xtrans[i];
    }

    unpackParams(problemStruct);
    expl_temp.calcSldDuringFit = controls_calcSldDuringFit;
    expl_temp.resampleNPoints = controls_resampleNPoints;
    expl_temp.resampleMinAngle = controls_resampleMinAngle;
    expl_temp.parallel.size[0] = 1;
    expl_temp.parallel.size[1] = controls_parallel_size[1];
    loop_ub = controls_parallel_size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&controls_parallel_data[0], &controls_parallel_data[loop_ub],
                &expl_temp.parallel.data[0]);
    }

    b_reflectivityCalculation(problemStruct, &expl_temp, result);
    *fval = result->calculationResults.sumChi;
  }
}

// End of code generation (simplexIntrafun.cpp)
