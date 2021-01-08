/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * persontest.c
 *
 * Code generation for function 'persontest'
 *
 */

/* Include files */
#include "persontest.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Type Definitions */
#include "personwrapper.h"

/* Function Definitions */
void persontest(const emlrtStack *sp, const char_T name_data[], const int32_T
                name_size[2], int16_T age, char_T pname_data[], int32_T
                pname_size[2], int32_T *page)
{
  persontype mypersonptr;
  int32_T loop_ub;
  char_T b_name_data[1024];
  (void)sp;
  pname_size[0] = 1;
  pname_size[1] = 1024;
  memset(&pname_data[0], 0, 1024U * sizeof(char_T));
  mypersonptr = person_constructor();
  loop_ub = name_size[0] * name_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&b_name_data[0], &name_data[0], loop_ub * sizeof(char_T));
  }

  set_name_wrapper(mypersonptr, &b_name_data[0]);
  set_age_wrapper(mypersonptr, age);
  get_name_wrapper(mypersonptr, &pname_data[0]);
  *page = get_age_wrapper(mypersonptr);
  person_destructor(mypersonptr);
}

/* End of code generation (persontest.c) */
