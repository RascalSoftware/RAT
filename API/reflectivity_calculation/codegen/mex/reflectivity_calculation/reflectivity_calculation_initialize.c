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
#include "reflectivity_calculation_mexutil.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void reflectivity_calculation_once(const emlrtStack *sp);

/* Function Definitions */
static void reflectivity_calculation_once(const emlrtStack *sp)
{
  const int32_T caseStarts_0_0[2] = { -1, 1465 };

  const int32_T caseExprEnds_0_0[2] = { 8, 1482 };

  const int32_T caseStarts_1_0[4] = { -1, 1485, 1717, 1962 };

  const int32_T caseExprEnds_1_0[4] = { 8, 1498, 1737, 1978 };

  const int32_T caseStarts_2_0[4] = { -1, 2419, 3016, 3617 };

  const int32_T caseExprEnds_2_0[4] = { 8, 2432, 3029, 3633 };

  const int32_T cond_starts_5_0[1] = { 507 };

  const int32_T cond_ends_5_0[1] = { 521 };

  const int32_T postfix_exprs_5_0[2] = { 0, -1 };

  const int32_T cond_starts_8_0[1] = { 1830 };

  const int32_T cond_ends_8_0[1] = { 1845 };

  const int32_T postfix_exprs_8_0[2] = { 0, -1 };

  const int32_T cond_starts_8_1[1] = { 2878 };

  const int32_T cond_ends_8_1[1] = { 2893 };

  const int32_T postfix_exprs_8_1[2] = { 0, -1 };

  const int32_T cond_starts_8_2[1] = { 3111 };

  const int32_T cond_ends_8_2[1] = { 3126 };

  const int32_T postfix_exprs_8_2[2] = { 0, -1 };

  const int32_T caseStarts_8_0[3] = { -1, 1882, 1979 };

  const int32_T caseExprEnds_8_0[3] = { 8, 1902, 2002 };

  const int32_T cond_starts_14_0[1] = { 587 };

  const int32_T cond_ends_14_0[1] = { 601 };

  const int32_T postfix_exprs_14_0[2] = { 0, -1 };

  const int32_T cond_starts_15_0[1] = { 750 };

  const int32_T cond_ends_15_0[1] = { 767 };

  const int32_T postfix_exprs_15_0[2] = { 0, -1 };

  const int32_T cond_starts_15_1[1] = { 924 };

  const int32_T cond_ends_15_1[1] = { 940 };

  const int32_T postfix_exprs_15_1[2] = { 0, -1 };

  const int32_T caseStarts_15_0[2] = { 1103, 404 };

  const int32_T caseExprEnds_15_0[2] = { 1112, 410 };

  const int32_T caseStarts_16_0[2] = { 1542, 1289 };

  const int32_T caseExprEnds_16_0[2] = { 1551, 1302 };

  const int32_T caseStarts_19_0[3] = { -1, 133, 253 };

  const int32_T caseExprEnds_19_0[3] = { 8, 139, 259 };

  const int32_T cond_starts_20_0[1] = { 393 };

  const int32_T cond_ends_20_0[1] = { 403 };

  const int32_T postfix_exprs_20_0[2] = { 0, -1 };

  const int32_T caseStarts_24_0[4] = { -1, 2838, 4054, 5275 };

  const int32_T caseExprEnds_24_0[4] = { 8, 2851, 4067, 5291 };

  const int32_T cond_starts_27_0[1] = { 624 };

  const int32_T cond_ends_27_0[1] = { 637 };

  const int32_T postfix_exprs_27_0[2] = { 0, -1 };

  const int32_T caseStarts_30_0[3] = { -1, 2837, 4052 };

  const int32_T caseExprEnds_30_0[3] = { 8, 2850, 4065 };

  mex_InitInfAndNan();

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",
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
                  1U, 1U, 15U, 0U, 0U, 0U, 1U, 6U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U,
               "standardTF_reflectivityCalculation", 0, -1, 2204);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 14U, 1986, -1, 2194);
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
  covrtSwitchInit(&emlrtCoverageInstance, 1U, 0U, 1469, 1481, 2199, 4U,
                  caseStarts_1_0, caseExprEnds_1_0);

  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 1U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",
                  2U, 1U, 17U, 0U, 0U, 0U, 1U, 6U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 2U, 0U,
               "standardTF_stanLay_reflectivityCalculation", 0, -1, 4524);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 16U, 4220, -1, 4518);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 15U, 3651, -1, 4207);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 14U, 3048, -1, 3602);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 13U, 2450, -1, 3000);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 12U, 2380, -1, 2400);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 11U, 2351, -1, 2373);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 10U, 2280, -1, 2317);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 9U, 2246, -1, 2273);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 8U, 2173, -1, 2212);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 7U, 2137, -1, 2166);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 6U, 2066, -1, 2103);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 5U, 2027, -1, 2059);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 4U, 1953, -1, 1993);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 3U, 1919, -1, 1946);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 2U, 1847, -1, 1885);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 1U, 1811, -1, 1840);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 0U, 191, -1, 1777);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 2U, 0U, 1779, 1807, 1845);
  covrtForInit(&emlrtCoverageInstance, 2U, 1U, 1887, 1915, 1951);
  covrtForInit(&emlrtCoverageInstance, 2U, 2U, 1995, 2023, 2064);
  covrtForInit(&emlrtCoverageInstance, 2U, 3U, 2105, 2133, 2171);
  covrtForInit(&emlrtCoverageInstance, 2U, 4U, 2214, 2242, 2278);
  covrtForInit(&emlrtCoverageInstance, 2U, 5U, 2319, 2347, 2378);

  /* Initialize While Information */
  /* Initialize Switch Information */
  covrtSwitchInit(&emlrtCoverageInstance, 2U, 0U, 2403, 2415, 4218, 4U,
                  caseStarts_2_0, caseExprEnds_2_0);

  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 2U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/API/RAT_parse_cells.m",
                  3U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 3U, 0U, "RAT_parse_cells", 0, -1, 332);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 0U, 119, -1, 326);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 3U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",
                  4U, 1U, 14U, 3U, 0U, 0U, 0U, 4U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 4U, 0U, "standardTF_stanlay_single", 0,
               -1, 3571);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 13U, 2565, -1, 3561);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 12U, 2474, -1, 2496);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 11U, 2418, -1, 2455);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 10U, 2314, -1, 2334);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 9U, 2210, -1, 2295);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 8U, 2087, -1, 2102);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 7U, 1494, -1, 2053);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 6U, 1323, -1, 1393);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 5U, 1294, -1, 1316);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 4U, 1223, -1, 1260);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 3U, 1189, -1, 1216);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 2U, 1117, -1, 1155);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 1U, 1081, -1, 1110);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 0U, 551, -1, 1047);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 4U, 0U, 2059, 2078, -1, 2111);
  covrtIfInit(&emlrtCoverageInstance, 4U, 1U, 2182, 2201, 2301, 2343);
  covrtIfInit(&emlrtCoverageInstance, 4U, 2U, 2390, 2409, 2461, 2505);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 4U, 0U, 1049, 1077, 1115);
  covrtForInit(&emlrtCoverageInstance, 4U, 1U, 1157, 1185, 1221);
  covrtForInit(&emlrtCoverageInstance, 4U, 2U, 1262, 1290, 1321);
  covrtForInit(&emlrtCoverageInstance, 4U, 3U, 1396, 1424, 3566);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 4U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",
                  5U, 1U, 6U, 1U, 0U, 0U, 0U, 2U, 0U, 1U, 1U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 5U, 0U, "allocateParamsToLayers", 0, -1,
               732);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 5U, 641, -1, 722);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 4U, 594, -1, 615);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 3U, 534, -1, 567);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 2U, 471, -1, 493);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 1U, 397, -1, 425);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 0U, 264, -1, 365);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 5U, 0U, 503, 521, 577, 628);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 5U, 0U, 506, 521, 1, 0, cond_starts_5_0,
                cond_ends_5_0, 2, postfix_exprs_5_0);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 5U, 0U, 368, 393, 727);
  covrtForInit(&emlrtCoverageInstance, 5U, 1U, 431, 463, 636);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 5U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",
                  6U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 6U, 0U, "backSort", 0, -1, 1986);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 0U, 1664, -1, 1967);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 6U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m",
                  7U, 1U, 2U, 0U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 7U, 0U, "allocateLayersForContrast", 0,
               -1, 381);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 1U, 277, -1, 371);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 0U, 185, -1, 237);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 7U, 0U, 240, 273, 376);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 7U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",
                  8U, 1U, 14U, 6U, 0U, 0U, 1U, 1U, 0U, 3U, 3U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 8U, 0U, "groupLayers_Mod", 0, -1, 3218);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 13U, 3195, -1, 3211);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 12U, 3167, -1, 3189);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 11U, 3131, -1, 3156);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 10U, 2914, -1, 2982);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 9U, 2822, -1, 2836);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 8U, 2764, -1, 2779);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 7U, 2684, -1, 2706);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 6U, 2578, -1, 2624);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 5U, 2491, -1, 2503);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 4U, 2414, -1, 2453);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 3U, 2286, -1, 2371);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 2U, 2019, -1, 2238);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 1U, 1919, -1, 1934);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 0U, 1646, -1, 1820);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 8U, 0U, 1826, 1845, -1, 3040);
  covrtIfInit(&emlrtCoverageInstance, 8U, 1U, 2256, 2265, 2389, 2474);
  covrtIfInit(&emlrtCoverageInstance, 8U, 2U, 2634, 2643, -1, 3031);
  covrtIfInit(&emlrtCoverageInstance, 8U, 3U, 2724, 2743, 2797, 2857);
  covrtIfInit(&emlrtCoverageInstance, 8U, 4U, 2874, 2893, -1, 3003);
  covrtIfInit(&emlrtCoverageInstance, 8U, 5U, 3107, 3126, 3158, 3194);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 8U, 0U, 1829, 1845, 1, 0,
                cond_starts_8_0, cond_ends_8_0, 2, postfix_exprs_8_0);
  covrtMcdcInit(&emlrtCoverageInstance, 8U, 1U, 2877, 2893, 1, 1,
                cond_starts_8_1, cond_ends_8_1, 2, postfix_exprs_8_1);
  covrtMcdcInit(&emlrtCoverageInstance, 8U, 2U, 3110, 3126, 1, 2,
                cond_starts_8_2, cond_ends_8_2, 2, postfix_exprs_8_2);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 8U, 0U, 2656, 2668, 3019);

  /* Initialize While Information */
  /* Initialize Switch Information */
  covrtSwitchInit(&emlrtCoverageInstance, 8U, 0U, 1854, 1870, 2516, 3U,
                  caseStarts_8_0, caseExprEnds_8_0);

  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 8U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfiles.m",
                  9U, 1U, 4U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 9U, 0U, "makeSLDProfiles", 0, -1, 223);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 3U, 156, -1, 217);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 2U, 131, -1, 148);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 1U, 112, -1, 120);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 0U, 69, -1, 87);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 9U, 0U, 89, 107, 122, 153);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 9U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",
                  10U, 1U, 8U, 2U, 0U, 0U, 0U, 2U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 10U, 0U, "makeSLDProfileXY", 0, -1, 1962);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 7U, 1937, -1, 1956);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 6U, 1689, -1, 1917);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 5U, 1217, -1, 1678);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 4U, 894, -1, 1159);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 3U, 845, -1, 864);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 2U, 675, -1, 703);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 1U, 521, -1, 625);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 0U, 106, -1, 451);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 10U, 0U, 82, 101, 1680, 1922);
  covrtIfInit(&emlrtCoverageInstance, 10U, 1U, 639, 658, 824, 881);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 10U, 0U, 457, 476, 1212);
  covrtForInit(&emlrtCoverageInstance, 10U, 1U, 484, 509, 1204);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 10U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m",
                  11U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 11U, 0U, "asymconvstep", 0, -1, 1125);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 0U, 973, -1, 1121);

  /* Initialize If Information */
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
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",
                  12U, 1U, 6U, 1U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 12U, 0U, "resampleLayers", 1, -1, 874);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 5U, 853, -1, 868);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 4U, 804, -1, 847);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 3U, 745, -1, 785);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 2U, 686, -1, 726);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 1U, 534, -1, 655);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 0U, 116, -1, 448);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 12U, 0U, 661, 677, 732, 794);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 12U, 0U, 505, 530, 852);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 12U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",
                  13U, 6U, 20U, 9U, 0U, 0U, 0U, 2U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 13U, 0U, "adaptive", 0, -1, 13047);
  covrtFcnInit(&emlrtCoverageInstance, 13U, 1U, "normalizeFunction", 13066, -1,
               14216);
  covrtFcnInit(&emlrtCoverageInstance, 13U, 2U, "calculateTrianglesSides", 14218,
               -1, 14660);
  covrtFcnInit(&emlrtCoverageInstance, 13U, 3U, "calculateCentralAngles", 14662,
               -1, 15645);
  covrtFcnInit(&emlrtCoverageInstance, 13U, 4U, "calculateTrianglesArea", 15647,
               -1, 16075);
  covrtFcnInit(&emlrtCoverageInstance, 13U, 5U, "increaseSampling", 16077, -1,
               16698);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 13U, 12982, -1, 13038);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 12U, 12942, -1, 12961);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 10U, 12345, -1, 12415);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 11U, 12428, -1, 12433);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 9U, 12095, -1, 12304);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 8U, 11660, -1, 12059);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 7U, 11557, -1, 11630);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 6U, 11203, -1, 11372);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 5U, 10994, -1, 11167);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 4U, 10559, -1, 10966);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 3U, 9991, -1, 10202);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 2U, 9600, -1, 9693);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 1U, 9400, -1, 9425);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 0U, 6435, -1, 8353);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 15U, 14169, -1, 14200);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 14U, 13537, -1, 13726);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 16U, 14503, -1, 14655);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 17U, 14985, -1, 15640);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 18U, 15922, -1, 16070);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 19U, 16220, -1, 16693);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 13U, 0U, 9376, 9397, -1, 9430);
  covrtIfInit(&emlrtCoverageInstance, 13U, 1U, 9571, 9597, -1, 9698);
  covrtIfInit(&emlrtCoverageInstance, 13U, 2U, 10970, 10989, -1, 11174);
  covrtIfInit(&emlrtCoverageInstance, 13U, 3U, 11177, 11198, -1, 11379);
  covrtIfInit(&emlrtCoverageInstance, 13U, 4U, 11634, 11655, -1, 12066);
  covrtIfInit(&emlrtCoverageInstance, 13U, 5U, 12069, 12090, -1, 12311);
  covrtIfInit(&emlrtCoverageInstance, 13U, 6U, 12317, 12340, 12419, 12440);
  covrtIfInit(&emlrtCoverageInstance, 13U, 7U, 12926, 12939, 12963, 12979);
  covrtIfInit(&emlrtCoverageInstance, 13U, 8U, 12963, 12979, -1, 12979);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 13U, 0U, 10459, 10495, 12643);
  covrtForInit(&emlrtCoverageInstance, 13U, 1U, 13980, 14000, 14207);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 13U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m",
                  14U, 1U, 5U, 2U, 0U, 0U, 0U, 0U, 0U, 1U, 1U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 14U, 0U, "sldFunc", 0, -1, 1122);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 4U, 1045, -1, 1069);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 3U, 1002, -1, 1026);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 2U, 636, -1, 964);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 1U, 606, -1, 625);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 0U, 529, -1, 580);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 14U, 0U, 583, 601, 627, 1119);
  covrtIfInit(&emlrtCoverageInstance, 14U, 1U, 975, 993, 1032, 1078);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 14U, 0U, 586, 601, 1, 0,
                cond_starts_14_0, cond_ends_14_0, 2, postfix_exprs_14_0);

  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 14U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m",
                  15U, 1U, 9U, 3U, 0U, 0U, 1U, 0U, 0U, 2U, 2U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 15U, 0U, "shiftdata", 0, -1, 1664);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 7U, 1058, -1, 1097);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 6U, 1000, -1, 1027);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 5U, 953, -1, 973);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 4U, 874, -1, 909);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 3U, 831, -1, 843);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 2U, 780, -1, 804);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 1U, 486, -1, 736);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 0U, 448, -1, 464);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 8U, 1121, -1, 1140);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 15U, 0U, 419, 435, -1, 477);
  covrtIfInit(&emlrtCoverageInstance, 15U, 1U, 746, 767, 814, 856);
  covrtIfInit(&emlrtCoverageInstance, 15U, 2U, 919, 940, 983, 1040);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 15U, 0U, 749, 767, 1, 0,
                cond_starts_15_0, cond_ends_15_0, 2, postfix_exprs_15_0);
  covrtMcdcInit(&emlrtCoverageInstance, 15U, 1U, 923, 940, 1, 1,
                cond_starts_15_1, cond_ends_15_1, 2, postfix_exprs_15_1);

  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  covrtSwitchInit(&emlrtCoverageInstance, 15U, 0U, 381, 400, 1145, 2U,
                  caseStarts_15_0, caseExprEnds_15_0);

  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 15U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",
                  16U, 1U, 12U, 3U, 0U, 0U, 1U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 16U, 0U, "callReflectivity", 0, -1, 1931);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 16U, 11U, 1729, -1, 1923);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16U, 9U, 1311, -1, 1531);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16U, 10U, 1560, -1, 1722);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16U, 8U, 1071, -1, 1270);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16U, 7U, 1048, -1, 1064);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16U, 6U, 952, -1, 1037);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16U, 5U, 901, -1, 918);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16U, 4U, 814, -1, 890);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16U, 3U, 710, -1, 786);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16U, 2U, 658, -1, 703);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16U, 1U, 614, -1, 647);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16U, 0U, 549, -1, 588);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 16U, 0U, 591, 609, 649, 708);
  covrtIfInit(&emlrtCoverageInstance, 16U, 1U, 789, 809, 892, 923);
  covrtIfInit(&emlrtCoverageInstance, 16U, 2U, 925, 947, 1039, 1069);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  covrtSwitchInit(&emlrtCoverageInstance, 16U, 0U, 1273, 1285, 1727, 2U,
                  caseStarts_16_0, caseExprEnds_16_0);

  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 16U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_single.m",
                  17U, 1U, 5U, 0U, 0U, 0U, 0U, 3U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 17U, 0U, "abeles_single", 0, -1, 2110);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 17U, 4U, 2100, -1, 2106);
  covrtBasicBlockInit(&emlrtCoverageInstance, 17U, 3U, 1700, -1, 2093);
  covrtBasicBlockInit(&emlrtCoverageInstance, 17U, 2U, 964, -1, 1674);
  covrtBasicBlockInit(&emlrtCoverageInstance, 17U, 1U, 596, -1, 895);
  covrtBasicBlockInit(&emlrtCoverageInstance, 17U, 0U, 225, -1, 570);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 17U, 0U, 572, 592, 2098);
  covrtForInit(&emlrtCoverageInstance, 17U, 1U, 901, 926, 1695);
  covrtForInit(&emlrtCoverageInstance, 17U, 2U, 934, 952, 1687);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 17U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",
                  18U, 1U, 9U, 3U, 0U, 0U, 0U, 2U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 18U, 0U, "resolution_polly", 0, -1, 635);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 8U, 614, -1, 629);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 7U, 565, -1, 599);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 6U, 394, -1, 528);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 5U, 325, -1, 341);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 4U, 298, -1, 306);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 3U, 235, -1, 248);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 2U, 206, -1, 216);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 1U, 147, -1, 177);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18U, 0U, 58, -1, 123);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 18U, 0U, 188, 197, 222, 257);
  covrtIfInit(&emlrtCoverageInstance, 18U, 1U, 267, 289, 312, 350);
  covrtIfInit(&emlrtCoverageInstance, 18U, 2U, 542, 556, -1, 608);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 18U, 0U, 126, 143, 612);
  covrtForInit(&emlrtCoverageInstance, 18U, 1U, 369, 386, 537);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 18U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/applyBackgroundCorrection.m",
                  19U, 1U, 2U, 0U, 0U, 0U, 1U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 19U, 0U, "applyBackgroundCorrection", 0,
               -1, 439);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 19U, 1U, 320, -1, 363);
  covrtBasicBlockInit(&emlrtCoverageInstance, 19U, 0U, 190, -1, 246);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  covrtSwitchInit(&emlrtCoverageInstance, 19U, 0U, 112, 129, 426, 3U,
                  caseStarts_19_0, caseExprEnds_19_0);

  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 19U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m",
                  20U, 1U, 5U, 2U, 0U, 0U, 0U, 0U, 0U, 1U, 1U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 20U, 0U, "chiSquared", 0, -1, 498);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 20U, 4U, 438, -1, 463);
  covrtBasicBlockInit(&emlrtCoverageInstance, 20U, 3U, 412, -1, 424);
  covrtBasicBlockInit(&emlrtCoverageInstance, 20U, 2U, 331, -1, 383);
  covrtBasicBlockInit(&emlrtCoverageInstance, 20U, 1U, 306, -1, 317);
  covrtBasicBlockInit(&emlrtCoverageInstance, 20U, 0U, 190, -1, 282);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 20U, 0U, 288, 297, -1, 326);
  covrtIfInit(&emlrtCoverageInstance, 20U, 1U, 389, 403, -1, 433);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 20U, 0U, 392, 403, 1, 0,
                cond_starts_20_0, cond_ends_20_0, 2, postfix_exprs_20_0);

  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 20U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",
                  21U, 1U, 15U, 3U, 0U, 0U, 0U, 4U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 21U, 0U, "standardTF_stanlay_paraPoints",
               0, -1, 3524);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 21U, 14U, 3009, -1, 3514);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21U, 13U, 2938, -1, 2991);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21U, 12U, 2849, -1, 2919);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21U, 11U, 2787, -1, 2814);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21U, 10U, 2748, -1, 2768);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21U, 9U, 2646, -1, 2729);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21U, 8U, 2584, -1, 2599);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21U, 7U, 2134, -1, 2550);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21U, 6U, 2009, -1, 2099);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21U, 5U, 1980, -1, 2002);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21U, 4U, 1909, -1, 1946);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21U, 3U, 1875, -1, 1902);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21U, 2U, 1803, -1, 1841);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21U, 1U, 1767, -1, 1796);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21U, 0U, 1156, -1, 1733);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 21U, 0U, 2556, 2575, -1, 2608);
  covrtIfInit(&emlrtCoverageInstance, 21U, 1U, 2618, 2637, 2735, 2777);
  covrtIfInit(&emlrtCoverageInstance, 21U, 2U, 2821, 2840, 2925, 3000);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 21U, 0U, 1735, 1763, 1801);
  covrtForInit(&emlrtCoverageInstance, 21U, 1U, 1843, 1871, 1907);
  covrtForInit(&emlrtCoverageInstance, 21U, 2U, 1948, 1976, 2007);
  covrtForInit(&emlrtCoverageInstance, 21U, 3U, 2102, 2130, 3519);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 21U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_paraPoints.m",
                  22U, 1U, 5U, 0U, 0U, 0U, 0U, 3U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 22U, 0U, "abeles_paraPoints", 0, -1, 2136);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 22U, 4U, 2126, -1, 2132);
  covrtBasicBlockInit(&emlrtCoverageInstance, 22U, 3U, 1726, -1, 2119);
  covrtBasicBlockInit(&emlrtCoverageInstance, 22U, 2U, 990, -1, 1700);
  covrtBasicBlockInit(&emlrtCoverageInstance, 22U, 1U, 568, -1, 921);
  covrtBasicBlockInit(&emlrtCoverageInstance, 22U, 0U, 229, -1, 534);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 22U, 0U, 536, -1, 2124);
  covrtForInit(&emlrtCoverageInstance, 22U, 1U, 927, 952, 1721);
  covrtForInit(&emlrtCoverageInstance, 22U, 2U, 960, 978, 1713);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 22U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",
                  23U, 1U, 15U, 3U, 0U, 0U, 0U, 4U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 23U, 0U,
               "standardTF_stanlay_paraContrasts", 0, -1, 3532);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 14U, 3016, -1, 3521);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 13U, 2945, -1, 2998);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 12U, 2856, -1, 2926);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 11U, 2790, -1, 2817);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 10U, 2755, -1, 2775);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 9U, 2652, -1, 2735);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 8U, 2590, -1, 2605);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 7U, 2140, -1, 2556);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 6U, 2012, -1, 2102);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 5U, 1983, -1, 2005);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 4U, 1912, -1, 1949);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 3U, 1878, -1, 1905);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 2U, 1806, -1, 1844);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 1U, 1770, -1, 1799);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23U, 0U, 1159, -1, 1736);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 23U, 0U, 2562, 2581, -1, 2614);
  covrtIfInit(&emlrtCoverageInstance, 23U, 1U, 2624, 2643, 2742, 2784);
  covrtIfInit(&emlrtCoverageInstance, 23U, 2U, 2828, 2847, 2932, 3007);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 23U, 0U, 1738, 1766, 1804);
  covrtForInit(&emlrtCoverageInstance, 23U, 1U, 1846, 1874, 1910);
  covrtForInit(&emlrtCoverageInstance, 23U, 2U, 1951, 1979, 2010);
  covrtForInit(&emlrtCoverageInstance, 23U, 3U, 2105, -1, 3526);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 23U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",
                  24U, 1U, 18U, 2U, 0U, 0U, 1U, 6U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 24U, 0U,
               "standardTF_custLay_reflectivityCalculation", 0, -1, 8259);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 17U, 8092, -1, 8242);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 16U, 6502, -1, 6800);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 15U, 5300, -1, 6486);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 14U, 4076, -1, 5259);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 13U, 2860, -1, 4039);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 12U, 2743, -1, 2815);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 11U, 2715, -1, 2737);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 10U, 2594, -1, 2681);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 9U, 2561, -1, 2588);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 8U, 2440, -1, 2527);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 7U, 2405, -1, 2434);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 6U, 2283, -1, 2371);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 5U, 2245, -1, 2277);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 4U, 2121, -1, 2211);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 3U, 2088, -1, 2115);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 2U, 1965, -1, 2054);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 1U, 1930, -1, 1959);
  covrtBasicBlockInit(&emlrtCoverageInstance, 24U, 0U, 219, -1, 1896);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 24U, 0U, 8041, 8066, -1, 8255);
  covrtIfInit(&emlrtCoverageInstance, 24U, 1U, 8071, 8083, -1, 8251);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 24U, 0U, 1898, 1926, 1964);
  covrtForInit(&emlrtCoverageInstance, 24U, 1U, 2056, 2084, 2120);
  covrtForInit(&emlrtCoverageInstance, 24U, 2U, 2213, 2241, 2282);
  covrtForInit(&emlrtCoverageInstance, 24U, 3U, 2373, 2401, 2439);
  covrtForInit(&emlrtCoverageInstance, 24U, 4U, 2529, 2557, 2593);
  covrtForInit(&emlrtCoverageInstance, 24U, 5U, 2683, 2711, 2742);

  /* Initialize While Information */
  /* Initialize Switch Information */
  covrtSwitchInit(&emlrtCoverageInstance, 24U, 0U, 2818, 2834, 6500, 4U,
                  caseStarts_24_0, caseExprEnds_24_0);

  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 24U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",
                  25U, 1U, 11U, 1U, 0U, 0U, 0U, 4U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 25U, 0U, "standardTF_custlay_single", 0,
               -1, 3496);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 25U, 10U, 2976, -1, 3485);
  covrtBasicBlockInit(&emlrtCoverageInstance, 25U, 9U, 2905, -1, 2958);
  covrtBasicBlockInit(&emlrtCoverageInstance, 25U, 8U, 2816, -1, 2886);
  covrtBasicBlockInit(&emlrtCoverageInstance, 25U, 7U, 2277, -1, 2781);
  covrtBasicBlockInit(&emlrtCoverageInstance, 25U, 6U, 2196, -1, 2241);
  covrtBasicBlockInit(&emlrtCoverageInstance, 25U, 5U, 2168, -1, 2190);
  covrtBasicBlockInit(&emlrtCoverageInstance, 25U, 4U, 2048, -1, 2134);
  covrtBasicBlockInit(&emlrtCoverageInstance, 25U, 3U, 2015, -1, 2042);
  covrtBasicBlockInit(&emlrtCoverageInstance, 25U, 2U, 1892, -1, 1981);
  covrtBasicBlockInit(&emlrtCoverageInstance, 25U, 1U, 1857, -1, 1886);
  covrtBasicBlockInit(&emlrtCoverageInstance, 25U, 0U, 1289, -1, 1823);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 25U, 0U, 2788, 2807, 2892, 2967);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 25U, 0U, 1825, 1853, 1891);
  covrtForInit(&emlrtCoverageInstance, 25U, 1U, 1983, 2011, 2047);
  covrtForInit(&emlrtCoverageInstance, 25U, 2U, 2136, 2164, 2195);
  covrtForInit(&emlrtCoverageInstance, 25U, 3U, 2245, 2273, 3490);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 25U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/call_customLayers.m",
                  26U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 26U, 0U, "call_customLayers", 0, -1, 213);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 26U, 0U, 92, -1, 207);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 26U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",
                  27U, 1U, 10U, 5U, 0U, 0U, 0U, 1U, 0U, 1U, 1U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 27U, 0U,
               "matlabEngineCaller_customLayers", 0, -1, 2692);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 27U, 9U, 2641, -1, 2677);
  covrtBasicBlockInit(&emlrtCoverageInstance, 27U, 8U, 2541, -1, 2594);
  covrtBasicBlockInit(&emlrtCoverageInstance, 27U, 7U, 2343, -1, 2484);
  covrtBasicBlockInit(&emlrtCoverageInstance, 27U, 6U, 2274, -1, 2299);
  covrtBasicBlockInit(&emlrtCoverageInstance, 27U, 5U, 802, -1, 2191);
  covrtBasicBlockInit(&emlrtCoverageInstance, 27U, 4U, 689, -1, 786);
  covrtBasicBlockInit(&emlrtCoverageInstance, 27U, 3U, 646, -1, 675);
  covrtBasicBlockInit(&emlrtCoverageInstance, 27U, 2U, 585, -1, 614);
  covrtBasicBlockInit(&emlrtCoverageInstance, 27U, 1U, 492, -1, 571);
  covrtBasicBlockInit(&emlrtCoverageInstance, 27U, 0U, 111, -1, 438);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 27U, 0U, 440, 465, 788, 2691);
  covrtIfInit(&emlrtCoverageInstance, 27U, 1U, 470, 483, -1, 580);
  covrtIfInit(&emlrtCoverageInstance, 27U, 2U, 620, 637, -1, 684);
  covrtIfInit(&emlrtCoverageInstance, 27U, 3U, 2248, 2265, 2628, 2686);
  covrtIfInit(&emlrtCoverageInstance, 27U, 4U, 2498, 2524, -1, 2611);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 27U, 0U, 623, 637, 1, 0,
                cond_starts_27_0, cond_ends_27_0, 2, postfix_exprs_27_0);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 27U, 0U, 2309, 2331, 2623);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 27U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",
                  28U, 1U, 11U, 1U, 0U, 0U, 0U, 4U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 28U, 0U, "standardTF_custlay_paraPoints",
               0, -1, 3500);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 10U, 2980, -1, 3489);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 9U, 2909, -1, 2962);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 8U, 2820, -1, 2890);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 7U, 2281, -1, 2785);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 6U, 2200, -1, 2245);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 5U, 2172, -1, 2194);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 4U, 2052, -1, 2138);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 3U, 2019, -1, 2046);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 2U, 1896, -1, 1985);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 1U, 1861, -1, 1890);
  covrtBasicBlockInit(&emlrtCoverageInstance, 28U, 0U, 1293, -1, 1827);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 28U, 0U, 2792, 2811, 2896, 2971);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 28U, 0U, 1829, 1857, 1895);
  covrtForInit(&emlrtCoverageInstance, 28U, 1U, 1987, 2015, 2051);
  covrtForInit(&emlrtCoverageInstance, 28U, 2U, 2140, 2168, 2199);
  covrtForInit(&emlrtCoverageInstance, 28U, 3U, 2249, 2277, 3494);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 28U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",
                  29U, 1U, 11U, 1U, 0U, 0U, 0U, 4U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 29U, 0U,
               "standardTF_custlay_paraContrasts", 0, -1, 3506);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 29U, 10U, 2986, -1, 3495);
  covrtBasicBlockInit(&emlrtCoverageInstance, 29U, 9U, 2915, -1, 2968);
  covrtBasicBlockInit(&emlrtCoverageInstance, 29U, 8U, 2826, -1, 2896);
  covrtBasicBlockInit(&emlrtCoverageInstance, 29U, 7U, 2287, -1, 2791);
  covrtBasicBlockInit(&emlrtCoverageInstance, 29U, 6U, 2203, -1, 2248);
  covrtBasicBlockInit(&emlrtCoverageInstance, 29U, 5U, 2175, -1, 2197);
  covrtBasicBlockInit(&emlrtCoverageInstance, 29U, 4U, 2055, -1, 2141);
  covrtBasicBlockInit(&emlrtCoverageInstance, 29U, 3U, 2022, -1, 2049);
  covrtBasicBlockInit(&emlrtCoverageInstance, 29U, 2U, 1899, -1, 1988);
  covrtBasicBlockInit(&emlrtCoverageInstance, 29U, 1U, 1864, -1, 1893);
  covrtBasicBlockInit(&emlrtCoverageInstance, 29U, 0U, 1296, -1, 1830);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 29U, 0U, 2798, 2817, 2902, 2977);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 29U, 0U, 1832, 1860, 1898);
  covrtForInit(&emlrtCoverageInstance, 29U, 1U, 1990, 2018, 2054);
  covrtForInit(&emlrtCoverageInstance, 29U, 2U, 2143, 2171, 2202);
  covrtForInit(&emlrtCoverageInstance, 29U, 3U, 2252, -1, 3500);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 29U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",
                  30U, 1U, 17U, 2U, 0U, 0U, 1U, 6U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 30U, 0U,
               "standardTF_custXY_reflectivityCalculation", 0, -1, 8347);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 30U, 16U, 8180, -1, 8330);
  covrtBasicBlockInit(&emlrtCoverageInstance, 30U, 15U, 6590, -1, 6888);
  covrtBasicBlockInit(&emlrtCoverageInstance, 30U, 14U, 4074, -1, 5256);
  covrtBasicBlockInit(&emlrtCoverageInstance, 30U, 13U, 2859, -1, 4037);
  covrtBasicBlockInit(&emlrtCoverageInstance, 30U, 12U, 2742, -1, 2814);
  covrtBasicBlockInit(&emlrtCoverageInstance, 30U, 11U, 2714, -1, 2736);
  covrtBasicBlockInit(&emlrtCoverageInstance, 30U, 10U, 2593, -1, 2680);
  covrtBasicBlockInit(&emlrtCoverageInstance, 30U, 9U, 2560, -1, 2587);
  covrtBasicBlockInit(&emlrtCoverageInstance, 30U, 8U, 2439, -1, 2526);
  covrtBasicBlockInit(&emlrtCoverageInstance, 30U, 7U, 2404, -1, 2433);
  covrtBasicBlockInit(&emlrtCoverageInstance, 30U, 6U, 2282, -1, 2370);
  covrtBasicBlockInit(&emlrtCoverageInstance, 30U, 5U, 2244, -1, 2276);
  covrtBasicBlockInit(&emlrtCoverageInstance, 30U, 4U, 2120, -1, 2210);
  covrtBasicBlockInit(&emlrtCoverageInstance, 30U, 3U, 2087, -1, 2114);
  covrtBasicBlockInit(&emlrtCoverageInstance, 30U, 2U, 1964, -1, 2053);
  covrtBasicBlockInit(&emlrtCoverageInstance, 30U, 1U, 1929, -1, 1958);
  covrtBasicBlockInit(&emlrtCoverageInstance, 30U, 0U, 218, -1, 1895);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 30U, 0U, 8129, 8154, -1, 8343);
  covrtIfInit(&emlrtCoverageInstance, 30U, 1U, 8159, 8171, -1, 8339);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 30U, 0U, 1897, 1925, 1963);
  covrtForInit(&emlrtCoverageInstance, 30U, 1U, 2055, 2083, 2119);
  covrtForInit(&emlrtCoverageInstance, 30U, 2U, 2212, 2240, 2281);
  covrtForInit(&emlrtCoverageInstance, 30U, 3U, 2372, 2400, 2438);
  covrtForInit(&emlrtCoverageInstance, 30U, 4U, 2528, 2556, 2592);
  covrtForInit(&emlrtCoverageInstance, 30U, 5U, 2682, 2710, 2741);

  /* Initialize While Information */
  /* Initialize Switch Information */
  covrtSwitchInit(&emlrtCoverageInstance, 30U, 0U, 2817, 2833, 6588, 3U,
                  caseStarts_30_0, caseExprEnds_30_0);

  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 30U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",
                  31U, 1U, 8U, 0U, 0U, 0U, 0U, 4U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 31U, 0U, "standardTF_custXY_single", 0,
               -1, 3482);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 31U, 7U, 2276, -1, 3471);
  covrtBasicBlockInit(&emlrtCoverageInstance, 31U, 6U, 2195, -1, 2240);
  covrtBasicBlockInit(&emlrtCoverageInstance, 31U, 5U, 2167, -1, 2189);
  covrtBasicBlockInit(&emlrtCoverageInstance, 31U, 4U, 2047, -1, 2133);
  covrtBasicBlockInit(&emlrtCoverageInstance, 31U, 3U, 2014, -1, 2041);
  covrtBasicBlockInit(&emlrtCoverageInstance, 31U, 2U, 1891, -1, 1980);
  covrtBasicBlockInit(&emlrtCoverageInstance, 31U, 1U, 1856, -1, 1885);
  covrtBasicBlockInit(&emlrtCoverageInstance, 31U, 0U, 1288, -1, 1822);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 31U, 0U, 1824, 1852, 1890);
  covrtForInit(&emlrtCoverageInstance, 31U, 1U, 1982, 2010, 2046);
  covrtForInit(&emlrtCoverageInstance, 31U, 2U, 2135, 2163, 2194);
  covrtForInit(&emlrtCoverageInstance, 31U, 3U, 2244, 2272, 3476);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 31U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/call_customXY.m",
                  32U, 1U, 4U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 32U, 0U, "call_customXY", 0, -1, 332);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 32U, 3U, 308, -1, 326);
  covrtBasicBlockInit(&emlrtCoverageInstance, 32U, 2U, 289, -1, 301);
  covrtBasicBlockInit(&emlrtCoverageInstance, 32U, 1U, 259, -1, 278);
  covrtBasicBlockInit(&emlrtCoverageInstance, 32U, 0U, 88, -1, 229);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 32U, 0U, 235, 254, 280, 306);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 32U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",
                  33U, 1U, 8U, 0U, 0U, 0U, 0U, 4U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 33U, 0U, "standardTF_custXY_paraPoints",
               0, -1, 3486);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 33U, 7U, 2280, -1, 3475);
  covrtBasicBlockInit(&emlrtCoverageInstance, 33U, 6U, 2199, -1, 2244);
  covrtBasicBlockInit(&emlrtCoverageInstance, 33U, 5U, 2171, -1, 2193);
  covrtBasicBlockInit(&emlrtCoverageInstance, 33U, 4U, 2051, -1, 2137);
  covrtBasicBlockInit(&emlrtCoverageInstance, 33U, 3U, 2018, -1, 2045);
  covrtBasicBlockInit(&emlrtCoverageInstance, 33U, 2U, 1895, -1, 1984);
  covrtBasicBlockInit(&emlrtCoverageInstance, 33U, 1U, 1860, -1, 1889);
  covrtBasicBlockInit(&emlrtCoverageInstance, 33U, 0U, 1292, -1, 1826);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 33U, 0U, 1828, 1856, 1894);
  covrtForInit(&emlrtCoverageInstance, 33U, 1U, 1986, 2014, 2050);
  covrtForInit(&emlrtCoverageInstance, 33U, 2U, 2139, 2167, 2198);
  covrtForInit(&emlrtCoverageInstance, 33U, 3U, 2248, 2276, 3480);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 33U);
  emlrtSetGlobalSyncFcn(sp, (void (*)(const void *))&emlrt_synchGlobalsToML);
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
    reflectivity_calculation_once(&st);
  }
}

/* End of code generation (reflectivity_calculation_initialize.c) */
