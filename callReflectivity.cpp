//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
                        double nRepeats, ::coder::array<double, 2U> &layers,
                        double ssubs, const ::coder::array<double, 2U>
                        &resolution, const char parallel_data[], const int
                        parallel_size[2], ::coder::array<double, 2U>
                        &reflectivity, ::coder::array<double, 2U> &simulation)
  {
    ::coder::array<creal_T, 1U> slds;
    ::coder::array<double, 1U> b_resolution;
    ::coder::array<double, 1U> r;
    ::coder::array<double, 1U> roughnesses;
    ::coder::array<double, 1U> simRef;
    ::coder::array<double, 1U> thicknesses;
    double nLayersTot;
    int i;
    int i1;
    unsigned int layerCount;
    int loop_ub_tmp;

    //  Build the input arrays for thick, sld and rough
    if ((layers.size(0) == 0) || (layers.size(1) == 0)) {
      //  No layers defined. Make a zeros dummy zero layer
      layers.set_size(1, 4);
      layers[0] = 0.0;
      layers[layers.size(0)] = bulkIn;
      layers[layers.size(0) * 2] = 0.0;
      layers[layers.size(0) * 3] = 0.0;
    }

    //  Number of layers (including repeats)
    nLayersTot = static_cast<double>(layers.size(0)) * nRepeats + 2.0;

    //  Make arrays for thick, sld, rough
    loop_ub_tmp = static_cast<int>(nLayersTot);
    thicknesses.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      thicknesses[i] = 0.0;
    }

    slds.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      slds[i].re = 0.0;
      slds[i].im = 0.0;
    }

    roughnesses.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      roughnesses[i] = 0.0;
    }

    //  Populate the d,rho,sig arrays...
    layerCount = 2U;
    i = static_cast<int>(nRepeats);
    for (int m{0}; m < i; m++) {
      i1 = layers.size(0);
      for (int n{0}; n < i1; n++) {
        loop_ub_tmp = static_cast<int>(layerCount + static_cast<unsigned int>(n))
          - 1;
        thicknesses[loop_ub_tmp] = layers[n];
        slds[loop_ub_tmp].re = layers[n + layers.size(0)];
        slds[loop_ub_tmp].im = layers[n + layers.size(0) * 2];
        roughnesses[loop_ub_tmp] = layers[n + layers.size(0) * 3];
      }

      layerCount += static_cast<unsigned int>(layers.size(0));
    }

    //  Add the air and substrate parameters
    slds[0].re = bulkIn;
    slds[0].im = 2.2204460492503131E-16;
    slds[slds.size(0) - 1].re = bulkOut;
    slds[slds.size(0) - 1].im = 2.2204460492503131E-16;
    roughnesses[roughnesses.size(0) - 1] = ssubs;
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

    if (coder::internal::r_strcmp(parallel_data, parallel_size)) {
      i = 0;
    } else {
      i = -1;
    }

    if (i == 0) {
      //  Parallelise over points
      //  Calculate reflectivity
      abelesParallelPoints(simulationXData, nLayersTot, thicknesses, slds,
                           roughnesses, simRef);
    } else {
      //  Calculate reflectivity
      abelesSingle(simulationXData, nLayersTot, thicknesses, slds, roughnesses,
                   simRef);
    }

    //  Apply resolution correction
    b_resolution.set_size(resolution.size(0));
    loop_ub_tmp = resolution.size(0);
    for (i = 0; i < loop_ub_tmp; i++) {
      b_resolution[i] = resolution[i + resolution.size(0)];
    }

    resolutionPolly(simulationXData, simRef, b_resolution, static_cast<double>
                    (simulationXData.size(0)), r);
    loop_ub_tmp = simulation.size(0);
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

  void callReflectivity(double bulkIn, double bulkOut, const ::coder::array<
                        double, 1U> &simulationXData, const double dataIndices[2],
                        ::coder::array<double, 2U> &layers, double ssubs, const ::
                        coder::array<double, 2U> &resolution, const char
                        parallel_data[], const int parallel_size[2], ::coder::
                        array<double, 2U> &reflectivity, ::coder::array<double,
                        2U> &simulation)
  {
    ::coder::array<creal_T, 1U> slds;
    ::coder::array<double, 1U> b_resolution;
    ::coder::array<double, 1U> r;
    ::coder::array<double, 1U> roughnesses;
    ::coder::array<double, 1U> simRef;
    ::coder::array<double, 1U> thicknesses;
    int i;
    int i1;
    int loop_ub_tmp;

    //  Build the input arrays for thick, sld and rough
    if (layers.size(0) == 0) {
      //  No layers defined. Make a zeros dummy zero layer
      layers.set_size(1, 4);
      layers[0] = 0.0;
      layers[layers.size(0)] = bulkIn;
      layers[layers.size(0) * 2] = 0.0;
      layers[layers.size(0) * 3] = 0.0;
    }

    //  Number of layers (including repeats)
    //  Make arrays for thick, sld, rough
    thicknesses.set_size(layers.size(0) + 2);
    loop_ub_tmp = layers.size(0) + 2;
    for (i = 0; i < loop_ub_tmp; i++) {
      thicknesses[i] = 0.0;
    }

    slds.set_size(layers.size(0) + 2);
    for (i = 0; i < loop_ub_tmp; i++) {
      slds[i].re = 0.0;
      slds[i].im = 0.0;
    }

    roughnesses.set_size(layers.size(0) + 2);
    for (i = 0; i < loop_ub_tmp; i++) {
      roughnesses[i] = 0.0;
    }

    //  Populate the d,rho,sig arrays...
    i = layers.size(0);
    for (int n{0}; n < i; n++) {
      thicknesses[n + 1] = layers[n];
      slds[n + 1].re = layers[n + layers.size(0)];
      slds[n + 1].im = layers[n + layers.size(0) * 2];
      roughnesses[n + 1] = layers[n + layers.size(0) * 3];
    }

    //  Add the air and substrate parameters
    slds[0].re = bulkIn;
    slds[0].im = 2.2204460492503131E-16;
    slds[slds.size(0) - 1].re = bulkOut;
    slds[slds.size(0) - 1].im = 2.2204460492503131E-16;
    roughnesses[roughnesses.size(0) - 1] = ssubs;
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

    if (coder::internal::r_strcmp(parallel_data, parallel_size)) {
      i = 0;
    } else {
      i = -1;
    }

    if (i == 0) {
      //  Parallelise over points
      //  Calculate reflectivity
      abelesParallelPoints(simulationXData, static_cast<double>(layers.size(0))
                           + 2.0, thicknesses, slds, roughnesses, simRef);
    } else {
      //  Calculate reflectivity
      abelesSingle(simulationXData, static_cast<double>(layers.size(0)) + 2.0,
                   thicknesses, slds, roughnesses, simRef);
    }

    //  Apply resolution correction
    b_resolution.set_size(resolution.size(0));
    loop_ub_tmp = resolution.size(0);
    for (i = 0; i < loop_ub_tmp; i++) {
      b_resolution[i] = resolution[i + resolution.size(0)];
    }

    resolutionPolly(simulationXData, simRef, b_resolution, static_cast<double>
                    (simulationXData.size(0)), r);
    loop_ub_tmp = simulation.size(0);
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
