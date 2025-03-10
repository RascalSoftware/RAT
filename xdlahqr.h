//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xdlahqr.h
//
// Code generation for function 'xdlahqr'
//
#ifndef XDLAHQR_H
#define XDLAHQR_H

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
        int xdlahqr(int ilo, int ihi, ::coder::array<double, 2U> &h, int iloz,
                    int ihiz, ::coder::array<double, 2U> &z, ::coder::array<
                    double, 1U> &wr, ::coder::array<double, 1U> &wi);
        int xdlahqr(int ihi, ::coder::array<double, 2U> &h, int ihiz, ::coder::
                    array<double, 2U> &z, ::coder::array<double, 1U> &wr, ::
                    coder::array<double, 1U> &wi);
      }
    }
  }
}

#endif

// End of code generation (xdlahqr.h)
