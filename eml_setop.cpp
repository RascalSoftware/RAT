//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// eml_setop.cpp
//
// Code generation for function 'eml_setop'
//

// Include files
#include "eml_setop.h"
#include "eps.h"
#include "relop.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    static double skip_to_last_equal_value(int *k, const ::coder::array<double,
      2U> &x);
  }
}

// Function Definitions
namespace RAT
{
  namespace coder
  {
    static double skip_to_last_equal_value(int *k, const ::coder::array<double,
      2U> &x)
    {
      double xk;
      xk = x[*k - 1];
      while ((*k < x.size(1)) && ((std::abs(xk - x[*k]) < eps(xk / 2.0)) || (std::
               isinf(x[*k]) && std::isinf(xk) && ((x[*k] > 0.0) == (xk > 0.0)))))
      {
        (*k)++;
      }

      return xk;
    }

    void do_vectors(const ::coder::array<double, 2U> &a, double b, ::coder::
                    array<double, 2U> &c, ::coder::array<int, 1U> &ia, int
                    *ib_size)
    {
      double ak;
      int b_ialast;
      int iafirst;
      int ialast;
      int iblast;
      int na;
      int nc;
      int nia;
      na = a.size(1);
      c.set_size(1, a.size(1));
      ia.set_size(a.size(1));
      *ib_size = 0;
      nc = 0;
      nia = 0;
      iafirst = 0;
      ialast = 1;
      iblast = 1;
      while ((ialast <= na) && (iblast <= 1)) {
        b_ialast = ialast;
        ak = skip_to_last_equal_value(&b_ialast, a);
        ialast = b_ialast;
        if ((std::abs(b - ak) < eps(b / 2.0)) || (std::isinf(ak) && std::isinf(b)
             && ((ak > 0.0) == (b > 0.0)))) {
          ialast = b_ialast + 1;
          iafirst = b_ialast;
          iblast = 2;
        } else if (internal::c_relop(ak, b)) {
          nc++;
          nia++;
          c[nc - 1] = ak;
          ia[nia - 1] = iafirst + 1;
          ialast = b_ialast + 1;
          iafirst = b_ialast;
        } else {
          iblast = 2;
        }
      }

      while (ialast <= na) {
        iblast = ialast;
        ak = skip_to_last_equal_value(&iblast, a);
        nc++;
        nia++;
        c[nc - 1] = ak;
        ia[nia - 1] = iafirst + 1;
        ialast = iblast + 1;
        iafirst = iblast;
      }

      if (a.size(1) > 0) {
        if (1 > nia) {
          nia = 0;
        }

        ia.set_size(nia);
        if (1 > nc) {
          nc = 0;
        }

        c.set_size(c.size(0), nc);
      }
    }
  }
}

// End of code generation (eml_setop.cpp)
