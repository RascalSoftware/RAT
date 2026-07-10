//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// alignALProfiles.h
//
// Code generation for function 'alignALProfiles'
//
#ifndef ALIGNALPROFILES_H
#define ALIGNALPROFILES_H

// Include files
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void alignALProfiles(const char geometry_data[], const int geometry_size[2],
                       const char modelType_data[], const int modelType_size[2],
                       ::coder::array<cell_wrap_7, 2U> &sldProfiles, ::coder::
                       array<cell_wrap_9, 2U> &resampledLayers);
}

#endif

// End of code generation (alignALProfiles.h)
