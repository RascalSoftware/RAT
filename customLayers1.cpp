//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// customLayers1.cpp
//
// Code generation for function 'customLayers1'
//

// Include files
#include "customLayers1.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "backSort.h"
#include "chiSquared.h"
#include "constructBackground.h"
#include "constructResolution.h"
#include "coreLayersCalculation.h"
#include "extractProblemParams.h"
#include "makeSimulationRange.h"
#include "processCustomFunction2.h"
#include "rt_nonfinite.h"
#include "shiftData.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Declarations
namespace RAT
{
  namespace domainsTF
  {
    static void b_contrastCalculation(const double backgroundParamIndex_data[],
      const int backgroundParamIndex_size[2], double qzshiftIndex, double
      scalefactorIndex, double bulkInIndex, double bulkOutIndex, const double
      resolutionParamIndex_data[], const int resolutionParamIndex_size[2],
      double domainRatioIndex, const ::coder::array<double, 2U>
      &backgroundParams, const ::coder::array<double, 2U> &qzshifts, const ::
      coder::array<double, 2U> &scalefactors, const ::coder::array<double, 2U>
      &bulkIns, const ::coder::array<double, 2U> &bulkOuts, const ::coder::array<
      double, 2U> &resolutionParams, const ::coder::array<double, 2U>
      &domainRatios, double dataPresent, const ::coder::array<double, 2U> &data,
      const double dataLimits[2], const double simLimits[2], const double
      repeatLayers[2], const char backgroundType_data[], const int
      backgroundType_size[2], const char backgroundAction_data[], const int
      backgroundAction_size[2], const char resolutionType_data[], const int
      resolutionType_size[2], const ::coder::array<cell_wrap_10, 2U>
      &customFiles, double nParams, const char parallel_data[], const int
      parallel_size[2], double resampleMinAngle, double resampleNPoints,
      boolean_T useImaginary, double resample, const char geometry_data[], const
      int geometry_size[2], double roughness, boolean_T calcSld, const ::coder::
      array<double, 2U> &calcAllLayers1, const ::coder::array<double, 2U>
      &calcAllLayers2, double *qzshiftValue, double *scalefactorValue, double
      *bulkInValue, double *bulkOutValue, double *chi, ::coder::array<double, 2U>
      &reflectivity, ::coder::array<double, 2U> &simulation, ::coder::array<
      double, 2U> &shiftedData, ::coder::array<double, 2U> &background, ::coder::
      array<double, 2U> &resolution, cell_wrap_9 layerSld[2], cell_wrap_7
      sldProfile[2], cell_wrap_9 resampledLayer[2]);
  }
}

// Function Definitions
namespace RAT
{
  namespace domainsTF
  {
    static void b_contrastCalculation(const double backgroundParamIndex_data[],
      const int backgroundParamIndex_size[2], double qzshiftIndex, double
      scalefactorIndex, double bulkInIndex, double bulkOutIndex, const double
      resolutionParamIndex_data[], const int resolutionParamIndex_size[2],
      double domainRatioIndex, const ::coder::array<double, 2U>
      &backgroundParams, const ::coder::array<double, 2U> &qzshifts, const ::
      coder::array<double, 2U> &scalefactors, const ::coder::array<double, 2U>
      &bulkIns, const ::coder::array<double, 2U> &bulkOuts, const ::coder::array<
      double, 2U> &resolutionParams, const ::coder::array<double, 2U>
      &domainRatios, double dataPresent, const ::coder::array<double, 2U> &data,
      const double dataLimits[2], const double simLimits[2], const double
      repeatLayers[2], const char backgroundType_data[], const int
      backgroundType_size[2], const char backgroundAction_data[], const int
      backgroundAction_size[2], const char resolutionType_data[], const int
      resolutionType_size[2], const ::coder::array<cell_wrap_10, 2U>
      &customFiles, double nParams, const char parallel_data[], const int
      parallel_size[2], double resampleMinAngle, double resampleNPoints,
      boolean_T useImaginary, double resample, const char geometry_data[], const
      int geometry_size[2], double roughness, boolean_T calcSld, const ::coder::
      array<double, 2U> &calcAllLayers1, const ::coder::array<double, 2U>
      &calcAllLayers2, double *qzshiftValue, double *scalefactorValue, double
      *bulkInValue, double *bulkOutValue, double *chi, ::coder::array<double, 2U>
      &reflectivity, ::coder::array<double, 2U> &simulation, ::coder::array<
      double, 2U> &shiftedData, ::coder::array<double, 2U> &background, ::coder::
      array<double, 2U> &resolution, cell_wrap_9 layerSld[2], cell_wrap_7
      sldProfile[2], cell_wrap_9 resampledLayer[2])
    {
      ::coder::array<double, 2U> a__5;
      ::coder::array<double, 2U> b_data;
      ::coder::array<double, 2U> b_shiftedData;
      ::coder::array<double, 2U> reflect1;
      ::coder::array<double, 2U> reflect2;
      ::coder::array<double, 2U> simul1;
      ::coder::array<double, 2U> simul2;
      ::coder::array<double, 1U> simulationXData;
      cell_wrap_7 r;
      cell_wrap_7 r3;
      cell_wrap_9 r1;
      cell_wrap_9 r2;
      cell_wrap_9 r4;
      cell_wrap_9 r5;
      double dataIndices[2];
      double a__6;
      double a__7;
      double domainRatios_tmp;
      int b_loop_ub;
      int i;
      int loop_ub;

      //  Get the domain ratio for this contrast
      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backgrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(qzshiftIndex, scalefactorIndex, bulkInIndex, bulkOutIndex,
               qzshifts, scalefactors, bulkIns, bulkOuts, qzshiftValue,
               scalefactorValue, bulkInValue, bulkOutValue);

      //  Apply scale factors and q shifts to the data
      b_data.set_size(data.size(0), 6);
      loop_ub = data.size(0) - 1;
      for (i = 0; i < 6; i++) {
        for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
          b_data[b_loop_ub + b_data.size(0) * i] = data[b_loop_ub + data.size(0)
            * i];
        }
      }

      shiftData(*scalefactorValue, *qzshiftValue, dataPresent, b_data,
                dataLimits, simLimits, b_shiftedData);
      makeSimulationRange(b_shiftedData, simLimits, simulationXData, dataIndices);
      constructBackground(backgroundType_data, backgroundType_size,
                          backgroundParamIndex_data, backgroundParamIndex_size,
                          b_shiftedData, customFiles, backgroundParams,
                          simulationXData, dataIndices, background);
      constructResolution(resolutionType_data, resolutionType_size,
                          resolutionParamIndex_data, resolutionParamIndex_size,
                          b_shiftedData, resolutionParams, simulationXData,
                          dataIndices, resolution);

      //  Call the core layers calculation - need to do this once for each
      //  domain
      normalTF::coreLayersCalculation(calcAllLayers1, roughness, geometry_data,
        geometry_size, *bulkInValue, *bulkOutValue, resample, calcSld,
        b_shiftedData, simulationXData, dataIndices, repeatLayers, resolution,
        background, backgroundAction_data, backgroundAction_size, nParams,
        parallel_data, parallel_size, resampleMinAngle, resampleNPoints,
        useImaginary, r.f1, reflect1, simul1, a__5, r1.f1, r2.f1, &a__6);
      normalTF::coreLayersCalculation(calcAllLayers2, roughness, geometry_data,
        geometry_size, *bulkInValue, *bulkOutValue, resample, calcSld,
        b_shiftedData, simulationXData, dataIndices, repeatLayers, resolution,
        background, backgroundAction_data, backgroundAction_size, nParams,
        parallel_data, parallel_size, resampleMinAngle, resampleNPoints,
        useImaginary, r3.f1, reflect2, simul2, shiftedData, r4.f1, r5.f1, &a__7);

      //  Calculate the average reflectivities....
      //  Calculates the averaged reflectivity for domains samples (incoherent
      //  sum)
      domainRatios_tmp = domainRatios[static_cast<int>(domainRatioIndex) - 1];
      loop_ub = reflect1.size(0);
      b_loop_ub = reflect1.size(0);
      reflectivity.set_size(reflect1.size(0), 2);
      for (i = 0; i < loop_ub; i++) {
        reflectivity[i] = reflect1[i];
      }

      for (i = 0; i < b_loop_ub; i++) {
        reflectivity[i + reflectivity.size(0)] = domainRatios_tmp * reflect1[i +
          reflect1.size(0)] + (1.0 - domainRatios_tmp) * reflect2[i +
          reflect2.size(0)];
      }

      loop_ub = simul1.size(0);
      b_loop_ub = simul1.size(0);
      simulation.set_size(simul1.size(0), 2);
      for (i = 0; i < loop_ub; i++) {
        simulation[i] = simul1[i];
      }

      for (i = 0; i < b_loop_ub; i++) {
        simulation[i + simulation.size(0)] = domainRatios_tmp * simul1[i +
          simul1.size(0)] + (1.0 - domainRatios_tmp) * simul2[i + simul2.size(0)];
      }

      //  Get an overall chi-squared for the new averaged curve..
      *chi = chiSquared(shiftedData, reflectivity, nParams);

      //  Store returned values for this contrast in the output arrays.
      sldProfile[0] = r;
      sldProfile[1] = r3;
      layerSld[0] = r1;
      layerSld[1] = r4;
      resampledLayer[0] = r2;
      resampledLayer[1] = r5;
    }

    void b_customLayers(const ProblemDefinition *problemStruct, const Controls
                        *controls, ::coder::array<double, 1U> &qzshifts, ::coder::
                        array<double, 1U> &scalefactors, ::coder::array<double,
                        1U> &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::
                        coder::array<double, 1U> &chis, ::coder::array<
                        cell_wrap_7, 1U> &reflectivity, ::coder::array<
                        cell_wrap_7, 1U> &simulation, ::coder::array<cell_wrap_8,
                        1U> &shiftedData, ::coder::array<cell_wrap_8, 1U>
                        &backgrounds, ::coder::array<cell_wrap_7, 1U>
                        &resolutions, ::coder::array<cell_wrap_9, 2U>
                        &domainLayerSlds, ::coder::array<cell_wrap_9, 2U>
                        &domainSldProfiles, ::coder::array<cell_wrap_9, 2U>
                        &domainResampledLayers, ::coder::array<double, 1U>
                        &subRoughs)
    {
      ::coder::array<cell_wrap_63, 1U> layerSlds;
      ::coder::array<cell_wrap_63, 1U> resampledLayers;
      ::coder::array<cell_wrap_64, 1U> sldProfiles;
      ::coder::array<cell_wrap_9, 2U> calcAllLayers;
      ::coder::array<cell_wrap_9, 1U> calcAllLayers1;
      ::coder::array<cell_wrap_9, 1U> calcAllLayers2;
      ::coder::array<double, 2U> r;
      ::coder::array<double, 2U> r1;
      double d;
      double d1;
      double d2;
      double d3;
      double d4;
      double numberOfContrasts;
      double resampleMinAngle;
      double resampleNPoints;
      int iv[2];
      int iv1[2];
      int iv2[2];
      int iv3[2];
      int iv4[2];
      int iv5[2];
      int iv6[2];
      int iv7[2];
      int iv8[2];
      int iv9[2];
      int b_i;
      int b_loop_ub;
      int c_i;
      int c_loop_ub;
      int i;
      int i1;
      int i2;
      int i3;
      int i4;
      int loop_ub;
      int nParams;
      int unnamed_idx_0_tmp_tmp;
      boolean_T useImaginary;

      //  The custom layers, domainsTF reflectivity calculation.
      //  The function extracts the relevant parameters from the input arrays,
      //  allocates these on a pre-contrast basis, then calls the
      //  'coreLayersCalculation' (the core layers domainsTF calc is shared
      //  between multiple calculation types).
      //  Extract parameters from problemStruct
      numberOfContrasts = problemStruct->numberOfContrasts;
      nParams = problemStruct->params.size(1);
      useImaginary = problemStruct->useImaginary;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Pre-Allocation of output arrays...
      unnamed_idx_0_tmp_tmp = static_cast<int>(problemStruct->numberOfContrasts);
      calcAllLayers1.set_size(unnamed_idx_0_tmp_tmp);
      calcAllLayers2.set_size(unnamed_idx_0_tmp_tmp);
      for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
        calcAllLayers1[i].f1.set_size(2, 1);
        calcAllLayers1[i].f1[0] = 1.0;
        calcAllLayers1[i].f1[1] = 1.0;
        calcAllLayers2[i].f1.set_size(2, 1);
        calcAllLayers2[i].f1[0] = 1.0;
        calcAllLayers2[i].f1[1] = 1.0;
      }

      //  Process the custom models....
      customLayers::processCustomFunction(problemStruct->contrastBulkIns,
        problemStruct->contrastBulkOuts, problemStruct->bulkIns,
        problemStruct->bulkOuts, problemStruct->contrastCustomFiles,
        problemStruct->numberOfContrasts, problemStruct->customFiles,
        problemStruct->params, problemStruct->useImaginary, calcAllLayers,
        subRoughs);
      b_i = calcAllLayers.size(0);
      for (i = 0; i < b_i; i++) {
        loop_ub = calcAllLayers[i].f1.size(1);
        calcAllLayers1[i].f1.set_size(calcAllLayers[i].f1.size(0),
          calcAllLayers[i].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = calcAllLayers[i].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            calcAllLayers1[i].f1[i2 + calcAllLayers1[i].f1.size(0) * i1] =
              calcAllLayers[i].f1[i2 + calcAllLayers[i].f1.size(0) * i1];
          }
        }

        loop_ub = calcAllLayers[i + calcAllLayers.size(0)].f1.size(1);
        calcAllLayers2[i].f1.set_size(calcAllLayers[i + calcAllLayers.size(0)].
          f1.size(0), calcAllLayers[i + calcAllLayers.size(0)].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = calcAllLayers[i + calcAllLayers.size(0)].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            calcAllLayers2[i].f1[i2 + calcAllLayers2[i].f1.size(0) * i1] =
              calcAllLayers[i + calcAllLayers.size(0)].f1[i2 + calcAllLayers[i +
              calcAllLayers.size(0)].f1.size(0) * i1];
          }
        }
      }

      if (coder::internal::m_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        //  Parallel over all contrasts
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        resampledLayers.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        sldProfiles.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        layerSlds.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        resolutions.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        backgrounds.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        shiftedData.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        simulation.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        reflectivity.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        qzshifts.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        scalefactors.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        bulkIns.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        bulkOuts.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        chis.set_size(b_i);
        loop_ub = static_cast<int>(problemStruct->numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,d,d1,d2,d3,d4,iv5,c_i,iv6,iv7,iv8,iv9,c_loop_ub,i3,i4)

        for (c_i = 0; c_i <= loop_ub; c_i++) {
          iv5[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct->contrastBackgroundParams[c_i].f1)->size())
            [0];
          iv5[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct->contrastBackgroundParams[c_i].f1)->size())
            [1];
          iv6[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct->contrastResolutionParams[c_i].f1)->size())
            [0];
          iv6[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct->contrastResolutionParams[c_i].f1)->size())
            [1];
          iv7[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundTypes[c_i].f1)->size())[0];
          iv7[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundTypes[c_i].f1)->size())[1];
          iv8[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundActions[c_i].f1)->size())
            [0];
          iv8[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundActions[c_i].f1)->size())
            [1];
          iv9[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastResolutionTypes[c_i].f1)->size())[0];
          iv9[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastResolutionTypes[c_i].f1)->size())[1];
          b_contrastCalculation((const double *)((::coder::array<double, 2U> *)
            &problemStruct->contrastBackgroundParams[c_i].f1)->data(), iv5,
                                problemStruct->contrastQzshifts[c_i],
                                problemStruct->contrastScalefactors[c_i],
                                problemStruct->contrastBulkIns[c_i],
                                problemStruct->contrastBulkOuts[c_i], (const
            double *)((::coder::array<double, 2U> *)
                      &problemStruct->contrastResolutionParams[c_i].f1)->data(),
                                iv6, problemStruct->contrastDomainRatios[c_i],
                                problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIns, problemStruct->bulkOuts,
                                problemStruct->resolutionParams,
                                problemStruct->domainRatios,
                                problemStruct->dataPresent[c_i],
                                problemStruct->data[c_i].f1,
                                problemStruct->dataLimits[c_i].f1,
                                problemStruct->simulationLimits[c_i].f1,
                                problemStruct->repeatLayers[c_i].f1, (const char
            *)((::coder::array<char, 2U> *)
               &problemStruct->contrastBackgroundTypes[c_i].f1)->data(), iv7, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct->contrastBackgroundActions[c_i].f1)
                                ->data(), iv8, (const char *)((::coder::array<
            char, 2U> *)&problemStruct->contrastResolutionTypes[c_i].f1)->data(),
                                iv9, problemStruct->customFiles, static_cast<
                                double>(nParams), controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary,
                                problemStruct->resample[c_i],
                                problemStruct->geometry.data,
                                problemStruct->geometry.size, subRoughs[c_i],
                                true, calcAllLayers1[c_i].f1, calcAllLayers2[c_i]
                                .f1, &d4, &d3, &d2, &d1, &d, reflectivity[c_i].
                                f1, simulation[c_i].f1, r, backgrounds[c_i].f1,
                                resolutions[c_i].f1, layerSlds[c_i].f1,
                                sldProfiles[c_i].f1, resampledLayers[c_i].f1);
          c_loop_ub = r.size(0);
          shiftedData[c_i].f1.set_size(r.size(0), 3);
          for (i3 = 0; i3 < 3; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              shiftedData[c_i].f1[i4 + shiftedData[c_i].f1.size(0) * i3] = r[i4
                + r.size(0) * i3];
            }
          }

          qzshifts[c_i] = d4;
          scalefactors[c_i] = d3;
          bulkIns[c_i] = d2;
          bulkOuts[c_i] = d1;
          chis[c_i] = d;
        }
      } else {
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        resampledLayers.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        sldProfiles.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        layerSlds.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        resolutions.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        backgrounds.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        shiftedData.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        simulation.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        reflectivity.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        qzshifts.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        scalefactors.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        bulkIns.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        bulkOuts.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        chis.set_size(b_i);
        for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
          iv[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct->contrastBackgroundParams[i].f1)->size())[0];
          iv[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct->contrastBackgroundParams[i].f1)->size())[1];
          iv1[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct->contrastResolutionParams[i].f1)->size())[0];
          iv1[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct->contrastResolutionParams[i].f1)->size())[1];
          iv2[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundTypes[i].f1)->size())[0];
          iv2[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundTypes[i].f1)->size())[1];
          iv3[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundActions[i].f1)->size())[0];
          iv3[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundActions[i].f1)->size())[1];
          iv4[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastResolutionTypes[i].f1)->size())[0];
          iv4[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastResolutionTypes[i].f1)->size())[1];
          b_contrastCalculation((const double *)((::coder::array<double, 2U> *)
            &problemStruct->contrastBackgroundParams[i].f1)->data(), iv,
                                problemStruct->contrastQzshifts[i],
                                problemStruct->contrastScalefactors[i],
                                problemStruct->contrastBulkIns[i],
                                problemStruct->contrastBulkOuts[i], (const
            double *)((::coder::array<double, 2U> *)
                      &problemStruct->contrastResolutionParams[i].f1)->data(),
                                iv1, problemStruct->contrastDomainRatios[i],
                                problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIns, problemStruct->bulkOuts,
                                problemStruct->resolutionParams,
                                problemStruct->domainRatios,
                                problemStruct->dataPresent[i],
                                problemStruct->data[i].f1,
                                problemStruct->dataLimits[i].f1,
                                problemStruct->simulationLimits[i].f1,
                                problemStruct->repeatLayers[i].f1, (const char *)
                                ((::coder::array<char, 2U> *)
            &problemStruct->contrastBackgroundTypes[i].f1)->data(), iv2, (const
            char *)((::coder::array<char, 2U> *)
                    &problemStruct->contrastBackgroundActions[i].f1)->data(),
                                iv3, (const char *)((::coder::array<char, 2U> *)
            &problemStruct->contrastResolutionTypes[i].f1)->data(), iv4,
                                problemStruct->customFiles, static_cast<double>
                                (problemStruct->params.size(1)),
                                controls->parallel.data, controls->parallel.size,
                                resampleMinAngle, resampleNPoints,
                                problemStruct->useImaginary,
                                problemStruct->resample[i],
                                problemStruct->geometry.data,
                                problemStruct->geometry.size, subRoughs[i], true,
                                calcAllLayers1[i].f1, calcAllLayers2[i].f1,
                                &qzshifts[i], &scalefactors[i], &bulkIns[i],
                                &bulkOuts[i], &chis[i], reflectivity[i].f1,
                                simulation[i].f1, r1, backgrounds[i].f1,
                                resolutions[i].f1, layerSlds[i].f1,
                                sldProfiles[i].f1, resampledLayers[i].f1);
          loop_ub = r1.size(0);
          shiftedData[i].f1.set_size(r1.size(0), 3);
          for (b_i = 0; b_i < 3; b_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              shiftedData[i].f1[i1 + shiftedData[i].f1.size(0) * b_i] = r1[i1 +
                r1.size(0) * b_i];
            }
          }
        }
      }

      b_i = static_cast<int>(numberOfContrasts);
      domainSldProfiles.set_size(unnamed_idx_0_tmp_tmp, 2);
      domainLayerSlds.set_size(unnamed_idx_0_tmp_tmp, 2);
      domainResampledLayers.set_size(unnamed_idx_0_tmp_tmp, 2);
      for (i = 0; i < b_i; i++) {
        loop_ub = sldProfiles[i].f1[0].f1.size(0);
        domainSldProfiles[i].f1.set_size(sldProfiles[i].f1[0].f1.size(0), 2);
        b_loop_ub = sldProfiles[i].f1[1].f1.size(0);
        domainSldProfiles[i + domainSldProfiles.size(0)].f1.set_size
          (sldProfiles[i].f1[1].f1.size(0), 2);
        for (i1 = 0; i1 < 2; i1++) {
          for (i2 = 0; i2 < loop_ub; i2++) {
            domainSldProfiles[i].f1[i2 + domainSldProfiles[i].f1.size(0) * i1] =
              sldProfiles[i].f1[0].f1[i2 + sldProfiles[i].f1[0].f1.size(0) * i1];
          }

          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainSldProfiles[i + domainSldProfiles.size(0)].f1[i2 +
              domainSldProfiles[i + domainSldProfiles.size(0)].f1.size(0) * i1] =
              sldProfiles[i].f1[1].f1[i2 + sldProfiles[i].f1[1].f1.size(0) * i1];
          }
        }

        loop_ub = layerSlds[i].f1[0].f1.size(1);
        domainLayerSlds[i].f1.set_size(layerSlds[i].f1[0].f1.size(0),
          layerSlds[i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = layerSlds[i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainLayerSlds[i].f1[i2 + domainLayerSlds[i].f1.size(0) * i1] =
              layerSlds[i].f1[0].f1[i2 + layerSlds[i].f1[0].f1.size(0) * i1];
          }
        }

        loop_ub = layerSlds[i].f1[1].f1.size(1);
        domainLayerSlds[i + domainLayerSlds.size(0)].f1.set_size(layerSlds[i]
          .f1[1].f1.size(0), layerSlds[i].f1[1].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = layerSlds[i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainLayerSlds[i + domainLayerSlds.size(0)].f1[i2 +
              domainLayerSlds[i + domainLayerSlds.size(0)].f1.size(0) * i1] =
              layerSlds[i].f1[1].f1[i2 + layerSlds[i].f1[1].f1.size(0) * i1];
          }
        }

        loop_ub = resampledLayers[i].f1[0].f1.size(1);
        domainResampledLayers[i].f1.set_size(resampledLayers[i].f1[0].f1.size(0),
          resampledLayers[i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = resampledLayers[i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainResampledLayers[i].f1[i2 + domainResampledLayers[i].f1.size(0)
              * i1] = resampledLayers[i].f1[0].f1[i2 + resampledLayers[i].f1[0].
              f1.size(0) * i1];
          }
        }

        loop_ub = resampledLayers[i].f1[1].f1.size(1);
        domainResampledLayers[i + domainResampledLayers.size(0)].f1.set_size
          (resampledLayers[i].f1[1].f1.size(0), resampledLayers[i].f1[1].f1.size
           (1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = resampledLayers[i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainResampledLayers[i + domainResampledLayers.size(0)].f1[i2 +
              domainResampledLayers[i + domainResampledLayers.size(0)].f1.size(0)
              * i1] = resampledLayers[i].f1[1].f1[i2 + resampledLayers[i].f1[1].
              f1.size(0) * i1];
          }
        }
      }
    }

    void b_customLayers(const b_ProblemDefinition *problemStruct, const Controls
                        *controls, ::coder::array<double, 1U> &qzshifts, ::coder::
                        array<double, 1U> &scalefactors, ::coder::array<double,
                        1U> &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::
                        coder::array<double, 1U> &chis, ::coder::array<
                        cell_wrap_7, 1U> &reflectivity, ::coder::array<
                        cell_wrap_7, 1U> &simulation, ::coder::array<cell_wrap_8,
                        1U> &shiftedData, ::coder::array<cell_wrap_8, 1U>
                        &backgrounds, ::coder::array<cell_wrap_7, 1U>
                        &resolutions, ::coder::array<cell_wrap_9, 2U>
                        &domainLayerSlds, ::coder::array<cell_wrap_9, 2U>
                        &domainSldProfiles, ::coder::array<cell_wrap_9, 2U>
                        &domainResampledLayers, ::coder::array<double, 1U>
                        &subRoughs)
    {
      ::coder::array<cell_wrap_1, 2U> data;
      ::coder::array<cell_wrap_10, 2U> contrastBackgroundActions;
      ::coder::array<cell_wrap_10, 2U> contrastBackgroundTypes;
      ::coder::array<cell_wrap_10, 2U> contrastResolutionTypes;
      ::coder::array<cell_wrap_10, 2U> customFiles;
      ::coder::array<cell_wrap_2, 2U> dataLimits;
      ::coder::array<cell_wrap_2, 2U> repeatLayers;
      ::coder::array<cell_wrap_2, 2U> simLimits;
      ::coder::array<cell_wrap_47, 2U> contrastBackgroundIndices;
      ::coder::array<cell_wrap_63, 1U> layerSlds;
      ::coder::array<cell_wrap_63, 1U> resampledLayers;
      ::coder::array<cell_wrap_64, 1U> sldProfiles;
      ::coder::array<cell_wrap_9, 2U> a__2;
      ::coder::array<cell_wrap_9, 2U> a__3;
      ::coder::array<cell_wrap_9, 2U> a__4;
      ::coder::array<cell_wrap_9, 2U> calcAllLayers;
      ::coder::array<cell_wrap_9, 2U> contrastResolutionIndices;
      ::coder::array<cell_wrap_9, 1U> calcAllLayers1;
      ::coder::array<cell_wrap_9, 1U> calcAllLayers2;
      ::coder::array<double, 2U> backgroundParamArray;
      ::coder::array<double, 2U> bulkInArray;
      ::coder::array<double, 2U> bulkOutArray;
      ::coder::array<double, 2U> cCustFiles;
      ::coder::array<double, 2U> contrastBulkInIndices;
      ::coder::array<double, 2U> contrastBulkOutIndices;
      ::coder::array<double, 2U> contrastDomainRatioIndices;
      ::coder::array<double, 2U> contrastQzshiftIndices;
      ::coder::array<double, 2U> contrastScalefactorIndices;
      ::coder::array<double, 2U> dataPresent;
      ::coder::array<double, 2U> domainRatioArray;
      ::coder::array<double, 2U> params;
      ::coder::array<double, 2U> qzshiftArray;
      ::coder::array<double, 2U> r;
      ::coder::array<double, 2U> r1;
      ::coder::array<double, 2U> resample;
      ::coder::array<double, 2U> resolutionParamArray;
      ::coder::array<double, 2U> scalefactorArray;
      double a__1;
      double d;
      double d1;
      double d2;
      double d3;
      double d4;
      double nParams;
      double numberOfContrasts;
      double resampleMinAngle;
      double resampleNPoints;
      int geometry_size[2];
      int iv[2];
      int iv1[2];
      int iv2[2];
      int iv3[2];
      int iv4[2];
      int iv5[2];
      int iv6[2];
      int iv7[2];
      int iv8[2];
      int iv9[2];
      int b_i;
      int b_loop_ub;
      int c_i;
      int c_loop_ub;
      int i;
      int i1;
      int i2;
      int i3;
      int i4;
      int loop_ub;
      int unnamed_idx_0;
      int unnamed_idx_0_tmp_tmp;
      char geometry_data[10000];
      boolean_T useImaginary;

      //  The custom layers, domainsTF reflectivity calculation.
      //  The function extracts the relevant parameters from the input arrays,
      //  allocates these on a pre-contrast basis, then calls the
      //  'coreLayersCalculation' (the core layers domainsTF calc is shared
      //  between multiple calculation types).
      //  Extract parameters from problemStruct
      extractProblemParams(problemStruct, &numberOfContrasts, geometry_data,
                           geometry_size, contrastBackgroundIndices,
                           contrastQzshiftIndices, contrastScalefactorIndices,
                           contrastBulkInIndices, contrastBulkOutIndices,
                           contrastResolutionIndices, contrastDomainRatioIndices,
                           backgroundParamArray, qzshiftArray, scalefactorArray,
                           bulkInArray, bulkOutArray, resolutionParamArray,
                           domainRatioArray, dataPresent, &nParams, params,
                           &a__1, resample, contrastBackgroundTypes,
                           contrastBackgroundActions, contrastResolutionTypes,
                           cCustFiles, &useImaginary, repeatLayers, data,
                           dataLimits, simLimits, a__2, a__3, customFiles, a__4);
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Pre-Allocation of output arrays...
      unnamed_idx_0_tmp_tmp = static_cast<int>(numberOfContrasts);
      unnamed_idx_0 = static_cast<int>(numberOfContrasts);
      calcAllLayers1.set_size(unnamed_idx_0_tmp_tmp);
      calcAllLayers2.set_size(unnamed_idx_0_tmp_tmp);
      for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
        calcAllLayers1[i].f1.set_size(2, 1);
        calcAllLayers1[i].f1[0] = 1.0;
        calcAllLayers1[i].f1[1] = 1.0;
        calcAllLayers2[i].f1.set_size(2, 1);
        calcAllLayers2[i].f1[0] = 1.0;
        calcAllLayers2[i].f1[1] = 1.0;
      }

      //  Process the custom models....
      customLayers::processCustomFunction(contrastBulkInIndices,
        contrastBulkOutIndices, bulkInArray, bulkOutArray, cCustFiles,
        numberOfContrasts, customFiles, params, useImaginary, calcAllLayers,
        subRoughs);
      b_i = calcAllLayers.size(0);
      for (i = 0; i < b_i; i++) {
        loop_ub = calcAllLayers[i].f1.size(1);
        calcAllLayers1[i].f1.set_size(calcAllLayers[i].f1.size(0),
          calcAllLayers[i].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = calcAllLayers[i].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            calcAllLayers1[i].f1[i2 + calcAllLayers1[i].f1.size(0) * i1] =
              calcAllLayers[i].f1[i2 + calcAllLayers[i].f1.size(0) * i1];
          }
        }

        loop_ub = calcAllLayers[i + calcAllLayers.size(0)].f1.size(1);
        calcAllLayers2[i].f1.set_size(calcAllLayers[i + calcAllLayers.size(0)].
          f1.size(0), calcAllLayers[i + calcAllLayers.size(0)].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = calcAllLayers[i + calcAllLayers.size(0)].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            calcAllLayers2[i].f1[i2 + calcAllLayers2[i].f1.size(0) * i1] =
              calcAllLayers[i + calcAllLayers.size(0)].f1[i2 + calcAllLayers[i +
              calcAllLayers.size(0)].f1.size(0) * i1];
          }
        }
      }

      if (coder::internal::m_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        //  Parallel over all contrasts
        resampledLayers.set_size(unnamed_idx_0_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp);
        layerSlds.set_size(unnamed_idx_0_tmp_tmp);
        resolutions.set_size(unnamed_idx_0_tmp_tmp);
        backgrounds.set_size(unnamed_idx_0_tmp_tmp);
        shiftedData.set_size(unnamed_idx_0_tmp_tmp);
        simulation.set_size(unnamed_idx_0_tmp_tmp);
        reflectivity.set_size(unnamed_idx_0_tmp_tmp);
        qzshifts.set_size(unnamed_idx_0_tmp_tmp);
        scalefactors.set_size(unnamed_idx_0_tmp_tmp);
        bulkIns.set_size(unnamed_idx_0_tmp_tmp);
        bulkOuts.set_size(unnamed_idx_0_tmp_tmp);
        chis.set_size(unnamed_idx_0_tmp_tmp);
        unnamed_idx_0_tmp_tmp = static_cast<int>(numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,d,d1,d2,d3,d4,iv5,c_i,iv6,iv7,iv8,iv9,c_loop_ub,i3,i4)

        for (c_i = 0; c_i <= unnamed_idx_0_tmp_tmp; c_i++) {
          iv5[0] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[0];
          iv5[1] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[1];
          iv6[0] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[0];
          iv6[1] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[1];
          iv7[0] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[0];
          iv7[1] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[1];
          iv8[0] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[0];
          iv8[1] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[1];
          iv9[0] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[0];
          iv9[1] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[1];
          b_contrastCalculation((const double *)contrastBackgroundIndices[c_i].
                                f1.data(), iv5, contrastQzshiftIndices[c_i],
                                contrastScalefactorIndices[c_i],
                                contrastBulkInIndices[c_i],
                                contrastBulkOutIndices[c_i], (const double *)
                                contrastResolutionIndices[c_i].f1.data(), iv6,
                                contrastDomainRatioIndices[c_i],
                                backgroundParamArray, qzshiftArray,
                                scalefactorArray, bulkInArray, bulkOutArray,
                                resolutionParamArray, domainRatioArray,
                                dataPresent[c_i], data[c_i].f1, dataLimits[c_i].
                                f1, simLimits[c_i].f1, repeatLayers[c_i].f1, (
            const char *)contrastBackgroundTypes[c_i].f1.data(), iv7, (const
            char *)contrastBackgroundActions[c_i].f1.data(), iv8, (const char *)
                                contrastResolutionTypes[c_i].f1.data(), iv9,
                                customFiles, nParams, controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, resample[c_i],
                                geometry_data, geometry_size, subRoughs[c_i],
                                true, calcAllLayers1[c_i].f1, calcAllLayers2[c_i]
                                .f1, &d4, &d3, &d2, &d1, &d, reflectivity[c_i].
                                f1, simulation[c_i].f1, r, backgrounds[c_i].f1,
                                resolutions[c_i].f1, layerSlds[c_i].f1,
                                sldProfiles[c_i].f1, resampledLayers[c_i].f1);
          c_loop_ub = r.size(0);
          shiftedData[c_i].f1.set_size(r.size(0), 3);
          for (i3 = 0; i3 < 3; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              shiftedData[c_i].f1[i4 + shiftedData[c_i].f1.size(0) * i3] = r[i4
                + r.size(0) * i3];
            }
          }

          qzshifts[c_i] = d4;
          scalefactors[c_i] = d3;
          bulkIns[c_i] = d2;
          bulkOuts[c_i] = d1;
          chis[c_i] = d;
        }
      } else {
        resampledLayers.set_size(unnamed_idx_0_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp);
        layerSlds.set_size(unnamed_idx_0_tmp_tmp);
        resolutions.set_size(unnamed_idx_0_tmp_tmp);
        backgrounds.set_size(unnamed_idx_0_tmp_tmp);
        shiftedData.set_size(unnamed_idx_0_tmp_tmp);
        simulation.set_size(unnamed_idx_0_tmp_tmp);
        reflectivity.set_size(unnamed_idx_0_tmp_tmp);
        qzshifts.set_size(unnamed_idx_0_tmp_tmp);
        scalefactors.set_size(unnamed_idx_0_tmp_tmp);
        bulkIns.set_size(unnamed_idx_0_tmp_tmp);
        bulkOuts.set_size(unnamed_idx_0_tmp_tmp);
        chis.set_size(unnamed_idx_0_tmp_tmp);
        for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
          iv[0] = (*(int (*)[2])contrastBackgroundIndices[i].f1.size())[0];
          iv[1] = (*(int (*)[2])contrastBackgroundIndices[i].f1.size())[1];
          iv1[0] = (*(int (*)[2])contrastResolutionIndices[i].f1.size())[0];
          iv1[1] = (*(int (*)[2])contrastResolutionIndices[i].f1.size())[1];
          iv2[0] = (*(int (*)[2])contrastBackgroundTypes[i].f1.size())[0];
          iv2[1] = (*(int (*)[2])contrastBackgroundTypes[i].f1.size())[1];
          iv3[0] = (*(int (*)[2])contrastBackgroundActions[i].f1.size())[0];
          iv3[1] = (*(int (*)[2])contrastBackgroundActions[i].f1.size())[1];
          iv4[0] = (*(int (*)[2])contrastResolutionTypes[i].f1.size())[0];
          iv4[1] = (*(int (*)[2])contrastResolutionTypes[i].f1.size())[1];
          b_contrastCalculation((const double *)contrastBackgroundIndices[i].
                                f1.data(), iv, contrastQzshiftIndices[i],
                                contrastScalefactorIndices[i],
                                contrastBulkInIndices[i],
                                contrastBulkOutIndices[i], (const double *)
                                contrastResolutionIndices[i].f1.data(), iv1,
                                contrastDomainRatioIndices[i],
                                backgroundParamArray, qzshiftArray,
                                scalefactorArray, bulkInArray, bulkOutArray,
                                resolutionParamArray, domainRatioArray,
                                dataPresent[i], data[i].f1, dataLimits[i].f1,
                                simLimits[i].f1, repeatLayers[i].f1, (const char
            *)contrastBackgroundTypes[i].f1.data(), iv2, (const char *)
                                contrastBackgroundActions[i].f1.data(), iv3, (
            const char *)contrastResolutionTypes[i].f1.data(), iv4, customFiles,
                                nParams, controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, resample[i],
                                geometry_data, geometry_size, subRoughs[i], true,
                                calcAllLayers1[i].f1, calcAllLayers2[i].f1,
                                &qzshifts[i], &scalefactors[i], &bulkIns[i],
                                &bulkOuts[i], &chis[i], reflectivity[i].f1,
                                simulation[i].f1, r1, backgrounds[i].f1,
                                resolutions[i].f1, layerSlds[i].f1,
                                sldProfiles[i].f1, resampledLayers[i].f1);
          loop_ub = r1.size(0);
          shiftedData[i].f1.set_size(r1.size(0), 3);
          for (b_i = 0; b_i < 3; b_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              shiftedData[i].f1[i1 + shiftedData[i].f1.size(0) * b_i] = r1[i1 +
                r1.size(0) * b_i];
            }
          }
        }
      }

      b_i = static_cast<int>(numberOfContrasts);
      domainSldProfiles.set_size(unnamed_idx_0, 2);
      domainLayerSlds.set_size(unnamed_idx_0, 2);
      domainResampledLayers.set_size(unnamed_idx_0, 2);
      for (i = 0; i < b_i; i++) {
        loop_ub = sldProfiles[i].f1[0].f1.size(0);
        domainSldProfiles[i].f1.set_size(sldProfiles[i].f1[0].f1.size(0), 2);
        b_loop_ub = sldProfiles[i].f1[1].f1.size(0);
        domainSldProfiles[i + domainSldProfiles.size(0)].f1.set_size
          (sldProfiles[i].f1[1].f1.size(0), 2);
        for (i1 = 0; i1 < 2; i1++) {
          for (i2 = 0; i2 < loop_ub; i2++) {
            domainSldProfiles[i].f1[i2 + domainSldProfiles[i].f1.size(0) * i1] =
              sldProfiles[i].f1[0].f1[i2 + sldProfiles[i].f1[0].f1.size(0) * i1];
          }

          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainSldProfiles[i + domainSldProfiles.size(0)].f1[i2 +
              domainSldProfiles[i + domainSldProfiles.size(0)].f1.size(0) * i1] =
              sldProfiles[i].f1[1].f1[i2 + sldProfiles[i].f1[1].f1.size(0) * i1];
          }
        }

        loop_ub = layerSlds[i].f1[0].f1.size(1);
        domainLayerSlds[i].f1.set_size(layerSlds[i].f1[0].f1.size(0),
          layerSlds[i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = layerSlds[i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainLayerSlds[i].f1[i2 + domainLayerSlds[i].f1.size(0) * i1] =
              layerSlds[i].f1[0].f1[i2 + layerSlds[i].f1[0].f1.size(0) * i1];
          }
        }

        loop_ub = layerSlds[i].f1[1].f1.size(1);
        domainLayerSlds[i + domainLayerSlds.size(0)].f1.set_size(layerSlds[i]
          .f1[1].f1.size(0), layerSlds[i].f1[1].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = layerSlds[i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainLayerSlds[i + domainLayerSlds.size(0)].f1[i2 +
              domainLayerSlds[i + domainLayerSlds.size(0)].f1.size(0) * i1] =
              layerSlds[i].f1[1].f1[i2 + layerSlds[i].f1[1].f1.size(0) * i1];
          }
        }

        loop_ub = resampledLayers[i].f1[0].f1.size(1);
        domainResampledLayers[i].f1.set_size(resampledLayers[i].f1[0].f1.size(0),
          resampledLayers[i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = resampledLayers[i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainResampledLayers[i].f1[i2 + domainResampledLayers[i].f1.size(0)
              * i1] = resampledLayers[i].f1[0].f1[i2 + resampledLayers[i].f1[0].
              f1.size(0) * i1];
          }
        }

        loop_ub = resampledLayers[i].f1[1].f1.size(1);
        domainResampledLayers[i + domainResampledLayers.size(0)].f1.set_size
          (resampledLayers[i].f1[1].f1.size(0), resampledLayers[i].f1[1].f1.size
           (1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = resampledLayers[i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainResampledLayers[i + domainResampledLayers.size(0)].f1[i2 +
              domainResampledLayers[i + domainResampledLayers.size(0)].f1.size(0)
              * i1] = resampledLayers[i].f1[1].f1[i2 + resampledLayers[i].f1[1].
              f1.size(0) * i1];
          }
        }
      }
    }

    void c_customLayers(const ProblemDefinition *problemStruct, const Controls
                        *controls, ::coder::array<double, 1U> &qzshifts, ::coder::
                        array<double, 1U> &scalefactors, ::coder::array<double,
                        1U> &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::
                        coder::array<double, 1U> &chis, ::coder::array<
                        cell_wrap_7, 1U> &reflectivity, ::coder::array<
                        cell_wrap_7, 1U> &simulation, ::coder::array<cell_wrap_8,
                        1U> &shiftedData, ::coder::array<cell_wrap_8, 1U>
                        &backgrounds, ::coder::array<cell_wrap_7, 1U>
                        &resolutions, ::coder::array<cell_wrap_9, 2U>
                        &domainLayerSlds, ::coder::array<cell_wrap_9, 2U>
                        &domainSldProfiles, ::coder::array<cell_wrap_9, 2U>
                        &domainResampledLayers, ::coder::array<double, 1U>
                        &subRoughs)
    {
      ::coder::array<cell_wrap_63, 1U> layerSlds;
      ::coder::array<cell_wrap_63, 1U> resampledLayers;
      ::coder::array<cell_wrap_64, 1U> sldProfiles;
      ::coder::array<cell_wrap_9, 2U> calcAllLayers;
      ::coder::array<cell_wrap_9, 1U> calcAllLayers1;
      ::coder::array<cell_wrap_9, 1U> calcAllLayers2;
      ::coder::array<double, 2U> r;
      ::coder::array<double, 2U> r1;
      double d;
      double d1;
      double d2;
      double d3;
      double d4;
      double numberOfContrasts;
      double resampleMinAngle;
      double resampleNPoints;
      int iv[2];
      int iv1[2];
      int iv2[2];
      int iv3[2];
      int iv4[2];
      int iv5[2];
      int iv6[2];
      int iv7[2];
      int iv8[2];
      int iv9[2];
      int b_i;
      int b_loop_ub;
      int c_i;
      int c_loop_ub;
      int i;
      int i1;
      int i2;
      int i3;
      int i4;
      int loop_ub;
      int nParams;
      int unnamed_idx_0_tmp_tmp;
      boolean_T calcSld;
      boolean_T useImaginary;

      //  The custom layers, domainsTF reflectivity calculation.
      //  The function extracts the relevant parameters from the input arrays,
      //  allocates these on a pre-contrast basis, then calls the
      //  'coreLayersCalculation' (the core layers domainsTF calc is shared
      //  between multiple calculation types).
      //  Extract parameters from problemStruct
      numberOfContrasts = problemStruct->numberOfContrasts;
      nParams = problemStruct->params.size(1);
      useImaginary = problemStruct->useImaginary;
      calcSld = controls->calcSldDuringFit;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Pre-Allocation of output arrays...
      unnamed_idx_0_tmp_tmp = static_cast<int>(problemStruct->numberOfContrasts);
      calcAllLayers1.set_size(unnamed_idx_0_tmp_tmp);
      calcAllLayers2.set_size(unnamed_idx_0_tmp_tmp);
      for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
        calcAllLayers1[i].f1.set_size(2, 1);
        calcAllLayers1[i].f1[0] = 1.0;
        calcAllLayers1[i].f1[1] = 1.0;
        calcAllLayers2[i].f1.set_size(2, 1);
        calcAllLayers2[i].f1[0] = 1.0;
        calcAllLayers2[i].f1[1] = 1.0;
      }

      //  Process the custom models....
      customLayers::processCustomFunction(problemStruct->contrastBulkIns,
        problemStruct->contrastBulkOuts, problemStruct->bulkIns,
        problemStruct->bulkOuts, problemStruct->contrastCustomFiles,
        problemStruct->numberOfContrasts, problemStruct->customFiles,
        problemStruct->params, problemStruct->useImaginary, calcAllLayers,
        subRoughs);
      b_i = calcAllLayers.size(0);
      for (i = 0; i < b_i; i++) {
        loop_ub = calcAllLayers[i].f1.size(1);
        calcAllLayers1[i].f1.set_size(calcAllLayers[i].f1.size(0),
          calcAllLayers[i].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = calcAllLayers[i].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            calcAllLayers1[i].f1[i2 + calcAllLayers1[i].f1.size(0) * i1] =
              calcAllLayers[i].f1[i2 + calcAllLayers[i].f1.size(0) * i1];
          }
        }

        loop_ub = calcAllLayers[i + calcAllLayers.size(0)].f1.size(1);
        calcAllLayers2[i].f1.set_size(calcAllLayers[i + calcAllLayers.size(0)].
          f1.size(0), calcAllLayers[i + calcAllLayers.size(0)].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = calcAllLayers[i + calcAllLayers.size(0)].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            calcAllLayers2[i].f1[i2 + calcAllLayers2[i].f1.size(0) * i1] =
              calcAllLayers[i + calcAllLayers.size(0)].f1[i2 + calcAllLayers[i +
              calcAllLayers.size(0)].f1.size(0) * i1];
          }
        }
      }

      if (coder::internal::m_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        //  Parallel over all contrasts
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        resampledLayers.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        sldProfiles.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        layerSlds.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        resolutions.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        backgrounds.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        shiftedData.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        simulation.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        reflectivity.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        qzshifts.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        scalefactors.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        bulkIns.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        bulkOuts.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        chis.set_size(b_i);
        loop_ub = static_cast<int>(problemStruct->numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,d,d1,d2,d3,d4,iv5,c_i,iv6,iv7,iv8,iv9,c_loop_ub,i3,i4)

        for (c_i = 0; c_i <= loop_ub; c_i++) {
          iv5[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct->contrastBackgroundParams[c_i].f1)->size())
            [0];
          iv5[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct->contrastBackgroundParams[c_i].f1)->size())
            [1];
          iv6[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct->contrastResolutionParams[c_i].f1)->size())
            [0];
          iv6[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct->contrastResolutionParams[c_i].f1)->size())
            [1];
          iv7[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundTypes[c_i].f1)->size())[0];
          iv7[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundTypes[c_i].f1)->size())[1];
          iv8[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundActions[c_i].f1)->size())
            [0];
          iv8[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundActions[c_i].f1)->size())
            [1];
          iv9[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastResolutionTypes[c_i].f1)->size())[0];
          iv9[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastResolutionTypes[c_i].f1)->size())[1];
          b_contrastCalculation((const double *)((::coder::array<double, 2U> *)
            &problemStruct->contrastBackgroundParams[c_i].f1)->data(), iv5,
                                problemStruct->contrastQzshifts[c_i],
                                problemStruct->contrastScalefactors[c_i],
                                problemStruct->contrastBulkIns[c_i],
                                problemStruct->contrastBulkOuts[c_i], (const
            double *)((::coder::array<double, 2U> *)
                      &problemStruct->contrastResolutionParams[c_i].f1)->data(),
                                iv6, problemStruct->contrastDomainRatios[c_i],
                                problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIns, problemStruct->bulkOuts,
                                problemStruct->resolutionParams,
                                problemStruct->domainRatios,
                                problemStruct->dataPresent[c_i],
                                problemStruct->data[c_i].f1,
                                problemStruct->dataLimits[c_i].f1,
                                problemStruct->simulationLimits[c_i].f1,
                                problemStruct->repeatLayers[c_i].f1, (const char
            *)((::coder::array<char, 2U> *)
               &problemStruct->contrastBackgroundTypes[c_i].f1)->data(), iv7, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct->contrastBackgroundActions[c_i].f1)
                                ->data(), iv8, (const char *)((::coder::array<
            char, 2U> *)&problemStruct->contrastResolutionTypes[c_i].f1)->data(),
                                iv9, problemStruct->customFiles, static_cast<
                                double>(nParams), controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary,
                                problemStruct->resample[c_i],
                                problemStruct->geometry.data,
                                problemStruct->geometry.size, subRoughs[c_i],
                                calcSld, calcAllLayers1[c_i].f1,
                                calcAllLayers2[c_i].f1, &d4, &d3, &d2, &d1, &d,
                                reflectivity[c_i].f1, simulation[c_i].f1, r,
                                backgrounds[c_i].f1, resolutions[c_i].f1,
                                layerSlds[c_i].f1, sldProfiles[c_i].f1,
                                resampledLayers[c_i].f1);
          c_loop_ub = r.size(0);
          shiftedData[c_i].f1.set_size(r.size(0), 3);
          for (i3 = 0; i3 < 3; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              shiftedData[c_i].f1[i4 + shiftedData[c_i].f1.size(0) * i3] = r[i4
                + r.size(0) * i3];
            }
          }

          qzshifts[c_i] = d4;
          scalefactors[c_i] = d3;
          bulkIns[c_i] = d2;
          bulkOuts[c_i] = d1;
          chis[c_i] = d;
        }
      } else {
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        resampledLayers.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        sldProfiles.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        layerSlds.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        resolutions.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        backgrounds.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        shiftedData.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        simulation.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        reflectivity.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        qzshifts.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        scalefactors.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        bulkIns.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        bulkOuts.set_size(b_i);
        b_i = static_cast<int>(problemStruct->numberOfContrasts);
        chis.set_size(b_i);
        for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
          iv[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct->contrastBackgroundParams[i].f1)->size())[0];
          iv[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct->contrastBackgroundParams[i].f1)->size())[1];
          iv1[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct->contrastResolutionParams[i].f1)->size())[0];
          iv1[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct->contrastResolutionParams[i].f1)->size())[1];
          iv2[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundTypes[i].f1)->size())[0];
          iv2[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundTypes[i].f1)->size())[1];
          iv3[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundActions[i].f1)->size())[0];
          iv3[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastBackgroundActions[i].f1)->size())[1];
          iv4[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastResolutionTypes[i].f1)->size())[0];
          iv4[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct->contrastResolutionTypes[i].f1)->size())[1];
          b_contrastCalculation((const double *)((::coder::array<double, 2U> *)
            &problemStruct->contrastBackgroundParams[i].f1)->data(), iv,
                                problemStruct->contrastQzshifts[i],
                                problemStruct->contrastScalefactors[i],
                                problemStruct->contrastBulkIns[i],
                                problemStruct->contrastBulkOuts[i], (const
            double *)((::coder::array<double, 2U> *)
                      &problemStruct->contrastResolutionParams[i].f1)->data(),
                                iv1, problemStruct->contrastDomainRatios[i],
                                problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIns, problemStruct->bulkOuts,
                                problemStruct->resolutionParams,
                                problemStruct->domainRatios,
                                problemStruct->dataPresent[i],
                                problemStruct->data[i].f1,
                                problemStruct->dataLimits[i].f1,
                                problemStruct->simulationLimits[i].f1,
                                problemStruct->repeatLayers[i].f1, (const char *)
                                ((::coder::array<char, 2U> *)
            &problemStruct->contrastBackgroundTypes[i].f1)->data(), iv2, (const
            char *)((::coder::array<char, 2U> *)
                    &problemStruct->contrastBackgroundActions[i].f1)->data(),
                                iv3, (const char *)((::coder::array<char, 2U> *)
            &problemStruct->contrastResolutionTypes[i].f1)->data(), iv4,
                                problemStruct->customFiles, static_cast<double>
                                (problemStruct->params.size(1)),
                                controls->parallel.data, controls->parallel.size,
                                resampleMinAngle, resampleNPoints,
                                problemStruct->useImaginary,
                                problemStruct->resample[i],
                                problemStruct->geometry.data,
                                problemStruct->geometry.size, subRoughs[i],
                                calcSld, calcAllLayers1[i].f1, calcAllLayers2[i]
                                .f1, &qzshifts[i], &scalefactors[i], &bulkIns[i],
                                &bulkOuts[i], &chis[i], reflectivity[i].f1,
                                simulation[i].f1, r1, backgrounds[i].f1,
                                resolutions[i].f1, layerSlds[i].f1,
                                sldProfiles[i].f1, resampledLayers[i].f1);
          loop_ub = r1.size(0);
          shiftedData[i].f1.set_size(r1.size(0), 3);
          for (b_i = 0; b_i < 3; b_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              shiftedData[i].f1[i1 + shiftedData[i].f1.size(0) * b_i] = r1[i1 +
                r1.size(0) * b_i];
            }
          }
        }
      }

      b_i = static_cast<int>(numberOfContrasts);
      domainSldProfiles.set_size(unnamed_idx_0_tmp_tmp, 2);
      domainLayerSlds.set_size(unnamed_idx_0_tmp_tmp, 2);
      domainResampledLayers.set_size(unnamed_idx_0_tmp_tmp, 2);
      for (i = 0; i < b_i; i++) {
        loop_ub = sldProfiles[i].f1[0].f1.size(0);
        domainSldProfiles[i].f1.set_size(sldProfiles[i].f1[0].f1.size(0), 2);
        b_loop_ub = sldProfiles[i].f1[1].f1.size(0);
        domainSldProfiles[i + domainSldProfiles.size(0)].f1.set_size
          (sldProfiles[i].f1[1].f1.size(0), 2);
        for (i1 = 0; i1 < 2; i1++) {
          for (i2 = 0; i2 < loop_ub; i2++) {
            domainSldProfiles[i].f1[i2 + domainSldProfiles[i].f1.size(0) * i1] =
              sldProfiles[i].f1[0].f1[i2 + sldProfiles[i].f1[0].f1.size(0) * i1];
          }

          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainSldProfiles[i + domainSldProfiles.size(0)].f1[i2 +
              domainSldProfiles[i + domainSldProfiles.size(0)].f1.size(0) * i1] =
              sldProfiles[i].f1[1].f1[i2 + sldProfiles[i].f1[1].f1.size(0) * i1];
          }
        }

        loop_ub = layerSlds[i].f1[0].f1.size(1);
        domainLayerSlds[i].f1.set_size(layerSlds[i].f1[0].f1.size(0),
          layerSlds[i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = layerSlds[i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainLayerSlds[i].f1[i2 + domainLayerSlds[i].f1.size(0) * i1] =
              layerSlds[i].f1[0].f1[i2 + layerSlds[i].f1[0].f1.size(0) * i1];
          }
        }

        loop_ub = layerSlds[i].f1[1].f1.size(1);
        domainLayerSlds[i + domainLayerSlds.size(0)].f1.set_size(layerSlds[i]
          .f1[1].f1.size(0), layerSlds[i].f1[1].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = layerSlds[i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainLayerSlds[i + domainLayerSlds.size(0)].f1[i2 +
              domainLayerSlds[i + domainLayerSlds.size(0)].f1.size(0) * i1] =
              layerSlds[i].f1[1].f1[i2 + layerSlds[i].f1[1].f1.size(0) * i1];
          }
        }

        loop_ub = resampledLayers[i].f1[0].f1.size(1);
        domainResampledLayers[i].f1.set_size(resampledLayers[i].f1[0].f1.size(0),
          resampledLayers[i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = resampledLayers[i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainResampledLayers[i].f1[i2 + domainResampledLayers[i].f1.size(0)
              * i1] = resampledLayers[i].f1[0].f1[i2 + resampledLayers[i].f1[0].
              f1.size(0) * i1];
          }
        }

        loop_ub = resampledLayers[i].f1[1].f1.size(1);
        domainResampledLayers[i + domainResampledLayers.size(0)].f1.set_size
          (resampledLayers[i].f1[1].f1.size(0), resampledLayers[i].f1[1].f1.size
           (1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = resampledLayers[i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainResampledLayers[i + domainResampledLayers.size(0)].f1[i2 +
              domainResampledLayers[i + domainResampledLayers.size(0)].f1.size(0)
              * i1] = resampledLayers[i].f1[1].f1[i2 + resampledLayers[i].f1[1].
              f1.size(0) * i1];
          }
        }
      }
    }
  }
}

// End of code generation (customLayers1.cpp)
