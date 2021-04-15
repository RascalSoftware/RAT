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
#include "callReflectivity.h"
#include "main.h"
#include "callReflectivity_terminate.h"
#include "callReflectivity_emxAPI.h"
#include "callReflectivity_initialize.h"

/* Function Declarations */
static void argInit_1x2_real_T(double result[2]);
static emxArray_real_T *argInit_Unboundedx3_real_T(void);
static double argInit_real_T(void);
static void main_callReflectivity(void);

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

static void main_callReflectivity(void)
{
  emxArray_real_T *reflectivity;
  emxArray_real_T *Simulation;
  double nbairs;
  double nbsubs;
  double simLimits[2];
  double repeatLayers[2];
  emxArray_real_T *this_data;
  emxArray_real_T *layers;
  emxInitArray_real_T(&reflectivity, 2);
  emxInitArray_real_T(&Simulation, 2);

  /* Initialize function 'callReflectivity' input arguments. */
  nbairs = argInit_real_T();
  nbsubs = argInit_real_T();

  /* Initialize function input argument 'simLimits'. */
  argInit_1x2_real_T(simLimits);

  /* Initialize function input argument 'repeatLayers'. */
  argInit_1x2_real_T(repeatLayers);

  /* Initialize function input argument 'this_data'. */
  this_data = argInit_Unboundedx3_real_T();

  /* Initialize function input argument 'layers'. */
  layers = argInit_Unboundedx3_real_T();

  /* Call the entry-point 'callReflectivity'. */
  callReflectivity(nbairs, nbsubs, simLimits, repeatLayers, this_data, layers,
                   argInit_real_T(), argInit_real_T(), argInit_real_T(),
                   reflectivity, Simulation);
  emxDestroyArray_real_T(Simulation);
  emxDestroyArray_real_T(reflectivity);
  emxDestroyArray_real_T(layers);
  emxDestroyArray_real_T(this_data);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  callReflectivity_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_callReflectivity();

  /* Terminate the application.
     You do not need to do this more than one time. */
  callReflectivity_terminate();
  return 0;
}

/* End of code generation (main.c) */
