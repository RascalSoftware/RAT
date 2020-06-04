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
#include <string.h>
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "callReflectivity.h"
#include "reflectivity_calculation_emxutil.h"
#include "paratt.h"

/* Function Definitions */
void callReflectivity(double nbairs, double nbsubs, const double simLimits[2],
                      const double repeatLayers[2], const double this_data_data[],
                      const int this_data_size[2], const emxArray_real_T *layers,
                      double ssubs, double backgrounds, double res, double
                      reflectivity_data[], int reflectivity_size[2],
                      emxArray_real_T *Simulation)
{
  emxArray_real_T *slds;
  int loop_ub;
  int i11;
  int lays;
  int i12;
  emxArray_real_T *firstSection;
  double step;
  double sumg;
  emxArray_real_T *lastSection;
  double ndbl;
  double apnd;
  double a;
  double cdiff;
  emxArray_real_T *simXdata;
  int nm1d2;
  int ilow;
  emxArray_real_T *simRef;
  emxArray_real_T *dummydata;
  unsigned int splits_idx_0;
  int varargin_2;
  unsigned int tmp_data[51];
  int i13;

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
  emxInit_real_T(&slds, 2);
  if (layers->size[0] == 0) {
    i11 = slds->size[0] * slds->size[1];
    slds->size[0] = 1;
    slds->size[1] = 3;
    emxEnsureCapacity_real_T(slds, i11);
    slds->data[0] = 0.0;
    slds->data[1] = nbairs;
    slds->data[2] = 0.0;
    lays = 0;
  } else {
    loop_ub = layers->size[0];
    i11 = slds->size[0] * slds->size[1];
    slds->size[0] = loop_ub;
    slds->size[1] = 3;
    emxEnsureCapacity_real_T(slds, i11);
    for (i11 = 0; i11 < 3; i11++) {
      for (i12 = 0; i12 < loop_ub; i12++) {
        slds->data[i12 + slds->size[0] * i11] = layers->data[i12 + layers->size
          [0] * i11];
      }
    }

    lays = layers->size[0];
  }

  emxInit_real_T(&firstSection, 2);
  if (simLimits[0] < this_data_data[0]) {
    step = this_data_data[1] - this_data_data[0];
    sumg = this_data_data[0] - step;
    if (rtIsNaN(step) || rtIsNaN(sumg)) {
      i11 = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(firstSection, i11);
      firstSection->data[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits[0] < sumg) && (step < 0.0)) ||
               ((sumg < simLimits[0]) && (step > 0.0))) {
      firstSection->size[0] = 1;
      firstSection->size[1] = 0;
    } else if ((rtIsInf(simLimits[0]) || rtIsInf(sumg)) && (rtIsInf(step) ||
                (simLimits[0] == sumg))) {
      i11 = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(firstSection, i11);
      firstSection->data[0] = rtNaN;
    } else if (rtIsInf(step)) {
      i11 = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(firstSection, i11);
      firstSection->data[0] = simLimits[0];
    } else if ((floor(simLimits[0]) == simLimits[0]) && (floor(step) == step)) {
      i11 = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      loop_ub = (int)floor((sumg - simLimits[0]) / step);
      firstSection->size[1] = loop_ub + 1;
      emxEnsureCapacity_real_T(firstSection, i11);
      for (i11 = 0; i11 <= loop_ub; i11++) {
        firstSection->data[i11] = simLimits[0] + step * (double)i11;
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
        loop_ub = (int)ndbl;
      } else {
        loop_ub = 0;
      }

      i11 = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = loop_ub;
      emxEnsureCapacity_real_T(firstSection, i11);
      if (loop_ub > 0) {
        firstSection->data[0] = simLimits[0];
        if (loop_ub > 1) {
          firstSection->data[loop_ub - 1] = apnd;
          nm1d2 = (loop_ub - 1) / 2;
          for (ilow = 0; ilow <= nm1d2 - 2; ilow++) {
            ndbl = (1.0 + (double)ilow) * step;
            firstSection->data[1 + ilow] = simLimits[0] + ndbl;
            firstSection->data[(loop_ub - ilow) - 2] = apnd - ndbl;
          }

          if (nm1d2 << 1 == loop_ub - 1) {
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
    i11 = firstSection->size[0] * firstSection->size[1];
    firstSection->size[0] = 1;
    firstSection->size[1] = 1;
    emxEnsureCapacity_real_T(firstSection, i11);
    firstSection->data[0] = 0.0;
  }

  emxInit_real_T(&lastSection, 2);
  ndbl = this_data_data[this_data_size[0] - 1];
  if (simLimits[1] > ndbl) {
    step = ndbl - this_data_data[this_data_size[0] - 2];
    a = ndbl + step;
    if (rtIsNaN(a) || rtIsNaN(step)) {
      i11 = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(lastSection, i11);
      lastSection->data[0] = rtNaN;
    } else if ((step == 0.0) || ((a < simLimits[1]) && (step < 0.0)) ||
               ((simLimits[1] < a) && (step > 0.0))) {
      lastSection->size[0] = 1;
      lastSection->size[1] = 0;
    } else if ((rtIsInf(a) || rtIsInf(simLimits[1])) && (rtIsInf(step) || (a ==
                 simLimits[1]))) {
      i11 = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(lastSection, i11);
      lastSection->data[0] = rtNaN;
    } else if (rtIsInf(step)) {
      i11 = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(lastSection, i11);
      lastSection->data[0] = a;
    } else if ((floor(a) == a) && (floor(step) == step)) {
      i11 = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      loop_ub = (int)floor((simLimits[1] - a) / step);
      lastSection->size[1] = loop_ub + 1;
      emxEnsureCapacity_real_T(lastSection, i11);
      for (i11 = 0; i11 <= loop_ub; i11++) {
        lastSection->data[i11] = a + step * (double)i11;
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
        loop_ub = (int)ndbl;
      } else {
        loop_ub = 0;
      }

      i11 = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = loop_ub;
      emxEnsureCapacity_real_T(lastSection, i11);
      if (loop_ub > 0) {
        lastSection->data[0] = a;
        if (loop_ub > 1) {
          lastSection->data[loop_ub - 1] = apnd;
          nm1d2 = (loop_ub - 1) / 2;
          for (ilow = 0; ilow <= nm1d2 - 2; ilow++) {
            ndbl = (1.0 + (double)ilow) * step;
            lastSection->data[1 + ilow] = a + ndbl;
            lastSection->data[(loop_ub - ilow) - 2] = apnd - ndbl;
          }

          if (nm1d2 << 1 == loop_ub - 1) {
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
    i11 = lastSection->size[0] * lastSection->size[1];
    lastSection->size[0] = 1;
    lastSection->size[1] = 1;
    emxEnsureCapacity_real_T(lastSection, i11);
    lastSection->data[0] = 0.0;
  }

  emxInit_real_T(&simXdata, 2);
  nm1d2 = firstSection->size[1];
  ilow = lastSection->size[1];
  loop_ub = this_data_size[0];
  i11 = simXdata->size[0] * simXdata->size[1];
  simXdata->size[0] = 1;
  simXdata->size[1] = (nm1d2 + this_data_size[0]) + ilow;
  emxEnsureCapacity_real_T(simXdata, i11);
  for (i11 = 0; i11 < nm1d2; i11++) {
    simXdata->data[i11] = firstSection->data[i11];
  }

  for (i11 = 0; i11 < loop_ub; i11++) {
    simXdata->data[i11 + nm1d2] = this_data_data[i11];
  }

  for (i11 = 0; i11 < ilow; i11++) {
    simXdata->data[(i11 + nm1d2) + loop_ub] = lastSection->data[i11];
  }

  emxFree_real_T(&lastSection);
  emxInit_real_T(&simRef, 1);
  emxInit_real_T(&dummydata, 1);
  splits_idx_0 = (unsigned int)firstSection->size[1];
  paratt(simXdata, slds, nbairs, nbsubs, repeatLayers[1], ssubs, lays,
         simXdata->size[1], simRef);
  varargin_2 = simXdata->size[1] - 10;
  i11 = dummydata->size[0];
  dummydata->size[0] = simXdata->size[1];
  emxEnsureCapacity_real_T(dummydata, i11);
  loop_ub = simXdata->size[1];
  emxFree_real_T(&firstSection);
  emxFree_real_T(&slds);
  for (i11 = 0; i11 < loop_ub; i11++) {
    dummydata->data[i11] = 0.0;
  }

  i11 = simXdata->size[1];
  for (nm1d2 = 0; nm1d2 < i11; nm1d2++) {
    sumg = 0.0;
    dummydata->data[nm1d2] = 0.0;
    if (1 + nm1d2 > 10) {
      ilow = -10;
    } else {
      ilow = -nm1d2;
    }

    /*     try */
    if (1 + nm1d2 < varargin_2) {
      i13 = 1;
    } else {
      i13 = varargin_2 - nm1d2;
    }

    i12 = (i13 - ilow) + 9;
    for (loop_ub = 0; loop_ub <= i12; loop_ub++) {
      lays = (nm1d2 + ilow) + loop_ub;
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
  loop_ub = this_data_size[0] - 1;
  for (i11 = 0; i11 <= loop_ub; i11++) {
    tmp_data[i11] = i11 + (splits_idx_0 + 1U);
  }

  /* Ref = Ref + backgrounds; */
  reflectivity_size[0] = this_data_size[0];
  reflectivity_size[1] = 2;
  if (0 <= this_data_size[0] - 1) {
    memcpy(&reflectivity_data[0], &this_data_data[0], (unsigned int)
           (this_data_size[0] * (int)sizeof(double)));
  }

  loop_ub = this_data_size[0];
  for (i11 = 0; i11 < loop_ub; i11++) {
    reflectivity_data[i11 + reflectivity_size[0]] = dummydata->data[(int)
      tmp_data[i11] - 1];
  }

  i11 = Simulation->size[0] * Simulation->size[1];
  Simulation->size[0] = simXdata->size[1];
  Simulation->size[1] = 2;
  emxEnsureCapacity_real_T(Simulation, i11);
  loop_ub = simXdata->size[1];
  for (i11 = 0; i11 < loop_ub; i11++) {
    Simulation->data[i11] = simXdata->data[i11];
  }

  emxFree_real_T(&simXdata);
  loop_ub = dummydata->size[0];
  for (i11 = 0; i11 < loop_ub; i11++) {
    Simulation->data[i11 + Simulation->size[0]] = dummydata->data[i11] +
      backgrounds;
  }

  emxFree_real_T(&dummydata);
}

/* End of code generation (callReflectivity.c) */
