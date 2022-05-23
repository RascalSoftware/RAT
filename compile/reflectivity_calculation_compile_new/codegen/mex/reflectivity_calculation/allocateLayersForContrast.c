/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * allocateLayersForContrast.c
 *
 * Code generation for function 'allocateLayersForContrast'
 *
 */

/* Include files */
#include "allocateLayersForContrast.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo s_emlrtRSI = { 19,  /* lineNo */
  "allocateLayersForContrast",         /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 22,  /* lineNo */
  "nullAssignment",                    /* fcnName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 26,  /* lineNo */
  "nullAssignment",                    /* fcnName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtBCInfo ne_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  28,                                  /* colNo */
  "thisContrastLayers",                /* aName */
  "allocateLayersForContrast",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo fb_emlrtRTEI = { 297,/* lineNo */
  1,                                   /* colNo */
  "delete_rows",                       /* fName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 81,/* lineNo */
  27,                                  /* colNo */
  "validate_inputs",                   /* fName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtBCInfo oe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  9,                                   /* colNo */
  "contrastLayers",                    /* aName */
  "allocateLayersForContrast",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  21,                                  /* colNo */
  "outParameterisedLayers",            /* aName */
  "allocateLayersForContrast",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo bb_emlrtDCI = { 16, /* lineNo */
  21,                                  /* colNo */
  "allocateLayersForContrast",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo qe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  21,                                  /* colNo */
  "contrastLayers",                    /* aName */
  "allocateLayersForContrast",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo hh_emlrtRTEI = { 12,/* lineNo */
  1,                                   /* colNo */
  "allocateLayersForContrast",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m"/* pName */
};

static emlrtRTEInfo ih_emlrtRTEI = { 298,/* lineNo */
  5,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo jh_emlrtRTEI = { 19,/* lineNo */
  9,                                   /* colNo */
  "allocateLayersForContrast",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m"/* pName */
};

/* Function Definitions */
void allocateLayersForContrast(const emlrtStack *sp, const emxArray_real_T
  *contrastLayers, const emxArray_cell_wrap_17 *outParameterisedLayers,
  emxArray_real_T *thisContrastLayers)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *b_thisContrastLayers;
  real_T d;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  int32_T j;
  int32_T n;
  int32_T nrows;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  Decide which layers are needed for a particular contrast */
  /*  This function takes the master array of all layers */
  /*  and extracts which parameters are requires for  */
  /*  a particular contrast.  */
  /*  outParameterisedLayers - List of all the available layers */
  /*  thisContrastLayers     - Array detailing which layers are required  */
  /*                           for this contrast */
  if ((contrastLayers->size[0] == 0) || (contrastLayers->size[1] == 0)) {
    n = 0;
  } else {
    n = contrastLayers->size[1];
  }

  i = thisContrastLayers->size[0] * thisContrastLayers->size[1];
  thisContrastLayers->size[0] = n;
  thisContrastLayers->size[1] = 5;
  emxEnsureCapacity_real_T(sp, thisContrastLayers, i, &hh_emlrtRTEI);
  nrows = n * 5;
  for (i = 0; i < nrows; i++) {
    thisContrastLayers->data[i] = 0.0;
  }

  if ((contrastLayers->size[0] == 0) || (contrastLayers->size[1] == 0)) {
    n = 0;
  } else {
    n = contrastLayers->size[1];
  }

  emxInit_real_T(sp, &b_thisContrastLayers, 2, &ih_emlrtRTEI, true);
  for (b_i = 0; b_i < n; b_i++) {
    i = contrastLayers->size[0] * contrastLayers->size[1];
    if ((b_i + 1 < 1) || (b_i + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &oe_emlrtBCI, sp);
    }

    if (contrastLayers->data[b_i] != 0.0) {
      if ((b_i + 1 < 1) || (b_i + 1 > thisContrastLayers->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, thisContrastLayers->size[0],
          &ne_emlrtBCI, sp);
      }

      for (i = 0; i < 5; i++) {
        j = contrastLayers->size[0] * contrastLayers->size[1];
        if ((b_i + 1 < 1) || (b_i + 1 > j)) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, j, &qe_emlrtBCI, sp);
        }

        d = contrastLayers->data[b_i];
        if (d != (int32_T)muDoubleScalarFloor(d)) {
          emlrtIntegerCheckR2012b(d, &bb_emlrtDCI, sp);
        }

        if (((int32_T)d - 1 < 0) || ((int32_T)d - 1 >
             outParameterisedLayers->size[1] - 1)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)d - 1, 0,
            outParameterisedLayers->size[1] - 1, &pe_emlrtBCI, sp);
        }

        thisContrastLayers->data[b_i + thisContrastLayers->size[0] * i] =
          outParameterisedLayers->data[(int32_T)d - 1].f1[i];
      }
    } else {
      st.site = &s_emlrtRSI;
      b_st.site = &t_emlrtRSI;
      i = thisContrastLayers->size[0];
      if (1 > thisContrastLayers->size[0]) {
        emlrtErrorWithMessageIdR2018a(&b_st, &gb_emlrtRTEI,
          "MATLAB:subsdeldimmismatch", "MATLAB:subsdeldimmismatch", 0);
      }

      b_st.site = &u_emlrtRSI;
      nrows = thisContrastLayers->size[0] - 1;
      for (j = 0; j < 5; j++) {
        for (c_i = 0; c_i < nrows; c_i++) {
          thisContrastLayers->data[c_i + thisContrastLayers->size[0] * j] =
            thisContrastLayers->data[(c_i + thisContrastLayers->size[0] * j) + 1];
        }
      }

      if (i - 1 > i) {
        emlrtErrorWithMessageIdR2018a(&b_st, &fb_emlrtRTEI,
          "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
      }

      if (1 > i - 1) {
        nrows = 0;
      } else {
        nrows = i - 1;
      }

      i = b_thisContrastLayers->size[0] * b_thisContrastLayers->size[1];
      b_thisContrastLayers->size[0] = nrows;
      b_thisContrastLayers->size[1] = 5;
      emxEnsureCapacity_real_T(&b_st, b_thisContrastLayers, i, &ih_emlrtRTEI);
      for (i = 0; i < 5; i++) {
        for (j = 0; j < nrows; j++) {
          b_thisContrastLayers->data[j + b_thisContrastLayers->size[0] * i] =
            thisContrastLayers->data[j + thisContrastLayers->size[0] * i];
        }
      }

      i = thisContrastLayers->size[0] * thisContrastLayers->size[1];
      thisContrastLayers->size[0] = b_thisContrastLayers->size[0];
      thisContrastLayers->size[1] = 5;
      emxEnsureCapacity_real_T(&b_st, thisContrastLayers, i, &jh_emlrtRTEI);
      nrows = b_thisContrastLayers->size[0] * b_thisContrastLayers->size[1];
      for (i = 0; i < nrows; i++) {
        thisContrastLayers->data[i] = b_thisContrastLayers->data[i];
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_thisContrastLayers);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (allocateLayersForContrast.c) */
