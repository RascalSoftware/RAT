/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * resample_sld.c
 *
 * Code generation for function 'resample_sld'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_custlay_single.h"
#include "resample_sld.h"
#include "standardTF_custlay_single_emxutil.h"

/* Function Definitions */
void resample_sld(const emxArray_real_T *sld, emxArray_real_T *x_new_tot,
                  emxArray_real_T *y_new_tot)
{
  emxArray_real_T *x;
  int nx;
  int i6;
  emxArray_real_T *prof;
  emxArray_real_T *x_new;
  emxArray_real_T *y_new;
  unsigned int count;
  int i;
  emxArray_real_T *newsteps;
  emxArray_real_T *new_xs;
  emxArray_real_T *xi;
  emxArray_real_T *b_x_new;
  emxArray_real_T *b_y_new;
  double this_step;
  double apnd;
  double cdiff;
  double absa;
  double absb;
  double varargin_1[2];
  double varargin_2[2];
  unsigned int outsize[2];
  int idx;
  emxArray_boolean_T *b_x;
  int nm1d2;
  int exitg2;
  emxArray_int32_T *ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int k;
  double r;
  emxArray_real_T *b_x_new_tot;
  emxArray_real_T *b_y_new_tot;
  emxInit_real_T1(&x, 1);
  nx = sld->size[0];
  i6 = x->size[0];
  x->size[0] = nx;
  emxEnsureCapacity((emxArray__common *)x, i6, (int)sizeof(double));
  for (i6 = 0; i6 < nx; i6++) {
    x->data[i6] = sld->data[i6];
  }

  emxInit_real_T1(&prof, 1);
  nx = sld->size[0];
  i6 = prof->size[0];
  prof->size[0] = nx;
  emxEnsureCapacity((emxArray__common *)prof, i6, (int)sizeof(double));
  for (i6 = 0; i6 < nx; i6++) {
    prof->data[i6] = sld->data[i6 + sld->size[0]];
  }

  emxInit_real_T(&x_new, 2);
  i6 = x_new->size[0] * x_new->size[1];
  x_new->size[0] = 10000;
  x_new->size[1] = 1;
  emxEnsureCapacity((emxArray__common *)x_new, i6, (int)sizeof(double));
  for (i6 = 0; i6 < 10000; i6++) {
    x_new->data[i6] = 0.0;
  }

  emxInit_real_T(&y_new, 2);
  i6 = y_new->size[0] * y_new->size[1];
  y_new->size[0] = 10000;
  y_new->size[1] = 1;
  emxEnsureCapacity((emxArray__common *)y_new, i6, (int)sizeof(double));
  for (i6 = 0; i6 < 10000; i6++) {
    y_new->data[i6] = 0.0;
  }

  count = 1U;
  i = 0;
  emxInit_real_T(&newsteps, 2);
  emxInit_real_T(&new_xs, 2);
  emxInit_real_T(&xi, 2);
  emxInit_real_T(&b_x_new, 2);
  emxInit_real_T(&b_y_new, 2);
  while (i + 2 < x->size[0]) {
    this_step = prof->data[i + 1] - prof->data[i];
    if (fabs(this_step) < 1.0) {
      /* Keep original points */
      x_new->data[(int)count - 1] = x->data[i + 1];
      y_new->data[(int)count - 1] = prof->data[i + 1];
      count++;
      i++;
    } else {
      if (this_step > 0.0) {
        if (rtIsNaN(prof->data[i]) || rtIsNaN(prof->data[i + 1])) {
          i6 = newsteps->size[0] * newsteps->size[1];
          newsteps->size[0] = 1;
          newsteps->size[1] = 1;
          emxEnsureCapacity((emxArray__common *)newsteps, i6, (int)sizeof(double));
          newsteps->data[0] = rtNaN;
        } else if (prof->data[i + 1] < prof->data[i]) {
          i6 = newsteps->size[0] * newsteps->size[1];
          newsteps->size[0] = 1;
          newsteps->size[1] = 0;
          emxEnsureCapacity((emxArray__common *)newsteps, i6, (int)sizeof(double));
        } else if ((rtIsInf(prof->data[i]) || rtIsInf(prof->data[i + 1])) &&
                   (prof->data[i] == prof->data[i + 1])) {
          i6 = newsteps->size[0] * newsteps->size[1];
          newsteps->size[0] = 1;
          newsteps->size[1] = 1;
          emxEnsureCapacity((emxArray__common *)newsteps, i6, (int)sizeof(double));
          newsteps->data[0] = rtNaN;
        } else if (floor(prof->data[i]) == prof->data[i]) {
          this_step = prof->data[i];
          apnd = prof->data[i + 1];
          i6 = newsteps->size[0] * newsteps->size[1];
          newsteps->size[0] = 1;
          newsteps->size[1] = (int)floor(apnd - this_step) + 1;
          emxEnsureCapacity((emxArray__common *)newsteps, i6, (int)sizeof(double));
          nx = (int)floor(apnd - this_step);
          for (i6 = 0; i6 <= nx; i6++) {
            newsteps->data[newsteps->size[0] * i6] = this_step + (double)i6;
          }
        } else {
          this_step = floor((prof->data[i + 1] - prof->data[i]) + 0.5);
          apnd = prof->data[i] + this_step;
          cdiff = apnd - prof->data[i + 1];
          absa = fabs(prof->data[i]);
          absb = fabs(prof->data[i + 1]);
          if ((absa >= absb) || rtIsNaN(absb)) {
            absb = absa;
          }

          if (fabs(cdiff) < 4.4408920985006262E-16 * absb) {
            this_step++;
            apnd = prof->data[i + 1];
          } else if (cdiff > 0.0) {
            apnd = prof->data[i] + (this_step - 1.0);
          } else {
            this_step++;
          }

          if (this_step >= 0.0) {
            idx = (int)this_step;
          } else {
            idx = 0;
          }

          i6 = newsteps->size[0] * newsteps->size[1];
          newsteps->size[0] = 1;
          newsteps->size[1] = idx;
          emxEnsureCapacity((emxArray__common *)newsteps, i6, (int)sizeof(double));
          if (idx > 0) {
            newsteps->data[0] = prof->data[i];
            if (idx > 1) {
              newsteps->data[idx - 1] = apnd;
              nm1d2 = (idx - 1) / 2;
              for (nx = 1; nx < nm1d2; nx++) {
                newsteps->data[nx] = prof->data[i] + (double)nx;
                newsteps->data[(idx - nx) - 1] = apnd - (double)nx;
              }

              if (nm1d2 << 1 == idx - 1) {
                newsteps->data[nm1d2] = (prof->data[i] + apnd) / 2.0;
              } else {
                newsteps->data[nm1d2] = prof->data[i] + (double)nm1d2;
                newsteps->data[nm1d2 + 1] = apnd - (double)nm1d2;
              }
            }
          }
        }
      } else if (rtIsNaN(prof->data[i]) || rtIsNaN(prof->data[i + 1])) {
        i6 = newsteps->size[0] * newsteps->size[1];
        newsteps->size[0] = 1;
        newsteps->size[1] = 1;
        emxEnsureCapacity((emxArray__common *)newsteps, i6, (int)sizeof(double));
        newsteps->data[0] = rtNaN;
      } else if (prof->data[i] < prof->data[i + 1]) {
        i6 = newsteps->size[0] * newsteps->size[1];
        newsteps->size[0] = 1;
        newsteps->size[1] = 0;
        emxEnsureCapacity((emxArray__common *)newsteps, i6, (int)sizeof(double));
      } else if ((rtIsInf(prof->data[i]) || rtIsInf(prof->data[i + 1])) &&
                 (prof->data[i] == prof->data[i + 1])) {
        i6 = newsteps->size[0] * newsteps->size[1];
        newsteps->size[0] = 1;
        newsteps->size[1] = 1;
        emxEnsureCapacity((emxArray__common *)newsteps, i6, (int)sizeof(double));
        newsteps->data[0] = rtNaN;
      } else if (floor(prof->data[i]) == prof->data[i]) {
        this_step = prof->data[i];
        apnd = prof->data[i + 1];
        i6 = newsteps->size[0] * newsteps->size[1];
        newsteps->size[0] = 1;
        newsteps->size[1] = (int)floor(-(apnd - this_step)) + 1;
        emxEnsureCapacity((emxArray__common *)newsteps, i6, (int)sizeof(double));
        nx = (int)floor(-(apnd - this_step));
        for (i6 = 0; i6 <= nx; i6++) {
          newsteps->data[newsteps->size[0] * i6] = this_step - (double)i6;
        }
      } else {
        this_step = floor((prof->data[i + 1] - prof->data[i]) / -1.0 + 0.5);
        apnd = prof->data[i] + -this_step;
        cdiff = prof->data[i + 1] - apnd;
        absa = fabs(prof->data[i]);
        absb = fabs(prof->data[i + 1]);
        if ((absa >= absb) || rtIsNaN(absb)) {
          absb = absa;
        }

        if (fabs(cdiff) < 4.4408920985006262E-16 * absb) {
          this_step++;
          apnd = prof->data[i + 1];
        } else if (cdiff > 0.0) {
          apnd = prof->data[i] + -(this_step - 1.0);
        } else {
          this_step++;
        }

        if (this_step >= 0.0) {
          idx = (int)this_step;
        } else {
          idx = 0;
        }

        i6 = newsteps->size[0] * newsteps->size[1];
        newsteps->size[0] = 1;
        newsteps->size[1] = idx;
        emxEnsureCapacity((emxArray__common *)newsteps, i6, (int)sizeof(double));
        if (idx > 0) {
          newsteps->data[0] = prof->data[i];
          if (idx > 1) {
            newsteps->data[idx - 1] = apnd;
            nm1d2 = (idx - 1) / 2;
            for (nx = 1; nx < nm1d2; nx++) {
              newsteps->data[nx] = prof->data[i] + -(double)nx;
              newsteps->data[(idx - nx) - 1] = apnd - (-(double)nx);
            }

            if (nm1d2 << 1 == idx - 1) {
              newsteps->data[nm1d2] = (prof->data[i] + apnd) / 2.0;
            } else {
              newsteps->data[nm1d2] = prof->data[i] + -(double)nm1d2;
              newsteps->data[nm1d2 + 1] = apnd - (-(double)nm1d2);
            }
          }
        }
      }

      for (i6 = 0; i6 < 2; i6++) {
        varargin_1[i6] = prof->data[i6 + i];
      }

      for (i6 = 0; i6 < 2; i6++) {
        varargin_2[i6] = x->data[i6 + i];
      }

      for (i6 = 0; i6 < 2; i6++) {
        outsize[i6] = (unsigned int)newsteps->size[i6];
      }

      i6 = new_xs->size[0] * new_xs->size[1];
      new_xs->size[0] = 1;
      new_xs->size[1] = (int)outsize[1];
      emxEnsureCapacity((emxArray__common *)new_xs, i6, (int)sizeof(double));
      nx = (int)outsize[1];
      for (i6 = 0; i6 < nx; i6++) {
        new_xs->data[i6] = rtNaN;
      }

      if (newsteps->size[1] != 0) {
        nx = -2;
        do {
          exitg2 = 0;
          if (nx + 3 < 3) {
            if (rtIsNaN(prof->data[(nx + i) + 2])) {
              exitg2 = 1;
            } else {
              nx++;
            }
          } else {
            if (prof->data[i + 1] < prof->data[i]) {
              varargin_1[0] = prof->data[1 + i];
              varargin_1[1] = prof->data[i];
              varargin_2[0] = x->data[1 + i];
              varargin_2[1] = x->data[i];
            }

            i6 = xi->size[0] * xi->size[1];
            xi->size[0] = 1;
            xi->size[1] = newsteps->size[1];
            emxEnsureCapacity((emxArray__common *)xi, i6, (int)sizeof(double));
            nx = newsteps->size[0] * newsteps->size[1];
            for (i6 = 0; i6 < nx; i6++) {
              xi->data[i6] = newsteps->data[i6];
            }

            this_step = varargin_1[0];
            apnd = varargin_1[1];
            nm1d2 = newsteps->size[1];

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r)

            for (k = 1; k <= nm1d2; k++) {
              r = new_xs->data[k - 1];
              if (rtIsNaN(xi->data[k - 1])) {
                r = rtNaN;
              } else {
                if ((!(xi->data[k - 1] > apnd)) && (!(xi->data[k - 1] <
                      this_step))) {
                  r = (xi->data[k - 1] - varargin_1[0]) / (varargin_1[1] -
                    varargin_1[0]);
                  if (r == 0.0) {
                    r = varargin_2[0];
                  } else if (r == 1.0) {
                    r = varargin_2[1];
                  } else if (varargin_2[0] == varargin_2[1]) {
                    r = varargin_2[0];
                  } else {
                    r = (1.0 - r) * varargin_2[0] + r * varargin_2[1];
                  }
                }
              }

              new_xs->data[k - 1] = r;
            }

            exitg2 = 1;
          }
        } while (exitg2 == 0);
      }

      if (!(new_xs->size[1] == 0)) {
        idx = new_xs->size[1];
      } else {
        idx = 0;
      }

      i6 = b_x_new->size[0] * b_x_new->size[1];
      b_x_new->size[0] = 10000;
      b_x_new->size[1] = x_new->size[1] + idx;
      emxEnsureCapacity((emxArray__common *)b_x_new, i6, (int)sizeof(double));
      nx = x_new->size[1];
      for (i6 = 0; i6 < nx; i6++) {
        for (nm1d2 = 0; nm1d2 < 10000; nm1d2++) {
          b_x_new->data[nm1d2 + b_x_new->size[0] * i6] = x_new->data[nm1d2 +
            x_new->size[0] * i6];
        }
      }

      for (i6 = 0; i6 < idx; i6++) {
        for (nm1d2 = 0; nm1d2 < 10000; nm1d2++) {
          b_x_new->data[nm1d2 + b_x_new->size[0] * (i6 + x_new->size[1])] =
            new_xs->data[nm1d2 + 10000 * i6];
        }
      }

      i6 = x_new->size[0] * x_new->size[1];
      x_new->size[0] = 10000;
      x_new->size[1] = b_x_new->size[1];
      emxEnsureCapacity((emxArray__common *)x_new, i6, (int)sizeof(double));
      nx = b_x_new->size[1];
      for (i6 = 0; i6 < nx; i6++) {
        for (nm1d2 = 0; nm1d2 < 10000; nm1d2++) {
          x_new->data[nm1d2 + x_new->size[0] * i6] = b_x_new->data[nm1d2 +
            b_x_new->size[0] * i6];
        }
      }

      if (!(newsteps->size[1] == 0)) {
        idx = newsteps->size[1];
      } else {
        idx = 0;
      }

      i6 = b_y_new->size[0] * b_y_new->size[1];
      b_y_new->size[0] = 10000;
      b_y_new->size[1] = y_new->size[1] + idx;
      emxEnsureCapacity((emxArray__common *)b_y_new, i6, (int)sizeof(double));
      nx = y_new->size[1];
      for (i6 = 0; i6 < nx; i6++) {
        for (nm1d2 = 0; nm1d2 < 10000; nm1d2++) {
          b_y_new->data[nm1d2 + b_y_new->size[0] * i6] = y_new->data[nm1d2 +
            y_new->size[0] * i6];
        }
      }

      for (i6 = 0; i6 < idx; i6++) {
        for (nm1d2 = 0; nm1d2 < 10000; nm1d2++) {
          b_y_new->data[nm1d2 + b_y_new->size[0] * (i6 + y_new->size[1])] =
            newsteps->data[nm1d2 + 10000 * i6];
        }
      }

      i6 = y_new->size[0] * y_new->size[1];
      y_new->size[0] = 10000;
      y_new->size[1] = b_y_new->size[1];
      emxEnsureCapacity((emxArray__common *)y_new, i6, (int)sizeof(double));
      nx = b_y_new->size[1];
      for (i6 = 0; i6 < nx; i6++) {
        for (nm1d2 = 0; nm1d2 < 10000; nm1d2++) {
          y_new->data[nm1d2 + y_new->size[0] * i6] = b_y_new->data[nm1d2 +
            b_y_new->size[0] * i6];
        }
      }

      nm1d2 = x_new->size[1];
      if (10000 >= nm1d2) {
        nm1d2 = 10000;
      }

      count = (unsigned int)nm1d2;
      i++;
    }
  }

  emxFree_real_T(&b_y_new);
  emxFree_real_T(&b_x_new);
  emxFree_real_T(&xi);
  emxFree_real_T(&new_xs);
  emxFree_real_T(&newsteps);
  emxFree_real_T(&prof);

  /* x_new_tot = x_new(:); */
  /* y_new_tot = y_new(:); */
  /* Make it into a 'histogram' */
  i6 = x_new_tot->size[0];
  x_new_tot->size[0] = (int)count;
  emxEnsureCapacity((emxArray__common *)x_new_tot, i6, (int)sizeof(double));
  nx = (int)count;
  for (i6 = 0; i6 < nx; i6++) {
    x_new_tot->data[i6] = 0.0;
  }

  i6 = y_new_tot->size[0];
  y_new_tot->size[0] = (int)count;
  emxEnsureCapacity((emxArray__common *)y_new_tot, i6, (int)sizeof(double));
  nx = (int)count;
  for (i6 = 0; i6 < nx; i6++) {
    y_new_tot->data[i6] = 0.0;
  }

  for (i = 0; i <= (int)count - 2; i++) {
    x_new_tot->data[i] = x_new->data[1 + i] - x_new->data[i];
    y_new_tot->data[i] = y_new->data[i];
  }

  emxFree_real_T(&y_new);
  emxFree_real_T(&x_new);
  emxInit_boolean_T(&b_x, 1);

  /* Remove any zero thickness layers... */
  i6 = b_x->size[0];
  b_x->size[0] = x_new_tot->size[0];
  emxEnsureCapacity((emxArray__common *)b_x, i6, (int)sizeof(boolean_T));
  nx = x_new_tot->size[0];
  for (i6 = 0; i6 < nx; i6++) {
    b_x->data[i6] = (x_new_tot->data[i6] != 0.0);
  }

  emxInit_int32_T(&ii, 1);
  nx = b_x->size[0];
  idx = 0;
  i6 = ii->size[0];
  ii->size[0] = b_x->size[0];
  emxEnsureCapacity((emxArray__common *)ii, i6, (int)sizeof(int));
  nm1d2 = 1;
  exitg1 = false;
  while ((!exitg1) && (nm1d2 <= nx)) {
    guard1 = false;
    if (b_x->data[nm1d2 - 1]) {
      idx++;
      ii->data[idx - 1] = nm1d2;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      nm1d2++;
    }
  }

  if (b_x->size[0] == 1) {
    if (idx == 0) {
      i6 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)ii, i6, (int)sizeof(int));
    }
  } else {
    i6 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity((emxArray__common *)ii, i6, (int)sizeof(int));
  }

  emxFree_boolean_T(&b_x);
  i6 = x->size[0];
  x->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)x, i6, (int)sizeof(double));
  nx = ii->size[0];
  for (i6 = 0; i6 < nx; i6++) {
    x->data[i6] = ii->data[i6];
  }

  emxFree_int32_T(&ii);
  emxInit_real_T1(&b_x_new_tot, 1);
  i6 = b_x_new_tot->size[0];
  b_x_new_tot->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)b_x_new_tot, i6, (int)sizeof(double));
  nx = x->size[0];
  for (i6 = 0; i6 < nx; i6++) {
    b_x_new_tot->data[i6] = x_new_tot->data[(int)x->data[i6] - 1];
  }

  i6 = x_new_tot->size[0];
  x_new_tot->size[0] = b_x_new_tot->size[0];
  emxEnsureCapacity((emxArray__common *)x_new_tot, i6, (int)sizeof(double));
  nx = b_x_new_tot->size[0];
  for (i6 = 0; i6 < nx; i6++) {
    x_new_tot->data[i6] = b_x_new_tot->data[i6];
  }

  emxFree_real_T(&b_x_new_tot);
  emxInit_real_T1(&b_y_new_tot, 1);
  i6 = b_y_new_tot->size[0];
  b_y_new_tot->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)b_y_new_tot, i6, (int)sizeof(double));
  nx = x->size[0];
  for (i6 = 0; i6 < nx; i6++) {
    b_y_new_tot->data[i6] = y_new_tot->data[(int)x->data[i6] - 1];
  }

  emxFree_real_T(&x);
  i6 = y_new_tot->size[0];
  y_new_tot->size[0] = b_y_new_tot->size[0];
  emxEnsureCapacity((emxArray__common *)y_new_tot, i6, (int)sizeof(double));
  nx = b_y_new_tot->size[0];
  for (i6 = 0; i6 < nx; i6++) {
    y_new_tot->data[i6] = b_y_new_tot->data[i6];
  }

  emxFree_real_T(&b_y_new_tot);
}

/* End of code generation (resample_sld.c) */
