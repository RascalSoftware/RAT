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
#include <math.h>
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "resample_sld.h"
#include "reflectivity_calculation_emxutil.h"
#include "interp1.h"
#include <string.h>

/* Function Definitions */
void resample_sld(const emxArray_real_T *sld, emxArray_real_T *x_new_tot,
                  emxArray_real_T *y_new_tot)
{
  emxArray_real_T *x;
  int nx;
  int i8;
  emxArray_real_T *prof;
  emxArray_real_T *x_new;
  emxArray_real_T *y_new;
  unsigned int count;
  int i;
  emxArray_real_T *newsteps;
  emxArray_real_T *new_xs;
  emxArray_real_T *b_x_new;
  int exitg1;
  double this_step;
  double apnd;
  double cdiff;
  double absa;
  int varargin_1_tmp[2];
  double absb;
  double varargin_1[2];
  double varargin_2[2];
  int idx;
  emxArray_boolean_T *b_x;
  int nm1d2;
  int exitg2;
  emxArray_int16_T *ii;
  int i9;
  boolean_T exitg3;
  emxInit_real_T(&x, 1);
  nx = sld->size[0];
  i8 = x->size[0];
  x->size[0] = nx;
  emxEnsureCapacity_real_T(x, i8);
  for (i8 = 0; i8 < nx; i8++) {
    x->data[i8] = sld->data[i8];
  }

  emxInit_real_T(&prof, 1);
  nx = sld->size[0];
  i8 = prof->size[0];
  prof->size[0] = nx;
  emxEnsureCapacity_real_T(prof, i8);
  for (i8 = 0; i8 < nx; i8++) {
    prof->data[i8] = sld->data[i8 + sld->size[0]];
  }

  emxInit_real_T(&x_new, 2);
  i8 = x_new->size[0] * x_new->size[1];
  x_new->size[0] = 10000;
  x_new->size[1] = 1;
  emxEnsureCapacity_real_T(x_new, i8);
  for (i8 = 0; i8 < 10000; i8++) {
    x_new->data[i8] = 0.0;
  }

  emxInit_real_T(&y_new, 2);
  i8 = y_new->size[0] * y_new->size[1];
  y_new->size[0] = 10000;
  y_new->size[1] = 1;
  emxEnsureCapacity_real_T(y_new, i8);
  for (i8 = 0; i8 < 10000; i8++) {
    y_new->data[i8] = 0.0;
  }

  count = 1U;
  i = 0;
  emxInit_real_T(&newsteps, 2);
  emxInit_real_T(&new_xs, 2);
  emxInit_real_T(&b_x_new, 2);
  do {
    exitg1 = 0;
    i8 = sld->size[0];
    if (i + 2 < i8) {
      this_step = sld->data[(i + sld->size[0]) + 1] - sld->data[i + sld->size[0]];
      if (fabs(this_step) < 1.0) {
        /* Keep original points */
        i8 = (int)count - 1;
        x_new->data[i8] = sld->data[i + 1];
        y_new->data[i8] = sld->data[(i + sld->size[0]) + 1];
        count++;
        i++;
      } else {
        if (this_step > 0.0) {
          if (rtIsNaN(sld->data[i + sld->size[0]]) || rtIsNaN(sld->data[(i +
                sld->size[0]) + 1])) {
            i8 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = 1;
            emxEnsureCapacity_real_T(newsteps, i8);
            newsteps->data[0] = rtNaN;
          } else if (sld->data[(i + sld->size[0]) + 1] < sld->data[i + sld->
                     size[0]]) {
            newsteps->size[0] = 1;
            newsteps->size[1] = 0;
          } else if ((rtIsInf(sld->data[i + sld->size[0]]) || rtIsInf(sld->data
                       [(i + sld->size[0]) + 1])) && (sld->data[i + sld->size[0]]
                      == sld->data[(i + sld->size[0]) + 1])) {
            i8 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = 1;
            emxEnsureCapacity_real_T(newsteps, i8);
            newsteps->data[0] = rtNaN;
          } else if (floor(sld->data[i + sld->size[0]]) == sld->data[i +
                     sld->size[0]]) {
            this_step = sld->data[(i + sld->size[0]) + 1];
            i8 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = (int)floor(this_step - sld->data[i + sld->size[0]])
              + 1;
            emxEnsureCapacity_real_T(newsteps, i8);
            nx = (int)floor(this_step - sld->data[i + sld->size[0]]);
            for (i8 = 0; i8 <= nx; i8++) {
              newsteps->data[i8] = sld->data[i + sld->size[0]] + (double)i8;
            }
          } else {
            this_step = floor((sld->data[(i + sld->size[0]) + 1] - sld->data[i +
                               sld->size[0]]) + 0.5);
            apnd = sld->data[i + sld->size[0]] + this_step;
            cdiff = apnd - sld->data[(i + sld->size[0]) + 1];
            absa = fabs(sld->data[i + sld->size[0]]);
            absb = fabs(sld->data[(i + sld->size[0]) + 1]);
            if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(absa, absb)) {
              this_step++;
              apnd = sld->data[(i + sld->size[0]) + 1];
            } else if (cdiff > 0.0) {
              apnd = sld->data[i + sld->size[0]] + (this_step - 1.0);
            } else {
              this_step++;
            }

            if (this_step >= 0.0) {
              idx = (int)this_step;
            } else {
              idx = 0;
            }

            i8 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = idx;
            emxEnsureCapacity_real_T(newsteps, i8);
            if (idx > 0) {
              newsteps->data[0] = sld->data[i + sld->size[0]];
              if (idx > 1) {
                newsteps->data[idx - 1] = apnd;
                nm1d2 = (idx - 1) / 2;
                for (nx = 0; nx <= nm1d2 - 2; nx++) {
                  newsteps->data[1 + nx] = sld->data[i + sld->size[0]] + (1.0 +
                    (double)nx);
                  newsteps->data[(idx - nx) - 2] = apnd - (1.0 + (double)nx);
                }

                if (nm1d2 << 1 == idx - 1) {
                  newsteps->data[nm1d2] = (sld->data[i + sld->size[0]] + apnd) /
                    2.0;
                } else {
                  newsteps->data[nm1d2] = sld->data[i + sld->size[0]] + (double)
                    nm1d2;
                  newsteps->data[nm1d2 + 1] = apnd - (double)nm1d2;
                }
              }
            }
          }
        } else if (rtIsNaN(sld->data[i + sld->size[0]]) || rtIsNaN(sld->data[(i
                     + sld->size[0]) + 1])) {
          i8 = newsteps->size[0] * newsteps->size[1];
          newsteps->size[0] = 1;
          newsteps->size[1] = 1;
          emxEnsureCapacity_real_T(newsteps, i8);
          newsteps->data[0] = rtNaN;
        } else if (sld->data[i + sld->size[0]] < sld->data[(i + sld->size[0]) +
                   1]) {
          newsteps->size[0] = 1;
          newsteps->size[1] = 0;
        } else if ((rtIsInf(sld->data[i + sld->size[0]]) || rtIsInf(sld->data[(i
          + sld->size[0]) + 1])) && (sld->data[i + sld->size[0]] == sld->data[(i
          + sld->size[0]) + 1])) {
          i8 = newsteps->size[0] * newsteps->size[1];
          newsteps->size[0] = 1;
          newsteps->size[1] = 1;
          emxEnsureCapacity_real_T(newsteps, i8);
          newsteps->data[0] = rtNaN;
        } else if (floor(sld->data[i + sld->size[0]]) == sld->data[i + sld->
                   size[0]]) {
          this_step = sld->data[(i + sld->size[0]) + 1];
          i8 = newsteps->size[0] * newsteps->size[1];
          newsteps->size[0] = 1;
          newsteps->size[1] = (int)floor(-(this_step - sld->data[i + sld->size[0]]))
            + 1;
          emxEnsureCapacity_real_T(newsteps, i8);
          nx = (int)floor(-(this_step - sld->data[i + sld->size[0]]));
          for (i8 = 0; i8 <= nx; i8++) {
            newsteps->data[i8] = sld->data[i + sld->size[0]] - (double)i8;
          }
        } else {
          this_step = floor((sld->data[(i + sld->size[0]) + 1] - sld->data[i +
                             sld->size[0]]) / -1.0 + 0.5);
          apnd = sld->data[i + sld->size[0]] + -this_step;
          cdiff = sld->data[(i + sld->size[0]) + 1] - apnd;
          absa = fabs(sld->data[i + sld->size[0]]);
          absb = fabs(sld->data[(i + sld->size[0]) + 1]);
          if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(absa, absb)) {
            this_step++;
            apnd = sld->data[(i + sld->size[0]) + 1];
          } else if (cdiff > 0.0) {
            apnd = sld->data[i + sld->size[0]] + -(this_step - 1.0);
          } else {
            this_step++;
          }

          if (this_step >= 0.0) {
            idx = (int)this_step;
          } else {
            idx = 0;
          }

          i8 = newsteps->size[0] * newsteps->size[1];
          newsteps->size[0] = 1;
          newsteps->size[1] = idx;
          emxEnsureCapacity_real_T(newsteps, i8);
          if (idx > 0) {
            newsteps->data[0] = sld->data[i + sld->size[0]];
            if (idx > 1) {
              newsteps->data[idx - 1] = apnd;
              nm1d2 = (idx - 1) / 2;
              for (nx = 0; nx <= nm1d2 - 2; nx++) {
                newsteps->data[1 + nx] = sld->data[i + sld->size[0]] + -(1.0 +
                  (double)nx);
                newsteps->data[(idx - nx) - 2] = apnd - (-(1.0 + (double)nx));
              }

              if (nm1d2 << 1 == idx - 1) {
                newsteps->data[nm1d2] = (sld->data[i + sld->size[0]] + apnd) /
                  2.0;
              } else {
                newsteps->data[nm1d2] = sld->data[i + sld->size[0]] + -(double)
                  nm1d2;
                newsteps->data[nm1d2 + 1] = apnd - (-(double)nm1d2);
              }
            }
          }
        }

        varargin_1_tmp[0] = i + 1;
        varargin_1_tmp[1] = i + 2;
        varargin_1[0] = prof->data[varargin_1_tmp[0] - 1];
        varargin_1[1] = prof->data[varargin_1_tmp[1] - 1];
        varargin_2[0] = x->data[varargin_1_tmp[0] - 1];
        varargin_2[1] = x->data[varargin_1_tmp[1] - 1];
        count = (unsigned int)newsteps->size[1];
        i8 = new_xs->size[0] * new_xs->size[1];
        new_xs->size[0] = 1;
        new_xs->size[1] = (int)count;
        emxEnsureCapacity_real_T(new_xs, i8);
        nx = (int)count;
        for (i8 = 0; i8 < nx; i8++) {
          new_xs->data[i8] = rtNaN;
        }

        if (newsteps->size[1] != 0) {
          nx = 0;
          do {
            exitg2 = 0;
            if (nx < 2) {
              if (rtIsNaN(prof->data[varargin_1_tmp[nx] - 1])) {
                exitg2 = 1;
              } else {
                nx++;
              }
            } else {
              if (prof->data[varargin_1_tmp[1] - 1] < prof->data[varargin_1_tmp
                  [0] - 1]) {
                varargin_1[0] = prof->data[varargin_1_tmp[1] - 1];
                varargin_1[1] = prof->data[varargin_1_tmp[0] - 1];
                varargin_2[0] = x->data[varargin_1_tmp[1] - 1];
                varargin_2[1] = x->data[varargin_1_tmp[0] - 1];
              }

              interp1Linear(varargin_2, newsteps, new_xs, varargin_1);
              exitg2 = 1;
            }
          } while (exitg2 == 0);
        }

        if (new_xs->size[1] != 0) {
          idx = new_xs->size[1];
        } else {
          idx = 0;
        }

        i8 = b_x_new->size[0] * b_x_new->size[1];
        b_x_new->size[0] = 10000;
        b_x_new->size[1] = x_new->size[1] + idx;
        emxEnsureCapacity_real_T(b_x_new, i8);
        nx = x_new->size[1];
        for (i8 = 0; i8 < nx; i8++) {
          for (nm1d2 = 0; nm1d2 < 10000; nm1d2++) {
            i9 = nm1d2 + 10000 * i8;
            b_x_new->data[i9] = x_new->data[i9];
          }
        }

        for (i8 = 0; i8 < idx; i8++) {
          for (nm1d2 = 0; nm1d2 < 10000; nm1d2++) {
            b_x_new->data[nm1d2 + 10000 * (i8 + x_new->size[1])] = new_xs->
              data[nm1d2 + 10000 * i8];
          }
        }

        i8 = x_new->size[0] * x_new->size[1];
        x_new->size[0] = 10000;
        x_new->size[1] = b_x_new->size[1];
        emxEnsureCapacity_real_T(x_new, i8);
        nx = b_x_new->size[0] * b_x_new->size[1];
        for (i8 = 0; i8 < nx; i8++) {
          x_new->data[i8] = b_x_new->data[i8];
        }

        if (newsteps->size[1] != 0) {
          idx = newsteps->size[1];
        } else {
          idx = 0;
        }

        i8 = b_x_new->size[0] * b_x_new->size[1];
        b_x_new->size[0] = 10000;
        b_x_new->size[1] = y_new->size[1] + idx;
        emxEnsureCapacity_real_T(b_x_new, i8);
        nx = y_new->size[1];
        for (i8 = 0; i8 < nx; i8++) {
          for (nm1d2 = 0; nm1d2 < 10000; nm1d2++) {
            i9 = nm1d2 + 10000 * i8;
            b_x_new->data[i9] = y_new->data[i9];
          }
        }

        for (i8 = 0; i8 < idx; i8++) {
          for (nm1d2 = 0; nm1d2 < 10000; nm1d2++) {
            b_x_new->data[nm1d2 + 10000 * (i8 + y_new->size[1])] =
              newsteps->data[nm1d2 + 10000 * i8];
          }
        }

        i8 = y_new->size[0] * y_new->size[1];
        y_new->size[0] = 10000;
        y_new->size[1] = b_x_new->size[1];
        emxEnsureCapacity_real_T(y_new, i8);
        nx = b_x_new->size[0] * b_x_new->size[1];
        for (i8 = 0; i8 < nx; i8++) {
          y_new->data[i8] = b_x_new->data[i8];
        }

        nm1d2 = x_new->size[1];
        if (10000 > nm1d2) {
          nm1d2 = 10000;
        }

        count = (unsigned int)nm1d2;
        i++;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_real_T(&b_x_new);
  emxFree_real_T(&new_xs);
  emxFree_real_T(&newsteps);

  /* x_new_tot = x_new(:); */
  /* y_new_tot = y_new(:); */
  /* Make it into a 'histogram' */
  i8 = x_new_tot->size[0];
  x_new_tot->size[0] = (int)count;
  emxEnsureCapacity_real_T(x_new_tot, i8);
  nx = (int)count;
  for (i8 = 0; i8 < nx; i8++) {
    x_new_tot->data[i8] = 0.0;
  }

  i8 = y_new_tot->size[0];
  y_new_tot->size[0] = (int)count;
  emxEnsureCapacity_real_T(y_new_tot, i8);
  nx = (int)count;
  for (i8 = 0; i8 < nx; i8++) {
    y_new_tot->data[i8] = 0.0;
  }

  i8 = (int)count;
  for (i = 0; i <= i8 - 2; i++) {
    x_new_tot->data[i] = x_new->data[i + 1] - x_new->data[i];
    y_new_tot->data[i] = y_new->data[i];
  }

  emxFree_real_T(&y_new);
  emxFree_real_T(&x_new);
  emxInit_boolean_T(&b_x, 1);

  /* Remove any zero thickness layers... */
  i8 = b_x->size[0];
  b_x->size[0] = x_new_tot->size[0];
  emxEnsureCapacity_boolean_T(b_x, i8);
  nx = x_new_tot->size[0];
  for (i8 = 0; i8 < nx; i8++) {
    b_x->data[i8] = (x_new_tot->data[i8] != 0.0);
  }

  emxInit_int16_T(&ii, 1);
  nx = b_x->size[0];
  idx = 0;
  i8 = ii->size[0];
  ii->size[0] = b_x->size[0];
  emxEnsureCapacity_int16_T(ii, i8);
  nm1d2 = 0;
  exitg3 = false;
  while ((!exitg3) && (nm1d2 <= nx - 1)) {
    if (b_x->data[nm1d2]) {
      idx++;
      ii->data[idx - 1] = (short)(nm1d2 + 1);
      if (idx >= nx) {
        exitg3 = true;
      } else {
        nm1d2++;
      }
    } else {
      nm1d2++;
    }
  }

  if (b_x->size[0] == 1) {
    if (idx == 0) {
      ii->size[0] = 0;
    }
  } else if (1 > idx) {
    ii->size[0] = 0;
  } else {
    i8 = ii->size[0];
    ii->size[0] = idx;
    emxEnsureCapacity_int16_T(ii, i8);
  }

  emxFree_boolean_T(&b_x);
  i8 = x->size[0];
  x->size[0] = ii->size[0];
  emxEnsureCapacity_real_T(x, i8);
  nx = ii->size[0];
  for (i8 = 0; i8 < nx; i8++) {
    x->data[i8] = ii->data[i8];
  }

  emxFree_int16_T(&ii);
  i8 = prof->size[0];
  prof->size[0] = x->size[0];
  emxEnsureCapacity_real_T(prof, i8);
  nx = x->size[0];
  for (i8 = 0; i8 < nx; i8++) {
    prof->data[i8] = x_new_tot->data[(int)x->data[i8] - 1];
  }

  i8 = x_new_tot->size[0];
  x_new_tot->size[0] = prof->size[0];
  emxEnsureCapacity_real_T(x_new_tot, i8);
  nx = prof->size[0];
  for (i8 = 0; i8 < nx; i8++) {
    x_new_tot->data[i8] = prof->data[i8];
  }

  i8 = prof->size[0];
  prof->size[0] = x->size[0];
  emxEnsureCapacity_real_T(prof, i8);
  nx = x->size[0];
  for (i8 = 0; i8 < nx; i8++) {
    prof->data[i8] = y_new_tot->data[(int)x->data[i8] - 1];
  }

  emxFree_real_T(&x);
  i8 = y_new_tot->size[0];
  y_new_tot->size[0] = prof->size[0];
  emxEnsureCapacity_real_T(y_new_tot, i8);
  nx = prof->size[0];
  for (i8 = 0; i8 < nx; i8++) {
    y_new_tot->data[i8] = prof->data[i8];
  }

  emxFree_real_T(&prof);
}

/* End of code generation (resample_sld.c) */
