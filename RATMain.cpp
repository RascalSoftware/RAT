//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// RATMain.cpp
//
// Code generation for function 'RATMain'
//

// Include files
#include "RATMain.h"
#include "RATMain_data.h"
#include "RATMain_internal_types.h"
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "makeEmptyBayesResultsStruct.h"
#include "reflectivityCalculation.h"
#include "rt_nonfinite.h"
#include "runDE.h"
#include "runDREAM.h"
#include "runNestedSampler.h"
#include "runSimplex.h"
#include "strcmp.h"
#include "triggerEvent.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>

// Function Declarations
namespace RAT
{
  static void cast(const struct0_T *b, e_struct_T *c);
  static void cast(const ::coder::array<cell_wrap_0, 2U> &t8_params, const ::
                   coder::array<cell_wrap_0, 2U> &t8_backgroundParams, const ::
                   coder::array<cell_wrap_0, 2U> &t8_scalefactors, const ::coder::
                   array<cell_wrap_0, 2U> &t8_qzshifts, const ::coder::array<
                   cell_wrap_0, 2U> &t8_bulkIns, const ::coder::array<
                   cell_wrap_0, 2U> &t8_bulkOuts, const ::coder::array<
                   cell_wrap_0, 2U> &t8_resolutionParams, const ::coder::array<
                   cell_wrap_0, 2U> &t8_domainRatios, const ::coder::array<
                   cell_wrap_0, 2U> &t8_contrasts, d_struct_T *b);
  static void cast(const e_struct_T *b, struct0_T *c);
  static void cast(const ::coder::array<cell_wrap_48, 2U> &b, ::coder::array<
                   cell_wrap_3, 2U> &c);
  static void cast(const ::coder::array<cell_wrap_10, 2U> &b, ::coder::array<
                   cell_wrap_5, 2U> &c);
  static void cast(const ::coder::array<cell_wrap_10, 2U> &b, ::coder::array<
                   cell_wrap_4, 2U> &c);
  static void cast(const ::coder::array<cell_wrap_7, 2U> &t9_params, const ::
                   coder::array<cell_wrap_7, 2U> &t9_backgroundParams, const ::
                   coder::array<cell_wrap_7, 2U> &t9_scalefactors, const ::coder::
                   array<cell_wrap_7, 2U> &t9_qzshifts, const ::coder::array<
                   cell_wrap_7, 2U> &t9_bulkIns, const ::coder::array<
                   cell_wrap_7, 2U> &t9_bulkOuts, const ::coder::array<
                   cell_wrap_7, 2U> &t9_resolutionParams, const ::coder::array<
                   cell_wrap_7, 2U> &t9_domainRatios, const ::coder::array<
                   cell_wrap_7, 2U> &t9_contrasts, struct1_T *b);
  static void cast(const ::coder::array<cell_wrap_7, 2U> &b, ::coder::array<
                   cell_wrap_0, 2U> &c);
}

// Function Definitions
namespace RAT
{
  static void cast(const struct0_T *b, e_struct_T *c)
  {
    int32_T b_loop_ub;
    int32_T i;
    int32_T loop_ub;
    c->TF.size[0] = 1;
    c->TF.size[1] = b->TF.size[1];
    loop_ub = b->TF.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&b->TF.data[0], &b->TF.data[loop_ub], &c->TF.data[0]);
    }

    c->resample.set_size(1, b->resample.size(1));
    loop_ub = b->resample.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->resample[i] = b->resample[i];
    }

    c->data.set_size(1, b->data.size(1));
    loop_ub = b->data.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->data[i] = b->data[i];
    }

    c->dataPresent.set_size(1, b->dataPresent.size(1));
    loop_ub = b->dataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->dataPresent[i] = b->dataPresent[i];
    }

    c->dataLimits.set_size(1, b->dataLimits.size(1));
    loop_ub = b->dataLimits.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->dataLimits[i] = b->dataLimits[i];
    }

    c->simulationLimits.set_size(1, b->simulationLimits.size(1));
    loop_ub = b->simulationLimits.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->simulationLimits[i] = b->simulationLimits[i];
    }

    c->oilChiDataPresent.set_size(1, b->oilChiDataPresent.size(1));
    loop_ub = b->oilChiDataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->oilChiDataPresent[i] = b->oilChiDataPresent[i];
    }

    c->numberOfContrasts = b->numberOfContrasts;
    c->geometry.size[0] = 1;
    c->geometry.size[1] = b->geometry.size[1];
    loop_ub = b->geometry.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&b->geometry.data[0], &b->geometry.data[loop_ub],
                &c->geometry.data[0]);
    }

    c->useImaginary = b->useImaginary;
    c->repeatLayers.set_size(1, b->repeatLayers.size(1));
    loop_ub = b->repeatLayers.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->repeatLayers[i] = b->repeatLayers[i];
    }

    cast(b->contrastBackgroundParams, c->contrastBackgroundParams);
    cast(b->contrastBackgroundTypes, c->contrastBackgroundTypes);
    cast(b->contrastBackgroundActions, c->contrastBackgroundActions);
    c->contrastQzshifts.set_size(1, b->contrastQzshifts.size(1));
    loop_ub = b->contrastQzshifts.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastQzshifts[i] = b->contrastQzshifts[i];
    }

    c->contrastScalefactors.set_size(1, b->contrastScalefactors.size(1));
    loop_ub = b->contrastScalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastScalefactors[i] = b->contrastScalefactors[i];
    }

    c->contrastBulkIns.set_size(1, b->contrastBulkIns.size(1));
    loop_ub = b->contrastBulkIns.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastBulkIns[i] = b->contrastBulkIns[i];
    }

    c->contrastBulkOuts.set_size(1, b->contrastBulkOuts.size(1));
    loop_ub = b->contrastBulkOuts.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastBulkOuts[i] = b->contrastBulkOuts[i];
    }

    c->contrastResolutionParams.set_size(1, b->contrastResolutionParams.size(1));
    loop_ub = b->contrastResolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastResolutionParams[i] = b->contrastResolutionParams[i];
    }

    c->backgroundParams.set_size(1, b->backgroundParams.size(1));
    loop_ub = b->backgroundParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->backgroundParams[i] = b->backgroundParams[i];
    }

    c->qzshifts.set_size(1, b->qzshifts.size(1));
    loop_ub = b->qzshifts.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->qzshifts[i] = b->qzshifts[i];
    }

    c->scalefactors.set_size(1, b->scalefactors.size(1));
    loop_ub = b->scalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->scalefactors[i] = b->scalefactors[i];
    }

    c->bulkIns.set_size(1, b->bulkIns.size(1));
    loop_ub = b->bulkIns.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->bulkIns[i] = b->bulkIns[i];
    }

    c->bulkOuts.set_size(1, b->bulkOuts.size(1));
    loop_ub = b->bulkOuts.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->bulkOuts[i] = b->bulkOuts[i];
    }

    c->resolutionParams.set_size(1, b->resolutionParams.size(1));
    loop_ub = b->resolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->resolutionParams[i] = b->resolutionParams[i];
    }

    c->params.set_size(1, b->params.size(1));
    loop_ub = b->params.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->params[i] = b->params[i];
    }

    c->numberOfLayers = b->numberOfLayers;
    cast(b->contrastLayers, c->contrastLayers);
    cast(b->layersDetails, c->layersDetails);
    cast(b->customFiles, c->customFiles);
    c->modelType.size[0] = 1;
    c->modelType.size[1] = b->modelType.size[1];
    loop_ub = b->modelType.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&b->modelType.data[0], &b->modelType.data[loop_ub],
                &c->modelType.data[0]);
    }

    c->contrastCustomFiles.set_size(1, b->contrastCustomFiles.size(1));
    loop_ub = b->contrastCustomFiles.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastCustomFiles[i] = b->contrastCustomFiles[i];
    }

    c->contrastDomainRatios.set_size(1, b->contrastDomainRatios.size(1));
    loop_ub = b->contrastDomainRatios.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastDomainRatios[i] = b->contrastDomainRatios[i];
    }

    c->domainRatios.set_size(1, b->domainRatios.size(1));
    loop_ub = b->domainRatios.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->domainRatios[i] = b->domainRatios[i];
    }

    c->numberOfDomainContrasts = b->numberOfDomainContrasts;
    cast(b->domainContrastLayers, c->domainContrastLayers);
    c->fitParams.set_size(1, b->fitParams.size(1));
    loop_ub = b->fitParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->fitParams[i] = b->fitParams[i];
    }

    c->otherParams.set_size(1, b->otherParams.size(1));
    loop_ub = b->otherParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->otherParams[i] = b->otherParams[i];
    }

    c->fitLimits.set_size(b->fitLimits.size(0), 2);
    c->otherLimits.set_size(b->otherLimits.size(0), 2);
    loop_ub = b->fitLimits.size(0);
    b_loop_ub = b->otherLimits.size(0);
    for (i = 0; i < 2; i++) {
      int32_T i1;
      for (i1 = 0; i1 < loop_ub; i1++) {
        c->fitLimits[i1 + c->fitLimits.size(0) * i] = b->fitLimits[i1 +
          b->fitLimits.size(0) * i];
      }

      for (i1 = 0; i1 < b_loop_ub; i1++) {
        c->otherLimits[i1 + c->otherLimits.size(0) * i] = b->otherLimits[i1 +
          b->otherLimits.size(0) * i];
      }
    }

    cast(b->names.params, b->names.backgroundParams, b->names.scalefactors,
         b->names.qzshifts, b->names.bulkIns, b->names.bulkOuts,
         b->names.resolutionParams, b->names.domainRatios, b->names.contrasts,
         &c->names);
    c->checks = b->checks;
  }

  static void cast(const ::coder::array<cell_wrap_0, 2U> &t8_params, const ::
                   coder::array<cell_wrap_0, 2U> &t8_backgroundParams, const ::
                   coder::array<cell_wrap_0, 2U> &t8_scalefactors, const ::coder::
                   array<cell_wrap_0, 2U> &t8_qzshifts, const ::coder::array<
                   cell_wrap_0, 2U> &t8_bulkIns, const ::coder::array<
                   cell_wrap_0, 2U> &t8_bulkOuts, const ::coder::array<
                   cell_wrap_0, 2U> &t8_resolutionParams, const ::coder::array<
                   cell_wrap_0, 2U> &t8_domainRatios, const ::coder::array<
                   cell_wrap_0, 2U> &t8_contrasts, d_struct_T *b)
  {
    cast(t8_params, b->params);
    cast(t8_backgroundParams, b->backgroundParams);
    cast(t8_scalefactors, b->scalefactors);
    cast(t8_qzshifts, b->qzshifts);
    cast(t8_bulkIns, b->bulkIns);
    cast(t8_bulkOuts, b->bulkOuts);
    cast(t8_resolutionParams, b->resolutionParams);
    cast(t8_domainRatios, b->domainRatios);
    cast(t8_contrasts, b->contrasts);
  }

  static void cast(const e_struct_T *b, struct0_T *c)
  {
    int32_T b_loop_ub;
    int32_T i;
    int32_T loop_ub;
    c->TF.size[0] = 1;
    c->TF.size[1] = b->TF.size[1];
    loop_ub = b->TF.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&b->TF.data[0], &b->TF.data[loop_ub], &c->TF.data[0]);
    }

    c->resample.set_size(1, b->resample.size(1));
    loop_ub = b->resample.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->resample[i] = b->resample[i];
    }

    c->data.set_size(1, b->data.size(1));
    loop_ub = b->data.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->data[i] = b->data[i];
    }

    c->dataPresent.set_size(1, b->dataPresent.size(1));
    loop_ub = b->dataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->dataPresent[i] = b->dataPresent[i];
    }

    c->dataLimits.set_size(1, b->dataLimits.size(1));
    loop_ub = b->dataLimits.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->dataLimits[i] = b->dataLimits[i];
    }

    c->simulationLimits.set_size(1, b->simulationLimits.size(1));
    loop_ub = b->simulationLimits.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->simulationLimits[i] = b->simulationLimits[i];
    }

    c->oilChiDataPresent.set_size(1, b->oilChiDataPresent.size(1));
    loop_ub = b->oilChiDataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->oilChiDataPresent[i] = b->oilChiDataPresent[i];
    }

    c->numberOfContrasts = b->numberOfContrasts;
    c->geometry.size[0] = 1;
    c->geometry.size[1] = b->geometry.size[1];
    loop_ub = b->geometry.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&b->geometry.data[0], &b->geometry.data[loop_ub],
                &c->geometry.data[0]);
    }

    c->useImaginary = b->useImaginary;
    c->repeatLayers.set_size(1, b->repeatLayers.size(1));
    loop_ub = b->repeatLayers.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->repeatLayers[i] = b->repeatLayers[i];
    }

    cast(b->contrastBackgroundParams, c->contrastBackgroundParams);
    cast(b->contrastBackgroundTypes, c->contrastBackgroundTypes);
    cast(b->contrastBackgroundActions, c->contrastBackgroundActions);
    c->contrastQzshifts.set_size(1, b->contrastQzshifts.size(1));
    loop_ub = b->contrastQzshifts.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastQzshifts[i] = b->contrastQzshifts[i];
    }

    c->contrastScalefactors.set_size(1, b->contrastScalefactors.size(1));
    loop_ub = b->contrastScalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastScalefactors[i] = b->contrastScalefactors[i];
    }

    c->contrastBulkIns.set_size(1, b->contrastBulkIns.size(1));
    loop_ub = b->contrastBulkIns.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastBulkIns[i] = b->contrastBulkIns[i];
    }

    c->contrastBulkOuts.set_size(1, b->contrastBulkOuts.size(1));
    loop_ub = b->contrastBulkOuts.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastBulkOuts[i] = b->contrastBulkOuts[i];
    }

    c->contrastResolutionParams.set_size(1, b->contrastResolutionParams.size(1));
    loop_ub = b->contrastResolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastResolutionParams[i] = b->contrastResolutionParams[i];
    }

    c->backgroundParams.set_size(1, b->backgroundParams.size(1));
    loop_ub = b->backgroundParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->backgroundParams[i] = b->backgroundParams[i];
    }

    c->qzshifts.set_size(1, b->qzshifts.size(1));
    loop_ub = b->qzshifts.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->qzshifts[i] = b->qzshifts[i];
    }

    c->scalefactors.set_size(1, b->scalefactors.size(1));
    loop_ub = b->scalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->scalefactors[i] = b->scalefactors[i];
    }

    c->bulkIns.set_size(1, b->bulkIns.size(1));
    loop_ub = b->bulkIns.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->bulkIns[i] = b->bulkIns[i];
    }

    c->bulkOuts.set_size(1, b->bulkOuts.size(1));
    loop_ub = b->bulkOuts.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->bulkOuts[i] = b->bulkOuts[i];
    }

    c->resolutionParams.set_size(1, b->resolutionParams.size(1));
    loop_ub = b->resolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->resolutionParams[i] = b->resolutionParams[i];
    }

    c->params.set_size(1, b->params.size(1));
    loop_ub = b->params.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->params[i] = b->params[i];
    }

    c->numberOfLayers = b->numberOfLayers;
    cast(b->contrastLayers, c->contrastLayers);
    cast(b->layersDetails, c->layersDetails);
    cast(b->customFiles, c->customFiles);
    c->modelType.size[0] = 1;
    c->modelType.size[1] = b->modelType.size[1];
    loop_ub = b->modelType.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&b->modelType.data[0], &b->modelType.data[loop_ub],
                &c->modelType.data[0]);
    }

    c->contrastCustomFiles.set_size(1, b->contrastCustomFiles.size(1));
    loop_ub = b->contrastCustomFiles.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastCustomFiles[i] = b->contrastCustomFiles[i];
    }

    c->contrastDomainRatios.set_size(1, b->contrastDomainRatios.size(1));
    loop_ub = b->contrastDomainRatios.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastDomainRatios[i] = b->contrastDomainRatios[i];
    }

    c->domainRatios.set_size(1, b->domainRatios.size(1));
    loop_ub = b->domainRatios.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->domainRatios[i] = b->domainRatios[i];
    }

    c->numberOfDomainContrasts = b->numberOfDomainContrasts;
    cast(b->domainContrastLayers, c->domainContrastLayers);
    c->fitParams.set_size(1, b->fitParams.size(1));
    loop_ub = b->fitParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->fitParams[i] = b->fitParams[i];
    }

    c->otherParams.set_size(1, b->otherParams.size(1));
    loop_ub = b->otherParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->otherParams[i] = b->otherParams[i];
    }

    c->fitLimits.set_size(b->fitLimits.size(0), 2);
    c->otherLimits.set_size(b->otherLimits.size(0), 2);
    loop_ub = b->fitLimits.size(0);
    b_loop_ub = b->otherLimits.size(0);
    for (i = 0; i < 2; i++) {
      int32_T i1;
      for (i1 = 0; i1 < loop_ub; i1++) {
        c->fitLimits[i1 + c->fitLimits.size(0) * i] = b->fitLimits[i1 +
          b->fitLimits.size(0) * i];
      }

      for (i1 = 0; i1 < b_loop_ub; i1++) {
        c->otherLimits[i1 + c->otherLimits.size(0) * i] = b->otherLimits[i1 +
          b->otherLimits.size(0) * i];
      }
    }

    cast(b->names.params, b->names.backgroundParams, b->names.scalefactors,
         b->names.qzshifts, b->names.bulkIns, b->names.bulkOuts,
         b->names.resolutionParams, b->names.domainRatios, b->names.contrasts,
         &c->names);
    c->checks = b->checks;
  }

  static void cast(const ::coder::array<cell_wrap_48, 2U> &b, ::coder::array<
                   cell_wrap_3, 2U> &c)
  {
    int32_T i;
    c.set_size(1, b.size(1));
    i = b.size(1) - 1;
    for (int32_T i1{0}; i1 <= i; i1++) {
      int32_T loop_ub;
      c[i1].f1.size[0] = 1;
      loop_ub = b[i1].f1.size(1);
      c[i1].f1.size[1] = b[i1].f1.size(1);
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        c[i1].f1.data[i2] = b[i1].f1[i2];
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_10, 2U> &b, ::coder::array<
                   cell_wrap_5, 2U> &c)
  {
    int32_T i;
    c.set_size(b.size(0), b.size(1));
    i = b.size(0) * b.size(1);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      c[i1].f1.size[0] = b[i1].f1.size(0);
      loop_ub = b[i1].f1.size(1);
      c[i1].f1.size[1] = b[i1].f1.size(1);
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = b[i1].f1.size(0);
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          c[i1].f1.data[i3 + c[i1].f1.size[0] * i2] = b[i1].f1[i3 + b[i1].
            f1.size(0) * i2];
        }
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_10, 2U> &b, ::coder::array<
                   cell_wrap_4, 2U> &c)
  {
    int32_T i;
    c.set_size(1, b.size(1));
    i = b.size(1) - 1;
    for (int32_T i1{0}; i1 <= i; i1++) {
      int32_T loop_ub;
      loop_ub = b[i1].f1.size(1);
      c[c.size(0) * i1].f1.set_size(b[b.size(0) * i1].f1.size(0), b[b.size(0) *
        i1].f1.size(1));
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = b[i1].f1.size(0);
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          c[i1].f1[i3 + c[i1].f1.size(0) * i2] = b[i1].f1[i3 + b[i1].f1.size(0) *
            i2];
        }
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_7, 2U> &t9_params, const ::
                   coder::array<cell_wrap_7, 2U> &t9_backgroundParams, const ::
                   coder::array<cell_wrap_7, 2U> &t9_scalefactors, const ::coder::
                   array<cell_wrap_7, 2U> &t9_qzshifts, const ::coder::array<
                   cell_wrap_7, 2U> &t9_bulkIns, const ::coder::array<
                   cell_wrap_7, 2U> &t9_bulkOuts, const ::coder::array<
                   cell_wrap_7, 2U> &t9_resolutionParams, const ::coder::array<
                   cell_wrap_7, 2U> &t9_domainRatios, const ::coder::array<
                   cell_wrap_7, 2U> &t9_contrasts, struct1_T *b)
  {
    cast(t9_params, b->params);
    cast(t9_backgroundParams, b->backgroundParams);
    cast(t9_scalefactors, b->scalefactors);
    cast(t9_qzshifts, b->qzshifts);
    cast(t9_bulkIns, b->bulkIns);
    cast(t9_bulkOuts, b->bulkOuts);
    cast(t9_resolutionParams, b->resolutionParams);
    cast(t9_domainRatios, b->domainRatios);
    cast(t9_contrasts, b->contrasts);
  }

  static void cast(const ::coder::array<cell_wrap_7, 2U> &b, ::coder::array<
                   cell_wrap_0, 2U> &c)
  {
    int32_T i;
    c.set_size(1, b.size(1));
    i = b.size(1) - 1;
    for (int32_T i1{0}; i1 <= i; i1++) {
      int32_T loop_ub;
      c[i1].f1.size[0] = 1;
      loop_ub = b[i1].f1.size(1);
      c[i1].f1.size[1] = b[i1].f1.size(1);
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        c[i1].f1.data[i2] = b[i1].f1[i2];
      }
    }
  }

  void RATMain(struct0_T *problemStruct, const struct3_T *problemLimits,
               struct4_T *controls, const struct5_T *priors, struct6_T *result,
               struct9_T *bayesResults)
  {
    static g_struct_T b_bayesResults;
    c_struct_T bayesResults_nestedSamplerOutput;
    e_struct_T b_problemStruct;
    e_struct_T r;
    makeEmptyBayesResultsStruct(problemStruct->numberOfContrasts, coder::
      internal::b_strcmp(problemStruct->TF.data, problemStruct->TF.size),
      controls->nChains, bayesResults->predictionIntervals.reflectivity,
      bayesResults->predictionIntervals.sld,
      bayesResults->predictionIntervals.sampleChi.data,
      &bayesResults->predictionIntervals.sampleChi.size[0],
      bayesResults->confidenceIntervals.percentile95,
      bayesResults->confidenceIntervals.percentile65,
      bayesResults->confidenceIntervals.mean, &bayesResults->dreamParams,
      &bayesResults->dreamOutput, &bayesResults_nestedSamplerOutput,
      bayesResults->chain);
    bayesResults->nestedSamplerOutput.LogZ =
      bayesResults_nestedSamplerOutput.LogZ;
    bayesResults->nestedSamplerOutput.LogZErr =
      bayesResults_nestedSamplerOutput.LogZErr;
    bayesResults->nestedSamplerOutput.nestSamples.set_size(1, 2);
    bayesResults->nestedSamplerOutput.postSamples.set_size(1, 2);
    bayesResults->nestedSamplerOutput.nestSamples[0] =
      bayesResults_nestedSamplerOutput.nestSamples.data[0];
    bayesResults->nestedSamplerOutput.postSamples[0] =
      bayesResults_nestedSamplerOutput.postSamples.data[0];
    bayesResults->nestedSamplerOutput.nestSamples
      [bayesResults->nestedSamplerOutput.nestSamples.size(0)] =
      bayesResults_nestedSamplerOutput.nestSamples.data[1];
    bayesResults->nestedSamplerOutput.postSamples
      [bayesResults->nestedSamplerOutput.postSamples.size(0)] =
      bayesResults_nestedSamplerOutput.postSamples.data[1];
    if (problemStruct->numberOfContrasts > 0.0) {
      int32_T b_index;
      int32_T i;
      if (coder::internal::c_strcmp(controls->procedure.data,
           controls->procedure.size)) {
        b_index = 0;
      } else if (coder::internal::d_strcmp(controls->procedure.data,
                  controls->procedure.size)) {
        b_index = 1;
      } else if (coder::internal::e_strcmp(controls->procedure.data,
                  controls->procedure.size)) {
        b_index = 2;
      } else if (coder::internal::f_strcmp(controls->procedure.data,
                  controls->procedure.size)) {
        b_index = 3;
      } else if (coder::internal::g_strcmp(controls->procedure.data,
                  controls->procedure.size)) {
        b_index = 4;
      } else {
        b_index = -1;
      }

      switch (b_index) {
       case 0:
        //  Just a single reflectivity calculation
        controls->calcSldDuringFit = true;
        cast(problemStruct, &r);
        reflectivityCalculation(&r, controls, result);
        break;

       case 1:
        if (!coder::internal::t_strcmp(controls->display.data,
             controls->display.size)) {
          triggerEvent();
        }

        cast(problemStruct, &b_problemStruct);
        runSimplex(&b_problemStruct, problemLimits->params,
                   problemLimits->backgroundParams, problemLimits->scalefactors,
                   problemLimits->qzshifts, problemLimits->bulkIns,
                   problemLimits->bulkOuts, problemLimits->resolutionParams,
                   problemLimits->domainRatios, controls, result);
        cast(&b_problemStruct, problemStruct);
        break;

       case 2:
        if (!coder::internal::t_strcmp(controls->display.data,
             controls->display.size)) {
          d_triggerEvent();
        }

        cast(problemStruct, &b_problemStruct);
        runDE(&b_problemStruct, problemLimits->params,
              problemLimits->backgroundParams, problemLimits->scalefactors,
              problemLimits->qzshifts, problemLimits->bulkIns,
              problemLimits->bulkOuts, problemLimits->resolutionParams,
              problemLimits->domainRatios, controls, result);
        cast(&b_problemStruct, problemStruct);
        break;

       case 3:
        if (!coder::internal::t_strcmp(controls->display.data,
             controls->display.size)) {
          i_triggerEvent();
        }

        cast(problemStruct, &b_problemStruct);
        runNestedSampler(&b_problemStruct, problemLimits->params,
                         problemLimits->backgroundParams,
                         problemLimits->scalefactors, problemLimits->qzshifts,
                         problemLimits->bulkIns, problemLimits->bulkOuts,
                         problemLimits->resolutionParams,
                         problemLimits->domainRatios, controls,
                         priors->priorNames, priors->priorValues, result,
                         &bayesResults->predictionIntervals,
                         &bayesResults->confidenceIntervals,
                         &bayesResults->dreamParams, &bayesResults->dreamOutput,
                         &bayesResults->nestedSamplerOutput, bayesResults->chain);
        cast(&b_problemStruct, problemStruct);
        break;

       case 4:
        {
          if (!coder::internal::t_strcmp(controls->display.data,
               controls->display.size)) {
            j_triggerEvent();
          }

          cast(problemStruct, &r);
          runDREAM(&r, problemLimits, controls, priors, &b_problemStruct, result,
                   &b_bayesResults);
          bayesResults->predictionIntervals = b_bayesResults.predictionIntervals;
          bayesResults->confidenceIntervals = b_bayesResults.confidenceIntervals;
          bayesResults->dreamParams = b_bayesResults.dreamParams;
          bayesResults->dreamOutput = b_bayesResults.dreamOutput;
          bayesResults_nestedSamplerOutput.nestSamples.size[0] = 1;
          bayesResults_nestedSamplerOutput.nestSamples.size[1] = 2;
          bayesResults_nestedSamplerOutput.postSamples.size[0] = 1;
          bayesResults_nestedSamplerOutput.postSamples.size[1] = 2;
          bayesResults_nestedSamplerOutput.nestSamples.data[0] =
            b_bayesResults.nestedSamplerOutput.nestSamples.data[0];
          bayesResults_nestedSamplerOutput.postSamples.data[0] =
            b_bayesResults.nestedSamplerOutput.postSamples.data[0];
          bayesResults_nestedSamplerOutput.nestSamples.data[1] =
            b_bayesResults.nestedSamplerOutput.nestSamples.data[1];
          bayesResults_nestedSamplerOutput.postSamples.data[1] =
            b_bayesResults.nestedSamplerOutput.postSamples.data[1];
          bayesResults->chain.set_size(b_bayesResults.chain.size(0),
            b_bayesResults.chain.size(1));
          b_index = b_bayesResults.chain.size(1);
          for (i = 0; i < b_index; i++) {
            int32_T loop_ub;
            loop_ub = b_bayesResults.chain.size(0);
            for (int32_T i1{0}; i1 < loop_ub; i1++) {
              bayesResults->chain[i1 + bayesResults->chain.size(0) * i] =
                b_bayesResults.chain[i1 + b_bayesResults.chain.size(0) * i];
            }
          }

          cast(&b_problemStruct, problemStruct);
          bayesResults->nestedSamplerOutput.LogZ =
            b_bayesResults.nestedSamplerOutput.LogZ;
          bayesResults->nestedSamplerOutput.LogZErr =
            b_bayesResults.nestedSamplerOutput.LogZErr;
          bayesResults->nestedSamplerOutput.nestSamples.set_size(1, 2);
          bayesResults->nestedSamplerOutput.postSamples.set_size(1, 2);
          bayesResults->nestedSamplerOutput.nestSamples[0] =
            bayesResults_nestedSamplerOutput.nestSamples.data[0];
          bayesResults->nestedSamplerOutput.postSamples[0] =
            bayesResults_nestedSamplerOutput.postSamples.data[0];
          bayesResults->nestedSamplerOutput.nestSamples
            [bayesResults->nestedSamplerOutput.nestSamples.size(0)] =
            bayesResults_nestedSamplerOutput.nestSamples.data[1];
          bayesResults->nestedSamplerOutput.postSamples
            [bayesResults->nestedSamplerOutput.postSamples.size(0)] =
            bayesResults_nestedSamplerOutput.postSamples.data[1];
        }
        break;
      }

      //  Then just do a final calculation to fill in SLD if necessary
      //  (i.e. if calcSLD is no for fit)
      if (!controls->calcSldDuringFit) {
        controls->calcSldDuringFit = true;
        controls->procedure.size[0] = 1;
        controls->procedure.size[1] = 9;
        for (i = 0; i < 9; i++) {
          controls->procedure.data[i] = cv1[i];
        }

        reflectivityCalculation(problemStruct, controls, result);
      }
    }
  }
}

// End of code generation (RATMain.cpp)
