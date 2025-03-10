//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
  double backSort(double contrastScalefactors, double contrastBulkIns, double
                  contrastBulkOuts, const ::coder::array<double, 2U>
                  &scalefactors, const ::coder::array<double, 2U> &bulkIn, const
                  ::coder::array<double, 2U> &bulkOut, double &outScalefactor,
                  double &outBulkIn, double &outBulkOut)
  {
    double outQzshift;

    //  Distributes the background and shift values among the different contrasts
    //
    //  INPUTS:
    //     * contrastQzshifts: Which qz_shift value is associated with each contrast
    //     * contrastScalefactors: Which scalefactor value is associated with each contrast
    //     * contrastBulkIns: Which BulkIn value is associated with each contrast
    //     * contrastBulkOuts: Which BulkOut value is associated with each contrast
    //     * qzshifts: List of all qzshift values
    //     * scalefactors: List of all scalefactor values
    //     * bulkIn: List of all bulkIn values
    //     * bulkOut: List of all bulkOut values
    //
    //  OUTPUTS:
    //     * outQzshift: list of actual qzshift values for each contrast
    //     * outScalefactor: list of actual scalefactor values for each contrast
    //     * outBulkIn: list of actual bulkIn values for each contrast
    //     * outBulkOut: list of actual bulkOut values for each contrast
    outQzshift = 0.0;
    outScalefactor = scalefactors[static_cast<int>(contrastScalefactors) - 1];
    outBulkIn = bulkIn[static_cast<int>(contrastBulkIns) - 1];
    outBulkOut = bulkOut[static_cast<int>(contrastBulkOuts) - 1];
    return outQzshift;
  }
}

// End of code generation (backSort.cpp)
