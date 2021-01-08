//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: persontest.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 18-Dec-2020 16:40:07
//

// Include Files
#include "persontest.h"
#include <string.h>

// Type Definitions
#include "personwrapper.h"

// Function Definitions

//
// Arguments    : const char name_data[]
//                const int name_size[2]
//                short age
//                char pname_data[]
//                int pname_size[2]
//                int *page
// Return Type  : void
//
void persontest(const char name_data[], const int name_size[2], short age, char
                pname_data[], int pname_size[2], int *page)
{
  persontype mypersonptr;
  int loop_ub;
  char b_name_data[1024];
  pname_size[0] = 1;
  pname_size[1] = 1024;
  memset(&pname_data[0], 0, 1024U * sizeof(char));
  mypersonptr = person_constructor();
  loop_ub = name_size[0] * name_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&b_name_data[0], &name_data[0], loop_ub * sizeof(char));
  }

  set_name_wrapper(mypersonptr, &b_name_data[0]);
  set_age_wrapper(mypersonptr, age);
  get_name_wrapper(mypersonptr, &pname_data[0]);
  *page = get_age_wrapper(mypersonptr);
  person_destructor(mypersonptr);
}

//
// File trailer for persontest.cpp
//
// [EOF]
//
