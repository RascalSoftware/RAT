//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: callReflectivity.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "callReflectivity.h"
#include "abeles_paraPoints.h"
#include "abeles_single.h"
#include "colon.h"
#include "data_resolution_polly.h"
#include "resolution_polly.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : real_T nbairs
//                real_T nbsubs
//                const real_T simLimits_data[]
//                const real_T repeatLayers[2]
//                const real_T this_data_data[]
//                const int32_T this_data_size[2]
//                const ::coder::array<real_T, 2U> &layers
//                real_T ssubs
//                real_T res
//                ::coder::array<real_T, 2U> &reflectivity
//                ::coder::array<real_T, 2U> &Simulation
// Return Type  : void
//
namespace RAT
{
  void b_callReflectivity(real_T nbairs, real_T nbsubs, const real_T
    simLimits_data[], const real_T repeatLayers[2], const real_T this_data_data[],
    const int32_T this_data_size[2], const ::coder::array<real_T, 2U> &layers,
    real_T ssubs, real_T res, ::coder::array<real_T, 2U> &reflectivity, ::coder::
    array<real_T, 2U> &Simulation)
  {
    ::coder::array<real_T, 2U> firstSection;
    ::coder::array<real_T, 2U> lastSection;
    ::coder::array<real_T, 2U> slds;
    ::coder::array<real_T, 1U> r;
    ::coder::array<real_T, 1U> simRef;
    ::coder::array<real_T, 1U> simResolData;
    ::coder::array<real_T, 1U> simXdata;
    real_T b;
    real_T step;
    int32_T i;
    int32_T i1;
    int32_T lays;
    int32_T loop_ub;
    int32_T simLimits;
    uint32_T splits_idx_1;
    if (layers.size(0) == 0) {
      slds.set_size(1, 3);
      slds[0] = 0.0;
      slds[slds.size(0)] = nbairs;
      slds[slds.size(0) * 2] = 0.0;
      lays = 0;
    } else {
      slds.set_size(layers.size(0), 3);
      loop_ub = layers.size(0);
      for (i = 0; i < 3; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          slds[i1 + slds.size(0) * i] = layers[i1 + layers.size(0) * i];
        }
      }

      lays = layers.size(0);
    }

    if (simLimits_data[0] < this_data_data[0]) {
      step = this_data_data[1] - this_data_data[0];
      b = this_data_data[0] - step;
      if (std::isnan(step) || std::isnan(b)) {
        firstSection.set_size(1, 1);
        firstSection[0] = rtNaN;
      } else if ((step == 0.0) || ((simLimits_data[0] < b) && (step < 0.0)) ||
                 ((b < simLimits_data[0]) && (step > 0.0))) {
        firstSection.set_size(1, 0);
      } else if ((std::isinf(simLimits_data[0]) || std::isinf(b)) && (std::isinf
                  (step) || (simLimits_data[0] == b))) {
        firstSection.set_size(1, 1);
        firstSection[0] = rtNaN;
      } else if (std::isinf(step)) {
        firstSection.set_size(1, 1);
        firstSection[0] = simLimits_data[0];
      } else if ((std::floor(simLimits_data[0]) == simLimits_data[0]) && (std::
                  floor(step) == step)) {
        loop_ub = static_cast<int32_T>((b - simLimits_data[0]) / step);
        firstSection.set_size(1, loop_ub + 1);
        for (i = 0; i <= loop_ub; i++) {
          firstSection[i] = simLimits_data[0] + step * static_cast<real_T>(i);
        }
      } else {
        coder::eml_float_colon(simLimits_data[0], step, b, firstSection);
      }
    } else {
      firstSection.set_size(1, 0);
    }

    b = this_data_data[this_data_size[0] - 1];
    if (simLimits_data[1] > b) {
      step = b - this_data_data[this_data_size[0] - 2];
      b += step;
      if (std::isnan(b) || std::isnan(step)) {
        lastSection.set_size(1, 1);
        lastSection[0] = rtNaN;
      } else if ((step == 0.0) || ((b < simLimits_data[1]) && (step < 0.0)) ||
                 ((simLimits_data[1] < b) && (step > 0.0))) {
        lastSection.set_size(1, 0);
      } else if ((std::isinf(b) || std::isinf(simLimits_data[1])) && (std::isinf
                  (step) || (b == simLimits_data[1]))) {
        lastSection.set_size(1, 1);
        lastSection[0] = rtNaN;
      } else if (std::isinf(step)) {
        lastSection.set_size(1, 1);
        lastSection[0] = b;
      } else if ((std::floor(b) == b) && (std::floor(step) == step)) {
        loop_ub = static_cast<int32_T>((simLimits_data[1] - b) / step);
        lastSection.set_size(1, loop_ub + 1);
        for (i = 0; i <= loop_ub; i++) {
          lastSection[i] = b + step * static_cast<real_T>(i);
        }
      } else {
        coder::eml_float_colon(b, step, simLimits_data[1], lastSection);
      }
    } else {
      lastSection.set_size(1, 0);
    }

    simLimits = firstSection.size(1);
    simXdata.set_size((this_data_size[0] + firstSection.size(1)) +
                      lastSection.size(1));
    loop_ub = firstSection.size(1);
    for (i = 0; i < loop_ub; i++) {
      simXdata[i] = firstSection[i];
    }

    loop_ub = this_data_size[0];
    for (i = 0; i < loop_ub; i++) {
      simXdata[i + simLimits] = this_data_data[i];
    }

    loop_ub = lastSection.size(1);
    for (i = 0; i < loop_ub; i++) {
      simXdata[(i + simLimits) + this_data_size[0]] = lastSection[i];
    }

    splits_idx_1 = static_cast<uint32_T>(firstSection.size(1)) +
      static_cast<uint32_T>(this_data_size[0]);
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

    //  If we are using data resolutions, then we also need to adjust the length
    //  of the reolution column. We do thit by just extending with the rosolution
    //  values at the ends of the curve.
    simResolData.set_size(1);
    simResolData[0] = 0.0;
    if (res == -1.0) {
      simLimits = firstSection.size(1);
      simResolData.set_size((this_data_size[0] + firstSection.size(1)) +
                            lastSection.size(1));
      loop_ub = firstSection.size(1);
      for (i = 0; i < loop_ub; i++) {
        simResolData[i] = this_data_data[this_data_size[0] * 3];
      }

      loop_ub = this_data_size[0];
      for (i = 0; i < loop_ub; i++) {
        simResolData[i + simLimits] = this_data_data[i + this_data_size[0] * 3];
      }

      loop_ub = lastSection.size(1);
      for (i = 0; i < loop_ub; i++) {
        simResolData[(i + simLimits) + this_data_size[0]] = this_data_data
          [(this_data_size[0] + this_data_size[0] * 3) - 1];
      }
    }

    //  Parallelise over points
    //  Calculate reflectivity....
    abeles_paraPoints(simXdata, slds, nbairs, nbsubs, repeatLayers[1], ssubs,
                      static_cast<real_T>(lays), static_cast<real_T>
                      (simXdata.size(0)), simRef);

    // (x,sld,nbair,nbsub,nrepeats,ssub,layers,points)
    //  Apply resolution
    //  Note: paraPoints gives an error during valifation, so use
    //  single cored resolution as a workaround for now.
    if (res == -1.0) {
      // simRef = data_resolution_polly_paraPoints(simXdata,simRef,simResolData,length(simXdata));
      data_resolution_polly(simXdata, simRef, simResolData, static_cast<real_T>
                            (simXdata.size(0)), r);
      loop_ub = r.size(0);
      for (i = 0; i < loop_ub; i++) {
        Simulation[i + Simulation.size(0)] = r[i];
      }
    } else {
      // simRef = resolution_polly_paraPoints(simXdata,simRef,res,length(simXdata));
      resolution_polly(simXdata, simRef, res, static_cast<real_T>(simXdata.size
        (0)), r);
      loop_ub = r.size(0);
      for (i = 0; i < loop_ub; i++) {
        Simulation[i + Simulation.size(0)] = r[i];
      }
    }

    if (static_cast<uint32_T>(firstSection.size(1)) + 1U > splits_idx_1) {
      i = 0;
      i1 = 0;
    } else {
      i = firstSection.size(1);
      i1 = static_cast<int32_T>(splits_idx_1);
    }

    loop_ub = i1 - i;
    reflectivity.set_size(loop_ub, 2);
    for (i1 = 0; i1 < 2; i1++) {
      for (simLimits = 0; simLimits < loop_ub; simLimits++) {
        reflectivity[simLimits + reflectivity.size(0) * i1] = Simulation[(i +
          simLimits) + Simulation.size(0) * i1];
      }
    }
  }

  //
  // Arguments    : real_T nbairs
  //                real_T nbsubs
  //                const real_T simLimits_data[]
  //                const real_T repeatLayers[2]
  //                const real_T this_data_data[]
  //                const int32_T this_data_size[2]
  //                const ::coder::array<real_T, 2U> &layers
  //                real_T ssubs
  //                real_T res
  //                ::coder::array<real_T, 2U> &reflectivity
  //                ::coder::array<real_T, 2U> &Simulation
  // Return Type  : void
  //
  void callReflectivity(real_T nbairs, real_T nbsubs, const real_T
                        simLimits_data[], const real_T repeatLayers[2], const
                        real_T this_data_data[], const int32_T this_data_size[2],
                        const ::coder::array<real_T, 2U> &layers, real_T ssubs,
                        real_T res, ::coder::array<real_T, 2U> &reflectivity, ::
                        coder::array<real_T, 2U> &Simulation)
  {
    ::coder::array<real_T, 2U> firstSection;
    ::coder::array<real_T, 2U> lastSection;
    ::coder::array<real_T, 2U> slds;
    ::coder::array<real_T, 1U> r;
    ::coder::array<real_T, 1U> simRef;
    ::coder::array<real_T, 1U> simResolData;
    ::coder::array<real_T, 1U> simXdata;
    real_T b;
    real_T step;
    int32_T i;
    int32_T i1;
    int32_T lays;
    int32_T loop_ub;
    int32_T simLimits;
    uint32_T splits_idx_1;
    if (layers.size(0) == 0) {
      slds.set_size(1, 3);
      slds[0] = 0.0;
      slds[slds.size(0)] = nbairs;
      slds[slds.size(0) * 2] = 0.0;
      lays = 0;
    } else {
      slds.set_size(layers.size(0), 3);
      loop_ub = layers.size(0);
      for (i = 0; i < 3; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          slds[i1 + slds.size(0) * i] = layers[i1 + layers.size(0) * i];
        }
      }

      lays = layers.size(0);
    }

    if (simLimits_data[0] < this_data_data[0]) {
      step = this_data_data[1] - this_data_data[0];
      b = this_data_data[0] - step;
      if (std::isnan(step) || std::isnan(b)) {
        firstSection.set_size(1, 1);
        firstSection[0] = rtNaN;
      } else if ((step == 0.0) || ((simLimits_data[0] < b) && (step < 0.0)) ||
                 ((b < simLimits_data[0]) && (step > 0.0))) {
        firstSection.set_size(1, 0);
      } else if ((std::isinf(simLimits_data[0]) || std::isinf(b)) && (std::isinf
                  (step) || (simLimits_data[0] == b))) {
        firstSection.set_size(1, 1);
        firstSection[0] = rtNaN;
      } else if (std::isinf(step)) {
        firstSection.set_size(1, 1);
        firstSection[0] = simLimits_data[0];
      } else if ((std::floor(simLimits_data[0]) == simLimits_data[0]) && (std::
                  floor(step) == step)) {
        loop_ub = static_cast<int32_T>((b - simLimits_data[0]) / step);
        firstSection.set_size(1, loop_ub + 1);
        for (i = 0; i <= loop_ub; i++) {
          firstSection[i] = simLimits_data[0] + step * static_cast<real_T>(i);
        }
      } else {
        coder::eml_float_colon(simLimits_data[0], step, b, firstSection);
      }
    } else {
      firstSection.set_size(1, 0);
    }

    b = this_data_data[this_data_size[0] - 1];
    if (simLimits_data[1] > b) {
      step = b - this_data_data[this_data_size[0] - 2];
      b += step;
      if (std::isnan(b) || std::isnan(step)) {
        lastSection.set_size(1, 1);
        lastSection[0] = rtNaN;
      } else if ((step == 0.0) || ((b < simLimits_data[1]) && (step < 0.0)) ||
                 ((simLimits_data[1] < b) && (step > 0.0))) {
        lastSection.set_size(1, 0);
      } else if ((std::isinf(b) || std::isinf(simLimits_data[1])) && (std::isinf
                  (step) || (b == simLimits_data[1]))) {
        lastSection.set_size(1, 1);
        lastSection[0] = rtNaN;
      } else if (std::isinf(step)) {
        lastSection.set_size(1, 1);
        lastSection[0] = b;
      } else if ((std::floor(b) == b) && (std::floor(step) == step)) {
        loop_ub = static_cast<int32_T>((simLimits_data[1] - b) / step);
        lastSection.set_size(1, loop_ub + 1);
        for (i = 0; i <= loop_ub; i++) {
          lastSection[i] = b + step * static_cast<real_T>(i);
        }
      } else {
        coder::eml_float_colon(b, step, simLimits_data[1], lastSection);
      }
    } else {
      lastSection.set_size(1, 0);
    }

    simLimits = firstSection.size(1);
    simXdata.set_size((this_data_size[0] + firstSection.size(1)) +
                      lastSection.size(1));
    loop_ub = firstSection.size(1);
    for (i = 0; i < loop_ub; i++) {
      simXdata[i] = firstSection[i];
    }

    loop_ub = this_data_size[0];
    for (i = 0; i < loop_ub; i++) {
      simXdata[i + simLimits] = this_data_data[i];
    }

    loop_ub = lastSection.size(1);
    for (i = 0; i < loop_ub; i++) {
      simXdata[(i + simLimits) + this_data_size[0]] = lastSection[i];
    }

    splits_idx_1 = static_cast<uint32_T>(firstSection.size(1)) +
      static_cast<uint32_T>(this_data_size[0]);
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

    //  If we are using data resolutions, then we also need to adjust the length
    //  of the reolution column. We do thit by just extending with the rosolution
    //  values at the ends of the curve.
    simResolData.set_size(1);
    simResolData[0] = 0.0;
    if (res == -1.0) {
      simLimits = firstSection.size(1);
      simResolData.set_size((this_data_size[0] + firstSection.size(1)) +
                            lastSection.size(1));
      loop_ub = firstSection.size(1);
      for (i = 0; i < loop_ub; i++) {
        simResolData[i] = this_data_data[this_data_size[0] * 3];
      }

      loop_ub = this_data_size[0];
      for (i = 0; i < loop_ub; i++) {
        simResolData[i + simLimits] = this_data_data[i + this_data_size[0] * 3];
      }

      loop_ub = lastSection.size(1);
      for (i = 0; i < loop_ub; i++) {
        simResolData[(i + simLimits) + this_data_size[0]] = this_data_data
          [(this_data_size[0] + this_data_size[0] * 3) - 1];
      }
    }

    //  Single cored over points
    //  Calculate reflectivity.....
    abeles_single(simXdata, slds, nbairs, nbsubs, repeatLayers[1], ssubs,
                  static_cast<real_T>(lays), static_cast<real_T>(simXdata.size(0)),
                  simRef);

    //  Apply resolution correction...
    if (res == -1.0) {
      data_resolution_polly(simXdata, simRef, simResolData, static_cast<real_T>
                            (simXdata.size(0)), r);
      loop_ub = r.size(0);
      for (i = 0; i < loop_ub; i++) {
        Simulation[i + Simulation.size(0)] = r[i];
      }
    } else {
      resolution_polly(simXdata, simRef, res, static_cast<real_T>(simXdata.size
        (0)), r);
      loop_ub = r.size(0);
      for (i = 0; i < loop_ub; i++) {
        Simulation[i + Simulation.size(0)] = r[i];
      }
    }

    if (static_cast<uint32_T>(firstSection.size(1)) + 1U > splits_idx_1) {
      i = 0;
      i1 = 0;
    } else {
      i = firstSection.size(1);
      i1 = static_cast<int32_T>(splits_idx_1);
    }

    loop_ub = i1 - i;
    reflectivity.set_size(loop_ub, 2);
    for (i1 = 0; i1 < 2; i1++) {
      for (simLimits = 0; simLimits < loop_ub; simLimits++) {
        reflectivity[simLimits + reflectivity.size(0) * i1] = Simulation[(i +
          simLimits) + Simulation.size(0) * i1];
      }
    }
  }
}

//
// File trailer for callReflectivity.cpp
//
// [EOF]
//
