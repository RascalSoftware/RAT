//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// standardLayers1.cpp
//
// Code generation for function 'standardLayers1'
//

// Include files
#include "standardLayers1.h"
#include "RATMain_internal_types.h"
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "backSort.h"
#include "chiSquared.h"
#include "coreLayersCalculation.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Declarations
namespace RAT
{
  namespace domainsTF
  {
    static void contrastCalculation(real_T backgroundParamIndex, real_T
      qzshiftIndex, real_T scalefactorIndex, real_T bulkInIndex, real_T
      bulkOutIndex, real_T resolutionParamIndex, real_T domainRatioIndex, const ::
      coder::array<real_T, 2U> &backgroundParams, const ::coder::array<real_T,
      2U> &qzshifts, const ::coder::array<real_T, 2U> &scalefactors, const ::
      coder::array<real_T, 2U> &bulkIns, const ::coder::array<real_T, 2U>
      &bulkOuts, const ::coder::array<real_T, 2U> &resolutionParams, const ::
      coder::array<real_T, 2U> &domainRatios, real_T dataPresent, const ::coder::
      array<real_T, 2U> &allData, const real_T dataLimits[2], const real_T
      simLimits[2], const real_T repeatLayers[2], real_T contrastBackgroundsType,
      real_T nParams, const char_T parallel_data[], const int32_T parallel_size
      [2], const real_T resamPars[2], boolean_T useImaginary, real_T resample,
      const char_T geometry_data[], const int32_T geometry_size[2], real_T
      roughness, boolean_T calcSld, const ::coder::array<real_T, 2U>
      &domainContrastLayers1, const ::coder::array<real_T, 2U>
      &domainContrastLayers2, const ::coder::array<cell_wrap_31, 2U>
      &outParameterisedLayers, real_T *backgroundParamValue, real_T
      *qzshiftValue, real_T *scalefactorValue, real_T *bulkInValue, real_T
      *bulkOutValue, real_T *resolutionParamValue, real_T *chi, ::coder::array<
      real_T, 2U> &reflectivity, ::coder::array<real_T, 2U> &simulation, ::coder::
      array<real_T, 2U> &shiftedData, cell_wrap_10 layerSld[2], cell_wrap_10
      sldProfile[2], cell_wrap_10 allLayer[2], real_T *ssub);
  }
}

// Function Definitions
namespace RAT
{
  namespace domainsTF
  {
    static void contrastCalculation(real_T backgroundParamIndex, real_T
      qzshiftIndex, real_T scalefactorIndex, real_T bulkInIndex, real_T
      bulkOutIndex, real_T resolutionParamIndex, real_T domainRatioIndex, const ::
      coder::array<real_T, 2U> &backgroundParams, const ::coder::array<real_T,
      2U> &qzshifts, const ::coder::array<real_T, 2U> &scalefactors, const ::
      coder::array<real_T, 2U> &bulkIns, const ::coder::array<real_T, 2U>
      &bulkOuts, const ::coder::array<real_T, 2U> &resolutionParams, const ::
      coder::array<real_T, 2U> &domainRatios, real_T dataPresent, const ::coder::
      array<real_T, 2U> &allData, const real_T dataLimits[2], const real_T
      simLimits[2], const real_T repeatLayers[2], real_T contrastBackgroundsType,
      real_T nParams, const char_T parallel_data[], const int32_T parallel_size
      [2], const real_T resamPars[2], boolean_T useImaginary, real_T resample,
      const char_T geometry_data[], const int32_T geometry_size[2], real_T
      roughness, boolean_T calcSld, const ::coder::array<real_T, 2U>
      &domainContrastLayers1, const ::coder::array<real_T, 2U>
      &domainContrastLayers2, const ::coder::array<cell_wrap_31, 2U>
      &outParameterisedLayers, real_T *backgroundParamValue, real_T
      *qzshiftValue, real_T *scalefactorValue, real_T *bulkInValue, real_T
      *bulkOutValue, real_T *resolutionParamValue, real_T *chi, ::coder::array<
      real_T, 2U> &reflectivity, ::coder::array<real_T, 2U> &simulation, ::coder::
      array<real_T, 2U> &shiftedData, cell_wrap_10 layerSld[2], cell_wrap_10
      sldProfile[2], cell_wrap_10 allLayer[2], real_T *ssub)
    {
      ::coder::array<real_T, 2U> a__6;
      ::coder::array<real_T, 2U> reflect1;
      ::coder::array<real_T, 2U> reflect2;
      ::coder::array<real_T, 2U> simul1;
      ::coder::array<real_T, 2U> simul2;
      ::coder::array<real_T, 2U> sldProfile1;
      ::coder::array<real_T, 2U> sldProfile2;
      ::coder::array<real_T, 2U> thisContrastLayers1_data;
      ::coder::array<real_T, 2U> thisContrastLayers2_data;
      RATMainTLS *RATMainTLSThread;
      cell_wrap_10 r;
      cell_wrap_10 r1;
      cell_wrap_10 r2;
      cell_wrap_10 r3;
      cell_wrap_10 r4;
      cell_wrap_10 r5;
      real_T a__5;
      real_T a__7;
      real_T a__8;
      real_T domainRatios_tmp;
      int32_T thisContrastLayers1_size[2];
      int32_T thisContrastLayers2_size[2];
      int32_T b_loop_ub;
      int32_T i;
      int32_T i1;
      int32_T loop_ub;
      RATMainTLSThread = emlrtGetThreadStackData();

      //  Get the domain ratio for this contrast
      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backgrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(backgroundParamIndex, qzshiftIndex, scalefactorIndex, bulkInIndex,
               bulkOutIndex, resolutionParamIndex, backgroundParams, qzshifts,
               scalefactors, bulkIns, bulkOuts, resolutionParams,
               backgroundParamValue, qzshiftValue, scalefactorValue, bulkInValue,
               bulkOutValue, resolutionParamValue);

      //  Also need to determine which layers from the overall layers list
      //  are required for this contrast, and put them in the correct order
      //  according to geometry. We run it twice, once for each domain...
      allocateLayersForContrast(domainContrastLayers1, outParameterisedLayers,
        useImaginary, RATMainTLSThread->f1.thisContrastLayers1_data,
        thisContrastLayers1_size);
      allocateLayersForContrast(domainContrastLayers2, outParameterisedLayers,
        useImaginary, RATMainTLSThread->f1.thisContrastLayers2_data,
        thisContrastLayers2_size);

      //  Call the core layers calculation - need to do this once for each
      //  domain
      thisContrastLayers1_data.set
        (&RATMainTLSThread->f1.thisContrastLayers1_data[0],
         thisContrastLayers1_size[0], thisContrastLayers1_size[1]);
      nonPolarisedTF::coreLayersCalculation(thisContrastLayers1_data, roughness,
        geometry_data, geometry_size, *bulkInValue, *bulkOutValue, resample,
        calcSld, *scalefactorValue, *qzshiftValue, dataPresent, allData,
        dataLimits, simLimits, repeatLayers, *backgroundParamValue,
        *resolutionParamValue, contrastBackgroundsType, nParams, parallel_data,
        parallel_size, resamPars, useImaginary, sldProfile1, reflect1, simul1,
        shiftedData, r.f1, r1.f1, &a__5, ssub);
      thisContrastLayers2_data.set
        (&RATMainTLSThread->f1.thisContrastLayers2_data[0],
         thisContrastLayers2_size[0], thisContrastLayers2_size[1]);
      nonPolarisedTF::coreLayersCalculation(thisContrastLayers2_data, roughness,
        geometry_data, geometry_size, *bulkInValue, *bulkOutValue, resample,
        calcSld, *scalefactorValue, *qzshiftValue, dataPresent, allData,
        dataLimits, simLimits, repeatLayers, *backgroundParamValue,
        *resolutionParamValue, contrastBackgroundsType, nParams, parallel_data,
        parallel_size, resamPars, useImaginary, sldProfile2, reflect2, simul2,
        a__6, r2.f1, r3.f1, &a__7, &a__8);

      //  Calculate the average reflectivities....
      //  Calculates the avereaged reflectivity for domains samples (incoherent
      //  sum)
      domainRatios_tmp = domainRatios[static_cast<int32_T>(domainRatioIndex) - 1];
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
      r4.f1.set_size(sldProfile1.size(0), sldProfile1.size(1));
      loop_ub = sldProfile1.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = sldProfile1.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          r4.f1[i1 + r4.f1.size(0) * i] = sldProfile1[i1 + sldProfile1.size(0) *
            i];
        }
      }

      r5.f1.set_size(sldProfile2.size(0), sldProfile2.size(1));
      loop_ub = sldProfile2.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = sldProfile2.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          r5.f1[i1 + r5.f1.size(0) * i] = sldProfile2[i1 + sldProfile2.size(0) *
            i];
        }
      }

      sldProfile[0] = r4;
      sldProfile[1] = r5;
      layerSld[0] = r;
      layerSld[1] = r2;
      allLayer[0] = r1;
      allLayer[1] = r3;
    }

    void standardLayers(const f_struct_T *problemStruct, const cell_11
                        *problemCells, const struct2_T *controls, ::coder::array<
                        real_T, 1U> &outSsubs, ::coder::array<real_T, 1U>
                        &backgroundParams, ::coder::array<real_T, 1U> &qzshifts,
                        ::coder::array<real_T, 1U> &scalefactors, ::coder::array<
                        real_T, 1U> &bulkIns, ::coder::array<real_T, 1U>
                        &bulkOuts, ::coder::array<real_T, 1U> &resolutionParams,
                        ::coder::array<real_T, 1U> &chis, ::coder::array<
                        cell_wrap_8, 1U> &reflectivity, ::coder::array<
                        cell_wrap_8, 1U> &simulation, ::coder::array<
                        cell_wrap_10, 1U> &shiftedData, ::coder::array<
                        cell_wrap_10, 2U> &domainLayerSlds, ::coder::array<
                        cell_wrap_10, 2U> &domainSldProfiles, ::coder::array<
                        cell_wrap_10, 2U> &domainAllLayers, ::coder::array<
                        real_T, 1U> &allRoughs)
    {
      ::coder::array<cell_wrap_10, 1U> domainContrastLayers1;
      ::coder::array<cell_wrap_10, 1U> domainContrastLayers2;
      ::coder::array<cell_wrap_31, 2U> outParameterisedLayers;
      ::coder::array<cell_wrap_53, 1U> allLayers;
      ::coder::array<cell_wrap_53, 1U> layerSlds;
      ::coder::array<cell_wrap_53, 1U> sldProfiles;
      ::coder::array<real_T, 2U> r;
      ::coder::array<real_T, 2U> r1;
      real_T d;
      real_T d1;
      real_T d2;
      real_T d3;
      real_T d4;
      real_T d5;
      real_T d6;
      real_T d7;
      real_T numberOfContrasts;
      int32_T b_i;
      int32_T b_loop_ub;
      int32_T c_i;
      int32_T c_loop_ub;
      int32_T d_loop_ub;
      int32_T i;
      int32_T i1;
      int32_T i2;
      int32_T i3;
      int32_T i4;
      int32_T loop_ub;
      int32_T nParams;
      int32_T unnamed_idx_0_tmp_tmp;
      boolean_T calcSld;
      boolean_T useImaginary;

      //  This is the main reflectivity calculation of the standard layers
      //  calculation type. It extracts the required parameters for the contrasts
      //  from the input arrays, then passes the main calculation to
      //  'coreLayersCalculation', which carries out the calculation itself.
      //  The core calculation is common for both standard and custom layers.
      //  Extract individual cell arrays
      //  Splits up the master input list of all arrays into separate arrays
      //
      //  INPUTS:
      //      * problemCells: cell array where all the project data is grouped together.
      //
      //  OUTPUTS:
      //      * repeatLayers: controls repeating of the layers stack.
      //      * allData: Array of all the data arrays.
      //      * dataLimits: Min max limits in q for the data arrays.
      //      * simLimits: Limits in Q for the reflectivity simulations.
      //      * layersDetails: Master array of all available layers.
      //      * contrastLayers: Which specific combination of arrays are needed for each contrast.
      //      * customFiles:Filenames and path for any custom files used.
      //  Additionally extract the additional domain layers details
      //  Extract individual parameters from problemStruct
      // Extract individual parameters from problem
      numberOfContrasts = problemStruct->numberOfContrasts;
      nParams = problemStruct->params.size(1);
      useImaginary = problemStruct->useImaginary;
      calcSld = controls->calcSldDuringFit;

      //  Allocate the memory for the output arrays before the main loop
      unnamed_idx_0_tmp_tmp = static_cast<int32_T>
        (problemStruct->numberOfContrasts);
      domainLayerSlds.set_size(unnamed_idx_0_tmp_tmp, 2);
      domainSldProfiles.set_size(unnamed_idx_0_tmp_tmp, 2);
      for (i = 0; i < (unnamed_idx_0_tmp_tmp << 1); i++) {
        domainLayerSlds[i].f1.set_size(0, 0);
        domainSldProfiles[i].f1.set_size(0, 0);
      }

      domainContrastLayers1.set_size(unnamed_idx_0_tmp_tmp);
      domainContrastLayers2.set_size(unnamed_idx_0_tmp_tmp);

      //  end memory allocation.
      //  First we need to allocate the absolute values of the input
      //  parameters to all the layers in the layers list. This only needs
      //  to be done once, and so is done outside the contrasts loop
      allocateParamsToLayers(problemStruct->params, problemCells->f6,
        outParameterisedLayers);

      //  Substrate roughness is always first parameter for standard layers
      allRoughs.set_size(unnamed_idx_0_tmp_tmp);
      for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
        domainContrastLayers1[b_i].f1.set_size(2, 1);
        domainContrastLayers1[b_i].f1[0] = 1.0;
        domainContrastLayers1[b_i].f1[1] = 1.0;
        domainContrastLayers2[b_i].f1.set_size(2, 1);
        domainContrastLayers2[b_i].f1[0] = 1.0;
        domainContrastLayers2[b_i].f1[1] = 1.0;
        allRoughs[b_i] = problemStruct->params[0];
      }

      i = domainContrastLayers1.size(0);
      domainContrastLayers1.set_size(unnamed_idx_0_tmp_tmp);
      for (b_i = 0; b_i < i; b_i++) {
        loop_ub = problemCells->f19[0].f1.size(1);
        domainContrastLayers1[0].f1.set_size(problemCells->f19[0].f1.size(0),
          problemCells->f19[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = problemCells->f19[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainContrastLayers1[0].f1[i2 + domainContrastLayers1[0].f1.size(0)
              * i1] = problemCells->f19[0].f1[i2 + problemCells->f19[0].f1.size
              (0) * i1];
          }
        }

        loop_ub = problemCells->f19[1].f1.size(1);
        domainContrastLayers2[0].f1.set_size(problemCells->f19
          [problemCells->f19.size(0)].f1.size(0), problemCells->f19
          [problemCells->f19.size(0)].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = problemCells->f19[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainContrastLayers2[0].f1[i2 + domainContrastLayers2[0].f1.size(0)
              * i1] = problemCells->f19[1].f1[i2 + problemCells->f19[1].f1.size
              (0) * i1];
          }
        }
      }

      if (coder::internal::l_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        //  Loop over all the contrasts
        allLayers.set_size(unnamed_idx_0_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp);
        layerSlds.set_size(unnamed_idx_0_tmp_tmp);
        shiftedData.set_size(unnamed_idx_0_tmp_tmp);
        simulation.set_size(unnamed_idx_0_tmp_tmp);
        reflectivity.set_size(unnamed_idx_0_tmp_tmp);
        backgroundParams.set_size(unnamed_idx_0_tmp_tmp);
        qzshifts.set_size(unnamed_idx_0_tmp_tmp);
        scalefactors.set_size(unnamed_idx_0_tmp_tmp);
        bulkIns.set_size(unnamed_idx_0_tmp_tmp);
        bulkOuts.set_size(unnamed_idx_0_tmp_tmp);
        resolutionParams.set_size(unnamed_idx_0_tmp_tmp);
        chis.set_size(unnamed_idx_0_tmp_tmp);
        outSsubs.set_size(unnamed_idx_0_tmp_tmp);
        domainAllLayers.set_size(unnamed_idx_0_tmp_tmp, 2);
        domainLayerSlds.set_size(unnamed_idx_0_tmp_tmp, 2);
        domainSldProfiles.set_size(unnamed_idx_0_tmp_tmp, 2);
        unnamed_idx_0_tmp_tmp--;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r1,d,d1,d2,d3,d4,d5,d6,d7,c_i,c_loop_ub,i3,d_loop_ub,i4)

        for (c_i = 0; c_i <= unnamed_idx_0_tmp_tmp; c_i++) {
          contrastCalculation(problemStruct->contrastBackgrounds[c_i],
                              problemStruct->contrastQzshifts[c_i],
                              problemStruct->contrastScalefactors[c_i],
                              problemStruct->contrastBulkIns[c_i],
                              problemStruct->contrastBulkOuts[c_i],
                              problemStruct->contrastResolutions[c_i],
                              problemStruct->contrastDomainRatios[c_i],
                              problemStruct->backgroundParams,
                              problemStruct->qzshifts,
                              problemStruct->scalefactors, problemStruct->bulkIn,
                              problemStruct->bulkOut,
                              problemStruct->resolutionParams,
                              problemStruct->domainRatio,
                              problemStruct->dataPresent[c_i], problemCells->
                              f2[c_i].f1, problemCells->f3[c_i].f1,
                              problemCells->f4[c_i].f1, problemCells->f1[c_i].f1,
                              problemStruct->contrastBackgroundsType[c_i],
                              static_cast<real_T>(nParams),
                              controls->parallel.data, controls->parallel.size,
                              controls->resamPars, useImaginary,
                              problemStruct->resample[c_i],
                              problemStruct->geometry.data,
                              problemStruct->geometry.size, allRoughs[c_i],
                              calcSld, domainContrastLayers1[c_i].f1,
                              domainContrastLayers2[c_i].f1,
                              outParameterisedLayers, &d7, &d6, &d5, &d4, &d3,
                              &d2, &d1, reflectivity[c_i].f1, simulation[c_i].f1,
                              r1, layerSlds[c_i].f1, sldProfiles[c_i].f1,
                              allLayers[c_i].f1, &d);
          c_loop_ub = r1.size(1);
          shiftedData[c_i].f1.set_size(r1.size(0), r1.size(1));
          for (i3 = 0; i3 < c_loop_ub; i3++) {
            d_loop_ub = r1.size(0);
            for (i4 = 0; i4 < d_loop_ub; i4++) {
              shiftedData[c_i].f1[i4 + shiftedData[c_i].f1.size(0) * i3] = r1[i4
                + r1.size(0) * i3];
            }
          }

          backgroundParams[c_i] = d7;
          qzshifts[c_i] = d6;
          scalefactors[c_i] = d5;
          bulkIns[c_i] = d4;
          bulkOuts[c_i] = d3;
          resolutionParams[c_i] = d2;
          chis[c_i] = d1;
          outSsubs[c_i] = d;
        }
      } else {
        //  Loop over all the contrasts
        allLayers.set_size(unnamed_idx_0_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp);
        layerSlds.set_size(unnamed_idx_0_tmp_tmp);
        shiftedData.set_size(unnamed_idx_0_tmp_tmp);
        simulation.set_size(unnamed_idx_0_tmp_tmp);
        reflectivity.set_size(unnamed_idx_0_tmp_tmp);
        backgroundParams.set_size(unnamed_idx_0_tmp_tmp);
        qzshifts.set_size(unnamed_idx_0_tmp_tmp);
        scalefactors.set_size(unnamed_idx_0_tmp_tmp);
        bulkIns.set_size(unnamed_idx_0_tmp_tmp);
        bulkOuts.set_size(unnamed_idx_0_tmp_tmp);
        resolutionParams.set_size(unnamed_idx_0_tmp_tmp);
        chis.set_size(unnamed_idx_0_tmp_tmp);
        outSsubs.set_size(unnamed_idx_0_tmp_tmp);
        domainAllLayers.set_size(unnamed_idx_0_tmp_tmp, 2);
        for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
          contrastCalculation(problemStruct->contrastBackgrounds[b_i],
                              problemStruct->contrastQzshifts[b_i],
                              problemStruct->contrastScalefactors[b_i],
                              problemStruct->contrastBulkIns[b_i],
                              problemStruct->contrastBulkOuts[b_i],
                              problemStruct->contrastResolutions[b_i],
                              problemStruct->contrastDomainRatios[b_i],
                              problemStruct->backgroundParams,
                              problemStruct->qzshifts,
                              problemStruct->scalefactors, problemStruct->bulkIn,
                              problemStruct->bulkOut,
                              problemStruct->resolutionParams,
                              problemStruct->domainRatio,
                              problemStruct->dataPresent[b_i], problemCells->
                              f2[b_i].f1, problemCells->f3[b_i].f1,
                              problemCells->f4[b_i].f1, problemCells->f1[b_i].f1,
                              problemStruct->contrastBackgroundsType[b_i],
                              static_cast<real_T>(problemStruct->params.size(1)),
                              controls->parallel.data, controls->parallel.size,
                              controls->resamPars, problemStruct->useImaginary,
                              problemStruct->resample[b_i],
                              problemStruct->geometry.data,
                              problemStruct->geometry.size, allRoughs[b_i],
                              calcSld, domainContrastLayers1[b_i].f1,
                              domainContrastLayers2[b_i].f1,
                              outParameterisedLayers, &backgroundParams[b_i],
                              &qzshifts[b_i], &scalefactors[b_i], &bulkIns[b_i],
                              &bulkOuts[b_i], &resolutionParams[b_i], &chis[b_i],
                              reflectivity[b_i].f1, simulation[b_i].f1, r,
                              layerSlds[b_i].f1, sldProfiles[b_i].f1,
                              allLayers[b_i].f1, &outSsubs[b_i]);
          loop_ub = r.size(1);
          shiftedData[b_i].f1.set_size(r.size(0), r.size(1));
          for (i = 0; i < loop_ub; i++) {
            b_loop_ub = r.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              shiftedData[b_i].f1[i1 + shiftedData[b_i].f1.size(0) * i] = r[i1 +
                r.size(0) * i];
            }
          }
        }
      }

      i = static_cast<int32_T>(numberOfContrasts);
      for (b_i = 0; b_i < i; b_i++) {
        loop_ub = sldProfiles[b_i].f1[0].f1.size(1);
        domainSldProfiles[b_i].f1.set_size(sldProfiles[b_i].f1[0].f1.size(0),
          sldProfiles[b_i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = sldProfiles[b_i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainSldProfiles[b_i].f1[i2 + domainSldProfiles[b_i].f1.size(0) *
              i1] = sldProfiles[b_i].f1[0].f1[i2 + sldProfiles[b_i].f1[0].
              f1.size(0) * i1];
          }
        }

        loop_ub = sldProfiles[b_i].f1[1].f1.size(1);
        domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.set_size
          (sldProfiles[b_i].f1[1].f1.size(0), sldProfiles[b_i].f1[1].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = sldProfiles[b_i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainSldProfiles[b_i + domainSldProfiles.size(0)].f1[i2 +
              domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.size(0) * i1]
              = sldProfiles[b_i].f1[1].f1[i2 + sldProfiles[b_i].f1[1].f1.size(0)
              * i1];
          }
        }

        loop_ub = layerSlds[b_i].f1[0].f1.size(1);
        domainLayerSlds[b_i].f1.set_size(layerSlds[b_i].f1[0].f1.size(0),
          layerSlds[b_i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = layerSlds[b_i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainLayerSlds[b_i].f1[i2 + domainLayerSlds[b_i].f1.size(0) * i1] =
              layerSlds[b_i].f1[0].f1[i2 + layerSlds[b_i].f1[0].f1.size(0) * i1];
          }
        }

        loop_ub = layerSlds[b_i].f1[1].f1.size(1);
        domainLayerSlds[b_i + domainLayerSlds.size(0)].f1.set_size(layerSlds[b_i]
          .f1[1].f1.size(0), layerSlds[b_i].f1[1].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = layerSlds[b_i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainLayerSlds[b_i + domainLayerSlds.size(0)].f1[i2 +
              domainLayerSlds[b_i + domainLayerSlds.size(0)].f1.size(0) * i1] =
              layerSlds[b_i].f1[1].f1[i2 + layerSlds[b_i].f1[1].f1.size(0) * i1];
          }
        }

        loop_ub = allLayers[b_i].f1[0].f1.size(1);
        domainAllLayers[b_i].f1.set_size(allLayers[b_i].f1[0].f1.size(0),
          allLayers[b_i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = allLayers[b_i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainAllLayers[b_i].f1[i2 + domainAllLayers[b_i].f1.size(0) * i1] =
              allLayers[b_i].f1[0].f1[i2 + allLayers[b_i].f1[0].f1.size(0) * i1];
          }
        }

        loop_ub = allLayers[b_i].f1[1].f1.size(1);
        domainAllLayers[b_i + domainAllLayers.size(0)].f1.set_size(allLayers[b_i]
          .f1[1].f1.size(0), allLayers[b_i].f1[1].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = allLayers[b_i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainAllLayers[b_i + domainAllLayers.size(0)].f1[i2 +
              domainAllLayers[b_i + domainAllLayers.size(0)].f1.size(0) * i1] =
              allLayers[b_i].f1[1].f1[i2 + allLayers[b_i].f1[1].f1.size(0) * i1];
          }
        }
      }
    }
  }
}

// End of code generation (standardLayers1.cpp)
