//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// isRATStopped.cpp
//
// Code generation for function 'isRATStopped'
//

// Include files
#include "isRATStopped.h"
#include "fileManager.h"
#include "fread.h"
#include "rt_nonfinite.h"
#include "strcmp.h"

// Function Definitions
namespace RAT
{
  void isRATStopped(const char_T IPCFilePath_data[], const int32_T
                    IPCFilePath_size[2], boolean_T state_data[], int32_T
                    *state_size)
  {
    int32_T tmp_size;
    uint8_T tmp_data;

    //  Checks if the stop event was set via the IPC file. The expected input
    //  is the path to the inter-process communication file
    //
    //  stopped = isRATStopped(filePath);
    if (IPCFilePath_size[1] == 0) {
      *state_size = 1;
      state_data[0] = false;
    } else {
      int32_T fileID;
      if (coder::internal::y_strcmp(IPCFilePath_data, IPCFilePath_size)) {
        fileID = 0;
      } else {
        int8_T fileid;
        fileid = coder::cfopen(IPCFilePath_data, IPCFilePath_size, "rb");
        fileID = fileid;
      }

      coder::b_fread(static_cast<real_T>(fileID), (uint8_T *)&tmp_data,
                     &tmp_size);
      *state_size = tmp_size;
      if (0 <= tmp_size - 1) {
        state_data[0] = (tmp_data != 0);
      }

      coder::cfclose(static_cast<real_T>(fileID));
    }
  }
}

// End of code generation (isRATStopped.cpp)
