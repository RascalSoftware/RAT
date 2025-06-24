//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// standardLayers1.cpp
//
// Code generation for function 'standardLayers1'
//

// Include files
#include "standardLayers1.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "backSort.h"
#include "cat.h"
#include "chiSquared.h"
#include "constructBackground.h"
#include "constructResolution.h"
#include "coreLayersCalculation.h"
#include "makeSimulationRange.h"
#include "nullAssignment.h"
#include "rt_nonfinite.h"
#include "shiftData.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "omp.h"

// Function Declarations
namespace RAT
{
  namespace domainsTF
  {
    static double contrastCalculation(const double backgroundParamIndex_data[],
      const int backgroundParamIndex_size[2], double scalefactorIndex, double
      bulkInIndex, double bulkOutIndex, const double resolutionParamIndex_data[],
      const int resolutionParamIndex_size[2], double domainRatioIndex, const ::
      coder::array<double, 2U> &backgroundParamValues, const ::coder::array<
      double, 2U> &scalefactorValues, const ::coder::array<double, 2U>
      &bulkInValues, const ::coder::array<double, 2U> &bulkOutValues, const ::
      coder::array<double, 2U> &resolutionParamValues, const ::coder::array<
      double, 2U> &domainRatioValues, double dataPresent, const ::coder::array<
      double, 2U> &data, const double dataLimits[2], const double
      simulationLimits[2], double repeatLayers, const char backgroundType_data[],
      const int backgroundType_size[2], const char backgroundAction_data[],
      const int backgroundAction_size[2], const char resolutionType_data[],
      const int resolutionType_size[2], const ::coder::array<cell_wrap_10, 2U>
      &customFiles, double nParams, const char parallel_data[], const int
      parallel_size[2], double numSimulationPoints, double resampleMinAngle,
      double resampleNPoints, double resample, const char geometry_data[], const
      int geometry_size[2], double roughness, boolean_T calcSld, const ::coder::
      array<double, 2U> &domainLayersIndices1, const ::coder::array<double, 2U>
      &domainLayersIndices2, const ::coder::array<cell_wrap_51, 2U> &layerValues,
      ::coder::array<double, 2U> &reflectivity, ::coder::array<double, 2U>
      &simulation, ::coder::array<double, 2U> &shiftedData, ::coder::array<
      double, 2U> &background, ::coder::array<double, 2U> &resolution,
      cell_wrap_7 sldProfile[2], cell_wrap_9 layers[2], cell_wrap_64
      resampledLayers[2], double &scalefactor, double &bulkIn, double &bulkOut,
      double &chi);
  }
}

// Function Definitions
namespace RAT
{
  namespace domainsTF
  {
    static double contrastCalculation(const double backgroundParamIndex_data[],
      const int backgroundParamIndex_size[2], double scalefactorIndex, double
      bulkInIndex, double bulkOutIndex, const double resolutionParamIndex_data[],
      const int resolutionParamIndex_size[2], double domainRatioIndex, const ::
      coder::array<double, 2U> &backgroundParamValues, const ::coder::array<
      double, 2U> &scalefactorValues, const ::coder::array<double, 2U>
      &bulkInValues, const ::coder::array<double, 2U> &bulkOutValues, const ::
      coder::array<double, 2U> &resolutionParamValues, const ::coder::array<
      double, 2U> &domainRatioValues, double dataPresent, const ::coder::array<
      double, 2U> &data, const double dataLimits[2], const double
      simulationLimits[2], double repeatLayers, const char backgroundType_data[],
      const int backgroundType_size[2], const char backgroundAction_data[],
      const int backgroundAction_size[2], const char resolutionType_data[],
      const int resolutionType_size[2], const ::coder::array<cell_wrap_10, 2U>
      &customFiles, double nParams, const char parallel_data[], const int
      parallel_size[2], double numSimulationPoints, double resampleMinAngle,
      double resampleNPoints, double resample, const char geometry_data[], const
      int geometry_size[2], double roughness, boolean_T calcSld, const ::coder::
      array<double, 2U> &domainLayersIndices1, const ::coder::array<double, 2U>
      &domainLayersIndices2, const ::coder::array<cell_wrap_51, 2U> &layerValues,
      ::coder::array<double, 2U> &reflectivity, ::coder::array<double, 2U>
      &simulation, ::coder::array<double, 2U> &shiftedData, ::coder::array<
      double, 2U> &background, ::coder::array<double, 2U> &resolution,
      cell_wrap_7 sldProfile[2], cell_wrap_9 layers[2], cell_wrap_64
      resampledLayers[2], double &scalefactor, double &bulkIn, double &bulkOut,
      double &chi)
    {
      ::coder::array<double, 2U> a__3;
      ::coder::array<double, 2U> b_data;
      ::coder::array<double, 2U> b_shiftedData;
      ::coder::array<double, 2U> reflectivity1;
      ::coder::array<double, 2U> reflectivity2;
      ::coder::array<double, 2U> simulation1;
      ::coder::array<double, 2U> simulation2;
      ::coder::array<double, 1U> simulationXData;
      cell_wrap_64 r2;
      cell_wrap_64 r5;
      cell_wrap_7 r;
      cell_wrap_7 r3;
      cell_wrap_9 r1;
      cell_wrap_9 r4;
      double dataIndices[2];
      double domainRatioValues_tmp;
      int loop_ub;

      //  Get the domain ratio for this contrast
      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backgrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(scalefactorIndex, bulkInIndex, bulkOutIndex, scalefactorValues,
               bulkInValues, bulkOutValues, scalefactor, bulkIn, bulkOut);

      //  Also need to determine which layers from the overall layers list
      //  are required for this contrast, and put them in the correct order
      //  according to geometry. We run it twice, once for each domain
      //  Apply scale factors and q shifts to the data
      b_data.set_size(data.size(0), 6);
      for (int i{0}; i < 6; i++) {
        loop_ub = data.size(0) - 1;
        for (int i1{0}; i1 <= loop_ub; i1++) {
          b_data[i1 + b_data.size(0) * i] = data[i1 + data.size(0) * i];
        }
      }

      shiftData(scalefactor, dataPresent, b_data, dataLimits, simulationLimits,
                numSimulationPoints, b_shiftedData);
      makeSimulationRange(b_shiftedData, simulationLimits, simulationXData,
                          dataIndices);
      constructBackground(backgroundType_data, backgroundType_size,
                          backgroundParamIndex_data, backgroundParamIndex_size,
                          b_shiftedData, customFiles, backgroundParamValues,
                          simulationXData, dataIndices, background);
      constructResolution(resolutionType_data, resolutionType_size,
                          resolutionParamIndex_data, resolutionParamIndex_size,
                          b_shiftedData, resolutionParamValues, simulationXData,
                          dataIndices, resolution);

      //  Call the core layers calculation - need to do this once for each
      //  domain
      allocateLayersForContrast(domainLayersIndices1, layerValues, b_data);
      normalTF::coreLayersCalculation(b_data, roughness, geometry_data,
        geometry_size, bulkIn, bulkOut, resample, calcSld, b_shiftedData,
        simulationXData, dataIndices, repeatLayers, resolution, background,
        backgroundAction_data, backgroundAction_size, parallel_data,
        parallel_size, resampleMinAngle, resampleNPoints, reflectivity1,
        simulation1, a__3, r.f1, r1.f1, r2.f1);
      allocateLayersForContrast(domainLayersIndices2, layerValues, b_data);
      normalTF::coreLayersCalculation(b_data, roughness, geometry_data,
        geometry_size, bulkIn, bulkOut, resample, calcSld, b_shiftedData,
        simulationXData, dataIndices, repeatLayers, resolution, background,
        backgroundAction_data, backgroundAction_size, parallel_data,
        parallel_size, resampleMinAngle, resampleNPoints, reflectivity2,
        simulation2, shiftedData, r3.f1, r4.f1, r5.f1);

      //  Calculate the average reflectivities
      //  Calculates the averaged reflectivity for domains samples (incoherent
      //  sum)
      if (reflectivity1.size(0) == reflectivity2.size(0)) {
        domainRatioValues_tmp = domainRatioValues[static_cast<int>
          (domainRatioIndex) - 1];
        reflectivity.set_size(reflectivity1.size(0), 2);
        loop_ub = reflectivity1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          reflectivity[i] = reflectivity1[i];
          reflectivity[i + reflectivity.size(0)] = domainRatioValues_tmp *
            reflectivity1[i + reflectivity1.size(0)] + (1.0 -
            domainRatioValues_tmp) * reflectivity2[i + reflectivity2.size(0)];
        }
      } else {
        binary_expand_op(reflectivity, reflectivity1, domainRatioValues,
                         domainRatioIndex, reflectivity2);
      }

      if (simulation1.size(0) == simulation2.size(0)) {
        domainRatioValues_tmp = domainRatioValues[static_cast<int>
          (domainRatioIndex) - 1];
        simulation.set_size(simulation1.size(0), 2);
        loop_ub = simulation1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          simulation[i] = simulation1[i];
          simulation[i + simulation.size(0)] = domainRatioValues_tmp *
            simulation1[i + simulation1.size(0)] + (1.0 - domainRatioValues_tmp)
            * simulation2[i + simulation2.size(0)];
        }
      } else {
        binary_expand_op(simulation, simulation1, domainRatioValues,
                         domainRatioIndex, simulation2);
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
      return 0.0;
    }

    void b_standardLayers(const ProblemDefinition &problemStruct, const Controls
                          *controls, ::coder::array<double, 1U> &qzshifts, ::
                          coder::array<double, 1U> &scalefactors, ::coder::array<
                          double, 1U> &bulkIns, ::coder::array<double, 1U>
                          &bulkOuts, ::coder::array<double, 1U> &chis, ::coder::
                          array<cell_wrap_7, 1U> &reflectivity, ::coder::array<
                          cell_wrap_7, 1U> &simulation, ::coder::array<
                          cell_wrap_8, 1U> &shiftedData, ::coder::array<
                          cell_wrap_8, 1U> &backgrounds, ::coder::array<
                          cell_wrap_7, 1U> &resolutions, ::coder::array<
                          cell_wrap_9, 2U> &domainSldProfiles, ::coder::array<
                          cell_wrap_9, 2U> &domainLayers, ::coder::array<
                          cell_wrap_9, 2U> &domainResampledLayers, ::coder::
                          array<double, 1U> &subRoughs)
    {
      ::coder::array<cell_wrap_51, 2U> layerValues;
      ::coder::array<cell_wrap_62, 1U> sldProfiles;
      ::coder::array<cell_wrap_63, 1U> layers;
      ::coder::array<cell_wrap_65, 1U> resampledLayers;
      ::coder::array<cell_wrap_9, 1U> domainContrastLayers1;
      ::coder::array<cell_wrap_9, 1U> domainContrastLayers2;
      ::coder::array<double, 2U> r;
      double dv2[2];
      double dv3[2];
      double d;
      double d1;
      double d2;
      double d3;
      double numSimulationPoints;
      double resampleMinAngle;
      double resampleNPoints;
      int iv5[2];
      int iv6[2];
      int iv7[2];
      int iv8[2];
      int iv9[2];
      int b_loop_ub;
      int loop_ub;
      int nParams;
      int unnamed_idx_0_tmp_tmp_tmp;
      boolean_T calcSld;
      boolean_T useImaginary;

      //  This is the main reflectivity calculation of the standard layers
      //  calculation type. It extracts the required parameters for the contrasts
      //  from the input arrays, then passes the main calculation to
      //  'coreLayersCalculation', which carries out the calculation itself.
      //  The core calculation is common for both standard and custom layers.
      //  Extract parameters from problemStruct
      useImaginary = problemStruct.useImaginary;

      //  qzshifts are not included as a parameter in RAT, so we set up dummy
      //  values for the reflectivity calculation
      nParams = problemStruct.params.size(1);
      calcSld = controls->calcSldDuringFit;
      numSimulationPoints = controls->numSimulationPoints;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Allocate the memory for the output arrays before the main loop
      unnamed_idx_0_tmp_tmp_tmp = static_cast<int>
        (problemStruct.numberOfContrasts);

      //  First we need to allocate the absolute values of the input
      //  parameters to all the layers in the layers list. This only needs
      //  to be done once, and so is done outside the contrasts loop
      allocateParamsToLayers(problemStruct.params, problemStruct.layersDetails,
        layerValues);

      //  Substrate roughness is always first parameter for standard layers
      subRoughs.set_size(unnamed_idx_0_tmp_tmp_tmp);
      for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
        subRoughs[i] = problemStruct.params[0];
      }

      domainContrastLayers1.set_size(unnamed_idx_0_tmp_tmp_tmp);
      domainContrastLayers2.set_size(unnamed_idx_0_tmp_tmp_tmp);
      for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
        domainContrastLayers1[i].f1.set_size
          (problemStruct.domainContrastLayers[problemStruct.domainContrastLayers.size
           (0) * (static_cast<int>
                  (problemStruct.contrastLayers[problemStruct.contrastLayers.size
                   (0) * i].f1[0]) - 1)].f1.size(0),
           problemStruct.domainContrastLayers[problemStruct.domainContrastLayers.size
           (0) * (static_cast<int>
                  (problemStruct.contrastLayers[problemStruct.contrastLayers.size
                   (0) * i].f1[0]) - 1)].f1.size(1));
        loop_ub = problemStruct.domainContrastLayers[static_cast<int>
          (problemStruct.contrastLayers[i].f1[0]) - 1].f1.size(1);
        for (int b_i{0}; b_i < loop_ub; b_i++) {
          b_loop_ub = problemStruct.domainContrastLayers[static_cast<int>
            (problemStruct.contrastLayers[i].f1[0]) - 1].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainContrastLayers1[i].f1[i1 + domainContrastLayers1[i].f1.size(0)
              * b_i] = problemStruct.domainContrastLayers[static_cast<int>
              (problemStruct.contrastLayers[i].f1[0]) - 1].f1[i1 +
              problemStruct.domainContrastLayers[static_cast<int>
              (problemStruct.contrastLayers[i].f1[0]) - 1].f1.size(0) * b_i];
          }
        }

        domainContrastLayers2[i].f1.set_size
          (problemStruct.domainContrastLayers[problemStruct.domainContrastLayers.size
           (0) * (static_cast<int>
                  (problemStruct.contrastLayers[problemStruct.contrastLayers.size
                   (0) * i].f1[1]) - 1)].f1.size(0),
           problemStruct.domainContrastLayers[problemStruct.domainContrastLayers.size
           (0) * (static_cast<int>
                  (problemStruct.contrastLayers[problemStruct.contrastLayers.size
                   (0) * i].f1[1]) - 1)].f1.size(1));
        loop_ub = problemStruct.domainContrastLayers[static_cast<int>
          (problemStruct.contrastLayers[i].f1[1]) - 1].f1.size(1);
        for (int b_i{0}; b_i < loop_ub; b_i++) {
          b_loop_ub = problemStruct.domainContrastLayers[static_cast<int>
            (problemStruct.contrastLayers[i].f1[1]) - 1].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainContrastLayers2[i].f1[i1 + domainContrastLayers2[i].f1.size(0)
              * b_i] = problemStruct.domainContrastLayers[static_cast<int>
              (problemStruct.contrastLayers[i].f1[1]) - 1].f1[i1 +
              problemStruct.domainContrastLayers[static_cast<int>
              (problemStruct.contrastLayers[i].f1[1]) - 1].f1.size(0) * b_i];
          }
        }
      }

      if (coder::internal::o_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        //  Loop over all the contrasts
        resampledLayers.set_size(unnamed_idx_0_tmp_tmp_tmp);
        layers.set_size(unnamed_idx_0_tmp_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp_tmp);
        resolutions.set_size(unnamed_idx_0_tmp_tmp_tmp);
        backgrounds.set_size(unnamed_idx_0_tmp_tmp_tmp);
        shiftedData.set_size(unnamed_idx_0_tmp_tmp_tmp);
        simulation.set_size(unnamed_idx_0_tmp_tmp_tmp);
        reflectivity.set_size(unnamed_idx_0_tmp_tmp_tmp);
        qzshifts.set_size(unnamed_idx_0_tmp_tmp_tmp);
        scalefactors.set_size(unnamed_idx_0_tmp_tmp_tmp);
        bulkIns.set_size(unnamed_idx_0_tmp_tmp_tmp);
        bulkOuts.set_size(unnamed_idx_0_tmp_tmp_tmp);
        chis.set_size(unnamed_idx_0_tmp_tmp_tmp);
        loop_ub = unnamed_idx_0_tmp_tmp_tmp - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(d,d1,d2,d3,iv5,iv6,dv2,dv3,iv7,iv8,iv9)

        for (int c_i = 0; c_i <= loop_ub; c_i++) {
          iv5[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[c_i].f1)->size())[0];
          iv5[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[c_i].f1)->size())[1];
          iv6[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[c_i].f1)->size())[0];
          iv6[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[c_i].f1)->size())[1];
          dv2[0] = problemStruct.dataLimits[c_i].f1[0];
          dv2[1] = problemStruct.dataLimits[c_i].f1[1];
          dv3[0] = problemStruct.simulationLimits[c_i].f1[0];
          dv3[1] = problemStruct.simulationLimits[c_i].f1[1];
          iv7[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[c_i].f1)->size())[0];
          iv7[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[c_i].f1)->size())[1];
          iv8[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[c_i].f1)->size())
            [0];
          iv8[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[c_i].f1)->size())
            [1];
          iv9[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[c_i].f1)->size())[0];
          iv9[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[c_i].f1)->size())[1];
          contrastCalculation((const double *)((::coder::array<double, 2U> *)
            &problemStruct.contrastBackgroundParams[c_i].f1)->data(), iv5,
                              problemStruct.contrastScalefactors[c_i],
                              problemStruct.contrastBulkIns[c_i],
                              problemStruct.contrastBulkOuts[c_i], (const double
            *)((::coder::array<double, 2U> *)
               &problemStruct.contrastResolutionParams[c_i].f1)->data(), iv6,
                              problemStruct.contrastDomainRatios[c_i],
                              problemStruct.backgroundParams,
                              problemStruct.scalefactors, problemStruct.bulkIns,
                              problemStruct.bulkOuts,
                              problemStruct.resolutionParams,
                              problemStruct.domainRatios,
                              problemStruct.dataPresent[c_i],
                              problemStruct.data[c_i].f1, dv2, dv3,
                              problemStruct.repeatLayers[c_i], (const char *)((::
            coder::array<char, 2U> *)&problemStruct.contrastBackgroundTypes[c_i]
            .f1)->data(), iv7, (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[c_i].f1)->data(), iv8, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastResolutionTypes[c_i].f1)->data(),
                              iv9, problemStruct.customFiles, static_cast<double>
                              (nParams), controls->parallel.data,
                              controls->parallel.size, numSimulationPoints,
                              resampleMinAngle, resampleNPoints,
                              problemStruct.resample[c_i],
                              problemStruct.geometry.data,
                              problemStruct.geometry.size, subRoughs[c_i],
                              calcSld, domainContrastLayers1[c_i].f1,
                              domainContrastLayers2[c_i].f1, layerValues,
                              reflectivity[c_i].f1, simulation[c_i].f1,
                              shiftedData[c_i].f1, backgrounds[c_i].f1,
                              resolutions[c_i].f1, sldProfiles[c_i].f1,
                              layers[c_i].f1, resampledLayers[c_i].f1, d3, d2,
                              d1, d);
          qzshifts[c_i] = 0.0;
          scalefactors[c_i] = d3;
          bulkIns[c_i] = d2;
          bulkOuts[c_i] = d1;
          chis[c_i] = d;
        }
      } else {
        //  Loop over all the contrasts
        resampledLayers.set_size(unnamed_idx_0_tmp_tmp_tmp);
        layers.set_size(unnamed_idx_0_tmp_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp_tmp);
        resolutions.set_size(unnamed_idx_0_tmp_tmp_tmp);
        backgrounds.set_size(unnamed_idx_0_tmp_tmp_tmp);
        shiftedData.set_size(unnamed_idx_0_tmp_tmp_tmp);
        simulation.set_size(unnamed_idx_0_tmp_tmp_tmp);
        reflectivity.set_size(unnamed_idx_0_tmp_tmp_tmp);
        qzshifts.set_size(unnamed_idx_0_tmp_tmp_tmp);
        scalefactors.set_size(unnamed_idx_0_tmp_tmp_tmp);
        bulkIns.set_size(unnamed_idx_0_tmp_tmp_tmp);
        bulkOuts.set_size(unnamed_idx_0_tmp_tmp_tmp);
        chis.set_size(unnamed_idx_0_tmp_tmp_tmp);
        for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
          double b_dv[2];
          double b_dv1[2];
          double d4;
          double d5;
          double d6;
          double d7;
          int iv[2];
          int iv1[2];
          int iv2[2];
          int iv3[2];
          int iv4[2];
          iv[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct.contrastBackgroundParams[i].f1)->size())[0];
          iv[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct.contrastBackgroundParams[i].f1)->size())[1];
          iv1[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[i].f1)->size())[0];
          iv1[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[i].f1)->size())[1];
          b_dv[0] = problemStruct.dataLimits[i].f1[0];
          b_dv[1] = problemStruct.dataLimits[i].f1[1];
          b_dv1[0] = problemStruct.simulationLimits[i].f1[0];
          b_dv1[1] = problemStruct.simulationLimits[i].f1[1];
          iv2[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[i].f1)->size())[0];
          iv2[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[i].f1)->size())[1];
          iv3[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[i].f1)->size())[0];
          iv3[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[i].f1)->size())[1];
          iv4[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[i].f1)->size())[0];
          iv4[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[i].f1)->size())[1];
          contrastCalculation((const double *)((::coder::array<double, 2U> *)
            &problemStruct.contrastBackgroundParams[i].f1)->data(), iv,
                              problemStruct.contrastScalefactors[i],
                              problemStruct.contrastBulkIns[i],
                              problemStruct.contrastBulkOuts[i], (const double *)
                              ((::coder::array<double, 2U> *)
                               &problemStruct.contrastResolutionParams[i].f1)
                              ->data(), iv1,
                              problemStruct.contrastDomainRatios[i],
                              problemStruct.backgroundParams,
                              problemStruct.scalefactors, problemStruct.bulkIns,
                              problemStruct.bulkOuts,
                              problemStruct.resolutionParams,
                              problemStruct.domainRatios,
                              problemStruct.dataPresent[i], problemStruct.data[i]
                              .f1, b_dv, b_dv1, problemStruct.repeatLayers[i], (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastBackgroundTypes[i].f1)->data(),
                              iv2, (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[i].f1)->data(), iv3, (const
            char *)((::coder::array<char, 2U> *)
                    &problemStruct.contrastResolutionTypes[i].f1)->data(), iv4,
                              problemStruct.customFiles, static_cast<double>
                              (problemStruct.params.size(1)),
                              controls->parallel.data, controls->parallel.size,
                              numSimulationPoints, resampleMinAngle,
                              resampleNPoints, problemStruct.resample[i],
                              problemStruct.geometry.data,
                              problemStruct.geometry.size, subRoughs[i], calcSld,
                              domainContrastLayers1[i].f1,
                              domainContrastLayers2[i].f1, layerValues,
                              reflectivity[i].f1, simulation[i].f1,
                              shiftedData[i].f1, backgrounds[i].f1,
                              resolutions[i].f1, sldProfiles[i].f1, layers[i].f1,
                              resampledLayers[i].f1, d4, d5, d6, d7);
          chis[i] = d7;
          bulkOuts[i] = d6;
          bulkIns[i] = d5;
          scalefactors[i] = d4;
          qzshifts[i] = 0.0;
        }
      }

      domainSldProfiles.set_size(unnamed_idx_0_tmp_tmp_tmp, 2);
      domainLayers.set_size(unnamed_idx_0_tmp_tmp_tmp, 2);
      domainResampledLayers.set_size(unnamed_idx_0_tmp_tmp_tmp, 2);
      for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
        loop_ub = sldProfiles[i].f1[0].f1.size(0);
        domainSldProfiles[i].f1.set_size(sldProfiles[i].f1[0].f1.size(0), 2);
        b_loop_ub = sldProfiles[i].f1[1].f1.size(0);
        domainSldProfiles[i + domainSldProfiles.size(0)].f1.set_size
          (sldProfiles[i].f1[1].f1.size(0), 2);
        for (int b_i{0}; b_i < 2; b_i++) {
          for (int i1{0}; i1 < loop_ub; i1++) {
            domainSldProfiles[i].f1[i1 + domainSldProfiles[i].f1.size(0) * b_i] =
              sldProfiles[i].f1[0].f1[i1 + sldProfiles[i].f1[0].f1.size(0) * b_i];
          }

          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainSldProfiles[i + domainSldProfiles.size(0)].f1[i1 +
              domainSldProfiles[i + domainSldProfiles.size(0)].f1.size(0) * b_i]
              = sldProfiles[i].f1[1].f1[i1 + sldProfiles[i].f1[1].f1.size(0) *
              b_i];
          }
        }

        loop_ub = layers[i].f1[0].f1.size(1);
        domainLayers[i].f1.set_size(layers[i].f1[0].f1.size(0), layers[i].f1[0].
          f1.size(1));
        for (int b_i{0}; b_i < loop_ub; b_i++) {
          b_loop_ub = layers[i].f1[0].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainLayers[i].f1[i1 + domainLayers[i].f1.size(0) * b_i] = layers[i]
              .f1[0].f1[i1 + layers[i].f1[0].f1.size(0) * b_i];
          }
        }

        loop_ub = layers[i].f1[1].f1.size(1);
        domainLayers[i + domainLayers.size(0)].f1.set_size(layers[i].f1[1].
          f1.size(0), layers[i].f1[1].f1.size(1));
        for (int b_i{0}; b_i < loop_ub; b_i++) {
          b_loop_ub = layers[i].f1[1].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainLayers[i + domainLayers.size(0)].f1[i1 + domainLayers[i +
              domainLayers.size(0)].f1.size(0) * b_i] = layers[i].f1[1].f1[i1 +
              layers[i].f1[1].f1.size(0) * b_i];
          }
        }

        loop_ub = resampledLayers[i].f1[0].f1.size(0);
        domainResampledLayers[i].f1.set_size(resampledLayers[i].f1[0].f1.size(0),
          4);
        b_loop_ub = resampledLayers[i].f1[1].f1.size(0);
        domainResampledLayers[i + domainResampledLayers.size(0)].f1.set_size
          (resampledLayers[i].f1[1].f1.size(0), 4);
        for (int b_i{0}; b_i < 4; b_i++) {
          for (int i1{0}; i1 < loop_ub; i1++) {
            domainResampledLayers[i].f1[i1 + domainResampledLayers[i].f1.size(0)
              * b_i] = resampledLayers[i].f1[0].f1[i1 + resampledLayers[i].f1[0]
              .f1.size(0) * b_i];
          }

          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainResampledLayers[i + domainResampledLayers.size(0)].f1[i1 +
              domainResampledLayers[i + domainResampledLayers.size(0)].f1.size(0)
              * b_i] = resampledLayers[i].f1[1].f1[i1 + resampledLayers[i].f1[1]
              .f1.size(0) * b_i];
          }
        }
      }

      //  Remove dummy imaginary column if present
      if (!useImaginary) {
        for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
          coder::internal::nullAssignment(domainLayers[i].f1);
          coder::internal::nullAssignment(domainLayers[i + domainLayers.size(0)]
            .f1);
          coder::internal::nullAssignment(domainResampledLayers[i].f1, r);
          domainResampledLayers[i].f1.set_size(r.size(0), 3);
          loop_ub = r.size(0);
          for (int b_i{0}; b_i < 3; b_i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              domainResampledLayers[i].f1[i1 + domainResampledLayers[i].f1.size
                (0) * b_i] = r[i1 + r.size(0) * b_i];
            }
          }

          coder::internal::nullAssignment(domainResampledLayers[i +
            domainResampledLayers.size(0)].f1);
        }
      }
    }

    void standardLayers(const ProblemDefinition &problemStruct, const Controls
                        *controls, ::coder::array<double, 1U> &qzshifts, ::coder::
                        array<double, 1U> &scalefactors, ::coder::array<double,
                        1U> &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::
                        coder::array<double, 1U> &chis, ::coder::array<
                        cell_wrap_7, 1U> &reflectivity, ::coder::array<
                        cell_wrap_7, 1U> &simulation, ::coder::array<cell_wrap_8,
                        1U> &shiftedData, ::coder::array<cell_wrap_8, 1U>
                        &backgrounds, ::coder::array<cell_wrap_7, 1U>
                        &resolutions, ::coder::array<cell_wrap_9, 2U>
                        &domainSldProfiles, ::coder::array<cell_wrap_9, 2U>
                        &domainLayers, ::coder::array<cell_wrap_9, 2U>
                        &domainResampledLayers, ::coder::array<double, 1U>
                        &subRoughs)
    {
      ::coder::array<cell_wrap_51, 2U> layerValues;
      ::coder::array<cell_wrap_62, 1U> sldProfiles;
      ::coder::array<cell_wrap_63, 1U> layers;
      ::coder::array<cell_wrap_65, 1U> resampledLayers;
      ::coder::array<cell_wrap_9, 1U> domainContrastLayers1;
      ::coder::array<cell_wrap_9, 1U> domainContrastLayers2;
      ::coder::array<double, 2U> r;
      double dv2[2];
      double dv3[2];
      double d;
      double d1;
      double d2;
      double d3;
      double numSimulationPoints;
      double resampleMinAngle;
      double resampleNPoints;
      int iv5[2];
      int iv6[2];
      int iv7[2];
      int iv8[2];
      int iv9[2];
      int b_loop_ub;
      int loop_ub;
      int nParams;
      int unnamed_idx_0_tmp_tmp_tmp;
      boolean_T useImaginary;

      //  This is the main reflectivity calculation of the standard layers
      //  calculation type. It extracts the required parameters for the contrasts
      //  from the input arrays, then passes the main calculation to
      //  'coreLayersCalculation', which carries out the calculation itself.
      //  The core calculation is common for both standard and custom layers.
      //  Extract parameters from problemStruct
      useImaginary = problemStruct.useImaginary;

      //  qzshifts are not included as a parameter in RAT, so we set up dummy
      //  values for the reflectivity calculation
      nParams = problemStruct.params.size(1);
      numSimulationPoints = controls->numSimulationPoints;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Allocate the memory for the output arrays before the main loop
      unnamed_idx_0_tmp_tmp_tmp = static_cast<int>
        (problemStruct.numberOfContrasts);

      //  First we need to allocate the absolute values of the input
      //  parameters to all the layers in the layers list. This only needs
      //  to be done once, and so is done outside the contrasts loop
      allocateParamsToLayers(problemStruct.params, problemStruct.layersDetails,
        layerValues);

      //  Substrate roughness is always first parameter for standard layers
      subRoughs.set_size(unnamed_idx_0_tmp_tmp_tmp);
      for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
        subRoughs[i] = problemStruct.params[0];
      }

      domainContrastLayers1.set_size(unnamed_idx_0_tmp_tmp_tmp);
      domainContrastLayers2.set_size(unnamed_idx_0_tmp_tmp_tmp);
      for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
        domainContrastLayers1[i].f1.set_size
          (problemStruct.domainContrastLayers[problemStruct.domainContrastLayers.size
           (0) * (static_cast<int>
                  (problemStruct.contrastLayers[problemStruct.contrastLayers.size
                   (0) * i].f1[0]) - 1)].f1.size(0),
           problemStruct.domainContrastLayers[problemStruct.domainContrastLayers.size
           (0) * (static_cast<int>
                  (problemStruct.contrastLayers[problemStruct.contrastLayers.size
                   (0) * i].f1[0]) - 1)].f1.size(1));
        loop_ub = problemStruct.domainContrastLayers[static_cast<int>
          (problemStruct.contrastLayers[i].f1[0]) - 1].f1.size(1);
        for (int b_i{0}; b_i < loop_ub; b_i++) {
          b_loop_ub = problemStruct.domainContrastLayers[static_cast<int>
            (problemStruct.contrastLayers[i].f1[0]) - 1].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainContrastLayers1[i].f1[i1 + domainContrastLayers1[i].f1.size(0)
              * b_i] = problemStruct.domainContrastLayers[static_cast<int>
              (problemStruct.contrastLayers[i].f1[0]) - 1].f1[i1 +
              problemStruct.domainContrastLayers[static_cast<int>
              (problemStruct.contrastLayers[i].f1[0]) - 1].f1.size(0) * b_i];
          }
        }

        domainContrastLayers2[i].f1.set_size
          (problemStruct.domainContrastLayers[problemStruct.domainContrastLayers.size
           (0) * (static_cast<int>
                  (problemStruct.contrastLayers[problemStruct.contrastLayers.size
                   (0) * i].f1[1]) - 1)].f1.size(0),
           problemStruct.domainContrastLayers[problemStruct.domainContrastLayers.size
           (0) * (static_cast<int>
                  (problemStruct.contrastLayers[problemStruct.contrastLayers.size
                   (0) * i].f1[1]) - 1)].f1.size(1));
        loop_ub = problemStruct.domainContrastLayers[static_cast<int>
          (problemStruct.contrastLayers[i].f1[1]) - 1].f1.size(1);
        for (int b_i{0}; b_i < loop_ub; b_i++) {
          b_loop_ub = problemStruct.domainContrastLayers[static_cast<int>
            (problemStruct.contrastLayers[i].f1[1]) - 1].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainContrastLayers2[i].f1[i1 + domainContrastLayers2[i].f1.size(0)
              * b_i] = problemStruct.domainContrastLayers[static_cast<int>
              (problemStruct.contrastLayers[i].f1[1]) - 1].f1[i1 +
              problemStruct.domainContrastLayers[static_cast<int>
              (problemStruct.contrastLayers[i].f1[1]) - 1].f1.size(0) * b_i];
          }
        }
      }

      if (coder::internal::o_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        //  Loop over all the contrasts
        resampledLayers.set_size(unnamed_idx_0_tmp_tmp_tmp);
        layers.set_size(unnamed_idx_0_tmp_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp_tmp);
        resolutions.set_size(unnamed_idx_0_tmp_tmp_tmp);
        backgrounds.set_size(unnamed_idx_0_tmp_tmp_tmp);
        shiftedData.set_size(unnamed_idx_0_tmp_tmp_tmp);
        simulation.set_size(unnamed_idx_0_tmp_tmp_tmp);
        reflectivity.set_size(unnamed_idx_0_tmp_tmp_tmp);
        qzshifts.set_size(unnamed_idx_0_tmp_tmp_tmp);
        scalefactors.set_size(unnamed_idx_0_tmp_tmp_tmp);
        bulkIns.set_size(unnamed_idx_0_tmp_tmp_tmp);
        bulkOuts.set_size(unnamed_idx_0_tmp_tmp_tmp);
        chis.set_size(unnamed_idx_0_tmp_tmp_tmp);
        loop_ub = unnamed_idx_0_tmp_tmp_tmp - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(d,d1,d2,d3,iv5,iv6,dv2,dv3,iv7,iv8,iv9)

        for (int c_i = 0; c_i <= loop_ub; c_i++) {
          iv5[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[c_i].f1)->size())[0];
          iv5[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[c_i].f1)->size())[1];
          iv6[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[c_i].f1)->size())[0];
          iv6[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[c_i].f1)->size())[1];
          dv2[0] = problemStruct.dataLimits[c_i].f1[0];
          dv2[1] = problemStruct.dataLimits[c_i].f1[1];
          dv3[0] = problemStruct.simulationLimits[c_i].f1[0];
          dv3[1] = problemStruct.simulationLimits[c_i].f1[1];
          iv7[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[c_i].f1)->size())[0];
          iv7[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[c_i].f1)->size())[1];
          iv8[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[c_i].f1)->size())
            [0];
          iv8[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[c_i].f1)->size())
            [1];
          iv9[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[c_i].f1)->size())[0];
          iv9[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[c_i].f1)->size())[1];
          contrastCalculation((const double *)((::coder::array<double, 2U> *)
            &problemStruct.contrastBackgroundParams[c_i].f1)->data(), iv5,
                              problemStruct.contrastScalefactors[c_i],
                              problemStruct.contrastBulkIns[c_i],
                              problemStruct.contrastBulkOuts[c_i], (const double
            *)((::coder::array<double, 2U> *)
               &problemStruct.contrastResolutionParams[c_i].f1)->data(), iv6,
                              problemStruct.contrastDomainRatios[c_i],
                              problemStruct.backgroundParams,
                              problemStruct.scalefactors, problemStruct.bulkIns,
                              problemStruct.bulkOuts,
                              problemStruct.resolutionParams,
                              problemStruct.domainRatios,
                              problemStruct.dataPresent[c_i],
                              problemStruct.data[c_i].f1, dv2, dv3,
                              problemStruct.repeatLayers[c_i], (const char *)((::
            coder::array<char, 2U> *)&problemStruct.contrastBackgroundTypes[c_i]
            .f1)->data(), iv7, (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[c_i].f1)->data(), iv8, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastResolutionTypes[c_i].f1)->data(),
                              iv9, problemStruct.customFiles, static_cast<double>
                              (nParams), controls->parallel.data,
                              controls->parallel.size, numSimulationPoints,
                              resampleMinAngle, resampleNPoints,
                              problemStruct.resample[c_i],
                              problemStruct.geometry.data,
                              problemStruct.geometry.size, subRoughs[c_i], true,
                              domainContrastLayers1[c_i].f1,
                              domainContrastLayers2[c_i].f1, layerValues,
                              reflectivity[c_i].f1, simulation[c_i].f1,
                              shiftedData[c_i].f1, backgrounds[c_i].f1,
                              resolutions[c_i].f1, sldProfiles[c_i].f1,
                              layers[c_i].f1, resampledLayers[c_i].f1, d3, d2,
                              d1, d);
          qzshifts[c_i] = 0.0;
          scalefactors[c_i] = d3;
          bulkIns[c_i] = d2;
          bulkOuts[c_i] = d1;
          chis[c_i] = d;
        }
      } else {
        //  Loop over all the contrasts
        resampledLayers.set_size(unnamed_idx_0_tmp_tmp_tmp);
        layers.set_size(unnamed_idx_0_tmp_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp_tmp);
        resolutions.set_size(unnamed_idx_0_tmp_tmp_tmp);
        backgrounds.set_size(unnamed_idx_0_tmp_tmp_tmp);
        shiftedData.set_size(unnamed_idx_0_tmp_tmp_tmp);
        simulation.set_size(unnamed_idx_0_tmp_tmp_tmp);
        reflectivity.set_size(unnamed_idx_0_tmp_tmp_tmp);
        qzshifts.set_size(unnamed_idx_0_tmp_tmp_tmp);
        scalefactors.set_size(unnamed_idx_0_tmp_tmp_tmp);
        bulkIns.set_size(unnamed_idx_0_tmp_tmp_tmp);
        bulkOuts.set_size(unnamed_idx_0_tmp_tmp_tmp);
        chis.set_size(unnamed_idx_0_tmp_tmp_tmp);
        for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
          double b_dv[2];
          double b_dv1[2];
          double d4;
          double d5;
          double d6;
          double d7;
          int iv[2];
          int iv1[2];
          int iv2[2];
          int iv3[2];
          int iv4[2];
          iv[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct.contrastBackgroundParams[i].f1)->size())[0];
          iv[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct.contrastBackgroundParams[i].f1)->size())[1];
          iv1[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[i].f1)->size())[0];
          iv1[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[i].f1)->size())[1];
          b_dv[0] = problemStruct.dataLimits[i].f1[0];
          b_dv[1] = problemStruct.dataLimits[i].f1[1];
          b_dv1[0] = problemStruct.simulationLimits[i].f1[0];
          b_dv1[1] = problemStruct.simulationLimits[i].f1[1];
          iv2[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[i].f1)->size())[0];
          iv2[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[i].f1)->size())[1];
          iv3[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[i].f1)->size())[0];
          iv3[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[i].f1)->size())[1];
          iv4[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[i].f1)->size())[0];
          iv4[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[i].f1)->size())[1];
          contrastCalculation((const double *)((::coder::array<double, 2U> *)
            &problemStruct.contrastBackgroundParams[i].f1)->data(), iv,
                              problemStruct.contrastScalefactors[i],
                              problemStruct.contrastBulkIns[i],
                              problemStruct.contrastBulkOuts[i], (const double *)
                              ((::coder::array<double, 2U> *)
                               &problemStruct.contrastResolutionParams[i].f1)
                              ->data(), iv1,
                              problemStruct.contrastDomainRatios[i],
                              problemStruct.backgroundParams,
                              problemStruct.scalefactors, problemStruct.bulkIns,
                              problemStruct.bulkOuts,
                              problemStruct.resolutionParams,
                              problemStruct.domainRatios,
                              problemStruct.dataPresent[i], problemStruct.data[i]
                              .f1, b_dv, b_dv1, problemStruct.repeatLayers[i], (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastBackgroundTypes[i].f1)->data(),
                              iv2, (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[i].f1)->data(), iv3, (const
            char *)((::coder::array<char, 2U> *)
                    &problemStruct.contrastResolutionTypes[i].f1)->data(), iv4,
                              problemStruct.customFiles, static_cast<double>
                              (problemStruct.params.size(1)),
                              controls->parallel.data, controls->parallel.size,
                              numSimulationPoints, resampleMinAngle,
                              resampleNPoints, problemStruct.resample[i],
                              problemStruct.geometry.data,
                              problemStruct.geometry.size, subRoughs[i], true,
                              domainContrastLayers1[i].f1,
                              domainContrastLayers2[i].f1, layerValues,
                              reflectivity[i].f1, simulation[i].f1,
                              shiftedData[i].f1, backgrounds[i].f1,
                              resolutions[i].f1, sldProfiles[i].f1, layers[i].f1,
                              resampledLayers[i].f1, d4, d5, d6, d7);
          chis[i] = d7;
          bulkOuts[i] = d6;
          bulkIns[i] = d5;
          scalefactors[i] = d4;
          qzshifts[i] = 0.0;
        }
      }

      domainSldProfiles.set_size(unnamed_idx_0_tmp_tmp_tmp, 2);
      domainLayers.set_size(unnamed_idx_0_tmp_tmp_tmp, 2);
      domainResampledLayers.set_size(unnamed_idx_0_tmp_tmp_tmp, 2);
      for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
        loop_ub = sldProfiles[i].f1[0].f1.size(0);
        domainSldProfiles[i].f1.set_size(sldProfiles[i].f1[0].f1.size(0), 2);
        b_loop_ub = sldProfiles[i].f1[1].f1.size(0);
        domainSldProfiles[i + domainSldProfiles.size(0)].f1.set_size
          (sldProfiles[i].f1[1].f1.size(0), 2);
        for (int b_i{0}; b_i < 2; b_i++) {
          for (int i1{0}; i1 < loop_ub; i1++) {
            domainSldProfiles[i].f1[i1 + domainSldProfiles[i].f1.size(0) * b_i] =
              sldProfiles[i].f1[0].f1[i1 + sldProfiles[i].f1[0].f1.size(0) * b_i];
          }

          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainSldProfiles[i + domainSldProfiles.size(0)].f1[i1 +
              domainSldProfiles[i + domainSldProfiles.size(0)].f1.size(0) * b_i]
              = sldProfiles[i].f1[1].f1[i1 + sldProfiles[i].f1[1].f1.size(0) *
              b_i];
          }
        }

        loop_ub = layers[i].f1[0].f1.size(1);
        domainLayers[i].f1.set_size(layers[i].f1[0].f1.size(0), layers[i].f1[0].
          f1.size(1));
        for (int b_i{0}; b_i < loop_ub; b_i++) {
          b_loop_ub = layers[i].f1[0].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainLayers[i].f1[i1 + domainLayers[i].f1.size(0) * b_i] = layers[i]
              .f1[0].f1[i1 + layers[i].f1[0].f1.size(0) * b_i];
          }
        }

        loop_ub = layers[i].f1[1].f1.size(1);
        domainLayers[i + domainLayers.size(0)].f1.set_size(layers[i].f1[1].
          f1.size(0), layers[i].f1[1].f1.size(1));
        for (int b_i{0}; b_i < loop_ub; b_i++) {
          b_loop_ub = layers[i].f1[1].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainLayers[i + domainLayers.size(0)].f1[i1 + domainLayers[i +
              domainLayers.size(0)].f1.size(0) * b_i] = layers[i].f1[1].f1[i1 +
              layers[i].f1[1].f1.size(0) * b_i];
          }
        }

        loop_ub = resampledLayers[i].f1[0].f1.size(0);
        domainResampledLayers[i].f1.set_size(resampledLayers[i].f1[0].f1.size(0),
          4);
        b_loop_ub = resampledLayers[i].f1[1].f1.size(0);
        domainResampledLayers[i + domainResampledLayers.size(0)].f1.set_size
          (resampledLayers[i].f1[1].f1.size(0), 4);
        for (int b_i{0}; b_i < 4; b_i++) {
          for (int i1{0}; i1 < loop_ub; i1++) {
            domainResampledLayers[i].f1[i1 + domainResampledLayers[i].f1.size(0)
              * b_i] = resampledLayers[i].f1[0].f1[i1 + resampledLayers[i].f1[0]
              .f1.size(0) * b_i];
          }

          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainResampledLayers[i + domainResampledLayers.size(0)].f1[i1 +
              domainResampledLayers[i + domainResampledLayers.size(0)].f1.size(0)
              * b_i] = resampledLayers[i].f1[1].f1[i1 + resampledLayers[i].f1[1]
              .f1.size(0) * b_i];
          }
        }
      }

      //  Remove dummy imaginary column if present
      if (!useImaginary) {
        for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
          coder::internal::nullAssignment(domainLayers[i].f1);
          coder::internal::nullAssignment(domainLayers[i + domainLayers.size(0)]
            .f1);
          coder::internal::nullAssignment(domainResampledLayers[i].f1, r);
          domainResampledLayers[i].f1.set_size(r.size(0), 3);
          loop_ub = r.size(0);
          for (int b_i{0}; b_i < 3; b_i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              domainResampledLayers[i].f1[i1 + domainResampledLayers[i].f1.size
                (0) * b_i] = r[i1 + r.size(0) * b_i];
            }
          }

          coder::internal::nullAssignment(domainResampledLayers[i +
            domainResampledLayers.size(0)].f1);
        }
      }
    }
  }
}

// End of code generation (standardLayers1.cpp)
