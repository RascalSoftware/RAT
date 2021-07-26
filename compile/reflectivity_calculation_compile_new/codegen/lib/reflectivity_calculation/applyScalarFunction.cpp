//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// applyScalarFunction.cpp
//
// Code generation for function 'applyScalarFunction'
//

// Include files
#include "applyScalarFunction.h"
#include "eml_erfcore.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
namespace internal {
void applyScalarFunction(const ::coder::array<double, 2U> &x,
                         ::coder::array<double, 2U> &z1)
{
  int k;
  int ub_loop;
  z1.set_size(1, x.size(1));
  ub_loop = x.size(1) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(k)

  for (k = 0; k <= ub_loop; k++) {
    z1[k] = scalar_erf(x[k]);
  }
}

} // namespace internal
} // namespace coder

// End of code generation (applyScalarFunction.cpp)
