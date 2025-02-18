//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// strlength.cpp
//
// Code generation for function 'strlength'
//

// Include files
#include "strlength.h"
#include "RATMain_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void intstrlen(const ::coder::array<cell_wrap_10, 2U> &s, int32_T len_data[],
                   int32_T len_size[2])
    {
      int32_T ns;
      len_size[0] = 1;
      len_size[1] = static_cast<int16_T>(s.size(1));
      ns = static_cast<int16_T>(s.size(1));
      if (0 <= ns - 1) {
        std::memset(&len_data[0], 0, ns * sizeof(int32_T));
      }

      ns = s.size(1);
      for (int32_T idx{0}; idx < ns; idx++) {
        len_data[idx] = s[idx].f1.size(1);
      }
    }
  }
}

// End of code generation (strlength.cpp)
