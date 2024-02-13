//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// fileManager.cpp
//
// Code generation for function 'fileManager'
//

// Include files
#include "fileManager.h"
#include "rt_nonfinite.h"
#include <stdio.h>

// Variable Definitions
namespace RAT
{
  static FILE * eml_openfiles[20];
}

// Function Definitions
namespace RAT
{
  namespace coder
  {
    int32_T fileManager()
    {
      int32_T f;
      f = 0;
      for (int32_T j{0}; j < 20; j++) {
        if (eml_openfiles[j] != NULL) {
          int32_T cst;
          cst = fclose(eml_openfiles[j]);
          if (cst == 0) {
            eml_openfiles[j] = NULL;
          } else {
            f = -1;
          }
        }
      }

      return f;
    }
  }

  void filedata_init()
  {
    FILE * a;
    a = NULL;
    for (int32_T i{0}; i < 20; i++) {
      eml_openfiles[i] = a;
    }
  }
}

// End of code generation (fileManager.cpp)
