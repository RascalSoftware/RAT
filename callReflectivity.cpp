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
#include "gaussianConvolution.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"

// Function Declarations
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::
    array<double, 1U> &in2, const ::coder::array<double, 1U> &in3, const ::coder::
    array<double, 2U> &in4);
}

// Function Definitions
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::
    array<double, 1U> &in2, const ::coder::array<double, 1U> &in3, const ::coder::
    array<double, 2U> &in4)
  {
    ::coder::array<double, 1U> b_in4;
    int loop_ub;
    int stride_0_0;
    int stride_1_0;
    if (in2.size(0) == 1) {
      loop_ub = in4.size(0);
    } else {
      loop_ub = in2.size(0);
    }

    b_in4.set_size(loop_ub);
    stride_0_0 = (in4.size(0) != 1);
    stride_1_0 = (in2.size(0) != 1);
    for (int i{0}; i < loop_ub; i++) {
      b_in4[i] = in4[i * stride_0_0 + in4.size(0)] * in2[i * stride_1_0];
    }

    gaussianConvolution(in2, in3, in2, b_in4, in1);
  }

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
    if (resolution.size(0) == simulationXData.size(0)) {
      b_resolution.set_size(resolution.size(0));
      loop_ub_tmp = resolution.size(0);
      for (i = 0; i < loop_ub_tmp; i++) {
        b_resolution[i] = resolution[i + resolution.size(0)] * simulationXData[i];
      }

      gaussianConvolution(simulationXData, simRef, simulationXData, b_resolution,
                          r);
    } else {
      binary_expand_op(r, simulationXData, simRef, resolution);
    }

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
    if (resolution.size(0) == simulationXData.size(0)) {
      b_resolution.set_size(resolution.size(0));
      loop_ub_tmp = resolution.size(0);
      for (i = 0; i < loop_ub_tmp; i++) {
        b_resolution[i] = resolution[i + resolution.size(0)] * simulationXData[i];
      }

      gaussianConvolution(simulationXData, simRef, simulationXData, b_resolution,
                          r);
    } else {
      binary_expand_op(r, simulationXData, simRef, resolution);
    }

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
