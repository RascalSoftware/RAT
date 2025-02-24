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
#include "resolutionPolly.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void callReflectivity(double bulkIn, double bulkOut, const ::coder::array<
                        double, 1U> &simulationXData, const double dataIndices[2],
                        const double repeatLayers[2], ::coder::array<double, 2U>
                        &layers, double ssubs, const ::coder::array<double, 2U>
                        &resolution, const char parallel_data[], const int
                        parallel_size[2], boolean_T useImaginary, ::coder::array<
                        double, 2U> &reflectivity, ::coder::array<double, 2U>
                        &simulation)
  {
    ::coder::array<creal_T, 1U> slds;
    ::coder::array<double, 1U> b_resolution;
    ::coder::array<double, 1U> r;
    ::coder::array<double, 1U> roughs;
    ::coder::array<double, 1U> simRef;
    ::coder::array<double, 1U> thicks;
    double nLayersTot;
    double nRepeats;
    int i;
    int i1;
    unsigned int layerCount;
    int loop_ub_tmp;
    if (repeatLayers[0] != 0.0) {
      nRepeats = repeatLayers[1];
    } else {
      nRepeats = 1.0;
    }

    //  Build the input arrays for thick, sld and rough
    if (layers.size(0) == 0) {
      //  No layers defined. Make a zeros dummy zero layer
      layers.set_size(1, 3);
      layers[0] = 0.0;
      layers[layers.size(0)] = bulkIn;
      layers[layers.size(0) * 2] = 0.0;
    }

    //  Number of layers (including repeats)
    nLayersTot = static_cast<double>(layers.size(0)) * nRepeats + 2.0;

    //  Make arrays for thick, sld, rough
    loop_ub_tmp = static_cast<int>(nLayersTot);
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
    i = static_cast<int>(nRepeats);
    for (int m{0}; m < i; m++) {
      i1 = layers.size(0);
      for (int n{0}; n < i1; n++) {
        loop_ub_tmp = static_cast<int>(layerCount + n) - 1;
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
    simulation.set_size(simulationXData.size(0), 2);
    loop_ub_tmp = simulationXData.size(0);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        simulation[i1 + simulation.size(0) * i] = 0.0;
      }
    }

    loop_ub_tmp = simulationXData.size(0);
    for (i = 0; i < loop_ub_tmp; i++) {
      simulation[i] = simulationXData[i];
    }

    if (coder::internal::q_strcmp(parallel_data, parallel_size)) {
      i = 0;
    } else {
      i = -1;
    }

    switch (i) {
     case 0:
      //  Parallelise over points
      //  Calculate reflectivity
      abelesParallelPoints(simulationXData, nLayersTot, thicks, slds, roughs,
                           simRef);
      break;

     default:
      //  Calculate reflectivity
      abelesSingle(simulationXData, nLayersTot, thicks, slds, roughs, simRef);
      break;
    }

    //  Apply resolution correction
    loop_ub_tmp = resolution.size(0);
    b_resolution.set_size(resolution.size(0));
    for (i = 0; i < loop_ub_tmp; i++) {
      b_resolution[i] = resolution[i + resolution.size(0)];
    }

    resolutionPolly(simulationXData, simRef, b_resolution, static_cast<double>
                    (simulationXData.size(0)), r);
    loop_ub_tmp = r.size(0);
    for (i = 0; i < loop_ub_tmp; i++) {
      simulation[i + simulation.size(0)] = r[i];
    }

    if (dataIndices[0] > dataIndices[1]) {
      i = 0;
      i1 = 0;
    } else {
      i = static_cast<int>(dataIndices[0]) - 1;
      i1 = static_cast<int>(dataIndices[1]);
    }

    loop_ub_tmp = i1 - i;
    reflectivity.set_size(loop_ub_tmp, 2);
    for (i1 = 0; i1 < 2; i1++) {
      for (int i2{0}; i2 < loop_ub_tmp; i2++) {
        reflectivity[i2 + reflectivity.size(0) * i1] = simulation[(i + i2) +
          simulation.size(0) * i1];
      }
    }
  }
}

// End of code generation (callReflectivity.cpp)
