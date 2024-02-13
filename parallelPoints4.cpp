//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// parallelPoints4.cpp
//
// Code generation for function 'parallelPoints4'
//

// Include files
#include "parallelPoints4.h"
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
      void parallelPoints(const d_struct_T *problemStruct, const cell_11
                          *problemCells, const struct2_T *controls, ::coder::
                          array<real_T, 1U> &outSsubs, ::coder::array<real_T, 1U>
                          &backgroundParams, ::coder::array<real_T, 1U>
                          &qzshifts, ::coder::array<real_T, 1U> &scalefactors, ::
                          coder::array<real_T, 1U> &bulkIns, ::coder::array<
                          real_T, 1U> &bulkOuts, ::coder::array<real_T, 1U>
                          &resolutionParams, ::coder::array<real_T, 1U> &chis, ::
                          coder::array<cell_wrap_20, 1U> &reflectivity, ::coder::
                          array<cell_wrap_20, 1U> &simulation, ::coder::array<
                          cell_wrap_8, 1U> &shiftedData, ::coder::array<
                          cell_wrap_8, 2U> &layerSlds, ::coder::array<
                          cell_wrap_8, 2U> &domainSldProfiles, ::coder::array<
                          cell_wrap_8, 2U> &allLayers, ::coder::array<real_T, 1U>
                          &allRoughs)
      {
        ::coder::array<cell_wrap_18, 2U> r;
        ::coder::array<cell_wrap_34, 1U> tempAllLayers;
        ::coder::array<cell_wrap_34, 1U> tempLayerSlds;
        ::coder::array<cell_wrap_34, 1U> tempSldProfiles;
        ::coder::array<cell_wrap_8, 2U> calcAllLayers;
        ::coder::array<real_T, 2U> a__5;
        ::coder::array<real_T, 2U> reflect1;
        ::coder::array<real_T, 2U> reflect2;
        ::coder::array<real_T, 2U> shiftedDat;
        ::coder::array<real_T, 2U> simul1;
        ::coder::array<real_T, 2U> simul2;
        ::coder::array<real_T, 2U> sldProfile1;
        ::coder::array<real_T, 2U> sldProfile2;
        ::coder::array<real_T, 2U> totReflect;
        cell_wrap_8 r1;
        cell_wrap_8 r2;
        cell_wrap_8 r3;
        cell_wrap_8 r4;
        cell_wrap_8 r5;
        cell_wrap_8 r6;
        real_T a__4;
        real_T a__6;
        real_T a__7;
        real_T thisBackground;
        real_T thisBulkIn;
        real_T thisBulkOut;
        real_T thisQzshift;
        real_T thisResol;
        real_T thisScalefactor;
        int32_T b_i;
        int32_T b_loop_ub;
        int32_T i;
        int32_T i1;
        int32_T i2;
        int32_T loop_ub;
        int32_T nParams;
        boolean_T calcSld;
        boolean_T useImaginary;

        //  Single threaded version of the custom layers, domainsTF reflectivity
        //  calculation. The function extracts the relevant parameters from the input
        //  arrays, allocates these on a pre-contrast basis, then calls the 'core'
        //  calculation (the core layers nonPolarisedTF calc is shared between
        //  multiple calculation types).
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
        calcSld = controls->calcSldDuringFit;
        useImaginary = problemStruct->useImaginary;

        //  Default for compile.
        //  Pre-Allocation of output arrays...
        i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        backgroundParams.set_size(i);

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
        outSsubs.set_size(i);
        tempSldProfiles.set_size(i);
        reflectivity.set_size(i);
        simulation.set_size(i);
        shiftedData.set_size(i);
        tempLayerSlds.set_size(i);
        tempAllLayers.set_size(i);
        chis.set_size(i);
        qzshifts.set_size(i);
        scalefactors.set_size(i);
        bulkIns.set_size(i);
        bulkOuts.set_size(i);
        resolutionParams.set_size(i);
        layerSlds.set_size(i, 2);
        domainSldProfiles.set_size(i, 2);
        for (b_i = 0; b_i < i; b_i++) {
          //  Get the domain ratio for this contrast
          //  Extract the relevant parameter values for this contrast
          //  from the input arrays.
          //  First need to decide which values of the backgrounds, scalefactors
          //  data shifts and bulk contrasts are associated with this contrast
          backSort(problemStruct->contrastBackgrounds[b_i],
                   problemStruct->contrastQzshifts[b_i],
                   problemStruct->contrastScalefactors[b_i],
                   problemStruct->contrastBulkIns[b_i],
                   problemStruct->contrastBulkOuts[b_i],
                   problemStruct->contrastResolutions[b_i],
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
          nonPolarisedTF::b_coreLayersCalculation(calcAllLayers[b_i].f1,
            allRoughs[b_i], problemStruct->geometry.data,
            problemStruct->geometry.size, thisBulkIn, thisBulkOut,
            problemStruct->resample[b_i], calcSld, thisScalefactor, thisQzshift,
            problemStruct->dataPresent[b_i], problemCells->f2[b_i].f1,
            problemCells->f3[b_i].f1, problemCells->f4[b_i].f1, problemCells->
            f1[b_i].f1, thisBackground, thisResol,
            problemStruct->contrastBackgroundsType[b_i], static_cast<real_T>
            (nParams), controls->resamPars, useImaginary, sldProfile1, reflect1,
            simul1, shiftedDat, r1.f1, r2.f1, &a__4, &outSsubs[b_i]);

          //  Domain 2
          nonPolarisedTF::b_coreLayersCalculation(calcAllLayers[b_i +
            calcAllLayers.size(0)].f1, allRoughs[b_i],
            problemStruct->geometry.data, problemStruct->geometry.size,
            thisBulkIn, thisBulkOut, problemStruct->resample[b_i], calcSld,
            thisScalefactor, thisQzshift, problemStruct->dataPresent[b_i],
            problemCells->f2[b_i].f1, problemCells->f3[b_i].f1, problemCells->
            f4[b_i].f1, problemCells->f1[b_i].f1, thisBackground, thisResol,
            problemStruct->contrastBackgroundsType[b_i], static_cast<real_T>
            (nParams), controls->resamPars, useImaginary, sldProfile2, reflect2,
            simul2, a__5, r3.f1, r4.f1, &a__6, &a__7);

          //  Calculate the average reflectivities....
          averageReflectivity(reflect1, reflect2, simul1, simul2,
                              problemStruct->domainRatio[static_cast<int32_T>
                              (problemStruct->contrastDomainRatios[b_i]) - 1],
                              totReflect, simulation[b_i].f1);

          //  Get an overall chi-squared for the new averaged curve..
          chis[b_i] = chiSquared(shiftedDat, totReflect, static_cast<real_T>
            (problemStruct->params.size(1)));

          //  Store returned values for this contrast in the output arrays.
          //  As well as the calculated profiles, we also store a record of
          //  the other values (background, scalefactors etc) for each contrast
          //  for future use.
          //      domainSldProfiles{i,1} = sldProfile1;
          //      domainSldProfiles{i,2} = sldProfile2;
          loop_ub = sldProfile1.size(1);
          r5.f1.set_size(sldProfile1.size(0), sldProfile1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = sldProfile1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              r5.f1[i2 + r5.f1.size(0) * i1] = sldProfile1[i2 + sldProfile1.size
                (0) * i1];
            }
          }

          loop_ub = sldProfile2.size(1);
          r6.f1.set_size(sldProfile2.size(0), sldProfile2.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = sldProfile2.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              r6.f1[i2 + r6.f1.size(0) * i1] = sldProfile2[i2 + sldProfile2.size
                (0) * i1];
            }
          }

          tempSldProfiles[b_i].f1[0] = r5;
          tempSldProfiles[b_i].f1[1] = r6;
          reflectivity[b_i].f1.set_size(totReflect.size(0), 2);
          loop_ub = totReflect.size(0);
          for (i1 = 0; i1 < 2; i1++) {
            for (i2 = 0; i2 < loop_ub; i2++) {
              reflectivity[b_i].f1[i2 + reflectivity[b_i].f1.size(0) * i1] =
                totReflect[i2 + totReflect.size(0) * i1];
            }
          }

          shiftedData[b_i].f1.set_size(shiftedDat.size(0), shiftedDat.size(1));
          loop_ub = shiftedDat.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = shiftedDat.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              shiftedData[b_i].f1[i2 + shiftedData[b_i].f1.size(0) * i1] =
                shiftedDat[i2 + shiftedDat.size(0) * i1];
            }
          }

          tempLayerSlds[b_i].f1[0] = r1;
          tempLayerSlds[b_i].f1[1] = r3;
          tempAllLayers[b_i].f1[0] = r2;
          tempAllLayers[b_i].f1[1] = r4;
          backgroundParams[b_i] = thisBackground;
          qzshifts[b_i] = thisQzshift;
          scalefactors[b_i] = thisScalefactor;
          bulkIns[b_i] = thisBulkIn;
          bulkOuts[b_i] = thisBulkOut;
          resolutionParams[b_i] = thisResol;
        }

        allLayers.set_size(i, 2);
        for (b_i = 0; b_i < i; b_i++) {
          loop_ub = tempSldProfiles[b_i].f1[0].f1.size(1);
          domainSldProfiles[b_i].f1.set_size(tempSldProfiles[b_i].f1[0].f1.size
            (0), tempSldProfiles[b_i].f1[0].f1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = tempSldProfiles[b_i].f1[0].f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              domainSldProfiles[b_i].f1[i2 + domainSldProfiles[b_i].f1.size(0) *
                i1] = tempSldProfiles[b_i].f1[0].f1[i2 + tempSldProfiles[b_i]
                .f1[0].f1.size(0) * i1];
            }
          }

          loop_ub = tempSldProfiles[b_i].f1[1].f1.size(1);
          domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.set_size
            (tempSldProfiles[b_i].f1[1].f1.size(0), tempSldProfiles[b_i].f1[1].
             f1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = tempSldProfiles[b_i].f1[1].f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              domainSldProfiles[b_i + domainSldProfiles.size(0)].f1[i2 +
                domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.size(0) *
                i1] = tempSldProfiles[b_i].f1[1].f1[i2 + tempSldProfiles[b_i]
                .f1[1].f1.size(0) * i1];
            }
          }

          loop_ub = tempAllLayers[b_i].f1[0].f1.size(1);
          allLayers[b_i].f1.set_size(tempAllLayers[b_i].f1[0].f1.size(0),
            tempAllLayers[b_i].f1[0].f1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = tempAllLayers[b_i].f1[0].f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              allLayers[b_i].f1[i2 + allLayers[b_i].f1.size(0) * i1] =
                tempAllLayers[b_i].f1[0].f1[i2 + tempAllLayers[b_i].f1[0].
                f1.size(0) * i1];
            }
          }

          loop_ub = tempAllLayers[b_i].f1[1].f1.size(1);
          allLayers[b_i + allLayers.size(0)].f1.set_size(tempAllLayers[b_i].f1[1]
            .f1.size(0), tempAllLayers[b_i].f1[1].f1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = tempAllLayers[b_i].f1[1].f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              allLayers[b_i + allLayers.size(0)].f1[i2 + allLayers[b_i +
                allLayers.size(0)].f1.size(0) * i1] = tempAllLayers[b_i].f1[1].
                f1[i2 + tempAllLayers[b_i].f1[1].f1.size(0) * i1];
            }
          }

          loop_ub = tempLayerSlds[b_i].f1[0].f1.size(1);
          layerSlds[b_i].f1.set_size(tempLayerSlds[b_i].f1[0].f1.size(0),
            tempLayerSlds[b_i].f1[0].f1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = tempLayerSlds[b_i].f1[0].f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              layerSlds[b_i].f1[i2 + layerSlds[b_i].f1.size(0) * i1] =
                tempLayerSlds[b_i].f1[0].f1[i2 + tempLayerSlds[b_i].f1[0].
                f1.size(0) * i1];
            }
          }

          loop_ub = tempLayerSlds[b_i].f1[1].f1.size(1);
          layerSlds[b_i + layerSlds.size(0)].f1.set_size(tempLayerSlds[b_i].f1[1]
            .f1.size(0), tempLayerSlds[b_i].f1[1].f1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = tempLayerSlds[b_i].f1[1].f1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              layerSlds[b_i + layerSlds.size(0)].f1[i2 + layerSlds[b_i +
                layerSlds.size(0)].f1.size(0) * i1] = tempLayerSlds[b_i].f1[1].
                f1[i2 + tempLayerSlds[b_i].f1[1].f1.size(0) * i1];
            }
          }
        }
      }
    }
  }
}

// End of code generation (parallelPoints4.cpp)
