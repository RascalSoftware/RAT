//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sprintf.cpp
//
// Code generation for function 'sprintf'
//

// Include files
#include "sprintf.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstddef>
#include <stdio.h>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_sprintf(real_T varargin_1, real_T varargin_2, ::coder::array<char_T,
                   2U> &str)
    {
      int32_T nbytes;
      nbytes = snprintf(nullptr, 0,
                        "Exiting - X satisfies termination criteria: TolX %e, TolF %e",
                        varargin_1, varargin_2);
      str.set_size(1, nbytes + 1);
      snprintf(&str[0], (size_t)(nbytes + 1),
               "Exiting - X satisfies termination criteria: TolX %e, TolF %e",
               varargin_1, varargin_2);
      if (1 > nbytes) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }
  }
}

// End of code generation (sprintf.cpp)
