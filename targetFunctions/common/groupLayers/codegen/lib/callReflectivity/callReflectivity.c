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
#include "callReflectivity.h"
#include "callReflectivity_emxutil.h"
#include "abeles.h"

/* Function Definitions */
void callReflectivity(double nbairs, double nbsubs, const double simLimits[2],
                      const double repeatLayers[2], const emxArray_real_T
                      *this_data, const emxArray_real_T *layers, double ssubs,
                      double backgrounds, double res, emxArray_real_T
                      *reflectivity, emxArray_real_T *Simulation)
{
  emxArray_real_T *xdata;
  int loop_ub;
  int i0;
  emxArray_real_T *slds;
  double dv0[3];
  int lays;
  int i1;
  emxArray_real_T *middleSection;
  emxArray_real_T *firstSection;
  emxArray_real_T *simXdata;
  double step;
  double kd;
  emxArray_real_T *lastSection;
  double ndbl;
  double apnd;
  double cdiff;
  double a;
  double absa;
  int nm1d2;
  double absb;
  int ilow;
  int n;
  emxArray_real_T *dummydata;
  emxArray_uint32_T *r0;
  int i2;
  emxInit_real_T(&xdata, 1);

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
  loop_ub = this_data->size[0];
  i0 = xdata->size[0];
  xdata->size[0] = loop_ub;
  emxEnsureCapacity((emxArray__common *)xdata, i0, (int)sizeof(double));
  for (i0 = 0; i0 < loop_ub; i0++) {
    xdata->data[i0] = this_data->data[i0];
  }

  emxInit_real_T1(&slds, 2);
  if (layers->size[0] == 0) {
    dv0[0] = 0.0;
    dv0[1] = nbairs;
    dv0[2] = 0.0;
    i0 = slds->size[0] * slds->size[1];
    slds->size[0] = 1;
    slds->size[1] = 3;
    emxEnsureCapacity((emxArray__common *)slds, i0, (int)sizeof(double));
    for (i0 = 0; i0 < 3; i0++) {
      slds->data[slds->size[0] * i0] = dv0[i0];
    }

    lays = 0;
  } else {
    loop_ub = layers->size[0];
    i0 = slds->size[0] * slds->size[1];
    slds->size[0] = loop_ub;
    slds->size[1] = 3;
    emxEnsureCapacity((emxArray__common *)slds, i0, (int)sizeof(double));
    for (i0 = 0; i0 < 3; i0++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        slds->data[i1 + slds->size[0] * i0] = layers->data[i1 + layers->size[0] *
          i0];
      }
    }

    lays = layers->size[0];
  }

  emxInit_real_T(&middleSection, 1);
  loop_ub = this_data->size[0];
  i0 = middleSection->size[0];
  middleSection->size[0] = loop_ub;
  emxEnsureCapacity((emxArray__common *)middleSection, i0, (int)sizeof(double));
  for (i0 = 0; i0 < loop_ub; i0++) {
    middleSection->data[i0] = this_data->data[i0];
  }

  emxInit_real_T1(&firstSection, 2);
  emxInit_real_T1(&simXdata, 2);
  if (simLimits[0] < this_data->data[0]) {
    step = this_data->data[1] - this_data->data[0];
    kd = this_data->data[0] - step;
    if (rtIsNaN(step) || rtIsNaN(kd)) {
      i0 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)simXdata, i0, (int)sizeof(double));
      simXdata->data[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits[0] < kd) && (step < 0.0)) || ((kd <
                 simLimits[0]) && (step > 0.0))) {
      i0 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)simXdata, i0, (int)sizeof(double));
    } else if ((rtIsInf(simLimits[0]) || rtIsInf(kd)) && (rtIsInf(step) ||
                (simLimits[0] == kd))) {
      i0 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)simXdata, i0, (int)sizeof(double));
      simXdata->data[0] = rtNaN;
    } else if (rtIsInf(step)) {
      i0 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)simXdata, i0, (int)sizeof(double));
      simXdata->data[0] = simLimits[0];
    } else if ((floor(simLimits[0]) == simLimits[0]) && (floor(step) == step)) {
      i0 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = (int)floor((kd - simLimits[0]) / step) + 1;
      emxEnsureCapacity((emxArray__common *)simXdata, i0, (int)sizeof(double));
      loop_ub = (int)floor((kd - simLimits[0]) / step);
      for (i0 = 0; i0 <= loop_ub; i0++) {
        simXdata->data[simXdata->size[0] * i0] = simLimits[0] + step * (double)
          i0;
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

      i0 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = n;
      emxEnsureCapacity((emxArray__common *)simXdata, i0, (int)sizeof(double));
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

    i0 = firstSection->size[0] * firstSection->size[1];
    firstSection->size[0] = 1;
    firstSection->size[1] = simXdata->size[1];
    emxEnsureCapacity((emxArray__common *)firstSection, i0, (int)sizeof(double));
    loop_ub = simXdata->size[0] * simXdata->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      firstSection->data[i0] = simXdata->data[i0];
    }
  } else {
    i0 = firstSection->size[0] * firstSection->size[1];
    firstSection->size[0] = 0;
    firstSection->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)firstSection, i0, (int)sizeof(double));
  }

  i0 = this_data->size[0];
  emxInit_real_T1(&lastSection, 2);
  if (simLimits[1] > this_data->data[i0 - 1]) {
    i0 = this_data->size[0] - 1;
    i1 = this_data->size[0] - 2;
    step = this_data->data[i0] - xdata->data[i1];
    i0 = this_data->size[0] - 1;
    a = xdata->data[i0] + step;
    if (rtIsNaN(a) || rtIsNaN(step)) {
      i0 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)simXdata, i0, (int)sizeof(double));
      simXdata->data[0] = rtNaN;
    } else if ((step == 0.0) || ((a < simLimits[1]) && (step < 0.0)) ||
               ((simLimits[1] < a) && (step > 0.0))) {
      i0 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)simXdata, i0, (int)sizeof(double));
    } else if ((rtIsInf(a) || rtIsInf(simLimits[1])) && (rtIsInf(step) || (a ==
                 simLimits[1]))) {
      i0 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)simXdata, i0, (int)sizeof(double));
      simXdata->data[0] = rtNaN;
    } else if (rtIsInf(step)) {
      i0 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)simXdata, i0, (int)sizeof(double));
      simXdata->data[0] = a;
    } else if ((floor(a) == a) && (floor(step) == step)) {
      i0 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = (int)floor((simLimits[1] - a) / step) + 1;
      emxEnsureCapacity((emxArray__common *)simXdata, i0, (int)sizeof(double));
      loop_ub = (int)floor((simLimits[1] - a) / step);
      for (i0 = 0; i0 <= loop_ub; i0++) {
        simXdata->data[simXdata->size[0] * i0] = a + step * (double)i0;
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

      i0 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = n;
      emxEnsureCapacity((emxArray__common *)simXdata, i0, (int)sizeof(double));
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

    i0 = lastSection->size[0] * lastSection->size[1];
    lastSection->size[0] = 1;
    lastSection->size[1] = simXdata->size[1];
    emxEnsureCapacity((emxArray__common *)lastSection, i0, (int)sizeof(double));
    loop_ub = simXdata->size[0] * simXdata->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      lastSection->data[i0] = simXdata->data[i0];
    }
  } else {
    i0 = lastSection->size[0] * lastSection->size[1];
    lastSection->size[0] = 0;
    lastSection->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)lastSection, i0, (int)sizeof(double));
  }

  nm1d2 = firstSection->size[0] * firstSection->size[1];
  ilow = lastSection->size[0] * lastSection->size[1];
  i0 = simXdata->size[0] * simXdata->size[1];
  simXdata->size[0] = 1;
  simXdata->size[1] = (nm1d2 + middleSection->size[0]) + ilow;
  emxEnsureCapacity((emxArray__common *)simXdata, i0, (int)sizeof(double));
  for (i0 = 0; i0 < nm1d2; i0++) {
    simXdata->data[simXdata->size[0] * i0] = firstSection->data[i0];
  }

  loop_ub = middleSection->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    simXdata->data[simXdata->size[0] * (i0 + nm1d2)] = middleSection->data[i0];
  }

  for (i0 = 0; i0 < ilow; i0++) {
    simXdata->data[simXdata->size[0] * ((i0 + nm1d2) + middleSection->size[0])] =
      lastSection->data[i0];
  }

  if ((firstSection->size[0] == 0) || (firstSection->size[1] == 0)) {
    n = 0;
  } else {
    n = firstSection->size[1];
  }

  emxFree_real_T(&firstSection);
  emxFree_real_T(&lastSection);
  emxInit_real_T(&dummydata, 1);
  i0 = this_data->size[0];
  abeles(simXdata, slds, nbairs, nbsubs, repeatLayers[1], ssubs, lays,
         simXdata->size[1], xdata);
  lays = simXdata->size[1] - 10;
  i1 = dummydata->size[0];
  dummydata->size[0] = simXdata->size[1];
  emxEnsureCapacity((emxArray__common *)dummydata, i1, (int)sizeof(double));
  loop_ub = simXdata->size[1];
  emxFree_real_T(&slds);
  for (i1 = 0; i1 < loop_ub; i1++) {
    dummydata->data[i1] = 0.0;
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
      i2 = 10;
    } else {
      i2 = (lays - nm1d2) + 9;
    }

    i1 = (int)((double)i2 + (1.0 - (double)ilow));
    for (loop_ub = 0; loop_ub < i1; loop_ub++) {
      cdiff = (double)ilow + (double)loop_ub;
      kd = simXdata->data[(int)((1.0 + (double)nm1d2) + cdiff) - 1] -
        simXdata->data[nm1d2];
      kd /= (res + 0.0001) * simXdata->data[nm1d2];
      kd = exp(-(kd * kd));
      ndbl += kd;
      dummydata->data[nm1d2] += xdata->data[(int)(cdiff + (1.0 + (double)nm1d2))
        - 1] * kd;
    }

    if (ndbl != 0.0) {
      dummydata->data[nm1d2] /= ndbl;
    }

    /*      catch */
    /*          disp('debug!'); */
    /*      end */
  }

  emxInit_uint32_T(&r0, 2);
  i1 = r0->size[0] * r0->size[1];
  r0->size[0] = 1;
  r0->size[1] = i0;
  emxEnsureCapacity((emxArray__common *)r0, i1, (int)sizeof(unsigned int));
  loop_ub = (int)(i0 + MAX_uint32_T);
  for (i0 = 0; i0 <= loop_ub; i0++) {
    r0->data[r0->size[0] * i0] = ((unsigned int)i0 + n) + 1U;
  }

  i0 = xdata->size[0];
  xdata->size[0] = r0->size[1];
  emxEnsureCapacity((emxArray__common *)xdata, i0, (int)sizeof(double));
  loop_ub = r0->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    xdata->data[i0] = dummydata->data[(int)r0->data[r0->size[0] * i0] - 1] +
      backgrounds;
  }

  emxFree_uint32_T(&r0);
  loop_ub = this_data->size[0];
  nm1d2 = xdata->size[0];
  i0 = reflectivity->size[0] * reflectivity->size[1];
  reflectivity->size[0] = loop_ub;
  reflectivity->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)reflectivity, i0, (int)sizeof(double));
  for (i0 = 0; i0 < loop_ub; i0++) {
    reflectivity->data[i0] = middleSection->data[i0];
  }

  emxFree_real_T(&middleSection);
  for (i0 = 0; i0 < nm1d2; i0++) {
    reflectivity->data[i0 + reflectivity->size[0]] = xdata->data[i0];
  }

  emxFree_real_T(&xdata);
  i0 = Simulation->size[0] * Simulation->size[1];
  Simulation->size[0] = simXdata->size[1];
  Simulation->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)Simulation, i0, (int)sizeof(double));
  loop_ub = simXdata->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Simulation->data[i0] = simXdata->data[simXdata->size[0] * i0];
  }

  emxFree_real_T(&simXdata);
  loop_ub = dummydata->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Simulation->data[i0 + Simulation->size[0]] = dummydata->data[i0] +
      backgrounds;
  }

  emxFree_real_T(&dummydata);
}

/* End of code generation (callReflectivity.c) */
