//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xgeev.cpp
//
// Code generation for function 'xgeev'
//

// Include files
#include "xgeev.h"
#include "RATMain_rtwutil.h"
#include "ixamax.h"
#include "rt_nonfinite.h"
#include "xdlahqr.h"
#include "xdtrevc3.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xzgebak.h"
#include "xzgebal.h"
#include "xzgehrd.h"
#include "xzlangeM.h"
#include "xzlartg.h"
#include "xzlascl.h"
#include "xzunghr.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace lapack
      {
        int xgeev(const ::coder::array<double, 2U> &A, ::coder::array<creal_T,
                  1U> &W, ::coder::array<creal_T, 2U> &VR)
        {
          ::coder::array<double, 2U> b_A;
          ::coder::array<double, 2U> vr;
          ::coder::array<double, 1U> scale;
          ::coder::array<double, 1U> wi;
          ::coder::array<double, 1U> wr;
          double sn;
          int b_loop_ub;
          int i;
          int ihi;
          int info;
          int loop_ub;
          int n;
          b_A.set_size(A.size(0), A.size(1));
          loop_ub = A.size(1);
          for (i = 0; i < loop_ub; i++) {
            b_loop_ub = A.size(0);
            for (int b_i{0}; b_i < b_loop_ub; b_i++) {
              b_A[b_i + b_A.size(0) * i] = A[b_i + A.size(0) * i];
            }
          }

          info = 0;
          n = A.size(0);
          W.set_size(A.size(0));
          VR.set_size(A.size(0), A.size(0));
          if (A.size(0) != 0) {
            double anrm;
            anrm = reflapack::xzlangeM(A);
            if (std::isinf(anrm) || std::isnan(anrm)) {
              W.set_size(A.size(0));
              loop_ub = A.size(0);
              for (i = 0; i < loop_ub; i++) {
                W[i].re = rtNaN;
                W[i].im = 0.0;
              }

              loop_ub = A.size(0);
              b_loop_ub = A.size(0);
              VR.set_size(A.size(0), A.size(0));
              for (i = 0; i < b_loop_ub; i++) {
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  VR[b_i + VR.size(0) * i].re = rtNaN;
                  VR[b_i + VR.size(0) * i].im = 0.0;
                }
              }
            } else {
              double cscale;
              int ilo;
              boolean_T guard1;
              boolean_T scalea;
              cscale = anrm;
              scalea = false;
              guard1 = false;
              if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
                scalea = true;
                cscale = 6.7178761075670888E-139;
                guard1 = true;
              } else if (anrm > 1.4885657073574029E+138) {
                scalea = true;
                cscale = 1.4885657073574029E+138;
                guard1 = true;
              }

              if (guard1) {
                b_A.set_size(A.size(0), A.size(1));
                loop_ub = A.size(1);
                for (i = 0; i < loop_ub; i++) {
                  b_loop_ub = A.size(0);
                  for (int b_i{0}; b_i < b_loop_ub; b_i++) {
                    b_A[b_i + b_A.size(0) * i] = A[b_i + A.size(0) * i];
                  }
                }

                reflapack::xzlascl(anrm, cscale, A.size(0), A.size(0), b_A,
                                   A.size(0));
              }

              ilo = reflapack::xzgebal(b_A, scale, ihi);
              reflapack::xzgehrd(b_A, ilo, ihi, wr);
              vr.set_size(b_A.size(0), b_A.size(1));
              loop_ub = b_A.size(1);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = b_A.size(0);
                for (int b_i{0}; b_i < b_loop_ub; b_i++) {
                  vr[b_i + vr.size(0) * i] = b_A[b_i + b_A.size(0) * i];
                }
              }

              reflapack::xzunghr(A.size(0), ilo, ihi, vr, A.size(0), wr);
              info = reflapack::xdlahqr(ilo, ihi, b_A, ilo, ihi, vr, wr, wi);
              if (info == 0) {
                double scl;
                reflapack::xdtrevc3(b_A, vr);
                reflapack::xzgebak(ilo, ihi, scale, vr);
                for (int b_i{0}; b_i < n; b_i++) {
                  if (!(wi[b_i] < 0.0)) {
                    if ((b_i + 1 != n) && (wi[b_i] > 0.0)) {
                      loop_ub = b_i * n;
                      b_loop_ub = (b_i + 1) * n;
                      scl = 1.0 / rt_hypotd_snf(blas::xnrm2(n, vr, loop_ub + 1),
                        blas::xnrm2(n, vr, b_loop_ub + 1));
                      i = loop_ub + n;
                      for (ihi = loop_ub + 1; ihi <= i; ihi++) {
                        vr[ihi - 1] = scl * vr[ihi - 1];
                      }

                      i = b_loop_ub + n;
                      for (ihi = b_loop_ub + 1; ihi <= i; ihi++) {
                        vr[ihi - 1] = scl * vr[ihi - 1];
                      }

                      for (ihi = 0; ihi < n; ihi++) {
                        scl = vr[ihi + vr.size(0) * b_i];
                        sn = vr[ihi + vr.size(0) * (b_i + 1)];
                        scale[ihi] = scl * scl + sn * sn;
                      }

                      ihi = blas::ixamax(n, scale) - 1;
                      scl = reflapack::xzlartg(vr[ihi + vr.size(0) * b_i],
                        vr[ihi + vr.size(0) * (b_i + 1)], sn);
                      blas::xrot(n, vr, loop_ub + 1, b_loop_ub + 1, scl, sn);
                      vr[ihi + vr.size(0) * (b_i + 1)] = 0.0;
                    } else {
                      loop_ub = b_i * n;
                      scl = 1.0 / blas::xnrm2(n, vr, loop_ub + 1);
                      i = loop_ub + n;
                      for (ihi = loop_ub + 1; ihi <= i; ihi++) {
                        vr[ihi - 1] = scl * vr[ihi - 1];
                      }
                    }
                  }
                }

                VR.set_size(vr.size(0), vr.size(1));
                loop_ub = vr.size(1);
                for (i = 0; i < loop_ub; i++) {
                  b_loop_ub = vr.size(0);
                  for (int b_i{0}; b_i < b_loop_ub; b_i++) {
                    VR[b_i + VR.size(0) * i].re = vr[b_i + vr.size(0) * i];
                    VR[b_i + VR.size(0) * i].im = 0.0;
                  }
                }

                for (ihi = 2; ihi <= n; ihi++) {
                  if ((wi[ihi - 2] > 0.0) && (wi[ihi - 1] < 0.0)) {
                    for (int b_i{0}; b_i < n; b_i++) {
                      scl = VR[b_i + VR.size(0) * (ihi - 2)].re;
                      sn = VR[b_i + VR.size(0) * (ihi - 1)].re;
                      VR[b_i + VR.size(0) * (ihi - 2)].re = scl;
                      VR[b_i + VR.size(0) * (ihi - 2)].im = sn;
                      VR[b_i + VR.size(0) * (ihi - 1)].re = scl;
                      VR[b_i + VR.size(0) * (ihi - 1)].im = -sn;
                    }
                  }
                }
              } else {
                loop_ub = A.size(0);
                b_loop_ub = A.size(0);
                VR.set_size(A.size(0), A.size(0));
                for (i = 0; i < b_loop_ub; i++) {
                  for (int b_i{0}; b_i < loop_ub; b_i++) {
                    VR[b_i + VR.size(0) * i].re = rtNaN;
                    VR[b_i + VR.size(0) * i].im = 0.0;
                  }
                }
              }

              if (scalea) {
                i = A.size(0) - info;
                reflapack::xzlascl(cscale, anrm, i, wr, info + 1);
                reflapack::xzlascl(cscale, anrm, i, wi, info + 1);
                if (info != 0) {
                  reflapack::xzlascl(cscale, anrm, ilo - 1, wr, 1);
                  reflapack::xzlascl(cscale, anrm, ilo - 1, wi, 1);
                }
              }

              if (info != 0) {
                for (int b_i{ilo}; b_i <= info; b_i++) {
                  wr[b_i - 1] = rtNaN;
                  wi[b_i - 1] = 0.0;
                }
              }

              W.set_size(wr.size(0));
              loop_ub = wr.size(0);
              for (i = 0; i < loop_ub; i++) {
                W[i].re = wr[i];
                W[i].im = wi[i];
              }
            }
          }

          return info;
        }
      }
    }
  }
}

// End of code generation (xgeev.cpp)
