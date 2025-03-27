//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
        static double rescale(double &re, double &im);
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
        static double rescale(double &re, double &im)
        {
          double absim;
          double scale;
          scale = std::abs(re);
          absim = std::abs(im);
          if (scale > absim) {
            if (re < 0.0) {
              re = -1.0;
            } else {
              re = 1.0;
            }

            im /= scale;
          } else if (absim > scale) {
            re /= absim;
            if (im < 0.0) {
              im = -1.0;
            } else {
              im = 1.0;
            }

            scale = absim;
          } else {
            if (re < 0.0) {
              re = -1.0;
            } else {
              re = 1.0;
            }

            if (im < 0.0) {
              im = -1.0;
            } else {
              im = 1.0;
            }
          }

          return scale;
        }

        double complexTimes(double ar, double ai, double br, double bi)
        {
          double cr;
          if ((ai == 0.0) && (bi == 0.0)) {
            cr = 0.0;
          } else {
            double t3;
            double t4;
            boolean_T b;
            boolean_T b1;
            t3 = ar * bi;
            t4 = ai * br;
            cr = t3 + t4;
            b = std::isnan(cr);
            b1 = std::isinf(cr);
            if ((b1 || b) && (!std::isnan(ar)) && (!std::isnan(ai)) && (!std::
                 isnan(br)) && (!std::isnan(bi))) {
              double sai;
              double sar;
              double sbi;
              double sbr;
              double scaleA;
              double scaleB;
              boolean_T b2;
              boolean_T finiteScale;
              sar = ar;
              sai = ai;
              scaleA = rescale(sar, sai);
              sbr = br;
              sbi = bi;
              scaleB = rescale(sbr, sbi);
              b2 = std::isinf(scaleA);
              if ((!b2) && (!std::isnan(scaleA)) && ((!std::isinf(scaleB)) &&
                   (!std::isnan(scaleB)))) {
                finiteScale = true;
              } else {
                finiteScale = false;
              }

              if (b || (b1 && finiteScale)) {
                cr = sar * sbi + sai * sbr;
                if (cr != 0.0) {
                  cr = cr * scaleA * scaleB;
                } else if ((b2 && ((br == 0.0) || (bi == 0.0))) || (std::isinf
                            (scaleB) && ((ar == 0.0) || (ai == 0.0)))) {
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
