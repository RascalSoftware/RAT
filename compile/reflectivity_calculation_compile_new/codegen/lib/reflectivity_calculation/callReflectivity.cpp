//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// callReflectivity.cpp
//
// Code generation for function 'callReflectivity'
//

// Include files
#include "callReflectivity.h"
#include "abeles_paraPoints.h"
#include "abeles_single.h"
#include "colon.h"
#include "floor1.h"
#include "isinf.h"
#include "isnan.h"
#include "resolution_polly.h"
#include "resolution_polly_paraPoints.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
void b_callReflectivity(double nbairs, double nbsubs, const double simLimits[2],
                        const double repeatLayers[2],
                        const coder::array<double, 2U> &this_data,
                        const coder::array<double, 2U> &layers, double ssubs,
                        double res, coder::array<double, 2U> &reflectivity,
                        coder::array<double, 2U> &Simulation)
{
  coder::array<double, 2U> firstSection;
  coder::array<double, 2U> lastSection;
  coder::array<double, 2U> slds;
  coder::array<double, 1U> r;
  coder::array<double, 1U> simRef;
  coder::array<double, 1U> simXdata;
  double b;
  double d;
  double step;
  int b_loop_ub;
  int firstSection_idx_0;
  int i;
  int lays;
  int loop_ub;
  unsigned int splits_idx_1;
  //  nbairs = problem.nbairs;
  //  nbsubs = problem.nbsubs;
  //  simLimits = problem.simLimits;
  //  repeatLayers = problem.repeatLayers;
  //  allData = problem.shifted_data;
  //  layers = problem.layers;
  //  ssubs = problem.ssubs;
  //  numberOfContrasts = problem.numberOfContrasts;
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
      for (lays = 0; lays < loop_ub; lays++) {
        slds[lays + slds.size(0) * i] = layers[lays + layers.size(0) * i];
      }
    }
    lays = layers.size(0);
  }
  if (simLimits[0] < this_data[0]) {
    step = this_data[1] - this_data[0];
    b = this_data[0] - step;
    if (coder::b_isnan(simLimits[0]) || coder::b_isnan(step) ||
        coder::b_isnan(b)) {
      firstSection.set_size(1, 1);
      firstSection[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits[0] < b) && (step < 0.0)) ||
               ((b < simLimits[0]) && (step > 0.0))) {
      firstSection.set_size(1, 0);
    } else if ((coder::b_isinf(simLimits[0]) || coder::b_isinf(b)) &&
               (coder::b_isinf(step) || (simLimits[0] == b))) {
      firstSection.set_size(1, 1);
      firstSection[0] = rtNaN;
    } else if (coder::b_isinf(step)) {
      firstSection.set_size(1, 1);
      firstSection[0] = simLimits[0];
    } else {
      d = simLimits[0];
      coder::b_floor(&d);
      if (d == simLimits[0]) {
        d = step;
        coder::b_floor(&d);
        if (d == step) {
          loop_ub = static_cast<int>(std::floor((b - simLimits[0]) / step));
          firstSection.set_size(1, loop_ub + 1);
          for (i = 0; i <= loop_ub; i++) {
            firstSection[i] = simLimits[0] + step * static_cast<double>(i);
          }
        } else {
          coder::eml_float_colon(simLimits[0], step, b, firstSection);
        }
      } else {
        coder::eml_float_colon(simLimits[0], step, b, firstSection);
      }
    }
  } else {
    firstSection.set_size(1, 0);
  }
  if (simLimits[1] > this_data[this_data.size(0) - 1]) {
    step = this_data[this_data.size(0) - 1] - this_data[this_data.size(0) - 2];
    b = this_data[this_data.size(0) - 1] + step;
    if (coder::b_isnan(b) || coder::b_isnan(step) ||
        coder::b_isnan(simLimits[1])) {
      lastSection.set_size(1, 1);
      lastSection[0] = rtNaN;
    } else if ((step == 0.0) || ((b < simLimits[1]) && (step < 0.0)) ||
               ((simLimits[1] < b) && (step > 0.0))) {
      lastSection.set_size(1, 0);
    } else if ((coder::b_isinf(b) || coder::b_isinf(simLimits[1])) &&
               (coder::b_isinf(step) || (b == simLimits[1]))) {
      lastSection.set_size(1, 1);
      lastSection[0] = rtNaN;
    } else if (coder::b_isinf(step)) {
      lastSection.set_size(1, 1);
      lastSection[0] = b;
    } else {
      d = b;
      coder::b_floor(&d);
      if (d == b) {
        d = step;
        coder::b_floor(&d);
        if (d == step) {
          loop_ub = static_cast<int>(std::floor((simLimits[1] - b) / step));
          lastSection.set_size(1, loop_ub + 1);
          for (i = 0; i <= loop_ub; i++) {
            lastSection[i] = b + step * static_cast<double>(i);
          }
        } else {
          coder::eml_float_colon(b, step, simLimits[1], lastSection);
        }
      } else {
        coder::eml_float_colon(b, step, simLimits[1], lastSection);
      }
    }
  } else {
    lastSection.set_size(1, 0);
  }
  firstSection_idx_0 = firstSection.size(1);
  loop_ub = this_data.size(0);
  simXdata.set_size((this_data.size(0) + firstSection.size(1)) +
                    lastSection.size(1));
  b_loop_ub = firstSection.size(1);
  for (i = 0; i < b_loop_ub; i++) {
    simXdata[i] = firstSection[i];
  }
  for (i = 0; i < loop_ub; i++) {
    simXdata[i + firstSection_idx_0] = this_data[i];
  }
  b_loop_ub = lastSection.size(1);
  for (i = 0; i < b_loop_ub; i++) {
    simXdata[(i + firstSection_idx_0) + loop_ub] = lastSection[i];
  }
  splits_idx_1 =
      static_cast<unsigned int>(firstSection.size(1)) + this_data.size(0);
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
                    static_cast<double>(lays),
                    static_cast<double>(simXdata.size(0)), simRef);
  // (x,sld,nbair,nbsub,nrepeats,ssub,layers,points)
  resolution_polly_paraPoints(simXdata, simRef, res,
                              static_cast<double>(simXdata.size(0)), r);
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    Simulation[i + Simulation.size(0)] = r[i];
  }
  if (firstSection.size(1) + 1U > splits_idx_1) {
    i = 0;
    lays = 0;
  } else {
    i = firstSection.size(1);
    lays = static_cast<int>(splits_idx_1);
  }
  loop_ub = lays - i;
  reflectivity.set_size(loop_ub, 2);
  for (lays = 0; lays < 2; lays++) {
    for (firstSection_idx_0 = 0; firstSection_idx_0 < loop_ub;
         firstSection_idx_0++) {
      reflectivity[firstSection_idx_0 + reflectivity.size(0) * lays] =
          Simulation[(i + firstSection_idx_0) + Simulation.size(0) * lays];
    }
  }
}

void callReflectivity(double nbairs, double nbsubs, const double simLimits[2],
                      const double repeatLayers[2],
                      const coder::array<double, 2U> &this_data,
                      const coder::array<double, 2U> &layers, double ssubs,
                      double res, coder::array<double, 2U> &reflectivity,
                      coder::array<double, 2U> &Simulation)
{
  coder::array<double, 2U> firstSection;
  coder::array<double, 2U> lastSection;
  coder::array<double, 2U> slds;
  coder::array<double, 1U> r;
  coder::array<double, 1U> simRef;
  coder::array<double, 1U> simXdata;
  double b;
  double d;
  double step;
  int b_loop_ub;
  int firstSection_idx_0;
  int i;
  int lays;
  int loop_ub;
  unsigned int splits_idx_1;
  //  nbairs = problem.nbairs;
  //  nbsubs = problem.nbsubs;
  //  simLimits = problem.simLimits;
  //  repeatLayers = problem.repeatLayers;
  //  allData = problem.shifted_data;
  //  layers = problem.layers;
  //  ssubs = problem.ssubs;
  //  numberOfContrasts = problem.numberOfContrasts;
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
      for (lays = 0; lays < loop_ub; lays++) {
        slds[lays + slds.size(0) * i] = layers[lays + layers.size(0) * i];
      }
    }
    lays = layers.size(0);
  }
  if (simLimits[0] < this_data[0]) {
    step = this_data[1] - this_data[0];
    b = this_data[0] - step;
    if (coder::b_isnan(simLimits[0]) || coder::b_isnan(step) ||
        coder::b_isnan(b)) {
      firstSection.set_size(1, 1);
      firstSection[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits[0] < b) && (step < 0.0)) ||
               ((b < simLimits[0]) && (step > 0.0))) {
      firstSection.set_size(1, 0);
    } else if ((coder::b_isinf(simLimits[0]) || coder::b_isinf(b)) &&
               (coder::b_isinf(step) || (simLimits[0] == b))) {
      firstSection.set_size(1, 1);
      firstSection[0] = rtNaN;
    } else if (coder::b_isinf(step)) {
      firstSection.set_size(1, 1);
      firstSection[0] = simLimits[0];
    } else {
      d = simLimits[0];
      coder::b_floor(&d);
      if (d == simLimits[0]) {
        d = step;
        coder::b_floor(&d);
        if (d == step) {
          loop_ub = static_cast<int>(std::floor((b - simLimits[0]) / step));
          firstSection.set_size(1, loop_ub + 1);
          for (i = 0; i <= loop_ub; i++) {
            firstSection[i] = simLimits[0] + step * static_cast<double>(i);
          }
        } else {
          coder::eml_float_colon(simLimits[0], step, b, firstSection);
        }
      } else {
        coder::eml_float_colon(simLimits[0], step, b, firstSection);
      }
    }
  } else {
    firstSection.set_size(1, 0);
  }
  if (simLimits[1] > this_data[this_data.size(0) - 1]) {
    step = this_data[this_data.size(0) - 1] - this_data[this_data.size(0) - 2];
    b = this_data[this_data.size(0) - 1] + step;
    if (coder::b_isnan(b) || coder::b_isnan(step) ||
        coder::b_isnan(simLimits[1])) {
      lastSection.set_size(1, 1);
      lastSection[0] = rtNaN;
    } else if ((step == 0.0) || ((b < simLimits[1]) && (step < 0.0)) ||
               ((simLimits[1] < b) && (step > 0.0))) {
      lastSection.set_size(1, 0);
    } else if ((coder::b_isinf(b) || coder::b_isinf(simLimits[1])) &&
               (coder::b_isinf(step) || (b == simLimits[1]))) {
      lastSection.set_size(1, 1);
      lastSection[0] = rtNaN;
    } else if (coder::b_isinf(step)) {
      lastSection.set_size(1, 1);
      lastSection[0] = b;
    } else {
      d = b;
      coder::b_floor(&d);
      if (d == b) {
        d = step;
        coder::b_floor(&d);
        if (d == step) {
          loop_ub = static_cast<int>(std::floor((simLimits[1] - b) / step));
          lastSection.set_size(1, loop_ub + 1);
          for (i = 0; i <= loop_ub; i++) {
            lastSection[i] = b + step * static_cast<double>(i);
          }
        } else {
          coder::eml_float_colon(b, step, simLimits[1], lastSection);
        }
      } else {
        coder::eml_float_colon(b, step, simLimits[1], lastSection);
      }
    }
  } else {
    lastSection.set_size(1, 0);
  }
  firstSection_idx_0 = firstSection.size(1);
  loop_ub = this_data.size(0);
  simXdata.set_size((this_data.size(0) + firstSection.size(1)) +
                    lastSection.size(1));
  b_loop_ub = firstSection.size(1);
  for (i = 0; i < b_loop_ub; i++) {
    simXdata[i] = firstSection[i];
  }
  for (i = 0; i < loop_ub; i++) {
    simXdata[i + firstSection_idx_0] = this_data[i];
  }
  b_loop_ub = lastSection.size(1);
  for (i = 0; i < b_loop_ub; i++) {
    simXdata[(i + firstSection_idx_0) + loop_ub] = lastSection[i];
  }
  splits_idx_1 =
      static_cast<unsigned int>(firstSection.size(1)) + this_data.size(0);
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
                static_cast<double>(lays),
                static_cast<double>(simXdata.size(0)), simRef);
  resolution_polly(simXdata, simRef, res, static_cast<double>(simXdata.size(0)),
                   r);
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    Simulation[i + Simulation.size(0)] = r[i];
  }
  if (firstSection.size(1) + 1U > splits_idx_1) {
    i = 0;
    lays = 0;
  } else {
    i = firstSection.size(1);
    lays = static_cast<int>(splits_idx_1);
  }
  loop_ub = lays - i;
  reflectivity.set_size(loop_ub, 2);
  for (lays = 0; lays < 2; lays++) {
    for (firstSection_idx_0 = 0; firstSection_idx_0 < loop_ub;
         firstSection_idx_0++) {
      reflectivity[firstSection_idx_0 + reflectivity.size(0) * lays] =
          Simulation[(i + firstSection_idx_0) + Simulation.size(0) * lays];
    }
  }
}

// End of code generation (callReflectivity.cpp)
