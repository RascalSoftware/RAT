//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// fileManager.cpp
//
// Code generation for function 'fileManager'
//

// Include files
#include "fileManager.h"
#include "RATMain_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstdio>

// Variable Definitions
namespace RAT
{
  static std::FILE *eml_openfiles[20];
}

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      static std::FILE *fileManager(signed char varargin_1);
      static signed char filedata();
    }
  }
}

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      static std::FILE *fileManager(signed char varargin_1)
      {
        std::FILE *f;
        signed char fileid;
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
          f = nullptr;
        }

        return f;
      }

      static signed char filedata()
      {
        int k;
        signed char f;
        boolean_T exitg1;
        f = 0;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < 20)) {
          if (eml_openfiles[k] == nullptr) {
            f = static_cast<signed char>(k + 1);
            exitg1 = true;
          } else {
            k++;
          }
        }

        return f;
      }

      int cfclose(double fid)
      {
        std::FILE *filestar;
        int st;
        signed char fileid;
        st = -1;
        fileid = static_cast<signed char>(fid);
        if ((static_cast<signed char>(fid) < 0) || (fid != static_cast<signed
             char>(fid))) {
          fileid = -1;
        }

        filestar = fileManager(fileid);
        if ((filestar != nullptr) && (fileid >= 3)) {
          int cst;
          cst = std::fclose(filestar);
          if (cst == 0) {
            st = 0;
            eml_openfiles[fileid - 3] = nullptr;
          }
        }

        return st;
      }

      signed char cfopen(const char cfilename_data[], const int cfilename_size[2])
      {
        std::FILE *filestar;
        ::coder::array<char, 2U> ccfilename;
        signed char fileid;
        signed char j;
        fileid = -1;
        j = filedata();
        if (j >= 1) {
          int i;
          int loop_ub;
          ccfilename.set_size(1, cfilename_size[1] + 1);
          loop_ub = cfilename_size[1];
          for (i = 0; i < loop_ub; i++) {
            ccfilename[i] = cfilename_data[i];
          }

          ccfilename[cfilename_size[1]] = '\x00';
          filestar = std::fopen(&ccfilename[0], "rb");
          if (filestar != nullptr) {
            eml_openfiles[j - 1] = filestar;
            i = j + 2;
            if (j + 2 > 127) {
              i = 127;
            }

            fileid = static_cast<signed char>(i);
          }
        }

        return fileid;
      }

      std::FILE *fileManager(double varargin_1)
      {
        std::FILE *f;
        signed char fileid;
        fileid = static_cast<signed char>(varargin_1);
        if ((static_cast<signed char>(varargin_1) < 0) || (varargin_1 !=
             static_cast<signed char>(varargin_1))) {
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
          f = nullptr;
        }

        return f;
      }
    }
  }

  void filedata_init()
  {
    for (int i{0}; i < 20; i++) {
      eml_openfiles[i] = nullptr;
    }
  }
}

// End of code generation (fileManager.cpp)
