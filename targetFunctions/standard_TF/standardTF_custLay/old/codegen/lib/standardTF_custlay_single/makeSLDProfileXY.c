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
#include "standardTF_custlay_single.h"
#include "makeSLDProfileXY.h"
#include "standardTF_custlay_single_emxutil.h"
#include "asymconvstep.h"
#include "erf.h"
#include "sum.h"

/* Function Definitions */
void makeSLDProfileXY(double nbair, double nbsub, double ssub, const
                      emxArray_real_T *layers, double numberOfLayers, double
                      nrepeats, emxArray_real_T *out)
{
  emxArray_real_T *x;
  emxArray_real_T *airBox;
  emxArray_real_T *SLD;
  int i3;
  emxArray_real_T *b_layers;
  int vstride;
  int mtmp;
  double layerThicks;
  int b_mtmp;
  emxArray_real_T *r0;
  emxArray_real_T *Lays;
  double subBox_data[101];
  int subBox_size[2];
  emxArray_real_T *b_x;
  double nextLayRough;
  emxArray_real_T *r1;
  double bFactor;
  emxArray_real_T *c_x;
  emxArray_int32_T *r2;
  int i;
  emxArray_real_T *y;
  emxArray_real_T *b_SLD;
  emxInit_real_T(&x, 2);
  emxInit_real_T(&airBox, 2);
  emxInit_real_T(&SLD, 2);
  if (numberOfLayers > 0.0) {
    emxInit_real_T1(&b_layers, 1);
    vstride = layers->size[0];
    i3 = b_layers->size[0];
    b_layers->size[0] = vstride;
    emxEnsureCapacity((emxArray__common *)b_layers, i3, (int)sizeof(double));
    for (i3 = 0; i3 < vstride; i3++) {
      b_layers->data[i3] = layers->data[i3];
    }

    layerThicks = sum(b_layers);
    layerThicks = layerThicks * nrepeats + 150.0;
    emxFree_real_T(&b_layers);
    if (rtIsNaN(layerThicks)) {
      i3 = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)x, i3, (int)sizeof(double));
      x->data[0] = rtNaN;
    } else if (layerThicks < 0.0) {
      i3 = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)x, i3, (int)sizeof(double));
    } else if (rtIsInf(layerThicks) && (0.0 == layerThicks)) {
      i3 = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)x, i3, (int)sizeof(double));
      x->data[0] = rtNaN;
    } else {
      i3 = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = (int)floor(layerThicks) + 1;
      emxEnsureCapacity((emxArray__common *)x, i3, (int)sizeof(double));
      vstride = (int)floor(layerThicks);
      for (i3 = 0; i3 <= vstride; i3++) {
        x->data[x->size[0] * i3] = i3;
      }
    }

    emxInit_real_T(&Lays, 2);
    i3 = Lays->size[0] * Lays->size[1];
    Lays->size[0] = x->size[1];
    Lays->size[1] = (int)(numberOfLayers * nrepeats + 2.0);
    emxEnsureCapacity((emxArray__common *)Lays, i3, (int)sizeof(double));
    vstride = x->size[1] * (int)(numberOfLayers * nrepeats + 2.0);
    for (i3 = 0; i3 < vstride; i3++) {
      Lays->data[i3] = 0.0;
    }

    emxInit_real_T(&b_x, 2);
    nextLayRough = layers->data[layers->size[0] << 1];

    /*  Produces a step function convoluted with differnt error functions */
    /*  on each side. */
    /*  Convstep (x,xw,xcen,s1,s2,h) */
    /*        x = vector of x values */
    /*       xw = Width of step function */
    /*     xcen = Centre point of step function */
    /*        s1 = Roughness parameter of left side */
    /*        s2 = Roughness parameter of right side */
    /*        h = Height of step function. */
    /*  if length(xw) > 1 */
    /*      ME = MException('VerifyOutput:OutOfBounds', ... */
    /*               'xw must be single value'); */
    /*      throw(ME); */
    /*  end */
    /*   */
    /*  if length(xcen) > 1 */
    /*      ME = MException('VerifyOutput:OutOfBounds', ... */
    /*               'xcen must be single value'); */
    /*      throw(ME); */
    /*  end */
    /*   */
    /*  if length(s1) > 1 */
    /*      ME = MException('VerifyOutput:OutOfBounds', ... */
    /*               's1 must be single value'); */
    /*      throw(ME); */
    /*  end */
    /*   */
    /*  if length(s2) > 1 */
    /*      ME = MException('VerifyOutput:OutOfBounds', ... */
    /*               's2 must be single value'); */
    /*      throw(ME); */
    /*  end */
    layerThicks = 1.4142135623730951 * layers->data[layers->size[0] << 1];
    bFactor = 1.4142135623730951 * layers->data[layers->size[0] << 1];
    i3 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = x->size[1];
    emxEnsureCapacity((emxArray__common *)b_x, i3, (int)sizeof(double));
    vstride = x->size[0] * x->size[1];
    for (i3 = 0; i3 < vstride; i3++) {
      b_x->data[i3] = (x->data[i3] - -50.0) / layerThicks;
    }

    emxInit_real_T(&r0, 2);
    emxInit_real_T(&c_x, 2);
    b_erf(b_x, r0);
    i3 = c_x->size[0] * c_x->size[1];
    c_x->size[0] = 1;
    c_x->size[1] = x->size[1];
    emxEnsureCapacity((emxArray__common *)c_x, i3, (int)sizeof(double));
    vstride = x->size[0] * x->size[1];
    emxFree_real_T(&b_x);
    for (i3 = 0; i3 < vstride; i3++) {
      c_x->data[i3] = (x->data[i3] - 50.0) / bFactor;
    }

    emxInit_real_T(&r1, 2);
    b_erf(c_x, r1);
    bFactor = nbair / 2.0;
    layerThicks = 50.0;
    mtmp = 0;
    emxFree_real_T(&c_x);
    emxInit_int32_T(&r2, 1);
    while (mtmp <= (int)nrepeats - 1) {
      for (i = 0; i < (int)numberOfLayers; i++) {
        if (1.0 + (double)i < numberOfLayers) {
          nextLayRough = layers->data[((int)((1.0 + (double)i) + 1.0) +
            (layers->size[0] << 1)) - 1];

          /*              elseif (i == numberOfLayers) && (n < nrepeats) */
          /*                  nextLayRough = layers(1,3); */
        } else {
          nextLayRough = ssub;
        }

        layerThicks += layers->data[i] / 2.0;
        asymconvstep(x, layers->data[i], layerThicks, layers->data[i +
                     (layers->size[0] << 1)], nextLayRough, layers->data[i +
                     layers->size[0]], airBox);
        vstride = Lays->size[0];
        i3 = r2->size[0];
        r2->size[0] = vstride;
        emxEnsureCapacity((emxArray__common *)r2, i3, (int)sizeof(int));
        for (i3 = 0; i3 < vstride; i3++) {
          r2->data[i3] = i3;
        }

        i3 = (int)((1.0 + (double)i) + numberOfLayers * ((1.0 + (double)mtmp) -
                    1.0)) - 1;
        vstride = r2->size[0];
        for (b_mtmp = 0; b_mtmp < vstride; b_mtmp++) {
          Lays->data[r2->data[b_mtmp] + Lays->size[0] * i3] = airBox->
            data[b_mtmp];
        }

        layerThicks += layers->data[i] / 2.0;

        /* plot(x,Lays(:,i)); */
      }

      mtmp++;
    }

    /* layers(end,3); */
    vstride = Lays->size[0];
    i3 = r2->size[0];
    r2->size[0] = vstride;
    emxEnsureCapacity((emxArray__common *)r2, i3, (int)sizeof(int));
    for (i3 = 0; i3 < vstride; i3++) {
      r2->data[i3] = i3;
    }

    i3 = (int)(numberOfLayers * nrepeats + 1.0) - 1;
    asymconvstep(x, (x->data[x->size[1] - 1] - layerThicks) * 2.0, x->data
                 [x->size[1] - 1], nextLayRough, ssub, nbsub, airBox);
    vstride = r2->size[0];
    for (b_mtmp = 0; b_mtmp < vstride; b_mtmp++) {
      Lays->data[r2->data[b_mtmp] + Lays->size[0] * i3] = airBox->data[b_mtmp];
    }

    /* plot(x,Lays(:,(numberOfLayers*nrepeats)+1)) */
    vstride = Lays->size[0];
    i3 = r2->size[0];
    r2->size[0] = vstride;
    emxEnsureCapacity((emxArray__common *)r2, i3, (int)sizeof(int));
    for (i3 = 0; i3 < vstride; i3++) {
      r2->data[i3] = i3;
    }

    emxInit_real_T(&y, 2);
    i3 = (int)(numberOfLayers * nrepeats + 2.0) - 1;
    b_mtmp = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = r0->size[1];
    emxEnsureCapacity((emxArray__common *)y, b_mtmp, (int)sizeof(double));
    vstride = r0->size[1];
    for (b_mtmp = 0; b_mtmp < vstride; b_mtmp++) {
      y->data[y->size[0] * b_mtmp] = bFactor * (r0->data[r0->size[0] * b_mtmp] -
        r1->data[r1->size[0] * b_mtmp]);
    }

    emxFree_real_T(&r1);
    emxFree_real_T(&r0);
    vstride = r2->size[0];
    for (b_mtmp = 0; b_mtmp < vstride; b_mtmp++) {
      Lays->data[r2->data[b_mtmp] + Lays->size[0] * i3] = y->data[b_mtmp];
    }

    emxFree_real_T(&y);
    emxFree_int32_T(&r2);
    emxInit_real_T1(&b_SLD, 1);

    /* plot(x,Lays(:,(numberOfLayers*nrepeats)+2)) */
    i3 = b_SLD->size[0];
    b_SLD->size[0] = Lays->size[0];
    emxEnsureCapacity((emxArray__common *)b_SLD, i3, (int)sizeof(double));
    if ((Lays->size[0] == 0) || (Lays->size[1] == 0)) {
      vstride = b_SLD->size[0];
      i3 = b_SLD->size[0];
      b_SLD->size[0] = vstride;
      emxEnsureCapacity((emxArray__common *)b_SLD, i3, (int)sizeof(double));
      for (i3 = 0; i3 < vstride; i3++) {
        b_SLD->data[i3] = 0.0;
      }
    } else {
      vstride = Lays->size[0];
      for (mtmp = 0; mtmp + 1 <= vstride; mtmp++) {
        layerThicks = Lays->data[mtmp];
        for (b_mtmp = 2; b_mtmp <= Lays->size[1]; b_mtmp++) {
          layerThicks += Lays->data[mtmp + (b_mtmp - 1) * vstride];
        }

        b_SLD->data[mtmp] = layerThicks;
      }
    }

    emxFree_real_T(&Lays);
    i3 = SLD->size[0] * SLD->size[1];
    SLD->size[0] = b_SLD->size[0];
    SLD->size[1] = 1;
    emxEnsureCapacity((emxArray__common *)SLD, i3, (int)sizeof(double));
    vstride = b_SLD->size[0];
    for (i3 = 0; i3 < vstride; i3++) {
      SLD->data[i3] = b_SLD->data[i3];
    }

    emxFree_real_T(&b_SLD);
  } else {
    i3 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = 101;
    emxEnsureCapacity((emxArray__common *)x, i3, (int)sizeof(double));
    for (i3 = 0; i3 < 101; i3++) {
      x->data[i3] = i3;
    }

    mtmp = 0;
    for (vstride = 1; vstride + 1 < 102; vstride++) {
      if ((signed char)vstride > mtmp) {
        mtmp = (signed char)vstride;
      }
    }

    b_mtmp = 0;
    for (vstride = 1; vstride + 1 < 102; vstride++) {
      if ((signed char)vstride > b_mtmp) {
        b_mtmp = (signed char)vstride;
      }
    }

    emxInit_real_T(&r0, 2);
    i3 = r0->size[0] * r0->size[1];
    r0->size[0] = 1;
    r0->size[1] = 101;
    emxEnsureCapacity((emxArray__common *)r0, i3, (int)sizeof(double));
    for (i3 = 0; i3 < 101; i3++) {
      r0->data[i3] = i3;
    }

    b_asymconvstep(r0->data, b_mtmp, 0.0, ssub, ssub, nbair, subBox_data,
                   subBox_size);
    i3 = airBox->size[0] * airBox->size[1];
    airBox->size[0] = 1;
    airBox->size[1] = 101;
    emxEnsureCapacity((emxArray__common *)airBox, i3, (int)sizeof(double));
    emxFree_real_T(&r0);
    for (i3 = 0; i3 < 101; i3++) {
      airBox->data[i3] = subBox_data[i3];
    }

    emxInit_real_T(&r1, 2);
    i3 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = 101;
    emxEnsureCapacity((emxArray__common *)r1, i3, (int)sizeof(double));
    for (i3 = 0; i3 < 101; i3++) {
      r1->data[i3] = i3;
    }

    b_asymconvstep(r1->data, b_mtmp, mtmp, ssub, ssub, nbsub, subBox_data,
                   subBox_size);
    i3 = SLD->size[0] * SLD->size[1];
    SLD->size[0] = 1;
    SLD->size[1] = airBox->size[1];
    emxEnsureCapacity((emxArray__common *)SLD, i3, (int)sizeof(double));
    vstride = airBox->size[0] * airBox->size[1];
    emxFree_real_T(&r1);
    for (i3 = 0; i3 < vstride; i3++) {
      SLD->data[i3] = airBox->data[i3] + subBox_data[i3];
    }
  }

  emxFree_real_T(&airBox);

  /* plot(x,SLD) */
  vstride = x->size[1];
  mtmp = SLD->size[0] * SLD->size[1];
  i3 = out->size[0] * out->size[1];
  out->size[0] = vstride;
  out->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)out, i3, (int)sizeof(double));
  for (i3 = 0; i3 < vstride; i3++) {
    out->data[i3] = x->data[i3];
  }

  emxFree_real_T(&x);
  for (i3 = 0; i3 < mtmp; i3++) {
    out->data[i3 + out->size[0]] = SLD->data[i3];
  }

  emxFree_real_T(&SLD);
}

/* End of code generation (makeSLDProfileXY.c) */
