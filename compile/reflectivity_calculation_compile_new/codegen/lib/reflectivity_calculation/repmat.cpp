//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// repmat.cpp
//
// Code generation for function 'repmat'
//

// Include files
#include "repmat.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
void repmat(const double a[2], double varargin_1, ::coder::array<double, 2U> &b)
{
  int i;
  i = static_cast<int>(varargin_1);
  b.set_size(i, 2);
  for (int jcol{0}; jcol < 2; jcol++) {
    int ibmat;
    ibmat = jcol * static_cast<int>(varargin_1);
    for (int itilerow{0}; itilerow < i; itilerow++) {
      b[ibmat + itilerow] = a[jcol];
    }
  }
}

} // namespace coder

// End of code generation (repmat.cpp)
