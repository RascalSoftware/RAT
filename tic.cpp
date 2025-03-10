//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// tic.cpp
//
// Code generation for function 'tic'
//

// Include files
#include "tic.h"
#include "RATMain_data.h"
#include "rt_nonfinite.h"
#include "timeKeeper.h"
#include "coder_posix_time.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void tic()
    {
      coderTimespec b_timespec;
      if (!freq_not_empty) {
        freq_not_empty = true;
        coderInitTimeFunctions(&freq);
      }

      coderTimeClockGettimeMonotonic(&b_timespec, freq);
      internal::b_time::impl::timeKeeper(b_timespec.tv_sec, b_timespec.tv_nsec);
    }
  }
}

// End of code generation (tic.cpp)
