//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
      int loop_ub;
      len_size[0] = 1;
      len_size[1] = static_cast<short>(s.size(1));
      loop_ub = static_cast<short>(s.size(1));
      if (loop_ub - 1 >= 0) {
        std::memset(&len_data[0], 0, static_cast<unsigned int>(loop_ub) * sizeof
                    (int));
      }

      loop_ub = s.size(1);
      for (int idx{0}; idx < loop_ub; idx++) {
        len_data[idx] = s[idx].f1.size(1);
      }
    }
  }
}

// End of code generation (strlength.cpp)
