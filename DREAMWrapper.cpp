//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
                      ProblemDefinition &ratInputs_problemStruct, const Controls
                      *ratInputs_controls)
  {
    ProblemDefinition problemStruct;
    b_struct_T expl_temp;
    int loop_ub;

    //  Calculate the log-likelihood for a set of parameters.
    //
    //  Parameters
    //  ----------
    //  pars : vector
    //      The current parameter values.
    //  ratInputs : struct
    //      The problem and controls to calculate log-likelihood from.
    //
    //  Returns
    //  -------
    //  Lik : float
    //      The (natural) log-likelihood value for the given parameter values.
    //
    //  Get the inputs for Reflectivity Calculation
    problemStruct = ratInputs_problemStruct;

    //  Put the current parameters into problem
    problemStruct.fitParams.set_size(1, pars.size(1));
    loop_ub = pars.size(1);
    for (int i{0}; i < loop_ub; i++) {
      problemStruct.fitParams[i] = pars[i];
    }

    //  Distribute them to the right parts
    unpackParams(problemStruct);

    //  Calculate....
    b_reflectivityCalculation(problemStruct, ratInputs_controls, expl_temp);

    //  Function value is chi-squared....
    return -0.5 * expl_temp.calculationResults.sumChi;
  }
}

// End of code generation (DREAMWrapper.cpp)
