//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// fread.cpp
//
// Code generation for function 'fread'
//

// Include files
#include "fread.h"
#include "fileManager.h"
#include "rt_nonfinite.h"
#include <cstddef>
#include <stdio.h>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    static FILE * getFileStar(real_T fileID);
    static boolean_T isImplementedFilestar(real_T fileID);
  }
}

// Function Definitions
namespace RAT
{
  namespace coder
  {
    static FILE * getFileStar(real_T fileID)
    {
      FILE * filestar;
      filestar = fileManager(fileID);
      if (!isImplementedFilestar(fileID)) {
        filestar = NULL;
      }

      return filestar;
    }

    static boolean_T isImplementedFilestar(real_T fileID)
    {
      boolean_T p;
      if ((fileID != 0.0) && (fileID != 1.0) && (fileID != 2.0)) {
        p = true;
      } else {
        p = false;
      }

      return p;
    }

    void b_fread(real_T fileID, uint8_T A_data[], int32_T *A_size)
    {
      FILE * filestar;
      uint8_T b_A_data;
      filestar = getFileStar(fileID);
      if (filestar == NULL) {
        *A_size = 0;
      } else {
        size_t numReadSizeT;
        numReadSizeT = fread(&b_A_data, sizeof(uint8_T), 1, filestar);
        if ((int32_T)numReadSizeT + 1 <= 1) {
          b_A_data = 0U;
        }

        *A_size = 1;
        A_data[0] = b_A_data;
        if ((int32_T)numReadSizeT < 1) {
          *A_size = 0;
        }
      }
    }
  }
}

// End of code generation (fread.cpp)
