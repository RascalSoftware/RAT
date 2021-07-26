//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// reflectivity_calculation_rtwutil.cpp
//
// Code generation for function 'reflectivity_calculation_rtwutil'
//

// Include files
#include "reflectivity_calculation_rtwutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
void b_cast(const coder::array<double, 2U> &t7_f1,
            coder::array<double, 2U> &t8_f1)
{
  int loop_ub;
  t8_f1.set_size(t7_f1.size(0), t7_f1.size(1));
  loop_ub = t7_f1.size(0) * t7_f1.size(1);
  for (int i{0}; i < loop_ub; i++) {
    t8_f1[i] = t7_f1[i];
  }
}

void cast(const coder::array<cell_wrap_10, 1U> &b,
          coder::array<cell_wrap_7, 1U> &c)
{
  int i;
  c.set_size(b.size(0));
  i = b.size(0);
  for (int i1{0}; i1 < i; i1++) {
    cast(b[i1].f1, c[i1].f1);
  }
}

void cast(const coder::array<cell_wrap_23, 1U> &b,
          coder::array<cell_wrap_1, 1U> &c)
{
  int i;
  c.set_size(b.size(0));
  i = b.size(0);
  for (int i1{0}; i1 < i; i1++) {
    b_cast(b[i1].f1, c[i1].f1);
  }
}

void cast(const coder::array<double, 2U> &t9_f1,
          coder::array<double, 2U> &t10_f1)
{
  int loop_ub;
  t10_f1.set_size(t9_f1.size(0), 2);
  loop_ub = t9_f1.size(0) * 2;
  for (int i{0}; i < loop_ub; i++) {
    t10_f1[i] = t9_f1[i];
  }
}

// End of code generation (reflectivity_calculation_rtwutil.cpp)
