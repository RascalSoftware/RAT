//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// RATMain_initialize.cpp
//
// Code generation for function 'RATMain_initialize'
//

// Include files
#include "RATMain_initialize.h"
#include "CoderTimeAPI.h"
#include "RATMain_data.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "fileManager.h"
#include "hasPlotHandler.h"
#include "rt_nonfinite.h"
#include "timeKeeper.h"
#include "triggerEvent.h"
#include "omp.h"

// Function Definitions
namespace RAT
{
  void RATMain_initialize()
  {
    omp_init_nest_lock(&RATMain_nestLockGlobal);
    savedTime_not_empty_init();
    freq_not_empty_init();
    b_helper_not_empty_init();
    helper_not_empty_init();
    notified_not_empty_init();
    triggerEvent_init();
    filedata_init();
    eml_rand_mt19937ar_stateful_init();
  }
}

// End of code generation (RATMain_initialize.cpp)
