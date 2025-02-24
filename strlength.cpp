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
    void intstrlen(const ::coder::array<cell_wrap_10, 2U> &s, int len_data[],
                   int len_size[2])
    {
      int ns;
      len_size[0] = 1;
      len_size[1] = static_cast<short>(s.size(1));
      ns = static_cast<short>(s.size(1));
      if (0 <= ns - 1) {
        std::memset(&len_data[0], 0, ns * sizeof(int));
      }

      ns = s.size(1);
      for (int idx{0}; idx < ns; idx++) {
        len_data[idx] = s[idx].f1.size(1);
      }
    }
  }
}

// End of code generation (strlength.cpp)
