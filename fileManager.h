//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// fileManager.h
//
// Code generation for function 'fileManager'
//
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdio>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      int cfclose(double fid);
      signed char cfopen(const char cfilename_data[], const int cfilename_size[2]);
      std::FILE *fileManager(double varargin_1);
    }
  }

  void filedata_init();
}

#endif

// End of code generation (fileManager.h)
