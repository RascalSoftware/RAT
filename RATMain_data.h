//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
#include <cstdlib>

// Variable Declarations
namespace RAT
{
  extern uint32_T state[625];
  extern real_T verbose;
  extern real_T DEBUG;
  extern real_T freq;
  extern boolean_T freq_not_empty;
  extern omp_nest_lock_t emlrtNestLockGlobal;
  extern const char_T cv[128];
  extern const char_T cv1[9];
  extern const real_T dv[257];
  extern const real_T dv1[257];
}

#endif

// End of code generation (RATMain_data.h)
