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
  double nsIntraFun(const ProblemDefinition *data_f1, const Controls *data_f2,
                    const ::coder::array<double, 2U> &p)
  {
    ProblemDefinition problemStruct;
    Results expl_temp;
    int loop_ub;
    problemStruct = *data_f1;

    //  Removed use of cells....
    problemStruct.fitParams.set_size(1, p.size(1));
    loop_ub = p.size(1);
    for (int i{0}; i < loop_ub; i++) {
      problemStruct.fitParams[i] = p[i];
    }

    unpackParams(&problemStruct);
    b_reflectivityCalculation(&problemStruct, data_f2, &expl_temp);
    return -expl_temp.calculationResults.sumChi / 2.0;
  }
}

// End of code generation (nsIntraFun.cpp)
