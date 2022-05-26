//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// main.cpp
//
// Code generation for function 'main'
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include files
#include "main.h"
#include "myFun.h"
#include "myFun_terminate.h"

// Function Declarations
static void argInit_4x1_real_T(double result[4]);

static double argInit_real_T();

static void main_myFun();

// Function Definitions
static void argInit_4x1_real_T(double result[4])
{
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 4; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_real_T();
  }
}

static double argInit_real_T()
{
  return 0.0;
}

static void main_myFun()
{
  double dv[4];
  double out1[2][2];
  double foo_tmp;
  double out2;
  // Initialize function 'myFun' input arguments.
  // Initialize function input argument 'params'.
  foo_tmp = argInit_real_T();
  // Call the entry-point 'myFun'.
  argInit_4x1_real_T(dv);
  myFun(dv, foo_tmp, foo_tmp, out1, &out2);
}

int main(int, char **)
{
  // The initialize function is being called automatically from your entry-point
  // function. So, a call to initialize is not included here. Invoke the
  // entry-point functions.
  // You can call entry-point functions multiple times.
  main_myFun();
  // Terminate the application.
  // You do not need to do this more than one time.
  myFun_terminate();
  return 0;
}

// End of code generation (main.cpp)
