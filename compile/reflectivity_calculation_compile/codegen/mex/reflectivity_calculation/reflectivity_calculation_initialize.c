/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * reflectivity_calculation_initialize.c
 *
 * Code generation for function 'reflectivity_calculation_initialize'
 *
 */

/* Include files */
#include "reflectivity_calculation_initialize.h"
#include "_coder_reflectivity_calculation_mex.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void reflectivity_calculation_once(void);

/* Function Definitions */
static void reflectivity_calculation_once(void)
{
  const int32_T caseStarts_0_0[2] = { -1, 1465 };

  const int32_T caseExprEnds_0_0[2] = { 8, 1482 };

  const int32_T caseStarts_1_0[3] = { -1, 1485, 1717 };

  const int32_T caseExprEnds_1_0[3] = { 8, 1498, 1737 };

  const int32_T caseStarts_2_0[5] = { -1, 1381, 1691, 1992, 2323 };

  const int32_T caseExprEnds_2_0[5] = { 8, 1394, 1704, 2008, 2333 };

  const int32_T cond_starts_6_0[1] = { 507 };

  const int32_T cond_ends_6_0[1] = { 521 };

  const int32_T postfix_exprs_6_0[2] = { 0, -1 };

  const int32_T cond_starts_9_0[2] = { 2529, 2546 };

  const int32_T cond_ends_9_0[2] = { 2542, 2558 };

  const int32_T postfix_exprs_9_0[3] = { 0, 1, -3 };

  const int32_T cond_starts_10_0[1] = { 1830 };

  const int32_T cond_ends_10_0[1] = { 1845 };

  const int32_T postfix_exprs_10_0[2] = { 0, -1 };

  const int32_T cond_starts_10_1[1] = { 2843 };

  const int32_T cond_ends_10_1[1] = { 2858 };

  const int32_T postfix_exprs_10_1[2] = { 0, -1 };

  const int32_T cond_starts_10_2[1] = { 3076 };

  const int32_T cond_ends_10_2[1] = { 3091 };

  const int32_T postfix_exprs_10_2[2] = { 0, -1 };

  const int32_T cond_starts_16_0[1] = { 587 };

  const int32_T cond_ends_16_0[1] = { 601 };

  const int32_T postfix_exprs_16_0[2] = { 0, -1 };

  const int32_T cond_starts_17_0[1] = { 750 };

  const int32_T cond_ends_17_0[1] = { 767 };

  const int32_T postfix_exprs_17_0[2] = { 0, -1 };

  const int32_T cond_starts_17_1[1] = { 924 };

  const int32_T cond_ends_17_1[1] = { 940 };

  const int32_T postfix_exprs_17_1[2] = { 0, -1 };

  const int32_T caseStarts_17_0[2] = { 1103, 404 };

  const int32_T caseExprEnds_17_0[2] = { 1112, 410 };

  const int32_T caseStarts_18_0[2] = { -1, 1349 };

  const int32_T caseExprEnds_18_0[2] = { 8, 1379 };

  const int32_T caseStarts_18_1[2] = { 1754, 1412 };

  const int32_T caseExprEnds_18_1[2] = { 1763, 1425 };

  const int32_T caseStarts_21_0[3] = { -1, 133, 253 };

  const int32_T caseExprEnds_21_0[3] = { 8, 139, 259 };

  const int32_T cond_starts_22_0[1] = { 393 };

  const int32_T cond_ends_22_0[1] = { 403 };

  const int32_T postfix_exprs_22_0[2] = { 0, -1 };

  const int32_T caseStarts_28_0[4] = { -1, 2910, 3507, 4117 };

  const int32_T caseExprEnds_28_0[4] = { 8, 2923, 3520, 4133 };

  const int32_T cond_starts_31_0[1] = { 624 };

  const int32_T cond_ends_31_0[1] = { 637 };

  const int32_T postfix_exprs_31_0[2] = { 0, -1 };

  mex_InitInfAndNan();

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile/reflectivity_calculation.m",
                  0U, 1U, 27U, 0U, 0U, 0U, 1U, 12U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "reflectivity_calculation", 1, -1,
               3447);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 26U, 2858, -1, 3441);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 25U, 2837, -1, 2851);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 24U, 2729, -1, 2803);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 23U, 2697, -1, 2722);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 22U, 2589, -1, 2663);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 21U, 2560, -1, 2583);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 20U, 2452, -1, 2526);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 19U, 2419, -1, 2445);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 18U, 2311, -1, 2385);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 17U, 2281, -1, 2305);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 16U, 2175, -1, 2247);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 15U, 2143, -1, 2169);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 14U, 2022, -1, 2109);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 13U, 1491, -1, 1662);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 12U, 1328, -1, 1444);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 11U, 1300, -1, 1322);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 10U, 1179, -1, 1266);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 9U, 1145, -1, 1173);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 8U, 1024, -1, 1111);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 7U, 988, -1, 1018);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 6U, 866, -1, 954);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 5U, 827, -1, 860);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 704, -1, 793);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 671, -1, 698);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 548, -1, 637);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 513, -1, 542);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 137, -1, 479);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 481, 509, 547);
  covrtForInit(&emlrtCoverageInstance, 0U, 1U, 639, 667, 703);
  covrtForInit(&emlrtCoverageInstance, 0U, 2U, 795, 823, 865);
  covrtForInit(&emlrtCoverageInstance, 0U, 3U, 956, 984, 1023);
  covrtForInit(&emlrtCoverageInstance, 0U, 4U, 1113, 1141, 1178);
  covrtForInit(&emlrtCoverageInstance, 0U, 5U, 1268, 1296, 1327);
  covrtForInit(&emlrtCoverageInstance, 0U, 6U, 2111, 2139, 2174);
  covrtForInit(&emlrtCoverageInstance, 0U, 7U, 2249, 2277, 2310);
  covrtForInit(&emlrtCoverageInstance, 0U, 8U, 2387, 2415, 2451);
  covrtForInit(&emlrtCoverageInstance, 0U, 9U, 2528, 2556, 2588);
  covrtForInit(&emlrtCoverageInstance, 0U, 10U, 2665, 2693, 2728);
  covrtForInit(&emlrtCoverageInstance, 0U, 11U, 2805, 2833, 2857);

  /* Initialize While Information */
  /* Initialize Switch Information */
  covrtSwitchInit(&emlrtCoverageInstance, 0U, 0U, 1446, 1461, 2019, 2U,
                  caseStarts_0_0, caseExprEnds_0_0);

  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",
                  1U, 1U, 14U, 0U, 0U, 0U, 1U, 6U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U,
               "standardTF_reflectivityCalculation", 0, -1, 2212);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 13U, 1746, -1, 1957);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 12U, 1507, -1, 1711);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 11U, 1429, -1, 1451);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 10U, 1358, -1, 1395);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 9U, 1323, -1, 1351);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 8U, 1250, -1, 1289);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 7U, 1213, -1, 1243);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 6U, 1142, -1, 1179);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 5U, 1102, -1, 1135);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 4U, 1028, -1, 1068);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 3U, 994, -1, 1021);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 2U, 922, -1, 960);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 1U, 886, -1, 915);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 250, -1, 852);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 1U, 0U, 854, 882, 920);
  covrtForInit(&emlrtCoverageInstance, 1U, 1U, 962, 990, 1026);
  covrtForInit(&emlrtCoverageInstance, 1U, 2U, 1070, 1098, 1140);
  covrtForInit(&emlrtCoverageInstance, 1U, 3U, 1181, 1209, 1248);
  covrtForInit(&emlrtCoverageInstance, 1U, 4U, 1291, 1319, 1356);
  covrtForInit(&emlrtCoverageInstance, 1U, 5U, 1397, 1425, 1456);

  /* Initialize While Information */
  /* Initialize Switch Information */
  covrtSwitchInit(&emlrtCoverageInstance, 1U, 0U, 1469, 1481, 2207, 3U,
                  caseStarts_1_0, caseExprEnds_1_0);

  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 1U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",
                  2U, 1U, 18U, 0U, 0U, 0U, 1U, 6U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 2U, 0U,
               "standardTF_stanLay_reflectivityCalculation", 0, -1, 2923);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 17U, 2619, -1, 2917);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 16U, 2345, -1, 2611);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 15U, 2028, -1, 2300);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 14U, 1716, -1, 1985);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 13U, 1418, -1, 1683);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 12U, 1342, -1, 1362);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 11U, 1313, -1, 1335);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 10U, 1242, -1, 1279);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 9U, 1208, -1, 1235);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 8U, 1135, -1, 1174);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 7U, 1099, -1, 1128);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 6U, 1028, -1, 1065);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 5U, 989, -1, 1021);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 4U, 915, -1, 955);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 3U, 881, -1, 908);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 2U, 809, -1, 847);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 1U, 773, -1, 802);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 0U, 318, -1, 739);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 2U, 0U, 741, 769, 807);
  covrtForInit(&emlrtCoverageInstance, 2U, 1U, 849, 877, 913);
  covrtForInit(&emlrtCoverageInstance, 2U, 2U, 957, 985, 1026);
  covrtForInit(&emlrtCoverageInstance, 2U, 3U, 1067, 1095, 1133);
  covrtForInit(&emlrtCoverageInstance, 2U, 4U, 1176, 1204, 1240);
  covrtForInit(&emlrtCoverageInstance, 2U, 5U, 1281, 1309, 1340);

  /* Initialize While Information */
  /* Initialize Switch Information */
  covrtSwitchInit(&emlrtCoverageInstance, 2U, 0U, 1365, 1377, 2617, 5U,
                  caseStarts_2_0, caseExprEnds_2_0);

  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 2U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",
                  3U, 1U, 8U, 0U, 0U, 0U, 0U, 4U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 3U, 0U, "standardTF_stanlay_single", 1,
               -1, 4468);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 7U, 2155, -1, 4280);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 6U, 1781, -1, 1851);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 5U, 1537, -1, 1559);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 4U, 1466, -1, 1503);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 3U, 1432, -1, 1459);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 2U, 1360, -1, 1398);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 1U, 1324, -1, 1353);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 0U, 284, -1, 1290);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 3U, 0U, 1292, 1320, 1358);
  covrtForInit(&emlrtCoverageInstance, 3U, 1U, 1400, 1428, 1464);
  covrtForInit(&emlrtCoverageInstance, 3U, 2U, 1505, 1533, 1564);
  covrtForInit(&emlrtCoverageInstance, 3U, 3U, 1884, 1912, 4285);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 3U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/API/RAT_parse_cells.m",
                  4U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 4U, 0U, "RAT_parse_cells", 0, -1, 332);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 0U, 119, -1, 326);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 4U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m",
                  5U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 5U, 0U, "extractProblemParams", 0, -1,
               931);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 0U, 277, -1, 924);

  /* Initialize If Information */
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
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",
                  6U, 1U, 6U, 1U, 0U, 0U, 0U, 2U, 0U, 1U, 1U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 6U, 0U, "allocateParamsToLayers", 0, -1,
               732);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 5U, 641, -1, 722);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 4U, 594, -1, 615);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 3U, 534, -1, 567);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 2U, 471, -1, 493);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 1U, 397, -1, 425);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 0U, 264, -1, 365);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 6U, 0U, 503, 521, 577, 628);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 6U, 0U, 506, 521, 1, 0, cond_starts_6_0,
                cond_ends_6_0, 2, postfix_exprs_6_0);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 6U, 0U, 368, 393, 727);
  covrtForInit(&emlrtCoverageInstance, 6U, 1U, 431, 463, 636);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 6U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",
                  7U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 7U, 0U, "backSort", 0, -1, 1986);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 0U, 1664, -1, 1967);

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
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m",
                  8U, 1U, 2U, 0U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 8U, 0U, "allocateLayersForContrast", 0,
               -1, 380);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 1U, 276, -1, 370);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 0U, 184, -1, 236);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 8U, 0U, 239, 272, 375);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 8U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_layers_core.m",
                  9U, 1U, 7U, 3U, 0U, 0U, 0U, 0U, 0U, 2U, 1U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 9U, 0U, "standardTF_layers_core", 0, -1,
               3472);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 6U, 2947, -1, 3466);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 5U, 2871, -1, 2893);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 4U, 2823, -1, 2860);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 3U, 2738, -1, 2758);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 2U, 2659, -1, 2727);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 1U, 2564, -1, 2575);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 0U, 2289, -1, 2366);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 9U, 0U, 2525, 2559, -1, 2580);
  covrtIfInit(&emlrtCoverageInstance, 9U, 1U, 2639, 2654, 2729, 2763);
  covrtIfInit(&emlrtCoverageInstance, 9U, 2U, 2802, 2818, 2862, 2898);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 9U, 0U, 2529, 2558, 2, 0,
                cond_starts_9_0, cond_ends_9_0, 3, postfix_exprs_9_0);

  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 9U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",
                  10U, 1U, 14U, 7U, 0U, 0U, 0U, 1U, 0U, 3U, 3U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 10U, 0U, "groupLayers_Mod", 0, -1, 3183);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 13U, 3160, -1, 3176);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 12U, 3132, -1, 3154);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 11U, 3096, -1, 3121);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 10U, 2879, -1, 2947);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 9U, 2786, -1, 2801);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 8U, 2729, -1, 2743);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 7U, 2649, -1, 2671);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 6U, 2543, -1, 2589);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 5U, 2456, -1, 2468);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 4U, 2379, -1, 2418);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 3U, 2251, -1, 2336);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 2U, 1984, -1, 2203);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 1U, 1907, -1, 1922);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 0U, 1646, -1, 1820);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 10U, 0U, 1826, 1845, -1, 3005);
  covrtIfInit(&emlrtCoverageInstance, 10U, 1U, 1854, 1890, 1963, 2481);
  covrtIfInit(&emlrtCoverageInstance, 10U, 2U, 2221, 2230, 2354, 2439);
  covrtIfInit(&emlrtCoverageInstance, 10U, 3U, 2599, 2608, -1, 2996);
  covrtIfInit(&emlrtCoverageInstance, 10U, 4U, 2689, 2708, 2761, 2822);
  covrtIfInit(&emlrtCoverageInstance, 10U, 5U, 2839, 2858, -1, 2968);
  covrtIfInit(&emlrtCoverageInstance, 10U, 6U, 3072, 3091, 3123, 3159);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 10U, 0U, 1829, 1845, 1, 0,
                cond_starts_10_0, cond_ends_10_0, 2, postfix_exprs_10_0);
  covrtMcdcInit(&emlrtCoverageInstance, 10U, 1U, 2842, 2858, 1, 1,
                cond_starts_10_1, cond_ends_10_1, 2, postfix_exprs_10_1);
  covrtMcdcInit(&emlrtCoverageInstance, 10U, 2U, 3075, 3091, 1, 2,
                cond_starts_10_2, cond_ends_10_2, 2, postfix_exprs_10_2);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 10U, 0U, 2621, 2633, 2984);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 10U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfiles.m",
                  11U, 1U, 4U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 11U, 0U, "makeSLDProfiles", 0, -1, 223);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 3U, 156, -1, 217);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 2U, 131, -1, 148);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 1U, 112, -1, 120);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 0U, 69, -1, 87);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 11U, 0U, 89, 107, 122, 153);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 11U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",
                  12U, 1U, 8U, 2U, 0U, 0U, 0U, 2U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 12U, 0U, "makeSLDProfileXY", 0, -1, 1962);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 7U, 1937, -1, 1956);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 6U, 1689, -1, 1917);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 5U, 1217, -1, 1678);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 4U, 894, -1, 1159);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 3U, 845, -1, 864);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 2U, 675, -1, 703);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 1U, 521, -1, 625);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 0U, 106, -1, 451);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 12U, 0U, 82, 101, 1680, 1922);
  covrtIfInit(&emlrtCoverageInstance, 12U, 1U, 639, 658, 824, 881);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 12U, 0U, 457, 476, 1212);
  covrtForInit(&emlrtCoverageInstance, 12U, 1U, 484, 509, 1204);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 12U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m",
                  13U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 13U, 0U, "asymconvstep", 0, -1, 1125);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 0U, 973, -1, 1121);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 13U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",
                  14U, 1U, 6U, 1U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 14U, 0U, "resampleLayers", 1, -1, 874);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 5U, 853, -1, 868);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 4U, 804, -1, 847);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 3U, 745, -1, 785);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 2U, 686, -1, 726);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 1U, 534, -1, 655);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 0U, 116, -1, 448);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 14U, 0U, 661, 677, 732, 794);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 14U, 0U, 505, 530, 852);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 14U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",
                  15U, 6U, 19U, 9U, 0U, 0U, 0U, 2U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 15U, 0U, "adaptive", 0, -1, 13051);
  covrtFcnInit(&emlrtCoverageInstance, 15U, 1U, "normalizeFunction", 13070, -1,
               14220);
  covrtFcnInit(&emlrtCoverageInstance, 15U, 2U, "calculateTrianglesSides", 14222,
               -1, 14664);
  covrtFcnInit(&emlrtCoverageInstance, 15U, 3U, "calculateCentralAngles", 14666,
               -1, 15649);
  covrtFcnInit(&emlrtCoverageInstance, 15U, 4U, "calculateTrianglesArea", 15651,
               -1, 16079);
  covrtFcnInit(&emlrtCoverageInstance, 15U, 5U, "increaseSampling", 16081, -1,
               16702);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 12U, 12986, -1, 13042);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 11U, 12946, -1, 12965);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 10U, 12345, -1, 12415);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 9U, 12095, -1, 12304);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 8U, 11660, -1, 12059);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 7U, 11557, -1, 11630);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 6U, 11203, -1, 11372);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 5U, 10994, -1, 11167);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 4U, 10559, -1, 10966);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 3U, 9991, -1, 10202);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 2U, 9600, -1, 9693);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 1U, 9400, -1, 9425);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 0U, 6435, -1, 8353);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 14U, 14173, -1, 14204);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 13U, 13541, -1, 13730);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 15U, 14507, -1, 14659);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 16U, 14989, -1, 15644);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 17U, 15926, -1, 16074);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 18U, 16224, -1, 16697);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 15U, 0U, 9376, 9397, -1, 9430);
  covrtIfInit(&emlrtCoverageInstance, 15U, 1U, 9571, 9597, -1, 9698);
  covrtIfInit(&emlrtCoverageInstance, 15U, 2U, 10970, 10989, -1, 11174);
  covrtIfInit(&emlrtCoverageInstance, 15U, 3U, 11177, 11198, -1, 11379);
  covrtIfInit(&emlrtCoverageInstance, 15U, 4U, 11634, 11655, -1, 12066);
  covrtIfInit(&emlrtCoverageInstance, 15U, 5U, 12069, 12090, -1, 12311);
  covrtIfInit(&emlrtCoverageInstance, 15U, 6U, 12317, 12340, -1, 12444);
  covrtIfInit(&emlrtCoverageInstance, 15U, 7U, 12930, 12943, 12967, 12983);
  covrtIfInit(&emlrtCoverageInstance, 15U, 8U, 12967, 12983, -1, 12983);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 15U, 0U, 10459, 10495, 12647);
  covrtForInit(&emlrtCoverageInstance, 15U, 1U, 13984, 14004, 14211);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 15U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m",
                  16U, 1U, 5U, 2U, 0U, 0U, 0U, 0U, 0U, 1U, 1U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 16U, 0U, "sldFunc", 0, -1, 1122);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 16U, 4U, 1045, -1, 1069);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16U, 3U, 1002, -1, 1026);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16U, 2U, 636, -1, 964);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16U, 1U, 606, -1, 625);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16U, 0U, 529, -1, 580);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 16U, 0U, 583, 601, 627, 1119);
  covrtIfInit(&emlrtCoverageInstance, 16U, 1U, 975, 993, 1032, 1078);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 16U, 0U, 586, 601, 1, 0,
                cond_starts_16_0, cond_ends_16_0, 2, postfix_exprs_16_0);

  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 16U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m",
                  17U, 1U, 9U, 3U, 0U, 0U, 1U, 0U, 0U, 2U, 2U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 17U, 0U, "shiftdata", 0, -1, 1664);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 17U, 7U, 1058, -1, 1097);
  covrtBasicBlockInit(&emlrtCoverageInstance, 17U, 6U, 1000, -1, 1027);
  covrtBasicBlockInit(&emlrtCoverageInstance, 17U, 5U, 953, -1, 973);
  covrtBasicBlockInit(&emlrtCoverageInstance, 17U, 4U, 874, -1, 909);
  covrtBasicBlockInit(&emlrtCoverageInstance, 17U, 3U, 831, -1, 843);
  covrtBasicBlockInit(&emlrtCoverageInstance, 17U, 2U, 780, -1, 804);
  covrtBasicBlockInit(&emlrtCoverageInstance, 17U, 1U, 486, -1, 736);
  covrtBasicBlockInit(&emlrtCoverageInstance, 17U, 0U, 448, -1, 464);
  covrtBasicBlockInit(&emlrtCoverageInstance, 17U, 8U, 1121, -1, 1140);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 17U, 0U, 419, 435, -1, 477);
  covrtIfInit(&emlrtCoverageInstance, 17U, 1U, 746, 767, 814, 856);
  covrtIfInit(&emlrtCoverageInstance, 17U, 2U, 919, 940, 983, 1040);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 17U, 0U, 749, 767, 1, 0,
                cond_starts_17_0, cond_ends_17_0, 2, postfix_exprs_17_0);
  covrtMcdcInit(&emlrtCoverageInstance, 17U, 1U, 923, 940, 1, 1,
                cond_starts_17_1, cond_ends_17_1, 2, postfix_exprs_17_1);

  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  covrtSwitchInit(&emlrtCoverageInstance, 17U, 0U, 381, 400, 1145, 2U,
                  caseStarts_17_0, caseExprEnds_17_0);

  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 17U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",
                  18U, 1U, 12U, 3U, 0U, 0U, 2U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 18U, 0U, "callReflectivity", 0, -1, 2096);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 11U, 2013, -1, 2090);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 9U, 1484, -1, 1723);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 10U, 1823, -1, 1993);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 8U, 1082, -1, 1327);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 7U, 1059, -1, 1075);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 6U, 963, -1, 1048);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 5U, 912, -1, 929);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 4U, 825, -1, 901);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 3U, 706, -1, 797);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 2U, 654, -1, 699);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 1U, 610, -1, 643);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 0U, 545, -1, 584);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 18U, 0U, 587, 605, 645, 704);
  covrtIfInit(&emlrtCoverageInstance, 18U, 1U, 800, 820, 903, 934);
  covrtIfInit(&emlrtCoverageInstance, 18U, 2U, 936, 958, 1050, 1080);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  covrtSwitchInit(&emlrtCoverageInstance, 18U, 0U, 1330, 1345, 2010, 2U,
                  caseStarts_18_0, caseExprEnds_18_0);
  covrtSwitchInit(&emlrtCoverageInstance, 18U, 1U, 1388, 1400, 2006, 2U,
                  caseStarts_18_1, caseExprEnds_18_1);

  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 18U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/reflectivityCalculations/Abeles/abeles_single.m",
                  19U, 1U, 5U, 0U, 0U, 0U, 0U, 3U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 19U, 0U, "abeles_single", 0, -1, 2110);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 19U, 4U, 2100, -1, 2106);
  covrtBasicBlockInit(&emlrtCoverageInstance, 19U, 3U, 1700, -1, 2093);
  covrtBasicBlockInit(&emlrtCoverageInstance, 19U, 2U, 964, -1, 1674);
  covrtBasicBlockInit(&emlrtCoverageInstance, 19U, 1U, 596, -1, 895);
  covrtBasicBlockInit(&emlrtCoverageInstance, 19U, 0U, 225, -1, 570);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 19U, 0U, 572, 592, 2098);
  covrtForInit(&emlrtCoverageInstance, 19U, 1U, 901, 926, 1695);
  covrtForInit(&emlrtCoverageInstance, 19U, 2U, 934, 952, 1687);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 19U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m",
                  20U, 1U, 9U, 3U, 0U, 0U, 0U, 2U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 20U, 0U, "resolution_polly", 0, -1, 635);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 20U, 8U, 614, -1, 629);
  covrtBasicBlockInit(&emlrtCoverageInstance, 20U, 7U, 565, -1, 599);
  covrtBasicBlockInit(&emlrtCoverageInstance, 20U, 6U, 394, -1, 528);
  covrtBasicBlockInit(&emlrtCoverageInstance, 20U, 5U, 325, -1, 341);
  covrtBasicBlockInit(&emlrtCoverageInstance, 20U, 4U, 298, -1, 306);
  covrtBasicBlockInit(&emlrtCoverageInstance, 20U, 3U, 235, -1, 248);
  covrtBasicBlockInit(&emlrtCoverageInstance, 20U, 2U, 206, -1, 216);
  covrtBasicBlockInit(&emlrtCoverageInstance, 20U, 1U, 147, -1, 177);
  covrtBasicBlockInit(&emlrtCoverageInstance, 20U, 0U, 58, -1, 123);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 20U, 0U, 188, 197, 222, 257);
  covrtIfInit(&emlrtCoverageInstance, 20U, 1U, 267, 289, 312, 350);
  covrtIfInit(&emlrtCoverageInstance, 20U, 2U, 542, 556, -1, 608);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 20U, 0U, 126, 143, 612);
  covrtForInit(&emlrtCoverageInstance, 20U, 1U, 369, 386, 537);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 20U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/applyBackgroundCorrection.m",
                  21U, 1U, 2U, 0U, 0U, 0U, 1U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 21U, 0U, "applyBackgroundCorrection", 0,
               -1, 439);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 21U, 1U, 320, -1, 363);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21U, 0U, 190, -1, 246);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  covrtSwitchInit(&emlrtCoverageInstance, 21U, 0U, 112, 129, 426, 3U,
                  caseStarts_21_0, caseExprEnds_21_0);

  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 21U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m",
                  22U, 1U, 5U, 2U, 0U, 0U, 0U, 0U, 0U, 1U, 1U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 22U, 0U, "chiSquared", 0, -1, 498);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 22U, 4U, 438, -1, 463);
  covrtBasicBlockInit(&emlrtCoverageInstance, 22U, 3U, 412, -1, 424);
  covrtBasicBlockInit(&emlrtCoverageInstance, 22U, 2U, 331, -1, 383);
  covrtBasicBlockInit(&emlrtCoverageInstance, 22U, 1U, 306, -1, 317);
  covrtBasicBlockInit(&emlrtCoverageInstance, 22U, 0U, 190, -1, 282);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 22U, 0U, 288, 297, -1, 326);
  covrtIfInit(&emlrtCoverageInstance, 22U, 1U, 389, 403, -1, 433);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 22U, 0U, 392, 403, 1, 0,
                cond_starts_22_0, cond_ends_22_0, 2, postfix_exprs_22_0);

  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 22U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",
                  23U, 1U, 8U, 0U, 0U, 0U, 0U, 4U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 23U, 0U, "standardTF_stanlay_paraPoints",
               1, -1, 4307);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 7U, 2208, -1, 4297);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 6U, 1827, -1, 1897);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 5U, 1578, -1, 1600);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 4U, 1507, -1, 1544);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 3U, 1473, -1, 1500);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 2U, 1401, -1, 1439);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 1U, 1365, -1, 1394);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 0U, 288, -1, 1331);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 23U, 0U, 1333, 1361, 1399);
  covrtForInit(&emlrtCoverageInstance, 23U, 1U, 1441, 1469, 1505);
  covrtForInit(&emlrtCoverageInstance, 23U, 2U, 1546, 1574, 1605);
  covrtForInit(&emlrtCoverageInstance, 23U, 3U, 1937, 1965, 4302);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 23U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/reflectivityCalculations/Abeles/abeles_paraPoints.m",
                  24U, 1U, 5U, 0U, 0U, 0U, 0U, 3U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 24U, 0U, "abeles_paraPoints", 0, -1, 2136);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 4U, 2126, -1, 2132);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 3U, 1726, -1, 2119);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 2U, 990, -1, 1700);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 1U, 568, -1, 921);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 0U, 229, -1, 534);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 24U, 0U, 536, -1, 2124);
  covrtForInit(&emlrtCoverageInstance, 24U, 1U, 927, 952, 1721);
  covrtForInit(&emlrtCoverageInstance, 24U, 2U, 960, 978, 1713);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 24U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly_paraPoints.m",
                  25U, 1U, 9U, 3U, 0U, 0U, 0U, 2U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 25U, 0U, "resolution_polly_paraPoints", 0,
               -1, 697);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 25U, 8U, 676, -1, 691);
  covrtBasicBlockInit(&emlrtCoverageInstance, 25U, 7U, 579, -1, 613);
  covrtBasicBlockInit(&emlrtCoverageInstance, 25U, 6U, 408, -1, 542);
  covrtBasicBlockInit(&emlrtCoverageInstance, 25U, 5U, 339, -1, 355);
  covrtBasicBlockInit(&emlrtCoverageInstance, 25U, 4U, 312, -1, 320);
  covrtBasicBlockInit(&emlrtCoverageInstance, 25U, 3U, 249, -1, 262);
  covrtBasicBlockInit(&emlrtCoverageInstance, 25U, 2U, 220, -1, 230);
  covrtBasicBlockInit(&emlrtCoverageInstance, 25U, 1U, 161, -1, 191);
  covrtBasicBlockInit(&emlrtCoverageInstance, 25U, 0U, 69, -1, 134);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 25U, 0U, 202, 211, 236, 271);
  covrtIfInit(&emlrtCoverageInstance, 25U, 1U, 281, 303, 326, 364);
  covrtIfInit(&emlrtCoverageInstance, 25U, 2U, 556, 570, -1, 622);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 25U, 0U, 137, -1, 674);
  covrtForInit(&emlrtCoverageInstance, 25U, 1U, 383, 400, 551);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 25U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",
                  26U, 1U, 8U, 0U, 0U, 0U, 0U, 4U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 26U, 0U,
               "standardTF_stanlay_paraContrasts", 1, -1, 4315);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 26U, 7U, 2210, -1, 4305);
  covrtBasicBlockInit(&emlrtCoverageInstance, 26U, 6U, 1824, -1, 1894);
  covrtBasicBlockInit(&emlrtCoverageInstance, 26U, 5U, 1571, -1, 1593);
  covrtBasicBlockInit(&emlrtCoverageInstance, 26U, 4U, 1500, -1, 1537);
  covrtBasicBlockInit(&emlrtCoverageInstance, 26U, 3U, 1466, -1, 1493);
  covrtBasicBlockInit(&emlrtCoverageInstance, 26U, 2U, 1394, -1, 1432);
  covrtBasicBlockInit(&emlrtCoverageInstance, 26U, 1U, 1358, -1, 1387);
  covrtBasicBlockInit(&emlrtCoverageInstance, 26U, 0U, 291, -1, 1324);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 26U, 0U, 1326, 1354, 1392);
  covrtForInit(&emlrtCoverageInstance, 26U, 1U, 1434, 1462, 1498);
  covrtForInit(&emlrtCoverageInstance, 26U, 2U, 1539, 1567, 1598);
  covrtForInit(&emlrtCoverageInstance, 26U, 3U, 1936, -1, 4310);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 26U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraAll.m",
                  27U, 1U, 8U, 0U, 0U, 0U, 0U, 4U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 27U, 0U, "standardTF_stanlay_paraAll", 1,
               -1, 4293);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 27U, 7U, 2194, -1, 4283);
  covrtBasicBlockInit(&emlrtCoverageInstance, 27U, 6U, 1813, -1, 1883);
  covrtBasicBlockInit(&emlrtCoverageInstance, 27U, 5U, 1564, -1, 1586);
  covrtBasicBlockInit(&emlrtCoverageInstance, 27U, 4U, 1493, -1, 1530);
  covrtBasicBlockInit(&emlrtCoverageInstance, 27U, 3U, 1459, -1, 1486);
  covrtBasicBlockInit(&emlrtCoverageInstance, 27U, 2U, 1387, -1, 1425);
  covrtBasicBlockInit(&emlrtCoverageInstance, 27U, 1U, 1351, -1, 1380);
  covrtBasicBlockInit(&emlrtCoverageInstance, 27U, 0U, 285, -1, 1317);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 27U, 0U, 1319, 1347, 1385);
  covrtForInit(&emlrtCoverageInstance, 27U, 1U, 1427, 1455, 1491);
  covrtForInit(&emlrtCoverageInstance, 27U, 2U, 1532, 1560, 1591);
  covrtForInit(&emlrtCoverageInstance, 27U, 3U, 1920, -1, 4288);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 27U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",
                  28U, 1U, 17U, 0U, 0U, 0U, 1U, 6U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 28U, 0U,
               "standardTF_custLay_reflectivityCalculation", 0, -1, 5037);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 16U, 4733, -1, 5031);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 15U, 4150, -1, 4717);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 14U, 3537, -1, 4101);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 13U, 2932, -1, 3492);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 12U, 2780, -1, 2887);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 11U, 2752, -1, 2774);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 10U, 2631, -1, 2718);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 9U, 2598, -1, 2625);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 8U, 2477, -1, 2564);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 7U, 2442, -1, 2471);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 6U, 2320, -1, 2408);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 5U, 2282, -1, 2314);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 4U, 2158, -1, 2248);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 3U, 2125, -1, 2152);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 2U, 2002, -1, 2091);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 1U, 1967, -1, 1996);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 0U, 191, -1, 1933);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 28U, 0U, 1935, 1963, 2001);
  covrtForInit(&emlrtCoverageInstance, 28U, 1U, 2093, 2121, 2157);
  covrtForInit(&emlrtCoverageInstance, 28U, 2U, 2250, 2278, 2319);
  covrtForInit(&emlrtCoverageInstance, 28U, 3U, 2410, 2438, 2476);
  covrtForInit(&emlrtCoverageInstance, 28U, 4U, 2566, 2594, 2630);
  covrtForInit(&emlrtCoverageInstance, 28U, 5U, 2720, 2748, 2779);

  /* Initialize While Information */
  /* Initialize Switch Information */
  covrtSwitchInit(&emlrtCoverageInstance, 28U, 0U, 2890, 2906, 4731, 4U,
                  caseStarts_28_0, caseExprEnds_28_0);

  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 28U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",
                  29U, 1U, 8U, 0U, 0U, 0U, 0U, 4U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 29U, 0U, "standardTF_custlay_single", 0,
               -1, 4067);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 29U, 7U, 1955, -1, 4055);
  covrtBasicBlockInit(&emlrtCoverageInstance, 29U, 6U, 1573, -1, 1618);
  covrtBasicBlockInit(&emlrtCoverageInstance, 29U, 5U, 1545, -1, 1567);
  covrtBasicBlockInit(&emlrtCoverageInstance, 29U, 4U, 1425, -1, 1511);
  covrtBasicBlockInit(&emlrtCoverageInstance, 29U, 3U, 1392, -1, 1419);
  covrtBasicBlockInit(&emlrtCoverageInstance, 29U, 2U, 1269, -1, 1358);
  covrtBasicBlockInit(&emlrtCoverageInstance, 29U, 1U, 1234, -1, 1263);
  covrtBasicBlockInit(&emlrtCoverageInstance, 29U, 0U, 666, -1, 1200);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 29U, 0U, 1202, 1230, 1268);
  covrtForInit(&emlrtCoverageInstance, 29U, 1U, 1360, 1388, 1424);
  covrtForInit(&emlrtCoverageInstance, 29U, 2U, 1513, 1541, 1572);
  covrtForInit(&emlrtCoverageInstance, 29U, 3U, 1689, 1717, 4061);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 29U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/call_customLayers.m",
                  30U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 30U, 0U, "call_customLayers", 0, -1, 511);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 30U, 0U, 138, -1, 261);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 30U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",
                  31U, 1U, 10U, 5U, 0U, 0U, 0U, 1U, 0U, 1U, 1U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 31U, 0U,
               "matlabEngineCaller_customLayers", 0, -1, 2725);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 31U, 9U, 2674, -1, 2710);
  covrtBasicBlockInit(&emlrtCoverageInstance, 31U, 8U, 2574, -1, 2627);
  covrtBasicBlockInit(&emlrtCoverageInstance, 31U, 7U, 2376, -1, 2517);
  covrtBasicBlockInit(&emlrtCoverageInstance, 31U, 6U, 2307, -1, 2332);
  covrtBasicBlockInit(&emlrtCoverageInstance, 31U, 5U, 802, -1, 2224);
  covrtBasicBlockInit(&emlrtCoverageInstance, 31U, 4U, 689, -1, 786);
  covrtBasicBlockInit(&emlrtCoverageInstance, 31U, 3U, 646, -1, 675);
  covrtBasicBlockInit(&emlrtCoverageInstance, 31U, 2U, 585, -1, 614);
  covrtBasicBlockInit(&emlrtCoverageInstance, 31U, 1U, 492, -1, 571);
  covrtBasicBlockInit(&emlrtCoverageInstance, 31U, 0U, 111, -1, 438);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 31U, 0U, 440, 465, 788, 2724);
  covrtIfInit(&emlrtCoverageInstance, 31U, 1U, 470, 483, -1, 580);
  covrtIfInit(&emlrtCoverageInstance, 31U, 2U, 620, 637, -1, 684);
  covrtIfInit(&emlrtCoverageInstance, 31U, 3U, 2281, 2298, 2661, 2719);
  covrtIfInit(&emlrtCoverageInstance, 31U, 4U, 2531, 2557, -1, 2644);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 31U, 0U, 623, 637, 1, 0,
                cond_starts_31_0, cond_ends_31_0, 2, postfix_exprs_31_0);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 31U, 0U, 2342, 2364, 2656);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 31U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",
                  32U, 1U, 8U, 0U, 0U, 0U, 0U, 4U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 32U, 0U, "standardTF_custlay_paraPoints",
               0, -1, 4040);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 32U, 7U, 1959, -1, 4028);
  covrtBasicBlockInit(&emlrtCoverageInstance, 32U, 6U, 1577, -1, 1622);
  covrtBasicBlockInit(&emlrtCoverageInstance, 32U, 5U, 1549, -1, 1571);
  covrtBasicBlockInit(&emlrtCoverageInstance, 32U, 4U, 1429, -1, 1515);
  covrtBasicBlockInit(&emlrtCoverageInstance, 32U, 3U, 1396, -1, 1423);
  covrtBasicBlockInit(&emlrtCoverageInstance, 32U, 2U, 1273, -1, 1362);
  covrtBasicBlockInit(&emlrtCoverageInstance, 32U, 1U, 1238, -1, 1267);
  covrtBasicBlockInit(&emlrtCoverageInstance, 32U, 0U, 670, -1, 1204);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 32U, 0U, 1206, 1234, 1272);
  covrtForInit(&emlrtCoverageInstance, 32U, 1U, 1364, 1392, 1428);
  covrtForInit(&emlrtCoverageInstance, 32U, 2U, 1517, 1545, 1576);
  covrtForInit(&emlrtCoverageInstance, 32U, 3U, 1693, 1721, 4034);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 32U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",
                  33U, 1U, 8U, 0U, 0U, 0U, 0U, 4U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 33U, 0U,
               "standardTF_custlay_paraContrasts", 0, -1, 4067);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 33U, 7U, 1955, -1, 4055);
  covrtBasicBlockInit(&emlrtCoverageInstance, 33U, 6U, 1573, -1, 1618);
  covrtBasicBlockInit(&emlrtCoverageInstance, 33U, 5U, 1545, -1, 1567);
  covrtBasicBlockInit(&emlrtCoverageInstance, 33U, 4U, 1425, -1, 1511);
  covrtBasicBlockInit(&emlrtCoverageInstance, 33U, 3U, 1392, -1, 1419);
  covrtBasicBlockInit(&emlrtCoverageInstance, 33U, 2U, 1269, -1, 1358);
  covrtBasicBlockInit(&emlrtCoverageInstance, 33U, 1U, 1234, -1, 1263);
  covrtBasicBlockInit(&emlrtCoverageInstance, 33U, 0U, 666, -1, 1200);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 33U, 0U, 1202, 1230, 1268);
  covrtForInit(&emlrtCoverageInstance, 33U, 1U, 1360, 1388, 1424);
  covrtForInit(&emlrtCoverageInstance, 33U, 2U, 1513, 1541, 1572);
  covrtForInit(&emlrtCoverageInstance, 33U, 3U, 1689, 1717, 4061);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 33U);
}

void reflectivity_calculation_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    reflectivity_calculation_once();
  }
}

/* End of code generation (reflectivity_calculation_initialize.c) */
