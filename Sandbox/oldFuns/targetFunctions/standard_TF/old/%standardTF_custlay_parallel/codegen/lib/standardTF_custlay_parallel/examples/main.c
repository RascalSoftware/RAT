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
#include "standardTF_custlay_parallel.h"
#include "main.h"
#include "standardTF_custlay_parallel_terminate.h"
#include "standardTF_custlay_parallel_emxAPI.h"
#include "standardTF_custlay_parallel_initialize.h"

/* Function Declarations */
static void argInit_1x2_real_T(double result[2]);
static emxArray_cell_wrap_0 *argInit_1xUnbounded_cell_wrap_0(void);
static emxArray_cell_wrap_1 *argInit_1xUnbounded_cell_wrap_1(void);
static emxArray_cell_wrap_2 *argInit_1xUnbounded_cell_wrap_2(void);
static emxArray_char_T *argInit_1xUnbounded_char_T(void);
static emxArray_real_T *argInit_1xUnbounded_real_T(void);
static emxArray_real_T *argInit_Unboundedx1_real_T(void);
static emxArray_real_T *argInit_Unboundedx3_real_T(void);
static cell_wrap_0 argInit_cell_wrap_0(void);
static cell_wrap_1 argInit_cell_wrap_1(void);
static char argInit_char_T(void);
static double argInit_real_T(void);
static void c_main_standardTF_custlay_paral(void);

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

static emxArray_cell_wrap_0 *argInit_1xUnbounded_cell_wrap_0(void)
{
  emxArray_cell_wrap_0 *result;
  static int iv3[2] = { 1, 2 };

  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_cell_wrap_0(2, iv3);

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[result->size[0] * idx1] = argInit_cell_wrap_0();
  }

  return result;
}

static emxArray_cell_wrap_1 *argInit_1xUnbounded_cell_wrap_1(void)
{
  emxArray_cell_wrap_1 *result;
  static int iv4[2] = { 1, 2 };

  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_cell_wrap_1(2, iv4);

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[result->size[0] * idx1] = argInit_cell_wrap_1();
  }

  return result;
}

static emxArray_cell_wrap_2 *argInit_1xUnbounded_cell_wrap_2(void)
{
  emxArray_cell_wrap_2 *result;
  static int iv6[2] = { 1, 2 };

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_cell_wrap_2(2, iv6);

  /* Loop over the array to initialize each element. */
  return result;
}

static emxArray_char_T *argInit_1xUnbounded_char_T(void)
{
  emxArray_char_T *result;
  static int iv1[2] = { 1, 2 };

  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_char_T(2, iv1);

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[result->size[0] * idx1] = argInit_char_T();
  }

  return result;
}

static emxArray_real_T *argInit_1xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  static int iv2[2] = { 1, 2 };

  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(2, iv2);

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[result->size[0] * idx1] = argInit_real_T();
  }

  return result;
}

static emxArray_real_T *argInit_Unboundedx1_real_T(void)
{
  emxArray_real_T *result;
  static int iv0[1] = { 2 };

  int idx0;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(1, iv0);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0] = argInit_real_T();
  }

  return result;
}

static emxArray_real_T *argInit_Unboundedx3_real_T(void)
{
  emxArray_real_T *result;
  static int iv5[2] = { 2, 3 };

  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(2, iv5);

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

static cell_wrap_0 argInit_cell_wrap_0(void)
{
  cell_wrap_0 result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x2_real_T(result.f1);
  return result;
}

static cell_wrap_1 argInit_cell_wrap_1(void)
{
  cell_wrap_1 result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result.f1 = argInit_Unboundedx3_real_T();
  return result;
}

static char argInit_char_T(void)
{
  return '?';
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void c_main_standardTF_custlay_paral(void)
{
  emxArray_real_T *outSsubs;
  emxArray_real_T *backgs;
  emxArray_real_T *qshifts;
  emxArray_real_T *sfs;
  emxArray_real_T *nbas;
  emxArray_real_T *nbss;
  emxArray_real_T *resols;
  emxArray_real_T *chis;
  emxArray_cell_wrap_3 *reflectivity;
  emxArray_cell_wrap_3 *Simulation;
  emxArray_cell_wrap_1 *shifted_data;
  emxArray_cell_wrap_1 *layerSlds;
  emxArray_cell_wrap_3 *sldProfiles;
  emxArray_cell_wrap_4 *allLayers;
  emxArray_real_T *allRoughs;
  emxArray_real_T *resam;
  double numberOfContrasts;
  emxArray_char_T *geometry;
  emxArray_real_T *nbairs;
  emxArray_real_T *nbsubs;
  emxArray_cell_wrap_0 *repeats;
  emxArray_real_T *cBacks;
  emxArray_real_T *cShifts;
  emxArray_real_T *cScales;
  emxArray_real_T *cNbas;
  emxArray_real_T *cNbss;
  emxArray_real_T *cRes;
  emxArray_real_T *backs;
  emxArray_real_T *shifts;
  emxArray_real_T *sf;
  emxArray_real_T *nba;
  emxArray_real_T *nbs;
  emxArray_real_T *res;
  emxArray_real_T *dataPresent;
  emxArray_cell_wrap_1 *allData;
  emxArray_cell_wrap_0 *dataLimits;
  emxArray_cell_wrap_0 *simLimits;
  emxArray_cell_wrap_0 *repeatLayers;
  double nParams;
  emxArray_real_T *params;
  emxArray_cell_wrap_2 *contrastLayers;
  double numberOfLayers;
  double whichType;
  emxArray_char_T *fileHandle;
  emxArray_char_T *path;
  emxInitArray_real_T(&outSsubs, 1);
  emxInitArray_real_T(&backgs, 1);
  emxInitArray_real_T(&qshifts, 1);
  emxInitArray_real_T(&sfs, 1);
  emxInitArray_real_T(&nbas, 1);
  emxInitArray_real_T(&nbss, 1);
  emxInitArray_real_T(&resols, 1);
  emxInitArray_real_T(&chis, 1);
  emxInitArray_cell_wrap_3(&reflectivity, 2);
  emxInitArray_cell_wrap_3(&Simulation, 2);
  emxInitArray_cell_wrap_1(&shifted_data, 2);
  emxInitArray_cell_wrap_1(&layerSlds, 2);
  emxInitArray_cell_wrap_3(&sldProfiles, 2);
  emxInitArray_cell_wrap_4(&allLayers, 2);
  emxInitArray_real_T(&allRoughs, 1);

  /* Initialize function 'standardTF_custlay_parallel' input arguments. */
  /* Initialize function input argument 'resam'. */
  resam = argInit_Unboundedx1_real_T();
  numberOfContrasts = argInit_real_T();

  /* Initialize function input argument 'geometry'. */
  geometry = argInit_1xUnbounded_char_T();

  /* Initialize function input argument 'nbairs'. */
  nbairs = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'nbsubs'. */
  nbsubs = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'repeats'. */
  repeats = argInit_1xUnbounded_cell_wrap_0();

  /* Initialize function input argument 'cBacks'. */
  cBacks = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'cShifts'. */
  cShifts = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'cScales'. */
  cScales = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'cNbas'. */
  cNbas = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'cNbss'. */
  cNbss = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'cRes'. */
  cRes = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'backs'. */
  backs = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'shifts'. */
  shifts = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'sf'. */
  sf = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'nba'. */
  nba = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'nbs'. */
  nbs = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'res'. */
  res = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'dataPresent'. */
  dataPresent = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'allData'. */
  allData = argInit_1xUnbounded_cell_wrap_1();

  /* Initialize function input argument 'dataLimits'. */
  dataLimits = argInit_1xUnbounded_cell_wrap_0();

  /* Initialize function input argument 'simLimits'. */
  simLimits = argInit_1xUnbounded_cell_wrap_0();

  /* Initialize function input argument 'repeatLayers'. */
  repeatLayers = argInit_1xUnbounded_cell_wrap_0();
  nParams = argInit_real_T();

  /* Initialize function input argument 'params'. */
  params = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'contrastLayers'. */
  contrastLayers = argInit_1xUnbounded_cell_wrap_2();
  numberOfLayers = argInit_real_T();

  /* Initialize function input argument 'layersDetails'. */
  whichType = argInit_real_T();

  /* Initialize function input argument 'fileHandle'. */
  fileHandle = argInit_1xUnbounded_char_T();

  /* Initialize function input argument 'path'. */
  path = argInit_1xUnbounded_char_T();

  /* Call the entry-point 'standardTF_custlay_parallel'. */
  standardTF_custlay_parallel(resam, numberOfContrasts, geometry, nbairs, nbsubs,
    repeats, cBacks, cShifts, cScales, cNbas, cNbss, cRes, backs, shifts, sf,
    nba, nbs, res, dataPresent, allData, dataLimits, simLimits, repeatLayers,
    nParams, params, contrastLayers, numberOfLayers, whichType, fileHandle, path,
    outSsubs, backgs, qshifts, sfs, nbas, nbss, resols, chis, reflectivity,
    Simulation, shifted_data, layerSlds, sldProfiles, allLayers, allRoughs);
  emxDestroyArray_real_T(allRoughs);
  emxDestroyArray_cell_wrap_4(allLayers);
  emxDestroyArray_cell_wrap_3(sldProfiles);
  emxDestroyArray_cell_wrap_1(layerSlds);
  emxDestroyArray_cell_wrap_1(shifted_data);
  emxDestroyArray_cell_wrap_3(Simulation);
  emxDestroyArray_cell_wrap_3(reflectivity);
  emxDestroyArray_real_T(chis);
  emxDestroyArray_real_T(resols);
  emxDestroyArray_real_T(nbss);
  emxDestroyArray_real_T(nbas);
  emxDestroyArray_real_T(sfs);
  emxDestroyArray_real_T(qshifts);
  emxDestroyArray_real_T(backgs);
  emxDestroyArray_real_T(outSsubs);
  emxDestroyArray_char_T(path);
  emxDestroyArray_char_T(fileHandle);
  emxDestroyArray_cell_wrap_2(contrastLayers);
  emxDestroyArray_real_T(params);
  emxDestroyArray_cell_wrap_0(repeatLayers);
  emxDestroyArray_cell_wrap_0(simLimits);
  emxDestroyArray_cell_wrap_0(dataLimits);
  emxDestroyArray_cell_wrap_1(allData);
  emxDestroyArray_real_T(dataPresent);
  emxDestroyArray_real_T(res);
  emxDestroyArray_real_T(nbs);
  emxDestroyArray_real_T(nba);
  emxDestroyArray_real_T(sf);
  emxDestroyArray_real_T(shifts);
  emxDestroyArray_real_T(backs);
  emxDestroyArray_real_T(cRes);
  emxDestroyArray_real_T(cNbss);
  emxDestroyArray_real_T(cNbas);
  emxDestroyArray_real_T(cScales);
  emxDestroyArray_real_T(cShifts);
  emxDestroyArray_real_T(cBacks);
  emxDestroyArray_cell_wrap_0(repeats);
  emxDestroyArray_real_T(nbsubs);
  emxDestroyArray_real_T(nbairs);
  emxDestroyArray_char_T(geometry);
  emxDestroyArray_real_T(resam);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  standardTF_custlay_parallel_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  c_main_standardTF_custlay_paral();

  /* Terminate the application.
     You do not need to do this more than one time. */
  standardTF_custlay_parallel_terminate();
  return 0;
}

/* End of code generation (main.c) */
