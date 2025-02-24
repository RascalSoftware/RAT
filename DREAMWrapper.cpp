//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// DREAMWrapper.cpp
//
// Code generation for function 'DREAMWrapper'
//

// Include files
#include "DREAMWrapper.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "reflectivityCalculation.h"
#include "rt_nonfinite.h"
#include "unpackParams.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  double DREAMWrapper(const ::coder::array<double, 2U> &pars, const
                      ProblemDefinition *ratInputs_problemStruct, const Controls
                      *ratInputs_controls)
  {
    ProblemDefinition problemStruct;
    Results expl_temp;
    int loop_ub;

    //  Get the inputs for Reflectivity Calculation
    problemStruct = *ratInputs_problemStruct;

    //  Put the current parameters into problem
    problemStruct.fitParams.set_size(1, pars.size(1));
    loop_ub = pars.size(1);
    for (int i{0}; i < loop_ub; i++) {
      problemStruct.fitParams[i] = pars[i];
    }

    //  Distribute them to the right parts
    unpackParams(&problemStruct);

    //  Calculate....
    b_reflectivityCalculation(&problemStruct, ratInputs_controls, &expl_temp);

    //  Function value is chi-squared....
    return -expl_temp.calculationResults.sumChi / 2.0;
  }
}

// End of code generation (DREAMWrapper.cpp)
