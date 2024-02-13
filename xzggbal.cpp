//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzggbal.cpp
//
// Code generation for function 'xzggbal'
//

// Include files
#include "xzggbal.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace reflapack
      {
        void xzggbal(::coder::array<creal_T, 2U> &A, int32_T *ilo, int32_T *ihi,
                     ::coder::array<int32_T, 1U> &rscale)
        {
          int32_T ii;
          int32_T nzcount;
          nzcount = A.size(0);
          rscale.set_size(nzcount);
          for (ii = 0; ii < nzcount; ii++) {
            rscale[ii] = 1;
          }

          *ilo = 1;
          *ihi = A.size(0);
          if (A.size(0) <= 1) {
            *ihi = 1;
          } else {
            real_T atmp_im;
            real_T atmp_re;
            int32_T exitg2;
            int32_T i;
            int32_T j;
            int32_T jj;
            boolean_T exitg3;
            boolean_T exitg4;
            boolean_T found;
            do {
              exitg2 = 0;
              i = 0;
              j = 0;
              found = false;
              ii = *ihi;
              exitg3 = false;
              while ((!exitg3) && (ii > 0)) {
                nzcount = 0;
                i = ii;
                j = *ihi;
                jj = 0;
                exitg4 = false;
                while ((!exitg4) && (jj <= *ihi - 1)) {
                  if ((A[(ii + A.size(0) * jj) - 1].re != 0.0) || (A[(ii +
                        A.size(0) * jj) - 1].im != 0.0) || (ii == jj + 1)) {
                    if (nzcount == 0) {
                      j = jj + 1;
                      nzcount = 1;
                      jj++;
                    } else {
                      nzcount = 2;
                      exitg4 = true;
                    }
                  } else {
                    jj++;
                  }
                }

                if (nzcount < 2) {
                  found = true;
                  exitg3 = true;
                } else {
                  ii--;
                }
              }

              if (!found) {
                exitg2 = 2;
              } else {
                nzcount = A.size(0);
                if (i != *ihi) {
                  for (ii = 1; ii <= nzcount; ii++) {
                    atmp_re = A[(i + A.size(0) * (ii - 1)) - 1].re;
                    atmp_im = A[(i + A.size(0) * (ii - 1)) - 1].im;
                    A[(i + A.size(0) * (ii - 1)) - 1] = A[(*ihi + A.size(0) *
                      (ii - 1)) - 1];
                    A[(*ihi + A.size(0) * (ii - 1)) - 1].re = atmp_re;
                    A[(*ihi + A.size(0) * (ii - 1)) - 1].im = atmp_im;
                  }
                }

                if (j != *ihi) {
                  for (ii = 0; ii < *ihi; ii++) {
                    atmp_re = A[ii + A.size(0) * (j - 1)].re;
                    atmp_im = A[ii + A.size(0) * (j - 1)].im;
                    A[ii + A.size(0) * (j - 1)] = A[ii + A.size(0) * (*ihi - 1)];
                    A[ii + A.size(0) * (*ihi - 1)].re = atmp_re;
                    A[ii + A.size(0) * (*ihi - 1)].im = atmp_im;
                  }
                }

                rscale[*ihi - 1] = j;
                (*ihi)--;
                if (*ihi == 1) {
                  rscale[0] = 1;
                  exitg2 = 1;
                }
              }
            } while (exitg2 == 0);

            if (exitg2 != 1) {
              int32_T exitg1;
              do {
                exitg1 = 0;
                i = 0;
                j = 0;
                found = false;
                jj = *ilo;
                exitg3 = false;
                while ((!exitg3) && (jj <= *ihi)) {
                  nzcount = 0;
                  i = *ihi;
                  j = jj;
                  ii = *ilo;
                  exitg4 = false;
                  while ((!exitg4) && (ii <= *ihi)) {
                    if ((A[(ii + A.size(0) * (jj - 1)) - 1].re != 0.0) || (A[(ii
                          + A.size(0) * (jj - 1)) - 1].im != 0.0) || (ii == jj))
                    {
                      if (nzcount == 0) {
                        i = ii;
                        nzcount = 1;
                        ii++;
                      } else {
                        nzcount = 2;
                        exitg4 = true;
                      }
                    } else {
                      ii++;
                    }
                  }

                  if (nzcount < 2) {
                    found = true;
                    exitg3 = true;
                  } else {
                    jj++;
                  }
                }

                if (!found) {
                  exitg1 = 1;
                } else {
                  nzcount = A.size(0);
                  if (i != *ilo) {
                    for (ii = *ilo; ii <= nzcount; ii++) {
                      atmp_re = A[(i + A.size(0) * (ii - 1)) - 1].re;
                      atmp_im = A[(i + A.size(0) * (ii - 1)) - 1].im;
                      A[(i + A.size(0) * (ii - 1)) - 1] = A[(*ilo + A.size(0) *
                        (ii - 1)) - 1];
                      A[(*ilo + A.size(0) * (ii - 1)) - 1].re = atmp_re;
                      A[(*ilo + A.size(0) * (ii - 1)) - 1].im = atmp_im;
                    }
                  }

                  if (j != *ilo) {
                    for (ii = 0; ii < *ihi; ii++) {
                      atmp_re = A[ii + A.size(0) * (j - 1)].re;
                      atmp_im = A[ii + A.size(0) * (j - 1)].im;
                      A[ii + A.size(0) * (j - 1)] = A[ii + A.size(0) * (*ilo - 1)];
                      A[ii + A.size(0) * (*ilo - 1)].re = atmp_re;
                      A[ii + A.size(0) * (*ilo - 1)].im = atmp_im;
                    }
                  }

                  rscale[*ilo - 1] = j;
                  (*ilo)++;
                  if (*ilo == *ihi) {
                    rscale[*ilo - 1] = *ilo;
                    exitg1 = 1;
                  }
                }
              } while (exitg1 == 0);
            }
          }
        }
      }
    }
  }
}

// End of code generation (xzggbal.cpp)
