//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// nsIntraFun.h
//
// Code generation for function 'nsIntraFun'
//
#ifndef NSINTRAFUN_H
#define NSINTRAFUN_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct ProblemDefinition;
  struct Controls;
}

// Function Declarations
namespace RAT
{
  double nsIntraFun(const ProblemDefinition &data_f1, const Controls &data_f2,
                    const ::coder::array<double, 2U> &p);
}

#endif

// End of code generation (nsIntraFun.h)
