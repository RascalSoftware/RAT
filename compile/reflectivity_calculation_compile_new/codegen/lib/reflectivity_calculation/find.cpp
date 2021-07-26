//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// find.cpp
//
// Code generation for function 'find'
//

// Include files
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
void b_eml_find(const boolean_T x[3], int i_data[], int *i_size)
{
  int idx;
  int ii;
  boolean_T exitg1;
  idx = 0;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 3)) {
    if (x[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= 3) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (1 > idx) {
    *i_size = 0;
  } else {
    *i_size = idx;
  }
}

void eml_find(const ::coder::array<boolean_T, 1U> &x,
              ::coder::array<int, 1U> &i)
{
  int idx;
  int ii;
  int nx;
  boolean_T exitg1;
  nx = x.size(0);
  idx = 0;
  i.set_size(x.size(0));
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x[ii]) {
      idx++;
      i[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (x.size(0) == 1) {
    if (idx == 0) {
      i.set_size(0);
    }
  } else {
    if (1 > idx) {
      idx = 0;
    }
    i.set_size(idx);
  }
}

} // namespace coder

// End of code generation (find.cpp)
