//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// runDE.cpp
//
// Code generation for function 'runDE'
//

// Include files
#include "runDE.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "deopt.h"
#include "reflectivityCalculation.h"
#include "rt_nonfinite.h"
#include "sprintf.h"
#include "strcmp.h"
#include "triggerEvent.h"
#include "unpackParams.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>

// Function Definitions
namespace RAT
{
  double intrafun(const ::coder::array<double, 2U> &p, ProblemDefinition &
                  problemStruct, const char controls_parallel_data[], const int
                  controls_parallel_size[2], double controls_numSimulationPoints,
                  double controls_resampleMinAngle, double
                  controls_resampleNPoints, boolean_T controls_calcSLD,
                  b_struct_T &result, double &S_MSE_FVr_ca, double &S_MSE_I_no,
                  double &S_MSE_FVr_oa)
  {
    Controls expl_temp;
    double S_MSE_I_nc;
    int loop_ub;
    problemStruct.fitParams.set_size(1, p.size(1));
    loop_ub = p.size(1);
    for (int i{0}; i < loop_ub; i++) {
      problemStruct.fitParams[i] = p[i];
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

    // no constraints                 THESE FIRST FEW VALS MAY BE WRONG
    // no constraint array
    // number of objectives (costs)
    S_MSE_I_nc = 0.0;
    S_MSE_FVr_ca = 0.0;
    S_MSE_I_no = 1.0;
    S_MSE_FVr_oa = result.calculationResults.sumChi;
    return S_MSE_I_nc;
  }

  void runDE(ProblemDefinition &problemStruct, Controls &controls, b_struct_T
             &result)
  {
    static const double S_struct_FVr_x[50]{ -1.0, -0.95918367346938771,
      -0.91836734693877542, -0.87755102040816324, -0.836734693877551,
      -0.79591836734693866, -0.75510204081632648, -0.71428571428571419,
      -0.673469387755102, -0.63265306122448972, -0.59183673469387754,
      -0.55102040816326525, -0.51020408163265307, -0.46938775510204078,
      -0.42857142857142855, -0.38775510204081631, -0.34693877551020408,
      -0.30612244897959179, -0.26530612244897955, -0.22448979591836732,
      -0.18367346938775508, -0.14285714285714285, -0.1020408163265306,
      -0.061224489795918366, -0.020408163265306121, 0.020408163265306121,
      0.061224489795918366, 0.1020408163265306, 0.14285714285714285,
      0.18367346938775508, 0.22448979591836732, 0.26530612244897955,
      0.30612244897959179, 0.34693877551020408, 0.38775510204081631,
      0.42857142857142855, 0.46938775510204078, 0.51020408163265307,
      0.55102040816326525, 0.59183673469387754, 0.63265306122448972,
      0.673469387755102, 0.71428571428571419, 0.75510204081632648,
      0.79591836734693866, 0.836734693877551, 0.87755102040816324,
      0.91836734693877542, 0.95918367346938771, 1.0 };

    ::coder::array<double, 2U> res;
    ::coder::array<signed char, 2U> S_struct_FM_pop;
    ::coder::array<char, 2U> charStr;
    h_struct_T expl_temp;
    int loop_ub;

    //  Run the differential evolution algorithm for a given problem and controls.
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
    // Value to reach
    expl_temp.FVr_minbound.set_size(1, problemStruct.fitLimits.size(0));
    loop_ub = problemStruct.fitLimits.size(0);
    expl_temp.FVr_maxbound.set_size(1, problemStruct.fitLimits.size(0));
    for (int i{0}; i < loop_ub; i++) {
      expl_temp.FVr_minbound[i] = problemStruct.fitLimits[i];
      expl_temp.FVr_maxbound[i] = problemStruct.fitLimits[i +
        problemStruct.fitLimits.size(0)];
    }

    // 1: use bounds as bound constraints, 0: no bound constraints
    //  I_NP            number of population members
    //  I_itermax       maximum number of iterations (generations)
    //  fWeight        DE-stepsize fWeight ex [0, 2]
    //  F_CR            crossover probability constant ex [0, 1]
    //  I_strategy     1 --> DE/rand/1:
    //                       the classical version of DE.
    //                 2 --> DE/local-to-best/1:
    //                       a version which has been used by quite a number
    //                       of scientists. Attempts a balance between robustness
    //                       and fast convergence.
    //                 3 --> DE/best/1 with jitter:
    //                       taylored for small population sizes and fast convergence.
    //                       Dimensionality should not be too high.
    //                 4 --> DE/rand/1 with per-vector-dither:
    //                       Classical DE with dither to become even more robust.
    //                 5 --> DE/rand/1 with per-generation-dither:
    //                       Classical DE with dither to become even more robust.
    //                       Choosing fWeight = 0.3 is a good start here.
    //                 6 --> DE/rand/1 either-or-algorithm:
    //                       Alternates between differential mutation and three-point-
    //                       recombination.
    //  I_refresh     intermediate output will be produced after "I_refresh"
    //                iterations. No intermediate output will be produced
    //                if I_refresh is < 1
    //  I_plotting    Will use plotting if set to 1. Will skip plotting otherwise.
    // -----Definition of tolerance scheme--------------------------------------
    // -----The scheme is sampled at I_lentol points----------------------------
    // ordinate running from -1 to +1
    // upper limit is 1
    // lower limit is -1
    // Tell compiler abut variable sizes
    // -----tie all important values to a structure that can be passed along----
    loop_ub = static_cast<int>(controls.populationSize);
    S_struct_FM_pop.set_size(loop_ub, 2);
    expl_temp.FVr_bestmem.set_size(1, 2);
    for (int i{0}; i < 2; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        S_struct_FM_pop[i1 + S_struct_FM_pop.size(0) * i] = 0;
      }

      expl_temp.FVr_bestmem[i] = 0.0;
    }

    expl_temp.FM_pop.set_size(S_struct_FM_pop.size(0), 2);
    loop_ub = S_struct_FM_pop.size(0);
    for (int i{0}; i < 2; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        expl_temp.FM_pop[i1 + expl_temp.FM_pop.size(0) * i] = 0.0;
      }
    }

    expl_temp.I_plotting = 0.0;
    expl_temp.I_refresh = 1.0;
    expl_temp.I_strategy = controls.strategy;
    expl_temp.F_VTR = controls.targetValue;
    expl_temp.I_itermax = controls.numGenerations;
    expl_temp.I_bnd_constr = 1.0;
    expl_temp.I_D = problemStruct.fitParams.size(1);
    expl_temp.F_CR = controls.crossoverProbability;
    expl_temp.fWeight = controls.fWeight;
    expl_temp.I_NP = controls.populationSize;
    for (int i{0}; i < 50; i++) {
      expl_temp.FVr_lim_lo[i] = -1.0;
      expl_temp.FVr_lim_up[i] = 1.0;
      expl_temp.FVr_x[i] = S_struct_FVr_x[i];
    }

    expl_temp.I_lentol = 50.0;
    deopt(problemStruct, controls.parallel.data, controls.parallel.size,
          controls.numSimulationPoints, controls.resampleMinAngle,
          controls.resampleNPoints, controls.display.data, controls.display.size,
          controls.updateFreq, controls.updatePlotFreq, controls.calcSLD,
          controls.IPCFilePath.data, controls.IPCFilePath.size, expl_temp, res);
    problemStruct.fitParams.set_size(1, res.size(1));
    loop_ub = res.size(1);
    for (int i{0}; i < loop_ub; i++) {
      problemStruct.fitParams[i] = res[i];
    }

    unpackParams(problemStruct);

    //  Ensure SLD is calculated for final result
    controls.calcSLD = true;
    b_reflectivityCalculation(problemStruct, &controls, result);
    if (!coder::internal::d_strcmp(controls.display.data, controls.display.size))
    {
      coder::snPrint(result.calculationResults.sumChi, charStr);
      triggerEvent(charStr);
    }
  }
}

// End of code generation (runDE.cpp)
