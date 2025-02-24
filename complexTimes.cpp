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
#include "rt_nonfinite.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace scalar
      {
        static double b_rescale(double *re, double *im);
      }
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
      namespace scalar
      {
        static double b_rescale(double *re, double *im)
        {
          double absim;
          double scale;
          scale = std::abs(*re);
          absim = std::abs(*im);
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
            if ((std::isinf(cr) || std::isnan(cr)) && (!std::isnan(ar)) && (!std::
                 isnan(ai)) && (!std::isnan(br)) && (!std::isnan(bi))) {
              double scaleA;
              double scaleB;
              boolean_T finiteScale;
              sar = ar;
              sai = ai;
              scaleA = b_rescale(&sar, &sai);
              sbr = br;
              sbi = bi;
              scaleB = b_rescale(&sbr, &sbi);
              if ((!std::isinf(scaleA)) && (!std::isnan(scaleA)) && ((!std::
                    isinf(scaleB)) && (!std::isnan(scaleB)))) {
                finiteScale = true;
              } else {
                finiteScale = false;
              }

              if (std::isnan(cr) || (std::isinf(cr) && finiteScale)) {
                cr = sar * sbi + sai * sbr;
                if (cr != 0.0) {
                  cr = cr * scaleA * scaleB;
                } else if ((std::isinf(scaleA) && ((br == 0.0) || (bi == 0.0))) ||
                           (std::isinf(scaleB) && ((ar == 0.0) || (ai == 0.0))))
                {
                  if (std::isnan(t3)) {
                    t3 = 0.0;
                  }

                  if (std::isnan(t4)) {
                    t4 = 0.0;
                  }

                  cr = t3 + t4;
                }
              }
            }
          }

          return cr;
        }
      }
    }
  }
}

// End of code generation (complexTimes.cpp)
