/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custlay_single_initialize.c
 *
 * Code generation for function 'standardTF_custlay_single_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_custlay_single.h"
#include "standardTF_custlay_single_initialize.h"
#include "_coder_standardTF_custlay_single_mex.h"
#include "standardTF_custlay_single_data.h"

/* Function Declarations */
static void standardTF_custlay_single_once(void);

/* Function Definitions */
static void standardTF_custlay_single_once(void)
{
  covrtInstanceData *t0_data = NULL;
  int32_T cond_starts_4_0[1] = { 1318 };

  int32_T cond_ends_4_0[1] = { 1333 };

  int32_T postfix_exprs_4_0[2] = { 0, -1 };

  int32_T cond_starts_4_1[1] = { 2351 };

  int32_T cond_ends_4_1[1] = { 2366 };

  int32_T postfix_exprs_4_1[2] = { 0, -1 };

  int32_T caseStarts_4_0[3] = { -1, 1370, 1477 };

  int32_T caseExprEnds_4_0[3] = { 8, 1400, 1498 };

  int32_T cond_starts_11_0[1] = { 750 };

  int32_T cond_ends_11_0[1] = { 767 };

  int32_T postfix_exprs_11_0[2] = { 0, -1 };

  int32_T cond_starts_11_1[1] = { 924 };

  int32_T cond_ends_11_1[1] = { 940 };

  int32_T postfix_exprs_11_1[2] = { 0, -1 };

  int32_T caseStarts_11_0[2] = { 1103, 404 };

  int32_T caseExprEnds_11_0[2] = { 1112, 410 };

  int32_T cond_starts_15_0[1] = { 393 };

  int32_T cond_ends_15_0[1] = { 403 };

  int32_T postfix_exprs_15_0[2] = { 0, -1 };

  emlrtCoverageInstance.data = t0_data;

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",
                  0U, 1U, 5U, 1U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "standardTF_custlay_single", 0,
               -1, 2956);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 2562, -1, 2945);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 2491, -1, 2544);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 2402, -1, 2472);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 1859, -1, 2370);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 1232, -1, 1823);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 2377, 2393, 2478, 2553);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 1827, 1855, 2950);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",
                  1U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U, "backSort", 0, -1, 1976);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 1662, -1, 1965);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 1U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/call_customLayers.m",
                  2U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 2U, 0U, "call_customLayers", 0, -1, 213);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 0U, 92, -1, 207);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 2U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/eclipseWorkspace_new/matlabEngine_demo/src/matlabEngineCaller_customLayers.m",
                  3U, 1U, 8U, 4U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 3U, 0U, "matlabEngineCaller_customLayers",
               0, -1, 2317);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 7U, 2270, -1, 2302);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 6U, 2170, -1, 2223);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 5U, 1972, -1, 2113);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 4U, 1903, -1, 1928);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 3U, 639, -1, 1866);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 2U, 526, -1, 623);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 1U, 433, -1, 512);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 0U, 205, -1, 379);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 3U, 0U, 381, 406, 625, 2316);
  covrtIfInit(&emlrtCoverageInstance, 3U, 1U, 411, 424, -1, 521);
  covrtIfInit(&emlrtCoverageInstance, 3U, 2U, 1877, 1894, 2257, 2311);
  covrtIfInit(&emlrtCoverageInstance, 3U, 3U, 2127, 2153, -1, 2240);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 3U, 0U, 1938, 1960, 2252);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 3U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",
                  4U, 1U, 12U, 5U, 0U, 0U, 1U, 1U, 0U, 2U, 2U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 4U, 0U, "groupLayers_Mod", 0, -1, 2628);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 11U, 2580, -1, 2623);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 10U, 2387, -1, 2455);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 9U, 2295, -1, 2309);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 8U, 2237, -1, 2252);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 7U, 2157, -1, 2179);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 6U, 2075, -1, 2091);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 5U, 1988, -1, 2000);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 4U, 1911, -1, 1950);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 3U, 1783, -1, 1868);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 2U, 1515, -1, 1732);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 1U, 1417, -1, 1432);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 0U, 1250, -1, 1308);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 4U, 0U, 1314, 1333, -1, 2513);
  covrtIfInit(&emlrtCoverageInstance, 4U, 1U, 1750, 1762, 1886, 1971);
  covrtIfInit(&emlrtCoverageInstance, 4U, 2U, 2101, 2113, -1, 2504);
  covrtIfInit(&emlrtCoverageInstance, 4U, 3U, 2197, 2216, 2270, 2330);
  covrtIfInit(&emlrtCoverageInstance, 4U, 4U, 2347, 2366, -1, 2476);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 4U, 0U, 1317, 1333, 1, 0,
                cond_starts_4_0, cond_ends_4_0, 2, postfix_exprs_4_0);
  covrtMcdcInit(&emlrtCoverageInstance, 4U, 1U, 2350, 2366, 1, 1,
                cond_starts_4_1, cond_ends_4_1, 2, postfix_exprs_4_1);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 4U, 0U, 2126, 2141, 2492);

  /* Initialize While Information */
  /* Initialize Switch Information */
  covrtSwitchInit(&emlrtCoverageInstance, 4U, 0U, 1342, 1358, 2013, 3U,
                  caseStarts_4_0, caseExprEnds_4_0);

  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 4U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfiles.m",
                  5U, 1U, 4U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 5U, 0U, "makeSLDProfiles", 0, -1, 223);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 3U, 156, -1, 217);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 2U, 131, -1, 148);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 1U, 112, -1, 120);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 0U, 69, -1, 87);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 5U, 0U, 89, 107, 122, 153);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 5U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",
                  6U, 1U, 8U, 2U, 0U, 0U, 0U, 2U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 6U, 0U, "makeSLDProfileXY", 0, -1, 1962);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 7U, 1937, -1, 1956);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 6U, 1689, -1, 1917);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 5U, 1217, -1, 1678);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 4U, 894, -1, 1159);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 3U, 845, -1, 864);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 2U, 675, -1, 703);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 1U, 521, -1, 625);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 0U, 106, -1, 451);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 6U, 0U, 82, 101, 1680, 1922);
  covrtIfInit(&emlrtCoverageInstance, 6U, 1U, 639, 658, 824, 881);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 6U, 0U, 457, 476, 1212);
  covrtForInit(&emlrtCoverageInstance, 6U, 1U, 484, 509, 1204);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 6U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m",
                  7U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 7U, 0U, "asymconvstep", 0, -1, 1125);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 0U, 973, -1, 1121);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 7U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",
                  8U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 8U, 0U, "resampleLayers", 0, -1, 373);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 0U, 44, -1, 367);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 8U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",
                  9U, 1U, 9U, 2U, 0U, 0U, 0U, 1U, 1U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 9U, 0U, "resample_sld", 0, -1, 1187);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 5U, 575, -1, 738);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 4U, 513, -1, 553);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 3U, 447, -1, 486);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 2U, 302, -1, 399);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 1U, 196, -1, 227);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 8U, 1077, -1, 1183);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 7U, 966, -1, 1033);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 6U, 799, -1, 934);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 0U, 63, -1, 170);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 9U, 0U, 233, 263, 405, 747);
  covrtIfInit(&emlrtCoverageInstance, 9U, 1U, 418, 434, 496, 566);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 9U, 0U, 936, 961, 1038);

  /* Initialize While Information */
  covrtWhileInit(&emlrtCoverageInstance, 9U, 0U, 172, 192, 751);

  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 9U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m",
                  10U, 1U, 5U, 1U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 10U, 0U, "groupSamples", 0, -1, 567);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 4U, 494, -1, 555);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 3U, 348, -1, 475);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 2U, 248, -1, 329);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 1U, 186, -1, 211);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 0U, 54, -1, 152);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 10U, 0U, 217, 237, 335, 484);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 10U, 0U, 154, 181, 488);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 10U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m",
                  11U, 1U, 9U, 3U, 0U, 0U, 1U, 0U, 0U, 2U, 2U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 11U, 0U, "shiftdata", 0, -1, 1664);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 7U, 1058, -1, 1097);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 6U, 1000, -1, 1027);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 5U, 953, -1, 973);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 4U, 874, -1, 909);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 3U, 831, -1, 843);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 2U, 780, -1, 804);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 1U, 486, -1, 736);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 0U, 448, -1, 464);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 8U, 1121, -1, 1140);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 11U, 0U, 419, 435, -1, 477);
  covrtIfInit(&emlrtCoverageInstance, 11U, 1U, 746, 767, 814, 856);
  covrtIfInit(&emlrtCoverageInstance, 11U, 2U, 919, 940, 983, 1040);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 11U, 0U, 749, 767, 1, 0,
                cond_starts_11_0, cond_ends_11_0, 2, postfix_exprs_11_0);
  covrtMcdcInit(&emlrtCoverageInstance, 11U, 1U, 923, 940, 1, 1,
                cond_starts_11_1, cond_ends_11_1, 2, postfix_exprs_11_1);

  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  covrtSwitchInit(&emlrtCoverageInstance, 11U, 0U, 381, 400, 1145, 2U,
                  caseStarts_11_0, caseExprEnds_11_0);

  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 11U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",
                  12U, 1U, 9U, 3U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 12U, 0U, "callReflectivity", 0, -1, 1682);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 8U, 1067, -1, 1674);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 7U, 1044, -1, 1060);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 6U, 948, -1, 1033);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 5U, 897, -1, 914);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 4U, 810, -1, 886);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 3U, 706, -1, 782);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 2U, 654, -1, 699);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 1U, 610, -1, 643);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 0U, 545, -1, 584);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 12U, 0U, 587, 605, 645, 704);
  covrtIfInit(&emlrtCoverageInstance, 12U, 1U, 785, 805, 888, 919);
  covrtIfInit(&emlrtCoverageInstance, 12U, 2U, 921, 943, 1035, 1065);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 12U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/abeles.m",
                  13U, 1U, 5U, 0U, 0U, 0U, 0U, 3U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 13U, 0U, "abeles", 0, -1, 2049);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 4U, 2039, -1, 2045);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 3U, 1642, -1, 2032);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 2U, 933, -1, 1616);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 1U, 565, -1, 864);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 0U, 216, -1, 539);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 13U, 0U, 541, 561, 2037);
  covrtForInit(&emlrtCoverageInstance, 13U, 1U, 870, 895, 1637);
  covrtForInit(&emlrtCoverageInstance, 13U, 2U, 903, 921, 1629);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 13U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",
                  14U, 1U, 9U, 3U, 0U, 0U, 0U, 2U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 14U, 0U, "resolution_polly", 0, -1, 683);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 8U, 662, -1, 677);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 7U, 565, -1, 599);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 6U, 394, -1, 528);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 5U, 325, -1, 341);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 4U, 298, -1, 306);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 3U, 235, -1, 248);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 2U, 206, -1, 216);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 1U, 147, -1, 177);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 0U, 58, -1, 123);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 14U, 0U, 188, 197, 222, 257);
  covrtIfInit(&emlrtCoverageInstance, 14U, 1U, 267, 289, 312, 350);
  covrtIfInit(&emlrtCoverageInstance, 14U, 2U, 542, 556, -1, 608);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 14U, 0U, 126, 143, 660);
  covrtForInit(&emlrtCoverageInstance, 14U, 1U, 369, 386, 537);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 14U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m",
                  15U, 1U, 5U, 2U, 0U, 0U, 0U, 0U, 0U, 1U, 1U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 15U, 0U, "chiSquared", 0, -1, 498);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 4U, 438, -1, 463);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 3U, 412, -1, 424);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 2U, 331, -1, 383);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 1U, 306, -1, 317);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 0U, 190, -1, 282);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 15U, 0U, 288, 297, -1, 326);
  covrtIfInit(&emlrtCoverageInstance, 15U, 1U, 389, 403, -1, 433);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 15U, 0U, 392, 403, 1, 0,
                cond_starts_15_0, cond_ends_15_0, 2, postfix_exprs_15_0);

  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 15U);
}

void standardTF_custlay_single_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    standardTF_custlay_single_once();
  }
}

/* End of code generation (standardTF_custlay_single_initialize.c) */
