//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// makeEmptyResultStruct.cpp
//
// Code generation for function 'makeEmptyResultStruct'
//

// Include files
#include "makeEmptyResultStruct.h"
#include "RATMain_internal_types.h"
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "rt_nonfinite.h"
#include "structConstructorHelper.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Type Definitions
namespace RAT
{
  struct cell_wrap_29
  {
    ::coder::array<double, 2U> f1;
  };

  struct cell_wrap_37
  {
    ::coder::array<cell_wrap_29, 1U> f1;
  };

  struct cell_wrap_30
  {
    ::coder::array<double, 2U> f1;
  };

  struct cell_wrap_38
  {
    ::coder::array<cell_wrap_30, 1U> f1;
  };

  struct cell_wrap_31
  {
    ::coder::array<double, 2U> f1;
  };

  struct cell_wrap_39
  {
    ::coder::array<cell_wrap_31, 2U> f1;
  };

  struct cell_wrap_32
  {
    ::coder::array<double, 2U> f1;
  };

  struct cell_wrap_40
  {
    ::coder::array<cell_wrap_32, 2U> f1;
  };
}

// Function Declarations
namespace RAT
{
  static void cast(const cell_wrap_38 &r, cell_wrap_34 &r1);
  static void cast(const cell_wrap_37 &r, cell_wrap_33 &r1);
  static void cast(const cell_wrap_39 &r, cell_wrap_35 &r1);
  static void cast(const cell_wrap_40 &r, cell_wrap_35 &r1);
}

// Function Definitions
namespace RAT
{
  static void cast(const cell_wrap_38 &r, cell_wrap_34 &r1)
  {
    int i;
    i = r.f1.size(0);
    r1.f1.set_size(r.f1.size(0));
    for (int i1{0}; i1 < i; i1++) {
      int loop_ub;
      loop_ub = r.f1[i1].f1.size(0);
      r1.f1[i1].f1.set_size(r.f1[i1].f1.size(0), 3);
      for (int i2{0}; i2 < 3; i2++) {
        for (int i3{0}; i3 < loop_ub; i3++) {
          r1.f1[i1].f1[i3 + r1.f1[i1].f1.size(0) * i2] = r.f1[i1].f1[i3 +
            r.f1[i1].f1.size(0) * i2];
        }
      }
    }
  }

  static void cast(const cell_wrap_37 &r, cell_wrap_33 &r1)
  {
    int i;
    i = r.f1.size(0);
    r1.f1.set_size(r.f1.size(0));
    for (int i1{0}; i1 < i; i1++) {
      int loop_ub;
      loop_ub = r.f1[i1].f1.size(0);
      r1.f1[i1].f1.set_size(r.f1[i1].f1.size(0), 2);
      for (int i2{0}; i2 < 2; i2++) {
        for (int i3{0}; i3 < loop_ub; i3++) {
          r1.f1[i1].f1[i3 + r1.f1[i1].f1.size(0) * i2] = r.f1[i1].f1[i3 +
            r.f1[i1].f1.size(0) * i2];
        }
      }
    }
  }

  static void cast(const cell_wrap_39 &r, cell_wrap_35 &r1)
  {
    int i;
    i = r.f1.size(0) * r.f1.size(1);
    r1.f1.set_size(r.f1.size(0), r.f1.size(1));
    for (int i1{0}; i1 < i; i1++) {
      int loop_ub;
      loop_ub = r.f1[i1].f1.size(1);
      r1.f1[i1].f1.set_size(r.f1[i1].f1.size(0), r.f1[i1].f1.size(1));
      for (int i2{0}; i2 < loop_ub; i2++) {
        int b_loop_ub;
        b_loop_ub = r.f1[i1].f1.size(0);
        for (int i3{0}; i3 < b_loop_ub; i3++) {
          r1.f1[i1].f1[i3 + r1.f1[i1].f1.size(0) * i2] = r.f1[i1].f1[i3 +
            r.f1[i1].f1.size(0) * i2];
        }
      }
    }
  }

  static void cast(const cell_wrap_40 &r, cell_wrap_35 &r1)
  {
    int i;
    i = r.f1.size(0) * r.f1.size(1);
    r1.f1.set_size(r.f1.size(0), r.f1.size(1));
    for (int i1{0}; i1 < i; i1++) {
      int loop_ub;
      loop_ub = r.f1[i1].f1.size(1);
      r1.f1[i1].f1.set_size(r.f1[i1].f1.size(0), r.f1[i1].f1.size(1));
      for (int i2{0}; i2 < loop_ub; i2++) {
        int b_loop_ub;
        b_loop_ub = r.f1[i1].f1.size(0);
        for (int i3{0}; i3 < b_loop_ub; i3++) {
          r1.f1[i1].f1[i3 + r1.f1[i1].f1.size(0) * i2] = r.f1[i1].f1[i3 +
            r.f1[i1].f1.size(0) * i2];
        }
      }
    }
  }

  void makeEmptyResultStruct(double nContrasts, double nParams, boolean_T
    domains, ::coder::array<cell_wrap_7, 1U> &result_reflectivity, ::coder::
    array<cell_wrap_7, 1U> &result_simulation, ::coder::array<cell_wrap_8, 1U>
    &result_shiftedData, ::coder::array<cell_wrap_8, 1U> &result_backgrounds, ::
    coder::array<cell_wrap_7, 1U> &result_resolutions, ::coder::array<
    cell_wrap_9, 2U> &result_sldProfiles, ::coder::array<cell_wrap_9, 2U>
    &result_layers, ::coder::array<cell_wrap_9, 2U> &result_resampledLayers, ::
    coder::array<double, 2U> &result_fitParams, ::coder::array<cell_wrap_10, 1U>
    &result_fitNames, CalculationResults &result_calculationResults,
    ContrastParams &result_contrastParams)
  {
    ::coder::array<cell_wrap_0, 1U> fitNames;
    ::coder::array<cell_wrap_29, 1U> b_f1;
    ::coder::array<cell_wrap_29, 1U> e_f1;
    ::coder::array<cell_wrap_29, 1U> f1;
    ::coder::array<cell_wrap_30, 1U> c_f1;
    ::coder::array<cell_wrap_30, 1U> d_f1;
    ::coder::array<cell_wrap_31, 2U> f_f1;
    ::coder::array<cell_wrap_32, 2U> g_f1;
    ::coder::array<cell_wrap_32, 2U> h_f1;
    ::coder::array<double, 2U> r9;
    ::coder::array<signed char, 1U> calculationResults_chiValues;
    ::coder::array<signed char, 1U> contrastParams_subRoughs;
    CalculationResults expl_temp;
    ContrastParams b_expl_temp;
    Results c_expl_temp;
    cell_wrap_33 r11;
    cell_wrap_33 r2;
    cell_wrap_33 r3;
    cell_wrap_34 r10;
    cell_wrap_34 r5;
    cell_wrap_35 r12;
    cell_wrap_35 r13;
    cell_wrap_35 r8;
    cell_wrap_36 r;
    cell_wrap_37 r1;
    cell_wrap_38 r4;
    cell_wrap_39 r6;
    cell_wrap_40 r7;
    int b_loop_ub_tmp;
    int loop_ub;
    int loop_ub_tmp;

    //  A function to make an empty container to hold the results of
    //  reflectivity calculations. The struct has the following format:
    //
    //  nParams = number of fitted parameters
    //  nContrasts = number of contrasts
    //  nDomains = number of domains - 1 for normal, 2 for domains
    //
    //  result =
    //
    //    struct with fields:
    //
    //        reflectivity: [nContrastsx1 cell]
    //          simulation: [nContrastsx1 cell]
    //         shiftedData: [nContrastsx1 cell]
    //         backgrounds: [nContrastsx1 cell]
    //         resolutions: [nContrastsx1 cell]
    //         sldProfiles: [nContrastsxnDomains cell]
    //              layers: [nContrastsxnDomains cell]
    //     resampledLayers: [nContrastsxnDomains cell]
    //  calculationResults: [1x1 struct]
    //      contrastParams: [1x1 struct]
    //           fitParams: [1xnParams double]
    //            fitNames: [nParamsx1 cell]
    //  -----------------------------------------------------------
    //  Make the individual structs:
    //
    //  (1) result.calculationResults
    loop_ub_tmp = static_cast<int>(nContrasts);
    calculationResults_chiValues.set_size(loop_ub_tmp);

    //  --------------------------------------------------------------------
    //  (2) result.contrastParams
    contrastParams_subRoughs.set_size(loop_ub_tmp);
    for (int i{0}; i < loop_ub_tmp; i++) {
      calculationResults_chiValues[i] = 0;
      contrastParams_subRoughs[i] = 0;
    }

    //  -------------------------------------------------------------------
    //  Make the final structure...
    f1.set_size(loop_ub_tmp);
    for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
      f1[b_i].f1.set_size(2, 2);
      f1[b_i].f1[0] = 1.0;
      f1[b_i].f1[1] = 1.0;
      f1[b_i].f1[f1[b_i].f1.size(0)] = 1.0;
      f1[b_i].f1[f1[b_i].f1.size(0) + 1] = 1.0;
    }

    b_f1.set_size(loop_ub_tmp);
    for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
      b_f1[b_i].f1.set_size(2, 2);
      b_f1[b_i].f1[0] = 1.0;
      b_f1[b_i].f1[1] = 1.0;
      b_f1[b_i].f1[b_f1[b_i].f1.size(0)] = 1.0;
      b_f1[b_i].f1[b_f1[b_i].f1.size(0) + 1] = 1.0;
    }

    c_f1.set_size(loop_ub_tmp);
    for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
      c_f1[b_i].f1.set_size(2, 3);
      for (int i{0}; i < 3; i++) {
        c_f1[b_i].f1[c_f1[b_i].f1.size(0) * i] = 1.0;
        c_f1[b_i].f1[c_f1[b_i].f1.size(0) * i + 1] = 1.0;
      }
    }

    d_f1.set_size(loop_ub_tmp);
    for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
      d_f1[b_i].f1.set_size(2, 3);
      for (int i{0}; i < 3; i++) {
        d_f1[b_i].f1[d_f1[b_i].f1.size(0) * i] = 1.0;
        d_f1[b_i].f1[d_f1[b_i].f1.size(0) * i + 1] = 1.0;
      }
    }

    e_f1.set_size(loop_ub_tmp);
    for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
      e_f1[b_i].f1.set_size(2, 2);
      e_f1[b_i].f1[0] = 1.0;
      e_f1[b_i].f1[1] = 1.0;
      e_f1[b_i].f1[e_f1[b_i].f1.size(0)] = 1.0;
      e_f1[b_i].f1[e_f1[b_i].f1.size(0) + 1] = 1.0;
    }

    if (domains) {
      f_f1.set_size(loop_ub_tmp, 2);
      for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
        f_f1[b_i].f1.set_size(2, 2);
        f_f1[b_i + f_f1.size(0)].f1.set_size(2, 2);
        f_f1[b_i].f1[0] = 1.0;
        f_f1[b_i + f_f1.size(0)].f1[0] = 1.0;
        f_f1[b_i].f1[1] = 1.0;
        f_f1[b_i + f_f1.size(0)].f1[1] = 1.0;
        f_f1[b_i].f1[f_f1[b_i].f1.size(0)] = 1.0;
        f_f1[b_i + f_f1.size(0)].f1[f_f1[b_i + f_f1.size(0)].f1.size(0)] = 1.0;
        f_f1[b_i].f1[f_f1[b_i].f1.size(0) + 1] = 1.0;
        f_f1[b_i + f_f1.size(0)].f1[f_f1[b_i + f_f1.size(0)].f1.size(0) + 1] =
          1.0;
      }

      g_f1.set_size(loop_ub_tmp, 2);
      for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
        g_f1[b_i].f1.set_size(2, 3);
        g_f1[b_i + g_f1.size(0)].f1.set_size(2, 3);
        for (int i{0}; i < 3; i++) {
          g_f1[b_i].f1[g_f1[b_i].f1.size(0) * i] = 1.0;
          g_f1[b_i + g_f1.size(0)].f1[g_f1[b_i + g_f1.size(0)].f1.size(0) * i] =
            1.0;
          g_f1[b_i].f1[g_f1[b_i].f1.size(0) * i + 1] = 1.0;
          g_f1[b_i + g_f1.size(0)].f1[g_f1[b_i + g_f1.size(0)].f1.size(0) * i +
            1] = 1.0;
        }
      }

      h_f1.set_size(loop_ub_tmp, 2);
      for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
        h_f1[b_i].f1.set_size(2, 3);
        h_f1[b_i + h_f1.size(0)].f1.set_size(2, 3);
        for (int i{0}; i < 3; i++) {
          h_f1[b_i].f1[h_f1[b_i].f1.size(0) * i] = 1.0;
          h_f1[b_i + h_f1.size(0)].f1[h_f1[b_i + h_f1.size(0)].f1.size(0) * i] =
            1.0;
          h_f1[b_i].f1[h_f1[b_i].f1.size(0) * i + 1] = 1.0;
          h_f1[b_i + h_f1.size(0)].f1[h_f1[b_i + h_f1.size(0)].f1.size(0) * i +
            1] = 1.0;
        }
      }
    } else {
      f_f1.set_size(loop_ub_tmp, 1);
      for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
        f_f1[b_i].f1.set_size(2, 2);
        f_f1[b_i].f1[0] = 1.0;
        f_f1[b_i].f1[1] = 1.0;
        f_f1[b_i].f1[f_f1[b_i].f1.size(0)] = 1.0;
        f_f1[b_i].f1[f_f1[b_i].f1.size(0) + 1] = 1.0;
      }

      g_f1.set_size(loop_ub_tmp, 1);
      for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
        g_f1[b_i].f1.set_size(2, 3);
        for (int i{0}; i < 3; i++) {
          g_f1[b_i].f1[g_f1[b_i].f1.size(0) * i] = 1.0;
          g_f1[b_i].f1[g_f1[b_i].f1.size(0) * i + 1] = 1.0;
        }
      }

      h_f1.set_size(loop_ub_tmp, 1);
      for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
        h_f1[b_i].f1.set_size(2, 3);
        for (int i{0}; i < 3; i++) {
          h_f1[b_i].f1[h_f1[b_i].f1.size(0) * i] = 1.0;
          h_f1[b_i].f1[h_f1[b_i].f1.size(0) * i + 1] = 1.0;
        }
      }
    }

    b_loop_ub_tmp = static_cast<int>(nParams);
    fitNames.set_size(b_loop_ub_tmp);
    for (int b_i{0}; b_i < b_loop_ub_tmp; b_i++) {
      fitNames[b_i].f1.size[0] = 1;
      fitNames[b_i].f1.size[1] = 0;
    }

    cast(fitNames, r.f1);
    r1.f1 = f1;
    cast(r1, r2);
    r1.f1 = b_f1;
    cast(r1, r3);
    r4.f1 = c_f1;
    cast(r4, r5);
    r4.f1 = d_f1;
    r1.f1 = e_f1;
    r6.f1 = f_f1;
    r7.f1 = g_f1;
    cast(r7, r8);
    r7.f1 = h_f1;
    expl_temp.sumChi = 0.0;
    expl_temp.chiValues.set_size(calculationResults_chiValues.size(0));
    loop_ub = calculationResults_chiValues.size(0);
    for (int i{0}; i < loop_ub; i++) {
      expl_temp.chiValues[i] = 0.0;
    }

    b_expl_temp.resample.set_size(1, loop_ub_tmp);
    for (int i{0}; i < loop_ub_tmp; i++) {
      b_expl_temp.resample[i] = 0.0;
    }

    b_expl_temp.subRoughs.set_size(contrastParams_subRoughs.size(0));
    loop_ub = contrastParams_subRoughs.size(0);
    for (int i{0}; i < loop_ub; i++) {
      b_expl_temp.subRoughs[i] = 0.0;
    }

    b_expl_temp.bulkOut.set_size(loop_ub_tmp);
    for (int i{0}; i < loop_ub_tmp; i++) {
      b_expl_temp.bulkOut[i] = 0.0;
    }

    b_expl_temp.bulkIn.set_size(loop_ub_tmp);
    for (int i{0}; i < loop_ub_tmp; i++) {
      b_expl_temp.bulkIn[i] = 0.0;
    }

    b_expl_temp.scalefactors.set_size(loop_ub_tmp);
    for (int i{0}; i < loop_ub_tmp; i++) {
      b_expl_temp.scalefactors[i] = 0.0;
    }

    r9.set_size(1, b_loop_ub_tmp);
    for (int i{0}; i < b_loop_ub_tmp; i++) {
      r9[i] = 0.0;
    }

    cast(r4, r10);
    cast(r1, r11);
    cast(r6, r12);
    cast(r7, r13);
    coder::internal::structConstructorHelper(r2, r3, r5, r10, r11, r12, r8, r13,
      expl_temp, b_expl_temp, r9, r, c_expl_temp);
    result_reflectivity.set_size(c_expl_temp.reflectivity.size(0));
    loop_ub = c_expl_temp.reflectivity.size(0);
    for (int i{0}; i < loop_ub; i++) {
      result_reflectivity[i] = c_expl_temp.reflectivity[i];
    }

    result_simulation.set_size(c_expl_temp.simulation.size(0));
    loop_ub = c_expl_temp.simulation.size(0);
    for (int i{0}; i < loop_ub; i++) {
      result_simulation[i] = c_expl_temp.simulation[i];
    }

    result_shiftedData.set_size(c_expl_temp.shiftedData.size(0));
    loop_ub = c_expl_temp.shiftedData.size(0);
    for (int i{0}; i < loop_ub; i++) {
      result_shiftedData[i] = c_expl_temp.shiftedData[i];
    }

    result_backgrounds.set_size(c_expl_temp.backgrounds.size(0));
    loop_ub = c_expl_temp.backgrounds.size(0);
    for (int i{0}; i < loop_ub; i++) {
      result_backgrounds[i] = c_expl_temp.backgrounds[i];
    }

    result_resolutions.set_size(c_expl_temp.resolutions.size(0));
    loop_ub = c_expl_temp.resolutions.size(0);
    for (int i{0}; i < loop_ub; i++) {
      result_resolutions[i] = c_expl_temp.resolutions[i];
    }

    result_sldProfiles.set_size(c_expl_temp.sldProfiles.size(0),
      c_expl_temp.sldProfiles.size(1));
    loop_ub = c_expl_temp.sldProfiles.size(1);
    for (int i{0}; i < loop_ub; i++) {
      loop_ub_tmp = c_expl_temp.sldProfiles.size(0);
      for (b_loop_ub_tmp = 0; b_loop_ub_tmp < loop_ub_tmp; b_loop_ub_tmp++) {
        result_sldProfiles[b_loop_ub_tmp + result_sldProfiles.size(0) * i] =
          c_expl_temp.sldProfiles[b_loop_ub_tmp + c_expl_temp.sldProfiles.size(0)
          * i];
      }
    }

    result_layers.set_size(c_expl_temp.layers.size(0), c_expl_temp.layers.size(1));
    loop_ub = c_expl_temp.layers.size(1);
    for (int i{0}; i < loop_ub; i++) {
      loop_ub_tmp = c_expl_temp.layers.size(0);
      for (b_loop_ub_tmp = 0; b_loop_ub_tmp < loop_ub_tmp; b_loop_ub_tmp++) {
        result_layers[b_loop_ub_tmp + result_layers.size(0) * i] =
          c_expl_temp.layers[b_loop_ub_tmp + c_expl_temp.layers.size(0) * i];
      }
    }

    result_resampledLayers.set_size(c_expl_temp.resampledLayers.size(0),
      c_expl_temp.resampledLayers.size(1));
    loop_ub = c_expl_temp.resampledLayers.size(1);
    for (int i{0}; i < loop_ub; i++) {
      loop_ub_tmp = c_expl_temp.resampledLayers.size(0);
      for (b_loop_ub_tmp = 0; b_loop_ub_tmp < loop_ub_tmp; b_loop_ub_tmp++) {
        result_resampledLayers[b_loop_ub_tmp + result_resampledLayers.size(0) *
          i] = c_expl_temp.resampledLayers[b_loop_ub_tmp +
          c_expl_temp.resampledLayers.size(0) * i];
      }
    }

    result_calculationResults = c_expl_temp.calculationResults;
    result_contrastParams = c_expl_temp.contrastParams;
    result_fitParams.set_size(1, c_expl_temp.fitParams.size(1));
    loop_ub = c_expl_temp.fitParams.size(1);
    for (int i{0}; i < loop_ub; i++) {
      result_fitParams[i] = c_expl_temp.fitParams[i];
    }

    result_fitNames.set_size(c_expl_temp.fitNames.size(0));
    loop_ub = c_expl_temp.fitNames.size(0);
    for (int i{0}; i < loop_ub; i++) {
      result_fitNames[i] = c_expl_temp.fitNames[i];
    }
  }
}

// End of code generation (makeEmptyResultStruct.cpp)
