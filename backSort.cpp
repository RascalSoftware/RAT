//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// backSort.cpp
//
// Code generation for function 'backSort'
//

// Include files
#include "backSort.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void backSort(real_T contrastBackgroundParams, real_T contrastQzshifts, real_T
                contrastScalefactors, real_T contrastBulkIns, real_T
                contrastBulkOuts, real_T contrastResolutionParams, const ::coder::
                array<real_T, 2U> &backgroundParams, const ::coder::array<real_T,
                2U> &qzshifts, const ::coder::array<real_T, 2U> &scalefactors,
                const ::coder::array<real_T, 2U> &bulkIn, const ::coder::array<
                real_T, 2U> &bulkOut, const ::coder::array<real_T, 2U>
                &resolutionParams, real_T *outBackgroundParam, real_T
                *outQzshift, real_T *outScalefactor, real_T *outBulkIn, real_T
                *outBulkOut, real_T *outResolutionParam)
  {
    //  Distributes the background and shift values among the different contrasts
    //
    //  USAGE::
    //
    //     [backgroundParams,qzshift,scalefactor,bulkIn,bulkOut,resolutionParams] = backsort(contrastBackgrounds,contrastQzshifts,contrastScalefactors,contrastBulkIns,contrastBulkOuts,contrastResolutions,backs,qzshifts,scalefactor,bulkIn,bulkOut,res)
    //
    //  INPUTS:
    //     * contrastBackgroundParams: Which background value is associated with each contrast
    //     * contrastQzshifts: Which qz_shift value is associated with each contrast
    //     * contrastScalefactors: Which scalefactor value is associated with each contrast
    //     * contrastBulkIns: Which BulkIn value is associated with each contrast
    //     * contrastBulkOuts: Which BulkOut value is associated with each contrast
    //     * contrastResolutionParams: Which resolution value is associated with each contrast
    //     * backgroundParams: List of all background parameter values.
    //     * qzshifts: List of all qzshift values
    //     * scalefactors: List of all scalefactor values
    //     * bulkIn: List of all bulkIn values
    //     * bulkOut: List of all bulkOut values
    //     * resolutionParams: List of all resolution parameter values
    //
    //  OUTPUTS:
    //     * outBackground: list of actual background parameter values for each contrast
    //     * outQzshift: list of actual qzshift values for each contrast
    //     * outScalefactor: list of actual scalefactor values for each contrast
    //     * outBulkIn: list of actual bulkIn values for each contrast
    //     * outBulkOut: list of actual bulkOut values for each contrast
    //     * outResolution: list of actual resolution parameter for each contrast
    if (contrastBackgroundParams != -1.0) {
      *outBackgroundParam = backgroundParams[static_cast<int32_T>
        (contrastBackgroundParams) - 1];
    } else {
      *outBackgroundParam = -1.0;

      //  Negative value means we have a data background.
    }

    *outQzshift = qzshifts[static_cast<int32_T>(contrastQzshifts) - 1];
    *outScalefactor = scalefactors[static_cast<int32_T>(contrastScalefactors) -
      1];
    *outBulkIn = bulkIn[static_cast<int32_T>(contrastBulkIns) - 1];
    *outBulkOut = bulkOut[static_cast<int32_T>(contrastBulkOuts) - 1];
    if (contrastResolutionParams != -1.0) {
      *outResolutionParam = resolutionParams[static_cast<int32_T>
        (contrastResolutionParams) - 1];
    } else {
      *outResolutionParam = -1.0;

      //  Negative value means we have a data resolution.
    }
  }
}

// End of code generation (backSort.cpp)
