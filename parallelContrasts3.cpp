//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// parallelContrasts3.cpp
//
// Code generation for function 'parallelContrasts3'
//

// Include files
#include "parallelContrasts3.h"
#include "RATMain_internal_types.h"
#include "RATMain_rtwutil.h"
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
        ::coder::array<cell_wrap_31, 2U> outParameterisedLayers;
        ::coder::array<cell_wrap_53, 1U> tempAllLayers;
        ::coder::array<cell_wrap_53, 1U> tempLayerSlds;
        ::coder::array<cell_wrap_53, 1U> tempSldProfiles;
        ::coder::array<real_T, 2U> a__6;
        ::coder::array<real_T, 2U> reflect1;
        ::coder::array<real_T, 2U> reflect2;
        ::coder::array<real_T, 2U> shiftedDat;
        ::coder::array<real_T, 2U> simul1;
        ::coder::array<real_T, 2U> simul2;
        ::coder::array<real_T, 2U> sldProfile1;
        ::coder::array<real_T, 2U> sldProfile2;
        ::coder::array<real_T, 2U> thisContrastLayers1_data;
        ::coder::array<real_T, 2U> thisContrastLayers2_data;
        ::coder::array<real_T, 2U> totReflect;
        ::coder::array<real_T, 2U> totSimul;
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
        real_T numberOfContrasts;
        real_T thisBackground;
        real_T thisBulkIn;
        real_T thisBulkOut;
        real_T thisChiSquared;
        real_T thisQzshift;
        real_T thisResol;
        real_T thisRough;
        real_T thisScalefactor;
        real_T thisSsubs;
        int32_T thisContrastLayers1_size[2];
        int32_T thisContrastLayers2_size[2];
        int32_T b_i;
        int32_T b_loop_ub;
        int32_T c_i;
        int32_T c_loop_ub;
        int32_T d_loop_ub;
        int32_T i;
        int32_T i1;
        int32_T i2;
        int32_T i3;
        int32_T loop_ub;
        int32_T nParams;
        int32_T ub_loop;
        boolean_T calcSld;
        boolean_T useImaginary;
        RATMainTLSThread = emlrtGetThreadStackData();

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
        numberOfContrasts = problemStruct->numberOfContrasts;
        calcSld = controls->calcSldDuringFit;
        useImaginary = problemStruct->useImaginary;

        //  Default for compile.
        //  Allocate the memory for the output arrays before the main loop
        backgroundParams.set_size(static_cast<int32_T>
          (problemStruct->numberOfContrasts));

        //  end memory allocation.
        //  First we need to allocate the absolute values of the input
        //  parameters to all the layers in the layers list. This only needs
        //  to be done once, and so is done outside the contrasts loop
        allocateParamsToLayers(problemStruct->params, problemCells->f6,
          outParameterisedLayers);

        //  Resample params if requiired
        //  Substrate roughness is always first parameter for standard layers
        thisRough = problemStruct->params[0];

        //  Loop over all the contrasts
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
        allRoughs.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts));
        layerSlds.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts),
                           2);
        allLayers.set_size(static_cast<int32_T>(problemStruct->numberOfContrasts),
                           2);
        domainSldProfiles.set_size(static_cast<int32_T>
          (problemStruct->numberOfContrasts), 2);
        ub_loop = static_cast<int32_T>(problemStruct->numberOfContrasts) - 1;

#pragma omp parallel \
 num_threads(omp_get_max_threads()) \
 private(RATMainTLSThread,r,r1,r2,sldProfile2,r3,sldProfile1,reflect1,simul1,shiftedDat,r4,reflect2,simul2,a__6,r5,totReflect,totSimul,thisChiSquared,a__8,a__7,thisSsubs,a__5,thisContrastLayers2_size,thisContrastLayers1_size,thisResol,thisBulkOut,thisBulkIn,thisScalefactor,thisQzshift,thisBackground,i,c_loop_ub,i2,d_loop_ub,i3) \
 firstprivate(thisContrastLayers1_data,thisContrastLayers2_data)

        {
          RATMainTLSThread = emlrtGetThreadStackData();

#pragma omp for nowait

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
                     &thisBackground, &thisQzshift, &thisScalefactor,
                     &thisBulkIn, &thisBulkOut, &thisResol);

            //  Also need to determine which layers from the overall layers list
            //  are required for this contrast, and put them in the correct order
            //  according to geometry. We run it twice, once for each domain...
            allocateLayersForContrast(problemCells->f19[0].f1,
              outParameterisedLayers, useImaginary,
              RATMainTLSThread->f1.thisContrastLayers1_data,
              thisContrastLayers1_size);
            allocateLayersForContrast(problemCells->f19[1].f1,
              outParameterisedLayers, useImaginary,
              RATMainTLSThread->f1.thisContrastLayers2_data,
              thisContrastLayers2_size);

            //  For the other parameters, we extract the correct ones from the input
            //  arrays
            //  Call the core layers calculation - need to do this once for each
            //  domain
            thisContrastLayers1_data.set
              (&RATMainTLSThread->f1.thisContrastLayers1_data[0],
               thisContrastLayers1_size[0], thisContrastLayers1_size[1]);
            nonPolarisedTF::coreLayersCalculation(thisContrastLayers1_data,
              thisRough, problemStruct->geometry.data,
              problemStruct->geometry.size, thisBulkIn, thisBulkOut,
              problemStruct->resample[i], calcSld, thisScalefactor, thisQzshift,
              problemStruct->dataPresent[i], problemCells->f2[i].f1,
              problemCells->f3[i].f1, problemCells->f4[i].f1, problemCells->f1[i]
              .f1, thisBackground, thisResol,
              problemStruct->contrastBackgroundsType[i], static_cast<real_T>
              (nParams), controls->parallel.data, controls->parallel.size,
              controls->resamPars, useImaginary, sldProfile1, reflect1, simul1,
              shiftedDat, r3.f1, r4.f1, &a__5, &thisSsubs);
            thisContrastLayers2_data.set
              (&RATMainTLSThread->f1.thisContrastLayers2_data[0],
               thisContrastLayers2_size[0], thisContrastLayers2_size[1]);
            nonPolarisedTF::coreLayersCalculation(thisContrastLayers2_data,
              thisRough, problemStruct->geometry.data,
              problemStruct->geometry.size, thisBulkIn, thisBulkOut,
              problemStruct->resample[i], calcSld, thisScalefactor, thisQzshift,
              problemStruct->dataPresent[i], problemCells->f2[i].f1,
              problemCells->f3[i].f1, problemCells->f4[i].f1, problemCells->f1[i]
              .f1, thisBackground, thisResol,
              problemStruct->contrastBackgroundsType[i], static_cast<real_T>
              (nParams), controls->parallel.data, controls->parallel.size,
              controls->resamPars, useImaginary, sldProfile2, reflect2, simul2,
              a__6, r2.f1, r5.f1, &a__7, &a__8);

            //  Calculate the average reflectivities....
            averageReflectivity(reflect1, reflect2, simul1, simul2,
                                problemStruct->domainRatio[static_cast<int32_T>
                                (problemStruct->contrastDomainRatios[i]) - 1],
                                totReflect, totSimul);

            //  Get an overall chi-squared for the new averaged curve..
            thisChiSquared = chiSquared(shiftedDat, totReflect,
              static_cast<real_T>(problemStruct->params.size(1)));

            //  Store returned values for this contrast in the output arrays.
            //  As well as the calculated profiles, we also store a record of
            //  the other values (background, scalefactors etc) for each contrast
            //  for future use.
            outSsubs[i] = thisSsubs;
            c_loop_ub = sldProfile1.size(1);
            r1.f1.set_size(sldProfile1.size(0), sldProfile1.size(1));
            for (i2 = 0; i2 < c_loop_ub; i2++) {
              d_loop_ub = sldProfile1.size(0);
              for (i3 = 0; i3 < d_loop_ub; i3++) {
                r1.f1[i3 + r1.f1.size(0) * i2] = sldProfile1[i3 +
                  sldProfile1.size(0) * i2];
              }
            }

            c_loop_ub = sldProfile2.size(1);
            r.f1.set_size(sldProfile2.size(0), sldProfile2.size(1));
            for (i2 = 0; i2 < c_loop_ub; i2++) {
              d_loop_ub = sldProfile2.size(0);
              for (i3 = 0; i3 < d_loop_ub; i3++) {
                r.f1[i3 + r.f1.size(0) * i2] = sldProfile2[i3 + sldProfile2.size
                  (0) * i2];
              }
            }

            tempSldProfiles[i].f1[0] = r1;
            tempSldProfiles[i].f1[1] = r;
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
                simulation[i].f1[i3 + simulation[i].f1.size(0) * i2] =
                  totSimul[i3 + totSimul.size(0) * i2];
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
            tempLayerSlds[i].f1[1] = r2;
            tempAllLayers[i].f1[0] = r4;
            tempAllLayers[i].f1[1] = r5;
            chis[i] = thisChiSquared;
            backgroundParams[i] = thisBackground;
            qzshifts[i] = thisQzshift;
            scalefactors[i] = thisScalefactor;
            bulkIns[i] = thisBulkIn;
            bulkOuts[i] = thisBulkOut;
            resolutionParams[i] = thisResol;
            allRoughs[i] = thisRough;
          }
        }

        ub_loop = static_cast<int32_T>(numberOfContrasts);
        for (b_i = 0; b_i < ub_loop; b_i++) {
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

// End of code generation (parallelContrasts3.cpp)
