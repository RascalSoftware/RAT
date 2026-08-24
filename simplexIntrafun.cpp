//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
  double simplexIntrafun(const ::coder::array<double, 1U> &x, ProblemDefinition
    &problemStruct, const char controls_parallel_data[], const int
    controls_parallel_size[2], double controls_numSimulationPoints, double
    controls_resampleMinAngle, double controls_resampleNPoints, boolean_T
    controls_calcSLD, const ::coder::array<double, 1U> &params_LB, const ::coder::
    array<double, 1U> &params_UB, const ::coder::array<double, 1U>
    &params_BoundClass, b_struct_T &result)
  {
    static Controls expl_temp;
    ::coder::array<double, 1U> xtrans;
    int loop_ub;

    //  Produce a chi-squared fit value at a point for a given problem and controls.
    //
    //  Used as the objective function for Nelder-Mead simplex.
    //
    //  Parameters
    //  ----------
    //  x : vector
    //      The point to evaluate.
    //  problemStruct : struct
    //      The problem struct for calculation.
    //  controls : struct
    //      The controls struct for the calculation.
    //  params : struct
    //      A struct containing parameter fit information.
    //
    //  Returns
    //  -------
    //  fval : float
    //      The chi-squared value at ``x``.
    //  result : struct
    //      The result struct from the reflectivity calculation.
    //  transform variables, then call original function
    simplexXTransform(x, params_LB, params_UB, params_BoundClass, xtrans);

    // Unpck the params..
    problemStruct.fitParams.set_size(1, xtrans.size(0));
    loop_ub = xtrans.size(0);
    for (int i{0}; i < loop_ub; i++) {
      problemStruct.fitParams[i] = xtrans[i];
    }

    unpackParams(problemStruct);
    expl_temp.calcSLD = controls_calcSLD;
    expl_temp.resampleNPoints = controls_resampleNPoints;
    expl_temp.resampleMinAngle = controls_resampleMinAngle;
    expl_temp.numSimulationPoints = controls_numSimulationPoints;
    expl_temp.parallel.size[0] = 1;
    expl_temp.parallel.size[1] = controls_parallel_size[1];
    loop_ub = controls_parallel_size[1];
    if (loop_ub - 1 >= 0) {
      std::copy(&controls_parallel_data[0], &controls_parallel_data[loop_ub],
                &expl_temp.parallel.data[0]);
    }

    b_reflectivityCalculation(problemStruct, &expl_temp, result);
    return result.calculationResults.sumChi;
  }
}

// End of code generation (simplexIntrafun.cpp)
