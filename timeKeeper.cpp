//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// timeKeeper.cpp
//
// Code generation for function 'timeKeeper'
//

// Include files
#include "timeKeeper.h"
#include "getTime.h"
#include "rt_nonfinite.h"
#include "coder_posix_time.h"

// Variable Definitions
namespace RAT
{
  static coderTimespec savedTime;
  static boolean_T savedTime_not_empty;
}

// Function Definitions
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
          void timeKeeper(real_T newTime_tv_sec, real_T newTime_tv_nsec)
          {
            if (!savedTime_not_empty) {
              getTime(&savedTime.tv_sec, &savedTime.tv_nsec);
              savedTime_not_empty = true;
            }

            savedTime.tv_sec = newTime_tv_sec;
            savedTime.tv_nsec = newTime_tv_nsec;
          }

          void timeKeeper(real_T *outTime_tv_sec, real_T *outTime_tv_nsec)
          {
            *outTime_tv_sec = savedTime.tv_sec;
            *outTime_tv_nsec = savedTime.tv_nsec;
          }
        }
      }
    }
  }

  void savedTime_not_empty_init()
  {
    savedTime_not_empty = false;
  }
}

// End of code generation (timeKeeper.cpp)
