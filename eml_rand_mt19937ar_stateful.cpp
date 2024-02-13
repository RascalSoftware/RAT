//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// eml_rand_mt19937ar_stateful.cpp
//
// Code generation for function 'eml_rand_mt19937ar_stateful'
//

// Include files
#include "eml_rand_mt19937ar_stateful.h"
#include "RATMain_data.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
namespace RAT
{
  void eml_rand_mt19937ar_stateful_init()
  {
    uint32_T r;
    std::memset(&state[0], 0, 625U * sizeof(uint32_T));
    r = 5489U;
    state[0] = 5489U;
    for (int32_T mti{0}; mti < 623; mti++) {
      r = ((r ^ r >> 30U) * 1812433253U + mti) + 1U;
      state[mti + 1] = r;
    }

    state[624] = 624U;
  }
}

// End of code generation (eml_rand_mt19937ar_stateful.cpp)
