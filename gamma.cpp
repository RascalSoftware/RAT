//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// gamma.cpp
//
// Code generation for function 'gamma'
//

// Include files
#include "gamma.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_gamma(double &x)
    {
      static const double gam[23]{ 1.0, 1.0, 2.0, 6.0, 24.0, 120.0, 720.0,
        5040.0, 40320.0, 362880.0, 3.6288E+6, 3.99168E+7, 4.790016E+8,
        6.2270208E+9, 8.71782912E+10, 1.307674368E+12, 2.0922789888E+13,
        3.55687428096E+14, 6.402373705728E+15, 1.21645100408832E+17,
        2.43290200817664E+18, 5.109094217170944E+19, 1.1240007277776077E+21 };

      static const double p[8]{ -1.716185138865495, 24.76565080557592,
        -379.80425647094563, 629.3311553128184, 866.96620279041326,
        -31451.272968848367, -36144.413418691176, 66456.143820240541 };

      static const double q[8]{ -30.840230011973897, 315.35062697960416,
        -1015.1563674902192, -3107.7716715723109, 22538.11842098015,
        4755.8462775278813, -134659.95986496931, -115132.25967555349 };

      static const double c[7]{ -0.001910444077728, 0.00084171387781295,
        -0.00059523799130430121, 0.0007936507935003503, -0.0027777777777776816,
        0.083333333333333329, 0.0057083835261 };

      if ((x <= 23.0) && (x == std::floor(x))) {
        x = gam[static_cast<int>(x) - 1];
      } else if (std::isnan(x)) {
        x = rtNaN;
      } else if (std::isinf(x)) {
        x = rtInf;
      } else {
        double ysq;
        if (x < 12.0) {
          double b_sum;
          double xkold;
          double y;
          int i;
          xkold = x;
          y = std::floor(x);
          x -= y - 1.0;
          ysq = 0.0 * (x - 1.0);
          b_sum = 1.0;
          for (i = 0; i < 8; i++) {
            ysq = (ysq + p[i]) * (x - 1.0);
            b_sum = b_sum * (x - 1.0) + q[i];
          }

          ysq = ysq / b_sum + 1.0;
          if (xkold < x) {
            ysq /= xkold;
          } else if (xkold > x) {
            i = static_cast<int>(y - 1.0);
            for (int j{0}; j < i; j++) {
              ysq *= x;
              x++;
            }
          }
        } else {
          double b_sum;
          ysq = x * x;
          b_sum = 0.0057083835261;
          for (int i{0}; i < 6; i++) {
            b_sum = b_sum / ysq + c[i];
          }

          b_sum = (b_sum / x - x) + 0.91893853320467278;
          b_sum += (x - 0.5) * std::log(x);
          ysq = std::exp(b_sum);
        }

        x = ysq;
      }
    }
  }
}

// End of code generation (gamma.cpp)
