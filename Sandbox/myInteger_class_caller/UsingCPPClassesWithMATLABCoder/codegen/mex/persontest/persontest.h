/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * persontest.h
 *
 * Code generation for function 'persontest'
 *
 */

#pragma once

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "persontest_types.h"

/* Type Definitions */
#include "personwrapper.h"

/* Function Declarations */
void persontest(const emlrtStack *sp, const char_T name_data[], const int32_T
                name_size[2], int16_T age, char_T pname_data[], int32_T
                pname_size[2], int32_T *page);

/* End of code generation (persontest.h) */
