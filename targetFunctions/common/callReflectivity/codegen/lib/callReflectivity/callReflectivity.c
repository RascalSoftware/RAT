/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * callReflectivity.c
 *
 * Code generation for function 'callReflectivity'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include "callReflectivity.h"
#include "callReflectivity_emxutil.h"
#include "paratt.h"

/* Function Definitions */
void callReflectivity(double nbairs, double nbsubs, const double simLimits[2],
                      const double repeatLayers[2], const double this_data[153],
                      const double layers_data[], const int layers_size[2],
                      double ssubs, double backgrounds, double res, double
                      reflectivity[102], emxArray_real_T *Simulation)
{
  int nm1d2;
  int slds_size[2];
  double slds_data[126];
  int i0;
  int lays;
  int i1;
  emxArray_real_T *firstSection;
  double step;
  double sumg;
  emxArray_real_T *lastSection;
  double ndbl;
  double apnd;
  double a;
  double cdiff;
  emxArray_real_T *simXdata;
  int ilow;
  int n;
  emxArray_real_T *simRef;
  emxArray_real_T *dummydata;
  unsigned int splits_idx_0;
  int varargin_2;
  double Ref[51];
  int i2;
  (void)backgrounds;

  /*  nbairs = problem.nbairs; */
  /*  nbsubs = problem.nbsubs; */
  /*  simLimits = problem.simLimits; */
  /*  repeatLayers = problem.repeatLayers; */
  /*  allData = problem.shifted_data; */
  /*  layers = problem.layers; */
  /*  ssubs = problem.ssubs; */
  /*  numberOfContrasts = problem.numberOfContrasts; */
  /*  reflectivity = cell(numberOfContrasts,1); */
  /*  Simulation = cell(numberOfContrasts,1); */
  /*   */
  /*  parfor i = 1:numberOfContrasts */
  /* this_data = allData{i}; */
  if (layers_size[0] == 0) {
    slds_size[0] = 1;
    slds_size[1] = 3;
    slds_data[0] = 0.0;
    slds_data[1] = nbairs;
    slds_data[2] = 0.0;
    lays = 0;
  } else {
    nm1d2 = layers_size[0];
    slds_size[0] = layers_size[0];
    slds_size[1] = 3;
    for (i0 = 0; i0 < 3; i0++) {
      for (i1 = 0; i1 < nm1d2; i1++) {
        slds_data[i1 + nm1d2 * i0] = layers_data[i1 + layers_size[0] * i0];
      }
    }

    lays = layers_size[0];
  }

  emxInit_real_T(&firstSection, 2);
  if (simLimits[0] < this_data[0]) {
    step = this_data[1] - this_data[0];
    sumg = this_data[0] - step;
    if (rtIsNaN(step) || rtIsNaN(sumg)) {
      i0 = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(firstSection, i0);
      firstSection->data[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits[0] < sumg) && (step < 0.0)) ||
               ((sumg < simLimits[0]) && (step > 0.0))) {
      firstSection->size[0] = 1;
      firstSection->size[1] = 0;
    } else if ((rtIsInf(simLimits[0]) || rtIsInf(sumg)) && (rtIsInf(step) ||
                (simLimits[0] == sumg))) {
      i0 = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(firstSection, i0);
      firstSection->data[0] = rtNaN;
    } else if (rtIsInf(step)) {
      i0 = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(firstSection, i0);
      firstSection->data[0] = simLimits[0];
    } else if ((floor(simLimits[0]) == simLimits[0]) && (floor(step) == step)) {
      i0 = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      nm1d2 = (int)floor((sumg - simLimits[0]) / step);
      firstSection->size[1] = nm1d2 + 1;
      emxEnsureCapacity_real_T(firstSection, i0);
      for (i0 = 0; i0 <= nm1d2; i0++) {
        firstSection->data[i0] = simLimits[0] + step * (double)i0;
      }
    } else {
      ndbl = floor((sumg - simLimits[0]) / step + 0.5);
      apnd = simLimits[0] + ndbl * step;
      if (step > 0.0) {
        cdiff = apnd - sumg;
      } else {
        cdiff = sumg - apnd;
      }

      if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(fabs(simLimits[0]), fabs
           (sumg))) {
        ndbl++;
        apnd = sumg;
      } else if (cdiff > 0.0) {
        apnd = simLimits[0] + (ndbl - 1.0) * step;
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        n = (int)ndbl;
      } else {
        n = 0;
      }

      i0 = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = n;
      emxEnsureCapacity_real_T(firstSection, i0);
      if (n > 0) {
        firstSection->data[0] = simLimits[0];
        if (n > 1) {
          firstSection->data[n - 1] = apnd;
          nm1d2 = (n - 1) / 2;
          for (ilow = 0; ilow <= nm1d2 - 2; ilow++) {
            ndbl = (1.0 + (double)ilow) * step;
            firstSection->data[1 + ilow] = simLimits[0] + ndbl;
            firstSection->data[(n - ilow) - 2] = apnd - ndbl;
          }

          if (nm1d2 << 1 == n - 1) {
            firstSection->data[nm1d2] = (simLimits[0] + apnd) / 2.0;
          } else {
            ndbl = (double)nm1d2 * step;
            firstSection->data[nm1d2] = simLimits[0] + ndbl;
            firstSection->data[nm1d2 + 1] = apnd - ndbl;
          }
        }
      }
    }
  } else {
    i0 = firstSection->size[0] * firstSection->size[1];
    firstSection->size[0] = 1;
    firstSection->size[1] = 1;
    emxEnsureCapacity_real_T(firstSection, i0);
    firstSection->data[0] = 0.0;
  }

  emxInit_real_T(&lastSection, 2);
  if (simLimits[1] > this_data[50]) {
    step = this_data[50] - this_data[49];
    a = this_data[50] + step;
    if (rtIsNaN(a) || rtIsNaN(step)) {
      i0 = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(lastSection, i0);
      lastSection->data[0] = rtNaN;
    } else if ((step == 0.0) || ((a < simLimits[1]) && (step < 0.0)) ||
               ((simLimits[1] < a) && (step > 0.0))) {
      lastSection->size[0] = 1;
      lastSection->size[1] = 0;
    } else if ((rtIsInf(a) || rtIsInf(simLimits[1])) && (rtIsInf(step) || (a ==
                 simLimits[1]))) {
      i0 = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(lastSection, i0);
      lastSection->data[0] = rtNaN;
    } else if (rtIsInf(step)) {
      i0 = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(lastSection, i0);
      lastSection->data[0] = a;
    } else if ((floor(a) == a) && (floor(step) == step)) {
      i0 = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      nm1d2 = (int)floor((simLimits[1] - a) / step);
      lastSection->size[1] = nm1d2 + 1;
      emxEnsureCapacity_real_T(lastSection, i0);
      for (i0 = 0; i0 <= nm1d2; i0++) {
        lastSection->data[i0] = a + step * (double)i0;
      }
    } else {
      ndbl = floor((simLimits[1] - a) / step + 0.5);
      apnd = a + ndbl * step;
      if (step > 0.0) {
        cdiff = apnd - simLimits[1];
      } else {
        cdiff = simLimits[1] - apnd;
      }

      if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(fabs(a), fabs(simLimits[1])))
      {
        ndbl++;
        apnd = simLimits[1];
      } else if (cdiff > 0.0) {
        apnd = a + (ndbl - 1.0) * step;
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        n = (int)ndbl;
      } else {
        n = 0;
      }

      i0 = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = n;
      emxEnsureCapacity_real_T(lastSection, i0);
      if (n > 0) {
        lastSection->data[0] = a;
        if (n > 1) {
          lastSection->data[n - 1] = apnd;
          nm1d2 = (n - 1) / 2;
          for (ilow = 0; ilow <= nm1d2 - 2; ilow++) {
            ndbl = (1.0 + (double)ilow) * step;
            lastSection->data[1 + ilow] = a + ndbl;
            lastSection->data[(n - ilow) - 2] = apnd - ndbl;
          }

          if (nm1d2 << 1 == n - 1) {
            lastSection->data[nm1d2] = (a + apnd) / 2.0;
          } else {
            ndbl = (double)nm1d2 * step;
            lastSection->data[nm1d2] = a + ndbl;
            lastSection->data[nm1d2 + 1] = apnd - ndbl;
          }
        }
      }
    }
  } else {
    i0 = lastSection->size[0] * lastSection->size[1];
    lastSection->size[0] = 1;
    lastSection->size[1] = 1;
    emxEnsureCapacity_real_T(lastSection, i0);
    lastSection->data[0] = 0.0;
  }

  emxInit_real_T(&simXdata, 2);
  nm1d2 = firstSection->size[1];
  ilow = lastSection->size[1];
  i0 = simXdata->size[0] * simXdata->size[1];
  simXdata->size[0] = 1;
  simXdata->size[1] = (nm1d2 + ilow) + 51;
  emxEnsureCapacity_real_T(simXdata, i0);
  for (i0 = 0; i0 < nm1d2; i0++) {
    simXdata->data[i0] = firstSection->data[i0];
  }

  for (i0 = 0; i0 < 51; i0++) {
    simXdata->data[i0 + nm1d2] = this_data[i0];
  }

  for (i0 = 0; i0 < ilow; i0++) {
    simXdata->data[(i0 + nm1d2) + 51] = lastSection->data[i0];
  }

  emxFree_real_T(&lastSection);
  emxInit_real_T(&simRef, 1);
  emxInit_real_T(&dummydata, 1);
  splits_idx_0 = (unsigned int)firstSection->size[1];
  paratt(simXdata, slds_data, slds_size, nbairs, nbsubs, repeatLayers[1], ssubs,
         lays, simXdata->size[1], simRef);
  varargin_2 = simXdata->size[1] - 10;
  i0 = dummydata->size[0];
  dummydata->size[0] = simXdata->size[1];
  emxEnsureCapacity_real_T(dummydata, i0);
  nm1d2 = simXdata->size[1];
  emxFree_real_T(&firstSection);
  for (i0 = 0; i0 < nm1d2; i0++) {
    dummydata->data[i0] = 0.0;
  }

  i0 = simXdata->size[1];
  for (nm1d2 = 0; nm1d2 < i0; nm1d2++) {
    sumg = 0.0;
    dummydata->data[nm1d2] = 0.0;
    if (1 + nm1d2 > 10) {
      ilow = -10;
    } else {
      ilow = -nm1d2;
    }

    /*     try */
    if (1 + nm1d2 < varargin_2) {
      i2 = 1;
    } else {
      i2 = varargin_2 - nm1d2;
    }

    i1 = (i2 - ilow) + 9;
    for (n = 0; n <= i1; n++) {
      lays = (nm1d2 + ilow) + n;
      a = (simXdata->data[lays] - simXdata->data[nm1d2]) / ((res + 0.0001) *
        simXdata->data[nm1d2]);
      ndbl = exp(-(a * a));
      sumg += ndbl;
      dummydata->data[nm1d2] += simRef->data[lays] * ndbl;
    }

    if (sumg != 0.0) {
      dummydata->data[nm1d2] /= sumg;
    }

    /*      catch */
    /*          disp('debug!'); */
    /*      end */
  }

  emxFree_real_T(&simRef);
  for (i0 = 0; i0 < 51; i0++) {
    Ref[i0] = dummydata->data[(int)(i0 + splits_idx_0)];
  }

  /* Ref = Ref + backgrounds; */
  for (i0 = 0; i0 < 51; i0++) {
    reflectivity[i0] = this_data[i0];
    reflectivity[51 + i0] = Ref[i0];
  }

  /* simRef = simRef + backgrounds; */
  i0 = Simulation->size[0] * Simulation->size[1];
  Simulation->size[0] = simXdata->size[1];
  Simulation->size[1] = 2;
  emxEnsureCapacity_real_T(Simulation, i0);
  nm1d2 = simXdata->size[1];
  for (i0 = 0; i0 < nm1d2; i0++) {
    Simulation->data[i0] = simXdata->data[i0];
  }

  emxFree_real_T(&simXdata);
  nm1d2 = dummydata->size[0];
  for (i0 = 0; i0 < nm1d2; i0++) {
    Simulation->data[i0 + Simulation->size[0]] = dummydata->data[i0];
  }

  emxFree_real_T(&dummydata);
}

/* End of code generation (callReflectivity.c) */
