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
#include "abelesParallelPoints.h"
#include "abelesSingle.h"
#include "colon.h"
#include "dataResolutionPolly.h"
#include "resolutionPolly.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void callReflectivity(real_T bulkIns, real_T bulkOuts, const real_T simLimits
                        [2], const real_T repeatLayers[2], const ::coder::array<
                        real_T, 2U> &thisData, ::coder::array<real_T, 2U>
                        &layers, real_T ssubs, real_T resolution, const char_T
                        parallel_data[], const int32_T parallel_size[2],
                        boolean_T useImaginary, ::coder::array<real_T, 2U>
                        &reflectivity, ::coder::array<real_T, 2U> &simulation)
  {
    ::coder::array<creal_T, 1U> slds;
    ::coder::array<real_T, 2U> firstSection;
    ::coder::array<real_T, 2U> lastSection;
    ::coder::array<real_T, 1U> r;
    ::coder::array<real_T, 1U> roughs;
    ::coder::array<real_T, 1U> simRef;
    ::coder::array<real_T, 1U> simResolData;
    ::coder::array<real_T, 1U> simXdata;
    ::coder::array<real_T, 1U> thicks;
    real_T b;
    real_T nLayersTot;
    real_T nRepeats;
    real_T step;
    int32_T b_loop_ub;
    int32_T i;
    int32_T loop_ub;
    int32_T loop_ub_tmp;
    uint32_T layerCount;
    uint32_T splits_idx_1;
    if (repeatLayers[0] != 0.0) {
      nRepeats = repeatLayers[1];
    } else {
      nRepeats = 1.0;
    }

    //  Build the input arrays for thick, sld and rough.....
    if (layers.size(0) == 0) {
      //  No layers defined. Make a zeros dummy zero layer
      layers.set_size(1, 3);
      layers[0] = 0.0;
      layers[layers.size(0)] = bulkIns;
      layers[layers.size(0) * 2] = 0.0;
    }

    //  Number of layers (including repeats)
    nLayersTot = static_cast<real_T>(layers.size(0)) * nRepeats + 2.0;

    //  Make arrays for thick, sld, rough
    loop_ub_tmp = static_cast<int32_T>(nLayersTot);
    thicks.set_size(loop_ub_tmp);
    roughs.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      thicks[i] = 0.0;
      roughs[i] = 0.0;
    }

    if (useImaginary) {
      slds.set_size(loop_ub_tmp);
      for (i = 0; i < loop_ub_tmp; i++) {
        slds[i].re = 0.0;
        slds[i].im = 0.0;
      }
    } else {
      slds.set_size(loop_ub_tmp);
      for (i = 0; i < loop_ub_tmp; i++) {
        slds[i].re = 0.0;
        slds[i].im = 0.0;
      }
    }

    //  Populate the d,rho,sig arrays...
    layerCount = 2U;
    i = static_cast<int32_T>(nRepeats);
    for (int32_T m{0}; m < i; m++) {
      loop_ub = layers.size(0);
      for (int32_T n{0}; n < loop_ub; n++) {
        if (!useImaginary) {
          loop_ub_tmp = static_cast<int32_T>(layerCount + n) - 1;
          thicks[loop_ub_tmp] = layers[n];
          slds[loop_ub_tmp].re = layers[n + layers.size(0)];
          slds[loop_ub_tmp].im = 0.0;
          roughs[loop_ub_tmp] = layers[n + layers.size(0) * 2];
        } else {
          loop_ub_tmp = static_cast<int32_T>(layerCount + n) - 1;
          thicks[loop_ub_tmp] = layers[n];
          slds[loop_ub_tmp].re = layers[n + layers.size(0)];
          slds[loop_ub_tmp].im = layers[n + layers.size(0) * 2];
          roughs[loop_ub_tmp] = layers[n + layers.size(0) * 3];
        }
      }

      layerCount += layers.size(0);
    }

    //  Add the air and substrate parameters
    slds[0].re = bulkIns;
    slds[0].im = 0.0;
    slds[slds.size(0) - 1].re = bulkOuts;
    slds[slds.size(0) - 1].im = 0.0;
    roughs[roughs.size(0) - 1] = ssubs;
    if (simLimits[0] < thisData[0]) {
      step = thisData[1] - thisData[0];
      b = thisData[0] - step;
      if (std::isnan(step) || std::isnan(b)) {
        firstSection.set_size(1, 1);
        firstSection[0] = rtNaN;
      } else if ((step == 0.0) || ((simLimits[0] < b) && (step < 0.0)) || ((b <
                   simLimits[0]) && (step > 0.0))) {
        firstSection.set_size(1, 0);
      } else if ((std::isinf(simLimits[0]) || std::isinf(b)) && (std::isinf(step)
                  || (simLimits[0] == b))) {
        firstSection.set_size(1, 1);
        firstSection[0] = rtNaN;
      } else if (std::isinf(step)) {
        firstSection.set_size(1, 1);
        firstSection[0] = simLimits[0];
      } else if ((std::floor(simLimits[0]) == simLimits[0]) && (std::floor(step)
                  == step)) {
        b_loop_ub = static_cast<int32_T>(std::floor((b - simLimits[0]) / step));
        firstSection.set_size(1, b_loop_ub + 1);
        for (i = 0; i <= b_loop_ub; i++) {
          firstSection[i] = simLimits[0] + step * static_cast<real_T>(i);
        }
      } else {
        coder::eml_float_colon(simLimits[0], step, b, firstSection);
      }
    } else {
      firstSection.set_size(1, 0);
    }

    if (simLimits[1] > thisData[thisData.size(0) - 1]) {
      step = thisData[thisData.size(0) - 1] - thisData[thisData.size(0) - 2];
      b = thisData[thisData.size(0) - 1] + step;
      if (std::isnan(b) || std::isnan(step)) {
        lastSection.set_size(1, 1);
        lastSection[0] = rtNaN;
      } else if ((step == 0.0) || ((b < simLimits[1]) && (step < 0.0)) ||
                 ((simLimits[1] < b) && (step > 0.0))) {
        lastSection.set_size(1, 0);
      } else if ((std::isinf(b) || std::isinf(simLimits[1])) && (std::isinf(step)
                  || (b == simLimits[1]))) {
        lastSection.set_size(1, 1);
        lastSection[0] = rtNaN;
      } else if (std::isinf(step)) {
        lastSection.set_size(1, 1);
        lastSection[0] = b;
      } else if ((std::floor(b) == b) && (std::floor(step) == step)) {
        b_loop_ub = static_cast<int32_T>(std::floor((simLimits[1] - b) / step));
        lastSection.set_size(1, b_loop_ub + 1);
        for (i = 0; i <= b_loop_ub; i++) {
          lastSection[i] = b + step * static_cast<real_T>(i);
        }
      } else {
        coder::eml_float_colon(b, step, simLimits[1], lastSection);
      }
    } else {
      lastSection.set_size(1, 0);
    }

    loop_ub_tmp = firstSection.size(1);
    b_loop_ub = thisData.size(0);
    simXdata.set_size((thisData.size(0) + firstSection.size(1)) +
                      lastSection.size(1));
    loop_ub = firstSection.size(1);
    for (i = 0; i < loop_ub; i++) {
      simXdata[i] = firstSection[i];
    }

    for (i = 0; i < b_loop_ub; i++) {
      simXdata[i + loop_ub_tmp] = thisData[i];
    }

    loop_ub = lastSection.size(1);
    for (i = 0; i < loop_ub; i++) {
      simXdata[(i + loop_ub_tmp) + b_loop_ub] = lastSection[i];
    }

    splits_idx_1 = static_cast<uint32_T>(firstSection.size(1)) + thisData.size(0);
    simulation.set_size(simXdata.size(0), 2);
    b_loop_ub = simXdata.size(0);
    for (i = 0; i < 2; i++) {
      for (loop_ub = 0; loop_ub < b_loop_ub; loop_ub++) {
        simulation[loop_ub + simulation.size(0) * i] = 0.0;
      }
    }

    b_loop_ub = simXdata.size(0);
    for (i = 0; i < b_loop_ub; i++) {
      simulation[i] = simXdata[i];
    }

    //  If we are using data resolutions, then we also need to adjust the length
    //  of the reolution column. We do thit by just extending with the rosolution
    //  values at the ends of the curve.
    simResolData.set_size(1);
    simResolData[0] = 0.0;
    if (resolution == -1.0) {
      loop_ub_tmp = firstSection.size(1);
      b_loop_ub = thisData.size(0);
      simResolData.set_size((thisData.size(0) + firstSection.size(1)) +
                            lastSection.size(1));
      loop_ub = firstSection.size(1);
      for (i = 0; i < loop_ub; i++) {
        simResolData[i] = thisData[thisData.size(0) * 3];
      }

      for (i = 0; i < b_loop_ub; i++) {
        simResolData[i + loop_ub_tmp] = thisData[i + thisData.size(0) * 3];
      }

      loop_ub = lastSection.size(1);
      for (i = 0; i < loop_ub; i++) {
        simResolData[(i + loop_ub_tmp) + b_loop_ub] = thisData[(thisData.size(0)
          + thisData.size(0) * 3) - 1];
      }
    }

    if (coder::internal::n_strcmp(parallel_data, parallel_size)) {
      i = 0;
    } else {
      i = -1;
    }

    switch (i) {
     case 0:
      //  Parallelise over points
      //  Calculate reflectivity....
      abelesParallelPoints(simXdata, nLayersTot, thicks, slds, roughs, simRef);

      //  Apply resolution
      //  Note: paraPoints gives an error during valifation, so use
      //  single cored resolution as a workaround for now.
      if (resolution == -1.0) {
        // simRef = dataResolutionPollyParallelPoints(simXdata,simRef,simResolData,length(simXdata));
        dataResolutionPolly(simXdata, simRef, simResolData, static_cast<real_T>
                            (simXdata.size(0)), r);
        b_loop_ub = r.size(0);
        for (i = 0; i < b_loop_ub; i++) {
          simulation[i + simulation.size(0)] = r[i];
        }
      } else {
        // simRef = resolutionPollyParallelPoints(simXdata,simRef,res,length(simXdata));
        resolutionPolly(simXdata, simRef, resolution, static_cast<real_T>
                        (simXdata.size(0)), r);
        b_loop_ub = r.size(0);
        for (i = 0; i < b_loop_ub; i++) {
          simulation[i + simulation.size(0)] = r[i];
        }
      }
      break;

     default:
      //  Single cored over points
      //  Calculate reflectivity.....
      abelesSingle(simXdata, nLayersTot, thicks, slds, roughs, simRef);

      //  Apply resolution correction...
      if (resolution == -1.0) {
        dataResolutionPolly(simXdata, simRef, simResolData, static_cast<real_T>
                            (simXdata.size(0)), r);
        b_loop_ub = r.size(0);
        for (i = 0; i < b_loop_ub; i++) {
          simulation[i + simulation.size(0)] = r[i];
        }
      } else {
        resolutionPolly(simXdata, simRef, resolution, static_cast<real_T>
                        (simXdata.size(0)), r);
        b_loop_ub = r.size(0);
        for (i = 0; i < b_loop_ub; i++) {
          simulation[i + simulation.size(0)] = r[i];
        }
      }
      break;
    }

    if (firstSection.size(1) + 1U > splits_idx_1) {
      i = 0;
      loop_ub = 0;
    } else {
      i = firstSection.size(1);
      loop_ub = static_cast<int32_T>(splits_idx_1);
    }

    b_loop_ub = loop_ub - i;
    reflectivity.set_size(b_loop_ub, 2);
    for (loop_ub = 0; loop_ub < 2; loop_ub++) {
      for (loop_ub_tmp = 0; loop_ub_tmp < b_loop_ub; loop_ub_tmp++) {
        reflectivity[loop_ub_tmp + reflectivity.size(0) * loop_ub] = simulation
          [(i + loop_ub_tmp) + simulation.size(0) * loop_ub];
      }
    }
  }
}

// End of code generation (callReflectivity.cpp)
