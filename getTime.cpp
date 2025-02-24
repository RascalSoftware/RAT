//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// getTime.cpp
//
// Code generation for function 'getTime'
//

// Include files
#include "getTime.h"
#include "RATMain_data.h"
#include "rt_nonfinite.h"
#include "coder_posix_time.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace time
      {
        void getTime(double *t_tv_sec, double *t_tv_nsec)
        {
          coderTimespec b_timespec;
          if (!freq_not_empty) {
            freq_not_empty = true;
            coderInitTimeFunctions(&freq);
          }

          coderTimeClockGettimeMonotonic(&b_timespec, freq);
          *t_tv_sec = b_timespec.tv_sec;
          *t_tv_nsec = b_timespec.tv_nsec;
        }
      }
    }
  }
}

// End of code generation (getTime.cpp)
