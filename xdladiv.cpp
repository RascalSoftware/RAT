//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xdladiv.cpp
//
// Code generation for function 'xdladiv'
//

// Include files
#include "xdladiv.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace reflapack
      {
        static double dladiv1(double a, double b, double c, double d, double &q);
        static double dladiv2(double a, double b, double c, double d, double r,
                              double t);
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
      namespace reflapack
      {
        static double dladiv1(double a, double b, double c, double d, double &q)
        {
          double p;
          double r;
          double t;
          r = d / c;
          t = 1.0 / (c + d * r);
          p = dladiv2(a, b, c, d, r, t);
          a = -a;
          q = dladiv2(b, a, c, d, r, t);
          return p;
        }

        static double dladiv2(double a, double b, double c, double d, double r,
                              double t)
        {
          double y;
          if (r != 0.0) {
            double br;
            br = b * r;
            if (br != 0.0) {
              y = (a + br) * t;
            } else {
              y = a * t + b * t * r;
            }
          } else {
            y = (a + d * (b / c)) * t;
          }

          return y;
        }

        double xdladiv(double a, double b, double c, double d, double &q)
        {
          double aa;
          double ab;
          double b_cd_tmp;
          double bb;
          double cc;
          double cd;
          double cd_tmp;
          double dd;
          double p;
          double s;
          aa = a;
          bb = b;
          cc = c;
          dd = d;
          ab = std::fmax(std::abs(a), std::abs(b));
          cd_tmp = std::abs(d);
          b_cd_tmp = std::abs(c);
          cd = std::fmax(b_cd_tmp, cd_tmp);
          s = 1.0;
          if (ab >= 8.9884656743115785E+307) {
            aa = 0.5 * a;
            bb = 0.5 * b;
            s = 2.0;
          }

          if (cd >= 8.9884656743115785E+307) {
            cc = 0.5 * c;
            dd = 0.5 * d;
            s *= 0.5;
          }

          if (ab <= 2.0041683600089728E-292) {
            aa *= 4.0564819207303341E+31;
            bb *= 4.0564819207303341E+31;
            s /= 4.0564819207303341E+31;
          }

          if (cd <= 2.0041683600089728E-292) {
            cc *= 4.0564819207303341E+31;
            dd *= 4.0564819207303341E+31;
            s *= 4.0564819207303341E+31;
          }

          if (cd_tmp <= b_cd_tmp) {
            p = dladiv1(aa, bb, cc, dd, q);
          } else {
            p = dladiv1(bb, aa, dd, cc, q);
            q = -q;
          }

          p *= s;
          q *= s;
          return p;
        }
      }
    }
  }
}

// End of code generation (xdladiv.cpp)
