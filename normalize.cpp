//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// normalize.cpp
//
// Code generation for function 'normalize'
//

// Include files
#include "normalize.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void normalize(const double a[2], double n[2])
    {
      double fillA_idx_0;
      double fillA_idx_1;
      fillA_idx_0 = a[0];
      fillA_idx_1 = a[1];
      if (std::isnan(a[0])) {
        fillA_idx_0 = 0.0;
      }

      if (std::isnan(a[1])) {
        fillA_idx_1 = 0.0;
      }

      fillA_idx_0 = std::abs(fillA_idx_0) + std::abs(fillA_idx_1);
      n[0] = a[0] / fillA_idx_0;
      n[1] = a[1] / fillA_idx_0;
    }

    void normalize(const double a_data[], double n_data[], int n_size[2])
    {
      double fillA_data_idx_0;
      double fillA_data_idx_1;
      double fillA_data_idx_2;
      fillA_data_idx_0 = a_data[0];
      fillA_data_idx_1 = a_data[1];
      fillA_data_idx_2 = a_data[2];
      if (std::isnan(a_data[0])) {
        fillA_data_idx_0 = 0.0;
      }

      if (std::isnan(a_data[1])) {
        fillA_data_idx_1 = 0.0;
      }

      if (std::isnan(a_data[2])) {
        fillA_data_idx_2 = 0.0;
      }

      fillA_data_idx_0 = (std::abs(fillA_data_idx_0) + std::abs(fillA_data_idx_1))
        + std::abs(fillA_data_idx_2);
      n_size[0] = 1;
      n_size[1] = 3;
      n_data[0] = a_data[0] / fillA_data_idx_0;
      n_data[1] = a_data[1] / fillA_data_idx_0;
      n_data[2] = a_data[2] / fillA_data_idx_0;
    }
  }
}

// End of code generation (normalize.cpp)
