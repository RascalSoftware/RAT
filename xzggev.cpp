//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzggev.cpp
//
// Code generation for function 'xzggev'
//

// Include files
#include "xzggev.h"
#include "rt_nonfinite.h"
#include "xzggbak.h"
#include "xzggbal.h"
#include "xzgghrd.h"
#include "xzhgeqz.h"
#include "xzlangeM.h"
#include "xzlascl.h"
#include "xztgevc.h"
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
        void xzggev(::coder::array<creal_T, 2U> &A, int *info, ::coder::array<
                    creal_T, 1U> &alpha1, ::coder::array<creal_T, 1U> &beta1, ::
                    coder::array<creal_T, 2U> &V)
        {
          ::coder::array<int, 1U> rscale;
          int i;
          int i1;
          int ihi;
          int ilo;
          int n;
          *info = 0;
          n = A.size(0) - 1;
          ilo = A.size(0);
          alpha1.set_size(ilo);
          for (i = 0; i < ilo; i++) {
            alpha1[i].re = 0.0;
            alpha1[i].im = 0.0;
          }

          ilo = A.size(0);
          beta1.set_size(ilo);
          for (i = 0; i < ilo; i++) {
            beta1[i].re = 0.0;
            beta1[i].im = 0.0;
          }

          ilo = A.size(0);
          ihi = A.size(0);
          V.set_size(ilo, ihi);
          for (i = 0; i < ihi; i++) {
            for (i1 = 0; i1 < ilo; i1++) {
              V[i1 + V.size(0) * i].re = 0.0;
              V[i1 + V.size(0) * i].im = 0.0;
            }
          }

          if ((A.size(0) != 0) && (A.size(1) != 0)) {
            double anrm;
            anrm = xzlangeM(A);
            if (std::isinf(anrm) || std::isnan(anrm)) {
              ilo = A.size(0);
              alpha1.set_size(ilo);
              for (i = 0; i < ilo; i++) {
                alpha1[i].re = rtNaN;
                alpha1[i].im = 0.0;
              }

              ilo = A.size(0);
              beta1.set_size(ilo);
              for (i = 0; i < ilo; i++) {
                beta1[i].re = rtNaN;
                beta1[i].im = 0.0;
              }

              ilo = A.size(0);
              ihi = A.size(0);
              V.set_size(ilo, ihi);
              for (i = 0; i < ihi; i++) {
                for (i1 = 0; i1 < ilo; i1++) {
                  V[i1 + V.size(0) * i].re = rtNaN;
                  V[i1 + V.size(0) * i].im = 0.0;
                }
              }
            } else {
              double anrmto;
              boolean_T ilascl;
              ilascl = false;
              anrmto = anrm;
              if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
                anrmto = 6.7178761075670888E-139;
                ilascl = true;
                xzlascl(anrm, anrmto, A);
              } else if (anrm > 1.4885657073574029E+138) {
                anrmto = 1.4885657073574029E+138;
                ilascl = true;
                xzlascl(anrm, anrmto, A);
              }

              xzggbal(A, &ilo, &ihi, rscale);
              xzgghrd(ilo, ihi, A, V);
              xzhgeqz(A, ilo, ihi, V, info, alpha1, beta1);
              if (*info == 0) {
                xztgevc(A, V);
                xzggbak(V, ilo, ihi, rscale);
                for (ilo = 0; ilo <= n; ilo++) {
                  double vtemp;
                  vtemp = std::abs(V[V.size(0) * ilo].re) + std::abs(V[V.size(0)
                    * ilo].im);
                  if (n + 1 > 1) {
                    for (ihi = 0; ihi < n; ihi++) {
                      double y;
                      y = std::abs(V[(ihi + V.size(0) * ilo) + 1].re) + std::abs
                        (V[(ihi + V.size(0) * ilo) + 1].im);
                      if (y > vtemp) {
                        vtemp = y;
                      }
                    }
                  }

                  if (vtemp >= 6.7178761075670888E-139) {
                    vtemp = 1.0 / vtemp;
                    for (ihi = 0; ihi <= n; ihi++) {
                      V[ihi + V.size(0) * ilo].re = vtemp * V[ihi + V.size(0) *
                        ilo].re;
                      V[ihi + V.size(0) * ilo].im = vtemp * V[ihi + V.size(0) *
                        ilo].im;
                    }
                  }
                }

                if (ilascl) {
                  xzlascl(anrmto, anrm, alpha1);
                }
              }
            }
          }
        }
      }
    }
  }
}

// End of code generation (xzggev.cpp)
