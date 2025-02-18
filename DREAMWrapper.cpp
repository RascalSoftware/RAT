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
  real_T DREAMWrapper(const ::coder::array<real_T, 2U> &pars, const e_struct_T
                      *ratInputs_problemStruct, const struct4_T
                      *ratInputs_controls)
  {
    e_struct_T problemStruct;
    struct5_T expl_temp;
    int32_T loop_ub;

    //  Get the inputs for Reflectivity Calculation
    problemStruct = *ratInputs_problemStruct;

    //  Put the current parameters into problem
    problemStruct.fitParams.set_size(1, pars.size(1));
    loop_ub = pars.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
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
