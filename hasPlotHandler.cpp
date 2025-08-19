//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// hasPlotHandler.cpp
//
// Code generation for function 'hasPlotHandler'
//

// Include files
#include "hasPlotHandler.h"
#include "getenv.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "eventHelper.hpp"

// Variable Definitions
namespace RAT
{
  static boolean_T b_helper_not_empty;
}

// Function Definitions
namespace RAT
{
  void b_helper_not_empty_init()
  {
    b_helper_not_empty = false;
  }

  boolean_T hasPlotHandler()
  {
    static eventHelper b_helper;
    ::coder::array<char, 2U> path;
    ::coder::array<char, 2U> r;
    boolean_T b_state;
    boolean_T initialised;

    //  Checks if a function is listening for the plot event
    //
    //  state = hasPlotHandler();
    b_state = false;
    if (!b_helper_not_empty) {
      int loop_ub;

      //  Declaration for coder
      b_helper_not_empty = true;

      //  Make an instance
      b_helper = eventHelper();
      coder::b_getenv(r);
      path.set_size(1, r.size(1) + 1);
      loop_ub = r.size(1);
      for (int i{0}; i < loop_ub; i++) {
        path[i] = r[i];
      }

      path[r.size(1)] = '\x00';
      std::mem_fn(&eventHelper::init)(b_helper, &path[0]);
    }

    initialised = std::mem_fn(&eventHelper::isInitialised)(b_helper);
    if (initialised) {
      b_state = std::mem_fn(&eventHelper::hasPlotHandler)(b_helper);
    }

    return b_state;
  }
}

// End of code generation (hasPlotHandler.cpp)
