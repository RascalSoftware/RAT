//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// vAllOrAny.cpp
//
// Code generation for function 'vAllOrAny'
//

// Include files
#include "vAllOrAny.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      static void genloops(const ::coder::array<double, 2U> &x, boolean_T &p,
                           int varargin_1, int varargin_2);
    }
  }
}

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      static void genloops(const ::coder::array<double, 2U> &x, boolean_T &p,
                           int varargin_1, int varargin_2)
      {
        if (p || std::isnan(x[(varargin_1 + x.size(0) * (varargin_2 - 1)) - 1]))
        {
          p = true;
        } else {
          p = false;
        }
      }

      void b_genloops(const ::coder::array<double, 2U> &x, boolean_T &p, int
                      varargin_1, int varargin_2)
      {
        if (p) {
          double b_x;
          b_x = x[(varargin_1 + x.size(0) * (varargin_2 - 1)) - 1];
          if ((!std::isinf(b_x)) && (!std::isnan(b_x))) {
            p = true;
          } else {
            p = false;
          }
        } else {
          p = false;
        }
      }

      boolean_T vAllOrAny(const ::coder::array<double, 2U> &x)
      {
        int i;
        boolean_T p;
        p = false;
        i = x.size(1);
        for (int k{0}; k < i; k++) {
          int i1;
          i1 = x.size(0);
          for (int b_k{0}; b_k < i1; b_k++) {
            genloops(x, p, b_k + 1, k + 1);
          }
        }

        return p;
      }
    }
  }
}

// End of code generation (vAllOrAny.cpp)
