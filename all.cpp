//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// all.cpp
//
// Code generation for function 'all'
//

// Include files
#include "all.h"
#include "allOrAny.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void all(const boolean_T x_data[], boolean_T y_data[], int y_size[2])
    {
      y_size[0] = 1;
      y_size[1] = 1;
      y_data[0] = false;
      internal::e_anon(x_data, y_data);
    }

    boolean_T b_all(const boolean_T x_data[])
    {
      return internal::d_anon(x_data);
    }
  }
}

// End of code generation (all.cpp)
