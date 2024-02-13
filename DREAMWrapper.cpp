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
  real_T DREAMWrapper(const ::coder::array<real_T, 2U> &pars, const d_struct_T
                      *ratInputs_problemStruct, const cell_11
                      *ratInputs_problemCells, const struct2_T
                      *ratInputs_controls)
  {
    cell_wrap_9 a__1[6];
    d_struct_T problemStruct;
    e_struct_T contrastParams;
    int32_T loop_ub;

    //  Get the inputs for Reflectivity Calculation
    problemStruct = *ratInputs_problemStruct;

    //  Put the current parameters into problem
    problemStruct.fitParams.set_size(1, pars.size(1));
    loop_ub = pars.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      problemStruct.fitParams[problemStruct.fitParams.size(0) * i] = pars[i];
    }

    //  Distribute them to the right parts
    unpackParams(&problemStruct, ratInputs_controls->checks.fitParam,
                 ratInputs_controls->checks.fitBackgroundParam,
                 ratInputs_controls->checks.fitQzshift,
                 ratInputs_controls->checks.fitScalefactor,
                 ratInputs_controls->checks.fitBulkIn,
                 ratInputs_controls->checks.fitBulkOut,
                 ratInputs_controls->checks.fitResolutionParam,
                 ratInputs_controls->checks.fitDomainRatio);

    //  Calculate....
    reflectivityCalculation(&problemStruct, ratInputs_problemCells,
      ratInputs_controls, &contrastParams, a__1);

    //  Function value is chi-squared....
    return -contrastParams.calculations.sumChi / 2.0;
  }
}

// End of code generation (DREAMWrapper.cpp)
