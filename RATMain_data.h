//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// RATMain_data.h
//
// Code generation for function 'RATMain_data'
//
#ifndef RATMAIN_DATA_H
#define RATMAIN_DATA_H

// Include files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdio>
#include <cstdlib>

// Variable Declarations
namespace RAT
{
  extern unsigned int state[625];
  extern double freq;
  extern boolean_T freq_not_empty;
  extern omp_nest_lock_t RATMain_nestLockGlobal;
  extern const char cv[128];
  extern const char cv1[22];
  extern const double dv[257];
  extern const double dv1[257];
}

#endif

// End of code generation (RATMain_data.h)
