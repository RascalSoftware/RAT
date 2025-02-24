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
  struct cell_wrap_9;
}

// Function Declarations
namespace RAT
{
  void b_makeCell(double m, const double vals[3], ::coder::array<cell_wrap_9, 2U>
                  &x);
  void makeCell(cell_wrap_9 x[50]);
  void makeCell(double m, const double vals[3], ::coder::array<cell_wrap_9, 2U>
                &x);
}

#endif

// End of code generation (makeCell.h)
