//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// runSimplex.cpp
//
// Code generation for function 'runSimplex'
//

// Include files
#include "runSimplex.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "fMinSearch.h"
#include "reflectivityCalculation.h"
#include "rt_nonfinite.h"
#include "simplexXTransform.h"
#include "strcmp.h"
#include "unpackParams.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void runSimplex(ProblemDefinition &problemStruct, Controls &controls,
                  b_struct_T &result)
  {
    static const char b_cv1[6]{ 'n', 'o', 't', 'i', 'f', 'y' };

    static const char b_cv[5]{ 'f', 'i', 'n', 'a', 'l' };

    ::coder::array<double, 1U> x;
    ::coder::array<double, 1U> x0u;
    g_struct_T a__3;
    i_struct_T expl_temp;
    double a__2;
    int dis_size[2];
    int outsize_idx_0;
    char dis_data[6];

    //  Run the Nelder-Mead simplex algorithm for a given problem and controls.
    //
    //  Parameters
    //  ----------
    //  problemStruct : struct
    //      the Project struct.
    //  controls : struct
    //      the Controls struct.
    //
    //  Returns
    //  -------
    //  problemStruct : struct
    //      the output project struct.
    //  result : struct
    //      the calculation and optimisation results object.
    //
    if (coder::internal::v_strcmp(controls.display.data, controls.display.size))
    {
      outsize_idx_0 = 0;
    } else if (coder::internal::w_strcmp(controls.display.data,
                controls.display.size)) {
      outsize_idx_0 = 1;
    } else if (coder::internal::x_strcmp(controls.display.data,
                controls.display.size)) {
      outsize_idx_0 = 2;
    } else if (coder::internal::y_strcmp(controls.display.data,
                controls.display.size)) {
      outsize_idx_0 = 3;
    } else {
      outsize_idx_0 = -1;
    }

    switch (outsize_idx_0) {
     case 0:
      dis_size[0] = 1;
      dis_size[1] = 4;
      dis_data[0] = 'n';
      dis_data[1] = 'o';
      dis_data[2] = 'n';
      dis_data[3] = 'e';
      break;

     case 1:
      dis_size[0] = 1;
      dis_size[1] = 4;
      dis_data[0] = 'i';
      dis_data[1] = 't';
      dis_data[2] = 'e';
      dis_data[3] = 'r';
      break;

     case 2:
      dis_size[0] = 1;
      dis_size[1] = 6;
      for (int i{0}; i < 6; i++) {
        dis_data[i] = b_cv1[i];
      }
      break;

     case 3:
      dis_size[0] = 1;
      dis_size[1] = 5;
      for (int i{0}; i < 5; i++) {
        dis_data[i] = b_cv[i];
      }
      break;

     default:
      dis_size[0] = 1;
      dis_size[1] = 5;
      for (int i{0}; i < 5; i++) {
        dis_data[i] = b_cv[i];
      }
      break;
    }

    expl_temp.LB.set_size(problemStruct.fitLimits.size(0));
    outsize_idx_0 = problemStruct.fitLimits.size(0);
    expl_temp.UB.set_size(problemStruct.fitLimits.size(0));
    for (int i{0}; i < outsize_idx_0; i++) {
      expl_temp.LB[i] = problemStruct.fitLimits[i];
      expl_temp.UB[i] = problemStruct.fitLimits[i + problemStruct.fitLimits.size
        (0)];
    }

    //  size checks
    if (problemStruct.fitLimits.size(0) == 0) {
      outsize_idx_0 = problemStruct.fitParams.size(1);
      expl_temp.LB.set_size(outsize_idx_0);
      for (int i{0}; i < outsize_idx_0; i++) {
        expl_temp.LB[i] = rtMinusInf;
      }
    }

    if (problemStruct.fitLimits.size(0) == 0) {
      outsize_idx_0 = problemStruct.fitParams.size(1);
      expl_temp.UB.set_size(outsize_idx_0);
      for (int i{0}; i < outsize_idx_0; i++) {
        expl_temp.UB[i] = rtInf;
      }
    }

    //  stuff into a struct to pass around
    // varargin;
    // problemStruct.modelFilename;%fun;
    //  0 --> unconstrained variable
    //  1 --> lower bound only
    //  2 --> upper bound only
    //  3 --> dual finite bounds
    outsize_idx_0 = problemStruct.fitParams.size(1);
    expl_temp.BoundClass.set_size(outsize_idx_0);

    //  transform starting values into their unconstrained
    //  surrogates. Check for infeasible starting guesses.
    x0u.set_size(problemStruct.fitParams.size(1));
    for (int b_i{0}; b_i < outsize_idx_0; b_i++) {
      double d;
      int k;
      k = ((!std::isinf(expl_temp.LB[b_i])) && (!std::isnan(expl_temp.LB[b_i])))
        + (((!std::isinf(expl_temp.UB[b_i])) && (!std::isnan(expl_temp.UB[b_i])))
           << 1);
      expl_temp.BoundClass[b_i] = k;
      d = problemStruct.fitParams[b_i];
      x0u[b_i] = d;
      switch (k) {
       case 1:
        //  lower bound only
        if (d <= expl_temp.LB[b_i]) {
          //  infeasible starting value. Use bound.
          x0u[b_i] = 0.0;
        } else {
          x0u[b_i] = std::sqrt(d - expl_temp.LB[b_i]);
        }
        break;

       case 2:
        //  upper bound only
        if (d >= expl_temp.UB[b_i]) {
          //  infeasible starting value. use bound.
          x0u[b_i] = 0.0;
        } else {
          x0u[b_i] = std::sqrt(expl_temp.UB[b_i] - d);
        }
        break;

       case 3:
        //  lower and upper bounds
        if (d <= expl_temp.LB[b_i]) {
          //  infeasible starting value
          x0u[b_i] = -1.5707963267948966;
        } else if (d >= expl_temp.UB[b_i]) {
          //  infeasible starting value
          x0u[b_i] = 1.5707963267948966;
        } else {
          x0u[b_i] = std::asin(std::fmax(-1.0, std::fmin(1.0, 2.0 * (d -
            expl_temp.LB[b_i]) / (expl_temp.UB[b_i] - expl_temp.LB[b_i]) - 1.0)));
        }
        break;

       default:
        //  unconstrained variable. x0u(i) is set.
        break;
      }
    }

    //  now we can call fminsearch, but with our own
    //  intra-objective function.
    fMinSearch(x0u, controls.maxIterations, controls.maxFuncEvals,
               controls.xTolerance, controls.funcTolerance, dis_data, dis_size,
               problemStruct, controls.parallel.data, controls.parallel.size,
               controls.numSimulationPoints, controls.resampleMinAngle,
               controls.resampleNPoints, controls.updateFreq,
               controls.updatePlotFreq, controls.calcSLD,
               controls.IPCFilePath.data, controls.IPCFilePath.size, expl_temp,
               a__3, a__2);

    //  undo the variable transformations into the original space
    simplexXTransform(x0u, expl_temp.LB, expl_temp.UB, expl_temp.BoundClass, x);

    //  final reshape
    // x = reshape(x,xsize);
    problemStruct.fitParams.set_size(1, x.size(0));
    outsize_idx_0 = x.size(0);
    for (int i{0}; i < outsize_idx_0; i++) {
      problemStruct.fitParams[i] = x[i];
    }

    unpackParams(problemStruct);

    //  Ensure SLD is calculated for final result
    controls.calcSLD = true;
    b_reflectivityCalculation(problemStruct, &controls, result);
  }
}

// End of code generation (runSimplex.cpp)
