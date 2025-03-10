//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// lower.cpp
//
// Code generation for function 'lower'
//

// Include files
#include "lower.h"
#include "RATMain_data.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void lower(const char x_data[], const int x_size[2], char y_data[], int
               y_size[2])
    {
      int i;
      y_size[0] = 1;
      y_size[1] = x_size[1];
      i = x_size[1];
      for (int k{0}; k < i; k++) {
        y_data[k] = cv[static_cast<unsigned char>(x_data[k]) & 127];
      }
    }
  }
}

// End of code generation (lower.cpp)
