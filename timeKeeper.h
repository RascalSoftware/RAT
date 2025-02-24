//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// timeKeeper.h
//
// Code generation for function 'timeKeeper'
//
#ifndef TIMEKEEPER_H
#define TIMEKEEPER_H

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
        namespace impl
        {
          void timeKeeper(double newTime_tv_sec, double newTime_tv_nsec);
          void timeKeeper(double *outTime_tv_sec, double *outTime_tv_nsec);
        }
      }
    }
  }

  void savedTime_not_empty_init();
}

#endif

// End of code generation (timeKeeper.h)
