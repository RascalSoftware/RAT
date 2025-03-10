//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// eml_setop.cpp
//
// Code generation for function 'eml_setop'
//

// Include files
#include "eml_setop.h"
#include "relop.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
namespace RAT
{
  namespace coder
  {
    static double skip_to_last_equal_value(int &k, const ::coder::array<double,
      2U> &x);
  }
}

// Function Definitions
namespace RAT
{
  namespace coder
  {
    static double skip_to_last_equal_value(int &k, const ::coder::array<double,
      2U> &x)
    {
      double xk;
      xk = x[k - 1];
      while ((k < x.size(1)) && (x[k] == xk)) {
        k++;
      }

      return xk;
    }

    int do_vectors(const ::coder::array<double, 2U> &a, double b, ::coder::array<
                   double, 2U> &c, ::coder::array<int, 1U> &ia)
    {
      double ak;
      int iafirst;
      int ialast;
      int ib_size;
      int iblast;
      int na;
      int nc;
      int nia;
      na = a.size(1);
      c.set_size(1, a.size(1));
      ia.set_size(a.size(1));
      ib_size = 0;
      nc = 0;
      nia = 0;
      iafirst = 0;
      ialast = 1;
      iblast = 1;
      while ((ialast <= na) && (iblast <= 1)) {
        int b_ialast;
        b_ialast = ialast;
        ak = skip_to_last_equal_value(b_ialast, a);
        ialast = b_ialast;
        if (ak == b) {
          ialast = b_ialast + 1;
          iafirst = b_ialast;
          iblast = 2;
        } else if (internal::c_relop(ak, b)) {
          nia = nc + 1;
          nc++;
          c[nia - 1] = ak;
          ia[nia - 1] = iafirst + 1;
          ialast = b_ialast + 1;
          iafirst = b_ialast;
        } else {
          iblast = 2;
        }
      }

      while (ialast <= na) {
        iblast = ialast;
        ak = skip_to_last_equal_value(iblast, a);
        nia = nc + 1;
        nc++;
        c[nia - 1] = ak;
        ia[nia - 1] = iafirst + 1;
        ialast = iblast + 1;
        iafirst = iblast;
      }

      if (a.size(1) > 0) {
        if (nia < 1) {
          iblast = 0;
        } else {
          iblast = nia;
        }

        ia.set_size(iblast);
        c.set_size(c.size(0), iblast);
      }

      return ib_size;
    }
  }
}

// End of code generation (eml_setop.cpp)
