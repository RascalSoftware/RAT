//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: reflectivity_calculation.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_reflectivityCalculation.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>

// Type Definitions
namespace RAT
{
  struct cell_wrap_13
  {
    ::coder::array<real_T, 2U> f1;
  };
}

// Function Declarations
namespace RAT
{
  static void cast(const cell_wrap_0 t0_f1_data[], const int32_T t0_f1_size[2],
                   const ::coder::array<cell_wrap_1, 2U> &t0_f2, const
                   cell_wrap_0 t0_f3_data[], const int32_T t0_f3_size[2], const
                   cell_wrap_2 t0_f4_data[], const int32_T t0_f4_size[2], const ::
                   coder::array<cell_wrap_3, 2U> &t0_f5, const ::coder::array<
                   cell_wrap_4, 1U> &t0_f6, const ::coder::array<cell_wrap_5, 2U>
                   &t0_f7, const ::coder::array<cell_wrap_6, 2U> &t0_f8, const ::
                   coder::array<cell_wrap_6, 2U> &t0_f9, const ::coder::array<
                   cell_wrap_6, 2U> &t0_f10, const ::coder::array<cell_wrap_6,
                   2U> &t0_f11, const ::coder::array<cell_wrap_6, 2U> &t0_f12,
                   const ::coder::array<cell_wrap_6, 2U> &t0_f13, const ::coder::
                   array<cell_wrap_7, 2U> &t0_f14, cell_18 *r);
  static void cast(const ::coder::array<cell_wrap_1, 2U> &r, cell_wrap_14 _data[],
                   int32_T _size[2]);
  static void cast(const cell_wrap_2 _data[], const int32_T _size[2],
                   cell_wrap_14 b__data[], int32_T b__size[2]);
  static void cast(const ::coder::array<cell_wrap_3, 2U> &r, cell_wrap_14 _data[],
                   int32_T _size[2]);
  static void cast(const ::coder::array<cell_wrap_4, 1U> &r, cell_wrap_14 _data[],
                   int32_T *_size);
  static void cast(const ::coder::array<cell_wrap_9, 1U> &r, ::coder::array<
                   cell_wrap_12, 1U> &r1);
  static void cast(const ::coder::array<cell_wrap_10, 1U> &r, ::coder::array<
                   cell_wrap_13, 1U> &r1);
  static void cast(const ::coder::array<cell_wrap_14, 1U> &r, ::coder::array<
                   cell_wrap_12, 1U> &r1);
  static void cast(const ::coder::array<cell_wrap_14, 1U> &r, ::coder::array<
                   cell_wrap_13, 1U> &r1);
}

// Function Definitions
//
// Arguments    : const cell_wrap_0 t0_f1_data[]
//                const int32_T t0_f1_size[2]
//                const ::coder::array<cell_wrap_1, 2U> &t0_f2
//                const cell_wrap_0 t0_f3_data[]
//                const int32_T t0_f3_size[2]
//                const cell_wrap_2 t0_f4_data[]
//                const int32_T t0_f4_size[2]
//                const ::coder::array<cell_wrap_3, 2U> &t0_f5
//                const ::coder::array<cell_wrap_4, 1U> &t0_f6
//                const ::coder::array<cell_wrap_5, 2U> &t0_f7
//                const ::coder::array<cell_wrap_6, 2U> &t0_f8
//                const ::coder::array<cell_wrap_6, 2U> &t0_f9
//                const ::coder::array<cell_wrap_6, 2U> &t0_f10
//                const ::coder::array<cell_wrap_6, 2U> &t0_f11
//                const ::coder::array<cell_wrap_6, 2U> &t0_f12
//                const ::coder::array<cell_wrap_6, 2U> &t0_f13
//                const ::coder::array<cell_wrap_7, 2U> &t0_f14
//                cell_18 *r
// Return Type  : void
//
namespace RAT
{
  static void cast(const cell_wrap_0 t0_f1_data[], const int32_T t0_f1_size[2],
                   const ::coder::array<cell_wrap_1, 2U> &t0_f2, const
                   cell_wrap_0 t0_f3_data[], const int32_T t0_f3_size[2], const
                   cell_wrap_2 t0_f4_data[], const int32_T t0_f4_size[2], const ::
                   coder::array<cell_wrap_3, 2U> &t0_f5, const ::coder::array<
                   cell_wrap_4, 1U> &t0_f6, const ::coder::array<cell_wrap_5, 2U>
                   &t0_f7, const ::coder::array<cell_wrap_6, 2U> &t0_f8, const ::
                   coder::array<cell_wrap_6, 2U> &t0_f9, const ::coder::array<
                   cell_wrap_6, 2U> &t0_f10, const ::coder::array<cell_wrap_6,
                   2U> &t0_f11, const ::coder::array<cell_wrap_6, 2U> &t0_f12,
                   const ::coder::array<cell_wrap_6, 2U> &t0_f13, const ::coder::
                   array<cell_wrap_7, 2U> &t0_f14, cell_18 *r)
  {
    int32_T loop_ub;
    r->f1.size[0] = 1;
    r->f1.size[1] = t0_f1_size[1];
    loop_ub = t0_f1_size[1];
    if (loop_ub - 1 >= 0) {
      std::copy(&t0_f1_data[0], &t0_f1_data[loop_ub], &r->f1.data[0]);
    }

    cast(t0_f2, r->f2.data, r->f2.size);
    r->f3.size[0] = 1;
    r->f3.size[1] = t0_f3_size[1];
    loop_ub = t0_f3_size[1];
    if (loop_ub - 1 >= 0) {
      std::copy(&t0_f3_data[0], &t0_f3_data[loop_ub], &r->f3.data[0]);
    }

    cast(t0_f4_data, t0_f4_size, r->f4.data, r->f4.size);
    cast(t0_f5, r->f5.data, r->f5.size);
    cast(t0_f6, r->f6.data, &r->f6.size[0]);
    r->f7.set_size(1, t0_f7.size(1));
    loop_ub = t0_f7.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      r->f7[i] = t0_f7[i];
    }

    r->f8.set_size(1, t0_f8.size(1));
    loop_ub = t0_f8.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      r->f8[i] = t0_f8[i];
    }

    r->f9.set_size(1, t0_f9.size(1));
    loop_ub = t0_f9.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      r->f9[i] = t0_f9[i];
    }

    r->f10.set_size(1, t0_f10.size(1));
    loop_ub = t0_f10.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      r->f10[i] = t0_f10[i];
    }

    r->f11.set_size(1, t0_f11.size(1));
    loop_ub = t0_f11.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      r->f11[i] = t0_f11[i];
    }

    r->f12.set_size(1, t0_f12.size(1));
    loop_ub = t0_f12.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      r->f12[i] = t0_f12[i];
    }

    r->f13.set_size(1, t0_f13.size(1));
    loop_ub = t0_f13.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      r->f13[i] = t0_f13[i];
    }

    r->f14.set_size(1, t0_f14.size(1));
    loop_ub = t0_f14.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      r->f14[i] = t0_f14[i];
    }
  }

  //
  // Arguments    : const ::coder::array<cell_wrap_1, 2U> &r
  //                cell_wrap_14 _data[]
  //                int32_T _size[2]
  // Return Type  : void
  //
  static void cast(const ::coder::array<cell_wrap_1, 2U> &r, cell_wrap_14 _data[],
                   int32_T _size[2])
  {
    int32_T i;
    _size[0] = 1;
    _size[1] = r.size(1);
    i = r.size(1) - 1;
    for (int32_T i1{0}; i1 <= i; i1++) {
      int32_T loop_ub;
      loop_ub = r[i1].f1.size[1];
      _data[_size[0] * i1].f1.set_size(r[r.size(0) * i1].f1.size[0], r[r.size(0)
        * i1].f1.size[1]);
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = r[i1].f1.size[0];
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          _data[i1].f1[i3 + _data[i1].f1.size(0) * i2] = r[i1].f1.data[i3 + r[i1]
            .f1.size[0] * i2];
        }
      }
    }
  }

  //
  // Arguments    : const cell_wrap_2 _data[]
  //                const int32_T _size[2]
  //                cell_wrap_14 b__data[]
  //                int32_T b__size[2]
  // Return Type  : void
  //
  static void cast(const cell_wrap_2 _data[], const int32_T _size[2],
                   cell_wrap_14 b__data[], int32_T b__size[2])
  {
    int32_T i;
    b__size[0] = 1;
    b__size[1] = _size[1];
    i = _size[1] - 1;
    for (int32_T i1{0}; i1 <= i; i1++) {
      int32_T i2;
      int32_T loop_ub;
      loop_ub = _data[i1].f1.size[1];
      i2 = _size[0] * i1;
      b__data[b__size[0] * i1].f1.set_size(_data[i2].f1.size[0], _data[i2].
        f1.size[1]);
      for (i2 = 0; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = _data[i1].f1.size[0];
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          b__data[i1].f1[b__data[i1].f1.size(0) * i2] = _data[i1]
            .f1.data[_data[i1].f1.size[0] * i2];
        }
      }
    }
  }

  //
  // Arguments    : const ::coder::array<cell_wrap_3, 2U> &r
  //                cell_wrap_14 _data[]
  //                int32_T _size[2]
  // Return Type  : void
  //
  static void cast(const ::coder::array<cell_wrap_3, 2U> &r, cell_wrap_14 _data[],
                   int32_T _size[2])
  {
    int32_T i;
    _size[0] = 1;
    _size[1] = r.size(1);
    i = r.size(1) - 1;
    for (int32_T i1{0}; i1 <= i; i1++) {
      int32_T loop_ub;
      loop_ub = r[i1].f1.size[1];
      _data[_size[0] * i1].f1.set_size(r[r.size(0) * i1].f1.size[0], r[r.size(0)
        * i1].f1.size[1]);
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = r[i1].f1.size[0];
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          _data[i1].f1[_data[i1].f1.size(0) * i2] = r[i1].f1.data[r[i1].f1.size
            [0] * i2];
        }
      }
    }
  }

  //
  // Arguments    : const ::coder::array<cell_wrap_4, 1U> &r
  //                cell_wrap_14 _data[]
  //                int32_T *_size
  // Return Type  : void
  //
  static void cast(const ::coder::array<cell_wrap_4, 1U> &r, cell_wrap_14 _data[],
                   int32_T *_size)
  {
    int32_T i;
    *_size = r.size(0);
    i = r.size(0);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = r[i1].f1.size[1];
      _data[i1].f1.set_size(r[i1].f1.size[0], r[i1].f1.size[1]);
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = r[i1].f1.size[0];
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          _data[i1].f1[_data[i1].f1.size(0) * i2] = r[i1].f1.data[r[i1].f1.size
            [0] * i2];
        }
      }
    }
  }

  //
  // Arguments    : const ::coder::array<cell_wrap_9, 1U> &r
  //                ::coder::array<cell_wrap_12, 1U> &r1
  // Return Type  : void
  //
  static void cast(const ::coder::array<cell_wrap_9, 1U> &r, ::coder::array<
                   cell_wrap_12, 1U> &r1)
  {
    int32_T i;
    r1.set_size(r.size(0));
    i = r.size(0);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = r[i1].f1.size(0);
      r1[i1].f1.set_size(r[i1].f1.size(0), 2);
      for (int32_T i2{0}; i2 < 2; i2++) {
        for (int32_T i3{0}; i3 < loop_ub; i3++) {
          r1[i1].f1[i3 + r1[i1].f1.size(0) * i2] = r[i1].f1[i3 + r[i1].f1.size(0)
            * i2];
        }
      }
    }
  }

  //
  // Arguments    : const ::coder::array<cell_wrap_10, 1U> &r
  //                ::coder::array<cell_wrap_13, 1U> &r1
  // Return Type  : void
  //
  static void cast(const ::coder::array<cell_wrap_10, 1U> &r, ::coder::array<
                   cell_wrap_13, 1U> &r1)
  {
    int32_T i;
    r1.set_size(r.size(0));
    i = r.size(0);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = r[i1].f1.size(0);
      r1[i1].f1.set_size(r[i1].f1.size(0), 3);
      for (int32_T i2{0}; i2 < 3; i2++) {
        for (int32_T i3{0}; i3 < loop_ub; i3++) {
          r1[i1].f1[i3 + r1[i1].f1.size(0) * i2] = r[i1].f1[i3 + r[i1].f1.size(0)
            * i2];
        }
      }
    }
  }

  //
  // Arguments    : const ::coder::array<cell_wrap_14, 1U> &r
  //                ::coder::array<cell_wrap_12, 1U> &r1
  // Return Type  : void
  //
  static void cast(const ::coder::array<cell_wrap_14, 1U> &r, ::coder::array<
                   cell_wrap_12, 1U> &r1)
  {
    int32_T i;
    r1.set_size(r.size(0));
    i = r.size(0);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = r[i1].f1.size(1);
      r1[i1].f1.set_size(r[i1].f1.size(0), r[i1].f1.size(1));
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = r[i1].f1.size(0);
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          r1[i1].f1[i3 + r1[i1].f1.size(0) * i2] = r[i1].f1[i3 + r[i1].f1.size(0)
            * i2];
        }
      }
    }
  }

  //
  // Arguments    : const ::coder::array<cell_wrap_14, 1U> &r
  //                ::coder::array<cell_wrap_13, 1U> &r1
  // Return Type  : void
  //
  static void cast(const ::coder::array<cell_wrap_14, 1U> &r, ::coder::array<
                   cell_wrap_13, 1U> &r1)
  {
    int32_T i;
    r1.set_size(r.size(0));
    i = r.size(0);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = r[i1].f1.size(1);
      r1[i1].f1.set_size(r[i1].f1.size(0), r[i1].f1.size(1));
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = r[i1].f1.size(0);
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          r1[i1].f1[i3 + r1[i1].f1.size(0) * i2] = r[i1].f1[i3 + r[i1].f1.size(0)
            * i2];
        }
      }
    }
  }

  //
  // Main entry point into the reflectivity calculation for the toolbox.
  //  This is the main function that is called by any of the minimisers or
  //  analysis tools from the rest of the toolbox.
  //
  //  *The main job of this function is to decide which type of calculation (i.e. 'Target function'
  //  is required, and call the relevant routines. The types of available
  //  target functions are:*
  //
  //  * standardTF     - The main basic target function type, for non polarised neutrons (or x-rays) with non-absorbing samples. Different model types are specified in sub functions from here.
  //
  //  * standardTFAbs  - Identical to standardTF, but includes imaginary refractive index terms.
  //
  //  * oilWaterTF     - Target function for oil-water samples
  //
  //  * domainsTF      - Target function for samples consisting of domains which are larger than the beam lateral coherence length.
  //
  //  * polarisedTF    - Target function for cases for polarised neutrons with polarisation analysis.
  //
  //
  // Arguments    : const struct0_T *problemDef
  //                const cell_8 *problemDef_cells
  //                const struct1_T *problemDef_limits
  //                const struct2_T *controls
  //                struct4_T *problem
  //                cell_11 *result
  // Return Type  : void
  //
  void reflectivity_calculation(const struct0_T *problemDef, const cell_8
    *problemDef_cells, const struct1_T *, const struct2_T *controls, struct4_T
    *problem, cell_11 *result)
  {
    static cell_18 r;
    ::coder::array<cell_wrap_10, 1U> b_layerSlds;
    ::coder::array<cell_wrap_12, 1U> Simulation;
    ::coder::array<cell_wrap_12, 1U> reflectivity;
    ::coder::array<cell_wrap_12, 1U> sldProfiles;
    ::coder::array<cell_wrap_13, 1U> allLayers;
    ::coder::array<cell_wrap_13, 1U> layerSlds;
    ::coder::array<cell_wrap_13, 1U> shifted_data;
    ::coder::array<cell_wrap_14, 1U> b_allLayers;
    ::coder::array<cell_wrap_14, 1U> b_shifted_data;
    ::coder::array<cell_wrap_14, 1U> b_sldProfiles;
    ::coder::array<cell_wrap_9, 1U> b_Simulation;
    ::coder::array<cell_wrap_9, 1U> b_reflectivity;
    int32_T i;
    int32_T i1;

    //  for compilation, we have to preallocate memory for the output arrays
    //  Setting these parameters in the struct defines them as doubles
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
    problem->resample.set_size(1, 1);
    problem->resample[0] = 0.0;

    //  We also foll the results arrays to define their
    //  type and size. (NOTE: at the moment we have a 'coder.varsize'
    //  pre-processor directives for the compiler here and at the
    //  end for the results block. We are unlikely to need both
    //  TODO: Find out which is necessary and tidy this up.
    i = static_cast<int32_T>(problemDef->numberOfContrasts);
    reflectivity.set_size(i);
    Simulation.set_size(i);
    shifted_data.set_size(i);
    layerSlds.set_size(i);
    sldProfiles.set_size(i);
    allLayers.set_size(i);
    for (int32_T b_i{0}; b_i < i; b_i++) {
      reflectivity[b_i].f1.set_size(2, 2);
      reflectivity[b_i].f1[0] = 1.0;
      reflectivity[b_i].f1[1] = 1.0;
      reflectivity[b_i].f1[reflectivity[b_i].f1.size(0)] = 1.0;
      reflectivity[b_i].f1[reflectivity[b_i].f1.size(0) + 1] = 1.0;
      Simulation[b_i].f1.set_size(2, 2);
      Simulation[b_i].f1[0] = 1.0;
      Simulation[b_i].f1[1] = 1.0;
      Simulation[b_i].f1[Simulation[b_i].f1.size(0)] = 1.0;
      Simulation[b_i].f1[Simulation[b_i].f1.size(0) + 1] = 1.0;
      shifted_data[b_i].f1.set_size(2, 3);
      layerSlds[b_i].f1.set_size(2, 3);
      sldProfiles[b_i].f1.set_size(2, 2);
      sldProfiles[b_i].f1[0] = 1.0;
      sldProfiles[b_i].f1[1] = 1.0;
      sldProfiles[b_i].f1[sldProfiles[b_i].f1.size(0)] = 1.0;
      sldProfiles[b_i].f1[sldProfiles[b_i].f1.size(0) + 1] = 1.0;
      allLayers[b_i].f1.set_size(2, 3);
      for (i1 = 0; i1 < 3; i1++) {
        shifted_data[b_i].f1[shifted_data[b_i].f1.size(0) * i1] = 1.0;
        shifted_data[b_i].f1[shifted_data[b_i].f1.size(0) * i1 + 1] = 1.0;
        layerSlds[b_i].f1[layerSlds[b_i].f1.size(0) * i1] = 1.0;
        layerSlds[b_i].f1[layerSlds[b_i].f1.size(0) * i1 + 1] = 1.0;
        allLayers[b_i].f1[allLayers[b_i].f1.size(0) * i1] = 1.0;
        allLayers[b_i].f1[allLayers[b_i].f1.size(0) * i1 + 1] = 1.0;
      }
    }

    // Decide which target function we are calling ans call the relevant routines
    if (coder::internal::b_strcmp(problemDef->TF.data, problemDef->TF.size)) {
      i1 = 0;
    } else {
      i1 = -1;
    }

    if (i1 == 0) {
      cast(problemDef_cells->f1.data, problemDef_cells->f1.size,
           problemDef_cells->f2, problemDef_cells->f3.data,
           problemDef_cells->f3.size, problemDef_cells->f4.data,
           problemDef_cells->f4.size, problemDef_cells->f5, problemDef_cells->f6,
           problemDef_cells->f7, problemDef_cells->f8, problemDef_cells->f9,
           problemDef_cells->f10, problemDef_cells->f11, problemDef_cells->f12,
           problemDef_cells->f13, problemDef_cells->f14, &r);
      standardTF_reflectivityCalculation(problemDef, &r, controls, problem,
        b_reflectivity, b_Simulation, b_shifted_data, b_layerSlds, b_sldProfiles,
        b_allLayers);
      cast(b_reflectivity, reflectivity);
      cast(b_Simulation, Simulation);
      cast(b_shifted_data, shifted_data);
      cast(b_layerSlds, layerSlds);
      cast(b_sldProfiles, sldProfiles);
      cast(b_allLayers, allLayers);

      // case 'standardTFAbs'
      // [problem,reflectivity,Simulation,shifted_data,layerSlds,sldProfiles,allLayers] = standardTFAbs_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);
      // case 'oilWaterTF'
      // problem = oilWaterTF_reflectivityCalculation(problemDef,problemDef_cells,controls);
      // case 'polarisedTF'
      // problem = polarisedTF_reflectivityCalculation(problemDef,problemDef_cells,controls);
      // case 'domainsTF'
      // [problem,reflectivity,Simulation,shifted_data,layerSlds,sldProfiles,allLayers] = domainsTF_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);
    }

    result->f1.set_size(i);
    result->f2.set_size(i);
    result->f3.set_size(i);
    result->f4.set_size(i);
    result->f5.set_size(i);
    result->f6.set_size(i);
    for (int32_T b_i{0}; b_i < i; b_i++) {
      int32_T b_loop_ub;
      int32_T loop_ub;
      loop_ub = reflectivity[b_i].f1.size(0);
      result->f1[b_i].f1.set_size(reflectivity[b_i].f1.size(0), 2);
      b_loop_ub = Simulation[b_i].f1.size(0);
      result->f2[b_i].f1.set_size(Simulation[b_i].f1.size(0), 2);
      for (i1 = 0; i1 < 2; i1++) {
        for (int32_T i2{0}; i2 < loop_ub; i2++) {
          result->f1[b_i].f1[i2 + result->f1[b_i].f1.size(0) * i1] =
            reflectivity[b_i].f1[i2 + reflectivity[b_i].f1.size(0) * i1];
        }

        for (int32_T i2{0}; i2 < b_loop_ub; i2++) {
          result->f2[b_i].f1[i2 + result->f2[b_i].f1.size(0) * i1] =
            Simulation[b_i].f1[i2 + Simulation[b_i].f1.size(0) * i1];
        }
      }

      loop_ub = shifted_data[b_i].f1.size(0);
      result->f3[b_i].f1.set_size(shifted_data[b_i].f1.size(0), 3);
      b_loop_ub = layerSlds[b_i].f1.size(0);
      result->f4[b_i].f1.set_size(layerSlds[b_i].f1.size(0), 3);
      for (i1 = 0; i1 < 3; i1++) {
        for (int32_T i2{0}; i2 < loop_ub; i2++) {
          result->f3[b_i].f1[i2 + result->f3[b_i].f1.size(0) * i1] =
            shifted_data[b_i].f1[i2 + shifted_data[b_i].f1.size(0) * i1];
        }

        for (int32_T i2{0}; i2 < b_loop_ub; i2++) {
          result->f4[b_i].f1[i2 + result->f4[b_i].f1.size(0) * i1] =
            layerSlds[b_i].f1[i2 + layerSlds[b_i].f1.size(0) * i1];
        }
      }

      loop_ub = sldProfiles[b_i].f1.size(0);
      result->f5[b_i].f1.set_size(sldProfiles[b_i].f1.size(0), 2);
      for (i1 = 0; i1 < 2; i1++) {
        for (int32_T i2{0}; i2 < loop_ub; i2++) {
          result->f5[b_i].f1[i2 + result->f5[b_i].f1.size(0) * i1] =
            sldProfiles[b_i].f1[i2 + sldProfiles[b_i].f1.size(0) * i1];
        }
      }

      loop_ub = allLayers[b_i].f1.size(0);
      result->f6[b_i].f1.set_size(allLayers[b_i].f1.size(0), 3);
      for (i1 = 0; i1 < 3; i1++) {
        for (int32_T i2{0}; i2 < loop_ub; i2++) {
          result->f6[b_i].f1[i2 + result->f6[b_i].f1.size(0) * i1] =
            allLayers[b_i].f1[i2 + allLayers[b_i].f1.size(0) * i1];
        }
      }
    }

    //  Pre-processor directives for Matlab Coder
    //  to define the size of the output array
    // Result coder definitions....
    // Reflectivity
    // Simulatin
    // Shifted data
    // Layers slds
    // Sld profiles
    // All layers (resampled)
  }
}

//
// File trailer for reflectivity_calculation.cpp
//
// [EOF]
//
