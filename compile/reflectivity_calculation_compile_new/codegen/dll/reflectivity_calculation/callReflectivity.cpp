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
#include "colon.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_rtwutil.h"
#include "resolution_polly_paraPoints.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
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
    slds[slds.size(0)] = nbairs;
    slds[slds.size(0) * 2] = 0.0;
    lays = 0;
  } else {
    loop_ub = layers.size(0);
    slds.set_size(layers.size(0), 3);
    for (i = 0; i < 3; i++) {
      for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
        slds[b_loop_ub + slds.size(0) * i] =
            layers[b_loop_ub + layers.size(0) * i];
      }
    }
    lays = layers.size(0);
  }
  if (simLimits[0] < this_data[0]) {
    step = this_data[1] - this_data[0];
    b = this_data[0] - step;
    if (std::isnan(step) || std::isnan(b)) {
      firstSection.set_size(1, 1);
      firstSection[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits[0] < b) && (step < 0.0)) ||
               ((b < simLimits[0]) && (step > 0.0))) {
      firstSection.set_size(1, 0);
    } else if ((std::isinf(simLimits[0]) || std::isinf(b)) &&
               (std::isinf(step) || (simLimits[0] == b))) {
      firstSection.set_size(1, 1);
      firstSection[0] = rtNaN;
    } else if (std::isinf(step)) {
      firstSection.set_size(1, 1);
      firstSection[0] = simLimits[0];
    } else if ((std::floor(simLimits[0]) == simLimits[0]) &&
               (std::floor(step) == step)) {
      loop_ub = static_cast<int>(std::floor((b - simLimits[0]) / step));
      firstSection.set_size(1, loop_ub + 1);
      for (i = 0; i <= loop_ub; i++) {
        firstSection[i] = simLimits[0] + step * static_cast<double>(i);
      }
    } else {
      coder::eml_float_colon(simLimits[0], step, b, firstSection);
    }
  } else {
    firstSection.set_size(1, 0);
  }
  if (simLimits[1] > this_data[this_data.size(0) - 1]) {
    step = this_data[this_data.size(0) - 1] - this_data[this_data.size(0) - 2];
    b = this_data[this_data.size(0) - 1] + step;
    if (std::isnan(b) || std::isnan(step)) {
      lastSection.set_size(1, 1);
      lastSection[0] = rtNaN;
    } else if ((step == 0.0) || ((b < simLimits[1]) && (step < 0.0)) ||
               ((simLimits[1] < b) && (step > 0.0))) {
      lastSection.set_size(1, 0);
    } else if ((std::isinf(b) || std::isinf(simLimits[1])) &&
               (std::isinf(step) || (b == simLimits[1]))) {
      lastSection.set_size(1, 1);
      lastSection[0] = rtNaN;
    } else if (std::isinf(step)) {
      lastSection.set_size(1, 1);
      lastSection[0] = b;
    } else if ((std::floor(b) == b) && (std::floor(step) == step)) {
      loop_ub = static_cast<int>(std::floor((simLimits[1] - b) / step));
      lastSection.set_size(1, loop_ub + 1);
      for (i = 0; i <= loop_ub; i++) {
        lastSection[i] = b + step * static_cast<double>(i);
      }
    } else {
      coder::eml_float_colon(b, step, simLimits[1], lastSection);
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
  loop_ub = simXdata.size(0);
  for (i = 0; i < 2; i++) {
    for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
      Simulation[b_loop_ub + Simulation.size(0) * i] = 0.0;
    }
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
    b_loop_ub = 0;
  } else {
    i = firstSection.size(1);
    b_loop_ub = static_cast<int>(splits_idx_1);
  }
  loop_ub = b_loop_ub - i;
  reflectivity.set_size(loop_ub, 2);
  for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
    for (firstSection_idx_0 = 0; firstSection_idx_0 < loop_ub;
         firstSection_idx_0++) {
      reflectivity[firstSection_idx_0 + reflectivity.size(0) * b_loop_ub] =
          Simulation[(i + firstSection_idx_0) + Simulation.size(0) * b_loop_ub];
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
  coder::array<double, 1U> dummydata;
  coder::array<double, 1U> simRef;
  coder::array<double, 1U> simXdata;
  creal_T MI[2][2];
  creal_T b_MI[2][2];
  creal_T pimag;
  creal_T psub;
  double ar_tmp;
  double snair;
  double snlay;
  double snsub;
  double step;
  int b_i;
  int b_layers;
  int b_loop_ub;
  int i;
  int i1;
  int ilow;
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
    slds[slds.size(0)] = nbairs;
    slds[slds.size(0) * 2] = 0.0;
    b_layers = -1;
  } else {
    loop_ub = layers.size(0);
    slds.set_size(layers.size(0), 3);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        slds[i1 + slds.size(0) * i] = layers[i1 + layers.size(0) * i];
      }
    }
    b_layers = layers.size(0) - 1;
  }
  if (simLimits[0] < this_data[0]) {
    step = this_data[1] - this_data[0];
    snlay = this_data[0] - step;
    if (std::isnan(step) || std::isnan(snlay)) {
      firstSection.set_size(1, 1);
      firstSection[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits[0] < snlay) && (step < 0.0)) ||
               ((snlay < simLimits[0]) && (step > 0.0))) {
      firstSection.set_size(1, 0);
    } else if ((std::isinf(simLimits[0]) || std::isinf(snlay)) &&
               (std::isinf(step) || (simLimits[0] == snlay))) {
      firstSection.set_size(1, 1);
      firstSection[0] = rtNaN;
    } else if (std::isinf(step)) {
      firstSection.set_size(1, 1);
      firstSection[0] = simLimits[0];
    } else if ((std::floor(simLimits[0]) == simLimits[0]) &&
               (std::floor(step) == step)) {
      loop_ub = static_cast<int>(std::floor((snlay - simLimits[0]) / step));
      firstSection.set_size(1, loop_ub + 1);
      for (i = 0; i <= loop_ub; i++) {
        firstSection[i] = simLimits[0] + step * static_cast<double>(i);
      }
    } else {
      coder::eml_float_colon(simLimits[0], step, snlay, firstSection);
    }
  } else {
    firstSection.set_size(1, 0);
  }
  if (simLimits[1] > this_data[this_data.size(0) - 1]) {
    step = this_data[this_data.size(0) - 1] - this_data[this_data.size(0) - 2];
    snlay = this_data[this_data.size(0) - 1] + step;
    if (std::isnan(snlay) || std::isnan(step)) {
      lastSection.set_size(1, 1);
      lastSection[0] = rtNaN;
    } else if ((step == 0.0) || ((snlay < simLimits[1]) && (step < 0.0)) ||
               ((simLimits[1] < snlay) && (step > 0.0))) {
      lastSection.set_size(1, 0);
    } else if ((std::isinf(snlay) || std::isinf(simLimits[1])) &&
               (std::isinf(step) || (snlay == simLimits[1]))) {
      lastSection.set_size(1, 1);
      lastSection[0] = rtNaN;
    } else if (std::isinf(step)) {
      lastSection.set_size(1, 1);
      lastSection[0] = snlay;
    } else if ((std::floor(snlay) == snlay) && (std::floor(step) == step)) {
      loop_ub = static_cast<int>(std::floor((simLimits[1] - snlay) / step));
      lastSection.set_size(1, loop_ub + 1);
      for (i = 0; i <= loop_ub; i++) {
        lastSection[i] = snlay + step * static_cast<double>(i);
      }
    } else {
      coder::eml_float_colon(snlay, step, simLimits[1], lastSection);
    }
  } else {
    lastSection.set_size(1, 0);
  }
  ilow = firstSection.size(1);
  loop_ub = this_data.size(0);
  simXdata.set_size((this_data.size(0) + firstSection.size(1)) +
                    lastSection.size(1));
  b_loop_ub = firstSection.size(1);
  for (i = 0; i < b_loop_ub; i++) {
    simXdata[i] = firstSection[i];
  }
  for (i = 0; i < loop_ub; i++) {
    simXdata[i + ilow] = this_data[i];
  }
  b_loop_ub = lastSection.size(1);
  for (i = 0; i < b_loop_ub; i++) {
    simXdata[(i + ilow) + loop_ub] = lastSection[i];
  }
  splits_idx_1 =
      static_cast<unsigned int>(firstSection.size(1)) + this_data.size(0);
  Simulation.set_size(simXdata.size(0), 2);
  loop_ub = simXdata.size(0);
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      Simulation[i1 + Simulation.size(0) * i] = 0.0;
    }
  }
  loop_ub = simXdata.size(0);
  for (i = 0; i < loop_ub; i++) {
    Simulation[i] = simXdata[i];
  }
  //  Single cored over points
  //  nbair = nbairs(thisCont);
  //  nbsub = nbsubs(thisCont);
  //  ssub = ssubs(thisCont);
  //  nrepeats = nrepeatss(thisCont);
  //  resol = resols(thisCont);
  simRef.set_size(simXdata.size(0));
  // pi = 3.141592653589;
  snair = 1.0 - nbairs * 0.377451863036739;
  snsub = 1.0 - nbsubs * 0.377451863036739;
  i = simXdata.size(0);
  if (0 <= i - 1) {
    b_i = static_cast<int>(repeatLayers[1]);
    ar_tmp = ssubs * ssubs;
  }
  for (b_loop_ub = 0; b_loop_ub < i; b_loop_ub++) {
    double N_tmp_im;
    double N_tmp_re;
    double bim;
    double blast_im;
    double blast_re;
    double brm;
    double d;
    double d1;
    double pair_im;
    double pair_re;
    double psub_tmp_tmp;
    double rij_im;
    double rough;
    double x_im;
    double x_re;
    step = std::asin(simXdata[b_loop_ub] * 1.54 / 12.566370614359172);
    snlay = std::cos(step);
    psub_tmp_tmp = snair * snair * (snlay * snlay);
    snlay = snsub * snsub - psub_tmp_tmp;
    psub.re = snlay;
    psub.im = snlay * 0.0;
    coder::internal::scalar::b_sqrt(&psub);
    pair_re = snair * std::sin(step);
    pair_im = pair_re * 0.0;
    blast_re = 0.0;
    blast_im = 0.0;
    MI[0][0].re = 1.0;
    MI[0][0].im = 0.0;
    MI[1][1].re = 1.0;
    MI[1][1].im = 0.0;
    MI[1][0].re = 0.0;
    MI[1][0].im = 0.0;
    MI[0][1].re = 0.0;
    MI[0][1].im = 0.0;
    for (ilow = 0; ilow < b_i; ilow++) {
      for (loop_ub = 0; loop_ub <= b_layers; loop_ub++) {
        rough = slds[loop_ub + slds.size(0) * 2];
        snlay = 1.0 - slds[loop_ub + slds.size(0)] * 0.377451863036739;
        step = snlay * snlay - psub_tmp_tmp;
        pimag.re = step;
        pimag.im = step * 0.0;
        coder::internal::scalar::b_sqrt(&pimag);
        snlay = -78.956835208714864 * pair_re;
        rij_im = -78.956835208714864 * pair_im;
        step = rough * rough;
        rough = (snlay * pimag.re - rij_im * pimag.im) * step;
        rij_im = (snlay * pimag.im + rij_im * pimag.re) * step;
        if (rij_im == 0.0) {
          x_re = rough / 2.3716;
          x_im = 0.0;
        } else if (rough == 0.0) {
          x_re = 0.0;
          x_im = rij_im / 2.3716;
        } else {
          x_re = rough / 2.3716;
          x_im = rij_im / 2.3716;
        }
        if (x_im == 0.0) {
          x_re = std::exp(x_re);
          x_im = 0.0;
        } else if (std::isinf(x_im) && std::isinf(x_re) && (x_re < 0.0)) {
          x_re = 0.0;
          x_im = 0.0;
        } else {
          step = std::exp(x_re / 2.0);
          x_re = step * (step * std::cos(x_im));
          x_im = step * (step * std::sin(x_im));
        }
        rough = pair_re - pimag.re;
        rij_im = pair_im - pimag.im;
        step = pair_re + pimag.re;
        snlay = pair_im + pimag.im;
        if (snlay == 0.0) {
          if (rij_im == 0.0) {
            pair_re = rough / step;
            pair_im = 0.0;
          } else if (rough == 0.0) {
            pair_re = 0.0;
            pair_im = rij_im / step;
          } else {
            pair_re = rough / step;
            pair_im = rij_im / step;
          }
        } else if (step == 0.0) {
          if (rough == 0.0) {
            pair_re = rij_im / snlay;
            pair_im = 0.0;
          } else if (rij_im == 0.0) {
            pair_re = 0.0;
            pair_im = -(rough / snlay);
          } else {
            pair_re = rij_im / snlay;
            pair_im = -(rough / snlay);
          }
        } else {
          brm = std::abs(step);
          bim = std::abs(snlay);
          if (brm > bim) {
            bim = snlay / step;
            step += bim * snlay;
            pair_re = (rough + bim * rij_im) / step;
            pair_im = (rij_im - bim * rough) / step;
          } else if (bim == brm) {
            if (step > 0.0) {
              bim = 0.5;
            } else {
              bim = -0.5;
            }
            if (snlay > 0.0) {
              step = 0.5;
            } else {
              step = -0.5;
            }
            pair_re = (rough * bim + rij_im * step) / brm;
            pair_im = (rij_im * bim - rough * step) / brm;
          } else {
            bim = step / snlay;
            step = snlay + bim * step;
            pair_re = (bim * rough + rij_im) / step;
            pair_im = (bim * rij_im - rough) / step;
          }
        }
        snlay = pair_re * x_re - pair_im * x_im;
        rij_im = pair_re * x_im + pair_im * x_re;
        x_re = blast_re * 0.0 - blast_im;
        x_im = blast_re + blast_im * 0.0;
        if (x_im == 0.0) {
          N_tmp_re = std::exp(x_re);
          N_tmp_im = 0.0;
        } else if (std::isinf(x_im) && std::isinf(x_re) && (x_re < 0.0)) {
          N_tmp_re = 0.0;
          N_tmp_im = 0.0;
        } else {
          step = std::exp(x_re / 2.0);
          N_tmp_re = step * (step * std::cos(x_im));
          N_tmp_im = step * (step * std::sin(x_im));
        }
        x_re = -blast_re * 0.0 - (-blast_im);
        x_im = -blast_re + -blast_im * 0.0;
        if (x_im == 0.0) {
          pair_re = std::exp(x_re);
          pair_im = 0.0;
        } else if (std::isinf(x_im) && std::isinf(x_re) && (x_re < 0.0)) {
          pair_re = 0.0;
          pair_im = 0.0;
        } else {
          step = std::exp(x_re / 2.0);
          pair_re = step * (step * std::cos(x_im));
          pair_im = step * (step * std::sin(x_im));
        }
        brm = snlay * pair_re - rij_im * pair_im;
        x_re = snlay * pair_im + rij_im * pair_re;
        x_im = pair_re;
        d = pair_im;
        d1 = snlay * N_tmp_re - rij_im * N_tmp_im;
        step = snlay * N_tmp_im + rij_im * N_tmp_re;
        pair_re = pimag.re;
        pair_im = pimag.im;
        blast_re = 4.0799904592075231 * slds[loop_ub] * pimag.re;
        blast_im = 4.0799904592075231 * slds[loop_ub] * pimag.im;
        for (i1 = 0; i1 < 2; i1++) {
          snlay = MI[0][i1].re;
          rough = MI[0][i1].im;
          bim = MI[1][i1].re;
          rij_im = MI[1][i1].im;
          b_MI[0][i1].re = (snlay * N_tmp_re - rough * N_tmp_im) +
                           (bim * brm - rij_im * x_re);
          b_MI[0][i1].im = (snlay * N_tmp_im + rough * N_tmp_re) +
                           (bim * x_re + rij_im * brm);
          b_MI[1][i1].re =
              (snlay * d1 - rough * step) + (bim * x_im - rij_im * d);
          b_MI[1][i1].im =
              (snlay * step + rough * d1) + (bim * d + rij_im * x_im);
        }
        MI[0][0] = b_MI[0][0];
        MI[0][1] = b_MI[0][1];
        MI[1][0] = b_MI[1][0];
        MI[1][1] = b_MI[1][1];
      }
    }
    snlay = -78.956835208714864 * pair_re;
    rij_im = -78.956835208714864 * pair_im;
    rough = (snlay * psub.re - rij_im * psub.im) * ar_tmp;
    rij_im = (snlay * psub.im + rij_im * psub.re) * ar_tmp;
    if (rij_im == 0.0) {
      x_re = rough / 2.3716;
      x_im = 0.0;
    } else if (rough == 0.0) {
      x_re = 0.0;
      x_im = rij_im / 2.3716;
    } else {
      x_re = rough / 2.3716;
      x_im = rij_im / 2.3716;
    }
    if (x_im == 0.0) {
      x_re = std::exp(x_re);
      x_im = 0.0;
    } else if (std::isinf(x_im) && std::isinf(x_re) && (x_re < 0.0)) {
      x_re = 0.0;
      x_im = 0.0;
    } else {
      step = std::exp(x_re / 2.0);
      x_re = step * (step * std::cos(x_im));
      x_im = step * (step * std::sin(x_im));
    }
    rough = pair_re - psub.re;
    rij_im = pair_im - psub.im;
    step = pair_re + psub.re;
    snlay = pair_im + psub.im;
    if (snlay == 0.0) {
      if (rij_im == 0.0) {
        pair_re = rough / step;
        pair_im = 0.0;
      } else if (rough == 0.0) {
        pair_re = 0.0;
        pair_im = rij_im / step;
      } else {
        pair_re = rough / step;
        pair_im = rij_im / step;
      }
    } else if (step == 0.0) {
      if (rough == 0.0) {
        pair_re = rij_im / snlay;
        pair_im = 0.0;
      } else if (rij_im == 0.0) {
        pair_re = 0.0;
        pair_im = -(rough / snlay);
      } else {
        pair_re = rij_im / snlay;
        pair_im = -(rough / snlay);
      }
    } else {
      brm = std::abs(step);
      bim = std::abs(snlay);
      if (brm > bim) {
        bim = snlay / step;
        step += bim * snlay;
        pair_re = (rough + bim * rij_im) / step;
        pair_im = (rij_im - bim * rough) / step;
      } else if (bim == brm) {
        if (step > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }
        if (snlay > 0.0) {
          step = 0.5;
        } else {
          step = -0.5;
        }
        pair_re = (rough * bim + rij_im * step) / brm;
        pair_im = (rij_im * bim - rough * step) / brm;
      } else {
        bim = step / snlay;
        step = snlay + bim * step;
        pair_re = (bim * rough + rij_im) / step;
        pair_im = (bim * rij_im - rough) / step;
      }
    }
    snlay = pair_re * x_re - pair_im * x_im;
    rij_im = pair_re * x_im + pair_im * x_re;
    x_re = blast_re * 0.0 - blast_im;
    x_im = blast_re + blast_im * 0.0;
    if (x_im == 0.0) {
      N_tmp_re = std::exp(x_re);
      N_tmp_im = 0.0;
    } else if (std::isinf(x_im) && std::isinf(x_re) && (x_re < 0.0)) {
      N_tmp_re = 0.0;
      N_tmp_im = 0.0;
    } else {
      step = std::exp(x_re / 2.0);
      N_tmp_re = step * (step * std::cos(x_im));
      N_tmp_im = step * (step * std::sin(x_im));
    }
    x_re = -blast_re * 0.0 - (-blast_im);
    x_im = -blast_re + -blast_im * 0.0;
    if (x_im == 0.0) {
      pair_re = std::exp(x_re);
      pair_im = 0.0;
    } else if (std::isinf(x_im) && std::isinf(x_re) && (x_re < 0.0)) {
      pair_re = 0.0;
      pair_im = 0.0;
    } else {
      step = std::exp(x_re / 2.0);
      pair_re = step * (step * std::cos(x_im));
      pair_im = step * (step * std::sin(x_im));
    }
    brm = snlay * pair_re - rij_im * pair_im;
    x_re = snlay * pair_im + rij_im * pair_re;
    x_im = snlay * N_tmp_re - rij_im * N_tmp_im;
    d = snlay * N_tmp_im + rij_im * N_tmp_re;
    for (i1 = 0; i1 < 2; i1++) {
      d1 = MI[0][i1].re;
      step = MI[0][i1].im;
      snlay = MI[1][i1].re;
      rough = MI[1][i1].im;
      b_MI[0][i1].re =
          (d1 * N_tmp_re - step * N_tmp_im) + (snlay * brm - rough * x_re);
      b_MI[0][i1].im =
          (d1 * N_tmp_im + step * N_tmp_re) + (snlay * x_re + rough * brm);
      b_MI[1][i1].re =
          (d1 * x_im - step * d) + (snlay * pair_re - rough * pair_im);
      b_MI[1][i1].im =
          (d1 * d + step * x_im) + (snlay * pair_im + rough * pair_re);
    }
    rij_im = b_MI[0][1].re * b_MI[0][1].re - b_MI[0][1].im * -b_MI[0][1].im;
    rough = b_MI[0][1].re * -b_MI[0][1].im + b_MI[0][1].im * b_MI[0][1].re;
    step = b_MI[0][0].re * b_MI[0][0].re - b_MI[0][0].im * -b_MI[0][0].im;
    snlay = b_MI[0][0].re * -b_MI[0][0].im + b_MI[0][0].im * b_MI[0][0].re;
    if (snlay == 0.0) {
      if (rough == 0.0) {
        pair_re = rij_im / step;
        pair_im = 0.0;
      } else if (rij_im == 0.0) {
        pair_re = 0.0;
        pair_im = rough / step;
      } else {
        pair_re = rij_im / step;
        pair_im = rough / step;
      }
    } else if (step == 0.0) {
      if (rij_im == 0.0) {
        pair_re = rough / snlay;
        pair_im = 0.0;
      } else if (rough == 0.0) {
        pair_re = 0.0;
        pair_im = -(rij_im / snlay);
      } else {
        pair_re = rough / snlay;
        pair_im = -(rij_im / snlay);
      }
    } else {
      brm = std::abs(step);
      bim = std::abs(snlay);
      if (brm > bim) {
        bim = snlay / step;
        step += bim * snlay;
        pair_re = (rij_im + bim * rough) / step;
        pair_im = (rough - bim * rij_im) / step;
      } else if (bim == brm) {
        if (step > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }
        if (snlay > 0.0) {
          step = 0.5;
        } else {
          step = -0.5;
        }
        pair_re = (rij_im * bim + rough * step) / brm;
        pair_im = (rough * bim - rij_im * step) / brm;
      } else {
        bim = step / snlay;
        step = snlay + bim * step;
        pair_re = (bim * rij_im + rough) / step;
        pair_im = (bim * rough - rij_im) / step;
      }
    }
    simRef[b_loop_ub] = rt_hypotd_snf(pair_re, pair_im);
  }
  b_layers = simXdata.size(0) - 10;
  dummydata.set_size(simXdata.size(0));
  loop_ub = simXdata.size(0);
  for (i = 0; i < loop_ub; i++) {
    dummydata[i] = 0.0;
  }
  i = simXdata.size(0);
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    step = 0.0;
    dummydata[loop_ub] = 0.0;
    if (loop_ub + 1 > 10) {
      ilow = -10;
    } else {
      ilow = -loop_ub;
    }
    //     try
    if (loop_ub + 1 < b_layers) {
      b_loop_ub = 1;
    } else {
      b_loop_ub = b_layers - loop_ub;
    }
    i1 = (b_loop_ub - ilow) + 9;
    for (b_i = 0; b_i <= i1; b_i++) {
      b_loop_ub = (loop_ub + ilow) + b_i;
      snlay = (simXdata[b_loop_ub] - simXdata[loop_ub]) /
              ((res + 0.0001) * simXdata[loop_ub]);
      snlay = std::exp(-(snlay * snlay));
      step += snlay;
      dummydata[loop_ub] = dummydata[loop_ub] + simRef[b_loop_ub] * snlay;
    }
    if (step != 0.0) {
      dummydata[loop_ub] = dummydata[loop_ub] / step;
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
  for (i1 = 0; i1 < 2; i1++) {
    for (b_i = 0; b_i < loop_ub; b_i++) {
      reflectivity[b_i + reflectivity.size(0) * i1] =
          Simulation[(i + b_i) + Simulation.size(0) * i1];
    }
  }
}

// End of code generation (callReflectivity.cpp)
