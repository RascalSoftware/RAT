//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// myFun.cpp
//
// Code generation for function 'myFun'
//

// Include files
#include "myFun.h"
#include <cmath>

// Function Definitions
void myFun(const double params[4], double foo, double bar, double out1[2][2],
           double *out2)
{
  double myPar1;
  //  Vital we keep these variable names by way of explanation
  //  A comment here will explain the calculation
  myPar1 = (params[0] + params[3]) * (params[2] - foo);
  //  Another comment to keep here....
  //  Making the outputs is alse expained by variable names...
  out1[0][0] = myPar1;
  out1[1][0] = foo * bar;
  out1[0][1] = foo;
  out1[1][1] = bar;
  *out2 = std::sin(myPar1) * params[1];
}

// End of code generation (myFun.cpp)
