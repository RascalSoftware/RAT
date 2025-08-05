//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// deopt.h
//
// Code generation for function 'deopt'
//
#ifndef DEOPT_H
#define DEOPT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct ProblemDefinition;
  struct h_struct_T;
}

// Function Declarations
namespace RAT
{
  void deopt(const ProblemDefinition &problem, const char
             controls_parallel_data[], const int controls_parallel_size[2],
             double controls_numSimulationPoints, double
             controls_resampleMinAngle, double controls_resampleNPoints, const
             char controls_display_data[], const int controls_display_size[2],
             double controls_updateFreq, double controls_updatePlotFreq,
             boolean_T controls_calcSLD, const char controls_IPCFilePath_data[],
             const int controls_IPCFilePath_size[2], const h_struct_T &S_struct,
             ::coder::array<double, 2U> &FVr_bestmem);
}

#endif

// End of code generation (deopt.h)
