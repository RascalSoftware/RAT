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
#include "rt_nonfinite.h"
#include "standardTF_custlay_single.h"
#include "callReflectivity.h"
#include "standardTF_custlay_single_emxutil.h"
#include "abeles.h"

/* Function Definitions */
void callReflectivity(double nbairs, double nbsubs, const double simLimits[2],
                      const double repeatLayers[2], const double this_data_data[],
                      const int this_data_size[2], const emxArray_real_T *layers,
                      double ssubs, double backgrounds, double res, double
                      reflectivity_data[], int reflectivity_size[2],
                      emxArray_real_T *Simulation)
{
  int loop_ub;
  int i7;
  emxArray_real_T *slds;
  double xdata_data[51];
  double dv0[3];
  int lays;
  int nm1d2;
  emxArray_real_T *firstSection;
  double middleSection_data[51];
  emxArray_real_T *simXdata;
  double step;
  double kd;
  emxArray_real_T *lastSection;
  double ndbl;
  double a;
  double apnd;
  double cdiff;
  int ilow;
  double absa;
  int lastSection_idx_0;
  double absb;
  int n;
  emxArray_real_T *simRef;
  emxArray_real_T *dummydata;
  unsigned int tmp_data[51];
  int i8;

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
  loop_ub = this_data_size[0];
  for (i7 = 0; i7 < loop_ub; i7++) {
    xdata_data[i7] = this_data_data[i7];
  }

  emxInit_real_T(&slds, 2);
  if (layers->size[0] == 0) {
    dv0[0] = 0.0;
    dv0[1] = nbairs;
    dv0[2] = 0.0;
    i7 = slds->size[0] * slds->size[1];
    slds->size[0] = 1;
    slds->size[1] = 3;
    emxEnsureCapacity((emxArray__common *)slds, i7, (int)sizeof(double));
    for (i7 = 0; i7 < 3; i7++) {
      slds->data[slds->size[0] * i7] = dv0[i7];
    }

    lays = 0;
  } else {
    loop_ub = layers->size[0];
    i7 = slds->size[0] * slds->size[1];
    slds->size[0] = loop_ub;
    slds->size[1] = 3;
    emxEnsureCapacity((emxArray__common *)slds, i7, (int)sizeof(double));
    for (i7 = 0; i7 < 3; i7++) {
      for (nm1d2 = 0; nm1d2 < loop_ub; nm1d2++) {
        slds->data[nm1d2 + slds->size[0] * i7] = layers->data[nm1d2 +
          layers->size[0] * i7];
      }
    }

    lays = layers->size[0];
  }

  loop_ub = this_data_size[0];
  for (i7 = 0; i7 < loop_ub; i7++) {
    middleSection_data[i7] = this_data_data[i7];
  }

  emxInit_real_T(&firstSection, 2);
  emxInit_real_T(&simXdata, 2);
  if (simLimits[0] < this_data_data[0]) {
    step = this_data_data[1] - this_data_data[0];
    kd = this_data_data[0] - step;
    if (rtIsNaN(step) || rtIsNaN(kd)) {
      i7 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)simXdata, i7, (int)sizeof(double));
      simXdata->data[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits[0] < kd) && (step < 0.0)) || ((kd <
                 simLimits[0]) && (step > 0.0))) {
      i7 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)simXdata, i7, (int)sizeof(double));
    } else if ((rtIsInf(simLimits[0]) || rtIsInf(kd)) && (rtIsInf(step) ||
                (simLimits[0] == kd))) {
      i7 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)simXdata, i7, (int)sizeof(double));
      simXdata->data[0] = rtNaN;
    } else if (rtIsInf(step)) {
      i7 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)simXdata, i7, (int)sizeof(double));
      simXdata->data[0] = simLimits[0];
    } else if ((floor(simLimits[0]) == simLimits[0]) && (floor(step) == step)) {
      i7 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = (int)floor((kd - simLimits[0]) / step) + 1;
      emxEnsureCapacity((emxArray__common *)simXdata, i7, (int)sizeof(double));
      nm1d2 = (int)floor((kd - simLimits[0]) / step);
      for (i7 = 0; i7 <= nm1d2; i7++) {
        simXdata->data[simXdata->size[0] * i7] = simLimits[0] + step * (double)
          i7;
      }
    } else {
      ndbl = floor((kd - simLimits[0]) / step + 0.5);
      apnd = simLimits[0] + ndbl * step;
      if (step > 0.0) {
        cdiff = apnd - kd;
      } else {
        cdiff = kd - apnd;
      }

      absa = fabs(simLimits[0]);
      absb = fabs(kd);
      if ((absa >= absb) || rtIsNaN(absb)) {
        absb = absa;
      }

      if (fabs(cdiff) < 4.4408920985006262E-16 * absb) {
        ndbl++;
        apnd = kd;
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

      i7 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = n;
      emxEnsureCapacity((emxArray__common *)simXdata, i7, (int)sizeof(double));
      if (n > 0) {
        simXdata->data[0] = simLimits[0];
        if (n > 1) {
          simXdata->data[n - 1] = apnd;
          nm1d2 = (n - 1) / 2;
          for (ilow = 1; ilow < nm1d2; ilow++) {
            kd = (double)ilow * step;
            simXdata->data[ilow] = simLimits[0] + kd;
            simXdata->data[(n - ilow) - 1] = apnd - kd;
          }

          if (nm1d2 << 1 == n - 1) {
            simXdata->data[nm1d2] = (simLimits[0] + apnd) / 2.0;
          } else {
            kd = (double)nm1d2 * step;
            simXdata->data[nm1d2] = simLimits[0] + kd;
            simXdata->data[nm1d2 + 1] = apnd - kd;
          }
        }
      }
    }

    i7 = firstSection->size[0] * firstSection->size[1];
    firstSection->size[0] = 1;
    firstSection->size[1] = simXdata->size[1];
    emxEnsureCapacity((emxArray__common *)firstSection, i7, (int)sizeof(double));
    nm1d2 = simXdata->size[0] * simXdata->size[1];
    for (i7 = 0; i7 < nm1d2; i7++) {
      firstSection->data[i7] = simXdata->data[i7];
    }
  } else {
    i7 = firstSection->size[0] * firstSection->size[1];
    firstSection->size[0] = 0;
    firstSection->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)firstSection, i7, (int)sizeof(double));
  }

  emxInit_real_T(&lastSection, 2);
  if (simLimits[1] > this_data_data[this_data_size[0] - 1]) {
    step = this_data_data[this_data_size[0] - 1] - xdata_data[this_data_size[0]
      - 2];
    a = xdata_data[this_data_size[0] - 1] + step;
    if (rtIsNaN(a) || rtIsNaN(step)) {
      i7 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)simXdata, i7, (int)sizeof(double));
      simXdata->data[0] = rtNaN;
    } else if ((step == 0.0) || ((a < simLimits[1]) && (step < 0.0)) ||
               ((simLimits[1] < a) && (step > 0.0))) {
      i7 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)simXdata, i7, (int)sizeof(double));
    } else if ((rtIsInf(a) || rtIsInf(simLimits[1])) && (rtIsInf(step) || (a ==
                 simLimits[1]))) {
      i7 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)simXdata, i7, (int)sizeof(double));
      simXdata->data[0] = rtNaN;
    } else if (rtIsInf(step)) {
      i7 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)simXdata, i7, (int)sizeof(double));
      simXdata->data[0] = a;
    } else if ((floor(a) == a) && (floor(step) == step)) {
      i7 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = (int)floor((simLimits[1] - a) / step) + 1;
      emxEnsureCapacity((emxArray__common *)simXdata, i7, (int)sizeof(double));
      nm1d2 = (int)floor((simLimits[1] - a) / step);
      for (i7 = 0; i7 <= nm1d2; i7++) {
        simXdata->data[simXdata->size[0] * i7] = a + step * (double)i7;
      }
    } else {
      ndbl = floor((simLimits[1] - a) / step + 0.5);
      apnd = a + ndbl * step;
      if (step > 0.0) {
        cdiff = apnd - simLimits[1];
      } else {
        cdiff = simLimits[1] - apnd;
      }

      absa = fabs(a);
      absb = fabs(simLimits[1]);
      if (absa >= absb) {
        absb = absa;
      }

      if (fabs(cdiff) < 4.4408920985006262E-16 * absb) {
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

      i7 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = n;
      emxEnsureCapacity((emxArray__common *)simXdata, i7, (int)sizeof(double));
      if (n > 0) {
        simXdata->data[0] = a;
        if (n > 1) {
          simXdata->data[n - 1] = apnd;
          nm1d2 = (n - 1) / 2;
          for (ilow = 1; ilow < nm1d2; ilow++) {
            kd = (double)ilow * step;
            simXdata->data[ilow] = a + kd;
            simXdata->data[(n - ilow) - 1] = apnd - kd;
          }

          if (nm1d2 << 1 == n - 1) {
            simXdata->data[nm1d2] = (a + apnd) / 2.0;
          } else {
            kd = (double)nm1d2 * step;
            simXdata->data[nm1d2] = a + kd;
            simXdata->data[nm1d2 + 1] = apnd - kd;
          }
        }
      }
    }

    i7 = lastSection->size[0] * lastSection->size[1];
    lastSection->size[0] = 1;
    lastSection->size[1] = simXdata->size[1];
    emxEnsureCapacity((emxArray__common *)lastSection, i7, (int)sizeof(double));
    nm1d2 = simXdata->size[0] * simXdata->size[1];
    for (i7 = 0; i7 < nm1d2; i7++) {
      lastSection->data[i7] = simXdata->data[i7];
    }
  } else {
    i7 = lastSection->size[0] * lastSection->size[1];
    lastSection->size[0] = 0;
    lastSection->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)lastSection, i7, (int)sizeof(double));
  }

  ilow = firstSection->size[0] * firstSection->size[1];
  lastSection_idx_0 = lastSection->size[0] * lastSection->size[1];
  i7 = simXdata->size[0] * simXdata->size[1];
  simXdata->size[0] = 1;
  simXdata->size[1] = (ilow + this_data_size[0]) + lastSection_idx_0;
  emxEnsureCapacity((emxArray__common *)simXdata, i7, (int)sizeof(double));
  for (i7 = 0; i7 < ilow; i7++) {
    simXdata->data[simXdata->size[0] * i7] = firstSection->data[i7];
  }

  nm1d2 = this_data_size[0];
  for (i7 = 0; i7 < nm1d2; i7++) {
    simXdata->data[simXdata->size[0] * (i7 + ilow)] = middleSection_data[i7];
  }

  for (i7 = 0; i7 < lastSection_idx_0; i7++) {
    simXdata->data[simXdata->size[0] * ((i7 + ilow) + loop_ub)] =
      lastSection->data[i7];
  }

  if ((firstSection->size[0] == 0) || (firstSection->size[1] == 0)) {
    n = 0;
  } else {
    n = firstSection->size[1];
  }

  emxFree_real_T(&firstSection);
  emxFree_real_T(&lastSection);
  emxInit_real_T1(&simRef, 1);
  emxInit_real_T1(&dummydata, 1);
  abeles(simXdata, slds, nbairs, nbsubs, repeatLayers[1], ssubs, lays,
         simXdata->size[1], simRef);
  lays = simXdata->size[1] - 10;
  i7 = dummydata->size[0];
  dummydata->size[0] = simXdata->size[1];
  emxEnsureCapacity((emxArray__common *)dummydata, i7, (int)sizeof(double));
  loop_ub = simXdata->size[1];
  emxFree_real_T(&slds);
  for (i7 = 0; i7 < loop_ub; i7++) {
    dummydata->data[i7] = 0.0;
  }

  for (nm1d2 = 0; nm1d2 < simXdata->size[1]; nm1d2++) {
    ndbl = 0.0;
    dummydata->data[nm1d2] = 0.0;
    if (1 + nm1d2 > 10) {
      ilow = -10;
    } else {
      ilow = -nm1d2;
    }

    /*     try */
    if (1 + nm1d2 < lays) {
      i8 = 10;
    } else {
      i8 = (lays - nm1d2) + 9;
    }

    i7 = (int)((double)i8 + (1.0 - (double)ilow));
    for (lastSection_idx_0 = 0; lastSection_idx_0 < i7; lastSection_idx_0++) {
      cdiff = (double)ilow + (double)lastSection_idx_0;
      kd = simXdata->data[(int)((1.0 + (double)nm1d2) + cdiff) - 1] -
        simXdata->data[nm1d2];
      kd /= (res + 0.0001) * simXdata->data[nm1d2];
      kd = exp(-(kd * kd));
      ndbl += kd;
      dummydata->data[nm1d2] += simRef->data[(int)(cdiff + (1.0 + (double)nm1d2))
        - 1] * kd;
    }

    if (ndbl != 0.0) {
      dummydata->data[nm1d2] /= ndbl;
    }

    /*      catch */
    /*          disp('debug!'); */
    /*      end */
  }

  loop_ub = (int)(this_data_size[0] + MAX_uint32_T);
  for (i7 = 0; i7 <= loop_ub; i7++) {
    tmp_data[i7] = ((unsigned int)i7 + n) + 1U;
  }

  i7 = simRef->size[0];
  simRef->size[0] = this_data_size[0];
  emxEnsureCapacity((emxArray__common *)simRef, i7, (int)sizeof(double));
  loop_ub = this_data_size[0];
  for (i7 = 0; i7 < loop_ub; i7++) {
    simRef->data[i7] = dummydata->data[(int)tmp_data[i7] - 1] + backgrounds;
  }

  nm1d2 = simRef->size[0];
  reflectivity_size[0] = this_data_size[0];
  reflectivity_size[1] = 2;
  loop_ub = this_data_size[0];
  for (i7 = 0; i7 < loop_ub; i7++) {
    reflectivity_data[i7] = middleSection_data[i7];
  }

  for (i7 = 0; i7 < nm1d2; i7++) {
    reflectivity_data[i7 + reflectivity_size[0]] = simRef->data[i7];
  }

  emxFree_real_T(&simRef);
  i7 = Simulation->size[0] * Simulation->size[1];
  Simulation->size[0] = simXdata->size[1];
  Simulation->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)Simulation, i7, (int)sizeof(double));
  loop_ub = simXdata->size[1];
  for (i7 = 0; i7 < loop_ub; i7++) {
    Simulation->data[i7] = simXdata->data[simXdata->size[0] * i7];
  }

  emxFree_real_T(&simXdata);
  loop_ub = dummydata->size[0];
  for (i7 = 0; i7 < loop_ub; i7++) {
    Simulation->data[i7 + Simulation->size[0]] = dummydata->data[i7] +
      backgrounds;
  }

  emxFree_real_T(&dummydata);
}

/* End of code generation (callReflectivity.c) */
