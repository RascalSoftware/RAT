//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// fread.cpp
//
// Code generation for function 'fread'
//

// Include files
#include "fread.h"
#include "RATMain_data.h"
#include "coderFread.h"
#include "rt_nonfinite.h"
#include <cstddef>
#include <cstdio>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    int b_fread(double fileID, unsigned char A_data[])
    {
      std::FILE *filestar;
      int A_size;
      filestar = internal::getFileStar(fileID);
      if (filestar == nullptr) {
        A_size = 0;
      } else {
        size_t numReadSizeT;
        A_size = 1;
        numReadSizeT = std::fread(&A_data[0], sizeof(unsigned char), (size_t)1,
          filestar);
        if ((int)numReadSizeT + 1 <= 1) {
          A_data[0] = 0U;
        }

        if ((int)numReadSizeT < 1) {
          A_size = 0;
        }
      }

      return A_size;
    }

    boolean_T isImplementedFilestar(double fileID)
    {
      boolean_T p;
      if ((fileID != 0.0) && (fileID != 1.0) && (fileID != 2.0)) {
        p = true;
      } else {
        p = false;
      }

      return p;
    }
  }
}

// End of code generation (fread.cpp)
