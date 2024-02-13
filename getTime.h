//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// getTime.h
//
// Code generation for function 'getTime'
//
#ifndef GETTIME_H
#define GETTIME_H

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
    namespace internal
    {
      namespace time
      {
        void getTime(real_T *t_tv_sec, real_T *t_tv_nsec);
      }
    }
  }
}

#endif

// End of code generation (getTime.h)
