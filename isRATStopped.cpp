//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
  int isRATStopped(const char IPCFilePath_data[], const int IPCFilePath_size[2],
                   boolean_T state_data[])
  {
    int state_size;
    unsigned char tmp_data;

    //  Checks if the stop event was set via the IPC file. The expected input
    //  is the path to the inter-process communication file
    //
    //  stopped = isRATStopped(filePath);
    if (IPCFilePath_size[1] == 0) {
      state_size = 1;
      state_data[0] = false;
    } else {
      int fileID;
      int tmp_size;
      if (coder::internal::bb_strcmp(IPCFilePath_data, IPCFilePath_size)) {
        fileID = 0;
      } else {
        signed char fileid;
        fileid = coder::internal::cfopen(IPCFilePath_data, IPCFilePath_size);
        fileID = fileid;
      }

      tmp_size = coder::b_fread(static_cast<double>(fileID), (unsigned char *)
        &tmp_data);
      state_size = tmp_size;
      if (tmp_size - 1 >= 0) {
        state_data[0] = (tmp_data != 0);
      }

      coder::internal::cfclose(static_cast<double>(fileID));
    }

    return state_size;
  }
}

// End of code generation (isRATStopped.cpp)
