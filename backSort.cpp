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
  double backSort(double scalefactorIndex, double bulkInIndex, double
                  bulkOutIndex, const ::coder::array<double, 2U>
                  &scalefactorValues, const ::coder::array<double, 2U>
                  &bulkInValues, const ::coder::array<double, 2U> &bulkOutValues,
                  double &scalefactor, double &bulkIn, double &bulkOut)
  {
    double qzshift;

    //  Distributes the background and shift values among the different contrasts
    //
    //  INPUTS:
    //     * qzshiftIndex: Index of the qzshift value associated with this contrast
    //     * scalefactorIndex: Index of the scalefactor value  associated with this contrast
    //     * bulkInIndex: Index of the BulkIn value associated with this contrast
    //     * bulkOutIndex: Index of the BulkOut value associated with this contrast
    //     * qzshiftValues: List of all qzshift values
    //     * scalefactorValues: List of all scalefactor values
    //     * bulkInValues: List of all bulk In values
    //     * bulkOutValues: List of all bulk Out values
    //
    //  OUTPUTS:
    //     * qzshift: qzshift value for this contrast
    //     * scalefactor: scalefactor value for this contrast
    //     * bulkIn: bulk In value for this contrast
    //     * bulkOut: bulk Out value for this contrast
    qzshift = 0.0;
    scalefactor = scalefactorValues[static_cast<int>(scalefactorIndex) - 1];
    bulkIn = bulkInValues[static_cast<int>(bulkInIndex) - 1];
    bulkOut = bulkOutValues[static_cast<int>(bulkOutIndex) - 1];
    return qzshift;
  }
}

// End of code generation (backSort.cpp)
