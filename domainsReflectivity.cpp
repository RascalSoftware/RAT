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
      &sldProfiles, ::coder::array<cell_wrap_9, 2U> &layers, ::coder::array<
      cell_wrap_9, 2U> &resampledLayers, ::coder::array<double, 1U> &qzshifts, ::
      coder::array<double, 1U> &scalefactors, ::coder::array<double, 1U>
      &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::coder::array<double, 1U>
      &subRoughs, ::coder::array<double, 1U> &chis)
    {
      ::coder::array<cell_wrap_51, 2U> layerValues;
      ::coder::array<cell_wrap_62, 1U> domainSldProfiles;
      ::coder::array<cell_wrap_63, 1U> domainLayers;
      ::coder::array<cell_wrap_65, 1U> domainResampledLayers;
      ::coder::array<cell_wrap_9, 1U> contrastLayers1;
      ::coder::array<cell_wrap_9, 1U> contrastLayers2;
      ::coder::array<cell_wrap_9, 1U> contrastSlds1;
      ::coder::array<cell_wrap_9, 1U> contrastSlds2;
      ::coder::array<double, 2U> r1;
      ::coder::array<double, 1U> b_simulationXData;
      ::coder::array<double, 1U> domainRatios;
      ::coder::array<double, 1U> simulationXData;
      ::coder::array<char, 2U> r;
      double b_dataIndices[2];
      double dataIndices[2];
      double dv2[2];
      double dv3[2];
      double d;
      double numSimulationPoints;
      double resampleMinAngle;
      double resampleNPoints;
      int iv3[2];
      int iv4[2];
      int iv5[2];
      int iv6[2];
      int switch_expression_size[2];
      int b_index;
      int loop_ub;
      int loop_ub_tmp;
      int nParams;
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
      useImaginary = problemStruct.useImaginary;
      nParams = problemStruct.params.size(1);
      calcSld = controls->calcSLD;
      numSimulationPoints = controls->numSimulationPoints;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Find the actual values from the indices given in each contrast
      scalefactors.set_size(problemStruct.contrastScalefactors.size(1));
      loop_ub = problemStruct.contrastScalefactors.size(1);
      for (int i{0}; i < loop_ub; i++) {
        scalefactors[i] = problemStruct.scalefactors[static_cast<int>
          (problemStruct.contrastScalefactors[i]) - 1];
      }

      bulkIns.set_size(problemStruct.contrastBulkIns.size(1));
      loop_ub = problemStruct.contrastBulkIns.size(1);
      for (int i{0}; i < loop_ub; i++) {
        bulkIns[i] = problemStruct.bulkIns[static_cast<int>
          (problemStruct.contrastBulkIns[i]) - 1];
      }

      bulkOuts.set_size(problemStruct.contrastBulkOuts.size(1));
      loop_ub = problemStruct.contrastBulkOuts.size(1);
      for (int i{0}; i < loop_ub; i++) {
        bulkOuts[i] = problemStruct.bulkOuts[static_cast<int>
          (problemStruct.contrastBulkOuts[i]) - 1];
      }

      domainRatios.set_size(problemStruct.contrastDomainRatios.size(1));
      loop_ub = problemStruct.contrastDomainRatios.size(1);
      for (int i{0}; i < loop_ub; i++) {
        domainRatios[i] = problemStruct.domainRatios[static_cast<int>
          (problemStruct.contrastDomainRatios[i]) - 1];
      }

      //  qzshifts are not included as a parameter in RAT,
      //  so we set up dummy values for the reflectivity calculation
      loop_ub_tmp = static_cast<int>(problemStruct.numberOfContrasts);
      qzshifts.set_size(loop_ub_tmp);
      for (int i{0}; i < loop_ub_tmp; i++) {
        qzshifts[i] = 0.0;
      }

      //  Allocate the memory for the output arrays before the main loop
      shiftedData.set_size(loop_ub_tmp);
      backgrounds.set_size(loop_ub_tmp);
      resolutions.set_size(loop_ub_tmp);
      contrastLayers1.set_size(loop_ub_tmp);
      contrastLayers2.set_size(loop_ub_tmp);
      contrastSlds1.set_size(loop_ub_tmp);
      contrastSlds2.set_size(loop_ub_tmp);
      layers.set_size(loop_ub_tmp, 2);
      resampledLayers.set_size(loop_ub_tmp, 2);
      for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
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
        for (int i{0}; i < 6; i++) {
          contrastLayers1[b_i].f1[contrastLayers1[b_i].f1.size(0) * i] = 0.0;
          contrastLayers2[b_i].f1[contrastLayers2[b_i].f1.size(0) * i] = 0.0;
        }

        contrastSlds1[b_i].f1.set_size(1, 3);
        contrastSlds2[b_i].f1.set_size(1, 3);
        contrastSlds1[b_i].f1[0] = 0.0;
        contrastSlds2[b_i].f1[0] = 0.0;
        contrastSlds1[b_i].f1[contrastSlds1[b_i].f1.size(0)] = 0.0;
        contrastSlds2[b_i].f1[contrastSlds2[b_i].f1.size(0)] = 0.0;
        contrastSlds1[b_i].f1[contrastSlds1[b_i].f1.size(0) * 2] = 0.0;
        contrastSlds2[b_i].f1[contrastSlds2[b_i].f1.size(0) * 2] = 0.0;
        layers[b_i].f1.set_size(1, 6);
        layers[b_i + layers.size(0)].f1.set_size(1, 6);
        resampledLayers[b_i].f1.set_size(1, 6);
        resampledLayers[b_i + resampledLayers.size(0)].f1.set_size(1, 6);
        for (int i{0}; i < 6; i++) {
          layers[b_i].f1[layers[b_i].f1.size(0) * i] = 0.0;
          layers[b_i + layers.size(0)].f1[layers[b_i + layers.size(0)].f1.size(0)
            * i] = 0.0;
          resampledLayers[b_i].f1[resampledLayers[b_i].f1.size(0) * i] = 0.0;
          resampledLayers[b_i + resampledLayers.size(0)].f1[resampledLayers[b_i
            + resampledLayers.size(0)].f1.size(0) * i] = 0.0;
        }
      }

      //  Obtain model specific parameters
      coder::lower(problemStruct.modelType.data, problemStruct.modelType.size,
                   switch_expression_data, switch_expression_size);
      if (coder::internal::k_strcmp(switch_expression_data,
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
        allocateParamsToLayers(problemStruct.params, problemStruct.layersDetails,
          layerValues);
        subRoughs.set_size(loop_ub_tmp);
        contrastLayers1.set_size(loop_ub_tmp);
        contrastLayers2.set_size(loop_ub_tmp);
        for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
          //  Substrate roughness is always first parameter for
          //  standard layers
          subRoughs[b_i] = problemStruct.params[0];

          //  Also need to determine which layers from the overall
          //  layers list are required for this contrast, and put them
          //  in the correct order according to geometry. We run it
          //  twice, once for each domain
          allocateLayersForContrast(problemStruct.domainContrastLayers[
            static_cast<int>(problemStruct.contrastLayers[b_i].f1[0]) - 1].f1,
            layerValues, r1);
          contrastLayers1[b_i].f1.set_size(r1.size(0), 6);
          loop_ub = r1.size(0);
          for (int i{0}; i < 6; i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              contrastLayers1[b_i].f1[i1 + contrastLayers1[b_i].f1.size(0) * i] =
                r1[i1 + r1.size(0) * i];
            }
          }

          allocateLayersForContrast(problemStruct.domainContrastLayers[
            static_cast<int>(problemStruct.contrastLayers[b_i].f1[1]) - 1].f1,
            layerValues, r1);
          contrastLayers2[b_i].f1.set_size(r1.size(0), 6);
          loop_ub = r1.size(0);
          for (int i{0}; i < 6; i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              contrastLayers2[b_i].f1[i1 + contrastLayers2[b_i].f1.size(0) * i] =
                r1[i1 + r1.size(0) * i];
            }
          }
        }
        break;

       case 1:
        processCustomFunction(bulkIns, bulkOuts,
                              problemStruct.contrastCustomFiles,
                              problemStruct.numberOfContrasts,
                              problemStruct.customFiles, problemStruct.params,
                              problemStruct.useImaginary, contrastLayers1,
                              contrastLayers2, subRoughs);
        break;

       case 2:
        b_processCustomFunction(bulkIns, bulkOuts,
          problemStruct.contrastCustomFiles, problemStruct.numberOfContrasts,
          problemStruct.customFiles, problemStruct.params,
          problemStruct.useImaginary, contrastSlds1, contrastSlds2, subRoughs);
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
      if (coder::internal::l_strcmp(problemStruct.modelType.data,
           problemStruct.modelType.size)) {
        if (coder::internal::m_strcmp(controls->parallel.data,
             controls->parallel.size)) {
          domainLayers.set_size(loop_ub_tmp);
          domainResampledLayers.set_size(loop_ub_tmp);
          chis.set_size(loop_ub_tmp);
          domainSldProfiles.set_size(loop_ub_tmp);
          simulation.set_size(loop_ub_tmp);
          reflectivity.set_size(loop_ub_tmp);
          sldProfiles.set_size(loop_ub_tmp, 2);
          b_index = static_cast<int>(problemStruct.numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(simulationXData,d,b_dataIndices,iv3,iv4,iv5,iv6,dv2,dv3)

          for (int c_i = 0; c_i <= b_index; c_i++) {
            iv3[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                       &problemStruct.contrastBackgroundParams[c_i].f1)->size())
              [0];
            iv3[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                       &problemStruct.contrastBackgroundParams[c_i].f1)->size())
              [1];
            iv4[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                       &problemStruct.contrastResolutionParams[c_i].f1)->size())
              [0];
            iv4[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                       &problemStruct.contrastResolutionParams[c_i].f1)->size())
              [1];
            iv5[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundTypes[c_i].f1)->size())
              [0];
            iv5[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundTypes[c_i].f1)->size())
              [1];
            iv6[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastResolutionTypes[c_i].f1)->size())
              [0];
            iv6[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastResolutionTypes[c_i].f1)->size())
              [1];
            dv2[0] = problemStruct.dataLimits[c_i].f1[0];
            dv2[1] = problemStruct.dataLimits[c_i].f1[1];
            dv3[0] = problemStruct.simulationLimits[c_i].f1[0];
            dv3[1] = problemStruct.simulationLimits[c_i].f1[1];
            setupCoreReflectivityCalculation((const double *)((::coder::array<
              double, 2U> *)&problemStruct.contrastBackgroundParams[c_i].f1)
              ->data(), iv3, (const double *)((::coder::array<double, 2U> *)
              &problemStruct.contrastResolutionParams[c_i].f1)->data(), iv4,
              problemStruct.backgroundParams, problemStruct.resolutionParams, (
              const char *)((::coder::array<char, 2U> *)
                            &problemStruct.contrastBackgroundTypes[c_i].f1)
              ->data(), iv5, (const char *)((::coder::array<char, 2U> *)
              &problemStruct.contrastResolutionTypes[c_i].f1)->data(), iv6,
              problemStruct.customFiles, scalefactors[c_i],
              problemStruct.dataPresent[c_i], problemStruct.data[c_i].f1, dv2,
              dv3, numSimulationPoints, backgrounds[c_i].f1, resolutions[c_i].f1,
              shiftedData[c_i].f1, simulationXData, b_dataIndices);
            iv3[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundActions[c_i].f1)->size())
              [0];
            iv3[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundActions[c_i].f1)->size())
              [1];
            d = contrastCustomXYCalculation(bulkIns[c_i], bulkOuts[c_i],
              domainRatios[c_i], shiftedData[c_i].f1, simulationXData,
              b_dataIndices, backgrounds[c_i].f1, resolutions[c_i].f1, (const
              char *)((::coder::array<char, 2U> *)
                      &problemStruct.contrastBackgroundActions[c_i].f1)->data(),
              iv3, static_cast<double>(nParams), controls->parallel.data,
              controls->parallel.size, resampleMinAngle, resampleNPoints,
              subRoughs[c_i], contrastSlds1[c_i].f1, contrastSlds2[c_i].f1,
              reflectivity[c_i].f1, simulation[c_i].f1, domainSldProfiles[c_i].
              f1, domainLayers[c_i].f1, domainResampledLayers[c_i].f1);
            chis[c_i] = d;
          }
        } else {
          domainLayers.set_size(loop_ub_tmp);
          domainResampledLayers.set_size(loop_ub_tmp);
          chis.set_size(loop_ub_tmp);
          domainSldProfiles.set_size(loop_ub_tmp);
          simulation.set_size(loop_ub_tmp);
          reflectivity.set_size(loop_ub_tmp);
          sldProfiles.set_size(loop_ub_tmp, 2);
          for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
            double b_dv[2];
            double b_dv1[2];
            int iv[2];
            int iv1[2];
            int iv2[2];
            switch_expression_size[0] = (*(int (*)[2])((::coder::array<double,
              2U> *)&problemStruct.contrastBackgroundParams[b_i].f1)->size())[0];
            switch_expression_size[1] = (*(int (*)[2])((::coder::array<double,
              2U> *)&problemStruct.contrastBackgroundParams[b_i].f1)->size())[1];
            iv[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                      &problemStruct.contrastResolutionParams[b_i].f1)->size())
              [0];
            iv[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                      &problemStruct.contrastResolutionParams[b_i].f1)->size())
              [1];
            iv1[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundTypes[b_i].f1)->size())
              [0];
            iv1[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundTypes[b_i].f1)->size())
              [1];
            iv2[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastResolutionTypes[b_i].f1)->size())
              [0];
            iv2[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastResolutionTypes[b_i].f1)->size())
              [1];
            b_dv[0] = problemStruct.dataLimits[b_i].f1[0];
            b_dv[1] = problemStruct.dataLimits[b_i].f1[1];
            b_dv1[0] = problemStruct.simulationLimits[b_i].f1[0];
            b_dv1[1] = problemStruct.simulationLimits[b_i].f1[1];
            setupCoreReflectivityCalculation((const double *)((::coder::array<
              double, 2U> *)&problemStruct.contrastBackgroundParams[b_i].f1)
              ->data(), switch_expression_size, (const double *)((::coder::array<
              double, 2U> *)&problemStruct.contrastResolutionParams[b_i].f1)
              ->data(), iv, problemStruct.backgroundParams,
              problemStruct.resolutionParams, (const char *)((::coder::array<
              char, 2U> *)&problemStruct.contrastBackgroundTypes[b_i].f1)->data(),
              iv1, (const char *)((::coder::array<char, 2U> *)
                                  &problemStruct.contrastResolutionTypes[b_i].f1)
              ->data(), iv2, problemStruct.customFiles,
              problemStruct.scalefactors[static_cast<int>
              (problemStruct.contrastScalefactors[b_i]) - 1],
              problemStruct.dataPresent[b_i], problemStruct.data[b_i].f1, b_dv,
              b_dv1, numSimulationPoints, backgrounds[b_i].f1, resolutions[b_i].
              f1, shiftedData[b_i].f1, b_simulationXData, dataIndices);
            switch_expression_size[0] = (*(int (*)[2])((::coder::array<char, 2U>
              *)&problemStruct.contrastBackgroundActions[b_i].f1)->size())[0];
            switch_expression_size[1] = (*(int (*)[2])((::coder::array<char, 2U>
              *)&problemStruct.contrastBackgroundActions[b_i].f1)->size())[1];
            chis[b_i] = contrastCustomXYCalculation(problemStruct.bulkIns[
              static_cast<int>(problemStruct.contrastBulkIns[b_i]) - 1],
              problemStruct.bulkOuts[static_cast<int>
              (problemStruct.contrastBulkOuts[b_i]) - 1],
              problemStruct.domainRatios[static_cast<int>
              (problemStruct.contrastDomainRatios[b_i]) - 1], shiftedData[b_i].
              f1, b_simulationXData, dataIndices, backgrounds[b_i].f1,
              resolutions[b_i].f1, (const char *)((::coder::array<char, 2U> *)
              &problemStruct.contrastBackgroundActions[b_i].f1)->data(),
              switch_expression_size, static_cast<double>(nParams),
              controls->parallel.data, controls->parallel.size, resampleMinAngle,
              resampleNPoints, subRoughs[b_i], contrastSlds1[b_i].f1,
              contrastSlds2[b_i].f1, reflectivity[b_i].f1, simulation[b_i].f1,
              domainSldProfiles[b_i].f1, domainLayers[b_i].f1,
              domainResampledLayers[b_i].f1);
          }
        }
      } else if (coder::internal::m_strcmp(controls->parallel.data,
                  controls->parallel.size)) {
        domainLayers.set_size(loop_ub_tmp);
        domainResampledLayers.set_size(loop_ub_tmp);
        chis.set_size(loop_ub_tmp);
        domainSldProfiles.set_size(loop_ub_tmp);
        simulation.set_size(loop_ub_tmp);
        reflectivity.set_size(loop_ub_tmp);
        sldProfiles.set_size(loop_ub_tmp, 2);
        b_index = loop_ub_tmp - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(simulationXData,d,b_dataIndices,iv3,iv4,iv5,iv6,dv2,dv3)

        for (int c_i = 0; c_i <= b_index; c_i++) {
          iv3[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[c_i].f1)->size())[0];
          iv3[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[c_i].f1)->size())[1];
          iv4[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[c_i].f1)->size())[0];
          iv4[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[c_i].f1)->size())[1];
          iv5[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[c_i].f1)->size())[0];
          iv5[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[c_i].f1)->size())[1];
          iv6[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[c_i].f1)->size())[0];
          iv6[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[c_i].f1)->size())[1];
          dv2[0] = problemStruct.dataLimits[c_i].f1[0];
          dv2[1] = problemStruct.dataLimits[c_i].f1[1];
          dv3[0] = problemStruct.simulationLimits[c_i].f1[0];
          dv3[1] = problemStruct.simulationLimits[c_i].f1[1];
          setupCoreReflectivityCalculation((const double *)((::coder::array<
            double, 2U> *)&problemStruct.contrastBackgroundParams[c_i].f1)->data
            (), iv3, (const double *)((::coder::array<double, 2U> *)
            &problemStruct.contrastResolutionParams[c_i].f1)->data(), iv4,
            problemStruct.backgroundParams, problemStruct.resolutionParams, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastBackgroundTypes[c_i].f1)->data(),
            iv5, (const char *)((::coder::array<char, 2U> *)
                                &problemStruct.contrastResolutionTypes[c_i].f1
            )->data(), iv6, problemStruct.customFiles, scalefactors[c_i],
            problemStruct.dataPresent[c_i], problemStruct.data[c_i].f1, dv2, dv3,
            numSimulationPoints, backgrounds[c_i].f1, resolutions[c_i].f1,
            shiftedData[c_i].f1, simulationXData, b_dataIndices);
          iv3[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[c_i].f1)->size())
            [0];
          iv3[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[c_i].f1)->size())
            [1];
          d = contrastLayersCalculation(bulkIns[c_i], bulkOuts[c_i],
            domainRatios[c_i], shiftedData[c_i].f1, simulationXData,
            b_dataIndices, backgrounds[c_i].f1, resolutions[c_i].f1,
            problemStruct.repeatLayers[c_i], (const char *)((::coder::array<char,
            2U> *)&problemStruct.contrastBackgroundActions[c_i].f1)->data(), iv3,
            static_cast<double>(nParams), controls->parallel.data,
            controls->parallel.size, resampleMinAngle, resampleNPoints,
            problemStruct.resample[c_i], problemStruct.geometry.data,
            problemStruct.geometry.size, subRoughs[c_i], calcSld,
            contrastLayers1[c_i].f1, contrastLayers2[c_i].f1, reflectivity[c_i].
            f1, simulation[c_i].f1, domainSldProfiles[c_i].f1, domainLayers[c_i]
            .f1, domainResampledLayers[c_i].f1);
          chis[c_i] = d;
        }
      } else {
        domainLayers.set_size(loop_ub_tmp);
        domainResampledLayers.set_size(loop_ub_tmp);
        chis.set_size(loop_ub_tmp);
        domainSldProfiles.set_size(loop_ub_tmp);
        simulation.set_size(loop_ub_tmp);
        reflectivity.set_size(loop_ub_tmp);
        sldProfiles.set_size(loop_ub_tmp, 2);
        for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
          double b_dv[2];
          double b_dv1[2];
          int iv[2];
          int iv1[2];
          int iv2[2];
          switch_expression_size[0] = (*(int (*)[2])((::coder::array<double, 2U>
            *)&problemStruct.contrastBackgroundParams[b_i].f1)->size())[0];
          switch_expression_size[1] = (*(int (*)[2])((::coder::array<double, 2U>
            *)&problemStruct.contrastBackgroundParams[b_i].f1)->size())[1];
          iv[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct.contrastResolutionParams[b_i].f1)->size())[0];
          iv[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct.contrastResolutionParams[b_i].f1)->size())[1];
          iv1[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[b_i].f1)->size())[0];
          iv1[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[b_i].f1)->size())[1];
          iv2[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[b_i].f1)->size())[0];
          iv2[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[b_i].f1)->size())[1];
          b_dv[0] = problemStruct.dataLimits[b_i].f1[0];
          b_dv[1] = problemStruct.dataLimits[b_i].f1[1];
          b_dv1[0] = problemStruct.simulationLimits[b_i].f1[0];
          b_dv1[1] = problemStruct.simulationLimits[b_i].f1[1];
          setupCoreReflectivityCalculation((const double *)((::coder::array<
            double, 2U> *)&problemStruct.contrastBackgroundParams[b_i].f1)->data
            (), switch_expression_size, (const double *)((::coder::array<double,
            2U> *)&problemStruct.contrastResolutionParams[b_i].f1)->data(), iv,
            problemStruct.backgroundParams, problemStruct.resolutionParams, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastBackgroundTypes[b_i].f1)->data(),
            iv1, (const char *)((::coder::array<char, 2U> *)
                                &problemStruct.contrastResolutionTypes[b_i].f1
            )->data(), iv2, problemStruct.customFiles,
            problemStruct.scalefactors[static_cast<int>
            (problemStruct.contrastScalefactors[b_i]) - 1],
            problemStruct.dataPresent[b_i], problemStruct.data[b_i].f1, b_dv,
            b_dv1, numSimulationPoints, backgrounds[b_i].f1, resolutions[b_i].f1,
            shiftedData[b_i].f1, b_simulationXData, dataIndices);
          switch_expression_size[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[b_i].f1)->size())[0];
          switch_expression_size[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[b_i].f1)->size())[1];
          chis[b_i] = contrastLayersCalculation(problemStruct.bulkIns[
            static_cast<int>(problemStruct.contrastBulkIns[b_i]) - 1],
            problemStruct.bulkOuts[static_cast<int>
            (problemStruct.contrastBulkOuts[b_i]) - 1],
            problemStruct.domainRatios[static_cast<int>
            (problemStruct.contrastDomainRatios[b_i]) - 1], shiftedData[b_i].f1,
            b_simulationXData, dataIndices, backgrounds[b_i].f1, resolutions[b_i]
            .f1, problemStruct.repeatLayers[b_i], (const char *)((::coder::array<
            char, 2U> *)&problemStruct.contrastBackgroundActions[b_i].f1)->data(),
            switch_expression_size, static_cast<double>(nParams),
            controls->parallel.data, controls->parallel.size, resampleMinAngle,
            resampleNPoints, problemStruct.resample[b_i],
            problemStruct.geometry.data, problemStruct.geometry.size,
            subRoughs[b_i], calcSld, contrastLayers1[b_i].f1,
            contrastLayers2[b_i].f1, reflectivity[b_i].f1, simulation[b_i].f1,
            domainSldProfiles[b_i].f1, domainLayers[b_i].f1,
            domainResampledLayers[b_i].f1);
        }
      }

      for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
        for (int j{0}; j < 2; j++) {
          loop_ub = domainSldProfiles[b_i].f1[j].f1.size(0);
          sldProfiles[b_i + sldProfiles.size(0) * j].f1.set_size
            (domainSldProfiles[b_i].f1[j].f1.size(0), 2);
          for (int i{0}; i < 2; i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              sldProfiles[b_i + sldProfiles.size(0) * j].f1[i1 + sldProfiles[b_i
                + sldProfiles.size(0) * j].f1.size(0) * i] =
                domainSldProfiles[b_i].f1[j].f1[i1 + domainSldProfiles[b_i].f1[j]
                .f1.size(0) * i];
            }
          }

          loop_ub = domainLayers[b_i].f1[j].f1.size(1);
          layers[b_i + layers.size(0) * j].f1.set_size(domainLayers[b_i].f1[j].
            f1.size(0), domainLayers[b_i].f1[j].f1.size(1));
          for (int i{0}; i < loop_ub; i++) {
            b_index = domainLayers[b_i].f1[j].f1.size(0);
            for (int i1{0}; i1 < b_index; i1++) {
              layers[b_i + layers.size(0) * j].f1[i1 + layers[b_i + layers.size
                (0) * j].f1.size(0) * i] = domainLayers[b_i].f1[j].f1[i1 +
                domainLayers[b_i].f1[j].f1.size(0) * i];
            }
          }

          loop_ub = domainResampledLayers[b_i].f1[j].f1.size(0);
          resampledLayers[b_i + resampledLayers.size(0) * j].f1.set_size
            (domainResampledLayers[b_i].f1[j].f1.size(0), 4);
          for (int i{0}; i < 4; i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              resampledLayers[b_i + resampledLayers.size(0) * j].f1[i1 +
                resampledLayers[b_i + resampledLayers.size(0) * j].f1.size(0) *
                i] = domainResampledLayers[b_i].f1[j].f1[i1 +
                domainResampledLayers[b_i].f1[j].f1.size(0) * i];
            }
          }
        }
      }

      //  Remove dummy imaginary column if present
      if (!useImaginary) {
        for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
          coder::internal::nullAssignment(layers[b_i].f1);
          coder::internal::nullAssignment(resampledLayers[b_i].f1);
          coder::internal::nullAssignment(layers[b_i + layers.size(0)].f1);
          coder::internal::nullAssignment(resampledLayers[b_i +
            resampledLayers.size(0)].f1);
        }
      }
    }

    void domainsReflectivity(const ProblemDefinition &problemStruct, const
      Controls *controls, ::coder::array<cell_wrap_7, 1U> &reflectivity, ::coder::
      array<cell_wrap_7, 1U> &simulation, ::coder::array<cell_wrap_8, 1U>
      &shiftedData, ::coder::array<cell_wrap_8, 1U> &backgrounds, ::coder::array<
      cell_wrap_7, 1U> &resolutions, ::coder::array<cell_wrap_7, 2U>
      &sldProfiles, ::coder::array<cell_wrap_9, 2U> &layers, ::coder::array<
      cell_wrap_9, 2U> &resampledLayers, ::coder::array<double, 1U> &qzshifts, ::
      coder::array<double, 1U> &scalefactors, ::coder::array<double, 1U>
      &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::coder::array<double, 1U>
      &subRoughs, ::coder::array<double, 1U> &chis)
    {
      ::coder::array<cell_wrap_51, 2U> layerValues;
      ::coder::array<cell_wrap_62, 1U> domainSldProfiles;
      ::coder::array<cell_wrap_63, 1U> domainLayers;
      ::coder::array<cell_wrap_65, 1U> domainResampledLayers;
      ::coder::array<cell_wrap_9, 1U> contrastLayers1;
      ::coder::array<cell_wrap_9, 1U> contrastLayers2;
      ::coder::array<cell_wrap_9, 1U> contrastSlds1;
      ::coder::array<cell_wrap_9, 1U> contrastSlds2;
      ::coder::array<double, 2U> r1;
      ::coder::array<double, 1U> b_simulationXData;
      ::coder::array<double, 1U> domainRatios;
      ::coder::array<double, 1U> simulationXData;
      ::coder::array<char, 2U> r;
      double b_dataIndices[2];
      double dataIndices[2];
      double dv2[2];
      double dv3[2];
      double d;
      double numSimulationPoints;
      double resampleMinAngle;
      double resampleNPoints;
      int iv3[2];
      int iv4[2];
      int iv5[2];
      int iv6[2];
      int switch_expression_size[2];
      int b_index;
      int loop_ub;
      int loop_ub_tmp;
      int nParams;
      char switch_expression_data[10000];
      boolean_T useImaginary;

      //  This is the main domains reflectivity calculation.
      //  It extracts the required parameters for the contrasts
      //  from the input arrays, then passes the main calculation to
      //  the appropriate core calculation, which carries out the calculation
      //  itself. The core layers calculation is common for both standard and
      //  custom layers, with an additional core custom XY calculation.
      //  Extract parameters from problemStruct
      useImaginary = problemStruct.useImaginary;
      nParams = problemStruct.params.size(1);
      numSimulationPoints = controls->numSimulationPoints;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Find the actual values from the indices given in each contrast
      scalefactors.set_size(problemStruct.contrastScalefactors.size(1));
      loop_ub = problemStruct.contrastScalefactors.size(1);
      for (int i{0}; i < loop_ub; i++) {
        scalefactors[i] = problemStruct.scalefactors[static_cast<int>
          (problemStruct.contrastScalefactors[i]) - 1];
      }

      bulkIns.set_size(problemStruct.contrastBulkIns.size(1));
      loop_ub = problemStruct.contrastBulkIns.size(1);
      for (int i{0}; i < loop_ub; i++) {
        bulkIns[i] = problemStruct.bulkIns[static_cast<int>
          (problemStruct.contrastBulkIns[i]) - 1];
      }

      bulkOuts.set_size(problemStruct.contrastBulkOuts.size(1));
      loop_ub = problemStruct.contrastBulkOuts.size(1);
      for (int i{0}; i < loop_ub; i++) {
        bulkOuts[i] = problemStruct.bulkOuts[static_cast<int>
          (problemStruct.contrastBulkOuts[i]) - 1];
      }

      domainRatios.set_size(problemStruct.contrastDomainRatios.size(1));
      loop_ub = problemStruct.contrastDomainRatios.size(1);
      for (int i{0}; i < loop_ub; i++) {
        domainRatios[i] = problemStruct.domainRatios[static_cast<int>
          (problemStruct.contrastDomainRatios[i]) - 1];
      }

      //  qzshifts are not included as a parameter in RAT,
      //  so we set up dummy values for the reflectivity calculation
      loop_ub_tmp = static_cast<int>(problemStruct.numberOfContrasts);
      qzshifts.set_size(loop_ub_tmp);
      for (int i{0}; i < loop_ub_tmp; i++) {
        qzshifts[i] = 0.0;
      }

      //  Allocate the memory for the output arrays before the main loop
      shiftedData.set_size(loop_ub_tmp);
      backgrounds.set_size(loop_ub_tmp);
      resolutions.set_size(loop_ub_tmp);
      contrastLayers1.set_size(loop_ub_tmp);
      contrastLayers2.set_size(loop_ub_tmp);
      contrastSlds1.set_size(loop_ub_tmp);
      contrastSlds2.set_size(loop_ub_tmp);
      layers.set_size(loop_ub_tmp, 2);
      resampledLayers.set_size(loop_ub_tmp, 2);
      for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
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
        for (int i{0}; i < 6; i++) {
          contrastLayers1[b_i].f1[contrastLayers1[b_i].f1.size(0) * i] = 0.0;
          contrastLayers2[b_i].f1[contrastLayers2[b_i].f1.size(0) * i] = 0.0;
        }

        contrastSlds1[b_i].f1.set_size(1, 3);
        contrastSlds2[b_i].f1.set_size(1, 3);
        contrastSlds1[b_i].f1[0] = 0.0;
        contrastSlds2[b_i].f1[0] = 0.0;
        contrastSlds1[b_i].f1[contrastSlds1[b_i].f1.size(0)] = 0.0;
        contrastSlds2[b_i].f1[contrastSlds2[b_i].f1.size(0)] = 0.0;
        contrastSlds1[b_i].f1[contrastSlds1[b_i].f1.size(0) * 2] = 0.0;
        contrastSlds2[b_i].f1[contrastSlds2[b_i].f1.size(0) * 2] = 0.0;
        layers[b_i].f1.set_size(1, 6);
        layers[b_i + layers.size(0)].f1.set_size(1, 6);
        resampledLayers[b_i].f1.set_size(1, 6);
        resampledLayers[b_i + resampledLayers.size(0)].f1.set_size(1, 6);
        for (int i{0}; i < 6; i++) {
          layers[b_i].f1[layers[b_i].f1.size(0) * i] = 0.0;
          layers[b_i + layers.size(0)].f1[layers[b_i + layers.size(0)].f1.size(0)
            * i] = 0.0;
          resampledLayers[b_i].f1[resampledLayers[b_i].f1.size(0) * i] = 0.0;
          resampledLayers[b_i + resampledLayers.size(0)].f1[resampledLayers[b_i
            + resampledLayers.size(0)].f1.size(0) * i] = 0.0;
        }
      }

      //  Obtain model specific parameters
      coder::lower(problemStruct.modelType.data, problemStruct.modelType.size,
                   switch_expression_data, switch_expression_size);
      if (coder::internal::k_strcmp(switch_expression_data,
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
        allocateParamsToLayers(problemStruct.params, problemStruct.layersDetails,
          layerValues);
        subRoughs.set_size(loop_ub_tmp);
        contrastLayers1.set_size(loop_ub_tmp);
        contrastLayers2.set_size(loop_ub_tmp);
        for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
          //  Substrate roughness is always first parameter for
          //  standard layers
          subRoughs[b_i] = problemStruct.params[0];

          //  Also need to determine which layers from the overall
          //  layers list are required for this contrast, and put them
          //  in the correct order according to geometry. We run it
          //  twice, once for each domain
          allocateLayersForContrast(problemStruct.domainContrastLayers[
            static_cast<int>(problemStruct.contrastLayers[b_i].f1[0]) - 1].f1,
            layerValues, r1);
          contrastLayers1[b_i].f1.set_size(r1.size(0), 6);
          loop_ub = r1.size(0);
          for (int i{0}; i < 6; i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              contrastLayers1[b_i].f1[i1 + contrastLayers1[b_i].f1.size(0) * i] =
                r1[i1 + r1.size(0) * i];
            }
          }

          allocateLayersForContrast(problemStruct.domainContrastLayers[
            static_cast<int>(problemStruct.contrastLayers[b_i].f1[1]) - 1].f1,
            layerValues, r1);
          contrastLayers2[b_i].f1.set_size(r1.size(0), 6);
          loop_ub = r1.size(0);
          for (int i{0}; i < 6; i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              contrastLayers2[b_i].f1[i1 + contrastLayers2[b_i].f1.size(0) * i] =
                r1[i1 + r1.size(0) * i];
            }
          }
        }
        break;

       case 1:
        processCustomFunction(bulkIns, bulkOuts,
                              problemStruct.contrastCustomFiles,
                              problemStruct.numberOfContrasts,
                              problemStruct.customFiles, problemStruct.params,
                              problemStruct.useImaginary, contrastLayers1,
                              contrastLayers2, subRoughs);
        break;

       case 2:
        b_processCustomFunction(bulkIns, bulkOuts,
          problemStruct.contrastCustomFiles, problemStruct.numberOfContrasts,
          problemStruct.customFiles, problemStruct.params,
          problemStruct.useImaginary, contrastSlds1, contrastSlds2, subRoughs);
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
      if (coder::internal::l_strcmp(problemStruct.modelType.data,
           problemStruct.modelType.size)) {
        if (coder::internal::m_strcmp(controls->parallel.data,
             controls->parallel.size)) {
          domainLayers.set_size(loop_ub_tmp);
          domainResampledLayers.set_size(loop_ub_tmp);
          chis.set_size(loop_ub_tmp);
          domainSldProfiles.set_size(loop_ub_tmp);
          simulation.set_size(loop_ub_tmp);
          reflectivity.set_size(loop_ub_tmp);
          sldProfiles.set_size(loop_ub_tmp, 2);
          b_index = static_cast<int>(problemStruct.numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(simulationXData,d,b_dataIndices,iv3,iv4,iv5,iv6,dv2,dv3)

          for (int c_i = 0; c_i <= b_index; c_i++) {
            iv3[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                       &problemStruct.contrastBackgroundParams[c_i].f1)->size())
              [0];
            iv3[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                       &problemStruct.contrastBackgroundParams[c_i].f1)->size())
              [1];
            iv4[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                       &problemStruct.contrastResolutionParams[c_i].f1)->size())
              [0];
            iv4[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                       &problemStruct.contrastResolutionParams[c_i].f1)->size())
              [1];
            iv5[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundTypes[c_i].f1)->size())
              [0];
            iv5[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundTypes[c_i].f1)->size())
              [1];
            iv6[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastResolutionTypes[c_i].f1)->size())
              [0];
            iv6[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastResolutionTypes[c_i].f1)->size())
              [1];
            dv2[0] = problemStruct.dataLimits[c_i].f1[0];
            dv2[1] = problemStruct.dataLimits[c_i].f1[1];
            dv3[0] = problemStruct.simulationLimits[c_i].f1[0];
            dv3[1] = problemStruct.simulationLimits[c_i].f1[1];
            setupCoreReflectivityCalculation((const double *)((::coder::array<
              double, 2U> *)&problemStruct.contrastBackgroundParams[c_i].f1)
              ->data(), iv3, (const double *)((::coder::array<double, 2U> *)
              &problemStruct.contrastResolutionParams[c_i].f1)->data(), iv4,
              problemStruct.backgroundParams, problemStruct.resolutionParams, (
              const char *)((::coder::array<char, 2U> *)
                            &problemStruct.contrastBackgroundTypes[c_i].f1)
              ->data(), iv5, (const char *)((::coder::array<char, 2U> *)
              &problemStruct.contrastResolutionTypes[c_i].f1)->data(), iv6,
              problemStruct.customFiles, scalefactors[c_i],
              problemStruct.dataPresent[c_i], problemStruct.data[c_i].f1, dv2,
              dv3, numSimulationPoints, backgrounds[c_i].f1, resolutions[c_i].f1,
              shiftedData[c_i].f1, simulationXData, b_dataIndices);
            iv3[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundActions[c_i].f1)->size())
              [0];
            iv3[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundActions[c_i].f1)->size())
              [1];
            d = contrastCustomXYCalculation(bulkIns[c_i], bulkOuts[c_i],
              domainRatios[c_i], shiftedData[c_i].f1, simulationXData,
              b_dataIndices, backgrounds[c_i].f1, resolutions[c_i].f1, (const
              char *)((::coder::array<char, 2U> *)
                      &problemStruct.contrastBackgroundActions[c_i].f1)->data(),
              iv3, static_cast<double>(nParams), controls->parallel.data,
              controls->parallel.size, resampleMinAngle, resampleNPoints,
              subRoughs[c_i], contrastSlds1[c_i].f1, contrastSlds2[c_i].f1,
              reflectivity[c_i].f1, simulation[c_i].f1, domainSldProfiles[c_i].
              f1, domainLayers[c_i].f1, domainResampledLayers[c_i].f1);
            chis[c_i] = d;
          }
        } else {
          domainLayers.set_size(loop_ub_tmp);
          domainResampledLayers.set_size(loop_ub_tmp);
          chis.set_size(loop_ub_tmp);
          domainSldProfiles.set_size(loop_ub_tmp);
          simulation.set_size(loop_ub_tmp);
          reflectivity.set_size(loop_ub_tmp);
          sldProfiles.set_size(loop_ub_tmp, 2);
          for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
            double b_dv[2];
            double b_dv1[2];
            int iv[2];
            int iv1[2];
            int iv2[2];
            switch_expression_size[0] = (*(int (*)[2])((::coder::array<double,
              2U> *)&problemStruct.contrastBackgroundParams[b_i].f1)->size())[0];
            switch_expression_size[1] = (*(int (*)[2])((::coder::array<double,
              2U> *)&problemStruct.contrastBackgroundParams[b_i].f1)->size())[1];
            iv[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                      &problemStruct.contrastResolutionParams[b_i].f1)->size())
              [0];
            iv[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                      &problemStruct.contrastResolutionParams[b_i].f1)->size())
              [1];
            iv1[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundTypes[b_i].f1)->size())
              [0];
            iv1[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastBackgroundTypes[b_i].f1)->size())
              [1];
            iv2[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastResolutionTypes[b_i].f1)->size())
              [0];
            iv2[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                       &problemStruct.contrastResolutionTypes[b_i].f1)->size())
              [1];
            b_dv[0] = problemStruct.dataLimits[b_i].f1[0];
            b_dv[1] = problemStruct.dataLimits[b_i].f1[1];
            b_dv1[0] = problemStruct.simulationLimits[b_i].f1[0];
            b_dv1[1] = problemStruct.simulationLimits[b_i].f1[1];
            setupCoreReflectivityCalculation((const double *)((::coder::array<
              double, 2U> *)&problemStruct.contrastBackgroundParams[b_i].f1)
              ->data(), switch_expression_size, (const double *)((::coder::array<
              double, 2U> *)&problemStruct.contrastResolutionParams[b_i].f1)
              ->data(), iv, problemStruct.backgroundParams,
              problemStruct.resolutionParams, (const char *)((::coder::array<
              char, 2U> *)&problemStruct.contrastBackgroundTypes[b_i].f1)->data(),
              iv1, (const char *)((::coder::array<char, 2U> *)
                                  &problemStruct.contrastResolutionTypes[b_i].f1)
              ->data(), iv2, problemStruct.customFiles,
              problemStruct.scalefactors[static_cast<int>
              (problemStruct.contrastScalefactors[b_i]) - 1],
              problemStruct.dataPresent[b_i], problemStruct.data[b_i].f1, b_dv,
              b_dv1, numSimulationPoints, backgrounds[b_i].f1, resolutions[b_i].
              f1, shiftedData[b_i].f1, b_simulationXData, dataIndices);
            switch_expression_size[0] = (*(int (*)[2])((::coder::array<char, 2U>
              *)&problemStruct.contrastBackgroundActions[b_i].f1)->size())[0];
            switch_expression_size[1] = (*(int (*)[2])((::coder::array<char, 2U>
              *)&problemStruct.contrastBackgroundActions[b_i].f1)->size())[1];
            chis[b_i] = contrastCustomXYCalculation(problemStruct.bulkIns[
              static_cast<int>(problemStruct.contrastBulkIns[b_i]) - 1],
              problemStruct.bulkOuts[static_cast<int>
              (problemStruct.contrastBulkOuts[b_i]) - 1],
              problemStruct.domainRatios[static_cast<int>
              (problemStruct.contrastDomainRatios[b_i]) - 1], shiftedData[b_i].
              f1, b_simulationXData, dataIndices, backgrounds[b_i].f1,
              resolutions[b_i].f1, (const char *)((::coder::array<char, 2U> *)
              &problemStruct.contrastBackgroundActions[b_i].f1)->data(),
              switch_expression_size, static_cast<double>(nParams),
              controls->parallel.data, controls->parallel.size, resampleMinAngle,
              resampleNPoints, subRoughs[b_i], contrastSlds1[b_i].f1,
              contrastSlds2[b_i].f1, reflectivity[b_i].f1, simulation[b_i].f1,
              domainSldProfiles[b_i].f1, domainLayers[b_i].f1,
              domainResampledLayers[b_i].f1);
          }
        }
      } else if (coder::internal::m_strcmp(controls->parallel.data,
                  controls->parallel.size)) {
        domainLayers.set_size(loop_ub_tmp);
        domainResampledLayers.set_size(loop_ub_tmp);
        chis.set_size(loop_ub_tmp);
        domainSldProfiles.set_size(loop_ub_tmp);
        simulation.set_size(loop_ub_tmp);
        reflectivity.set_size(loop_ub_tmp);
        sldProfiles.set_size(loop_ub_tmp, 2);
        b_index = loop_ub_tmp - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(simulationXData,d,b_dataIndices,iv3,iv4,iv5,iv6,dv2,dv3)

        for (int c_i = 0; c_i <= b_index; c_i++) {
          iv3[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[c_i].f1)->size())[0];
          iv3[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[c_i].f1)->size())[1];
          iv4[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[c_i].f1)->size())[0];
          iv4[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[c_i].f1)->size())[1];
          iv5[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[c_i].f1)->size())[0];
          iv5[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[c_i].f1)->size())[1];
          iv6[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[c_i].f1)->size())[0];
          iv6[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[c_i].f1)->size())[1];
          dv2[0] = problemStruct.dataLimits[c_i].f1[0];
          dv2[1] = problemStruct.dataLimits[c_i].f1[1];
          dv3[0] = problemStruct.simulationLimits[c_i].f1[0];
          dv3[1] = problemStruct.simulationLimits[c_i].f1[1];
          setupCoreReflectivityCalculation((const double *)((::coder::array<
            double, 2U> *)&problemStruct.contrastBackgroundParams[c_i].f1)->data
            (), iv3, (const double *)((::coder::array<double, 2U> *)
            &problemStruct.contrastResolutionParams[c_i].f1)->data(), iv4,
            problemStruct.backgroundParams, problemStruct.resolutionParams, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastBackgroundTypes[c_i].f1)->data(),
            iv5, (const char *)((::coder::array<char, 2U> *)
                                &problemStruct.contrastResolutionTypes[c_i].f1
            )->data(), iv6, problemStruct.customFiles, scalefactors[c_i],
            problemStruct.dataPresent[c_i], problemStruct.data[c_i].f1, dv2, dv3,
            numSimulationPoints, backgrounds[c_i].f1, resolutions[c_i].f1,
            shiftedData[c_i].f1, simulationXData, b_dataIndices);
          iv3[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[c_i].f1)->size())
            [0];
          iv3[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[c_i].f1)->size())
            [1];
          d = contrastLayersCalculation(bulkIns[c_i], bulkOuts[c_i],
            domainRatios[c_i], shiftedData[c_i].f1, simulationXData,
            b_dataIndices, backgrounds[c_i].f1, resolutions[c_i].f1,
            problemStruct.repeatLayers[c_i], (const char *)((::coder::array<char,
            2U> *)&problemStruct.contrastBackgroundActions[c_i].f1)->data(), iv3,
            static_cast<double>(nParams), controls->parallel.data,
            controls->parallel.size, resampleMinAngle, resampleNPoints,
            problemStruct.resample[c_i], problemStruct.geometry.data,
            problemStruct.geometry.size, subRoughs[c_i], true,
            contrastLayers1[c_i].f1, contrastLayers2[c_i].f1, reflectivity[c_i].
            f1, simulation[c_i].f1, domainSldProfiles[c_i].f1, domainLayers[c_i]
            .f1, domainResampledLayers[c_i].f1);
          chis[c_i] = d;
        }
      } else {
        domainLayers.set_size(loop_ub_tmp);
        domainResampledLayers.set_size(loop_ub_tmp);
        chis.set_size(loop_ub_tmp);
        domainSldProfiles.set_size(loop_ub_tmp);
        simulation.set_size(loop_ub_tmp);
        reflectivity.set_size(loop_ub_tmp);
        sldProfiles.set_size(loop_ub_tmp, 2);
        for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
          double b_dv[2];
          double b_dv1[2];
          int iv[2];
          int iv1[2];
          int iv2[2];
          switch_expression_size[0] = (*(int (*)[2])((::coder::array<double, 2U>
            *)&problemStruct.contrastBackgroundParams[b_i].f1)->size())[0];
          switch_expression_size[1] = (*(int (*)[2])((::coder::array<double, 2U>
            *)&problemStruct.contrastBackgroundParams[b_i].f1)->size())[1];
          iv[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct.contrastResolutionParams[b_i].f1)->size())[0];
          iv[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct.contrastResolutionParams[b_i].f1)->size())[1];
          iv1[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[b_i].f1)->size())[0];
          iv1[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[b_i].f1)->size())[1];
          iv2[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[b_i].f1)->size())[0];
          iv2[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[b_i].f1)->size())[1];
          b_dv[0] = problemStruct.dataLimits[b_i].f1[0];
          b_dv[1] = problemStruct.dataLimits[b_i].f1[1];
          b_dv1[0] = problemStruct.simulationLimits[b_i].f1[0];
          b_dv1[1] = problemStruct.simulationLimits[b_i].f1[1];
          setupCoreReflectivityCalculation((const double *)((::coder::array<
            double, 2U> *)&problemStruct.contrastBackgroundParams[b_i].f1)->data
            (), switch_expression_size, (const double *)((::coder::array<double,
            2U> *)&problemStruct.contrastResolutionParams[b_i].f1)->data(), iv,
            problemStruct.backgroundParams, problemStruct.resolutionParams, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastBackgroundTypes[b_i].f1)->data(),
            iv1, (const char *)((::coder::array<char, 2U> *)
                                &problemStruct.contrastResolutionTypes[b_i].f1
            )->data(), iv2, problemStruct.customFiles,
            problemStruct.scalefactors[static_cast<int>
            (problemStruct.contrastScalefactors[b_i]) - 1],
            problemStruct.dataPresent[b_i], problemStruct.data[b_i].f1, b_dv,
            b_dv1, numSimulationPoints, backgrounds[b_i].f1, resolutions[b_i].f1,
            shiftedData[b_i].f1, b_simulationXData, dataIndices);
          switch_expression_size[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[b_i].f1)->size())[0];
          switch_expression_size[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[b_i].f1)->size())[1];
          chis[b_i] = contrastLayersCalculation(problemStruct.bulkIns[
            static_cast<int>(problemStruct.contrastBulkIns[b_i]) - 1],
            problemStruct.bulkOuts[static_cast<int>
            (problemStruct.contrastBulkOuts[b_i]) - 1],
            problemStruct.domainRatios[static_cast<int>
            (problemStruct.contrastDomainRatios[b_i]) - 1], shiftedData[b_i].f1,
            b_simulationXData, dataIndices, backgrounds[b_i].f1, resolutions[b_i]
            .f1, problemStruct.repeatLayers[b_i], (const char *)((::coder::array<
            char, 2U> *)&problemStruct.contrastBackgroundActions[b_i].f1)->data(),
            switch_expression_size, static_cast<double>(nParams),
            controls->parallel.data, controls->parallel.size, resampleMinAngle,
            resampleNPoints, problemStruct.resample[b_i],
            problemStruct.geometry.data, problemStruct.geometry.size,
            subRoughs[b_i], true, contrastLayers1[b_i].f1, contrastLayers2[b_i].
            f1, reflectivity[b_i].f1, simulation[b_i].f1, domainSldProfiles[b_i]
            .f1, domainLayers[b_i].f1, domainResampledLayers[b_i].f1);
        }
      }

      for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
        for (int j{0}; j < 2; j++) {
          loop_ub = domainSldProfiles[b_i].f1[j].f1.size(0);
          sldProfiles[b_i + sldProfiles.size(0) * j].f1.set_size
            (domainSldProfiles[b_i].f1[j].f1.size(0), 2);
          for (int i{0}; i < 2; i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              sldProfiles[b_i + sldProfiles.size(0) * j].f1[i1 + sldProfiles[b_i
                + sldProfiles.size(0) * j].f1.size(0) * i] =
                domainSldProfiles[b_i].f1[j].f1[i1 + domainSldProfiles[b_i].f1[j]
                .f1.size(0) * i];
            }
          }

          loop_ub = domainLayers[b_i].f1[j].f1.size(1);
          layers[b_i + layers.size(0) * j].f1.set_size(domainLayers[b_i].f1[j].
            f1.size(0), domainLayers[b_i].f1[j].f1.size(1));
          for (int i{0}; i < loop_ub; i++) {
            b_index = domainLayers[b_i].f1[j].f1.size(0);
            for (int i1{0}; i1 < b_index; i1++) {
              layers[b_i + layers.size(0) * j].f1[i1 + layers[b_i + layers.size
                (0) * j].f1.size(0) * i] = domainLayers[b_i].f1[j].f1[i1 +
                domainLayers[b_i].f1[j].f1.size(0) * i];
            }
          }

          loop_ub = domainResampledLayers[b_i].f1[j].f1.size(0);
          resampledLayers[b_i + resampledLayers.size(0) * j].f1.set_size
            (domainResampledLayers[b_i].f1[j].f1.size(0), 4);
          for (int i{0}; i < 4; i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              resampledLayers[b_i + resampledLayers.size(0) * j].f1[i1 +
                resampledLayers[b_i + resampledLayers.size(0) * j].f1.size(0) *
                i] = domainResampledLayers[b_i].f1[j].f1[i1 +
                domainResampledLayers[b_i].f1[j].f1.size(0) * i];
            }
          }
        }
      }

      //  Remove dummy imaginary column if present
      if (!useImaginary) {
        for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
          coder::internal::nullAssignment(layers[b_i].f1);
          coder::internal::nullAssignment(resampledLayers[b_i].f1);
          coder::internal::nullAssignment(layers[b_i + layers.size(0)].f1);
          coder::internal::nullAssignment(resampledLayers[b_i +
            resampledLayers.size(0)].f1);
        }
      }
    }
  }
}

// End of code generation (domainsReflectivity.cpp)
