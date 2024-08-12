//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// fread.h
//
// Code generation for function 'fread'
//
#ifndef FREAD_H
#define FREAD_H

// Include files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void b_fread(real_T fileID, uint8_T A_data[], int32_T *A_size);
  }
}

#endif

// End of code generation (fread.h)
