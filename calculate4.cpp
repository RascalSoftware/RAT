//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// calculate4.cpp
//
// Code generation for function 'calculate4'
//

// Include files
#include "calculate4.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "blockedSummation.h"
#include "parallelContrasts4.h"
#include "parallelPoints4.h"
#include "rt_nonfinite.h"
#include "single4.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Definitions
namespace RAT
{
  namespace domainsTF
  {
    namespace customLayers
    {
      void calculate(const f_struct_T *problemStruct, const cell_11
                     *problemCells, const struct2_T *controls, b_struct_T
                     *contrastParams, struct6_T *calculationResults, ::coder::
                     array<cell_wrap_8, 1U> &reflectivity, ::coder::array<
                     cell_wrap_8, 1U> &simulation, ::coder::array<cell_wrap_10,
                     1U> &shiftedData, ::coder::array<cell_wrap_10, 2U>
                     &layerSlds, ::coder::array<cell_wrap_10, 2U>
                     &domainSldProfiles, ::coder::array<cell_wrap_10, 2U>
                     &allLayers)
      {
        ::coder::array<cell_wrap_10, 2U> b_allLayers;
        real_T y;
        int32_T i;
        int32_T loop_ub_tmp;

        //  Custom layers reflectivity calculation for domainsTF
        //  This function decides on parallelisation options before calling the
        //  relevant version of the main custom layers calculation. It is more
        //  efficient to have multiple versions of the core calculation, each dealing
        //  with a different scheme for parallelisation. These are:
        //  single    - single threaded reflectivity calculation
        //  points    - parallelise over points in the reflectivity calculation
        //  contrasts - parallelise over contrasts.
        //  Pre-allocation - It's necessary to
        //  pre-allocate the memory for all the arrays
        //  for compilation, so do this in this block.
        loop_ub_tmp = static_cast<int32_T>(problemStruct->numberOfContrasts);
        contrastParams->ssubs.set_size(loop_ub_tmp);
        contrastParams->backgroundParams.set_size(loop_ub_tmp);
        contrastParams->qzshifts.set_size(loop_ub_tmp);
        contrastParams->scalefactors.set_size(loop_ub_tmp);
        contrastParams->bulkIn.set_size(loop_ub_tmp);
        contrastParams->bulkOut.set_size(loop_ub_tmp);
        for (i = 0; i < loop_ub_tmp; i++) {
          contrastParams->ssubs[i] = 0.0;
          contrastParams->backgroundParams[i] = 0.0;
          contrastParams->qzshifts[i] = 0.0;
          contrastParams->scalefactors[i] = 0.0;
          contrastParams->bulkIn[i] = 0.0;
          contrastParams->bulkOut[i] = 0.0;
        }

        calculationResults->allChis.set_size(loop_ub_tmp);
        for (i = 0; i < loop_ub_tmp; i++) {
          calculationResults->allChis[i] = 0.0;
        }

        contrastParams->resolutionParams.set_size(loop_ub_tmp);
        contrastParams->allSubRough.set_size(loop_ub_tmp);
        reflectivity.set_size(loop_ub_tmp);
        simulation.set_size(loop_ub_tmp);
        shiftedData.set_size(loop_ub_tmp);
        layerSlds.set_size(loop_ub_tmp, 2);
        domainSldProfiles.set_size(loop_ub_tmp, 2);
        allLayers.set_size(loop_ub_tmp, 2);
        for (int32_T b_i{0}; b_i < loop_ub_tmp; b_i++) {
          contrastParams->resolutionParams[b_i] = 0.0;
          contrastParams->allSubRough[b_i] = 0.0;
          reflectivity[b_i].f1.set_size(2, 2);
          reflectivity[b_i].f1[0] = 1.0;
          reflectivity[b_i].f1[1] = 1.0;
          reflectivity[b_i].f1[reflectivity[b_i].f1.size(0)] = 1.0;
          reflectivity[b_i].f1[reflectivity[b_i].f1.size(0) + 1] = 1.0;
          simulation[b_i].f1.set_size(2, 2);
          simulation[b_i].f1[0] = 1.0;
          simulation[b_i].f1[1] = 1.0;
          simulation[b_i].f1[simulation[b_i].f1.size(0)] = 1.0;
          simulation[b_i].f1[simulation[b_i].f1.size(0) + 1] = 1.0;
          shiftedData[b_i].f1.set_size(2, 3);
          layerSlds[b_i].f1.set_size(2, 3);
          layerSlds[b_i + layerSlds.size(0)].f1.set_size(2, 3);
          domainSldProfiles[b_i].f1.set_size(2, 2);
          domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.set_size(2, 2);
          domainSldProfiles[b_i].f1[0] = 1.0;
          domainSldProfiles[b_i + domainSldProfiles.size(0)].f1[0] = 1.0;
          domainSldProfiles[b_i].f1[1] = 1.0;
          domainSldProfiles[b_i + domainSldProfiles.size(0)].f1[1] = 1.0;
          domainSldProfiles[b_i].f1[domainSldProfiles[b_i].f1.size(0)] = 1.0;
          domainSldProfiles[b_i + domainSldProfiles.size(0)]
            .f1[domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.size(0)] =
            1.0;
          domainSldProfiles[b_i].f1[domainSldProfiles[b_i].f1.size(0) + 1] = 1.0;
          domainSldProfiles[b_i + domainSldProfiles.size(0)]
            .f1[domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.size(0) +
            1] = 1.0;
          allLayers[b_i].f1.set_size(2, 3);
          allLayers[b_i + allLayers.size(0)].f1.set_size(2, 3);
          for (i = 0; i < 3; i++) {
            shiftedData[b_i].f1[shiftedData[b_i].f1.size(0) * i] = 1.0;
            shiftedData[b_i].f1[shiftedData[b_i].f1.size(0) * i + 1] = 1.0;
            layerSlds[b_i].f1[layerSlds[b_i].f1.size(0) * i] = 1.0;
            layerSlds[b_i + layerSlds.size(0)].f1[layerSlds[b_i + layerSlds.size
              (0)].f1.size(0) * i] = 1.0;
            layerSlds[b_i].f1[layerSlds[b_i].f1.size(0) * i + 1] = 1.0;
            layerSlds[b_i + layerSlds.size(0)].f1[layerSlds[b_i + layerSlds.size
              (0)].f1.size(0) * i + 1] = 1.0;
            allLayers[b_i].f1[allLayers[b_i].f1.size(0) * i] = 1.0;
            allLayers[b_i + allLayers.size(0)].f1[allLayers[b_i + allLayers.size
              (0)].f1.size(0) * i] = 1.0;
            allLayers[b_i].f1[allLayers[b_i].f1.size(0) * i + 1] = 1.0;
            allLayers[b_i + allLayers.size(0)].f1[allLayers[b_i + allLayers.size
              (0)].f1.size(0) * i + 1] = 1.0;
          }
        }

        //  End pre-allocation
        if (coder::internal::m_strcmp(controls->parallel.data,
             controls->parallel.size)) {
          loop_ub_tmp = 0;
        } else if (coder::internal::n_strcmp(controls->parallel.data,
                    controls->parallel.size)) {
          loop_ub_tmp = 1;
        } else if (coder::internal::o_strcmp(controls->parallel.data,
                    controls->parallel.size)) {
          loop_ub_tmp = 2;
        } else {
          loop_ub_tmp = -1;
        }

        switch (loop_ub_tmp) {
         case 0:
          b_single(problemStruct, problemCells, controls, contrastParams->ssubs,
                   contrastParams->backgroundParams, contrastParams->qzshifts,
                   contrastParams->scalefactors, contrastParams->bulkIn,
                   contrastParams->bulkOut, contrastParams->resolutionParams,
                   calculationResults->allChis, reflectivity, simulation,
                   shiftedData, layerSlds, domainSldProfiles, b_allLayers,
                   contrastParams->allSubRough);
          allLayers.set_size(b_allLayers.size(0), 2);
          loop_ub_tmp = b_allLayers.size(0);
          for (i = 0; i < 2; i++) {
            for (int32_T i1{0}; i1 < loop_ub_tmp; i1++) {
              allLayers[i1 + allLayers.size(0) * i] = b_allLayers[i1 +
                b_allLayers.size(0) * i];
            }
          }
          break;

         case 1:
          parallelPoints(problemStruct, problemCells, controls,
                         contrastParams->ssubs, contrastParams->backgroundParams,
                         contrastParams->qzshifts, contrastParams->scalefactors,
                         contrastParams->bulkIn, contrastParams->bulkOut,
                         contrastParams->resolutionParams,
                         calculationResults->allChis, reflectivity, simulation,
                         shiftedData, layerSlds, domainSldProfiles, b_allLayers,
                         contrastParams->allSubRough);
          allLayers.set_size(b_allLayers.size(0), 2);
          loop_ub_tmp = b_allLayers.size(0);
          for (i = 0; i < 2; i++) {
            for (int32_T i1{0}; i1 < loop_ub_tmp; i1++) {
              allLayers[i1 + allLayers.size(0) * i] = b_allLayers[i1 +
                b_allLayers.size(0) * i];
            }
          }
          break;

         case 2:
          parallelContrasts(problemStruct, problemCells, controls,
                            contrastParams->ssubs,
                            contrastParams->backgroundParams,
                            contrastParams->qzshifts,
                            contrastParams->scalefactors, contrastParams->bulkIn,
                            contrastParams->bulkOut,
                            contrastParams->resolutionParams,
                            calculationResults->allChis, reflectivity,
                            simulation, shiftedData, layerSlds,
                            domainSldProfiles, b_allLayers,
                            contrastParams->allSubRough);
          allLayers.set_size(b_allLayers.size(0), 2);
          loop_ub_tmp = b_allLayers.size(0);
          for (i = 0; i < 2; i++) {
            for (int32_T i1{0}; i1 < loop_ub_tmp; i1++) {
              allLayers[i1 + allLayers.size(0) * i] = b_allLayers[i1 +
                b_allLayers.size(0) * i];
            }
          }
          break;
        }

        contrastParams->resample.set_size(1, problemStruct->resample.size(1));
        loop_ub_tmp = problemStruct->resample.size(1);
        for (i = 0; i < loop_ub_tmp; i++) {
          contrastParams->resample[i] = problemStruct->resample[i];
        }

        if (calculationResults->allChis.size(0) == 0) {
          y = 0.0;
        } else {
          y = coder::nestedIter(calculationResults->allChis,
                                calculationResults->allChis.size(0));
        }

        calculationResults->sumChi = y;
      }
    }
  }
}

// End of code generation (calculate4.cpp)
