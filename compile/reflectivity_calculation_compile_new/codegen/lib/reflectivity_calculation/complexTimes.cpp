//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// complexTimes.cpp
//
// Code generation for function 'complexTimes'
//

// Include files
#include "complexTimes.h"
#include "abs.h"
#include "isfinite.h"
#include "isinf.h"
#include "isnan.h"
#include "rt_nonfinite.h"

// Function Declarations
namespace coder {
namespace internal {
namespace scalar {
static double rescale(double *re, double *im);

}
} // namespace internal
} // namespace coder

// Function Definitions
namespace coder {
namespace internal {
namespace scalar {
static double rescale(double *re, double *im)
{
  double absim;
  double scale;
  scale = b_abs(*re);
  absim = b_abs(*im);
  if (scale > absim) {
    if (*re < 0.0) {
      *re = -1.0;
    } else {
      *re = 1.0;
    }
    *im /= scale;
  } else if (absim > scale) {
    *re /= absim;
    if (*im < 0.0) {
      *im = -1.0;
    } else {
      *im = 1.0;
    }
    scale = absim;
  } else {
    if (*re < 0.0) {
      *re = -1.0;
    } else {
      *re = 1.0;
    }
    if (*im < 0.0) {
      *im = -1.0;
    } else {
      *im = 1.0;
    }
  }
  return scale;
}

double complexTimes(double ar, double ai, double br, double bi)
{
  double cr;
  double sai;
  double sar;
  double sbi;
  double sbr;
  if ((ai == 0.0) && (bi == 0.0)) {
    cr = 0.0;
  } else {
    double t3;
    double t4;
    t3 = ar * bi;
    t4 = ai * br;
    cr = t3 + t4;
    if ((!b_isfinite(cr)) && (!b_isnan(ar)) && (!b_isnan(ai)) &&
        (!b_isnan(br)) && (!b_isnan(bi))) {
      double scaleA;
      double scaleB;
      boolean_T finiteScale;
      sar = ar;
      sai = ai;
      scaleA = rescale(&sar, &sai);
      sbr = br;
      sbi = bi;
      scaleB = rescale(&sbr, &sbi);
      if (b_isfinite(scaleA) && b_isfinite(scaleB)) {
        finiteScale = true;
      } else {
        finiteScale = false;
      }
      if (b_isnan(cr) || (b_isinf(cr) && finiteScale)) {
        cr = sar * sbi + sai * sbr;
        if (cr != 0.0) {
          cr = cr * scaleA * scaleB;
        } else if ((b_isinf(scaleA) && ((br == 0.0) || (bi == 0.0))) ||
                   (b_isinf(scaleB) && ((ar == 0.0) || (ai == 0.0)))) {
          if (b_isnan(t3)) {
            t3 = 0.0;
          }
          if (b_isnan(t4)) {
            t4 = 0.0;
          }
          cr = t3 + t4;
        }
      }
    }
  }
  return cr;
}

} // namespace scalar
} // namespace internal
} // namespace coder

// End of code generation (complexTimes.cpp)
