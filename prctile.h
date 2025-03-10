//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// prctile.h
//
// Code generation for function 'prctile'
//
#ifndef PRCTILE_H
#define PRCTILE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void b_prctile(const ::coder::array<double, 2U> &x, ::coder::array<double,
                   2U> &y);
    void b_prctile(const double x_data[], int x_size, double y[2]);
    void prctile(const ::coder::array<double, 2U> &x, double y[2]);
    void prctile(const ::coder::array<double, 2U> &x, ::coder::array<double, 2U>
                 &y);
    void prctile(const double x_data[], int x_size, double y[2]);
  }
}

#endif

// End of code generation (prctile.h)
