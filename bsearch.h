//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// bsearch.h
//
// Code generation for function 'bsearch'
//
#ifndef BSEARCH_H
#define BSEARCH_H

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
    namespace internal
    {
      int b_bsearch(const double x_data[], double xi);
      int b_bsearch(const ::coder::array<double, 1U> &x, double xi);
      int c_bsearch(const double x[3], double xi);
    }
  }
}

#endif

// End of code generation (bsearch.h)
