//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// toc.cpp
//
// Code generation for function 'toc'
//

// Include files
#include "toc.h"
#include "getTime.h"
#include "rt_nonfinite.h"
#include "timeKeeper.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    real_T toc()
    {
      real_T tnow_tv_nsec;
      real_T tnow_tv_sec;
      real_T tstart_tv_nsec;
      real_T tstart_tv_sec;
      internal::time::impl::timeKeeper(&tstart_tv_sec, &tstart_tv_nsec);
      internal::time::getTime(&tnow_tv_sec, &tnow_tv_nsec);
      return (tnow_tv_sec - tstart_tv_sec) + (tnow_tv_nsec - tstart_tv_nsec) /
        1.0E+9;
    }
  }
}

// End of code generation (toc.cpp)
