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
#include "dataResolutionPolly.h"
#include "makeSimulationRange.h"
#include "resolutionPolly.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void callReflectivity(real_T bulkIn, real_T bulkOut, const real_T simLimits[2],
                        const real_T repeatLayers[2], const ::coder::array<
                        real_T, 2U> &data, ::coder::array<real_T, 2U> &layers,
                        real_T ssubs, real_T resolution, const char_T
                        parallel_data[], const int32_T parallel_size[2],
                        boolean_T useImaginary, ::coder::array<real_T, 2U>
                        &reflectivity, ::coder::array<real_T, 2U> &simulation)
  {
    ::coder::array<creal_T, 1U> slds;
    ::coder::array<real_T, 1U> endResol;
    ::coder::array<real_T, 1U> r;
    ::coder::array<real_T, 1U> roughs;
    ::coder::array<real_T, 1U> simRef;
    ::coder::array<real_T, 1U> simResolData;
    ::coder::array<real_T, 1U> simulationXData;
    ::coder::array<real_T, 1U> thicks;
    real_T dataIndices[2];
    real_T nLayersTot;
    real_T nRepeats;
    int32_T b_loop_ub;
    int32_T i;
    int32_T loop_ub;
    int32_T loop_ub_tmp;
    uint32_T layerCount;
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
      layers[layers.size(0)] = bulkIn;
      layers[layers.size(0) * 2] = 0.0;
    }

    //  Number of layers (including repeats)
    nLayersTot = static_cast<real_T>(layers.size(0)) * nRepeats + 2.0;

    //  Make arrays for thick, sld, rough
    loop_ub_tmp = static_cast<int32_T>(nLayersTot);
    thicks.set_size(loop_ub_tmp);
    slds.set_size(loop_ub_tmp);
    roughs.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      thicks[i] = 0.0;
      slds[i].re = 0.0;
      slds[i].im = 0.0;
      roughs[i] = 0.0;
    }

    //  Populate the d,rho,sig arrays...
    layerCount = 2U;
    i = static_cast<int32_T>(nRepeats);
    for (int32_T m{0}; m < i; m++) {
      loop_ub = layers.size(0);
      for (int32_T n{0}; n < loop_ub; n++) {
        loop_ub_tmp = static_cast<int32_T>(layerCount + n) - 1;
        thicks[loop_ub_tmp] = layers[n];
        if (!useImaginary) {
          slds[loop_ub_tmp].re = layers[n + layers.size(0)];
          slds[loop_ub_tmp].im = 2.2204460492503131E-16;
          roughs[loop_ub_tmp] = layers[n + layers.size(0) * 2];
        } else {
          slds[loop_ub_tmp].re = layers[n + layers.size(0)];
          slds[loop_ub_tmp].im = layers[n + layers.size(0) * 2];
          roughs[loop_ub_tmp] = layers[n + layers.size(0) * 3];
        }
      }

      layerCount += layers.size(0);
    }

    //  Add the air and substrate parameters
    slds[0].re = bulkIn;
    slds[0].im = 2.2204460492503131E-16;
    slds[slds.size(0) - 1].re = bulkOut;
    slds[slds.size(0) - 1].im = 2.2204460492503131E-16;
    roughs[roughs.size(0) - 1] = ssubs;
    makeSimulationRange(data, simLimits, simulationXData, dataIndices);
    simulation.set_size(simulationXData.size(0), 2);
    b_loop_ub = simulationXData.size(0);
    for (i = 0; i < 2; i++) {
      for (loop_ub = 0; loop_ub < b_loop_ub; loop_ub++) {
        simulation[loop_ub + simulation.size(0) * i] = 0.0;
      }
    }

    b_loop_ub = simulationXData.size(0);
    for (i = 0; i < b_loop_ub; i++) {
      simulation[i] = simulationXData[i];
    }

    //  If we are using data resolutions, then we also need to adjust the length
    //  of the resolution column. We do this by just extending with the resolution
    //  values at the ends of the curve.
    simResolData.set_size(1);
    simResolData[0] = 0.0;
    if (resolution == -1.0) {
      loop_ub_tmp = static_cast<int32_T>(static_cast<real_T>
        (simulationXData.size(0)) - dataIndices[1]);
      endResol.set_size(loop_ub_tmp);
      for (i = 0; i < loop_ub_tmp; i++) {
        endResol[i] = data[(data.size(0) + data.size(0) * 3) - 1];
      }

      loop_ub_tmp = static_cast<int32_T>(dataIndices[0] - 1.0);
      b_loop_ub = data.size(0);
      simResolData.set_size((static_cast<int32_T>(dataIndices[0] - 1.0) +
        data.size(0)) + endResol.size(0));
      for (i = 0; i < loop_ub_tmp; i++) {
        simResolData[i] = data[data.size(0) * 3];
      }

      for (i = 0; i < b_loop_ub; i++) {
        simResolData[i + loop_ub_tmp] = data[i + data.size(0) * 3];
      }

      loop_ub = endResol.size(0);
      for (i = 0; i < loop_ub; i++) {
        simResolData[(i + loop_ub_tmp) + b_loop_ub] = endResol[i];
      }
    }

    if (coder::internal::p_strcmp(parallel_data, parallel_size)) {
      i = 0;
    } else {
      i = -1;
    }

    switch (i) {
     case 0:
      //  Parallelise over points
      //  Calculate reflectivity....
      abelesParallelPoints(simulationXData, nLayersTot, thicks, slds, roughs,
                           simRef);

      //  Apply resolution
      //  Note: paraPoints gives an error during validation, so use
      //  single cored resolution as a workaround for now.
      if (resolution == -1.0) {
        // simRef = dataResolutionPollyParallelPoints(simXdata,simRef,simResolData,length(simXdata));
        dataResolutionPolly(simulationXData, simRef, simResolData,
                            static_cast<real_T>(simulationXData.size(0)), r);
        b_loop_ub = r.size(0);
        for (i = 0; i < b_loop_ub; i++) {
          simulation[i + simulation.size(0)] = r[i];
        }
      } else {
        // simRef = resolutionPollyParallelPoints(simXdata,simRef,res,length(simXdata));
        resolutionPolly(simulationXData, simRef, resolution, static_cast<real_T>
                        (simulationXData.size(0)), r);
        b_loop_ub = r.size(0);
        for (i = 0; i < b_loop_ub; i++) {
          simulation[i + simulation.size(0)] = r[i];
        }
      }
      break;

     default:
      //  Single cored over points
      //  Calculate reflectivity.....
      abelesSingle(simulationXData, nLayersTot, thicks, slds, roughs, simRef);

      //  Apply resolution correction...
      if (resolution == -1.0) {
        dataResolutionPolly(simulationXData, simRef, simResolData, static_cast<
                            real_T>(simulationXData.size(0)), r);
        b_loop_ub = r.size(0);
        for (i = 0; i < b_loop_ub; i++) {
          simulation[i + simulation.size(0)] = r[i];
        }
      } else {
        resolutionPolly(simulationXData, simRef, resolution, static_cast<real_T>
                        (simulationXData.size(0)), r);
        b_loop_ub = r.size(0);
        for (i = 0; i < b_loop_ub; i++) {
          simulation[i + simulation.size(0)] = r[i];
        }
      }
      break;
    }

    if (dataIndices[0] > dataIndices[1]) {
      i = 0;
      loop_ub = 0;
    } else {
      i = static_cast<int32_T>(dataIndices[0]) - 1;
      loop_ub = static_cast<int32_T>(dataIndices[1]);
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
