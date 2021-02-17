//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: mycode.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 08-Jan-2021 10:39:07
//

// Include Files
#include "mycode.h"
#include "myclass.h"
#include <functional>

// Type Definitions
#include "myclass.h"

// Function Definitions

//
// MYMCODE Summary of this function goes here
//    Detailed explanation goes here
// Arguments    : void
// Return Type  : int
//
int mycode()
{
  MyClass p;
  p = MyClass();
  return std::mem_fn(&MyClass::mymethod)(p, 5);
}

//
// File trailer for mycode.cpp
//
// [EOF]
//
