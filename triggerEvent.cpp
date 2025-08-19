//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// triggerEvent.cpp
//
// Code generation for function 'triggerEvent'
//

// Include files
#include "triggerEvent.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "getenv.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "strjoin.h"
#include "strlength.h"
#include "coder_array.h"
#include "eventHelper.hpp"
#include <algorithm>
#include <cstdio>

// Variable Definitions
namespace RAT
{
  static boolean_T notified;
  static boolean_T notified_not_empty;
  static eventHelper helper;
  static boolean_T helper_not_empty;
}

// Function Declarations
namespace RAT
{
  static void b_packCellArray(const ::coder::array<cell_wrap_7, 2U> &cellArray, ::
    coder::array<double, 1U> &packedArray, ::coder::array<double, 1U> &dims);
  static void b_packCellArray(const ::coder::array<cell_wrap_9, 2U> &cellArray, ::
    coder::array<double, 1U> &packedArray, ::coder::array<double, 1U> &dims);
  static void packCellArray(const ::coder::array<cell_wrap_7, 1U> &cellArray, ::
    coder::array<double, 1U> &packedArray, ::coder::array<double, 1U> &dims);
  static void packCellArray(const ::coder::array<cell_wrap_8, 1U> &cellArray, ::
    coder::array<double, 1U> &packedArray, ::coder::array<double, 1U> &dims);
  static void packCellArray(const ::coder::array<cell_wrap_7, 2U> &cellArray, ::
    coder::array<double, 1U> &packedArray, ::coder::array<double, 1U> &dims);
  static void packCellArray(const ::coder::array<cell_wrap_9, 2U> &cellArray, ::
    coder::array<double, 1U> &packedArray, ::coder::array<double, 1U> &dims);
}

// Function Definitions
namespace RAT
{
  static void b_packCellArray(const ::coder::array<cell_wrap_9, 2U> &cellArray, ::
    coder::array<double, 1U> &packedArray, ::coder::array<double, 1U> &dims)
  {
    double rowSize;
    double start;
    int b_cellArray;
    unsigned int b_index;
    int i;

    //  Packs a specified column of a cell array with different sized arrays into a
    //  single row array and an array of the dimensions for each cell. For the example
    //  below packedArray will be [1, 2, 3, 4, 5, 6, 7] and dims will be [3, 1, 4, 1]
    //
    //  [packedArray, dims] = packCellArray({[1; 2; 3], [4; 5; 6; 7]}, 1);
    rowSize = 0.0;
    b_cellArray = cellArray.size(0) * 2;
    dims.set_size(b_cellArray);
    for (i = 0; i < b_cellArray; i++) {
      dims[i] = 0.0;
    }

    i = cellArray.size(0);
    for (int b_i{0}; b_i < i; b_i++) {
      b_index = (static_cast<unsigned int>(b_i + 1) << 1) + MAX_uint32_T;
      dims[static_cast<int>(b_index) - 1] = cellArray[b_i + cellArray.size(0)].
        f1.size(0);
      dims[static_cast<int>(b_index)] = cellArray[b_i + cellArray.size(0)].
        f1.size(1);
      rowSize += static_cast<double>(cellArray[b_i + cellArray.size(0)].f1.size
        (0)) * static_cast<double>(cellArray[b_i + cellArray.size(0)].f1.size(1));
    }

    start = 1.0;
    b_cellArray = static_cast<int>(rowSize);
    packedArray.set_size(b_cellArray);
    for (i = 0; i < b_cellArray; i++) {
      packedArray[i] = 0.0;
    }

    i = cellArray.size(0);
    for (int b_i{0}; b_i < i; b_i++) {
      double stop;
      int i1;
      int i2;
      b_index = (static_cast<unsigned int>(b_i + 1) << 1) - 1U;
      stop = start + dims[static_cast<int>(b_index) - 1] * dims[static_cast<int>
        (static_cast<double>(b_index) + 1.0) - 1];
      if (start > stop - 1.0) {
        i1 = 0;
        i2 = 0;
      } else {
        i1 = static_cast<int>(start) - 1;
        i2 = static_cast<int>(stop - 1.0);
      }

      b_cellArray = i2 - i1;
      for (i2 = 0; i2 < b_cellArray; i2++) {
        packedArray[i1 + i2] = cellArray[b_i + cellArray.size(0)].f1[i2];
      }

      start = stop;
    }
  }

  static void b_packCellArray(const ::coder::array<cell_wrap_7, 2U> &cellArray, ::
    coder::array<double, 1U> &packedArray, ::coder::array<double, 1U> &dims)
  {
    double rowSize;
    double start;
    int b_cellArray;
    unsigned int b_index;
    int i;

    //  Packs a specified column of a cell array with different sized arrays into a
    //  single row array and an array of the dimensions for each cell. For the example
    //  below packedArray will be [1, 2, 3, 4, 5, 6, 7] and dims will be [3, 1, 4, 1]
    //
    //  [packedArray, dims] = packCellArray({[1; 2; 3], [4; 5; 6; 7]}, 1);
    rowSize = 0.0;
    b_cellArray = cellArray.size(0) * 2;
    dims.set_size(b_cellArray);
    for (i = 0; i < b_cellArray; i++) {
      dims[i] = 0.0;
    }

    i = cellArray.size(0);
    for (int b_i{0}; b_i < i; b_i++) {
      b_index = (static_cast<unsigned int>(b_i + 1) << 1) + MAX_uint32_T;
      dims[static_cast<int>(b_index) - 1] = cellArray[b_i + cellArray.size(0)].
        f1.size(0);
      dims[static_cast<int>(b_index)] = 2.0;
      rowSize += static_cast<double>(cellArray[b_i + cellArray.size(0)].f1.size
        (0)) * 2.0;
    }

    start = 1.0;
    b_cellArray = static_cast<int>(rowSize);
    packedArray.set_size(b_cellArray);
    for (i = 0; i < b_cellArray; i++) {
      packedArray[i] = 0.0;
    }

    i = cellArray.size(0);
    for (int b_i{0}; b_i < i; b_i++) {
      double stop;
      int i1;
      int i2;
      b_index = (static_cast<unsigned int>(b_i + 1) << 1) - 1U;
      stop = start + dims[static_cast<int>(b_index) - 1] * dims[static_cast<int>
        (static_cast<double>(b_index) + 1.0) - 1];
      if (start > stop - 1.0) {
        i1 = 0;
        i2 = 0;
      } else {
        i1 = static_cast<int>(start) - 1;
        i2 = static_cast<int>(stop - 1.0);
      }

      b_cellArray = i2 - i1;
      for (i2 = 0; i2 < b_cellArray; i2++) {
        packedArray[i1 + i2] = cellArray[b_i + cellArray.size(0)].f1[i2];
      }

      start = stop;
    }
  }

  static void packCellArray(const ::coder::array<cell_wrap_7, 1U> &cellArray, ::
    coder::array<double, 1U> &packedArray, ::coder::array<double, 1U> &dims)
  {
    double rowSize;
    double start;
    int b_cellArray;
    unsigned int b_index;
    int i;

    //  Packs a specified column of a cell array with different sized arrays into a
    //  single row array and an array of the dimensions for each cell. For the example
    //  below packedArray will be [1, 2, 3, 4, 5, 6, 7] and dims will be [3, 1, 4, 1]
    //
    //  [packedArray, dims] = packCellArray({[1; 2; 3], [4; 5; 6; 7]}, 1);
    rowSize = 0.0;
    b_cellArray = cellArray.size(0) * 2;
    dims.set_size(b_cellArray);
    for (i = 0; i < b_cellArray; i++) {
      dims[i] = 0.0;
    }

    i = cellArray.size(0);
    for (int b_i{0}; b_i < i; b_i++) {
      b_index = (static_cast<unsigned int>(b_i + 1) << 1) + MAX_uint32_T;
      dims[static_cast<int>(b_index) - 1] = cellArray[b_i].f1.size(0);
      dims[static_cast<int>(b_index)] = 2.0;
      rowSize += static_cast<double>(cellArray[b_i].f1.size(0)) * 2.0;
    }

    start = 1.0;
    b_cellArray = static_cast<int>(rowSize);
    packedArray.set_size(b_cellArray);
    for (i = 0; i < b_cellArray; i++) {
      packedArray[i] = 0.0;
    }

    i = cellArray.size(0);
    for (int b_i{0}; b_i < i; b_i++) {
      double stop;
      int i1;
      int i2;
      b_index = (static_cast<unsigned int>(b_i + 1) << 1) - 1U;
      stop = start + dims[static_cast<int>(b_index) - 1] * dims[static_cast<int>
        (static_cast<double>(b_index) + 1.0) - 1];
      if (start > stop - 1.0) {
        i1 = 0;
        i2 = 0;
      } else {
        i1 = static_cast<int>(start) - 1;
        i2 = static_cast<int>(stop - 1.0);
      }

      b_cellArray = i2 - i1;
      for (i2 = 0; i2 < b_cellArray; i2++) {
        packedArray[i1 + i2] = cellArray[b_i].f1[i2];
      }

      start = stop;
    }
  }

  static void packCellArray(const ::coder::array<cell_wrap_8, 1U> &cellArray, ::
    coder::array<double, 1U> &packedArray, ::coder::array<double, 1U> &dims)
  {
    double rowSize;
    double start;
    int b_cellArray;
    unsigned int b_index;
    int i;

    //  Packs a specified column of a cell array with different sized arrays into a
    //  single row array and an array of the dimensions for each cell. For the example
    //  below packedArray will be [1, 2, 3, 4, 5, 6, 7] and dims will be [3, 1, 4, 1]
    //
    //  [packedArray, dims] = packCellArray({[1; 2; 3], [4; 5; 6; 7]}, 1);
    rowSize = 0.0;
    b_cellArray = cellArray.size(0) * 2;
    dims.set_size(b_cellArray);
    for (i = 0; i < b_cellArray; i++) {
      dims[i] = 0.0;
    }

    i = cellArray.size(0);
    for (int b_i{0}; b_i < i; b_i++) {
      b_index = (static_cast<unsigned int>(b_i + 1) << 1) + MAX_uint32_T;
      dims[static_cast<int>(b_index) - 1] = cellArray[b_i].f1.size(0);
      dims[static_cast<int>(b_index)] = 3.0;
      rowSize += static_cast<double>(cellArray[b_i].f1.size(0)) * 3.0;
    }

    start = 1.0;
    b_cellArray = static_cast<int>(rowSize);
    packedArray.set_size(b_cellArray);
    for (i = 0; i < b_cellArray; i++) {
      packedArray[i] = 0.0;
    }

    i = cellArray.size(0);
    for (int b_i{0}; b_i < i; b_i++) {
      double stop;
      int i1;
      int i2;
      b_index = (static_cast<unsigned int>(b_i + 1) << 1) - 1U;
      stop = start + dims[static_cast<int>(b_index) - 1] * dims[static_cast<int>
        (static_cast<double>(b_index) + 1.0) - 1];
      if (start > stop - 1.0) {
        i1 = 0;
        i2 = 0;
      } else {
        i1 = static_cast<int>(start) - 1;
        i2 = static_cast<int>(stop - 1.0);
      }

      b_cellArray = i2 - i1;
      for (i2 = 0; i2 < b_cellArray; i2++) {
        packedArray[i1 + i2] = cellArray[b_i].f1[i2];
      }

      start = stop;
    }
  }

  static void packCellArray(const ::coder::array<cell_wrap_7, 2U> &cellArray, ::
    coder::array<double, 1U> &packedArray, ::coder::array<double, 1U> &dims)
  {
    double rowSize;
    double start;
    int b_cellArray;
    unsigned int b_index;
    int i;

    //  Packs a specified column of a cell array with different sized arrays into a
    //  single row array and an array of the dimensions for each cell. For the example
    //  below packedArray will be [1, 2, 3, 4, 5, 6, 7] and dims will be [3, 1, 4, 1]
    //
    //  [packedArray, dims] = packCellArray({[1; 2; 3], [4; 5; 6; 7]}, 1);
    rowSize = 0.0;
    b_cellArray = cellArray.size(0) * 2;
    dims.set_size(b_cellArray);
    for (i = 0; i < b_cellArray; i++) {
      dims[i] = 0.0;
    }

    i = cellArray.size(0);
    for (int b_i{0}; b_i < i; b_i++) {
      b_index = (static_cast<unsigned int>(b_i + 1) << 1) + MAX_uint32_T;
      dims[static_cast<int>(b_index) - 1] = cellArray[b_i].f1.size(0);
      dims[static_cast<int>(b_index)] = 2.0;
      rowSize += static_cast<double>(cellArray[b_i].f1.size(0)) * 2.0;
    }

    start = 1.0;
    b_cellArray = static_cast<int>(rowSize);
    packedArray.set_size(b_cellArray);
    for (i = 0; i < b_cellArray; i++) {
      packedArray[i] = 0.0;
    }

    i = cellArray.size(0);
    for (int b_i{0}; b_i < i; b_i++) {
      double stop;
      int i1;
      int i2;
      b_index = (static_cast<unsigned int>(b_i + 1) << 1) - 1U;
      stop = start + dims[static_cast<int>(b_index) - 1] * dims[static_cast<int>
        (static_cast<double>(b_index) + 1.0) - 1];
      if (start > stop - 1.0) {
        i1 = 0;
        i2 = 0;
      } else {
        i1 = static_cast<int>(start) - 1;
        i2 = static_cast<int>(stop - 1.0);
      }

      b_cellArray = i2 - i1;
      for (i2 = 0; i2 < b_cellArray; i2++) {
        packedArray[i1 + i2] = cellArray[b_i].f1[i2];
      }

      start = stop;
    }
  }

  static void packCellArray(const ::coder::array<cell_wrap_9, 2U> &cellArray, ::
    coder::array<double, 1U> &packedArray, ::coder::array<double, 1U> &dims)
  {
    double rowSize;
    double start;
    int b_cellArray;
    unsigned int b_index;
    int i;

    //  Packs a specified column of a cell array with different sized arrays into a
    //  single row array and an array of the dimensions for each cell. For the example
    //  below packedArray will be [1, 2, 3, 4, 5, 6, 7] and dims will be [3, 1, 4, 1]
    //
    //  [packedArray, dims] = packCellArray({[1; 2; 3], [4; 5; 6; 7]}, 1);
    rowSize = 0.0;
    b_cellArray = cellArray.size(0) * 2;
    dims.set_size(b_cellArray);
    for (i = 0; i < b_cellArray; i++) {
      dims[i] = 0.0;
    }

    i = cellArray.size(0);
    for (int b_i{0}; b_i < i; b_i++) {
      b_index = (static_cast<unsigned int>(b_i + 1) << 1) + MAX_uint32_T;
      dims[static_cast<int>(b_index) - 1] = cellArray[b_i].f1.size(0);
      dims[static_cast<int>(b_index)] = cellArray[b_i].f1.size(1);
      rowSize += static_cast<double>(cellArray[b_i].f1.size(0)) * static_cast<
        double>(cellArray[b_i].f1.size(1));
    }

    start = 1.0;
    b_cellArray = static_cast<int>(rowSize);
    packedArray.set_size(b_cellArray);
    for (i = 0; i < b_cellArray; i++) {
      packedArray[i] = 0.0;
    }

    i = cellArray.size(0);
    for (int b_i{0}; b_i < i; b_i++) {
      double stop;
      int i1;
      int i2;
      b_index = (static_cast<unsigned int>(b_i + 1) << 1) - 1U;
      stop = start + dims[static_cast<int>(b_index) - 1] * dims[static_cast<int>
        (static_cast<double>(b_index) + 1.0) - 1];
      if (start > stop - 1.0) {
        i1 = 0;
        i2 = 0;
      } else {
        i1 = static_cast<int>(start) - 1;
        i2 = static_cast<int>(stop - 1.0);
      }

      b_cellArray = i2 - i1;
      for (i2 = 0; i2 < b_cellArray; i2++) {
        packedArray[i1 + i2] = cellArray[b_i].f1[i2];
      }

      start = stop;
    }
  }

  void b_triggerEvent(double varargin_2)
  {
    static const char b_cv1[8]{ "DREAM: " };

    ::coder::array<char, 2U> path;
    ::coder::array<char, 2U> r;
    boolean_T initialised;

    //  Triggers the event type with the given varargin. The supported event types are
    //  0, 1, and 2.
    //  * The input for the message event is a char array,
    //  * The inputs for the plot event are the result struct, problem struct and cell
    //  * The inputs for progress events are the message (char array) and
    //    percentage progress expressed as a decimal (i.e., between 0 and 1).
    //
    //  triggerEvent(coderEnums.eventTypes.Message, 'Hello world');
    //  triggerEvent(coderEnums.eventTypes.Plot, result, problemStruct);
    //  triggerEvent(coderEnums.eventTypes.Progress, 'Hello world', 0.5);
    if (!helper_not_empty) {
      int loop_ub;

      //  Declaration for coder
      helper_not_empty = true;

      //  Make an instance
      helper = eventHelper();
      coder::b_getenv(r);
      path.set_size(1, r.size(1) + 1);
      loop_ub = r.size(1);
      for (int i{0}; i < loop_ub; i++) {
        path[i] = r[i];
      }

      path[r.size(1)] = '\x00';
      std::mem_fn(&eventHelper::init)(helper, &path[0]);
    }

    initialised = std::mem_fn(&eventHelper::isInitialised)(helper);
    if (initialised) {
      char b_cv[8];
      for (int i{0}; i < 8; i++) {
        b_cv[i] = b_cv1[i];
      }

      std::mem_fn(&eventHelper::updateProgress)(helper, &b_cv[0], varargin_2);
      notified = false;

      //  This avoids printing the error message multiple times during the optimization.
    } else if (!notified) {
      std::fprintf(stderr,
                   "\neventManager library could be loaded. Check that the dynamic library is present in the compile/events folder.\n");
      std::fflush(stderr);
      notified = true;
    }
  }

  void b_triggerEvent()
  {
    static const char b_cv1[57]{
      "\n Iteration   Func-count     min f(x)         Procedure\n" };

    ::coder::array<char, 2U> path;
    ::coder::array<char, 2U> r;
    boolean_T initialised;

    //  Triggers the event type with the given varargin. The supported event types are
    //  0, 1, and 2.
    //  * The input for the message event is a char array,
    //  * The inputs for the plot event are the result struct, problem struct and cell
    //  * The inputs for progress events are the message (char array) and
    //    percentage progress expressed as a decimal (i.e., between 0 and 1).
    //
    //  triggerEvent(coderEnums.eventTypes.Message, 'Hello world');
    //  triggerEvent(coderEnums.eventTypes.Plot, result, problemStruct);
    //  triggerEvent(coderEnums.eventTypes.Progress, 'Hello world', 0.5);
    if (!helper_not_empty) {
      int loop_ub;

      //  Declaration for coder
      helper_not_empty = true;

      //  Make an instance
      helper = eventHelper();
      coder::b_getenv(r);
      path.set_size(1, r.size(1) + 1);
      loop_ub = r.size(1);
      for (int i{0}; i < loop_ub; i++) {
        path[i] = r[i];
      }

      path[r.size(1)] = '\x00';
      std::mem_fn(&eventHelper::init)(helper, &path[0]);
    }

    initialised = std::mem_fn(&eventHelper::isInitialised)(helper);
    if (initialised) {
      char b_cv[57];
      for (int i{0}; i < 57; i++) {
        b_cv[i] = b_cv1[i];
      }

      std::mem_fn(&eventHelper::sendMessage)(helper, &b_cv[0]);
      notified = false;
    } else {
      //  This avoids printing the error message multiple times during the optimization.
      if (!notified) {
        std::fprintf(stderr,
                     "\neventManager library could be loaded. Check that the dynamic library is present in the compile/events folder.\n");
        std::fflush(stderr);
        notified = true;
      }

      std::printf("%s",
                  "\n Iteration   Func-count     min f(x)         Procedure\n");
      std::fflush(stdout);
    }
  }

  void b_triggerEvent(const b_struct_T &varargin_1, const char
                      varargin_2_TF_data[], const int varargin_2_TF_size[2],
                      const ::coder::array<double, 2U> &varargin_2_resample,
                      const ::coder::array<double, 2U> &varargin_2_dataPresent,
                      const char varargin_2_modelType_data[], const int
                      varargin_2_modelType_size[2], const ::coder::array<
                      cell_wrap_10, 2U> &varargin_2_names_contrasts)
  {
    ::coder::array<double, 2U> b_nSldProfiles2;
    ::coder::array<double, 2U> dataPresent;
    ::coder::array<double, 2U> layers2;
    ::coder::array<double, 2U> nContrastNames;
    ::coder::array<double, 2U> nLayers2;
    ::coder::array<double, 2U> resample;
    ::coder::array<double, 2U> sldProfiles2;
    ::coder::array<double, 1U> b_sldProfiles2;
    ::coder::array<double, 1U> layers;
    ::coder::array<double, 1U> nLayers;
    ::coder::array<double, 1U> nReflect;
    ::coder::array<double, 1U> nShiftedData;
    ::coder::array<double, 1U> nSldProfiles;
    ::coder::array<double, 1U> nSldProfiles2;
    ::coder::array<double, 1U> reflect;
    ::coder::array<double, 1U> shiftedData;
    ::coder::array<double, 1U> sldProfiles;
    ::coder::array<double, 1U> subRoughs;
    ::coder::array<char, 2U> contrastNames;
    ::coder::array<char, 2U> path;
    ::coder::array<char, 2U> r;
    int tmp_data[10000];
    int i;
    int loop_ub;
    char modelType_data[10001];
    boolean_T initialised;

    //  Triggers the event type with the given varargin. The supported event types are
    //  0, 1, and 2.
    //  * The input for the message event is a char array,
    //  * The inputs for the plot event are the result struct, problem struct and cell
    //  * The inputs for progress events are the message (char array) and
    //    percentage progress expressed as a decimal (i.e., between 0 and 1).
    //
    //  triggerEvent(coderEnums.eventTypes.Message, 'Hello world');
    //  triggerEvent(coderEnums.eventTypes.Plot, result, problemStruct);
    //  triggerEvent(coderEnums.eventTypes.Progress, 'Hello world', 0.5);
    if (!notified_not_empty) {
      notified = false;
      notified_not_empty = true;
    }

    if (!helper_not_empty) {
      //  Declaration for coder
      helper_not_empty = true;

      //  Make an instance
      helper = eventHelper();
      coder::b_getenv(r);
      path.set_size(1, r.size(1) + 1);
      loop_ub = r.size(1);
      for (i = 0; i < loop_ub; i++) {
        path[i] = r[i];
      }

      path[r.size(1)] = '\x00';
      std::mem_fn(&eventHelper::init)(helper, &path[0]);
    }

    initialised = std::mem_fn(&eventHelper::isInitialised)(helper);
    if (initialised) {
      subRoughs.set_size(varargin_1.contrastParams.subRoughs.size(0));
      loop_ub = varargin_1.contrastParams.subRoughs.size(0);
      for (i = 0; i < loop_ub; i++) {
        subRoughs[i] = varargin_1.contrastParams.subRoughs[i];
      }

      int tmp_size[2];
      packCellArray(varargin_1.reflectivity, reflect, nReflect);
      packCellArray(varargin_1.shiftedData, shiftedData, nShiftedData);
      packCellArray(varargin_1.sldProfiles, sldProfiles, nSldProfiles);
      packCellArray(varargin_1.resampledLayers, layers, nLayers);
      coder::strjoin(varargin_2_names_contrasts, contrastNames);
      coder::intstrlen(varargin_2_names_contrasts, tmp_data, tmp_size);
      nContrastNames.set_size(1, tmp_size[1]);
      loop_ub = tmp_size[1];
      for (i = 0; i < loop_ub; i++) {
        nContrastNames[i] = tmp_data[i];
      }

      if (coder::internal::j_strcmp(varargin_2_TF_data, varargin_2_TF_size)) {
        i = 0;
      } else {
        i = -1;
      }

      if (i == 0) {
        b_packCellArray(varargin_1.sldProfiles, b_sldProfiles2, nSldProfiles2);
        loop_ub = b_sldProfiles2.size(0);
        sldProfiles2.set_size(b_sldProfiles2.size(0), 1);
        for (i = 0; i < loop_ub; i++) {
          sldProfiles2[i] = b_sldProfiles2[i];
        }

        loop_ub = nSldProfiles2.size(0);
        b_nSldProfiles2.set_size(nSldProfiles2.size(0), 1);
        for (i = 0; i < loop_ub; i++) {
          b_nSldProfiles2[i] = nSldProfiles2[i];
        }

        b_packCellArray(varargin_1.resampledLayers, b_sldProfiles2,
                        nSldProfiles2);
        loop_ub = b_sldProfiles2.size(0);
        layers2.set_size(b_sldProfiles2.size(0), 1);
        for (i = 0; i < loop_ub; i++) {
          layers2[i] = b_sldProfiles2[i];
        }

        loop_ub = nSldProfiles2.size(0);
        nLayers2.set_size(nSldProfiles2.size(0), 1);
        for (i = 0; i < loop_ub; i++) {
          nLayers2[i] = nSldProfiles2[i];
        }
      } else {
        sldProfiles2.set_size(0, 0);
        b_nSldProfiles2.set_size(0, 0);
        layers2.set_size(0, 0);
        nLayers2.set_size(0, 0);
      }

      loop_ub = varargin_2_modelType_size[1];
      if (loop_ub - 1 >= 0) {
        std::copy(&varargin_2_modelType_data[0],
                  &varargin_2_modelType_data[loop_ub], &modelType_data[0]);
      }

      modelType_data[varargin_2_modelType_size[1]] = '\x00';
      resample.set_size(1, varargin_2_resample.size(1));
      loop_ub = varargin_2_resample.size(1);
      for (i = 0; i < loop_ub; i++) {
        resample[i] = varargin_2_resample[i];
      }

      dataPresent.set_size(1, varargin_2_dataPresent.size(1));
      loop_ub = varargin_2_dataPresent.size(1);
      for (i = 0; i < loop_ub; i++) {
        dataPresent[i] = varargin_2_dataPresent[i];
      }

      std::mem_fn(&eventHelper::updatePlot)(helper, static_cast<double>
        (varargin_1.reflectivity.size(0)), &(reflect.data())[0], &(nReflect.data
        ())[0], &(shiftedData.data())[0], &(nShiftedData.data())[0],
        &(sldProfiles.data())[0], &(nSldProfiles.data())[0], &(layers.data())[0],
        &(nLayers.data())[0], &sldProfiles2[0], &b_nSldProfiles2[0], &layers2[0],
        &nLayers2[0], &(subRoughs.data())[0], &resample[0], &dataPresent[0],
        &modelType_data[0], &contrastNames[0], &nContrastNames[0]);
      notified = false;

      //  This avoids printing the error message multiple times during the optimization.
    } else if (!notified) {
      std::fprintf(stderr,
                   "\neventManager library could be loaded. Check that the dynamic library is present in the compile/events folder.\n");
      std::fflush(stderr);
      notified = true;
    }
  }

  void c_triggerEvent()
  {
    static const char b_cv1[34]{ "\nOptimisation terminated by user\n" };

    ::coder::array<char, 2U> path;
    ::coder::array<char, 2U> r;
    boolean_T initialised;

    //  Triggers the event type with the given varargin. The supported event types are
    //  0, 1, and 2.
    //  * The input for the message event is a char array,
    //  * The inputs for the plot event are the result struct, problem struct and cell
    //  * The inputs for progress events are the message (char array) and
    //    percentage progress expressed as a decimal (i.e., between 0 and 1).
    //
    //  triggerEvent(coderEnums.eventTypes.Message, 'Hello world');
    //  triggerEvent(coderEnums.eventTypes.Plot, result, problemStruct);
    //  triggerEvent(coderEnums.eventTypes.Progress, 'Hello world', 0.5);
    if (!helper_not_empty) {
      int loop_ub;

      //  Declaration for coder
      helper_not_empty = true;

      //  Make an instance
      helper = eventHelper();
      coder::b_getenv(r);
      path.set_size(1, r.size(1) + 1);
      loop_ub = r.size(1);
      for (int i{0}; i < loop_ub; i++) {
        path[i] = r[i];
      }

      path[r.size(1)] = '\x00';
      std::mem_fn(&eventHelper::init)(helper, &path[0]);
    }

    initialised = std::mem_fn(&eventHelper::isInitialised)(helper);
    if (initialised) {
      char b_cv[34];
      for (int i{0}; i < 34; i++) {
        b_cv[i] = b_cv1[i];
      }

      std::mem_fn(&eventHelper::sendMessage)(helper, &b_cv[0]);
      notified = false;
    } else {
      //  This avoids printing the error message multiple times during the optimization.
      if (!notified) {
        std::fprintf(stderr,
                     "\neventManager library could be loaded. Check that the dynamic library is present in the compile/events folder.\n");
        std::fflush(stderr);
        notified = true;
      }

      std::printf("%s", "\nOptimisation terminated by user\n");
      std::fflush(stdout);
    }
  }

  void d_triggerEvent()
  {
    static const char b_cv1[34]{ "\nRunning Differential Evolution\n\n" };

    ::coder::array<char, 2U> path;
    ::coder::array<char, 2U> r;
    boolean_T initialised;

    //  Triggers the event type with the given varargin. The supported event types are
    //  0, 1, and 2.
    //  * The input for the message event is a char array,
    //  * The inputs for the plot event are the result struct, problem struct and cell
    //  * The inputs for progress events are the message (char array) and
    //    percentage progress expressed as a decimal (i.e., between 0 and 1).
    //
    //  triggerEvent(coderEnums.eventTypes.Message, 'Hello world');
    //  triggerEvent(coderEnums.eventTypes.Plot, result, problemStruct);
    //  triggerEvent(coderEnums.eventTypes.Progress, 'Hello world', 0.5);
    if (!helper_not_empty) {
      int loop_ub;

      //  Declaration for coder
      helper_not_empty = true;

      //  Make an instance
      helper = eventHelper();
      coder::b_getenv(r);
      path.set_size(1, r.size(1) + 1);
      loop_ub = r.size(1);
      for (int i{0}; i < loop_ub; i++) {
        path[i] = r[i];
      }

      path[r.size(1)] = '\x00';
      std::mem_fn(&eventHelper::init)(helper, &path[0]);
    }

    initialised = std::mem_fn(&eventHelper::isInitialised)(helper);
    if (initialised) {
      char b_cv[34];
      for (int i{0}; i < 34; i++) {
        b_cv[i] = b_cv1[i];
      }

      std::mem_fn(&eventHelper::sendMessage)(helper, &b_cv[0]);
      notified = false;
    } else {
      //  This avoids printing the error message multiple times during the optimization.
      if (!notified) {
        std::fprintf(stderr,
                     "\neventManager library could be loaded. Check that the dynamic library is present in the compile/events folder.\n");
        std::fflush(stderr);
        notified = true;
      }

      std::printf("%s", "\nRunning Differential Evolution\n\n");
      std::fflush(stdout);
    }
  }

  void e_triggerEvent()
  {
    static const char b_cv1[35]{ "I_NP increased to minimal value 5\n" };

    ::coder::array<char, 2U> path;
    ::coder::array<char, 2U> r;
    boolean_T initialised;

    //  Triggers the event type with the given varargin. The supported event types are
    //  0, 1, and 2.
    //  * The input for the message event is a char array,
    //  * The inputs for the plot event are the result struct, problem struct and cell
    //  * The inputs for progress events are the message (char array) and
    //    percentage progress expressed as a decimal (i.e., between 0 and 1).
    //
    //  triggerEvent(coderEnums.eventTypes.Message, 'Hello world');
    //  triggerEvent(coderEnums.eventTypes.Plot, result, problemStruct);
    //  triggerEvent(coderEnums.eventTypes.Progress, 'Hello world', 0.5);
    if (!helper_not_empty) {
      int loop_ub;

      //  Declaration for coder
      helper_not_empty = true;

      //  Make an instance
      helper = eventHelper();
      coder::b_getenv(r);
      path.set_size(1, r.size(1) + 1);
      loop_ub = r.size(1);
      for (int i{0}; i < loop_ub; i++) {
        path[i] = r[i];
      }

      path[r.size(1)] = '\x00';
      std::mem_fn(&eventHelper::init)(helper, &path[0]);
    }

    initialised = std::mem_fn(&eventHelper::isInitialised)(helper);
    if (initialised) {
      char b_cv[35];
      for (int i{0}; i < 35; i++) {
        b_cv[i] = b_cv1[i];
      }

      std::mem_fn(&eventHelper::sendMessage)(helper, &b_cv[0]);
      notified = false;
    } else {
      //  This avoids printing the error message multiple times during the optimization.
      if (!notified) {
        std::fprintf(stderr,
                     "\neventManager library could be loaded. Check that the dynamic library is present in the compile/events folder.\n");
        std::fflush(stderr);
        notified = true;
      }

      std::printf("%s", "I_NP increased to minimal value 5\n");
      std::fflush(stdout);
    }
  }

  void f_triggerEvent()
  {
    static const char b_cv1[62]{
      "F_CR should be from interval [0,1]; set to default value 0.5\n" };

    ::coder::array<char, 2U> path;
    ::coder::array<char, 2U> r;
    boolean_T initialised;

    //  Triggers the event type with the given varargin. The supported event types are
    //  0, 1, and 2.
    //  * The input for the message event is a char array,
    //  * The inputs for the plot event are the result struct, problem struct and cell
    //  * The inputs for progress events are the message (char array) and
    //    percentage progress expressed as a decimal (i.e., between 0 and 1).
    //
    //  triggerEvent(coderEnums.eventTypes.Message, 'Hello world');
    //  triggerEvent(coderEnums.eventTypes.Plot, result, problemStruct);
    //  triggerEvent(coderEnums.eventTypes.Progress, 'Hello world', 0.5);
    if (!helper_not_empty) {
      int loop_ub;

      //  Declaration for coder
      helper_not_empty = true;

      //  Make an instance
      helper = eventHelper();
      coder::b_getenv(r);
      path.set_size(1, r.size(1) + 1);
      loop_ub = r.size(1);
      for (int i{0}; i < loop_ub; i++) {
        path[i] = r[i];
      }

      path[r.size(1)] = '\x00';
      std::mem_fn(&eventHelper::init)(helper, &path[0]);
    }

    initialised = std::mem_fn(&eventHelper::isInitialised)(helper);
    if (initialised) {
      char b_cv[62];
      for (int i{0}; i < 62; i++) {
        b_cv[i] = b_cv1[i];
      }

      std::mem_fn(&eventHelper::sendMessage)(helper, &b_cv[0]);
      notified = false;
    } else {
      //  This avoids printing the error message multiple times during the optimization.
      if (!notified) {
        std::fprintf(stderr,
                     "\neventManager library could be loaded. Check that the dynamic library is present in the compile/events folder.\n");
        std::fflush(stderr);
        notified = true;
      }

      std::printf("%s",
                  "F_CR should be from interval [0,1]; set to default value 0.5\n");
      std::fflush(stdout);
    }
  }

  void g_triggerEvent()
  {
    static const char b_cv1[51]{
      "I_itermax should be > 0; set to default value 200\n" };

    ::coder::array<char, 2U> path;
    ::coder::array<char, 2U> r;
    boolean_T initialised;

    //  Triggers the event type with the given varargin. The supported event types are
    //  0, 1, and 2.
    //  * The input for the message event is a char array,
    //  * The inputs for the plot event are the result struct, problem struct and cell
    //  * The inputs for progress events are the message (char array) and
    //    percentage progress expressed as a decimal (i.e., between 0 and 1).
    //
    //  triggerEvent(coderEnums.eventTypes.Message, 'Hello world');
    //  triggerEvent(coderEnums.eventTypes.Plot, result, problemStruct);
    //  triggerEvent(coderEnums.eventTypes.Progress, 'Hello world', 0.5);
    if (!helper_not_empty) {
      int loop_ub;

      //  Declaration for coder
      helper_not_empty = true;

      //  Make an instance
      helper = eventHelper();
      coder::b_getenv(r);
      path.set_size(1, r.size(1) + 1);
      loop_ub = r.size(1);
      for (int i{0}; i < loop_ub; i++) {
        path[i] = r[i];
      }

      path[r.size(1)] = '\x00';
      std::mem_fn(&eventHelper::init)(helper, &path[0]);
    }

    initialised = std::mem_fn(&eventHelper::isInitialised)(helper);
    if (initialised) {
      char b_cv[51];
      for (int i{0}; i < 51; i++) {
        b_cv[i] = b_cv1[i];
      }

      std::mem_fn(&eventHelper::sendMessage)(helper, &b_cv[0]);
      notified = false;
    } else {
      //  This avoids printing the error message multiple times during the optimization.
      if (!notified) {
        std::fprintf(stderr,
                     "\neventManager library could be loaded. Check that the dynamic library is present in the compile/events folder.\n");
        std::fflush(stderr);
        notified = true;
      }

      std::printf("%s", "I_itermax should be > 0; set to default value 200\n");
      std::fflush(stdout);
    }
  }

  void h_triggerEvent()
  {
    static const char b_cv1[33]{ "Optimisation terminated by user\n" };

    ::coder::array<char, 2U> path;
    ::coder::array<char, 2U> r;
    boolean_T initialised;

    //  Triggers the event type with the given varargin. The supported event types are
    //  0, 1, and 2.
    //  * The input for the message event is a char array,
    //  * The inputs for the plot event are the result struct, problem struct and cell
    //  * The inputs for progress events are the message (char array) and
    //    percentage progress expressed as a decimal (i.e., between 0 and 1).
    //
    //  triggerEvent(coderEnums.eventTypes.Message, 'Hello world');
    //  triggerEvent(coderEnums.eventTypes.Plot, result, problemStruct);
    //  triggerEvent(coderEnums.eventTypes.Progress, 'Hello world', 0.5);
    if (!helper_not_empty) {
      int loop_ub;

      //  Declaration for coder
      helper_not_empty = true;

      //  Make an instance
      helper = eventHelper();
      coder::b_getenv(r);
      path.set_size(1, r.size(1) + 1);
      loop_ub = r.size(1);
      for (int i{0}; i < loop_ub; i++) {
        path[i] = r[i];
      }

      path[r.size(1)] = '\x00';
      std::mem_fn(&eventHelper::init)(helper, &path[0]);
    }

    initialised = std::mem_fn(&eventHelper::isInitialised)(helper);
    if (initialised) {
      char b_cv[33];
      for (int i{0}; i < 33; i++) {
        b_cv[i] = b_cv1[i];
      }

      std::mem_fn(&eventHelper::sendMessage)(helper, &b_cv[0]);
      notified = false;
    } else {
      //  This avoids printing the error message multiple times during the optimization.
      if (!notified) {
        std::fprintf(stderr,
                     "\neventManager library could be loaded. Check that the dynamic library is present in the compile/events folder.\n");
        std::fflush(stderr);
        notified = true;
      }

      std::printf("%s", "Optimisation terminated by user\n");
      std::fflush(stdout);
    }
  }

  void helper_not_empty_init()
  {
    helper_not_empty = false;
  }

  void i_triggerEvent()
  {
    static const char b_cv1[26]{ "\nRunning Nested Sampler\n\n" };

    ::coder::array<char, 2U> path;
    ::coder::array<char, 2U> r;
    boolean_T initialised;

    //  Triggers the event type with the given varargin. The supported event types are
    //  0, 1, and 2.
    //  * The input for the message event is a char array,
    //  * The inputs for the plot event are the result struct, problem struct and cell
    //  * The inputs for progress events are the message (char array) and
    //    percentage progress expressed as a decimal (i.e., between 0 and 1).
    //
    //  triggerEvent(coderEnums.eventTypes.Message, 'Hello world');
    //  triggerEvent(coderEnums.eventTypes.Plot, result, problemStruct);
    //  triggerEvent(coderEnums.eventTypes.Progress, 'Hello world', 0.5);
    if (!helper_not_empty) {
      int loop_ub;

      //  Declaration for coder
      helper_not_empty = true;

      //  Make an instance
      helper = eventHelper();
      coder::b_getenv(r);
      path.set_size(1, r.size(1) + 1);
      loop_ub = r.size(1);
      for (int i{0}; i < loop_ub; i++) {
        path[i] = r[i];
      }

      path[r.size(1)] = '\x00';
      std::mem_fn(&eventHelper::init)(helper, &path[0]);
    }

    initialised = std::mem_fn(&eventHelper::isInitialised)(helper);
    if (initialised) {
      char b_cv[26];
      for (int i{0}; i < 26; i++) {
        b_cv[i] = b_cv1[i];
      }

      std::mem_fn(&eventHelper::sendMessage)(helper, &b_cv[0]);
      notified = false;
    } else {
      //  This avoids printing the error message multiple times during the optimization.
      if (!notified) {
        std::fprintf(stderr,
                     "\neventManager library could be loaded. Check that the dynamic library is present in the compile/events folder.\n");
        std::fflush(stderr);
        notified = true;
      }

      std::printf("%s", "\nRunning Nested Sampler\n\n");
      std::fflush(stdout);
    }
  }

  void j_triggerEvent()
  {
    static const char b_cv1[17]{ "\nRunning DREAM\n\n" };

    ::coder::array<char, 2U> path;
    ::coder::array<char, 2U> r;
    boolean_T initialised;

    //  Triggers the event type with the given varargin. The supported event types are
    //  0, 1, and 2.
    //  * The input for the message event is a char array,
    //  * The inputs for the plot event are the result struct, problem struct and cell
    //  * The inputs for progress events are the message (char array) and
    //    percentage progress expressed as a decimal (i.e., between 0 and 1).
    //
    //  triggerEvent(coderEnums.eventTypes.Message, 'Hello world');
    //  triggerEvent(coderEnums.eventTypes.Plot, result, problemStruct);
    //  triggerEvent(coderEnums.eventTypes.Progress, 'Hello world', 0.5);
    if (!helper_not_empty) {
      int loop_ub;

      //  Declaration for coder
      helper_not_empty = true;

      //  Make an instance
      helper = eventHelper();
      coder::b_getenv(r);
      path.set_size(1, r.size(1) + 1);
      loop_ub = r.size(1);
      for (int i{0}; i < loop_ub; i++) {
        path[i] = r[i];
      }

      path[r.size(1)] = '\x00';
      std::mem_fn(&eventHelper::init)(helper, &path[0]);
    }

    initialised = std::mem_fn(&eventHelper::isInitialised)(helper);
    if (initialised) {
      char b_cv[17];
      for (int i{0}; i < 17; i++) {
        b_cv[i] = b_cv1[i];
      }

      std::mem_fn(&eventHelper::sendMessage)(helper, &b_cv[0]);
      notified = false;
    } else {
      //  This avoids printing the error message multiple times during the optimization.
      if (!notified) {
        std::fprintf(stderr,
                     "\neventManager library could be loaded. Check that the dynamic library is present in the compile/events folder.\n");
        std::fflush(stderr);
        notified = true;
      }

      std::printf("%s", "\nRunning DREAM\n\n");
      std::fflush(stdout);
    }
  }

  void notified_not_empty_init()
  {
    notified_not_empty = false;
  }

  void triggerEvent(const b_struct_T &varargin_1, const char varargin_2_TF_data[],
                    const int varargin_2_TF_size[2], const ::coder::array<double,
                    2U> &varargin_2_resample, const ::coder::array<double, 2U>
                    &varargin_2_dataPresent, const char
                    varargin_2_modelType_data[], const int
                    varargin_2_modelType_size[2], const ::coder::array<
                    cell_wrap_10, 2U> &varargin_2_names_contrasts)
  {
    ::coder::array<double, 2U> b_nSldProfiles2;
    ::coder::array<double, 2U> dataPresent;
    ::coder::array<double, 2U> layers2;
    ::coder::array<double, 2U> nContrastNames;
    ::coder::array<double, 2U> nLayers2;
    ::coder::array<double, 2U> resample;
    ::coder::array<double, 2U> sldProfiles2;
    ::coder::array<double, 1U> b_sldProfiles2;
    ::coder::array<double, 1U> layers;
    ::coder::array<double, 1U> nLayers;
    ::coder::array<double, 1U> nReflect;
    ::coder::array<double, 1U> nShiftedData;
    ::coder::array<double, 1U> nSldProfiles;
    ::coder::array<double, 1U> nSldProfiles2;
    ::coder::array<double, 1U> reflect;
    ::coder::array<double, 1U> shiftedData;
    ::coder::array<double, 1U> sldProfiles;
    ::coder::array<double, 1U> subRoughs;
    ::coder::array<char, 2U> contrastNames;
    ::coder::array<char, 2U> path;
    ::coder::array<char, 2U> r;
    int tmp_data[10000];
    int i;
    int loop_ub;
    char modelType_data[10001];
    boolean_T initialised;

    //  Triggers the event type with the given varargin. The supported event types are
    //  0, 1, and 2.
    //  * The input for the message event is a char array,
    //  * The inputs for the plot event are the result struct, problem struct and cell
    //  * The inputs for progress events are the message (char array) and
    //    percentage progress expressed as a decimal (i.e., between 0 and 1).
    //
    //  triggerEvent(coderEnums.eventTypes.Message, 'Hello world');
    //  triggerEvent(coderEnums.eventTypes.Plot, result, problemStruct);
    //  triggerEvent(coderEnums.eventTypes.Progress, 'Hello world', 0.5);
    if (!helper_not_empty) {
      //  Declaration for coder
      helper_not_empty = true;

      //  Make an instance
      helper = eventHelper();
      coder::b_getenv(r);
      path.set_size(1, r.size(1) + 1);
      loop_ub = r.size(1);
      for (i = 0; i < loop_ub; i++) {
        path[i] = r[i];
      }

      path[r.size(1)] = '\x00';
      std::mem_fn(&eventHelper::init)(helper, &path[0]);
    }

    initialised = std::mem_fn(&eventHelper::isInitialised)(helper);
    if (initialised) {
      subRoughs.set_size(varargin_1.contrastParams.subRoughs.size(0));
      loop_ub = varargin_1.contrastParams.subRoughs.size(0);
      for (i = 0; i < loop_ub; i++) {
        subRoughs[i] = varargin_1.contrastParams.subRoughs[i];
      }

      int tmp_size[2];
      packCellArray(varargin_1.reflectivity, reflect, nReflect);
      packCellArray(varargin_1.shiftedData, shiftedData, nShiftedData);
      packCellArray(varargin_1.sldProfiles, sldProfiles, nSldProfiles);
      packCellArray(varargin_1.resampledLayers, layers, nLayers);
      coder::strjoin(varargin_2_names_contrasts, contrastNames);
      coder::intstrlen(varargin_2_names_contrasts, tmp_data, tmp_size);
      nContrastNames.set_size(1, tmp_size[1]);
      loop_ub = tmp_size[1];
      for (i = 0; i < loop_ub; i++) {
        nContrastNames[i] = tmp_data[i];
      }

      if (coder::internal::j_strcmp(varargin_2_TF_data, varargin_2_TF_size)) {
        i = 0;
      } else {
        i = -1;
      }

      if (i == 0) {
        b_packCellArray(varargin_1.sldProfiles, b_sldProfiles2, nSldProfiles2);
        loop_ub = b_sldProfiles2.size(0);
        sldProfiles2.set_size(b_sldProfiles2.size(0), 1);
        for (i = 0; i < loop_ub; i++) {
          sldProfiles2[i] = b_sldProfiles2[i];
        }

        loop_ub = nSldProfiles2.size(0);
        b_nSldProfiles2.set_size(nSldProfiles2.size(0), 1);
        for (i = 0; i < loop_ub; i++) {
          b_nSldProfiles2[i] = nSldProfiles2[i];
        }

        b_packCellArray(varargin_1.resampledLayers, b_sldProfiles2,
                        nSldProfiles2);
        loop_ub = b_sldProfiles2.size(0);
        layers2.set_size(b_sldProfiles2.size(0), 1);
        for (i = 0; i < loop_ub; i++) {
          layers2[i] = b_sldProfiles2[i];
        }

        loop_ub = nSldProfiles2.size(0);
        nLayers2.set_size(nSldProfiles2.size(0), 1);
        for (i = 0; i < loop_ub; i++) {
          nLayers2[i] = nSldProfiles2[i];
        }
      } else {
        sldProfiles2.set_size(0, 0);
        b_nSldProfiles2.set_size(0, 0);
        layers2.set_size(0, 0);
        nLayers2.set_size(0, 0);
      }

      loop_ub = varargin_2_modelType_size[1];
      if (loop_ub - 1 >= 0) {
        std::copy(&varargin_2_modelType_data[0],
                  &varargin_2_modelType_data[loop_ub], &modelType_data[0]);
      }

      modelType_data[varargin_2_modelType_size[1]] = '\x00';
      resample.set_size(1, varargin_2_resample.size(1));
      loop_ub = varargin_2_resample.size(1);
      for (i = 0; i < loop_ub; i++) {
        resample[i] = varargin_2_resample[i];
      }

      dataPresent.set_size(1, varargin_2_dataPresent.size(1));
      loop_ub = varargin_2_dataPresent.size(1);
      for (i = 0; i < loop_ub; i++) {
        dataPresent[i] = varargin_2_dataPresent[i];
      }

      std::mem_fn(&eventHelper::updatePlot)(helper, static_cast<double>
        (varargin_1.reflectivity.size(0)), &(reflect.data())[0], &(nReflect.data
        ())[0], &(shiftedData.data())[0], &(nShiftedData.data())[0],
        &(sldProfiles.data())[0], &(nSldProfiles.data())[0], &(layers.data())[0],
        &(nLayers.data())[0], &sldProfiles2[0], &b_nSldProfiles2[0], &layers2[0],
        &nLayers2[0], &(subRoughs.data())[0], &resample[0], &dataPresent[0],
        &modelType_data[0], &contrastNames[0], &nContrastNames[0]);
      notified = false;

      //  This avoids printing the error message multiple times during the optimization.
    } else if (!notified) {
      std::fprintf(stderr,
                   "\neventManager library could be loaded. Check that the dynamic library is present in the compile/events folder.\n");
      std::fflush(stderr);
      notified = true;
    }
  }

  void triggerEvent(const ::coder::array<char, 2U> &varargin_1)
  {
    ::coder::array<char, 2U> b_varargin_1;
    ::coder::array<char, 2U> path;
    int loop_ub;
    boolean_T initialised;

    //  Triggers the event type with the given varargin. The supported event types are
    //  0, 1, and 2.
    //  * The input for the message event is a char array,
    //  * The inputs for the plot event are the result struct, problem struct and cell
    //  * The inputs for progress events are the message (char array) and
    //    percentage progress expressed as a decimal (i.e., between 0 and 1).
    //
    //  triggerEvent(coderEnums.eventTypes.Message, 'Hello world');
    //  triggerEvent(coderEnums.eventTypes.Plot, result, problemStruct);
    //  triggerEvent(coderEnums.eventTypes.Progress, 'Hello world', 0.5);
    if (!helper_not_empty) {
      //  Declaration for coder
      helper_not_empty = true;

      //  Make an instance
      helper = eventHelper();
      coder::b_getenv(b_varargin_1);
      path.set_size(1, b_varargin_1.size(1) + 1);
      loop_ub = b_varargin_1.size(1);
      for (int i{0}; i < loop_ub; i++) {
        path[i] = b_varargin_1[i];
      }

      path[b_varargin_1.size(1)] = '\x00';
      std::mem_fn(&eventHelper::init)(helper, &path[0]);
    }

    initialised = std::mem_fn(&eventHelper::isInitialised)(helper);
    if (initialised) {
      b_varargin_1.set_size(1, varargin_1.size(1) + 1);
      loop_ub = varargin_1.size(1);
      for (int i{0}; i < loop_ub; i++) {
        b_varargin_1[i] = varargin_1[i];
      }

      b_varargin_1[varargin_1.size(1)] = '\x00';
      std::mem_fn(&eventHelper::sendMessage)(helper, &b_varargin_1[0]);
      notified = false;
    } else {
      //  This avoids printing the error message multiple times during the optimization.
      if (!notified) {
        std::fprintf(stderr,
                     "\neventManager library could be loaded. Check that the dynamic library is present in the compile/events folder.\n");
        std::fflush(stderr);
        notified = true;
      }

      b_varargin_1.set_size(1, varargin_1.size(1) + 1);
      loop_ub = varargin_1.size(1);
      for (int i{0}; i < loop_ub; i++) {
        b_varargin_1[i] = varargin_1[i];
      }

      b_varargin_1[varargin_1.size(1)] = '\x00';
      std::printf("%s", &b_varargin_1[0]);
      std::fflush(stdout);
    }
  }

  void triggerEvent()
  {
    static const char b_cv1[19]{ "\nRunning simplex\n\n" };

    ::coder::array<char, 2U> path;
    ::coder::array<char, 2U> r;
    boolean_T initialised;

    //  Triggers the event type with the given varargin. The supported event types are
    //  0, 1, and 2.
    //  * The input for the message event is a char array,
    //  * The inputs for the plot event are the result struct, problem struct and cell
    //  * The inputs for progress events are the message (char array) and
    //    percentage progress expressed as a decimal (i.e., between 0 and 1).
    //
    //  triggerEvent(coderEnums.eventTypes.Message, 'Hello world');
    //  triggerEvent(coderEnums.eventTypes.Plot, result, problemStruct);
    //  triggerEvent(coderEnums.eventTypes.Progress, 'Hello world', 0.5);
    if (!helper_not_empty) {
      int loop_ub;

      //  Declaration for coder
      helper_not_empty = true;

      //  Make an instance
      helper = eventHelper();
      coder::b_getenv(r);
      path.set_size(1, r.size(1) + 1);
      loop_ub = r.size(1);
      for (int i{0}; i < loop_ub; i++) {
        path[i] = r[i];
      }

      path[r.size(1)] = '\x00';
      std::mem_fn(&eventHelper::init)(helper, &path[0]);
    }

    initialised = std::mem_fn(&eventHelper::isInitialised)(helper);
    if (initialised) {
      char b_cv[19];
      for (int i{0}; i < 19; i++) {
        b_cv[i] = b_cv1[i];
      }

      std::mem_fn(&eventHelper::sendMessage)(helper, &b_cv[0]);
      notified = false;
    } else {
      //  This avoids printing the error message multiple times during the optimization.
      if (!notified) {
        std::fprintf(stderr,
                     "\neventManager library could be loaded. Check that the dynamic library is present in the compile/events folder.\n");
        std::fflush(stderr);
        notified = true;
      }

      std::printf("%s", "\nRunning simplex\n\n");
      std::fflush(stdout);
    }
  }

  void triggerEvent(double varargin_2)
  {
    static const char b_cv1[6]{ "DREAM" };

    ::coder::array<char, 2U> path;
    ::coder::array<char, 2U> r;
    boolean_T initialised;

    //  Triggers the event type with the given varargin. The supported event types are
    //  0, 1, and 2.
    //  * The input for the message event is a char array,
    //  * The inputs for the plot event are the result struct, problem struct and cell
    //  * The inputs for progress events are the message (char array) and
    //    percentage progress expressed as a decimal (i.e., between 0 and 1).
    //
    //  triggerEvent(coderEnums.eventTypes.Message, 'Hello world');
    //  triggerEvent(coderEnums.eventTypes.Plot, result, problemStruct);
    //  triggerEvent(coderEnums.eventTypes.Progress, 'Hello world', 0.5);
    if (!helper_not_empty) {
      int loop_ub;

      //  Declaration for coder
      helper_not_empty = true;

      //  Make an instance
      helper = eventHelper();
      coder::b_getenv(r);
      path.set_size(1, r.size(1) + 1);
      loop_ub = r.size(1);
      for (int i{0}; i < loop_ub; i++) {
        path[i] = r[i];
      }

      path[r.size(1)] = '\x00';
      std::mem_fn(&eventHelper::init)(helper, &path[0]);
    }

    initialised = std::mem_fn(&eventHelper::isInitialised)(helper);
    if (initialised) {
      char b_cv[6];
      for (int i{0}; i < 6; i++) {
        b_cv[i] = b_cv1[i];
      }

      std::mem_fn(&eventHelper::updateProgress)(helper, &b_cv[0], varargin_2);
      notified = false;

      //  This avoids printing the error message multiple times during the optimization.
    } else if (!notified) {
      std::fprintf(stderr,
                   "\neventManager library could be loaded. Check that the dynamic library is present in the compile/events folder.\n");
      std::fflush(stderr);
      notified = true;
    }
  }

  void triggerEvent_init()
  {
    notified = false;
    notified_not_empty = true;
  }
}

// End of code generation (triggerEvent.cpp)
