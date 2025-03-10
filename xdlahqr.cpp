//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xdlahqr.cpp
//
// Code generation for function 'xdlahqr'
//

// Include files
#include "xdlahqr.h"
#include "rt_nonfinite.h"
#include "xdlanv2.h"
#include "xrot.h"
#include "xzlarfg.h"
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
        int xdlahqr(int ilo, int ihi, ::coder::array<double, 2U> &h, int iloz,
                    int ihiz, ::coder::array<double, 2U> &z, ::coder::array<
                    double, 1U> &wr, ::coder::array<double, 1U> &wi)
        {
          double d;
          double h12;
          double h22;
          double rt1r;
          double rt2r;
          double s;
          double tr;
          double tst;
          int info;
          int n;
          n = h.size(0);
          wr.set_size(h.size(0));
          wi.set_size(wr.size(0));
          info = 0;
          if ((h.size(0) != 0) && (h.size(1) != 0)) {
            int i;
            int ix0;
            for (i = 0; i <= ilo - 2; i++) {
              wr[i] = h[i + h.size(0) * i];
              wi[i] = 0.0;
            }

            ix0 = ihi + 1;
            for (i = ix0; i <= n; i++) {
              wr[i - 1] = h[(i + h.size(0) * (i - 1)) - 1];
              wi[i - 1] = 0.0;
            }

            if (ilo == ihi) {
              wr[ilo - 1] = h[(ilo + h.size(0) * (ilo - 1)) - 1];
              wi[ilo - 1] = 0.0;
            } else {
              double smlnum;
              int itmax;
              int kdefl;
              int nh;
              int nz;
              boolean_T exitg1;
              ix0 = ihi - 3;
              for (nh = ilo; nh <= ix0; nh++) {
                h[(nh + h.size(0) * (nh - 1)) + 1] = 0.0;
                h[(nh + h.size(0) * (nh - 1)) + 2] = 0.0;
              }

              if (ilo <= ihi - 2) {
                h[(ihi + h.size(0) * (ihi - 3)) - 1] = 0.0;
              }

              nh = (ihi - ilo) + 1;
              nz = (ihiz - iloz) + 1;
              smlnum = 2.2250738585072014E-308 * (static_cast<double>(nh) /
                2.2204460492503131E-16);
              if (nh < 10) {
                nh = 10;
              }

              itmax = 30 * nh;
              kdefl = 0;
              i = ihi - 1;
              exitg1 = false;
              while ((!exitg1) && (i + 1 >= ilo)) {
                double aa;
                int its;
                int l;
                boolean_T converged;
                boolean_T exitg2;
                l = ilo;
                converged = false;
                its = 0;
                exitg2 = false;
                while ((!exitg2) && (its <= itmax)) {
                  int k;
                  boolean_T exitg3;
                  k = i;
                  exitg3 = false;
                  while ((!exitg3) && (k + 1 > l)) {
                    d = std::abs(h[k + h.size(0) * (k - 1)]);
                    if (d <= smlnum) {
                      exitg3 = true;
                    } else {
                      h12 = std::abs(h[k + h.size(0) * k]);
                      aa = h[(k + h.size(0) * (k - 1)) - 1];
                      tst = std::abs(aa) + h12;
                      if (tst == 0.0) {
                        if (k - 1 >= ilo) {
                          tst = std::abs(h[(k + h.size(0) * (k - 2)) - 1]);
                        }

                        if (k + 2 <= ihi) {
                          tst += std::abs(h[(k + h.size(0) * k) + 1]);
                        }
                      }

                      if (d <= 2.2204460492503131E-16 * tst) {
                        tr = std::abs(h[(k + h.size(0) * k) - 1]);
                        tst = std::abs(aa - h[k + h.size(0) * k]);
                        aa = std::fmax(h12, tst);
                        tst = std::fmin(h12, tst);
                        s = aa + tst;
                        if (std::fmin(d, tr) * (std::fmax(d, tr) / s) <= std::
                            fmax(smlnum, 2.2204460492503131E-16 * (tst * (aa / s))))
                        {
                          exitg3 = true;
                        } else {
                          k--;
                        }
                      } else {
                        k--;
                      }
                    }
                  }

                  l = k + 1;
                  if (k + 1 > ilo) {
                    h[k + h.size(0) * (k - 1)] = 0.0;
                  }

                  if (k + 1 >= i) {
                    converged = true;
                    exitg2 = true;
                  } else {
                    double v[3];
                    int m;
                    kdefl++;
                    if (kdefl - kdefl / 20 * 20 == 0) {
                      s = std::abs(h[i + h.size(0) * (i - 1)]) + std::abs(h[(i +
                        h.size(0) * (i - 2)) - 1]);
                      tst = 0.75 * s + h[i + h.size(0) * i];
                      h12 = -0.4375 * s;
                      aa = s;
                      h22 = tst;
                    } else if (kdefl - kdefl / 10 * 10 == 0) {
                      s = std::abs(h[(k + h.size(0) * k) + 1]) + std::abs(h[(k +
                        h.size(0) * (k + 1)) + 2]);
                      tst = 0.75 * s + h[k + h.size(0) * k];
                      h12 = -0.4375 * s;
                      aa = s;
                      h22 = tst;
                    } else {
                      tst = h[(i + h.size(0) * (i - 1)) - 1];
                      aa = h[i + h.size(0) * (i - 1)];
                      h12 = h[(i + h.size(0) * i) - 1];
                      h22 = h[i + h.size(0) * i];
                    }

                    s = ((std::abs(tst) + std::abs(h12)) + std::abs(aa)) + std::
                      abs(h22);
                    if (s == 0.0) {
                      rt1r = 0.0;
                      h12 = 0.0;
                      rt2r = 0.0;
                      aa = 0.0;
                    } else {
                      tst /= s;
                      aa /= s;
                      h12 /= s;
                      h22 /= s;
                      tr = (tst + h22) / 2.0;
                      tst = (tst - tr) * (h22 - tr) - h12 * aa;
                      h12 = std::sqrt(std::abs(tst));
                      if (tst >= 0.0) {
                        rt1r = tr * s;
                        rt2r = rt1r;
                        h12 *= s;
                        aa = -h12;
                      } else {
                        rt1r = tr + h12;
                        rt2r = tr - h12;
                        if (std::abs(rt1r - h22) <= std::abs(rt2r - h22)) {
                          rt1r *= s;
                          rt2r = rt1r;
                        } else {
                          rt2r *= s;
                          rt1r = rt2r;
                        }

                        h12 = 0.0;
                        aa = 0.0;
                      }
                    }

                    m = i - 1;
                    exitg3 = false;
                    while ((!exitg3) && (m >= k + 1)) {
                      tst = h[m + h.size(0) * (m - 1)];
                      tr = h[(m + h.size(0) * (m - 1)) - 1];
                      h22 = tr - rt2r;
                      s = (std::abs(h22) + std::abs(aa)) + std::abs(tst);
                      tst /= s;
                      v[0] = (tst * h[(m + h.size(0) * m) - 1] + h22 * (h22 / s))
                        - h12 * (aa / s);
                      v[1] = tst * (((tr + h[m + h.size(0) * m]) - rt1r) - rt2r);
                      v[2] = tst * h[(m + h.size(0) * m) + 1];
                      s = (std::abs(v[0]) + std::abs(v[1])) + std::abs(v[2]);
                      v[0] /= s;
                      v[1] /= s;
                      v[2] /= s;
                      if ((m == k + 1) || (std::abs(h[(m + h.size(0) * (m - 2))
                            - 1]) * (std::abs(v[1]) + std::abs(v[2])) <=
                                           2.2204460492503131E-16 * std::abs(v[0])
                                           * ((std::abs(h[(m + h.size(0) * (m -
                                2)) - 2]) + std::abs(tr)) + std::abs(h[m +
                             h.size(0) * m])))) {
                        exitg3 = true;
                      } else {
                        m--;
                      }
                    }

                    for (int b_k{m}; b_k <= i; b_k++) {
                      nh = (i - b_k) + 2;
                      if (nh >= 3) {
                        nh = 3;
                      }

                      if (b_k > m) {
                        ix0 = ((b_k - 2) * n + b_k) - 1;
                        for (int c_k{0}; c_k < nh; c_k++) {
                          v[c_k] = h[ix0 + c_k];
                        }
                      }

                      tst = v[0];
                      tr = xzlarfg(nh, tst, v);
                      if (b_k > m) {
                        h[(b_k + h.size(0) * (b_k - 2)) - 1] = tst;
                        h[b_k + h.size(0) * (b_k - 2)] = 0.0;
                        if (b_k < i) {
                          h[(b_k + h.size(0) * (b_k - 2)) + 1] = 0.0;
                        }
                      } else if (m > k + 1) {
                        h[(b_k + h.size(0) * (b_k - 2)) - 1] = h[(b_k + h.size(0)
                          * (b_k - 2)) - 1] * (1.0 - tr);
                      }

                      d = v[1];
                      tst = tr * v[1];
                      if (nh == 3) {
                        h22 = v[2];
                        aa = tr * v[2];
                        for (nh = b_k; nh <= n; nh++) {
                          rt2r = h[(b_k + h.size(0) * (nh - 1)) - 1];
                          rt1r = h[b_k + h.size(0) * (nh - 1)];
                          s = h[(b_k + h.size(0) * (nh - 1)) + 1];
                          h12 = (rt2r + d * rt1r) + h22 * s;
                          rt2r -= h12 * tr;
                          h[(b_k + h.size(0) * (nh - 1)) - 1] = rt2r;
                          rt1r -= h12 * tst;
                          h[b_k + h.size(0) * (nh - 1)] = rt1r;
                          s -= h12 * aa;
                          h[(b_k + h.size(0) * (nh - 1)) + 1] = s;
                        }

                        if (b_k + 3 <= i + 1) {
                          ix0 = b_k + 2;
                        } else {
                          ix0 = i;
                        }

                        for (nh = 0; nh <= ix0; nh++) {
                          rt2r = h[nh + h.size(0) * (b_k - 1)];
                          rt1r = h[nh + h.size(0) * b_k];
                          s = h[nh + h.size(0) * (b_k + 1)];
                          h12 = (rt2r + d * rt1r) + h22 * s;
                          rt2r -= h12 * tr;
                          h[nh + h.size(0) * (b_k - 1)] = rt2r;
                          rt1r -= h12 * tst;
                          h[nh + h.size(0) * b_k] = rt1r;
                          s -= h12 * aa;
                          h[nh + h.size(0) * (b_k + 1)] = s;
                        }

                        for (nh = iloz; nh <= ihiz; nh++) {
                          rt2r = z[(nh + z.size(0) * (b_k - 1)) - 1];
                          rt1r = z[(nh + z.size(0) * b_k) - 1];
                          s = z[(nh + z.size(0) * (b_k + 1)) - 1];
                          h12 = (rt2r + d * rt1r) + h22 * s;
                          rt2r -= h12 * tr;
                          z[(nh + z.size(0) * (b_k - 1)) - 1] = rt2r;
                          rt1r -= h12 * tst;
                          z[(nh + z.size(0) * b_k) - 1] = rt1r;
                          s -= h12 * aa;
                          z[(nh + z.size(0) * (b_k + 1)) - 1] = s;
                        }
                      } else if (nh == 2) {
                        for (nh = b_k; nh <= n; nh++) {
                          h22 = h[(b_k + h.size(0) * (nh - 1)) - 1];
                          rt2r = h[b_k + h.size(0) * (nh - 1)];
                          h12 = h22 + d * rt2r;
                          h22 -= h12 * tr;
                          h[(b_k + h.size(0) * (nh - 1)) - 1] = h22;
                          rt2r -= h12 * tst;
                          h[b_k + h.size(0) * (nh - 1)] = rt2r;
                        }

                        for (nh = 0; nh <= i; nh++) {
                          h22 = h[nh + h.size(0) * (b_k - 1)];
                          rt2r = h[nh + h.size(0) * b_k];
                          h12 = h22 + d * rt2r;
                          h22 -= h12 * tr;
                          h[nh + h.size(0) * (b_k - 1)] = h22;
                          rt2r -= h12 * tst;
                          h[nh + h.size(0) * b_k] = rt2r;
                        }

                        for (nh = iloz; nh <= ihiz; nh++) {
                          h22 = z[(nh + z.size(0) * (b_k - 1)) - 1];
                          rt2r = z[(nh + z.size(0) * b_k) - 1];
                          h12 = h22 + d * rt2r;
                          h22 -= h12 * tr;
                          z[(nh + z.size(0) * (b_k - 1)) - 1] = h22;
                          rt2r -= h12 * tst;
                          z[(nh + z.size(0) * b_k) - 1] = rt2r;
                        }
                      }
                    }

                    its++;
                  }
                }

                if (!converged) {
                  info = i + 1;
                  exitg1 = true;
                } else {
                  if (l == i + 1) {
                    wr[i] = h[i + h.size(0) * i];
                    wi[i] = 0.0;
                  } else if (l == i) {
                    d = h[(i + h.size(0) * i) - 1];
                    h22 = h[i + h.size(0) * (i - 1)];
                    rt2r = h[i + h.size(0) * i];
                    aa = xdlanv2(&h[(i + h.size(0) * (i - 1)) - 1], d, h22, rt2r,
                                 tr, rt1r, s, tst, h12);
                    wi[i - 1] = tr;
                    wr[i - 1] = aa;
                    wr[i] = rt1r;
                    wi[i] = s;
                    h[(i + h.size(0) * i) - 1] = d;
                    h[i + h.size(0) * (i - 1)] = h22;
                    h[i + h.size(0) * i] = rt2r;
                    if (n > i + 1) {
                      ix0 = (i + 1) * n + i;
                      blas::xrot((n - i) - 1, h, ix0, n, ix0 + 1, n, tst, h12);
                    }

                    ix0 = (i - 1) * n;
                    nh = i * n;
                    blas::xrot(i - 1, h, ix0 + 1, nh + 1, tst, h12);
                    blas::xrot(nz, z, ix0 + iloz, nh + iloz, tst, h12);
                  }

                  kdefl = 0;
                  i = l - 2;
                }
              }

              if (n > 2) {
                for (nh = 3; nh <= n; nh++) {
                  for (i = nh; i <= n; i++) {
                    h[(i + h.size(0) * (nh - 3)) - 1] = 0.0;
                  }
                }
              }
            }
          }

          return info;
        }

        int xdlahqr(int ihi, ::coder::array<double, 2U> &h, int ihiz, ::coder::
                    array<double, 2U> &z, ::coder::array<double, 1U> &wr, ::
                    coder::array<double, 1U> &wi)
        {
          double d;
          double h12;
          double h22;
          double rt1r;
          double rt2r;
          double s;
          double tr;
          double tst;
          int info;
          int n;
          n = h.size(0);
          wr.set_size(h.size(0));
          wi.set_size(wr.size(0));
          info = 0;
          if ((h.size(0) != 0) && (h.size(1) != 0)) {
            int i;
            int ix0;
            ix0 = ihi + 1;
            for (i = ix0; i <= n; i++) {
              wr[i - 1] = h[(i + h.size(0) * (i - 1)) - 1];
              wi[i - 1] = 0.0;
            }

            if (ihi == 1) {
              wr[0] = h[0];
              wi[0] = 0.0;
            } else {
              double smlnum;
              int itmax;
              int kdefl;
              int nr;
              boolean_T exitg1;
              for (nr = 0; nr <= ihi - 4; nr++) {
                h[(nr + h.size(0) * nr) + 2] = 0.0;
                h[(nr + h.size(0) * nr) + 3] = 0.0;
              }

              if (ihi - 2 >= 1) {
                h[(ihi + h.size(0) * (ihi - 3)) - 1] = 0.0;
              }

              smlnum = 2.2250738585072014E-308 * (static_cast<double>(ihi) /
                2.2204460492503131E-16);
              if (ihi >= 10) {
                nr = ihi;
              } else {
                nr = 10;
              }

              itmax = 30 * nr;
              kdefl = 0;
              i = ihi - 1;
              exitg1 = false;
              while ((!exitg1) && (i + 1 >= 1)) {
                double aa;
                int its;
                int l;
                boolean_T converged;
                boolean_T exitg2;
                l = 1;
                converged = false;
                its = 0;
                exitg2 = false;
                while ((!exitg2) && (its <= itmax)) {
                  int k;
                  boolean_T exitg3;
                  k = i;
                  exitg3 = false;
                  while ((!exitg3) && (k + 1 > l)) {
                    d = std::abs(h[k + h.size(0) * (k - 1)]);
                    if (d <= smlnum) {
                      exitg3 = true;
                    } else {
                      h12 = std::abs(h[k + h.size(0) * k]);
                      aa = h[(k + h.size(0) * (k - 1)) - 1];
                      tst = std::abs(aa) + h12;
                      if (tst == 0.0) {
                        if (k - 1 >= 1) {
                          tst = std::abs(h[(k + h.size(0) * (k - 2)) - 1]);
                        }

                        if (k + 2 <= ihi) {
                          tst += std::abs(h[(k + h.size(0) * k) + 1]);
                        }
                      }

                      if (d <= 2.2204460492503131E-16 * tst) {
                        tr = std::abs(h[(k + h.size(0) * k) - 1]);
                        tst = std::abs(aa - h[k + h.size(0) * k]);
                        aa = std::fmax(h12, tst);
                        tst = std::fmin(h12, tst);
                        s = aa + tst;
                        if (std::fmin(d, tr) * (std::fmax(d, tr) / s) <= std::
                            fmax(smlnum, 2.2204460492503131E-16 * (tst * (aa / s))))
                        {
                          exitg3 = true;
                        } else {
                          k--;
                        }
                      } else {
                        k--;
                      }
                    }
                  }

                  l = k + 1;
                  if (k + 1 > 1) {
                    h[k + h.size(0) * (k - 1)] = 0.0;
                  }

                  if (k + 1 >= i) {
                    converged = true;
                    exitg2 = true;
                  } else {
                    double v[3];
                    int m;
                    kdefl++;
                    if (kdefl - kdefl / 20 * 20 == 0) {
                      s = std::abs(h[i + h.size(0) * (i - 1)]) + std::abs(h[(i +
                        h.size(0) * (i - 2)) - 1]);
                      tst = 0.75 * s + h[i + h.size(0) * i];
                      h12 = -0.4375 * s;
                      aa = s;
                      h22 = tst;
                    } else if (kdefl - kdefl / 10 * 10 == 0) {
                      s = std::abs(h[(k + h.size(0) * k) + 1]) + std::abs(h[(k +
                        h.size(0) * (k + 1)) + 2]);
                      tst = 0.75 * s + h[k + h.size(0) * k];
                      h12 = -0.4375 * s;
                      aa = s;
                      h22 = tst;
                    } else {
                      tst = h[(i + h.size(0) * (i - 1)) - 1];
                      aa = h[i + h.size(0) * (i - 1)];
                      h12 = h[(i + h.size(0) * i) - 1];
                      h22 = h[i + h.size(0) * i];
                    }

                    s = ((std::abs(tst) + std::abs(h12)) + std::abs(aa)) + std::
                      abs(h22);
                    if (s == 0.0) {
                      rt1r = 0.0;
                      h12 = 0.0;
                      rt2r = 0.0;
                      aa = 0.0;
                    } else {
                      tst /= s;
                      aa /= s;
                      h12 /= s;
                      h22 /= s;
                      tr = (tst + h22) / 2.0;
                      tst = (tst - tr) * (h22 - tr) - h12 * aa;
                      h12 = std::sqrt(std::abs(tst));
                      if (tst >= 0.0) {
                        rt1r = tr * s;
                        rt2r = rt1r;
                        h12 *= s;
                        aa = -h12;
                      } else {
                        rt1r = tr + h12;
                        rt2r = tr - h12;
                        if (std::abs(rt1r - h22) <= std::abs(rt2r - h22)) {
                          rt1r *= s;
                          rt2r = rt1r;
                        } else {
                          rt2r *= s;
                          rt1r = rt2r;
                        }

                        h12 = 0.0;
                        aa = 0.0;
                      }
                    }

                    m = i - 1;
                    exitg3 = false;
                    while ((!exitg3) && (m >= k + 1)) {
                      tst = h[m + h.size(0) * (m - 1)];
                      tr = h[(m + h.size(0) * (m - 1)) - 1];
                      h22 = tr - rt2r;
                      s = (std::abs(h22) + std::abs(aa)) + std::abs(tst);
                      tst /= s;
                      v[0] = (tst * h[(m + h.size(0) * m) - 1] + h22 * (h22 / s))
                        - h12 * (aa / s);
                      v[1] = tst * (((tr + h[m + h.size(0) * m]) - rt1r) - rt2r);
                      v[2] = tst * h[(m + h.size(0) * m) + 1];
                      s = (std::abs(v[0]) + std::abs(v[1])) + std::abs(v[2]);
                      v[0] /= s;
                      v[1] /= s;
                      v[2] /= s;
                      if ((m == k + 1) || (std::abs(h[(m + h.size(0) * (m - 2))
                            - 1]) * (std::abs(v[1]) + std::abs(v[2])) <=
                                           2.2204460492503131E-16 * std::abs(v[0])
                                           * ((std::abs(h[(m + h.size(0) * (m -
                                2)) - 2]) + std::abs(tr)) + std::abs(h[m +
                             h.size(0) * m])))) {
                        exitg3 = true;
                      } else {
                        m--;
                      }
                    }

                    for (int b_k{m}; b_k <= i; b_k++) {
                      nr = (i - b_k) + 2;
                      if (nr >= 3) {
                        nr = 3;
                      }

                      if (b_k > m) {
                        ix0 = ((b_k - 2) * n + b_k) - 1;
                        for (int c_k{0}; c_k < nr; c_k++) {
                          v[c_k] = h[ix0 + c_k];
                        }
                      }

                      tst = v[0];
                      tr = xzlarfg(nr, tst, v);
                      if (b_k > m) {
                        h[(b_k + h.size(0) * (b_k - 2)) - 1] = tst;
                        h[b_k + h.size(0) * (b_k - 2)] = 0.0;
                        if (b_k < i) {
                          h[(b_k + h.size(0) * (b_k - 2)) + 1] = 0.0;
                        }
                      } else if (m > k + 1) {
                        h[(b_k + h.size(0) * (b_k - 2)) - 1] = h[(b_k + h.size(0)
                          * (b_k - 2)) - 1] * (1.0 - tr);
                      }

                      d = v[1];
                      tst = tr * v[1];
                      if (nr == 3) {
                        h22 = v[2];
                        aa = tr * v[2];
                        for (nr = b_k; nr <= n; nr++) {
                          rt2r = h[(b_k + h.size(0) * (nr - 1)) - 1];
                          rt1r = h[b_k + h.size(0) * (nr - 1)];
                          s = h[(b_k + h.size(0) * (nr - 1)) + 1];
                          h12 = (rt2r + d * rt1r) + h22 * s;
                          rt2r -= h12 * tr;
                          h[(b_k + h.size(0) * (nr - 1)) - 1] = rt2r;
                          rt1r -= h12 * tst;
                          h[b_k + h.size(0) * (nr - 1)] = rt1r;
                          s -= h12 * aa;
                          h[(b_k + h.size(0) * (nr - 1)) + 1] = s;
                        }

                        if (b_k + 3 <= i + 1) {
                          ix0 = b_k + 2;
                        } else {
                          ix0 = i;
                        }

                        for (nr = 0; nr <= ix0; nr++) {
                          rt2r = h[nr + h.size(0) * (b_k - 1)];
                          rt1r = h[nr + h.size(0) * b_k];
                          s = h[nr + h.size(0) * (b_k + 1)];
                          h12 = (rt2r + d * rt1r) + h22 * s;
                          rt2r -= h12 * tr;
                          h[nr + h.size(0) * (b_k - 1)] = rt2r;
                          rt1r -= h12 * tst;
                          h[nr + h.size(0) * b_k] = rt1r;
                          s -= h12 * aa;
                          h[nr + h.size(0) * (b_k + 1)] = s;
                        }

                        for (nr = 0; nr < ihiz; nr++) {
                          rt2r = z[nr + z.size(0) * (b_k - 1)];
                          rt1r = z[nr + z.size(0) * b_k];
                          s = z[nr + z.size(0) * (b_k + 1)];
                          h12 = (rt2r + d * rt1r) + h22 * s;
                          rt2r -= h12 * tr;
                          z[nr + z.size(0) * (b_k - 1)] = rt2r;
                          rt1r -= h12 * tst;
                          z[nr + z.size(0) * b_k] = rt1r;
                          s -= h12 * aa;
                          z[nr + z.size(0) * (b_k + 1)] = s;
                        }
                      } else if (nr == 2) {
                        for (nr = b_k; nr <= n; nr++) {
                          h22 = h[(b_k + h.size(0) * (nr - 1)) - 1];
                          rt2r = h[b_k + h.size(0) * (nr - 1)];
                          h12 = h22 + d * rt2r;
                          h22 -= h12 * tr;
                          h[(b_k + h.size(0) * (nr - 1)) - 1] = h22;
                          rt2r -= h12 * tst;
                          h[b_k + h.size(0) * (nr - 1)] = rt2r;
                        }

                        for (nr = 0; nr <= i; nr++) {
                          h22 = h[nr + h.size(0) * (b_k - 1)];
                          rt2r = h[nr + h.size(0) * b_k];
                          h12 = h22 + d * rt2r;
                          h22 -= h12 * tr;
                          h[nr + h.size(0) * (b_k - 1)] = h22;
                          rt2r -= h12 * tst;
                          h[nr + h.size(0) * b_k] = rt2r;
                        }

                        for (nr = 0; nr < ihiz; nr++) {
                          h22 = z[nr + z.size(0) * (b_k - 1)];
                          rt2r = z[nr + z.size(0) * b_k];
                          h12 = h22 + d * rt2r;
                          h22 -= h12 * tr;
                          z[nr + z.size(0) * (b_k - 1)] = h22;
                          rt2r -= h12 * tst;
                          z[nr + z.size(0) * b_k] = rt2r;
                        }
                      }
                    }

                    its++;
                  }
                }

                if (!converged) {
                  info = i + 1;
                  exitg1 = true;
                } else {
                  if (l == i + 1) {
                    wr[i] = h[i + h.size(0) * i];
                    wi[i] = 0.0;
                  } else if (l == i) {
                    d = h[(i + h.size(0) * i) - 1];
                    h22 = h[i + h.size(0) * (i - 1)];
                    rt2r = h[i + h.size(0) * i];
                    aa = xdlanv2(&h[(i + h.size(0) * (i - 1)) - 1], d, h22, rt2r,
                                 tr, rt1r, s, tst, h12);
                    wi[i - 1] = tr;
                    wr[i - 1] = aa;
                    wr[i] = rt1r;
                    wi[i] = s;
                    h[(i + h.size(0) * i) - 1] = d;
                    h[i + h.size(0) * (i - 1)] = h22;
                    h[i + h.size(0) * i] = rt2r;
                    if (n > i + 1) {
                      ix0 = (i + 1) * n + i;
                      blas::xrot((n - i) - 1, h, ix0, n, ix0 + 1, n, tst, h12);
                    }

                    ix0 = (i - 1) * n + 1;
                    nr = i * n + 1;
                    blas::xrot(i - 1, h, ix0, nr, tst, h12);
                    blas::xrot(ihiz, z, ix0, nr, tst, h12);
                  }

                  kdefl = 0;
                  i = l - 2;
                }
              }

              if (n > 2) {
                for (nr = 3; nr <= n; nr++) {
                  for (i = nr; i <= n; i++) {
                    h[(i + h.size(0) * (nr - 3)) - 1] = 0.0;
                  }
                }
              }
            }
          }

          return info;
        }
      }
    }
  }
}

// End of code generation (xdlahqr.cpp)
