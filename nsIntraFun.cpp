//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
  double nsIntraFun(const ProblemDefinition &data_f1, const Controls &data_f2,
                    const ::coder::array<double, 2U> &p)
  {
    ProblemDefinition problemStruct;
    b_struct_T expl_temp;
    int loop_ub;

    //  Calculate the log-likelihood of a data point during nested sampling.
    //
    //  Parameters
    //  ----------
    //  data : array
    //      The problem struct and controls.
    //  p : array
    //      The point in parameter space to calculate likelihood for.
    problemStruct = data_f1;

    //  Removed use of cells....
    problemStruct.fitParams.set_size(1, p.size(1));
    loop_ub = p.size(1);
    for (int i{0}; i < loop_ub; i++) {
      problemStruct.fitParams[i] = p[i];
    }

    unpackParams(problemStruct);
    b_reflectivityCalculation(problemStruct, &data_f2, expl_temp);
    return -0.5 * expl_temp.calculationResults.sumChi;
  }
}

// End of code generation (nsIntraFun.cpp)
