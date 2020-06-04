/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * applyScalarFunction.c
 *
 * Code generation for function 'applyScalarFunction'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "applyScalarFunction.h"
#include "standardTF_stanlay_single.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_rtwutil.h"
#include <string.h>

/* Function Definitions */
void applyScalarFunction(const emxArray_real_T *x, emxArray_real_T *z1)
{
  int ub_loop;
  int i5;
  int k;
  int b_k;
  double absx;
  double S;
  double s;
  double R;
  int eint;
  ub_loop = x->size[1];
  i5 = z1->size[0] * z1->size[1];
  z1->size[0] = 1;
  z1->size[1] = x->size[1];
  emxEnsureCapacity_real_T(z1, i5);
  ub_loop--;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(b_k,absx,s,S,R,eint)

  for (k = 0; k <= ub_loop; k++) {
    /* ========================== COPYRIGHT NOTICE ============================ */
    /*  The algorithms for calculating ERF(X) and ERFC(X) are derived           */
    /*  from FDLIBM, which has the following notice:                            */
    /*                                                                          */
    /*  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.       */
    /*                                                                          */
    /*  Developed at SunSoft, a Sun Microsystems, Inc. business.                */
    /*  Permission to use, copy, modify, and distribute this                    */
    /*  software is freely granted, provided that this notice                   */
    /*  is preserved.                                                           */
    /* =============================    END    ================================ */
    absx = fabs(x->data[k]);
    if (rtIsNaN(x->data[k])) {
      z1->data[k] = x->data[k];
    } else if (rtIsInf(x->data[k])) {
      if (x->data[k] < 0.0) {
        z1->data[k] = -1.0;
      } else {
        z1->data[k] = 1.0;
      }
    } else if (absx < 0.84375) {
      if (absx < 3.7252902984619141E-9) {
        if (absx < 2.8480945388892178E-306) {
          z1->data[k] = 0.125 * (8.0 * x->data[k] + 1.0270333367641007 * x->
            data[k]);
        } else {
          z1->data[k] = x->data[k] + 0.12837916709551259 * x->data[k];
        }
      } else {
        s = x->data[k] * x->data[k];
        z1->data[k] = x->data[k] + x->data[k] * ((0.12837916709551256 + s *
          (-0.3250421072470015 + s * (-0.02848174957559851 + s *
          (-0.0057702702964894416 + s * -2.3763016656650163E-5)))) / (1.0 + s *
          (0.39791722395915535 + s * (0.0650222499887673 + s *
          (0.0050813062818757656 + s * (0.00013249473800432164 + s *
          -3.9602282787753681E-6))))));
      }
    } else if (absx < 1.25) {
      S = -0.0023621185607526594 + (absx - 1.0) * (0.41485611868374833 + (absx -
        1.0) * (-0.37220787603570132 + (absx - 1.0) * (0.31834661990116175 +
        (absx - 1.0) * (-0.11089469428239668 + (absx - 1.0) *
                        (0.035478304325618236 + (absx - 1.0) *
                         -0.0021663755948687908)))));
      s = 1.0 + (absx - 1.0) * (0.10642088040084423 + (absx - 1.0) *
        (0.540397917702171 + (absx - 1.0) * (0.071828654414196266 + (absx - 1.0)
        * (0.12617121980876164 + (absx - 1.0) * (0.013637083912029051 + (absx -
        1.0) * 0.011984499846799107)))));
      if (x->data[k] >= 0.0) {
        z1->data[k] = 0.84506291151046753 + S / s;
      } else {
        z1->data[k] = -0.84506291151046753 - S / s;
      }
    } else if (absx > 6.0) {
      if (x->data[k] < 0.0) {
        z1->data[k] = -1.0;
      } else {
        z1->data[k] = 1.0;
      }
    } else {
      s = 1.0 / (absx * absx);
      if (absx < 2.8571434020996094) {
        R = -0.0098649440348471482 + s * (-0.69385857270718176 + s *
          (-10.558626225323291 + s * (-62.375332450326006 + s *
          (-162.39666946257347 + s * (-184.60509290671104 + s *
          (-81.2874355063066 + s * -9.8143293441691455))))));
        S = 1.0 + s * (19.651271667439257 + s * (137.65775414351904 + s *
          (434.56587747522923 + s * (645.38727173326788 + s *
          (429.00814002756783 + s * (108.63500554177944 + s *
          (6.5702497703192817 + s * -0.0604244152148581)))))));
      } else {
        R = -0.0098649429247001 + s * (-0.799283237680523 + s *
          (-17.757954917754752 + s * (-160.63638485582192 + s *
          (-637.56644336838963 + s * (-1025.0951316110772 + s *
          -483.5191916086514)))));
        S = 1.0 + s * (30.338060743482458 + s * (325.79251299657392 + s *
          (1536.729586084437 + s * (3199.8582195085955 + s * (2553.0504064331644
          + s * (474.52854120695537 + s * -22.440952446585818))))));
      }

      if (!rtIsNaN(absx)) {
        s = frexp(absx, &eint);
        b_k = eint;
      } else {
        s = absx;
        b_k = 0;
      }

      s = floor(s * 2.097152E+6) / 2.097152E+6 * rt_powd_snf(2.0, b_k);
      s = exp(-s * s - 0.5625) * exp((s - absx) * (s + absx) + R / S) / absx;
      if (x->data[k] < 0.0) {
        z1->data[k] = s - 1.0;
      } else {
        z1->data[k] = 1.0 - s;
      }
    }
  }
}

/* End of code generation (applyScalarFunction.c) */
