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
#include "RATMain_types.h"
#include "lower.h"
#include "makeEmptyBayesResultsStruct.h"
#include "reflectivityCalculation.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "runDE.h"
#include "runDREAM.h"
#include "runNestedSampler.h"
#include "runSimplex.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>
#include <stdio.h>

// Function Declarations
namespace RAT
{
  static void cast(const d_struct_T *b, struct0_T *c);
  static void cast(const struct0_T *b, d_struct_T *c);
  static void cast(const cell_7 *b, cell_11 *c);
  static void cast(const ::coder::array<cell_wrap_5, 1U> &b, ::coder::array<
                   cell_wrap_8, 1U> &c);
  static void cast(const ::coder::array<cell_wrap_3, 2U> &b, ::coder::array<
                   cell_wrap_8, 2U> &c);
  static void cast(const ::coder::array<cell_wrap_4, 2U> &b, ::coder::array<
                   cell_wrap_8, 2U> &c);
  static void cast(const ::coder::array<cell_wrap_6, 2U> &b, ::coder::array<
                   cell_wrap_1, 2U> &c);
}

// Function Definitions
namespace RAT
{
  static void cast(const d_struct_T *b, struct0_T *c)
  {
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    c->contrastBackgrounds.set_size(1, b->contrastBackgrounds.size(1));
    loop_ub = b->contrastBackgrounds.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastBackgrounds[i] = b->contrastBackgrounds[i];
    }

    c->contrastBackgroundsType.set_size(1, b->contrastBackgroundsType.size(1));
    loop_ub = b->contrastBackgroundsType.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastBackgroundsType[i] = b->contrastBackgroundsType[i];
    }

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

    c->dataPresent.set_size(1, b->dataPresent.size(1));
    loop_ub = b->dataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->dataPresent[i] = b->dataPresent[i];
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

    c->contrastResolutions.set_size(1, b->contrastResolutions.size(1));
    loop_ub = b->contrastResolutions.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastResolutions[i] = b->contrastResolutions[i];
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

    c->bulkIn.set_size(1, b->bulkIn.size(1));
    loop_ub = b->bulkIn.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->bulkIn[i] = b->bulkIn[i];
    }

    c->bulkOut.set_size(1, b->bulkOut.size(1));
    loop_ub = b->bulkOut.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->bulkOut[i] = b->bulkOut[i];
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

    c->domainRatio.set_size(1, b->domainRatio.size(1));
    loop_ub = b->domainRatio.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->domainRatio[i] = b->domainRatio[i];
    }

    c->numberOfDomainContrasts = b->numberOfDomainContrasts;
    c->fitParams.set_size(b->fitParams.size(0), b->fitParams.size(1));
    loop_ub = b->fitParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = b->fitParams.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        c->fitParams[i1 + c->fitParams.size(0) * i] = b->fitParams[i1 +
          b->fitParams.size(0) * i];
      }
    }

    c->otherParams.set_size(b->otherParams.size(0), b->otherParams.size(1));
    loop_ub = b->otherParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = b->otherParams.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        c->otherParams[i1 + c->otherParams.size(0) * i] = b->otherParams[i1 +
          b->otherParams.size(0) * i];
      }
    }

    c->fitLimits.set_size(b->fitLimits.size(0), b->fitLimits.size(1));
    loop_ub = b->fitLimits.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = b->fitLimits.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        c->fitLimits[i1 + c->fitLimits.size(0) * i] = b->fitLimits[i1 +
          b->fitLimits.size(0) * i];
      }
    }

    c->otherLimits.set_size(b->otherLimits.size(0), b->otherLimits.size(1));
    loop_ub = b->otherLimits.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = b->otherLimits.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        c->otherLimits[i1 + c->otherLimits.size(0) * i] = b->otherLimits[i1 +
          b->otherLimits.size(0) * i];
      }
    }
  }

  static void cast(const struct0_T *b, d_struct_T *c)
  {
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    c->contrastBackgrounds.set_size(1, b->contrastBackgrounds.size(1));
    loop_ub = b->contrastBackgrounds.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastBackgrounds[i] = b->contrastBackgrounds[i];
    }

    c->contrastBackgroundsType.set_size(1, b->contrastBackgroundsType.size(1));
    loop_ub = b->contrastBackgroundsType.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastBackgroundsType[i] = b->contrastBackgroundsType[i];
    }

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

    c->dataPresent.set_size(1, b->dataPresent.size(1));
    loop_ub = b->dataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->dataPresent[i] = b->dataPresent[i];
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

    c->contrastResolutions.set_size(1, b->contrastResolutions.size(1));
    loop_ub = b->contrastResolutions.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastResolutions[i] = b->contrastResolutions[i];
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

    c->bulkIn.set_size(1, b->bulkIn.size(1));
    loop_ub = b->bulkIn.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->bulkIn[i] = b->bulkIn[i];
    }

    c->bulkOut.set_size(1, b->bulkOut.size(1));
    loop_ub = b->bulkOut.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->bulkOut[i] = b->bulkOut[i];
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

    c->domainRatio.set_size(1, b->domainRatio.size(1));
    loop_ub = b->domainRatio.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->domainRatio[i] = b->domainRatio[i];
    }

    c->numberOfDomainContrasts = b->numberOfDomainContrasts;
    c->fitParams.set_size(b->fitParams.size(0), b->fitParams.size(1));
    loop_ub = b->fitParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = b->fitParams.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        c->fitParams[i1 + c->fitParams.size(0) * i] = b->fitParams[i1 +
          b->fitParams.size(0) * i];
      }
    }

    c->otherParams.set_size(b->otherParams.size(0), b->otherParams.size(1));
    loop_ub = b->otherParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = b->otherParams.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        c->otherParams[i1 + c->otherParams.size(0) * i] = b->otherParams[i1 +
          b->otherParams.size(0) * i];
      }
    }

    c->fitLimits.set_size(b->fitLimits.size(0), b->fitLimits.size(1));
    loop_ub = b->fitLimits.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = b->fitLimits.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        c->fitLimits[i1 + c->fitLimits.size(0) * i] = b->fitLimits[i1 +
          b->fitLimits.size(0) * i];
      }
    }

    c->otherLimits.set_size(b->otherLimits.size(0), b->otherLimits.size(1));
    loop_ub = b->otherLimits.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = b->otherLimits.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        c->otherLimits[i1 + c->otherLimits.size(0) * i] = b->otherLimits[i1 +
          b->otherLimits.size(0) * i];
      }
    }
  }

  static void cast(const cell_7 *b, cell_11 *c)
  {
    int32_T i;
    int32_T loop_ub;
    c->f1.set_size(1, b->f1.size(1));
    loop_ub = b->f1.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->f1[i] = b->f1[i];
    }

    cast(b->f2, c->f2);
    c->f3.set_size(1, b->f3.size(1));
    loop_ub = b->f3.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->f3[i] = b->f3[i];
    }

    c->f4.set_size(1, b->f4.size(1));
    loop_ub = b->f4.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->f4[i] = b->f4[i];
    }

    cast(b->f5, c->f5);
    cast(b->f6, c->f6);
    cast(b->f7, c->f7);
    cast(b->f8, c->f8);
    cast(b->f9, c->f9);
    cast(b->f10, c->f10);
    cast(b->f11, c->f11);
    cast(b->f12, c->f12);
    cast(b->f13, c->f13);
    cast(b->f14, c->f14);
    cast(b->f15, c->f15);
    cast(b->f16, c->f16);
    cast(b->f17, c->f17);
    c->f18.set_size(1, b->f18.size(1));
    loop_ub = b->f18.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->f18[i] = b->f18[i];
    }

    cast(b->f19, c->f19);
    cast(b->f20, c->f20);
  }

  static void cast(const ::coder::array<cell_wrap_5, 1U> &b, ::coder::array<
                   cell_wrap_8, 1U> &c)
  {
    int32_T i;
    c.set_size(b.size(0));
    i = b.size(0);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = b[i1].f1.size[1];
      c[i1].f1.set_size(b[i1].f1.size[0], b[i1].f1.size[1]);
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = b[i1].f1.size[0];
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          c[i1].f1[c[i1].f1.size(0) * i2] = b[i1].f1.data[b[i1].f1.size[0] * i2];
        }
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_3, 2U> &b, ::coder::array<
                   cell_wrap_8, 2U> &c)
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

  static void cast(const ::coder::array<cell_wrap_4, 2U> &b, ::coder::array<
                   cell_wrap_8, 2U> &c)
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
          c[i1].f1[c[i1].f1.size(0) * i2] = b[i1].f1[b[i1].f1.size(0) * i2];
        }
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_6, 2U> &b, ::coder::array<
                   cell_wrap_1, 2U> &c)
  {
    int32_T i;
    c.set_size(1, b.size(1));
    i = b.size(1) - 1;
    for (int32_T i1{0}; i1 <= i; i1++) {
      int32_T loop_ub;
      loop_ub = b[i1].f1.size[1];
      c[c.size(0) * i1].f1.set_size(1, b[b.size(0) * i1].f1.size[1]);
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        c[i1].f1[i2] = b[i1].f1.data[i2];
      }
    }
  }

  void RATMain(struct0_T *problemStruct, const cell_7 *problemCells, const
               struct1_T *problemLimits, struct2_T *controls, const struct4_T
               *priors, struct5_T *contrastParams, cell_wrap_9 resultCells[6],
               struct7_T *bayesResults)
  {
    static c_struct_T bayesResults_bayesRes;
    static d_struct_T b_problemStruct;
    static d_struct_T r;
    static h_struct_T b_bayesResults;
    ::coder::array<int8_T, 1U> t19_calculations_allChis;
    cell_11 r1;
    e_struct_T b_contrastParams;
    e_struct_T c_contrastParams;
    int32_T switch_expression_size[2];
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T loop_ub;
    int32_T problemStruct_idx_0_tmp;
    char_T switch_expression_data[10000];
    coder::repmat(resultCells);
    problemStruct_idx_0_tmp = static_cast<int32_T>
      (problemStruct->numberOfContrasts);
    t19_calculations_allChis.set_size(problemStruct_idx_0_tmp);
    contrastParams->ssubs.set_size(problemStruct_idx_0_tmp);
    contrastParams->backgroundParams.set_size(problemStruct_idx_0_tmp);
    contrastParams->qzshifts.set_size(problemStruct_idx_0_tmp);
    contrastParams->scalefactors.set_size(problemStruct_idx_0_tmp);
    contrastParams->bulkIn.set_size(problemStruct_idx_0_tmp);
    contrastParams->bulkOut.set_size(problemStruct_idx_0_tmp);
    contrastParams->resolutionParams.set_size(problemStruct_idx_0_tmp);
    for (i = 0; i < problemStruct_idx_0_tmp; i++) {
      t19_calculations_allChis[i] = 0;
      contrastParams->ssubs[i] = 0.0;
      contrastParams->backgroundParams[i] = 0.0;
      contrastParams->qzshifts[i] = 0.0;
      contrastParams->scalefactors[i] = 0.0;
      contrastParams->bulkIn[i] = 0.0;
      contrastParams->bulkOut[i] = 0.0;
      contrastParams->resolutionParams[i] = 0.0;
    }

    contrastParams->calculations.allChis.set_size(t19_calculations_allChis.size
      (0));
    loop_ub = t19_calculations_allChis.size(0);
    for (i = 0; i < loop_ub; i++) {
      contrastParams->calculations.allChis[i] = 0.0;
    }

    contrastParams->calculations.sumChi = 0.0;
    contrastParams->allSubRough.set_size(problemStruct_idx_0_tmp);
    for (i = 0; i < problemStruct_idx_0_tmp; i++) {
      contrastParams->allSubRough[i] = 0.0;
    }

    contrastParams->resample.set_size(problemStruct_idx_0_tmp, 1);
    for (i = 0; i < 1; i++) {
      for (i1 = 0; i1 < problemStruct_idx_0_tmp; i1++) {
        contrastParams->resample[i1] = 0.0;
      }
    }

    makeEmptyBayesResultsStruct(problemStruct->numberOfContrasts, coder::
      internal::b_strcmp(problemStruct->TF.data, problemStruct->TF.size),
      controls->nChains, bayesResults->bestFitsMean.ref,
      bayesResults->bestFitsMean.sld, &bayesResults->bestFitsMean.chi,
      bayesResults->bestFitsMean.data, bayesResults->predlims.refPredInts,
      bayesResults->predlims.sldPredInts, bayesResults->predlims.refXdata,
      bayesResults->predlims.sldXdata, bayesResults->predlims.sampleChi.data,
      &bayesResults->predlims.sampleChi.size[0], bayesResults->parConfInts.par95,
      bayesResults->parConfInts.par65, bayesResults->parConfInts.mean,
      bayesResults->bestPars, &bayesResults_bayesRes, bayesResults->chain);
    bayesResults->bayesRes.allChains.set_size
      (bayesResults_bayesRes.allChains.size(0),
       bayesResults_bayesRes.allChains.size(1),
       bayesResults_bayesRes.allChains.size(2));
    loop_ub = bayesResults_bayesRes.allChains.size(2);
    for (i = 0; i < loop_ub; i++) {
      problemStruct_idx_0_tmp = bayesResults_bayesRes.allChains.size(1);
      for (i1 = 0; i1 < problemStruct_idx_0_tmp; i1++) {
        b_loop_ub = bayesResults_bayesRes.allChains.size(0);
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          bayesResults->bayesRes.allChains[(i2 +
            bayesResults->bayesRes.allChains.size(0) * i1) +
            bayesResults->bayesRes.allChains.size(0) *
            bayesResults->bayesRes.allChains.size(1) * i] =
            bayesResults_bayesRes.allChains[(i2 +
            bayesResults_bayesRes.allChains.size(0) * i1) +
            bayesResults_bayesRes.allChains.size(0) *
            bayesResults_bayesRes.allChains.size(1) * i];
        }
      }
    }

    bayesResults->bayesRes.dreamOutput = bayesResults_bayesRes.dreamOutput;
    bayesResults->bayesRes.nestOutput.LogZ =
      bayesResults_bayesRes.nestOutput.LogZ;
    bayesResults->bayesRes.nestOutput.nestSamples.set_size(1, 2);
    bayesResults->bayesRes.nestOutput.postSamples.set_size(1, 2);
    bayesResults->bayesRes.nestOutput.nestSamples[0] =
      bayesResults_bayesRes.nestOutput.nestSamples.data[0];
    bayesResults->bayesRes.nestOutput.postSamples[0] =
      bayesResults_bayesRes.nestOutput.postSamples.data[0];
    bayesResults->bayesRes.nestOutput.nestSamples
      [bayesResults->bayesRes.nestOutput.nestSamples.size(0)] =
      bayesResults_bayesRes.nestOutput.nestSamples.data[1];
    bayesResults->bayesRes.nestOutput.postSamples
      [bayesResults->bayesRes.nestOutput.postSamples.size(0)] =
      bayesResults_bayesRes.nestOutput.postSamples.data[1];

    // Decide what we are doing....
    coder::lower(controls->procedure.data, controls->procedure.size,
                 switch_expression_data, switch_expression_size);
    if (coder::internal::c_strcmp(switch_expression_data, switch_expression_size))
    {
      problemStruct_idx_0_tmp = 0;
    } else if (coder::internal::d_strcmp(switch_expression_data,
                switch_expression_size)) {
      problemStruct_idx_0_tmp = 1;
    } else if (coder::internal::e_strcmp(switch_expression_data,
                switch_expression_size)) {
      problemStruct_idx_0_tmp = 2;
    } else if (coder::internal::f_strcmp(switch_expression_data,
                switch_expression_size)) {
      problemStruct_idx_0_tmp = 3;
    } else if (coder::internal::g_strcmp(switch_expression_data,
                switch_expression_size)) {
      problemStruct_idx_0_tmp = 4;
    } else {
      problemStruct_idx_0_tmp = -1;
    }

    switch (problemStruct_idx_0_tmp) {
     case 0:
      // Just a single reflectivity calculation
      cast(problemStruct, &r);
      cast(problemCells, &r1);
      reflectivityCalculation(&r, &r1, controls, &b_contrastParams, resultCells);
      contrastParams->ssubs.set_size(b_contrastParams.ssubs.size(0));
      loop_ub = b_contrastParams.ssubs.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->ssubs[i] = b_contrastParams.ssubs[i];
      }

      contrastParams->backgroundParams.set_size
        (b_contrastParams.backgroundParams.size(0));
      loop_ub = b_contrastParams.backgroundParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->backgroundParams[i] =
          b_contrastParams.backgroundParams[i];
      }

      contrastParams->qzshifts.set_size(b_contrastParams.qzshifts.size(0));
      loop_ub = b_contrastParams.qzshifts.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->qzshifts[i] = b_contrastParams.qzshifts[i];
      }

      contrastParams->scalefactors.set_size(b_contrastParams.scalefactors.size(0));
      loop_ub = b_contrastParams.scalefactors.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->scalefactors[i] = b_contrastParams.scalefactors[i];
      }

      contrastParams->bulkIn.set_size(b_contrastParams.bulkIn.size(0));
      loop_ub = b_contrastParams.bulkIn.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->bulkIn[i] = b_contrastParams.bulkIn[i];
      }

      contrastParams->bulkOut.set_size(b_contrastParams.bulkOut.size(0));
      loop_ub = b_contrastParams.bulkOut.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->bulkOut[i] = b_contrastParams.bulkOut[i];
      }

      contrastParams->resolutionParams.set_size
        (b_contrastParams.resolutionParams.size(0));
      loop_ub = b_contrastParams.resolutionParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->resolutionParams[i] =
          b_contrastParams.resolutionParams[i];
      }

      contrastParams->calculations = b_contrastParams.calculations;
      contrastParams->allSubRough.set_size(b_contrastParams.allSubRough.size(0));
      loop_ub = b_contrastParams.allSubRough.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->allSubRough[i] = b_contrastParams.allSubRough[i];
      }

      contrastParams->resample.set_size(1, b_contrastParams.resample.size(1));
      loop_ub = b_contrastParams.resample.size(1);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->resample[contrastParams->resample.size(0) * i] =
          b_contrastParams.resample[i];
      }
      break;

     case 1:
      if (!coder::internal::q_strcmp(controls->display.data,
           controls->display.size)) {
        printf("\nRunning simplex\n\n");
        fflush(stdout);
      }

      cast(problemStruct, &b_problemStruct);
      cast(problemCells, &r1);
      runSimplex(&b_problemStruct, &r1, problemLimits, controls,
                 &c_contrastParams, resultCells);
      b_contrastParams.ssubs.set_size(c_contrastParams.ssubs.size(0));
      loop_ub = c_contrastParams.ssubs.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.ssubs[i] = c_contrastParams.ssubs[i];
      }

      b_contrastParams.backgroundParams.set_size
        (c_contrastParams.backgroundParams.size(0));
      loop_ub = c_contrastParams.backgroundParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.backgroundParams[i] =
          c_contrastParams.backgroundParams[i];
      }

      b_contrastParams.qzshifts.set_size(c_contrastParams.qzshifts.size(0));
      loop_ub = c_contrastParams.qzshifts.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.qzshifts[i] = c_contrastParams.qzshifts[i];
      }

      b_contrastParams.scalefactors.set_size(c_contrastParams.scalefactors.size
        (0));
      loop_ub = c_contrastParams.scalefactors.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.scalefactors[i] = c_contrastParams.scalefactors[i];
      }

      b_contrastParams.bulkIn.set_size(c_contrastParams.bulkIn.size(0));
      loop_ub = c_contrastParams.bulkIn.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.bulkIn[i] = c_contrastParams.bulkIn[i];
      }

      b_contrastParams.bulkOut.set_size(c_contrastParams.bulkOut.size(0));
      loop_ub = c_contrastParams.bulkOut.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.bulkOut[i] = c_contrastParams.bulkOut[i];
      }

      b_contrastParams.resolutionParams.set_size
        (c_contrastParams.resolutionParams.size(0));
      loop_ub = c_contrastParams.resolutionParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.resolutionParams[i] =
          c_contrastParams.resolutionParams[i];
      }

      b_contrastParams.allSubRough.set_size(c_contrastParams.allSubRough.size(0));
      loop_ub = c_contrastParams.allSubRough.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.allSubRough[i] = c_contrastParams.allSubRough[i];
      }

      b_contrastParams.resample.set_size(1, c_contrastParams.resample.size(1));
      loop_ub = c_contrastParams.resample.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.resample[i] = c_contrastParams.resample[i];
      }

      cast(&b_problemStruct, problemStruct);
      contrastParams->ssubs.set_size(b_contrastParams.ssubs.size(0));
      loop_ub = b_contrastParams.ssubs.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->ssubs[i] = b_contrastParams.ssubs[i];
      }

      contrastParams->backgroundParams.set_size
        (b_contrastParams.backgroundParams.size(0));
      loop_ub = b_contrastParams.backgroundParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->backgroundParams[i] =
          b_contrastParams.backgroundParams[i];
      }

      contrastParams->qzshifts.set_size(b_contrastParams.qzshifts.size(0));
      loop_ub = b_contrastParams.qzshifts.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->qzshifts[i] = b_contrastParams.qzshifts[i];
      }

      contrastParams->scalefactors.set_size(b_contrastParams.scalefactors.size(0));
      loop_ub = b_contrastParams.scalefactors.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->scalefactors[i] = b_contrastParams.scalefactors[i];
      }

      contrastParams->bulkIn.set_size(b_contrastParams.bulkIn.size(0));
      loop_ub = b_contrastParams.bulkIn.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->bulkIn[i] = b_contrastParams.bulkIn[i];
      }

      contrastParams->bulkOut.set_size(b_contrastParams.bulkOut.size(0));
      loop_ub = b_contrastParams.bulkOut.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->bulkOut[i] = b_contrastParams.bulkOut[i];
      }

      contrastParams->resolutionParams.set_size
        (b_contrastParams.resolutionParams.size(0));
      loop_ub = b_contrastParams.resolutionParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->resolutionParams[i] =
          b_contrastParams.resolutionParams[i];
      }

      contrastParams->calculations = c_contrastParams.calculations;
      contrastParams->allSubRough.set_size(b_contrastParams.allSubRough.size(0));
      loop_ub = b_contrastParams.allSubRough.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->allSubRough[i] = b_contrastParams.allSubRough[i];
      }

      contrastParams->resample.set_size(1, b_contrastParams.resample.size(1));
      loop_ub = b_contrastParams.resample.size(1);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->resample[contrastParams->resample.size(0) * i] =
          b_contrastParams.resample[i];
      }
      break;

     case 2:
      if (!coder::internal::q_strcmp(controls->display.data,
           controls->display.size)) {
        printf("\nRunning Differential Evolution\n\n");
        fflush(stdout);
      }

      cast(problemStruct, &b_problemStruct);
      cast(problemCells, &r1);
      runDE(&b_problemStruct, &r1, problemLimits, controls, &c_contrastParams,
            resultCells);
      b_contrastParams.ssubs.set_size(c_contrastParams.ssubs.size(0));
      loop_ub = c_contrastParams.ssubs.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.ssubs[i] = c_contrastParams.ssubs[i];
      }

      b_contrastParams.backgroundParams.set_size
        (c_contrastParams.backgroundParams.size(0));
      loop_ub = c_contrastParams.backgroundParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.backgroundParams[i] =
          c_contrastParams.backgroundParams[i];
      }

      b_contrastParams.qzshifts.set_size(c_contrastParams.qzshifts.size(0));
      loop_ub = c_contrastParams.qzshifts.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.qzshifts[i] = c_contrastParams.qzshifts[i];
      }

      b_contrastParams.scalefactors.set_size(c_contrastParams.scalefactors.size
        (0));
      loop_ub = c_contrastParams.scalefactors.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.scalefactors[i] = c_contrastParams.scalefactors[i];
      }

      b_contrastParams.bulkIn.set_size(c_contrastParams.bulkIn.size(0));
      loop_ub = c_contrastParams.bulkIn.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.bulkIn[i] = c_contrastParams.bulkIn[i];
      }

      b_contrastParams.bulkOut.set_size(c_contrastParams.bulkOut.size(0));
      loop_ub = c_contrastParams.bulkOut.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.bulkOut[i] = c_contrastParams.bulkOut[i];
      }

      b_contrastParams.resolutionParams.set_size
        (c_contrastParams.resolutionParams.size(0));
      loop_ub = c_contrastParams.resolutionParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.resolutionParams[i] =
          c_contrastParams.resolutionParams[i];
      }

      b_contrastParams.allSubRough.set_size(c_contrastParams.allSubRough.size(0));
      loop_ub = c_contrastParams.allSubRough.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.allSubRough[i] = c_contrastParams.allSubRough[i];
      }

      b_contrastParams.resample.set_size(1, c_contrastParams.resample.size(1));
      loop_ub = c_contrastParams.resample.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.resample[i] = c_contrastParams.resample[i];
      }

      cast(&b_problemStruct, problemStruct);
      contrastParams->ssubs.set_size(b_contrastParams.ssubs.size(0));
      loop_ub = b_contrastParams.ssubs.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->ssubs[i] = b_contrastParams.ssubs[i];
      }

      contrastParams->backgroundParams.set_size
        (b_contrastParams.backgroundParams.size(0));
      loop_ub = b_contrastParams.backgroundParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->backgroundParams[i] =
          b_contrastParams.backgroundParams[i];
      }

      contrastParams->qzshifts.set_size(b_contrastParams.qzshifts.size(0));
      loop_ub = b_contrastParams.qzshifts.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->qzshifts[i] = b_contrastParams.qzshifts[i];
      }

      contrastParams->scalefactors.set_size(b_contrastParams.scalefactors.size(0));
      loop_ub = b_contrastParams.scalefactors.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->scalefactors[i] = b_contrastParams.scalefactors[i];
      }

      contrastParams->bulkIn.set_size(b_contrastParams.bulkIn.size(0));
      loop_ub = b_contrastParams.bulkIn.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->bulkIn[i] = b_contrastParams.bulkIn[i];
      }

      contrastParams->bulkOut.set_size(b_contrastParams.bulkOut.size(0));
      loop_ub = b_contrastParams.bulkOut.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->bulkOut[i] = b_contrastParams.bulkOut[i];
      }

      contrastParams->resolutionParams.set_size
        (b_contrastParams.resolutionParams.size(0));
      loop_ub = b_contrastParams.resolutionParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->resolutionParams[i] =
          b_contrastParams.resolutionParams[i];
      }

      contrastParams->calculations = c_contrastParams.calculations;
      contrastParams->allSubRough.set_size(b_contrastParams.allSubRough.size(0));
      loop_ub = b_contrastParams.allSubRough.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->allSubRough[i] = b_contrastParams.allSubRough[i];
      }

      contrastParams->resample.set_size(1, b_contrastParams.resample.size(1));
      loop_ub = b_contrastParams.resample.size(1);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->resample[contrastParams->resample.size(0) * i] =
          b_contrastParams.resample[i];
      }
      break;

     case 3:
      if (!coder::internal::q_strcmp(controls->display.data,
           controls->display.size)) {
        printf("\nRunning Nested Sampler\n\n");
        fflush(stdout);
      }

      cast(problemStruct, &b_problemStruct);
      cast(problemCells, &r1);
      runNestedSampler(&b_problemStruct, &r1, problemLimits, controls, priors,
                       &c_contrastParams, resultCells, bayesResults);
      b_contrastParams.ssubs.set_size(c_contrastParams.ssubs.size(0));
      loop_ub = c_contrastParams.ssubs.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.ssubs[i] = c_contrastParams.ssubs[i];
      }

      b_contrastParams.backgroundParams.set_size
        (c_contrastParams.backgroundParams.size(0));
      loop_ub = c_contrastParams.backgroundParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.backgroundParams[i] =
          c_contrastParams.backgroundParams[i];
      }

      b_contrastParams.qzshifts.set_size(c_contrastParams.qzshifts.size(0));
      loop_ub = c_contrastParams.qzshifts.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.qzshifts[i] = c_contrastParams.qzshifts[i];
      }

      b_contrastParams.scalefactors.set_size(c_contrastParams.scalefactors.size
        (0));
      loop_ub = c_contrastParams.scalefactors.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.scalefactors[i] = c_contrastParams.scalefactors[i];
      }

      b_contrastParams.bulkIn.set_size(c_contrastParams.bulkIn.size(0));
      loop_ub = c_contrastParams.bulkIn.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.bulkIn[i] = c_contrastParams.bulkIn[i];
      }

      b_contrastParams.bulkOut.set_size(c_contrastParams.bulkOut.size(0));
      loop_ub = c_contrastParams.bulkOut.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.bulkOut[i] = c_contrastParams.bulkOut[i];
      }

      b_contrastParams.resolutionParams.set_size
        (c_contrastParams.resolutionParams.size(0));
      loop_ub = c_contrastParams.resolutionParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.resolutionParams[i] =
          c_contrastParams.resolutionParams[i];
      }

      b_contrastParams.allSubRough.set_size(c_contrastParams.allSubRough.size(0));
      loop_ub = c_contrastParams.allSubRough.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.allSubRough[i] = c_contrastParams.allSubRough[i];
      }

      b_contrastParams.resample.set_size(1, c_contrastParams.resample.size(1));
      loop_ub = c_contrastParams.resample.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.resample[i] = c_contrastParams.resample[i];
      }

      cast(&b_problemStruct, problemStruct);
      contrastParams->ssubs.set_size(b_contrastParams.ssubs.size(0));
      loop_ub = b_contrastParams.ssubs.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->ssubs[i] = b_contrastParams.ssubs[i];
      }

      contrastParams->backgroundParams.set_size
        (b_contrastParams.backgroundParams.size(0));
      loop_ub = b_contrastParams.backgroundParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->backgroundParams[i] =
          b_contrastParams.backgroundParams[i];
      }

      contrastParams->qzshifts.set_size(b_contrastParams.qzshifts.size(0));
      loop_ub = b_contrastParams.qzshifts.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->qzshifts[i] = b_contrastParams.qzshifts[i];
      }

      contrastParams->scalefactors.set_size(b_contrastParams.scalefactors.size(0));
      loop_ub = b_contrastParams.scalefactors.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->scalefactors[i] = b_contrastParams.scalefactors[i];
      }

      contrastParams->bulkIn.set_size(b_contrastParams.bulkIn.size(0));
      loop_ub = b_contrastParams.bulkIn.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->bulkIn[i] = b_contrastParams.bulkIn[i];
      }

      contrastParams->bulkOut.set_size(b_contrastParams.bulkOut.size(0));
      loop_ub = b_contrastParams.bulkOut.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->bulkOut[i] = b_contrastParams.bulkOut[i];
      }

      contrastParams->resolutionParams.set_size
        (b_contrastParams.resolutionParams.size(0));
      loop_ub = b_contrastParams.resolutionParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->resolutionParams[i] =
          b_contrastParams.resolutionParams[i];
      }

      contrastParams->calculations = c_contrastParams.calculations;
      contrastParams->allSubRough.set_size(b_contrastParams.allSubRough.size(0));
      loop_ub = b_contrastParams.allSubRough.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->allSubRough[i] = b_contrastParams.allSubRough[i];
      }

      contrastParams->resample.set_size(1, b_contrastParams.resample.size(1));
      loop_ub = b_contrastParams.resample.size(1);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->resample[contrastParams->resample.size(0) * i] =
          b_contrastParams.resample[i];
      }
      break;

     case 4:
      if (!coder::internal::q_strcmp(controls->display.data,
           controls->display.size)) {
        printf("\nRunning DREAM\n\n");
        fflush(stdout);
      }

      cast(problemStruct, &r);
      cast(problemCells, &r1);
      runDREAM(&r, &r1, problemLimits, controls, priors, &b_problemStruct,
               &c_contrastParams, resultCells, &b_bayesResults);
      bayesResults->bestFitsMean = b_bayesResults.bestFitsMean;
      bayesResults->predlims = b_bayesResults.predlims;
      bayesResults->parConfInts = b_bayesResults.parConfInts;
      bayesResults->bestPars.set_size(1, b_bayesResults.bestPars.size(1));
      loop_ub = b_bayesResults.bestPars.size(1);
      for (i = 0; i < loop_ub; i++) {
        bayesResults->bestPars[i] = b_bayesResults.bestPars[i];
      }

      bayesResults_bayesRes.allChains.set_size
        (b_bayesResults.bayesRes.allChains.size(0),
         b_bayesResults.bayesRes.allChains.size(1),
         b_bayesResults.bayesRes.allChains.size(2));
      loop_ub = b_bayesResults.bayesRes.allChains.size(2);
      for (i = 0; i < loop_ub; i++) {
        problemStruct_idx_0_tmp = b_bayesResults.bayesRes.allChains.size(1);
        for (i1 = 0; i1 < problemStruct_idx_0_tmp; i1++) {
          b_loop_ub = b_bayesResults.bayesRes.allChains.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            bayesResults_bayesRes.allChains[(i2 +
              bayesResults_bayesRes.allChains.size(0) * i1) +
              bayesResults_bayesRes.allChains.size(0) *
              bayesResults_bayesRes.allChains.size(1) * i] =
              b_bayesResults.bayesRes.allChains[(i2 +
              b_bayesResults.bayesRes.allChains.size(0) * i1) +
              b_bayesResults.bayesRes.allChains.size(0) *
              b_bayesResults.bayesRes.allChains.size(1) * i];
          }
        }
      }

      bayesResults_bayesRes.nestOutput.nestSamples.size[0] = 1;
      bayesResults_bayesRes.nestOutput.nestSamples.size[1] = 2;
      bayesResults_bayesRes.nestOutput.postSamples.size[0] = 1;
      bayesResults_bayesRes.nestOutput.postSamples.size[1] = 2;
      bayesResults_bayesRes.nestOutput.nestSamples.data[0] =
        b_bayesResults.bayesRes.nestOutput.nestSamples.data[0];
      bayesResults_bayesRes.nestOutput.postSamples.data[0] =
        b_bayesResults.bayesRes.nestOutput.postSamples.data[0];
      bayesResults_bayesRes.nestOutput.nestSamples.data[1] =
        b_bayesResults.bayesRes.nestOutput.nestSamples.data[1];
      bayesResults_bayesRes.nestOutput.postSamples.data[1] =
        b_bayesResults.bayesRes.nestOutput.postSamples.data[1];
      bayesResults->chain.set_size(b_bayesResults.chain.size(0),
        b_bayesResults.chain.size(1));
      loop_ub = b_bayesResults.chain.size(1);
      for (i = 0; i < loop_ub; i++) {
        problemStruct_idx_0_tmp = b_bayesResults.chain.size(0);
        for (i1 = 0; i1 < problemStruct_idx_0_tmp; i1++) {
          bayesResults->chain[i1 + bayesResults->chain.size(0) * i] =
            b_bayesResults.chain[i1 + b_bayesResults.chain.size(0) * i];
        }
      }

      b_contrastParams.ssubs.set_size(c_contrastParams.ssubs.size(0));
      loop_ub = c_contrastParams.ssubs.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.ssubs[i] = c_contrastParams.ssubs[i];
      }

      b_contrastParams.backgroundParams.set_size
        (c_contrastParams.backgroundParams.size(0));
      loop_ub = c_contrastParams.backgroundParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.backgroundParams[i] =
          c_contrastParams.backgroundParams[i];
      }

      b_contrastParams.qzshifts.set_size(c_contrastParams.qzshifts.size(0));
      loop_ub = c_contrastParams.qzshifts.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.qzshifts[i] = c_contrastParams.qzshifts[i];
      }

      b_contrastParams.scalefactors.set_size(c_contrastParams.scalefactors.size
        (0));
      loop_ub = c_contrastParams.scalefactors.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.scalefactors[i] = c_contrastParams.scalefactors[i];
      }

      b_contrastParams.bulkIn.set_size(c_contrastParams.bulkIn.size(0));
      loop_ub = c_contrastParams.bulkIn.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.bulkIn[i] = c_contrastParams.bulkIn[i];
      }

      b_contrastParams.bulkOut.set_size(c_contrastParams.bulkOut.size(0));
      loop_ub = c_contrastParams.bulkOut.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.bulkOut[i] = c_contrastParams.bulkOut[i];
      }

      b_contrastParams.resolutionParams.set_size
        (c_contrastParams.resolutionParams.size(0));
      loop_ub = c_contrastParams.resolutionParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.resolutionParams[i] =
          c_contrastParams.resolutionParams[i];
      }

      b_contrastParams.allSubRough.set_size(c_contrastParams.allSubRough.size(0));
      loop_ub = c_contrastParams.allSubRough.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.allSubRough[i] = c_contrastParams.allSubRough[i];
      }

      b_contrastParams.resample.set_size(1, c_contrastParams.resample.size(1));
      loop_ub = c_contrastParams.resample.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.resample[i] = c_contrastParams.resample[i];
      }

      cast(&b_problemStruct, problemStruct);
      contrastParams->ssubs.set_size(b_contrastParams.ssubs.size(0));
      loop_ub = b_contrastParams.ssubs.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->ssubs[i] = b_contrastParams.ssubs[i];
      }

      contrastParams->backgroundParams.set_size
        (b_contrastParams.backgroundParams.size(0));
      loop_ub = b_contrastParams.backgroundParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->backgroundParams[i] =
          b_contrastParams.backgroundParams[i];
      }

      contrastParams->qzshifts.set_size(b_contrastParams.qzshifts.size(0));
      loop_ub = b_contrastParams.qzshifts.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->qzshifts[i] = b_contrastParams.qzshifts[i];
      }

      contrastParams->scalefactors.set_size(b_contrastParams.scalefactors.size(0));
      loop_ub = b_contrastParams.scalefactors.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->scalefactors[i] = b_contrastParams.scalefactors[i];
      }

      contrastParams->bulkIn.set_size(b_contrastParams.bulkIn.size(0));
      loop_ub = b_contrastParams.bulkIn.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->bulkIn[i] = b_contrastParams.bulkIn[i];
      }

      contrastParams->bulkOut.set_size(b_contrastParams.bulkOut.size(0));
      loop_ub = b_contrastParams.bulkOut.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->bulkOut[i] = b_contrastParams.bulkOut[i];
      }

      contrastParams->resolutionParams.set_size
        (b_contrastParams.resolutionParams.size(0));
      loop_ub = b_contrastParams.resolutionParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->resolutionParams[i] =
          b_contrastParams.resolutionParams[i];
      }

      contrastParams->calculations = c_contrastParams.calculations;
      contrastParams->allSubRough.set_size(b_contrastParams.allSubRough.size(0));
      loop_ub = b_contrastParams.allSubRough.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->allSubRough[i] = b_contrastParams.allSubRough[i];
      }

      contrastParams->resample.set_size(1, b_contrastParams.resample.size(1));
      loop_ub = b_contrastParams.resample.size(1);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->resample[contrastParams->resample.size(0) * i] =
          b_contrastParams.resample[i];
      }

      bayesResults->bayesRes.allChains.set_size
        (bayesResults_bayesRes.allChains.size(0),
         bayesResults_bayesRes.allChains.size(1),
         bayesResults_bayesRes.allChains.size(2));
      loop_ub = bayesResults_bayesRes.allChains.size(2);
      for (i = 0; i < loop_ub; i++) {
        problemStruct_idx_0_tmp = bayesResults_bayesRes.allChains.size(1);
        for (i1 = 0; i1 < problemStruct_idx_0_tmp; i1++) {
          b_loop_ub = bayesResults_bayesRes.allChains.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            bayesResults->bayesRes.allChains[(i2 +
              bayesResults->bayesRes.allChains.size(0) * i1) +
              bayesResults->bayesRes.allChains.size(0) *
              bayesResults->bayesRes.allChains.size(1) * i] =
              bayesResults_bayesRes.allChains[(i2 +
              bayesResults_bayesRes.allChains.size(0) * i1) +
              bayesResults_bayesRes.allChains.size(0) *
              bayesResults_bayesRes.allChains.size(1) * i];
          }
        }
      }

      bayesResults->bayesRes.dreamOutput = b_bayesResults.bayesRes.dreamOutput;
      bayesResults->bayesRes.nestOutput.LogZ =
        b_bayesResults.bayesRes.nestOutput.LogZ;
      bayesResults->bayesRes.nestOutput.nestSamples.set_size(1, 2);
      bayesResults->bayesRes.nestOutput.postSamples.set_size(1, 2);
      bayesResults->bayesRes.nestOutput.nestSamples[0] =
        bayesResults_bayesRes.nestOutput.nestSamples.data[0];
      bayesResults->bayesRes.nestOutput.postSamples[0] =
        bayesResults_bayesRes.nestOutput.postSamples.data[0];
      bayesResults->bayesRes.nestOutput.nestSamples
        [bayesResults->bayesRes.nestOutput.nestSamples.size(0)] =
        bayesResults_bayesRes.nestOutput.nestSamples.data[1];
      bayesResults->bayesRes.nestOutput.postSamples
        [bayesResults->bayesRes.nestOutput.postSamples.size(0)] =
        bayesResults_bayesRes.nestOutput.postSamples.data[1];
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

      cast(problemStruct, &r);
      cast(problemCells, &r1);
      reflectivityCalculation(&r, &r1, controls, &c_contrastParams, resultCells);
      b_contrastParams.ssubs.set_size(c_contrastParams.ssubs.size(0));
      loop_ub = c_contrastParams.ssubs.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.ssubs[i] = c_contrastParams.ssubs[i];
      }

      b_contrastParams.backgroundParams.set_size
        (c_contrastParams.backgroundParams.size(0));
      loop_ub = c_contrastParams.backgroundParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.backgroundParams[i] =
          c_contrastParams.backgroundParams[i];
      }

      b_contrastParams.qzshifts.set_size(c_contrastParams.qzshifts.size(0));
      loop_ub = c_contrastParams.qzshifts.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.qzshifts[i] = c_contrastParams.qzshifts[i];
      }

      b_contrastParams.scalefactors.set_size(c_contrastParams.scalefactors.size
        (0));
      loop_ub = c_contrastParams.scalefactors.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.scalefactors[i] = c_contrastParams.scalefactors[i];
      }

      b_contrastParams.bulkIn.set_size(c_contrastParams.bulkIn.size(0));
      loop_ub = c_contrastParams.bulkIn.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.bulkIn[i] = c_contrastParams.bulkIn[i];
      }

      b_contrastParams.bulkOut.set_size(c_contrastParams.bulkOut.size(0));
      loop_ub = c_contrastParams.bulkOut.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.bulkOut[i] = c_contrastParams.bulkOut[i];
      }

      b_contrastParams.resolutionParams.set_size
        (c_contrastParams.resolutionParams.size(0));
      loop_ub = c_contrastParams.resolutionParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.resolutionParams[i] =
          c_contrastParams.resolutionParams[i];
      }

      b_contrastParams.allSubRough.set_size(c_contrastParams.allSubRough.size(0));
      loop_ub = c_contrastParams.allSubRough.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.allSubRough[i] = c_contrastParams.allSubRough[i];
      }

      b_contrastParams.resample.set_size(1, c_contrastParams.resample.size(1));
      loop_ub = c_contrastParams.resample.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_contrastParams.resample[i] = c_contrastParams.resample[i];
      }

      contrastParams->ssubs.set_size(b_contrastParams.ssubs.size(0));
      loop_ub = b_contrastParams.ssubs.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->ssubs[i] = b_contrastParams.ssubs[i];
      }

      contrastParams->backgroundParams.set_size
        (b_contrastParams.backgroundParams.size(0));
      loop_ub = b_contrastParams.backgroundParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->backgroundParams[i] =
          b_contrastParams.backgroundParams[i];
      }

      contrastParams->qzshifts.set_size(b_contrastParams.qzshifts.size(0));
      loop_ub = b_contrastParams.qzshifts.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->qzshifts[i] = b_contrastParams.qzshifts[i];
      }

      contrastParams->scalefactors.set_size(b_contrastParams.scalefactors.size(0));
      loop_ub = b_contrastParams.scalefactors.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->scalefactors[i] = b_contrastParams.scalefactors[i];
      }

      contrastParams->bulkIn.set_size(b_contrastParams.bulkIn.size(0));
      loop_ub = b_contrastParams.bulkIn.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->bulkIn[i] = b_contrastParams.bulkIn[i];
      }

      contrastParams->bulkOut.set_size(b_contrastParams.bulkOut.size(0));
      loop_ub = b_contrastParams.bulkOut.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->bulkOut[i] = b_contrastParams.bulkOut[i];
      }

      contrastParams->resolutionParams.set_size
        (b_contrastParams.resolutionParams.size(0));
      loop_ub = b_contrastParams.resolutionParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->resolutionParams[i] =
          b_contrastParams.resolutionParams[i];
      }

      contrastParams->calculations = c_contrastParams.calculations;
      contrastParams->allSubRough.set_size(b_contrastParams.allSubRough.size(0));
      loop_ub = b_contrastParams.allSubRough.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->allSubRough[i] = b_contrastParams.allSubRough[i];
      }

      contrastParams->resample.set_size(1, b_contrastParams.resample.size(1));
      loop_ub = b_contrastParams.resample.size(1);
      for (i = 0; i < loop_ub; i++) {
        contrastParams->resample[contrastParams->resample.size(0) * i] =
          b_contrastParams.resample[i];
      }
    }
  }
}

// End of code generation (RATMain.cpp)
