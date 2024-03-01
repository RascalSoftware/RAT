//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// parallelContrasts4.cpp
//
// Code generation for function 'parallelContrasts4'
//

// Include files
#include "parallelContrasts4.h"
#include "RATMain_internal_types.h"
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "averageReflectivity.h"
#include "backSort.h"
#include "chiSquared.h"
#include "coreLayersCalculation.h"
#include "processCustomFunction2.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Definitions
namespace RAT
{
  namespace domainsTF
  {
    namespace customLayers
    {
      void parallelContrasts(const f_struct_T *problemStruct, const cell_11
        *problemCells, const struct2_T *controls, ::coder::array<real_T, 1U>
        &outSsubs, ::coder::array<real_T, 1U> &backgroundParams, ::coder::array<
        real_T, 1U> &qzshifts, ::coder::array<real_T, 1U> &scalefactors, ::coder::
        array<real_T, 1U> &bulkIns, ::coder::array<real_T, 1U> &bulkOuts, ::
        coder::array<real_T, 1U> &resolutionParams, ::coder::array<real_T, 1U>
        &chis, ::coder::array<cell_wrap_8, 1U> &reflectivity, ::coder::array<
        cell_wrap_8, 1U> &simulation, ::coder::array<cell_wrap_10, 1U>
        &shiftedData, ::coder::array<cell_wrap_10, 2U> &layerSlds, ::coder::
        array<cell_wrap_10, 2U> &domainSldProfiles, ::coder::array<cell_wrap_10,
        2U> &allLayers, ::coder::array<real_T, 1U> &allRoughs)
      {
        ::coder::array<cell_wrap_10, 2U> calcAllLayers;
        ::coder::array<cell_wrap_25, 2U> r;
        ::coder::array<cell_wrap_39, 1U> tempAllLayers;
        ::coder::array<cell_wrap_39, 1U> tempLayerSlds;
        ::coder::array<cell_wrap_39, 1U> tempSldProfiles;
        ::coder::array<real_T, 2U> a__5;
        ::coder::array<real_T, 2U> reflect1;
        ::coder::array<real_T, 2U> reflect2;
        ::coder::array<real_T, 2U> shiftedDat;
        ::coder::array<real_T, 2U> simul1;
        ::coder::array<real_T, 2U> simul2;
        ::coder::array<real_T, 2U> sldProfile1;
        ::coder::array<real_T, 2U> sldProfile2;
        ::coder::array<real_T, 2U> totReflect;
        ::coder::array<real_T, 2U> totSimul;
        cell_wrap_10 r1;
        cell_wrap_10 r2;
        cell_wrap_10 r3;
        cell_wrap_10 r4;
        cell_wrap_10 r5;
        cell_wrap_10 r6;
        real_T a__4;
        real_T a__6;
        real_T a__7;
        real_T numberOfContrasts;
        real_T thisBackground;
        real_T thisBulkIn;
        real_T thisBulkOut;
        real_T thisChiSquared;
        real_T thisQzshift;
        real_T thisResol;
        real_T thisScalefactor;
        real_T thisSsubs;
        int32_T c_loop_ub;
        int32_T d_loop_ub;
        int32_T i;
        int32_T i2;
        int32_T i3;
        int32_T nParams;
        int32_T ub_loop;
        boolean_T calcSld;
        boolean_T useImaginary;

        //  Single threaded version of the custom layers, domainsTF reflectivity
        //  calculation. The function extracts the relevant parameters from the input
        //  arrays, allocates these on a pre-contrast basis, then calls the 'core'
        //  calculation (the core layers domainsTF calc is shared between multiple
        //  calculation types).
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
        //  Extract individual parameters from problemStruct
        // Extract individual parameters from problem
        nParams = problemStruct->params.size(1);
        numberOfContrasts = problemStruct->numberOfContrasts;
        calcSld = controls->calcSldDuringFit;
        useImaginary = problemStruct->useImaginary;

        //  Default for compile.
        //  Pre-Allocation of output arrays...
        backgroundParams.set_size(static_cast<int32_T>
          (problemStruct->numberOfContrasts));

        //  Resampling parameters
        //  Process the custom models....
        processCustomFunction(problemStruct->contrastBulkIns,
                              problemStruct->contrastBulkOuts,
                              problemStruct->bulkIn, problemStruct->bulkOut,
                              problemStruct->contrastCustomFiles,
                              problemStruct->numberOfContrasts,
                              problemCells->f14, problemStruct->params,
                              problemStruct->useImaginary, r, allRoughs);
        cast(r, calcAllLayers);

        //  Parallel over all contrasts
        // layersCounter = 1;
        outSsubs.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        tempSldProfiles.set_size(static_cast<int32_T>
          (problemStruct->numberOfContrasts));
        reflectivity.set_size(static_cast<int32_T>
                              (problemStruct->numberOfContrasts));
        simulation.set_size(static_cast<int32_T>
                            (problemStruct->numberOfContrasts));
        shiftedData.set_size(static_cast<int32_T>
                             (problemStruct->numberOfContrasts));
        tempLayerSlds.set_size(static_cast<int32_T>
          (problemStruct->numberOfContrasts));
        tempAllLayers.set_size(static_cast<int32_T>
          (problemStruct->numberOfContrasts));
        chis.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        qzshifts.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        scalefactors.set_size(static_cast<int32_T>
                              (problemStruct->numberOfContrasts));
        bulkIns.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        bulkOuts.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        resolutionParams.set_size(static_cast<int32_T>
          (problemStruct->numberOfContrasts));
        layerSlds.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts),
                           2);
        allLayers.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts),
                           2);
        domainSldProfiles.set_size(static_cast<int32_T>
          (problemStruct->numberOfContrasts), 2);
        ub_loop = static_cast<int32_T>(problemStruct->numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r1,r2,sldProfile2,sldProfile1,reflect1,simul1,shiftedDat,r3,r4,reflect2,simul2,a__5,r5,r6,totReflect,totSimul,thisChiSquared,a__7,a__6,thisSsubs,a__4,thisResol,thisBulkOut,thisBulkIn,thisScalefactor,thisQzshift,thisBackground,i,c_loop_ub,i2,d_loop_ub,i3)

        for (i = 0; i <= ub_loop; i++) {
          //  Get the domain ratio for this contrast
          //  Extract the relevant parameter values for this contrast
          //  from the input arrays.
          //  First need to decide which values of the backgrounds, scalefactors
          //  data shifts and bulk contrasts are associated with this contrast
          backSort(problemStruct->contrastBackgrounds[i],
                   problemStruct->contrastQzshifts[i],
                   problemStruct->contrastScalefactors[i],
                   problemStruct->contrastBulkIns[i],
                   problemStruct->contrastBulkOuts[i],
                   problemStruct->contrastResolutions[i],
                   problemStruct->backgroundParams, problemStruct->qzshifts,
                   problemStruct->scalefactors, problemStruct->bulkIn,
                   problemStruct->bulkOut, problemStruct->resolutionParams,
                   &thisBackground, &thisQzshift, &thisScalefactor, &thisBulkIn,
                   &thisBulkOut, &thisResol);

          //  Get the custom layers output for this contrast
          //  We have two for each contrast - one for each domain
          //  For the other parameters, we extract the correct ones from the input
          //  arrays
          //  Now call the core layers reflectivity calculation
          //  In this case we are single cored, so we do not parallelise over
          //  points
          //  Call the reflectivity calculation for each domain
          //  Domain 1
          nonPolarisedTF::coreLayersCalculation(calcAllLayers[i].f1, allRoughs[i],
            problemStruct->geometry.data, problemStruct->geometry.size,
            thisBulkIn, thisBulkOut, problemStruct->resample[i], calcSld,
            thisScalefactor, thisQzshift, problemStruct->dataPresent[i],
            problemCells->f2[i].f1, problemCells->f3[i].f1, problemCells->f4[i].
            f1, problemCells->f1[i].f1, thisBackground, thisResol,
            problemStruct->contrastBackgroundsType[i], static_cast<real_T>
            (nParams), controls->resamPars, useImaginary, sldProfile1, reflect1,
            simul1, shiftedDat, r3.f1, r4.f1, &a__4, &thisSsubs);

          //  Domain 2
          nonPolarisedTF::coreLayersCalculation(calcAllLayers[i +
            calcAllLayers.size(0)].f1, allRoughs[i],
            problemStruct->geometry.data, problemStruct->geometry.size,
            thisBulkIn, thisBulkOut, problemStruct->resample[i], calcSld,
            thisScalefactor, thisQzshift, problemStruct->dataPresent[i],
            problemCells->f2[i].f1, problemCells->f3[i].f1, problemCells->f4[i].
            f1, problemCells->f1[i].f1, thisBackground, thisResol,
            problemStruct->contrastBackgroundsType[i], static_cast<real_T>
            (nParams), controls->resamPars, useImaginary, sldProfile2, reflect2,
            simul2, a__5, r5.f1, r6.f1, &a__6, &a__7);

          //  Calculate the average reflectivities....
          averageReflectivity(reflect1, reflect2, simul1, simul2,
                              problemStruct->domainRatio[static_cast<int32_T>
                              (problemStruct->contrastDomainRatios[i]) - 1],
                              totReflect, totSimul);

          //  Get an overall chi-squared for the new averaged curve..
          thisChiSquared = chiSquared(shiftedDat, totReflect, static_cast<real_T>
            (problemStruct->params.size(1)));

          //  Store returned values for this contrast in the output arrays.
          //  As well as the calculated profiles, we also store a record of
          //  the other values (background, scalefactors etc) for each contrast
          //  for future use.
          outSsubs[i] = thisSsubs;

          //      domainSldProfiles{i,1} = sldProfile1;
          //      domainSldProfiles{i,2} = sldProfile2;
          c_loop_ub = sldProfile1.size(1);
          r2.f1.set_size(sldProfile1.size(0), sldProfile1.size(1));
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            d_loop_ub = sldProfile1.size(0);
            for (i3 = 0; i3 < d_loop_ub; i3++) {
              r2.f1[i3 + r2.f1.size(0) * i2] = sldProfile1[i3 + sldProfile1.size
                (0) * i2];
            }
          }

          c_loop_ub = sldProfile2.size(1);
          r1.f1.set_size(sldProfile2.size(0), sldProfile2.size(1));
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            d_loop_ub = sldProfile2.size(0);
            for (i3 = 0; i3 < d_loop_ub; i3++) {
              r1.f1[i3 + r1.f1.size(0) * i2] = sldProfile2[i3 + sldProfile2.size
                (0) * i2];
            }
          }

          tempSldProfiles[i].f1[0] = r2;
          tempSldProfiles[i].f1[1] = r1;
          reflectivity[i].f1.set_size(totReflect.size(0), 2);
          c_loop_ub = totSimul.size(0);
          simulation[i].f1.set_size(totSimul.size(0), 2);
          d_loop_ub = totReflect.size(0);
          for (i2 = 0; i2 < 2; i2++) {
            for (i3 = 0; i3 < d_loop_ub; i3++) {
              reflectivity[i].f1[i3 + reflectivity[i].f1.size(0) * i2] =
                totReflect[i3 + totReflect.size(0) * i2];
            }

            for (i3 = 0; i3 < c_loop_ub; i3++) {
              simulation[i].f1[i3 + simulation[i].f1.size(0) * i2] = totSimul[i3
                + totSimul.size(0) * i2];
            }
          }

          shiftedData[i].f1.set_size(shiftedDat.size(0), shiftedDat.size(1));
          c_loop_ub = shiftedDat.size(1);
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            d_loop_ub = shiftedDat.size(0);
            for (i3 = 0; i3 < d_loop_ub; i3++) {
              shiftedData[i].f1[i3 + shiftedData[i].f1.size(0) * i2] =
                shiftedDat[i3 + shiftedDat.size(0) * i2];
            }
          }

          tempLayerSlds[i].f1[0] = r3;
          tempLayerSlds[i].f1[1] = r5;
          tempAllLayers[i].f1[0] = r4;
          tempAllLayers[i].f1[1] = r6;
          chis[i] = thisChiSquared;
          backgroundParams[i] = thisBackground;
          qzshifts[i] = thisQzshift;
          scalefactors[i] = thisScalefactor;
          bulkIns[i] = thisBulkIn;
          bulkOuts[i] = thisBulkOut;
          resolutionParams[i] = thisResol;
        }

        ub_loop = static_cast<int32_T>(numberOfContrasts);
        for (int32_T b_i{0}; b_i < ub_loop; b_i++) {
          int32_T b_loop_ub;
          int32_T c_i;
          int32_T i1;
          int32_T loop_ub;
          loop_ub = tempSldProfiles[b_i].f1[0].f1.size(1);
          domainSldProfiles[b_i].f1.set_size(tempSldProfiles[b_i].f1[0].f1.size
            (0), tempSldProfiles[b_i].f1[0].f1.size(1));
          for (c_i = 0; c_i < loop_ub; c_i++) {
            b_loop_ub = tempSldProfiles[b_i].f1[0].f1.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              domainSldProfiles[b_i].f1[i1 + domainSldProfiles[b_i].f1.size(0) *
                c_i] = tempSldProfiles[b_i].f1[0].f1[i1 + tempSldProfiles[b_i].
                f1[0].f1.size(0) * c_i];
            }
          }

          loop_ub = tempSldProfiles[b_i].f1[1].f1.size(1);
          domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.set_size
            (tempSldProfiles[b_i].f1[1].f1.size(0), tempSldProfiles[b_i].f1[1].
             f1.size(1));
          for (c_i = 0; c_i < loop_ub; c_i++) {
            b_loop_ub = tempSldProfiles[b_i].f1[1].f1.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              domainSldProfiles[b_i + domainSldProfiles.size(0)].f1[i1 +
                domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.size(0) *
                c_i] = tempSldProfiles[b_i].f1[1].f1[i1 + tempSldProfiles[b_i].
                f1[1].f1.size(0) * c_i];
            }
          }

          loop_ub = tempAllLayers[b_i].f1[0].f1.size(1);
          allLayers[b_i].f1.set_size(tempAllLayers[b_i].f1[0].f1.size(0),
            tempAllLayers[b_i].f1[0].f1.size(1));
          for (c_i = 0; c_i < loop_ub; c_i++) {
            b_loop_ub = tempAllLayers[b_i].f1[0].f1.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              allLayers[b_i].f1[i1 + allLayers[b_i].f1.size(0) * c_i] =
                tempAllLayers[b_i].f1[0].f1[i1 + tempAllLayers[b_i].f1[0].
                f1.size(0) * c_i];
            }
          }

          loop_ub = tempAllLayers[b_i].f1[1].f1.size(1);
          allLayers[b_i + allLayers.size(0)].f1.set_size(tempAllLayers[b_i].f1[1]
            .f1.size(0), tempAllLayers[b_i].f1[1].f1.size(1));
          for (c_i = 0; c_i < loop_ub; c_i++) {
            b_loop_ub = tempAllLayers[b_i].f1[1].f1.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              allLayers[b_i + allLayers.size(0)].f1[i1 + allLayers[b_i +
                allLayers.size(0)].f1.size(0) * c_i] = tempAllLayers[b_i].f1[1].
                f1[i1 + tempAllLayers[b_i].f1[1].f1.size(0) * c_i];
            }
          }

          loop_ub = tempLayerSlds[b_i].f1[0].f1.size(1);
          layerSlds[b_i].f1.set_size(tempLayerSlds[b_i].f1[0].f1.size(0),
            tempLayerSlds[b_i].f1[0].f1.size(1));
          for (c_i = 0; c_i < loop_ub; c_i++) {
            b_loop_ub = tempLayerSlds[b_i].f1[0].f1.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              layerSlds[b_i].f1[i1 + layerSlds[b_i].f1.size(0) * c_i] =
                tempLayerSlds[b_i].f1[0].f1[i1 + tempLayerSlds[b_i].f1[0].
                f1.size(0) * c_i];
            }
          }

          loop_ub = tempLayerSlds[b_i].f1[1].f1.size(1);
          layerSlds[b_i + layerSlds.size(0)].f1.set_size(tempLayerSlds[b_i].f1[1]
            .f1.size(0), tempLayerSlds[b_i].f1[1].f1.size(1));
          for (c_i = 0; c_i < loop_ub; c_i++) {
            b_loop_ub = tempLayerSlds[b_i].f1[1].f1.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              layerSlds[b_i + layerSlds.size(0)].f1[i1 + layerSlds[b_i +
                layerSlds.size(0)].f1.size(0) * c_i] = tempLayerSlds[b_i].f1[1].
                f1[i1 + tempLayerSlds[b_i].f1[1].f1.size(0) * c_i];
            }
          }
        }
      }
    }
  }
}

// End of code generation (parallelContrasts4.cpp)
