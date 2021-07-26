//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// reflectivity_calculation.cpp
//
// Code generation for function 'reflectivity_calculation'
//

// Include files
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_initialize.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_rtwutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_reflectivityCalculation.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Type Definitions
struct cell_wrap_11 {
  coder::array<double, 2U> f1;
};

// Function Declarations
static void c_cast(const coder::array<double, 2U> &t5_f1,
                   coder::array<double, 2U> &t6_f1);

static void cast(const coder::array<cell_wrap_0, 2U> &t2_f1,
                 const coder::array<cell_wrap_1, 2U> &t2_f2,
                 const coder::array<cell_wrap_0, 2U> &t2_f3,
                 const coder::array<cell_wrap_0, 2U> &t2_f4,
                 const coder::array<cell_wrap_2, 2U> &t2_f5,
                 const coder::array<cell_wrap_3, 1U> &t2_f6,
                 const coder::array<cell_wrap_4, 2U> &t2_f7,
                 const coder::array<cell_wrap_4, 2U> &t2_f8,
                 const coder::array<cell_wrap_4, 2U> &t2_f9,
                 const coder::array<cell_wrap_4, 2U> &t2_f10,
                 const coder::array<cell_wrap_4, 2U> &t2_f11,
                 const coder::array<cell_wrap_4, 2U> &t2_f12,
                 const coder::array<cell_wrap_4, 2U> &t2_f13,
                 const coder::array<cell_wrap_5, 2U> &t2_f14, cell_14 *b);

static void cast(const coder::array<cell_wrap_3, 1U> &b,
                 coder::array<cell_wrap_2, 1U> &c);

static void cast(const double t0_f1_data[], const int t0_f1_size[2],
                 coder::array<double, 2U> &t1_f1);

static void cast(const coder::array<cell_wrap_7, 1U> &b,
                 coder::array<cell_wrap_10, 1U> &c);

static void cast(const coder::array<cell_wrap_1, 1U> &b,
                 coder::array<cell_wrap_11, 1U> &c);

static void cast(const coder::array<cell_wrap_8, 1U> &b,
                 coder::array<cell_wrap_11, 1U> &c);

static void cast(const coder::array<cell_wrap_1, 1U> &b,
                 coder::array<cell_wrap_10, 1U> &c);

// Function Definitions
static void c_cast(const coder::array<double, 2U> &t5_f1,
                   coder::array<double, 2U> &t6_f1)
{
  int loop_ub;
  t6_f1.set_size(t5_f1.size(0), 3);
  loop_ub = t5_f1.size(0) * 3;
  for (int i{0}; i < loop_ub; i++) {
    t6_f1[i] = t5_f1[i];
  }
}

static void cast(const coder::array<cell_wrap_0, 2U> &t2_f1,
                 const coder::array<cell_wrap_1, 2U> &t2_f2,
                 const coder::array<cell_wrap_0, 2U> &t2_f3,
                 const coder::array<cell_wrap_0, 2U> &t2_f4,
                 const coder::array<cell_wrap_2, 2U> &t2_f5,
                 const coder::array<cell_wrap_3, 1U> &t2_f6,
                 const coder::array<cell_wrap_4, 2U> &t2_f7,
                 const coder::array<cell_wrap_4, 2U> &t2_f8,
                 const coder::array<cell_wrap_4, 2U> &t2_f9,
                 const coder::array<cell_wrap_4, 2U> &t2_f10,
                 const coder::array<cell_wrap_4, 2U> &t2_f11,
                 const coder::array<cell_wrap_4, 2U> &t2_f12,
                 const coder::array<cell_wrap_4, 2U> &t2_f13,
                 const coder::array<cell_wrap_5, 2U> &t2_f14, cell_14 *b)
{
  int i;
  int loop_ub;
  b->f1.set_size(1, t2_f1.size(1));
  loop_ub = t2_f1.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f1[i] = t2_f1[i];
  }
  b->f2.set_size(1, t2_f2.size(1));
  loop_ub = t2_f2.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f2[i] = t2_f2[i];
  }
  b->f3.set_size(1, t2_f3.size(1));
  loop_ub = t2_f3.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f3[i] = t2_f3[i];
  }
  b->f4.set_size(1, t2_f4.size(1));
  loop_ub = t2_f4.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f4[i] = t2_f4[i];
  }
  b->f5.set_size(1, t2_f5.size(1));
  loop_ub = t2_f5.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f5[i] = t2_f5[i];
  }
  cast(t2_f6, b->f6);
  b->f7.set_size(1, t2_f7.size(1));
  loop_ub = t2_f7.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f7[i] = t2_f7[i];
  }
  b->f8.set_size(1, t2_f8.size(1));
  loop_ub = t2_f8.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f8[i] = t2_f8[i];
  }
  b->f9.set_size(1, t2_f9.size(1));
  loop_ub = t2_f9.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f9[i] = t2_f9[i];
  }
  b->f10.set_size(1, t2_f10.size(1));
  loop_ub = t2_f10.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f10[i] = t2_f10[i];
  }
  b->f11.set_size(1, t2_f11.size(1));
  loop_ub = t2_f11.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f11[i] = t2_f11[i];
  }
  b->f12.set_size(1, t2_f12.size(1));
  loop_ub = t2_f12.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f12[i] = t2_f12[i];
  }
  b->f13.set_size(1, t2_f13.size(1));
  loop_ub = t2_f13.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f13[i] = t2_f13[i];
  }
  b->f14.set_size(1, t2_f14.size(1));
  loop_ub = t2_f14.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f14[i] = t2_f14[i];
  }
}

static void cast(const coder::array<cell_wrap_3, 1U> &b,
                 coder::array<cell_wrap_2, 1U> &c)
{
  int i;
  c.set_size(b.size(0));
  i = b.size(0);
  for (int i1{0}; i1 < i; i1++) {
    cast(b[i1].f1.data, b[i1].f1.size, c[i1].f1);
  }
}

static void cast(const double t0_f1_data[], const int t0_f1_size[2],
                 coder::array<double, 2U> &t1_f1)
{
  int loop_ub;
  t1_f1.set_size(1, t0_f1_size[1]);
  loop_ub = t0_f1_size[1];
  for (int i{0}; i < loop_ub; i++) {
    t1_f1[i] = t0_f1_data[i];
  }
}

static void cast(const coder::array<cell_wrap_7, 1U> &b,
                 coder::array<cell_wrap_10, 1U> &c)
{
  int i;
  c.set_size(b.size(0));
  i = b.size(0);
  for (int i1{0}; i1 < i; i1++) {
    cast(b[i1].f1, c[i1].f1);
  }
}

static void cast(const coder::array<cell_wrap_1, 1U> &b,
                 coder::array<cell_wrap_11, 1U> &c)
{
  int i;
  c.set_size(b.size(0));
  i = b.size(0);
  for (int i1{0}; i1 < i; i1++) {
    b_cast(b[i1].f1, c[i1].f1);
  }
}

static void cast(const coder::array<cell_wrap_8, 1U> &b,
                 coder::array<cell_wrap_11, 1U> &c)
{
  int i;
  c.set_size(b.size(0));
  i = b.size(0);
  for (int i1{0}; i1 < i; i1++) {
    c_cast(b[i1].f1, c[i1].f1);
  }
}

static void cast(const coder::array<cell_wrap_1, 1U> &b,
                 coder::array<cell_wrap_10, 1U> &c)
{
  int i;
  c.set_size(b.size(0));
  i = b.size(0);
  for (int i1{0}; i1 < i; i1++) {
    b_cast(b[i1].f1, c[i1].f1);
  }
}

void reflectivity_calculation(const struct0_T *problemDef,
                              const cell_6 *problemDef_cells, const struct1_T *,
                              const struct2_T *controls, struct4_T *problem,
                              cell_9 *result)
{
  coder::array<cell_wrap_1, 1U> allLayers;
  coder::array<cell_wrap_1, 1U> b_shifted_data;
  coder::array<cell_wrap_1, 1U> b_sldProfiles;
  coder::array<cell_wrap_10, 1U> Simulation;
  coder::array<cell_wrap_10, 1U> reflectivity;
  coder::array<cell_wrap_10, 1U> sldProfiles;
  coder::array<cell_wrap_11, 1U> layerSlds;
  coder::array<cell_wrap_11, 1U> shifted_data;
  coder::array<cell_wrap_7, 1U> b_Simulation;
  coder::array<cell_wrap_7, 1U> b_reflectivity;
  coder::array<cell_wrap_8, 1U> b_layerSlds;
  coder::array<signed char, 1U> cell6;
  cell_14 r;
  int b_i;
  int i;
  int i1;
  int loop_ub;
  if (!isInitialized_reflectivity_calculation) {
    reflectivity_calculation_initialize();
  }
  // Preallocatin of outputs
  problem->ssubs.set_size(1);
  problem->ssubs[0] = 0.0;
  problem->backgrounds.set_size(1);
  problem->backgrounds[0] = 0.0;
  problem->qshifts.set_size(1);
  problem->qshifts[0] = 0.0;
  problem->scalefactors.set_size(1);
  problem->scalefactors[0] = 0.0;
  problem->nbairs.set_size(1);
  problem->nbairs[0] = 0.0;
  problem->nbsubs.set_size(1);
  problem->nbsubs[0] = 0.0;
  problem->resolutions.set_size(1);
  problem->resolutions[0] = 0.0;
  problem->calculations.all_chis.set_size(1);
  problem->calculations.all_chis[0] = 0.0;
  problem->calculations.sum_chi = 0.0;
  problem->allSubRough.set_size(1);
  problem->allSubRough[0] = 0.0;
  i = static_cast<int>(problemDef->numberOfContrasts);
  reflectivity.set_size(i);
  Simulation.set_size(i);
  shifted_data.set_size(i);
  layerSlds.set_size(i);
  sldProfiles.set_size(i);
  for (b_i = 0; b_i < i; b_i++) {
    reflectivity[b_i].f1.set_size(2, 2);
    reflectivity[b_i].f1[0] = 1.0;
    reflectivity[b_i].f1[1] = 1.0;
    reflectivity[b_i].f1[2] = 1.0;
    reflectivity[b_i].f1[3] = 1.0;
    Simulation[b_i].f1.set_size(2, 2);
    Simulation[b_i].f1[0] = 1.0;
    Simulation[b_i].f1[1] = 1.0;
    Simulation[b_i].f1[2] = 1.0;
    Simulation[b_i].f1[3] = 1.0;
    shifted_data[b_i].f1.set_size(2, 3);
    layerSlds[b_i].f1.set_size(2, 3);
    for (i1 = 0; i1 < 6; i1++) {
      shifted_data[b_i].f1[i1] = 1.0;
      layerSlds[b_i].f1[i1] = 1.0;
    }
    sldProfiles[b_i].f1.set_size(2, 2);
    sldProfiles[b_i].f1[0] = 1.0;
    sldProfiles[b_i].f1[1] = 1.0;
    sldProfiles[b_i].f1[2] = 1.0;
    sldProfiles[b_i].f1[3] = 1.0;
  }
  // Decide which target function we are calling
  if (coder::internal::b_strcmp(problemDef->TF)) {
    i1 = 0;
  } else {
    i1 = -1;
  }
  switch (i1) {
  case 0:
    cast(problemDef_cells->f1, problemDef_cells->f2, problemDef_cells->f3,
         problemDef_cells->f4, problemDef_cells->f5, problemDef_cells->f6,
         problemDef_cells->f7, problemDef_cells->f8, problemDef_cells->f9,
         problemDef_cells->f10, problemDef_cells->f11, problemDef_cells->f12,
         problemDef_cells->f13, problemDef_cells->f14, &r);
    standardTF_reflectivityCalculation(
        problemDef, &r, controls, problem, b_reflectivity, b_Simulation,
        b_shifted_data, b_layerSlds, b_sldProfiles, allLayers);
    cast(b_reflectivity, reflectivity);
    cast(b_Simulation, Simulation);
    cast(b_shifted_data, shifted_data);
    cast(b_layerSlds, layerSlds);
    cast(b_sldProfiles, sldProfiles);
    // case 'oilWaterTF'
    // problem =
    // oilWaterTF_reflectivityCalculation(problemDef,problemDef_cells,controls);
    // case 'polarisedTF'
    // problem =
    // polarisedTF_reflectivityCalculation(problemDef,problemDef_cells,controls);
    // case 'domainsTF'
    // problem =
    // domainsTF_reflectivityCalculation(problemDef,problemDef_cells,controls);
    break;
  }
  // cell1Length = numberOfContrasts;
  result->f1.set_size(i);
  //  cell2Length = 7;
  result->f2.set_size(i);
  //
  //  cell3Length = 7;
  result->f3.set_size(i);
  //
  //  cell4Length = 7;
  result->f4.set_size(i);
  //
  //  cell5Length = 7;
  result->f5.set_size(i);
  //
  //  cell6Length = 7;
  cell6.set_size(i);
  for (b_i = 0; b_i < i; b_i++) {
    result->f1[b_i].f1.set_size(reflectivity[b_i].f1.size(0), 2);
    loop_ub = reflectivity[b_i].f1.size(0) * 2;
    for (i1 = 0; i1 < loop_ub; i1++) {
      result->f1[b_i].f1[i1] = reflectivity[b_i].f1[i1];
    }
    result->f2[b_i].f1.set_size(Simulation[b_i].f1.size(0), 2);
    loop_ub = Simulation[b_i].f1.size(0) * 2;
    for (i1 = 0; i1 < loop_ub; i1++) {
      result->f2[b_i].f1[i1] = Simulation[b_i].f1[i1];
    }
    result->f3[b_i].f1.set_size(shifted_data[b_i].f1.size(0), 3);
    loop_ub = shifted_data[b_i].f1.size(0) * 3;
    for (i1 = 0; i1 < loop_ub; i1++) {
      result->f3[b_i].f1[i1] = shifted_data[b_i].f1[i1];
    }
    result->f4[b_i].f1.set_size(layerSlds[b_i].f1.size(0), 3);
    loop_ub = layerSlds[b_i].f1.size(0) * 3;
    for (i1 = 0; i1 < loop_ub; i1++) {
      result->f4[b_i].f1[i1] = layerSlds[b_i].f1[i1];
    }
    result->f5[b_i].f1.set_size(sldProfiles[b_i].f1.size(0), 2);
    loop_ub = sldProfiles[b_i].f1.size(0) * 2;
    for (i1 = 0; i1 < loop_ub; i1++) {
      result->f5[b_i].f1[i1] = sldProfiles[b_i].f1[i1];
    }
    cell6[b_i] = 0;
  }
  result->f6.set_size(cell6.size(0));
  loop_ub = cell6.size(0);
  for (i = 0; i < loop_ub; i++) {
    result->f6[i] = 0.0;
  }
}

// End of code generation (reflectivity_calculation.cpp)
