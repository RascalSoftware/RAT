//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// rng.cpp
//
// Code generation for function 'rng'
//

// Include files
#include "rng.h"
#include "RATMain_data.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void rng()
    {
      unsigned int r;
      std::memset(&state[0], 0, 625U * sizeof(unsigned int));
      r = 5489U;
      state[0] = 5489U;
      for (int mti{0}; mti < 623; mti++) {
        r = ((r ^ r >> 30U) * 1812433253U + static_cast<unsigned int>(mti)) + 1U;
        state[mti + 1] = r;
      }

      state[624] = 624U;
    }
  }
}

// End of code generation (rng.cpp)
