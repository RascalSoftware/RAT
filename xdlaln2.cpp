//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xdlaln2.cpp
//
// Code generation for function 'xdlaln2'
//

// Include files
#include "xdlaln2.h"
#include "rt_nonfinite.h"
#include "xdladiv.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace reflapack
      {
        double xdlaln2(int na, int nw, double smin, const ::coder::array<double,
                       2U> &A, int ia0, int lda, const ::coder::array<double, 2U>
                       &B, int ib0, int ldb, double wr, double wi, double X[2][2],
                       double &xnorm)
        {
          static const signed char ipivot[4][4]{ { 1, 2, 3, 4 }, { 2, 1, 4, 3 },
            { 3, 4, 1, 2 }, { 4, 3, 2, 1 } };

          double scale;
          double smini;
          smini = std::fmax(smin, 4.4501477170144028E-308);
          scale = 1.0;
          if (na == 1) {
            if (nw == 1) {
              double cr21;
              double cr22;
              double ui12;
              cr21 = A[ia0 - 1] - wr;
              cr22 = std::abs(cr21);
              if (cr22 < smini) {
                cr21 = smini;
                cr22 = smini;
              }

              ui12 = std::abs(B[ib0 - 1]);
              if ((cr22 < 1.0) && (ui12 > 1.0) && (ui12 >
                   2.2471164185778949E+307 * cr22)) {
                scale = 1.0 / ui12;
              }

              (&X[0][0])[0] = B[ib0 - 1] * scale / cr21;
              xnorm = std::abs((&X[0][0])[0]);
            } else {
              double cr21;
              double cr22;
              double temp;
              double ui12;
              int cr_tmp;
              cr21 = A[ia0 - 1] - wr;
              temp = -wi;
              cr22 = std::abs(cr21) + std::abs(-wi);
              if (cr22 < smini) {
                cr21 = smini;
                temp = 0.0;
                cr22 = smini;
              }

              cr_tmp = (ib0 + ldb) - 1;
              ui12 = std::abs(B[ib0 - 1]) + std::abs(B[cr_tmp]);
              if ((cr22 < 1.0) && (ui12 > 1.0) && (ui12 >
                   2.2471164185778949E+307 * cr22)) {
                scale = 1.0 / ui12;
              }

              (&X[0][0])[0] = xdladiv(scale * B[ib0 - 1], scale * B[cr_tmp],
                cr21, temp, (&X[0][0])[2]);
              xnorm = std::abs((&X[0][0])[0]) + std::abs((&X[0][0])[2]);
            }
          } else {
            double cr[2][2];
            int cr_tmp;
            cr[0][0] = A[ia0 - 1] - wr;
            cr_tmp = ia0 + lda;
            cr[1][1] = A[cr_tmp] - wr;
            cr[0][1] = A[ia0];
            cr[1][0] = A[cr_tmp - 1];
            if (nw == 1) {
              double cmax;
              double cr21;
              int icmax;
              cmax = 0.0;
              icmax = -1;
              cr21 = std::abs((&cr[0][0])[0]);
              if (cr21 > 0.0) {
                cmax = cr21;
                icmax = 0;
              }

              cr21 = std::abs((&cr[0][0])[1]);
              if (cr21 > cmax) {
                cmax = cr21;
                icmax = 1;
              }

              cr21 = std::abs((&cr[0][0])[2]);
              if (cr21 > cmax) {
                cmax = cr21;
                icmax = 2;
              }

              cr21 = std::abs((&cr[0][0])[3]);
              if (cr21 > cmax) {
                cmax = cr21;
                icmax = 3;
              }

              if (cmax < smini) {
                double temp;
                double ui12;
                ui12 = std::fmax(std::abs(B[ib0 - 1]), std::abs(B[ib0]));
                if ((smini < 1.0) && (ui12 > 1.0) && (ui12 >
                     2.2471164185778949E+307 * smini)) {
                  scale = 1.0 / ui12;
                }

                temp = scale / smini;
                (&X[0][0])[0] = temp * B[ib0 - 1];
                (&X[0][0])[1] = temp * B[ib0];
                xnorm = temp * ui12;
              } else {
                double br1;
                double cr22;
                double lr21;
                double temp;
                double ui12;
                double ur11r;
                double ur12;
                double ur22;
                ur12 = (&cr[0][0])[ipivot[icmax][2] - 1];
                ur11r = 1.0 / (&cr[0][0])[icmax];
                lr21 = ur11r * (&cr[0][0])[ipivot[icmax][1] - 1];
                ur22 = (&cr[0][0])[ipivot[icmax][3] - 1] - ur12 * lr21;
                if (std::abs(ur22) < smini) {
                  ur22 = smini;
                }

                if ((icmax + 1 == 2) || (icmax + 1 == 4)) {
                  br1 = B[ib0];
                  ui12 = B[ib0 - 1];
                } else {
                  br1 = B[ib0 - 1];
                  ui12 = B[ib0];
                }

                ui12 -= lr21 * br1;
                temp = std::fmax(std::abs(br1 * (ur22 * ur11r)), std::abs(ui12));
                if (temp > 1.0) {
                  cr21 = std::abs(ur22);
                  if ((cr21 < 1.0) && (temp >= 2.2471164185778949E+307 * cr21))
                  {
                    scale = 1.0 / temp;
                  }
                }

                ui12 = ui12 * scale / ur22;
                cr22 = scale * br1 * ur11r - ui12 * (ur11r * ur12);
                if ((icmax + 1 == 3) || (icmax + 1 == 4)) {
                  (&X[0][0])[0] = ui12;
                  (&X[0][0])[1] = cr22;
                } else {
                  (&X[0][0])[0] = cr22;
                  (&X[0][0])[1] = ui12;
                }

                xnorm = std::fmax(std::abs(cr22), std::abs(ui12));
                if ((xnorm > 1.0) && (cmax > 1.0) && (xnorm >
                     2.2471164185778949E+307 / cmax)) {
                  temp = cmax / 2.2471164185778949E+307;
                  (&X[0][0])[0] *= temp;
                  (&X[0][0])[1] *= temp;
                  xnorm *= temp;
                  scale *= temp;
                }
              }
            } else {
              double ci[2][2];
              double cmax;
              double cr21;
              double temp;
              int icmax;
              ci[0][0] = -wi;
              ci[0][1] = 0.0;
              ci[1][0] = 0.0;
              ci[1][1] = -wi;
              cmax = 0.0;
              icmax = -1;
              cr21 = std::abs((&ci[0][0])[0]);
              temp = std::abs((&cr[0][0])[0]) + cr21;
              if (temp > 0.0) {
                cmax = temp;
                icmax = 0;
              }

              temp = std::abs((&cr[0][0])[1]);
              if (temp > cmax) {
                cmax = temp;
                icmax = 1;
              }

              temp = std::abs((&cr[0][0])[2]);
              if (temp > cmax) {
                cmax = temp;
                icmax = 2;
              }

              temp = std::abs((&cr[0][0])[3]) + cr21;
              if (temp > cmax) {
                cmax = temp;
                icmax = 3;
              }

              if (cmax < smini) {
                double ui12;
                cr_tmp = ib0 + ldb;
                ui12 = std::fmax(std::abs(B[ib0 - 1]) + std::abs(B[cr_tmp - 1]),
                                 std::abs(B[ib0]) + std::abs(B[cr_tmp]));
                if ((smini < 1.0) && (ui12 > 1.0) && (ui12 >
                     2.2471164185778949E+307 * smini)) {
                  scale = 1.0 / ui12;
                }

                temp = scale / smini;
                (&X[0][0])[0] = temp * B[ib0 - 1];
                (&X[0][0])[1] = temp * B[ib0];
                (&X[0][0])[2] = temp * B[cr_tmp - 1];
                (&X[0][0])[3] = temp * B[cr_tmp];
                xnorm = temp * ui12;
              } else {
                double br1;
                double cr22;
                double lr21;
                double ui11r;
                double ui12;
                double ui12s;
                double ur11r;
                double ur12;
                double ur12s;
                double ur22;
                int cr21_tmp;
                cr21_tmp = ipivot[icmax][1] - 1;
                cr21 = (&cr[0][0])[cr21_tmp];
                cr_tmp = ipivot[icmax][2] - 1;
                ur12 = (&cr[0][0])[cr_tmp];
                ui12 = (&ci[0][0])[cr_tmp];
                cr_tmp = ipivot[icmax][3] - 1;
                cr22 = (&cr[0][0])[cr_tmp];
                if ((icmax + 1 == 1) || (icmax + 1 == 4)) {
                  if (std::abs((&cr[0][0])[icmax]) > std::abs((&ci[0][0])[icmax]))
                  {
                    temp = (&ci[0][0])[icmax] / (&cr[0][0])[icmax];
                    ur11r = 1.0 / ((&cr[0][0])[icmax] * (temp * temp + 1.0));
                    ui11r = -temp * ur11r;
                  } else {
                    temp = (&cr[0][0])[icmax] / (&ci[0][0])[icmax];
                    ui11r = -1.0 / ((&ci[0][0])[icmax] * (temp * temp + 1.0));
                    ur11r = -temp * ui11r;
                  }

                  lr21 = cr21 * ur11r;
                  temp = cr21 * ui11r;
                  ur12s = ur12 * ur11r;
                  ui12s = ur12 * ui11r;
                  ur22 = cr22 - ur12 * lr21;
                  ur12 = (&ci[0][0])[cr_tmp] - ur12 * temp;
                } else {
                  ur11r = 1.0 / (&cr[0][0])[icmax];
                  ui11r = 0.0;
                  lr21 = cr21 * ur11r;
                  temp = (&ci[0][0])[cr21_tmp] * ur11r;
                  ur12s = ur12 * ur11r;
                  ui12s = ui12 * ur11r;
                  ur22 = (cr22 - ur12 * lr21) + ui12 * temp;
                  ur12 = -ur12 * temp - ui12 * lr21;
                }

                cr21 = std::abs(ur22) + std::abs(ur12);
                if (cr21 < smini) {
                  ur22 = smini;
                  ur12 = 0.0;
                }

                if ((icmax + 1 == 2) || (icmax + 1 == 4)) {
                  ui12 = B[ib0 - 1];
                  br1 = B[ib0];
                  cr_tmp = ib0 + ldb;
                  cr22 = B[cr_tmp - 1];
                  smini = B[cr_tmp];
                } else {
                  br1 = B[ib0 - 1];
                  ui12 = B[ib0];
                  cr_tmp = ib0 + ldb;
                  smini = B[cr_tmp - 1];
                  cr22 = B[cr_tmp];
                }

                ui12 = (ui12 - lr21 * br1) + temp * smini;
                cr22 = (cr22 - temp * br1) - lr21 * smini;
                temp = std::fmax((std::abs(br1) + std::abs(smini)) * (cr21 *
                  (std::abs(ur11r) + std::abs(ui11r))), std::abs(ui12) + std::
                                 abs(cr22));
                if ((temp > 1.0) && (cr21 < 1.0) && (temp >=
                     2.2471164185778949E+307 * cr21)) {
                  scale = 1.0 / temp;
                  br1 *= scale;
                  smini *= scale;
                  ui12 *= scale;
                  cr22 *= scale;
                }

                ui12 = xdladiv(ui12, cr22, ur22, ur12, temp);
                cr22 = ((ur11r * br1 - ui11r * smini) - ur12s * ui12) + ui12s *
                  temp;
                cr21 = ((ui11r * br1 + ur11r * smini) - ui12s * ui12) - ur12s *
                  temp;
                if ((icmax + 1 == 3) || (icmax + 1 == 4)) {
                  (&X[0][0])[0] = ui12;
                  (&X[0][0])[1] = cr22;
                  (&X[0][0])[2] = temp;
                  (&X[0][0])[3] = cr21;
                } else {
                  (&X[0][0])[0] = cr22;
                  (&X[0][0])[1] = ui12;
                  (&X[0][0])[2] = cr21;
                  (&X[0][0])[3] = temp;
                }

                xnorm = std::fmax(std::abs(cr22) + std::abs(cr21), std::abs(ui12)
                                  + std::abs(temp));
                if ((xnorm > 1.0) && (cmax > 1.0) && (xnorm >
                     2.2471164185778949E+307 / cmax)) {
                  temp = cmax / 2.2471164185778949E+307;
                  (&X[0][0])[0] *= temp;
                  (&X[0][0])[1] *= temp;
                  (&X[0][0])[2] *= temp;
                  (&X[0][0])[3] *= temp;
                  xnorm *= temp;
                  scale *= temp;
                }
              }
            }
          }

          return scale;
        }
      }
    }
  }
}

// End of code generation (xdlaln2.cpp)
