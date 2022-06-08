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
#include "customBilayer.h"
#include "customBilayer_terminate.h"
#include "coder_array.h"

// Function Declarations
static void argInit_3x1_real_T(double result[3]);

static coder::array<double, 1U> argInit_Unboundedx1_real_T();

static double argInit_real_T();

static void main_customBilayer();

// Function Definitions
static void argInit_3x1_real_T(double result[3])
{
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 3; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_real_T();
  }
}

static coder::array<double, 1U> argInit_Unboundedx1_real_T()
{
  coder::array<double, 1U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < result.size(0); idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_real_T();
  }
  return result;
}

static double argInit_real_T()
{
  return 0.0;
}

static void main_customBilayer()
{
  coder::array<double, 1U> params;
  double output[3][6];
  double dv[3];
  double bulk_in_tmp;
  double sub_rough;
  // Initialize function 'customBilayer' input arguments.
  // Initialize function input argument 'params'.
  params = argInit_Unboundedx1_real_T();
  bulk_in_tmp = argInit_real_T();
  // Initialize function input argument 'bulk_out'.
  // Call the entry-point 'customBilayer'.
  argInit_3x1_real_T(dv);
  customBilayer(params, bulk_in_tmp, dv, bulk_in_tmp, output, &sub_rough);
}

int main(int, char **)
{
  // The initialize function is being called automatically from your entry-point
  // function. So, a call to initialize is not included here. Invoke the
  // entry-point functions.
  // You can call entry-point functions multiple times.
  main_customBilayer();
  // Terminate the application.
  // You do not need to do this more than one time.
  customBilayer_terminate();
  return 0;
}

// End of code generation (main.cpp)
