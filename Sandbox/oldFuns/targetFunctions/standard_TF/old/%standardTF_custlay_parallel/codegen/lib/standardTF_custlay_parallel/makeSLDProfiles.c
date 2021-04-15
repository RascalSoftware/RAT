/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * makeSLDProfiles.c
 *
 * Code generation for function 'makeSLDProfiles'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_custlay_parallel.h"
#include "makeSLDProfiles.h"
#include "makeSLDProfileXY.h"

/* Function Definitions */
void makeSLDProfiles(double nbair, double nbsub, const emxArray_real_T *sld,
                     double ssub, const double repeats[2], emxArray_real_T
                     *sldProfile)
{
  double b_repeats;
  if (repeats[0] == 0.0) {
    b_repeats = 1.0;
  } else {
    b_repeats = repeats[1];
  }

  makeSLDProfileXY(nbair, nbsub, ssub, sld, sld->size[0], b_repeats, sldProfile);
}

/* End of code generation (makeSLDProfiles.c) */
