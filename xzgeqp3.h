//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xzgeqp3.h
//
// Code generation for function 'xzgeqp3'
//
#ifndef XZGEQP3_H
#define XZGEQP3_H

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
      namespace reflapack
      {
        void qrpf(::coder::array<double, 2U> &A, int m, int n, ::coder::array<
                  double, 1U> &tau, ::coder::array<int, 2U> &jpvt);
        int xzgeqp3(::coder::array<double, 1U> &A, int m, double tau_data[], int
                    &jpvt);
        int xzgeqp3(::coder::array<double, 2U> &A, int n, double tau_data[], ::
                    coder::array<int, 2U> &jpvt);
      }
    }
  }
}

#endif

// End of code generation (xzgeqp3.h)
