//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xdhseqr.cpp
//
// Code generation for function 'xdhseqr'
//

// Include files
#include "xdhseqr.h"
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
        int32_T eml_dlahqr(::coder::array<real_T, 2U> &h, ::coder::array<real_T,
                           2U> &z)
        {
          real_T v[3];
          real_T aa;
          real_T ab;
          real_T ba;
          real_T bb;
          real_T d;
          real_T rt1r;
          real_T rt2r;
          real_T s;
          real_T tst;
          int32_T info;
          int32_T ldh;
          int32_T ldz;
          int32_T n;
          n = h.size(0);
          ldh = h.size(0);
          ldz = z.size(0);
          info = 0;
          if ((n != 0) && (1 != n)) {
            real_T SMLNUM;
            int32_T i;
            int32_T itmax;
            int32_T j;
            int32_T kdefl;
            int32_T nr;
            boolean_T exitg1;
            v[0] = 0.0;
            v[1] = 0.0;
            v[2] = 0.0;
            for (j = 0; j <= n - 4; j++) {
              h[(j + h.size(0) * j) + 2] = 0.0;
              h[(j + h.size(0) * j) + 3] = 0.0;
            }

            if (1 <= n - 2) {
              h[(n + h.size(0) * (n - 3)) - 1] = 0.0;
            }

            if (10 > n) {
              nr = 10;
            } else {
              nr = n;
            }

            itmax = 30 * nr;
            kdefl = 0;
            SMLNUM = 2.2250738585072014E-308 * (static_cast<real_T>(n) /
              2.2204460492503131E-16);
            i = n - 1;
            exitg1 = false;
            while ((!exitg1) && (i + 1 >= 1)) {
              int32_T L;
              int32_T its;
              boolean_T exitg2;
              boolean_T goto150;
              L = 1;
              goto150 = false;
              its = 0;
              exitg2 = false;
              while ((!exitg2) && (its <= itmax)) {
                int32_T k;
                boolean_T exitg3;
                k = i;
                exitg3 = false;
                while ((!exitg3) && (k + 1 > L)) {
                  ba = std::abs(h[k + h.size(0) * (k - 1)]);
                  if (ba <= SMLNUM) {
                    exitg3 = true;
                  } else {
                    bb = std::abs(h[k + h.size(0) * k]);
                    tst = std::abs(h[(k + h.size(0) * (k - 1)) - 1]) + bb;
                    if (tst == 0.0) {
                      if (k - 1 >= 1) {
                        tst = std::abs(h[(k + h.size(0) * (k - 2)) - 1]);
                      }

                      if (k + 2 <= n) {
                        tst += std::abs(h[(k + h.size(0) * k) + 1]);
                      }
                    }

                    if (ba <= 2.2204460492503131E-16 * tst) {
                      tst = std::abs(h[(k + h.size(0) * k) - 1]);
                      if (ba > tst) {
                        ab = ba;
                        ba = tst;
                      } else {
                        ab = tst;
                      }

                      tst = std::abs(h[(k + h.size(0) * (k - 1)) - 1] - h[k +
                                     h.size(0) * k]);
                      if (bb > tst) {
                        aa = bb;
                        bb = tst;
                      } else {
                        aa = tst;
                      }

                      s = aa + ab;
                      if (ba * (ab / s) <= std::fmax(SMLNUM,
                           2.2204460492503131E-16 * (bb * (aa / s)))) {
                        exitg3 = true;
                      } else {
                        k--;
                      }
                    } else {
                      k--;
                    }
                  }
                }

                L = k + 1;
                if (k + 1 > 1) {
                  h[k + h.size(0) * (k - 1)] = 0.0;
                }

                if (k + 1 >= i) {
                  goto150 = true;
                  exitg2 = true;
                } else {
                  int32_T m;
                  kdefl++;
                  if (kdefl - kdefl / 20 * 20 == 0) {
                    s = std::abs(h[i + h.size(0) * (i - 1)]) + std::abs(h[(i +
                      h.size(0) * (i - 2)) - 1]);
                    tst = 0.75 * s + h[i + h.size(0) * i];
                    aa = -0.4375 * s;
                    ab = s;
                    bb = tst;
                  } else if (kdefl - kdefl / 10 * 10 == 0) {
                    s = std::abs(h[(k + h.size(0) * k) + 1]) + std::abs(h[(k +
                      h.size(0) * (k + 1)) + 2]);
                    tst = 0.75 * s + h[k + h.size(0) * k];
                    aa = -0.4375 * s;
                    ab = s;
                    bb = tst;
                  } else {
                    tst = h[(i + h.size(0) * (i - 1)) - 1];
                    ab = h[i + h.size(0) * (i - 1)];
                    aa = h[(i + h.size(0) * i) - 1];
                    bb = h[i + h.size(0) * i];
                  }

                  s = ((std::abs(tst) + std::abs(aa)) + std::abs(ab)) + std::abs
                    (bb);
                  if (s == 0.0) {
                    rt1r = 0.0;
                    ab = 0.0;
                    rt2r = 0.0;
                    aa = 0.0;
                  } else {
                    tst /= s;
                    ab /= s;
                    aa /= s;
                    bb /= s;
                    ba = (tst + bb) / 2.0;
                    tst = (tst - ba) * (bb - ba) - aa * ab;
                    ab = std::sqrt(std::abs(tst));
                    if (tst >= 0.0) {
                      rt1r = ba * s;
                      rt2r = rt1r;
                      ab *= s;
                      aa = -ab;
                    } else {
                      rt1r = ba + ab;
                      rt2r = ba - ab;
                      if (std::abs(rt1r - bb) <= std::abs(rt2r - bb)) {
                        rt1r *= s;
                        rt2r = rt1r;
                      } else {
                        rt2r *= s;
                        rt1r = rt2r;
                      }

                      ab = 0.0;
                      aa = 0.0;
                    }
                  }

                  m = i - 1;
                  exitg3 = false;
                  while ((!exitg3) && (m >= k + 1)) {
                    tst = h[m + h.size(0) * (m - 1)];
                    ba = h[(m + h.size(0) * (m - 1)) - 1];
                    bb = ba - rt2r;
                    s = (std::abs(bb) + std::abs(aa)) + std::abs(tst);
                    tst /= s;
                    v[0] = (tst * h[(m + h.size(0) * m) - 1] + (ba - rt1r) * (bb
                             / s)) - ab * (aa / s);
                    v[1] = tst * (((ba + h[m + h.size(0) * m]) - rt1r) - rt2r);
                    v[2] = tst * h[(m + h.size(0) * m) + 1];
                    s = (std::abs(v[0]) + std::abs(v[1])) + std::abs(v[2]);
                    v[0] /= s;
                    v[1] /= s;
                    v[2] /= s;
                    if ((m == k + 1) || (std::abs(h[(m + h.size(0) * (m - 2)) -
                          1]) * (std::abs(v[1]) + std::abs(v[2])) <=
                                         2.2204460492503131E-16 * std::abs(v[0])
                                         * ((std::abs(h[(m + h.size(0) * (m - 2))
                            - 2]) + std::abs(ba)) + std::abs(h[m + h.size(0) * m]))))
                    {
                      exitg3 = true;
                    } else {
                      m--;
                    }
                  }

                  for (int32_T b_k{m}; b_k <= i; b_k++) {
                    nr = (i - b_k) + 2;
                    if (3 < nr) {
                      nr = 3;
                    }

                    if (b_k > m) {
                      int32_T hoffset;
                      hoffset = (b_k + ldh * (b_k - 2)) - 1;
                      for (j = 0; j < nr; j++) {
                        v[j] = h[j + hoffset];
                      }
                    }

                    tst = v[0];
                    bb = xzlarfg(nr, &tst, v);
                    v[0] = tst;
                    if (b_k > m) {
                      h[(b_k + h.size(0) * (b_k - 2)) - 1] = tst;
                      h[b_k + h.size(0) * (b_k - 2)] = 0.0;
                      if (b_k < i) {
                        h[(b_k + h.size(0) * (b_k - 2)) + 1] = 0.0;
                      }
                    } else if (m > k + 1) {
                      h[(b_k + h.size(0) * (b_k - 2)) - 1] = h[(b_k + h.size(0) *
                        (b_k - 2)) - 1] * (1.0 - bb);
                    }

                    s = v[1];
                    tst = bb * v[1];
                    if (nr == 3) {
                      d = v[2];
                      ba = bb * v[2];
                      for (j = b_k; j <= n; j++) {
                        aa = (h[(b_k + h.size(0) * (j - 1)) - 1] + s * h[b_k +
                              h.size(0) * (j - 1)]) + d * h[(b_k + h.size(0) *
                          (j - 1)) + 1];
                        h[(b_k + h.size(0) * (j - 1)) - 1] = h[(b_k + h.size(0) *
                          (j - 1)) - 1] - aa * bb;
                        h[b_k + h.size(0) * (j - 1)] = h[b_k + h.size(0) * (j -
                          1)] - aa * tst;
                        h[(b_k + h.size(0) * (j - 1)) + 1] = h[(b_k + h.size(0) *
                          (j - 1)) + 1] - aa * ba;
                      }

                      if (b_k + 3 < i + 1) {
                        nr = b_k + 2;
                      } else {
                        nr = i;
                      }

                      for (j = 0; j <= nr; j++) {
                        aa = (h[j + h.size(0) * (b_k - 1)] + s * h[j + h.size(0)
                              * b_k]) + d * h[j + h.size(0) * (b_k + 1)];
                        h[j + h.size(0) * (b_k - 1)] = h[j + h.size(0) * (b_k -
                          1)] - aa * bb;
                        h[j + h.size(0) * b_k] = h[j + h.size(0) * b_k] - aa *
                          tst;
                        h[j + h.size(0) * (b_k + 1)] = h[j + h.size(0) * (b_k +
                          1)] - aa * ba;
                      }

                      for (j = 0; j < n; j++) {
                        ab = z[j + z.size(0) * (b_k - 1)];
                        aa = (ab + s * z[j + z.size(0) * b_k]) + d * z[j +
                          z.size(0) * (b_k + 1)];
                        z[j + z.size(0) * (b_k - 1)] = ab - aa * bb;
                        z[j + z.size(0) * b_k] = z[j + z.size(0) * b_k] - aa *
                          tst;
                        z[j + z.size(0) * (b_k + 1)] = z[j + z.size(0) * (b_k +
                          1)] - aa * ba;
                      }
                    } else if (nr == 2) {
                      for (j = b_k; j <= n; j++) {
                        ab = h[(b_k + h.size(0) * (j - 1)) - 1];
                        aa = ab + s * h[b_k + h.size(0) * (j - 1)];
                        h[(b_k + h.size(0) * (j - 1)) - 1] = ab - aa * bb;
                        h[b_k + h.size(0) * (j - 1)] = h[b_k + h.size(0) * (j -
                          1)] - aa * tst;
                      }

                      for (j = 0; j <= i; j++) {
                        aa = h[j + h.size(0) * (b_k - 1)] + s * h[j + h.size(0) *
                          b_k];
                        h[j + h.size(0) * (b_k - 1)] = h[j + h.size(0) * (b_k -
                          1)] - aa * bb;
                        h[j + h.size(0) * b_k] = h[j + h.size(0) * b_k] - aa *
                          tst;
                      }

                      for (j = 0; j < n; j++) {
                        ab = z[j + z.size(0) * (b_k - 1)];
                        aa = ab + s * z[j + z.size(0) * b_k];
                        z[j + z.size(0) * (b_k - 1)] = ab - aa * bb;
                        z[j + z.size(0) * b_k] = z[j + z.size(0) * b_k] - aa *
                          tst;
                      }
                    }
                  }

                  its++;
                }
              }

              if (!goto150) {
                info = i + 1;
                exitg1 = true;
              } else {
                if ((L != i + 1) && (L == i)) {
                  s = h[(i + h.size(0) * i) - 1];
                  d = h[i + h.size(0) * (i - 1)];
                  tst = h[i + h.size(0) * i];
                  xdlanv2(&h[(i + h.size(0) * (i - 1)) - 1], &s, &d, &tst, &ab,
                          &aa, &ba, &bb, &rt2r, &rt1r);
                  h[(i + h.size(0) * i) - 1] = s;
                  h[i + h.size(0) * (i - 1)] = d;
                  h[i + h.size(0) * i] = tst;
                  if (n > i + 1) {
                    nr = i + (i + 1) * ldh;
                    blas::xrot((n - i) - 1, h, nr, ldh, nr + 1, ldh, rt2r, rt1r);
                  }

                  blas::xrot(i - 1, h, (i - 1) * ldh + 1, i * ldh + 1, rt2r,
                             rt1r);
                  blas::xrot(n, z, (i - 1) * ldz + 1, i * ldz + 1, rt2r, rt1r);
                }

                kdefl = 0;
                i = L - 2;
              }
            }
          }

          return info;
        }
      }
    }
  }
}

// End of code generation (xdhseqr.cpp)
