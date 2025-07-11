//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// domainsReflectivity.cpp
//
// Code generation for function 'domainsReflectivity'
//

// Include files
#include "domainsReflectivity.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "cat.h"
#include "chiSquared.h"
#include "coreCustomXYCalculation.h"
#include "coreLayersCalculation.h"
#include "extractProblemParams.h"
#include "lower.h"
#include "nullAssignment.h"
#include "processCustomFunction1.h"
#include "rt_nonfinite.h"
#include "setupCoreReflectivityCalculation.h"
#include "sprintf.h"
#include "strcmp.h"
#include "coderException.hpp"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "omp.h"

// Type Definitions
namespace RAT
{
  struct cell_wrap_62
  {
    cell_wrap_7 f1[2];
  };

  struct cell_wrap_63
  {
    cell_wrap_9 f1[2];
  };

  struct cell_wrap_64
  {
    ::coder::array<double, 2U> f1;
  };

  struct cell_wrap_65
  {
    cell_wrap_64 f1[2];
  };
}

// Function Declarations
namespace RAT
{
  namespace domainsTF
  {
    static double contrastCustomXYCalculation(double bulkIn, double bulkOut,
      double domainRatio, ::coder::array<double, 2U> &shiftedData, const ::coder::
      array<double, 1U> &simulationXData, const double dataIndices[2], const ::
      coder::array<double, 2U> &background, const ::coder::array<double, 2U>
      &resolution, const char backgroundAction_data[], const int
      backgroundAction_size[2], double nParams, const char parallel_data[],
      const int parallel_size[2], double resampleMinAngle, double
      resampleNPoints, double roughness, const ::coder::array<double, 2U>
      &contrastSld1, const ::coder::array<double, 2U> &contrastSld2, ::coder::
      array<double, 2U> &reflectivity, ::coder::array<double, 2U> &simulation,
      cell_wrap_7 sldProfile[2], cell_wrap_9 layers[2], cell_wrap_64
      resampledLayers[2]);
    static double contrastLayersCalculation(double bulkIn, double bulkOut,
      double domainRatio, ::coder::array<double, 2U> &shiftedData, const ::coder::
      array<double, 1U> &simulationXData, const double dataIndices[2], const ::
      coder::array<double, 2U> &background, const ::coder::array<double, 2U>
      &resolution, double repeatLayers, const char backgroundAction_data[],
      const int backgroundAction_size[2], double nParams, const char
      parallel_data[], const int parallel_size[2], double resampleMinAngle,
      double resampleNPoints, double resample, const char geometry_data[], const
      int geometry_size[2], double roughness, boolean_T calcSld, const ::coder::
      array<double, 2U> &contrastLayers1, const ::coder::array<double, 2U>
      &contrastLayers2, ::coder::array<double, 2U> &reflectivity, ::coder::array<
      double, 2U> &simulation, cell_wrap_7 sldProfile[2], cell_wrap_9 layers[2],
      cell_wrap_64 resampledLayers[2]);
  }
}

// Function Definitions
namespace RAT
{
  namespace domainsTF
  {
    static double contrastCustomXYCalculation(double bulkIn, double bulkOut,
      double domainRatio, ::coder::array<double, 2U> &shiftedData, const ::coder::
      array<double, 1U> &simulationXData, const double dataIndices[2], const ::
      coder::array<double, 2U> &background, const ::coder::array<double, 2U>
      &resolution, const char backgroundAction_data[], const int
      backgroundAction_size[2], double nParams, const char parallel_data[],
      const int parallel_size[2], double resampleMinAngle, double
      resampleNPoints, double roughness, const ::coder::array<double, 2U>
      &contrastSld1, const ::coder::array<double, 2U> &contrastSld2, ::coder::
      array<double, 2U> &reflectivity, ::coder::array<double, 2U> &simulation,
      cell_wrap_7 sldProfile[2], cell_wrap_9 layers[2], cell_wrap_64
      resampledLayers[2])
    {
      ::coder::array<double, 2U> a__4;
      ::coder::array<double, 2U> reflectivity1;
      ::coder::array<double, 2U> reflectivity2;
      ::coder::array<double, 2U> simulation1;
      ::coder::array<double, 2U> simulation2;
      cell_wrap_64 r2;
      cell_wrap_64 r5;
      cell_wrap_7 r;
      cell_wrap_7 r3;
      cell_wrap_9 r1;
      cell_wrap_9 r4;
      double chi;
      int loop_ub;

      //  Call the core custom XY calculation once for each domain
      a__4.set_size(shiftedData.size(0), 3);
      loop_ub = shiftedData.size(0);
      for (int i{0}; i < 3; i++) {
        for (int i1{0}; i1 < loop_ub; i1++) {
          a__4[i1 + a__4.size(0) * i] = shiftedData[i1 + shiftedData.size(0) * i];
        }
      }

      coreCustomXYCalculation(bulkIn, bulkOut, a__4, simulationXData,
        dataIndices, background, resolution, backgroundAction_data,
        backgroundAction_size, parallel_data, parallel_size, resampleMinAngle,
        resampleNPoints, roughness, contrastSld1, nParams, reflectivity1,
        simulation1, r.f1, r1.f1, r2.f1);
      coreCustomXYCalculation(bulkIn, bulkOut, shiftedData, simulationXData,
        dataIndices, background, resolution, backgroundAction_data,
        backgroundAction_size, parallel_data, parallel_size, resampleMinAngle,
        resampleNPoints, roughness, contrastSld2, nParams, reflectivity2,
        simulation2, r3.f1, r4.f1, r5.f1);

      //  Calculate the average reflectivities
      //  Calculates the averaged reflectivity for domains samples (incoherent
      //  sum)
      if (reflectivity1.size(0) == reflectivity2.size(0)) {
        reflectivity.set_size(reflectivity1.size(0), 2);
        loop_ub = reflectivity1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          reflectivity[i] = reflectivity1[i];
          reflectivity[i + reflectivity.size(0)] = domainRatio * reflectivity1[i
            + reflectivity1.size(0)] + (1.0 - domainRatio) * reflectivity2[i +
            reflectivity2.size(0)];
        }
      } else {
        binary_expand_op(reflectivity, reflectivity1, domainRatio, reflectivity2);
      }

      if (simulation1.size(0) == simulation2.size(0)) {
        simulation.set_size(simulation1.size(0), 2);
        loop_ub = simulation1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          simulation[i] = simulation1[i];
          simulation[i + simulation.size(0)] = domainRatio * simulation1[i +
            simulation1.size(0)] + (1.0 - domainRatio) * simulation2[i +
            simulation2.size(0)];
        }
      } else {
        binary_expand_op(simulation, simulation1, domainRatio, simulation2);
      }

      //  Get an overall chi-squared for the new averaged curve
      chi = chiSquared(shiftedData, reflectivity, nParams);

      //  Store returned values for this contrast in the output arrays
      sldProfile[0] = r;
      sldProfile[1] = r3;
      layers[0] = r1;
      layers[1] = r4;
      resampledLayers[0] = r2;
      resampledLayers[1] = r5;
      return chi;
    }

    static double contrastLayersCalculation(double bulkIn, double bulkOut,
      double domainRatio, ::coder::array<double, 2U> &shiftedData, const ::coder::
      array<double, 1U> &simulationXData, const double dataIndices[2], const ::
      coder::array<double, 2U> &background, const ::coder::array<double, 2U>
      &resolution, double repeatLayers, const char backgroundAction_data[],
      const int backgroundAction_size[2], double nParams, const char
      parallel_data[], const int parallel_size[2], double resampleMinAngle,
      double resampleNPoints, double resample, const char geometry_data[], const
      int geometry_size[2], double roughness, boolean_T calcSld, const ::coder::
      array<double, 2U> &contrastLayers1, const ::coder::array<double, 2U>
      &contrastLayers2, ::coder::array<double, 2U> &reflectivity, ::coder::array<
      double, 2U> &simulation, cell_wrap_7 sldProfile[2], cell_wrap_9 layers[2],
      cell_wrap_64 resampledLayers[2])
    {
      ::coder::array<double, 2U> a__1;
      ::coder::array<double, 2U> reflectivity1;
      ::coder::array<double, 2U> reflectivity2;
      ::coder::array<double, 2U> simulation1;
      ::coder::array<double, 2U> simulation2;
      cell_wrap_64 r2;
      cell_wrap_64 r5;
      cell_wrap_7 r;
      cell_wrap_7 r3;
      cell_wrap_9 r1;
      cell_wrap_9 r4;
      double chi;
      int loop_ub;

      //  Call the core layers calculation once for each domain
      a__1.set_size(shiftedData.size(0), 3);
      loop_ub = shiftedData.size(0);
      for (int i{0}; i < 3; i++) {
        for (int i1{0}; i1 < loop_ub; i1++) {
          a__1[i1 + a__1.size(0) * i] = shiftedData[i1 + shiftedData.size(0) * i];
        }
      }

      coreLayersCalculation(contrastLayers1, roughness, geometry_data,
                            geometry_size, bulkIn, bulkOut, resample, calcSld,
                            a__1, simulationXData, dataIndices, repeatLayers,
                            background, resolution, backgroundAction_data,
                            backgroundAction_size, parallel_data, parallel_size,
                            resampleMinAngle, resampleNPoints, nParams,
                            reflectivity1, simulation1, r.f1, r1.f1, r2.f1);
      coreLayersCalculation(contrastLayers2, roughness, geometry_data,
                            geometry_size, bulkIn, bulkOut, resample, calcSld,
                            shiftedData, simulationXData, dataIndices,
                            repeatLayers, background, resolution,
                            backgroundAction_data, backgroundAction_size,
                            parallel_data, parallel_size, resampleMinAngle,
                            resampleNPoints, nParams, reflectivity2, simulation2,
                            r3.f1, r4.f1, r5.f1);

      //  Calculate the average reflectivities
      //  Calculates the averaged reflectivity for domains samples (incoherent
      //  sum)
      if (reflectivity1.size(0) == reflectivity2.size(0)) {
        reflectivity.set_size(reflectivity1.size(0), 2);
        loop_ub = reflectivity1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          reflectivity[i] = reflectivity1[i];
          reflectivity[i + reflectivity.size(0)] = domainRatio * reflectivity1[i
            + reflectivity1.size(0)] + (1.0 - domainRatio) * reflectivity2[i +
            reflectivity2.size(0)];
        }
      } else {
        binary_expand_op(reflectivity, reflectivity1, domainRatio, reflectivity2);
      }

      if (simulation1.size(0) == simulation2.size(0)) {
        simulation.set_size(simulation1.size(0), 2);
        loop_ub = simulation1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          simulation[i] = simulation1[i];
          simulation[i + simulation.size(0)] = domainRatio * simulation1[i +
            simulation1.size(0)] + (1.0 - domainRatio) * simulation2[i +
            simulation2.size(0)];
        }
      } else {
        binary_expand_op(simulation, simulation1, domainRatio, simulation2);
      }

      //  Get an overall chi-squared for the new averaged curve
      chi = chiSquared(shiftedData, reflectivity, nParams);

      //  Store returned values for this contrast in the output arrays
      sldProfile[0] = r;
      sldProfile[1] = r3;
      layers[0] = r1;
      layers[1] = r4;
      resampledLayers[0] = r2;
      resampledLayers[1] = r5;
      return chi;
    }

    void b_domainsReflectivity(const ProblemDefinition &problemStruct, const
      Controls *controls, ::coder::array<cell_wrap_7, 1U> &reflectivity, ::coder::
      array<cell_wrap_7, 1U> &simulation, ::coder::array<cell_wrap_8, 1U>
      &shiftedData, ::coder::array<cell_wrap_8, 1U> &backgrounds, ::coder::array<
      cell_wrap_7, 1U> &resolutions, ::coder::array<cell_wrap_7, 2U>
      &domainSldProfiles, ::coder::array<cell_wrap_9, 2U> &domainLayers, ::coder::
      array<cell_wrap_9, 2U> &domainResampledLayers, ::coder::array<double, 1U>
      &qzshifts, ::coder::array<double, 1U> &scalefactors, ::coder::array<double,
      1U> &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::coder::array<double,
      1U> &subRoughs, ::coder::array<double, 1U> &chis)
    {
      ::coder::array<cell_wrap_1, 2U> data;
      ::coder::array<cell_wrap_10, 2U> contrastBackgroundActions;
      ::coder::array<cell_wrap_10, 2U> contrastBackgroundTypes;
      ::coder::array<cell_wrap_10, 2U> contrastResolutionTypes;
      ::coder::array<cell_wrap_10, 2U> customFiles;
      ::coder::array<cell_wrap_2, 2U> dataLimits;
      ::coder::array<cell_wrap_2, 2U> simulationLimits;
      ::coder::array<cell_wrap_44, 2U> contrastBackgroundIndices;
      ::coder::array<cell_wrap_51, 2U> layerValues;
      ::coder::array<cell_wrap_62, 1U> sldProfiles;
      ::coder::array<cell_wrap_63, 1U> layers;
      ::coder::array<cell_wrap_65, 1U> resampledLayers;
      ::coder::array<cell_wrap_9, 2U> contrastResolutionIndices;
      ::coder::array<cell_wrap_9, 2U> domainContrastLayers;
      ::coder::array<cell_wrap_9, 2U> inputContrastLayers;
      ::coder::array<cell_wrap_9, 2U> layersDetails;
      ::coder::array<cell_wrap_9, 1U> contrastLayers1;
      ::coder::array<cell_wrap_9, 1U> contrastLayers2;
      ::coder::array<cell_wrap_9, 1U> contrastSlds1;
      ::coder::array<cell_wrap_9, 1U> contrastSlds2;
      ::coder::array<double, 2U> backgroundParamValues;
      ::coder::array<double, 2U> contrastCustomFiles;
      ::coder::array<double, 2U> contrastDomainRatioIndices;
      ::coder::array<double, 2U> dataPresent;
      ::coder::array<double, 2U> domainRatioValues;
      ::coder::array<double, 2U> paramValues;
      ::coder::array<double, 2U> r1;
      ::coder::array<double, 2U> repeatLayers;
      ::coder::array<double, 2U> resample;
      ::coder::array<double, 2U> resolutionParamValues;
      ::coder::array<double, 1U> b_simulationXData;
      ::coder::array<double, 1U> domainRatios;
      ::coder::array<double, 1U> simulationXData;
      ::coder::array<char, 2U> r;
      double b_dataIndices[2];
      double dataIndices[2];
      double dv2[2];
      double dv3[2];
      double d;
      double nParams;
      double numSimulationPoints;
      double numberOfContrasts;
      double resampleMinAngle;
      double resampleNPoints;
      int geometry_size[2];
      int iv3[2];
      int iv4[2];
      int iv5[2];
      int iv6[2];
      int switch_expression_size[2];
      int b_index;
      int i;
      int i1;
      int loop_ub;
      char geometry_data[10000];
      char switch_expression_data[10000];
      boolean_T calcSld;
      boolean_T useImaginary;

      //  This is the main domains reflectivity calculation.
      //  It extracts the required parameters for the contrasts
      //  from the input arrays, then passes the main calculation to
      //  the appropriate core calculation, which carries out the calculation
      //  itself. The core layers calculation is common for both standard and
      //  custom layers, with an additional core custom XY calculation.
      //  Extract parameters from problemStruct
      numberOfContrasts = extractProblemParams(problemStruct, geometry_data,
        geometry_size, contrastBackgroundIndices, contrastResolutionIndices,
        contrastDomainRatioIndices, backgroundParamValues, resolutionParamValues,
        qzshifts, scalefactors, bulkIns, bulkOuts, domainRatioValues,
        dataPresent, paramValues, resample, contrastBackgroundTypes,
        contrastBackgroundActions, contrastResolutionTypes, contrastCustomFiles,
        repeatLayers, data, dataLimits, simulationLimits, inputContrastLayers,
        layersDetails, customFiles, domainContrastLayers, nParams, useImaginary);
      calcSld = controls->calcSldDuringFit;
      numSimulationPoints = controls->numSimulationPoints;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Allocate the memory for the output arrays before the main loop
      i = static_cast<int>(numberOfContrasts);
      i1 = static_cast<int>(numberOfContrasts);
      shiftedData.set_size(i);
      backgrounds.set_size(i);
      resolutions.set_size(i);
      contrastLayers1.set_size(i);
      contrastLayers2.set_size(i);
      contrastSlds1.set_size(i);
      contrastSlds2.set_size(i);
      domainLayers.set_size(i, 2);
      domainResampledLayers.set_size(i, 2);
      domainRatios.set_size(i);
      for (int b_i{0}; b_i < i; b_i++) {
        shiftedData[b_i].f1.set_size(1, 3);
        backgrounds[b_i].f1.set_size(1, 3);
        shiftedData[b_i].f1[0] = 0.0;
        backgrounds[b_i].f1[0] = 0.0;
        shiftedData[b_i].f1[shiftedData[b_i].f1.size(0)] = 0.0;
        backgrounds[b_i].f1[backgrounds[b_i].f1.size(0)] = 0.0;
        shiftedData[b_i].f1[shiftedData[b_i].f1.size(0) * 2] = 0.0;
        backgrounds[b_i].f1[backgrounds[b_i].f1.size(0) * 2] = 0.0;
        resolutions[b_i].f1.set_size(1, 2);
        resolutions[b_i].f1[0] = 0.0;
        resolutions[b_i].f1[resolutions[b_i].f1.size(0)] = 0.0;
        contrastLayers1[b_i].f1.set_size(1, 6);
        contrastLayers2[b_i].f1.set_size(1, 6);
        for (int i2{0}; i2 < 6; i2++) {
          contrastLayers1[b_i].f1[contrastLayers1[b_i].f1.size(0) * i2] = 0.0;
          contrastLayers2[b_i].f1[contrastLayers2[b_i].f1.size(0) * i2] = 0.0;
        }

        contrastSlds1[b_i].f1.set_size(1, 3);
        contrastSlds2[b_i].f1.set_size(1, 3);
        contrastSlds1[b_i].f1[0] = 0.0;
        contrastSlds2[b_i].f1[0] = 0.0;
        contrastSlds1[b_i].f1[contrastSlds1[b_i].f1.size(0)] = 0.0;
        contrastSlds2[b_i].f1[contrastSlds2[b_i].f1.size(0)] = 0.0;
        contrastSlds1[b_i].f1[contrastSlds1[b_i].f1.size(0) * 2] = 0.0;
        contrastSlds2[b_i].f1[contrastSlds2[b_i].f1.size(0) * 2] = 0.0;
        domainLayers[b_i].f1.set_size(1, 6);
        domainLayers[b_i + domainLayers.size(0)].f1.set_size(1, 6);
        domainResampledLayers[b_i].f1.set_size(1, 6);
        domainResampledLayers[b_i + domainResampledLayers.size(0)].f1.set_size(1,
          6);
        for (int i2{0}; i2 < 6; i2++) {
          domainLayers[b_i].f1[domainLayers[b_i].f1.size(0) * i2] = 0.0;
          domainLayers[b_i + domainLayers.size(0)].f1[domainLayers[b_i +
            domainLayers.size(0)].f1.size(0) * i2] = 0.0;
          domainResampledLayers[b_i].f1[domainResampledLayers[b_i].f1.size(0) *
            i2] = 0.0;
          domainResampledLayers[b_i + domainResampledLayers.size(0)]
            .f1[domainResampledLayers[b_i + domainResampledLayers.size(0)].
            f1.size(0) * i2] = 0.0;
        }

        //  Get the domain ratio for this contrast
        domainRatios[b_i] = domainRatioValues[static_cast<int>
          (contrastDomainRatioIndices[b_i]) - 1];
      }

      //  Obtain model specific parameters
      coder::lower(problemStruct.modelType.data, problemStruct.modelType.size,
                   switch_expression_data, switch_expression_size);
      if (coder::internal::l_strcmp(switch_expression_data,
           switch_expression_size)) {
        b_index = 0;
      } else if (coder::internal::n_strcmp(switch_expression_data,
                  switch_expression_size)) {
        b_index = 1;
      } else if (coder::internal::o_strcmp(switch_expression_data,
                  switch_expression_size)) {
        b_index = 2;
      } else {
        b_index = -1;
      }

      switch (b_index) {
       case 0:
        //  First we need to allocate the absolute values of the input
        //  parameters to all the layers in the layers list. This only
        //  needs to be done once, and so is done outside the contrasts
        //  loop
        allocateParamsToLayers(paramValues, layersDetails, layerValues);
        subRoughs.set_size(i);
        contrastLayers1.set_size(i);
        contrastLayers2.set_size(i);
        for (int b_i{0}; b_i < i; b_i++) {
          //  Substrate roughness is always first parameter for
          //  standard layers
          subRoughs[b_i] = paramValues[0];

          //  Also need to determine which layers from the overall
          //  layers list are required for this contrast, and put them
          //  in the correct order according to geometry. We run it
          //  twice, once for each domain
          allocateLayersForContrast(domainContrastLayers[static_cast<int>
            (inputContrastLayers[b_i].f1[0]) - 1].f1, layerValues, r1);
          contrastLayers1[b_i].f1.set_size(r1.size(0), 6);
          loop_ub = r1.size(0);
          for (int i2{0}; i2 < 6; i2++) {
            for (b_index = 0; b_index < loop_ub; b_index++) {
              contrastLayers1[b_i].f1[b_index + contrastLayers1[b_i].f1.size(0) *
                i2] = r1[b_index + r1.size(0) * i2];
            }
          }

          allocateLayersForContrast(domainContrastLayers[static_cast<int>
            (inputContrastLayers[b_i].f1[1]) - 1].f1, layerValues, r1);
          contrastLayers2[b_i].f1.set_size(r1.size(0), 6);
          loop_ub = r1.size(0);
          for (int i2{0}; i2 < 6; i2++) {
            for (b_index = 0; b_index < loop_ub; b_index++) {
              contrastLayers2[b_i].f1[b_index + contrastLayers2[b_i].f1.size(0) *
                i2] = r1[b_index + r1.size(0) * i2];
            }
          }
        }
        break;

       case 1:
        processCustomFunction(bulkIns, bulkOuts, contrastCustomFiles,
                              numberOfContrasts, customFiles, paramValues,
                              useImaginary, contrastLayers1, contrastLayers2,
                              subRoughs);
        break;

       case 2:
        b_processCustomFunction(bulkIns, bulkOuts, contrastCustomFiles,
          numberOfContrasts, customFiles, paramValues, useImaginary,
          contrastSlds1, contrastSlds2, subRoughs);
        break;

       default:
        //  Ensures a proper exception is thrown in the generated C++ code.
        //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
        //  and other parameters if message is a formatspec.
        //
        //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
        //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
        coder::b_sprintf(problemStruct.modelType.data,
                         problemStruct.modelType.size, r);
        coderException(1.0, &r[0]);
        break;
      }

      //  Run the core calculation for each contrast
      if (coder::internal::c_strcmp(problemStruct.modelType.data,
           problemStruct.modelType.size)) {
        if (coder::internal::m_strcmp(controls->parallel.data,
             controls->parallel.size)) {
          layers.set_size(i);
          resampledLayers.set_size(i);
          chis.set_size(i);
          sldProfiles.set_size(i);
          simulation.set_size(i);
          reflectivity.set_size(i);
          domainSldProfiles.set_size(i, 2);
          b_index = static_cast<int>(numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(simulationXData,d,b_dataIndices,iv3,iv4,iv5,iv6,dv2,dv3)

          for (int c_i = 0; c_i <= b_index; c_i++) {
            iv3[0] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[0];
            iv3[1] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[1];
            iv4[0] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[0];
            iv4[1] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[1];
            iv5[0] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[0];
            iv5[1] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[1];
            iv6[0] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[0];
            iv6[1] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[1];
            dv2[0] = dataLimits[c_i].f1[0];
            dv2[1] = dataLimits[c_i].f1[1];
            dv3[0] = simulationLimits[c_i].f1[0];
            dv3[1] = simulationLimits[c_i].f1[1];
            setupCoreReflectivityCalculation((const double *)
              contrastBackgroundIndices[c_i].f1.data(), iv3, (const double *)
              contrastResolutionIndices[c_i].f1.data(), iv4,
              backgroundParamValues, resolutionParamValues, (const char *)
              contrastBackgroundTypes[c_i].f1.data(), iv5, (const char *)
              contrastResolutionTypes[c_i].f1.data(), iv6, customFiles,
              scalefactors[c_i], dataPresent[c_i], data[c_i].f1, dv2, dv3,
              numSimulationPoints, backgrounds[c_i].f1, resolutions[c_i].f1,
              shiftedData[c_i].f1, simulationXData, b_dataIndices);
            iv3[0] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[0];
            iv3[1] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[1];
            d = contrastCustomXYCalculation(bulkIns[c_i], bulkOuts[c_i],
              domainRatios[c_i], shiftedData[c_i].f1, simulationXData,
              b_dataIndices, backgrounds[c_i].f1, resolutions[c_i].f1, (const
              char *)contrastBackgroundActions[c_i].f1.data(), iv3, nParams,
              controls->parallel.data, controls->parallel.size, resampleMinAngle,
              resampleNPoints, subRoughs[c_i], contrastSlds1[c_i].f1,
              contrastSlds2[c_i].f1, reflectivity[c_i].f1, simulation[c_i].f1,
              sldProfiles[c_i].f1, layers[c_i].f1, resampledLayers[c_i].f1);
            chis[c_i] = d;
          }
        } else {
          layers.set_size(i);
          resampledLayers.set_size(i);
          chis.set_size(i);
          sldProfiles.set_size(i);
          simulation.set_size(i);
          reflectivity.set_size(i);
          domainSldProfiles.set_size(i, 2);
          for (int b_i{0}; b_i < i; b_i++) {
            double b_dv[2];
            double b_dv1[2];
            int iv[2];
            int iv1[2];
            int iv2[2];
            switch_expression_size[0] = (*(int (*)[2])
              contrastBackgroundIndices[b_i].f1.size())[0];
            switch_expression_size[1] = (*(int (*)[2])
              contrastBackgroundIndices[b_i].f1.size())[1];
            iv[0] = (*(int (*)[2])contrastResolutionIndices[b_i].f1.size())[0];
            iv[1] = (*(int (*)[2])contrastResolutionIndices[b_i].f1.size())[1];
            iv1[0] = (*(int (*)[2])contrastBackgroundTypes[b_i].f1.size())[0];
            iv1[1] = (*(int (*)[2])contrastBackgroundTypes[b_i].f1.size())[1];
            iv2[0] = (*(int (*)[2])contrastResolutionTypes[b_i].f1.size())[0];
            iv2[1] = (*(int (*)[2])contrastResolutionTypes[b_i].f1.size())[1];
            b_dv[0] = dataLimits[b_i].f1[0];
            b_dv[1] = dataLimits[b_i].f1[1];
            b_dv1[0] = simulationLimits[b_i].f1[0];
            b_dv1[1] = simulationLimits[b_i].f1[1];
            setupCoreReflectivityCalculation((const double *)
              contrastBackgroundIndices[b_i].f1.data(), switch_expression_size,
              (const double *)contrastResolutionIndices[b_i].f1.data(), iv,
              backgroundParamValues, resolutionParamValues, (const char *)
              contrastBackgroundTypes[b_i].f1.data(), iv1, (const char *)
              contrastResolutionTypes[b_i].f1.data(), iv2, customFiles,
              scalefactors[b_i], dataPresent[b_i], data[b_i].f1, b_dv, b_dv1,
              numSimulationPoints, backgrounds[b_i].f1, resolutions[b_i].f1,
              shiftedData[b_i].f1, b_simulationXData, dataIndices);
            switch_expression_size[0] = (*(int (*)[2])
              contrastBackgroundActions[b_i].f1.size())[0];
            switch_expression_size[1] = (*(int (*)[2])
              contrastBackgroundActions[b_i].f1.size())[1];
            chis[b_i] = contrastCustomXYCalculation(bulkIns[b_i], bulkOuts[b_i],
              domainRatios[b_i], shiftedData[b_i].f1, b_simulationXData,
              dataIndices, backgrounds[b_i].f1, resolutions[b_i].f1, (const char
              *)contrastBackgroundActions[b_i].f1.data(), switch_expression_size,
              nParams, controls->parallel.data, controls->parallel.size,
              resampleMinAngle, resampleNPoints, subRoughs[b_i],
              contrastSlds1[b_i].f1, contrastSlds2[b_i].f1, reflectivity[b_i].f1,
              simulation[b_i].f1, sldProfiles[b_i].f1, layers[b_i].f1,
              resampledLayers[b_i].f1);
          }
        }
      } else if (coder::internal::m_strcmp(controls->parallel.data,
                  controls->parallel.size)) {
        layers.set_size(i);
        resampledLayers.set_size(i);
        chis.set_size(i);
        sldProfiles.set_size(i);
        simulation.set_size(i);
        reflectivity.set_size(i);
        domainSldProfiles.set_size(i, 2);
        b_index = static_cast<int>(numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(simulationXData,d,b_dataIndices,iv3,iv4,iv5,iv6,dv2,dv3)

        for (int c_i = 0; c_i <= b_index; c_i++) {
          iv3[0] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[0];
          iv3[1] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[1];
          iv4[0] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[0];
          iv4[1] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[1];
          iv5[0] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[0];
          iv5[1] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[1];
          iv6[0] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[0];
          iv6[1] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[1];
          dv2[0] = dataLimits[c_i].f1[0];
          dv2[1] = dataLimits[c_i].f1[1];
          dv3[0] = simulationLimits[c_i].f1[0];
          dv3[1] = simulationLimits[c_i].f1[1];
          setupCoreReflectivityCalculation((const double *)
            contrastBackgroundIndices[c_i].f1.data(), iv3, (const double *)
            contrastResolutionIndices[c_i].f1.data(), iv4, backgroundParamValues,
            resolutionParamValues, (const char *)contrastBackgroundTypes[c_i].
            f1.data(), iv5, (const char *)contrastResolutionTypes[c_i].f1.data(),
            iv6, customFiles, scalefactors[c_i], dataPresent[c_i], data[c_i].f1,
            dv2, dv3, numSimulationPoints, backgrounds[c_i].f1, resolutions[c_i]
            .f1, shiftedData[c_i].f1, simulationXData, b_dataIndices);
          iv3[0] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[0];
          iv3[1] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[1];
          d = contrastLayersCalculation(bulkIns[c_i], bulkOuts[c_i],
            domainRatios[c_i], shiftedData[c_i].f1, simulationXData,
            b_dataIndices, backgrounds[c_i].f1, resolutions[c_i].f1,
            repeatLayers[c_i], (const char *)contrastBackgroundActions[c_i].
            f1.data(), iv3, nParams, controls->parallel.data,
            controls->parallel.size, resampleMinAngle, resampleNPoints,
            resample[c_i], geometry_data, geometry_size, subRoughs[c_i], calcSld,
            contrastLayers1[c_i].f1, contrastLayers2[c_i].f1, reflectivity[c_i].
            f1, simulation[c_i].f1, sldProfiles[c_i].f1, layers[c_i].f1,
            resampledLayers[c_i].f1);
          chis[c_i] = d;
        }
      } else {
        layers.set_size(i);
        resampledLayers.set_size(i);
        chis.set_size(i);
        sldProfiles.set_size(i);
        simulation.set_size(i);
        reflectivity.set_size(i);
        domainSldProfiles.set_size(i, 2);
        for (int b_i{0}; b_i < i; b_i++) {
          double b_dv[2];
          double b_dv1[2];
          int iv[2];
          int iv1[2];
          int iv2[2];
          switch_expression_size[0] = (*(int (*)[2])
            contrastBackgroundIndices[b_i].f1.size())[0];
          switch_expression_size[1] = (*(int (*)[2])
            contrastBackgroundIndices[b_i].f1.size())[1];
          iv[0] = (*(int (*)[2])contrastResolutionIndices[b_i].f1.size())[0];
          iv[1] = (*(int (*)[2])contrastResolutionIndices[b_i].f1.size())[1];
          iv1[0] = (*(int (*)[2])contrastBackgroundTypes[b_i].f1.size())[0];
          iv1[1] = (*(int (*)[2])contrastBackgroundTypes[b_i].f1.size())[1];
          iv2[0] = (*(int (*)[2])contrastResolutionTypes[b_i].f1.size())[0];
          iv2[1] = (*(int (*)[2])contrastResolutionTypes[b_i].f1.size())[1];
          b_dv[0] = dataLimits[b_i].f1[0];
          b_dv[1] = dataLimits[b_i].f1[1];
          b_dv1[0] = simulationLimits[b_i].f1[0];
          b_dv1[1] = simulationLimits[b_i].f1[1];
          setupCoreReflectivityCalculation((const double *)
            contrastBackgroundIndices[b_i].f1.data(), switch_expression_size, (
            const double *)contrastResolutionIndices[b_i].f1.data(), iv,
            backgroundParamValues, resolutionParamValues, (const char *)
            contrastBackgroundTypes[b_i].f1.data(), iv1, (const char *)
            contrastResolutionTypes[b_i].f1.data(), iv2, customFiles,
            scalefactors[b_i], dataPresent[b_i], data[b_i].f1, b_dv, b_dv1,
            numSimulationPoints, backgrounds[b_i].f1, resolutions[b_i].f1,
            shiftedData[b_i].f1, b_simulationXData, dataIndices);
          switch_expression_size[0] = (*(int (*)[2])
            contrastBackgroundActions[b_i].f1.size())[0];
          switch_expression_size[1] = (*(int (*)[2])
            contrastBackgroundActions[b_i].f1.size())[1];
          chis[b_i] = contrastLayersCalculation(bulkIns[b_i], bulkOuts[b_i],
            domainRatios[b_i], shiftedData[b_i].f1, b_simulationXData,
            dataIndices, backgrounds[b_i].f1, resolutions[b_i].f1,
            repeatLayers[b_i], (const char *)contrastBackgroundActions[b_i].
            f1.data(), switch_expression_size, nParams, controls->parallel.data,
            controls->parallel.size, resampleMinAngle, resampleNPoints,
            resample[b_i], geometry_data, geometry_size, subRoughs[b_i], calcSld,
            contrastLayers1[b_i].f1, contrastLayers2[b_i].f1, reflectivity[b_i].
            f1, simulation[b_i].f1, sldProfiles[b_i].f1, layers[b_i].f1,
            resampledLayers[b_i].f1);
        }
      }

      for (int b_i{0}; b_i < i1; b_i++) {
        for (int j{0}; j < 2; j++) {
          loop_ub = sldProfiles[b_i].f1[j].f1.size(0);
          domainSldProfiles[b_i + domainSldProfiles.size(0) * j].f1.set_size
            (sldProfiles[b_i].f1[j].f1.size(0), 2);
          for (i = 0; i < 2; i++) {
            for (int i2{0}; i2 < loop_ub; i2++) {
              domainSldProfiles[b_i + domainSldProfiles.size(0) * j].f1[i2 +
                domainSldProfiles[b_i + domainSldProfiles.size(0) * j].f1.size(0)
                * i] = sldProfiles[b_i].f1[j].f1[i2 + sldProfiles[b_i].f1[j].
                f1.size(0) * i];
            }
          }

          loop_ub = layers[b_i].f1[j].f1.size(1);
          domainLayers[b_i + domainLayers.size(0) * j].f1.set_size(layers[b_i].
            f1[j].f1.size(0), layers[b_i].f1[j].f1.size(1));
          for (i = 0; i < loop_ub; i++) {
            b_index = layers[b_i].f1[j].f1.size(0);
            for (int i2{0}; i2 < b_index; i2++) {
              domainLayers[b_i + domainLayers.size(0) * j].f1[i2 +
                domainLayers[b_i + domainLayers.size(0) * j].f1.size(0) * i] =
                layers[b_i].f1[j].f1[i2 + layers[b_i].f1[j].f1.size(0) * i];
            }
          }

          loop_ub = resampledLayers[b_i].f1[j].f1.size(0);
          domainResampledLayers[b_i + domainResampledLayers.size(0) * j].
            f1.set_size(resampledLayers[b_i].f1[j].f1.size(0), 4);
          for (i = 0; i < 4; i++) {
            for (int i2{0}; i2 < loop_ub; i2++) {
              domainResampledLayers[b_i + domainResampledLayers.size(0) * j]
                .f1[i2 + domainResampledLayers[b_i + domainResampledLayers.size
                (0) * j].f1.size(0) * i] = resampledLayers[b_i].f1[j].f1[i2 +
                resampledLayers[b_i].f1[j].f1.size(0) * i];
            }
          }
        }
      }

      //  Remove dummy imaginary column if present
      if (!useImaginary) {
        for (int b_i{0}; b_i < i1; b_i++) {
          coder::internal::nullAssignment(domainLayers[b_i].f1);
          coder::internal::nullAssignment(domainResampledLayers[b_i].f1);
          coder::internal::nullAssignment(domainLayers[b_i + domainLayers.size(0)]
            .f1);
          coder::internal::nullAssignment(domainResampledLayers[b_i +
            domainResampledLayers.size(0)].f1);
        }
      }
    }

    void domainsReflectivity(const ProblemDefinition &problemStruct, const
      Controls *controls, ::coder::array<cell_wrap_7, 1U> &reflectivity, ::coder::
      array<cell_wrap_7, 1U> &simulation, ::coder::array<cell_wrap_8, 1U>
      &shiftedData, ::coder::array<cell_wrap_8, 1U> &backgrounds, ::coder::array<
      cell_wrap_7, 1U> &resolutions, ::coder::array<cell_wrap_7, 2U>
      &domainSldProfiles, ::coder::array<cell_wrap_9, 2U> &domainLayers, ::coder::
      array<cell_wrap_9, 2U> &domainResampledLayers, ::coder::array<double, 1U>
      &qzshifts, ::coder::array<double, 1U> &scalefactors, ::coder::array<double,
      1U> &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::coder::array<double,
      1U> &subRoughs, ::coder::array<double, 1U> &chis)
    {
      ::coder::array<cell_wrap_1, 2U> data;
      ::coder::array<cell_wrap_10, 2U> contrastBackgroundActions;
      ::coder::array<cell_wrap_10, 2U> contrastBackgroundTypes;
      ::coder::array<cell_wrap_10, 2U> contrastResolutionTypes;
      ::coder::array<cell_wrap_10, 2U> customFiles;
      ::coder::array<cell_wrap_2, 2U> dataLimits;
      ::coder::array<cell_wrap_2, 2U> simulationLimits;
      ::coder::array<cell_wrap_44, 2U> contrastBackgroundIndices;
      ::coder::array<cell_wrap_51, 2U> layerValues;
      ::coder::array<cell_wrap_62, 1U> sldProfiles;
      ::coder::array<cell_wrap_63, 1U> layers;
      ::coder::array<cell_wrap_65, 1U> resampledLayers;
      ::coder::array<cell_wrap_9, 2U> contrastResolutionIndices;
      ::coder::array<cell_wrap_9, 2U> domainContrastLayers;
      ::coder::array<cell_wrap_9, 2U> inputContrastLayers;
      ::coder::array<cell_wrap_9, 2U> layersDetails;
      ::coder::array<cell_wrap_9, 1U> contrastLayers1;
      ::coder::array<cell_wrap_9, 1U> contrastLayers2;
      ::coder::array<cell_wrap_9, 1U> contrastSlds1;
      ::coder::array<cell_wrap_9, 1U> contrastSlds2;
      ::coder::array<double, 2U> backgroundParamValues;
      ::coder::array<double, 2U> contrastCustomFiles;
      ::coder::array<double, 2U> contrastDomainRatioIndices;
      ::coder::array<double, 2U> dataPresent;
      ::coder::array<double, 2U> domainRatioValues;
      ::coder::array<double, 2U> paramValues;
      ::coder::array<double, 2U> r1;
      ::coder::array<double, 2U> repeatLayers;
      ::coder::array<double, 2U> resample;
      ::coder::array<double, 2U> resolutionParamValues;
      ::coder::array<double, 1U> b_simulationXData;
      ::coder::array<double, 1U> domainRatios;
      ::coder::array<double, 1U> simulationXData;
      ::coder::array<char, 2U> r;
      double b_dataIndices[2];
      double dataIndices[2];
      double dv2[2];
      double dv3[2];
      double d;
      double nParams;
      double numSimulationPoints;
      double numberOfContrasts;
      double resampleMinAngle;
      double resampleNPoints;
      int geometry_size[2];
      int iv3[2];
      int iv4[2];
      int iv5[2];
      int iv6[2];
      int switch_expression_size[2];
      int b_index;
      int i;
      int i1;
      int loop_ub;
      char geometry_data[10000];
      char switch_expression_data[10000];
      boolean_T useImaginary;

      //  This is the main domains reflectivity calculation.
      //  It extracts the required parameters for the contrasts
      //  from the input arrays, then passes the main calculation to
      //  the appropriate core calculation, which carries out the calculation
      //  itself. The core layers calculation is common for both standard and
      //  custom layers, with an additional core custom XY calculation.
      //  Extract parameters from problemStruct
      numberOfContrasts = extractProblemParams(problemStruct, geometry_data,
        geometry_size, contrastBackgroundIndices, contrastResolutionIndices,
        contrastDomainRatioIndices, backgroundParamValues, resolutionParamValues,
        qzshifts, scalefactors, bulkIns, bulkOuts, domainRatioValues,
        dataPresent, paramValues, resample, contrastBackgroundTypes,
        contrastBackgroundActions, contrastResolutionTypes, contrastCustomFiles,
        repeatLayers, data, dataLimits, simulationLimits, inputContrastLayers,
        layersDetails, customFiles, domainContrastLayers, nParams, useImaginary);
      numSimulationPoints = controls->numSimulationPoints;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Allocate the memory for the output arrays before the main loop
      i = static_cast<int>(numberOfContrasts);
      i1 = static_cast<int>(numberOfContrasts);
      shiftedData.set_size(i);
      backgrounds.set_size(i);
      resolutions.set_size(i);
      contrastLayers1.set_size(i);
      contrastLayers2.set_size(i);
      contrastSlds1.set_size(i);
      contrastSlds2.set_size(i);
      domainLayers.set_size(i, 2);
      domainResampledLayers.set_size(i, 2);
      domainRatios.set_size(i);
      for (int b_i{0}; b_i < i; b_i++) {
        shiftedData[b_i].f1.set_size(1, 3);
        backgrounds[b_i].f1.set_size(1, 3);
        shiftedData[b_i].f1[0] = 0.0;
        backgrounds[b_i].f1[0] = 0.0;
        shiftedData[b_i].f1[shiftedData[b_i].f1.size(0)] = 0.0;
        backgrounds[b_i].f1[backgrounds[b_i].f1.size(0)] = 0.0;
        shiftedData[b_i].f1[shiftedData[b_i].f1.size(0) * 2] = 0.0;
        backgrounds[b_i].f1[backgrounds[b_i].f1.size(0) * 2] = 0.0;
        resolutions[b_i].f1.set_size(1, 2);
        resolutions[b_i].f1[0] = 0.0;
        resolutions[b_i].f1[resolutions[b_i].f1.size(0)] = 0.0;
        contrastLayers1[b_i].f1.set_size(1, 6);
        contrastLayers2[b_i].f1.set_size(1, 6);
        for (int i2{0}; i2 < 6; i2++) {
          contrastLayers1[b_i].f1[contrastLayers1[b_i].f1.size(0) * i2] = 0.0;
          contrastLayers2[b_i].f1[contrastLayers2[b_i].f1.size(0) * i2] = 0.0;
        }

        contrastSlds1[b_i].f1.set_size(1, 3);
        contrastSlds2[b_i].f1.set_size(1, 3);
        contrastSlds1[b_i].f1[0] = 0.0;
        contrastSlds2[b_i].f1[0] = 0.0;
        contrastSlds1[b_i].f1[contrastSlds1[b_i].f1.size(0)] = 0.0;
        contrastSlds2[b_i].f1[contrastSlds2[b_i].f1.size(0)] = 0.0;
        contrastSlds1[b_i].f1[contrastSlds1[b_i].f1.size(0) * 2] = 0.0;
        contrastSlds2[b_i].f1[contrastSlds2[b_i].f1.size(0) * 2] = 0.0;
        domainLayers[b_i].f1.set_size(1, 6);
        domainLayers[b_i + domainLayers.size(0)].f1.set_size(1, 6);
        domainResampledLayers[b_i].f1.set_size(1, 6);
        domainResampledLayers[b_i + domainResampledLayers.size(0)].f1.set_size(1,
          6);
        for (int i2{0}; i2 < 6; i2++) {
          domainLayers[b_i].f1[domainLayers[b_i].f1.size(0) * i2] = 0.0;
          domainLayers[b_i + domainLayers.size(0)].f1[domainLayers[b_i +
            domainLayers.size(0)].f1.size(0) * i2] = 0.0;
          domainResampledLayers[b_i].f1[domainResampledLayers[b_i].f1.size(0) *
            i2] = 0.0;
          domainResampledLayers[b_i + domainResampledLayers.size(0)]
            .f1[domainResampledLayers[b_i + domainResampledLayers.size(0)].
            f1.size(0) * i2] = 0.0;
        }

        //  Get the domain ratio for this contrast
        domainRatios[b_i] = domainRatioValues[static_cast<int>
          (contrastDomainRatioIndices[b_i]) - 1];
      }

      //  Obtain model specific parameters
      coder::lower(problemStruct.modelType.data, problemStruct.modelType.size,
                   switch_expression_data, switch_expression_size);
      if (coder::internal::l_strcmp(switch_expression_data,
           switch_expression_size)) {
        b_index = 0;
      } else if (coder::internal::n_strcmp(switch_expression_data,
                  switch_expression_size)) {
        b_index = 1;
      } else if (coder::internal::o_strcmp(switch_expression_data,
                  switch_expression_size)) {
        b_index = 2;
      } else {
        b_index = -1;
      }

      switch (b_index) {
       case 0:
        //  First we need to allocate the absolute values of the input
        //  parameters to all the layers in the layers list. This only
        //  needs to be done once, and so is done outside the contrasts
        //  loop
        allocateParamsToLayers(paramValues, layersDetails, layerValues);
        subRoughs.set_size(i);
        contrastLayers1.set_size(i);
        contrastLayers2.set_size(i);
        for (int b_i{0}; b_i < i; b_i++) {
          //  Substrate roughness is always first parameter for
          //  standard layers
          subRoughs[b_i] = paramValues[0];

          //  Also need to determine which layers from the overall
          //  layers list are required for this contrast, and put them
          //  in the correct order according to geometry. We run it
          //  twice, once for each domain
          allocateLayersForContrast(domainContrastLayers[static_cast<int>
            (inputContrastLayers[b_i].f1[0]) - 1].f1, layerValues, r1);
          contrastLayers1[b_i].f1.set_size(r1.size(0), 6);
          loop_ub = r1.size(0);
          for (int i2{0}; i2 < 6; i2++) {
            for (b_index = 0; b_index < loop_ub; b_index++) {
              contrastLayers1[b_i].f1[b_index + contrastLayers1[b_i].f1.size(0) *
                i2] = r1[b_index + r1.size(0) * i2];
            }
          }

          allocateLayersForContrast(domainContrastLayers[static_cast<int>
            (inputContrastLayers[b_i].f1[1]) - 1].f1, layerValues, r1);
          contrastLayers2[b_i].f1.set_size(r1.size(0), 6);
          loop_ub = r1.size(0);
          for (int i2{0}; i2 < 6; i2++) {
            for (b_index = 0; b_index < loop_ub; b_index++) {
              contrastLayers2[b_i].f1[b_index + contrastLayers2[b_i].f1.size(0) *
                i2] = r1[b_index + r1.size(0) * i2];
            }
          }
        }
        break;

       case 1:
        processCustomFunction(bulkIns, bulkOuts, contrastCustomFiles,
                              numberOfContrasts, customFiles, paramValues,
                              useImaginary, contrastLayers1, contrastLayers2,
                              subRoughs);
        break;

       case 2:
        b_processCustomFunction(bulkIns, bulkOuts, contrastCustomFiles,
          numberOfContrasts, customFiles, paramValues, useImaginary,
          contrastSlds1, contrastSlds2, subRoughs);
        break;

       default:
        //  Ensures a proper exception is thrown in the generated C++ code.
        //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
        //  and other parameters if message is a formatspec.
        //
        //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
        //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
        coder::b_sprintf(problemStruct.modelType.data,
                         problemStruct.modelType.size, r);
        coderException(1.0, &r[0]);
        break;
      }

      //  Run the core calculation for each contrast
      if (coder::internal::c_strcmp(problemStruct.modelType.data,
           problemStruct.modelType.size)) {
        if (coder::internal::m_strcmp(controls->parallel.data,
             controls->parallel.size)) {
          layers.set_size(i);
          resampledLayers.set_size(i);
          chis.set_size(i);
          sldProfiles.set_size(i);
          simulation.set_size(i);
          reflectivity.set_size(i);
          domainSldProfiles.set_size(i, 2);
          b_index = static_cast<int>(numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(simulationXData,d,b_dataIndices,iv3,iv4,iv5,iv6,dv2,dv3)

          for (int c_i = 0; c_i <= b_index; c_i++) {
            iv3[0] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[0];
            iv3[1] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[1];
            iv4[0] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[0];
            iv4[1] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[1];
            iv5[0] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[0];
            iv5[1] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[1];
            iv6[0] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[0];
            iv6[1] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[1];
            dv2[0] = dataLimits[c_i].f1[0];
            dv2[1] = dataLimits[c_i].f1[1];
            dv3[0] = simulationLimits[c_i].f1[0];
            dv3[1] = simulationLimits[c_i].f1[1];
            setupCoreReflectivityCalculation((const double *)
              contrastBackgroundIndices[c_i].f1.data(), iv3, (const double *)
              contrastResolutionIndices[c_i].f1.data(), iv4,
              backgroundParamValues, resolutionParamValues, (const char *)
              contrastBackgroundTypes[c_i].f1.data(), iv5, (const char *)
              contrastResolutionTypes[c_i].f1.data(), iv6, customFiles,
              scalefactors[c_i], dataPresent[c_i], data[c_i].f1, dv2, dv3,
              numSimulationPoints, backgrounds[c_i].f1, resolutions[c_i].f1,
              shiftedData[c_i].f1, simulationXData, b_dataIndices);
            iv3[0] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[0];
            iv3[1] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[1];
            d = contrastCustomXYCalculation(bulkIns[c_i], bulkOuts[c_i],
              domainRatios[c_i], shiftedData[c_i].f1, simulationXData,
              b_dataIndices, backgrounds[c_i].f1, resolutions[c_i].f1, (const
              char *)contrastBackgroundActions[c_i].f1.data(), iv3, nParams,
              controls->parallel.data, controls->parallel.size, resampleMinAngle,
              resampleNPoints, subRoughs[c_i], contrastSlds1[c_i].f1,
              contrastSlds2[c_i].f1, reflectivity[c_i].f1, simulation[c_i].f1,
              sldProfiles[c_i].f1, layers[c_i].f1, resampledLayers[c_i].f1);
            chis[c_i] = d;
          }
        } else {
          layers.set_size(i);
          resampledLayers.set_size(i);
          chis.set_size(i);
          sldProfiles.set_size(i);
          simulation.set_size(i);
          reflectivity.set_size(i);
          domainSldProfiles.set_size(i, 2);
          for (int b_i{0}; b_i < i; b_i++) {
            double b_dv[2];
            double b_dv1[2];
            int iv[2];
            int iv1[2];
            int iv2[2];
            switch_expression_size[0] = (*(int (*)[2])
              contrastBackgroundIndices[b_i].f1.size())[0];
            switch_expression_size[1] = (*(int (*)[2])
              contrastBackgroundIndices[b_i].f1.size())[1];
            iv[0] = (*(int (*)[2])contrastResolutionIndices[b_i].f1.size())[0];
            iv[1] = (*(int (*)[2])contrastResolutionIndices[b_i].f1.size())[1];
            iv1[0] = (*(int (*)[2])contrastBackgroundTypes[b_i].f1.size())[0];
            iv1[1] = (*(int (*)[2])contrastBackgroundTypes[b_i].f1.size())[1];
            iv2[0] = (*(int (*)[2])contrastResolutionTypes[b_i].f1.size())[0];
            iv2[1] = (*(int (*)[2])contrastResolutionTypes[b_i].f1.size())[1];
            b_dv[0] = dataLimits[b_i].f1[0];
            b_dv[1] = dataLimits[b_i].f1[1];
            b_dv1[0] = simulationLimits[b_i].f1[0];
            b_dv1[1] = simulationLimits[b_i].f1[1];
            setupCoreReflectivityCalculation((const double *)
              contrastBackgroundIndices[b_i].f1.data(), switch_expression_size,
              (const double *)contrastResolutionIndices[b_i].f1.data(), iv,
              backgroundParamValues, resolutionParamValues, (const char *)
              contrastBackgroundTypes[b_i].f1.data(), iv1, (const char *)
              contrastResolutionTypes[b_i].f1.data(), iv2, customFiles,
              scalefactors[b_i], dataPresent[b_i], data[b_i].f1, b_dv, b_dv1,
              numSimulationPoints, backgrounds[b_i].f1, resolutions[b_i].f1,
              shiftedData[b_i].f1, b_simulationXData, dataIndices);
            switch_expression_size[0] = (*(int (*)[2])
              contrastBackgroundActions[b_i].f1.size())[0];
            switch_expression_size[1] = (*(int (*)[2])
              contrastBackgroundActions[b_i].f1.size())[1];
            chis[b_i] = contrastCustomXYCalculation(bulkIns[b_i], bulkOuts[b_i],
              domainRatios[b_i], shiftedData[b_i].f1, b_simulationXData,
              dataIndices, backgrounds[b_i].f1, resolutions[b_i].f1, (const char
              *)contrastBackgroundActions[b_i].f1.data(), switch_expression_size,
              nParams, controls->parallel.data, controls->parallel.size,
              resampleMinAngle, resampleNPoints, subRoughs[b_i],
              contrastSlds1[b_i].f1, contrastSlds2[b_i].f1, reflectivity[b_i].f1,
              simulation[b_i].f1, sldProfiles[b_i].f1, layers[b_i].f1,
              resampledLayers[b_i].f1);
          }
        }
      } else if (coder::internal::m_strcmp(controls->parallel.data,
                  controls->parallel.size)) {
        layers.set_size(i);
        resampledLayers.set_size(i);
        chis.set_size(i);
        sldProfiles.set_size(i);
        simulation.set_size(i);
        reflectivity.set_size(i);
        domainSldProfiles.set_size(i, 2);
        b_index = static_cast<int>(numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(simulationXData,d,b_dataIndices,iv3,iv4,iv5,iv6,dv2,dv3)

        for (int c_i = 0; c_i <= b_index; c_i++) {
          iv3[0] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[0];
          iv3[1] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[1];
          iv4[0] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[0];
          iv4[1] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[1];
          iv5[0] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[0];
          iv5[1] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[1];
          iv6[0] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[0];
          iv6[1] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[1];
          dv2[0] = dataLimits[c_i].f1[0];
          dv2[1] = dataLimits[c_i].f1[1];
          dv3[0] = simulationLimits[c_i].f1[0];
          dv3[1] = simulationLimits[c_i].f1[1];
          setupCoreReflectivityCalculation((const double *)
            contrastBackgroundIndices[c_i].f1.data(), iv3, (const double *)
            contrastResolutionIndices[c_i].f1.data(), iv4, backgroundParamValues,
            resolutionParamValues, (const char *)contrastBackgroundTypes[c_i].
            f1.data(), iv5, (const char *)contrastResolutionTypes[c_i].f1.data(),
            iv6, customFiles, scalefactors[c_i], dataPresent[c_i], data[c_i].f1,
            dv2, dv3, numSimulationPoints, backgrounds[c_i].f1, resolutions[c_i]
            .f1, shiftedData[c_i].f1, simulationXData, b_dataIndices);
          iv3[0] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[0];
          iv3[1] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[1];
          d = contrastLayersCalculation(bulkIns[c_i], bulkOuts[c_i],
            domainRatios[c_i], shiftedData[c_i].f1, simulationXData,
            b_dataIndices, backgrounds[c_i].f1, resolutions[c_i].f1,
            repeatLayers[c_i], (const char *)contrastBackgroundActions[c_i].
            f1.data(), iv3, nParams, controls->parallel.data,
            controls->parallel.size, resampleMinAngle, resampleNPoints,
            resample[c_i], geometry_data, geometry_size, subRoughs[c_i], true,
            contrastLayers1[c_i].f1, contrastLayers2[c_i].f1, reflectivity[c_i].
            f1, simulation[c_i].f1, sldProfiles[c_i].f1, layers[c_i].f1,
            resampledLayers[c_i].f1);
          chis[c_i] = d;
        }
      } else {
        layers.set_size(i);
        resampledLayers.set_size(i);
        chis.set_size(i);
        sldProfiles.set_size(i);
        simulation.set_size(i);
        reflectivity.set_size(i);
        domainSldProfiles.set_size(i, 2);
        for (int b_i{0}; b_i < i; b_i++) {
          double b_dv[2];
          double b_dv1[2];
          int iv[2];
          int iv1[2];
          int iv2[2];
          switch_expression_size[0] = (*(int (*)[2])
            contrastBackgroundIndices[b_i].f1.size())[0];
          switch_expression_size[1] = (*(int (*)[2])
            contrastBackgroundIndices[b_i].f1.size())[1];
          iv[0] = (*(int (*)[2])contrastResolutionIndices[b_i].f1.size())[0];
          iv[1] = (*(int (*)[2])contrastResolutionIndices[b_i].f1.size())[1];
          iv1[0] = (*(int (*)[2])contrastBackgroundTypes[b_i].f1.size())[0];
          iv1[1] = (*(int (*)[2])contrastBackgroundTypes[b_i].f1.size())[1];
          iv2[0] = (*(int (*)[2])contrastResolutionTypes[b_i].f1.size())[0];
          iv2[1] = (*(int (*)[2])contrastResolutionTypes[b_i].f1.size())[1];
          b_dv[0] = dataLimits[b_i].f1[0];
          b_dv[1] = dataLimits[b_i].f1[1];
          b_dv1[0] = simulationLimits[b_i].f1[0];
          b_dv1[1] = simulationLimits[b_i].f1[1];
          setupCoreReflectivityCalculation((const double *)
            contrastBackgroundIndices[b_i].f1.data(), switch_expression_size, (
            const double *)contrastResolutionIndices[b_i].f1.data(), iv,
            backgroundParamValues, resolutionParamValues, (const char *)
            contrastBackgroundTypes[b_i].f1.data(), iv1, (const char *)
            contrastResolutionTypes[b_i].f1.data(), iv2, customFiles,
            scalefactors[b_i], dataPresent[b_i], data[b_i].f1, b_dv, b_dv1,
            numSimulationPoints, backgrounds[b_i].f1, resolutions[b_i].f1,
            shiftedData[b_i].f1, b_simulationXData, dataIndices);
          switch_expression_size[0] = (*(int (*)[2])
            contrastBackgroundActions[b_i].f1.size())[0];
          switch_expression_size[1] = (*(int (*)[2])
            contrastBackgroundActions[b_i].f1.size())[1];
          chis[b_i] = contrastLayersCalculation(bulkIns[b_i], bulkOuts[b_i],
            domainRatios[b_i], shiftedData[b_i].f1, b_simulationXData,
            dataIndices, backgrounds[b_i].f1, resolutions[b_i].f1,
            repeatLayers[b_i], (const char *)contrastBackgroundActions[b_i].
            f1.data(), switch_expression_size, nParams, controls->parallel.data,
            controls->parallel.size, resampleMinAngle, resampleNPoints,
            resample[b_i], geometry_data, geometry_size, subRoughs[b_i], true,
            contrastLayers1[b_i].f1, contrastLayers2[b_i].f1, reflectivity[b_i].
            f1, simulation[b_i].f1, sldProfiles[b_i].f1, layers[b_i].f1,
            resampledLayers[b_i].f1);
        }
      }

      for (int b_i{0}; b_i < i1; b_i++) {
        for (int j{0}; j < 2; j++) {
          loop_ub = sldProfiles[b_i].f1[j].f1.size(0);
          domainSldProfiles[b_i + domainSldProfiles.size(0) * j].f1.set_size
            (sldProfiles[b_i].f1[j].f1.size(0), 2);
          for (i = 0; i < 2; i++) {
            for (int i2{0}; i2 < loop_ub; i2++) {
              domainSldProfiles[b_i + domainSldProfiles.size(0) * j].f1[i2 +
                domainSldProfiles[b_i + domainSldProfiles.size(0) * j].f1.size(0)
                * i] = sldProfiles[b_i].f1[j].f1[i2 + sldProfiles[b_i].f1[j].
                f1.size(0) * i];
            }
          }

          loop_ub = layers[b_i].f1[j].f1.size(1);
          domainLayers[b_i + domainLayers.size(0) * j].f1.set_size(layers[b_i].
            f1[j].f1.size(0), layers[b_i].f1[j].f1.size(1));
          for (i = 0; i < loop_ub; i++) {
            b_index = layers[b_i].f1[j].f1.size(0);
            for (int i2{0}; i2 < b_index; i2++) {
              domainLayers[b_i + domainLayers.size(0) * j].f1[i2 +
                domainLayers[b_i + domainLayers.size(0) * j].f1.size(0) * i] =
                layers[b_i].f1[j].f1[i2 + layers[b_i].f1[j].f1.size(0) * i];
            }
          }

          loop_ub = resampledLayers[b_i].f1[j].f1.size(0);
          domainResampledLayers[b_i + domainResampledLayers.size(0) * j].
            f1.set_size(resampledLayers[b_i].f1[j].f1.size(0), 4);
          for (i = 0; i < 4; i++) {
            for (int i2{0}; i2 < loop_ub; i2++) {
              domainResampledLayers[b_i + domainResampledLayers.size(0) * j]
                .f1[i2 + domainResampledLayers[b_i + domainResampledLayers.size
                (0) * j].f1.size(0) * i] = resampledLayers[b_i].f1[j].f1[i2 +
                resampledLayers[b_i].f1[j].f1.size(0) * i];
            }
          }
        }
      }

      //  Remove dummy imaginary column if present
      if (!useImaginary) {
        for (int b_i{0}; b_i < i1; b_i++) {
          coder::internal::nullAssignment(domainLayers[b_i].f1);
          coder::internal::nullAssignment(domainResampledLayers[b_i].f1);
          coder::internal::nullAssignment(domainLayers[b_i + domainLayers.size(0)]
            .f1);
          coder::internal::nullAssignment(domainResampledLayers[b_i +
            domainResampledLayers.size(0)].f1);
        }
      }
    }
  }
}

// End of code generation (domainsReflectivity.cpp)
