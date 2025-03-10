//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
    double toc()
    {
      double tnow_tv_nsec;
      double tnow_tv_sec;
      double tstart_tv_nsec;
      double tstart_tv_sec;
      tstart_tv_sec = internal::b_time::impl::timeKeeper(tstart_tv_nsec);
      tnow_tv_sec = internal::b_time::getTime(tnow_tv_nsec);
      return (tnow_tv_sec - tstart_tv_sec) + (tnow_tv_nsec - tstart_tv_nsec) /
        1.0E+9;
    }
  }
}

// End of code generation (toc.cpp)
