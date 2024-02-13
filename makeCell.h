//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// makeCell.h
//
// Code generation for function 'makeCell'
//
#ifndef MAKECELL_H
#define MAKECELL_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_wrap_8;
  struct cell_wrap_22;
}

// Function Declarations
namespace RAT
{
  void b_makeCell(real_T m, const real_T vals_data[], ::coder::array<
                  cell_wrap_22, 2U> &x);
  void b_makeCell(real_T m, const real_T vals_data[], ::coder::array<cell_wrap_8,
                  2U> &x);
  void makeCell(cell_wrap_8 x[50]);
  void makeCell(real_T m, const real_T vals_data[], ::coder::array<cell_wrap_22,
                2U> &x);
  void makeCell(real_T m, const real_T vals_data[], ::coder::array<cell_wrap_8,
                2U> &x);
}

#endif

// End of code generation (makeCell.h)
