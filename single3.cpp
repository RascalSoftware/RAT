//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// single3.cpp
//
// Code generation for function 'single3'
//

// Include files
#include "single3.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "averageReflectivity.h"
#include "backSort.h"
#include "chiSquared.h"
#include "coreLayersCalculation.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Definitions
namespace RAT
{
  namespace domainsTF
  {
    namespace standardLayers
    {
      void b_single(const f_struct_T *problemStruct, const cell_11 *problemCells,
                    const struct2_T *controls, ::coder::array<real_T, 1U>
                    &outSsubs, ::coder::array<real_T, 1U> &backgroundParams, ::
                    coder::array<real_T, 1U> &qzshifts, ::coder::array<real_T,
                    1U> &scalefactors, ::coder::array<real_T, 1U> &bulkIns, ::
                    coder::array<real_T, 1U> &bulkOuts, ::coder::array<real_T,
                    1U> &resolutionParams, ::coder::array<real_T, 1U> &chis, ::
                    coder::array<cell_wrap_8, 1U> &reflectivity, ::coder::array<
                    cell_wrap_8, 1U> &simulation, ::coder::array<cell_wrap_10,
                    1U> &shiftedData, ::coder::array<cell_wrap_10, 2U>
                    &layerSlds, ::coder::array<cell_wrap_10, 2U>
                    &domainSldProfiles, ::coder::array<cell_wrap_10, 2U>
                    &allLayers, ::coder::array<real_T, 1U> &allRoughs)
      {
        static real_T thisContrastLayers1_data[6000];
        static real_T thisContrastLayers2_data[6000];
        ::coder::array<cell_wrap_17, 2U> outParameterisedLayers;
        ::coder::array<cell_wrap_39, 1U> tempAllLayers;
        ::coder::array<cell_wrap_39, 1U> tempLayerSlds;
        ::coder::array<cell_wrap_39, 1U> tempSldProfiles;
        ::coder::array<real_T, 2U> a__6;
        ::coder::array<real_T, 2U> b_thisContrastLayers1_data;
        ::coder::array<real_T, 2U> b_thisContrastLayers2_data;
        ::coder::array<real_T, 2U> reflect1;
        ::coder::array<real_T, 2U> reflect2;
        ::coder::array<real_T, 2U> shiftedDat;
        ::coder::array<real_T, 2U> simul1;
        ::coder::array<real_T, 2U> simul2;
        ::coder::array<real_T, 2U> sldProfile1;
        ::coder::array<real_T, 2U> sldProfile2;
        ::coder::array<real_T, 2U> totReflect;
        cell_wrap_10 r;
        cell_wrap_10 r1;
        cell_wrap_10 r2;
        cell_wrap_10 r3;
        cell_wrap_10 r4;
        cell_wrap_10 r5;
        real_T a__5;
        real_T a__7;
        real_T a__8;
        real_T thisBackground;
        real_T thisBulkIn;
        real_T thisBulkOut;
        real_T thisQzshift;
        real_T thisResol;
        real_T thisScalefactor;
        int32_T thisContrastLayers1_size[2];
        int32_T thisContrastLayers2_size[2];
        int32_T b_i;
        int32_T b_loop_ub;
        int32_T i;
        int32_T i1;
        int32_T i2;
        int32_T loop_ub;
        int32_T nParams;
        boolean_T calcSld;
        boolean_T useImaginary;

        //  Single threaded version of the Standard Layers calculation
        //  This is the main reflectivity calculation of the standard layers
        //  calculation type. It extracts the required parameters for the contrasts
        //  from the input arrays, then passes the main calculation to
        //  'standardLayersCore', which carries out the calculation itself.
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
        nParams = problemStruct->params.size(1);
        calcSld = controls->calcSldDuringFit;
        useImaginary = problemStruct->useImaginary;

        //  Default for compile.
        //  Allocate the memory for the output arrays before the main loop
        i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        backgroundParams.set_size(i);

        //  end memory allocation.
        //  First we need to allocate the absolute values of the input
        //  parameters to all the layers in the layers list. This only needs
        //  to be done once, and so is done outside the contrasts loop
        allocateParamsToLayers(problemStruct->params, problemCells->f6,
          outParameterisedLayers);

        //  Resample params if requiired
        //  Loop over all the contrasts
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
        allRoughs.set_size(i);
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

          //  Also need to determine which layers from the overall layers list
          //  are required for this contrast, and put them in the correct order
          //  according to geometry. We run it twice, once for each domain...
          allocateLayersForContrast(problemCells->f19[0].f1,
            outParameterisedLayers, useImaginary, thisContrastLayers1_data,
            thisContrastLayers1_size);
          allocateLayersForContrast(problemCells->f19[1].f1,
            outParameterisedLayers, useImaginary, thisContrastLayers2_data,
            thisContrastLayers2_size);

          //  For the other parameters, we extract the correct ones from the input
          //  arrays
          //  Substrate roughness is always first parameter for standard layers
          //  Now call the core layers reflectivity calculation
          //  In this case we are single cored, so we do not parallelise over
          //  points
          //  Call the core layers calculation - need to do this once for each
          //  domain
          b_thisContrastLayers1_data.set(&thisContrastLayers1_data[0],
            thisContrastLayers1_size[0], thisContrastLayers1_size[1]);
          nonPolarisedTF::coreLayersCalculation(b_thisContrastLayers1_data,
            problemStruct->params[0], problemStruct->geometry.data,
            problemStruct->geometry.size, thisBulkIn, thisBulkOut,
            problemStruct->resample[b_i], calcSld, thisScalefactor, thisQzshift,
            problemStruct->dataPresent[b_i], problemCells->f2[b_i].f1,
            problemCells->f3[b_i].f1, problemCells->f4[b_i].f1, problemCells->
            f1[b_i].f1, thisBackground, thisResol,
            problemStruct->contrastBackgroundsType[b_i], static_cast<real_T>
            (nParams), controls->resamPars, useImaginary, sldProfile1, reflect1,
            simul1, shiftedDat, r.f1, r1.f1, &a__5, &outSsubs[b_i]);
          b_thisContrastLayers2_data.set(&thisContrastLayers2_data[0],
            thisContrastLayers2_size[0], thisContrastLayers2_size[1]);
          nonPolarisedTF::coreLayersCalculation(b_thisContrastLayers2_data,
            problemStruct->params[0], problemStruct->geometry.data,
            problemStruct->geometry.size, thisBulkIn, thisBulkOut,
            problemStruct->resample[b_i], calcSld, thisScalefactor, thisQzshift,
            problemStruct->dataPresent[b_i], problemCells->f2[b_i].f1,
            problemCells->f3[b_i].f1, problemCells->f4[b_i].f1, problemCells->
            f1[b_i].f1, thisBackground, thisResol,
            problemStruct->contrastBackgroundsType[b_i], static_cast<real_T>
            (nParams), controls->resamPars, useImaginary, sldProfile2, reflect2,
            simul2, a__6, r2.f1, r3.f1, &a__7, &a__8);

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
          loop_ub = sldProfile1.size(1);
          r4.f1.set_size(sldProfile1.size(0), sldProfile1.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = sldProfile1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              r4.f1[i2 + r4.f1.size(0) * i1] = sldProfile1[i2 + sldProfile1.size
                (0) * i1];
            }
          }

          loop_ub = sldProfile2.size(1);
          r5.f1.set_size(sldProfile2.size(0), sldProfile2.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = sldProfile2.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              r5.f1[i2 + r5.f1.size(0) * i1] = sldProfile2[i2 + sldProfile2.size
                (0) * i1];
            }
          }

          tempSldProfiles[b_i].f1[0] = r4;
          tempSldProfiles[b_i].f1[1] = r5;
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

          tempLayerSlds[b_i].f1[0] = r;
          tempLayerSlds[b_i].f1[1] = r2;
          tempAllLayers[b_i].f1[0] = r1;
          tempAllLayers[b_i].f1[1] = r3;
          backgroundParams[b_i] = thisBackground;
          qzshifts[b_i] = thisQzshift;
          scalefactors[b_i] = thisScalefactor;
          bulkIns[b_i] = thisBulkIn;
          bulkOuts[b_i] = thisBulkOut;
          resolutionParams[b_i] = thisResol;
          allRoughs[b_i] = problemStruct->params[0];
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

// End of code generation (single3.cpp)
