//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: callReflectivity.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 24-Feb-2021 09:15:13
//

// Include Files
#include "callReflectivity.h"
#include "abeles_paraPoints.h"
#include "abeles_single.h"
#include "reflectivity_calculation.h"
#include "resolution_polly_paraPoints.h"
#include "rt_nonfinite.h"
#include "standardTF_stanLay_reflectivityCalculation.h"
#include <math.h>

// Function Definitions

//
// nbairs = problem.nbairs;
//  nbsubs = problem.nbsubs;
//  simLimits = problem.simLimits;
//  repeatLayers = problem.repeatLayers;
//  allData = problem.shifted_data;
//  layers = problem.layers;
//  ssubs = problem.ssubs;
//  numberOfContrasts = problem.numberOfContrasts;
// Arguments    : double nbairs
//                double nbsubs
//                const double simLimits[2]
//                const double repeatLayers[2]
//                const coder::array<double, 2U> *this_data
//                const coder::array<double, 2U> *layers
//                double ssubs
//                double res
//                coder::array<double, 2U> *reflectivity
//                coder::array<double, 2U> *Simulation
// Return Type  : void
//
void b_callReflectivity(double nbairs, double nbsubs, const double simLimits[2],
  const double repeatLayers[2], const coder::array<double, 2U> &this_data, const
  coder::array<double, 2U> &layers, double ssubs, double res, coder::array<
  double, 2U> &reflectivity, coder::array<double, 2U> &Simulation)
{
  int loop_ub;
  coder::array<double, 2U> slds;
  int i;
  int lays;
  int n;
  coder::array<double, 2U> firstSection;
  double step;
  double kd;
  coder::array<double, 2U> lastSection;
  coder::array<double, 1U> simXdata;
  double ndbl;
  int nm1d2;
  double apnd;
  double cdiff;
  double u0;
  double u1;
  unsigned int splits_idx_1;
  coder::array<double, 1U> simRef;
  coder::array<double, 1U> r;

  //  reflectivity = cell(numberOfContrasts,1);
  //  Simulation = cell(numberOfContrasts,1);
  //
  //  parfor i = 1:numberOfContrasts
  // this_data = allData{i};
  if (layers.size(0) == 0) {
    slds.set_size(1, 3);
    slds[0] = 0.0;
    slds[1] = nbairs;
    slds[2] = 0.0;
    lays = 0;
  } else {
    loop_ub = layers.size(0);
    slds.set_size(layers.size(0), 3);
    for (i = 0; i < 3; i++) {
      for (n = 0; n < loop_ub; n++) {
        slds[n + slds.size(0) * i] = layers[n + layers.size(0) * i];
      }
    }

    lays = layers.size(0);
  }

  if (simLimits[0] < this_data[0]) {
    step = this_data[1] - this_data[0];
    kd = this_data[0] - step;
    if (rtIsNaN(step) || rtIsNaN(kd)) {
      firstSection.set_size(1, 1);
      firstSection[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits[0] < kd) && (step < 0.0)) || ((kd <
                 simLimits[0]) && (step > 0.0))) {
      firstSection.set_size(1, 0);
    } else if ((rtIsInf(simLimits[0]) || rtIsInf(kd)) && (rtIsInf(step) ||
                (simLimits[0] == kd))) {
      firstSection.set_size(1, 1);
      firstSection[0] = rtNaN;
    } else if (rtIsInf(step)) {
      firstSection.set_size(1, 1);
      firstSection[0] = simLimits[0];
    } else if ((floor(simLimits[0]) == simLimits[0]) && (floor(step) == step)) {
      loop_ub = static_cast<int>(floor((kd - simLimits[0]) / step));
      firstSection.set_size(1, (loop_ub + 1));
      for (i = 0; i <= loop_ub; i++) {
        firstSection[i] = simLimits[0] + step * static_cast<double>(i);
      }
    } else {
      ndbl = floor((kd - simLimits[0]) / step + 0.5);
      apnd = simLimits[0] + ndbl * step;
      if (step > 0.0) {
        cdiff = apnd - kd;
      } else {
        cdiff = kd - apnd;
      }

      u0 = fabs(simLimits[0]);
      u1 = fabs(kd);
      if ((u0 > u1) || rtIsNaN(u1)) {
        u1 = u0;
      }

      if (fabs(cdiff) < 4.4408920985006262E-16 * u1) {
        ndbl++;
        apnd = kd;
      } else if (cdiff > 0.0) {
        apnd = simLimits[0] + (ndbl - 1.0) * step;
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        n = static_cast<int>(ndbl);
      } else {
        n = 0;
      }

      firstSection.set_size(1, n);
      if (n > 0) {
        firstSection[0] = simLimits[0];
        if (n > 1) {
          firstSection[n - 1] = apnd;
          nm1d2 = (n - 1) / 2;
          for (loop_ub = 0; loop_ub <= nm1d2 - 2; loop_ub++) {
            kd = (static_cast<double>(loop_ub) + 1.0) * step;
            firstSection[loop_ub + 1] = simLimits[0] + kd;
            firstSection[(n - loop_ub) - 2] = apnd - kd;
          }

          if (nm1d2 << 1 == n - 1) {
            firstSection[nm1d2] = (simLimits[0] + apnd) / 2.0;
          } else {
            kd = static_cast<double>(nm1d2) * step;
            firstSection[nm1d2] = simLimits[0] + kd;
            firstSection[nm1d2 + 1] = apnd - kd;
          }
        }
      }
    }
  } else {
    firstSection.set_size(1, 0);
  }

  if (simLimits[1] > this_data[this_data.size(0) - 1]) {
    double a;
    step = this_data[this_data.size(0) - 1] - this_data[this_data.size(0) - 2];
    a = this_data[this_data.size(0) - 1] + step;
    if (rtIsNaN(a) || rtIsNaN(step)) {
      lastSection.set_size(1, 1);
      lastSection[0] = rtNaN;
    } else if ((step == 0.0) || ((a < simLimits[1]) && (step < 0.0)) ||
               ((simLimits[1] < a) && (step > 0.0))) {
      lastSection.set_size(1, 0);
    } else if ((rtIsInf(a) || rtIsInf(simLimits[1])) && (rtIsInf(step) || (a ==
                 simLimits[1]))) {
      lastSection.set_size(1, 1);
      lastSection[0] = rtNaN;
    } else if (rtIsInf(step)) {
      lastSection.set_size(1, 1);
      lastSection[0] = a;
    } else if ((floor(a) == a) && (floor(step) == step)) {
      loop_ub = static_cast<int>(floor((simLimits[1] - a) / step));
      lastSection.set_size(1, (loop_ub + 1));
      for (i = 0; i <= loop_ub; i++) {
        lastSection[i] = a + step * static_cast<double>(i);
      }
    } else {
      ndbl = floor((simLimits[1] - a) / step + 0.5);
      apnd = a + ndbl * step;
      if (step > 0.0) {
        cdiff = apnd - simLimits[1];
      } else {
        cdiff = simLimits[1] - apnd;
      }

      u0 = fabs(a);
      u1 = fabs(simLimits[1]);
      if (u0 > u1) {
        u1 = u0;
      }

      if (fabs(cdiff) < 4.4408920985006262E-16 * u1) {
        ndbl++;
        apnd = simLimits[1];
      } else if (cdiff > 0.0) {
        apnd = a + (ndbl - 1.0) * step;
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        n = static_cast<int>(ndbl);
      } else {
        n = 0;
      }

      lastSection.set_size(1, n);
      if (n > 0) {
        lastSection[0] = a;
        if (n > 1) {
          lastSection[n - 1] = apnd;
          nm1d2 = (n - 1) / 2;
          for (loop_ub = 0; loop_ub <= nm1d2 - 2; loop_ub++) {
            kd = (static_cast<double>(loop_ub) + 1.0) * step;
            lastSection[loop_ub + 1] = a + kd;
            lastSection[(n - loop_ub) - 2] = apnd - kd;
          }

          if (nm1d2 << 1 == n - 1) {
            lastSection[nm1d2] = (a + apnd) / 2.0;
          } else {
            kd = static_cast<double>(nm1d2) * step;
            lastSection[nm1d2] = a + kd;
            lastSection[nm1d2 + 1] = apnd - kd;
          }
        }
      }
    }
  } else {
    lastSection.set_size(1, 0);
  }

  n = firstSection.size(1);
  loop_ub = this_data.size(0);
  simXdata.set_size(((firstSection.size(1) + this_data.size(0)) +
                     lastSection.size(1)));
  nm1d2 = firstSection.size(1);
  for (i = 0; i < nm1d2; i++) {
    simXdata[i] = firstSection[i];
  }

  for (i = 0; i < loop_ub; i++) {
    simXdata[i + n] = this_data[i];
  }

  nm1d2 = lastSection.size(1);
  for (i = 0; i < nm1d2; i++) {
    simXdata[(i + n) + loop_ub] = lastSection[i];
  }

  splits_idx_1 = static_cast<unsigned int>(firstSection.size(1)) +
    this_data.size(0);
  Simulation.set_size(simXdata.size(0), 2);
  loop_ub = simXdata.size(0) << 1;
  for (i = 0; i < loop_ub; i++) {
    Simulation[i] = 0.0;
  }

  loop_ub = simXdata.size(0);
  for (i = 0; i < loop_ub; i++) {
    Simulation[i] = simXdata[i];
  }

  //  Parallelise over points
  abeles_paraPoints(simXdata, slds, nbairs, nbsubs, repeatLayers[1], ssubs,
                    static_cast<double>(lays), static_cast<double>(simXdata.size
    (0)), simRef);

  // (x,sld,nbair,nbsub,nrepeats,ssub,layers,points)
  resolution_polly_paraPoints(simXdata, simRef, res, static_cast<double>
    (simXdata.size(0)), r);
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    Simulation[i + Simulation.size(0)] = r[i];
  }

  if (firstSection.size(1) + 1U > splits_idx_1) {
    i = 0;
    n = 0;
  } else {
    i = firstSection.size(1);
    n = static_cast<int>(splits_idx_1);
  }

  loop_ub = n - i;
  reflectivity.set_size(loop_ub, 2);
  for (n = 0; n < loop_ub; n++) {
    reflectivity[n] = Simulation[i + n];
  }

  for (n = 0; n < loop_ub; n++) {
    reflectivity[n + reflectivity.size(0)] = Simulation[(i + n) +
      Simulation.size(0)];
  }
}

//
// nbairs = problem.nbairs;
//  nbsubs = problem.nbsubs;
//  simLimits = problem.simLimits;
//  repeatLayers = problem.repeatLayers;
//  allData = problem.shifted_data;
//  layers = problem.layers;
//  ssubs = problem.ssubs;
//  numberOfContrasts = problem.numberOfContrasts;
// Arguments    : double nbairs
//                double nbsubs
//                const double simLimits[2]
//                const double repeatLayers[2]
//                const coder::array<double, 2U> *this_data
//                const coder::array<double, 2U> *layers
//                double ssubs
//                double res
//                coder::array<double, 2U> *reflectivity
//                coder::array<double, 2U> *Simulation
// Return Type  : void
//
void callReflectivity(double nbairs, double nbsubs, const double simLimits[2],
                      const double repeatLayers[2], const coder::array<double,
                      2U> &this_data, const coder::array<double, 2U> &layers,
                      double ssubs, double res, coder::array<double, 2U>
                      &reflectivity, coder::array<double, 2U> &Simulation)
{
  int loop_ub;
  coder::array<double, 2U> slds;
  int i;
  int lays;
  int i1;
  coder::array<double, 2U> firstSection;
  double step;
  double sumg;
  coder::array<double, 2U> lastSection;
  double a;
  int ilow;
  coder::array<double, 1U> simXdata;
  double ndbl;
  int nm1d2;
  double apnd;
  double cdiff;
  double u0;
  double u1;
  unsigned int splits_idx_1;
  coder::array<double, 1U> simRef;
  coder::array<double, 1U> dummydata;

  //  reflectivity = cell(numberOfContrasts,1);
  //  Simulation = cell(numberOfContrasts,1);
  //
  //  parfor i = 1:numberOfContrasts
  // this_data = allData{i};
  if (layers.size(0) == 0) {
    slds.set_size(1, 3);
    slds[0] = 0.0;
    slds[1] = nbairs;
    slds[2] = 0.0;
    lays = 0;
  } else {
    loop_ub = layers.size(0);
    slds.set_size(layers.size(0), 3);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        slds[i1 + slds.size(0) * i] = layers[i1 + layers.size(0) * i];
      }
    }

    lays = layers.size(0);
  }

  if (simLimits[0] < this_data[0]) {
    step = this_data[1] - this_data[0];
    sumg = this_data[0] - step;
    if (rtIsNaN(step) || rtIsNaN(sumg)) {
      firstSection.set_size(1, 1);
      firstSection[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits[0] < sumg) && (step < 0.0)) ||
               ((sumg < simLimits[0]) && (step > 0.0))) {
      firstSection.set_size(1, 0);
    } else if ((rtIsInf(simLimits[0]) || rtIsInf(sumg)) && (rtIsInf(step) ||
                (simLimits[0] == sumg))) {
      firstSection.set_size(1, 1);
      firstSection[0] = rtNaN;
    } else if (rtIsInf(step)) {
      firstSection.set_size(1, 1);
      firstSection[0] = simLimits[0];
    } else if ((floor(simLimits[0]) == simLimits[0]) && (floor(step) == step)) {
      loop_ub = static_cast<int>(floor((sumg - simLimits[0]) / step));
      firstSection.set_size(1, (loop_ub + 1));
      for (i = 0; i <= loop_ub; i++) {
        firstSection[i] = simLimits[0] + step * static_cast<double>(i);
      }
    } else {
      ndbl = floor((sumg - simLimits[0]) / step + 0.5);
      apnd = simLimits[0] + ndbl * step;
      if (step > 0.0) {
        cdiff = apnd - sumg;
      } else {
        cdiff = sumg - apnd;
      }

      u0 = fabs(simLimits[0]);
      u1 = fabs(sumg);
      if ((u0 > u1) || rtIsNaN(u1)) {
        u1 = u0;
      }

      if (fabs(cdiff) < 4.4408920985006262E-16 * u1) {
        ndbl++;
        apnd = sumg;
      } else if (cdiff > 0.0) {
        apnd = simLimits[0] + (ndbl - 1.0) * step;
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        ilow = static_cast<int>(ndbl);
      } else {
        ilow = 0;
      }

      firstSection.set_size(1, ilow);
      if (ilow > 0) {
        firstSection[0] = simLimits[0];
        if (ilow > 1) {
          firstSection[ilow - 1] = apnd;
          nm1d2 = (ilow - 1) / 2;
          for (loop_ub = 0; loop_ub <= nm1d2 - 2; loop_ub++) {
            ndbl = (static_cast<double>(loop_ub) + 1.0) * step;
            firstSection[loop_ub + 1] = simLimits[0] + ndbl;
            firstSection[(ilow - loop_ub) - 2] = apnd - ndbl;
          }

          if (nm1d2 << 1 == ilow - 1) {
            firstSection[nm1d2] = (simLimits[0] + apnd) / 2.0;
          } else {
            ndbl = static_cast<double>(nm1d2) * step;
            firstSection[nm1d2] = simLimits[0] + ndbl;
            firstSection[nm1d2 + 1] = apnd - ndbl;
          }
        }
      }
    }
  } else {
    firstSection.set_size(1, 0);
  }

  if (simLimits[1] > this_data[this_data.size(0) - 1]) {
    step = this_data[this_data.size(0) - 1] - this_data[this_data.size(0) - 2];
    a = this_data[this_data.size(0) - 1] + step;
    if (rtIsNaN(a) || rtIsNaN(step)) {
      lastSection.set_size(1, 1);
      lastSection[0] = rtNaN;
    } else if ((step == 0.0) || ((a < simLimits[1]) && (step < 0.0)) ||
               ((simLimits[1] < a) && (step > 0.0))) {
      lastSection.set_size(1, 0);
    } else if ((rtIsInf(a) || rtIsInf(simLimits[1])) && (rtIsInf(step) || (a ==
                 simLimits[1]))) {
      lastSection.set_size(1, 1);
      lastSection[0] = rtNaN;
    } else if (rtIsInf(step)) {
      lastSection.set_size(1, 1);
      lastSection[0] = a;
    } else if ((floor(a) == a) && (floor(step) == step)) {
      loop_ub = static_cast<int>(floor((simLimits[1] - a) / step));
      lastSection.set_size(1, (loop_ub + 1));
      for (i = 0; i <= loop_ub; i++) {
        lastSection[i] = a + step * static_cast<double>(i);
      }
    } else {
      ndbl = floor((simLimits[1] - a) / step + 0.5);
      apnd = a + ndbl * step;
      if (step > 0.0) {
        cdiff = apnd - simLimits[1];
      } else {
        cdiff = simLimits[1] - apnd;
      }

      u0 = fabs(a);
      u1 = fabs(simLimits[1]);
      if (u0 > u1) {
        u1 = u0;
      }

      if (fabs(cdiff) < 4.4408920985006262E-16 * u1) {
        ndbl++;
        apnd = simLimits[1];
      } else if (cdiff > 0.0) {
        apnd = a + (ndbl - 1.0) * step;
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        ilow = static_cast<int>(ndbl);
      } else {
        ilow = 0;
      }

      lastSection.set_size(1, ilow);
      if (ilow > 0) {
        lastSection[0] = a;
        if (ilow > 1) {
          lastSection[ilow - 1] = apnd;
          nm1d2 = (ilow - 1) / 2;
          for (loop_ub = 0; loop_ub <= nm1d2 - 2; loop_ub++) {
            ndbl = (static_cast<double>(loop_ub) + 1.0) * step;
            lastSection[loop_ub + 1] = a + ndbl;
            lastSection[(ilow - loop_ub) - 2] = apnd - ndbl;
          }

          if (nm1d2 << 1 == ilow - 1) {
            lastSection[nm1d2] = (a + apnd) / 2.0;
          } else {
            ndbl = static_cast<double>(nm1d2) * step;
            lastSection[nm1d2] = a + ndbl;
            lastSection[nm1d2 + 1] = apnd - ndbl;
          }
        }
      }
    }
  } else {
    lastSection.set_size(1, 0);
  }

  ilow = firstSection.size(1);
  loop_ub = this_data.size(0);
  simXdata.set_size(((firstSection.size(1) + this_data.size(0)) +
                     lastSection.size(1)));
  nm1d2 = firstSection.size(1);
  for (i = 0; i < nm1d2; i++) {
    simXdata[i] = firstSection[i];
  }

  for (i = 0; i < loop_ub; i++) {
    simXdata[i + ilow] = this_data[i];
  }

  nm1d2 = lastSection.size(1);
  for (i = 0; i < nm1d2; i++) {
    simXdata[(i + ilow) + loop_ub] = lastSection[i];
  }

  splits_idx_1 = static_cast<unsigned int>(firstSection.size(1)) +
    this_data.size(0);
  Simulation.set_size(simXdata.size(0), 2);
  loop_ub = simXdata.size(0) << 1;
  for (i = 0; i < loop_ub; i++) {
    Simulation[i] = 0.0;
  }

  loop_ub = simXdata.size(0);
  for (i = 0; i < loop_ub; i++) {
    Simulation[i] = simXdata[i];
  }

  //  Single cored over points
  abeles_single(simXdata, slds, nbairs, nbsubs, repeatLayers[1], ssubs,
                static_cast<double>(lays), static_cast<double>(simXdata.size(0)),
                simRef);
  lays = simXdata.size(0) - 10;
  dummydata.set_size(simXdata.size(0));
  loop_ub = simXdata.size(0);
  for (i = 0; i < loop_ub; i++) {
    dummydata[i] = 0.0;
  }

  i = simXdata.size(0);
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    sumg = 0.0;
    dummydata[loop_ub] = 0.0;
    if (loop_ub + 1 > 10) {
      ilow = -10;
    } else {
      ilow = -loop_ub;
    }

    //     try
    if (loop_ub + 1 < lays) {
      nm1d2 = 1;
    } else {
      nm1d2 = lays - loop_ub;
    }

    i1 = (nm1d2 - ilow) + 9;
    for (int b_i = 0; b_i <= i1; b_i++) {
      nm1d2 = static_cast<int>((static_cast<double>(loop_ub) + 1.0) +
        static_cast<double>(ilow + b_i)) - 1;
      a = (simXdata[nm1d2] - simXdata[loop_ub]) / ((res + 0.0001) *
        simXdata[loop_ub]);
      ndbl = exp(-(a * a));
      sumg += ndbl;
      dummydata[loop_ub] = dummydata[loop_ub] + simRef[nm1d2] * ndbl;
    }

    if (sumg != 0.0) {
      dummydata[loop_ub] = dummydata[loop_ub] / sumg;
    }
  }

  loop_ub = dummydata.size(0);
  for (i = 0; i < loop_ub; i++) {
    Simulation[i + Simulation.size(0)] = dummydata[i];
  }

  if (firstSection.size(1) + 1U > splits_idx_1) {
    i = 0;
    i1 = 0;
  } else {
    i = firstSection.size(1);
    i1 = static_cast<int>(splits_idx_1);
  }

  loop_ub = i1 - i;
  reflectivity.set_size(loop_ub, 2);
  for (i1 = 0; i1 < loop_ub; i1++) {
    reflectivity[i1] = Simulation[i + i1];
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    reflectivity[i1 + reflectivity.size(0)] = Simulation[(i + i1) +
      Simulation.size(0)];
  }
}

//
// File trailer for callReflectivity.cpp
//
// [EOF]
//
