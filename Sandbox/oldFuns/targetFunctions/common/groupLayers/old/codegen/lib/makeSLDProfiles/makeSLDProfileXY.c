/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * makeSLDProfileXY.c
 *
 * Code generation for function 'makeSLDProfileXY'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "makeSLDProfiles.h"
#include "makeSLDProfileXY.h"
#include "asymconvstep.h"
#include "makeSLDProfiles_emxutil.h"
#include "erf.h"
#include "rdivide.h"

/* Function Definitions */
void makeSLDProfileXY(double nbair, double nbsub, double ssub, const
                      emxArray_real_T *layers, double numberOfLayers, double
                      nrepeats, emxArray_real_T *out)
{
  double nextLayRough;
  emxArray_real_T *x;
  emxArray_real_T *airBox;
  emxArray_real_T *SLD;
  int i0;
  double layerThicks;
  int mtmp;
  int exitg1;
  int b_mtmp;
  int vstride;
  emxArray_real_T *Lays;
  emxArray_real_T *r0;
  emxArray_real_T *b_x;
  double subBox_data[101];
  int subBox_size[2];
  emxArray_real_T *r1;
  emxArray_real_T *c_x;
  double y;
  emxArray_real_T *d_x;
  emxArray_real_T *r2;
  emxArray_real_T *e_x;
  int i1;
  emxArray_real_T *r3;
  emxArray_int32_T *r4;
  emxArray_real_T *b_y;
  emxArray_real_T *b_SLD;

  /* coder.extrinsic('asymconvstep_mex'); */
  nextLayRough = ssub;
  emxInit_real_T(&x, 2);
  emxInit_real_T(&airBox, 2);
  emxInit_real_T(&SLD, 2);
  if (numberOfLayers > 0.0) {
    i0 = layers->size[0];
    if (i0 == 0) {
      layerThicks = 0.0;
    } else {
      layerThicks = layers->data[0];
      mtmp = 2;
      do {
        exitg1 = 0;
        i0 = layers->size[0];
        if (mtmp <= i0) {
          layerThicks += layers->data[mtmp - 1];
          mtmp++;
        } else {
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    layerThicks = layerThicks * nrepeats + 150.0;
    if (rtIsNaN(layerThicks)) {
      i0 = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)x, i0, (int)sizeof(double));
      x->data[0] = rtNaN;
    } else if (layerThicks < 0.0) {
      i0 = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)x, i0, (int)sizeof(double));
    } else if (rtIsInf(layerThicks) && (0.0 == layerThicks)) {
      i0 = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)x, i0, (int)sizeof(double));
      x->data[0] = rtNaN;
    } else {
      i0 = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = (int)floor(layerThicks) + 1;
      emxEnsureCapacity((emxArray__common *)x, i0, (int)sizeof(double));
      vstride = (int)floor(layerThicks);
      for (i0 = 0; i0 <= vstride; i0++) {
        x->data[x->size[0] * i0] = i0;
      }
    }

    emxInit_real_T(&Lays, 2);
    i0 = Lays->size[0] * Lays->size[1];
    Lays->size[0] = x->size[1];
    Lays->size[1] = (int)(numberOfLayers * nrepeats + 2.0);
    emxEnsureCapacity((emxArray__common *)Lays, i0, (int)sizeof(double));
    vstride = x->size[1] * (int)(numberOfLayers * nrepeats + 2.0);
    for (i0 = 0; i0 < vstride; i0++) {
      Lays->data[i0] = 0.0;
    }

    emxInit_real_T(&b_x, 2);

    /*  Produces a step function convoluted with differnt error functions */
    /*  on each side. */
    /*  Convstep (x,xw,xcen,s1,s2,h) */
    /*        x = vector of x values */
    /*       xw = Width of step function */
    /*     xcen = Centre point of step function */
    /*        s1 = Roughness parameter of left side */
    /*        s2 = Roughness parameter of right side */
    /*        h = Height of step function. */
    /* f = (h/2)*(Faddeeva_erf(a)-Faddeeva_erf(b)); */
    i0 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = x->size[1];
    emxEnsureCapacity((emxArray__common *)b_x, i0, (int)sizeof(double));
    vstride = x->size[0] * x->size[1];
    for (i0 = 0; i0 < vstride; i0++) {
      b_x->data[i0] = x->data[i0] - -50.0;
    }

    emxInit_real_T(&r0, 2);
    emxInit_real_T(&c_x, 2);
    rdivide(b_x, 1.4142135623730951 * layers->data[layers->size[0] << 1], airBox);
    b_erf(airBox, r0);
    i0 = c_x->size[0] * c_x->size[1];
    c_x->size[0] = 1;
    c_x->size[1] = x->size[1];
    emxEnsureCapacity((emxArray__common *)c_x, i0, (int)sizeof(double));
    vstride = x->size[0] * x->size[1];
    emxFree_real_T(&b_x);
    for (i0 = 0; i0 < vstride; i0++) {
      c_x->data[i0] = x->data[i0] - 50.0;
    }

    emxInit_real_T(&r1, 2);
    rdivide(c_x, 1.4142135623730951 * layers->data[layers->size[0] << 1], airBox);
    b_erf(airBox, r1);
    y = nbair / 2.0;
    layerThicks = 50.0;
    b_mtmp = 0;
    emxFree_real_T(&c_x);
    emxInit_real_T1(&d_x, 1);
    emxInit_real_T1(&r2, 1);
    while (b_mtmp <= (int)nrepeats - 1) {
      for (mtmp = 0; mtmp < (int)numberOfLayers; mtmp++) {
        if (1.0 + (double)mtmp < numberOfLayers) {
          nextLayRough = layers->data[((int)((1.0 + (double)mtmp) + 1.0) +
            (layers->size[0] << 1)) - 1];
        } else if ((1.0 + (double)mtmp == numberOfLayers) && (1.0 + (double)
                    b_mtmp < nrepeats)) {
          nextLayRough = layers->data[layers->size[0] << 1];
        } else {
          nextLayRough = layers->data[layers->size[0] << 1];
        }

        layerThicks += layers->data[mtmp] / 2.0;
        i0 = (int)((1.0 + (double)mtmp) + numberOfLayers * ((1.0 + (double)
          b_mtmp) - 1.0)) - 1;
        i1 = d_x->size[0];
        d_x->size[0] = x->size[1];
        emxEnsureCapacity((emxArray__common *)d_x, i1, (int)sizeof(double));
        vstride = x->size[1];
        for (i1 = 0; i1 < vstride; i1++) {
          d_x->data[i1] = x->data[x->size[0] * i1];
        }

        asymconvstep(d_x, layers->data[mtmp], layerThicks, layers->data[mtmp +
                     (layers->size[0] << 1)], nextLayRough, layers->data[mtmp +
                     layers->size[0]], r2);
        vstride = r2->size[0];
        for (i1 = 0; i1 < vstride; i1++) {
          Lays->data[i1 + Lays->size[0] * i0] = r2->data[i1];
        }

        layerThicks += layers->data[mtmp] / 2.0;

        /* plot(x,Lays(:,i)); */
      }

      b_mtmp++;
    }

    emxFree_real_T(&r2);
    emxFree_real_T(&d_x);
    emxInit_real_T1(&e_x, 1);

    /* layers(end,3); */
    i0 = (int)(numberOfLayers * nrepeats + 1.0) - 1;
    i1 = e_x->size[0];
    e_x->size[0] = x->size[1];
    emxEnsureCapacity((emxArray__common *)e_x, i1, (int)sizeof(double));
    vstride = x->size[1];
    for (i1 = 0; i1 < vstride; i1++) {
      e_x->data[i1] = x->data[x->size[0] * i1];
    }

    emxInit_real_T1(&r3, 1);
    asymconvstep(e_x, (x->data[x->size[1] - 1] - layerThicks) * 2.0, x->data
                 [x->size[1] - 1], nextLayRough, ssub, nbsub, r3);
    vstride = r3->size[0];
    emxFree_real_T(&e_x);
    for (i1 = 0; i1 < vstride; i1++) {
      Lays->data[i1 + Lays->size[0] * i0] = r3->data[i1];
    }

    emxFree_real_T(&r3);
    emxInit_int32_T(&r4, 1);

    /* plot(x,Lays(:,(numberOfLayers*nrepeats)+1)) */
    vstride = Lays->size[0];
    i0 = r4->size[0];
    r4->size[0] = vstride;
    emxEnsureCapacity((emxArray__common *)r4, i0, (int)sizeof(int));
    for (i0 = 0; i0 < vstride; i0++) {
      r4->data[i0] = i0;
    }

    emxInit_real_T(&b_y, 2);
    i0 = (int)(numberOfLayers * nrepeats + 2.0) - 1;
    i1 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = r0->size[1];
    emxEnsureCapacity((emxArray__common *)b_y, i1, (int)sizeof(double));
    vstride = r0->size[1];
    for (i1 = 0; i1 < vstride; i1++) {
      b_y->data[b_y->size[0] * i1] = y * (r0->data[r0->size[0] * i1] - r1->
        data[r1->size[0] * i1]);
    }

    emxFree_real_T(&r1);
    emxFree_real_T(&r0);
    vstride = r4->size[0];
    for (i1 = 0; i1 < vstride; i1++) {
      Lays->data[r4->data[i1] + Lays->size[0] * i0] = b_y->data[i1];
    }

    emxFree_real_T(&b_y);
    emxFree_int32_T(&r4);
    emxInit_real_T1(&b_SLD, 1);

    /* plot(x,Lays(:,(numberOfLayers*nrepeats)+2)) */
    i0 = b_SLD->size[0];
    b_SLD->size[0] = Lays->size[0];
    emxEnsureCapacity((emxArray__common *)b_SLD, i0, (int)sizeof(double));
    if ((Lays->size[0] == 0) || (Lays->size[1] == 0)) {
      vstride = b_SLD->size[0];
      i0 = b_SLD->size[0];
      b_SLD->size[0] = vstride;
      emxEnsureCapacity((emxArray__common *)b_SLD, i0, (int)sizeof(double));
      for (i0 = 0; i0 < vstride; i0++) {
        b_SLD->data[i0] = 0.0;
      }
    } else {
      vstride = Lays->size[0];
      for (b_mtmp = 0; b_mtmp + 1 <= vstride; b_mtmp++) {
        layerThicks = Lays->data[b_mtmp];
        for (mtmp = 2; mtmp <= Lays->size[1]; mtmp++) {
          layerThicks += Lays->data[b_mtmp + (mtmp - 1) * vstride];
        }

        b_SLD->data[b_mtmp] = layerThicks;
      }
    }

    emxFree_real_T(&Lays);
    i0 = SLD->size[0] * SLD->size[1];
    SLD->size[0] = b_SLD->size[0];
    SLD->size[1] = 1;
    emxEnsureCapacity((emxArray__common *)SLD, i0, (int)sizeof(double));
    vstride = b_SLD->size[0];
    for (i0 = 0; i0 < vstride; i0++) {
      SLD->data[i0] = b_SLD->data[i0];
    }

    emxFree_real_T(&b_SLD);
  } else {
    i0 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = 101;
    emxEnsureCapacity((emxArray__common *)x, i0, (int)sizeof(double));
    for (i0 = 0; i0 < 101; i0++) {
      x->data[i0] = i0;
    }

    b_mtmp = 0;
    for (vstride = 1; vstride + 1 < 102; vstride++) {
      if ((signed char)vstride > b_mtmp) {
        b_mtmp = (signed char)vstride;
      }
    }

    mtmp = 0;
    for (vstride = 1; vstride + 1 < 102; vstride++) {
      if ((signed char)vstride > mtmp) {
        mtmp = (signed char)vstride;
      }
    }

    emxInit_real_T(&r0, 2);
    i0 = r0->size[0] * r0->size[1];
    r0->size[0] = 1;
    r0->size[1] = 101;
    emxEnsureCapacity((emxArray__common *)r0, i0, (int)sizeof(double));
    for (i0 = 0; i0 < 101; i0++) {
      r0->data[i0] = i0;
    }

    b_asymconvstep(r0->data, mtmp, 0.0, ssub, ssub, nbair, subBox_data,
                   subBox_size);
    i0 = airBox->size[0] * airBox->size[1];
    airBox->size[0] = 1;
    airBox->size[1] = 101;
    emxEnsureCapacity((emxArray__common *)airBox, i0, (int)sizeof(double));
    emxFree_real_T(&r0);
    for (i0 = 0; i0 < 101; i0++) {
      airBox->data[i0] = subBox_data[i0];
    }

    emxInit_real_T(&r1, 2);
    i0 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = 101;
    emxEnsureCapacity((emxArray__common *)r1, i0, (int)sizeof(double));
    for (i0 = 0; i0 < 101; i0++) {
      r1->data[i0] = i0;
    }

    b_asymconvstep(r1->data, mtmp, b_mtmp, ssub, ssub, nbsub, subBox_data,
                   subBox_size);
    i0 = SLD->size[0] * SLD->size[1];
    SLD->size[0] = 1;
    SLD->size[1] = airBox->size[1];
    emxEnsureCapacity((emxArray__common *)SLD, i0, (int)sizeof(double));
    vstride = airBox->size[0] * airBox->size[1];
    emxFree_real_T(&r1);
    for (i0 = 0; i0 < vstride; i0++) {
      SLD->data[i0] = airBox->data[i0] + subBox_data[i0];
    }
  }

  emxFree_real_T(&airBox);

  /* plot(x,SLD) */
  vstride = x->size[1];
  b_mtmp = SLD->size[0] * SLD->size[1];
  i0 = out->size[0] * out->size[1];
  out->size[0] = vstride;
  out->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)out, i0, (int)sizeof(double));
  for (i0 = 0; i0 < vstride; i0++) {
    out->data[i0] = x->data[i0];
  }

  emxFree_real_T(&x);
  for (i0 = 0; i0 < b_mtmp; i0++) {
    out->data[i0 + out->size[0]] = SLD->data[i0];
  }

  emxFree_real_T(&SLD);
}

/* End of code generation (makeSLDProfileXY.c) */
