//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// evaluateModel.cpp
//
// Code generation for function 'evaluateModel'
//

// Include files
#include "evaluateModel.h"
#include "DREAMWrapper.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void evaluateModel(const ::coder::array<real_T, 2U> &x, const struct14_T
                     *DREAMPar, const f_struct_T *ratInputs_problemStruct, const
                     cell_11 *ratInputs_problemCells, const struct1_T
                     *ratInputs_problemLimits, const struct2_T
                     *ratInputs_controls, ::coder::array<real_T, 2U> &fx)
  {
    ::coder::array<real_T, 2U> b_x;
    int32_T i;
    int32_T loop_ub_tmp;

    //  This function computes the likelihood and log-likelihood of each d-vector
    //  of x values
    //
    //  Code both for sequential and parallel evaluation of model ( = pdf )
    //
    //  Written by Jasper A. Vrugt
    //  Check whether to store the output of each model evaluation (function call)
    //  if DREAMPar.modout && ( Meas_info.N > 0 )
    //
    //      % Create initial fx of size model output by DREAMPar.N
    //      fx = NaN(Meas_info.N,DREAMPar.N);
    //
    //  end
    //  Now evaluate the model
    loop_ub_tmp = static_cast<int32_T>(DREAMPar->N);
    fx.set_size(1, loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      fx[i] = 0.0;
    }

    //  Sequential evaluation
    //  Loop over each d-vector of parameter values of x using 1 worker
    for (int32_T ii{0}; ii < loop_ub_tmp; ii++) {
      int32_T loop_ub;

      //  Execute the model and return the model simulation
      // fx(:,ii) = f_handle(x(ii,:), ratInputs);
      loop_ub = x.size(1);
      b_x.set_size(1, x.size(1));
      for (i = 0; i < loop_ub; i++) {
        b_x[i] = x[ii + x.size(0) * i];
      }

      fx[ii] = DREAMWrapper(b_x, ratInputs_problemStruct, ratInputs_problemCells,
                            ratInputs_problemLimits, ratInputs_controls);
    }
  }
}

// End of code generation (evaluateModel.cpp)
