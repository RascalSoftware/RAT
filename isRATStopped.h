//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// isRATStopped.h
//
// Code generation for function 'isRATStopped'
//
#ifndef ISRATSTOPPED_H
#define ISRATSTOPPED_H

// Include files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void isRATStopped(const char IPCFilePath_data[], const int IPCFilePath_size[2],
                    boolean_T state_data[], int *state_size);
}

#endif

// End of code generation (isRATStopped.h)
