/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
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
/* Include files */
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "main.h"
#include "shiftdata_terminate.h"
#include "shiftdata_emxAPI.h"
#include "shiftdata_initialize.h"

/* Function Declarations */
static void argInit_1x2_real_T(double result[2]);
static emxArray_real_T *argInit_Unboundedx3_real_T(void);
static double argInit_real_T(void);
static void main_shiftdata(void);

/* Function Definitions */
static void argInit_1x2_real_T(double result[2])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 2; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static emxArray_real_T *argInit_Unboundedx3_real_T(void)
{
  emxArray_real_T *result;
  static int iv0[2] = { 2, 3 };

  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(2, iv0);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < 3; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
  }

  return result;
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void main_shiftdata(void)
{
  emxArray_real_T *shifted_data;
  double scalefac;
  double horshift;
  double dataPresent;
  emxArray_real_T *data;
  double dv0[2];
  emxInitArray_real_T(&shifted_data, 2);

  /* Initialize function 'shiftdata' input arguments. */
  scalefac = argInit_real_T();
  horshift = argInit_real_T();
  dataPresent = argInit_real_T();

  /* Initialize function input argument 'data'. */
  data = argInit_Unboundedx3_real_T();

  /* Initialize function input argument 'dataLimits'. */
  /* Call the entry-point 'shiftdata'. */
  argInit_1x2_real_T(dv0);
  shiftdata(scalefac, horshift, dataPresent, data, dv0, shifted_data);
  emxDestroyArray_real_T(shifted_data);
  emxDestroyArray_real_T(data);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  shiftdata_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_shiftdata();

  /* Terminate the application.
     You do not need to do this more than one time. */
  shiftdata_terminate();
  return 0;
}

/* End of code generation (main.c) */
