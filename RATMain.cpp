//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// RATMain.cpp
//
// Code generation for function 'RATMain'
//

// Include files
#include "RATMain.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "makeEmptyBayesResultsStruct.h"
#include "reflectivityCalculation.h"
#include "rt_nonfinite.h"
#include "runDE.h"
#include "runDREAM.h"
#include "runNestedSampler.h"
#include "runSimplex.h"
#include "sprintf.h"
#include "strcmp.h"
#include "strjoin.h"
#include "triggerEvent.h"
#include "coderException.hpp"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>

// Function Declarations
namespace RAT
{
  static void cast(const ProblemDefinition &r, b_ProblemDefinition *r1);
  static void cast(const ::coder::array<cell_wrap_7, 1U> &t12_reflectivity,
                   const ::coder::array<cell_wrap_7, 1U> &t12_simulation, const ::
                   coder::array<cell_wrap_8, 1U> &t12_shiftedData, const ::coder::
                   array<cell_wrap_8, 1U> &t12_backgrounds, const ::coder::array<
                   cell_wrap_7, 1U> &t12_resolutions, const ::coder::array<
                   cell_wrap_7, 2U> &t12_sldProfiles, const ::coder::array<
                   cell_wrap_9, 2U> &t12_layers, const ::coder::array<
                   cell_wrap_9, 2U> &t12_resampledLayers, const ::coder::array<
                   double, 1U> &t12_calculationResults_chiValues, double
                   t12_calculationResults_sumChi, const ::coder::array<double,
                   1U> &t12_contrastParams_scalefactors, const ::coder::array<
                   double, 1U> &t12_contrastParams_bulkIn, const ::coder::array<
                   double, 1U> &t12_contrastParams_bulkOut, const ::coder::array<
                   double, 1U> &t12_contrastParams_subRoughs, const ::coder::
                   array<double, 2U> &t12_contrastParams_resample, const ::coder::
                   array<double, 2U> &t12_fitParams, const ::coder::array<
                   cell_wrap_10, 1U> &t12_fitNames, Results *r);
  static void cast(const ::coder::array<cell_wrap_10, 2U> &r, ::coder::array<
                   cell_wrap_0, 2U> &r1);
  static void cast(const ::coder::array<cell_wrap_10, 2U> &t13_params, const ::
                   coder::array<cell_wrap_10, 2U> &t13_backgroundParams, const ::
                   coder::array<cell_wrap_10, 2U> &t13_scalefactors, const ::
                   coder::array<cell_wrap_10, 2U> &t13_bulkIns, const ::coder::
                   array<cell_wrap_10, 2U> &t13_bulkOuts, const ::coder::array<
                   cell_wrap_10, 2U> &t13_resolutionParams, const ::coder::array<
                   cell_wrap_10, 2U> &t13_domainRatios, const ::coder::array<
                   cell_wrap_10, 2U> &t13_contrasts, ::coder::array<cell_wrap_0,
                   2U> &t14_params, ::coder::array<cell_wrap_0, 2U>
                   &t14_backgroundParams, ::coder::array<cell_wrap_0, 2U>
                   &t14_scalefactors, ::coder::array<cell_wrap_0, 2U>
                   &t14_bulkIns, ::coder::array<cell_wrap_0, 2U> &t14_bulkOuts, ::
                   coder::array<cell_wrap_0, 2U> &t14_resolutionParams, ::coder::
                   array<cell_wrap_0, 2U> &t14_domainRatios, ::coder::array<
                   cell_wrap_0, 2U> &t14_contrasts);
  static void cast(const ::coder::array<cell_wrap_10, 1U> &r, ::coder::array<
                   cell_wrap_0, 1U> &r1);
  static void cast(const ::coder::array<cell_wrap_9, 2U> &r, ::coder::array<
                   cell_wrap_5, 2U> &r1);
  static void cast(const ::coder::array<cell_wrap_9, 2U> &r, ::coder::array<
                   cell_wrap_6, 2U> &r1);
  static void cast(const ::coder::array<cell_wrap_9, 2U> &r, ::coder::array<
                   cell_wrap_4, 2U> &r1);
  static void cast(const ::coder::array<cell_wrap_44, 2U> &r, ::coder::array<
                   cell_wrap_3, 2U> &r1);
  static void cast(const b_ProblemDefinition *r, ProblemDefinition &r1);
  static void cast(const ::coder::array<cell_wrap_0, 2U> &r, ::coder::array<
                   cell_wrap_10, 2U> &r1);
  static void cast(const ::coder::array<cell_wrap_0, 2U> &t10_params, const ::
                   coder::array<cell_wrap_0, 2U> &t10_backgroundParams, const ::
                   coder::array<cell_wrap_0, 2U> &t10_scalefactors, const ::
                   coder::array<cell_wrap_0, 2U> &t10_bulkIns, const ::coder::
                   array<cell_wrap_0, 2U> &t10_bulkOuts, const ::coder::array<
                   cell_wrap_0, 2U> &t10_resolutionParams, const ::coder::array<
                   cell_wrap_0, 2U> &t10_domainRatios, const ::coder::array<
                   cell_wrap_0, 2U> &t10_contrasts, ::coder::array<cell_wrap_10,
                   2U> &t11_params, ::coder::array<cell_wrap_10, 2U>
                   &t11_backgroundParams, ::coder::array<cell_wrap_10, 2U>
                   &t11_scalefactors, ::coder::array<cell_wrap_10, 2U>
                   &t11_bulkIns, ::coder::array<cell_wrap_10, 2U> &t11_bulkOuts,
                   ::coder::array<cell_wrap_10, 2U> &t11_resolutionParams, ::
                   coder::array<cell_wrap_10, 2U> &t11_domainRatios, ::coder::
                   array<cell_wrap_10, 2U> &t11_contrasts);
  static void cast(const ::coder::array<cell_wrap_0, 1U> &r, ::coder::array<
                   cell_wrap_10, 1U> &r1);
  static void cast(const ::coder::array<cell_wrap_5, 2U> &r, ::coder::array<
                   cell_wrap_9, 2U> &r1);
  static void cast(const ::coder::array<cell_wrap_6, 2U> &r, ::coder::array<
                   cell_wrap_9, 2U> &r1);
  static void cast(const ::coder::array<cell_wrap_4, 2U> &r, ::coder::array<
                   cell_wrap_9, 2U> &r1);
  static void cast(const ::coder::array<cell_wrap_3, 2U> &r, ::coder::array<
                   cell_wrap_44, 2U> &r1);
}

// Function Definitions
namespace RAT
{
  static void cast(const ProblemDefinition &r, b_ProblemDefinition *r1)
  {
    int loop_ub;
    r1->TF.size[0] = 1;
    r1->TF.size[1] = r.TF.size[1];
    loop_ub = r.TF.size[1];
    if (loop_ub - 1 >= 0) {
      std::copy(&r.TF.data[0], &r.TF.data[loop_ub], &r1->TF.data[0]);
    }

    r1->resample.set_size(1, r.resample.size(1));
    loop_ub = r.resample.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1->resample[i] = r.resample[i];
    }

    r1->data.set_size(1, r.data.size(1));
    loop_ub = r.data.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1->data[i] = r.data[i];
    }

    r1->dataPresent.set_size(1, r.dataPresent.size(1));
    loop_ub = r.dataPresent.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1->dataPresent[i] = r.dataPresent[i];
    }

    r1->dataLimits.set_size(1, r.dataLimits.size(1));
    loop_ub = r.dataLimits.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1->dataLimits[i] = r.dataLimits[i];
    }

    r1->simulationLimits.set_size(1, r.simulationLimits.size(1));
    loop_ub = r.simulationLimits.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1->simulationLimits[i] = r.simulationLimits[i];
    }

    r1->numberOfContrasts = r.numberOfContrasts;
    r1->geometry.size[0] = 1;
    r1->geometry.size[1] = r.geometry.size[1];
    loop_ub = r.geometry.size[1];
    if (loop_ub - 1 >= 0) {
      std::copy(&r.geometry.data[0], &r.geometry.data[loop_ub],
                &r1->geometry.data[0]);
    }

    r1->useImaginary = r.useImaginary;
    r1->repeatLayers.set_size(1, r.repeatLayers.size(1));
    loop_ub = r.repeatLayers.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1->repeatLayers[i] = r.repeatLayers[i];
    }

    cast(r.contrastBackgroundParams, r1->contrastBackgroundParams);
    cast(r.contrastBackgroundTypes, r1->contrastBackgroundTypes);
    cast(r.contrastBackgroundActions, r1->contrastBackgroundActions);
    r1->contrastScalefactors.set_size(1, r.contrastScalefactors.size(1));
    loop_ub = r.contrastScalefactors.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1->contrastScalefactors[i] = r.contrastScalefactors[i];
    }

    r1->contrastBulkIns.set_size(1, r.contrastBulkIns.size(1));
    loop_ub = r.contrastBulkIns.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1->contrastBulkIns[i] = r.contrastBulkIns[i];
    }

    r1->contrastBulkOuts.set_size(1, r.contrastBulkOuts.size(1));
    loop_ub = r.contrastBulkOuts.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1->contrastBulkOuts[i] = r.contrastBulkOuts[i];
    }

    cast(r.contrastResolutionParams, r1->contrastResolutionParams);
    cast(r.contrastResolutionTypes, r1->contrastResolutionTypes);
    r1->backgroundParams.set_size(1, r.backgroundParams.size(1));
    loop_ub = r.backgroundParams.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1->backgroundParams[i] = r.backgroundParams[i];
    }

    r1->scalefactors.set_size(1, r.scalefactors.size(1));
    loop_ub = r.scalefactors.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1->scalefactors[i] = r.scalefactors[i];
    }

    r1->bulkIns.set_size(1, r.bulkIns.size(1));
    loop_ub = r.bulkIns.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1->bulkIns[i] = r.bulkIns[i];
    }

    r1->bulkOuts.set_size(1, r.bulkOuts.size(1));
    loop_ub = r.bulkOuts.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1->bulkOuts[i] = r.bulkOuts[i];
    }

    r1->resolutionParams.set_size(1, r.resolutionParams.size(1));
    loop_ub = r.resolutionParams.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1->resolutionParams[i] = r.resolutionParams[i];
    }

    r1->params.set_size(1, r.params.size(1));
    loop_ub = r.params.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1->params[i] = r.params[i];
    }

    r1->numberOfLayers = r.numberOfLayers;
    cast(r.contrastLayers, r1->contrastLayers);
    cast(r.layersDetails, r1->layersDetails);
    cast(r.customFiles, r1->customFiles);
    r1->modelType.size[0] = 1;
    r1->modelType.size[1] = r.modelType.size[1];
    loop_ub = r.modelType.size[1];
    if (loop_ub - 1 >= 0) {
      std::copy(&r.modelType.data[0], &r.modelType.data[loop_ub],
                &r1->modelType.data[0]);
    }

    r1->contrastCustomFiles.set_size(1, r.contrastCustomFiles.size(1));
    loop_ub = r.contrastCustomFiles.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1->contrastCustomFiles[i] = r.contrastCustomFiles[i];
    }

    r1->contrastDomainRatios.set_size(1, r.contrastDomainRatios.size(1));
    loop_ub = r.contrastDomainRatios.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1->contrastDomainRatios[i] = r.contrastDomainRatios[i];
    }

    r1->domainRatios.set_size(1, r.domainRatios.size(1));
    loop_ub = r.domainRatios.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1->domainRatios[i] = r.domainRatios[i];
    }

    r1->numberOfDomainContrasts = r.numberOfDomainContrasts;
    cast(r.domainContrastLayers, r1->domainContrastLayers);
    r1->fitParams.set_size(1, r.fitParams.size(1));
    loop_ub = r.fitParams.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1->fitParams[i] = r.fitParams[i];
    }

    r1->fitLimits.set_size(r.fitLimits.size(0), 2);
    loop_ub = r.fitLimits.size(0);
    for (int i{0}; i < 2; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        r1->fitLimits[i1 + r1->fitLimits.size(0) * i] = r.fitLimits[i1 +
          r.fitLimits.size(0) * i];
      }
    }

    cast(r.priorNames, r1->priorNames);
    r1->priorValues.set_size(r.priorValues.size(0), 3);
    loop_ub = r.priorValues.size(0);
    for (int i{0}; i < 3; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        r1->priorValues[i1 + r1->priorValues.size(0) * i] = r.priorValues[i1 +
          r.priorValues.size(0) * i];
      }
    }

    cast(r.names.params, r.names.backgroundParams, r.names.scalefactors,
         r.names.bulkIns, r.names.bulkOuts, r.names.resolutionParams,
         r.names.domainRatios, r.names.contrasts, r1->names.params,
         r1->names.backgroundParams, r1->names.scalefactors, r1->names.bulkIns,
         r1->names.bulkOuts, r1->names.resolutionParams, r1->names.domainRatios,
         r1->names.contrasts);
    r1->checks = r.checks;
  }

  static void cast(const ::coder::array<cell_wrap_7, 1U> &t12_reflectivity,
                   const ::coder::array<cell_wrap_7, 1U> &t12_simulation, const ::
                   coder::array<cell_wrap_8, 1U> &t12_shiftedData, const ::coder::
                   array<cell_wrap_8, 1U> &t12_backgrounds, const ::coder::array<
                   cell_wrap_7, 1U> &t12_resolutions, const ::coder::array<
                   cell_wrap_7, 2U> &t12_sldProfiles, const ::coder::array<
                   cell_wrap_9, 2U> &t12_layers, const ::coder::array<
                   cell_wrap_9, 2U> &t12_resampledLayers, const ::coder::array<
                   double, 1U> &t12_calculationResults_chiValues, double
                   t12_calculationResults_sumChi, const ::coder::array<double,
                   1U> &t12_contrastParams_scalefactors, const ::coder::array<
                   double, 1U> &t12_contrastParams_bulkIn, const ::coder::array<
                   double, 1U> &t12_contrastParams_bulkOut, const ::coder::array<
                   double, 1U> &t12_contrastParams_subRoughs, const ::coder::
                   array<double, 2U> &t12_contrastParams_resample, const ::coder::
                   array<double, 2U> &t12_fitParams, const ::coder::array<
                   cell_wrap_10, 1U> &t12_fitNames, Results *r)
  {
    int b_loop_ub;
    int i;
    int loop_ub;
    r->reflectivity.set_size(t12_reflectivity.size(0));
    loop_ub = t12_reflectivity.size(0);
    for (i = 0; i < loop_ub; i++) {
      r->reflectivity[i] = t12_reflectivity[i];
    }

    r->simulation.set_size(t12_simulation.size(0));
    loop_ub = t12_simulation.size(0);
    for (i = 0; i < loop_ub; i++) {
      r->simulation[i] = t12_simulation[i];
    }

    r->shiftedData.set_size(t12_shiftedData.size(0));
    loop_ub = t12_shiftedData.size(0);
    for (i = 0; i < loop_ub; i++) {
      r->shiftedData[i] = t12_shiftedData[i];
    }

    r->backgrounds.set_size(t12_backgrounds.size(0));
    loop_ub = t12_backgrounds.size(0);
    for (i = 0; i < loop_ub; i++) {
      r->backgrounds[i] = t12_backgrounds[i];
    }

    r->resolutions.set_size(t12_resolutions.size(0));
    loop_ub = t12_resolutions.size(0);
    for (i = 0; i < loop_ub; i++) {
      r->resolutions[i] = t12_resolutions[i];
    }

    r->sldProfiles.set_size(t12_sldProfiles.size(0), t12_sldProfiles.size(1));
    i = t12_sldProfiles.size(0) * t12_sldProfiles.size(1);
    for (int i1{0}; i1 < i; i1++) {
      loop_ub = t12_sldProfiles[i1].f1.size(0);
      r->sldProfiles[i1].f1.set_size(t12_sldProfiles[i1].f1.size(0), 2);
      for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
        for (int i2{0}; i2 < loop_ub; i2++) {
          r->sldProfiles[i1].f1[i2 + r->sldProfiles[i1].f1.size(0) * b_loop_ub] =
            t12_sldProfiles[i1].f1[i2 + t12_sldProfiles[i1].f1.size(0) *
            b_loop_ub];
        }
      }
    }

    r->layers.set_size(t12_layers.size(0), t12_layers.size(1));
    loop_ub = t12_layers.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t12_layers.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        r->layers[i1 + r->layers.size(0) * i] = t12_layers[i1 + t12_layers.size
          (0) * i];
      }
    }

    r->resampledLayers.set_size(t12_resampledLayers.size(0),
      t12_resampledLayers.size(1));
    loop_ub = t12_resampledLayers.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t12_resampledLayers.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        r->resampledLayers[i1 + r->resampledLayers.size(0) * i] =
          t12_resampledLayers[i1 + t12_resampledLayers.size(0) * i];
      }
    }

    r->calculationResults.chiValues.set_size
      (t12_calculationResults_chiValues.size(0));
    loop_ub = t12_calculationResults_chiValues.size(0);
    for (i = 0; i < loop_ub; i++) {
      r->calculationResults.chiValues[i] = t12_calculationResults_chiValues[i];
    }

    r->calculationResults.sumChi = t12_calculationResults_sumChi;
    r->contrastParams.scalefactors.set_size(t12_contrastParams_scalefactors.size
      (0));
    loop_ub = t12_contrastParams_scalefactors.size(0);
    for (i = 0; i < loop_ub; i++) {
      r->contrastParams.scalefactors[i] = t12_contrastParams_scalefactors[i];
    }

    r->contrastParams.bulkIn.set_size(t12_contrastParams_bulkIn.size(0));
    loop_ub = t12_contrastParams_bulkIn.size(0);
    for (i = 0; i < loop_ub; i++) {
      r->contrastParams.bulkIn[i] = t12_contrastParams_bulkIn[i];
    }

    r->contrastParams.bulkOut.set_size(t12_contrastParams_bulkOut.size(0));
    loop_ub = t12_contrastParams_bulkOut.size(0);
    for (i = 0; i < loop_ub; i++) {
      r->contrastParams.bulkOut[i] = t12_contrastParams_bulkOut[i];
    }

    r->contrastParams.subRoughs.set_size(t12_contrastParams_subRoughs.size(0));
    loop_ub = t12_contrastParams_subRoughs.size(0);
    for (i = 0; i < loop_ub; i++) {
      r->contrastParams.subRoughs[i] = t12_contrastParams_subRoughs[i];
    }

    r->contrastParams.resample.set_size(1, t12_contrastParams_resample.size(1));
    loop_ub = t12_contrastParams_resample.size(1);
    for (i = 0; i < loop_ub; i++) {
      r->contrastParams.resample[i] = t12_contrastParams_resample[i];
    }

    r->fitParams.set_size(1, t12_fitParams.size(1));
    loop_ub = t12_fitParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      r->fitParams[i] = t12_fitParams[i];
    }

    r->fitNames.set_size(t12_fitNames.size(0));
    loop_ub = t12_fitNames.size(0);
    for (i = 0; i < loop_ub; i++) {
      r->fitNames[i] = t12_fitNames[i];
    }
  }

  static void cast(const ::coder::array<cell_wrap_10, 2U> &r, ::coder::array<
                   cell_wrap_0, 2U> &r1)
  {
    int i;
    r1.set_size(1, r.size(1));
    i = r.size(1) - 1;
    for (int i1{0}; i1 <= i; i1++) {
      int loop_ub;
      r1[i1].f1.size[0] = 1;
      loop_ub = r[i1].f1.size(1);
      r1[i1].f1.size[1] = r[i1].f1.size(1);
      for (int i2{0}; i2 < loop_ub; i2++) {
        r1[i1].f1.data[i2] = r[i1].f1[i2];
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_10, 2U> &t13_params, const ::
                   coder::array<cell_wrap_10, 2U> &t13_backgroundParams, const ::
                   coder::array<cell_wrap_10, 2U> &t13_scalefactors, const ::
                   coder::array<cell_wrap_10, 2U> &t13_bulkIns, const ::coder::
                   array<cell_wrap_10, 2U> &t13_bulkOuts, const ::coder::array<
                   cell_wrap_10, 2U> &t13_resolutionParams, const ::coder::array<
                   cell_wrap_10, 2U> &t13_domainRatios, const ::coder::array<
                   cell_wrap_10, 2U> &t13_contrasts, ::coder::array<cell_wrap_0,
                   2U> &t14_params, ::coder::array<cell_wrap_0, 2U>
                   &t14_backgroundParams, ::coder::array<cell_wrap_0, 2U>
                   &t14_scalefactors, ::coder::array<cell_wrap_0, 2U>
                   &t14_bulkIns, ::coder::array<cell_wrap_0, 2U> &t14_bulkOuts, ::
                   coder::array<cell_wrap_0, 2U> &t14_resolutionParams, ::coder::
                   array<cell_wrap_0, 2U> &t14_domainRatios, ::coder::array<
                   cell_wrap_0, 2U> &t14_contrasts)
  {
    cast(t13_params, t14_params);
    cast(t13_backgroundParams, t14_backgroundParams);
    cast(t13_scalefactors, t14_scalefactors);
    cast(t13_bulkIns, t14_bulkIns);
    cast(t13_bulkOuts, t14_bulkOuts);
    cast(t13_resolutionParams, t14_resolutionParams);
    cast(t13_domainRatios, t14_domainRatios);
    cast(t13_contrasts, t14_contrasts);
  }

  static void cast(const ::coder::array<cell_wrap_10, 1U> &r, ::coder::array<
                   cell_wrap_0, 1U> &r1)
  {
    int i;
    r1.set_size(r.size(0));
    i = r.size(0);
    for (int i1{0}; i1 < i; i1++) {
      int loop_ub;
      r1[i1].f1.size[0] = 1;
      loop_ub = r[i1].f1.size(1);
      r1[i1].f1.size[1] = r[i1].f1.size(1);
      for (int i2{0}; i2 < loop_ub; i2++) {
        r1[i1].f1.data[i2] = r[i1].f1[i2];
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_9, 2U> &r, ::coder::array<
                   cell_wrap_5, 2U> &r1)
  {
    int i;
    r1.set_size(1, r.size(1));
    i = r.size(1) - 1;
    for (int i1{0}; i1 <= i; i1++) {
      int loop_ub;
      loop_ub = r[i1].f1.size(1);
      r1[r1.size(0) * i1].f1.set_size(r[r.size(0) * i1].f1.size(0), r[r.size(0) *
        i1].f1.size(1));
      for (int i2{0}; i2 < loop_ub; i2++) {
        int b_loop_ub;
        b_loop_ub = r[i1].f1.size(0);
        for (int i3{0}; i3 < b_loop_ub; i3++) {
          r1[i1].f1[i3 + r1[i1].f1.size(0) * i2] = r[i1].f1[i3 + r[i1].f1.size(0)
            * i2];
        }
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_9, 2U> &r, ::coder::array<
                   cell_wrap_6, 2U> &r1)
  {
    int i;
    r1.set_size(r.size(0), r.size(1));
    i = r.size(0) * r.size(1);
    for (int i1{0}; i1 < i; i1++) {
      int loop_ub;
      r1[i1].f1.size[0] = r[i1].f1.size(0);
      loop_ub = r[i1].f1.size(1);
      r1[i1].f1.size[1] = r[i1].f1.size(1);
      for (int i2{0}; i2 < loop_ub; i2++) {
        int b_loop_ub;
        b_loop_ub = r[i1].f1.size(0);
        for (int i3{0}; i3 < b_loop_ub; i3++) {
          r1[i1].f1.data[i3 + r1[i1].f1.size[0] * i2] = r[i1].f1[i3 + r[i1].
            f1.size(0) * i2];
        }
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_9, 2U> &r, ::coder::array<
                   cell_wrap_4, 2U> &r1)
  {
    int i;
    r1.set_size(1, r.size(1));
    i = r.size(1) - 1;
    for (int i1{0}; i1 <= i; i1++) {
      int loop_ub;
      r1[i1].f1.size[0] = r[i1].f1.size(0);
      loop_ub = r[i1].f1.size(1);
      r1[i1].f1.size[1] = r[i1].f1.size(1);
      for (int i2{0}; i2 < loop_ub; i2++) {
        int b_loop_ub;
        b_loop_ub = r[i1].f1.size(0);
        for (int i3{0}; i3 < b_loop_ub; i3++) {
          r1[i1].f1.data[i3 + r1[i1].f1.size[0] * i2] = r[i1].f1[i3 + r[i1].
            f1.size(0) * i2];
        }
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_44, 2U> &r, ::coder::array<
                   cell_wrap_3, 2U> &r1)
  {
    int i;
    r1.set_size(1, r.size(1));
    i = r.size(1) - 1;
    for (int i1{0}; i1 <= i; i1++) {
      int loop_ub;
      r1[i1].f1.size[0] = 1;
      loop_ub = r[i1].f1.size(1);
      r1[i1].f1.size[1] = r[i1].f1.size(1);
      for (int i2{0}; i2 < loop_ub; i2++) {
        r1[i1].f1.data[i2] = r[i1].f1[i2];
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_0, 2U> &r, ::coder::array<
                   cell_wrap_10, 2U> &r1)
  {
    int i;
    r1.set_size(1, r.size(1));
    i = r.size(1) - 1;
    for (int i1{0}; i1 <= i; i1++) {
      int loop_ub;
      loop_ub = r[i1].f1.size[1];
      r1[r1.size(0) * i1].f1.set_size(1, r[r.size(0) * i1].f1.size[1]);
      for (int i2{0}; i2 < loop_ub; i2++) {
        r1[i1].f1[i2] = r[i1].f1.data[i2];
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_0, 2U> &t10_params, const ::
                   coder::array<cell_wrap_0, 2U> &t10_backgroundParams, const ::
                   coder::array<cell_wrap_0, 2U> &t10_scalefactors, const ::
                   coder::array<cell_wrap_0, 2U> &t10_bulkIns, const ::coder::
                   array<cell_wrap_0, 2U> &t10_bulkOuts, const ::coder::array<
                   cell_wrap_0, 2U> &t10_resolutionParams, const ::coder::array<
                   cell_wrap_0, 2U> &t10_domainRatios, const ::coder::array<
                   cell_wrap_0, 2U> &t10_contrasts, ::coder::array<cell_wrap_10,
                   2U> &t11_params, ::coder::array<cell_wrap_10, 2U>
                   &t11_backgroundParams, ::coder::array<cell_wrap_10, 2U>
                   &t11_scalefactors, ::coder::array<cell_wrap_10, 2U>
                   &t11_bulkIns, ::coder::array<cell_wrap_10, 2U> &t11_bulkOuts,
                   ::coder::array<cell_wrap_10, 2U> &t11_resolutionParams, ::
                   coder::array<cell_wrap_10, 2U> &t11_domainRatios, ::coder::
                   array<cell_wrap_10, 2U> &t11_contrasts)
  {
    cast(t10_params, t11_params);
    cast(t10_backgroundParams, t11_backgroundParams);
    cast(t10_scalefactors, t11_scalefactors);
    cast(t10_bulkIns, t11_bulkIns);
    cast(t10_bulkOuts, t11_bulkOuts);
    cast(t10_resolutionParams, t11_resolutionParams);
    cast(t10_domainRatios, t11_domainRatios);
    cast(t10_contrasts, t11_contrasts);
  }

  static void cast(const ::coder::array<cell_wrap_0, 1U> &r, ::coder::array<
                   cell_wrap_10, 1U> &r1)
  {
    int i;
    r1.set_size(r.size(0));
    i = r.size(0);
    for (int i1{0}; i1 < i; i1++) {
      int loop_ub;
      loop_ub = r[i1].f1.size[1];
      r1[i1].f1.set_size(1, r[i1].f1.size[1]);
      for (int i2{0}; i2 < loop_ub; i2++) {
        r1[i1].f1[i2] = r[i1].f1.data[i2];
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_5, 2U> &r, ::coder::array<
                   cell_wrap_9, 2U> &r1)
  {
    int i;
    r1.set_size(1, r.size(1));
    i = r.size(1) - 1;
    for (int i1{0}; i1 <= i; i1++) {
      int loop_ub;
      loop_ub = r[i1].f1.size(1);
      r1[r1.size(0) * i1].f1.set_size(r[r.size(0) * i1].f1.size(0), r[r.size(0) *
        i1].f1.size(1));
      for (int i2{0}; i2 < loop_ub; i2++) {
        int b_loop_ub;
        b_loop_ub = r[i1].f1.size(0);
        for (int i3{0}; i3 < b_loop_ub; i3++) {
          r1[i1].f1[r1[i1].f1.size(0) * i2] = r[i1].f1[r[i1].f1.size(0) * i2];
        }
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_6, 2U> &r, ::coder::array<
                   cell_wrap_9, 2U> &r1)
  {
    int i;
    r1.set_size(r.size(0), r.size(1));
    i = r.size(0) * r.size(1);
    for (int i1{0}; i1 < i; i1++) {
      int loop_ub;
      loop_ub = r[i1].f1.size[1];
      r1[i1].f1.set_size(r[i1].f1.size[0], r[i1].f1.size[1]);
      for (int i2{0}; i2 < loop_ub; i2++) {
        int b_loop_ub;
        b_loop_ub = r[i1].f1.size[0];
        for (int i3{0}; i3 < b_loop_ub; i3++) {
          r1[i1].f1[r1[i1].f1.size(0) * i2] = r[i1].f1.data[r[i1].f1.size[0] *
            i2];
        }
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_4, 2U> &r, ::coder::array<
                   cell_wrap_9, 2U> &r1)
  {
    int i;
    r1.set_size(1, r.size(1));
    i = r.size(1) - 1;
    for (int i1{0}; i1 <= i; i1++) {
      int loop_ub;
      loop_ub = r[i1].f1.size[1];
      r1[r1.size(0) * i1].f1.set_size(r[r.size(0) * i1].f1.size[0], r[r.size(0) *
        i1].f1.size[1]);
      for (int i2{0}; i2 < loop_ub; i2++) {
        int b_loop_ub;
        b_loop_ub = r[i1].f1.size[0];
        for (int i3{0}; i3 < b_loop_ub; i3++) {
          r1[i1].f1[r1[i1].f1.size(0) * i2] = r[i1].f1.data[r[i1].f1.size[0] *
            i2];
        }
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_3, 2U> &r, ::coder::array<
                   cell_wrap_44, 2U> &r1)
  {
    int i;
    r1.set_size(1, r.size(1));
    i = r.size(1) - 1;
    for (int i1{0}; i1 <= i; i1++) {
      int loop_ub;
      loop_ub = r[i1].f1.size[1];
      r1[r1.size(0) * i1].f1.set_size(1, r[r.size(0) * i1].f1.size[1]);
      for (int i2{0}; i2 < loop_ub; i2++) {
        r1[i1].f1[i2] = r[i1].f1.data[i2];
      }
    }
  }

  static void cast(const b_ProblemDefinition *r, ProblemDefinition &r1)
  {
    int loop_ub;
    r1.TF.size[0] = 1;
    r1.TF.size[1] = r->TF.size[1];
    loop_ub = r->TF.size[1];
    if (loop_ub - 1 >= 0) {
      std::copy(&r->TF.data[0], &r->TF.data[loop_ub], &r1.TF.data[0]);
    }

    r1.resample.set_size(1, r->resample.size(1));
    loop_ub = r->resample.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1.resample[i] = r->resample[i];
    }

    r1.data.set_size(1, r->data.size(1));
    loop_ub = r->data.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1.data[i] = r->data[i];
    }

    r1.dataPresent.set_size(1, r->dataPresent.size(1));
    loop_ub = r->dataPresent.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1.dataPresent[i] = r->dataPresent[i];
    }

    r1.dataLimits.set_size(1, r->dataLimits.size(1));
    loop_ub = r->dataLimits.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1.dataLimits[i] = r->dataLimits[i];
    }

    r1.simulationLimits.set_size(1, r->simulationLimits.size(1));
    loop_ub = r->simulationLimits.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1.simulationLimits[i] = r->simulationLimits[i];
    }

    r1.numberOfContrasts = r->numberOfContrasts;
    r1.geometry.size[0] = 1;
    r1.geometry.size[1] = r->geometry.size[1];
    loop_ub = r->geometry.size[1];
    if (loop_ub - 1 >= 0) {
      std::copy(&r->geometry.data[0], &r->geometry.data[loop_ub],
                &r1.geometry.data[0]);
    }

    r1.useImaginary = r->useImaginary;
    r1.repeatLayers.set_size(1, r->repeatLayers.size(1));
    loop_ub = r->repeatLayers.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1.repeatLayers[i] = r->repeatLayers[i];
    }

    cast(r->contrastBackgroundParams, r1.contrastBackgroundParams);
    cast(r->contrastBackgroundTypes, r1.contrastBackgroundTypes);
    cast(r->contrastBackgroundActions, r1.contrastBackgroundActions);
    r1.contrastScalefactors.set_size(1, r->contrastScalefactors.size(1));
    loop_ub = r->contrastScalefactors.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1.contrastScalefactors[i] = r->contrastScalefactors[i];
    }

    r1.contrastBulkIns.set_size(1, r->contrastBulkIns.size(1));
    loop_ub = r->contrastBulkIns.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1.contrastBulkIns[i] = r->contrastBulkIns[i];
    }

    r1.contrastBulkOuts.set_size(1, r->contrastBulkOuts.size(1));
    loop_ub = r->contrastBulkOuts.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1.contrastBulkOuts[i] = r->contrastBulkOuts[i];
    }

    cast(r->contrastResolutionParams, r1.contrastResolutionParams);
    cast(r->contrastResolutionTypes, r1.contrastResolutionTypes);
    r1.backgroundParams.set_size(1, r->backgroundParams.size(1));
    loop_ub = r->backgroundParams.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1.backgroundParams[i] = r->backgroundParams[i];
    }

    r1.scalefactors.set_size(1, r->scalefactors.size(1));
    loop_ub = r->scalefactors.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1.scalefactors[i] = r->scalefactors[i];
    }

    r1.bulkIns.set_size(1, r->bulkIns.size(1));
    loop_ub = r->bulkIns.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1.bulkIns[i] = r->bulkIns[i];
    }

    r1.bulkOuts.set_size(1, r->bulkOuts.size(1));
    loop_ub = r->bulkOuts.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1.bulkOuts[i] = r->bulkOuts[i];
    }

    r1.resolutionParams.set_size(1, r->resolutionParams.size(1));
    loop_ub = r->resolutionParams.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1.resolutionParams[i] = r->resolutionParams[i];
    }

    r1.params.set_size(1, r->params.size(1));
    loop_ub = r->params.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1.params[i] = r->params[i];
    }

    r1.numberOfLayers = r->numberOfLayers;
    cast(r->contrastLayers, r1.contrastLayers);
    cast(r->layersDetails, r1.layersDetails);
    cast(r->customFiles, r1.customFiles);
    r1.modelType.size[0] = 1;
    r1.modelType.size[1] = r->modelType.size[1];
    loop_ub = r->modelType.size[1];
    if (loop_ub - 1 >= 0) {
      std::copy(&r->modelType.data[0], &r->modelType.data[loop_ub],
                &r1.modelType.data[0]);
    }

    r1.contrastCustomFiles.set_size(1, r->contrastCustomFiles.size(1));
    loop_ub = r->contrastCustomFiles.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1.contrastCustomFiles[i] = r->contrastCustomFiles[i];
    }

    r1.contrastDomainRatios.set_size(1, r->contrastDomainRatios.size(1));
    loop_ub = r->contrastDomainRatios.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1.contrastDomainRatios[i] = r->contrastDomainRatios[i];
    }

    r1.domainRatios.set_size(1, r->domainRatios.size(1));
    loop_ub = r->domainRatios.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1.domainRatios[i] = r->domainRatios[i];
    }

    r1.numberOfDomainContrasts = r->numberOfDomainContrasts;
    cast(r->domainContrastLayers, r1.domainContrastLayers);
    r1.fitParams.set_size(1, r->fitParams.size(1));
    loop_ub = r->fitParams.size(1);
    for (int i{0}; i < loop_ub; i++) {
      r1.fitParams[i] = r->fitParams[i];
    }

    r1.fitLimits.set_size(r->fitLimits.size(0), 2);
    loop_ub = r->fitLimits.size(0);
    for (int i{0}; i < 2; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        r1.fitLimits[i1 + r1.fitLimits.size(0) * i] = r->fitLimits[i1 +
          r->fitLimits.size(0) * i];
      }
    }

    cast(r->priorNames, r1.priorNames);
    r1.priorValues.set_size(r->priorValues.size(0), 3);
    loop_ub = r->priorValues.size(0);
    for (int i{0}; i < 3; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        r1.priorValues[i1 + r1.priorValues.size(0) * i] = r->priorValues[i1 +
          r->priorValues.size(0) * i];
      }
    }

    cast(r->names.params, r->names.backgroundParams, r->names.scalefactors,
         r->names.bulkIns, r->names.bulkOuts, r->names.resolutionParams,
         r->names.domainRatios, r->names.contrasts, r1.names.params,
         r1.names.backgroundParams, r1.names.scalefactors, r1.names.bulkIns,
         r1.names.bulkOuts, r1.names.resolutionParams, r1.names.domainRatios,
         r1.names.contrasts);
    r1.checks = r->checks;
  }

  void RATMain(b_ProblemDefinition *problemStruct, Controls *controls, Results
               *results, BayesResults *bayesResults)
  {
    static Controls b_controls;
    static ProblemDefinition r;
    static c_struct_T b_bayesResults;
    static const char b_cv1[71]{ 'R', 'A', 'T', ' ', 'c', 'a', 'n', 'n', 'o',
      't', ' ', 'p', 'r', 'o', 'c', 'e', 'e', 'd', ' ', 'w', 'i', 't', 'h', 'o',
      'u', 't', ' ', 'a', 't', ' ', 'l', 'e', 'a', 's', 't', ' ', 'o', 'n', 'e',
      ' ', 'c', 'o', 'n', 't', 'r', 'a', 's', 't', ' ', 'd', 'e', 'f', 'i', 'n',
      'e', 'd', ' ', 'i', 'n', ' ', 't', 'h', 'e', ' ', 'p', 'r', 'o', 'j', 'e',
      'c', 't' };

    ::coder::array<char, 2U> c_controls;
    ::coder::array<char, 2U> charStr;
    ::coder::array<char, 2U> varargin_2;
    ProblemDefinition b_problemStruct;
    b_struct_T expl_temp;
    char b_cv[71];
    char varargin_2_data[41];

    //  Select and run the internal RAT procedure.
    //
    //  Parameters
    //  ----------
    //  problemStruct : struct
    //      The project class in struct form (generated from parseClassToStructs)
    //  controls : struct
    //      The controls struct (generated from parseClassToStructs)
    //
    //  Returns
    //  -------
    //  problemStruct : struct
    //      The output problem struct.
    //  results : struct
    //      The calculation results.
    //  bayesResults : struct
    //      Additional results from a Bayesian calculation.
    //  Adds C struct names for inputs
    bayesResults->predictionIntervals.sampleChi.size[0] =
      makeEmptyBayesResultsStruct(problemStruct->numberOfContrasts, coder::
      internal::b_strcmp(problemStruct->TF.data, problemStruct->TF.size),
      controls->nChains, bayesResults->predictionIntervals.reflectivity,
      bayesResults->predictionIntervals.sld,
      bayesResults->predictionIntervals.sampleChi.data,
      bayesResults->confidenceIntervals.percentile95,
      bayesResults->confidenceIntervals.percentile65,
      bayesResults->confidenceIntervals.mean, bayesResults->dreamParams,
      bayesResults->dreamOutput, b_bayesResults.nestedSamplerOutput,
      bayesResults->chain);
    bayesResults->nestedSamplerOutput.LogZ =
      b_bayesResults.nestedSamplerOutput.LogZ;
    bayesResults->nestedSamplerOutput.LogZErr =
      b_bayesResults.nestedSamplerOutput.LogZErr;
    bayesResults->nestedSamplerOutput.nestSamples.set_size(1, 2);
    bayesResults->nestedSamplerOutput.postSamples.set_size(1, 2);
    bayesResults->nestedSamplerOutput.nestSamples[0] =
      b_bayesResults.nestedSamplerOutput.nestSamples.data[0];
    bayesResults->nestedSamplerOutput.postSamples[0] =
      b_bayesResults.nestedSamplerOutput.postSamples.data[0];
    bayesResults->nestedSamplerOutput.nestSamples
      [bayesResults->nestedSamplerOutput.nestSamples.size(0)] =
      b_bayesResults.nestedSamplerOutput.nestSamples.data[1];
    bayesResults->nestedSamplerOutput.postSamples
      [bayesResults->nestedSamplerOutput.postSamples.size(0)] =
      b_bayesResults.nestedSamplerOutput.postSamples.data[1];
    if (problemStruct->numberOfContrasts > 0.0) {
      int b_index;
      if (coder::internal::c_strcmp(controls->procedure.data,
           controls->procedure.size)) {
        b_index = 0;
      } else if (coder::internal::e_strcmp(controls->procedure.data,
                  controls->procedure.size)) {
        b_index = 1;
      } else if (coder::internal::f_strcmp(controls->procedure.data,
                  controls->procedure.size)) {
        b_index = 2;
      } else if (coder::internal::g_strcmp(controls->procedure.data,
                  controls->procedure.size)) {
        b_index = 3;
      } else if (coder::internal::h_strcmp(controls->procedure.data,
                  controls->procedure.size)) {
        b_index = 4;
      } else {
        b_index = -1;
      }

      switch (b_index) {
       case 0:
        //  Just a single reflectivity calculation
        controls->calcSLD = true;
        cast(problemStruct, r);
        reflectivityCalculation(r, controls, expl_temp);
        cast(expl_temp.reflectivity, expl_temp.simulation, expl_temp.shiftedData,
             expl_temp.backgrounds, expl_temp.resolutions, expl_temp.sldProfiles,
             expl_temp.layers, expl_temp.resampledLayers,
             expl_temp.calculationResults.chiValues,
             expl_temp.calculationResults.sumChi,
             expl_temp.contrastParams.scalefactors,
             expl_temp.contrastParams.bulkIn, expl_temp.contrastParams.bulkOut,
             expl_temp.contrastParams.subRoughs,
             expl_temp.contrastParams.resample, expl_temp.fitParams,
             expl_temp.fitNames, results);
        break;

       case 1:
        if (!coder::internal::d_strcmp(controls->display.data,
             controls->display.size)) {
          triggerEvent();
        }

        cast(problemStruct, b_problemStruct);
        b_controls = *controls;
        runSimplex(b_problemStruct, b_controls, expl_temp);
        cast(b_problemStruct, problemStruct);
        cast(expl_temp.reflectivity, expl_temp.simulation, expl_temp.shiftedData,
             expl_temp.backgrounds, expl_temp.resolutions, expl_temp.sldProfiles,
             expl_temp.layers, expl_temp.resampledLayers,
             expl_temp.calculationResults.chiValues,
             expl_temp.calculationResults.sumChi,
             expl_temp.contrastParams.scalefactors,
             expl_temp.contrastParams.bulkIn, expl_temp.contrastParams.bulkOut,
             expl_temp.contrastParams.subRoughs,
             expl_temp.contrastParams.resample, expl_temp.fitParams,
             expl_temp.fitNames, results);
        break;

       case 2:
        if (!coder::internal::d_strcmp(controls->display.data,
             controls->display.size)) {
          d_triggerEvent();
        }

        cast(problemStruct, b_problemStruct);
        b_controls = *controls;
        runDE(b_problemStruct, b_controls, expl_temp);
        cast(b_problemStruct, problemStruct);
        cast(expl_temp.reflectivity, expl_temp.simulation, expl_temp.shiftedData,
             expl_temp.backgrounds, expl_temp.resolutions, expl_temp.sldProfiles,
             expl_temp.layers, expl_temp.resampledLayers,
             expl_temp.calculationResults.chiValues,
             expl_temp.calculationResults.sumChi,
             expl_temp.contrastParams.scalefactors,
             expl_temp.contrastParams.bulkIn, expl_temp.contrastParams.bulkOut,
             expl_temp.contrastParams.subRoughs,
             expl_temp.contrastParams.resample, expl_temp.fitParams,
             expl_temp.fitNames, results);
        break;

       case 3:
        if (!coder::internal::d_strcmp(controls->display.data,
             controls->display.size)) {
          i_triggerEvent();
        }

        cast(problemStruct, b_problemStruct);
        bayesResults->predictionIntervals.sampleChi.size[0] = runNestedSampler
          (b_problemStruct, controls->parallel.data, controls->parallel.size,
           controls->numSimulationPoints, controls->resampleMinAngle,
           controls->resampleNPoints, controls->display.data,
           controls->display.size, controls->nLive, controls->nMCMC,
           controls->nsTolerance, controls->calcSLD, controls->IPCFilePath.data,
           controls->IPCFilePath.size, expl_temp,
           bayesResults->predictionIntervals.reflectivity,
           bayesResults->predictionIntervals.sld,
           bayesResults->predictionIntervals.sampleChi.data,
           bayesResults->confidenceIntervals, bayesResults->nestedSamplerOutput,
           bayesResults->chain, bayesResults->dreamParams,
           bayesResults->dreamOutput);
        cast(b_problemStruct, problemStruct);
        cast(expl_temp.reflectivity, expl_temp.simulation, expl_temp.shiftedData,
             expl_temp.backgrounds, expl_temp.resolutions, expl_temp.sldProfiles,
             expl_temp.layers, expl_temp.resampledLayers,
             expl_temp.calculationResults.chiValues,
             expl_temp.calculationResults.sumChi,
             expl_temp.contrastParams.scalefactors,
             expl_temp.contrastParams.bulkIn, expl_temp.contrastParams.bulkOut,
             expl_temp.contrastParams.subRoughs,
             expl_temp.contrastParams.resample, expl_temp.fitParams,
             expl_temp.fitNames, results);
        break;

       case 4:
        {
          if (!coder::internal::d_strcmp(controls->display.data,
               controls->display.size)) {
            j_triggerEvent();
          }

          cast(problemStruct, r);
          runDREAM(r, controls, expl_temp, b_bayesResults, b_problemStruct);
          bayesResults->predictionIntervals = b_bayesResults.predictionIntervals;
          bayesResults->confidenceIntervals = b_bayesResults.confidenceIntervals;
          bayesResults->dreamParams = b_bayesResults.dreamParams;
          bayesResults->dreamOutput = b_bayesResults.dreamOutput;
          bayesResults->chain.set_size(b_bayesResults.chain.size(0),
            b_bayesResults.chain.size(1));
          b_index = b_bayesResults.chain.size(1);
          for (int i{0}; i < b_index; i++) {
            int loop_ub;
            loop_ub = b_bayesResults.chain.size(0);
            for (int i1{0}; i1 < loop_ub; i1++) {
              bayesResults->chain[i1 + bayesResults->chain.size(0) * i] =
                b_bayesResults.chain[i1 + b_bayesResults.chain.size(0) * i];
            }
          }

          cast(b_problemStruct, problemStruct);
          cast(expl_temp.reflectivity, expl_temp.simulation,
               expl_temp.shiftedData, expl_temp.backgrounds,
               expl_temp.resolutions, expl_temp.sldProfiles, expl_temp.layers,
               expl_temp.resampledLayers, expl_temp.calculationResults.chiValues,
               expl_temp.calculationResults.sumChi,
               expl_temp.contrastParams.scalefactors,
               expl_temp.contrastParams.bulkIn, expl_temp.contrastParams.bulkOut,
               expl_temp.contrastParams.subRoughs,
               expl_temp.contrastParams.resample, expl_temp.fitParams,
               expl_temp.fitNames, results);
          bayesResults->nestedSamplerOutput.LogZ =
            b_bayesResults.nestedSamplerOutput.LogZ;
          bayesResults->nestedSamplerOutput.LogZErr =
            b_bayesResults.nestedSamplerOutput.LogZErr;
          bayesResults->nestedSamplerOutput.nestSamples.set_size(1, 2);
          bayesResults->nestedSamplerOutput.postSamples.set_size(1, 2);
          bayesResults->nestedSamplerOutput.nestSamples[0] =
            b_bayesResults.nestedSamplerOutput.nestSamples.data[0];
          bayesResults->nestedSamplerOutput.postSamples[0] =
            b_bayesResults.nestedSamplerOutput.postSamples.data[0];
          bayesResults->nestedSamplerOutput.nestSamples
            [bayesResults->nestedSamplerOutput.nestSamples.size(0)] =
            b_bayesResults.nestedSamplerOutput.nestSamples.data[1];
          bayesResults->nestedSamplerOutput.postSamples
            [bayesResults->nestedSamplerOutput.postSamples.size(0)] =
            b_bayesResults.nestedSamplerOutput.postSamples.data[1];
        }
        break;

       default:
        {
          int varargin_2_size[2];
          coder::strjoin(varargin_2_data, varargin_2_size);

          //  Ensures a proper exception is thrown in the generated C++ code.
          //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
          //  and other parameters if message is a formatspec.
          //
          //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
          //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
          c_controls.set_size(1, controls->procedure.size[1] + 1);
          b_index = controls->procedure.size[1];
          for (int i{0}; i < b_index; i++) {
            c_controls[i] = controls->procedure.data[i];
          }

          c_controls[controls->procedure.size[1]] = '\x00';
          varargin_2.set_size(1, varargin_2_size[1] + 1);
          b_index = varargin_2_size[1];
          for (int i{0}; i < b_index; i++) {
            varargin_2[i] = varargin_2_data[i];
          }

          varargin_2[varargin_2_size[1]] = '\x00';
          coder::snPrint(c_controls, varargin_2, charStr);
          coderException(1.0, &charStr[0]);
        }
        break;
      }
    } else {
      //  Ensures a proper exception is thrown in the generated C++ code.
      //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
      //  and other parameters if message is a formatspec.
      //
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
      std::copy(&b_cv1[0], &b_cv1[71], &b_cv[0]);
      coderException(2.0, &b_cv[0]);
    }

    //  Adds C struct names for outputs
  }
}

// End of code generation (RATMain.cpp)
