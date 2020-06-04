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
#include "resampleLayers.h"
#include "resample_sld.h"
#include "resampleLayers_emxutil.h"

/* Function Definitions */
void resample_sld(const emxArray_real_T *sld, emxArray_real_T *x_new_tot,
                  emxArray_real_T *y_new_tot)
{
  emxArray_real_T *x;
  int nx;
  int i1;
  emxArray_real_T *prof;
  emxArray_real_T *x_new;
  emxArray_real_T *y_new;
  unsigned int count;
  int i;
  emxArray_real_T *newsteps;
  emxArray_real_T *new_xs;
  emxArray_real_T *b_x_new;
  emxArray_real_T *b_y_new;
  int exitg2;
  double this_step;
  double a;
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
  int exitg3;
  emxArray_int32_T *ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_real_T *b_x_new_tot;
  emxArray_real_T *b_y_new_tot;
  emxInit_real_T1(&x, 1);

  /* coder.varsize('sld',[1e4 2],[1 0]); */
  nx = sld->size[0];
  i1 = x->size[0];
  x->size[0] = nx;
  emxEnsureCapacity((emxArray__common *)x, i1, (int)sizeof(double));
  for (i1 = 0; i1 < nx; i1++) {
    x->data[i1] = sld->data[i1];
  }

  emxInit_real_T1(&prof, 1);
  nx = sld->size[0];
  i1 = prof->size[0];
  prof->size[0] = nx;
  emxEnsureCapacity((emxArray__common *)prof, i1, (int)sizeof(double));
  for (i1 = 0; i1 < nx; i1++) {
    prof->data[i1] = sld->data[i1 + sld->size[0]];
  }

  emxInit_real_T(&x_new, 2);
  i1 = x_new->size[0] * x_new->size[1];
  x_new->size[0] = 10000;
  x_new->size[1] = 1;
  emxEnsureCapacity((emxArray__common *)x_new, i1, (int)sizeof(double));
  for (i1 = 0; i1 < 10000; i1++) {
    x_new->data[i1] = 0.0;
  }

  emxInit_real_T(&y_new, 2);
  i1 = y_new->size[0] * y_new->size[1];
  y_new->size[0] = 10000;
  y_new->size[1] = 1;
  emxEnsureCapacity((emxArray__common *)y_new, i1, (int)sizeof(double));
  for (i1 = 0; i1 < 10000; i1++) {
    y_new->data[i1] = 0.0;
  }

  count = 1U;
  i = 0;
  emxInit_real_T(&newsteps, 2);
  emxInit_real_T(&new_xs, 2);
  emxInit_real_T(&b_x_new, 2);
  emxInit_real_T(&b_y_new, 2);
  do {
    exitg2 = 0;
    i1 = sld->size[0];
    if (i + 2 < i1) {
      this_step = sld->data[(i + sld->size[0]) + 1] - sld->data[i + sld->size[0]];
      if (fabs(this_step) < 1.0) {
        /* Keep original points */
        x_new->data[(int)count - 1] = sld->data[i + 1];
        y_new->data[(int)count - 1] = sld->data[(i + sld->size[0]) + 1];
        count++;
        i++;
      } else {
        if (this_step > 0.0) {
          a = sld->data[i + sld->size[0]];
          this_step = sld->data[(i + sld->size[0]) + 1];
          if (rtIsNaN(a) || rtIsNaN(this_step)) {
            i1 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = 1;
            emxEnsureCapacity((emxArray__common *)newsteps, i1, (int)sizeof
                              (double));
            newsteps->data[0] = rtNaN;
          } else if (sld->data[(i + sld->size[0]) + 1] < sld->data[i + sld->
                     size[0]]) {
            i1 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = 0;
            emxEnsureCapacity((emxArray__common *)newsteps, i1, (int)sizeof
                              (double));
          } else if ((rtIsInf(a) || rtIsInf(this_step)) && (sld->data[i +
                      sld->size[0]] == sld->data[(i + sld->size[0]) + 1])) {
            i1 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = 1;
            emxEnsureCapacity((emxArray__common *)newsteps, i1, (int)sizeof
                              (double));
            newsteps->data[0] = rtNaN;
          } else if (floor(a) == sld->data[i + sld->size[0]]) {
            this_step = sld->data[i + sld->size[0]];
            apnd = sld->data[(i + sld->size[0]) + 1];
            i1 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = (int)floor(apnd - this_step) + 1;
            emxEnsureCapacity((emxArray__common *)newsteps, i1, (int)sizeof
                              (double));
            nx = (int)floor(apnd - this_step);
            for (i1 = 0; i1 <= nx; i1++) {
              newsteps->data[newsteps->size[0] * i1] = this_step + (double)i1;
            }
          } else {
            this_step = floor((sld->data[(i + sld->size[0]) + 1] - sld->data[i +
                               sld->size[0]]) + 0.5);
            apnd = sld->data[i + sld->size[0]] + this_step;
            cdiff = apnd - sld->data[(i + sld->size[0]) + 1];
            absa = fabs(sld->data[i + sld->size[0]]);
            absb = fabs(sld->data[(i + sld->size[0]) + 1]);
            if ((absa >= absb) || rtIsNaN(absb)) {
              absb = absa;
            }

            if (fabs(cdiff) < 4.4408920985006262E-16 * absb) {
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

            i1 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = idx;
            emxEnsureCapacity((emxArray__common *)newsteps, i1, (int)sizeof
                              (double));
            if (idx > 0) {
              newsteps->data[0] = sld->data[i + sld->size[0]];
              if (idx > 1) {
                newsteps->data[idx - 1] = apnd;
                nm1d2 = (idx - 1) / 2;
                for (nx = 1; nx < nm1d2; nx++) {
                  newsteps->data[nx] = a + (double)nx;
                  newsteps->data[(idx - nx) - 1] = apnd - (double)nx;
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
        } else {
          a = sld->data[i + sld->size[0]];
          this_step = sld->data[(i + sld->size[0]) + 1];
          if (rtIsNaN(a) || rtIsNaN(this_step)) {
            i1 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = 1;
            emxEnsureCapacity((emxArray__common *)newsteps, i1, (int)sizeof
                              (double));
            newsteps->data[0] = rtNaN;
          } else if (sld->data[i + sld->size[0]] < sld->data[(i + sld->size[0])
                     + 1]) {
            i1 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = 0;
            emxEnsureCapacity((emxArray__common *)newsteps, i1, (int)sizeof
                              (double));
          } else if ((rtIsInf(a) || rtIsInf(this_step)) && (sld->data[i +
                      sld->size[0]] == sld->data[(i + sld->size[0]) + 1])) {
            i1 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = 1;
            emxEnsureCapacity((emxArray__common *)newsteps, i1, (int)sizeof
                              (double));
            newsteps->data[0] = rtNaN;
          } else if (floor(a) == sld->data[i + sld->size[0]]) {
            this_step = sld->data[i + sld->size[0]];
            apnd = sld->data[(i + sld->size[0]) + 1];
            i1 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = (int)floor(-(apnd - this_step)) + 1;
            emxEnsureCapacity((emxArray__common *)newsteps, i1, (int)sizeof
                              (double));
            nx = (int)floor(-(apnd - this_step));
            for (i1 = 0; i1 <= nx; i1++) {
              newsteps->data[newsteps->size[0] * i1] = this_step - (double)i1;
            }
          } else {
            this_step = floor((sld->data[(i + sld->size[0]) + 1] - sld->data[i +
                               sld->size[0]]) / -1.0 + 0.5);
            apnd = sld->data[i + sld->size[0]] + -this_step;
            cdiff = sld->data[(i + sld->size[0]) + 1] - apnd;
            absa = fabs(sld->data[i + sld->size[0]]);
            absb = fabs(sld->data[(i + sld->size[0]) + 1]);
            if ((absa >= absb) || rtIsNaN(absb)) {
              absb = absa;
            }

            if (fabs(cdiff) < 4.4408920985006262E-16 * absb) {
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

            i1 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = idx;
            emxEnsureCapacity((emxArray__common *)newsteps, i1, (int)sizeof
                              (double));
            if (idx > 0) {
              newsteps->data[0] = sld->data[i + sld->size[0]];
              if (idx > 1) {
                newsteps->data[idx - 1] = apnd;
                nm1d2 = (idx - 1) / 2;
                for (nx = 1; nx < nm1d2; nx++) {
                  newsteps->data[nx] = a + -(double)nx;
                  newsteps->data[(idx - nx) - 1] = apnd - (-(double)nx);
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
        }

        for (i1 = 0; i1 < 2; i1++) {
          varargin_1[i1] = prof->data[i1 + i];
        }

        for (i1 = 0; i1 < 2; i1++) {
          varargin_2[i1] = x->data[i1 + i];
        }

        for (i1 = 0; i1 < 2; i1++) {
          outsize[i1] = (unsigned int)newsteps->size[i1];
        }

        i1 = new_xs->size[0] * new_xs->size[1];
        new_xs->size[0] = 1;
        new_xs->size[1] = (int)outsize[1];
        emxEnsureCapacity((emxArray__common *)new_xs, i1, (int)sizeof(double));
        nx = (int)outsize[1];
        for (i1 = 0; i1 < nx; i1++) {
          new_xs->data[i1] = rtNaN;
        }

        if (newsteps->size[1] != 0) {
          nx = -2;
          do {
            exitg3 = 0;
            if (nx + 3 < 3) {
              if (rtIsNaN(prof->data[(nx + i) + 2])) {
                exitg3 = 1;
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

              for (nx = 0; nx + 1 <= newsteps->size[1]; nx++) {
                this_step = new_xs->data[nx];
                if (rtIsNaN(newsteps->data[nx])) {
                  this_step = rtNaN;
                } else {
                  if ((!(newsteps->data[nx] > varargin_1[1])) &&
                      (!(newsteps->data[nx] < varargin_1[0]))) {
                    this_step = (newsteps->data[nx] - varargin_1[0]) /
                      (varargin_1[1] - varargin_1[0]);
                    if (this_step == 0.0) {
                      this_step = varargin_2[0];
                    } else if (this_step == 1.0) {
                      this_step = varargin_2[1];
                    } else if (varargin_2[0] == varargin_2[1]) {
                      this_step = varargin_2[0];
                    } else {
                      this_step = (1.0 - this_step) * varargin_2[0] + this_step *
                        varargin_2[1];
                    }
                  }
                }

                new_xs->data[nx] = this_step;
              }

              exitg3 = 1;
            }
          } while (exitg3 == 0);
        }

        if (!(new_xs->size[1] == 0)) {
          idx = new_xs->size[1];
        } else {
          idx = 0;
        }

        i1 = b_x_new->size[0] * b_x_new->size[1];
        b_x_new->size[0] = 10000;
        b_x_new->size[1] = x_new->size[1] + idx;
        emxEnsureCapacity((emxArray__common *)b_x_new, i1, (int)sizeof(double));
        nx = x_new->size[1];
        for (i1 = 0; i1 < nx; i1++) {
          for (nm1d2 = 0; nm1d2 < 10000; nm1d2++) {
            b_x_new->data[nm1d2 + b_x_new->size[0] * i1] = x_new->data[nm1d2 +
              x_new->size[0] * i1];
          }
        }

        for (i1 = 0; i1 < idx; i1++) {
          for (nm1d2 = 0; nm1d2 < 10000; nm1d2++) {
            b_x_new->data[nm1d2 + b_x_new->size[0] * (i1 + x_new->size[1])] =
              new_xs->data[nm1d2 + 10000 * i1];
          }
        }

        i1 = x_new->size[0] * x_new->size[1];
        x_new->size[0] = 10000;
        x_new->size[1] = b_x_new->size[1];
        emxEnsureCapacity((emxArray__common *)x_new, i1, (int)sizeof(double));
        nx = b_x_new->size[1];
        for (i1 = 0; i1 < nx; i1++) {
          for (nm1d2 = 0; nm1d2 < 10000; nm1d2++) {
            x_new->data[nm1d2 + x_new->size[0] * i1] = b_x_new->data[nm1d2 +
              b_x_new->size[0] * i1];
          }
        }

        if (!(newsteps->size[1] == 0)) {
          idx = newsteps->size[1];
        } else {
          idx = 0;
        }

        i1 = b_y_new->size[0] * b_y_new->size[1];
        b_y_new->size[0] = 10000;
        b_y_new->size[1] = y_new->size[1] + idx;
        emxEnsureCapacity((emxArray__common *)b_y_new, i1, (int)sizeof(double));
        nx = y_new->size[1];
        for (i1 = 0; i1 < nx; i1++) {
          for (nm1d2 = 0; nm1d2 < 10000; nm1d2++) {
            b_y_new->data[nm1d2 + b_y_new->size[0] * i1] = y_new->data[nm1d2 +
              y_new->size[0] * i1];
          }
        }

        for (i1 = 0; i1 < idx; i1++) {
          for (nm1d2 = 0; nm1d2 < 10000; nm1d2++) {
            b_y_new->data[nm1d2 + b_y_new->size[0] * (i1 + y_new->size[1])] =
              newsteps->data[nm1d2 + 10000 * i1];
          }
        }

        i1 = y_new->size[0] * y_new->size[1];
        y_new->size[0] = 10000;
        y_new->size[1] = b_y_new->size[1];
        emxEnsureCapacity((emxArray__common *)y_new, i1, (int)sizeof(double));
        nx = b_y_new->size[1];
        for (i1 = 0; i1 < nx; i1++) {
          for (nm1d2 = 0; nm1d2 < 10000; nm1d2++) {
            y_new->data[nm1d2 + y_new->size[0] * i1] = b_y_new->data[nm1d2 +
              b_y_new->size[0] * i1];
          }
        }

        nm1d2 = x_new->size[1];
        if (10000 >= nm1d2) {
          nm1d2 = 10000;
        }

        count = (unsigned int)nm1d2;
        i++;
      }
    } else {
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  emxFree_real_T(&b_y_new);
  emxFree_real_T(&b_x_new);
  emxFree_real_T(&new_xs);
  emxFree_real_T(&newsteps);
  emxFree_real_T(&prof);

  /* x_new_tot = x_new(:); */
  /* y_new_tot = y_new(:); */
  /* Make it into a 'histogram' */
  i1 = x_new_tot->size[0];
  x_new_tot->size[0] = (int)count;
  emxEnsureCapacity((emxArray__common *)x_new_tot, i1, (int)sizeof(double));
  nx = (int)count;
  for (i1 = 0; i1 < nx; i1++) {
    x_new_tot->data[i1] = 0.0;
  }

  i1 = y_new_tot->size[0];
  y_new_tot->size[0] = (int)count;
  emxEnsureCapacity((emxArray__common *)y_new_tot, i1, (int)sizeof(double));
  nx = (int)count;
  for (i1 = 0; i1 < nx; i1++) {
    y_new_tot->data[i1] = 0.0;
  }

  for (i = 0; i <= (int)count - 2; i++) {
    x_new_tot->data[i] = x_new->data[1 + i] - x_new->data[i];
    y_new_tot->data[i] = y_new->data[i];
  }

  emxFree_real_T(&y_new);
  emxFree_real_T(&x_new);
  emxInit_boolean_T(&b_x, 1);

  /* Remove any zero thickness layers... */
  i1 = b_x->size[0];
  b_x->size[0] = x_new_tot->size[0];
  emxEnsureCapacity((emxArray__common *)b_x, i1, (int)sizeof(boolean_T));
  nx = x_new_tot->size[0];
  for (i1 = 0; i1 < nx; i1++) {
    b_x->data[i1] = (x_new_tot->data[i1] != 0.0);
  }

  emxInit_int32_T(&ii, 1);
  nx = b_x->size[0];
  idx = 0;
  i1 = ii->size[0];
  ii->size[0] = b_x->size[0];
  emxEnsureCapacity((emxArray__common *)ii, i1, (int)sizeof(int));
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
      i1 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)ii, i1, (int)sizeof(int));
    }
  } else {
    i1 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity((emxArray__common *)ii, i1, (int)sizeof(int));
  }

  emxFree_boolean_T(&b_x);
  i1 = x->size[0];
  x->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)x, i1, (int)sizeof(double));
  nx = ii->size[0];
  for (i1 = 0; i1 < nx; i1++) {
    x->data[i1] = ii->data[i1];
  }

  emxFree_int32_T(&ii);
  emxInit_real_T1(&b_x_new_tot, 1);
  i1 = b_x_new_tot->size[0];
  b_x_new_tot->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)b_x_new_tot, i1, (int)sizeof(double));
  nx = x->size[0];
  for (i1 = 0; i1 < nx; i1++) {
    b_x_new_tot->data[i1] = x_new_tot->data[(int)x->data[i1] - 1];
  }

  i1 = x_new_tot->size[0];
  x_new_tot->size[0] = b_x_new_tot->size[0];
  emxEnsureCapacity((emxArray__common *)x_new_tot, i1, (int)sizeof(double));
  nx = b_x_new_tot->size[0];
  for (i1 = 0; i1 < nx; i1++) {
    x_new_tot->data[i1] = b_x_new_tot->data[i1];
  }

  emxFree_real_T(&b_x_new_tot);
  emxInit_real_T1(&b_y_new_tot, 1);
  i1 = b_y_new_tot->size[0];
  b_y_new_tot->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)b_y_new_tot, i1, (int)sizeof(double));
  nx = x->size[0];
  for (i1 = 0; i1 < nx; i1++) {
    b_y_new_tot->data[i1] = y_new_tot->data[(int)x->data[i1] - 1];
  }

  emxFree_real_T(&x);
  i1 = y_new_tot->size[0];
  y_new_tot->size[0] = b_y_new_tot->size[0];
  emxEnsureCapacity((emxArray__common *)y_new_tot, i1, (int)sizeof(double));
  nx = b_y_new_tot->size[0];
  for (i1 = 0; i1 < nx; i1++) {
    y_new_tot->data[i1] = b_y_new_tot->data[i1];
  }

  emxFree_real_T(&b_y_new_tot);
}

/* End of code generation (resample_sld.c) */
