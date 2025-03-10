//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// getenv.cpp
//
// Code generation for function 'getenv'
//

// Include files
#include "getenv.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <cstring>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_getenv(::coder::array<char, 2U> &b_value)
    {
      char *rawValue;
      rawValue = std::getenv("RAT_PATH");
      if (rawValue == nullptr) {
        b_value.set_size(1, 0);
      } else {
        size_t length;
        length = std::strlen(rawValue);
        b_value.set_size(1, (int)length);
        std::copy(rawValue, rawValue + (size_t)(int)length, (char *)&b_value[0]);
      }
    }
  }
}

// End of code generation (getenv.cpp)
