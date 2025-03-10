//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// coderFread.cpp
//
// Code generation for function 'coderFread'
//

// Include files
#include "coderFread.h"
#include "RATMain_data.h"
#include "fileManager.h"
#include "fread.h"
#include "rt_nonfinite.h"
#include <cstdio>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      std::FILE *getFileStar(double fileID)
      {
        std::FILE *filestar;
        filestar = fileManager(fileID);
        if (!isImplementedFilestar(fileID)) {
          filestar = nullptr;
        }

        return filestar;
      }
    }
  }
}

// End of code generation (coderFread.cpp)
