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
#include <algorithm>
#include <cmath>
#include <stdio.h>

// Variable Definitions
namespace RAT
{
  static FILE * eml_openfiles[20];
  static boolean_T eml_autoflush[20];
}

// Function Declarations
namespace RAT
{
  namespace coder
  {
    static FILE * fileManager(int8_T varargin_1);
    static int8_T filedata();
  }
}

// Function Definitions
namespace RAT
{
  namespace coder
  {
    static FILE * fileManager(int8_T varargin_1)
    {
      FILE * f;
      int8_T fileid;
      fileid = varargin_1;
      if (varargin_1 < 0) {
        fileid = -1;
      }

      if (fileid >= 3) {
        f = eml_openfiles[fileid - 3];
      } else if (fileid == 0) {
        f = stdin;
      } else if (fileid == 1) {
        f = stdout;
      } else if (fileid == 2) {
        f = stderr;
      } else {
        f = NULL;
      }

      return f;
    }

    static int8_T filedata()
    {
      int32_T k;
      int8_T f;
      boolean_T exitg1;
      f = 0;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 20)) {
        if (eml_openfiles[k] == NULL) {
          f = static_cast<int8_T>(k + 1);
          exitg1 = true;
        } else {
          k++;
        }
      }

      return f;
    }

    int32_T cfclose(real_T fid)
    {
      FILE * filestar;
      int32_T st;
      int8_T fileid;
      st = -1;
      fileid = static_cast<int8_T>(std::round(fid));
      if ((fileid < 0) || (fid != fileid)) {
        fileid = -1;
      }

      filestar = fileManager(fileid);
      if ((filestar != NULL) && (fileid >= 3)) {
        int32_T cst;
        cst = fclose(filestar);
        if (cst == 0) {
          st = 0;
          eml_openfiles[fileid - 3] = NULL;
          eml_autoflush[fileid - 3] = true;
        }
      }

      return st;
    }

    int8_T cfopen(const char_T cfilename_data[], const int32_T cfilename_size[2],
                  const char_T *cpermission)
    {
      char_T ccfilename_data[10001];
      int8_T fileid;
      int8_T j;
      fileid = -1;
      j = filedata();
      if (j >= 1) {
        FILE * filestar;
        int32_T loop_ub;
        loop_ub = cfilename_size[1];
        if (0 <= loop_ub - 1) {
          std::copy(&cfilename_data[0], &cfilename_data[loop_ub],
                    &ccfilename_data[0]);
        }

        ccfilename_data[cfilename_size[1]] = '\x00';
        filestar = fopen(&ccfilename_data[0], cpermission);
        if (filestar != NULL) {
          eml_openfiles[j - 1] = filestar;
          eml_autoflush[j - 1] = true;
          loop_ub = j + 2;
          if (j + 2 > 127) {
            loop_ub = 127;
          }

          fileid = static_cast<int8_T>(loop_ub);
        }
      }

      return fileid;
    }

    FILE * fileManager(real_T varargin_1)
    {
      FILE * f;
      int8_T fileid;
      fileid = static_cast<int8_T>(std::round(varargin_1));
      if ((fileid < 0) || (varargin_1 != fileid)) {
        fileid = -1;
      }

      if (fileid >= 3) {
        f = eml_openfiles[fileid - 3];
      } else if (fileid == 0) {
        f = stdin;
      } else if (fileid == 1) {
        f = stdout;
      } else if (fileid == 2) {
        f = stderr;
      } else {
        f = NULL;
      }

      return f;
    }
  }

  void filedata_init()
  {
    FILE * a;
    a = NULL;
    for (int32_T i{0}; i < 20; i++) {
      eml_autoflush[i] = false;
      eml_openfiles[i] = a;
    }
  }
}

// End of code generation (fileManager.cpp)
