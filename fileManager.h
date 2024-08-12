//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// fileManager.h
//
// Code generation for function 'fileManager'
//
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

// Include files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>
#include <stdio.h>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    int32_T cfclose(real_T fid);
    int8_T cfopen(const char_T cfilename_data[], const int32_T cfilename_size[2],
                  const char_T *cpermission);
    FILE * fileManager(real_T varargin_1);
  }

  void filedata_init();
}

#endif

// End of code generation (fileManager.h)
