/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * callOctave_main.c
 *
 * Code generation for function 'callOctave_main'
 *
 */

/* Include files */
#include "callOctave_main.h"
#include "callOctave.h"
#include "callOctave_main_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void callOctave_main(const emlrtStack *sp)
{
  (void)sp;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1U);
  callOctave();
}

/* End of code generation (callOctave_main.c) */
