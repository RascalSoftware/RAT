//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  reflectivity_calculation_gpu.cu
//
//  Code generation for function 'reflectivity_calculation_gpu'
//


// Include files
#include "reflectivity_calculation_gpu.h"
#include "MWCudaDimUtility.hpp"
#include "MWLaunchParametersUtilities.hpp"
#include "math_constants.h"
#include "reflectivity_calculation_gpu_data.h"
#include "reflectivity_calculation_gpu_emxutil.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

// Function Declarations
static __global__ void ab_reflectivity_calculation_gpu(const cell_10
  *problemDef_cells, const int32_T i, real_T thisData[153]);
static __global__ void ac_reflectivity_calculation_gpu(const emxArray_real_T *r1,
  const emxArray_real_T *r, const real_T a, const int32_T *qEnd, const int32_T
  ii_size[1], emxArray_real_T *Lays);
static __global__ void ad_reflectivity_calculation_gpu(const emxArray_real_T
  *normalizedData, const int32_T kEnd, emxArray_real_T *longStep);
static __global__ void ae_reflectivity_calculation_gpu(const emxArray_boolean_T *
  segmentsToSplit, const int32_T *nx, emxArray_boolean_T *r23);
static __global__ void af_reflectivity_calculation_gpu(const emxArray_real_T
  *simXdata, emxArray_real_T *Simul);
static __global__ void ag_reflectivity_calculation_gpu(const real_T terms_data
  [51], real_T *layerThicks);
static __global__ void ah_reflectivity_calculation_gpu(const real_T bFactor,
  const emxArray_real_T *x, emxArray_real_T *b);
static __global__ void ai_reflectivity_calculation_gpu(const real_T bFactor,
  const real_T *layerThicks, real_T y[50]);
static __global__ void aj_reflectivity_calculation_gpu(const emxArray_real_T
  *secondStepSquared, const emxArray_real_T *firstStepSquared, emxArray_real_T
  *x);
static __global__ void ak_reflectivity_calculation_gpu(int8_T col_data[2]);
static __global__ void al_reflectivity_calculation_gpu(const real_T l, const
  real_T *layerThicks, const real_T bFactor, const real_T nextLayRough, creal_T
  N[4]);
static __device__ real_T atomicOpreal_T(real_T *address, real_T value);
static __global__ void bb_reflectivity_calculation_gpu(real_T layers_data[10]);
static __global__ void bc_reflectivity_calculation_gpu(const emxArray_real_T
  *Lays, const int32_T vstride, emxArray_real_T *SLD);
static __global__ void bd_reflectivity_calculation_gpu(const emxArray_real_T
  *firstStep, const int32_T *nx, emxArray_real_T *z1);
static __global__ void be_reflectivity_calculation_gpu(const emxArray_int32_T
  *r27, const emxArray_real_T *dataPoints, const emxArray_int32_T *r25,
  emxArray_real_T *newDataPoints);
static __global__ void bf_reflectivity_calculation_gpu(const emxArray_real_T
  *simXdata, emxArray_real_T *Simul);
static __global__ void bg_reflectivity_calculation_gpu(const real_T terms_data
  [51], int32_T vlen, real_T *layerThicks);
static __global__ void bh_reflectivity_calculation_gpu(const emxArray_real_T *a,
  const int32_T *nx, emxArray_real_T *r2);
static __global__ void bi_reflectivity_calculation_gpu(const real_T bFactor,
  const real_T l, const real_T *layerThicks, real_T y[50]);
static __global__ void bj_reflectivity_calculation_gpu(const emxArray_real_T *x,
  int32_T *nx);
static __global__ void bk_reflectivity_calculation_gpu(const emxArray_real_T
  *dataPoints, emxArray_int32_T *idx);
static __global__ void bl_reflectivity_calculation_gpu(const creal_T N[4], const
  creal_T MI[4], creal_T b_MI[4]);
static __global__ void cb_reflectivity_calculation_gpu(const real_T
  thisContrastLayers[10], real_T layers_data[10]);
static __global__ void cc_reflectivity_calculation_gpu(const int32_T *xoffset,
  const emxArray_real_T *Lays, const int32_T vstride, emxArray_real_T *SLD);
static __global__ void cd_reflectivity_calculation_gpu(const emxArray_real_T
  *firstStep, const int32_T *nx, emxArray_real_T *z1);
static __global__ void ce_reflectivity_calculation_gpu(const real_T *layerThicks,
  const emxArray_real_T *sldProfile, const int32_T *qEnd, emxArray_boolean_T *x);
static __global__ void cf_reflectivity_calculation_gpu(creal_T MI[4]);
static __global__ void cg_reflectivity_calculation_gpu(real_T thisOutLayer[5]);
static __global__ void ch_reflectivity_calculation_gpu(const emxArray_real_T *b,
  const int32_T *nx, emxArray_real_T *r3);
static void checkCudaError(cudaError_t errCode, const char * file, uint32_T line);
static __global__ void ci_reflectivity_calculation_gpu(const real_T dataBoxSize
  [2], real_T y[50]);
static __global__ void cj_reflectivity_calculation_gpu(const int32_T *nx,
  emxArray_real_T *x);
static __global__ void ck_reflectivity_calculation_gpu(const int8_T col_data[2],
  const emxArray_real_T *dataPoints, const int32_T kEnd, emxArray_int32_T *idx);
static __global__ void cl_reflectivity_calculation_gpu(const creal_T MI[4],
  creal_T b_MI[4]);
static __global__ void d_reflectivity_calculation_gpu_(const struct0_T
  problemDef, emxArray_real_T *backgs);
static __global__ void db_reflectivity_calculation_gpu(const real_T nba, const
  struct0_T problemDef, const int32_T i, const real_T thisContrastLayers[10],
  real_T layers_data[10]);
static __global__ void dc_reflectivity_calculation_gpu(const emxArray_real_T
  *Lays, uint32_T sz[2]);
static __global__ void dd_reflectivity_calculation_gpu(const emxArray_real_T *z1,
  const emxArray_real_T *b_z1, emxArray_real_T *firstStepSquared);
static __global__ void de_reflectivity_calculation_gpu(const emxArray_real_T
  *sldProfile, const real_T *layerThicks, const int32_T *qEnd,
  emxArray_boolean_T *x);
static __global__ void df_reflectivity_calculation_gpu(const real_T l, const
  real_T *layerThicks, const real_T bFactor, const real_T nextLayRough, creal_T
  N[4]);
static __global__ void dg_reflectivity_calculation_gpu(const struct0_T
  problemDef, const cell_10 *problemDef_cells, real_T thisOutLayer[5]);
static __global__ void dh_reflectivity_calculation_gpu(const real_T *layerThicks,
  const real_T l, const emxArray_real_T *x, emxArray_real_T *a);
static __global__ void di_reflectivity_calculation_gpu(const real_T *layerThicks,
  const emxArray_real_T *sldProfile, const int32_T kEnd, emxArray_boolean_T *x);
static __global__ void dj_reflectivity_calculation_gpu(const emxArray_real_T *x,
  const emxArray_real_T *z1, const emxArray_real_T *b_z1, const emxArray_real_T *
  secondStepSquared, const emxArray_real_T *firstStepSquared, emxArray_creal_T
  *b_x);
static __global__ void dk_reflectivity_calculation_gpu(const emxArray_real_T
  *dataPoints, emxArray_int32_T *idx);
static __global__ void dl_reflectivity_calculation_gpu(const emxArray_real_T
  *simXdata, emxArray_real_T *dummydata);
static __global__ void e_reflectivity_calculation_gpu_(const struct0_T
  problemDef, emxArray_real_T *qshifts);
static __global__ void eb_reflectivity_calculation_gpu(emxArray_real_T
  *sldProfile);
static __global__ void ec_reflectivity_calculation_gpu(const uint32_T sz[2],
  emxArray_real_T *SLD);
static __global__ void ed_reflectivity_calculation_gpu(const emxArray_real_T
  *secondStep, const int32_T *nx, emxArray_real_T *z1);
static __global__ void ee_reflectivity_calculation_gpu(const emxArray_real_T
  *sldProfile, const real_T *layerThicks, const int32_T *qEnd,
  emxArray_boolean_T *x);
static __global__ void ef_reflectivity_calculation_gpu(const creal_T N[4], const
  creal_T MI[4], creal_T b_MI[4]);
static __global__ void eg_reflectivity_calculation_gpu(const cell_10
  *problemDef_cells, real_T thisOutLayer[5]);
static __global__ void eh_reflectivity_calculation_gpu(const real_T bFactor,
  const real_T r, const emxArray_real_T *x, emxArray_real_T *b);
static __global__ void ei_reflectivity_calculation_gpu(const emxArray_real_T
  *sldProfile, const real_T *layerThicks, const int32_T kEnd, emxArray_boolean_T
  *x);
static __global__ void ej_reflectivity_calculation_gpu(const emxArray_creal_T *x,
  int32_T *nx);
static __global__ void ek_reflectivity_calculation_gpu(const int32_T j, const
  emxArray_real_T *dataPoints, const emxArray_int32_T *idx, const int32_T
  *xoffset, emxArray_real_T *ycol);
static __global__ void el_reflectivity_calculation_gpu(const emxArray_real_T
  *simRef, const struct0_T problemDef, const emxArray_real_T *simXdata, const
  int32_T *xoffset, const int32_T kEnd, emxArray_real_T *dummydata);
static __global__ void f_reflectivity_calculation_gpu_(const struct0_T
  problemDef, emxArray_real_T *sfs);
static __global__ void fb_reflectivity_calculation_gpu(const real_T layers_data
  [10], real_T *layerThicks);
static __global__ void fc_reflectivity_calculation_gpu(const emxArray_real_T *x,
  const int32_T *nx, emxArray_real_T *sldProfile);
static __global__ void fd_reflectivity_calculation_gpu(const emxArray_real_T
  *secondStep, const int32_T *nx, emxArray_real_T *z1);
static __global__ void fe_reflectivity_calculation_gpu(const emxArray_real_T
  *sldProfile, const emxArray_int32_T *ii, emxArray_real_T *r30);
static __global__ void ff_reflectivity_calculation_gpu(const creal_T MI[4],
  creal_T b_MI[4]);
static __global__ void fg_reflectivity_calculation_gpu(const real_T
  thisOutLayer[5], cell_wrap_2 outParameterisedLayers[4]);
static __global__ void fh_reflectivity_calculation_gpu(const emxArray_real_T *a,
  const int32_T *nx, emxArray_real_T *r10);
static __global__ void fi_reflectivity_calculation_gpu(const emxArray_real_T
  *sldProfile, const real_T *layerThicks, const int32_T kEnd, emxArray_boolean_T
  *x);
static __global__ void fj_reflectivity_calculation_gpu(const int32_T *nx,
  emxArray_creal_T *x);
static __global__ void fk_reflectivity_calculation_gpu(const emxArray_real_T
  *ycol, const int32_T j, const int32_T *xoffset, emxArray_real_T *dataPoints);
static __global__ void fl_reflectivity_calculation_gpu(const emxArray_real_T
  *dummydata, emxArray_real_T *Simul);
static __global__ void g_reflectivity_calculation_gpu_(const struct0_T
  problemDef, emxArray_real_T *nbas);
static __global__ void gb_reflectivity_calculation_gpu(const real_T *layerThicks,
  emxArray_real_T *x);
static __global__ void gc_reflectivity_calculation_gpu(const emxArray_real_T
  *SLD, const int32_T *nx, emxArray_real_T *sldProfile);
static __global__ void gd_reflectivity_calculation_gpu(const emxArray_real_T *z1,
  const emxArray_real_T *b_z1, emxArray_real_T *secondStepSquared);
static __global__ void ge_reflectivity_calculation_gpu(const emxArray_real_T
  *r16, emxArray_real_T *newDataPoints);
static __global__ void gf_reflectivity_calculation_gpu(const real_T l, const
  real_T bFactor, creal_T N[4]);
static __global__ void gg_reflectivity_calculation_gpu(const struct0_T
  problemDef, const cell_10 *problemDef_cells, real_T thisOutLayer[5]);
static __global__ void gh_reflectivity_calculation_gpu(const emxArray_real_T *b,
  const int32_T *nx, emxArray_real_T *r12);
static __global__ void gi_reflectivity_calculation_gpu(const emxArray_real_T
  *sldProfile, const emxArray_int32_T *ii, emxArray_real_T *r13);
static __global__ void gj_reflectivity_calculation_gpu(const emxArray_creal_T *x,
  const emxArray_real_T *dataPoints, emxArray_boolean_T *trianglesToRefine);
static __global__ void gk_reflectivity_calculation_gpu(const emxArray_int32_T
  *iwork, const int32_T j, const int32_T kEnd, emxArray_int32_T *idx);
static __global__ void gl_reflectivity_calculation_gpu(const emxArray_real_T
  *Simul, const int32_T kEnd, const int32_T *qEnd, emxArray_real_T *reflect);
static void gpuEmxFree_boolean_T(emxArray_boolean_T *inter);
static void gpuEmxFree_creal_T(emxArray_creal_T *inter);
static void gpuEmxFree_int32_T(emxArray_int32_T *inter);
static void gpuEmxFree_int8_T(emxArray_int8_T *inter);
static void gpuEmxFree_real_T(emxArray_real_T *inter);
static void gpuEmxMemcpyCpuToGpu_boolean_T(const emxArray_boolean_T *cpu,
  emxArray_boolean_T *inter, emxArray_boolean_T *gpu);
static void gpuEmxMemcpyCpuToGpu_creal_T(const emxArray_creal_T *cpu,
  emxArray_creal_T *inter, emxArray_creal_T *gpu);
static void gpuEmxMemcpyCpuToGpu_int32_T(const emxArray_int32_T *cpu,
  emxArray_int32_T *inter, emxArray_int32_T *gpu);
static void gpuEmxMemcpyCpuToGpu_int8_T(const emxArray_int8_T *cpu,
  emxArray_int8_T *inter, emxArray_int8_T *gpu);
static void gpuEmxMemcpyCpuToGpu_real_T(const emxArray_real_T *cpu,
  emxArray_real_T *inter, emxArray_real_T *gpu);
static void gpuEmxMemcpyGpuToCpu_boolean_T(emxArray_boolean_T *cpu,
  emxArray_boolean_T *inter);
static void gpuEmxMemcpyGpuToCpu_creal_T(emxArray_creal_T *cpu, emxArray_creal_T
  *inter);
static void gpuEmxMemcpyGpuToCpu_int32_T(emxArray_int32_T *cpu, emxArray_int32_T
  *inter);
static void gpuEmxMemcpyGpuToCpu_int8_T(emxArray_int8_T *cpu, emxArray_int8_T
  *inter);
static void gpuEmxMemcpyGpuToCpu_real_T(emxArray_real_T *cpu, emxArray_real_T
  *inter);
static void gpuEmxReset_boolean_T(emxArray_boolean_T *inter);
static void gpuEmxReset_creal_T(emxArray_creal_T *inter);
static void gpuEmxReset_int32_T(emxArray_int32_T *inter);
static void gpuEmxReset_int8_T(emxArray_int8_T *inter);
static void gpuEmxReset_real_T(emxArray_real_T *inter);
static __global__ void h_reflectivity_calculation_gpu_(const struct0_T
  problemDef, emxArray_real_T *nbss);
static __global__ void hb_reflectivity_calculation_gpu(const real_T reps, const
  emxArray_real_T *x, emxArray_real_T *Lays);
static __global__ void hc_reflectivity_calculation_gpu(const real_T layers_data
  [10], emxArray_real_T *layers);
static __global__ void hd_reflectivity_calculation_gpu(const emxArray_real_T
  *longStep, const int32_T *nx, emxArray_real_T *z1);
static __global__ void he_reflectivity_calculation_gpu(const emxArray_real_T
  *dataPoints, emxArray_real_T *b_dataPoints);
static __global__ void hf_reflectivity_calculation_gpu(const real_T l, const
  real_T *layerThicks, const real_T bFactor, const real_T nextLayRough, creal_T
  N[4]);
static __global__ void hg_reflectivity_calculation_gpu(const cell_10
  *problemDef_cells, real_T thisOutLayer[5]);
static __global__ void hh_reflectivity_calculation_gpu(const emxArray_real_T
  *Lays, int32_T *xoffset);
static __global__ void hi_reflectivity_calculation_gpu(const real_T hiVal[50],
  const real_T y[50], real_T b_y[100]);
static __global__ void hj_reflectivity_calculation_gpu(const emxArray_boolean_T *
  trianglesToRefine, const int32_T *nx, emxArray_boolean_T *b_trianglesToRefine);
static __global__ void hk_reflectivity_calculation_gpu(const emxArray_real_T
  *dataPoints, emxArray_real_T *layers);
static __global__ void hl_reflectivity_calculation_gpu(const real_T *layerThicks,
  const emxArray_real_T *Simul, const int32_T kEnd, const int32_T *qEnd,
  emxArray_real_T *reflect);
static __global__ void i_reflectivity_calculation_gpu_(const struct0_T
  problemDef, emxArray_real_T *chis);
static __global__ void ib_reflectivity_calculation_gpu(const real_T *layerThicks,
  const emxArray_real_T *x, emxArray_real_T *a);
static __global__ void ic_reflectivity_calculation_gpu(const real_T dataBoxSize
  [2], real_T y[50]);
static __global__ void id_reflectivity_calculation_gpu(const emxArray_real_T
  *longStep, const int32_T *nx, emxArray_real_T *z1);
static __global__ void ie_reflectivity_calculation_gpu(const emxArray_real_T
  *dataPoints, emxArray_real_T *b_dataPoints);
static __global__ void if_reflectivity_calculation_gpu(const real_T l, const
  real_T bFactor, creal_T N[4]);
static __global__ void ig_reflectivity_calculation_gpu(const real_T
  thisOutLayer[5], cell_wrap_2 outParameterisedLayers[4]);
static __global__ void ih_reflectivity_calculation_gpu(const emxArray_real_T
  *r12, const emxArray_real_T *r10, const real_T *layerThicks, const int32_T
  *qEnd, const int32_T ii_size[1], emxArray_real_T *Lays);
static __global__ void ii_reflectivity_calculation_gpu(const real_T y[100],
  emxArray_real_T *dataPoints);
static __global__ void ij_reflectivity_calculation_gpu(const emxArray_boolean_T *
  trianglesToRefine, emxArray_boolean_T *b_trianglesToRefine);
static __global__ void ik_reflectivity_calculation_gpu(const emxArray_real_T
  *dataPoints, const int32_T kEnd, emxArray_real_T *layers);
static __global__ void il_reflectivity_calculation_gpu(const real_T *layerThicks,
  const int32_T kEnd, emxArray_real_T *Simul);
static __global__ void j_reflectivity_calculation_gpu_(const struct0_T
  problemDef, emxArray_real_T *resols);
static __global__ void jb_reflectivity_calculation_gpu(const real_T bFactor,
  const emxArray_real_T *x, emxArray_real_T *b);
static __global__ void jc_reflectivity_calculation_gpu(const real_T bFactor,
  const real_T *layerThicks, real_T y[50]);
static __global__ void jd_reflectivity_calculation_gpu(const emxArray_real_T
  *secondStepSquared, const emxArray_real_T *firstStepSquared, emxArray_real_T
  *x);
static __global__ void je_reflectivity_calculation_gpu(int8_T col_data[2]);
static __global__ void jf_reflectivity_calculation_gpu(const real_T l, const
  real_T *layerThicks, const real_T bFactor, const real_T nextLayRough, creal_T
  N[4]);
static __global__ void jg_reflectivity_calculation_gpu(const struct0_T
  problemDef, const cell_10 *problemDef_cells, real_T thisOutLayer[5]);
static __global__ void jh_reflectivity_calculation_gpu(const real_T *layerThicks,
  const real_T l, const emxArray_real_T *x, emxArray_real_T *a);
static __global__ void ji_reflectivity_calculation_gpu(const int32_T vlen, const
  emxArray_real_T *dataPoints, real_T dataBoxSize[2]);
static __global__ void jj_reflectivity_calculation_gpu(emxArray_boolean_T *r33);
static __global__ void jk_reflectivity_calculation_gpu(const cell_10
  *problemDef_cells, const int32_T i, real_T shifted_dat_data[153]);
static __global__ void jl_reflectivity_calculation_gpu(const real_T *layerThicks,
  const real_T shifted_dat_data[153], const int32_T shifted_dat_size[2], const
  int32_T kEnd, real_T terms_data[51]);
static __global__ void k_reflectivity_calculation_gpu_(const struct0_T
  problemDef, emxArray_real_T *allRoughs);
static __global__ void kb_reflectivity_calculation_gpu(const emxArray_real_T *a,
  const int32_T *nx, emxArray_real_T *r);
static __global__ void kc_reflectivity_calculation_gpu(const real_T bFactor,
  const real_T l, const real_T *layerThicks, real_T y[50]);
static __global__ void kd_reflectivity_calculation_gpu(const emxArray_real_T *x,
  int32_T *nx);
static __global__ void ke_reflectivity_calculation_gpu(const emxArray_real_T
  *dataPoints, emxArray_int32_T *idx);
static __global__ void kf_reflectivity_calculation_gpu(const creal_T N[4], const
  creal_T MI[4], creal_T b_MI[4]);
static __global__ void kg_reflectivity_calculation_gpu(const cell_10
  *problemDef_cells, real_T thisOutLayer[5]);
static __global__ void kh_reflectivity_calculation_gpu(const real_T bFactor,
  const real_T r, const emxArray_real_T *x, emxArray_real_T *b);
static __global__ void ki_reflectivity_calculation_gpu(const int32_T vlen, const
  emxArray_real_T *dataPoints, real_T minval[2]);
static __global__ void kj_reflectivity_calculation_gpu(const emxArray_boolean_T *
  trianglesToRefine, const int32_T *nx, emxArray_boolean_T *r33);
static __global__ void kk_reflectivity_calculation_gpu(const real_T bFactor,
  const real_T *layerThicks, const real_T shifts, const cell_10
  *problemDef_cells, const int32_T i, boolean_T x[51], real_T thisData[153]);
static __global__ void kl_reflectivity_calculation_gpu(const real_T terms_data
  [51], const int32_T shifted_dat_size[2], const int32_T ii_size[1], real_T
  shifted_dat_data[153]);
static __global__ void l_reflectivity_calculation_gpu_(real_T thisOutLayer[5]);
static __global__ void lb_reflectivity_calculation_gpu(const emxArray_real_T *b,
  const int32_T *nx, emxArray_real_T *r1);
static __global__ void lc_reflectivity_calculation_gpu(const real_T dataBoxSize
  [2], real_T y[50]);
static __global__ void ld_reflectivity_calculation_gpu(const int32_T *nx,
  emxArray_real_T *x);
static __global__ void le_reflectivity_calculation_gpu(const int8_T col_data[2],
  const emxArray_real_T *dataPoints, const int32_T kEnd, emxArray_int32_T *idx);
static __global__ void lf_reflectivity_calculation_gpu(const creal_T MI[4],
  creal_T b_MI[4]);
static __global__ void lg_reflectivity_calculation_gpu(const real_T
  thisOutLayer[5], cell_wrap_2 outParameterisedLayers[4]);
static __global__ void lh_reflectivity_calculation_gpu(const emxArray_real_T *a,
  const int32_T *nx, emxArray_real_T *r6);
static __global__ void li_reflectivity_calculation_gpu(const real_T minval[2],
  real_T dataBoxSize[2]);
static __global__ void lj_reflectivity_calculation_gpu(const emxArray_boolean_T *
  r33, const emxArray_boolean_T *trianglesToRefine, emxArray_boolean_T
  *segmentsToSplit);
static __global__ void lk_reflectivity_calculation_gpu(const real_T bFactor,
  const real_T thisData[153], boolean_T x[51]);
static __global__ void ll_reflectivity_calculation_gpu(const emxArray_real_T
  *reflect, const real_T shifted_dat_data[153], const int32_T shifted_dat_size[2],
  const int32_T kEnd, emxArray_real_T *z);
static __global__ void m_reflectivity_calculation_gpu_(const struct0_T
  problemDef, const cell_10 *problemDef_cells, real_T thisOutLayer[5]);
static __global__ void mb_reflectivity_calculation_gpu(const real_T *layerThicks,
  const real_T l, const emxArray_real_T *x, emxArray_real_T *a);
static __global__ void mc_reflectivity_calculation_gpu(const real_T *layerThicks,
  const emxArray_real_T *sldProfile, const int32_T kEnd, emxArray_boolean_T *x);
static __global__ void md_reflectivity_calculation_gpu(const emxArray_real_T *x,
  const emxArray_real_T *z1, const emxArray_real_T *b_z1, const emxArray_real_T *
  secondStepSquared, const emxArray_real_T *firstStepSquared, emxArray_creal_T
  *b_x);
static __global__ void me_reflectivity_calculation_gpu(const emxArray_real_T
  *dataPoints, emxArray_int32_T *idx);
static __global__ void mf_reflectivity_calculation_gpu(const emxArray_real_T
  *simXdata, emxArray_real_T *dummydata);
static __global__ void mg_reflectivity_calculation_gpu(const struct0_T
  problemDef, const cell_10 *problemDef_cells, real_T thisOutLayer[5]);
static __global__ void mh_reflectivity_calculation_gpu(const emxArray_real_T *b,
  const int32_T *nx, emxArray_real_T *r7);
static __global__ void mi_reflectivity_calculation_gpu(const int32_T vlen, const
  emxArray_real_T *dataPoints, real_T minval[2]);
static __global__ void mj_reflectivity_calculation_gpu(const int32_T *xoffset,
  emxArray_real_T *newDataPoints);
static __global__ void mk_reflectivity_calculation_gpu(const real_T thisData[153],
  const int32_T shifted_dat_size[2], const int32_T kEnd, const int32_T *qEnd,
  real_T shifted_dat_data[153]);
static __global__ void ml_reflectivity_calculation_gpu(const emxArray_real_T *z,
  const int32_T *nx, emxArray_real_T *z1);
static __global__ void n_reflectivity_calculation_gpu_(const cell_10
  *problemDef_cells, real_T thisOutLayer[5]);
static __global__ void nb_reflectivity_calculation_gpu(const real_T bFactor,
  const real_T r, const emxArray_real_T *x, emxArray_real_T *b);
static __global__ void nc_reflectivity_calculation_gpu(const emxArray_real_T
  *sldProfile, const real_T *layerThicks, const int32_T kEnd, emxArray_boolean_T
  *x);
static __global__ void nd_reflectivity_calculation_gpu(const emxArray_creal_T *x,
  int32_T *nx);
static __global__ void ne_reflectivity_calculation_gpu(const int32_T j, const
  emxArray_real_T *dataPoints, const emxArray_int32_T *idx, const int32_T
  *xoffset, emxArray_real_T *ycol);
static __global__ void nf_reflectivity_calculation_gpu(const emxArray_real_T
  *simRef, const struct0_T problemDef, const emxArray_real_T *simXdata, const
  int32_T *xoffset, const int32_T kEnd, emxArray_real_T *dummydata);
static __global__ void ng_reflectivity_calculation_gpu(const cell_10
  *problemDef_cells, real_T thisOutLayer[5]);
static __global__ void nh_reflectivity_calculation_gpu(const emxArray_real_T
  *Lays, int32_T *qEnd);
static __global__ void ni_reflectivity_calculation_gpu(const emxArray_real_T
  *r15, const emxArray_real_T *b, const emxArray_real_T *dataPoints, const
  int32_T kEnd, emxArray_real_T *normalizedData);
static __global__ void nj_reflectivity_calculation_gpu(const emxArray_boolean_T *
  segmentsToSplit, const int32_T *nx, emxArray_boolean_T *r24);
static __global__ void nk_reflectivity_calculation_gpu(const real_T reps, const
  real_T *layerThicks, const real_T bFactor, emxArray_real_T *firstSection);
static __global__ void nl_reflectivity_calculation_gpu(const emxArray_real_T *z1,
  real_T terms_data[51]);
static __global__ void o_reflectivity_calculation_gpu_(const real_T
  thisOutLayer[5], cell_wrap_2 outParameterisedLayers[4]);
static __global__ void ob_reflectivity_calculation_gpu(const emxArray_real_T *a,
  const int32_T *nx, emxArray_real_T *r8);
static __global__ void oc_reflectivity_calculation_gpu(const emxArray_real_T
  *sldProfile, const real_T *layerThicks, const int32_T kEnd, emxArray_boolean_T
  *x);
static __global__ void od_reflectivity_calculation_gpu(const int32_T *nx,
  emxArray_creal_T *x);
static __global__ void oe_reflectivity_calculation_gpu(const emxArray_real_T
  *ycol, const int32_T j, const int32_T *xoffset, emxArray_real_T *dataPoints);
static __global__ void of_reflectivity_calculation_gpu(const emxArray_real_T
  *dummydata, emxArray_real_T *Simul);
static __global__ void og_reflectivity_calculation_gpu(const real_T
  thisOutLayer[5], cell_wrap_2 outParameterisedLayers[4]);
static __global__ void oh_reflectivity_calculation_gpu(const emxArray_real_T *r7,
  const emxArray_real_T *r6, const real_T *layerThicks, const int32_T *qEnd,
  const int32_T ii_size[1], emxArray_real_T *Lays);
static __global__ void oi_reflectivity_calculation_gpu(const emxArray_real_T
  *normalizedData, const int32_T kEnd, emxArray_real_T *firstStep);
static __global__ void oj_reflectivity_calculation_gpu(const emxArray_boolean_T *
  segmentsToSplit, emxArray_boolean_T *r24);
static __global__ void ok_reflectivity_calculation_gpu(const real_T reps, const
  real_T a, const real_T *layerThicks, emxArray_real_T *lastSection);
static __global__ void ol_reflectivity_calculation_gpu(const emxArray_real_T *z1,
  emxArray_boolean_T *x);
static __global__ void p_reflectivity_calculation_gpu_(const struct0_T
  problemDef, const cell_10 *problemDef_cells, real_T thisOutLayer[5]);
static __global__ void pb_reflectivity_calculation_gpu(const emxArray_real_T *b,
  const int32_T *nx, emxArray_real_T *r9);
static __global__ void pc_reflectivity_calculation_gpu(const emxArray_real_T
  *sldProfile, const emxArray_int32_T *ii, emxArray_real_T *r11);
static __global__ void pd_reflectivity_calculation_gpu(const emxArray_creal_T *x,
  const emxArray_real_T *dataPoints, emxArray_boolean_T *trianglesToRefine);
static __global__ void pe_reflectivity_calculation_gpu(const emxArray_int32_T
  *iwork, const int32_T j, const int32_T kEnd, emxArray_int32_T *idx);
static __global__ void pf_reflectivity_calculation_gpu(const emxArray_real_T
  *Simul, const int32_T kEnd, const int32_T *qEnd, emxArray_real_T *reflect);
static __global__ void pg_reflectivity_calculation_gpu(const cell_wrap_2
  outParameterisedLayers[4], const cell_10 *problemDef_cells, const int32_T i,
  real_T thisContrastLayers[10]);
static __global__ void ph_reflectivity_calculation_gpu(const emxArray_real_T
  *Lays, int32_T *qEnd);
static __global__ void pi_reflectivity_calculation_gpu(const emxArray_real_T
  *normalizedData, const int32_T kEnd, emxArray_real_T *secondStep);
static __global__ void pj_reflectivity_calculation_gpu(emxArray_boolean_T *r26);
static __global__ void pk_reflectivity_calculation_gpu(const emxArray_real_T
  *firstSection, const int32_T vstride, emxArray_real_T *simXdata);
static __global__ void pl_reflectivity_calculation_gpu(const emxArray_int8_T *ii,
  real_T terms_data[51]);
static __global__ void q_reflectivity_calculation_gpu_(const cell_10
  *problemDef_cells, real_T thisOutLayer[5]);
static __global__ void qb_reflectivity_calculation_gpu(const emxArray_real_T
  *Lays, int32_T *xoffset);
static __global__ void qc_reflectivity_calculation_gpu(const real_T hiVal[50],
  const real_T y[50], real_T b_y[100]);
static __global__ void qd_reflectivity_calculation_gpu(const emxArray_boolean_T *
  trianglesToRefine, const int32_T *nx, emxArray_boolean_T *b_trianglesToRefine);
static __global__ void qe_reflectivity_calculation_gpu(const emxArray_real_T
  *dataPoints, emxArray_real_T *layers);
static __global__ void qf_reflectivity_calculation_gpu(const real_T *layerThicks,
  const emxArray_real_T *Simul, const int32_T kEnd, const int32_T *qEnd,
  emxArray_real_T *reflect);
static __global__ void qg_reflectivity_calculation_gpu(const cell_10
  *problemDef_cells, const int32_T i, real_T thisData[153]);
static __global__ void qh_reflectivity_calculation_gpu(const emxArray_real_T *r3,
  const emxArray_real_T *r2, const real_T a, const int32_T *qEnd, const int32_T
  ii_size[1], emxArray_real_T *Lays);
static __global__ void qi_reflectivity_calculation_gpu(const emxArray_real_T
  *normalizedData, const int32_T kEnd, emxArray_real_T *longStep);
static __global__ void qj_reflectivity_calculation_gpu(const emxArray_boolean_T *
  segmentsToSplit, const int32_T *nx, emxArray_boolean_T *r26);
static __global__ void qk_reflectivity_calculation_gpu(const emxArray_real_T
  *simXdata, emxArray_real_T *Simul);
static __global__ void ql_reflectivity_calculation_gpu(const real_T terms_data
  [51], real_T *layerThicks);
static __global__ void r_reflectivity_calculation_gpu_(const real_T
  thisOutLayer[5], cell_wrap_2 outParameterisedLayers[4]);
static __global__ void rb_reflectivity_calculation_gpu(const emxArray_real_T *r9,
  const emxArray_real_T *r8, const real_T *layerThicks, const int32_T *qEnd,
  const int32_T ii_size[1], emxArray_real_T *Lays);
static __global__ void rc_reflectivity_calculation_gpu(const real_T y[100],
  emxArray_real_T *dataPoints);
static __global__ void rd_reflectivity_calculation_gpu(const emxArray_boolean_T *
  trianglesToRefine, emxArray_boolean_T *b_trianglesToRefine);
static __global__ void re_reflectivity_calculation_gpu(const emxArray_real_T
  *dataPoints, const int32_T kEnd, emxArray_real_T *layers);
static __global__ void rf_reflectivity_calculation_gpu(const real_T *layerThicks,
  const int32_T kEnd, emxArray_real_T *Simul);
static __global__ void rg_reflectivity_calculation_gpu(real_T layers_data[10]);
static __global__ void rh_reflectivity_calculation_gpu(const emxArray_real_T
  *Lays, const int32_T vstride, emxArray_real_T *SLD);
static __global__ void ri_reflectivity_calculation_gpu(const emxArray_real_T
  *firstStep, const int32_T *nx, emxArray_real_T *z1);
static __global__ void rj_reflectivity_calculation_gpu(const emxArray_int32_T
  *r29, const emxArray_real_T *dataPoints, const emxArray_int32_T *r28,
  emxArray_real_T *newDataPoints);
static __global__ void rk_reflectivity_calculation_gpu(const emxArray_real_T
  *simXdata, emxArray_real_T *Simul);
static __global__ void rl_reflectivity_calculation_gpu(const real_T terms_data
  [51], int32_T vlen, real_T *layerThicks);
static __device__ real_T rt_atan2d_snf(real_T u0, real_T u1);
static real_T rt_hypotd_snf(real_T u0, real_T u1);
static __device__ real_T rt_hypotd_snf_device(real_T u0, real_T u1);
static __device__ real_T rt_powd_snf(real_T u0, real_T u1);
static __global__ void s_reflectivity_calculation_gpu_(const struct0_T
  problemDef, const cell_10 *problemDef_cells, real_T thisOutLayer[5]);
static __global__ void sb_reflectivity_calculation_gpu(const real_T *layerThicks,
  const real_T l, const emxArray_real_T *x, emxArray_real_T *a);
static __global__ void sc_reflectivity_calculation_gpu(const int32_T vlen, const
  emxArray_real_T *dataPoints, real_T dataBoxSize[2]);
static __global__ void sd_reflectivity_calculation_gpu(emxArray_boolean_T *r32);
static __global__ void se_reflectivity_calculation_gpu(const cell_10
  *problemDef_cells, const int32_T i, real_T shifted_dat_data[153]);
static __global__ void sf_reflectivity_calculation_gpu(const real_T *layerThicks,
  const real_T shifted_dat_data[153], const int32_T shifted_dat_size[2], const
  int32_T kEnd, real_T terms_data[51]);
static __global__ void sg_reflectivity_calculation_gpu(const real_T
  thisContrastLayers[10], real_T layers_data[10]);
static __global__ void sh_reflectivity_calculation_gpu(const int32_T *xoffset,
  const emxArray_real_T *Lays, const int32_T vstride, emxArray_real_T *SLD);
static __device__ real_T shflDown2(real_T in1, uint32_T offset, uint32_T mask);
static __global__ void si_reflectivity_calculation_gpu(const emxArray_real_T
  *firstStep, const int32_T *nx, emxArray_real_T *z1);
static __global__ void sj_reflectivity_calculation_gpu(const real_T *layerThicks,
  const emxArray_real_T *sldProfile, const int32_T *qEnd, emxArray_boolean_T *x);
static __global__ void sk_reflectivity_calculation_gpu(creal_T MI[4]);
static __global__ void sl_reflectivity_calculation_gpu(const int32_T i,
  emxArray_int8_T *cell6);
static __global__ void t_reflectivity_calculation_gpu_(const cell_10
  *problemDef_cells, real_T thisOutLayer[5]);
static __global__ void tb_reflectivity_calculation_gpu(const real_T bFactor,
  const real_T r, const emxArray_real_T *x, emxArray_real_T *b);
static __global__ void tc_reflectivity_calculation_gpu(const int32_T vlen, const
  emxArray_real_T *dataPoints, real_T minval[2]);
static __global__ void td_reflectivity_calculation_gpu(const emxArray_boolean_T *
  trianglesToRefine, const int32_T *nx, emxArray_boolean_T *r32);
static __global__ void te_reflectivity_calculation_gpu(const real_T bFactor,
  const real_T *layerThicks, const real_T shifts, const cell_10
  *problemDef_cells, const int32_T i, boolean_T x[51], real_T thisData[153]);
static __global__ void tf_reflectivity_calculation_gpu(const real_T terms_data
  [51], const int32_T shifted_dat_size[2], const int32_T ii_size[1], real_T
  shifted_dat_data[153]);
static __global__ void tg_reflectivity_calculation_gpu(const real_T nba, const
  struct0_T problemDef, const int32_T i, const real_T thisContrastLayers[10],
  real_T layers_data[10]);
static __global__ void th_reflectivity_calculation_gpu(const emxArray_real_T
  *Lays, uint32_T sz[2]);
static __device__ real_T threadGroupReduction(real_T val, uint32_T lane,
  uint32_T mask);
static __global__ void ti_reflectivity_calculation_gpu(const emxArray_real_T *z1,
  const emxArray_real_T *b_z1, emxArray_real_T *firstStepSquared);
static __global__ void tj_reflectivity_calculation_gpu(const emxArray_real_T
  *sldProfile, const real_T *layerThicks, const int32_T *qEnd,
  emxArray_boolean_T *x);
static __global__ void tk_reflectivity_calculation_gpu(const real_T l, const
  real_T *layerThicks, const real_T bFactor, const real_T nextLayRough, creal_T
  N[4]);
static __global__ void u_reflectivity_calculation_gpu_(const real_T
  thisOutLayer[5], cell_wrap_2 outParameterisedLayers[4]);
static __global__ void ub_reflectivity_calculation_gpu(const emxArray_real_T *a,
  const int32_T *nx, emxArray_real_T *r4);
static __global__ void uc_reflectivity_calculation_gpu(const real_T minval[2],
  real_T dataBoxSize[2]);
static __global__ void ud_reflectivity_calculation_gpu(const emxArray_boolean_T *
  r32, const emxArray_boolean_T *trianglesToRefine, emxArray_boolean_T
  *segmentsToSplit);
static __global__ void ue_reflectivity_calculation_gpu(const real_T bFactor,
  const real_T thisData[153], boolean_T x[51]);
static __global__ void uf_reflectivity_calculation_gpu(const emxArray_real_T
  *reflect, const real_T shifted_dat_data[153], const int32_T shifted_dat_size[2],
  const int32_T kEnd, emxArray_real_T *z);
static __global__ void ug_reflectivity_calculation_gpu(emxArray_real_T
  *sldProfile);
static __global__ void uh_reflectivity_calculation_gpu(const uint32_T sz[2],
  emxArray_real_T *SLD);
static __global__ void ui_reflectivity_calculation_gpu(const emxArray_real_T
  *secondStep, const int32_T *nx, emxArray_real_T *z1);
static __global__ void uj_reflectivity_calculation_gpu(const emxArray_real_T
  *sldProfile, const real_T *layerThicks, const int32_T *qEnd,
  emxArray_boolean_T *x);
static __global__ void uk_reflectivity_calculation_gpu(const creal_T N[4], const
  creal_T MI[4], creal_T b_MI[4]);
static __global__ void v_reflectivity_calculation_gpu_(const struct0_T
  problemDef, const cell_10 *problemDef_cells, real_T thisOutLayer[5]);
static __global__ void vb_reflectivity_calculation_gpu(const emxArray_real_T *b,
  const int32_T *nx, emxArray_real_T *r5);
static __global__ void vc_reflectivity_calculation_gpu(const int32_T vlen, const
  emxArray_real_T *dataPoints, real_T minval[2]);
static __global__ void vd_reflectivity_calculation_gpu(const int32_T *xoffset,
  emxArray_real_T *newDataPoints);
static __global__ void ve_reflectivity_calculation_gpu(const real_T thisData[153],
  const int32_T shifted_dat_size[2], const int32_T kEnd, const int32_T *qEnd,
  real_T shifted_dat_data[153]);
static __global__ void vf_reflectivity_calculation_gpu(const emxArray_real_T *z,
  const int32_T *nx, emxArray_real_T *z1);
static __global__ void vg_reflectivity_calculation_gpu(const real_T layers_data
  [10], real_T *layerThicks);
static __global__ void vh_reflectivity_calculation_gpu(const emxArray_real_T *x,
  const int32_T *nx, emxArray_real_T *sldProfile);
static __global__ void vi_reflectivity_calculation_gpu(const emxArray_real_T
  *secondStep, const int32_T *nx, emxArray_real_T *z1);
static __global__ void vj_reflectivity_calculation_gpu(const emxArray_real_T
  *sldProfile, const emxArray_int32_T *ii, emxArray_real_T *r31);
static __global__ void vk_reflectivity_calculation_gpu(const creal_T MI[4],
  creal_T b_MI[4]);
static __global__ void w_reflectivity_calculation_gpu_(const cell_10
  *problemDef_cells, real_T thisOutLayer[5]);
static __global__ void wb_reflectivity_calculation_gpu(const emxArray_real_T
  *Lays, int32_T *qEnd);
static __global__ void wc_reflectivity_calculation_gpu(const emxArray_real_T
  *r14, const emxArray_real_T *b, const emxArray_real_T *dataPoints, const
  int32_T kEnd, emxArray_real_T *normalizedData);
static __global__ void wd_reflectivity_calculation_gpu(const emxArray_boolean_T *
  segmentsToSplit, const int32_T *nx, emxArray_boolean_T *r21);
static __global__ void we_reflectivity_calculation_gpu(const real_T reps, const
  real_T *layerThicks, const real_T bFactor, emxArray_real_T *firstSection);
static __global__ void wf_reflectivity_calculation_gpu(const emxArray_real_T *z1,
  real_T terms_data[51]);
static __global__ void wg_reflectivity_calculation_gpu(const real_T *layerThicks,
  emxArray_real_T *x);
static __global__ void wh_reflectivity_calculation_gpu(const emxArray_real_T
  *SLD, const int32_T *nx, emxArray_real_T *sldProfile);
static __global__ void wi_reflectivity_calculation_gpu(const emxArray_real_T *z1,
  const emxArray_real_T *b_z1, emxArray_real_T *secondStepSquared);
static __global__ void wj_reflectivity_calculation_gpu(const emxArray_real_T
  *r18, emxArray_real_T *newDataPoints);
static __global__ void wk_reflectivity_calculation_gpu(const real_T l, const
  real_T bFactor, creal_T N[4]);
static __device__ real_T workGroupReduction(real_T val, uint32_T mask, uint32_T
  numActiveWarps);
static __global__ void x_reflectivity_calculation_gpu_(const real_T
  thisOutLayer[5], cell_wrap_2 outParameterisedLayers[4]);
static __global__ void xb_reflectivity_calculation_gpu(const emxArray_real_T *r5,
  const emxArray_real_T *r4, const real_T *layerThicks, const int32_T *qEnd,
  const int32_T ii_size[1], emxArray_real_T *Lays);
static __global__ void xc_reflectivity_calculation_gpu(const emxArray_real_T
  *normalizedData, const int32_T kEnd, emxArray_real_T *firstStep);
static __global__ void xd_reflectivity_calculation_gpu(const emxArray_boolean_T *
  segmentsToSplit, emxArray_boolean_T *r21);
static __global__ void xe_reflectivity_calculation_gpu(const real_T reps, const
  real_T a, const real_T *layerThicks, emxArray_real_T *lastSection);
static __global__ void xf_reflectivity_calculation_gpu(const emxArray_real_T *z1,
  emxArray_boolean_T *x);
static __global__ void xg_reflectivity_calculation_gpu(const real_T reps, const
  emxArray_real_T *x, emxArray_real_T *Lays);
static __global__ void xh_reflectivity_calculation_gpu(const real_T layers_data
  [10], emxArray_real_T *layers);
static __global__ void xi_reflectivity_calculation_gpu(const emxArray_real_T
  *longStep, const int32_T *nx, emxArray_real_T *z1);
static __global__ void xj_reflectivity_calculation_gpu(const emxArray_real_T
  *dataPoints, emxArray_real_T *b_dataPoints);
static __global__ void xk_reflectivity_calculation_gpu(const real_T l, const
  real_T *layerThicks, const real_T bFactor, const real_T nextLayRough, creal_T
  N[4]);
static __global__ void y_reflectivity_calculation_gpu_(const cell_wrap_2
  outParameterisedLayers[4], const cell_10 *problemDef_cells, const int32_T i,
  real_T thisContrastLayers[10]);
static __global__ void yb_reflectivity_calculation_gpu(const emxArray_real_T
  *Lays, int32_T *qEnd);
static __global__ void yc_reflectivity_calculation_gpu(const emxArray_real_T
  *normalizedData, const int32_T kEnd, emxArray_real_T *secondStep);
static __global__ void yd_reflectivity_calculation_gpu(emxArray_boolean_T *r23);
static __global__ void ye_reflectivity_calculation_gpu(const emxArray_real_T
  *firstSection, const int32_T vstride, emxArray_real_T *simXdata);
static __global__ void yf_reflectivity_calculation_gpu(const emxArray_int8_T *ii,
  real_T terms_data[51]);
static __global__ void yg_reflectivity_calculation_gpu(const real_T *layerThicks,
  const emxArray_real_T *x, emxArray_real_T *a);
static __global__ void yh_reflectivity_calculation_gpu(const real_T dataBoxSize
  [2], real_T y[50]);
static __global__ void yi_reflectivity_calculation_gpu(const emxArray_real_T
  *longStep, const int32_T *nx, emxArray_real_T *z1);
static __global__ void yj_reflectivity_calculation_gpu(const emxArray_real_T
  *dataPoints, emxArray_real_T *b_dataPoints);
static __global__ void yk_reflectivity_calculation_gpu(const real_T l, const
  real_T bFactor, creal_T N[4]);

// Function Definitions
static __global__ __launch_bounds__(160, 1) void ab_reflectivity_calculation_gpu
  (const cell_10 *problemDef_cells, const int32_T i, real_T thisData[153])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 153) {
    //  For the other parameters, we extract the correct ones from the input
    //  arrays
    //  Substrate roughness is always first parameter for standard layers
    thisData[i1] = problemDef_cells->f2[i].f1[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ac_reflectivity_calculation_gpu(const emxArray_real_T *r1, const
  emxArray_real_T *r, const real_T a, const int32_T *qEnd, const int32_T
  ii_size[1], emxArray_real_T *Lays)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(ii_size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    Lays->data[i1 + Lays->size[0] * *qEnd] = a * (r->data[i1] - r1->data[i1]);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ad_reflectivity_calculation_gpu(const emxArray_real_T *normalizedData, const
  int32_T kEnd, emxArray_real_T *longStep)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = (static_cast<int64_T>(kEnd - 2) + 1L) * 2L - 1L;
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    int32_T iv0;
    iv0 = static_cast<int32_T>(idx % (static_cast<uint32_T>(kEnd) - 1U));
    i1 = static_cast<int32_T>((idx - static_cast<uint32_T>(iv0)) / (static_cast<
      uint32_T>(kEnd) - 1U));
    longStep->data[iv0 + longStep->size[0] * i1] = normalizedData->data[(iv0 +
      normalizedData->size[0] * i1) + 2] - normalizedData->data[iv0 +
      normalizedData->size[0] * i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ae_reflectivity_calculation_gpu(const emxArray_boolean_T *segmentsToSplit,
  const int32_T *nx, emxArray_boolean_T *r23)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    r23->data[i1 + 1] = segmentsToSplit->data[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  af_reflectivity_calculation_gpu(const emxArray_real_T *simXdata,
  emxArray_real_T *Simul)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(simXdata->size[0] * 2 - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    Simul->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(32, 1) void ag_reflectivity_calculation_gpu(
  const real_T terms_data[51], real_T *layerThicks)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    *layerThicks = terms_data[0];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ah_reflectivity_calculation_gpu(const real_T bFactor, const emxArray_real_T *x,
  emxArray_real_T *b)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(x->size[0] * x->size[1] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    b->data[i1] = (x->data[i1] - 50.0) / bFactor;
  }
}

static __global__ __launch_bounds__(64, 1) void ai_reflectivity_calculation_gpu(
  const real_T bFactor, const real_T *layerThicks, real_T y[50])
{
  uint32_T threadId;
  int32_T j;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  j = static_cast<int32_T>(threadId);
  if (j < 48) {
    y[j + 1] = *layerThicks + (static_cast<real_T>(j) + 1.0) * bFactor;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  aj_reflectivity_calculation_gpu(const emxArray_real_T *secondStepSquared,
  const emxArray_real_T *firstStepSquared, emxArray_real_T *x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(firstStepSquared->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    x->data[i1] = firstStepSquared->data[i1] * secondStepSquared->data[i1];
  }
}

static __global__ __launch_bounds__(32, 1) void ak_reflectivity_calculation_gpu
  (int8_T col_data[2])
{
  uint32_T threadId;
  int32_T j;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  j = static_cast<int32_T>(threadId);
  if (j < 2) {
    col_data[j] = static_cast<int8_T>(j + 1);
  }
}

static __global__ __launch_bounds__(32, 1) void al_reflectivity_calculation_gpu(
  const real_T l, const real_T *layerThicks, const real_T bFactor, const real_T
  nextLayRough, creal_T N[4])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    N[2].re = nextLayRough * bFactor - *layerThicks * l;
    N[2].im = nextLayRough * l + *layerThicks * bFactor;
  }
}

static __device__ real_T atomicOpreal_T(real_T *address, real_T value)
{
  unsigned long long int *address_as_up;
  unsigned long long int old;
  address_as_up = (unsigned long long int *)address;
  old = *address_as_up;
  unsigned long long int assumed;
  do {
    assumed = old;
    old = atomicCAS(address_as_up, old, __double_as_longlong(value +
      __longlong_as_double(old)));
  } while (assumed != old);

  return __longlong_as_double(old);
}

static __global__ __launch_bounds__(32, 1) void bb_reflectivity_calculation_gpu
  (real_T layers_data[10])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 10) {
    layers_data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  bc_reflectivity_calculation_gpu(const emxArray_real_T *Lays, const int32_T
  vstride, emxArray_real_T *SLD)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(vstride - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    SLD->data[j] = Lays->data[j];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  bd_reflectivity_calculation_gpu(const emxArray_real_T *firstStep, const
  int32_T *nx, emxArray_real_T *z1)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    z1->data[j] = rt_powd_snf(firstStep->data[j], 2.0);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  be_reflectivity_calculation_gpu(const emxArray_int32_T *r27, const
  emxArray_real_T *dataPoints, const emxArray_int32_T *r25, emxArray_real_T
  *newDataPoints)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(r25->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    newDataPoints->data[i1] = 0.5 * (dataPoints->data[r25->data[i1] - 1] +
      dataPoints->data[r27->data[i1] - 1]);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  bf_reflectivity_calculation_gpu(const emxArray_real_T *simXdata,
  emxArray_real_T *Simul)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(simXdata->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    Simul->data[i1] = simXdata->data[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  bg_reflectivity_calculation_gpu(const real_T terms_data[51], int32_T vlen,
  real_T *layerThicks)
{
  uint32_T idx;
  real_T tmpRed0;
  uint32_T threadStride;
  uint32_T threadId;
  uint32_T thBlkId;
  uint32_T blockStride;
  uint32_T m;
  int64_T loopEnd;
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  thBlkId = static_cast<uint32_T>(mwGetThreadIndexWithinBlock());
  blockStride = static_cast<uint32_T>(mwGetThreadsPerBlock());
  tmpRed0 = 0.0;
  loopEnd = static_cast<int64_T>(vlen - 2);
  if (mwIsLastBlock()) {
    m = (static_cast<int64_T>(vlen - 2) + 1L) % static_cast<int64_T>(blockStride);
    if (m > 0U) {
      blockStride = m;
    }
  }

  blockStride = (uint32_T)(blockStride + (static_cast<int64_T>(warpSize) - 1L)) /
    warpSize;
  if (static_cast<int64_T>(threadId) <= loopEnd) {
    tmpRed0 = terms_data[static_cast<int32_T>(threadId) + 1];
  }

  m = __ballot_sync(MAX_uint32_T, static_cast<int64_T>(threadId) <= loopEnd);
  for (idx = threadId + threadStride; idx <= static_cast<uint32_T>(loopEnd); idx
       += threadStride) {
    tmpRed0 += terms_data[static_cast<int32_T>(idx) + 1];
  }

  tmpRed0 = workGroupReduction(tmpRed0, m, blockStride);
  if (thBlkId == 0U) {
    atomicOpreal_T(&layerThicks[0], tmpRed0);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  bh_reflectivity_calculation_gpu(const emxArray_real_T *a, const int32_T *nx,
  emxArray_real_T *r2)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int32_T eint;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    real_T absx;
    int32_T j;
    real_T Q;
    j = static_cast<int32_T>(idx);

    // ========================== COPYRIGHT NOTICE ============================
    //  The algorithms for calculating ERF(X) and ERFC(X) are derived
    //  from FDLIBM, which has the following notice:
    //
    //  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
    //
    //  Developed at SunSoft, a Sun Microsystems, Inc. business.
    //  Permission to use, copy, modify, and distribute this
    //  software is freely granted, provided that this notice
    //  is preserved.
    // =============================    END    ================================
    absx = fabs(a->data[j]);
    if (isnan(a->data[j])) {
      Q = a->data[j];
    } else if (isinf(a->data[j])) {
      if (a->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else if (absx < 0.84375) {
      if (absx < 3.7252902984619141E-9) {
        if (absx < 2.8480945388892178E-306) {
          Q = 0.125 * (8.0 * a->data[j] + 1.0270333367641007 * a->data[j]);
        } else {
          Q = a->data[j] + 0.12837916709551259 * a->data[j];
        }
      } else {
        Q = a->data[j] * a->data[j];
        Q = a->data[j] + a->data[j] * ((Q * (Q * (Q * (Q *
          -2.3763016656650163E-5 + -0.0057702702964894416) +
          -0.02848174957559851) + -0.3250421072470015) + 0.12837916709551256) /
          (Q * (Q * (Q * (Q * (Q * -3.9602282787753681E-6 +
          0.00013249473800432164) + 0.0050813062818757656) + 0.0650222499887673)
                + 0.39791722395915535) + 1.0));
      }
    } else if (absx < 1.25) {
      real_T P;
      P = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * -0.0021663755948687908 + 0.035478304325618236)
        + -0.11089469428239668) + 0.31834661990116175) + -0.37220787603570132) +
                          0.41485611868374833) + -0.0023621185607526594;
      Q = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * 0.011984499846799107 + 0.013637083912029051) +
        0.12617121980876164) + 0.071828654414196266) + 0.540397917702171) +
                          0.10642088040084423) + 1.0;
      if (a->data[j] >= 0.0) {
        Q = P / Q + 0.84506291151046753;
      } else {
        Q = -0.84506291151046753 - P / Q;
      }
    } else if (absx > 6.0) {
      if (a->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else {
      real_T P;
      real_T R;
      int32_T ix;
      Q = 1.0 / (absx * absx);
      if (absx < 2.8571434020996094) {
        R = Q * (Q * (Q * (Q * (Q * (Q * (Q * -9.8143293441691455 +
          -81.2874355063066) + -184.60509290671104) + -162.39666946257347) +
                           -62.375332450326006) + -10.558626225323291) +
                 -0.69385857270718176) + -0.0098649440348471482;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * (Q * -0.0604244152148581 +
          6.5702497703192817) + 108.63500554177944) + 429.00814002756783) +
                    645.38727173326788) + 434.56587747522923) +
                      137.65775414351904) + 19.651271667439257) + 1.0;
      } else {
        R = Q * (Q * (Q * (Q * (Q * (Q * -483.5191916086514 +
          -1025.0951316110772) + -637.56644336838963) + -160.63638485582192) +
                      -17.757954917754752) + -0.799283237680523) +
          -0.0098649429247001;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * -22.440952446585818 +
          474.52854120695537) + 2553.0504064331644) + 3199.8582195085955) +
                           1536.729586084437) + 325.79251299657392) +
                 30.338060743482458) + 1.0;
      }

      if (!static_cast<int32_T>(isnan(absx))) {
        Q = frexp(absx, &eint);
        ix = eint;
      } else {
        Q = absx;
        ix = 0;
      }

      Q = floor(Q * 2.097152E+6) / 2.097152E+6 * rt_powd_snf(2.0,
        static_cast<real_T>(ix));
      Q = exp(-Q * Q - 0.5625) * exp((Q - absx) * (Q + absx) + R / P) / absx;
      if (a->data[j] < 0.0) {
        Q--;
      } else {
        Q = 1.0 - Q;
      }
    }

    r2->data[j] = Q;
  }
}

static __global__ __launch_bounds__(64, 1) void bi_reflectivity_calculation_gpu(
  const real_T bFactor, const real_T l, const real_T *layerThicks, real_T y[50])
{
  uint32_T threadId;
  int32_T j;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  j = static_cast<int32_T>(threadId);
  if (j < 48) {
    y[j + 1] = (*layerThicks + l * (static_cast<real_T>(j) + 1.0)) - bFactor * (
      static_cast<real_T>(j) + 1.0);
  }
}

static __global__ __launch_bounds__(32, 1) void bj_reflectivity_calculation_gpu(
  const emxArray_real_T *x, int32_T *nx)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    *nx = x->size[0];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  bk_reflectivity_calculation_gpu(const emxArray_real_T *dataPoints,
  emxArray_int32_T *idx)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T b_idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(dataPoints->size[0] - 1);
  for (b_idx = threadId; b_idx <= static_cast<uint32_T>(loopEnd); b_idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(b_idx);
    idx->data[i1] = 0;
  }
}

static __global__ __launch_bounds__(32, 1) void bl_reflectivity_calculation_gpu(
  const creal_T N[4], const creal_T MI[4], creal_T b_MI[4])
{
  uint32_T threadId;
  int32_T i1;
  real_T P;
  real_T Q;
  int32_T ix;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  ix = static_cast<int32_T>(threadId % 2U);
  i1 = static_cast<int32_T>((threadId - static_cast<uint32_T>(ix)) / 2U);
  if (i1 < 2) {
    Q = 0.0;
    P = 0.0;
    for (int32_T iv0 = 0; iv0 < 2; iv0++) {
      Q += MI[i1 + (iv0 << 1)].re * N[iv0 + (ix << 1)].re - MI[i1 + (iv0 << 1)].
        im * N[iv0 + (ix << 1)].im;
      P += MI[i1 + (iv0 << 1)].re * N[iv0 + (ix << 1)].im + MI[i1 + (iv0 << 1)].
        im * N[iv0 + (ix << 1)].re;
    }

    b_MI[i1 + (ix << 1)].re = Q;
    b_MI[i1 + (ix << 1)].im = P;
  }
}

static __global__ __launch_bounds__(32, 1) void cb_reflectivity_calculation_gpu(
  const real_T thisContrastLayers[10], real_T layers_data[10])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 10) {
    layers_data[i1] = thisContrastLayers[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  cc_reflectivity_calculation_gpu(const int32_T *xoffset, const emxArray_real_T *
  Lays, const int32_T vstride, emxArray_real_T *SLD)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(vstride - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    SLD->data[j] += Lays->data[*xoffset + j];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  cd_reflectivity_calculation_gpu(const emxArray_real_T *firstStep, const
  int32_T *nx, emxArray_real_T *z1)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    z1->data[j] = rt_powd_snf(firstStep->data[j + firstStep->size[0]], 2.0);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ce_reflectivity_calculation_gpu(const real_T *layerThicks, const
  emxArray_real_T *sldProfile, const int32_T *qEnd, emxArray_boolean_T *x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*qEnd);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    x->data[i1] = (sldProfile->data[i1] == *layerThicks);
  }
}

static __global__ __launch_bounds__(32, 1) void cf_reflectivity_calculation_gpu
  (creal_T MI[4])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    MI[0].re = 1.0;
    MI[0].im = 0.0;
    MI[3].re = 1.0;
    MI[3].im = 0.0;
    MI[2].re = 0.0;
    MI[2].im = 0.0;
    MI[1].re = 0.0;
    MI[1].im = 0.0;
  }
}

static __global__ __launch_bounds__(32, 1) void cg_reflectivity_calculation_gpu
  (real_T thisOutLayer[5])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 5) {
    //  ---end memory allocation---
    //  First we need to allocate the absolute values of the input
    //  parameters to all the layers in the layers list. This only needs
    //  to be done once, and so is done outside the contrasts loop
    // This function takes the list of all layers (in terms of parameter
    // numbers) in layersDetails, and loops through putting in the correct
    // parameter value from the parameter array in each layer.
    thisOutLayer[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ch_reflectivity_calculation_gpu(const emxArray_real_T *b, const int32_T *nx,
  emxArray_real_T *r3)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int32_T eint;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    real_T absx;
    int32_T j;
    real_T Q;
    j = static_cast<int32_T>(idx);

    // ========================== COPYRIGHT NOTICE ============================
    //  The algorithms for calculating ERF(X) and ERFC(X) are derived
    //  from FDLIBM, which has the following notice:
    //
    //  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
    //
    //  Developed at SunSoft, a Sun Microsystems, Inc. business.
    //  Permission to use, copy, modify, and distribute this
    //  software is freely granted, provided that this notice
    //  is preserved.
    // =============================    END    ================================
    absx = fabs(b->data[j]);
    if (isnan(b->data[j])) {
      Q = b->data[j];
    } else if (isinf(b->data[j])) {
      if (b->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else if (absx < 0.84375) {
      if (absx < 3.7252902984619141E-9) {
        if (absx < 2.8480945388892178E-306) {
          Q = 0.125 * (8.0 * b->data[j] + 1.0270333367641007 * b->data[j]);
        } else {
          Q = b->data[j] + 0.12837916709551259 * b->data[j];
        }
      } else {
        Q = b->data[j] * b->data[j];
        Q = b->data[j] + b->data[j] * ((Q * (Q * (Q * (Q *
          -2.3763016656650163E-5 + -0.0057702702964894416) +
          -0.02848174957559851) + -0.3250421072470015) + 0.12837916709551256) /
          (Q * (Q * (Q * (Q * (Q * -3.9602282787753681E-6 +
          0.00013249473800432164) + 0.0050813062818757656) + 0.0650222499887673)
                + 0.39791722395915535) + 1.0));
      }
    } else if (absx < 1.25) {
      real_T P;
      P = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * -0.0021663755948687908 + 0.035478304325618236)
        + -0.11089469428239668) + 0.31834661990116175) + -0.37220787603570132) +
                          0.41485611868374833) + -0.0023621185607526594;
      Q = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * 0.011984499846799107 + 0.013637083912029051) +
        0.12617121980876164) + 0.071828654414196266) + 0.540397917702171) +
                          0.10642088040084423) + 1.0;
      if (b->data[j] >= 0.0) {
        Q = P / Q + 0.84506291151046753;
      } else {
        Q = -0.84506291151046753 - P / Q;
      }
    } else if (absx > 6.0) {
      if (b->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else {
      real_T P;
      real_T R;
      int32_T ix;
      Q = 1.0 / (absx * absx);
      if (absx < 2.8571434020996094) {
        R = Q * (Q * (Q * (Q * (Q * (Q * (Q * -9.8143293441691455 +
          -81.2874355063066) + -184.60509290671104) + -162.39666946257347) +
                           -62.375332450326006) + -10.558626225323291) +
                 -0.69385857270718176) + -0.0098649440348471482;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * (Q * -0.0604244152148581 +
          6.5702497703192817) + 108.63500554177944) + 429.00814002756783) +
                    645.38727173326788) + 434.56587747522923) +
                      137.65775414351904) + 19.651271667439257) + 1.0;
      } else {
        R = Q * (Q * (Q * (Q * (Q * (Q * -483.5191916086514 +
          -1025.0951316110772) + -637.56644336838963) + -160.63638485582192) +
                      -17.757954917754752) + -0.799283237680523) +
          -0.0098649429247001;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * -22.440952446585818 +
          474.52854120695537) + 2553.0504064331644) + 3199.8582195085955) +
                           1536.729586084437) + 325.79251299657392) +
                 30.338060743482458) + 1.0;
      }

      if (!static_cast<int32_T>(isnan(absx))) {
        Q = frexp(absx, &eint);
        ix = eint;
      } else {
        Q = absx;
        ix = 0;
      }

      Q = floor(Q * 2.097152E+6) / 2.097152E+6 * rt_powd_snf(2.0,
        static_cast<real_T>(ix));
      Q = exp(-Q * Q - 0.5625) * exp((Q - absx) * (Q + absx) + R / P) / absx;
      if (b->data[j] < 0.0) {
        Q--;
      } else {
        Q = 1.0 - Q;
      }
    }

    r3->data[j] = Q;
  }
}

static void checkCudaError(cudaError_t errCode, const char * file, uint32_T line)
{
  emlrtRTEInfo rtInfo;
  char_T *pn;
  char_T *fn;
  char_T *brk;
  if (errCode != cudaSuccess) {
    uint32_T len;
    len = strlen(file);
    pn = (char_T *)calloc(len + 1U, 1U);
    fn = (char_T *)calloc(len + 1U, 1U);
    memcpy(pn, file, len);
    memcpy(fn, file, len);
    brk = strrchr(fn, '.');
    *brk = '\x00';
    brk = strrchr(fn, '/');
    if (brk == NULL) {
      brk = strrchr(fn, '\\');
    }

    if (brk == NULL) {
      brk = fn;
    } else {
      brk++;
    }

    rtInfo.lineNo = static_cast<int32_T>(line);
    rtInfo.colNo = 0;
    rtInfo.fName = brk;
    rtInfo.pName = pn;
    emlrtCUDAError(errCode, cudaGetErrorName(errCode), cudaGetErrorString
                   (errCode), &rtInfo, emlrtRootTLSGlobal);
  }
}

static __global__ __launch_bounds__(64, 1) void ci_reflectivity_calculation_gpu(
  const real_T dataBoxSize[2], real_T y[50])
{
  uint32_T threadId;
  int32_T j;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  j = static_cast<int32_T>(threadId);
  if (j < 48) {
    y[j + 1] = dataBoxSize[1] * ((2.0 * (static_cast<real_T>(j) + 2.0) - 51.0) /
      49.0);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  cj_reflectivity_calculation_gpu(const int32_T *nx, emxArray_real_T *x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    x->data[j] = sqrt(x->data[j]);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ck_reflectivity_calculation_gpu(const int8_T col_data[2], const
  emxArray_real_T *dataPoints, const int32_T kEnd, emxArray_int32_T *idx)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T b_idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>((kEnd - 1) / 2);
  for (b_idx = threadId; b_idx <= static_cast<uint32_T>(loopEnd); b_idx +=
       threadStride) {
    int32_T j;
    boolean_T xneg;
    int32_T ix;
    boolean_T exitg1;
    j = static_cast<int32_T>(b_idx);
    j = (j << 1) + 1;
    xneg = true;
    ix = 1;
    exitg1 = false;
    while ((!static_cast<int32_T>(exitg1)) && (static_cast<int32_T>(ix < 3))) {
      real_T P;
      real_T Q;
      P = dataPoints->data[(j + dataPoints->size[0] * (static_cast<int32_T>
        (col_data[ix - 1]) - 1)) - 1];
      Q = dataPoints->data[j + dataPoints->size[0] * (static_cast<int32_T>
        (col_data[ix - 1]) - 1)];
      if ((static_cast<int32_T>(P == Q)) || (static_cast<int32_T>
           ((static_cast<int32_T>(isnan(P))) && (static_cast<int32_T>(isnan(Q))))))
      {
        ix++;
      } else {
        if ((!static_cast<int32_T>(P <= Q)) && (!static_cast<int32_T>(isnan(Q))))
        {
          xneg = false;
        }

        exitg1 = true;
      }
    }

    if (xneg) {
      idx->data[j - 1] = j;
      idx->data[j] = j + 1;
    } else {
      idx->data[j - 1] = j + 1;
      idx->data[j] = j;
    }
  }
}

static __global__ __launch_bounds__(32, 1) void cl_reflectivity_calculation_gpu(
  const creal_T MI[4], creal_T b_MI[4])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 4) {
    b_MI[i1] = MI[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  d_reflectivity_calculation_gpu_(const struct0_T problemDef, emxArray_real_T
  *backgs)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(static_cast<int32_T>
    (problemDef.numberOfContrasts) - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    backgs->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(32, 1) void db_reflectivity_calculation_gpu(
  const real_T nba, const struct0_T problemDef, const int32_T i, const real_T
  thisContrastLayers[10], real_T layers_data[10])
{
  uint32_T threadId;
  int32_T j;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  j = static_cast<int32_T>(threadId);
  if ((static_cast<int32_T>(j < 2)) && (!static_cast<int32_T>(isnan
        (thisContrastLayers[j + 6])))) {
    real_T b_thisContrastLayers;
    if (thisContrastLayers[j + 8] == 1.0) {
      b_thisContrastLayers = problemDef.nbs[static_cast<int32_T>
        (problemDef.contrastNbss[i]) - 1];
    } else {
      b_thisContrastLayers = nba;
    }

    layers_data[j + 2] = b_thisContrastLayers * (thisContrastLayers[j + 6] /
      100.0) + (1.0 - thisContrastLayers[j + 6] / 100.0) * layers_data[j + 2];
  }
}

static __global__ __launch_bounds__(32, 1) void dc_reflectivity_calculation_gpu(
  const emxArray_real_T *Lays, uint32_T sz[2])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 2) {
    sz[i1] = static_cast<uint32_T>(Lays->size[i1]);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  dd_reflectivity_calculation_gpu(const emxArray_real_T *z1, const
  emxArray_real_T *b_z1, emxArray_real_T *firstStepSquared)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(b_z1->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    firstStepSquared->data[i1] = b_z1->data[i1] + z1->data[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  de_reflectivity_calculation_gpu(const emxArray_real_T *sldProfile, const
  real_T *layerThicks, const int32_T *qEnd, emxArray_boolean_T *x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*qEnd);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    x->data[i1] = (*layerThicks > sldProfile->data[i1]);
  }
}

static __global__ __launch_bounds__(32, 1) void df_reflectivity_calculation_gpu(
  const real_T l, const real_T *layerThicks, const real_T bFactor, const real_T
  nextLayRough, creal_T N[4])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    N[2].re = nextLayRough * bFactor - *layerThicks * l;
    N[2].im = nextLayRough * l + *layerThicks * bFactor;
  }
}

static __global__ __launch_bounds__(32, 1) void dg_reflectivity_calculation_gpu(
  const struct0_T problemDef, const cell_10 *problemDef_cells, real_T
  thisOutLayer[5])
{
  uint32_T threadId;
  int32_T ix;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  ix = static_cast<int32_T>(threadId);
  if (ix < 4) {
    if (!static_cast<int32_T>(isnan(problemDef_cells->f6[0].f1[ix]))) {
      thisOutLayer[ix] = problemDef.params[static_cast<int32_T>
        (problemDef_cells->f6[0].f1[ix]) - 1];
    } else {
      thisOutLayer[ix] = CUDART_NAN;
    }
  }
}

static __global__ __launch_bounds__(1024, 1) void
  dh_reflectivity_calculation_gpu(const real_T *layerThicks, const real_T l,
  const emxArray_real_T *x, emxArray_real_T *a)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(x->size[0] * x->size[1] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    a->data[i1] = (x->data[i1] - l) / *layerThicks;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  di_reflectivity_calculation_gpu(const real_T *layerThicks, const
  emxArray_real_T *sldProfile, const int32_T kEnd, emxArray_boolean_T *x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(kEnd);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    x->data[i1] = (sldProfile->data[i1] == *layerThicks);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  dj_reflectivity_calculation_gpu(const emxArray_real_T *x, const
  emxArray_real_T *z1, const emxArray_real_T *b_z1, const emxArray_real_T
  *secondStepSquared, const emxArray_real_T *firstStepSquared, emxArray_creal_T *
  b_x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  real_T Q;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(firstStepSquared->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    Q = ((firstStepSquared->data[i1] + secondStepSquared->data[i1]) -
         (b_z1->data[i1] + z1->data[i1])) / 2.0;
    Q /= x->data[i1];
    b_x->data[i1].re = Q;
    b_x->data[i1].im = 0.0;
  }
}

static __global__ __launch_bounds__(32, 1) void dk_reflectivity_calculation_gpu(
  const emxArray_real_T *dataPoints, emxArray_int32_T *idx)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    idx->data[dataPoints->size[0] - 1] = dataPoints->size[0];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  dl_reflectivity_calculation_gpu(const emxArray_real_T *simXdata,
  emxArray_real_T *dummydata)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(simXdata->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    dummydata->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  e_reflectivity_calculation_gpu_(const struct0_T problemDef, emxArray_real_T
  *qshifts)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(static_cast<int32_T>
    (problemDef.numberOfContrasts) - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    qshifts->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(32, 1) void eb_reflectivity_calculation_gpu
  (emxArray_real_T *sldProfile)
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 3) {
    sldProfile->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ec_reflectivity_calculation_gpu(const uint32_T sz[2], emxArray_real_T *SLD)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(static_cast<int32_T>(sz[0]) - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    SLD->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ed_reflectivity_calculation_gpu(const emxArray_real_T *secondStep, const
  int32_T *nx, emxArray_real_T *z1)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    z1->data[j] = rt_powd_snf(secondStep->data[j], 2.0);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ee_reflectivity_calculation_gpu(const emxArray_real_T *sldProfile, const
  real_T *layerThicks, const int32_T *qEnd, emxArray_boolean_T *x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*qEnd);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    x->data[i1] = (*layerThicks < sldProfile->data[i1]);
  }
}

static __global__ __launch_bounds__(32, 1) void ef_reflectivity_calculation_gpu(
  const creal_T N[4], const creal_T MI[4], creal_T b_MI[4])
{
  uint32_T threadId;
  int32_T i1;
  real_T P;
  real_T Q;
  int32_T ix;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  ix = static_cast<int32_T>(threadId % 2U);
  i1 = static_cast<int32_T>((threadId - static_cast<uint32_T>(ix)) / 2U);
  if (i1 < 2) {
    Q = 0.0;
    P = 0.0;
    for (int32_T iv0 = 0; iv0 < 2; iv0++) {
      Q += MI[i1 + (iv0 << 1)].re * N[iv0 + (ix << 1)].re - MI[i1 + (iv0 << 1)].
        im * N[iv0 + (ix << 1)].im;
      P += MI[i1 + (iv0 << 1)].re * N[iv0 + (ix << 1)].im + MI[i1 + (iv0 << 1)].
        im * N[iv0 + (ix << 1)].re;
    }

    b_MI[i1 + (ix << 1)].re = Q;
    b_MI[i1 + (ix << 1)].im = P;
  }
}

static __global__ __launch_bounds__(32, 1) void eg_reflectivity_calculation_gpu(
  const cell_10 *problemDef_cells, real_T thisOutLayer[5])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    thisOutLayer[4] = problemDef_cells->f6[0].f1[4];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  eh_reflectivity_calculation_gpu(const real_T bFactor, const real_T r, const
  emxArray_real_T *x, emxArray_real_T *b)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(x->size[0] * x->size[1] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    b->data[i1] = (x->data[i1] - r) / bFactor;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ei_reflectivity_calculation_gpu(const emxArray_real_T *sldProfile, const
  real_T *layerThicks, const int32_T kEnd, emxArray_boolean_T *x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(kEnd);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    x->data[i1] = (*layerThicks > sldProfile->data[i1]);
  }
}

static __global__ __launch_bounds__(32, 1) void ej_reflectivity_calculation_gpu(
  const emxArray_creal_T *x, int32_T *nx)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    *nx = x->size[0];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ek_reflectivity_calculation_gpu(const int32_T j, const emxArray_real_T
  *dataPoints, const emxArray_int32_T *idx, const int32_T *xoffset,
  emxArray_real_T *ycol)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T b_idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*xoffset - 1);
  for (b_idx = threadId; b_idx <= static_cast<uint32_T>(loopEnd); b_idx +=
       threadStride) {
    int32_T i;
    i = static_cast<int32_T>(b_idx);
    ycol->data[i] = dataPoints->data[(idx->data[i] + dataPoints->size[0] * j) -
      1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  el_reflectivity_calculation_gpu(const emxArray_real_T *simRef, const struct0_T
  problemDef, const emxArray_real_T *simXdata, const int32_T *xoffset, const
  int32_T kEnd, emxArray_real_T *dummydata)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  real_T P;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(kEnd - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    int32_T iv0;
    int32_T b_j;
    j = static_cast<int32_T>(idx);
    P = 0.0;
    dummydata->data[j] = 0.0;
    if (j + 1 > 10) {
      iv0 = -10;
    } else {
      iv0 = -j;
    }

    //     try
    if (j + 1 < *xoffset - 10) {
      b_j = 10;
    } else {
      b_j = (*xoffset - j) - 1;
    }

    b_j = (b_j - iv0) + 1;
    for (int32_T ix = 0; ix < b_j; ix++) {
      int32_T i;
      real_T Q;
      i = iv0 + ix;
      Q = (simXdata->data[j + i] - simXdata->data[j]) / ((problemDef.res +
        0.0001) * simXdata->data[j]);
      Q = exp(-(Q * Q));
      P += Q;
      dummydata->data[j] += simRef->data[i + j] * Q;
    }

    if (P != 0.0) {
      dummydata->data[j] /= P;
    }

    //      catch
    //          disp('debug!');
    //      end
  }
}

static __global__ __launch_bounds__(1024, 1) void
  f_reflectivity_calculation_gpu_(const struct0_T problemDef, emxArray_real_T
  *sfs)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(static_cast<int32_T>
    (problemDef.numberOfContrasts) - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    sfs->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(32, 1) void fb_reflectivity_calculation_gpu(
  const real_T layers_data[10], real_T *layerThicks)
{
  uint32_T idx;
  real_T tmpRed0;
  uint32_T threadStride;
  uint32_T threadId;
  uint32_T thBlkId;
  uint32_T mask;
  uint32_T blockStride;
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  thBlkId = static_cast<uint32_T>(mwGetThreadIndexWithinBlock());
  blockStride = static_cast<uint32_T>(mwGetThreadsPerBlock());
  tmpRed0 = 0.0;
  if (mwIsLastBlock()) {
    int32_T m;
    m = static_cast<int32_T>(1U % blockStride);
    if (static_cast<uint32_T>(m) > 0U) {
      blockStride = 1U;
    }
  }

  blockStride = ((blockStride + warpSize) - 1U) / warpSize;
  if (threadId <= 0U) {
    tmpRed0 = layers_data[1];
  }

  mask = __ballot_sync(MAX_uint32_T, threadId <= 0U);
  for (idx = threadId + threadStride; idx <= 0U; idx += threadStride) {
    tmpRed0 += layers_data[1];
  }

  tmpRed0 = workGroupReduction(tmpRed0, mask, blockStride);
  if (thBlkId == 0U) {
    atomicOpreal_T(&layerThicks[0], tmpRed0);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  fc_reflectivity_calculation_gpu(const emxArray_real_T *x, const int32_T *nx,
  emxArray_real_T *sldProfile)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    sldProfile->data[i1] = x->data[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  fd_reflectivity_calculation_gpu(const emxArray_real_T *secondStep, const
  int32_T *nx, emxArray_real_T *z1)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    z1->data[j] = rt_powd_snf(secondStep->data[j + secondStep->size[0]], 2.0);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  fe_reflectivity_calculation_gpu(const emxArray_real_T *sldProfile, const
  emxArray_int32_T *ii, emxArray_real_T *r30)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(ii->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    r30->data[i1] = sldProfile->data[(ii->data[i1] + sldProfile->size[0]) - 1];
  }
}

static __global__ __launch_bounds__(32, 1) void ff_reflectivity_calculation_gpu(
  const creal_T MI[4], creal_T b_MI[4])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 4) {
    b_MI[i1] = MI[i1];
  }
}

static __global__ __launch_bounds__(32, 1) void fg_reflectivity_calculation_gpu(
  const real_T thisOutLayer[5], cell_wrap_2 outParameterisedLayers[4])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 5) {
    outParameterisedLayers[0].f1[i1] = thisOutLayer[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  fh_reflectivity_calculation_gpu(const emxArray_real_T *a, const int32_T *nx,
  emxArray_real_T *r10)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int32_T eint;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    real_T absx;
    int32_T j;
    real_T Q;
    j = static_cast<int32_T>(idx);

    // ========================== COPYRIGHT NOTICE ============================
    //  The algorithms for calculating ERF(X) and ERFC(X) are derived
    //  from FDLIBM, which has the following notice:
    //
    //  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
    //
    //  Developed at SunSoft, a Sun Microsystems, Inc. business.
    //  Permission to use, copy, modify, and distribute this
    //  software is freely granted, provided that this notice
    //  is preserved.
    // =============================    END    ================================
    absx = fabs(a->data[j]);
    if (isnan(a->data[j])) {
      Q = a->data[j];
    } else if (isinf(a->data[j])) {
      if (a->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else if (absx < 0.84375) {
      if (absx < 3.7252902984619141E-9) {
        if (absx < 2.8480945388892178E-306) {
          Q = 0.125 * (8.0 * a->data[j] + 1.0270333367641007 * a->data[j]);
        } else {
          Q = a->data[j] + 0.12837916709551259 * a->data[j];
        }
      } else {
        Q = a->data[j] * a->data[j];
        Q = a->data[j] + a->data[j] * ((Q * (Q * (Q * (Q *
          -2.3763016656650163E-5 + -0.0057702702964894416) +
          -0.02848174957559851) + -0.3250421072470015) + 0.12837916709551256) /
          (Q * (Q * (Q * (Q * (Q * -3.9602282787753681E-6 +
          0.00013249473800432164) + 0.0050813062818757656) + 0.0650222499887673)
                + 0.39791722395915535) + 1.0));
      }
    } else if (absx < 1.25) {
      real_T P;
      P = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * -0.0021663755948687908 + 0.035478304325618236)
        + -0.11089469428239668) + 0.31834661990116175) + -0.37220787603570132) +
                          0.41485611868374833) + -0.0023621185607526594;
      Q = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * 0.011984499846799107 + 0.013637083912029051) +
        0.12617121980876164) + 0.071828654414196266) + 0.540397917702171) +
                          0.10642088040084423) + 1.0;
      if (a->data[j] >= 0.0) {
        Q = P / Q + 0.84506291151046753;
      } else {
        Q = -0.84506291151046753 - P / Q;
      }
    } else if (absx > 6.0) {
      if (a->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else {
      real_T P;
      real_T R;
      int32_T ix;
      Q = 1.0 / (absx * absx);
      if (absx < 2.8571434020996094) {
        R = Q * (Q * (Q * (Q * (Q * (Q * (Q * -9.8143293441691455 +
          -81.2874355063066) + -184.60509290671104) + -162.39666946257347) +
                           -62.375332450326006) + -10.558626225323291) +
                 -0.69385857270718176) + -0.0098649440348471482;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * (Q * -0.0604244152148581 +
          6.5702497703192817) + 108.63500554177944) + 429.00814002756783) +
                    645.38727173326788) + 434.56587747522923) +
                      137.65775414351904) + 19.651271667439257) + 1.0;
      } else {
        R = Q * (Q * (Q * (Q * (Q * (Q * -483.5191916086514 +
          -1025.0951316110772) + -637.56644336838963) + -160.63638485582192) +
                      -17.757954917754752) + -0.799283237680523) +
          -0.0098649429247001;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * -22.440952446585818 +
          474.52854120695537) + 2553.0504064331644) + 3199.8582195085955) +
                           1536.729586084437) + 325.79251299657392) +
                 30.338060743482458) + 1.0;
      }

      if (!static_cast<int32_T>(isnan(absx))) {
        Q = frexp(absx, &eint);
        ix = eint;
      } else {
        Q = absx;
        ix = 0;
      }

      Q = floor(Q * 2.097152E+6) / 2.097152E+6 * rt_powd_snf(2.0,
        static_cast<real_T>(ix));
      Q = exp(-Q * Q - 0.5625) * exp((Q - absx) * (Q + absx) + R / P) / absx;
      if (a->data[j] < 0.0) {
        Q--;
      } else {
        Q = 1.0 - Q;
      }
    }

    r10->data[j] = Q;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  fi_reflectivity_calculation_gpu(const emxArray_real_T *sldProfile, const
  real_T *layerThicks, const int32_T kEnd, emxArray_boolean_T *x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(kEnd);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    x->data[i1] = (*layerThicks < sldProfile->data[i1]);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  fj_reflectivity_calculation_gpu(const int32_T *nx, emxArray_creal_T *x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  creal_T u;
  real_T P;
  real_T Q;
  real_T ci;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    if ((static_cast<int32_T>(x->data[j].im == 0.0)) && (!static_cast<int32_T>
         (fabs(x->data[j].re) > 1.0))) {
      u.re = acos(x->data[j].re);
      u.im = 0.0;
    } else {
      real_T yr;
      real_T yi;
      real_T b_yr;
      real_T b_yi;
      boolean_T xneg;
      u.re = x->data[j].re + 1.0;
      u.im = x->data[j].im;
      if (u.im == 0.0) {
        if (u.re < 0.0) {
          yr = 0.0;
          yi = sqrt(-u.re);
        } else {
          yr = sqrt(u.re);
          yi = 0.0;
        }
      } else if (u.re == 0.0) {
        if (u.im < 0.0) {
          yr = sqrt(-u.im / 2.0);
          yi = -yr;
        } else {
          yr = sqrt(u.im / 2.0);
          yi = yr;
        }
      } else if (isnan(u.re)) {
        yr = u.re;
        yi = u.re;
      } else if (isnan(u.im)) {
        yr = u.im;
        yi = u.im;
      } else if (isinf(u.im)) {
        yr = fabs(u.im);
        yi = u.im;
      } else if (isinf(u.re)) {
        if (u.re < 0.0) {
          yr = 0.0;
          yi = u.im * -u.re;
        } else {
          yr = u.re;
          yi = 0.0;
        }
      } else {
        P = fabs(u.re);
        Q = fabs(u.im);
        if ((static_cast<int32_T>(P > 4.4942328371557893E+307)) || (static_cast<
             int32_T>(Q > 4.4942328371557893E+307))) {
          P *= 0.5;
          Q *= 0.5;
          Q = rt_hypotd_snf_device(P, Q);
          if (Q > P) {
            yr = sqrt(Q) * sqrt(P / Q + 1.0);
          } else {
            yr = sqrt(Q) * 1.4142135623730951;
          }
        } else {
          yr = sqrt((rt_hypotd_snf_device(P, Q) + P) * 0.5);
        }

        if (u.re > 0.0) {
          yi = 0.5 * (u.im / yr);
        } else {
          if (u.im < 0.0) {
            yi = -yr;
          } else {
            yi = yr;
          }

          yr = 0.5 * (u.im / yi);
        }
      }

      u.re = 1.0 - x->data[j].re;
      u.im = 0.0 - x->data[j].im;
      if (u.im == 0.0) {
        if (u.re < 0.0) {
          b_yr = 0.0;
          b_yi = sqrt(-u.re);
        } else {
          b_yr = sqrt(u.re);
          b_yi = 0.0;
        }
      } else if (u.re == 0.0) {
        if (u.im < 0.0) {
          b_yr = sqrt(-u.im / 2.0);
          b_yi = -b_yr;
        } else {
          b_yr = sqrt(u.im / 2.0);
          b_yi = b_yr;
        }
      } else if (isnan(u.re)) {
        b_yr = u.re;
        b_yi = u.re;
      } else if (isnan(u.im)) {
        b_yr = u.im;
        b_yi = u.im;
      } else if (isinf(u.im)) {
        b_yr = fabs(u.im);
        b_yi = u.im;
      } else if (isinf(u.re)) {
        if (u.re < 0.0) {
          b_yr = 0.0;
          b_yi = u.im * -u.re;
        } else {
          b_yr = u.re;
          b_yi = 0.0;
        }
      } else {
        P = fabs(u.re);
        Q = fabs(u.im);
        if ((static_cast<int32_T>(P > 4.4942328371557893E+307)) || (static_cast<
             int32_T>(Q > 4.4942328371557893E+307))) {
          P *= 0.5;
          Q *= 0.5;
          Q = rt_hypotd_snf_device(P, Q);
          if (Q > P) {
            b_yr = sqrt(Q) * sqrt(P / Q + 1.0);
          } else {
            b_yr = sqrt(Q) * 1.4142135623730951;
          }
        } else {
          b_yr = sqrt((rt_hypotd_snf_device(P, Q) + P) * 0.5);
        }

        if (u.re > 0.0) {
          b_yi = 0.5 * (u.im / b_yr);
        } else {
          if (u.im < 0.0) {
            b_yi = -b_yr;
          } else {
            b_yi = b_yr;
          }

          b_yr = 0.5 * (u.im / b_yi);
        }
      }

      if ((static_cast<int32_T>(-yi == 0.0)) && (static_cast<int32_T>(b_yi ==
            0.0))) {
        ci = 0.0;
      } else {
        ci = yr * b_yi + -yi * b_yr;
        if ((static_cast<int32_T>((static_cast<int32_T>((static_cast<int32_T>((
                   static_cast<int32_T>((static_cast<int32_T>(isinf(ci))) || (
                     static_cast<int32_T>(isnan(ci))))) && (!static_cast<int32_T>
                   (isnan(yr))))) && (!static_cast<int32_T>(isnan(-yi))))) && (!
               static_cast<int32_T>(isnan(b_yr))))) && (!static_cast<int32_T>
             (isnan(b_yi)))) {
          real_T absre;
          real_T R;
          real_T sar;
          real_T sai;
          real_T absx;
          absre = fabs(yr);
          R = fabs(-yi);
          if (absre > R) {
            if (yr < 0.0) {
              sar = -1.0;
            } else {
              sar = 1.0;
            }

            sai = -yi / absre;
          } else if (R > absre) {
            sar = yr / R;
            if (-yi < 0.0) {
              sai = -1.0;
            } else {
              sai = 1.0;
            }

            absre = R;
          } else {
            if (yr < 0.0) {
              sar = -1.0;
            } else {
              sar = 1.0;
            }

            if (-yi < 0.0) {
              sai = -1.0;
            } else {
              sai = 1.0;
            }
          }

          absx = fabs(b_yr);
          R = fabs(b_yi);
          if (absx > R) {
            if (b_yr < 0.0) {
              P = -1.0;
            } else {
              P = 1.0;
            }

            Q = b_yi / absx;
          } else if (R > absx) {
            P = b_yr / R;
            if (b_yi < 0.0) {
              Q = -1.0;
            } else {
              Q = 1.0;
            }

            absx = R;
          } else {
            if (b_yr < 0.0) {
              P = -1.0;
            } else {
              P = 1.0;
            }

            if (b_yi < 0.0) {
              Q = -1.0;
            } else {
              Q = 1.0;
            }
          }

          if ((static_cast<int32_T>((!static_cast<int32_T>(isinf(absre))) && (!
                 static_cast<int32_T>(isnan(absre))))) && (static_cast<int32_T>
               ((!static_cast<int32_T>(isinf(absx))) && (!static_cast<int32_T>
                 (isnan(absx)))))) {
            xneg = true;
          } else {
            xneg = false;
          }

          if ((static_cast<int32_T>(isnan(ci))) || (static_cast<int32_T>((
                 static_cast<int32_T>(isinf(ci))) && (static_cast<int32_T>(xneg)))))
          {
            ci = sar * Q + sai * P;
            if (ci != 0.0) {
              ci = ci * absre * absx;
            } else {
              if ((static_cast<int32_T>((static_cast<int32_T>(isinf(absre))) &&
                    (static_cast<int32_T>((static_cast<int32_T>(b_yr == 0.0)) ||
                      (static_cast<int32_T>(b_yi == 0.0)))))) ||
                  (static_cast<int32_T>((static_cast<int32_T>(isinf(absx))) && (
                     static_cast<int32_T>((static_cast<int32_T>(yr == 0.0)) || (
                       static_cast<int32_T>(-yi == 0.0))))))) {
                P = yr * b_yi;
                Q = -yi * b_yr;
                if (isnan(P)) {
                  P = 0.0;
                }

                if (isnan(Q)) {
                  Q = 0.0;
                }

                ci = P + Q;
              }
            }
          }
        }
      }

      xneg = (ci < 0.0);
      if (xneg) {
        ci = -ci;
      }

      if (ci >= 2.68435456E+8) {
        ci = log(ci) + 0.69314718055994529;
      } else if (ci > 2.0) {
        ci = log(2.0 * ci + 1.0 / (sqrt(ci * ci + 1.0) + ci));
      } else {
        Q = ci * ci;
        ci += Q / (sqrt(Q + 1.0) + 1.0);
        Q = fabs(ci);
        if ((static_cast<int32_T>(Q > 4.503599627370496E+15)) ||
            (static_cast<int32_T>((static_cast<int32_T>(isinf(ci))) || (
               static_cast<int32_T>(isnan(ci)))))) {
          ci = log(ci + 1.0);
        } else {
          if (!static_cast<int32_T>(Q < 2.2204460492503131E-16)) {
            ci = log(ci + 1.0) * (ci / ((ci + 1.0) - 1.0));
          }
        }
      }

      if (xneg) {
        ci = -ci;
      }

      u.re = 2.0 * rt_atan2d_snf(b_yr, yr);
      u.im = ci;
    }

    x->data[j] = u;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  fk_reflectivity_calculation_gpu(const emxArray_real_T *ycol, const int32_T j,
  const int32_T *xoffset, emxArray_real_T *dataPoints)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*xoffset - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i;
    i = static_cast<int32_T>(idx);
    dataPoints->data[i + dataPoints->size[0] * j] = ycol->data[i];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  fl_reflectivity_calculation_gpu(const emxArray_real_T *dummydata,
  emxArray_real_T *Simul)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(dummydata->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    Simul->data[i1 + Simul->size[0]] = dummydata->data[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  g_reflectivity_calculation_gpu_(const struct0_T problemDef, emxArray_real_T
  *nbas)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(static_cast<int32_T>
    (problemDef.numberOfContrasts) - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    nbas->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  gb_reflectivity_calculation_gpu(const real_T *layerThicks, emxArray_real_T *x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(static_cast<int32_T>(*layerThicks));
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    x->data[i1] = static_cast<real_T>(i1);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  gc_reflectivity_calculation_gpu(const emxArray_real_T *SLD, const int32_T *nx,
  emxArray_real_T *sldProfile)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    sldProfile->data[i1 + sldProfile->size[0]] = SLD->data[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  gd_reflectivity_calculation_gpu(const emxArray_real_T *z1, const
  emxArray_real_T *b_z1, emxArray_real_T *secondStepSquared)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(b_z1->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    secondStepSquared->data[i1] = b_z1->data[i1] + z1->data[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ge_reflectivity_calculation_gpu(const emxArray_real_T *r16, emxArray_real_T
  *newDataPoints)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());

  // end
  loopEnd = static_cast<int64_T>(r16->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    newDataPoints->data[i1 + newDataPoints->size[0]] = r16->data[i1];
  }
}

static __global__ __launch_bounds__(32, 1) void gf_reflectivity_calculation_gpu(
  const real_T l, const real_T bFactor, creal_T N[4])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    N[0].re = bFactor;
    N[0].im = l;
  }
}

static __global__ __launch_bounds__(32, 1) void gg_reflectivity_calculation_gpu(
  const struct0_T problemDef, const cell_10 *problemDef_cells, real_T
  thisOutLayer[5])
{
  uint32_T threadId;
  int32_T ix;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  ix = static_cast<int32_T>(threadId);
  if (ix < 4) {
    if (!static_cast<int32_T>(isnan(problemDef_cells->f6[1].f1[ix]))) {
      thisOutLayer[ix] = problemDef.params[static_cast<int32_T>
        (problemDef_cells->f6[1].f1[ix]) - 1];
    } else {
      thisOutLayer[ix] = CUDART_NAN;
    }
  }
}

static __global__ __launch_bounds__(1024, 1) void
  gh_reflectivity_calculation_gpu(const emxArray_real_T *b, const int32_T *nx,
  emxArray_real_T *r12)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int32_T eint;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    real_T absx;
    int32_T j;
    real_T Q;
    j = static_cast<int32_T>(idx);

    // ========================== COPYRIGHT NOTICE ============================
    //  The algorithms for calculating ERF(X) and ERFC(X) are derived
    //  from FDLIBM, which has the following notice:
    //
    //  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
    //
    //  Developed at SunSoft, a Sun Microsystems, Inc. business.
    //  Permission to use, copy, modify, and distribute this
    //  software is freely granted, provided that this notice
    //  is preserved.
    // =============================    END    ================================
    absx = fabs(b->data[j]);
    if (isnan(b->data[j])) {
      Q = b->data[j];
    } else if (isinf(b->data[j])) {
      if (b->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else if (absx < 0.84375) {
      if (absx < 3.7252902984619141E-9) {
        if (absx < 2.8480945388892178E-306) {
          Q = 0.125 * (8.0 * b->data[j] + 1.0270333367641007 * b->data[j]);
        } else {
          Q = b->data[j] + 0.12837916709551259 * b->data[j];
        }
      } else {
        Q = b->data[j] * b->data[j];
        Q = b->data[j] + b->data[j] * ((Q * (Q * (Q * (Q *
          -2.3763016656650163E-5 + -0.0057702702964894416) +
          -0.02848174957559851) + -0.3250421072470015) + 0.12837916709551256) /
          (Q * (Q * (Q * (Q * (Q * -3.9602282787753681E-6 +
          0.00013249473800432164) + 0.0050813062818757656) + 0.0650222499887673)
                + 0.39791722395915535) + 1.0));
      }
    } else if (absx < 1.25) {
      real_T P;
      P = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * -0.0021663755948687908 + 0.035478304325618236)
        + -0.11089469428239668) + 0.31834661990116175) + -0.37220787603570132) +
                          0.41485611868374833) + -0.0023621185607526594;
      Q = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * 0.011984499846799107 + 0.013637083912029051) +
        0.12617121980876164) + 0.071828654414196266) + 0.540397917702171) +
                          0.10642088040084423) + 1.0;
      if (b->data[j] >= 0.0) {
        Q = P / Q + 0.84506291151046753;
      } else {
        Q = -0.84506291151046753 - P / Q;
      }
    } else if (absx > 6.0) {
      if (b->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else {
      real_T P;
      real_T R;
      int32_T ix;
      Q = 1.0 / (absx * absx);
      if (absx < 2.8571434020996094) {
        R = Q * (Q * (Q * (Q * (Q * (Q * (Q * -9.8143293441691455 +
          -81.2874355063066) + -184.60509290671104) + -162.39666946257347) +
                           -62.375332450326006) + -10.558626225323291) +
                 -0.69385857270718176) + -0.0098649440348471482;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * (Q * -0.0604244152148581 +
          6.5702497703192817) + 108.63500554177944) + 429.00814002756783) +
                    645.38727173326788) + 434.56587747522923) +
                      137.65775414351904) + 19.651271667439257) + 1.0;
      } else {
        R = Q * (Q * (Q * (Q * (Q * (Q * -483.5191916086514 +
          -1025.0951316110772) + -637.56644336838963) + -160.63638485582192) +
                      -17.757954917754752) + -0.799283237680523) +
          -0.0098649429247001;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * -22.440952446585818 +
          474.52854120695537) + 2553.0504064331644) + 3199.8582195085955) +
                           1536.729586084437) + 325.79251299657392) +
                 30.338060743482458) + 1.0;
      }

      if (!static_cast<int32_T>(isnan(absx))) {
        Q = frexp(absx, &eint);
        ix = eint;
      } else {
        Q = absx;
        ix = 0;
      }

      Q = floor(Q * 2.097152E+6) / 2.097152E+6 * rt_powd_snf(2.0,
        static_cast<real_T>(ix));
      Q = exp(-Q * Q - 0.5625) * exp((Q - absx) * (Q + absx) + R / P) / absx;
      if (b->data[j] < 0.0) {
        Q--;
      } else {
        Q = 1.0 - Q;
      }
    }

    r12->data[j] = Q;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  gi_reflectivity_calculation_gpu(const emxArray_real_T *sldProfile, const
  emxArray_int32_T *ii, emxArray_real_T *r13)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(ii->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    r13->data[i1] = sldProfile->data[(ii->data[i1] + sldProfile->size[0]) - 1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  gj_reflectivity_calculation_gpu(const emxArray_creal_T *x, const
  emxArray_real_T *dataPoints, emxArray_boolean_T *trianglesToRefine)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(dataPoints->size[0] - 3);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    trianglesToRefine->data[i1] = (x->data[i1].re < 2.1991148575128552);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  gk_reflectivity_calculation_gpu(const emxArray_int32_T *iwork, const int32_T j,
  const int32_T kEnd, emxArray_int32_T *idx)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T b_idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(kEnd - 1);
  for (b_idx = threadId; b_idx <= static_cast<uint32_T>(loopEnd); b_idx +=
       threadStride) {
    int32_T b_j;
    b_j = static_cast<int32_T>(b_idx);
    idx->data[(j + b_j) - 1] = iwork->data[b_j];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  gl_reflectivity_calculation_gpu(const emxArray_real_T *Simul, const int32_T
  kEnd, const int32_T *qEnd, emxArray_real_T *reflect)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = (static_cast<int64_T>(*qEnd - kEnd) + 1L) * 2L - 1L;
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    int32_T iv0;
    iv0 = static_cast<int32_T>(idx % (static_cast<uint32_T>(*qEnd - kEnd) + 1U));
    i1 = static_cast<int32_T>((idx - static_cast<uint32_T>(iv0)) / (static_cast<
      uint32_T>(*qEnd - kEnd) + 1U));
    reflect->data[iv0 + reflect->size[0] * i1] = Simul->data[(kEnd + iv0) +
      Simul->size[0] * i1];
  }
}

static void gpuEmxFree_boolean_T(emxArray_boolean_T *inter)
{

#define CUDACHECK(errCall)             checkCudaError(errCall, __FILE__, __LINE__)

  checkCudaError(cudaGetLastError(), __FILE__, __LINE__);
  CUDACHECK(cudaFree(inter->data));
  CUDACHECK(cudaFree(inter->size));

#undef CUDACHECK

}

static void gpuEmxFree_creal_T(emxArray_creal_T *inter)
{

#define CUDACHECK(errCall)             checkCudaError(errCall, __FILE__, __LINE__)

  checkCudaError(cudaGetLastError(), __FILE__, __LINE__);
  CUDACHECK(cudaFree(inter->data));
  CUDACHECK(cudaFree(inter->size));

#undef CUDACHECK

}

static void gpuEmxFree_int32_T(emxArray_int32_T *inter)
{

#define CUDACHECK(errCall)             checkCudaError(errCall, __FILE__, __LINE__)

  checkCudaError(cudaGetLastError(), __FILE__, __LINE__);
  CUDACHECK(cudaFree(inter->data));
  CUDACHECK(cudaFree(inter->size));

#undef CUDACHECK

}

static void gpuEmxFree_int8_T(emxArray_int8_T *inter)
{

#define CUDACHECK(errCall)             checkCudaError(errCall, __FILE__, __LINE__)

  checkCudaError(cudaGetLastError(), __FILE__, __LINE__);
  CUDACHECK(cudaFree(inter->data));
  CUDACHECK(cudaFree(inter->size));

#undef CUDACHECK

}

static void gpuEmxFree_real_T(emxArray_real_T *inter)
{

#define CUDACHECK(errCall)             checkCudaError(errCall, __FILE__, __LINE__)

  checkCudaError(cudaGetLastError(), __FILE__, __LINE__);
  CUDACHECK(cudaFree(inter->data));
  CUDACHECK(cudaFree(inter->size));

#undef CUDACHECK

}

static void gpuEmxMemcpyCpuToGpu_boolean_T(const emxArray_boolean_T *cpu,
  emxArray_boolean_T *inter, emxArray_boolean_T *gpu)
{
  int32_T actualSize;
  int32_T i;

#define CUDACHECK(errCall)             checkCudaError(errCall, __FILE__, __LINE__)

  checkCudaError(cudaGetLastError(), __FILE__, __LINE__);
  if (inter->numDimensions < cpu->numDimensions) {
    inter->numDimensions = cpu->numDimensions;
    CUDACHECK(cudaFree(inter->size));
    CUDACHECK(cudaMalloc(&inter->size, inter->numDimensions * sizeof(int32_T)));
  } else {
    inter->numDimensions = cpu->numDimensions;
  }

  actualSize = 1;
  for (i = 0; i < cpu->numDimensions; i++) {
    actualSize *= cpu->size[i];
  }

  if (inter->allocatedSize < actualSize) {
    if (inter->canFreeData) {
      CUDACHECK(cudaFree(inter->data));
    }

    i = cpu->allocatedSize;
    if (i < actualSize) {
      i = actualSize;
    }

    inter->allocatedSize = i;
    inter->canFreeData = true;
    CUDACHECK(cudaMalloc(&inter->data, inter->allocatedSize * sizeof(boolean_T)));
  }

  CUDACHECK(cudaMemcpy(inter->data, cpu->data, actualSize * sizeof(boolean_T),
                       cudaMemcpyHostToDevice));
  CUDACHECK(cudaMemcpy(inter->size, cpu->size, cpu->numDimensions * sizeof
                       (int32_T), cudaMemcpyHostToDevice));
  CUDACHECK(cudaMemcpy(gpu, inter, 32UL, cudaMemcpyHostToDevice));

#undef CUDACHECK

}

static void gpuEmxMemcpyCpuToGpu_creal_T(const emxArray_creal_T *cpu,
  emxArray_creal_T *inter, emxArray_creal_T *gpu)
{
  int32_T actualSize;
  int32_T i;

#define CUDACHECK(errCall)             checkCudaError(errCall, __FILE__, __LINE__)

  checkCudaError(cudaGetLastError(), __FILE__, __LINE__);
  if (inter->numDimensions < cpu->numDimensions) {
    inter->numDimensions = cpu->numDimensions;
    CUDACHECK(cudaFree(inter->size));
    CUDACHECK(cudaMalloc(&inter->size, inter->numDimensions * sizeof(int32_T)));
  } else {
    inter->numDimensions = cpu->numDimensions;
  }

  actualSize = 1;
  for (i = 0; i < cpu->numDimensions; i++) {
    actualSize *= cpu->size[i];
  }

  if (inter->allocatedSize < actualSize) {
    if (inter->canFreeData) {
      CUDACHECK(cudaFree(inter->data));
    }

    i = cpu->allocatedSize;
    if (i < actualSize) {
      i = actualSize;
    }

    inter->allocatedSize = i;
    inter->canFreeData = true;
    CUDACHECK(cudaMalloc(&inter->data, inter->allocatedSize * sizeof(creal_T)));
  }

  CUDACHECK(cudaMemcpy(inter->data, cpu->data, actualSize * sizeof(creal_T),
                       cudaMemcpyHostToDevice));
  CUDACHECK(cudaMemcpy(inter->size, cpu->size, cpu->numDimensions * sizeof
                       (int32_T), cudaMemcpyHostToDevice));
  CUDACHECK(cudaMemcpy(gpu, inter, 32UL, cudaMemcpyHostToDevice));

#undef CUDACHECK

}

static void gpuEmxMemcpyCpuToGpu_int32_T(const emxArray_int32_T *cpu,
  emxArray_int32_T *inter, emxArray_int32_T *gpu)
{
  int32_T actualSize;
  int32_T i;

#define CUDACHECK(errCall)             checkCudaError(errCall, __FILE__, __LINE__)

  checkCudaError(cudaGetLastError(), __FILE__, __LINE__);
  if (inter->numDimensions < cpu->numDimensions) {
    inter->numDimensions = cpu->numDimensions;
    CUDACHECK(cudaFree(inter->size));
    CUDACHECK(cudaMalloc(&inter->size, inter->numDimensions * sizeof(int32_T)));
  } else {
    inter->numDimensions = cpu->numDimensions;
  }

  actualSize = 1;
  for (i = 0; i < cpu->numDimensions; i++) {
    actualSize *= cpu->size[i];
  }

  if (inter->allocatedSize < actualSize) {
    if (inter->canFreeData) {
      CUDACHECK(cudaFree(inter->data));
    }

    i = cpu->allocatedSize;
    if (i < actualSize) {
      i = actualSize;
    }

    inter->allocatedSize = i;
    inter->canFreeData = true;
    CUDACHECK(cudaMalloc(&inter->data, inter->allocatedSize * sizeof(int32_T)));
  }

  CUDACHECK(cudaMemcpy(inter->data, cpu->data, actualSize * sizeof(int32_T),
                       cudaMemcpyHostToDevice));
  CUDACHECK(cudaMemcpy(inter->size, cpu->size, cpu->numDimensions * sizeof
                       (int32_T), cudaMemcpyHostToDevice));
  CUDACHECK(cudaMemcpy(gpu, inter, 32UL, cudaMemcpyHostToDevice));

#undef CUDACHECK

}

static void gpuEmxMemcpyCpuToGpu_int8_T(const emxArray_int8_T *cpu,
  emxArray_int8_T *inter, emxArray_int8_T *gpu)
{
  int32_T actualSize;
  int32_T i;

#define CUDACHECK(errCall)             checkCudaError(errCall, __FILE__, __LINE__)

  checkCudaError(cudaGetLastError(), __FILE__, __LINE__);
  if (inter->numDimensions < cpu->numDimensions) {
    inter->numDimensions = cpu->numDimensions;
    CUDACHECK(cudaFree(inter->size));
    CUDACHECK(cudaMalloc(&inter->size, inter->numDimensions * sizeof(int32_T)));
  } else {
    inter->numDimensions = cpu->numDimensions;
  }

  actualSize = 1;
  for (i = 0; i < cpu->numDimensions; i++) {
    actualSize *= cpu->size[i];
  }

  if (inter->allocatedSize < actualSize) {
    if (inter->canFreeData) {
      CUDACHECK(cudaFree(inter->data));
    }

    i = cpu->allocatedSize;
    if (i < actualSize) {
      i = actualSize;
    }

    inter->allocatedSize = i;
    inter->canFreeData = true;
    CUDACHECK(cudaMalloc(&inter->data, inter->allocatedSize * sizeof(int8_T)));
  }

  CUDACHECK(cudaMemcpy(inter->data, cpu->data, actualSize * sizeof(int8_T),
                       cudaMemcpyHostToDevice));
  CUDACHECK(cudaMemcpy(inter->size, cpu->size, cpu->numDimensions * sizeof
                       (int32_T), cudaMemcpyHostToDevice));
  CUDACHECK(cudaMemcpy(gpu, inter, 32UL, cudaMemcpyHostToDevice));

#undef CUDACHECK

}

static void gpuEmxMemcpyCpuToGpu_real_T(const emxArray_real_T *cpu,
  emxArray_real_T *inter, emxArray_real_T *gpu)
{
  int32_T actualSize;
  int32_T i;

#define CUDACHECK(errCall)             checkCudaError(errCall, __FILE__, __LINE__)

  checkCudaError(cudaGetLastError(), __FILE__, __LINE__);
  if (inter->numDimensions < cpu->numDimensions) {
    inter->numDimensions = cpu->numDimensions;
    CUDACHECK(cudaFree(inter->size));
    CUDACHECK(cudaMalloc(&inter->size, inter->numDimensions * sizeof(int32_T)));
  } else {
    inter->numDimensions = cpu->numDimensions;
  }

  actualSize = 1;
  for (i = 0; i < cpu->numDimensions; i++) {
    actualSize *= cpu->size[i];
  }

  if (inter->allocatedSize < actualSize) {
    if (inter->canFreeData) {
      CUDACHECK(cudaFree(inter->data));
    }

    i = cpu->allocatedSize;
    if (i < actualSize) {
      i = actualSize;
    }

    inter->allocatedSize = i;
    inter->canFreeData = true;
    CUDACHECK(cudaMalloc(&inter->data, inter->allocatedSize * sizeof(real_T)));
  }

  CUDACHECK(cudaMemcpy(inter->data, cpu->data, actualSize * sizeof(real_T),
                       cudaMemcpyHostToDevice));
  CUDACHECK(cudaMemcpy(inter->size, cpu->size, cpu->numDimensions * sizeof
                       (int32_T), cudaMemcpyHostToDevice));
  CUDACHECK(cudaMemcpy(gpu, inter, 32UL, cudaMemcpyHostToDevice));

#undef CUDACHECK

}

static void gpuEmxMemcpyGpuToCpu_boolean_T(emxArray_boolean_T *cpu,
  emxArray_boolean_T *inter)
{
  int32_T actualSize;

#define CUDACHECK(errCall)             checkCudaError(errCall, __FILE__, __LINE__)

  checkCudaError(cudaGetLastError(), __FILE__, __LINE__);
  actualSize = 1;
  for (int32_T i = 0; i < cpu->numDimensions; i++) {
    actualSize *= cpu->size[i];
  }

  CUDACHECK(cudaMemcpy(cpu->data, inter->data, actualSize * sizeof(boolean_T),
                       cudaMemcpyDeviceToHost));
  CUDACHECK(cudaMemcpy(cpu->size, inter->size, inter->numDimensions * sizeof
                       (int32_T), cudaMemcpyDeviceToHost));

#undef CUDACHECK

}

static void gpuEmxMemcpyGpuToCpu_creal_T(emxArray_creal_T *cpu, emxArray_creal_T
  *inter)
{
  int32_T actualSize;

#define CUDACHECK(errCall)             checkCudaError(errCall, __FILE__, __LINE__)

  checkCudaError(cudaGetLastError(), __FILE__, __LINE__);
  actualSize = 1;
  for (int32_T i = 0; i < cpu->numDimensions; i++) {
    actualSize *= cpu->size[i];
  }

  CUDACHECK(cudaMemcpy(cpu->data, inter->data, actualSize * sizeof(creal_T),
                       cudaMemcpyDeviceToHost));
  CUDACHECK(cudaMemcpy(cpu->size, inter->size, inter->numDimensions * sizeof
                       (int32_T), cudaMemcpyDeviceToHost));

#undef CUDACHECK

}

static void gpuEmxMemcpyGpuToCpu_int32_T(emxArray_int32_T *cpu, emxArray_int32_T
  *inter)
{
  int32_T actualSize;

#define CUDACHECK(errCall)             checkCudaError(errCall, __FILE__, __LINE__)

  checkCudaError(cudaGetLastError(), __FILE__, __LINE__);
  actualSize = 1;
  for (int32_T i = 0; i < cpu->numDimensions; i++) {
    actualSize *= cpu->size[i];
  }

  CUDACHECK(cudaMemcpy(cpu->data, inter->data, actualSize * sizeof(int32_T),
                       cudaMemcpyDeviceToHost));
  CUDACHECK(cudaMemcpy(cpu->size, inter->size, inter->numDimensions * sizeof
                       (int32_T), cudaMemcpyDeviceToHost));

#undef CUDACHECK

}

static void gpuEmxMemcpyGpuToCpu_int8_T(emxArray_int8_T *cpu, emxArray_int8_T
  *inter)
{
  int32_T actualSize;

#define CUDACHECK(errCall)             checkCudaError(errCall, __FILE__, __LINE__)

  checkCudaError(cudaGetLastError(), __FILE__, __LINE__);
  actualSize = 1;
  for (int32_T i = 0; i < cpu->numDimensions; i++) {
    actualSize *= cpu->size[i];
  }

  CUDACHECK(cudaMemcpy(cpu->data, inter->data, actualSize * sizeof(int8_T),
                       cudaMemcpyDeviceToHost));
  CUDACHECK(cudaMemcpy(cpu->size, inter->size, inter->numDimensions * sizeof
                       (int32_T), cudaMemcpyDeviceToHost));

#undef CUDACHECK

}

static void gpuEmxMemcpyGpuToCpu_real_T(emxArray_real_T *cpu, emxArray_real_T
  *inter)
{
  int32_T actualSize;

#define CUDACHECK(errCall)             checkCudaError(errCall, __FILE__, __LINE__)

  checkCudaError(cudaGetLastError(), __FILE__, __LINE__);
  actualSize = 1;
  for (int32_T i = 0; i < cpu->numDimensions; i++) {
    actualSize *= cpu->size[i];
  }

  CUDACHECK(cudaMemcpy(cpu->data, inter->data, actualSize * sizeof(real_T),
                       cudaMemcpyDeviceToHost));
  CUDACHECK(cudaMemcpy(cpu->size, inter->size, inter->numDimensions * sizeof
                       (int32_T), cudaMemcpyDeviceToHost));

#undef CUDACHECK

}

static void gpuEmxReset_boolean_T(emxArray_boolean_T *inter)
{
  memset(inter, 0, sizeof(emxArray_boolean_T));
}

static void gpuEmxReset_creal_T(emxArray_creal_T *inter)
{
  memset(inter, 0, sizeof(emxArray_creal_T));
}

static void gpuEmxReset_int32_T(emxArray_int32_T *inter)
{
  memset(inter, 0, sizeof(emxArray_int32_T));
}

static void gpuEmxReset_int8_T(emxArray_int8_T *inter)
{
  memset(inter, 0, sizeof(emxArray_int8_T));
}

static void gpuEmxReset_real_T(emxArray_real_T *inter)
{
  memset(inter, 0, sizeof(emxArray_real_T));
}

static __global__ __launch_bounds__(1024, 1) void
  h_reflectivity_calculation_gpu_(const struct0_T problemDef, emxArray_real_T
  *nbss)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(static_cast<int32_T>
    (problemDef.numberOfContrasts) - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    nbss->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  hb_reflectivity_calculation_gpu(const real_T reps, const emxArray_real_T *x,
  emxArray_real_T *Lays)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(x->size[1] * static_cast<int32_T>(2.0 * reps +
    2.0) - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    Lays->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(32, 1) void hc_reflectivity_calculation_gpu(
  const real_T layers_data[10], emxArray_real_T *layers)
{
  uint32_T threadId;
  int32_T i1;
  int32_T iv0;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  iv0 = static_cast<int32_T>(threadId % 2U);
  i1 = static_cast<int32_T>((threadId - static_cast<uint32_T>(iv0)) / 2U);
  if (i1 < 3) {
    layers->data[iv0 + layers->size[0] * i1] = layers_data[iv0 + (i1 << 1)];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  hd_reflectivity_calculation_gpu(const emxArray_real_T *longStep, const int32_T
  *nx, emxArray_real_T *z1)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    z1->data[j] = rt_powd_snf(longStep->data[j], 2.0);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  he_reflectivity_calculation_gpu(const emxArray_real_T *dataPoints,
  emxArray_real_T *b_dataPoints)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = (static_cast<int64_T>(dataPoints->size[0] - 1) + 1L) * 2L - 1L;
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    int32_T iv0;
    uint32_T tmpIndex;
    iv0 = static_cast<int32_T>(idx % static_cast<uint32_T>(dataPoints->size[0]));
    tmpIndex = (idx - static_cast<uint32_T>(iv0)) / static_cast<uint32_T>
      (dataPoints->size[0]);
    i1 = static_cast<int32_T>(tmpIndex);
    b_dataPoints->data[iv0 + b_dataPoints->size[0] * i1] = dataPoints->data[iv0
      + dataPoints->size[0] * i1];
  }
}

static __global__ __launch_bounds__(32, 1) void hf_reflectivity_calculation_gpu(
  const real_T l, const real_T *layerThicks, const real_T bFactor, const real_T
  nextLayRough, creal_T N[4])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    N[1].re = nextLayRough * bFactor - *layerThicks * l;
    N[1].im = nextLayRough * l + *layerThicks * bFactor;
  }
}

static __global__ __launch_bounds__(32, 1) void hg_reflectivity_calculation_gpu(
  const cell_10 *problemDef_cells, real_T thisOutLayer[5])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    thisOutLayer[4] = problemDef_cells->f6[1].f1[4];
  }
}

static __global__ __launch_bounds__(32, 1) void hh_reflectivity_calculation_gpu(
  const emxArray_real_T *Lays, int32_T *xoffset)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    *xoffset = Lays->size[0];
  }
}

static __global__ __launch_bounds__(64, 1) void hi_reflectivity_calculation_gpu(
  const real_T hiVal[50], const real_T y[50], real_T b_y[100])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 50) {
    // end
    // dataPoints = [initialDomain(:), func(initialDomain(:))];
    b_y[i1] = y[i1];
    b_y[i1 + 50] = hiVal[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  hj_reflectivity_calculation_gpu(const emxArray_boolean_T *trianglesToRefine,
  const int32_T *nx, emxArray_boolean_T *b_trianglesToRefine)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    b_trianglesToRefine->data[i1] = trianglesToRefine->data[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  hk_reflectivity_calculation_gpu(const emxArray_real_T *dataPoints,
  emxArray_real_T *layers)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>((dataPoints->size[0] - 1) * 3 - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    layers->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  hl_reflectivity_calculation_gpu(const real_T *layerThicks, const
  emxArray_real_T *Simul, const int32_T kEnd, const int32_T *qEnd,
  emxArray_real_T *reflect)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = (static_cast<int64_T>(*qEnd - kEnd) + 1L) * 2L - 1L;
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    int32_T iv0;
    iv0 = static_cast<int32_T>(idx % (static_cast<uint32_T>(*qEnd - kEnd) + 1U));
    i1 = static_cast<int32_T>((idx - static_cast<uint32_T>(iv0)) / (static_cast<
      uint32_T>(*qEnd - kEnd) + 1U));
    reflect->data[iv0 + reflect->size[0] * i1] = Simul->data[(kEnd + iv0) +
      Simul->size[0] * i1] + *layerThicks;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  i_reflectivity_calculation_gpu_(const struct0_T problemDef, emxArray_real_T
  *chis)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(static_cast<int32_T>
    (problemDef.numberOfContrasts) - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    chis->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ib_reflectivity_calculation_gpu(const real_T *layerThicks, const
  emxArray_real_T *x, emxArray_real_T *a)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(x->size[0] * x->size[1] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    a->data[i1] = (x->data[i1] - -50.0) / *layerThicks;
  }
}

static __global__ __launch_bounds__(32, 1) void ic_reflectivity_calculation_gpu(
  const real_T dataBoxSize[2], real_T y[50])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    y[49] = dataBoxSize[1];
    y[0] = dataBoxSize[0];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  id_reflectivity_calculation_gpu(const emxArray_real_T *longStep, const int32_T
  *nx, emxArray_real_T *z1)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    z1->data[j] = rt_powd_snf(longStep->data[j + longStep->size[0]], 2.0);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ie_reflectivity_calculation_gpu(const emxArray_real_T *dataPoints,
  emxArray_real_T *b_dataPoints)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(dataPoints->size[0] * dataPoints->size[1] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    b_dataPoints->data[i1] = dataPoints->data[i1];
  }
}

static __global__ __launch_bounds__(32, 1) void if_reflectivity_calculation_gpu(
  const real_T l, const real_T bFactor, creal_T N[4])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    N[3].re = bFactor;
    N[3].im = l;
  }
}

static __global__ __launch_bounds__(32, 1) void ig_reflectivity_calculation_gpu(
  const real_T thisOutLayer[5], cell_wrap_2 outParameterisedLayers[4])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 5) {
    outParameterisedLayers[1].f1[i1] = thisOutLayer[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ih_reflectivity_calculation_gpu(const emxArray_real_T *r12, const
  emxArray_real_T *r10, const real_T *layerThicks, const int32_T *qEnd, const
  int32_T ii_size[1], emxArray_real_T *Lays)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(ii_size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    Lays->data[i1 + Lays->size[0] * *qEnd] = *layerThicks * (r10->data[i1] -
      r12->data[i1]);
  }
}

static __global__ __launch_bounds__(128, 1) void ii_reflectivity_calculation_gpu
  (const real_T y[100], emxArray_real_T *dataPoints)
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 100) {
    dataPoints->data[i1] = y[i1];
  }
}

static __global__ __launch_bounds__(32, 1) void ij_reflectivity_calculation_gpu(
  const emxArray_boolean_T *trianglesToRefine, emxArray_boolean_T
  *b_trianglesToRefine)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    b_trianglesToRefine->data[trianglesToRefine->size[0]] = false;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ik_reflectivity_calculation_gpu(const emxArray_real_T *dataPoints, const
  int32_T kEnd, emxArray_real_T *layers)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(kEnd - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    real_T Q;
    int32_T ix;
    ix = static_cast<int32_T>(idx);
    if (dataPoints->data[(ix + dataPoints->size[0]) + 1] > dataPoints->data[ix +
        dataPoints->size[0]]) {
      Q = (dataPoints->data[(ix + dataPoints->size[0]) + 1] - dataPoints->
           data[ix + dataPoints->size[0]]) / 2.0 + dataPoints->data[ix +
        dataPoints->size[0]];
    } else {
      Q = (dataPoints->data[ix + dataPoints->size[0]] - dataPoints->data[(ix +
            dataPoints->size[0]) + 1]) / 2.0 + dataPoints->data[(ix +
        dataPoints->size[0]) + 1];
    }

    layers->data[ix] = dataPoints->data[ix + 1] - dataPoints->data[ix];
    layers->data[ix + layers->size[0]] = Q;
    layers->data[ix + (layers->size[0] << 1)] = 2.2204460492503131E-16;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  il_reflectivity_calculation_gpu(const real_T *layerThicks, const int32_T kEnd,
  emxArray_real_T *Simul)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(kEnd - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    Simul->data[i1] += *layerThicks;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  j_reflectivity_calculation_gpu_(const struct0_T problemDef, emxArray_real_T
  *resols)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(static_cast<int32_T>
    (problemDef.numberOfContrasts) - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    resols->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  jb_reflectivity_calculation_gpu(const real_T bFactor, const emxArray_real_T *x,
  emxArray_real_T *b)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(x->size[0] * x->size[1] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    b->data[i1] = (x->data[i1] - 50.0) / bFactor;
  }
}

static __global__ __launch_bounds__(64, 1) void jc_reflectivity_calculation_gpu(
  const real_T bFactor, const real_T *layerThicks, real_T y[50])
{
  uint32_T threadId;
  int32_T j;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  j = static_cast<int32_T>(threadId);
  if (j < 48) {
    y[j + 1] = *layerThicks + (static_cast<real_T>(j) + 1.0) * bFactor;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  jd_reflectivity_calculation_gpu(const emxArray_real_T *secondStepSquared,
  const emxArray_real_T *firstStepSquared, emxArray_real_T *x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(firstStepSquared->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    x->data[i1] = firstStepSquared->data[i1] * secondStepSquared->data[i1];
  }
}

static __global__ __launch_bounds__(32, 1) void je_reflectivity_calculation_gpu
  (int8_T col_data[2])
{
  uint32_T threadId;
  int32_T j;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  j = static_cast<int32_T>(threadId);
  if (j < 2) {
    col_data[j] = static_cast<int8_T>(j + 1);
  }
}

static __global__ __launch_bounds__(32, 1) void jf_reflectivity_calculation_gpu(
  const real_T l, const real_T *layerThicks, const real_T bFactor, const real_T
  nextLayRough, creal_T N[4])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    N[2].re = nextLayRough * bFactor - *layerThicks * l;
    N[2].im = nextLayRough * l + *layerThicks * bFactor;
  }
}

static __global__ __launch_bounds__(32, 1) void jg_reflectivity_calculation_gpu(
  const struct0_T problemDef, const cell_10 *problemDef_cells, real_T
  thisOutLayer[5])
{
  uint32_T threadId;
  int32_T ix;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  ix = static_cast<int32_T>(threadId);
  if (ix < 4) {
    if (!static_cast<int32_T>(isnan(problemDef_cells->f6[2].f1[ix]))) {
      thisOutLayer[ix] = problemDef.params[static_cast<int32_T>
        (problemDef_cells->f6[2].f1[ix]) - 1];
    } else {
      thisOutLayer[ix] = CUDART_NAN;
    }
  }
}

static __global__ __launch_bounds__(1024, 1) void
  jh_reflectivity_calculation_gpu(const real_T *layerThicks, const real_T l,
  const emxArray_real_T *x, emxArray_real_T *a)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(x->size[0] * x->size[1] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    a->data[i1] = (x->data[i1] - l) / *layerThicks;
  }
}

static __global__ __launch_bounds__(32, 1) void ji_reflectivity_calculation_gpu(
  const int32_T vlen, const emxArray_real_T *dataPoints, real_T dataBoxSize[2])
{
  uint32_T threadId;
  int32_T j;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  j = static_cast<int32_T>(threadId);
  if (j < 2) {
    int32_T iv0;
    iv0 = (j * (dataPoints->size[0] - 1) + j) + 1;
    dataBoxSize[j] = dataPoints->data[(iv0 - 1) % dataPoints->size[0] +
      dataPoints->size[0] * ((iv0 - 1) / dataPoints->size[0])];
    for (int32_T i = 0; i <= vlen - 2; i++) {
      int32_T ix;
      boolean_T xneg;
      ix = (iv0 + i) + 1;
      if (isnan(dataPoints->data[(ix - 1) % dataPoints->size[0] +
                dataPoints->size[0] * ((ix - 1) / dataPoints->size[0])])) {
        xneg = false;
      } else if (isnan(dataBoxSize[j])) {
        xneg = true;
      } else {
        xneg = (dataBoxSize[j] < dataPoints->data[(ix - 1) % dataPoints->size[0]
                + dataPoints->size[0] * ((ix - 1) / dataPoints->size[0])]);
      }

      if (xneg) {
        dataBoxSize[j] = dataPoints->data[(ix - 1) % dataPoints->size[0] +
          dataPoints->size[0] * ((ix - 1) / dataPoints->size[0])];
      }
    }
  }
}

static __global__ __launch_bounds__(32, 1) void jj_reflectivity_calculation_gpu
  (emxArray_boolean_T *r33)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    r33->data[0] = false;
  }
}

static __global__ __launch_bounds__(160, 1) void jk_reflectivity_calculation_gpu
  (const cell_10 *problemDef_cells, const int32_T i, real_T shifted_dat_data[153])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 153) {
    shifted_dat_data[i1] = problemDef_cells->f2[i].f1[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  jl_reflectivity_calculation_gpu(const real_T *layerThicks, const real_T
  shifted_dat_data[153], const int32_T shifted_dat_size[2], const int32_T kEnd,
  real_T terms_data[51])
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(kEnd);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    terms_data[i1] = shifted_dat_data[i1 + shifted_dat_size[0]] - *layerThicks;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  k_reflectivity_calculation_gpu_(const struct0_T problemDef, emxArray_real_T
  *allRoughs)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(static_cast<int32_T>
    (problemDef.numberOfContrasts) - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    allRoughs->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  kb_reflectivity_calculation_gpu(const emxArray_real_T *a, const int32_T *nx,
  emxArray_real_T *r)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int32_T eint;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    real_T absx;
    int32_T j;
    real_T Q;
    j = static_cast<int32_T>(idx);

    // ========================== COPYRIGHT NOTICE ============================
    //  The algorithms for calculating ERF(X) and ERFC(X) are derived
    //  from FDLIBM, which has the following notice:
    //
    //  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
    //
    //  Developed at SunSoft, a Sun Microsystems, Inc. business.
    //  Permission to use, copy, modify, and distribute this
    //  software is freely granted, provided that this notice
    //  is preserved.
    // =============================    END    ================================
    absx = fabs(a->data[j]);
    if (isnan(a->data[j])) {
      Q = a->data[j];
    } else if (isinf(a->data[j])) {
      if (a->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else if (absx < 0.84375) {
      if (absx < 3.7252902984619141E-9) {
        if (absx < 2.8480945388892178E-306) {
          Q = 0.125 * (8.0 * a->data[j] + 1.0270333367641007 * a->data[j]);
        } else {
          Q = a->data[j] + 0.12837916709551259 * a->data[j];
        }
      } else {
        Q = a->data[j] * a->data[j];
        Q = a->data[j] + a->data[j] * ((Q * (Q * (Q * (Q *
          -2.3763016656650163E-5 + -0.0057702702964894416) +
          -0.02848174957559851) + -0.3250421072470015) + 0.12837916709551256) /
          (Q * (Q * (Q * (Q * (Q * -3.9602282787753681E-6 +
          0.00013249473800432164) + 0.0050813062818757656) + 0.0650222499887673)
                + 0.39791722395915535) + 1.0));
      }
    } else if (absx < 1.25) {
      real_T P;
      P = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * -0.0021663755948687908 + 0.035478304325618236)
        + -0.11089469428239668) + 0.31834661990116175) + -0.37220787603570132) +
                          0.41485611868374833) + -0.0023621185607526594;
      Q = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * 0.011984499846799107 + 0.013637083912029051) +
        0.12617121980876164) + 0.071828654414196266) + 0.540397917702171) +
                          0.10642088040084423) + 1.0;
      if (a->data[j] >= 0.0) {
        Q = P / Q + 0.84506291151046753;
      } else {
        Q = -0.84506291151046753 - P / Q;
      }
    } else if (absx > 6.0) {
      if (a->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else {
      real_T P;
      real_T R;
      int32_T ix;
      Q = 1.0 / (absx * absx);
      if (absx < 2.8571434020996094) {
        R = Q * (Q * (Q * (Q * (Q * (Q * (Q * -9.8143293441691455 +
          -81.2874355063066) + -184.60509290671104) + -162.39666946257347) +
                           -62.375332450326006) + -10.558626225323291) +
                 -0.69385857270718176) + -0.0098649440348471482;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * (Q * -0.0604244152148581 +
          6.5702497703192817) + 108.63500554177944) + 429.00814002756783) +
                    645.38727173326788) + 434.56587747522923) +
                      137.65775414351904) + 19.651271667439257) + 1.0;
      } else {
        R = Q * (Q * (Q * (Q * (Q * (Q * -483.5191916086514 +
          -1025.0951316110772) + -637.56644336838963) + -160.63638485582192) +
                      -17.757954917754752) + -0.799283237680523) +
          -0.0098649429247001;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * -22.440952446585818 +
          474.52854120695537) + 2553.0504064331644) + 3199.8582195085955) +
                           1536.729586084437) + 325.79251299657392) +
                 30.338060743482458) + 1.0;
      }

      if (!static_cast<int32_T>(isnan(absx))) {
        Q = frexp(absx, &eint);
        ix = eint;
      } else {
        Q = absx;
        ix = 0;
      }

      Q = floor(Q * 2.097152E+6) / 2.097152E+6 * rt_powd_snf(2.0,
        static_cast<real_T>(ix));
      Q = exp(-Q * Q - 0.5625) * exp((Q - absx) * (Q + absx) + R / P) / absx;
      if (a->data[j] < 0.0) {
        Q--;
      } else {
        Q = 1.0 - Q;
      }
    }

    r->data[j] = Q;
  }
}

static __global__ __launch_bounds__(64, 1) void kc_reflectivity_calculation_gpu(
  const real_T bFactor, const real_T l, const real_T *layerThicks, real_T y[50])
{
  uint32_T threadId;
  int32_T j;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  j = static_cast<int32_T>(threadId);
  if (j < 48) {
    y[j + 1] = (*layerThicks + l * (static_cast<real_T>(j) + 1.0)) - bFactor * (
      static_cast<real_T>(j) + 1.0);
  }
}

static __global__ __launch_bounds__(32, 1) void kd_reflectivity_calculation_gpu(
  const emxArray_real_T *x, int32_T *nx)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    *nx = x->size[0];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ke_reflectivity_calculation_gpu(const emxArray_real_T *dataPoints,
  emxArray_int32_T *idx)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T b_idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(dataPoints->size[0] - 1);
  for (b_idx = threadId; b_idx <= static_cast<uint32_T>(loopEnd); b_idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(b_idx);
    idx->data[i1] = 0;
  }
}

static __global__ __launch_bounds__(32, 1) void kf_reflectivity_calculation_gpu(
  const creal_T N[4], const creal_T MI[4], creal_T b_MI[4])
{
  uint32_T threadId;
  int32_T i1;
  real_T P;
  real_T Q;
  int32_T ix;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  ix = static_cast<int32_T>(threadId % 2U);
  i1 = static_cast<int32_T>((threadId - static_cast<uint32_T>(ix)) / 2U);
  if (i1 < 2) {
    Q = 0.0;
    P = 0.0;
    for (int32_T iv0 = 0; iv0 < 2; iv0++) {
      Q += MI[i1 + (iv0 << 1)].re * N[iv0 + (ix << 1)].re - MI[i1 + (iv0 << 1)].
        im * N[iv0 + (ix << 1)].im;
      P += MI[i1 + (iv0 << 1)].re * N[iv0 + (ix << 1)].im + MI[i1 + (iv0 << 1)].
        im * N[iv0 + (ix << 1)].re;
    }

    b_MI[i1 + (ix << 1)].re = Q;
    b_MI[i1 + (ix << 1)].im = P;
  }
}

static __global__ __launch_bounds__(32, 1) void kg_reflectivity_calculation_gpu(
  const cell_10 *problemDef_cells, real_T thisOutLayer[5])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    thisOutLayer[4] = problemDef_cells->f6[2].f1[4];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  kh_reflectivity_calculation_gpu(const real_T bFactor, const real_T r, const
  emxArray_real_T *x, emxArray_real_T *b)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(x->size[0] * x->size[1] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    b->data[i1] = (x->data[i1] - r) / bFactor;
  }
}

static __global__ __launch_bounds__(32, 1) void ki_reflectivity_calculation_gpu(
  const int32_T vlen, const emxArray_real_T *dataPoints, real_T minval[2])
{
  uint32_T threadId;
  int32_T j;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  j = static_cast<int32_T>(threadId);
  if (j < 2) {
    int32_T iv0;
    iv0 = (j * (dataPoints->size[0] - 1) + j) + 1;
    minval[j] = dataPoints->data[(iv0 - 1) % dataPoints->size[0] +
      dataPoints->size[0] * ((iv0 - 1) / dataPoints->size[0])];
    for (int32_T i = 0; i <= vlen - 2; i++) {
      int32_T ix;
      boolean_T xneg;
      ix = (iv0 + i) + 1;
      if (isnan(dataPoints->data[(ix - 1) % dataPoints->size[0] +
                dataPoints->size[0] * ((ix - 1) / dataPoints->size[0])])) {
        xneg = false;
      } else if (isnan(minval[j])) {
        xneg = true;
      } else {
        xneg = (minval[j] > dataPoints->data[(ix - 1) % dataPoints->size[0] +
                dataPoints->size[0] * ((ix - 1) / dataPoints->size[0])]);
      }

      if (xneg) {
        minval[j] = dataPoints->data[(ix - 1) % dataPoints->size[0] +
          dataPoints->size[0] * ((ix - 1) / dataPoints->size[0])];
      }
    }
  }
}

static __global__ __launch_bounds__(1024, 1) void
  kj_reflectivity_calculation_gpu(const emxArray_boolean_T *trianglesToRefine,
  const int32_T *nx, emxArray_boolean_T *r33)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    r33->data[i1 + 1] = trianglesToRefine->data[i1];
  }
}

static __global__ __launch_bounds__(64, 1) void kk_reflectivity_calculation_gpu(
  const real_T bFactor, const real_T *layerThicks, const real_T shifts, const
  cell_10 *problemDef_cells, const int32_T i, boolean_T x[51], real_T thisData
  [153])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 51) {
    real_T Q;
    Q = problemDef_cells->f2[i].f1[i1] + shifts;
    thisData[i1] = Q;
    thisData[i1 + 51] /= *layerThicks;
    thisData[i1 + 102] /= *layerThicks;
    x[i1] = (Q < bFactor);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  kl_reflectivity_calculation_gpu(const real_T terms_data[51], const int32_T
  shifted_dat_size[2], const int32_T ii_size[1], real_T shifted_dat_data[153])
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(ii_size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    shifted_dat_data[i1 + shifted_dat_size[0]] = terms_data[i1];
  }
}

static __global__ __launch_bounds__(32, 1) void l_reflectivity_calculation_gpu_
  (real_T thisOutLayer[5])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 5) {
    //  end memory allocation.
    //  First we need to allocate the absolute values of the input
    //  parameters to all the layers in the layers list. This only needs
    //  to be done once, and so is done outside the contrasts loop
    // This function takes the list of all layers (in terms of parameter
    // numbers) in layersDetails, and loops through putting in the correct
    // parameter value from the parameter array in each layer.
    thisOutLayer[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  lb_reflectivity_calculation_gpu(const emxArray_real_T *b, const int32_T *nx,
  emxArray_real_T *r1)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int32_T eint;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    real_T absx;
    int32_T j;
    real_T Q;
    j = static_cast<int32_T>(idx);

    // ========================== COPYRIGHT NOTICE ============================
    //  The algorithms for calculating ERF(X) and ERFC(X) are derived
    //  from FDLIBM, which has the following notice:
    //
    //  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
    //
    //  Developed at SunSoft, a Sun Microsystems, Inc. business.
    //  Permission to use, copy, modify, and distribute this
    //  software is freely granted, provided that this notice
    //  is preserved.
    // =============================    END    ================================
    absx = fabs(b->data[j]);
    if (isnan(b->data[j])) {
      Q = b->data[j];
    } else if (isinf(b->data[j])) {
      if (b->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else if (absx < 0.84375) {
      if (absx < 3.7252902984619141E-9) {
        if (absx < 2.8480945388892178E-306) {
          Q = 0.125 * (8.0 * b->data[j] + 1.0270333367641007 * b->data[j]);
        } else {
          Q = b->data[j] + 0.12837916709551259 * b->data[j];
        }
      } else {
        Q = b->data[j] * b->data[j];
        Q = b->data[j] + b->data[j] * ((Q * (Q * (Q * (Q *
          -2.3763016656650163E-5 + -0.0057702702964894416) +
          -0.02848174957559851) + -0.3250421072470015) + 0.12837916709551256) /
          (Q * (Q * (Q * (Q * (Q * -3.9602282787753681E-6 +
          0.00013249473800432164) + 0.0050813062818757656) + 0.0650222499887673)
                + 0.39791722395915535) + 1.0));
      }
    } else if (absx < 1.25) {
      real_T P;
      P = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * -0.0021663755948687908 + 0.035478304325618236)
        + -0.11089469428239668) + 0.31834661990116175) + -0.37220787603570132) +
                          0.41485611868374833) + -0.0023621185607526594;
      Q = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * 0.011984499846799107 + 0.013637083912029051) +
        0.12617121980876164) + 0.071828654414196266) + 0.540397917702171) +
                          0.10642088040084423) + 1.0;
      if (b->data[j] >= 0.0) {
        Q = P / Q + 0.84506291151046753;
      } else {
        Q = -0.84506291151046753 - P / Q;
      }
    } else if (absx > 6.0) {
      if (b->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else {
      real_T P;
      real_T R;
      int32_T ix;
      Q = 1.0 / (absx * absx);
      if (absx < 2.8571434020996094) {
        R = Q * (Q * (Q * (Q * (Q * (Q * (Q * -9.8143293441691455 +
          -81.2874355063066) + -184.60509290671104) + -162.39666946257347) +
                           -62.375332450326006) + -10.558626225323291) +
                 -0.69385857270718176) + -0.0098649440348471482;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * (Q * -0.0604244152148581 +
          6.5702497703192817) + 108.63500554177944) + 429.00814002756783) +
                    645.38727173326788) + 434.56587747522923) +
                      137.65775414351904) + 19.651271667439257) + 1.0;
      } else {
        R = Q * (Q * (Q * (Q * (Q * (Q * -483.5191916086514 +
          -1025.0951316110772) + -637.56644336838963) + -160.63638485582192) +
                      -17.757954917754752) + -0.799283237680523) +
          -0.0098649429247001;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * -22.440952446585818 +
          474.52854120695537) + 2553.0504064331644) + 3199.8582195085955) +
                           1536.729586084437) + 325.79251299657392) +
                 30.338060743482458) + 1.0;
      }

      if (!static_cast<int32_T>(isnan(absx))) {
        Q = frexp(absx, &eint);
        ix = eint;
      } else {
        Q = absx;
        ix = 0;
      }

      Q = floor(Q * 2.097152E+6) / 2.097152E+6 * rt_powd_snf(2.0,
        static_cast<real_T>(ix));
      Q = exp(-Q * Q - 0.5625) * exp((Q - absx) * (Q + absx) + R / P) / absx;
      if (b->data[j] < 0.0) {
        Q--;
      } else {
        Q = 1.0 - Q;
      }
    }

    r1->data[j] = Q;
  }
}

static __global__ __launch_bounds__(64, 1) void lc_reflectivity_calculation_gpu(
  const real_T dataBoxSize[2], real_T y[50])
{
  uint32_T threadId;
  int32_T j;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  j = static_cast<int32_T>(threadId);
  if (j < 48) {
    y[j + 1] = dataBoxSize[1] * ((2.0 * (static_cast<real_T>(j) + 2.0) - 51.0) /
      49.0);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ld_reflectivity_calculation_gpu(const int32_T *nx, emxArray_real_T *x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    x->data[j] = sqrt(x->data[j]);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  le_reflectivity_calculation_gpu(const int8_T col_data[2], const
  emxArray_real_T *dataPoints, const int32_T kEnd, emxArray_int32_T *idx)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T b_idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>((kEnd - 1) / 2);
  for (b_idx = threadId; b_idx <= static_cast<uint32_T>(loopEnd); b_idx +=
       threadStride) {
    int32_T j;
    boolean_T xneg;
    int32_T ix;
    boolean_T exitg1;
    j = static_cast<int32_T>(b_idx);
    j = (j << 1) + 1;
    xneg = true;
    ix = 1;
    exitg1 = false;
    while ((!static_cast<int32_T>(exitg1)) && (static_cast<int32_T>(ix < 3))) {
      real_T P;
      real_T Q;
      P = dataPoints->data[(j + dataPoints->size[0] * (static_cast<int32_T>
        (col_data[ix - 1]) - 1)) - 1];
      Q = dataPoints->data[j + dataPoints->size[0] * (static_cast<int32_T>
        (col_data[ix - 1]) - 1)];
      if ((static_cast<int32_T>(P == Q)) || (static_cast<int32_T>
           ((static_cast<int32_T>(isnan(P))) && (static_cast<int32_T>(isnan(Q))))))
      {
        ix++;
      } else {
        if ((!static_cast<int32_T>(P <= Q)) && (!static_cast<int32_T>(isnan(Q))))
        {
          xneg = false;
        }

        exitg1 = true;
      }
    }

    if (xneg) {
      idx->data[j - 1] = j;
      idx->data[j] = j + 1;
    } else {
      idx->data[j - 1] = j + 1;
      idx->data[j] = j;
    }
  }
}

static __global__ __launch_bounds__(32, 1) void lf_reflectivity_calculation_gpu(
  const creal_T MI[4], creal_T b_MI[4])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 4) {
    b_MI[i1] = MI[i1];
  }
}

static __global__ __launch_bounds__(32, 1) void lg_reflectivity_calculation_gpu(
  const real_T thisOutLayer[5], cell_wrap_2 outParameterisedLayers[4])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 5) {
    outParameterisedLayers[2].f1[i1] = thisOutLayer[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  lh_reflectivity_calculation_gpu(const emxArray_real_T *a, const int32_T *nx,
  emxArray_real_T *r6)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int32_T eint;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    real_T absx;
    int32_T j;
    real_T Q;
    j = static_cast<int32_T>(idx);

    // ========================== COPYRIGHT NOTICE ============================
    //  The algorithms for calculating ERF(X) and ERFC(X) are derived
    //  from FDLIBM, which has the following notice:
    //
    //  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
    //
    //  Developed at SunSoft, a Sun Microsystems, Inc. business.
    //  Permission to use, copy, modify, and distribute this
    //  software is freely granted, provided that this notice
    //  is preserved.
    // =============================    END    ================================
    absx = fabs(a->data[j]);
    if (isnan(a->data[j])) {
      Q = a->data[j];
    } else if (isinf(a->data[j])) {
      if (a->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else if (absx < 0.84375) {
      if (absx < 3.7252902984619141E-9) {
        if (absx < 2.8480945388892178E-306) {
          Q = 0.125 * (8.0 * a->data[j] + 1.0270333367641007 * a->data[j]);
        } else {
          Q = a->data[j] + 0.12837916709551259 * a->data[j];
        }
      } else {
        Q = a->data[j] * a->data[j];
        Q = a->data[j] + a->data[j] * ((Q * (Q * (Q * (Q *
          -2.3763016656650163E-5 + -0.0057702702964894416) +
          -0.02848174957559851) + -0.3250421072470015) + 0.12837916709551256) /
          (Q * (Q * (Q * (Q * (Q * -3.9602282787753681E-6 +
          0.00013249473800432164) + 0.0050813062818757656) + 0.0650222499887673)
                + 0.39791722395915535) + 1.0));
      }
    } else if (absx < 1.25) {
      real_T P;
      P = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * -0.0021663755948687908 + 0.035478304325618236)
        + -0.11089469428239668) + 0.31834661990116175) + -0.37220787603570132) +
                          0.41485611868374833) + -0.0023621185607526594;
      Q = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * 0.011984499846799107 + 0.013637083912029051) +
        0.12617121980876164) + 0.071828654414196266) + 0.540397917702171) +
                          0.10642088040084423) + 1.0;
      if (a->data[j] >= 0.0) {
        Q = P / Q + 0.84506291151046753;
      } else {
        Q = -0.84506291151046753 - P / Q;
      }
    } else if (absx > 6.0) {
      if (a->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else {
      real_T P;
      real_T R;
      int32_T ix;
      Q = 1.0 / (absx * absx);
      if (absx < 2.8571434020996094) {
        R = Q * (Q * (Q * (Q * (Q * (Q * (Q * -9.8143293441691455 +
          -81.2874355063066) + -184.60509290671104) + -162.39666946257347) +
                           -62.375332450326006) + -10.558626225323291) +
                 -0.69385857270718176) + -0.0098649440348471482;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * (Q * -0.0604244152148581 +
          6.5702497703192817) + 108.63500554177944) + 429.00814002756783) +
                    645.38727173326788) + 434.56587747522923) +
                      137.65775414351904) + 19.651271667439257) + 1.0;
      } else {
        R = Q * (Q * (Q * (Q * (Q * (Q * -483.5191916086514 +
          -1025.0951316110772) + -637.56644336838963) + -160.63638485582192) +
                      -17.757954917754752) + -0.799283237680523) +
          -0.0098649429247001;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * -22.440952446585818 +
          474.52854120695537) + 2553.0504064331644) + 3199.8582195085955) +
                           1536.729586084437) + 325.79251299657392) +
                 30.338060743482458) + 1.0;
      }

      if (!static_cast<int32_T>(isnan(absx))) {
        Q = frexp(absx, &eint);
        ix = eint;
      } else {
        Q = absx;
        ix = 0;
      }

      Q = floor(Q * 2.097152E+6) / 2.097152E+6 * rt_powd_snf(2.0,
        static_cast<real_T>(ix));
      Q = exp(-Q * Q - 0.5625) * exp((Q - absx) * (Q + absx) + R / P) / absx;
      if (a->data[j] < 0.0) {
        Q--;
      } else {
        Q = 1.0 - Q;
      }
    }

    r6->data[j] = Q;
  }
}

static __global__ __launch_bounds__(32, 1) void li_reflectivity_calculation_gpu(
  const real_T minval[2], real_T dataBoxSize[2])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 2) {
    dataBoxSize[i1] -= minval[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  lj_reflectivity_calculation_gpu(const emxArray_boolean_T *r33, const
  emxArray_boolean_T *trianglesToRefine, emxArray_boolean_T *segmentsToSplit)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(trianglesToRefine->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    segmentsToSplit->data[i1] = ((static_cast<int32_T>(trianglesToRefine->
      data[i1])) || (static_cast<int32_T>(r33->data[i1])));
  }
}

static __global__ __launch_bounds__(64, 1) void lk_reflectivity_calculation_gpu(
  const real_T bFactor, const real_T thisData[153], boolean_T x[51])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 51) {
    x[i1] = (thisData[i1] > bFactor);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ll_reflectivity_calculation_gpu(const emxArray_real_T *reflect, const real_T
  shifted_dat_data[153], const int32_T shifted_dat_size[2], const int32_T kEnd,
  emxArray_real_T *z)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(kEnd);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    z->data[i1] = (shifted_dat_data[i1 + shifted_dat_size[0]] - reflect->data[i1
                   + reflect->size[0]]) / shifted_dat_data[i1 +
      (shifted_dat_size[0] << 1)];
  }
}

static __global__ __launch_bounds__(32, 1) void m_reflectivity_calculation_gpu_(
  const struct0_T problemDef, const cell_10 *problemDef_cells, real_T
  thisOutLayer[5])
{
  uint32_T threadId;
  int32_T ix;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  ix = static_cast<int32_T>(threadId);
  if (ix < 4) {
    if (!static_cast<int32_T>(isnan(problemDef_cells->f6[0].f1[ix]))) {
      thisOutLayer[ix] = problemDef.params[static_cast<int32_T>
        (problemDef_cells->f6[0].f1[ix]) - 1];
    } else {
      thisOutLayer[ix] = CUDART_NAN;
    }
  }
}

static __global__ __launch_bounds__(1024, 1) void
  mb_reflectivity_calculation_gpu(const real_T *layerThicks, const real_T l,
  const emxArray_real_T *x, emxArray_real_T *a)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(x->size[0] * x->size[1] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    a->data[i1] = (x->data[i1] - l) / *layerThicks;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  mc_reflectivity_calculation_gpu(const real_T *layerThicks, const
  emxArray_real_T *sldProfile, const int32_T kEnd, emxArray_boolean_T *x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(kEnd);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    x->data[i1] = (sldProfile->data[i1] == *layerThicks);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  md_reflectivity_calculation_gpu(const emxArray_real_T *x, const
  emxArray_real_T *z1, const emxArray_real_T *b_z1, const emxArray_real_T
  *secondStepSquared, const emxArray_real_T *firstStepSquared, emxArray_creal_T *
  b_x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  real_T Q;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(firstStepSquared->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    Q = ((firstStepSquared->data[i1] + secondStepSquared->data[i1]) -
         (b_z1->data[i1] + z1->data[i1])) / 2.0;
    Q /= x->data[i1];
    b_x->data[i1].re = Q;
    b_x->data[i1].im = 0.0;
  }
}

static __global__ __launch_bounds__(32, 1) void me_reflectivity_calculation_gpu(
  const emxArray_real_T *dataPoints, emxArray_int32_T *idx)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    idx->data[dataPoints->size[0] - 1] = dataPoints->size[0];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  mf_reflectivity_calculation_gpu(const emxArray_real_T *simXdata,
  emxArray_real_T *dummydata)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(simXdata->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    dummydata->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(32, 1) void mg_reflectivity_calculation_gpu(
  const struct0_T problemDef, const cell_10 *problemDef_cells, real_T
  thisOutLayer[5])
{
  uint32_T threadId;
  int32_T ix;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  ix = static_cast<int32_T>(threadId);
  if (ix < 4) {
    if (!static_cast<int32_T>(isnan(problemDef_cells->f6[3].f1[ix]))) {
      thisOutLayer[ix] = problemDef.params[static_cast<int32_T>
        (problemDef_cells->f6[3].f1[ix]) - 1];
    } else {
      thisOutLayer[ix] = CUDART_NAN;
    }
  }
}

static __global__ __launch_bounds__(1024, 1) void
  mh_reflectivity_calculation_gpu(const emxArray_real_T *b, const int32_T *nx,
  emxArray_real_T *r7)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int32_T eint;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    real_T absx;
    int32_T j;
    real_T Q;
    j = static_cast<int32_T>(idx);

    // ========================== COPYRIGHT NOTICE ============================
    //  The algorithms for calculating ERF(X) and ERFC(X) are derived
    //  from FDLIBM, which has the following notice:
    //
    //  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
    //
    //  Developed at SunSoft, a Sun Microsystems, Inc. business.
    //  Permission to use, copy, modify, and distribute this
    //  software is freely granted, provided that this notice
    //  is preserved.
    // =============================    END    ================================
    absx = fabs(b->data[j]);
    if (isnan(b->data[j])) {
      Q = b->data[j];
    } else if (isinf(b->data[j])) {
      if (b->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else if (absx < 0.84375) {
      if (absx < 3.7252902984619141E-9) {
        if (absx < 2.8480945388892178E-306) {
          Q = 0.125 * (8.0 * b->data[j] + 1.0270333367641007 * b->data[j]);
        } else {
          Q = b->data[j] + 0.12837916709551259 * b->data[j];
        }
      } else {
        Q = b->data[j] * b->data[j];
        Q = b->data[j] + b->data[j] * ((Q * (Q * (Q * (Q *
          -2.3763016656650163E-5 + -0.0057702702964894416) +
          -0.02848174957559851) + -0.3250421072470015) + 0.12837916709551256) /
          (Q * (Q * (Q * (Q * (Q * -3.9602282787753681E-6 +
          0.00013249473800432164) + 0.0050813062818757656) + 0.0650222499887673)
                + 0.39791722395915535) + 1.0));
      }
    } else if (absx < 1.25) {
      real_T P;
      P = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * -0.0021663755948687908 + 0.035478304325618236)
        + -0.11089469428239668) + 0.31834661990116175) + -0.37220787603570132) +
                          0.41485611868374833) + -0.0023621185607526594;
      Q = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * 0.011984499846799107 + 0.013637083912029051) +
        0.12617121980876164) + 0.071828654414196266) + 0.540397917702171) +
                          0.10642088040084423) + 1.0;
      if (b->data[j] >= 0.0) {
        Q = P / Q + 0.84506291151046753;
      } else {
        Q = -0.84506291151046753 - P / Q;
      }
    } else if (absx > 6.0) {
      if (b->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else {
      real_T P;
      real_T R;
      int32_T ix;
      Q = 1.0 / (absx * absx);
      if (absx < 2.8571434020996094) {
        R = Q * (Q * (Q * (Q * (Q * (Q * (Q * -9.8143293441691455 +
          -81.2874355063066) + -184.60509290671104) + -162.39666946257347) +
                           -62.375332450326006) + -10.558626225323291) +
                 -0.69385857270718176) + -0.0098649440348471482;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * (Q * -0.0604244152148581 +
          6.5702497703192817) + 108.63500554177944) + 429.00814002756783) +
                    645.38727173326788) + 434.56587747522923) +
                      137.65775414351904) + 19.651271667439257) + 1.0;
      } else {
        R = Q * (Q * (Q * (Q * (Q * (Q * -483.5191916086514 +
          -1025.0951316110772) + -637.56644336838963) + -160.63638485582192) +
                      -17.757954917754752) + -0.799283237680523) +
          -0.0098649429247001;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * -22.440952446585818 +
          474.52854120695537) + 2553.0504064331644) + 3199.8582195085955) +
                           1536.729586084437) + 325.79251299657392) +
                 30.338060743482458) + 1.0;
      }

      if (!static_cast<int32_T>(isnan(absx))) {
        Q = frexp(absx, &eint);
        ix = eint;
      } else {
        Q = absx;
        ix = 0;
      }

      Q = floor(Q * 2.097152E+6) / 2.097152E+6 * rt_powd_snf(2.0,
        static_cast<real_T>(ix));
      Q = exp(-Q * Q - 0.5625) * exp((Q - absx) * (Q + absx) + R / P) / absx;
      if (b->data[j] < 0.0) {
        Q--;
      } else {
        Q = 1.0 - Q;
      }
    }

    r7->data[j] = Q;
  }
}

static __global__ __launch_bounds__(32, 1) void mi_reflectivity_calculation_gpu(
  const int32_T vlen, const emxArray_real_T *dataPoints, real_T minval[2])
{
  uint32_T threadId;
  int32_T j;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  j = static_cast<int32_T>(threadId);
  if (j < 2) {
    int32_T iv0;
    iv0 = (j * (dataPoints->size[0] - 1) + j) + 1;
    minval[j] = dataPoints->data[(iv0 - 1) % dataPoints->size[0] +
      dataPoints->size[0] * ((iv0 - 1) / dataPoints->size[0])];
    for (int32_T i = 0; i <= vlen - 2; i++) {
      int32_T ix;
      boolean_T xneg;
      ix = (iv0 + i) + 1;
      if (isnan(dataPoints->data[(ix - 1) % dataPoints->size[0] +
                dataPoints->size[0] * ((ix - 1) / dataPoints->size[0])])) {
        xneg = false;
      } else if (isnan(minval[j])) {
        xneg = true;
      } else {
        xneg = (minval[j] > dataPoints->data[(ix - 1) % dataPoints->size[0] +
                dataPoints->size[0] * ((ix - 1) / dataPoints->size[0])]);
      }

      if (xneg) {
        minval[j] = dataPoints->data[(ix - 1) % dataPoints->size[0] +
          dataPoints->size[0] * ((ix - 1) / dataPoints->size[0])];
      }
    }
  }
}

static __global__ __launch_bounds__(1024, 1) void
  mj_reflectivity_calculation_gpu(const int32_T *xoffset, emxArray_real_T
  *newDataPoints)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*xoffset * 2 - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    newDataPoints->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  mk_reflectivity_calculation_gpu(const real_T thisData[153], const int32_T
  shifted_dat_size[2], const int32_T kEnd, const int32_T *qEnd, real_T
  shifted_dat_data[153])
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = (static_cast<int64_T>(*qEnd - kEnd) + 1L) * 3L - 1L;
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    int32_T iv0;
    iv0 = static_cast<int32_T>(idx % (static_cast<uint32_T>(*qEnd - kEnd) + 1U));
    i1 = static_cast<int32_T>((idx - static_cast<uint32_T>(iv0)) / (static_cast<
      uint32_T>(*qEnd - kEnd) + 1U));
    shifted_dat_data[iv0 + shifted_dat_size[0] * i1] = thisData[(kEnd + iv0) +
      51 * i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ml_reflectivity_calculation_gpu(const emxArray_real_T *z, const int32_T *nx,
  emxArray_real_T *z1)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    z1->data[j] = rt_powd_snf(z->data[j], 2.0);
  }
}

static __global__ __launch_bounds__(32, 1) void n_reflectivity_calculation_gpu_(
  const cell_10 *problemDef_cells, real_T thisOutLayer[5])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    thisOutLayer[4] = problemDef_cells->f6[0].f1[4];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  nb_reflectivity_calculation_gpu(const real_T bFactor, const real_T r, const
  emxArray_real_T *x, emxArray_real_T *b)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(x->size[0] * x->size[1] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    b->data[i1] = (x->data[i1] - r) / bFactor;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  nc_reflectivity_calculation_gpu(const emxArray_real_T *sldProfile, const
  real_T *layerThicks, const int32_T kEnd, emxArray_boolean_T *x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(kEnd);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    x->data[i1] = (*layerThicks > sldProfile->data[i1]);
  }
}

static __global__ __launch_bounds__(32, 1) void nd_reflectivity_calculation_gpu(
  const emxArray_creal_T *x, int32_T *nx)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    *nx = x->size[0];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ne_reflectivity_calculation_gpu(const int32_T j, const emxArray_real_T
  *dataPoints, const emxArray_int32_T *idx, const int32_T *xoffset,
  emxArray_real_T *ycol)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T b_idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*xoffset - 1);
  for (b_idx = threadId; b_idx <= static_cast<uint32_T>(loopEnd); b_idx +=
       threadStride) {
    int32_T i;
    i = static_cast<int32_T>(b_idx);
    ycol->data[i] = dataPoints->data[(idx->data[i] + dataPoints->size[0] * j) -
      1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  nf_reflectivity_calculation_gpu(const emxArray_real_T *simRef, const struct0_T
  problemDef, const emxArray_real_T *simXdata, const int32_T *xoffset, const
  int32_T kEnd, emxArray_real_T *dummydata)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  real_T P;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(kEnd - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    int32_T iv0;
    int32_T b_j;
    j = static_cast<int32_T>(idx);
    P = 0.0;
    dummydata->data[j] = 0.0;
    if (j + 1 > 10) {
      iv0 = -10;
    } else {
      iv0 = -j;
    }

    //     try
    if (j + 1 < *xoffset - 10) {
      b_j = 10;
    } else {
      b_j = (*xoffset - j) - 1;
    }

    b_j = (b_j - iv0) + 1;
    for (int32_T ix = 0; ix < b_j; ix++) {
      int32_T i;
      real_T Q;
      i = iv0 + ix;
      Q = (simXdata->data[j + i] - simXdata->data[j]) / ((problemDef.res +
        0.0001) * simXdata->data[j]);
      Q = exp(-(Q * Q));
      P += Q;
      dummydata->data[j] += simRef->data[i + j] * Q;
    }

    if (P != 0.0) {
      dummydata->data[j] /= P;
    }
  }
}

static __global__ __launch_bounds__(32, 1) void ng_reflectivity_calculation_gpu(
  const cell_10 *problemDef_cells, real_T thisOutLayer[5])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    thisOutLayer[4] = problemDef_cells->f6[3].f1[4];
  }
}

static __global__ __launch_bounds__(32, 1) void nh_reflectivity_calculation_gpu(
  const emxArray_real_T *Lays, int32_T *qEnd)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    *qEnd = Lays->size[0];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ni_reflectivity_calculation_gpu(const emxArray_real_T *r15, const
  emxArray_real_T *b, const emxArray_real_T *dataPoints, const int32_T kEnd,
  emxArray_real_T *normalizedData)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = (static_cast<int64_T>(kEnd) + 1L) * 2L - 1L;
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    int32_T iv0;
    iv0 = static_cast<int32_T>(idx % (static_cast<uint32_T>(kEnd) + 1U));
    i1 = static_cast<int32_T>((idx - static_cast<uint32_T>(iv0)) /
      (static_cast<uint32_T>(kEnd) + 1U));
    normalizedData->data[iv0 + normalizedData->size[0] * i1] = dataPoints->
      data[iv0 + dataPoints->size[0] * i1] / b->data[iv0 + b->size[0] * i1] -
      r15->data[iv0 + r15->size[0] * i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  nj_reflectivity_calculation_gpu(const emxArray_boolean_T *segmentsToSplit,
  const int32_T *nx, emxArray_boolean_T *r24)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    r24->data[i1] = segmentsToSplit->data[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  nk_reflectivity_calculation_gpu(const real_T reps, const real_T *layerThicks,
  const real_T bFactor, emxArray_real_T *firstSection)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(static_cast<int32_T>((bFactor - *layerThicks) /
    reps));
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    firstSection->data[i1] = *layerThicks + reps * static_cast<real_T>(i1);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  nl_reflectivity_calculation_gpu(const emxArray_real_T *z1, real_T terms_data
  [51])
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(z1->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    terms_data[i1] = z1->data[i1];
  }
}

static __global__ __launch_bounds__(32, 1) void o_reflectivity_calculation_gpu_(
  const real_T thisOutLayer[5], cell_wrap_2 outParameterisedLayers[4])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 5) {
    outParameterisedLayers[0].f1[i1] = thisOutLayer[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ob_reflectivity_calculation_gpu(const emxArray_real_T *a, const int32_T *nx,
  emxArray_real_T *r8)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int32_T eint;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    real_T absx;
    int32_T j;
    real_T Q;
    j = static_cast<int32_T>(idx);

    // ========================== COPYRIGHT NOTICE ============================
    //  The algorithms for calculating ERF(X) and ERFC(X) are derived
    //  from FDLIBM, which has the following notice:
    //
    //  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
    //
    //  Developed at SunSoft, a Sun Microsystems, Inc. business.
    //  Permission to use, copy, modify, and distribute this
    //  software is freely granted, provided that this notice
    //  is preserved.
    // =============================    END    ================================
    absx = fabs(a->data[j]);
    if (isnan(a->data[j])) {
      Q = a->data[j];
    } else if (isinf(a->data[j])) {
      if (a->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else if (absx < 0.84375) {
      if (absx < 3.7252902984619141E-9) {
        if (absx < 2.8480945388892178E-306) {
          Q = 0.125 * (8.0 * a->data[j] + 1.0270333367641007 * a->data[j]);
        } else {
          Q = a->data[j] + 0.12837916709551259 * a->data[j];
        }
      } else {
        Q = a->data[j] * a->data[j];
        Q = a->data[j] + a->data[j] * ((Q * (Q * (Q * (Q *
          -2.3763016656650163E-5 + -0.0057702702964894416) +
          -0.02848174957559851) + -0.3250421072470015) + 0.12837916709551256) /
          (Q * (Q * (Q * (Q * (Q * -3.9602282787753681E-6 +
          0.00013249473800432164) + 0.0050813062818757656) + 0.0650222499887673)
                + 0.39791722395915535) + 1.0));
      }
    } else if (absx < 1.25) {
      real_T P;
      P = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * -0.0021663755948687908 + 0.035478304325618236)
        + -0.11089469428239668) + 0.31834661990116175) + -0.37220787603570132) +
                          0.41485611868374833) + -0.0023621185607526594;
      Q = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * 0.011984499846799107 + 0.013637083912029051) +
        0.12617121980876164) + 0.071828654414196266) + 0.540397917702171) +
                          0.10642088040084423) + 1.0;
      if (a->data[j] >= 0.0) {
        Q = P / Q + 0.84506291151046753;
      } else {
        Q = -0.84506291151046753 - P / Q;
      }
    } else if (absx > 6.0) {
      if (a->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else {
      real_T P;
      real_T R;
      int32_T ix;
      Q = 1.0 / (absx * absx);
      if (absx < 2.8571434020996094) {
        R = Q * (Q * (Q * (Q * (Q * (Q * (Q * -9.8143293441691455 +
          -81.2874355063066) + -184.60509290671104) + -162.39666946257347) +
                           -62.375332450326006) + -10.558626225323291) +
                 -0.69385857270718176) + -0.0098649440348471482;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * (Q * -0.0604244152148581 +
          6.5702497703192817) + 108.63500554177944) + 429.00814002756783) +
                    645.38727173326788) + 434.56587747522923) +
                      137.65775414351904) + 19.651271667439257) + 1.0;
      } else {
        R = Q * (Q * (Q * (Q * (Q * (Q * -483.5191916086514 +
          -1025.0951316110772) + -637.56644336838963) + -160.63638485582192) +
                      -17.757954917754752) + -0.799283237680523) +
          -0.0098649429247001;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * -22.440952446585818 +
          474.52854120695537) + 2553.0504064331644) + 3199.8582195085955) +
                           1536.729586084437) + 325.79251299657392) +
                 30.338060743482458) + 1.0;
      }

      if (!static_cast<int32_T>(isnan(absx))) {
        Q = frexp(absx, &eint);
        ix = eint;
      } else {
        Q = absx;
        ix = 0;
      }

      Q = floor(Q * 2.097152E+6) / 2.097152E+6 * rt_powd_snf(2.0,
        static_cast<real_T>(ix));
      Q = exp(-Q * Q - 0.5625) * exp((Q - absx) * (Q + absx) + R / P) / absx;
      if (a->data[j] < 0.0) {
        Q--;
      } else {
        Q = 1.0 - Q;
      }
    }

    r8->data[j] = Q;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  oc_reflectivity_calculation_gpu(const emxArray_real_T *sldProfile, const
  real_T *layerThicks, const int32_T kEnd, emxArray_boolean_T *x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(kEnd);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    x->data[i1] = (*layerThicks < sldProfile->data[i1]);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  od_reflectivity_calculation_gpu(const int32_T *nx, emxArray_creal_T *x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  creal_T u;
  real_T P;
  real_T Q;
  real_T ci;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    if ((static_cast<int32_T>(x->data[j].im == 0.0)) && (!static_cast<int32_T>
         (fabs(x->data[j].re) > 1.0))) {
      u.re = acos(x->data[j].re);
      u.im = 0.0;
    } else {
      real_T yr;
      real_T yi;
      real_T b_yr;
      real_T b_yi;
      boolean_T xneg;
      u.re = x->data[j].re + 1.0;
      u.im = x->data[j].im;
      if (u.im == 0.0) {
        if (u.re < 0.0) {
          yr = 0.0;
          yi = sqrt(-u.re);
        } else {
          yr = sqrt(u.re);
          yi = 0.0;
        }
      } else if (u.re == 0.0) {
        if (u.im < 0.0) {
          yr = sqrt(-u.im / 2.0);
          yi = -yr;
        } else {
          yr = sqrt(u.im / 2.0);
          yi = yr;
        }
      } else if (isnan(u.re)) {
        yr = u.re;
        yi = u.re;
      } else if (isnan(u.im)) {
        yr = u.im;
        yi = u.im;
      } else if (isinf(u.im)) {
        yr = fabs(u.im);
        yi = u.im;
      } else if (isinf(u.re)) {
        if (u.re < 0.0) {
          yr = 0.0;
          yi = u.im * -u.re;
        } else {
          yr = u.re;
          yi = 0.0;
        }
      } else {
        P = fabs(u.re);
        Q = fabs(u.im);
        if ((static_cast<int32_T>(P > 4.4942328371557893E+307)) || (static_cast<
             int32_T>(Q > 4.4942328371557893E+307))) {
          P *= 0.5;
          Q *= 0.5;
          Q = rt_hypotd_snf_device(P, Q);
          if (Q > P) {
            yr = sqrt(Q) * sqrt(P / Q + 1.0);
          } else {
            yr = sqrt(Q) * 1.4142135623730951;
          }
        } else {
          yr = sqrt((rt_hypotd_snf_device(P, Q) + P) * 0.5);
        }

        if (u.re > 0.0) {
          yi = 0.5 * (u.im / yr);
        } else {
          if (u.im < 0.0) {
            yi = -yr;
          } else {
            yi = yr;
          }

          yr = 0.5 * (u.im / yi);
        }
      }

      u.re = 1.0 - x->data[j].re;
      u.im = 0.0 - x->data[j].im;
      if (u.im == 0.0) {
        if (u.re < 0.0) {
          b_yr = 0.0;
          b_yi = sqrt(-u.re);
        } else {
          b_yr = sqrt(u.re);
          b_yi = 0.0;
        }
      } else if (u.re == 0.0) {
        if (u.im < 0.0) {
          b_yr = sqrt(-u.im / 2.0);
          b_yi = -b_yr;
        } else {
          b_yr = sqrt(u.im / 2.0);
          b_yi = b_yr;
        }
      } else if (isnan(u.re)) {
        b_yr = u.re;
        b_yi = u.re;
      } else if (isnan(u.im)) {
        b_yr = u.im;
        b_yi = u.im;
      } else if (isinf(u.im)) {
        b_yr = fabs(u.im);
        b_yi = u.im;
      } else if (isinf(u.re)) {
        if (u.re < 0.0) {
          b_yr = 0.0;
          b_yi = u.im * -u.re;
        } else {
          b_yr = u.re;
          b_yi = 0.0;
        }
      } else {
        P = fabs(u.re);
        Q = fabs(u.im);
        if ((static_cast<int32_T>(P > 4.4942328371557893E+307)) || (static_cast<
             int32_T>(Q > 4.4942328371557893E+307))) {
          P *= 0.5;
          Q *= 0.5;
          Q = rt_hypotd_snf_device(P, Q);
          if (Q > P) {
            b_yr = sqrt(Q) * sqrt(P / Q + 1.0);
          } else {
            b_yr = sqrt(Q) * 1.4142135623730951;
          }
        } else {
          b_yr = sqrt((rt_hypotd_snf_device(P, Q) + P) * 0.5);
        }

        if (u.re > 0.0) {
          b_yi = 0.5 * (u.im / b_yr);
        } else {
          if (u.im < 0.0) {
            b_yi = -b_yr;
          } else {
            b_yi = b_yr;
          }

          b_yr = 0.5 * (u.im / b_yi);
        }
      }

      if ((static_cast<int32_T>(-yi == 0.0)) && (static_cast<int32_T>(b_yi ==
            0.0))) {
        ci = 0.0;
      } else {
        ci = yr * b_yi + -yi * b_yr;
        if ((static_cast<int32_T>((static_cast<int32_T>((static_cast<int32_T>((
                   static_cast<int32_T>((static_cast<int32_T>(isinf(ci))) || (
                     static_cast<int32_T>(isnan(ci))))) && (!static_cast<int32_T>
                   (isnan(yr))))) && (!static_cast<int32_T>(isnan(-yi))))) && (!
               static_cast<int32_T>(isnan(b_yr))))) && (!static_cast<int32_T>
             (isnan(b_yi)))) {
          real_T absre;
          real_T R;
          real_T sar;
          real_T sai;
          real_T absx;
          absre = fabs(yr);
          R = fabs(-yi);
          if (absre > R) {
            if (yr < 0.0) {
              sar = -1.0;
            } else {
              sar = 1.0;
            }

            sai = -yi / absre;
          } else if (R > absre) {
            sar = yr / R;
            if (-yi < 0.0) {
              sai = -1.0;
            } else {
              sai = 1.0;
            }

            absre = R;
          } else {
            if (yr < 0.0) {
              sar = -1.0;
            } else {
              sar = 1.0;
            }

            if (-yi < 0.0) {
              sai = -1.0;
            } else {
              sai = 1.0;
            }
          }

          absx = fabs(b_yr);
          R = fabs(b_yi);
          if (absx > R) {
            if (b_yr < 0.0) {
              P = -1.0;
            } else {
              P = 1.0;
            }

            Q = b_yi / absx;
          } else if (R > absx) {
            P = b_yr / R;
            if (b_yi < 0.0) {
              Q = -1.0;
            } else {
              Q = 1.0;
            }

            absx = R;
          } else {
            if (b_yr < 0.0) {
              P = -1.0;
            } else {
              P = 1.0;
            }

            if (b_yi < 0.0) {
              Q = -1.0;
            } else {
              Q = 1.0;
            }
          }

          if ((static_cast<int32_T>((!static_cast<int32_T>(isinf(absre))) && (!
                 static_cast<int32_T>(isnan(absre))))) && (static_cast<int32_T>
               ((!static_cast<int32_T>(isinf(absx))) && (!static_cast<int32_T>
                 (isnan(absx)))))) {
            xneg = true;
          } else {
            xneg = false;
          }

          if ((static_cast<int32_T>(isnan(ci))) || (static_cast<int32_T>((
                 static_cast<int32_T>(isinf(ci))) && (static_cast<int32_T>(xneg)))))
          {
            ci = sar * Q + sai * P;
            if (ci != 0.0) {
              ci = ci * absre * absx;
            } else {
              if ((static_cast<int32_T>((static_cast<int32_T>(isinf(absre))) &&
                    (static_cast<int32_T>((static_cast<int32_T>(b_yr == 0.0)) ||
                      (static_cast<int32_T>(b_yi == 0.0)))))) ||
                  (static_cast<int32_T>((static_cast<int32_T>(isinf(absx))) && (
                     static_cast<int32_T>((static_cast<int32_T>(yr == 0.0)) || (
                       static_cast<int32_T>(-yi == 0.0))))))) {
                P = yr * b_yi;
                Q = -yi * b_yr;
                if (isnan(P)) {
                  P = 0.0;
                }

                if (isnan(Q)) {
                  Q = 0.0;
                }

                ci = P + Q;
              }
            }
          }
        }
      }

      xneg = (ci < 0.0);
      if (xneg) {
        ci = -ci;
      }

      if (ci >= 2.68435456E+8) {
        ci = log(ci) + 0.69314718055994529;
      } else if (ci > 2.0) {
        ci = log(2.0 * ci + 1.0 / (sqrt(ci * ci + 1.0) + ci));
      } else {
        Q = ci * ci;
        ci += Q / (sqrt(Q + 1.0) + 1.0);
        Q = fabs(ci);
        if ((static_cast<int32_T>(Q > 4.503599627370496E+15)) ||
            (static_cast<int32_T>((static_cast<int32_T>(isinf(ci))) || (
               static_cast<int32_T>(isnan(ci)))))) {
          ci = log(ci + 1.0);
        } else {
          if (!static_cast<int32_T>(Q < 2.2204460492503131E-16)) {
            ci = log(ci + 1.0) * (ci / ((ci + 1.0) - 1.0));
          }
        }
      }

      if (xneg) {
        ci = -ci;
      }

      u.re = 2.0 * rt_atan2d_snf(b_yr, yr);
      u.im = ci;
    }

    x->data[j] = u;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  oe_reflectivity_calculation_gpu(const emxArray_real_T *ycol, const int32_T j,
  const int32_T *xoffset, emxArray_real_T *dataPoints)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*xoffset - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i;
    i = static_cast<int32_T>(idx);
    dataPoints->data[i + dataPoints->size[0] * j] = ycol->data[i];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  of_reflectivity_calculation_gpu(const emxArray_real_T *dummydata,
  emxArray_real_T *Simul)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(dummydata->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    Simul->data[i1 + Simul->size[0]] = dummydata->data[i1];
  }
}

static __global__ __launch_bounds__(32, 1) void og_reflectivity_calculation_gpu(
  const real_T thisOutLayer[5], cell_wrap_2 outParameterisedLayers[4])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 5) {
    outParameterisedLayers[3].f1[i1] = thisOutLayer[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  oh_reflectivity_calculation_gpu(const emxArray_real_T *r7, const
  emxArray_real_T *r6, const real_T *layerThicks, const int32_T *qEnd, const
  int32_T ii_size[1], emxArray_real_T *Lays)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(ii_size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    Lays->data[i1 + Lays->size[0] * *qEnd] = *layerThicks * (r6->data[i1] -
      r7->data[i1]);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  oi_reflectivity_calculation_gpu(const emxArray_real_T *normalizedData, const
  int32_T kEnd, emxArray_real_T *firstStep)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = (static_cast<int64_T>(kEnd - 1) + 1L) * 2L - 1L;
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    int32_T iv0;
    iv0 = static_cast<int32_T>(idx % static_cast<uint32_T>(kEnd));
    i1 = static_cast<int32_T>((idx - static_cast<uint32_T>(iv0)) /
      static_cast<uint32_T>(kEnd));
    firstStep->data[iv0 + firstStep->size[0] * i1] = normalizedData->data[(iv0 +
      normalizedData->size[0] * i1) + 1] - normalizedData->data[iv0 +
      normalizedData->size[0] * i1];
  }
}

static __global__ __launch_bounds__(32, 1) void oj_reflectivity_calculation_gpu(
  const emxArray_boolean_T *segmentsToSplit, emxArray_boolean_T *r24)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    r24->data[segmentsToSplit->size[0]] = false;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ok_reflectivity_calculation_gpu(const real_T reps, const real_T a, const
  real_T *layerThicks, emxArray_real_T *lastSection)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(static_cast<int32_T>((*layerThicks - a) / reps));
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    lastSection->data[i1] = a + reps * static_cast<real_T>(i1);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ol_reflectivity_calculation_gpu(const emxArray_real_T *z1, emxArray_boolean_T *
  x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(z1->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    x->data[i1] = (z1->data[i1] == CUDART_INF);
  }
}

static __global__ __launch_bounds__(32, 1) void p_reflectivity_calculation_gpu_(
  const struct0_T problemDef, const cell_10 *problemDef_cells, real_T
  thisOutLayer[5])
{
  uint32_T threadId;
  int32_T ix;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  ix = static_cast<int32_T>(threadId);
  if (ix < 4) {
    if (!static_cast<int32_T>(isnan(problemDef_cells->f6[1].f1[ix]))) {
      thisOutLayer[ix] = problemDef.params[static_cast<int32_T>
        (problemDef_cells->f6[1].f1[ix]) - 1];
    } else {
      thisOutLayer[ix] = CUDART_NAN;
    }
  }
}

static __global__ __launch_bounds__(1024, 1) void
  pb_reflectivity_calculation_gpu(const emxArray_real_T *b, const int32_T *nx,
  emxArray_real_T *r9)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int32_T eint;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    real_T absx;
    int32_T j;
    real_T Q;
    j = static_cast<int32_T>(idx);

    // ========================== COPYRIGHT NOTICE ============================
    //  The algorithms for calculating ERF(X) and ERFC(X) are derived
    //  from FDLIBM, which has the following notice:
    //
    //  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
    //
    //  Developed at SunSoft, a Sun Microsystems, Inc. business.
    //  Permission to use, copy, modify, and distribute this
    //  software is freely granted, provided that this notice
    //  is preserved.
    // =============================    END    ================================
    absx = fabs(b->data[j]);
    if (isnan(b->data[j])) {
      Q = b->data[j];
    } else if (isinf(b->data[j])) {
      if (b->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else if (absx < 0.84375) {
      if (absx < 3.7252902984619141E-9) {
        if (absx < 2.8480945388892178E-306) {
          Q = 0.125 * (8.0 * b->data[j] + 1.0270333367641007 * b->data[j]);
        } else {
          Q = b->data[j] + 0.12837916709551259 * b->data[j];
        }
      } else {
        Q = b->data[j] * b->data[j];
        Q = b->data[j] + b->data[j] * ((Q * (Q * (Q * (Q *
          -2.3763016656650163E-5 + -0.0057702702964894416) +
          -0.02848174957559851) + -0.3250421072470015) + 0.12837916709551256) /
          (Q * (Q * (Q * (Q * (Q * -3.9602282787753681E-6 +
          0.00013249473800432164) + 0.0050813062818757656) + 0.0650222499887673)
                + 0.39791722395915535) + 1.0));
      }
    } else if (absx < 1.25) {
      real_T P;
      P = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * -0.0021663755948687908 + 0.035478304325618236)
        + -0.11089469428239668) + 0.31834661990116175) + -0.37220787603570132) +
                          0.41485611868374833) + -0.0023621185607526594;
      Q = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * 0.011984499846799107 + 0.013637083912029051) +
        0.12617121980876164) + 0.071828654414196266) + 0.540397917702171) +
                          0.10642088040084423) + 1.0;
      if (b->data[j] >= 0.0) {
        Q = P / Q + 0.84506291151046753;
      } else {
        Q = -0.84506291151046753 - P / Q;
      }
    } else if (absx > 6.0) {
      if (b->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else {
      real_T P;
      real_T R;
      int32_T ix;
      Q = 1.0 / (absx * absx);
      if (absx < 2.8571434020996094) {
        R = Q * (Q * (Q * (Q * (Q * (Q * (Q * -9.8143293441691455 +
          -81.2874355063066) + -184.60509290671104) + -162.39666946257347) +
                           -62.375332450326006) + -10.558626225323291) +
                 -0.69385857270718176) + -0.0098649440348471482;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * (Q * -0.0604244152148581 +
          6.5702497703192817) + 108.63500554177944) + 429.00814002756783) +
                    645.38727173326788) + 434.56587747522923) +
                      137.65775414351904) + 19.651271667439257) + 1.0;
      } else {
        R = Q * (Q * (Q * (Q * (Q * (Q * -483.5191916086514 +
          -1025.0951316110772) + -637.56644336838963) + -160.63638485582192) +
                      -17.757954917754752) + -0.799283237680523) +
          -0.0098649429247001;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * -22.440952446585818 +
          474.52854120695537) + 2553.0504064331644) + 3199.8582195085955) +
                           1536.729586084437) + 325.79251299657392) +
                 30.338060743482458) + 1.0;
      }

      if (!static_cast<int32_T>(isnan(absx))) {
        Q = frexp(absx, &eint);
        ix = eint;
      } else {
        Q = absx;
        ix = 0;
      }

      Q = floor(Q * 2.097152E+6) / 2.097152E+6 * rt_powd_snf(2.0,
        static_cast<real_T>(ix));
      Q = exp(-Q * Q - 0.5625) * exp((Q - absx) * (Q + absx) + R / P) / absx;
      if (b->data[j] < 0.0) {
        Q--;
      } else {
        Q = 1.0 - Q;
      }
    }

    r9->data[j] = Q;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  pc_reflectivity_calculation_gpu(const emxArray_real_T *sldProfile, const
  emxArray_int32_T *ii, emxArray_real_T *r11)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(ii->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    r11->data[i1] = sldProfile->data[(ii->data[i1] + sldProfile->size[0]) - 1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  pd_reflectivity_calculation_gpu(const emxArray_creal_T *x, const
  emxArray_real_T *dataPoints, emxArray_boolean_T *trianglesToRefine)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(dataPoints->size[0] - 3);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    trianglesToRefine->data[i1] = (x->data[i1].re < 2.1991148575128552);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  pe_reflectivity_calculation_gpu(const emxArray_int32_T *iwork, const int32_T j,
  const int32_T kEnd, emxArray_int32_T *idx)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T b_idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(kEnd - 1);
  for (b_idx = threadId; b_idx <= static_cast<uint32_T>(loopEnd); b_idx +=
       threadStride) {
    int32_T b_j;
    b_j = static_cast<int32_T>(b_idx);
    idx->data[(j + b_j) - 1] = iwork->data[b_j];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  pf_reflectivity_calculation_gpu(const emxArray_real_T *Simul, const int32_T
  kEnd, const int32_T *qEnd, emxArray_real_T *reflect)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = (static_cast<int64_T>(*qEnd - kEnd) + 1L) * 2L - 1L;
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    int32_T iv0;
    iv0 = static_cast<int32_T>(idx % (static_cast<uint32_T>(*qEnd - kEnd) + 1U));
    i1 = static_cast<int32_T>((idx - static_cast<uint32_T>(iv0)) / (static_cast<
      uint32_T>(*qEnd - kEnd) + 1U));
    reflect->data[iv0 + reflect->size[0] * i1] = Simul->data[(kEnd + iv0) +
      Simul->size[0] * i1];
  }
}

static __global__ __launch_bounds__(32, 1) void pg_reflectivity_calculation_gpu(
  const cell_wrap_2 outParameterisedLayers[4], const cell_10 *problemDef_cells,
  const int32_T i, real_T thisContrastLayers[10])
{
  uint32_T threadId;
  int32_T b_i;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId % 5U);
  b_i = static_cast<int32_T>((threadId - static_cast<uint32_T>(i1)) / 5U);
  if (b_i < 2) {
    thisContrastLayers[b_i + (i1 << 1)] = outParameterisedLayers
      [static_cast<int32_T>(problemDef_cells->f5[i].f1[b_i]) - 1].f1[i1];
  }
}

static __global__ __launch_bounds__(32, 1) void ph_reflectivity_calculation_gpu(
  const emxArray_real_T *Lays, int32_T *qEnd)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    *qEnd = Lays->size[0];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  pi_reflectivity_calculation_gpu(const emxArray_real_T *normalizedData, const
  int32_T kEnd, emxArray_real_T *secondStep)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = (static_cast<int64_T>(kEnd - 2) + 1L) * 2L - 1L;
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    int32_T iv0;
    iv0 = static_cast<int32_T>(idx % (static_cast<uint32_T>(kEnd) - 1U));
    i1 = static_cast<int32_T>((idx - static_cast<uint32_T>(iv0)) /
      (static_cast<uint32_T>(kEnd) - 1U));
    secondStep->data[iv0 + secondStep->size[0] * i1] = normalizedData->data[(iv0
      + normalizedData->size[0] * i1) + 2] - normalizedData->data[(iv0 +
      normalizedData->size[0] * i1) + 1];
  }
}

static __global__ __launch_bounds__(32, 1) void pj_reflectivity_calculation_gpu
  (emxArray_boolean_T *r26)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    r26->data[0] = false;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  pk_reflectivity_calculation_gpu(const emxArray_real_T *firstSection, const
  int32_T vstride, emxArray_real_T *simXdata)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(vstride);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    simXdata->data[i1] = firstSection->data[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  pl_reflectivity_calculation_gpu(const emxArray_int8_T *ii, real_T terms_data
  [51])
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(ii->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    terms_data[static_cast<int32_T>(ii->data[i1]) - 1] = 0.0;
  }
}

static __global__ __launch_bounds__(32, 1) void q_reflectivity_calculation_gpu_(
  const cell_10 *problemDef_cells, real_T thisOutLayer[5])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    thisOutLayer[4] = problemDef_cells->f6[1].f1[4];
  }
}

static __global__ __launch_bounds__(32, 1) void qb_reflectivity_calculation_gpu(
  const emxArray_real_T *Lays, int32_T *xoffset)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    *xoffset = Lays->size[0];
  }
}

static __global__ __launch_bounds__(64, 1) void qc_reflectivity_calculation_gpu(
  const real_T hiVal[50], const real_T y[50], real_T b_y[100])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 50) {
    // end
    // dataPoints = [initialDomain(:), func(initialDomain(:))];
    b_y[i1] = y[i1];
    b_y[i1 + 50] = hiVal[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  qd_reflectivity_calculation_gpu(const emxArray_boolean_T *trianglesToRefine,
  const int32_T *nx, emxArray_boolean_T *b_trianglesToRefine)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    b_trianglesToRefine->data[i1] = trianglesToRefine->data[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  qe_reflectivity_calculation_gpu(const emxArray_real_T *dataPoints,
  emxArray_real_T *layers)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>((dataPoints->size[0] - 1) * 3 - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    layers->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  qf_reflectivity_calculation_gpu(const real_T *layerThicks, const
  emxArray_real_T *Simul, const int32_T kEnd, const int32_T *qEnd,
  emxArray_real_T *reflect)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = (static_cast<int64_T>(*qEnd - kEnd) + 1L) * 2L - 1L;
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    int32_T iv0;
    iv0 = static_cast<int32_T>(idx % (static_cast<uint32_T>(*qEnd - kEnd) + 1U));
    i1 = static_cast<int32_T>((idx - static_cast<uint32_T>(iv0)) / (static_cast<
      uint32_T>(*qEnd - kEnd) + 1U));
    reflect->data[iv0 + reflect->size[0] * i1] = Simul->data[(kEnd + iv0) +
      Simul->size[0] * i1] + *layerThicks;
  }
}

static __global__ __launch_bounds__(160, 1) void qg_reflectivity_calculation_gpu
  (const cell_10 *problemDef_cells, const int32_T i, real_T thisData[153])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 153) {
    //  For the other parameters, we extract the correct ones from the input
    //  arrays
    //  Substrate roughness is always first parameter for standard layers
    thisData[i1] = problemDef_cells->f2[i].f1[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  qh_reflectivity_calculation_gpu(const emxArray_real_T *r3, const
  emxArray_real_T *r2, const real_T a, const int32_T *qEnd, const int32_T
  ii_size[1], emxArray_real_T *Lays)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(ii_size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    Lays->data[i1 + Lays->size[0] * *qEnd] = a * (r2->data[i1] - r3->data[i1]);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  qi_reflectivity_calculation_gpu(const emxArray_real_T *normalizedData, const
  int32_T kEnd, emxArray_real_T *longStep)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = (static_cast<int64_T>(kEnd - 2) + 1L) * 2L - 1L;
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    int32_T iv0;
    iv0 = static_cast<int32_T>(idx % (static_cast<uint32_T>(kEnd) - 1U));
    i1 = static_cast<int32_T>((idx - static_cast<uint32_T>(iv0)) / (static_cast<
      uint32_T>(kEnd) - 1U));
    longStep->data[iv0 + longStep->size[0] * i1] = normalizedData->data[(iv0 +
      normalizedData->size[0] * i1) + 2] - normalizedData->data[iv0 +
      normalizedData->size[0] * i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  qj_reflectivity_calculation_gpu(const emxArray_boolean_T *segmentsToSplit,
  const int32_T *nx, emxArray_boolean_T *r26)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    r26->data[i1 + 1] = segmentsToSplit->data[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  qk_reflectivity_calculation_gpu(const emxArray_real_T *simXdata,
  emxArray_real_T *Simul)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(simXdata->size[0] * 2 - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    Simul->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(32, 1) void ql_reflectivity_calculation_gpu(
  const real_T terms_data[51], real_T *layerThicks)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    *layerThicks = terms_data[0];
  }
}

static __global__ __launch_bounds__(32, 1) void r_reflectivity_calculation_gpu_(
  const real_T thisOutLayer[5], cell_wrap_2 outParameterisedLayers[4])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 5) {
    outParameterisedLayers[1].f1[i1] = thisOutLayer[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  rb_reflectivity_calculation_gpu(const emxArray_real_T *r9, const
  emxArray_real_T *r8, const real_T *layerThicks, const int32_T *qEnd, const
  int32_T ii_size[1], emxArray_real_T *Lays)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(ii_size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    Lays->data[i1 + Lays->size[0] * *qEnd] = *layerThicks * (r8->data[i1] -
      r9->data[i1]);
  }
}

static __global__ __launch_bounds__(128, 1) void rc_reflectivity_calculation_gpu
  (const real_T y[100], emxArray_real_T *dataPoints)
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 100) {
    dataPoints->data[i1] = y[i1];
  }
}

static __global__ __launch_bounds__(32, 1) void rd_reflectivity_calculation_gpu(
  const emxArray_boolean_T *trianglesToRefine, emxArray_boolean_T
  *b_trianglesToRefine)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    b_trianglesToRefine->data[trianglesToRefine->size[0]] = false;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  re_reflectivity_calculation_gpu(const emxArray_real_T *dataPoints, const
  int32_T kEnd, emxArray_real_T *layers)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(kEnd - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    real_T Q;
    int32_T ix;
    ix = static_cast<int32_T>(idx);
    if (dataPoints->data[(ix + dataPoints->size[0]) + 1] > dataPoints->data[ix +
        dataPoints->size[0]]) {
      Q = (dataPoints->data[(ix + dataPoints->size[0]) + 1] - dataPoints->
           data[ix + dataPoints->size[0]]) / 2.0 + dataPoints->data[ix +
        dataPoints->size[0]];
    } else {
      Q = (dataPoints->data[ix + dataPoints->size[0]] - dataPoints->data[(ix +
            dataPoints->size[0]) + 1]) / 2.0 + dataPoints->data[(ix +
        dataPoints->size[0]) + 1];
    }

    layers->data[ix] = dataPoints->data[ix + 1] - dataPoints->data[ix];
    layers->data[ix + layers->size[0]] = Q;
    layers->data[ix + (layers->size[0] << 1)] = 2.2204460492503131E-16;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  rf_reflectivity_calculation_gpu(const real_T *layerThicks, const int32_T kEnd,
  emxArray_real_T *Simul)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(kEnd - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    Simul->data[i1] += *layerThicks;
  }
}

static __global__ __launch_bounds__(32, 1) void rg_reflectivity_calculation_gpu
  (real_T layers_data[10])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 10) {
    layers_data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  rh_reflectivity_calculation_gpu(const emxArray_real_T *Lays, const int32_T
  vstride, emxArray_real_T *SLD)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(vstride - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    SLD->data[j] = Lays->data[j];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ri_reflectivity_calculation_gpu(const emxArray_real_T *firstStep, const
  int32_T *nx, emxArray_real_T *z1)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    z1->data[j] = rt_powd_snf(firstStep->data[j], 2.0);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  rj_reflectivity_calculation_gpu(const emxArray_int32_T *r29, const
  emxArray_real_T *dataPoints, const emxArray_int32_T *r28, emxArray_real_T
  *newDataPoints)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(r28->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    newDataPoints->data[i1] = 0.5 * (dataPoints->data[r28->data[i1] - 1] +
      dataPoints->data[r29->data[i1] - 1]);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  rk_reflectivity_calculation_gpu(const emxArray_real_T *simXdata,
  emxArray_real_T *Simul)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(simXdata->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    Simul->data[i1] = simXdata->data[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  rl_reflectivity_calculation_gpu(const real_T terms_data[51], int32_T vlen,
  real_T *layerThicks)
{
  uint32_T idx;
  real_T tmpRed0;
  uint32_T threadStride;
  uint32_T threadId;
  uint32_T thBlkId;
  uint32_T blockStride;
  uint32_T m;
  int64_T loopEnd;
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  thBlkId = static_cast<uint32_T>(mwGetThreadIndexWithinBlock());
  blockStride = static_cast<uint32_T>(mwGetThreadsPerBlock());
  tmpRed0 = 0.0;
  loopEnd = static_cast<int64_T>(vlen - 2);
  if (mwIsLastBlock()) {
    m = (static_cast<int64_T>(vlen - 2) + 1L) % static_cast<int64_T>(blockStride);
    if (m > 0U) {
      blockStride = m;
    }
  }

  blockStride = (uint32_T)(blockStride + (static_cast<int64_T>(warpSize) - 1L)) /
    warpSize;
  if (static_cast<int64_T>(threadId) <= loopEnd) {
    tmpRed0 = terms_data[static_cast<int32_T>(threadId) + 1];
  }

  m = __ballot_sync(MAX_uint32_T, static_cast<int64_T>(threadId) <= loopEnd);
  for (idx = threadId + threadStride; idx <= static_cast<uint32_T>(loopEnd); idx
       += threadStride) {
    tmpRed0 += terms_data[static_cast<int32_T>(idx) + 1];
  }

  tmpRed0 = workGroupReduction(tmpRed0, m, blockStride);
  if (thBlkId == 0U) {
    atomicOpreal_T(&layerThicks[0], tmpRed0);
  }
}

static __device__ real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if ((static_cast<int32_T>(isnan(u0))) || (static_cast<int32_T>(isnan(u1)))) {
    y = CUDART_NAN;
  } else if ((static_cast<int32_T>(isinf(u0))) && (static_cast<int32_T>(isinf(u1))))
  {
    int32_T b_u0;
    int32_T b_u1;
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }

    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }

    y = atan2(static_cast<real_T>(b_u0), static_cast<real_T>(b_u1));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T a;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = a * sqrt(y * y + 1.0);
  } else {
    if (!rtIsNaN(y)) {
      y = a * 1.4142135623730951;
    }
  }

  return y;
}

static __device__ real_T rt_hypotd_snf_device(real_T u0, real_T u1)
{
  real_T y;
  real_T a;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = a * sqrt(y * y + 1.0);
  } else {
    if (!static_cast<int32_T>(isnan(y))) {
      y = a * 1.4142135623730951;
    }
  }

  return y;
}

static __device__ real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if ((static_cast<int32_T>(isnan(u0))) || (static_cast<int32_T>(isnan(u1)))) {
    y = CUDART_NAN;
  } else {
    real_T d;
    real_T d1;
    d = fabs(u0);
    d1 = fabs(u1);
    if (isinf(u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (u1 > 0.0) {
          y = CUDART_INF;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = CUDART_INF;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((static_cast<int32_T>(u1 == 0.5)) && (static_cast<int32_T>(u0 >=
                 0.0))) {
      y = sqrt(u0);
    } else if ((static_cast<int32_T>(u0 < 0.0)) && (static_cast<int32_T>(u1 >
                 floor(u1)))) {
      y = CUDART_NAN;
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

static __global__ __launch_bounds__(32, 1) void s_reflectivity_calculation_gpu_(
  const struct0_T problemDef, const cell_10 *problemDef_cells, real_T
  thisOutLayer[5])
{
  uint32_T threadId;
  int32_T ix;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  ix = static_cast<int32_T>(threadId);
  if (ix < 4) {
    if (!static_cast<int32_T>(isnan(problemDef_cells->f6[2].f1[ix]))) {
      thisOutLayer[ix] = problemDef.params[static_cast<int32_T>
        (problemDef_cells->f6[2].f1[ix]) - 1];
    } else {
      thisOutLayer[ix] = CUDART_NAN;
    }
  }
}

static __global__ __launch_bounds__(1024, 1) void
  sb_reflectivity_calculation_gpu(const real_T *layerThicks, const real_T l,
  const emxArray_real_T *x, emxArray_real_T *a)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(x->size[0] * x->size[1] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    a->data[i1] = (x->data[i1] - l) / *layerThicks;
  }
}

static __global__ __launch_bounds__(32, 1) void sc_reflectivity_calculation_gpu(
  const int32_T vlen, const emxArray_real_T *dataPoints, real_T dataBoxSize[2])
{
  uint32_T threadId;
  int32_T j;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  j = static_cast<int32_T>(threadId);
  if (j < 2) {
    int32_T iv0;
    iv0 = (j * (dataPoints->size[0] - 1) + j) + 1;
    dataBoxSize[j] = dataPoints->data[(iv0 - 1) % dataPoints->size[0] +
      dataPoints->size[0] * ((iv0 - 1) / dataPoints->size[0])];
    for (int32_T i = 0; i <= vlen - 2; i++) {
      int32_T ix;
      boolean_T xneg;
      ix = (iv0 + i) + 1;
      if (isnan(dataPoints->data[(ix - 1) % dataPoints->size[0] +
                dataPoints->size[0] * ((ix - 1) / dataPoints->size[0])])) {
        xneg = false;
      } else if (isnan(dataBoxSize[j])) {
        xneg = true;
      } else {
        xneg = (dataBoxSize[j] < dataPoints->data[(ix - 1) % dataPoints->size[0]
                + dataPoints->size[0] * ((ix - 1) / dataPoints->size[0])]);
      }

      if (xneg) {
        dataBoxSize[j] = dataPoints->data[(ix - 1) % dataPoints->size[0] +
          dataPoints->size[0] * ((ix - 1) / dataPoints->size[0])];
      }
    }
  }
}

static __global__ __launch_bounds__(32, 1) void sd_reflectivity_calculation_gpu
  (emxArray_boolean_T *r32)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    r32->data[0] = false;
  }
}

static __global__ __launch_bounds__(160, 1) void se_reflectivity_calculation_gpu
  (const cell_10 *problemDef_cells, const int32_T i, real_T shifted_dat_data[153])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 153) {
    shifted_dat_data[i1] = problemDef_cells->f2[i].f1[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  sf_reflectivity_calculation_gpu(const real_T *layerThicks, const real_T
  shifted_dat_data[153], const int32_T shifted_dat_size[2], const int32_T kEnd,
  real_T terms_data[51])
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(kEnd);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    terms_data[i1] = shifted_dat_data[i1 + shifted_dat_size[0]] - *layerThicks;
  }
}

static __global__ __launch_bounds__(32, 1) void sg_reflectivity_calculation_gpu(
  const real_T thisContrastLayers[10], real_T layers_data[10])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 10) {
    layers_data[i1] = thisContrastLayers[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  sh_reflectivity_calculation_gpu(const int32_T *xoffset, const emxArray_real_T *
  Lays, const int32_T vstride, emxArray_real_T *SLD)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(vstride - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    SLD->data[j] += Lays->data[*xoffset + j];
  }
}

static __device__ real_T shflDown2(real_T in1, uint32_T offset, uint32_T mask)
{
  int2 tmp;
  tmp = *(int2 *)&in1;
  tmp.x = __shfl_down_sync(mask, tmp.x, offset);
  tmp.y = __shfl_down_sync(mask, tmp.y, offset);
  return *(real_T *)&tmp;
}

static __global__ __launch_bounds__(1024, 1) void
  si_reflectivity_calculation_gpu(const emxArray_real_T *firstStep, const
  int32_T *nx, emxArray_real_T *z1)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    z1->data[j] = rt_powd_snf(firstStep->data[j + firstStep->size[0]], 2.0);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  sj_reflectivity_calculation_gpu(const real_T *layerThicks, const
  emxArray_real_T *sldProfile, const int32_T *qEnd, emxArray_boolean_T *x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*qEnd);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    x->data[i1] = (sldProfile->data[i1] == *layerThicks);
  }
}

static __global__ __launch_bounds__(32, 1) void sk_reflectivity_calculation_gpu
  (creal_T MI[4])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    MI[0].re = 1.0;
    MI[0].im = 0.0;
    MI[3].re = 1.0;
    MI[3].im = 0.0;
    MI[2].re = 0.0;
    MI[2].im = 0.0;
    MI[1].re = 0.0;
    MI[1].im = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  sl_reflectivity_calculation_gpu(const int32_T i, emxArray_int8_T *cell6)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(i - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T b_i;
    b_i = static_cast<int32_T>(idx);
    cell6->data[b_i] = static_cast<int8_T>(0);
  }
}

static __global__ __launch_bounds__(32, 1) void t_reflectivity_calculation_gpu_(
  const cell_10 *problemDef_cells, real_T thisOutLayer[5])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    thisOutLayer[4] = problemDef_cells->f6[2].f1[4];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  tb_reflectivity_calculation_gpu(const real_T bFactor, const real_T r, const
  emxArray_real_T *x, emxArray_real_T *b)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(x->size[0] * x->size[1] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    b->data[i1] = (x->data[i1] - r) / bFactor;
  }
}

static __global__ __launch_bounds__(32, 1) void tc_reflectivity_calculation_gpu(
  const int32_T vlen, const emxArray_real_T *dataPoints, real_T minval[2])
{
  uint32_T threadId;
  int32_T j;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  j = static_cast<int32_T>(threadId);
  if (j < 2) {
    int32_T iv0;
    iv0 = (j * (dataPoints->size[0] - 1) + j) + 1;
    minval[j] = dataPoints->data[(iv0 - 1) % dataPoints->size[0] +
      dataPoints->size[0] * ((iv0 - 1) / dataPoints->size[0])];
    for (int32_T i = 0; i <= vlen - 2; i++) {
      int32_T ix;
      boolean_T xneg;
      ix = (iv0 + i) + 1;
      if (isnan(dataPoints->data[(ix - 1) % dataPoints->size[0] +
                dataPoints->size[0] * ((ix - 1) / dataPoints->size[0])])) {
        xneg = false;
      } else if (isnan(minval[j])) {
        xneg = true;
      } else {
        xneg = (minval[j] > dataPoints->data[(ix - 1) % dataPoints->size[0] +
                dataPoints->size[0] * ((ix - 1) / dataPoints->size[0])]);
      }

      if (xneg) {
        minval[j] = dataPoints->data[(ix - 1) % dataPoints->size[0] +
          dataPoints->size[0] * ((ix - 1) / dataPoints->size[0])];
      }
    }
  }
}

static __global__ __launch_bounds__(1024, 1) void
  td_reflectivity_calculation_gpu(const emxArray_boolean_T *trianglesToRefine,
  const int32_T *nx, emxArray_boolean_T *r32)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    r32->data[i1 + 1] = trianglesToRefine->data[i1];
  }
}

static __global__ __launch_bounds__(64, 1) void te_reflectivity_calculation_gpu(
  const real_T bFactor, const real_T *layerThicks, const real_T shifts, const
  cell_10 *problemDef_cells, const int32_T i, boolean_T x[51], real_T thisData
  [153])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 51) {
    real_T Q;
    Q = problemDef_cells->f2[i].f1[i1] + shifts;
    thisData[i1] = Q;
    thisData[i1 + 51] /= *layerThicks;
    thisData[i1 + 102] /= *layerThicks;
    x[i1] = (Q < bFactor);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  tf_reflectivity_calculation_gpu(const real_T terms_data[51], const int32_T
  shifted_dat_size[2], const int32_T ii_size[1], real_T shifted_dat_data[153])
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(ii_size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    shifted_dat_data[i1 + shifted_dat_size[0]] = terms_data[i1];
  }
}

static __global__ __launch_bounds__(32, 1) void tg_reflectivity_calculation_gpu(
  const real_T nba, const struct0_T problemDef, const int32_T i, const real_T
  thisContrastLayers[10], real_T layers_data[10])
{
  uint32_T threadId;
  int32_T j;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  j = static_cast<int32_T>(threadId);
  if ((static_cast<int32_T>(j < 2)) && (!static_cast<int32_T>(isnan
        (thisContrastLayers[j + 6])))) {
    real_T b_thisContrastLayers;
    if (thisContrastLayers[j + 8] == 1.0) {
      b_thisContrastLayers = problemDef.nbs[static_cast<int32_T>
        (problemDef.contrastNbss[i]) - 1];
    } else {
      b_thisContrastLayers = nba;
    }

    layers_data[j + 2] = b_thisContrastLayers * (thisContrastLayers[j + 6] /
      100.0) + (1.0 - thisContrastLayers[j + 6] / 100.0) * layers_data[j + 2];
  }
}

static __global__ __launch_bounds__(32, 1) void th_reflectivity_calculation_gpu(
  const emxArray_real_T *Lays, uint32_T sz[2])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 2) {
    sz[i1] = static_cast<uint32_T>(Lays->size[i1]);
  }
}

static __device__ real_T threadGroupReduction(real_T val, uint32_T lane,
  uint32_T mask)
{
  uint32_T offset;
  uint32_T activeSize;
  activeSize = __popc(mask);
  offset = (activeSize + 1U) / 2U;
  while (activeSize > 1U) {
    real_T other;
    other = shflDown2(val, offset, mask);
    if (lane + offset < activeSize) {
      val += other;
    }

    activeSize = offset;
    offset = (offset + 1U) / 2U;
  }

  return val;
}

static __global__ __launch_bounds__(1024, 1) void
  ti_reflectivity_calculation_gpu(const emxArray_real_T *z1, const
  emxArray_real_T *b_z1, emxArray_real_T *firstStepSquared)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(b_z1->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    firstStepSquared->data[i1] = b_z1->data[i1] + z1->data[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  tj_reflectivity_calculation_gpu(const emxArray_real_T *sldProfile, const
  real_T *layerThicks, const int32_T *qEnd, emxArray_boolean_T *x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*qEnd);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    x->data[i1] = (*layerThicks > sldProfile->data[i1]);
  }
}

static __global__ __launch_bounds__(32, 1) void tk_reflectivity_calculation_gpu(
  const real_T l, const real_T *layerThicks, const real_T bFactor, const real_T
  nextLayRough, creal_T N[4])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    N[2].re = nextLayRough * bFactor - *layerThicks * l;
    N[2].im = nextLayRough * l + *layerThicks * bFactor;
  }
}

static __global__ __launch_bounds__(32, 1) void u_reflectivity_calculation_gpu_(
  const real_T thisOutLayer[5], cell_wrap_2 outParameterisedLayers[4])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 5) {
    outParameterisedLayers[2].f1[i1] = thisOutLayer[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ub_reflectivity_calculation_gpu(const emxArray_real_T *a, const int32_T *nx,
  emxArray_real_T *r4)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int32_T eint;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    real_T absx;
    int32_T j;
    real_T Q;
    j = static_cast<int32_T>(idx);

    // ========================== COPYRIGHT NOTICE ============================
    //  The algorithms for calculating ERF(X) and ERFC(X) are derived
    //  from FDLIBM, which has the following notice:
    //
    //  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
    //
    //  Developed at SunSoft, a Sun Microsystems, Inc. business.
    //  Permission to use, copy, modify, and distribute this
    //  software is freely granted, provided that this notice
    //  is preserved.
    // =============================    END    ================================
    absx = fabs(a->data[j]);
    if (isnan(a->data[j])) {
      Q = a->data[j];
    } else if (isinf(a->data[j])) {
      if (a->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else if (absx < 0.84375) {
      if (absx < 3.7252902984619141E-9) {
        if (absx < 2.8480945388892178E-306) {
          Q = 0.125 * (8.0 * a->data[j] + 1.0270333367641007 * a->data[j]);
        } else {
          Q = a->data[j] + 0.12837916709551259 * a->data[j];
        }
      } else {
        Q = a->data[j] * a->data[j];
        Q = a->data[j] + a->data[j] * ((Q * (Q * (Q * (Q *
          -2.3763016656650163E-5 + -0.0057702702964894416) +
          -0.02848174957559851) + -0.3250421072470015) + 0.12837916709551256) /
          (Q * (Q * (Q * (Q * (Q * -3.9602282787753681E-6 +
          0.00013249473800432164) + 0.0050813062818757656) + 0.0650222499887673)
                + 0.39791722395915535) + 1.0));
      }
    } else if (absx < 1.25) {
      real_T P;
      P = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * -0.0021663755948687908 + 0.035478304325618236)
        + -0.11089469428239668) + 0.31834661990116175) + -0.37220787603570132) +
                          0.41485611868374833) + -0.0023621185607526594;
      Q = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * 0.011984499846799107 + 0.013637083912029051) +
        0.12617121980876164) + 0.071828654414196266) + 0.540397917702171) +
                          0.10642088040084423) + 1.0;
      if (a->data[j] >= 0.0) {
        Q = P / Q + 0.84506291151046753;
      } else {
        Q = -0.84506291151046753 - P / Q;
      }
    } else if (absx > 6.0) {
      if (a->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else {
      real_T P;
      real_T R;
      int32_T ix;
      Q = 1.0 / (absx * absx);
      if (absx < 2.8571434020996094) {
        R = Q * (Q * (Q * (Q * (Q * (Q * (Q * -9.8143293441691455 +
          -81.2874355063066) + -184.60509290671104) + -162.39666946257347) +
                           -62.375332450326006) + -10.558626225323291) +
                 -0.69385857270718176) + -0.0098649440348471482;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * (Q * -0.0604244152148581 +
          6.5702497703192817) + 108.63500554177944) + 429.00814002756783) +
                    645.38727173326788) + 434.56587747522923) +
                      137.65775414351904) + 19.651271667439257) + 1.0;
      } else {
        R = Q * (Q * (Q * (Q * (Q * (Q * -483.5191916086514 +
          -1025.0951316110772) + -637.56644336838963) + -160.63638485582192) +
                      -17.757954917754752) + -0.799283237680523) +
          -0.0098649429247001;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * -22.440952446585818 +
          474.52854120695537) + 2553.0504064331644) + 3199.8582195085955) +
                           1536.729586084437) + 325.79251299657392) +
                 30.338060743482458) + 1.0;
      }

      if (!static_cast<int32_T>(isnan(absx))) {
        Q = frexp(absx, &eint);
        ix = eint;
      } else {
        Q = absx;
        ix = 0;
      }

      Q = floor(Q * 2.097152E+6) / 2.097152E+6 * rt_powd_snf(2.0,
        static_cast<real_T>(ix));
      Q = exp(-Q * Q - 0.5625) * exp((Q - absx) * (Q + absx) + R / P) / absx;
      if (a->data[j] < 0.0) {
        Q--;
      } else {
        Q = 1.0 - Q;
      }
    }

    r4->data[j] = Q;
  }
}

static __global__ __launch_bounds__(32, 1) void uc_reflectivity_calculation_gpu(
  const real_T minval[2], real_T dataBoxSize[2])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 2) {
    dataBoxSize[i1] -= minval[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ud_reflectivity_calculation_gpu(const emxArray_boolean_T *r32, const
  emxArray_boolean_T *trianglesToRefine, emxArray_boolean_T *segmentsToSplit)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(trianglesToRefine->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    segmentsToSplit->data[i1] = ((static_cast<int32_T>(trianglesToRefine->
      data[i1])) || (static_cast<int32_T>(r32->data[i1])));
  }
}

static __global__ __launch_bounds__(64, 1) void ue_reflectivity_calculation_gpu(
  const real_T bFactor, const real_T thisData[153], boolean_T x[51])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 51) {
    x[i1] = (thisData[i1] > bFactor);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  uf_reflectivity_calculation_gpu(const emxArray_real_T *reflect, const real_T
  shifted_dat_data[153], const int32_T shifted_dat_size[2], const int32_T kEnd,
  emxArray_real_T *z)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(kEnd);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    z->data[i1] = (shifted_dat_data[i1 + shifted_dat_size[0]] - reflect->data[i1
                   + reflect->size[0]]) / shifted_dat_data[i1 +
      (shifted_dat_size[0] << 1)];
  }
}

static __global__ __launch_bounds__(32, 1) void ug_reflectivity_calculation_gpu
  (emxArray_real_T *sldProfile)
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 3) {
    sldProfile->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  uh_reflectivity_calculation_gpu(const uint32_T sz[2], emxArray_real_T *SLD)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(static_cast<int32_T>(sz[0]) - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    SLD->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ui_reflectivity_calculation_gpu(const emxArray_real_T *secondStep, const
  int32_T *nx, emxArray_real_T *z1)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    z1->data[j] = rt_powd_snf(secondStep->data[j], 2.0);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  uj_reflectivity_calculation_gpu(const emxArray_real_T *sldProfile, const
  real_T *layerThicks, const int32_T *qEnd, emxArray_boolean_T *x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*qEnd);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    x->data[i1] = (*layerThicks < sldProfile->data[i1]);
  }
}

static __global__ __launch_bounds__(32, 1) void uk_reflectivity_calculation_gpu(
  const creal_T N[4], const creal_T MI[4], creal_T b_MI[4])
{
  uint32_T threadId;
  int32_T i1;
  real_T P;
  real_T Q;
  int32_T ix;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  ix = static_cast<int32_T>(threadId % 2U);
  i1 = static_cast<int32_T>((threadId - static_cast<uint32_T>(ix)) / 2U);
  if (i1 < 2) {
    Q = 0.0;
    P = 0.0;
    for (int32_T iv0 = 0; iv0 < 2; iv0++) {
      Q += MI[i1 + (iv0 << 1)].re * N[iv0 + (ix << 1)].re - MI[i1 + (iv0 << 1)].
        im * N[iv0 + (ix << 1)].im;
      P += MI[i1 + (iv0 << 1)].re * N[iv0 + (ix << 1)].im + MI[i1 + (iv0 << 1)].
        im * N[iv0 + (ix << 1)].re;
    }

    b_MI[i1 + (ix << 1)].re = Q;
    b_MI[i1 + (ix << 1)].im = P;
  }
}

static __global__ __launch_bounds__(32, 1) void v_reflectivity_calculation_gpu_(
  const struct0_T problemDef, const cell_10 *problemDef_cells, real_T
  thisOutLayer[5])
{
  uint32_T threadId;
  int32_T ix;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  ix = static_cast<int32_T>(threadId);
  if (ix < 4) {
    if (!static_cast<int32_T>(isnan(problemDef_cells->f6[3].f1[ix]))) {
      thisOutLayer[ix] = problemDef.params[static_cast<int32_T>
        (problemDef_cells->f6[3].f1[ix]) - 1];
    } else {
      thisOutLayer[ix] = CUDART_NAN;
    }
  }
}

static __global__ __launch_bounds__(1024, 1) void
  vb_reflectivity_calculation_gpu(const emxArray_real_T *b, const int32_T *nx,
  emxArray_real_T *r5)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int32_T eint;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    real_T absx;
    int32_T j;
    real_T Q;
    j = static_cast<int32_T>(idx);

    // ========================== COPYRIGHT NOTICE ============================
    //  The algorithms for calculating ERF(X) and ERFC(X) are derived
    //  from FDLIBM, which has the following notice:
    //
    //  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
    //
    //  Developed at SunSoft, a Sun Microsystems, Inc. business.
    //  Permission to use, copy, modify, and distribute this
    //  software is freely granted, provided that this notice
    //  is preserved.
    // =============================    END    ================================
    absx = fabs(b->data[j]);
    if (isnan(b->data[j])) {
      Q = b->data[j];
    } else if (isinf(b->data[j])) {
      if (b->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else if (absx < 0.84375) {
      if (absx < 3.7252902984619141E-9) {
        if (absx < 2.8480945388892178E-306) {
          Q = 0.125 * (8.0 * b->data[j] + 1.0270333367641007 * b->data[j]);
        } else {
          Q = b->data[j] + 0.12837916709551259 * b->data[j];
        }
      } else {
        Q = b->data[j] * b->data[j];
        Q = b->data[j] + b->data[j] * ((Q * (Q * (Q * (Q *
          -2.3763016656650163E-5 + -0.0057702702964894416) +
          -0.02848174957559851) + -0.3250421072470015) + 0.12837916709551256) /
          (Q * (Q * (Q * (Q * (Q * -3.9602282787753681E-6 +
          0.00013249473800432164) + 0.0050813062818757656) + 0.0650222499887673)
                + 0.39791722395915535) + 1.0));
      }
    } else if (absx < 1.25) {
      real_T P;
      P = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * -0.0021663755948687908 + 0.035478304325618236)
        + -0.11089469428239668) + 0.31834661990116175) + -0.37220787603570132) +
                          0.41485611868374833) + -0.0023621185607526594;
      Q = (absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx - 1.0) * ((absx
        - 1.0) * ((absx - 1.0) * 0.011984499846799107 + 0.013637083912029051) +
        0.12617121980876164) + 0.071828654414196266) + 0.540397917702171) +
                          0.10642088040084423) + 1.0;
      if (b->data[j] >= 0.0) {
        Q = P / Q + 0.84506291151046753;
      } else {
        Q = -0.84506291151046753 - P / Q;
      }
    } else if (absx > 6.0) {
      if (b->data[j] < 0.0) {
        Q = -1.0;
      } else {
        Q = 1.0;
      }
    } else {
      real_T P;
      real_T R;
      int32_T ix;
      Q = 1.0 / (absx * absx);
      if (absx < 2.8571434020996094) {
        R = Q * (Q * (Q * (Q * (Q * (Q * (Q * -9.8143293441691455 +
          -81.2874355063066) + -184.60509290671104) + -162.39666946257347) +
                           -62.375332450326006) + -10.558626225323291) +
                 -0.69385857270718176) + -0.0098649440348471482;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * (Q * -0.0604244152148581 +
          6.5702497703192817) + 108.63500554177944) + 429.00814002756783) +
                    645.38727173326788) + 434.56587747522923) +
                      137.65775414351904) + 19.651271667439257) + 1.0;
      } else {
        R = Q * (Q * (Q * (Q * (Q * (Q * -483.5191916086514 +
          -1025.0951316110772) + -637.56644336838963) + -160.63638485582192) +
                      -17.757954917754752) + -0.799283237680523) +
          -0.0098649429247001;
        P = Q * (Q * (Q * (Q * (Q * (Q * (Q * -22.440952446585818 +
          474.52854120695537) + 2553.0504064331644) + 3199.8582195085955) +
                           1536.729586084437) + 325.79251299657392) +
                 30.338060743482458) + 1.0;
      }

      if (!static_cast<int32_T>(isnan(absx))) {
        Q = frexp(absx, &eint);
        ix = eint;
      } else {
        Q = absx;
        ix = 0;
      }

      Q = floor(Q * 2.097152E+6) / 2.097152E+6 * rt_powd_snf(2.0,
        static_cast<real_T>(ix));
      Q = exp(-Q * Q - 0.5625) * exp((Q - absx) * (Q + absx) + R / P) / absx;
      if (b->data[j] < 0.0) {
        Q--;
      } else {
        Q = 1.0 - Q;
      }
    }

    r5->data[j] = Q;
  }
}

static __global__ __launch_bounds__(32, 1) void vc_reflectivity_calculation_gpu(
  const int32_T vlen, const emxArray_real_T *dataPoints, real_T minval[2])
{
  uint32_T threadId;
  int32_T j;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  j = static_cast<int32_T>(threadId);
  if (j < 2) {
    int32_T iv0;
    iv0 = (j * (dataPoints->size[0] - 1) + j) + 1;
    minval[j] = dataPoints->data[(iv0 - 1) % dataPoints->size[0] +
      dataPoints->size[0] * ((iv0 - 1) / dataPoints->size[0])];
    for (int32_T i = 0; i <= vlen - 2; i++) {
      int32_T ix;
      boolean_T xneg;
      ix = (iv0 + i) + 1;
      if (isnan(dataPoints->data[(ix - 1) % dataPoints->size[0] +
                dataPoints->size[0] * ((ix - 1) / dataPoints->size[0])])) {
        xneg = false;
      } else if (isnan(minval[j])) {
        xneg = true;
      } else {
        xneg = (minval[j] > dataPoints->data[(ix - 1) % dataPoints->size[0] +
                dataPoints->size[0] * ((ix - 1) / dataPoints->size[0])]);
      }

      if (xneg) {
        minval[j] = dataPoints->data[(ix - 1) % dataPoints->size[0] +
          dataPoints->size[0] * ((ix - 1) / dataPoints->size[0])];
      }
    }
  }
}

static __global__ __launch_bounds__(1024, 1) void
  vd_reflectivity_calculation_gpu(const int32_T *xoffset, emxArray_real_T
  *newDataPoints)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*xoffset * 2 - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    newDataPoints->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ve_reflectivity_calculation_gpu(const real_T thisData[153], const int32_T
  shifted_dat_size[2], const int32_T kEnd, const int32_T *qEnd, real_T
  shifted_dat_data[153])
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = (static_cast<int64_T>(*qEnd - kEnd) + 1L) * 3L - 1L;
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    int32_T iv0;
    iv0 = static_cast<int32_T>(idx % (static_cast<uint32_T>(*qEnd - kEnd) + 1U));
    i1 = static_cast<int32_T>((idx - static_cast<uint32_T>(iv0)) / (static_cast<
      uint32_T>(*qEnd - kEnd) + 1U));
    shifted_dat_data[iv0 + shifted_dat_size[0] * i1] = thisData[(kEnd + iv0) +
      51 * i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  vf_reflectivity_calculation_gpu(const emxArray_real_T *z, const int32_T *nx,
  emxArray_real_T *z1)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    z1->data[j] = rt_powd_snf(z->data[j], 2.0);
  }
}

static __global__ __launch_bounds__(32, 1) void vg_reflectivity_calculation_gpu(
  const real_T layers_data[10], real_T *layerThicks)
{
  uint32_T idx;
  real_T tmpRed0;
  uint32_T threadStride;
  uint32_T threadId;
  uint32_T thBlkId;
  uint32_T mask;
  uint32_T blockStride;
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  thBlkId = static_cast<uint32_T>(mwGetThreadIndexWithinBlock());
  blockStride = static_cast<uint32_T>(mwGetThreadsPerBlock());
  tmpRed0 = 0.0;
  if (mwIsLastBlock()) {
    int32_T m;
    m = static_cast<int32_T>(1U % blockStride);
    if (static_cast<uint32_T>(m) > 0U) {
      blockStride = 1U;
    }
  }

  blockStride = ((blockStride + warpSize) - 1U) / warpSize;
  if (threadId <= 0U) {
    tmpRed0 = layers_data[1];
  }

  mask = __ballot_sync(MAX_uint32_T, threadId <= 0U);
  for (idx = threadId + threadStride; idx <= 0U; idx += threadStride) {
    tmpRed0 += layers_data[1];
  }

  tmpRed0 = workGroupReduction(tmpRed0, mask, blockStride);
  if (thBlkId == 0U) {
    atomicOpreal_T(&layerThicks[0], tmpRed0);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  vh_reflectivity_calculation_gpu(const emxArray_real_T *x, const int32_T *nx,
  emxArray_real_T *sldProfile)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    sldProfile->data[i1] = x->data[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  vi_reflectivity_calculation_gpu(const emxArray_real_T *secondStep, const
  int32_T *nx, emxArray_real_T *z1)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    z1->data[j] = rt_powd_snf(secondStep->data[j + secondStep->size[0]], 2.0);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  vj_reflectivity_calculation_gpu(const emxArray_real_T *sldProfile, const
  emxArray_int32_T *ii, emxArray_real_T *r31)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(ii->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    r31->data[i1] = sldProfile->data[(ii->data[i1] + sldProfile->size[0]) - 1];
  }
}

static __global__ __launch_bounds__(32, 1) void vk_reflectivity_calculation_gpu(
  const creal_T MI[4], creal_T b_MI[4])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 4) {
    b_MI[i1] = MI[i1];
  }
}

static __global__ __launch_bounds__(32, 1) void w_reflectivity_calculation_gpu_(
  const cell_10 *problemDef_cells, real_T thisOutLayer[5])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    thisOutLayer[4] = problemDef_cells->f6[3].f1[4];
  }
}

static __global__ __launch_bounds__(32, 1) void wb_reflectivity_calculation_gpu(
  const emxArray_real_T *Lays, int32_T *qEnd)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    *qEnd = Lays->size[0];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  wc_reflectivity_calculation_gpu(const emxArray_real_T *r14, const
  emxArray_real_T *b, const emxArray_real_T *dataPoints, const int32_T kEnd,
  emxArray_real_T *normalizedData)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = (static_cast<int64_T>(kEnd) + 1L) * 2L - 1L;
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    int32_T iv0;
    iv0 = static_cast<int32_T>(idx % (static_cast<uint32_T>(kEnd) + 1U));
    i1 = static_cast<int32_T>((idx - static_cast<uint32_T>(iv0)) /
      (static_cast<uint32_T>(kEnd) + 1U));
    normalizedData->data[iv0 + normalizedData->size[0] * i1] = dataPoints->
      data[iv0 + dataPoints->size[0] * i1] / b->data[iv0 + b->size[0] * i1] -
      r14->data[iv0 + r14->size[0] * i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  wd_reflectivity_calculation_gpu(const emxArray_boolean_T *segmentsToSplit,
  const int32_T *nx, emxArray_boolean_T *r21)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    r21->data[i1] = segmentsToSplit->data[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  we_reflectivity_calculation_gpu(const real_T reps, const real_T *layerThicks,
  const real_T bFactor, emxArray_real_T *firstSection)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(static_cast<int32_T>((bFactor - *layerThicks) /
    reps));
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    firstSection->data[i1] = *layerThicks + reps * static_cast<real_T>(i1);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  wf_reflectivity_calculation_gpu(const emxArray_real_T *z1, real_T terms_data
  [51])
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(z1->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    terms_data[i1] = z1->data[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  wg_reflectivity_calculation_gpu(const real_T *layerThicks, emxArray_real_T *x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(static_cast<int32_T>(*layerThicks));
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    x->data[i1] = static_cast<real_T>(i1);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  wh_reflectivity_calculation_gpu(const emxArray_real_T *SLD, const int32_T *nx,
  emxArray_real_T *sldProfile)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    sldProfile->data[i1 + sldProfile->size[0]] = SLD->data[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  wi_reflectivity_calculation_gpu(const emxArray_real_T *z1, const
  emxArray_real_T *b_z1, emxArray_real_T *secondStepSquared)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(b_z1->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    secondStepSquared->data[i1] = b_z1->data[i1] + z1->data[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  wj_reflectivity_calculation_gpu(const emxArray_real_T *r18, emxArray_real_T
  *newDataPoints)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());

  // end
  loopEnd = static_cast<int64_T>(r18->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    newDataPoints->data[i1 + newDataPoints->size[0]] = r18->data[i1];
  }
}

static __global__ __launch_bounds__(32, 1) void wk_reflectivity_calculation_gpu(
  const real_T l, const real_T bFactor, creal_T N[4])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    N[0].re = bFactor;
    N[0].im = l;
  }
}

static __device__ real_T workGroupReduction(real_T val, uint32_T mask, uint32_T
  numActiveWarps)
{
  __shared__ real_T shared[32];
  uint32_T lane;
  uint32_T thBlkId;
  thBlkId = static_cast<uint32_T>(mwGetThreadIndexWithinBlock());
  lane = thBlkId % warpSize;
  thBlkId /= warpSize;
  val = threadGroupReduction(val, lane, mask);
  if (lane == 0U) {
    shared[thBlkId] = val;
  }

  __syncthreads();
  mask = __ballot_sync(MAX_uint32_T, lane < numActiveWarps);
  val = shared[lane];
  if (thBlkId == 0U) {
    val = threadGroupReduction(val, lane, mask);
  }

  return val;
}

static __global__ __launch_bounds__(32, 1) void x_reflectivity_calculation_gpu_(
  const real_T thisOutLayer[5], cell_wrap_2 outParameterisedLayers[4])
{
  uint32_T threadId;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId);
  if (i1 < 5) {
    outParameterisedLayers[3].f1[i1] = thisOutLayer[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  xb_reflectivity_calculation_gpu(const emxArray_real_T *r5, const
  emxArray_real_T *r4, const real_T *layerThicks, const int32_T *qEnd, const
  int32_T ii_size[1], emxArray_real_T *Lays)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(ii_size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    Lays->data[i1 + Lays->size[0] * *qEnd] = *layerThicks * (r4->data[i1] -
      r5->data[i1]);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  xc_reflectivity_calculation_gpu(const emxArray_real_T *normalizedData, const
  int32_T kEnd, emxArray_real_T *firstStep)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = (static_cast<int64_T>(kEnd - 1) + 1L) * 2L - 1L;
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    int32_T iv0;
    iv0 = static_cast<int32_T>(idx % static_cast<uint32_T>(kEnd));
    i1 = static_cast<int32_T>((idx - static_cast<uint32_T>(iv0)) /
      static_cast<uint32_T>(kEnd));
    firstStep->data[iv0 + firstStep->size[0] * i1] = normalizedData->data[(iv0 +
      normalizedData->size[0] * i1) + 1] - normalizedData->data[iv0 +
      normalizedData->size[0] * i1];
  }
}

static __global__ __launch_bounds__(32, 1) void xd_reflectivity_calculation_gpu(
  const emxArray_boolean_T *segmentsToSplit, emxArray_boolean_T *r21)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    r21->data[segmentsToSplit->size[0]] = false;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  xe_reflectivity_calculation_gpu(const real_T reps, const real_T a, const
  real_T *layerThicks, emxArray_real_T *lastSection)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(static_cast<int32_T>((*layerThicks - a) / reps));
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    lastSection->data[i1] = a + reps * static_cast<real_T>(i1);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  xf_reflectivity_calculation_gpu(const emxArray_real_T *z1, emxArray_boolean_T *
  x)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(z1->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    x->data[i1] = (z1->data[i1] == CUDART_INF);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  xg_reflectivity_calculation_gpu(const real_T reps, const emxArray_real_T *x,
  emxArray_real_T *Lays)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(x->size[1] * static_cast<int32_T>(2.0 * reps +
    2.0) - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    Lays->data[i1] = 0.0;
  }
}

static __global__ __launch_bounds__(32, 1) void xh_reflectivity_calculation_gpu(
  const real_T layers_data[10], emxArray_real_T *layers)
{
  uint32_T threadId;
  int32_T i1;
  int32_T iv0;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  iv0 = static_cast<int32_T>(threadId % 2U);
  i1 = static_cast<int32_T>((threadId - static_cast<uint32_T>(iv0)) / 2U);
  if (i1 < 3) {
    layers->data[iv0 + layers->size[0] * i1] = layers_data[iv0 + (i1 << 1)];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  xi_reflectivity_calculation_gpu(const emxArray_real_T *longStep, const int32_T
  *nx, emxArray_real_T *z1)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    z1->data[j] = rt_powd_snf(longStep->data[j], 2.0);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  xj_reflectivity_calculation_gpu(const emxArray_real_T *dataPoints,
  emxArray_real_T *b_dataPoints)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = (static_cast<int64_T>(dataPoints->size[0] - 1) + 1L) * 2L - 1L;
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    int32_T iv0;
    uint32_T tmpIndex;
    iv0 = static_cast<int32_T>(idx % static_cast<uint32_T>(dataPoints->size[0]));
    tmpIndex = (idx - static_cast<uint32_T>(iv0)) / static_cast<uint32_T>
      (dataPoints->size[0]);
    i1 = static_cast<int32_T>(tmpIndex);
    b_dataPoints->data[iv0 + b_dataPoints->size[0] * i1] = dataPoints->data[iv0
      + dataPoints->size[0] * i1];
  }
}

static __global__ __launch_bounds__(32, 1) void xk_reflectivity_calculation_gpu(
  const real_T l, const real_T *layerThicks, const real_T bFactor, const real_T
  nextLayRough, creal_T N[4])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    N[1].re = nextLayRough * bFactor - *layerThicks * l;
    N[1].im = nextLayRough * l + *layerThicks * bFactor;
  }
}

static __global__ __launch_bounds__(32, 1) void y_reflectivity_calculation_gpu_(
  const cell_wrap_2 outParameterisedLayers[4], const cell_10 *problemDef_cells,
  const int32_T i, real_T thisContrastLayers[10])
{
  uint32_T threadId;
  int32_T b_i;
  int32_T i1;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  i1 = static_cast<int32_T>(threadId % 5U);
  b_i = static_cast<int32_T>((threadId - static_cast<uint32_T>(i1)) / 5U);
  if (b_i < 2) {
    thisContrastLayers[b_i + (i1 << 1)] = outParameterisedLayers
      [static_cast<int32_T>(problemDef_cells->f5[i].f1[b_i]) - 1].f1[i1];
  }
}

static __global__ __launch_bounds__(32, 1) void yb_reflectivity_calculation_gpu(
  const emxArray_real_T *Lays, int32_T *qEnd)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    *qEnd = Lays->size[0];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  yc_reflectivity_calculation_gpu(const emxArray_real_T *normalizedData, const
  int32_T kEnd, emxArray_real_T *secondStep)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = (static_cast<int64_T>(kEnd - 2) + 1L) * 2L - 1L;
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    int32_T iv0;
    iv0 = static_cast<int32_T>(idx % (static_cast<uint32_T>(kEnd) - 1U));
    i1 = static_cast<int32_T>((idx - static_cast<uint32_T>(iv0)) /
      (static_cast<uint32_T>(kEnd) - 1U));
    secondStep->data[iv0 + secondStep->size[0] * i1] = normalizedData->data[(iv0
      + normalizedData->size[0] * i1) + 2] - normalizedData->data[(iv0 +
      normalizedData->size[0] * i1) + 1];
  }
}

static __global__ __launch_bounds__(32, 1) void yd_reflectivity_calculation_gpu
  (emxArray_boolean_T *r23)
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    r23->data[0] = false;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  ye_reflectivity_calculation_gpu(const emxArray_real_T *firstSection, const
  int32_T vstride, emxArray_real_T *simXdata)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(vstride);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    simXdata->data[i1] = firstSection->data[i1];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  yf_reflectivity_calculation_gpu(const emxArray_int8_T *ii, real_T terms_data
  [51])
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(ii->size[0] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    terms_data[static_cast<int32_T>(ii->data[i1]) - 1] = 0.0;
  }
}

static __global__ __launch_bounds__(1024, 1) void
  yg_reflectivity_calculation_gpu(const real_T *layerThicks, const
  emxArray_real_T *x, emxArray_real_T *a)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(x->size[0] * x->size[1] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    a->data[i1] = (x->data[i1] - -50.0) / *layerThicks;
  }
}

static __global__ __launch_bounds__(32, 1) void yh_reflectivity_calculation_gpu(
  const real_T dataBoxSize[2], real_T y[50])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    y[49] = dataBoxSize[1];
    y[0] = dataBoxSize[0];
  }
}

static __global__ __launch_bounds__(1024, 1) void
  yi_reflectivity_calculation_gpu(const emxArray_real_T *longStep, const int32_T
  *nx, emxArray_real_T *z1)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(*nx - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T j;
    j = static_cast<int32_T>(idx);
    z1->data[j] = rt_powd_snf(longStep->data[j + longStep->size[0]], 2.0);
  }
}

static __global__ __launch_bounds__(1024, 1) void
  yj_reflectivity_calculation_gpu(const emxArray_real_T *dataPoints,
  emxArray_real_T *b_dataPoints)
{
  uint32_T threadId;
  uint32_T threadStride;
  uint32_T idx;
  int64_T loopEnd;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  threadStride = static_cast<uint32_T>(mwGetTotalThreadsLaunched());
  loopEnd = static_cast<int64_T>(dataPoints->size[0] * dataPoints->size[1] - 1);
  for (idx = threadId; idx <= static_cast<uint32_T>(loopEnd); idx +=
       threadStride) {
    int32_T i1;
    i1 = static_cast<int32_T>(idx);
    b_dataPoints->data[i1] = dataPoints->data[i1];
  }
}

static __global__ __launch_bounds__(32, 1) void yk_reflectivity_calculation_gpu(
  const real_T l, const real_T bFactor, creal_T N[4])
{
  uint32_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint32_T>(mwGetGlobalThreadIndex());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    N[3].re = bFactor;
    N[3].im = l;
  }
}

void reflectivity_calculation_gpu(const struct0_T *problemDef, const cell_10
  *problemDef_cells, const struct1_T *problemDef_limits, const struct2_T
  *controls, struct4_T *problem, cell_13 *result)
{
  emxArray_cell_wrap_14 *reflectivity;
  int32_T i;
  int32_T kEnd;
  int32_T b_i;
  emxArray_cell_wrap_14 *Simulation;
  emxArray_cell_wrap_15 *shifted_data;
  emxArray_cell_wrap_15 *layerSlds;
  emxArray_cell_wrap_14 *sldProfiles;
  boolean_T b_bool;
  int32_T xoffset;
  static const char_T cv[10] = { 's', 't', 'a', 'n', 'd', 'a', 'r', 'd', 'T',
    'F' };

  emxArray_real_T *outSsubs;
  emxArray_cell_wrap_11 *cell1;
  emxArray_real_T *backgs;
  emxArray_cell_wrap_11 *cell2;
  emxArray_real_T *qshifts;
  emxArray_cell_wrap_12 *cell3;
  emxArray_real_T *sfs;
  emxArray_real_T *nbas;
  emxArray_cell_wrap_12 *cell4;
  emxArray_real_T *nbss;
  emxArray_real_T *chis;
  emxArray_real_T *resols;
  emxArray_cell_wrap_11 *cell5;
  emxArray_real_T *allRoughs;
  emxArray_cell_wrap_11 *b_reflectivity;
  emxArray_int8_T *cell6;
  emxArray_cell_wrap_11 *b_Simulation;
  emxArray_cell_wrap_12 *b_shifted_data;
  emxArray_cell_wrap_12 *b_layerSlds;
  emxArray_cell_wrap_17 *b_sldProfiles;
  static const char_T cv1[6] = { 's', 'i', 'n', 'g', 'l', 'e' };

  static const char_T cv2[6] = { 'p', 'o', 'i', 'n', 't', 's' };

  int32_T vlen;
  real_T layerThicks;
  emxArray_real_T *sldProfile;
  emxArray_real_T *reflect;
  emxArray_real_T *b_sldProfile;
  emxArray_real_T *Simul;
  emxArray_real_T *b_reflect;
  emxArray_real_T *layers;
  emxArray_real_T *b_Simul;
  emxArray_real_T *firstSection;
  emxArray_real_T *b_layers;
  emxArray_real_T *lastSection;
  emxArray_real_T *b_firstSection;
  emxArray_real_T *simXdata;
  emxArray_real_T *b_lastSection;
  emxArray_real_T *simRef;
  emxArray_real_T *b_simXdata;
  emxArray_real_T *x;
  emxArray_real_T *b_simRef;
  emxArray_real_T *Lays;
  emxArray_real_T *b_x;
  emxArray_real_T *SLD;
  emxArray_real_T *b_Lays;
  emxArray_real_T *dataPoints;
  emxArray_real_T *b_SLD;
  emxArray_boolean_T *trianglesToRefine;
  emxArray_real_T *b_dataPoints;
  emxArray_boolean_T *segmentsToSplit;
  emxArray_boolean_T *b_trianglesToRefine;
  emxArray_real_T *dummydata;
  emxArray_boolean_T *b_segmentsToSplit;
  emxArray_real_T *z;
  emxArray_real_T *b_dummydata;
  emxArray_boolean_T *c_x;
  emxArray_real_T *b_z;
  emxArray_int8_T *ii;
  emxArray_boolean_T *d_x;
  emxArray_real_T *a;
  emxArray_int8_T *b_ii;
  emxArray_real_T *b;
  emxArray_real_T *b_a;
  emxArray_real_T *r;
  emxArray_real_T *b_b;
  emxArray_real_T *r1;
  emxArray_real_T *r2;
  emxArray_real_T *c_a;
  emxArray_real_T *r3;
  emxArray_real_T *c_b;
  emxArray_real_T *d_a;
  emxArray_real_T *r4;
  emxArray_real_T *d_b;
  emxArray_real_T *r5;
  emxArray_real_T *r6;
  emxArray_real_T *e_a;
  emxArray_real_T *r7;
  emxArray_real_T *e_b;
  emxArray_real_T *f_a;
  emxArray_real_T *r8;
  emxArray_real_T *f_b;
  emxArray_real_T *r9;
  emxArray_real_T *r10;
  emxArray_real_T *r11;
  emxArray_real_T *r12;
  emxArray_real_T *normalizedData;
  emxArray_real_T *r13;
  emxArray_real_T *firstStepSquared;
  emxArray_real_T *b_normalizedData;
  emxArray_real_T *secondStepSquared;
  emxArray_real_T *b_firstStepSquared;
  emxArray_real_T *firstStep;
  emxArray_real_T *b_secondStepSquared;
  emxArray_real_T *secondStep;
  emxArray_real_T *b_firstStep;
  emxArray_real_T *longStep;
  emxArray_real_T *b_secondStep;
  emxArray_real_T *r14;
  emxArray_real_T *b_longStep;
  emxArray_real_T *newDataPoints;
  emxArray_real_T *r15;
  emxArray_real_T *r16;
  emxArray_real_T *b_newDataPoints;
  emxArray_boolean_T *r17;
  emxArray_real_T *r18;
  emxArray_boolean_T *r19;
  emxArray_boolean_T *r20;
  emxArray_boolean_T *r21;
  emxArray_boolean_T *r22;
  emxArray_boolean_T *r23;
  emxArray_boolean_T *r24;
  emxArray_int32_T *r25;
  emxArray_boolean_T *r26;
  emxArray_int32_T *r27;
  emxArray_int32_T *r28;
  emxArray_real_T *z1;
  emxArray_int32_T *r29;
  emxArray_real_T *g_b;
  emxArray_real_T *b_z1;
  emxArray_real_T *e_x;
  emxArray_real_T *h_b;
  emxArray_creal_T *f_x;
  emxArray_real_T *g_x;
  emxArray_real_T *r30;
  emxArray_creal_T *h_x;
  emxArray_int32_T *idx;
  emxArray_real_T *r31;
  emxArray_boolean_T *i_x;
  emxArray_int32_T *b_idx;
  emxArray_int32_T *c_ii;
  emxArray_boolean_T *j_x;
  emxArray_boolean_T *k_x;
  emxArray_int32_T *d_ii;
  emxArray_int32_T *e_ii;
  emxArray_boolean_T *l_x;
  emxArray_boolean_T *m_x;
  emxArray_int32_T *f_ii;
  emxArray_int32_T *g_ii;
  emxArray_boolean_T *n_x;
  emxArray_real_T *ycol;
  emxArray_int32_T *h_ii;
  emxArray_real_T *c_z1;
  emxArray_real_T *b_ycol;
  emxArray_real_T *d_z1;
  emxArray_real_T *e_z1;
  emxArray_real_T *f_z1;
  emxArray_real_T *g_z1;
  emxArray_real_T *h_z1;
  emxArray_real_T *i_z1;
  emxArray_real_T *j_z1;
  emxArray_real_T *k_z1;
  emxArray_real_T *l_z1;
  emxArray_real_T *m_z1;
  emxArray_boolean_T *o_x;
  emxArray_real_T *n_z1;
  emxArray_int32_T *i_ii;
  emxArray_boolean_T *p_x;
  emxArray_boolean_T *q_x;
  emxArray_int32_T *j_ii;
  emxArray_int32_T *k_ii;
  emxArray_boolean_T *r_x;
  emxArray_boolean_T *s_x;
  emxArray_int32_T *l_ii;
  emxArray_int32_T *m_ii;
  emxArray_boolean_T *t_x;
  emxArray_int32_T *iwork;
  emxArray_int32_T *n_ii;
  emxArray_boolean_T *c_trianglesToRefine;
  emxArray_int32_T *b_iwork;
  emxArray_boolean_T *r32;
  emxArray_boolean_T *d_trianglesToRefine;
  emxArray_real_T *c_dataPoints;
  emxArray_boolean_T *r33;
  emxArray_real_T *d_dataPoints;
  real_T layers_data[10];
  int32_T layers_size[2];
  static const char_T cv3[13] = { 'a', 'i', 'r', '/', 's', 'u', 'b', 's', 't',
    'r', 'a', 't', 'e' };

  real_T dataBoxSize[2];
  real_T shifted_dat_data[153];
  int32_T shifted_dat_size[2];
  boolean_T u_x[51];
  int8_T ii_data[51];
  int32_T ii_size[1];
  int32_T nx;
  int32_T qEnd;
  uint32_T sz[2];
  creal_T MI[4];
  creal_T N[4];
  real_T y[50];
  real_T hiVal[50];
  real_T minval[2];
  int8_T col_data[2];
  dim3 grid;
  dim3 block;
  boolean_T validLaunchParams;
  emxArray_real_T *gpu_backgs;
  dim3 b_grid;
  dim3 b_block;
  emxArray_real_T *gpu_qshifts;
  dim3 c_grid;
  dim3 c_block;
  emxArray_real_T *gpu_sfs;
  dim3 d_grid;
  dim3 d_block;
  emxArray_real_T *gpu_nbas;
  dim3 e_grid;
  dim3 e_block;
  emxArray_real_T *gpu_nbss;
  dim3 f_grid;
  dim3 f_block;
  emxArray_real_T *gpu_chis;
  dim3 g_grid;
  dim3 g_block;
  emxArray_real_T *gpu_resols;
  dim3 h_grid;
  dim3 h_block;
  emxArray_real_T *gpu_allRoughs;
  real_T (*gpu_thisOutLayer)[5];
  cell_10 *gpu_problemDef_cells;
  cell_wrap_2 (*gpu_outParameterisedLayers)[4];
  real_T (*gpu_thisContrastLayers)[10];
  real_T (*gpu_thisData)[153];
  real_T (*gpu_layers_data)[10];
  emxArray_real_T *gpu_sldProfile;
  int32_T (*gpu_layers_size)[2];
  real_T *gpu_layerThicks;
  dim3 i_grid;
  dim3 i_block;
  emxArray_real_T *gpu_x;
  dim3 j_grid;
  dim3 j_block;
  emxArray_real_T *gpu_Lays;
  dim3 k_grid;
  dim3 k_block;
  emxArray_real_T *gpu_a;
  dim3 l_grid;
  dim3 l_block;
  emxArray_real_T *gpu_b;
  int32_T *gpu_nx;
  dim3 m_grid;
  dim3 m_block;
  emxArray_real_T *gpu_r;
  dim3 n_grid;
  dim3 n_block;
  emxArray_real_T *gpu_r1;
  dim3 o_grid;
  dim3 o_block;
  emxArray_real_T *b_gpu_a;
  dim3 p_grid;
  dim3 p_block;
  emxArray_real_T *b_gpu_b;
  dim3 q_grid;
  dim3 q_block;
  emxArray_real_T *gpu_r8;
  dim3 r_grid;
  dim3 r_block;
  emxArray_real_T *gpu_r9;
  int32_T *gpu_xoffset;
  int32_T *gpu_qEnd;
  int32_T (*gpu_ii_size)[1];
  dim3 s_grid;
  dim3 s_block;
  dim3 t_grid;
  dim3 t_block;
  emxArray_real_T *c_gpu_a;
  dim3 u_grid;
  dim3 u_block;
  emxArray_real_T *c_gpu_b;
  dim3 v_grid;
  dim3 v_block;
  emxArray_real_T *gpu_r4;
  dim3 w_grid;
  dim3 w_block;
  emxArray_real_T *gpu_r5;
  dim3 x_grid;
  dim3 x_block;
  dim3 y_grid;
  dim3 y_block;
  dim3 ab_grid;
  dim3 ab_block;
  emxArray_real_T *gpu_SLD;
  dim3 bb_grid;
  dim3 bb_block;
  uint32_T (*gpu_sz)[2];
  dim3 cb_grid;
  dim3 cb_block;
  dim3 db_grid;
  dim3 db_block;
  dim3 eb_grid;
  dim3 eb_block;
  emxArray_real_T *gpu_layers;
  real_T (*gpu_dataBoxSize)[2];
  real_T (*gpu_y)[50];
  dim3 fb_grid;
  dim3 fb_block;
  emxArray_boolean_T *b_gpu_x;
  dim3 gb_grid;
  dim3 gb_block;
  emxArray_boolean_T *c_gpu_x;
  dim3 hb_grid;
  dim3 hb_block;
  emxArray_boolean_T *d_gpu_x;
  emxArray_int32_T *gpu_ii;
  dim3 ib_grid;
  dim3 ib_block;
  emxArray_real_T *gpu_r11;
  real_T (*gpu_hiVal)[50];
  real_T (*b_gpu_y)[100];
  emxArray_real_T *gpu_dataPoints;
  real_T (*gpu_minval)[2];
  emxArray_real_T *gpu_r14;
  emxArray_real_T *d_gpu_b;
  dim3 jb_grid;
  dim3 jb_block;
  emxArray_real_T *gpu_normalizedData;
  dim3 kb_grid;
  dim3 kb_block;
  emxArray_real_T *gpu_firstStep;
  dim3 lb_grid;
  dim3 lb_block;
  emxArray_real_T *gpu_secondStep;
  dim3 mb_grid;
  dim3 mb_block;
  emxArray_real_T *gpu_longStep;
  dim3 nb_grid;
  dim3 nb_block;
  emxArray_real_T *gpu_z1;
  dim3 ob_grid;
  dim3 ob_block;
  emxArray_real_T *b_gpu_z1;
  dim3 pb_grid;
  dim3 pb_block;
  emxArray_real_T *gpu_firstStepSquared;
  dim3 qb_grid;
  dim3 qb_block;
  emxArray_real_T *c_gpu_z1;
  dim3 rb_grid;
  dim3 rb_block;
  emxArray_real_T *d_gpu_z1;
  dim3 sb_grid;
  dim3 sb_block;
  emxArray_real_T *gpu_secondStepSquared;
  dim3 tb_grid;
  dim3 tb_block;
  emxArray_real_T *e_gpu_z1;
  dim3 ub_grid;
  dim3 ub_block;
  emxArray_real_T *f_gpu_z1;
  dim3 vb_grid;
  dim3 vb_block;
  emxArray_real_T *e_gpu_x;
  dim3 wb_grid;
  dim3 wb_block;
  dim3 xb_grid;
  dim3 xb_block;
  emxArray_creal_T *f_gpu_x;
  dim3 yb_grid;
  dim3 yb_block;
  dim3 ac_grid;
  dim3 ac_block;
  emxArray_boolean_T *gpu_trianglesToRefine;
  dim3 bc_grid;
  dim3 bc_block;
  emxArray_boolean_T *b_gpu_trianglesToRefine;
  emxArray_boolean_T *gpu_r32;
  dim3 cc_grid;
  dim3 cc_block;
  dim3 dc_grid;
  dim3 dc_block;
  emxArray_boolean_T *gpu_segmentsToSplit;
  dim3 ec_grid;
  dim3 ec_block;
  emxArray_real_T *gpu_newDataPoints;
  dim3 fc_grid;
  dim3 fc_block;
  emxArray_boolean_T *gpu_r21;
  emxArray_boolean_T *gpu_r23;
  dim3 gc_grid;
  dim3 gc_block;
  emxArray_int32_T *gpu_r27;
  emxArray_int32_T *gpu_r25;
  dim3 hc_grid;
  dim3 hc_block;
  dim3 ic_grid;
  dim3 ic_block;
  emxArray_boolean_T *g_gpu_x;
  dim3 jc_grid;
  dim3 jc_block;
  emxArray_boolean_T *h_gpu_x;
  dim3 kc_grid;
  dim3 kc_block;
  emxArray_boolean_T *i_gpu_x;
  emxArray_int32_T *b_gpu_ii;
  dim3 lc_grid;
  dim3 lc_block;
  emxArray_real_T *gpu_r30;
  emxArray_real_T *gpu_r16;
  dim3 mc_grid;
  dim3 mc_block;
  dim3 nc_grid;
  dim3 nc_block;
  emxArray_real_T *b_gpu_dataPoints;
  dim3 oc_grid;
  dim3 oc_block;
  int8_T (*gpu_col_data)[2];
  dim3 pc_grid;
  dim3 pc_block;
  emxArray_int32_T *gpu_idx;
  dim3 qc_grid;
  dim3 qc_block;
  dim3 rc_grid;
  dim3 rc_block;
  emxArray_real_T *gpu_ycol;
  dim3 sc_grid;
  dim3 sc_block;
  emxArray_int32_T *gpu_iwork;
  dim3 tc_grid;
  dim3 tc_block;
  dim3 uc_grid;
  dim3 uc_block;
  dim3 vc_grid;
  dim3 vc_block;
  real_T (*gpu_shifted_dat_data)[153];
  boolean_T (*j_gpu_x)[51];
  int32_T (*gpu_shifted_dat_size)[2];
  dim3 wc_grid;
  dim3 wc_block;
  dim3 xc_grid;
  dim3 xc_block;
  emxArray_real_T *gpu_firstSection;
  dim3 yc_grid;
  dim3 yc_block;
  emxArray_real_T *gpu_lastSection;
  dim3 ad_grid;
  dim3 ad_block;
  emxArray_real_T *gpu_simXdata;
  dim3 bd_grid;
  dim3 bd_block;
  emxArray_real_T *gpu_Simul;
  dim3 cd_grid;
  dim3 cd_block;
  creal_T (*gpu_MI)[4];
  creal_T (*gpu_N)[4];
  creal_T (*b_gpu_MI)[4];
  dim3 dd_grid;
  dim3 dd_block;
  emxArray_real_T *gpu_dummydata;
  emxArray_real_T *gpu_simRef;
  dim3 ed_grid;
  dim3 ed_block;
  dim3 fd_grid;
  dim3 fd_block;
  dim3 gd_grid;
  dim3 gd_block;
  emxArray_real_T *gpu_reflect;
  dim3 hd_grid;
  dim3 hd_block;
  dim3 id_grid;
  dim3 id_block;
  dim3 jd_grid;
  dim3 jd_block;
  real_T (*gpu_terms_data)[51];
  dim3 kd_grid;
  dim3 kd_block;
  dim3 ld_grid;
  dim3 ld_block;
  emxArray_real_T *gpu_z;
  dim3 md_grid;
  dim3 md_block;
  emxArray_real_T *g_gpu_z1;
  dim3 nd_grid;
  dim3 nd_block;
  dim3 od_grid;
  dim3 od_block;
  emxArray_boolean_T *k_gpu_x;
  emxArray_int8_T *c_gpu_ii;
  dim3 pd_grid;
  dim3 pd_block;
  dim3 qd_grid;
  dim3 qd_block;
  emxArray_real_T *b_gpu_sldProfile;
  emxArray_real_T *l_gpu_x;
  emxArray_real_T *b_gpu_Lays;
  emxArray_real_T *d_gpu_a;
  emxArray_real_T *e_gpu_b;
  emxArray_real_T *gpu_r2;
  emxArray_real_T *gpu_r3;
  emxArray_real_T *e_gpu_a;
  emxArray_real_T *f_gpu_b;
  emxArray_real_T *gpu_r10;
  emxArray_real_T *gpu_r12;
  emxArray_real_T *f_gpu_a;
  emxArray_real_T *g_gpu_b;
  emxArray_real_T *gpu_r6;
  emxArray_real_T *gpu_r7;
  emxArray_real_T *b_gpu_SLD;
  emxArray_real_T *b_gpu_layers;
  emxArray_boolean_T *m_gpu_x;
  emxArray_boolean_T *n_gpu_x;
  emxArray_boolean_T *o_gpu_x;
  emxArray_int32_T *d_gpu_ii;
  emxArray_real_T *gpu_r13;
  emxArray_real_T *c_gpu_dataPoints;
  emxArray_real_T *gpu_r15;
  emxArray_real_T *h_gpu_b;
  emxArray_real_T *b_gpu_normalizedData;
  emxArray_real_T *b_gpu_firstStep;
  emxArray_real_T *b_gpu_secondStep;
  emxArray_real_T *b_gpu_longStep;
  emxArray_real_T *h_gpu_z1;
  emxArray_real_T *i_gpu_z1;
  emxArray_real_T *b_gpu_firstStepSquared;
  emxArray_real_T *j_gpu_z1;
  emxArray_real_T *k_gpu_z1;
  emxArray_real_T *b_gpu_secondStepSquared;
  emxArray_real_T *l_gpu_z1;
  emxArray_real_T *m_gpu_z1;
  emxArray_real_T *p_gpu_x;
  emxArray_creal_T *q_gpu_x;
  emxArray_boolean_T *c_gpu_trianglesToRefine;
  emxArray_boolean_T *d_gpu_trianglesToRefine;
  emxArray_boolean_T *gpu_r33;
  emxArray_boolean_T *b_gpu_segmentsToSplit;
  emxArray_real_T *b_gpu_newDataPoints;
  emxArray_boolean_T *gpu_r24;
  emxArray_boolean_T *gpu_r26;
  emxArray_int32_T *gpu_r29;
  emxArray_int32_T *gpu_r28;
  emxArray_boolean_T *r_gpu_x;
  emxArray_boolean_T *s_gpu_x;
  emxArray_boolean_T *t_gpu_x;
  emxArray_int32_T *e_gpu_ii;
  emxArray_real_T *gpu_r31;
  emxArray_real_T *gpu_r18;
  emxArray_real_T *d_gpu_dataPoints;
  emxArray_int32_T *b_gpu_idx;
  emxArray_real_T *b_gpu_ycol;
  emxArray_int32_T *b_gpu_iwork;
  emxArray_real_T *b_gpu_firstSection;
  emxArray_real_T *b_gpu_lastSection;
  emxArray_real_T *b_gpu_simXdata;
  emxArray_real_T *b_gpu_Simul;
  emxArray_real_T *b_gpu_dummydata;
  emxArray_real_T *b_gpu_simRef;
  emxArray_real_T *b_gpu_reflect;
  emxArray_real_T *b_gpu_z;
  emxArray_real_T *n_gpu_z1;
  emxArray_boolean_T *u_gpu_x;
  emxArray_int8_T *f_gpu_ii;
  dim3 rd_grid;
  dim3 rd_block;
  emxArray_int8_T *gpu_cell6;
  boolean_T dataBoxSize_dirtyOnGpu;
  boolean_T shifted_dat_data_dirtyOnGpu;
  boolean_T N_dirtyOnGpu;
  boolean_T problemDef_cells_dirtyOnCpu;
  boolean_T sz_dirtyOnCpu;
  boolean_T hiVal_dirtyOnCpu;
  emxArray_real_T inter_backgs;
  emxArray_real_T inter_qshifts;
  emxArray_real_T inter_sfs;
  emxArray_real_T inter_nbas;
  emxArray_real_T inter_nbss;
  emxArray_real_T inter_chis;
  emxArray_real_T inter_resols;
  emxArray_real_T inter_allRoughs;
  emxArray_real_T inter_sldProfile;
  emxArray_real_T inter_x;
  emxArray_real_T inter_Lays;
  emxArray_real_T inter_a;
  emxArray_real_T inter_b;
  emxArray_real_T inter_r;
  emxArray_real_T inter_r1;
  emxArray_real_T b_inter_a;
  emxArray_real_T b_inter_b;
  emxArray_real_T inter_r8;
  emxArray_real_T inter_r9;
  emxArray_real_T c_inter_a;
  emxArray_real_T c_inter_b;
  emxArray_real_T inter_r4;
  emxArray_real_T inter_r5;
  emxArray_real_T inter_SLD;
  emxArray_real_T inter_layers;
  emxArray_boolean_T b_inter_x;
  emxArray_int32_T inter_ii;
  emxArray_boolean_T c_inter_x;
  emxArray_boolean_T d_inter_x;
  emxArray_real_T inter_r11;
  emxArray_real_T inter_dataPoints;
  emxArray_real_T d_inter_b;
  emxArray_real_T inter_r14;
  emxArray_real_T inter_normalizedData;
  emxArray_real_T inter_firstStep;
  emxArray_real_T inter_secondStep;
  emxArray_real_T inter_longStep;
  emxArray_real_T inter_z1;
  emxArray_real_T b_inter_z1;
  emxArray_real_T inter_firstStepSquared;
  emxArray_real_T c_inter_z1;
  emxArray_real_T d_inter_z1;
  emxArray_real_T inter_secondStepSquared;
  emxArray_real_T e_inter_z1;
  emxArray_real_T f_inter_z1;
  emxArray_real_T e_inter_x;
  emxArray_creal_T f_inter_x;
  emxArray_boolean_T inter_trianglesToRefine;
  emxArray_boolean_T b_inter_trianglesToRefine;
  emxArray_boolean_T inter_r32;
  emxArray_boolean_T inter_segmentsToSplit;
  emxArray_real_T inter_newDataPoints;
  emxArray_boolean_T inter_r21;
  emxArray_boolean_T inter_r23;
  emxArray_int32_T inter_r25;
  emxArray_int32_T inter_r27;
  emxArray_real_T inter_r16;
  emxArray_boolean_T g_inter_x;
  emxArray_int32_T b_inter_ii;
  emxArray_boolean_T h_inter_x;
  emxArray_boolean_T i_inter_x;
  emxArray_real_T inter_r30;
  emxArray_real_T b_inter_dataPoints;
  emxArray_int32_T inter_idx;
  emxArray_int32_T inter_iwork;
  emxArray_real_T inter_ycol;
  emxArray_real_T inter_firstSection;
  emxArray_real_T inter_lastSection;
  emxArray_real_T inter_simXdata;
  emxArray_real_T inter_Simul;
  emxArray_real_T inter_simRef;
  emxArray_real_T inter_dummydata;
  emxArray_real_T inter_reflect;
  emxArray_real_T inter_z;
  emxArray_real_T g_inter_z1;
  emxArray_boolean_T j_inter_x;
  emxArray_int8_T c_inter_ii;
  emxArray_real_T b_inter_sldProfile;
  emxArray_real_T k_inter_x;
  emxArray_real_T b_inter_Lays;
  emxArray_real_T d_inter_a;
  emxArray_real_T e_inter_b;
  emxArray_real_T inter_r2;
  emxArray_real_T inter_r3;
  emxArray_real_T e_inter_a;
  emxArray_real_T f_inter_b;
  emxArray_real_T inter_r10;
  emxArray_real_T inter_r12;
  emxArray_real_T f_inter_a;
  emxArray_real_T g_inter_b;
  emxArray_real_T inter_r6;
  emxArray_real_T inter_r7;
  emxArray_real_T b_inter_SLD;
  emxArray_real_T b_inter_layers;
  emxArray_boolean_T l_inter_x;
  emxArray_int32_T d_inter_ii;
  emxArray_boolean_T m_inter_x;
  emxArray_boolean_T n_inter_x;
  emxArray_real_T inter_r13;
  emxArray_real_T c_inter_dataPoints;
  emxArray_real_T h_inter_b;
  emxArray_real_T inter_r15;
  emxArray_real_T b_inter_normalizedData;
  emxArray_real_T b_inter_firstStep;
  emxArray_real_T b_inter_secondStep;
  emxArray_real_T b_inter_longStep;
  emxArray_real_T h_inter_z1;
  emxArray_real_T i_inter_z1;
  emxArray_real_T b_inter_firstStepSquared;
  emxArray_real_T j_inter_z1;
  emxArray_real_T k_inter_z1;
  emxArray_real_T b_inter_secondStepSquared;
  emxArray_real_T l_inter_z1;
  emxArray_real_T m_inter_z1;
  emxArray_real_T o_inter_x;
  emxArray_creal_T p_inter_x;
  emxArray_boolean_T c_inter_trianglesToRefine;
  emxArray_boolean_T d_inter_trianglesToRefine;
  emxArray_boolean_T inter_r33;
  emxArray_boolean_T b_inter_segmentsToSplit;
  emxArray_real_T b_inter_newDataPoints;
  emxArray_boolean_T inter_r24;
  emxArray_boolean_T inter_r26;
  emxArray_int32_T inter_r28;
  emxArray_int32_T inter_r29;
  emxArray_real_T inter_r18;
  emxArray_boolean_T q_inter_x;
  emxArray_int32_T e_inter_ii;
  emxArray_boolean_T r_inter_x;
  emxArray_boolean_T s_inter_x;
  emxArray_real_T inter_r31;
  emxArray_real_T d_inter_dataPoints;
  emxArray_int32_T b_inter_idx;
  emxArray_int32_T b_inter_iwork;
  emxArray_real_T b_inter_ycol;
  emxArray_real_T b_inter_firstSection;
  emxArray_real_T b_inter_lastSection;
  emxArray_real_T b_inter_simXdata;
  emxArray_real_T b_inter_Simul;
  emxArray_real_T b_inter_simRef;
  emxArray_real_T b_inter_dummydata;
  emxArray_real_T b_inter_reflect;
  emxArray_real_T b_inter_z;
  emxArray_real_T n_inter_z1;
  emxArray_boolean_T t_inter_x;
  emxArray_int8_T f_inter_ii;
  emxArray_int8_T inter_cell6;
  int32_T exitg1;
  (void)problemDef_limits;

#define CUDACHECK(errCall)             checkCudaError(errCall, __FILE__, __LINE__)

  checkCudaError(cudaGetLastError(), __FILE__, __LINE__);
  CUDACHECK(cudaMalloc(&gpu_cell6, 32UL));
  gpuEmxReset_int8_T(&inter_cell6);
  CUDACHECK(cudaMalloc(&f_gpu_ii, 32UL));
  gpuEmxReset_int8_T(&f_inter_ii);
  CUDACHECK(cudaMalloc(&u_gpu_x, 32UL));
  gpuEmxReset_boolean_T(&t_inter_x);
  CUDACHECK(cudaMalloc(&n_gpu_z1, 32UL));
  gpuEmxReset_real_T(&n_inter_z1);
  CUDACHECK(cudaMalloc(&b_gpu_z, 32UL));
  gpuEmxReset_real_T(&b_inter_z);
  CUDACHECK(cudaMalloc(&b_gpu_reflect, 32UL));
  gpuEmxReset_real_T(&b_inter_reflect);
  CUDACHECK(cudaMalloc(&b_gpu_dummydata, 32UL));
  gpuEmxReset_real_T(&b_inter_dummydata);
  CUDACHECK(cudaMalloc(&b_gpu_simRef, 32UL));
  gpuEmxReset_real_T(&b_inter_simRef);
  CUDACHECK(cudaMalloc(&b_gpu_Simul, 32UL));
  gpuEmxReset_real_T(&b_inter_Simul);
  CUDACHECK(cudaMalloc(&b_gpu_simXdata, 32UL));
  gpuEmxReset_real_T(&b_inter_simXdata);
  CUDACHECK(cudaMalloc(&b_gpu_lastSection, 32UL));
  gpuEmxReset_real_T(&b_inter_lastSection);
  CUDACHECK(cudaMalloc(&b_gpu_firstSection, 32UL));
  gpuEmxReset_real_T(&b_inter_firstSection);
  CUDACHECK(cudaMalloc(&b_gpu_ycol, 32UL));
  gpuEmxReset_real_T(&b_inter_ycol);
  CUDACHECK(cudaMalloc(&b_gpu_iwork, 32UL));
  gpuEmxReset_int32_T(&b_inter_iwork);
  CUDACHECK(cudaMalloc(&b_gpu_idx, 32UL));
  gpuEmxReset_int32_T(&b_inter_idx);
  CUDACHECK(cudaMalloc(&d_gpu_dataPoints, 32UL));
  gpuEmxReset_real_T(&d_inter_dataPoints);
  CUDACHECK(cudaMalloc(&gpu_r31, 32UL));
  gpuEmxReset_real_T(&inter_r31);
  CUDACHECK(cudaMalloc(&t_gpu_x, 32UL));
  gpuEmxReset_boolean_T(&s_inter_x);
  CUDACHECK(cudaMalloc(&s_gpu_x, 32UL));
  gpuEmxReset_boolean_T(&r_inter_x);
  CUDACHECK(cudaMalloc(&e_gpu_ii, 32UL));
  gpuEmxReset_int32_T(&e_inter_ii);
  CUDACHECK(cudaMalloc(&r_gpu_x, 32UL));
  gpuEmxReset_boolean_T(&q_inter_x);
  CUDACHECK(cudaMalloc(&gpu_r18, 32UL));
  gpuEmxReset_real_T(&inter_r18);
  CUDACHECK(cudaMalloc(&gpu_r29, 32UL));
  gpuEmxReset_int32_T(&inter_r29);
  CUDACHECK(cudaMalloc(&gpu_r28, 32UL));
  gpuEmxReset_int32_T(&inter_r28);
  CUDACHECK(cudaMalloc(&gpu_r26, 32UL));
  gpuEmxReset_boolean_T(&inter_r26);
  CUDACHECK(cudaMalloc(&gpu_r24, 32UL));
  gpuEmxReset_boolean_T(&inter_r24);
  CUDACHECK(cudaMalloc(&b_gpu_newDataPoints, 32UL));
  gpuEmxReset_real_T(&b_inter_newDataPoints);
  CUDACHECK(cudaMalloc(&b_gpu_segmentsToSplit, 32UL));
  gpuEmxReset_boolean_T(&b_inter_segmentsToSplit);
  CUDACHECK(cudaMalloc(&gpu_r33, 32UL));
  gpuEmxReset_boolean_T(&inter_r33);
  CUDACHECK(cudaMalloc(&d_gpu_trianglesToRefine, 32UL));
  gpuEmxReset_boolean_T(&d_inter_trianglesToRefine);
  CUDACHECK(cudaMalloc(&c_gpu_trianglesToRefine, 32UL));
  gpuEmxReset_boolean_T(&c_inter_trianglesToRefine);
  CUDACHECK(cudaMalloc(&q_gpu_x, 32UL));
  gpuEmxReset_creal_T(&p_inter_x);
  CUDACHECK(cudaMalloc(&p_gpu_x, 32UL));
  gpuEmxReset_real_T(&o_inter_x);
  CUDACHECK(cudaMalloc(&m_gpu_z1, 32UL));
  gpuEmxReset_real_T(&m_inter_z1);
  CUDACHECK(cudaMalloc(&l_gpu_z1, 32UL));
  gpuEmxReset_real_T(&l_inter_z1);
  CUDACHECK(cudaMalloc(&b_gpu_secondStepSquared, 32UL));
  gpuEmxReset_real_T(&b_inter_secondStepSquared);
  CUDACHECK(cudaMalloc(&k_gpu_z1, 32UL));
  gpuEmxReset_real_T(&k_inter_z1);
  CUDACHECK(cudaMalloc(&j_gpu_z1, 32UL));
  gpuEmxReset_real_T(&j_inter_z1);
  CUDACHECK(cudaMalloc(&b_gpu_firstStepSquared, 32UL));
  gpuEmxReset_real_T(&b_inter_firstStepSquared);
  CUDACHECK(cudaMalloc(&i_gpu_z1, 32UL));
  gpuEmxReset_real_T(&i_inter_z1);
  CUDACHECK(cudaMalloc(&h_gpu_z1, 32UL));
  gpuEmxReset_real_T(&h_inter_z1);
  CUDACHECK(cudaMalloc(&b_gpu_longStep, 32UL));
  gpuEmxReset_real_T(&b_inter_longStep);
  CUDACHECK(cudaMalloc(&b_gpu_secondStep, 32UL));
  gpuEmxReset_real_T(&b_inter_secondStep);
  CUDACHECK(cudaMalloc(&b_gpu_firstStep, 32UL));
  gpuEmxReset_real_T(&b_inter_firstStep);
  CUDACHECK(cudaMalloc(&b_gpu_normalizedData, 32UL));
  gpuEmxReset_real_T(&b_inter_normalizedData);
  CUDACHECK(cudaMalloc(&gpu_r15, 32UL));
  gpuEmxReset_real_T(&inter_r15);
  CUDACHECK(cudaMalloc(&h_gpu_b, 32UL));
  gpuEmxReset_real_T(&h_inter_b);
  CUDACHECK(cudaMalloc(&c_gpu_dataPoints, 32UL));
  gpuEmxReset_real_T(&c_inter_dataPoints);
  CUDACHECK(cudaMalloc(&gpu_r13, 32UL));
  gpuEmxReset_real_T(&inter_r13);
  CUDACHECK(cudaMalloc(&o_gpu_x, 32UL));
  gpuEmxReset_boolean_T(&n_inter_x);
  CUDACHECK(cudaMalloc(&n_gpu_x, 32UL));
  gpuEmxReset_boolean_T(&m_inter_x);
  CUDACHECK(cudaMalloc(&d_gpu_ii, 32UL));
  gpuEmxReset_int32_T(&d_inter_ii);
  CUDACHECK(cudaMalloc(&m_gpu_x, 32UL));
  gpuEmxReset_boolean_T(&l_inter_x);
  CUDACHECK(cudaMalloc(&b_gpu_layers, 32UL));
  gpuEmxReset_real_T(&b_inter_layers);
  CUDACHECK(cudaMalloc(&b_gpu_SLD, 32UL));
  gpuEmxReset_real_T(&b_inter_SLD);
  CUDACHECK(cudaMalloc(&gpu_r7, 32UL));
  gpuEmxReset_real_T(&inter_r7);
  CUDACHECK(cudaMalloc(&gpu_r6, 32UL));
  gpuEmxReset_real_T(&inter_r6);
  CUDACHECK(cudaMalloc(&g_gpu_b, 32UL));
  gpuEmxReset_real_T(&g_inter_b);
  CUDACHECK(cudaMalloc(&f_gpu_a, 32UL));
  gpuEmxReset_real_T(&f_inter_a);
  CUDACHECK(cudaMalloc(&gpu_r12, 32UL));
  gpuEmxReset_real_T(&inter_r12);
  CUDACHECK(cudaMalloc(&gpu_r10, 32UL));
  gpuEmxReset_real_T(&inter_r10);
  CUDACHECK(cudaMalloc(&f_gpu_b, 32UL));
  gpuEmxReset_real_T(&f_inter_b);
  CUDACHECK(cudaMalloc(&e_gpu_a, 32UL));
  gpuEmxReset_real_T(&e_inter_a);
  CUDACHECK(cudaMalloc(&gpu_r3, 32UL));
  gpuEmxReset_real_T(&inter_r3);
  CUDACHECK(cudaMalloc(&gpu_r2, 32UL));
  gpuEmxReset_real_T(&inter_r2);
  CUDACHECK(cudaMalloc(&e_gpu_b, 32UL));
  gpuEmxReset_real_T(&e_inter_b);
  CUDACHECK(cudaMalloc(&d_gpu_a, 32UL));
  gpuEmxReset_real_T(&d_inter_a);
  CUDACHECK(cudaMalloc(&b_gpu_Lays, 32UL));
  gpuEmxReset_real_T(&b_inter_Lays);
  CUDACHECK(cudaMalloc(&l_gpu_x, 32UL));
  gpuEmxReset_real_T(&k_inter_x);
  CUDACHECK(cudaMalloc(&b_gpu_sldProfile, 32UL));
  gpuEmxReset_real_T(&b_inter_sldProfile);
  CUDACHECK(cudaMalloc(&c_gpu_ii, 32UL));
  gpuEmxReset_int8_T(&c_inter_ii);
  CUDACHECK(cudaMalloc(&k_gpu_x, 32UL));
  gpuEmxReset_boolean_T(&j_inter_x);
  CUDACHECK(cudaMalloc(&g_gpu_z1, 32UL));
  gpuEmxReset_real_T(&g_inter_z1);
  CUDACHECK(cudaMalloc(&gpu_z, 32UL));
  gpuEmxReset_real_T(&inter_z);
  CUDACHECK(cudaMalloc(&gpu_terms_data, 51U * sizeof(real_T)));
  CUDACHECK(cudaMalloc(&gpu_reflect, 32UL));
  gpuEmxReset_real_T(&inter_reflect);
  CUDACHECK(cudaMalloc(&gpu_dummydata, 32UL));
  gpuEmxReset_real_T(&inter_dummydata);
  CUDACHECK(cudaMalloc(&b_gpu_MI, 64UL));
  CUDACHECK(cudaMalloc(&gpu_N, 64UL));
  CUDACHECK(cudaMalloc(&gpu_MI, 64UL));
  CUDACHECK(cudaMalloc(&gpu_simRef, 32UL));
  gpuEmxReset_real_T(&inter_simRef);
  CUDACHECK(cudaMalloc(&gpu_Simul, 32UL));
  gpuEmxReset_real_T(&inter_Simul);
  CUDACHECK(cudaMalloc(&gpu_simXdata, 32UL));
  gpuEmxReset_real_T(&inter_simXdata);
  CUDACHECK(cudaMalloc(&gpu_lastSection, 32UL));
  gpuEmxReset_real_T(&inter_lastSection);
  CUDACHECK(cudaMalloc(&gpu_firstSection, 32UL));
  gpuEmxReset_real_T(&inter_firstSection);
  CUDACHECK(cudaMalloc(&j_gpu_x, 51UL));
  CUDACHECK(cudaMalloc(&gpu_shifted_dat_data, 153U * sizeof(real_T)));
  CUDACHECK(cudaMalloc(&gpu_shifted_dat_size, 8UL));
  CUDACHECK(cudaMalloc(&gpu_ycol, 32UL));
  gpuEmxReset_real_T(&inter_ycol);
  CUDACHECK(cudaMalloc(&gpu_iwork, 32UL));
  gpuEmxReset_int32_T(&inter_iwork);
  CUDACHECK(cudaMalloc(&gpu_idx, 32UL));
  gpuEmxReset_int32_T(&inter_idx);
  CUDACHECK(cudaMalloc(&gpu_col_data, 2U * sizeof(int8_T)));
  CUDACHECK(cudaMalloc(&b_gpu_dataPoints, 32UL));
  gpuEmxReset_real_T(&b_inter_dataPoints);
  CUDACHECK(cudaMalloc(&gpu_r30, 32UL));
  gpuEmxReset_real_T(&inter_r30);
  CUDACHECK(cudaMalloc(&i_gpu_x, 32UL));
  gpuEmxReset_boolean_T(&i_inter_x);
  CUDACHECK(cudaMalloc(&h_gpu_x, 32UL));
  gpuEmxReset_boolean_T(&h_inter_x);
  CUDACHECK(cudaMalloc(&b_gpu_ii, 32UL));
  gpuEmxReset_int32_T(&b_inter_ii);
  CUDACHECK(cudaMalloc(&g_gpu_x, 32UL));
  gpuEmxReset_boolean_T(&g_inter_x);
  CUDACHECK(cudaMalloc(&gpu_r16, 32UL));
  gpuEmxReset_real_T(&inter_r16);
  CUDACHECK(cudaMalloc(&gpu_r27, 32UL));
  gpuEmxReset_int32_T(&inter_r27);
  CUDACHECK(cudaMalloc(&gpu_r25, 32UL));
  gpuEmxReset_int32_T(&inter_r25);
  CUDACHECK(cudaMalloc(&gpu_r23, 32UL));
  gpuEmxReset_boolean_T(&inter_r23);
  CUDACHECK(cudaMalloc(&gpu_r21, 32UL));
  gpuEmxReset_boolean_T(&inter_r21);
  CUDACHECK(cudaMalloc(&gpu_newDataPoints, 32UL));
  gpuEmxReset_real_T(&inter_newDataPoints);
  CUDACHECK(cudaMalloc(&gpu_segmentsToSplit, 32UL));
  gpuEmxReset_boolean_T(&inter_segmentsToSplit);
  CUDACHECK(cudaMalloc(&gpu_r32, 32UL));
  gpuEmxReset_boolean_T(&inter_r32);
  CUDACHECK(cudaMalloc(&b_gpu_trianglesToRefine, 32UL));
  gpuEmxReset_boolean_T(&b_inter_trianglesToRefine);
  CUDACHECK(cudaMalloc(&gpu_trianglesToRefine, 32UL));
  gpuEmxReset_boolean_T(&inter_trianglesToRefine);
  CUDACHECK(cudaMalloc(&f_gpu_x, 32UL));
  gpuEmxReset_creal_T(&f_inter_x);
  CUDACHECK(cudaMalloc(&e_gpu_x, 32UL));
  gpuEmxReset_real_T(&e_inter_x);
  CUDACHECK(cudaMalloc(&f_gpu_z1, 32UL));
  gpuEmxReset_real_T(&f_inter_z1);
  CUDACHECK(cudaMalloc(&e_gpu_z1, 32UL));
  gpuEmxReset_real_T(&e_inter_z1);
  CUDACHECK(cudaMalloc(&gpu_secondStepSquared, 32UL));
  gpuEmxReset_real_T(&inter_secondStepSquared);
  CUDACHECK(cudaMalloc(&d_gpu_z1, 32UL));
  gpuEmxReset_real_T(&d_inter_z1);
  CUDACHECK(cudaMalloc(&c_gpu_z1, 32UL));
  gpuEmxReset_real_T(&c_inter_z1);
  CUDACHECK(cudaMalloc(&gpu_firstStepSquared, 32UL));
  gpuEmxReset_real_T(&inter_firstStepSquared);
  CUDACHECK(cudaMalloc(&b_gpu_z1, 32UL));
  gpuEmxReset_real_T(&b_inter_z1);
  CUDACHECK(cudaMalloc(&gpu_z1, 32UL));
  gpuEmxReset_real_T(&inter_z1);
  CUDACHECK(cudaMalloc(&gpu_longStep, 32UL));
  gpuEmxReset_real_T(&inter_longStep);
  CUDACHECK(cudaMalloc(&gpu_secondStep, 32UL));
  gpuEmxReset_real_T(&inter_secondStep);
  CUDACHECK(cudaMalloc(&gpu_firstStep, 32UL));
  gpuEmxReset_real_T(&inter_firstStep);
  CUDACHECK(cudaMalloc(&gpu_normalizedData, 32UL));
  gpuEmxReset_real_T(&inter_normalizedData);
  CUDACHECK(cudaMalloc(&gpu_r14, 32UL));
  gpuEmxReset_real_T(&inter_r14);
  CUDACHECK(cudaMalloc(&d_gpu_b, 32UL));
  gpuEmxReset_real_T(&d_inter_b);
  CUDACHECK(cudaMalloc(&gpu_minval, 16UL));
  CUDACHECK(cudaMalloc(&gpu_dataPoints, 32UL));
  gpuEmxReset_real_T(&inter_dataPoints);
  CUDACHECK(cudaMalloc(&b_gpu_y, 800UL));
  CUDACHECK(cudaMalloc(&gpu_hiVal, 400UL));
  CUDACHECK(cudaMalloc(&gpu_r11, 32UL));
  gpuEmxReset_real_T(&inter_r11);
  CUDACHECK(cudaMalloc(&d_gpu_x, 32UL));
  gpuEmxReset_boolean_T(&d_inter_x);
  CUDACHECK(cudaMalloc(&c_gpu_x, 32UL));
  gpuEmxReset_boolean_T(&c_inter_x);
  CUDACHECK(cudaMalloc(&gpu_ii, 32UL));
  gpuEmxReset_int32_T(&inter_ii);
  CUDACHECK(cudaMalloc(&b_gpu_x, 32UL));
  gpuEmxReset_boolean_T(&b_inter_x);
  CUDACHECK(cudaMalloc(&gpu_y, 400UL));
  CUDACHECK(cudaMalloc(&gpu_dataBoxSize, 16UL));
  CUDACHECK(cudaMalloc(&gpu_layers, 32UL));
  gpuEmxReset_real_T(&inter_layers);
  CUDACHECK(cudaMalloc(&gpu_sz, 8UL));
  CUDACHECK(cudaMalloc(&gpu_SLD, 32UL));
  gpuEmxReset_real_T(&inter_SLD);
  CUDACHECK(cudaMalloc(&gpu_r5, 32UL));
  gpuEmxReset_real_T(&inter_r5);
  CUDACHECK(cudaMalloc(&gpu_r4, 32UL));
  gpuEmxReset_real_T(&inter_r4);
  CUDACHECK(cudaMalloc(&c_gpu_b, 32UL));
  gpuEmxReset_real_T(&c_inter_b);
  CUDACHECK(cudaMalloc(&c_gpu_a, 32UL));
  gpuEmxReset_real_T(&c_inter_a);
  CUDACHECK(cudaMalloc(&gpu_ii_size, 4UL));
  CUDACHECK(cudaMalloc(&gpu_r9, 32UL));
  gpuEmxReset_real_T(&inter_r9);
  CUDACHECK(cudaMalloc(&gpu_r8, 32UL));
  gpuEmxReset_real_T(&inter_r8);
  CUDACHECK(cudaMalloc(&b_gpu_b, 32UL));
  gpuEmxReset_real_T(&b_inter_b);
  CUDACHECK(cudaMalloc(&gpu_qEnd, 4UL));
  CUDACHECK(cudaMalloc(&b_gpu_a, 32UL));
  gpuEmxReset_real_T(&b_inter_a);
  CUDACHECK(cudaMalloc(&gpu_r1, 32UL));
  gpuEmxReset_real_T(&inter_r1);
  CUDACHECK(cudaMalloc(&gpu_nx, 4UL));
  CUDACHECK(cudaMalloc(&gpu_r, 32UL));
  gpuEmxReset_real_T(&inter_r);
  CUDACHECK(cudaMalloc(&gpu_b, 32UL));
  gpuEmxReset_real_T(&inter_b);
  CUDACHECK(cudaMalloc(&gpu_a, 32UL));
  gpuEmxReset_real_T(&inter_a);
  CUDACHECK(cudaMalloc(&gpu_Lays, 32UL));
  gpuEmxReset_real_T(&inter_Lays);
  CUDACHECK(cudaMalloc(&gpu_x, 32UL));
  gpuEmxReset_real_T(&inter_x);
  CUDACHECK(cudaMalloc(&gpu_sldProfile, 32UL));
  gpuEmxReset_real_T(&inter_sldProfile);
  CUDACHECK(cudaMalloc(&gpu_layerThicks, 8UL));
  CUDACHECK(cudaMalloc(&gpu_layers_data, 10U * sizeof(real_T)));
  CUDACHECK(cudaMalloc(&gpu_layers_size, 8UL));
  CUDACHECK(cudaMalloc(&gpu_thisData, 1224UL));
  CUDACHECK(cudaMalloc(&gpu_thisContrastLayers, 80UL));
  CUDACHECK(cudaMalloc(&gpu_outParameterisedLayers, 160UL));
  CUDACHECK(cudaMalloc(&gpu_problemDef_cells, 9424UL));
  CUDACHECK(cudaMalloc(&gpu_thisOutLayer, 40UL));
  CUDACHECK(cudaMalloc(&gpu_allRoughs, 32UL));
  gpuEmxReset_real_T(&inter_allRoughs);
  CUDACHECK(cudaMalloc(&gpu_resols, 32UL));
  gpuEmxReset_real_T(&inter_resols);
  CUDACHECK(cudaMalloc(&gpu_chis, 32UL));
  gpuEmxReset_real_T(&inter_chis);
  CUDACHECK(cudaMalloc(&gpu_nbss, 32UL));
  gpuEmxReset_real_T(&inter_nbss);
  CUDACHECK(cudaMalloc(&gpu_nbas, 32UL));
  gpuEmxReset_real_T(&inter_nbas);
  CUDACHECK(cudaMalloc(&gpu_sfs, 32UL));
  gpuEmxReset_real_T(&inter_sfs);
  CUDACHECK(cudaMalloc(&gpu_qshifts, 32UL));
  gpuEmxReset_real_T(&inter_qshifts);
  CUDACHECK(cudaMalloc(&gpu_backgs, 32UL));
  gpuEmxReset_real_T(&inter_backgs);
  CUDACHECK(cudaMalloc(&gpu_xoffset, 4UL));
  hiVal_dirtyOnCpu = false;
  sz_dirtyOnCpu = false;
  N_dirtyOnGpu = false;
  shifted_dat_data_dirtyOnGpu = false;
  dataBoxSize_dirtyOnGpu = false;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_cell_wrap_14(&reflectivity, 1, true);

  // Preallocatin of outputs
  i = problem->ssubs->size[0];
  problem->ssubs->size[0] = 1;
  emxEnsureCapacity_real_T(problem->ssubs, i);
  problem->ssubs->data[0] = 0.0;
  i = problem->backgrounds->size[0];
  problem->backgrounds->size[0] = 1;
  emxEnsureCapacity_real_T(problem->backgrounds, i);
  problem->backgrounds->data[0] = 0.0;
  i = problem->qshifts->size[0];
  problem->qshifts->size[0] = 1;
  emxEnsureCapacity_real_T(problem->qshifts, i);
  problem->qshifts->data[0] = 0.0;
  i = problem->scalefactors->size[0];
  problem->scalefactors->size[0] = 1;
  emxEnsureCapacity_real_T(problem->scalefactors, i);
  problem->scalefactors->data[0] = 0.0;
  i = problem->nbairs->size[0];
  problem->nbairs->size[0] = 1;
  emxEnsureCapacity_real_T(problem->nbairs, i);
  problem->nbairs->data[0] = 0.0;
  i = problem->nbsubs->size[0];
  problem->nbsubs->size[0] = 1;
  emxEnsureCapacity_real_T(problem->nbsubs, i);
  problem->nbsubs->data[0] = 0.0;
  i = problem->resolutions->size[0];
  problem->resolutions->size[0] = 1;
  emxEnsureCapacity_real_T(problem->resolutions, i);
  problem->resolutions->data[0] = 0.0;
  i = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = 1;
  emxEnsureCapacity_real_T(problem->calculations.all_chis, i);
  problem->calculations.all_chis->data[0] = 0.0;
  problem->calculations.sum_chi = 0.0;
  i = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = 1;
  emxEnsureCapacity_real_T(problem->allSubRough, i);
  problem->allSubRough->data[0] = 0.0;
  i = static_cast<int32_T>(problemDef->numberOfContrasts) - 1;
  kEnd = reflectivity->size[0];
  reflectivity->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
  emxEnsureCapacity_cell_wrap_14(reflectivity, kEnd);
  for (b_i = 0; b_i <= i; b_i++) {
    reflectivity->data[b_i].f1.size[0] = 2;
    reflectivity->data[b_i].f1.size[1] = 2;
    for (vlen = 0; vlen < 4; vlen++) {
      reflectivity->data[b_i].f1.data[vlen] = 1.0;
    }
  }

  emxInit_cell_wrap_14(&Simulation, 1, true);
  i = static_cast<int32_T>(problemDef->numberOfContrasts) - 1;
  kEnd = Simulation->size[0];
  Simulation->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
  emxEnsureCapacity_cell_wrap_14(Simulation, kEnd);
  for (b_i = 0; b_i <= i; b_i++) {
    Simulation->data[b_i].f1.size[0] = 2;
    Simulation->data[b_i].f1.size[1] = 2;
    for (vlen = 0; vlen < 4; vlen++) {
      Simulation->data[b_i].f1.data[vlen] = 1.0;
    }
  }

  emxInit_cell_wrap_15(&shifted_data, 1, true);
  i = static_cast<int32_T>(problemDef->numberOfContrasts) - 1;
  kEnd = shifted_data->size[0];
  shifted_data->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
  emxEnsureCapacity_cell_wrap_15(shifted_data, kEnd);
  for (b_i = 0; b_i <= i; b_i++) {
    shifted_data->data[b_i].f1.size[0] = 2;
    shifted_data->data[b_i].f1.size[1] = 3;
    for (vlen = 0; vlen < 6; vlen++) {
      shifted_data->data[b_i].f1.data[vlen] = 1.0;
    }
  }

  emxInit_cell_wrap_15(&layerSlds, 1, true);
  i = static_cast<int32_T>(problemDef->numberOfContrasts) - 1;
  kEnd = layerSlds->size[0];
  layerSlds->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
  emxEnsureCapacity_cell_wrap_15(layerSlds, kEnd);
  for (b_i = 0; b_i <= i; b_i++) {
    layerSlds->data[b_i].f1.size[0] = 2;
    layerSlds->data[b_i].f1.size[1] = 3;
    for (vlen = 0; vlen < 6; vlen++) {
      layerSlds->data[b_i].f1.data[vlen] = 1.0;
    }
  }

  emxInit_cell_wrap_14(&sldProfiles, 1, true);
  i = static_cast<int32_T>(problemDef->numberOfContrasts) - 1;
  kEnd = sldProfiles->size[0];
  sldProfiles->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
  emxEnsureCapacity_cell_wrap_14(sldProfiles, kEnd);
  for (b_i = 0; b_i <= i; b_i++) {
    sldProfiles->data[b_i].f1.size[0] = 2;
    sldProfiles->data[b_i].f1.size[1] = 2;
    for (vlen = 0; vlen < 4; vlen++) {
      sldProfiles->data[b_i].f1.data[vlen] = 1.0;
    }
  }

  // Decide which target function we are calling
  b_bool = false;
  xoffset = 0;
  do {
    exitg1 = 0;
    if (xoffset + 1 < 11) {
      if (problemDef->TF[xoffset] != cv[xoffset]) {
        exitg1 = 1;
      } else {
        xoffset++;
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (b_bool) {
    vlen = 0;
  } else {
    vlen = -1;
  }

  switch (vlen) {
   case 0:
    {
      real_T shifts;
      real_T sf;
      real_T nba;
      real_T calcSld;
      int32_T vstride;
      int32_T j;
      int32_T n;
      boolean_T backgs_dirtyOnGpu;
      boolean_T qshifts_dirtyOnGpu;
      boolean_T sfs_dirtyOnGpu;
      boolean_T nbas_dirtyOnGpu;
      boolean_T nbss_dirtyOnGpu;
      boolean_T chis_dirtyOnGpu;
      boolean_T resols_dirtyOnGpu;
      boolean_T allRoughs_dirtyOnGpu;
      emxInit_real_T(&outSsubs, 1, true);
      emxInit_real_T(&backgs, 1, true);
      backgs_dirtyOnGpu = false;

      // Decide what kind of calculation it is and call the appropriate one
      //  Pre-allocate the output arrays..
      //  switch type
      //      case 'layers'
      // Extract individual parameters from problemDef
      // nbairs = problemDef.nbairs;
      // nbsubs = problemDef.nbsubs;
      // repeats = problemDef.repeatLayers;
      shifts = problemDef->shifts;
      sf = problemDef->sf;
      nba = problemDef->nba;

      // allData = problemDef.allData;
      // dataLimits = problemDef.dataLimits;
      // simLimits = problemDef.simLimits;
      // repeatLayers = problemDef.repeatLayers;
      // contrastLayers = problemDef.contrastLayers;
      // layersDetails = problemDef.layersDetails;
      calcSld = controls->calcSld;

      // Pre-allocation
      i = outSsubs->size[0];
      outSsubs->size[0] = 1;
      emxEnsureCapacity_real_T(outSsubs, i);
      outSsubs->data[0] = problemDef->params[0];
      i = backgs->size[0];
      backgs->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
      emxEnsureCapacity_real_T(backgs, i);
      validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((
        static_cast<int32_T>(problemDef->numberOfContrasts) - 1) + 1L), &grid,
        &block, 1024U, 65535U);
      if (validLaunchParams) {
        gpuEmxMemcpyCpuToGpu_real_T(backgs, &inter_backgs, gpu_backgs);
        d_reflectivity_calculation_gpu_<<<grid, block>>>(*problemDef, gpu_backgs);
        CUDACHECK(cudaGetLastError());
        backgs_dirtyOnGpu = true;
      }

      emxInit_real_T(&qshifts, 1, true);
      qshifts_dirtyOnGpu = false;
      i = qshifts->size[0];
      qshifts->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
      emxEnsureCapacity_real_T(qshifts, i);
      validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((
        static_cast<int32_T>(problemDef->numberOfContrasts) - 1) + 1L), &b_grid,
        &b_block, 1024U, 65535U);
      if (validLaunchParams) {
        gpuEmxMemcpyCpuToGpu_real_T(qshifts, &inter_qshifts, gpu_qshifts);
        e_reflectivity_calculation_gpu_<<<b_grid, b_block>>>(*problemDef,
          gpu_qshifts);
        CUDACHECK(cudaGetLastError());
        qshifts_dirtyOnGpu = true;
      }

      emxInit_real_T(&sfs, 1, true);
      sfs_dirtyOnGpu = false;
      i = sfs->size[0];
      sfs->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
      emxEnsureCapacity_real_T(sfs, i);
      validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((
        static_cast<int32_T>(problemDef->numberOfContrasts) - 1) + 1L), &c_grid,
        &c_block, 1024U, 65535U);
      if (validLaunchParams) {
        gpuEmxMemcpyCpuToGpu_real_T(sfs, &inter_sfs, gpu_sfs);
        f_reflectivity_calculation_gpu_<<<c_grid, c_block>>>(*problemDef,
          gpu_sfs);
        CUDACHECK(cudaGetLastError());
        sfs_dirtyOnGpu = true;
      }

      emxInit_real_T(&nbas, 1, true);
      nbas_dirtyOnGpu = false;
      i = nbas->size[0];
      nbas->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
      emxEnsureCapacity_real_T(nbas, i);
      validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((
        static_cast<int32_T>(problemDef->numberOfContrasts) - 1) + 1L), &d_grid,
        &d_block, 1024U, 65535U);
      if (validLaunchParams) {
        gpuEmxMemcpyCpuToGpu_real_T(nbas, &inter_nbas, gpu_nbas);
        g_reflectivity_calculation_gpu_<<<d_grid, d_block>>>(*problemDef,
          gpu_nbas);
        CUDACHECK(cudaGetLastError());
        nbas_dirtyOnGpu = true;
      }

      emxInit_real_T(&nbss, 1, true);
      nbss_dirtyOnGpu = false;
      i = nbss->size[0];
      nbss->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
      emxEnsureCapacity_real_T(nbss, i);
      validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((
        static_cast<int32_T>(problemDef->numberOfContrasts) - 1) + 1L), &e_grid,
        &e_block, 1024U, 65535U);
      if (validLaunchParams) {
        gpuEmxMemcpyCpuToGpu_real_T(nbss, &inter_nbss, gpu_nbss);
        h_reflectivity_calculation_gpu_<<<e_grid, e_block>>>(*problemDef,
          gpu_nbss);
        CUDACHECK(cudaGetLastError());
        nbss_dirtyOnGpu = true;
      }

      emxInit_real_T(&chis, 1, true);
      chis_dirtyOnGpu = false;
      i = chis->size[0];
      chis->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
      emxEnsureCapacity_real_T(chis, i);
      validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((
        static_cast<int32_T>(problemDef->numberOfContrasts) - 1) + 1L), &f_grid,
        &f_block, 1024U, 65535U);
      if (validLaunchParams) {
        gpuEmxMemcpyCpuToGpu_real_T(chis, &inter_chis, gpu_chis);
        i_reflectivity_calculation_gpu_<<<f_grid, f_block>>>(*problemDef,
          gpu_chis);
        CUDACHECK(cudaGetLastError());
        chis_dirtyOnGpu = true;
      }

      emxInit_real_T(&resols, 1, true);
      resols_dirtyOnGpu = false;
      i = resols->size[0];
      resols->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
      emxEnsureCapacity_real_T(resols, i);
      validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((
        static_cast<int32_T>(problemDef->numberOfContrasts) - 1) + 1L), &g_grid,
        &g_block, 1024U, 65535U);
      if (validLaunchParams) {
        gpuEmxMemcpyCpuToGpu_real_T(resols, &inter_resols, gpu_resols);
        j_reflectivity_calculation_gpu_<<<g_grid, g_block>>>(*problemDef,
          gpu_resols);
        CUDACHECK(cudaGetLastError());
        resols_dirtyOnGpu = true;
      }

      emxInit_real_T(&allRoughs, 1, true);
      allRoughs_dirtyOnGpu = false;
      i = allRoughs->size[0];
      allRoughs->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
      emxEnsureCapacity_real_T(allRoughs, i);
      validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((
        static_cast<int32_T>(problemDef->numberOfContrasts) - 1) + 1L), &h_grid,
        &h_block, 1024U, 65535U);
      if (validLaunchParams) {
        gpuEmxMemcpyCpuToGpu_real_T(allRoughs, &inter_allRoughs, gpu_allRoughs);
        k_reflectivity_calculation_gpu_<<<h_grid, h_block>>>(*problemDef,
          gpu_allRoughs);
        CUDACHECK(cudaGetLastError());
        allRoughs_dirtyOnGpu = true;
      }

      emxInit_cell_wrap_11(&b_reflectivity, 1, true);
      i = static_cast<int32_T>(problemDef->numberOfContrasts);
      kEnd = b_reflectivity->size[0];
      b_reflectivity->size[0] = static_cast<int32_T>
        (problemDef->numberOfContrasts);
      emxEnsureCapacity_cell_wrap_11(b_reflectivity, kEnd);
      for (b_i = 0; b_i < i; b_i++) {
        kEnd = b_reflectivity->data[b_i].f1->size[0] * b_reflectivity->data[b_i]
          .f1->size[1];
        b_reflectivity->data[b_i].f1->size[0] = 2;
        b_reflectivity->data[b_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(b_reflectivity->data[b_i].f1, kEnd);
        for (kEnd = 0; kEnd < 4; kEnd++) {
          b_reflectivity->data[b_i].f1->data[kEnd] = 1.0;
        }
      }

      emxInit_cell_wrap_11(&b_Simulation, 1, true);
      i = static_cast<int32_T>(problemDef->numberOfContrasts);
      kEnd = b_Simulation->size[0];
      b_Simulation->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
      emxEnsureCapacity_cell_wrap_11(b_Simulation, kEnd);
      for (b_i = 0; b_i < i; b_i++) {
        kEnd = b_Simulation->data[b_i].f1->size[0] * b_Simulation->data[b_i].
          f1->size[1];
        b_Simulation->data[b_i].f1->size[0] = 2;
        b_Simulation->data[b_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(b_Simulation->data[b_i].f1, kEnd);
        for (kEnd = 0; kEnd < 4; kEnd++) {
          b_Simulation->data[b_i].f1->data[kEnd] = 1.0;
        }
      }

      emxInit_cell_wrap_12(&b_shifted_data, 1, true);
      i = static_cast<int32_T>(problemDef->numberOfContrasts);
      kEnd = b_shifted_data->size[0];
      b_shifted_data->size[0] = static_cast<int32_T>
        (problemDef->numberOfContrasts);
      emxEnsureCapacity_cell_wrap_12(b_shifted_data, kEnd);
      for (b_i = 0; b_i < i; b_i++) {
        kEnd = b_shifted_data->data[b_i].f1->size[0] * b_shifted_data->data[b_i]
          .f1->size[1];
        b_shifted_data->data[b_i].f1->size[0] = 2;
        b_shifted_data->data[b_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(b_shifted_data->data[b_i].f1, kEnd);
        for (kEnd = 0; kEnd < 6; kEnd++) {
          b_shifted_data->data[b_i].f1->data[kEnd] = 1.0;
        }
      }

      emxInit_cell_wrap_12(&b_layerSlds, 1, true);
      i = static_cast<int32_T>(problemDef->numberOfContrasts);
      kEnd = b_layerSlds->size[0];
      b_layerSlds->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
      emxEnsureCapacity_cell_wrap_12(b_layerSlds, kEnd);
      for (b_i = 0; b_i < i; b_i++) {
        kEnd = b_layerSlds->data[b_i].f1->size[0] * b_layerSlds->data[b_i]
          .f1->size[1];
        b_layerSlds->data[b_i].f1->size[0] = 2;
        b_layerSlds->data[b_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(b_layerSlds->data[b_i].f1, kEnd);
        for (kEnd = 0; kEnd < 6; kEnd++) {
          b_layerSlds->data[b_i].f1->data[kEnd] = 1.0;
        }
      }

      emxInit_cell_wrap_17(&b_sldProfiles, 1, true);
      i = static_cast<int32_T>(problemDef->numberOfContrasts);
      kEnd = b_sldProfiles->size[0];
      b_sldProfiles->size[0] = static_cast<int32_T>
        (problemDef->numberOfContrasts);
      emxEnsureCapacity_cell_wrap_17(b_sldProfiles, kEnd);
      for (b_i = 0; b_i < i; b_i++) {
        kEnd = b_sldProfiles->data[b_i].f1->size[0] * b_sldProfiles->data[b_i].
          f1->size[1];
        b_sldProfiles->data[b_i].f1->size[0] = 2;
        b_sldProfiles->data[b_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(b_sldProfiles->data[b_i].f1, kEnd);
        for (kEnd = 0; kEnd < 4; kEnd++) {
          b_sldProfiles->data[b_i].f1->data[kEnd] = 1.0;
        }
      }

      b_bool = false;
      xoffset = 0;
      do {
        exitg1 = 0;
        if (xoffset + 1 < 7) {
          if (controls->para[xoffset] != cv1[xoffset]) {
            exitg1 = 1;
          } else {
            xoffset++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);

      if (b_bool) {
        xoffset = 0;
      } else {
        xoffset = 0;
        do {
          exitg1 = 0;
          if (xoffset + 1 < 7) {
            if (controls->para[xoffset] != cv2[xoffset]) {
              exitg1 = 1;
            } else {
              xoffset++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);

        if (b_bool) {
          xoffset = 1;
        } else {
          xoffset = -1;
        }
      }

      switch (xoffset) {
       case 0:
        {
          boolean_T sldProfile_dirtyOnGpu;
          boolean_T x_dirtyOnGpu;
          boolean_T Lays_dirtyOnGpu;
          boolean_T a_dirtyOnGpu;
          boolean_T b_dirtyOnGpu;
          boolean_T r_dirtyOnGpu;
          boolean_T r1_dirtyOnGpu;
          boolean_T b_a_dirtyOnGpu;
          boolean_T b_b_dirtyOnGpu;
          boolean_T r8_dirtyOnGpu;
          boolean_T r9_dirtyOnGpu;
          boolean_T c_a_dirtyOnGpu;
          boolean_T c_b_dirtyOnGpu;
          boolean_T r4_dirtyOnGpu;
          boolean_T r5_dirtyOnGpu;
          boolean_T SLD_dirtyOnGpu;
          boolean_T layers_dirtyOnGpu;
          boolean_T normalizedData_dirtyOnGpu;
          boolean_T firstStep_dirtyOnGpu;
          boolean_T secondStep_dirtyOnGpu;
          boolean_T longStep_dirtyOnGpu;
          boolean_T z1_dirtyOnGpu;
          boolean_T b_z1_dirtyOnGpu;
          boolean_T firstStepSquared_dirtyOnGpu;
          boolean_T c_z1_dirtyOnGpu;
          boolean_T d_z1_dirtyOnGpu;
          boolean_T secondStepSquared_dirtyOnGpu;
          boolean_T e_z1_dirtyOnGpu;
          boolean_T f_z1_dirtyOnGpu;
          boolean_T b_x_dirtyOnGpu;
          boolean_T c_x_dirtyOnGpu;
          boolean_T trianglesToRefine_dirtyOnGpu;
          boolean_T r32_dirtyOnGpu;
          boolean_T segmentsToSplit_dirtyOnGpu;
          boolean_T newDataPoints_dirtyOnGpu;
          boolean_T r21_dirtyOnGpu;
          boolean_T b_dataPoints_dirtyOnGpu;
          boolean_T idx_dirtyOnGpu;
          boolean_T ycol_dirtyOnGpu;
          boolean_T firstSection_dirtyOnGpu;
          boolean_T lastSection_dirtyOnGpu;
          boolean_T simXdata_dirtyOnGpu;
          boolean_T Simul_dirtyOnGpu;
          boolean_T dummydata_dirtyOnGpu;
          boolean_T reflect_dirtyOnGpu;
          boolean_T z_dirtyOnGpu;
          boolean_T g_z1_dirtyOnGpu;

          //  Allocate the memory for the output arrays before the main loop
          xoffset = static_cast<int32_T>(problemDef->numberOfContrasts);

          //  end memory allocation.
          //  First we need to allocate the absolute values of the input
          //  parameters to all the layers in the layers list. This only needs
          //  to be done once, and so is done outside the contrasts loop
          // This function takes the list of all layers (in terms of parameter
          // numbers) in layersDetails, and loops through putting in the correct 
          // parameter value from the parameter array in each layer.
          l_reflectivity_calculation_gpu_<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (*gpu_thisOutLayer);
          CUDACHECK(cudaGetLastError());
          CUDACHECK(cudaMemcpy(gpu_problemDef_cells, (void *)problemDef_cells,
                               9424UL, cudaMemcpyHostToDevice));
          m_reflectivity_calculation_gpu_<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (*problemDef, gpu_problemDef_cells, *gpu_thisOutLayer);
          CUDACHECK(cudaGetLastError());
          n_reflectivity_calculation_gpu_<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (gpu_problemDef_cells, *gpu_thisOutLayer);
          CUDACHECK(cudaGetLastError());
          o_reflectivity_calculation_gpu_<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (*gpu_thisOutLayer, *gpu_outParameterisedLayers);
          CUDACHECK(cudaGetLastError());
          p_reflectivity_calculation_gpu_<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (*problemDef, gpu_problemDef_cells, *gpu_thisOutLayer);
          CUDACHECK(cudaGetLastError());
          q_reflectivity_calculation_gpu_<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (gpu_problemDef_cells, *gpu_thisOutLayer);
          CUDACHECK(cudaGetLastError());
          r_reflectivity_calculation_gpu_<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (*gpu_thisOutLayer, *gpu_outParameterisedLayers);
          CUDACHECK(cudaGetLastError());
          s_reflectivity_calculation_gpu_<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (*problemDef, gpu_problemDef_cells, *gpu_thisOutLayer);
          CUDACHECK(cudaGetLastError());
          t_reflectivity_calculation_gpu_<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (gpu_problemDef_cells, *gpu_thisOutLayer);
          CUDACHECK(cudaGetLastError());
          u_reflectivity_calculation_gpu_<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (*gpu_thisOutLayer, *gpu_outParameterisedLayers);
          CUDACHECK(cudaGetLastError());
          v_reflectivity_calculation_gpu_<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (*problemDef, gpu_problemDef_cells, *gpu_thisOutLayer);
          CUDACHECK(cudaGetLastError());
          w_reflectivity_calculation_gpu_<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (gpu_problemDef_cells, *gpu_thisOutLayer);
          CUDACHECK(cudaGetLastError());
          x_reflectivity_calculation_gpu_<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (*gpu_thisOutLayer, *gpu_outParameterisedLayers);
          CUDACHECK(cudaGetLastError());

          //  Loop over all the contrasts
          i = static_cast<int32_T>(problemDef->numberOfContrasts);
          kEnd = outSsubs->size[0];
          outSsubs->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
          emxEnsureCapacity_real_T(outSsubs, kEnd);
          kEnd = b_sldProfiles->size[0];
          b_sldProfiles->size[0] = static_cast<int32_T>
            (problemDef->numberOfContrasts);
          emxEnsureCapacity_cell_wrap_17(b_sldProfiles, kEnd);
          kEnd = b_reflectivity->size[0];
          b_reflectivity->size[0] = xoffset;
          emxEnsureCapacity_cell_wrap_11(b_reflectivity, kEnd);
          kEnd = b_Simulation->size[0];
          b_Simulation->size[0] = static_cast<int32_T>
            (problemDef->numberOfContrasts);
          emxEnsureCapacity_cell_wrap_11(b_Simulation, kEnd);
          kEnd = b_shifted_data->size[0];
          b_shifted_data->size[0] = static_cast<int32_T>
            (problemDef->numberOfContrasts);
          emxEnsureCapacity_cell_wrap_12(b_shifted_data, kEnd);
          kEnd = b_layerSlds->size[0];
          b_layerSlds->size[0] = static_cast<int32_T>
            (problemDef->numberOfContrasts);
          emxEnsureCapacity_cell_wrap_12(b_layerSlds, kEnd);
          if (chis_dirtyOnGpu) {
            gpuEmxMemcpyGpuToCpu_real_T(chis, &inter_chis);
            chis_dirtyOnGpu = false;
          }

          kEnd = chis->size[0];
          chis->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
          emxEnsureCapacity_real_T(chis, kEnd);
          if (backgs_dirtyOnGpu) {
            gpuEmxMemcpyGpuToCpu_real_T(backgs, &inter_backgs);
            backgs_dirtyOnGpu = false;
          }

          kEnd = backgs->size[0];
          backgs->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
          emxEnsureCapacity_real_T(backgs, kEnd);
          if (qshifts_dirtyOnGpu) {
            gpuEmxMemcpyGpuToCpu_real_T(qshifts, &inter_qshifts);
            qshifts_dirtyOnGpu = false;
          }

          kEnd = qshifts->size[0];
          qshifts->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
          emxEnsureCapacity_real_T(qshifts, kEnd);
          if (sfs_dirtyOnGpu) {
            gpuEmxMemcpyGpuToCpu_real_T(sfs, &inter_sfs);
            sfs_dirtyOnGpu = false;
          }

          kEnd = sfs->size[0];
          sfs->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
          emxEnsureCapacity_real_T(sfs, kEnd);
          if (nbas_dirtyOnGpu) {
            gpuEmxMemcpyGpuToCpu_real_T(nbas, &inter_nbas);
            nbas_dirtyOnGpu = false;
          }

          kEnd = nbas->size[0];
          nbas->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
          emxEnsureCapacity_real_T(nbas, kEnd);
          if (nbss_dirtyOnGpu) {
            gpuEmxMemcpyGpuToCpu_real_T(nbss, &inter_nbss);
            nbss_dirtyOnGpu = false;
          }

          kEnd = nbss->size[0];
          nbss->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
          emxEnsureCapacity_real_T(nbss, kEnd);
          if (resols_dirtyOnGpu) {
            gpuEmxMemcpyGpuToCpu_real_T(resols, &inter_resols);
            resols_dirtyOnGpu = false;
          }

          kEnd = resols->size[0];
          resols->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
          emxEnsureCapacity_real_T(resols, kEnd);
          if (allRoughs_dirtyOnGpu) {
            gpuEmxMemcpyGpuToCpu_real_T(allRoughs, &inter_allRoughs);
            allRoughs_dirtyOnGpu = false;
          }

          kEnd = allRoughs->size[0];
          allRoughs->size[0] = static_cast<int32_T>
            (problemDef->numberOfContrasts);
          emxEnsureCapacity_real_T(allRoughs, kEnd);
          emxInit_real_T(&sldProfile, 2, true);
          sldProfile_dirtyOnGpu = false;
          emxInit_real_T(&reflect, 2, true);
          reflect_dirtyOnGpu = false;
          emxInit_real_T(&Simul, 2, true);
          Simul_dirtyOnGpu = false;
          emxInit_real_T(&layers, 2, true);
          layers_dirtyOnGpu = false;
          emxInit_real_T(&firstSection, 2, true);
          firstSection_dirtyOnGpu = false;
          emxInit_real_T(&lastSection, 2, true);
          lastSection_dirtyOnGpu = false;
          emxInit_real_T(&simXdata, 1, true);
          simXdata_dirtyOnGpu = false;
          emxInit_real_T(&simRef, 1, true);
          emxInit_real_T(&x, 2, true);
          x_dirtyOnGpu = false;
          emxInit_real_T(&Lays, 2, true);
          Lays_dirtyOnGpu = false;
          emxInit_real_T(&SLD, 1, true);
          SLD_dirtyOnGpu = false;
          emxInit_real_T(&dataPoints, 2, true);
          emxInit_boolean_T(&trianglesToRefine, 1, true);
          trianglesToRefine_dirtyOnGpu = false;
          emxInit_boolean_T(&segmentsToSplit, 1, true);
          segmentsToSplit_dirtyOnGpu = false;
          emxInit_real_T(&dummydata, 1, true);
          dummydata_dirtyOnGpu = false;
          emxInit_real_T(&z, 1, true);
          z_dirtyOnGpu = false;
          emxInit_boolean_T(&c_x, 1, true);
          emxInit_int8_T(&ii, 1, true);
          emxInit_real_T(&a, 2, true);
          a_dirtyOnGpu = false;
          emxInit_real_T(&b, 2, true);
          b_dirtyOnGpu = false;
          emxInit_real_T(&r, 2, true);
          r_dirtyOnGpu = false;
          emxInit_real_T(&r1, 2, true);
          r1_dirtyOnGpu = false;
          emxInit_real_T(&c_a, 2, true);
          c_a_dirtyOnGpu = false;
          emxInit_real_T(&c_b, 2, true);
          c_b_dirtyOnGpu = false;
          emxInit_real_T(&r4, 2, true);
          r4_dirtyOnGpu = false;
          emxInit_real_T(&r5, 2, true);
          r5_dirtyOnGpu = false;
          emxInit_real_T(&e_a, 2, true);
          b_a_dirtyOnGpu = false;
          emxInit_real_T(&e_b, 2, true);
          b_b_dirtyOnGpu = false;
          emxInit_real_T(&r8, 2, true);
          r8_dirtyOnGpu = false;
          emxInit_real_T(&r9, 2, true);
          r9_dirtyOnGpu = false;
          emxInit_real_T(&r11, 1, true);
          emxInit_real_T(&normalizedData, 2, true);
          normalizedData_dirtyOnGpu = false;
          emxInit_real_T(&firstStepSquared, 1, true);
          firstStepSquared_dirtyOnGpu = false;
          emxInit_real_T(&secondStepSquared, 1, true);
          secondStepSquared_dirtyOnGpu = false;
          emxInit_real_T(&firstStep, 2, true);
          firstStep_dirtyOnGpu = false;
          emxInit_real_T(&secondStep, 2, true);
          secondStep_dirtyOnGpu = false;
          emxInit_real_T(&longStep, 2, true);
          longStep_dirtyOnGpu = false;
          emxInit_real_T(&r14, 2, true);
          emxInit_real_T(&newDataPoints, 2, true);
          newDataPoints_dirtyOnGpu = false;
          emxInit_real_T(&r16, 1, true);
          emxInit_boolean_T(&r17, 1, true);
          emxInit_boolean_T(&r19, 1, true);
          emxInit_boolean_T(&r21, 1, true);
          r21_dirtyOnGpu = false;
          emxInit_boolean_T(&r23, 1, true);
          emxInit_int32_T(&r25, 1, true);
          emxInit_int32_T(&r27, 1, true);
          emxInit_real_T(&z1, 1, true);
          g_z1_dirtyOnGpu = false;
          emxInit_real_T(&g_b, 2, true);
          emxInit_real_T(&e_x, 1, true);
          b_x_dirtyOnGpu = false;
          emxInit_creal_T(&f_x, 1, true);
          c_x_dirtyOnGpu = false;
          emxInit_real_T(&r30, 1, true);
          emxInit_int32_T(&idx, 1, true);
          idx_dirtyOnGpu = false;
          emxInit_boolean_T(&i_x, 1, true);
          emxInit_int32_T(&c_ii, 1, true);
          emxInit_boolean_T(&k_x, 1, true);
          emxInit_int32_T(&e_ii, 1, true);
          emxInit_boolean_T(&m_x, 1, true);
          emxInit_int32_T(&g_ii, 1, true);
          emxInit_real_T(&ycol, 1, true);
          ycol_dirtyOnGpu = false;
          emxInit_real_T(&c_z1, 1, true);
          z1_dirtyOnGpu = false;
          emxInit_real_T(&d_z1, 1, true);
          b_z1_dirtyOnGpu = false;
          emxInit_real_T(&f_z1, 1, true);
          c_z1_dirtyOnGpu = false;
          emxInit_real_T(&h_z1, 1, true);
          d_z1_dirtyOnGpu = false;
          emxInit_real_T(&j_z1, 1, true);
          e_z1_dirtyOnGpu = false;
          emxInit_real_T(&l_z1, 1, true);
          f_z1_dirtyOnGpu = false;
          emxInit_boolean_T(&o_x, 1, true);
          emxInit_int32_T(&i_ii, 1, true);
          emxInit_boolean_T(&q_x, 1, true);
          emxInit_int32_T(&k_ii, 1, true);
          emxInit_boolean_T(&s_x, 1, true);
          emxInit_int32_T(&m_ii, 1, true);
          emxInit_int32_T(&iwork, 1, true);
          emxInit_boolean_T(&c_trianglesToRefine, 1, true);
          emxInit_boolean_T(&r32, 1, true);
          r32_dirtyOnGpu = false;
          emxInit_real_T(&c_dataPoints, 2, true);
          b_dataPoints_dirtyOnGpu = false;
          for (b_i = 0; b_i < i; b_i++) {
            real_T s_sub;
            real_T reps;
            int32_T k;
            real_T nextLayRough;
            real_T bFactor;
            int32_T i2;
            real_T g_a;
            real_T l;
            real_T thisBoxCentre;
            real_T pair_im;
            int32_T c_i;
            real_T snair;
            real_T snsub;
            real_T b_r;
            boolean_T layerThicks_dirtyOnGpu;
            boolean_T sldProfile_dirtyOnCpu;
            boolean_T x_dirtyOnCpu;
            boolean_T Lays_dirtyOnCpu;
            boolean_T b_dirtyOnCpu;
            boolean_T r1_dirtyOnCpu;
            boolean_T r8_dirtyOnCpu;
            boolean_T xoffset_dirtyOnCpu;
            boolean_T exitg2;

            //  Extract the relevant parameter values for this contrast
            //  from the input arrays.
            //  First need to decide which values of the backrounds, scalefactors 
            //  data shifts and bulk contrasts are associated with this contrast 
            // Distributes the background and shift values among the different contrasts. 
            //
            // [backgs,qshifts,sfs,nbas,nbss,resols] = backSort(nc,cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,shifts,sf,nba,nbs,res) 
            //  Inputs:
            //        nc = number of contrasts (double)
            //        cBacks = Which backround value is associated with each contrast? 
            //        cShifts = Which qz_shift value is associated with each contrast? 
            //        cScales = Which scalefactor value is associated with each contrast? 
            //        cNba = Which NBa value is associated with each contrast?
            //        cNbs = Which Nbs value is associated with each contrast?
            //        cRes = Which resolution value is associated with each contrast? 
            //        backs = List of all background values.
            //        shifts = List of all qz-shift values
            //        sf = List of all scalefactor values
            //        nba = List of all nba values
            //        nbs = List of all nbs values
            //        res = List of all resolution values
            //
            //  Outputs:
            //        backgs = list of actual background values for each contrast 
            //        qshifts = list of actual shift values for each contrast       
            //        sfs = list of actual shift values for each contrast
            //        nbas = list of actual shift values for each contrast
            //        nbss = list of actual shift values for each contrast
            //        nbss = list of actual shift values for each contrast
            //  backgs = 0;%zeros(1,nc);
            //  qshifts = 0;%zeros(1,nc);
            //  sfs = 0;%zeros(1,nc);
            //  nbas = 0;%zeros(1,nc);
            //  nbss = 0;%zeros(1,nc);
            //  resols = 0;%zeros(1,nc);
            // for i = 1:nc
            // thisBack = cBacks(i);
            // thisShift = cShifts(i);
            // thisScale = cScales(i);
            // thisNbair = cNbas(i);
            // thisNbsub = cNbss(i);
            // thisResol = cRes(i);
            // end
            //  Also need to determine which layers from the overall layers list 
            //  are required for this contrast, and put them in the correct order  
            //  according to geometry
            //  Take the layers list for a contrast and build an
            //  array of real valued layers
            y_reflectivity_calculation_gpu_<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
              (*gpu_outParameterisedLayers, gpu_problemDef_cells, b_i,
               *gpu_thisContrastLayers);
            CUDACHECK(cudaGetLastError());

            //  For the other parameters, we extract the correct ones from the input 
            //  arrays
            //  Substrate roughness is always first parameter for standard layers 
            ab_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(160U, 1U,
              1U)>>>(gpu_problemDef_cells, b_i, *gpu_thisData);
            CUDACHECK(cudaGetLastError());

            //  Now call the core standardTF_stanlay reflectivity calculation
            //  In this case we are single cored, so we do not parallelise over
            //  points
            //  Call the calculation
            layerThicks = calcSld;
            layerThicks_dirtyOnGpu = false;

            //  function [sldProfile,reflect,Simul,shifted_dat,layerSld,chiSquared,ssubs] = ... 
            //      standardTF_stanlay_core(contrastLayers, rough, ...
            //      geometry, nba, nbs, resample, calcSld, sf, qshift,...
            //      dataPresent, data, dataLimits, simLimits, repeatLayers,...
            //      background,resol,backsType,params,paralellPoints)
            //
            //    This is the main reflectivity calculation for Layers models in the  
            //    standard target function. The function first arranges the
            //    roughness' in the correct order according
            //    to geometry. Then, if required it calculates the SLD profile and if 
            //    requested resamples this into a number of zero-roughness layers 
            //    (roughness resampling). It the applies any scalefactors and qz shifts 
            //    the data requires. This is done before calculating the reflectivity to 
            //    ensure that the reflectivity is calculated over the same range in qz as 
            //    the shifted datapoints. The main reflectivity calculation is then 
            //    called, including the resolution function. The calculation outputs two 
            //    profiles - 'reflect' which is the same range as the points, and 
            //    'Simulation' which can be a different range to allow extrapolation. 
            //    The background correction is the applied, and finally chi-squared is  
            //    calculated.
            //
            //  Inputs:
            //    contrastLayers  :
            //    rough           :
            //    geometry        :
            //    nba             :
            //    nbs             :
            //    resample        :
            //    calcSld         :
            //    sf              :
            //    qshift          :
            //    dataPresent     :
            //    data            :
            //    dataLimits      :
            //    simLimits       :
            //    repeatLayers    :
            //    background      :
            //    resol           :
            //    backsType       :
            //    params          :
            //    paralellPoints  :
            //
            //  Outputs:
            //
            //
            //
            //  ------------------------------------------------------------------------ 
            //
            //        (c) Arwel Hughes  -   12/1/21
            //
            //        Last Modified: 12/1/21 by Arwel Hughes.
            //
            //  ------------------------------------------------------------------------ 
            //  Bulid up the layers matrix for this contrast
            // Arrange layers according to geometry and apply any coverage correction. 
            //
            // [outLayers, outSsubs] = groupLayers_Mod(allLayers,allRoughs,numberOfContrasts,geometry,nbairs,nbsubs) 
            //  Inputs:
            //      allLayers = cell array, one for each contrast. Each cell is the  
            //                  list of layer values for each contrast.
            //                  e.g. allLayers{1} = [d1, rho1, r1, %hyd, hyd_which 
            //                                       d2, rho2, r2, %hyd2, hyd_which_2.. 
            //                                       etc]
            //      allRoughs = Double of substrate roughness for each contrast. 
            //      numberOfContrasts = double.
            //      geometry =  'Air / Liquid (or solid)' or 'Solid / Liquid'
            //      nbairs = vector of nbair values.
            //      nbsubs = vector of nbsub values.
            //
            //      The paratt calculation procedds through the
            //      z,rho,rough stack, and the parameter 'ssub' in
            //      callParatt is the final roughness encountered.
            //      For air liquid 'ssub' is therefore the substrate roughness.
            //      For solid liquid, the substrate roughness is the first roughness 
            //      encountered, and 'ssub' is then the roughness of the outermost layer. 
            //      The rougnesses need to be arranged accordingly.
            //
            //
            //  Outputs:
            //      outLayers = cell array of layers param values for each contrast. 
            //                  e.g. outLayers{1} = [d1 rho1 r1;
            //                                       d2 rho2 r2
            //                                       ... etc   ]
            //      outSsubs = vector of substrate roughness values.
            //
            // outLayers = cell(1,numberOfContrasts);
            // outSsubs = zeros(1,numberOfContrasts);
            // for i = 1:numberOfContrasts
            s_sub = problemDef->params[0];
            layers_size[0] = 2;
            layers_size[1] = 5;
            bb_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
              (*gpu_layers_data);
            CUDACHECK(cudaGetLastError());
            b_bool = false;
            xoffset = 0;
            xoffset_dirtyOnCpu = true;
            do {
              exitg1 = 0;
              if (xoffset + 1 < 14) {
                if (problemDef->geometry[xoffset] != cv3[xoffset]) {
                  exitg1 = 1;
                } else {
                  xoffset++;
                }
              } else {
                b_bool = true;
                exitg1 = 1;
              }
            } while (exitg1 == 0);

            if (b_bool) {
              vlen = 0;
            } else {
              vlen = -1;
            }

            if (vlen == 0) {
              layers_size[0] = 2;
              layers_size[1] = 5;
              cb_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(*gpu_thisContrastLayers, *gpu_layers_data);
              CUDACHECK(cudaGetLastError());

              // s_sub = rsub;
            }

            // Deal with the %coverage if present
            db_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
              (nba, *problemDef, b_i, *gpu_thisContrastLayers, *gpu_layers_data);
            CUDACHECK(cudaGetLastError());

            //      problem.layers{i} = layers;
            //      problem.ssubs(i) = s_sub;
            // end
            //  Make the SLD profiles.
            //  If resampling is needed, then enforce the calcSLD flag, so as to catch 
            //  the error af trying to resample a non-existent profile.
            if ((problemDef->resample[b_i] == 1.0) && (calcSld == 0.0)) {
              layerThicks = 1.0;
            }

            //  If cal SLD flag is set, then calculate the SLD profile
            if (layerThicks == 1.0) {
              if (problemDef_cells->f1[b_i].f1[0] == 0.0) {
                reps = 1.0;
              } else {
                reps = problemDef_cells->f1[b_i].f1[1];
              }

              CUDACHECK(cudaMemcpy(&layers_data[0], gpu_layers_data, 10U *
                                   sizeof(real_T), cudaMemcpyDeviceToHost));
              layerThicks = layers_data[0];
              CUDACHECK(cudaMemcpy(gpu_layers_size, &layers_size[0], 8UL,
                                   cudaMemcpyHostToDevice));
              CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                   cudaMemcpyHostToDevice));
              fb_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(*gpu_layers_data, gpu_layerThicks);
              CUDACHECK(cudaGetLastError());
              CUDACHECK(cudaMemcpy(&layerThicks, gpu_layerThicks, 8UL,
                                   cudaMemcpyDeviceToHost));
              layerThicks = layerThicks * reps + 150.0;
              if (rtIsNaN(layerThicks)) {
                kEnd = x->size[0] * x->size[1];
                x->size[0] = 1;
                x->size[1] = 1;
                emxEnsureCapacity_real_T(x, kEnd);
                x->data[0] = rtNaN;
                x_dirtyOnCpu = true;
              } else if (layerThicks < 0.0) {
                x->size[0] = 1;
                x->size[1] = 0;
                x_dirtyOnCpu = true;
              } else if (rtIsInf(layerThicks) && (0.0 == layerThicks)) {
                kEnd = x->size[0] * x->size[1];
                x->size[0] = 1;
                x->size[1] = 1;
                emxEnsureCapacity_real_T(x, kEnd);
                x->data[0] = rtNaN;
                x_dirtyOnCpu = true;
              } else {
                kEnd = x->size[0] * x->size[1];
                x->size[0] = 1;
                x->size[1] = static_cast<int32_T>(floor(layerThicks)) + 1;
                emxEnsureCapacity_real_T(x, kEnd);
                x_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>(
                  static_cast<int32_T>(layerThicks) + 1L), &i_grid, &i_block,
                  1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                       cudaMemcpyHostToDevice));
                  gpuEmxMemcpyCpuToGpu_real_T(x, &inter_x, gpu_x);
                  gb_reflectivity_calculation_gpu<<<i_grid, i_block>>>
                    (gpu_layerThicks, gpu_x);
                  CUDACHECK(cudaGetLastError());
                  x_dirtyOnCpu = false;
                  x_dirtyOnGpu = true;
                }
              }

              kEnd = Lays->size[0] * Lays->size[1];
              if (x_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(x, &inter_x);
                x_dirtyOnGpu = false;
              }

              Lays->size[0] = x->size[1];
              Lays->size[1] = static_cast<int32_T>(2.0 * reps + 2.0);
              emxEnsureCapacity_real_T(Lays, kEnd);
              Lays_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((x->size[1] * static_cast<int32_T>(2.0 * reps + 2.0) - 1) + 1L),
                &j_grid, &j_block, 1024U, 65535U);
              if (validLaunchParams) {
                if (x_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(x, &inter_x, gpu_x);
                  x_dirtyOnCpu = false;
                }

                gpuEmxMemcpyCpuToGpu_real_T(Lays, &inter_Lays, gpu_Lays);
                hb_reflectivity_calculation_gpu<<<j_grid, j_block>>>(reps, gpu_x,
                  gpu_Lays);
                CUDACHECK(cudaGetLastError());
                Lays_dirtyOnCpu = false;
                Lays_dirtyOnGpu = true;
              }

              nextLayRough = layers_data[4];

              //  Produces a step function convoluted with differnt error functions 
              //  on each side.
              //  Convstep (x,xw,xcen,s1,s2,h)
              //        x = vector of x values
              //       xw = Width of step function
              //     xcen = Centre point of step function
              //        s1 = Roughness parameter of left side
              //        s2 = Roughness parameter of right side
              //        h = Height of step function.
              //  if length(xw) > 1
              //      ME = MException('VerifyOutput:OutOfBounds', ...
              //               'xw must be single value');
              //      throw(ME);
              //  end
              //
              //  if length(xcen) > 1
              //      ME = MException('VerifyOutput:OutOfBounds', ...
              //               'xcen must be single value');
              //      throw(ME);
              //  end
              //
              //  if length(s1) > 1
              //      ME = MException('VerifyOutput:OutOfBounds', ...
              //               's1 must be single value');
              //      throw(ME);
              //  end
              //
              //  if length(s2) > 1
              //      ME = MException('VerifyOutput:OutOfBounds', ...
              //               's2 must be single value');
              //      throw(ME);
              //  end
              layerThicks = 1.4142135623730951 * layers_data[4];
              kEnd = a->size[0] * a->size[1];
              a->size[0] = 1;
              a->size[1] = x->size[1];
              emxEnsureCapacity_real_T(a, kEnd);
              problemDef_cells_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((x->size[0] * x->size[1] - 1) + 1L), &k_grid, &k_block, 1024U,
                65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                     cudaMemcpyHostToDevice));
                if (x_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(x, &inter_x, gpu_x);
                  x_dirtyOnCpu = false;
                }

                gpuEmxMemcpyCpuToGpu_real_T(a, &inter_a, gpu_a);
                ib_reflectivity_calculation_gpu<<<k_grid, k_block>>>
                  (gpu_layerThicks, gpu_x, gpu_a);
                CUDACHECK(cudaGetLastError());
                problemDef_cells_dirtyOnCpu = false;
                a_dirtyOnGpu = true;
              }

              kEnd = b->size[0] * b->size[1];
              b->size[0] = 1;
              b->size[1] = x->size[1];
              emxEnsureCapacity_real_T(b, kEnd);
              b_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((x->size[0] * x->size[1] - 1) + 1L), &l_grid, &l_block, 1024U,
                65535U);
              if (validLaunchParams) {
                if (x_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(x, &inter_x, gpu_x);
                  x_dirtyOnCpu = false;
                }

                gpuEmxMemcpyCpuToGpu_real_T(b, &inter_b, gpu_b);
                jb_reflectivity_calculation_gpu<<<l_grid, l_block>>>
                  (1.4142135623730951 * layers_data[4], gpu_x, gpu_b);
                CUDACHECK(cudaGetLastError());
                b_dirtyOnCpu = false;
                b_dirtyOnGpu = true;
              }

              if (a_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(a, &inter_a);
                a_dirtyOnGpu = false;
              }

              nx = a->size[1];
              if (r_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(r, &inter_r);
                r_dirtyOnGpu = false;
              }

              kEnd = r->size[0] * r->size[1];
              r->size[0] = 1;
              r->size[1] = a->size[1];
              emxEnsureCapacity_real_T(r, kEnd);
              b_bool = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((nx
                - 1) + 1L), &m_grid, &m_block, 1024U, 65535U);
              if (validLaunchParams) {
                if (problemDef_cells_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(a, &inter_a, gpu_a);
                }

                CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                gpuEmxMemcpyCpuToGpu_real_T(r, &inter_r, gpu_r);
                kb_reflectivity_calculation_gpu<<<m_grid, m_block>>>(gpu_a,
                  gpu_nx, gpu_r);
                CUDACHECK(cudaGetLastError());
                b_bool = false;
                r_dirtyOnGpu = true;
              }

              if (b_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(b, &inter_b);
                b_dirtyOnGpu = false;
              }

              nx = b->size[1];
              if (r1_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(r1, &inter_r1);
                r1_dirtyOnGpu = false;
              }

              kEnd = r1->size[0] * r1->size[1];
              r1->size[0] = 1;
              r1->size[1] = b->size[1];
              emxEnsureCapacity_real_T(r1, kEnd);
              r1_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((nx
                - 1) + 1L), &n_grid, &n_block, 1024U, 65535U);
              if (validLaunchParams) {
                if (b_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(b, &inter_b, gpu_b);
                }

                CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                gpuEmxMemcpyCpuToGpu_real_T(r1, &inter_r1, gpu_r1);
                lb_reflectivity_calculation_gpu<<<n_grid, n_block>>>(gpu_b,
                  gpu_nx, gpu_r1);
                CUDACHECK(cudaGetLastError());
                r1_dirtyOnCpu = false;
                r1_dirtyOnGpu = true;
              }

              layerThicks = 50.0;
              kEnd = static_cast<int32_T>(reps);
              for (n = 0; n < kEnd; n++) {
                for (c_i = 0; c_i < 2; c_i++) {
                  if (c_i + 1 < 2) {
                    nextLayRough = layers_data[5];

                    //              elseif (i == numberOfLayers) && (n < nrepeats) 
                    //                  nextLayRough = layers(1,3);
                  } else {
                    nextLayRough = s_sub;
                  }

                  thisBoxCentre = layerThicks + layers_data[c_i] / 2.0;

                  //  Produces a step function convoluted with differnt error functions 
                  //  on each side.
                  //  Convstep (x,xw,xcen,s1,s2,h)
                  //        x = vector of x values
                  //       xw = Width of step function
                  //     xcen = Centre point of step function
                  //        s1 = Roughness parameter of left side
                  //        s2 = Roughness parameter of right side
                  //        h = Height of step function.
                  //  if length(xw) > 1
                  //      ME = MException('VerifyOutput:OutOfBounds', ...
                  //               'xw must be single value');
                  //      throw(ME);
                  //  end
                  //
                  //  if length(xcen) > 1
                  //      ME = MException('VerifyOutput:OutOfBounds', ...
                  //               'xcen must be single value');
                  //      throw(ME);
                  //  end
                  //
                  //  if length(s1) > 1
                  //      ME = MException('VerifyOutput:OutOfBounds', ...
                  //               's1 must be single value');
                  //      throw(ME);
                  //  end
                  //
                  //  if length(s2) > 1
                  //      ME = MException('VerifyOutput:OutOfBounds', ...
                  //               's2 must be single value');
                  //      throw(ME);
                  //  end
                  b_r = thisBoxCentre + layers_data[c_i] / 2.0;
                  l = thisBoxCentre - layers_data[c_i] / 2.0;
                  layerThicks = 1.4142135623730951 * layers_data[c_i + 4];
                  qEnd = e_a->size[0] * e_a->size[1];
                  e_a->size[0] = 1;
                  e_a->size[1] = x->size[1];
                  emxEnsureCapacity_real_T(e_a, qEnd);
                  problemDef_cells_dirtyOnCpu = true;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((x->size[0] * x->size[1] - 1) + 1L), &o_grid, &o_block,
                    1024U, 65535U);
                  if (validLaunchParams) {
                    CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                         cudaMemcpyHostToDevice));
                    if (x_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(x, &inter_x, gpu_x);
                      x_dirtyOnCpu = false;
                    }

                    gpuEmxMemcpyCpuToGpu_real_T(e_a, &b_inter_a, b_gpu_a);
                    mb_reflectivity_calculation_gpu<<<o_grid, o_block>>>
                      (gpu_layerThicks, l, gpu_x, b_gpu_a);
                    CUDACHECK(cudaGetLastError());
                    problemDef_cells_dirtyOnCpu = false;
                    b_a_dirtyOnGpu = true;
                  }

                  qEnd = e_b->size[0] * e_b->size[1];
                  e_b->size[0] = 1;
                  e_b->size[1] = x->size[1];
                  emxEnsureCapacity_real_T(e_b, qEnd);
                  b_dirtyOnCpu = true;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((x->size[0] * x->size[1] - 1) + 1L), &p_grid, &p_block,
                    1024U, 65535U);
                  if (validLaunchParams) {
                    if (x_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(x, &inter_x, gpu_x);
                      x_dirtyOnCpu = false;
                    }

                    gpuEmxMemcpyCpuToGpu_real_T(e_b, &b_inter_b, b_gpu_b);
                    nb_reflectivity_calculation_gpu<<<p_grid, p_block>>>
                      (1.4142135623730951 * nextLayRough, b_r, gpu_x, b_gpu_b);
                    CUDACHECK(cudaGetLastError());
                    b_dirtyOnCpu = false;
                    b_b_dirtyOnGpu = true;
                  }

                  if (b_a_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_real_T(e_a, &b_inter_a);
                    b_a_dirtyOnGpu = false;
                  }

                  nx = e_a->size[1];
                  if (r8_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_real_T(r8, &inter_r8);
                    r8_dirtyOnGpu = false;
                  }

                  qEnd = r8->size[0] * r8->size[1];
                  r8->size[0] = 1;
                  r8->size[1] = e_a->size[1];
                  emxEnsureCapacity_real_T(r8, qEnd);
                  r8_dirtyOnCpu = true;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((nx - 1) + 1L), &q_grid, &q_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL,
                                         cudaMemcpyHostToDevice));
                    if (problemDef_cells_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(e_a, &b_inter_a, b_gpu_a);
                    }

                    gpuEmxMemcpyCpuToGpu_real_T(r8, &inter_r8, gpu_r8);
                    ob_reflectivity_calculation_gpu<<<q_grid, q_block>>>(b_gpu_a,
                      gpu_nx, gpu_r8);
                    CUDACHECK(cudaGetLastError());
                    r8_dirtyOnCpu = false;
                    r8_dirtyOnGpu = true;
                  }

                  if (b_b_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_real_T(e_b, &b_inter_b);
                    b_b_dirtyOnGpu = false;
                  }

                  nx = e_b->size[1];
                  if (r9_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_real_T(r9, &inter_r9);
                    r9_dirtyOnGpu = false;
                  }

                  qEnd = r9->size[0] * r9->size[1];
                  r9->size[0] = 1;
                  r9->size[1] = e_b->size[1];
                  emxEnsureCapacity_real_T(r9, qEnd);
                  problemDef_cells_dirtyOnCpu = true;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((nx - 1) + 1L), &r_grid, &r_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL,
                                         cudaMemcpyHostToDevice));
                    if (b_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(e_b, &b_inter_b, b_gpu_b);
                    }

                    gpuEmxMemcpyCpuToGpu_real_T(r9, &inter_r9, gpu_r9);
                    pb_reflectivity_calculation_gpu<<<r_grid, r_block>>>(b_gpu_b,
                      gpu_nx, gpu_r9);
                    CUDACHECK(cudaGetLastError());
                    problemDef_cells_dirtyOnCpu = false;
                    r9_dirtyOnGpu = true;
                  }

                  layerThicks = layers_data[c_i + 2] / 2.0;
                  qEnd = c_i + (n << 1);
                  if (Lays_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(Lays, &inter_Lays, gpu_Lays);
                    Lays_dirtyOnCpu = false;
                  }

                  if (xoffset_dirtyOnCpu) {
                    CUDACHECK(cudaMemcpy(gpu_xoffset, &xoffset, 4UL,
                                         cudaMemcpyHostToDevice));
                    xoffset_dirtyOnCpu = false;
                  }

                  qb_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U,
                    1U, 1U)>>>(gpu_Lays, gpu_xoffset);
                  CUDACHECK(cudaGetLastError());
                  CUDACHECK(cudaMemcpy(&xoffset, gpu_xoffset, 4UL,
                                       cudaMemcpyDeviceToHost));
                  ii_size[0] = xoffset;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((ii_size[0] - 1) + 1L), &s_grid, &s_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                         cudaMemcpyHostToDevice));
                    if (r8_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(r8, &inter_r8, gpu_r8);
                    }

                    if (problemDef_cells_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(r9, &inter_r9, gpu_r9);
                    }

                    CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL,
                                         cudaMemcpyHostToDevice));
                    CUDACHECK(cudaMemcpy(gpu_ii_size, &ii_size[0], 4UL,
                                         cudaMemcpyHostToDevice));
                    rb_reflectivity_calculation_gpu<<<s_grid, s_block>>>(gpu_r9,
                      gpu_r8, gpu_layerThicks, gpu_qEnd, *gpu_ii_size, gpu_Lays);
                    CUDACHECK(cudaGetLastError());
                    Lays_dirtyOnGpu = true;
                  }

                  layerThicks = thisBoxCentre + layers_data[c_i] / 2.0;

                  // plot(x,Lays(:,i));
                }
              }

              // layers(end,3);
              layerThicks = (x->data[x->size[1] - 1] - layerThicks) * 2.0;
              kEnd = static_cast<int32_T>(2.0 * reps + 1.0);

              //  Produces a step function convoluted with differnt error functions 
              //  on each side.
              //  Convstep (x,xw,xcen,s1,s2,h)
              //        x = vector of x values
              //       xw = Width of step function
              //     xcen = Centre point of step function
              //        s1 = Roughness parameter of left side
              //        s2 = Roughness parameter of right side
              //        h = Height of step function.
              //  if length(xw) > 1
              //      ME = MException('VerifyOutput:OutOfBounds', ...
              //               'xw must be single value');
              //      throw(ME);
              //  end
              //
              //  if length(xcen) > 1
              //      ME = MException('VerifyOutput:OutOfBounds', ...
              //               'xcen must be single value');
              //      throw(ME);
              //  end
              //
              //  if length(s1) > 1
              //      ME = MException('VerifyOutput:OutOfBounds', ...
              //               's1 must be single value');
              //      throw(ME);
              //  end
              //
              //  if length(s2) > 1
              //      ME = MException('VerifyOutput:OutOfBounds', ...
              //               's2 must be single value');
              //      throw(ME);
              //  end
              b_r = x->data[x->size[1] - 1] + layerThicks / 2.0;
              l = x->data[x->size[1] - 1] - layerThicks / 2.0;
              layerThicks = 1.4142135623730951 * nextLayRough;
              qEnd = c_a->size[0] * c_a->size[1];
              c_a->size[0] = 1;
              c_a->size[1] = x->size[1];
              emxEnsureCapacity_real_T(c_a, qEnd);
              problemDef_cells_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((x->size[0] * x->size[1] - 1) + 1L), &t_grid, &t_block, 1024U,
                65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                     cudaMemcpyHostToDevice));
                if (x_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(x, &inter_x, gpu_x);
                  x_dirtyOnCpu = false;
                }

                gpuEmxMemcpyCpuToGpu_real_T(c_a, &c_inter_a, c_gpu_a);
                sb_reflectivity_calculation_gpu<<<t_grid, t_block>>>
                  (gpu_layerThicks, l, gpu_x, c_gpu_a);
                CUDACHECK(cudaGetLastError());
                problemDef_cells_dirtyOnCpu = false;
                c_a_dirtyOnGpu = true;
              }

              qEnd = c_b->size[0] * c_b->size[1];
              c_b->size[0] = 1;
              c_b->size[1] = x->size[1];
              emxEnsureCapacity_real_T(c_b, qEnd);
              b_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((x->size[0] * x->size[1] - 1) + 1L), &u_grid, &u_block, 1024U,
                65535U);
              if (validLaunchParams) {
                if (x_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(x, &inter_x, gpu_x);
                  x_dirtyOnCpu = false;
                }

                gpuEmxMemcpyCpuToGpu_real_T(c_b, &c_inter_b, c_gpu_b);
                tb_reflectivity_calculation_gpu<<<u_grid, u_block>>>
                  (1.4142135623730951 * problemDef->params[0], b_r, gpu_x,
                   c_gpu_b);
                CUDACHECK(cudaGetLastError());
                b_dirtyOnCpu = false;
                c_b_dirtyOnGpu = true;
              }

              if (c_a_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(c_a, &c_inter_a);
                c_a_dirtyOnGpu = false;
              }

              nx = c_a->size[1];
              if (r4_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(r4, &inter_r4);
                r4_dirtyOnGpu = false;
              }

              qEnd = r4->size[0] * r4->size[1];
              r4->size[0] = 1;
              r4->size[1] = c_a->size[1];
              emxEnsureCapacity_real_T(r4, qEnd);
              r8_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((nx
                - 1) + 1L), &v_grid, &v_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                if (problemDef_cells_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(c_a, &c_inter_a, c_gpu_a);
                }

                gpuEmxMemcpyCpuToGpu_real_T(r4, &inter_r4, gpu_r4);
                ub_reflectivity_calculation_gpu<<<v_grid, v_block>>>(c_gpu_a,
                  gpu_nx, gpu_r4);
                CUDACHECK(cudaGetLastError());
                r8_dirtyOnCpu = false;
                r4_dirtyOnGpu = true;
              }

              if (c_b_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(c_b, &c_inter_b);
                c_b_dirtyOnGpu = false;
              }

              nx = c_b->size[1];
              if (r5_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(r5, &inter_r5);
                r5_dirtyOnGpu = false;
              }

              qEnd = r5->size[0] * r5->size[1];
              r5->size[0] = 1;
              r5->size[1] = c_b->size[1];
              emxEnsureCapacity_real_T(r5, qEnd);
              problemDef_cells_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((nx
                - 1) + 1L), &w_grid, &w_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                if (b_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(c_b, &c_inter_b, c_gpu_b);
                }

                gpuEmxMemcpyCpuToGpu_real_T(r5, &inter_r5, gpu_r5);
                vb_reflectivity_calculation_gpu<<<w_grid, w_block>>>(c_gpu_b,
                  gpu_nx, gpu_r5);
                CUDACHECK(cudaGetLastError());
                problemDef_cells_dirtyOnCpu = false;
                r5_dirtyOnGpu = true;
              }

              layerThicks = problemDef->nbs[static_cast<int32_T>
                (problemDef->contrastNbss[b_i]) - 1] / 2.0;
              if (Lays_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(Lays, &inter_Lays, gpu_Lays);
              }

              CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL, cudaMemcpyHostToDevice));
              wb_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(gpu_Lays, gpu_qEnd);
              CUDACHECK(cudaGetLastError());
              CUDACHECK(cudaMemcpy(&qEnd, gpu_qEnd, 4UL, cudaMemcpyDeviceToHost));
              ii_size[0] = qEnd;
              qEnd = kEnd - 1;
              Lays_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((ii_size[0] - 1) + 1L), &x_grid, &x_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                     cudaMemcpyHostToDevice));
                CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL,
                                     cudaMemcpyHostToDevice));
                Lays_dirtyOnCpu = false;
                CUDACHECK(cudaMemcpy(gpu_ii_size, &ii_size[0], 4UL,
                                     cudaMemcpyHostToDevice));
                if (r8_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(r4, &inter_r4, gpu_r4);
                }

                if (problemDef_cells_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(r5, &inter_r5, gpu_r5);
                }

                xb_reflectivity_calculation_gpu<<<x_grid, x_block>>>(gpu_r5,
                  gpu_r4, gpu_layerThicks, gpu_qEnd, *gpu_ii_size, gpu_Lays);
                CUDACHECK(cudaGetLastError());
                Lays_dirtyOnGpu = true;
              }

              // plot(x,Lays(:,(numberOfLayers*nrepeats)+1))
              kEnd = static_cast<int32_T>(2.0 * reps + 2.0);
              if (Lays_dirtyOnCpu) {
                CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL,
                                     cudaMemcpyHostToDevice));
              }

              yb_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(gpu_Lays, gpu_qEnd);
              CUDACHECK(cudaGetLastError());
              CUDACHECK(cudaMemcpy(&qEnd, gpu_qEnd, 4UL, cudaMemcpyDeviceToHost));
              ii_size[0] = qEnd;
              qEnd = kEnd - 1;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((ii_size[0] - 1) + 1L), &y_grid, &y_block, 1024U, 65535U);
              if (validLaunchParams) {
                if (b_bool) {
                  gpuEmxMemcpyCpuToGpu_real_T(r, &inter_r, gpu_r);
                }

                if (r1_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(r1, &inter_r1, gpu_r1);
                }

                CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL,
                                     cudaMemcpyHostToDevice));
                CUDACHECK(cudaMemcpy(gpu_ii_size, &ii_size[0], 4UL,
                                     cudaMemcpyHostToDevice));
                ac_reflectivity_calculation_gpu<<<y_grid, y_block>>>(gpu_r1,
                  gpu_r, nba / 2.0, gpu_qEnd, *gpu_ii_size, gpu_Lays);
                CUDACHECK(cudaGetLastError());
                Lays_dirtyOnGpu = true;
              }

              // plot(x,Lays(:,(numberOfLayers*nrepeats)+2))
              if (Lays_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(Lays, &inter_Lays);
                Lays_dirtyOnGpu = false;
              }

              vlen = Lays->size[1];
              if ((Lays->size[0] == 0) || (Lays->size[1] == 0)) {
                if (sz_dirtyOnCpu) {
                  CUDACHECK(cudaMemcpy(gpu_sz, &sz[0], 8UL,
                                       cudaMemcpyHostToDevice));
                }

                dc_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                  1U)>>>(gpu_Lays, *gpu_sz);
                CUDACHECK(cudaGetLastError());
                kEnd = SLD->size[0];
                CUDACHECK(cudaMemcpy(&sz[0], gpu_sz, 8UL, cudaMemcpyDeviceToHost));
                SLD->size[0] = static_cast<int32_T>(sz[0]);
                emxEnsureCapacity_real_T(SLD, kEnd);
                r8_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((
                  static_cast<int32_T>(sz[0]) - 1) + 1L), &cb_grid, &cb_block,
                  1024U, 65535U);
                if (validLaunchParams) {
                  gpuEmxMemcpyCpuToGpu_real_T(SLD, &inter_SLD, gpu_SLD);
                  ec_reflectivity_calculation_gpu<<<cb_grid, cb_block>>>(*gpu_sz,
                    gpu_SLD);
                  CUDACHECK(cudaGetLastError());
                  r8_dirtyOnCpu = false;
                  SLD_dirtyOnGpu = true;
                }
              } else {
                vstride = Lays->size[0];
                kEnd = SLD->size[0];
                SLD->size[0] = Lays->size[0];
                emxEnsureCapacity_real_T(SLD, kEnd);
                r8_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((vstride - 1) + 1L), &ab_grid, &ab_block, 1024U, 65535U);
                if (validLaunchParams) {
                  gpuEmxMemcpyCpuToGpu_real_T(SLD, &inter_SLD, gpu_SLD);
                  bc_reflectivity_calculation_gpu<<<ab_grid, ab_block>>>
                    (gpu_Lays, vstride, gpu_SLD);
                  CUDACHECK(cudaGetLastError());
                  r8_dirtyOnCpu = false;
                  SLD_dirtyOnGpu = true;
                }

                for (k = 0; k <= vlen - 2; k++) {
                  xoffset = (k + 1) * vstride;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((vstride - 1) + 1L), &bb_grid, &bb_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    CUDACHECK(cudaMemcpy(gpu_xoffset, &xoffset, 4UL,
                                         cudaMemcpyHostToDevice));
                    if (r8_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(SLD, &inter_SLD, gpu_SLD);
                      r8_dirtyOnCpu = false;
                    }

                    cc_reflectivity_calculation_gpu<<<bb_grid, bb_block>>>
                      (gpu_xoffset, gpu_Lays, vstride, gpu_SLD);
                    CUDACHECK(cudaGetLastError());
                    SLD_dirtyOnGpu = true;
                  }
                }
              }

              // plot(x,SLD)
              xoffset = x->size[1];
              kEnd = sldProfile->size[0] * sldProfile->size[1];
              sldProfile->size[0] = xoffset;
              sldProfile->size[1] = 2;
              emxEnsureCapacity_real_T(sldProfile, kEnd);
              sldProfile_dirtyOnCpu = true;
              nx = xoffset - 1;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>(nx +
                1L), &db_grid, &db_block, 1024U, 65535U);
              if (validLaunchParams) {
                gpuEmxMemcpyCpuToGpu_real_T(sldProfile, &inter_sldProfile,
                  gpu_sldProfile);
                if (x_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(x, &inter_x, gpu_x);
                }

                CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                fc_reflectivity_calculation_gpu<<<db_grid, db_block>>>(gpu_x,
                  gpu_nx, gpu_sldProfile);
                CUDACHECK(cudaGetLastError());
                sldProfile_dirtyOnCpu = false;
                sldProfile_dirtyOnGpu = true;
              }

              if (SLD_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(SLD, &inter_SLD);
                SLD_dirtyOnGpu = false;
              }

              nx = SLD->size[0] - 1;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>(nx +
                1L), &eb_grid, &eb_block, 1024U, 65535U);
              if (validLaunchParams) {
                if (sldProfile_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(sldProfile, &inter_sldProfile,
                    gpu_sldProfile);
                  sldProfile_dirtyOnCpu = false;
                }

                CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                if (r8_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(SLD, &inter_SLD, gpu_SLD);
                }

                gc_reflectivity_calculation_gpu<<<eb_grid, eb_block>>>(gpu_SLD,
                  gpu_nx, gpu_sldProfile);
                CUDACHECK(cudaGetLastError());
                sldProfile_dirtyOnGpu = true;
              }
            } else {
              kEnd = sldProfile->size[0] * sldProfile->size[1];
              sldProfile->size[0] = 1;
              sldProfile->size[1] = 3;
              emxEnsureCapacity_real_T(sldProfile, kEnd);
              gpuEmxMemcpyCpuToGpu_real_T(sldProfile, &inter_sldProfile,
                gpu_sldProfile);
              eb_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(gpu_sldProfile);
              CUDACHECK(cudaGetLastError());
              sldProfile_dirtyOnCpu = false;
              sldProfile_dirtyOnGpu = true;
            }

            //  If required, then resample the SLD
            if (problemDef->resample[b_i] == 1.0) {
              boolean_T dataPoints_dirtyOnGpu;
              boolean_T dataBoxSize_dirtyOnCpu;

              //  Function handle for adaptive resampling
              //  f = @(x) sldFunc(x);
              //
              //  Keep points and minangle as constants for now
              //  will fix later
              if (sldProfile_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(sldProfile, &inter_sldProfile);
                sldProfile_dirtyOnGpu = false;
              }

              if (dataBoxSize_dirtyOnGpu) {
                CUDACHECK(cudaMemcpy(&dataBoxSize[0], gpu_dataBoxSize, 16UL,
                                     cudaMemcpyDeviceToHost));
                dataBoxSize_dirtyOnGpu = false;
              }

              dataBoxSize[0] = sldProfile->data[0];
              dataBoxSize[1] = sldProfile->data[sldProfile->size[0] - 1];

              //  adaptive: evaluates a matlab function on a given range
              //
              //  'adaptive.m' allows to sample a function using a reduced number of 
              //  points. It works iteratively adding new points where needed.
              //  It is especially useful for functions which are computationally intensive 
              //  (e.g. involve solving a differential equation).
              //
              //  Usage:
              //  XY = adaptive(func, [xstart, xend])
              //   evaluates 'func' in the range [xstart, xend]. Key-value arguments are 
              //   used to control the function evaluation. If the function 'func' returns 
              //   multiple output values, only the first one is used for the refinement 
              //   process, but all of them are calculated and returned as additional 
              //   columns in the output matrix. The output matrix XY contains the new 
              //   domain points in the first column and the output values in the other 
              //   columns.
              //  [x,yy] = adaptive(func, [xstart, xend])
              //    as before but separately returns the array with the domain points and 
              //    the array/matrix with the function output values.
              //  [x,yy] = adaptive(func, xarray, ...)
              //    as before but explicitly provide an initial array of domain points. 
              //
              //  Methods:
              //    'adaptive' provides three methods for refining the function evaluation: 
              //    1) add more points near the sharp corners, which are found by 
              //     considering the triangles formed by three successive points and 
              //     measuring the central angle.
              //    2) measure the area of the same triangles and add more points when the 
              //     area is bigger than a threshold.
              //    3) measure the length of the segments formed by pairs of successive 
              //     and split the segments which are longer than a threshold.
              //    If no methods is explicitly specified, the 'angle' method is used. 
              //
              //  Input parameters
              //   - func: input function (function handle)
              //   - initialDomain: initial domain points (1D array)
              //
              //  Optional key-value input parameters
              //   - 'nPoints': (default 20)
              //        initial number of domain points, only used if an initial domain 
              //        array is not excplitely provided.
              //   - 'maxRefinements': (default 10)
              //        Specifies the maximum number of refinement steps.
              //   - 'minAngle': (default 0.8*pi)
              //        Refine near the  points which forms, together with their left and right 
              //        neighbours, a triangle with central angle smaller than a given value. 
              //   - 'maxArea': (default 5e-4)
              //        Refine near the points which forms, together with their left and right 
              //        neighbours, a triangle with area larger than a threshold. The threshold 
              //        in normalized to the area enclosing th graph:
              //        threshold==maxArea*(max(x)-min(x))*(max(f(x))-min(f(x))) 
              //   - 'maxLength': (default Inf)
              //        Refine all the sements which are longer than a given threshold. The 
              //        threshold is relative to the input and output ranges. Specifically, 
              //        before applying the threshold, the data are normalized so that 
              //        max(x)-min(x)==1 and max(f(x))-min(f(x))==1.
              //   - 'minLength': (default 0)
              //        Exclude from the refinement process the segments which are shorter 
              //        than a given threshold. The threshold is relative to the input and 
              //        output ranges. Specifically, before applying the threshold, the 
              //        data are normalized so that max(x)-min(x)==1 and max(f(x))-min(f(x))==1. 
              //   - 'minSignal': (default 0.2)
              //        Exclude from the refinement process the points where the function is 
              //        below a threshold. The threshold is relative to the output range: In 
              //        this example threshold == 0.01*(max(f(x))-min(f(x))).
              //   - 'vectorizable': (default false)
              //        Specifies whether the input function accepts arrays as input 
              //        (e.g. f(x)==x.^2).
              //   - 'waitbar': (default false)
              //        Display a waitbar.
              //
              //  Output parameters
              //   - a NxM array where N is the number of domain points and M is the number 
              //     of output parameters of the input function.
              //
              //
              //  Examples:
              //
              //    % Refine a function near sharp corners. The option 'minAngle' is useful 
              //    % for having more points near the peaks of the function.
              //    f = @(x) exp(-x.^2/4).*sin(3*x);
              //    % for test-purpose also evaluate the function directly
              //    x2 = -10:0.01:10;
              //    y2 = f(x2);
              //    y = adaptive(f, [-5,5], 'minAngle',0.8*pi);
              //    figure(1); plot(x2,f(x2),'k--',y(:,1),y(:,2),'o-');
              //    legend('high sampling','adaptive')
              //    title('y = adaptive(f, [xstart, xend], ''minAngle'',0.8*pi)') 
              //    % as before but starting with an inital array of domain points 
              //    x = -5:5;
              //    y = adaptive(f, x, 'minAngle',0.8*pi);
              //    figure(2); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-'); 
              //    legend('initial sampling','high sampling','adaptive')
              //    title('y = adaptive(f, x, ''minAngle'',0.8*pi)')
              //
              //    % Refine a function near sharp corners, but do not split segments which 
              //    % are already shorter than 'minLength'.
              //    y = adaptive(f, x, 'minAngle',0.8*pi, 'minLength',0.05);
              //    figure(3); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-'); 
              //    legend('initial sampling','high sampling','adaptive')
              //    title('y = adaptive(f, x, ''minAngle'',0.8*pi, ''minLength'',0.05)'); 
              //
              //    % Refine a function until the areas of the triangles formed by 
              //    % triplets of successive points are smaller than 'maxArea'.
              //    y = adaptive(f, x, 'maxArea',1e-3);
              //    figure(4); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-'); 
              //    legend('initial sampling','high sampling','adaptive')
              //    title('y = adaptive(f, x, ''maxArea'',1e-3)')
              //
              //    % Refine a function until the segments formed by pairs of successive 
              //    % points are shorter than 'maxLength'.
              //    y = adaptive(f, x, 'maxLength',0.1);
              //    figure(5); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-'); 
              //    legend('initial sampling','high sampling','adaptive')
              //    title('y = adaptive(f, x, ''maxLength'',0.1)');
              //  Copyright
              //  2017, Alberto Comin -  LMU Muenchen
              //  Version changes:
              //
              //  24/01/2017: 1) new default: when no optional argument is given, use the 
              //   'angle' method as default 2) it is now possible to provide just the 
              //   start and the end of the function domain, instead of having to 
              //   explicitly provide an initial array 3) a new key-word argument 
              //   'nPoints' controls the number of initial domain points in the cases when 
              //   the initial array is not explicitly provided. 4) it is now possible to 
              //   return the domain points and the function values either as a single 2D 
              //   array or as two separate arrays.
              //  25/01/2017: fixed defaults for the case when no method is specified 
              //  Default settings
              //  units normalized to data range
              //  units normalized to data range
              //  units normalized to data range
              //  units normalized to data range
              //  Test-mode
              //  The test mode is activated by calling 'adaptive.m' with no input. 
              //  if nargin==0
              //    initialDomain =  -10:10;
              //    input_func = @(x) 100*exp(-(x+5.2).^2) + 50*exp(-5*(x-0.5).^2)+ 20*exp(-10*(x-5.8).^2); 
              //    thresholdingAngles = true;
              //    minAngle = 0.8*pi;
              //    thresholdingLength = true;
              //    minLength = 0.02;
              //    disp('Running adaptive.m in test mode');
              //    fprintf('input function: %s\n',func2str(input_func));
              //    disp('Plotting the function on a initial set of points');
              //    testFigureHandle = figure();
              //    plot(initialDomain, input_func(initialDomain),'bs-','LineWidth',1.5); 
              //    grid on; xlabel('x'); ylabel('y'); title('adaptive.m example'); 
              //  end
              //  Processing input arguments
              //  assert(isa(input_func,'function_handle'),'adaptiveFunctionEvaluation:ArgChk',... 
              //    'the first argument must be a function handle');
              //  assert(isnumeric(initialDomain) && isvector(initialDomain),... 
              //    'adaptiveFunctionEvaluation:ArgChk','initial points must be specified as a numeric vector'); 
              //
              //  if mod(nExtraArgIn,2)==1
              //    error('adaptiveFunctionEvaluation:ArgChk', ...
              //      'At least a key or a value is missing in the key-value arguments list.'); 
              //  end
              //  while n < nExtraArgIn
              //    switch lower(varargin{n})
              //      case 'minangle'
              //      case 'maxarea'
              //        maxArea = varargin{n+1};
              //        thresholdingArea = true;
              //        usingDefaultMethod = false;
              //        n = n+2;
              //      case 'maxlength'
              //        maxLength = varargin{n+1};
              //        thresholdingLength = true;
              //        usingDefaultMethod = false;
              //        n = n+2;
              //      case 'minlength'
              //        minLength = varargin{n+1};
              //        thresholdingLength = true;
              //        n = n+2;
              //      case 'minsignal'
              //        minSignal = varargin{n+1};
              //        thresholdingSignal = true;
              //        n = n+2;
              //      case 'npoints'
              //        nPoints = varargin{n+1};
              //        n = n+2;
              //      case 'vectorize'
              //        vectorizable = varargin{n+1};
              //        n = n+2;
              //      case 'maxrefinements'
              //        maxRefinements = varargin{n+1};
              //        n = n+2;
              //      case 'waitbar'
              //        displayWaitbar = varargin{n+1};
              //        n = n+2;
              //      otherwise
              //        error('adaptiveFunctionEvaluation:ArgChk',...
              //          ['unknown keyword argument: ', varargin{n}]);
              //    end
              //  end
              //  if no method is specified use the 'angle' method as default
              //  Initial function evaluation
              //  if initialDomain only contains the start and the end points, create a new 
              //  array with 'nPoints' points.
              layerThicks = dataBoxSize[0];
              CUDACHECK(cudaMemcpy(gpu_dataBoxSize, &dataBoxSize[0], 16UL,
                                   cudaMemcpyHostToDevice));
              dataBoxSize_dirtyOnCpu = false;
              ic_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(*gpu_dataBoxSize, *gpu_y);
              CUDACHECK(cudaGetLastError());
              if (dataBoxSize[0] == -dataBoxSize[1]) {
                lc_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(64U, 1U,
                  1U)>>>(*gpu_dataBoxSize, *gpu_y);
                CUDACHECK(cudaGetLastError());
                problemDef_cells_dirtyOnCpu = true;
              } else if (((dataBoxSize[0] < 0.0) != (dataBoxSize[1] < 0.0)) &&
                         ((fabs(dataBoxSize[0]) > 8.9884656743115785E+307) ||
                          (fabs(dataBoxSize[1]) > 8.9884656743115785E+307))) {
                bFactor = dataBoxSize[0] / 49.0;
                CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                     cudaMemcpyHostToDevice));
                kc_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(64U, 1U,
                  1U)>>>(bFactor, dataBoxSize[1] / 49.0, gpu_layerThicks, *gpu_y);
                CUDACHECK(cudaGetLastError());
                problemDef_cells_dirtyOnCpu = true;
              } else {
                CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                     cudaMemcpyHostToDevice));
                jc_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(64U, 1U,
                  1U)>>>((dataBoxSize[1] - dataBoxSize[0]) / 49.0,
                         gpu_layerThicks, *gpu_y);
                CUDACHECK(cudaGetLastError());
                problemDef_cells_dirtyOnCpu = true;
              }

              //  Normalize the input function: This step allows to use the same syntax for 
              //  functions with single or multiple output parameters.
              //  Remove this syntax for compile - AVH
              // func = @(x) normalizeFunction(x,sldProfile,vectorizable);
              //  Evaluate the input function on the initial set of points.
              //  Subfunctions
              //  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N 
              //  is the number of elements of x and M is the number of outputs of func. 
              //  All the outputs of func must be scalar.
              //  The optional parameter 'vectorizable' (default false) allows to specify 
              //  that the input function can be vectorized.
              //  Modified by AVH for use with coder
              // if (~exist('vectorizable','var') || isempty(vectorizable))
              //  end
              // abs(nargout(func)); %for anonymous functions nargout<0
              //  if vectorizable
              //    % For uniformity reasons, transform the 'x' array into a column vector. 
              //    % In this way it does not matter if it is given as a column or a row 
              //    % vector.
              //    [newValues{:}] = func(x(:));
              //    y = cell2mat(newValues);
              //  else
              for (c_i = 0; c_i < 50; c_i++) {
                //  Remove cell array so no need for cell2mat
                //  which won't compile - AVH
                // [newValues{:}] = func(x(i));
                // y(i,:) = cell2mat(newValues);
                //  sldVal = sldFunc(x,SLD)
                //  SLD = [x rho;....xn rho]
                //    x = value in Angstrom.
                //
                //  This function returns the SLD (y) value associated with the
                //  supplied value of x. SLD is a two column, XY array defining an 
                //  SLD profile. This function interpolates the SLD profile
                //  to return the SLD at the specific value of X. X can be a vector of 
                //  multiple points.
                //
                //  (c) Arwel Hughes 2019.
                //  Last modified - AVH, 26/11/19.
                //  global sldProfile
                //
                //  SLD = sldProfile;
                // SLD = getappdata(0,'sldFuncSLD');
                if (problemDef_cells_dirtyOnCpu) {
                  CUDACHECK(cudaMemcpy(&y[0], gpu_y, 400UL,
                                       cudaMemcpyDeviceToHost));
                  problemDef_cells_dirtyOnCpu = false;
                }

                layerThicks = y[c_i];
                kEnd = sldProfile->size[0] - 1;
                qEnd = i_x->size[0];
                i_x->size[0] = kEnd + 1;
                emxEnsureCapacity_boolean_T(i_x, qEnd);
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  (kEnd + 1L), &fb_grid, &fb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  if (sldProfile_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(sldProfile, &inter_sldProfile,
                      gpu_sldProfile);
                    sldProfile_dirtyOnCpu = false;
                  }

                  CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                       cudaMemcpyHostToDevice));
                  gpuEmxMemcpyCpuToGpu_boolean_T(i_x, &b_inter_x, b_gpu_x);
                  mc_reflectivity_calculation_gpu<<<fb_grid, fb_block>>>
                    (gpu_layerThicks, gpu_sldProfile, kEnd, b_gpu_x);
                  CUDACHECK(cudaGetLastError());
                  gpuEmxMemcpyGpuToCpu_boolean_T(i_x, &b_inter_x);
                }

                nx = i_x->size[0];
                vlen = 0;
                kEnd = c_ii->size[0];
                c_ii->size[0] = i_x->size[0];
                emxEnsureCapacity_int32_T(c_ii, kEnd);
                xoffset = 1;
                exitg2 = false;
                while ((!exitg2) && (xoffset <= nx)) {
                  if (i_x->data[xoffset - 1]) {
                    vlen++;
                    c_ii->data[vlen - 1] = xoffset;
                    if (vlen >= nx) {
                      exitg2 = true;
                    } else {
                      xoffset++;
                    }
                  } else {
                    xoffset++;
                  }
                }

                if (i_x->size[0] == 1) {
                  if (vlen == 0) {
                    c_ii->size[0] = 0;
                  }
                } else {
                  kEnd = c_ii->size[0];
                  if (1 > vlen) {
                    c_ii->size[0] = 0;
                  } else {
                    c_ii->size[0] = vlen;
                  }

                  emxEnsureCapacity_int32_T(c_ii, kEnd);
                }

                if (c_ii->size[0] != 0) {
                  kEnd = r11->size[0];
                  r11->size[0] = c_ii->size[0];
                  emxEnsureCapacity_real_T(r11, kEnd);
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((c_ii->size[0] - 1) + 1L), &ib_grid, &ib_block, 1024U,
                    65535U);
                  if (validLaunchParams) {
                    if (sldProfile_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(sldProfile, &inter_sldProfile,
                        gpu_sldProfile);
                      sldProfile_dirtyOnCpu = false;
                    }

                    gpuEmxMemcpyCpuToGpu_int32_T(c_ii, &inter_ii, gpu_ii);
                    gpuEmxMemcpyCpuToGpu_real_T(r11, &inter_r11, gpu_r11);
                    pc_reflectivity_calculation_gpu<<<ib_grid, ib_block>>>
                      (gpu_sldProfile, gpu_ii, gpu_r11);
                    CUDACHECK(cudaGetLastError());
                    gpuEmxMemcpyGpuToCpu_real_T(r11, &inter_r11);
                  }
                } else {
                  layerThicks = y[c_i];
                  kEnd = sldProfile->size[0] - 1;
                  qEnd = k_x->size[0];
                  k_x->size[0] = kEnd + 1;
                  emxEnsureCapacity_boolean_T(k_x, qEnd);
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    (kEnd + 1L), &gb_grid, &gb_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    if (sldProfile_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(sldProfile, &inter_sldProfile,
                        gpu_sldProfile);
                      sldProfile_dirtyOnCpu = false;
                    }

                    CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                         cudaMemcpyHostToDevice));
                    gpuEmxMemcpyCpuToGpu_boolean_T(k_x, &c_inter_x, c_gpu_x);
                    nc_reflectivity_calculation_gpu<<<gb_grid, gb_block>>>
                      (gpu_sldProfile, gpu_layerThicks, kEnd, c_gpu_x);
                    CUDACHECK(cudaGetLastError());
                    gpuEmxMemcpyGpuToCpu_boolean_T(k_x, &c_inter_x);
                  }

                  nx = k_x->size[0];
                  vlen = 0;
                  kEnd = e_ii->size[0];
                  e_ii->size[0] = k_x->size[0];
                  emxEnsureCapacity_int32_T(e_ii, kEnd);
                  xoffset = 1;
                  exitg2 = false;
                  while ((!exitg2) && (xoffset <= nx)) {
                    if (k_x->data[xoffset - 1]) {
                      vlen++;
                      e_ii->data[vlen - 1] = xoffset;
                      if (vlen >= nx) {
                        exitg2 = true;
                      } else {
                        xoffset++;
                      }
                    } else {
                      xoffset++;
                    }
                  }

                  if (k_x->size[0] == 1) {
                    if (vlen == 0) {
                      e_ii->size[0] = 0;
                    }
                  } else {
                    kEnd = e_ii->size[0];
                    if (1 > vlen) {
                      e_ii->size[0] = 0;
                    } else {
                      e_ii->size[0] = vlen;
                    }

                    emxEnsureCapacity_int32_T(e_ii, kEnd);
                  }

                  layerThicks = y[c_i];
                  kEnd = sldProfile->size[0] - 1;
                  qEnd = m_x->size[0];
                  m_x->size[0] = kEnd + 1;
                  emxEnsureCapacity_boolean_T(m_x, qEnd);
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    (kEnd + 1L), &hb_grid, &hb_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    if (sldProfile_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(sldProfile, &inter_sldProfile,
                        gpu_sldProfile);
                      sldProfile_dirtyOnCpu = false;
                    }

                    CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                         cudaMemcpyHostToDevice));
                    gpuEmxMemcpyCpuToGpu_boolean_T(m_x, &d_inter_x, d_gpu_x);
                    oc_reflectivity_calculation_gpu<<<hb_grid, hb_block>>>
                      (gpu_sldProfile, gpu_layerThicks, kEnd, d_gpu_x);
                    CUDACHECK(cudaGetLastError());
                    gpuEmxMemcpyGpuToCpu_boolean_T(m_x, &d_inter_x);
                  }

                  nx = m_x->size[0];
                  vlen = 0;
                  kEnd = g_ii->size[0];
                  g_ii->size[0] = m_x->size[0];
                  emxEnsureCapacity_int32_T(g_ii, kEnd);
                  xoffset = 1;
                  exitg2 = false;
                  while ((!exitg2) && (xoffset <= nx)) {
                    if (m_x->data[xoffset - 1]) {
                      vlen++;
                      g_ii->data[vlen - 1] = xoffset;
                      if (vlen >= nx) {
                        exitg2 = true;
                      } else {
                        xoffset++;
                      }
                    } else {
                      xoffset++;
                    }
                  }

                  if (m_x->size[0] == 1) {
                    if (vlen == 0) {
                      g_ii->size[0] = 0;
                    }
                  } else {
                    kEnd = g_ii->size[0];
                    if (1 > vlen) {
                      g_ii->size[0] = 0;
                    } else {
                      g_ii->size[0] = vlen;
                    }

                    emxEnsureCapacity_int32_T(g_ii, kEnd);
                  }

                  layerThicks = (y[c_i] - sldProfile->data[e_ii->data[e_ii->
                                 size[0] - 1] - 1]) * (fabs(sldProfile->data
                    [(g_ii->data[0] + sldProfile->size[0]) - 1] -
                    sldProfile->data[(e_ii->data[e_ii->size[0] - 1] +
                                      sldProfile->size[0]) - 1]) /
                    (sldProfile->data[g_ii->data[0] - 1] - sldProfile->data
                     [e_ii->data[e_ii->size[0] - 1] - 1]));
                  if (sldProfile->data[(e_ii->data[e_ii->size[0] - 1] +
                                        sldProfile->size[0]) - 1] <
                      sldProfile->data[(g_ii->data[0] + sldProfile->size[0]) - 1])
                  {
                    kEnd = r11->size[0];
                    r11->size[0] = 1;
                    emxEnsureCapacity_real_T(r11, kEnd);
                    r11->data[0] = sldProfile->data[(e_ii->data[e_ii->size[0] -
                      1] + sldProfile->size[0]) - 1] + layerThicks;
                  } else {
                    kEnd = r11->size[0];
                    r11->size[0] = 1;
                    emxEnsureCapacity_real_T(r11, kEnd);
                    r11->data[0] = sldProfile->data[(e_ii->data[e_ii->size[0] -
                      1] + sldProfile->size[0]) - 1] - layerThicks;
                  }

                  // sldVal = interp1(z,rho,x);
                }

                hiVal[c_i] = r11->data[0];
                hiVal_dirtyOnCpu = true;
              }

              // end
              // dataPoints = [initialDomain(:), func(initialDomain(:))];
              if (hiVal_dirtyOnCpu) {
                CUDACHECK(cudaMemcpy(gpu_hiVal, &hiVal[0], 400UL,
                                     cudaMemcpyHostToDevice));
                hiVal_dirtyOnCpu = false;
              }

              qc_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(64U, 1U,
                1U)>>>(*gpu_hiVal, *gpu_y, *b_gpu_y);
              CUDACHECK(cudaGetLastError());
              kEnd = dataPoints->size[0] * dataPoints->size[1];
              dataPoints->size[0] = 50;
              dataPoints->size[1] = 2;
              emxEnsureCapacity_real_T(dataPoints, kEnd);
              gpuEmxMemcpyCpuToGpu_real_T(dataPoints, &inter_dataPoints,
                gpu_dataPoints);
              rc_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(128U, 1U,
                1U)>>>(*b_gpu_y, gpu_dataPoints);
              CUDACHECK(cudaGetLastError());
              sz_dirtyOnCpu = false;
              dataPoints_dirtyOnGpu = true;

              //  Iterative function refinement
              //  if displayWaitbar
              //    refinementWaitbar = waitbar(0,['Evaluating function ',func2str(func)],... 
              //      'CreateCancelBtn','setappdata(gcbf,''canceling'',true)');
              //    setappdata(refinementWaitbar,'canceling',false)
              //  end
              for (int32_T nRefinements = 0; nRefinements < 10; nRefinements++)
              {
                //  calculate the box which encloses the current data points:
                if (dataPoints_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(dataPoints, &inter_dataPoints);
                  dataPoints_dirtyOnGpu = false;
                }

                vlen = dataPoints->size[0];
                if (dataBoxSize_dirtyOnCpu) {
                  CUDACHECK(cudaMemcpy(gpu_dataBoxSize, &dataBoxSize[0], 16UL,
                                       cudaMemcpyHostToDevice));
                  dataBoxSize_dirtyOnCpu = false;
                }

                if (sz_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(dataPoints, &inter_dataPoints,
                    gpu_dataPoints);
                  sz_dirtyOnCpu = false;
                }

                sc_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                  1U)>>>(vlen, gpu_dataPoints, *gpu_dataBoxSize);
                CUDACHECK(cudaGetLastError());
                vlen = dataPoints->size[0];
                tc_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                  1U)>>>(vlen, gpu_dataPoints, *gpu_minval);
                CUDACHECK(cudaGetLastError());
                uc_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                  1U)>>>(*gpu_minval, *gpu_dataBoxSize);
                CUDACHECK(cudaGetLastError());
                dataBoxSize_dirtyOnGpu = true;

                //  Each point is considered as the central corner of the triangle formed 
                //  with its left and right hand side neighbours. The first and the last 
                //  points are not the central corner of any triangle, so for N points 
                //  there are only N-2 triangles.
                //  Calculate the central angle of the triangles formed by data points. 
                //  For input size NxM, the output size is (N-2)xN, because the first and the 
                //  last point are not the central corner of any triangle.
                //  Normalize data, because angles depend on scaling.
                kEnd = dataPoints->size[0];
                qEnd = g_b->size[0] * g_b->size[1];
                g_b->size[0] = kEnd;
                g_b->size[1] = 2;
                emxEnsureCapacity_real_T(g_b, qEnd);
                xoffset = dataPoints->size[0];
                for (nx = 0; nx < 2; nx++) {
                  vstride = nx * xoffset;
                  for (i2 = 0; i2 < xoffset; i2++) {
                    if (dataBoxSize_dirtyOnGpu) {
                      CUDACHECK(cudaMemcpy(&dataBoxSize[0], gpu_dataBoxSize,
                                           16UL, cudaMemcpyDeviceToHost));
                      dataBoxSize_dirtyOnGpu = false;
                    }

                    g_b->data[vstride + i2] = dataBoxSize[nx];
                  }
                }

                vlen = dataPoints->size[0];
                vc_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                  1U)>>>(vlen, gpu_dataPoints, *gpu_minval);
                CUDACHECK(cudaGetLastError());
                problemDef_cells_dirtyOnCpu = true;
                kEnd = dataPoints->size[0];
                qEnd = r14->size[0] * r14->size[1];
                r14->size[0] = kEnd;
                r14->size[1] = 2;
                emxEnsureCapacity_real_T(r14, qEnd);
                xoffset = dataPoints->size[0];
                for (nx = 0; nx < 2; nx++) {
                  vstride = nx * xoffset;
                  for (i2 = 0; i2 < xoffset; i2++) {
                    if (problemDef_cells_dirtyOnCpu) {
                      CUDACHECK(cudaMemcpy(&minval[0], gpu_minval, 16UL,
                                           cudaMemcpyDeviceToHost));
                      problemDef_cells_dirtyOnCpu = false;
                    }

                    r14->data[vstride + i2] = minval[nx];
                  }
                }

                kEnd = dataPoints->size[0] - 1;
                qEnd = normalizedData->size[0] * normalizedData->size[1];
                normalizedData->size[0] = kEnd + 1;
                normalizedData->size[1] = 2;
                emxEnsureCapacity_real_T(normalizedData, qEnd);
                problemDef_cells_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((kEnd + 1L) * 2L), &jb_grid, &jb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  gpuEmxMemcpyCpuToGpu_real_T(r14, &inter_r14, gpu_r14);
                  gpuEmxMemcpyCpuToGpu_real_T(g_b, &d_inter_b, d_gpu_b);
                  gpuEmxMemcpyCpuToGpu_real_T(normalizedData,
                    &inter_normalizedData, gpu_normalizedData);
                  wc_reflectivity_calculation_gpu<<<jb_grid, jb_block>>>(gpu_r14,
                    d_gpu_b, gpu_dataPoints, kEnd, gpu_normalizedData);
                  CUDACHECK(cudaGetLastError());
                  problemDef_cells_dirtyOnCpu = false;
                  normalizedData_dirtyOnGpu = true;
                }

                //  calculate cosine of central angles
                //  Return the sides (deltaX, deltaY) of the triangles formed by data points. 
                //  For input size NxM, the output size is (N-2)xN, because the first and the 
                //  last point are not the central corner of any triangle.
                if (normalizedData_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(normalizedData,
                    &inter_normalizedData);
                  normalizedData_dirtyOnGpu = false;
                }

                kEnd = normalizedData->size[0] - 2;
                qEnd = firstStep->size[0] * firstStep->size[1];
                firstStep->size[0] = kEnd;
                firstStep->size[1] = 2;
                emxEnsureCapacity_real_T(firstStep, qEnd);
                r8_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  (((kEnd - 1) + 1L) * 2L), &kb_grid, &kb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  if (problemDef_cells_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(normalizedData,
                      &inter_normalizedData, gpu_normalizedData);
                    problemDef_cells_dirtyOnCpu = false;
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(firstStep, &inter_firstStep,
                    gpu_firstStep);
                  xc_reflectivity_calculation_gpu<<<kb_grid, kb_block>>>
                    (gpu_normalizedData, kEnd, gpu_firstStep);
                  CUDACHECK(cudaGetLastError());
                  r8_dirtyOnCpu = false;
                  firstStep_dirtyOnGpu = true;
                }

                kEnd = normalizedData->size[0] - 1;
                qEnd = secondStep->size[0] * secondStep->size[1];
                secondStep->size[0] = kEnd - 1;
                secondStep->size[1] = 2;
                emxEnsureCapacity_real_T(secondStep, qEnd);
                r1_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  (((kEnd - 2) + 1L) * 2L), &lb_grid, &lb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  if (problemDef_cells_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(normalizedData,
                      &inter_normalizedData, gpu_normalizedData);
                    problemDef_cells_dirtyOnCpu = false;
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(secondStep, &inter_secondStep,
                    gpu_secondStep);
                  yc_reflectivity_calculation_gpu<<<lb_grid, lb_block>>>
                    (gpu_normalizedData, kEnd, gpu_secondStep);
                  CUDACHECK(cudaGetLastError());
                  r1_dirtyOnCpu = false;
                  secondStep_dirtyOnGpu = true;
                }

                kEnd = normalizedData->size[0] - 1;
                qEnd = longStep->size[0] * longStep->size[1];
                longStep->size[0] = kEnd - 1;
                longStep->size[1] = 2;
                emxEnsureCapacity_real_T(longStep, qEnd);
                b_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  (((kEnd - 2) + 1L) * 2L), &mb_grid, &mb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  if (problemDef_cells_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(normalizedData,
                      &inter_normalizedData, gpu_normalizedData);
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(longStep, &inter_longStep,
                    gpu_longStep);
                  ad_reflectivity_calculation_gpu<<<mb_grid, mb_block>>>
                    (gpu_normalizedData, kEnd, gpu_longStep);
                  CUDACHECK(cudaGetLastError());
                  b_dirtyOnCpu = false;
                  longStep_dirtyOnGpu = true;
                }

                //  calculate area of squares of length of triangle sides
                kEnd = c_z1->size[0];
                if (firstStep_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(firstStep, &inter_firstStep);
                  firstStep_dirtyOnGpu = false;
                }

                c_z1->size[0] = firstStep->size[0];
                emxEnsureCapacity_real_T(c_z1, kEnd);
                xoffset_dirtyOnCpu = true;
                nx = firstStep->size[0];
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((nx - 1) + 1L), &nb_grid, &nb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                  if (r8_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(firstStep, &inter_firstStep,
                      gpu_firstStep);
                    r8_dirtyOnCpu = false;
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(c_z1, &inter_z1, gpu_z1);
                  bd_reflectivity_calculation_gpu<<<nb_grid, nb_block>>>
                    (gpu_firstStep, gpu_nx, gpu_z1);
                  CUDACHECK(cudaGetLastError());
                  xoffset_dirtyOnCpu = false;
                  z1_dirtyOnGpu = true;
                }

                if (b_z1_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(d_z1, &b_inter_z1);
                  b_z1_dirtyOnGpu = false;
                }

                kEnd = d_z1->size[0];
                d_z1->size[0] = firstStep->size[0];
                emxEnsureCapacity_real_T(d_z1, kEnd);
                Lays_dirtyOnCpu = true;
                nx = firstStep->size[0];
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((nx - 1) + 1L), &ob_grid, &ob_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                  if (r8_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(firstStep, &inter_firstStep,
                      gpu_firstStep);
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(d_z1, &b_inter_z1, b_gpu_z1);
                  cd_reflectivity_calculation_gpu<<<ob_grid, ob_block>>>
                    (gpu_firstStep, gpu_nx, b_gpu_z1);
                  CUDACHECK(cudaGetLastError());
                  Lays_dirtyOnCpu = false;
                  b_z1_dirtyOnGpu = true;
                }

                kEnd = firstStepSquared->size[0];
                if (z1_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(c_z1, &inter_z1);
                  z1_dirtyOnGpu = false;
                }

                firstStepSquared->size[0] = c_z1->size[0];
                emxEnsureCapacity_real_T(firstStepSquared, kEnd);
                b_bool = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((c_z1->size[0] - 1) + 1L), &pb_grid, &pb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  if (xoffset_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(c_z1, &inter_z1, gpu_z1);
                  }

                  if (Lays_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(d_z1, &b_inter_z1, b_gpu_z1);
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(firstStepSquared,
                    &inter_firstStepSquared, gpu_firstStepSquared);
                  dd_reflectivity_calculation_gpu<<<pb_grid, pb_block>>>
                    (b_gpu_z1, gpu_z1, gpu_firstStepSquared);
                  CUDACHECK(cudaGetLastError());
                  b_bool = false;
                  firstStepSquared_dirtyOnGpu = true;
                }

                kEnd = f_z1->size[0];
                if (secondStep_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(secondStep, &inter_secondStep);
                  secondStep_dirtyOnGpu = false;
                }

                f_z1->size[0] = secondStep->size[0];
                emxEnsureCapacity_real_T(f_z1, kEnd);
                xoffset_dirtyOnCpu = true;
                nx = secondStep->size[0];
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((nx - 1) + 1L), &qb_grid, &qb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                  if (r1_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(secondStep, &inter_secondStep,
                      gpu_secondStep);
                    r1_dirtyOnCpu = false;
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(f_z1, &c_inter_z1, c_gpu_z1);
                  ed_reflectivity_calculation_gpu<<<qb_grid, qb_block>>>
                    (gpu_secondStep, gpu_nx, c_gpu_z1);
                  CUDACHECK(cudaGetLastError());
                  xoffset_dirtyOnCpu = false;
                  c_z1_dirtyOnGpu = true;
                }

                if (d_z1_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(h_z1, &d_inter_z1);
                  d_z1_dirtyOnGpu = false;
                }

                kEnd = h_z1->size[0];
                h_z1->size[0] = secondStep->size[0];
                emxEnsureCapacity_real_T(h_z1, kEnd);
                Lays_dirtyOnCpu = true;
                nx = secondStep->size[0];
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((nx - 1) + 1L), &rb_grid, &rb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                  if (r1_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(secondStep, &inter_secondStep,
                      gpu_secondStep);
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(h_z1, &d_inter_z1, d_gpu_z1);
                  fd_reflectivity_calculation_gpu<<<rb_grid, rb_block>>>
                    (gpu_secondStep, gpu_nx, d_gpu_z1);
                  CUDACHECK(cudaGetLastError());
                  Lays_dirtyOnCpu = false;
                  d_z1_dirtyOnGpu = true;
                }

                if (secondStepSquared_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(secondStepSquared,
                    &inter_secondStepSquared);
                  secondStepSquared_dirtyOnGpu = false;
                }

                kEnd = secondStepSquared->size[0];
                if (c_z1_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(f_z1, &c_inter_z1);
                  c_z1_dirtyOnGpu = false;
                }

                secondStepSquared->size[0] = f_z1->size[0];
                emxEnsureCapacity_real_T(secondStepSquared, kEnd);
                problemDef_cells_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((f_z1->size[0] - 1) + 1L), &sb_grid, &sb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  if (xoffset_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(f_z1, &c_inter_z1, c_gpu_z1);
                  }

                  if (Lays_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(h_z1, &d_inter_z1, d_gpu_z1);
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(secondStepSquared,
                    &inter_secondStepSquared, gpu_secondStepSquared);
                  gd_reflectivity_calculation_gpu<<<sb_grid, sb_block>>>
                    (d_gpu_z1, c_gpu_z1, gpu_secondStepSquared);
                  CUDACHECK(cudaGetLastError());
                  problemDef_cells_dirtyOnCpu = false;
                  secondStepSquared_dirtyOnGpu = true;
                }

                if (e_z1_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(j_z1, &e_inter_z1);
                  e_z1_dirtyOnGpu = false;
                }

                kEnd = j_z1->size[0];
                if (longStep_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(longStep, &inter_longStep);
                  longStep_dirtyOnGpu = false;
                }

                j_z1->size[0] = longStep->size[0];
                emxEnsureCapacity_real_T(j_z1, kEnd);
                xoffset_dirtyOnCpu = true;
                nx = longStep->size[0];
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((nx - 1) + 1L), &tb_grid, &tb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                  if (b_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(longStep, &inter_longStep,
                      gpu_longStep);
                    b_dirtyOnCpu = false;
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(j_z1, &e_inter_z1, e_gpu_z1);
                  hd_reflectivity_calculation_gpu<<<tb_grid, tb_block>>>
                    (gpu_longStep, gpu_nx, e_gpu_z1);
                  CUDACHECK(cudaGetLastError());
                  xoffset_dirtyOnCpu = false;
                  e_z1_dirtyOnGpu = true;
                }

                if (f_z1_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(l_z1, &f_inter_z1);
                  f_z1_dirtyOnGpu = false;
                }

                kEnd = l_z1->size[0];
                l_z1->size[0] = longStep->size[0];
                emxEnsureCapacity_real_T(l_z1, kEnd);
                Lays_dirtyOnCpu = true;
                nx = longStep->size[0];
                r8_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((nx - 1) + 1L), &ub_grid, &ub_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                  r8_dirtyOnCpu = false;
                  if (b_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(longStep, &inter_longStep,
                      gpu_longStep);
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(l_z1, &f_inter_z1, f_gpu_z1);
                  id_reflectivity_calculation_gpu<<<ub_grid, ub_block>>>
                    (gpu_longStep, gpu_nx, f_gpu_z1);
                  CUDACHECK(cudaGetLastError());
                  Lays_dirtyOnCpu = false;
                  f_z1_dirtyOnGpu = true;
                }

                if (b_x_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(e_x, &e_inter_x);
                  b_x_dirtyOnGpu = false;
                }

                kEnd = e_x->size[0];
                if (firstStepSquared_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(firstStepSquared,
                    &inter_firstStepSquared);
                  firstStepSquared_dirtyOnGpu = false;
                }

                e_x->size[0] = firstStepSquared->size[0];
                emxEnsureCapacity_real_T(e_x, kEnd);
                x_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((firstStepSquared->size[0] - 1) + 1L), &vb_grid, &vb_block,
                  1024U, 65535U);
                if (validLaunchParams) {
                  if (b_bool) {
                    gpuEmxMemcpyCpuToGpu_real_T(firstStepSquared,
                      &inter_firstStepSquared, gpu_firstStepSquared);
                    b_bool = false;
                  }

                  if (problemDef_cells_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(secondStepSquared,
                      &inter_secondStepSquared, gpu_secondStepSquared);
                    problemDef_cells_dirtyOnCpu = false;
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(e_x, &e_inter_x, e_gpu_x);
                  jd_reflectivity_calculation_gpu<<<vb_grid, vb_block>>>
                    (gpu_secondStepSquared, gpu_firstStepSquared, e_gpu_x);
                  CUDACHECK(cudaGetLastError());
                  x_dirtyOnCpu = false;
                  b_x_dirtyOnGpu = true;
                }

                if (r8_dirtyOnCpu) {
                  CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                }

                if (x_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(e_x, &e_inter_x, e_gpu_x);
                }

                kd_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                  1U)>>>(e_gpu_x, gpu_nx);
                CUDACHECK(cudaGetLastError());
                CUDACHECK(cudaMemcpy(&nx, gpu_nx, 4UL, cudaMemcpyDeviceToHost));
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((nx - 1) + 1L), &wb_grid, &wb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  ld_reflectivity_calculation_gpu<<<wb_grid, wb_block>>>(gpu_nx,
                    e_gpu_x);
                  CUDACHECK(cudaGetLastError());
                  b_x_dirtyOnGpu = true;
                }

                if (c_x_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_creal_T(f_x, &f_inter_x);
                  c_x_dirtyOnGpu = false;
                }

                kEnd = f_x->size[0];
                f_x->size[0] = firstStepSquared->size[0];
                emxEnsureCapacity_creal_T(f_x, kEnd);
                x_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((firstStepSquared->size[0] - 1) + 1L), &xb_grid, &xb_block,
                  1024U, 65535U);
                if (validLaunchParams) {
                  if (b_bool) {
                    gpuEmxMemcpyCpuToGpu_real_T(firstStepSquared,
                      &inter_firstStepSquared, gpu_firstStepSquared);
                  }

                  if (problemDef_cells_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(secondStepSquared,
                      &inter_secondStepSquared, gpu_secondStepSquared);
                  }

                  if (xoffset_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(j_z1, &e_inter_z1, e_gpu_z1);
                  }

                  if (Lays_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(l_z1, &f_inter_z1, f_gpu_z1);
                  }

                  gpuEmxMemcpyCpuToGpu_creal_T(f_x, &f_inter_x, f_gpu_x);
                  md_reflectivity_calculation_gpu<<<xb_grid, xb_block>>>(e_gpu_x,
                    f_gpu_z1, e_gpu_z1, gpu_secondStepSquared,
                    gpu_firstStepSquared, f_gpu_x);
                  CUDACHECK(cudaGetLastError());
                  x_dirtyOnCpu = false;
                  c_x_dirtyOnGpu = true;
                }

                if (x_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_creal_T(f_x, &f_inter_x, f_gpu_x);
                }

                nd_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                  1U)>>>(f_gpu_x, gpu_nx);
                CUDACHECK(cudaGetLastError());
                CUDACHECK(cudaMemcpy(&nx, gpu_nx, 4UL, cudaMemcpyDeviceToHost));
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((nx - 1) + 1L), &yb_grid, &yb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  od_reflectivity_calculation_gpu<<<yb_grid, yb_block>>>(gpu_nx,
                    f_gpu_x);
                  CUDACHECK(cudaGetLastError());
                  c_x_dirtyOnGpu = true;
                }

                kEnd = trianglesToRefine->size[0];
                trianglesToRefine->size[0] = dataPoints->size[0] - 2;
                emxEnsureCapacity_boolean_T(trianglesToRefine, kEnd);
                problemDef_cells_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((dataPoints->size[0] - 3) + 1L), &ac_grid, &ac_block, 1024U,
                  65535U);
                if (validLaunchParams) {
                  gpuEmxMemcpyCpuToGpu_boolean_T(trianglesToRefine,
                    &inter_trianglesToRefine, gpu_trianglesToRefine);
                  pd_reflectivity_calculation_gpu<<<ac_grid, ac_block>>>(f_gpu_x,
                    gpu_dataPoints, gpu_trianglesToRefine);
                  CUDACHECK(cudaGetLastError());
                  problemDef_cells_dirtyOnCpu = false;
                  trianglesToRefine_dirtyOnGpu = true;
                }

                //  For N points there are N-2 triangles and N-1 triangle sides. Each 
                //  triangle side is a segment, which can be split or not depending on the 
                //  refinement parameters.
                kEnd = c_trianglesToRefine->size[0];
                if (trianglesToRefine_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_boolean_T(trianglesToRefine,
                    &inter_trianglesToRefine);
                  trianglesToRefine_dirtyOnGpu = false;
                }

                c_trianglesToRefine->size[0] = trianglesToRefine->size[0] + 1;
                emxEnsureCapacity_boolean_T(c_trianglesToRefine, kEnd);
                r8_dirtyOnCpu = true;
                nx = trianglesToRefine->size[0] - 1;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>(nx
                  + 1L), &bc_grid, &bc_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                  if (problemDef_cells_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_boolean_T(trianglesToRefine,
                      &inter_trianglesToRefine, gpu_trianglesToRefine);
                    problemDef_cells_dirtyOnCpu = false;
                  }

                  gpuEmxMemcpyCpuToGpu_boolean_T(c_trianglesToRefine,
                    &b_inter_trianglesToRefine, b_gpu_trianglesToRefine);
                  qd_reflectivity_calculation_gpu<<<bc_grid, bc_block>>>
                    (gpu_trianglesToRefine, gpu_nx, b_gpu_trianglesToRefine);
                  CUDACHECK(cudaGetLastError());
                  r8_dirtyOnCpu = false;
                }

                if (problemDef_cells_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_boolean_T(trianglesToRefine,
                    &inter_trianglesToRefine, gpu_trianglesToRefine);
                }

                if (r8_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_boolean_T(c_trianglesToRefine,
                    &b_inter_trianglesToRefine, b_gpu_trianglesToRefine);
                }

                rd_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                  1U)>>>(gpu_trianglesToRefine, b_gpu_trianglesToRefine);
                CUDACHECK(cudaGetLastError());
                if (r32_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_boolean_T(r32, &inter_r32);
                }

                kEnd = r32->size[0];
                r32->size[0] = trianglesToRefine->size[0] + 1;
                emxEnsureCapacity_boolean_T(r32, kEnd);
                gpuEmxMemcpyCpuToGpu_boolean_T(r32, &inter_r32, gpu_r32);
                sd_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                  1U)>>>(gpu_r32);
                CUDACHECK(cudaGetLastError());
                r32_dirtyOnGpu = true;
                nx = trianglesToRefine->size[0] - 1;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>(nx
                  + 1L), &cc_grid, &cc_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                  td_reflectivity_calculation_gpu<<<cc_grid, cc_block>>>
                    (gpu_trianglesToRefine, gpu_nx, gpu_r32);
                  CUDACHECK(cudaGetLastError());
                }

                kEnd = segmentsToSplit->size[0];
                gpuEmxMemcpyGpuToCpu_boolean_T(c_trianglesToRefine,
                  &b_inter_trianglesToRefine);
                segmentsToSplit->size[0] = c_trianglesToRefine->size[0];
                emxEnsureCapacity_boolean_T(segmentsToSplit, kEnd);
                r1_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((c_trianglesToRefine->size[0] - 1) + 1L), &dc_grid, &dc_block,
                  1024U, 65535U);
                if (validLaunchParams) {
                  gpuEmxMemcpyCpuToGpu_boolean_T(segmentsToSplit,
                    &inter_segmentsToSplit, gpu_segmentsToSplit);
                  ud_reflectivity_calculation_gpu<<<dc_grid, dc_block>>>(gpu_r32,
                    b_gpu_trianglesToRefine, gpu_segmentsToSplit);
                  CUDACHECK(cudaGetLastError());
                  r1_dirtyOnCpu = false;
                  segmentsToSplit_dirtyOnGpu = true;
                }

                b_bool = false;
                xoffset = 1;
                do {
                  exitg1 = 0;
                  if (segmentsToSplit_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_boolean_T(segmentsToSplit,
                      &inter_segmentsToSplit);
                    segmentsToSplit_dirtyOnGpu = false;
                  }

                  if (xoffset <= segmentsToSplit->size[0]) {
                    problemDef_cells_dirtyOnCpu = !segmentsToSplit->data[xoffset
                      - 1];
                    if (!problemDef_cells_dirtyOnCpu) {
                      b_bool = true;
                      exitg1 = 1;
                    } else {
                      xoffset++;
                    }
                  } else {
                    exitg1 = 1;
                  }
                } while (exitg1 == 0);

                if (b_bool) {
                  //  increaseSampling increase the sampling of an input function 
                  vstride = segmentsToSplit->size[0];
                  xoffset = 0;
                  for (c_i = 0; c_i < vstride; c_i++) {
                    if (segmentsToSplit->data[c_i]) {
                      xoffset++;
                    }
                  }

                  kEnd = newDataPoints->size[0] * newDataPoints->size[1];
                  newDataPoints->size[0] = xoffset;
                  newDataPoints->size[1] = 2;
                  emxEnsureCapacity_real_T(newDataPoints, kEnd);
                  r8_dirtyOnCpu = true;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((xoffset * 2 - 1) + 1L), &ec_grid, &ec_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    CUDACHECK(cudaMemcpy(gpu_xoffset, &xoffset, 4UL,
                                         cudaMemcpyHostToDevice));
                    gpuEmxMemcpyCpuToGpu_real_T(newDataPoints,
                      &inter_newDataPoints, gpu_newDataPoints);
                    vd_reflectivity_calculation_gpu<<<ec_grid, ec_block>>>
                      (gpu_xoffset, gpu_newDataPoints);
                    CUDACHECK(cudaGetLastError());
                    r8_dirtyOnCpu = false;
                    newDataPoints_dirtyOnGpu = true;
                  }

                  if (r21_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_boolean_T(r21, &inter_r21);
                  }

                  kEnd = r21->size[0];
                  r21->size[0] = segmentsToSplit->size[0] + 1;
                  emxEnsureCapacity_boolean_T(r21, kEnd);
                  problemDef_cells_dirtyOnCpu = true;
                  nx = segmentsToSplit->size[0] - 1;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    (nx + 1L), &fc_grid, &fc_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL,
                                         cudaMemcpyHostToDevice));
                    if (r1_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_boolean_T(segmentsToSplit,
                        &inter_segmentsToSplit, gpu_segmentsToSplit);
                      r1_dirtyOnCpu = false;
                    }

                    gpuEmxMemcpyCpuToGpu_boolean_T(r21, &inter_r21, gpu_r21);
                    wd_reflectivity_calculation_gpu<<<fc_grid, fc_block>>>
                      (gpu_segmentsToSplit, gpu_nx, gpu_r21);
                    CUDACHECK(cudaGetLastError());
                    problemDef_cells_dirtyOnCpu = false;
                  }

                  if (r1_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_boolean_T(segmentsToSplit,
                      &inter_segmentsToSplit, gpu_segmentsToSplit);
                  }

                  if (problemDef_cells_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_boolean_T(r21, &inter_r21, gpu_r21);
                  }

                  xd_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U,
                    1U, 1U)>>>(gpu_segmentsToSplit, gpu_r21);
                  CUDACHECK(cudaGetLastError());
                  kEnd = r23->size[0];
                  r23->size[0] = segmentsToSplit->size[0] + 1;
                  emxEnsureCapacity_boolean_T(r23, kEnd);
                  gpuEmxMemcpyCpuToGpu_boolean_T(r23, &inter_r23, gpu_r23);
                  yd_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U,
                    1U, 1U)>>>(gpu_r23);
                  CUDACHECK(cudaGetLastError());
                  nx = segmentsToSplit->size[0] - 1;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    (nx + 1L), &gc_grid, &gc_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL,
                                         cudaMemcpyHostToDevice));
                    ae_reflectivity_calculation_gpu<<<gc_grid, gc_block>>>
                      (gpu_segmentsToSplit, gpu_nx, gpu_r23);
                    CUDACHECK(cudaGetLastError());
                  }

                  gpuEmxMemcpyGpuToCpu_boolean_T(r21, &inter_r21);
                  r21_dirtyOnGpu = false;
                  vstride = r21->size[0] - 1;
                  xoffset = 0;
                  for (c_i = 0; c_i <= vstride; c_i++) {
                    if (r21_dirtyOnGpu) {
                      gpuEmxMemcpyGpuToCpu_boolean_T(r21, &inter_r21);
                      r21_dirtyOnGpu = false;
                    }

                    if (r21->data[c_i]) {
                      xoffset++;
                    }
                  }

                  kEnd = r25->size[0];
                  r25->size[0] = xoffset;
                  emxEnsureCapacity_int32_T(r25, kEnd);
                  xoffset = 0;
                  for (c_i = 0; c_i <= vstride; c_i++) {
                    if (r21_dirtyOnGpu) {
                      gpuEmxMemcpyGpuToCpu_boolean_T(r21, &inter_r21);
                      r21_dirtyOnGpu = false;
                    }

                    if (r21->data[c_i]) {
                      r25->data[xoffset] = c_i + 1;
                      xoffset++;
                    }
                  }

                  gpuEmxMemcpyGpuToCpu_boolean_T(r23, &inter_r23);
                  vstride = r23->size[0] - 1;
                  xoffset = 0;
                  for (c_i = 0; c_i <= vstride; c_i++) {
                    if (r23->data[c_i]) {
                      xoffset++;
                    }
                  }

                  kEnd = r27->size[0];
                  r27->size[0] = xoffset;
                  emxEnsureCapacity_int32_T(r27, kEnd);
                  xoffset = 0;
                  for (c_i = 0; c_i <= vstride; c_i++) {
                    if (r23->data[c_i]) {
                      r27->data[xoffset] = c_i + 1;
                      xoffset++;
                    }
                  }

                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((r25->size[0] - 1) + 1L), &hc_grid, &hc_block, 1024U,
                    65535U);
                  if (validLaunchParams) {
                    if (r8_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(newDataPoints,
                        &inter_newDataPoints, gpu_newDataPoints);
                      r8_dirtyOnCpu = false;
                    }

                    gpuEmxMemcpyCpuToGpu_int32_T(r27, &inter_r27, gpu_r27);
                    gpuEmxMemcpyCpuToGpu_int32_T(r25, &inter_r25, gpu_r25);
                    be_reflectivity_calculation_gpu<<<hc_grid, hc_block>>>
                      (gpu_r27, gpu_dataPoints, gpu_r25, gpu_newDataPoints);
                    CUDACHECK(cudaGetLastError());
                    newDataPoints_dirtyOnGpu = true;
                  }

                  //  Subfunctions
                  //  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N 
                  //  is the number of elements of x and M is the number of outputs of func. 
                  //  All the outputs of func must be scalar.
                  //  The optional parameter 'vectorizable' (default false) allows to specify 
                  //  that the input function can be vectorized.
                  //  Modified by AVH for use with coder
                  // if (~exist('vectorizable','var') || isempty(vectorizable))
                  //  end
                  // abs(nargout(func)); %for anonymous functions nargout<0
                  //  if vectorizable
                  //    % For uniformity reasons, transform the 'x' array into a column vector. 
                  //    % In this way it does not matter if it is given as a column or a row 
                  //    % vector.
                  //    [newValues{:}] = func(x(:));
                  //    y = cell2mat(newValues);
                  //  else
                  if (newDataPoints_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_real_T(newDataPoints,
                      &inter_newDataPoints);
                    newDataPoints_dirtyOnGpu = false;
                  }

                  kEnd = newDataPoints->size[0];
                  qEnd = r16->size[0];
                  r16->size[0] = newDataPoints->size[0];
                  emxEnsureCapacity_real_T(r16, qEnd);
                  for (c_i = 0; c_i < kEnd; c_i++) {
                    //  Remove cell array so no need for cell2mat
                    //  which won't compile - AVH
                    // [newValues{:}] = func(x(i));
                    // y(i,:) = cell2mat(newValues);
                    //  sldVal = sldFunc(x,SLD)
                    //  SLD = [x rho;....xn rho]
                    //    x = value in Angstrom.
                    //
                    //  This function returns the SLD (y) value associated with the 
                    //  supplied value of x. SLD is a two column, XY array defining an 
                    //  SLD profile. This function interpolates the SLD profile
                    //  to return the SLD at the specific value of X. X can be a vector of 
                    //  multiple points.
                    //
                    //  (c) Arwel Hughes 2019.
                    //  Last modified - AVH, 26/11/19.
                    //  global sldProfile
                    //
                    //  SLD = sldProfile;
                    // SLD = getappdata(0,'sldFuncSLD');
                    layerThicks = newDataPoints->data[c_i];
                    qEnd = sldProfile->size[0] - 1;
                    xoffset = o_x->size[0];
                    o_x->size[0] = qEnd + 1;
                    emxEnsureCapacity_boolean_T(o_x, xoffset);
                    validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                      (qEnd + 1L), &ic_grid, &ic_block, 1024U, 65535U);
                    if (validLaunchParams) {
                      if (sldProfile_dirtyOnCpu) {
                        gpuEmxMemcpyCpuToGpu_real_T(sldProfile,
                          &inter_sldProfile, gpu_sldProfile);
                        sldProfile_dirtyOnCpu = false;
                      }

                      CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                           cudaMemcpyHostToDevice));
                      CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL,
                                           cudaMemcpyHostToDevice));
                      gpuEmxMemcpyCpuToGpu_boolean_T(o_x, &g_inter_x, g_gpu_x);
                      ce_reflectivity_calculation_gpu<<<ic_grid, ic_block>>>
                        (gpu_layerThicks, gpu_sldProfile, gpu_qEnd, g_gpu_x);
                      CUDACHECK(cudaGetLastError());
                      gpuEmxMemcpyGpuToCpu_boolean_T(o_x, &g_inter_x);
                    }

                    nx = o_x->size[0];
                    vlen = 0;
                    qEnd = i_ii->size[0];
                    i_ii->size[0] = o_x->size[0];
                    emxEnsureCapacity_int32_T(i_ii, qEnd);
                    xoffset = 1;
                    exitg2 = false;
                    while ((!exitg2) && (xoffset <= nx)) {
                      if (o_x->data[xoffset - 1]) {
                        vlen++;
                        i_ii->data[vlen - 1] = xoffset;
                        if (vlen >= nx) {
                          exitg2 = true;
                        } else {
                          xoffset++;
                        }
                      } else {
                        xoffset++;
                      }
                    }

                    if (o_x->size[0] == 1) {
                      if (vlen == 0) {
                        i_ii->size[0] = 0;
                      }
                    } else {
                      qEnd = i_ii->size[0];
                      if (1 > vlen) {
                        i_ii->size[0] = 0;
                      } else {
                        i_ii->size[0] = vlen;
                      }

                      emxEnsureCapacity_int32_T(i_ii, qEnd);
                    }

                    if (i_ii->size[0] != 0) {
                      qEnd = r30->size[0];
                      r30->size[0] = i_ii->size[0];
                      emxEnsureCapacity_real_T(r30, qEnd);
                      validLaunchParams = mwGetLaunchParameters
                        (static_cast<real_T>((i_ii->size[0] - 1) + 1L), &lc_grid,
                         &lc_block, 1024U, 65535U);
                      if (validLaunchParams) {
                        if (sldProfile_dirtyOnCpu) {
                          gpuEmxMemcpyCpuToGpu_real_T(sldProfile,
                            &inter_sldProfile, gpu_sldProfile);
                          sldProfile_dirtyOnCpu = false;
                        }

                        gpuEmxMemcpyCpuToGpu_int32_T(i_ii, &b_inter_ii, b_gpu_ii);
                        gpuEmxMemcpyCpuToGpu_real_T(r30, &inter_r30, gpu_r30);
                        fe_reflectivity_calculation_gpu<<<lc_grid, lc_block>>>
                          (gpu_sldProfile, b_gpu_ii, gpu_r30);
                        CUDACHECK(cudaGetLastError());
                        gpuEmxMemcpyGpuToCpu_real_T(r30, &inter_r30);
                      }
                    } else {
                      layerThicks = newDataPoints->data[c_i];
                      qEnd = sldProfile->size[0] - 1;
                      xoffset = q_x->size[0];
                      q_x->size[0] = qEnd + 1;
                      emxEnsureCapacity_boolean_T(q_x, xoffset);
                      validLaunchParams = mwGetLaunchParameters
                        (static_cast<real_T>(qEnd + 1L), &jc_grid, &jc_block,
                         1024U, 65535U);
                      if (validLaunchParams) {
                        if (sldProfile_dirtyOnCpu) {
                          gpuEmxMemcpyCpuToGpu_real_T(sldProfile,
                            &inter_sldProfile, gpu_sldProfile);
                          sldProfile_dirtyOnCpu = false;
                        }

                        CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                             cudaMemcpyHostToDevice));
                        CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL,
                                             cudaMemcpyHostToDevice));
                        gpuEmxMemcpyCpuToGpu_boolean_T(q_x, &h_inter_x, h_gpu_x);
                        de_reflectivity_calculation_gpu<<<jc_grid, jc_block>>>
                          (gpu_sldProfile, gpu_layerThicks, gpu_qEnd, h_gpu_x);
                        CUDACHECK(cudaGetLastError());
                        gpuEmxMemcpyGpuToCpu_boolean_T(q_x, &h_inter_x);
                      }

                      nx = q_x->size[0];
                      vlen = 0;
                      qEnd = k_ii->size[0];
                      k_ii->size[0] = q_x->size[0];
                      emxEnsureCapacity_int32_T(k_ii, qEnd);
                      xoffset = 1;
                      exitg2 = false;
                      while ((!exitg2) && (xoffset <= nx)) {
                        if (q_x->data[xoffset - 1]) {
                          vlen++;
                          k_ii->data[vlen - 1] = xoffset;
                          if (vlen >= nx) {
                            exitg2 = true;
                          } else {
                            xoffset++;
                          }
                        } else {
                          xoffset++;
                        }
                      }

                      if (q_x->size[0] == 1) {
                        if (vlen == 0) {
                          k_ii->size[0] = 0;
                        }
                      } else {
                        qEnd = k_ii->size[0];
                        if (1 > vlen) {
                          k_ii->size[0] = 0;
                        } else {
                          k_ii->size[0] = vlen;
                        }

                        emxEnsureCapacity_int32_T(k_ii, qEnd);
                      }

                      layerThicks = newDataPoints->data[c_i];
                      qEnd = sldProfile->size[0] - 1;
                      xoffset = s_x->size[0];
                      s_x->size[0] = qEnd + 1;
                      emxEnsureCapacity_boolean_T(s_x, xoffset);
                      validLaunchParams = mwGetLaunchParameters
                        (static_cast<real_T>(qEnd + 1L), &kc_grid, &kc_block,
                         1024U, 65535U);
                      if (validLaunchParams) {
                        if (sldProfile_dirtyOnCpu) {
                          gpuEmxMemcpyCpuToGpu_real_T(sldProfile,
                            &inter_sldProfile, gpu_sldProfile);
                          sldProfile_dirtyOnCpu = false;
                        }

                        CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                             cudaMemcpyHostToDevice));
                        CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL,
                                             cudaMemcpyHostToDevice));
                        gpuEmxMemcpyCpuToGpu_boolean_T(s_x, &i_inter_x, i_gpu_x);
                        ee_reflectivity_calculation_gpu<<<kc_grid, kc_block>>>
                          (gpu_sldProfile, gpu_layerThicks, gpu_qEnd, i_gpu_x);
                        CUDACHECK(cudaGetLastError());
                        gpuEmxMemcpyGpuToCpu_boolean_T(s_x, &i_inter_x);
                      }

                      nx = s_x->size[0];
                      vlen = 0;
                      qEnd = m_ii->size[0];
                      m_ii->size[0] = s_x->size[0];
                      emxEnsureCapacity_int32_T(m_ii, qEnd);
                      xoffset = 1;
                      exitg2 = false;
                      while ((!exitg2) && (xoffset <= nx)) {
                        if (s_x->data[xoffset - 1]) {
                          vlen++;
                          m_ii->data[vlen - 1] = xoffset;
                          if (vlen >= nx) {
                            exitg2 = true;
                          } else {
                            xoffset++;
                          }
                        } else {
                          xoffset++;
                        }
                      }

                      if (s_x->size[0] == 1) {
                        if (vlen == 0) {
                          m_ii->size[0] = 0;
                        }
                      } else {
                        qEnd = m_ii->size[0];
                        if (1 > vlen) {
                          m_ii->size[0] = 0;
                        } else {
                          m_ii->size[0] = vlen;
                        }

                        emxEnsureCapacity_int32_T(m_ii, qEnd);
                      }

                      layerThicks = (newDataPoints->data[c_i] - sldProfile->
                                     data[k_ii->data[k_ii->size[0] - 1] - 1]) *
                        (fabs(sldProfile->data[(m_ii->data[0] + sldProfile->
                           size[0]) - 1] - sldProfile->data[(k_ii->data
                           [k_ii->size[0] - 1] + sldProfile->size[0]) - 1]) /
                         (sldProfile->data[m_ii->data[0] - 1] - sldProfile->
                          data[k_ii->data[k_ii->size[0] - 1] - 1]));
                      if (sldProfile->data[(k_ii->data[k_ii->size[0] - 1] +
                                            sldProfile->size[0]) - 1] <
                          sldProfile->data[(m_ii->data[0] + sldProfile->size[0])
                          - 1]) {
                        qEnd = r30->size[0];
                        r30->size[0] = 1;
                        emxEnsureCapacity_real_T(r30, qEnd);
                        r30->data[0] = sldProfile->data[(k_ii->data[k_ii->size[0]
                          - 1] + sldProfile->size[0]) - 1] + layerThicks;
                      } else {
                        qEnd = r30->size[0];
                        r30->size[0] = 1;
                        emxEnsureCapacity_real_T(r30, qEnd);
                        r30->data[0] = sldProfile->data[(k_ii->data[k_ii->size[0]
                          - 1] + sldProfile->size[0]) - 1] - layerThicks;
                      }

                      // sldVal = interp1(z,rho,x);
                    }

                    r16->data[c_i] = r30->data[0];
                  }

                  // end
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((r16->size[0] - 1) + 1L), &mc_grid, &mc_block, 1024U,
                    65535U);
                  if (validLaunchParams) {
                    if (r8_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(newDataPoints,
                        &inter_newDataPoints, gpu_newDataPoints);
                    }

                    gpuEmxMemcpyCpuToGpu_real_T(r16, &inter_r16, gpu_r16);
                    ge_reflectivity_calculation_gpu<<<mc_grid, mc_block>>>
                      (gpu_r16, gpu_newDataPoints);
                    CUDACHECK(cudaGetLastError());
                    newDataPoints_dirtyOnGpu = true;
                  }

                  //  For simplicity append the new points at the end and then sort. 
                  if (newDataPoints_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_real_T(newDataPoints,
                      &inter_newDataPoints);
                    newDataPoints_dirtyOnGpu = false;
                  }

                  if (newDataPoints->size[0] != 0) {
                    xoffset = newDataPoints->size[0];
                  } else {
                    xoffset = 0;
                  }

                  kEnd = c_dataPoints->size[0] * c_dataPoints->size[1];
                  c_dataPoints->size[0] = dataPoints->size[0] + xoffset;
                  c_dataPoints->size[1] = 2;
                  emxEnsureCapacity_real_T(c_dataPoints, kEnd);
                  problemDef_cells_dirtyOnCpu = true;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    (((dataPoints->size[0] - 1) + 1L) * 2L), &nc_grid, &nc_block,
                    1024U, 65535U);
                  if (validLaunchParams) {
                    gpuEmxMemcpyCpuToGpu_real_T(c_dataPoints,
                      &b_inter_dataPoints, b_gpu_dataPoints);
                    he_reflectivity_calculation_gpu<<<nc_grid, nc_block>>>
                      (gpu_dataPoints, b_gpu_dataPoints);
                    CUDACHECK(cudaGetLastError());
                    problemDef_cells_dirtyOnCpu = false;
                    b_dataPoints_dirtyOnGpu = true;
                  }

                  for (kEnd = 0; kEnd < 2; kEnd++) {
                    for (qEnd = 0; qEnd < xoffset; qEnd++) {
                      if (b_dataPoints_dirtyOnGpu) {
                        gpuEmxMemcpyGpuToCpu_real_T(c_dataPoints,
                          &b_inter_dataPoints);
                        b_dataPoints_dirtyOnGpu = false;
                      }

                      c_dataPoints->data[(qEnd + dataPoints->size[0]) +
                        c_dataPoints->size[0] * kEnd] = newDataPoints->data[qEnd
                        + newDataPoints->size[0] * kEnd];
                      problemDef_cells_dirtyOnCpu = true;
                    }
                  }

                  kEnd = dataPoints->size[0] * dataPoints->size[1];
                  if (b_dataPoints_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_real_T(c_dataPoints,
                      &b_inter_dataPoints);
                    b_dataPoints_dirtyOnGpu = false;
                  }

                  dataPoints->size[0] = c_dataPoints->size[0];
                  dataPoints->size[1] = 2;
                  emxEnsureCapacity_real_T(dataPoints, kEnd);
                  sz_dirtyOnCpu = true;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((c_dataPoints->size[0] * c_dataPoints->size[1] - 1) + 1L),
                    &oc_grid, &oc_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    gpuEmxMemcpyCpuToGpu_real_T(dataPoints, &inter_dataPoints,
                      gpu_dataPoints);
                    if (problemDef_cells_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(c_dataPoints,
                        &b_inter_dataPoints, b_gpu_dataPoints);
                    }

                    ie_reflectivity_calculation_gpu<<<oc_grid, oc_block>>>
                      (b_gpu_dataPoints, gpu_dataPoints);
                    CUDACHECK(cudaGetLastError());
                    sz_dirtyOnCpu = false;
                    dataPoints_dirtyOnGpu = true;
                  }

                  je_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U,
                    1U, 1U)>>>(*gpu_col_data);
                  CUDACHECK(cudaGetLastError());
                  r8_dirtyOnCpu = true;
                  if (dataPoints_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_real_T(dataPoints, &inter_dataPoints);
                    dataPoints_dirtyOnGpu = false;
                  }

                  n = dataPoints->size[0] + 1;
                  if (idx_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_int32_T(idx, &inter_idx);
                    idx_dirtyOnGpu = false;
                  }

                  kEnd = idx->size[0];
                  idx->size[0] = dataPoints->size[0];
                  emxEnsureCapacity_int32_T(idx, kEnd);
                  r1_dirtyOnCpu = true;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((dataPoints->size[0] - 1) + 1L), &pc_grid, &pc_block, 1024U,
                    65535U);
                  if (validLaunchParams) {
                    if (sz_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(dataPoints, &inter_dataPoints,
                        gpu_dataPoints);
                      sz_dirtyOnCpu = false;
                    }

                    gpuEmxMemcpyCpuToGpu_int32_T(idx, &inter_idx, gpu_idx);
                    ke_reflectivity_calculation_gpu<<<pc_grid, pc_block>>>
                      (gpu_dataPoints, gpu_idx);
                    CUDACHECK(cudaGetLastError());
                    r1_dirtyOnCpu = false;
                    idx_dirtyOnGpu = true;
                  }

                  kEnd = iwork->size[0];
                  iwork->size[0] = dataPoints->size[0];
                  emxEnsureCapacity_int32_T(iwork, kEnd);
                  problemDef_cells_dirtyOnCpu = true;
                  kEnd = dataPoints->size[0] - 1;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((kEnd - 1) / 2 + 1L), &qc_grid, &qc_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    if (sz_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(dataPoints, &inter_dataPoints,
                        gpu_dataPoints);
                      sz_dirtyOnCpu = false;
                    }

                    if (r1_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_int32_T(idx, &inter_idx, gpu_idx);
                      r1_dirtyOnCpu = false;
                    }

                    le_reflectivity_calculation_gpu<<<qc_grid, qc_block>>>
                      (*gpu_col_data, gpu_dataPoints, kEnd, gpu_idx);
                    CUDACHECK(cudaGetLastError());
                    idx_dirtyOnGpu = true;
                  }

                  if ((dataPoints->size[0] & 1) != 0) {
                    if (sz_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(dataPoints, &inter_dataPoints,
                        gpu_dataPoints);
                      sz_dirtyOnCpu = false;
                    }

                    if (r1_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_int32_T(idx, &inter_idx, gpu_idx);
                      r1_dirtyOnCpu = false;
                    }

                    me_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U,
                      1U, 1U)>>>(gpu_dataPoints, gpu_idx);
                    CUDACHECK(cudaGetLastError());
                    idx_dirtyOnGpu = true;
                  }

                  c_i = 2;
                  while (c_i < n - 1) {
                    i2 = c_i << 1;
                    j = 1;
                    for (xoffset = c_i + 1; xoffset < n; xoffset = qEnd + c_i) {
                      vstride = j;
                      vlen = xoffset;
                      qEnd = j + i2;
                      if (qEnd > n) {
                        qEnd = n;
                      }

                      k = 0;
                      kEnd = qEnd - j;
                      while (k + 1 <= kEnd) {
                        b_bool = true;
                        nx = 0;
                        exitg2 = false;
                        while ((!exitg2) && (nx + 1 < 3)) {
                          if (r8_dirtyOnCpu) {
                            CUDACHECK(cudaMemcpy(&col_data[0], gpu_col_data, 2U *
                                                 sizeof(int8_T),
                                                 cudaMemcpyDeviceToHost));
                            r8_dirtyOnCpu = false;
                          }

                          if (idx_dirtyOnGpu) {
                            gpuEmxMemcpyGpuToCpu_int32_T(idx, &inter_idx);
                            idx_dirtyOnGpu = false;
                          }

                          layerThicks = dataPoints->data[(idx->data[vstride - 1]
                            + dataPoints->size[0] * (col_data[nx] - 1)) - 1];
                          bFactor = dataPoints->data[(idx->data[vlen - 1] +
                            dataPoints->size[0] * (col_data[nx] - 1)) - 1];
                          if ((layerThicks == bFactor) || (rtIsNaN(layerThicks) &&
                               rtIsNaN(bFactor))) {
                            nx++;
                          } else {
                            if ((!(layerThicks <= bFactor)) && (!rtIsNaN(bFactor)))
                            {
                              b_bool = false;
                            }

                            exitg2 = true;
                          }
                        }

                        if (b_bool) {
                          if (idx_dirtyOnGpu) {
                            gpuEmxMemcpyGpuToCpu_int32_T(idx, &inter_idx);
                            idx_dirtyOnGpu = false;
                          }

                          iwork->data[k] = idx->data[vstride - 1];
                          problemDef_cells_dirtyOnCpu = true;
                          vstride++;
                          if (vstride == xoffset) {
                            while (vlen < qEnd) {
                              k++;
                              iwork->data[k] = idx->data[vlen - 1];
                              vlen++;
                            }
                          }
                        } else {
                          if (idx_dirtyOnGpu) {
                            gpuEmxMemcpyGpuToCpu_int32_T(idx, &inter_idx);
                            idx_dirtyOnGpu = false;
                          }

                          iwork->data[k] = idx->data[vlen - 1];
                          problemDef_cells_dirtyOnCpu = true;
                          vlen++;
                          if (vlen == qEnd) {
                            while (vstride < xoffset) {
                              k++;
                              iwork->data[k] = idx->data[vstride - 1];
                              vstride++;
                            }
                          }
                        }

                        k++;
                      }

                      validLaunchParams = mwGetLaunchParameters
                        (static_cast<real_T>((kEnd - 1) + 1L), &tc_grid,
                         &tc_block, 1024U, 65535U);
                      if (validLaunchParams) {
                        if (r1_dirtyOnCpu) {
                          gpuEmxMemcpyCpuToGpu_int32_T(idx, &inter_idx, gpu_idx);
                          r1_dirtyOnCpu = false;
                        }

                        if (problemDef_cells_dirtyOnCpu) {
                          gpuEmxMemcpyCpuToGpu_int32_T(iwork, &inter_iwork,
                            gpu_iwork);
                          problemDef_cells_dirtyOnCpu = false;
                        }

                        pe_reflectivity_calculation_gpu<<<tc_grid, tc_block>>>
                          (gpu_iwork, j, kEnd, gpu_idx);
                        CUDACHECK(cudaGetLastError());
                        idx_dirtyOnGpu = true;
                      }

                      j = qEnd;
                    }

                    c_i = i2;
                  }

                  xoffset = dataPoints->size[0];
                  xoffset_dirtyOnCpu = true;
                  if (ycol_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_real_T(ycol, &inter_ycol);
                    ycol_dirtyOnGpu = false;
                  }

                  kEnd = ycol->size[0];
                  ycol->size[0] = dataPoints->size[0];
                  emxEnsureCapacity_real_T(ycol, kEnd);
                  problemDef_cells_dirtyOnCpu = true;
                  for (j = 0; j < 2; j++) {
                    validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                      ((xoffset - 1) + 1L), &rc_grid, &rc_block, 1024U, 65535U);
                    if (validLaunchParams) {
                      if (xoffset_dirtyOnCpu) {
                        CUDACHECK(cudaMemcpy(gpu_xoffset, &xoffset, 4UL,
                                             cudaMemcpyHostToDevice));
                        xoffset_dirtyOnCpu = false;
                      }

                      if (sz_dirtyOnCpu) {
                        gpuEmxMemcpyCpuToGpu_real_T(dataPoints,
                          &inter_dataPoints, gpu_dataPoints);
                        sz_dirtyOnCpu = false;
                      }

                      if (r1_dirtyOnCpu) {
                        gpuEmxMemcpyCpuToGpu_int32_T(idx, &inter_idx, gpu_idx);
                        r1_dirtyOnCpu = false;
                      }

                      if (problemDef_cells_dirtyOnCpu) {
                        gpuEmxMemcpyCpuToGpu_real_T(ycol, &inter_ycol, gpu_ycol);
                        problemDef_cells_dirtyOnCpu = false;
                      }

                      ne_reflectivity_calculation_gpu<<<rc_grid, rc_block>>>(j,
                        gpu_dataPoints, gpu_idx, gpu_xoffset, gpu_ycol);
                      CUDACHECK(cudaGetLastError());
                      ycol_dirtyOnGpu = true;
                    }

                    validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                      ((xoffset - 1) + 1L), &sc_grid, &sc_block, 1024U, 65535U);
                    if (validLaunchParams) {
                      if (xoffset_dirtyOnCpu) {
                        CUDACHECK(cudaMemcpy(gpu_xoffset, &xoffset, 4UL,
                                             cudaMemcpyHostToDevice));
                        xoffset_dirtyOnCpu = false;
                      }

                      if (sz_dirtyOnCpu) {
                        gpuEmxMemcpyCpuToGpu_real_T(dataPoints,
                          &inter_dataPoints, gpu_dataPoints);
                        sz_dirtyOnCpu = false;
                      }

                      if (problemDef_cells_dirtyOnCpu) {
                        gpuEmxMemcpyCpuToGpu_real_T(ycol, &inter_ycol, gpu_ycol);
                        problemDef_cells_dirtyOnCpu = false;
                      }

                      oe_reflectivity_calculation_gpu<<<sc_grid, sc_block>>>
                        (gpu_ycol, j, gpu_xoffset, gpu_dataPoints);
                      CUDACHECK(cudaGetLastError());
                      dataPoints_dirtyOnGpu = true;
                    }
                  }

                  //    else
                  //      break;
                }

                //  Removed waitbar for compile - AVH
                //    if displayWaitbar
                //      if getappdata(refinementWaitbar,'canceling'), break; end 
                //      waitbar(nRefinements/maxRefinements,refinementWaitbar);
                //    end
              }

              //  if displayWaitbar
              //    delete(refinementWaitbar);
              //  end
              //  Plotting refined function
              //  Removed for compile - AVH
              //  if nargin==0 % test mode
              //    figure(testFigureHandle);
              //    hold on;
              //    plot(dataPoints(:,1), dataPoints(:,2),'ro-');
              //    legend('initial', 'refiniment');
              //  end
              kEnd = layers->size[0] * layers->size[1];
              if (dataPoints_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(dataPoints, &inter_dataPoints);
              }

              layers->size[0] = dataPoints->size[0] - 1;
              layers->size[1] = 3;
              emxEnsureCapacity_real_T(layers, kEnd);
              problemDef_cells_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                (((dataPoints->size[0] - 1) * 3 - 1) + 1L), &uc_grid, &uc_block,
                1024U, 65535U);
              if (validLaunchParams) {
                gpuEmxMemcpyCpuToGpu_real_T(layers, &inter_layers, gpu_layers);
                if (sz_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(dataPoints, &inter_dataPoints,
                    gpu_dataPoints);
                  sz_dirtyOnCpu = false;
                }

                qe_reflectivity_calculation_gpu<<<uc_grid, uc_block>>>
                  (gpu_dataPoints, gpu_layers);
                CUDACHECK(cudaGetLastError());
                problemDef_cells_dirtyOnCpu = false;
                layers_dirtyOnGpu = true;
              }

              //  Now build a layer model from these resampled points
              kEnd = dataPoints->size[0] - 1;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((kEnd - 1) + 1L), &vc_grid, &vc_block, 1024U, 65535U);
              if (validLaunchParams) {
                if (problemDef_cells_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(layers, &inter_layers, gpu_layers);
                }

                if (sz_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(dataPoints, &inter_dataPoints,
                    gpu_dataPoints);
                }

                re_reflectivity_calculation_gpu<<<vc_grid, vc_block>>>
                  (gpu_dataPoints, kEnd, gpu_layers);
                CUDACHECK(cudaGetLastError());
                layers_dirtyOnGpu = true;
              }
            } else {
              kEnd = layers->size[0] * layers->size[1];
              layers->size[0] = 2;
              layers->size[1] = 3;
              emxEnsureCapacity_real_T(layers, kEnd);
              gpuEmxMemcpyCpuToGpu_real_T(layers, &inter_layers, gpu_layers);
              hc_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(*gpu_layers_data, gpu_layers);
              CUDACHECK(cudaGetLastError());
              layers_dirtyOnGpu = true;
            }

            //  Apply scale factors and q shifts to the data
            layerThicks = sf;
            b_dirtyOnCpu = true;

            // Shifts the data according to scale factor
            //  scalefac = problem.scalefactors;
            //  horshift = problem.qshifts;
            //  numberOfContrasts = problem.numberOfContrasts;
            //  dataPresent = problem.dataPresent;
            //  allData = problem.data;
            //  dataLimits = problem.dataLimits;
            // shifted_data = cell(1,numberOfContrasts);
            switch (static_cast<int32_T>(problemDef->dataPresent[b_i])) {
             case 1:
              if (sf == 0.0) {
                layerThicks = 1.0E-30;
              }

              bFactor = problemDef_cells->f3[b_i].f1[0];
              CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                   cudaMemcpyHostToDevice));
              b_dirtyOnCpu = false;
              te_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(64U, 1U,
                1U)>>>(bFactor, gpu_layerThicks, shifts, gpu_problemDef_cells,
                       b_i, *j_gpu_x, *gpu_thisData);
              CUDACHECK(cudaGetLastError());
              problemDef_cells_dirtyOnCpu = true;
              vlen = 0;
              xoffset = 1;
              exitg2 = false;
              while ((!exitg2) && (xoffset < 52)) {
                if (problemDef_cells_dirtyOnCpu) {
                  CUDACHECK(cudaMemcpy(&u_x[0], j_gpu_x, 51UL,
                                       cudaMemcpyDeviceToHost));
                  problemDef_cells_dirtyOnCpu = false;
                }

                if (u_x[xoffset - 1]) {
                  vlen++;
                  ii_data[vlen - 1] = static_cast<int8_T>(xoffset);
                  if (vlen >= 51) {
                    exitg2 = true;
                  } else {
                    xoffset++;
                  }
                } else {
                  xoffset++;
                }
              }

              if (1 > vlen) {
                kEnd = 0;
              } else {
                kEnd = vlen;
              }

              if (kEnd != 0) {
                vstride = ii_data[kEnd - 1];
              } else {
                vstride = 1;
              }

              ue_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(64U, 1U,
                1U)>>>(problemDef_cells->f3[b_i].f1[1], *gpu_thisData, *j_gpu_x);
              CUDACHECK(cudaGetLastError());
              problemDef_cells_dirtyOnCpu = true;
              vlen = 0;
              xoffset = 1;
              exitg2 = false;
              while ((!exitg2) && (xoffset < 52)) {
                if (problemDef_cells_dirtyOnCpu) {
                  CUDACHECK(cudaMemcpy(&u_x[0], j_gpu_x, 51UL,
                                       cudaMemcpyDeviceToHost));
                  problemDef_cells_dirtyOnCpu = false;
                }

                if (u_x[xoffset - 1]) {
                  vlen++;
                  ii_data[vlen - 1] = static_cast<int8_T>(xoffset);
                  if (vlen >= 51) {
                    exitg2 = true;
                  } else {
                    xoffset++;
                  }
                } else {
                  xoffset++;
                }
              }

              if (1 > vlen) {
                kEnd = 0;
              } else {
                kEnd = vlen;
              }

              if (kEnd != 0) {
                xoffset = ii_data[0];
              } else {
                xoffset = 51;
              }

              if (vstride > xoffset) {
                kEnd = 0;
                qEnd = -1;
              } else {
                kEnd = vstride - 1;
                qEnd = xoffset - 1;
              }

              shifted_dat_size[0] = (qEnd - kEnd) + 1;
              shifted_dat_size[1] = 3;
              r1_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                (((qEnd - kEnd) + 1L) * 3L), &wc_grid, &wc_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL,
                                     cudaMemcpyHostToDevice));
                CUDACHECK(cudaMemcpy(gpu_shifted_dat_size, &shifted_dat_size[0],
                                     8UL, cudaMemcpyHostToDevice));
                r1_dirtyOnCpu = false;
                ve_reflectivity_calculation_gpu<<<wc_grid, wc_block>>>
                  (*gpu_thisData, *gpu_shifted_dat_size, kEnd, gpu_qEnd,
                   *gpu_shifted_dat_data);
                CUDACHECK(cudaGetLastError());
                shifted_dat_data_dirtyOnGpu = true;
              }
              break;

             default:
              shifted_dat_size[0] = 51;
              shifted_dat_size[1] = 3;
              r1_dirtyOnCpu = true;
              se_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(160U, 1U,
                1U)>>>(gpu_problemDef_cells, b_i, *gpu_shifted_dat_data);
              CUDACHECK(cudaGetLastError());
              shifted_dat_data_dirtyOnGpu = true;
              break;
            }

            //  function Ref = makeFresnelData(problem,contrast)
            //
            //      this_data = problem.shifted_data{contrast};
            //      xdata = this_data(:,1);
            //      nbair = problem.nbairs(contrast);
            //      nbsub = problem.nbsubs(contrast);
            //      slds = [0 0 0];
            //      resol = problem.resolution;
            //      resolType = problem.resolType;
            //      %abeles(xdata,SLDs,nbair,nbsub,ssub,nrepeats,sinter,resol)
            //      %Ref = abeles_new_2(xdata,slds,nbair,nbsub,s_sub,repeats,
            //      Ref = abeles_new_2(xdata,slds,nbair,nbsub,0,1,resolType,resol); 
            //  Calculate the reflectivity
            //  nbairs = problem.nbairs;
            //  nbsubs = problem.nbsubs;
            //  simLimits = problem.simLimits;
            //  repeatLayers = problem.repeatLayers;
            //  allData = problem.shifted_data;
            //  layers = problem.layers;
            //  ssubs = problem.ssubs;
            //  numberOfContrasts = problem.numberOfContrasts;
            //  reflectivity = cell(numberOfContrasts,1);
            //  Simulation = cell(numberOfContrasts,1);
            //
            //  parfor i = 1:numberOfContrasts
            // this_data = allData{i};
            if (layers_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(layers, &inter_layers);
              layers_dirtyOnGpu = false;
            }

            i2 = layers->size[0] - 1;
            if (shifted_dat_data_dirtyOnGpu) {
              CUDACHECK(cudaMemcpy(&shifted_dat_data[0], gpu_shifted_dat_data,
                                   shifted_dat_size[0] * shifted_dat_size[1] *
                                   sizeof(real_T), cudaMemcpyDeviceToHost));
              shifted_dat_data_dirtyOnGpu = false;
            }

            if (problemDef_cells->f4[b_i].f1[0] < shifted_dat_data[0]) {
              reps = shifted_dat_data[1] - shifted_dat_data[0];
              bFactor = shifted_dat_data[0] - reps;
              if (rtIsNaN(problemDef_cells->f4[b_i].f1[0]) || rtIsNaN(reps) ||
                  rtIsNaN(bFactor)) {
                kEnd = firstSection->size[0] * firstSection->size[1];
                firstSection->size[0] = 1;
                firstSection->size[1] = 1;
                emxEnsureCapacity_real_T(firstSection, kEnd);
                firstSection->data[0] = rtNaN;
                problemDef_cells_dirtyOnCpu = true;
              } else if ((reps == 0.0) || ((problemDef_cells->f4[b_i].f1[0] <
                           bFactor) && (reps < 0.0)) || ((bFactor <
                           problemDef_cells->f4[b_i].f1[0]) && (reps > 0.0))) {
                firstSection->size[0] = 1;
                firstSection->size[1] = 0;
                problemDef_cells_dirtyOnCpu = true;
              } else if ((rtIsInf(problemDef_cells->f4[b_i].f1[0]) || rtIsInf
                          (bFactor)) && (rtIsInf(reps) || (problemDef_cells->
                           f4[b_i].f1[0] == bFactor))) {
                kEnd = firstSection->size[0] * firstSection->size[1];
                firstSection->size[0] = 1;
                firstSection->size[1] = 1;
                emxEnsureCapacity_real_T(firstSection, kEnd);
                firstSection->data[0] = rtNaN;
                problemDef_cells_dirtyOnCpu = true;
              } else if (rtIsInf(reps)) {
                kEnd = firstSection->size[0] * firstSection->size[1];
                firstSection->size[0] = 1;
                firstSection->size[1] = 1;
                emxEnsureCapacity_real_T(firstSection, kEnd);
                firstSection->data[0] = problemDef_cells->f4[b_i].f1[0];
                problemDef_cells_dirtyOnCpu = true;
              } else if ((floor(problemDef_cells->f4[b_i].f1[0]) ==
                          problemDef_cells->f4[b_i].f1[0]) && (floor(reps) ==
                          reps)) {
                layerThicks = problemDef_cells->f4[b_i].f1[0];
                b_dirtyOnCpu = true;
                kEnd = firstSection->size[0] * firstSection->size[1];
                firstSection->size[0] = 1;
                firstSection->size[1] = static_cast<int32_T>(floor((bFactor -
                  problemDef_cells->f4[b_i].f1[0]) / reps)) + 1;
                emxEnsureCapacity_real_T(firstSection, kEnd);
                problemDef_cells_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>(
                  static_cast<int32_T>((bFactor - layerThicks) / reps) + 1L),
                  &xc_grid, &xc_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                       cudaMemcpyHostToDevice));
                  b_dirtyOnCpu = false;
                  gpuEmxMemcpyCpuToGpu_real_T(firstSection, &inter_firstSection,
                    gpu_firstSection);
                  we_reflectivity_calculation_gpu<<<xc_grid, xc_block>>>(reps,
                    gpu_layerThicks, bFactor, gpu_firstSection);
                  CUDACHECK(cudaGetLastError());
                  problemDef_cells_dirtyOnCpu = false;
                  firstSection_dirtyOnGpu = true;
                }
              } else {
                layerThicks = floor((bFactor - problemDef_cells->f4[b_i].f1[0]) /
                                    reps + 0.5);
                b_dirtyOnCpu = true;
                nextLayRough = problemDef_cells->f4[b_i].f1[0] + layerThicks *
                  reps;
                if (reps > 0.0) {
                  l = nextLayRough - bFactor;
                } else {
                  l = bFactor - nextLayRough;
                }

                thisBoxCentre = fabs(problemDef_cells->f4[b_i].f1[0]);
                pair_im = fabs(bFactor);
                if ((thisBoxCentre > pair_im) || rtIsNaN(pair_im)) {
                  pair_im = thisBoxCentre;
                }

                if (fabs(l) < 4.4408920985006262E-16 * pair_im) {
                  layerThicks++;
                  nextLayRough = bFactor;
                } else if (l > 0.0) {
                  nextLayRough = problemDef_cells->f4[b_i].f1[0] + (layerThicks
                    - 1.0) * reps;
                } else {
                  layerThicks++;
                }

                if (layerThicks >= 0.0) {
                  n = static_cast<int32_T>(layerThicks);
                } else {
                  n = 0;
                }

                kEnd = firstSection->size[0] * firstSection->size[1];
                firstSection->size[0] = 1;
                firstSection->size[1] = n;
                emxEnsureCapacity_real_T(firstSection, kEnd);
                problemDef_cells_dirtyOnCpu = true;
                if (n > 0) {
                  firstSection->data[0] = problemDef_cells->f4[b_i].f1[0];
                  if (n > 1) {
                    firstSection->data[n - 1] = nextLayRough;
                    xoffset = (n - 1) / 2;
                    for (k = 0; k <= xoffset - 2; k++) {
                      layerThicks = (static_cast<real_T>(k) + 1.0) * reps;
                      firstSection->data[k + 1] = problemDef_cells->f4[b_i].f1[0]
                        + layerThicks;
                      firstSection->data[(n - k) - 2] = nextLayRough -
                        layerThicks;
                    }

                    if (xoffset << 1 == n - 1) {
                      firstSection->data[xoffset] = (problemDef_cells->f4[b_i].
                        f1[0] + nextLayRough) / 2.0;
                    } else {
                      layerThicks = static_cast<real_T>(xoffset) * reps;
                      firstSection->data[xoffset] = problemDef_cells->f4[b_i]
                        .f1[0] + layerThicks;
                      firstSection->data[xoffset + 1] = nextLayRough -
                        layerThicks;
                    }
                  }
                }
              }
            } else {
              firstSection->size[0] = 1;
              firstSection->size[1] = 0;
              problemDef_cells_dirtyOnCpu = true;
            }

            if (problemDef_cells->f4[b_i].f1[1] >
                shifted_dat_data[shifted_dat_size[0] - 1]) {
              reps = shifted_dat_data[shifted_dat_size[0] - 1] -
                shifted_dat_data[shifted_dat_size[0] - 2];
              g_a = shifted_dat_data[shifted_dat_size[0] - 1] + reps;
              if (rtIsNaN(g_a) || rtIsNaN(reps) || rtIsNaN(problemDef_cells->
                   f4[b_i].f1[1])) {
                kEnd = lastSection->size[0] * lastSection->size[1];
                lastSection->size[0] = 1;
                lastSection->size[1] = 1;
                emxEnsureCapacity_real_T(lastSection, kEnd);
                lastSection->data[0] = rtNaN;
              } else if ((reps == 0.0) || ((g_a < problemDef_cells->f4[b_i].f1[1])
                          && (reps < 0.0)) || ((problemDef_cells->f4[b_i].f1[1] <
                g_a) && (reps > 0.0))) {
                lastSection->size[0] = 1;
                lastSection->size[1] = 0;
              } else if ((rtIsInf(g_a) || rtIsInf(problemDef_cells->f4[b_i].f1[1]))
                         && (rtIsInf(reps) || (g_a == problemDef_cells->f4[b_i].
                           f1[1]))) {
                kEnd = lastSection->size[0] * lastSection->size[1];
                lastSection->size[0] = 1;
                lastSection->size[1] = 1;
                emxEnsureCapacity_real_T(lastSection, kEnd);
                lastSection->data[0] = rtNaN;
              } else if (rtIsInf(reps)) {
                kEnd = lastSection->size[0] * lastSection->size[1];
                lastSection->size[0] = 1;
                lastSection->size[1] = 1;
                emxEnsureCapacity_real_T(lastSection, kEnd);
                lastSection->data[0] = g_a;
              } else if ((floor(g_a) == g_a) && (floor(reps) == reps)) {
                layerThicks = problemDef_cells->f4[b_i].f1[1];
                b_dirtyOnCpu = true;
                kEnd = lastSection->size[0] * lastSection->size[1];
                lastSection->size[0] = 1;
                lastSection->size[1] = static_cast<int32_T>(floor
                  ((problemDef_cells->f4[b_i].f1[1] - g_a) / reps)) + 1;
                emxEnsureCapacity_real_T(lastSection, kEnd);
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>(
                  static_cast<int32_T>((layerThicks - g_a) / reps) + 1L),
                  &yc_grid, &yc_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                       cudaMemcpyHostToDevice));
                  b_dirtyOnCpu = false;
                  gpuEmxMemcpyCpuToGpu_real_T(lastSection, &inter_lastSection,
                    gpu_lastSection);
                  xe_reflectivity_calculation_gpu<<<yc_grid, yc_block>>>(reps,
                    g_a, gpu_layerThicks, gpu_lastSection);
                  CUDACHECK(cudaGetLastError());
                  lastSection_dirtyOnGpu = true;
                }
              } else {
                layerThicks = floor((problemDef_cells->f4[b_i].f1[1] - g_a) /
                                    reps + 0.5);
                b_dirtyOnCpu = true;
                nextLayRough = g_a + layerThicks * reps;
                if (reps > 0.0) {
                  l = nextLayRough - problemDef_cells->f4[b_i].f1[1];
                } else {
                  l = problemDef_cells->f4[b_i].f1[1] - nextLayRough;
                }

                thisBoxCentre = fabs(g_a);
                pair_im = fabs(problemDef_cells->f4[b_i].f1[1]);
                if ((thisBoxCentre > pair_im) || rtIsNaN(pair_im)) {
                  pair_im = thisBoxCentre;
                }

                if (fabs(l) < 4.4408920985006262E-16 * pair_im) {
                  layerThicks++;
                  nextLayRough = problemDef_cells->f4[b_i].f1[1];
                } else if (l > 0.0) {
                  nextLayRough = g_a + (layerThicks - 1.0) * reps;
                } else {
                  layerThicks++;
                }

                if (layerThicks >= 0.0) {
                  n = static_cast<int32_T>(layerThicks);
                } else {
                  n = 0;
                }

                kEnd = lastSection->size[0] * lastSection->size[1];
                lastSection->size[0] = 1;
                lastSection->size[1] = n;
                emxEnsureCapacity_real_T(lastSection, kEnd);
                if (n > 0) {
                  lastSection->data[0] = g_a;
                  if (n > 1) {
                    lastSection->data[n - 1] = nextLayRough;
                    xoffset = (n - 1) / 2;
                    for (k = 0; k <= xoffset - 2; k++) {
                      layerThicks = (static_cast<real_T>(k) + 1.0) * reps;
                      lastSection->data[k + 1] = g_a + layerThicks;
                      lastSection->data[(n - k) - 2] = nextLayRough -
                        layerThicks;
                    }

                    if (xoffset << 1 == n - 1) {
                      lastSection->data[xoffset] = (g_a + nextLayRough) / 2.0;
                    } else {
                      layerThicks = static_cast<real_T>(xoffset) * reps;
                      lastSection->data[xoffset] = g_a + layerThicks;
                      lastSection->data[xoffset + 1] = nextLayRough -
                        layerThicks;
                    }
                  }
                }
              }
            } else {
              lastSection->size[0] = 1;
              lastSection->size[1] = 0;
            }

            if (firstSection_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(firstSection, &inter_firstSection);
              firstSection_dirtyOnGpu = false;
            }

            xoffset = firstSection->size[1];
            if (lastSection_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(lastSection, &inter_lastSection);
              lastSection_dirtyOnGpu = false;
            }

            vlen = lastSection->size[1];
            nx = shifted_dat_size[0];
            kEnd = simXdata->size[0];
            simXdata->size[0] = (xoffset + shifted_dat_size[0]) + vlen;
            emxEnsureCapacity_real_T(simXdata, kEnd);
            r8_dirtyOnCpu = true;
            vstride = xoffset - 1;
            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
              (vstride + 1L), &ad_grid, &ad_block, 1024U, 65535U);
            if (validLaunchParams) {
              if (problemDef_cells_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(firstSection, &inter_firstSection,
                  gpu_firstSection);
              }

              gpuEmxMemcpyCpuToGpu_real_T(simXdata, &inter_simXdata,
                gpu_simXdata);
              ye_reflectivity_calculation_gpu<<<ad_grid, ad_block>>>
                (gpu_firstSection, vstride, gpu_simXdata);
              CUDACHECK(cudaGetLastError());
              r8_dirtyOnCpu = false;
              simXdata_dirtyOnGpu = true;
            }

            for (kEnd = 0; kEnd < nx; kEnd++) {
              if (simXdata_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(simXdata, &inter_simXdata);
                simXdata_dirtyOnGpu = false;
              }

              simXdata->data[kEnd + xoffset] = shifted_dat_data[kEnd];
              r8_dirtyOnCpu = true;
            }

            for (kEnd = 0; kEnd < vlen; kEnd++) {
              if (simXdata_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(simXdata, &inter_simXdata);
                simXdata_dirtyOnGpu = false;
              }

              simXdata->data[(kEnd + xoffset) + nx] = lastSection->data[kEnd];
              r8_dirtyOnCpu = true;
            }

            sz[0] = firstSection->size[1] + 1U;
            sz[1] = static_cast<uint32_T>(firstSection->size[1]) +
              shifted_dat_size[0];
            sz_dirtyOnCpu = true;
            kEnd = Simul->size[0] * Simul->size[1];
            if (simXdata_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(simXdata, &inter_simXdata);
              simXdata_dirtyOnGpu = false;
            }

            Simul->size[0] = simXdata->size[0];
            Simul->size[1] = 2;
            emxEnsureCapacity_real_T(Simul, kEnd);
            b_bool = true;
            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
              ((simXdata->size[0] * 2 - 1) + 1L), &bd_grid, &bd_block, 1024U,
              65535U);
            if (validLaunchParams) {
              if (r8_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(simXdata, &inter_simXdata,
                  gpu_simXdata);
                r8_dirtyOnCpu = false;
              }

              gpuEmxMemcpyCpuToGpu_real_T(Simul, &inter_Simul, gpu_Simul);
              af_reflectivity_calculation_gpu<<<bd_grid, bd_block>>>
                (gpu_simXdata, gpu_Simul);
              CUDACHECK(cudaGetLastError());
              b_bool = false;
              Simul_dirtyOnGpu = true;
            }

            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
              ((simXdata->size[0] - 1) + 1L), &cd_grid, &cd_block, 1024U, 65535U);
            if (validLaunchParams) {
              if (r8_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(simXdata, &inter_simXdata,
                  gpu_simXdata);
                r8_dirtyOnCpu = false;
              }

              if (b_bool) {
                gpuEmxMemcpyCpuToGpu_real_T(Simul, &inter_Simul, gpu_Simul);
                b_bool = false;
              }

              bf_reflectivity_calculation_gpu<<<cd_grid, cd_block>>>
                (gpu_simXdata, gpu_Simul);
              CUDACHECK(cudaGetLastError());
              Simul_dirtyOnGpu = true;
            }

            //  Single cored over points
            //  nbair = nbairs(thisCont);
            //  nbsub = nbsubs(thisCont);
            //  ssub = ssubs(thisCont);
            //  nrepeats = nrepeatss(thisCont);
            //  resol = resols(thisCont);
            // pi = 3.141592653589;
            snair = 1.0 - nba * 0.377451863036739;
            snsub = 1.0 - problemDef->nbs[static_cast<int32_T>
              (problemDef->contrastNbss[b_i]) - 1] * 0.377451863036739;
            kEnd = simXdata->size[0] - 1;
            qEnd = simRef->size[0];
            simRef->size[0] = simXdata->size[0];
            emxEnsureCapacity_real_T(simRef, qEnd);
            for (xoffset = 0; xoffset <= kEnd; xoffset++) {
              real_T theta;
              real_T psub_re;
              real_T yi;
              real_T yr;
              real_T blast_re;
              real_T blast_im;
              real_T ar;
              theta = asin(simXdata->data[xoffset] * 1.54 / 12.566370614359172);
              layerThicks = cos(theta);
              psub_re = snsub * snsub - snair * snair * (layerThicks *
                layerThicks);
              if ((snsub * snsub - snair * snair * (layerThicks * layerThicks)) *
                  0.0 == 0.0) {
                if (psub_re < 0.0) {
                  yr = 0.0;
                  yi = sqrt(-psub_re);
                } else {
                  yr = sqrt(psub_re);
                  yi = 0.0;
                }
              } else if (psub_re == 0.0) {
                yr = rtNaN;
                yi = rtNaN;
              } else if (rtIsNaN(psub_re)) {
                yr = psub_re;
                yi = psub_re;
              } else {
                yr = rtNaN;
                yi = rtNaN;
              }

              psub_re = yr;
              reps = snair * sin(theta);
              pair_im = snair * sin(theta) * 0.0;
              blast_re = 0.0;
              blast_im = 0.0;
              cf_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(*gpu_MI);
              CUDACHECK(cudaGetLastError());
              qEnd = static_cast<int32_T>(problemDef_cells->f1[b_i].f1[1]) - 1;
              for (vstride = 0; vstride <= qEnd; vstride++) {
                for (nx = 0; nx <= i2; nx++) {
                  real_T pimag_re;
                  l = layers->data[nx + (layers->size[0] << 1)];
                  bFactor = 1.0 - layers->data[nx + layers->size[0]] *
                    0.377451863036739;
                  layerThicks = cos(theta);
                  pimag_re = bFactor * bFactor - snair * snair * (layerThicks *
                    layerThicks);
                  if ((bFactor * bFactor - snair * snair * (layerThicks *
                        layerThicks)) * 0.0 == 0.0) {
                    if (pimag_re < 0.0) {
                      yr = 0.0;
                      pimag_re = sqrt(-pimag_re);
                    } else {
                      yr = sqrt(pimag_re);
                      pimag_re = 0.0;
                    }
                  } else if (pimag_re == 0.0) {
                    yr = rtNaN;
                    pimag_re = rtNaN;
                  } else if (rtIsNaN(pimag_re)) {
                    yr = pimag_re;
                  } else {
                    yr = rtNaN;
                    pimag_re = rtNaN;
                  }

                  layerThicks = -78.956835208714864 * reps;
                  bFactor = -78.956835208714864 * pair_im;
                  ar = (layerThicks * yr - bFactor * pimag_re) * (l * l);
                  l = (layerThicks * pimag_re + bFactor * yr) * (l * l);
                  if (l == 0.0) {
                    thisBoxCentre = ar / 2.3716;
                    g_a = 0.0;
                  } else if (ar == 0.0) {
                    thisBoxCentre = 0.0;
                    g_a = l / 2.3716;
                  } else {
                    thisBoxCentre = ar / 2.3716;
                    g_a = l / 2.3716;
                  }

                  if (g_a == 0.0) {
                    thisBoxCentre = exp(thisBoxCentre);
                    g_a = 0.0;
                  } else if (rtIsInf(g_a) && rtIsInf(thisBoxCentre) &&
                             (thisBoxCentre < 0.0)) {
                    thisBoxCentre = 0.0;
                    g_a = 0.0;
                  } else {
                    b_r = exp(thisBoxCentre / 2.0);
                    thisBoxCentre = b_r * (b_r * cos(g_a));
                    g_a = b_r * (b_r * sin(g_a));
                  }

                  ar = reps - yr;
                  l = pair_im - pimag_re;
                  layerThicks = reps + yr;
                  bFactor = pair_im + pimag_re;
                  if (bFactor == 0.0) {
                    if (l == 0.0) {
                      reps = ar / layerThicks;
                      pair_im = 0.0;
                    } else if (ar == 0.0) {
                      reps = 0.0;
                      pair_im = l / layerThicks;
                    } else {
                      reps = ar / layerThicks;
                      pair_im = l / layerThicks;
                    }
                  } else if (layerThicks == 0.0) {
                    if (ar == 0.0) {
                      reps = l / bFactor;
                      pair_im = 0.0;
                    } else if (l == 0.0) {
                      reps = 0.0;
                      pair_im = -(ar / bFactor);
                    } else {
                      reps = l / bFactor;
                      pair_im = -(ar / bFactor);
                    }
                  } else {
                    b_r = fabs(layerThicks);
                    reps = fabs(bFactor);
                    if (b_r > reps) {
                      nextLayRough = bFactor / layerThicks;
                      layerThicks += nextLayRough * bFactor;
                      reps = (ar + nextLayRough * l) / layerThicks;
                      pair_im = (l - nextLayRough * ar) / layerThicks;
                    } else if (reps == b_r) {
                      if (layerThicks > 0.0) {
                        nextLayRough = 0.5;
                      } else {
                        nextLayRough = -0.5;
                      }

                      if (bFactor > 0.0) {
                        layerThicks = 0.5;
                      } else {
                        layerThicks = -0.5;
                      }

                      reps = (ar * nextLayRough + l * layerThicks) / b_r;
                      pair_im = (l * nextLayRough - ar * layerThicks) / b_r;
                    } else {
                      nextLayRough = layerThicks / bFactor;
                      layerThicks = bFactor + nextLayRough * layerThicks;
                      reps = (nextLayRough * ar + l) / layerThicks;
                      pair_im = (nextLayRough * l - ar) / layerThicks;
                    }
                  }

                  nextLayRough = reps * thisBoxCentre - pair_im * g_a;
                  layerThicks = reps * g_a + pair_im * thisBoxCentre;
                  bFactor = blast_re * 0.0 - blast_im;
                  l = blast_re + blast_im * 0.0;
                  if (l == 0.0) {
                    bFactor = exp(bFactor);
                  } else if (rtIsInf(l) && rtIsInf(bFactor) && (bFactor < 0.0))
                  {
                    bFactor = 0.0;
                    l = 0.0;
                  } else {
                    b_r = exp(bFactor / 2.0);
                    bFactor = b_r * (b_r * cos(l));
                    l = b_r * (b_r * sin(l));
                  }

                  if (N_dirtyOnGpu) {
                    CUDACHECK(cudaMemcpy(&N[0], gpu_N, 64UL,
                                         cudaMemcpyDeviceToHost));
                  }

                  N[0].re = bFactor;
                  N[0].im = l;
                  bFactor = -blast_re * 0.0 - (-blast_im);
                  l = -blast_re + -blast_im * 0.0;
                  if (l == 0.0) {
                    bFactor = exp(bFactor);
                    l = 0.0;
                  } else if (rtIsInf(l) && rtIsInf(bFactor) && (bFactor < 0.0))
                  {
                    bFactor = 0.0;
                    l = 0.0;
                  } else {
                    b_r = exp(bFactor / 2.0);
                    bFactor = b_r * (b_r * cos(l));
                    l = b_r * (b_r * sin(l));
                  }

                  N[1].re = nextLayRough * bFactor - layerThicks * l;
                  N[1].im = nextLayRough * l + layerThicks * bFactor;
                  bFactor = -blast_re * 0.0 - (-blast_im);
                  l = -blast_re + -blast_im * 0.0;
                  if (l == 0.0) {
                    bFactor = exp(bFactor);
                    l = 0.0;
                  } else if (rtIsInf(l) && rtIsInf(bFactor) && (bFactor < 0.0))
                  {
                    bFactor = 0.0;
                    l = 0.0;
                  } else {
                    b_r = exp(bFactor / 2.0);
                    bFactor = b_r * (b_r * cos(l));
                    l = b_r * (b_r * sin(l));
                  }

                  N[3].re = bFactor;
                  N[3].im = l;
                  bFactor = blast_re * 0.0 - blast_im;
                  l = blast_re + blast_im * 0.0;
                  if (l == 0.0) {
                    bFactor = exp(bFactor);
                  } else if (rtIsInf(l) && rtIsInf(bFactor) && (bFactor < 0.0))
                  {
                    bFactor = 0.0;
                    l = 0.0;
                  } else {
                    b_r = exp(bFactor / 2.0);
                    bFactor = b_r * (b_r * cos(l));
                    l = b_r * (b_r * sin(l));
                  }

                  CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                       cudaMemcpyHostToDevice));
                  CUDACHECK(cudaMemcpy(gpu_N, &N[0], 64UL,
                                       cudaMemcpyHostToDevice));
                  df_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U,
                    1U, 1U)>>>(l, gpu_layerThicks, bFactor, nextLayRough, *gpu_N);
                  CUDACHECK(cudaGetLastError());
                  N_dirtyOnGpu = true;
                  reps = yr;
                  pair_im = pimag_re;
                  blast_re = 4.0799904592075231 * layers->data[nx] * yr;
                  blast_im = 4.0799904592075231 * layers->data[nx] * pimag_re;
                  ef_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U,
                    1U, 1U)>>>(*gpu_N, *gpu_MI, *b_gpu_MI);
                  CUDACHECK(cudaGetLastError());
                  ff_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U,
                    1U, 1U)>>>(*b_gpu_MI, *gpu_MI);
                  CUDACHECK(cudaGetLastError());
                }
              }

              layerThicks = -78.956835208714864 * reps;
              bFactor = -78.956835208714864 * pair_im;
              ar = (layerThicks * psub_re - bFactor * yi) * (s_sub * s_sub);
              l = (layerThicks * yi + bFactor * psub_re) * (s_sub * s_sub);
              if (l == 0.0) {
                thisBoxCentre = ar / 2.3716;
                g_a = 0.0;
              } else if (ar == 0.0) {
                thisBoxCentre = 0.0;
                g_a = l / 2.3716;
              } else {
                thisBoxCentre = ar / 2.3716;
                g_a = l / 2.3716;
              }

              if (g_a == 0.0) {
                thisBoxCentre = exp(thisBoxCentre);
                g_a = 0.0;
              } else if (rtIsInf(g_a) && rtIsInf(thisBoxCentre) &&
                         (thisBoxCentre < 0.0)) {
                thisBoxCentre = 0.0;
                g_a = 0.0;
              } else {
                b_r = exp(thisBoxCentre / 2.0);
                thisBoxCentre = b_r * (b_r * cos(g_a));
                g_a = b_r * (b_r * sin(g_a));
              }

              ar = reps - psub_re;
              l = pair_im - yi;
              layerThicks = reps + psub_re;
              bFactor = pair_im + yi;
              if (bFactor == 0.0) {
                if (l == 0.0) {
                  reps = ar / layerThicks;
                  pair_im = 0.0;
                } else if (ar == 0.0) {
                  reps = 0.0;
                  pair_im = l / layerThicks;
                } else {
                  reps = ar / layerThicks;
                  pair_im = l / layerThicks;
                }
              } else if (layerThicks == 0.0) {
                if (ar == 0.0) {
                  reps = l / bFactor;
                  pair_im = 0.0;
                } else if (l == 0.0) {
                  reps = 0.0;
                  pair_im = -(ar / bFactor);
                } else {
                  reps = l / bFactor;
                  pair_im = -(ar / bFactor);
                }
              } else {
                b_r = fabs(layerThicks);
                reps = fabs(bFactor);
                if (b_r > reps) {
                  nextLayRough = bFactor / layerThicks;
                  layerThicks += nextLayRough * bFactor;
                  reps = (ar + nextLayRough * l) / layerThicks;
                  pair_im = (l - nextLayRough * ar) / layerThicks;
                } else if (reps == b_r) {
                  if (layerThicks > 0.0) {
                    nextLayRough = 0.5;
                  } else {
                    nextLayRough = -0.5;
                  }

                  if (bFactor > 0.0) {
                    layerThicks = 0.5;
                  } else {
                    layerThicks = -0.5;
                  }

                  reps = (ar * nextLayRough + l * layerThicks) / b_r;
                  pair_im = (l * nextLayRough - ar * layerThicks) / b_r;
                } else {
                  nextLayRough = layerThicks / bFactor;
                  layerThicks = bFactor + nextLayRough * layerThicks;
                  reps = (nextLayRough * ar + l) / layerThicks;
                  pair_im = (nextLayRough * l - ar) / layerThicks;
                }
              }

              nextLayRough = reps * thisBoxCentre - pair_im * g_a;
              layerThicks = reps * g_a + pair_im * thisBoxCentre;
              bFactor = blast_re * 0.0 - blast_im;
              l = blast_re + blast_im * 0.0;
              if (l == 0.0) {
                bFactor = exp(bFactor);
                l = 0.0;
              } else if (rtIsInf(l) && rtIsInf(bFactor) && (bFactor < 0.0)) {
                bFactor = 0.0;
                l = 0.0;
              } else {
                b_r = exp(bFactor / 2.0);
                bFactor = b_r * (b_r * cos(l));
                l = b_r * (b_r * sin(l));
              }

              gf_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(l, bFactor, *gpu_N);
              CUDACHECK(cudaGetLastError());
              bFactor = -blast_re * 0.0 - (-blast_im);
              l = -blast_re + -blast_im * 0.0;
              if (l == 0.0) {
                bFactor = exp(bFactor);
                l = 0.0;
              } else if (rtIsInf(l) && rtIsInf(bFactor) && (bFactor < 0.0)) {
                bFactor = 0.0;
                l = 0.0;
              } else {
                b_r = exp(bFactor / 2.0);
                bFactor = b_r * (b_r * cos(l));
                l = b_r * (b_r * sin(l));
              }

              CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                   cudaMemcpyHostToDevice));
              hf_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(l, gpu_layerThicks, bFactor, nextLayRough, *gpu_N);
              CUDACHECK(cudaGetLastError());
              bFactor = -blast_re * 0.0 - (-blast_im);
              l = -blast_re + -blast_im * 0.0;
              if (l == 0.0) {
                bFactor = exp(bFactor);
                l = 0.0;
              } else if (rtIsInf(l) && rtIsInf(bFactor) && (bFactor < 0.0)) {
                bFactor = 0.0;
                l = 0.0;
              } else {
                b_r = exp(bFactor / 2.0);
                bFactor = b_r * (b_r * cos(l));
                l = b_r * (b_r * sin(l));
              }

              if_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(l, bFactor, *gpu_N);
              CUDACHECK(cudaGetLastError());
              bFactor = blast_re * 0.0 - blast_im;
              l = blast_re + blast_im * 0.0;
              if (l == 0.0) {
                bFactor = exp(bFactor);
                l = 0.0;
              } else if (rtIsInf(l) && rtIsInf(bFactor) && (bFactor < 0.0)) {
                bFactor = 0.0;
                l = 0.0;
              } else {
                b_r = exp(bFactor / 2.0);
                bFactor = b_r * (b_r * cos(l));
                l = b_r * (b_r * sin(l));
              }

              jf_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(l, gpu_layerThicks, bFactor, nextLayRough, *gpu_N);
              CUDACHECK(cudaGetLastError());
              N_dirtyOnGpu = true;
              kf_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(*gpu_N, *gpu_MI, *b_gpu_MI);
              CUDACHECK(cudaGetLastError());
              lf_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(*b_gpu_MI, *gpu_MI);
              CUDACHECK(cudaGetLastError());
              CUDACHECK(cudaMemcpy(&MI[0], gpu_MI, 64UL, cudaMemcpyDeviceToHost));
              l = MI[1].re * MI[1].re - MI[1].im * -MI[1].im;
              thisBoxCentre = MI[1].re * -MI[1].im + MI[1].im * MI[1].re;
              layerThicks = MI[0].re * MI[0].re - MI[0].im * -MI[0].im;
              bFactor = MI[0].re * -MI[0].im + MI[0].im * MI[0].re;
              if (bFactor == 0.0) {
                if (thisBoxCentre == 0.0) {
                  pair_im = l / layerThicks;
                  layerThicks = 0.0;
                  b_dirtyOnCpu = true;
                } else if (l == 0.0) {
                  pair_im = 0.0;
                  layerThicks = thisBoxCentre / layerThicks;
                  b_dirtyOnCpu = true;
                } else {
                  pair_im = l / layerThicks;
                  layerThicks = thisBoxCentre / layerThicks;
                  b_dirtyOnCpu = true;
                }
              } else if (layerThicks == 0.0) {
                if (l == 0.0) {
                  pair_im = thisBoxCentre / bFactor;
                  layerThicks = 0.0;
                  b_dirtyOnCpu = true;
                } else if (thisBoxCentre == 0.0) {
                  pair_im = 0.0;
                  layerThicks = -(l / bFactor);
                  b_dirtyOnCpu = true;
                } else {
                  pair_im = thisBoxCentre / bFactor;
                  layerThicks = -(l / bFactor);
                  b_dirtyOnCpu = true;
                }
              } else {
                b_r = fabs(layerThicks);
                reps = fabs(bFactor);
                if (b_r > reps) {
                  nextLayRough = bFactor / layerThicks;
                  layerThicks += nextLayRough * bFactor;
                  pair_im = (l + nextLayRough * thisBoxCentre) / layerThicks;
                  layerThicks = (thisBoxCentre - nextLayRough * l) / layerThicks;
                  b_dirtyOnCpu = true;
                } else if (reps == b_r) {
                  if (layerThicks > 0.0) {
                    nextLayRough = 0.5;
                  } else {
                    nextLayRough = -0.5;
                  }

                  if (bFactor > 0.0) {
                    layerThicks = 0.5;
                  } else {
                    layerThicks = -0.5;
                  }

                  pair_im = (l * nextLayRough + thisBoxCentre * layerThicks) /
                    b_r;
                  layerThicks = (thisBoxCentre * nextLayRough - l * layerThicks)
                    / b_r;
                  b_dirtyOnCpu = true;
                } else {
                  nextLayRough = layerThicks / bFactor;
                  layerThicks = bFactor + nextLayRough * layerThicks;
                  pair_im = (nextLayRough * l + thisBoxCentre) / layerThicks;
                  layerThicks = (nextLayRough * thisBoxCentre - l) / layerThicks;
                  b_dirtyOnCpu = true;
                }
              }

              simRef->data[xoffset] = rt_hypotd_snf(pair_im, layerThicks);
            }

            xoffset = simXdata->size[0];
            kEnd = dummydata->size[0];
            dummydata->size[0] = simXdata->size[0];
            emxEnsureCapacity_real_T(dummydata, kEnd);
            problemDef_cells_dirtyOnCpu = true;
            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
              ((simXdata->size[0] - 1) + 1L), &dd_grid, &dd_block, 1024U, 65535U);
            if (validLaunchParams) {
              if (r8_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(simXdata, &inter_simXdata,
                  gpu_simXdata);
                r8_dirtyOnCpu = false;
              }

              gpuEmxMemcpyCpuToGpu_real_T(dummydata, &inter_dummydata,
                gpu_dummydata);
              mf_reflectivity_calculation_gpu<<<dd_grid, dd_block>>>
                (gpu_simXdata, gpu_dummydata);
              CUDACHECK(cudaGetLastError());
              problemDef_cells_dirtyOnCpu = false;
              dummydata_dirtyOnGpu = true;
            }

            kEnd = simXdata->size[0];
            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((kEnd
              - 1) + 1L), &ed_grid, &ed_block, 1024U, 65535U);
            if (validLaunchParams) {
              CUDACHECK(cudaMemcpy(gpu_xoffset, &xoffset, 4UL,
                                   cudaMemcpyHostToDevice));
              if (r8_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(simXdata, &inter_simXdata,
                  gpu_simXdata);
              }

              if (problemDef_cells_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(dummydata, &inter_dummydata,
                  gpu_dummydata);
                problemDef_cells_dirtyOnCpu = false;
              }

              gpuEmxMemcpyCpuToGpu_real_T(simRef, &inter_simRef, gpu_simRef);
              nf_reflectivity_calculation_gpu<<<ed_grid, ed_block>>>(gpu_simRef,
                *problemDef, gpu_simXdata, gpu_xoffset, kEnd, gpu_dummydata);
              CUDACHECK(cudaGetLastError());
              dummydata_dirtyOnGpu = true;
            }

            if (dummydata_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(dummydata, &inter_dummydata);
              dummydata_dirtyOnGpu = false;
            }

            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
              ((dummydata->size[0] - 1) + 1L), &fd_grid, &fd_block, 1024U,
              65535U);
            if (validLaunchParams) {
              if (b_bool) {
                gpuEmxMemcpyCpuToGpu_real_T(Simul, &inter_Simul, gpu_Simul);
                b_bool = false;
              }

              if (problemDef_cells_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(dummydata, &inter_dummydata,
                  gpu_dummydata);
              }

              of_reflectivity_calculation_gpu<<<fd_grid, fd_block>>>
                (gpu_dummydata, gpu_Simul);
              CUDACHECK(cudaGetLastError());
              Simul_dirtyOnGpu = true;
            }

            if (sz[0] > sz[1]) {
              kEnd = 0;
              qEnd = -1;
              Lays_dirtyOnCpu = true;
            } else {
              kEnd = static_cast<int32_T>(sz[0]) - 1;
              qEnd = static_cast<int32_T>(sz[1]) - 1;
              Lays_dirtyOnCpu = true;
            }

            xoffset = reflect->size[0] * reflect->size[1];
            reflect->size[0] = (qEnd - kEnd) + 1;
            reflect->size[1] = 2;
            emxEnsureCapacity_real_T(reflect, xoffset);
            r8_dirtyOnCpu = true;
            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>(((qEnd
              - kEnd) + 1L) * 2L), &gd_grid, &gd_block, 1024U, 65535U);
            if (validLaunchParams) {
              CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL, cudaMemcpyHostToDevice));
              Lays_dirtyOnCpu = false;
              if (b_bool) {
                gpuEmxMemcpyCpuToGpu_real_T(Simul, &inter_Simul, gpu_Simul);
                b_bool = false;
              }

              gpuEmxMemcpyCpuToGpu_real_T(reflect, &inter_reflect, gpu_reflect);
              pf_reflectivity_calculation_gpu<<<gd_grid, gd_block>>>(gpu_Simul,
                kEnd, gpu_qEnd, gpu_reflect);
              CUDACHECK(cudaGetLastError());
              r8_dirtyOnCpu = false;
              reflect_dirtyOnGpu = true;
            }

            //  Apply background correction, either to the simulation or the data 
            switch (static_cast<int32_T>(problemDef->contrastBacksType[b_i])) {
             case 1:
              // Add background to the simulation
              layerThicks = problemDef->backs[static_cast<int32_T>
                (problemDef->contrastBacks[b_i]) - 1];
              if (reflect_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(reflect, &inter_reflect);
                reflect_dirtyOnGpu = false;
              }

              xoffset = reflect->size[0] * reflect->size[1];
              reflect->size[0] = (qEnd - kEnd) + 1;
              reflect->size[1] = 2;
              emxEnsureCapacity_real_T(reflect, xoffset);
              r8_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                (((qEnd - kEnd) + 1L) * 2L), &hd_grid, &hd_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                     cudaMemcpyHostToDevice));
                if (Lays_dirtyOnCpu) {
                  CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL,
                                       cudaMemcpyHostToDevice));
                }

                if (b_bool) {
                  gpuEmxMemcpyCpuToGpu_real_T(Simul, &inter_Simul, gpu_Simul);
                }

                gpuEmxMemcpyCpuToGpu_real_T(reflect, &inter_reflect, gpu_reflect);
                qf_reflectivity_calculation_gpu<<<hd_grid, hd_block>>>
                  (gpu_layerThicks, gpu_Simul, kEnd, gpu_qEnd, gpu_reflect);
                CUDACHECK(cudaGetLastError());
                r8_dirtyOnCpu = false;
                reflect_dirtyOnGpu = true;
              }

              if (Simul_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(Simul, &inter_Simul);
                Simul_dirtyOnGpu = false;
              }

              kEnd = Simul->size[0] * Simul->size[1];
              qEnd = Simul->size[0] * Simul->size[1];
              Simul->size[1] = 2;
              emxEnsureCapacity_real_T(Simul, qEnd);
              layerThicks = problemDef->backs[static_cast<int32_T>
                (problemDef->contrastBacks[b_i]) - 1];
              b_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((kEnd - 1) + 1L), &id_grid, &id_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                     cudaMemcpyHostToDevice));
                b_dirtyOnCpu = false;
                gpuEmxMemcpyCpuToGpu_real_T(Simul, &inter_Simul, gpu_Simul);
                rf_reflectivity_calculation_gpu<<<id_grid, id_block>>>
                  (gpu_layerThicks, kEnd, gpu_Simul);
                CUDACHECK(cudaGetLastError());
                Simul_dirtyOnGpu = true;
              }
              break;

             case 2:
              //          %Subtract the background from the data..
              layerThicks = problemDef->backs[static_cast<int32_T>
                (problemDef->contrastBacks[b_i]) - 1];
              b_dirtyOnCpu = true;
              kEnd = shifted_dat_size[0] - 1;
              ii_size[0] = shifted_dat_size[0];
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>(kEnd
                + 1L), &jd_grid, &jd_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                     cudaMemcpyHostToDevice));
                b_dirtyOnCpu = false;
                if (r1_dirtyOnCpu) {
                  CUDACHECK(cudaMemcpy(gpu_shifted_dat_size, &shifted_dat_size[0],
                                       8UL, cudaMemcpyHostToDevice));
                  r1_dirtyOnCpu = false;
                }

                sf_reflectivity_calculation_gpu<<<jd_grid, jd_block>>>
                  (gpu_layerThicks, *gpu_shifted_dat_data, *gpu_shifted_dat_size,
                   kEnd, *gpu_terms_data);
                CUDACHECK(cudaGetLastError());
              }

              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((ii_size[0] - 1) + 1L), &kd_grid, &kd_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_ii_size, &ii_size[0], 4UL,
                                     cudaMemcpyHostToDevice));
                if (r1_dirtyOnCpu) {
                  CUDACHECK(cudaMemcpy(gpu_shifted_dat_size, &shifted_dat_size[0],
                                       8UL, cudaMemcpyHostToDevice));
                  r1_dirtyOnCpu = false;
                }

                tf_reflectivity_calculation_gpu<<<kd_grid, kd_block>>>
                  (*gpu_terms_data, *gpu_shifted_dat_size, *gpu_ii_size,
                   *gpu_shifted_dat_data);
                CUDACHECK(cudaGetLastError());
                shifted_dat_data_dirtyOnGpu = true;
              }

              // shifted_dat(:,3) = shifted_dat(:,3) - backg;
              break;
            }

            //  Calculate chi squared.
            // chi_squared(func,data,numparams,errors)
            // allChis = zeros(1,numberOfContrasts);
            //      thisData = allData{i};
            //      thisFit = allFits{i};
            vstride = shifted_dat_size[0];
            if (shifted_dat_size[0] < 1) {
              vstride = 1;
            }

            if (vstride <= 10) {
              vstride = 11;
            }

            kEnd = shifted_dat_size[0] - 1;
            qEnd = z->size[0];
            z->size[0] = shifted_dat_size[0];
            emxEnsureCapacity_real_T(z, qEnd);
            problemDef_cells_dirtyOnCpu = true;
            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>(kEnd +
              1L), &ld_grid, &ld_block, 1024U, 65535U);
            if (validLaunchParams) {
              if (r1_dirtyOnCpu) {
                CUDACHECK(cudaMemcpy(gpu_shifted_dat_size, &shifted_dat_size[0],
                                     8UL, cudaMemcpyHostToDevice));
              }

              if (r8_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(reflect, &inter_reflect, gpu_reflect);
              }

              gpuEmxMemcpyCpuToGpu_real_T(z, &inter_z, gpu_z);
              uf_reflectivity_calculation_gpu<<<ld_grid, ld_block>>>(gpu_reflect,
                *gpu_shifted_dat_data, *gpu_shifted_dat_size, kEnd, gpu_z);
              CUDACHECK(cudaGetLastError());
              problemDef_cells_dirtyOnCpu = false;
              z_dirtyOnGpu = true;
            }

            kEnd = z1->size[0];
            if (z_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(z, &inter_z);
              z_dirtyOnGpu = false;
            }

            z1->size[0] = z->size[0];
            emxEnsureCapacity_real_T(z1, kEnd);
            xoffset_dirtyOnCpu = true;
            nx = z->size[0];
            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((nx -
              1) + 1L), &md_grid, &md_block, 1024U, 65535U);
            if (validLaunchParams) {
              CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
              if (problemDef_cells_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(z, &inter_z, gpu_z);
              }

              gpuEmxMemcpyCpuToGpu_real_T(z1, &g_inter_z1, g_gpu_z1);
              vf_reflectivity_calculation_gpu<<<md_grid, md_block>>>(gpu_z,
                gpu_nx, g_gpu_z1);
              CUDACHECK(cudaGetLastError());
              xoffset_dirtyOnCpu = false;
              g_z1_dirtyOnGpu = true;
            }

            if (g_z1_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(z1, &g_inter_z1);
              g_z1_dirtyOnGpu = false;
            }

            ii_size[0] = z1->size[0];
            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
              ((z1->size[0] - 1) + 1L), &nd_grid, &nd_block, 1024U, 65535U);
            if (validLaunchParams) {
              if (xoffset_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(z1, &g_inter_z1, g_gpu_z1);
                xoffset_dirtyOnCpu = false;
              }

              wf_reflectivity_calculation_gpu<<<nd_grid, nd_block>>>(g_gpu_z1,
                *gpu_terms_data);
              CUDACHECK(cudaGetLastError());
            }

            kEnd = c_x->size[0];
            c_x->size[0] = z1->size[0];
            emxEnsureCapacity_boolean_T(c_x, kEnd);
            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
              ((z1->size[0] - 1) + 1L), &od_grid, &od_block, 1024U, 65535U);
            if (validLaunchParams) {
              if (xoffset_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(z1, &g_inter_z1, g_gpu_z1);
              }

              gpuEmxMemcpyCpuToGpu_boolean_T(c_x, &j_inter_x, k_gpu_x);
              xf_reflectivity_calculation_gpu<<<od_grid, od_block>>>(g_gpu_z1,
                k_gpu_x);
              CUDACHECK(cudaGetLastError());
              gpuEmxMemcpyGpuToCpu_boolean_T(c_x, &j_inter_x);
            }

            nx = c_x->size[0];
            vlen = 0;
            kEnd = ii->size[0];
            ii->size[0] = c_x->size[0];
            emxEnsureCapacity_int8_T(ii, kEnd);
            xoffset = 1;
            exitg2 = false;
            while ((!exitg2) && (xoffset <= nx)) {
              if (c_x->data[xoffset - 1]) {
                vlen++;
                ii->data[vlen - 1] = static_cast<int8_T>(xoffset);
                if (vlen >= nx) {
                  exitg2 = true;
                } else {
                  xoffset++;
                }
              } else {
                xoffset++;
              }
            }

            if (c_x->size[0] == 1) {
              if (vlen == 0) {
                ii->size[0] = 0;
              }
            } else {
              kEnd = ii->size[0];
              if (1 > vlen) {
                ii->size[0] = 0;
              } else {
                ii->size[0] = vlen;
              }

              emxEnsureCapacity_int8_T(ii, kEnd);
            }

            if (ii->size[0] != 0) {
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((ii->size[0] - 1) + 1L), &pd_grid, &pd_block, 1024U, 65535U);
              if (validLaunchParams) {
                gpuEmxMemcpyCpuToGpu_int8_T(ii, &c_inter_ii, c_gpu_ii);
                yf_reflectivity_calculation_gpu<<<pd_grid, pd_block>>>(c_gpu_ii,
                  *gpu_terms_data);
                CUDACHECK(cudaGetLastError());
              }
            }

            vlen = ii_size[0];
            if (ii_size[0] == 0) {
              layerThicks = 0.0;
            } else {
              if (b_dirtyOnCpu) {
                CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                     cudaMemcpyHostToDevice));
              }

              ag_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(*gpu_terms_data, gpu_layerThicks);
              CUDACHECK(cudaGetLastError());
              layerThicks_dirtyOnGpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((vlen - 2) + 1L), &qd_grid, &qd_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_ii_size, &ii_size[0], 4UL,
                                     cudaMemcpyHostToDevice));
                bg_reflectivity_calculation_gpu<<<qd_grid, qd_block>>>
                  (*gpu_terms_data, vlen, gpu_layerThicks);
                CUDACHECK(cudaGetLastError());
              }
            }

            // allChis(i) = chi2;
            //  Store returned values for this contrast in the output arrays.
            //  As well as the calculated profiles, we also store a record of
            //  the other values (background, scalefactors etc) for each contrast 
            //  for future use.
            outSsubs->data[b_i] = problemDef->params[0];
            kEnd = b_sldProfiles->data[b_i].f1->size[0] * b_sldProfiles->
              data[b_i].f1->size[1];
            if (sldProfile_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(sldProfile, &inter_sldProfile);
              sldProfile_dirtyOnGpu = false;
            }

            b_sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
            b_sldProfiles->data[b_i].f1->size[1] = sldProfile->size[1];
            emxEnsureCapacity_real_T(b_sldProfiles->data[b_i].f1, kEnd);
            for (kEnd = 0; kEnd < sldProfile->size[0] * sldProfile->size[1];
                 kEnd++) {
              b_sldProfiles->data[b_i].f1->data[kEnd] = sldProfile->data[kEnd];
            }

            kEnd = b_reflectivity->data[b_i].f1->size[0] * b_reflectivity->
              data[b_i].f1->size[1];
            if (reflect_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(reflect, &inter_reflect);
              reflect_dirtyOnGpu = false;
            }

            b_reflectivity->data[b_i].f1->size[0] = reflect->size[0];
            b_reflectivity->data[b_i].f1->size[1] = 2;
            emxEnsureCapacity_real_T(b_reflectivity->data[b_i].f1, kEnd);
            for (kEnd = 0; kEnd < reflect->size[0] * reflect->size[1]; kEnd++) {
              b_reflectivity->data[b_i].f1->data[kEnd] = reflect->data[kEnd];
            }

            kEnd = b_Simulation->data[b_i].f1->size[0] * b_Simulation->data[b_i]
              .f1->size[1];
            if (Simul_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(Simul, &inter_Simul);
              Simul_dirtyOnGpu = false;
            }

            b_Simulation->data[b_i].f1->size[0] = Simul->size[0];
            b_Simulation->data[b_i].f1->size[1] = 2;
            emxEnsureCapacity_real_T(b_Simulation->data[b_i].f1, kEnd);
            for (kEnd = 0; kEnd < Simul->size[0] * Simul->size[1]; kEnd++) {
              b_Simulation->data[b_i].f1->data[kEnd] = Simul->data[kEnd];
            }

            kEnd = b_shifted_data->data[b_i].f1->size[0] * b_shifted_data->
              data[b_i].f1->size[1];
            b_shifted_data->data[b_i].f1->size[0] = shifted_dat_size[0];
            b_shifted_data->data[b_i].f1->size[1] = 3;
            emxEnsureCapacity_real_T(b_shifted_data->data[b_i].f1, kEnd);
            for (kEnd = 0; kEnd < shifted_dat_size[0] * 3; kEnd++) {
              if (shifted_dat_data_dirtyOnGpu) {
                CUDACHECK(cudaMemcpy(&shifted_dat_data[0], gpu_shifted_dat_data,
                                     shifted_dat_size[0] * shifted_dat_size[1] *
                                     sizeof(real_T), cudaMemcpyDeviceToHost));
                shifted_dat_data_dirtyOnGpu = false;
              }

              b_shifted_data->data[b_i].f1->data[kEnd] = shifted_dat_data[kEnd];
            }

            kEnd = b_layerSlds->data[b_i].f1->size[0] * b_layerSlds->data[b_i].
              f1->size[1];
            b_layerSlds->data[b_i].f1->size[0] = layers->size[0];
            b_layerSlds->data[b_i].f1->size[1] = 3;
            emxEnsureCapacity_real_T(b_layerSlds->data[b_i].f1, kEnd);
            for (kEnd = 0; kEnd < layers->size[0] * layers->size[1]; kEnd++) {
              b_layerSlds->data[b_i].f1->data[kEnd] = layers->data[kEnd];
            }

            if (layerThicks_dirtyOnGpu) {
              CUDACHECK(cudaMemcpy(&layerThicks, gpu_layerThicks, 8UL,
                                   cudaMemcpyDeviceToHost));
            }

            chis->data[b_i] = 1.0 / (static_cast<real_T>(vstride) - 10.0) *
              layerThicks;
            backgs->data[b_i] = problemDef->backs[static_cast<int32_T>
              (problemDef->contrastBacks[b_i]) - 1];
            qshifts->data[b_i] = shifts;
            sfs->data[b_i] = sf;
            nbas->data[b_i] = nba;
            nbss->data[b_i] = problemDef->nbs[static_cast<int32_T>
              (problemDef->contrastNbss[b_i]) - 1];
            resols->data[b_i] = problemDef->res;
            allRoughs->data[b_i] = problemDef->params[0];
          }

          emxFree_real_T(&c_dataPoints);
          gpuEmxFree_real_T(&b_inter_dataPoints);
          emxFree_boolean_T(&r32);
          gpuEmxFree_boolean_T(&inter_r32);
          emxFree_boolean_T(&c_trianglesToRefine);
          gpuEmxFree_boolean_T(&b_inter_trianglesToRefine);
          emxFree_int32_T(&iwork);
          gpuEmxFree_int32_T(&inter_iwork);
          emxFree_int32_T(&m_ii);
          emxFree_boolean_T(&s_x);
          gpuEmxFree_boolean_T(&i_inter_x);
          emxFree_int32_T(&k_ii);
          emxFree_boolean_T(&q_x);
          gpuEmxFree_boolean_T(&h_inter_x);
          emxFree_int32_T(&i_ii);
          gpuEmxFree_int32_T(&b_inter_ii);
          emxFree_boolean_T(&o_x);
          gpuEmxFree_boolean_T(&g_inter_x);
          emxFree_real_T(&l_z1);
          gpuEmxFree_real_T(&f_inter_z1);
          emxFree_real_T(&j_z1);
          gpuEmxFree_real_T(&e_inter_z1);
          emxFree_real_T(&h_z1);
          gpuEmxFree_real_T(&d_inter_z1);
          emxFree_real_T(&f_z1);
          gpuEmxFree_real_T(&c_inter_z1);
          emxFree_real_T(&d_z1);
          gpuEmxFree_real_T(&b_inter_z1);
          emxFree_real_T(&c_z1);
          gpuEmxFree_real_T(&inter_z1);
          emxFree_real_T(&ycol);
          gpuEmxFree_real_T(&inter_ycol);
          emxFree_int32_T(&g_ii);
          emxFree_boolean_T(&m_x);
          gpuEmxFree_boolean_T(&d_inter_x);
          emxFree_int32_T(&e_ii);
          emxFree_boolean_T(&k_x);
          gpuEmxFree_boolean_T(&c_inter_x);
          emxFree_int32_T(&c_ii);
          gpuEmxFree_int32_T(&inter_ii);
          emxFree_boolean_T(&i_x);
          gpuEmxFree_boolean_T(&b_inter_x);
          emxFree_int32_T(&idx);
          gpuEmxFree_int32_T(&inter_idx);
          emxFree_real_T(&r30);
          gpuEmxFree_real_T(&inter_r30);
          emxFree_creal_T(&f_x);
          gpuEmxFree_creal_T(&f_inter_x);
          emxFree_real_T(&e_x);
          gpuEmxFree_real_T(&e_inter_x);
          emxFree_real_T(&g_b);
          gpuEmxFree_real_T(&d_inter_b);
          emxFree_real_T(&z1);
          gpuEmxFree_real_T(&g_inter_z1);
          emxFree_int32_T(&r27);
          gpuEmxFree_int32_T(&inter_r27);
          emxFree_int32_T(&r25);
          gpuEmxFree_int32_T(&inter_r25);
          emxFree_boolean_T(&r23);
          gpuEmxFree_boolean_T(&inter_r23);
          emxFree_boolean_T(&r21);
          gpuEmxFree_boolean_T(&inter_r21);
          emxFree_boolean_T(&r19);
          emxFree_boolean_T(&r17);
          emxFree_real_T(&r16);
          gpuEmxFree_real_T(&inter_r16);
          emxFree_real_T(&newDataPoints);
          gpuEmxFree_real_T(&inter_newDataPoints);
          emxFree_real_T(&r14);
          gpuEmxFree_real_T(&inter_r14);
          emxFree_real_T(&longStep);
          gpuEmxFree_real_T(&inter_longStep);
          emxFree_real_T(&secondStep);
          gpuEmxFree_real_T(&inter_secondStep);
          emxFree_real_T(&firstStep);
          gpuEmxFree_real_T(&inter_firstStep);
          emxFree_real_T(&secondStepSquared);
          gpuEmxFree_real_T(&inter_secondStepSquared);
          emxFree_real_T(&firstStepSquared);
          gpuEmxFree_real_T(&inter_firstStepSquared);
          emxFree_real_T(&normalizedData);
          gpuEmxFree_real_T(&inter_normalizedData);
          emxFree_real_T(&r11);
          gpuEmxFree_real_T(&inter_r11);
          emxFree_real_T(&r9);
          gpuEmxFree_real_T(&inter_r9);
          emxFree_real_T(&r8);
          gpuEmxFree_real_T(&inter_r8);
          emxFree_real_T(&e_b);
          gpuEmxFree_real_T(&b_inter_b);
          emxFree_real_T(&e_a);
          gpuEmxFree_real_T(&b_inter_a);
          emxFree_real_T(&r5);
          gpuEmxFree_real_T(&inter_r5);
          emxFree_real_T(&r4);
          gpuEmxFree_real_T(&inter_r4);
          emxFree_real_T(&c_b);
          gpuEmxFree_real_T(&c_inter_b);
          emxFree_real_T(&c_a);
          gpuEmxFree_real_T(&c_inter_a);
          emxFree_real_T(&r1);
          gpuEmxFree_real_T(&inter_r1);
          emxFree_real_T(&r);
          gpuEmxFree_real_T(&inter_r);
          emxFree_real_T(&b);
          gpuEmxFree_real_T(&inter_b);
          emxFree_real_T(&a);
          gpuEmxFree_real_T(&inter_a);
          emxFree_int8_T(&ii);
          gpuEmxFree_int8_T(&c_inter_ii);
          emxFree_boolean_T(&c_x);
          gpuEmxFree_boolean_T(&j_inter_x);
          emxFree_real_T(&z);
          gpuEmxFree_real_T(&inter_z);
          emxFree_real_T(&dummydata);
          gpuEmxFree_real_T(&inter_dummydata);
          emxFree_boolean_T(&segmentsToSplit);
          gpuEmxFree_boolean_T(&inter_segmentsToSplit);
          emxFree_boolean_T(&trianglesToRefine);
          gpuEmxFree_boolean_T(&inter_trianglesToRefine);
          emxFree_real_T(&dataPoints);
          gpuEmxFree_real_T(&inter_dataPoints);
          emxFree_real_T(&SLD);
          gpuEmxFree_real_T(&inter_SLD);
          emxFree_real_T(&Lays);
          gpuEmxFree_real_T(&inter_Lays);
          emxFree_real_T(&x);
          gpuEmxFree_real_T(&inter_x);
          emxFree_real_T(&simRef);
          gpuEmxFree_real_T(&inter_simRef);
          emxFree_real_T(&simXdata);
          gpuEmxFree_real_T(&inter_simXdata);
          emxFree_real_T(&lastSection);
          gpuEmxFree_real_T(&inter_lastSection);
          emxFree_real_T(&firstSection);
          gpuEmxFree_real_T(&inter_firstSection);
          emxFree_real_T(&layers);
          gpuEmxFree_real_T(&inter_layers);
          emxFree_real_T(&Simul);
          gpuEmxFree_real_T(&inter_Simul);
          emxFree_real_T(&reflect);
          gpuEmxFree_real_T(&inter_reflect);
          emxFree_real_T(&sldProfile);
          gpuEmxFree_real_T(&inter_sldProfile);
        }
        break;

       case 1:
        {
          boolean_T sldProfile_dirtyOnGpu;
          boolean_T x_dirtyOnGpu;
          boolean_T Lays_dirtyOnGpu;
          boolean_T a_dirtyOnGpu;
          boolean_T b_dirtyOnGpu;
          boolean_T r_dirtyOnGpu;
          boolean_T r1_dirtyOnGpu;
          boolean_T b_a_dirtyOnGpu;
          boolean_T b_b_dirtyOnGpu;
          boolean_T r8_dirtyOnGpu;
          boolean_T r9_dirtyOnGpu;
          boolean_T c_a_dirtyOnGpu;
          boolean_T c_b_dirtyOnGpu;
          boolean_T r4_dirtyOnGpu;
          boolean_T r5_dirtyOnGpu;
          boolean_T SLD_dirtyOnGpu;
          boolean_T layers_dirtyOnGpu;
          boolean_T normalizedData_dirtyOnGpu;
          boolean_T firstStep_dirtyOnGpu;
          boolean_T secondStep_dirtyOnGpu;
          boolean_T longStep_dirtyOnGpu;
          boolean_T z1_dirtyOnGpu;
          boolean_T b_z1_dirtyOnGpu;
          boolean_T firstStepSquared_dirtyOnGpu;
          boolean_T c_z1_dirtyOnGpu;
          boolean_T d_z1_dirtyOnGpu;
          boolean_T secondStepSquared_dirtyOnGpu;
          boolean_T e_z1_dirtyOnGpu;
          boolean_T f_z1_dirtyOnGpu;
          boolean_T b_x_dirtyOnGpu;
          boolean_T c_x_dirtyOnGpu;
          boolean_T trianglesToRefine_dirtyOnGpu;
          boolean_T r32_dirtyOnGpu;
          boolean_T segmentsToSplit_dirtyOnGpu;
          boolean_T newDataPoints_dirtyOnGpu;
          boolean_T r21_dirtyOnGpu;
          boolean_T b_dataPoints_dirtyOnGpu;
          boolean_T idx_dirtyOnGpu;
          boolean_T ycol_dirtyOnGpu;
          boolean_T firstSection_dirtyOnGpu;
          boolean_T lastSection_dirtyOnGpu;
          boolean_T simXdata_dirtyOnGpu;
          boolean_T Simul_dirtyOnGpu;
          boolean_T dummydata_dirtyOnGpu;
          boolean_T reflect_dirtyOnGpu;
          boolean_T z_dirtyOnGpu;
          boolean_T g_z1_dirtyOnGpu;
          boolean_T r33_dirtyOnGpu;

          //  Allocate the memory for the output arrays before the main loop
          //    --- Begin memory allocation ---
          xoffset = static_cast<int32_T>(problemDef->numberOfContrasts);

          //  ---end memory allocation---
          //  First we need to allocate the absolute values of the input
          //  parameters to all the layers in the layers list. This only needs
          //  to be done once, and so is done outside the contrasts loop
          // This function takes the list of all layers (in terms of parameter
          // numbers) in layersDetails, and loops through putting in the correct 
          // parameter value from the parameter array in each layer.
          cg_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (*gpu_thisOutLayer);
          CUDACHECK(cudaGetLastError());
          CUDACHECK(cudaMemcpy(gpu_problemDef_cells, (void *)problemDef_cells,
                               9424UL, cudaMemcpyHostToDevice));
          dg_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (*problemDef, gpu_problemDef_cells, *gpu_thisOutLayer);
          CUDACHECK(cudaGetLastError());
          eg_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (gpu_problemDef_cells, *gpu_thisOutLayer);
          CUDACHECK(cudaGetLastError());
          fg_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (*gpu_thisOutLayer, *gpu_outParameterisedLayers);
          CUDACHECK(cudaGetLastError());
          gg_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (*problemDef, gpu_problemDef_cells, *gpu_thisOutLayer);
          CUDACHECK(cudaGetLastError());
          hg_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (gpu_problemDef_cells, *gpu_thisOutLayer);
          CUDACHECK(cudaGetLastError());
          ig_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (*gpu_thisOutLayer, *gpu_outParameterisedLayers);
          CUDACHECK(cudaGetLastError());
          jg_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (*problemDef, gpu_problemDef_cells, *gpu_thisOutLayer);
          CUDACHECK(cudaGetLastError());
          kg_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (gpu_problemDef_cells, *gpu_thisOutLayer);
          CUDACHECK(cudaGetLastError());
          lg_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (*gpu_thisOutLayer, *gpu_outParameterisedLayers);
          CUDACHECK(cudaGetLastError());
          mg_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (*problemDef, gpu_problemDef_cells, *gpu_thisOutLayer);
          CUDACHECK(cudaGetLastError());
          ng_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (gpu_problemDef_cells, *gpu_thisOutLayer);
          CUDACHECK(cudaGetLastError());
          og_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
            (*gpu_thisOutLayer, *gpu_outParameterisedLayers);
          CUDACHECK(cudaGetLastError());

          //  Single Loop over all the contrasts
          i = static_cast<int32_T>(problemDef->numberOfContrasts);
          kEnd = outSsubs->size[0];
          outSsubs->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
          emxEnsureCapacity_real_T(outSsubs, kEnd);
          kEnd = b_sldProfiles->size[0];
          b_sldProfiles->size[0] = static_cast<int32_T>
            (problemDef->numberOfContrasts);
          emxEnsureCapacity_cell_wrap_17(b_sldProfiles, kEnd);
          kEnd = b_reflectivity->size[0];
          b_reflectivity->size[0] = xoffset;
          emxEnsureCapacity_cell_wrap_11(b_reflectivity, kEnd);
          kEnd = b_Simulation->size[0];
          b_Simulation->size[0] = static_cast<int32_T>
            (problemDef->numberOfContrasts);
          emxEnsureCapacity_cell_wrap_11(b_Simulation, kEnd);
          kEnd = b_shifted_data->size[0];
          b_shifted_data->size[0] = static_cast<int32_T>
            (problemDef->numberOfContrasts);
          emxEnsureCapacity_cell_wrap_12(b_shifted_data, kEnd);
          kEnd = b_layerSlds->size[0];
          b_layerSlds->size[0] = static_cast<int32_T>
            (problemDef->numberOfContrasts);
          emxEnsureCapacity_cell_wrap_12(b_layerSlds, kEnd);
          if (chis_dirtyOnGpu) {
            gpuEmxMemcpyGpuToCpu_real_T(chis, &inter_chis);
            chis_dirtyOnGpu = false;
          }

          kEnd = chis->size[0];
          chis->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
          emxEnsureCapacity_real_T(chis, kEnd);
          if (backgs_dirtyOnGpu) {
            gpuEmxMemcpyGpuToCpu_real_T(backgs, &inter_backgs);
            backgs_dirtyOnGpu = false;
          }

          kEnd = backgs->size[0];
          backgs->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
          emxEnsureCapacity_real_T(backgs, kEnd);
          if (qshifts_dirtyOnGpu) {
            gpuEmxMemcpyGpuToCpu_real_T(qshifts, &inter_qshifts);
            qshifts_dirtyOnGpu = false;
          }

          kEnd = qshifts->size[0];
          qshifts->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
          emxEnsureCapacity_real_T(qshifts, kEnd);
          if (sfs_dirtyOnGpu) {
            gpuEmxMemcpyGpuToCpu_real_T(sfs, &inter_sfs);
            sfs_dirtyOnGpu = false;
          }

          kEnd = sfs->size[0];
          sfs->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
          emxEnsureCapacity_real_T(sfs, kEnd);
          if (nbas_dirtyOnGpu) {
            gpuEmxMemcpyGpuToCpu_real_T(nbas, &inter_nbas);
            nbas_dirtyOnGpu = false;
          }

          kEnd = nbas->size[0];
          nbas->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
          emxEnsureCapacity_real_T(nbas, kEnd);
          if (nbss_dirtyOnGpu) {
            gpuEmxMemcpyGpuToCpu_real_T(nbss, &inter_nbss);
            nbss_dirtyOnGpu = false;
          }

          kEnd = nbss->size[0];
          nbss->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
          emxEnsureCapacity_real_T(nbss, kEnd);
          if (resols_dirtyOnGpu) {
            gpuEmxMemcpyGpuToCpu_real_T(resols, &inter_resols);
            resols_dirtyOnGpu = false;
          }

          kEnd = resols->size[0];
          resols->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
          emxEnsureCapacity_real_T(resols, kEnd);
          if (allRoughs_dirtyOnGpu) {
            gpuEmxMemcpyGpuToCpu_real_T(allRoughs, &inter_allRoughs);
            allRoughs_dirtyOnGpu = false;
          }

          kEnd = allRoughs->size[0];
          allRoughs->size[0] = static_cast<int32_T>
            (problemDef->numberOfContrasts);
          emxEnsureCapacity_real_T(allRoughs, kEnd);
          emxInit_real_T(&b_sldProfile, 2, true);
          sldProfile_dirtyOnGpu = false;
          emxInit_real_T(&b_reflect, 2, true);
          reflect_dirtyOnGpu = false;
          emxInit_real_T(&b_Simul, 2, true);
          Simul_dirtyOnGpu = false;
          emxInit_real_T(&b_layers, 2, true);
          layers_dirtyOnGpu = false;
          emxInit_real_T(&b_firstSection, 2, true);
          firstSection_dirtyOnGpu = false;
          emxInit_real_T(&b_lastSection, 2, true);
          lastSection_dirtyOnGpu = false;
          emxInit_real_T(&b_simXdata, 1, true);
          simXdata_dirtyOnGpu = false;
          emxInit_real_T(&b_simRef, 1, true);
          emxInit_real_T(&b_x, 2, true);
          x_dirtyOnGpu = false;
          emxInit_real_T(&b_Lays, 2, true);
          Lays_dirtyOnGpu = false;
          emxInit_real_T(&b_SLD, 1, true);
          SLD_dirtyOnGpu = false;
          emxInit_real_T(&b_dataPoints, 2, true);
          emxInit_boolean_T(&b_trianglesToRefine, 1, true);
          trianglesToRefine_dirtyOnGpu = false;
          emxInit_boolean_T(&b_segmentsToSplit, 1, true);
          segmentsToSplit_dirtyOnGpu = false;
          emxInit_real_T(&b_dummydata, 1, true);
          dummydata_dirtyOnGpu = false;
          emxInit_real_T(&b_z, 1, true);
          z_dirtyOnGpu = false;
          emxInit_boolean_T(&d_x, 1, true);
          emxInit_int8_T(&b_ii, 1, true);
          emxInit_real_T(&b_a, 2, true);
          a_dirtyOnGpu = false;
          emxInit_real_T(&b_b, 2, true);
          b_dirtyOnGpu = false;
          emxInit_real_T(&r2, 2, true);
          r_dirtyOnGpu = false;
          emxInit_real_T(&r3, 2, true);
          r1_dirtyOnGpu = false;
          emxInit_real_T(&d_a, 2, true);
          c_a_dirtyOnGpu = false;
          emxInit_real_T(&d_b, 2, true);
          c_b_dirtyOnGpu = false;
          emxInit_real_T(&r6, 2, true);
          r4_dirtyOnGpu = false;
          emxInit_real_T(&r7, 2, true);
          r5_dirtyOnGpu = false;
          emxInit_real_T(&f_a, 2, true);
          b_a_dirtyOnGpu = false;
          emxInit_real_T(&f_b, 2, true);
          b_b_dirtyOnGpu = false;
          emxInit_real_T(&r10, 2, true);
          r8_dirtyOnGpu = false;
          emxInit_real_T(&r12, 2, true);
          r9_dirtyOnGpu = false;
          emxInit_real_T(&r13, 1, true);
          r32_dirtyOnGpu = false;
          emxInit_real_T(&b_normalizedData, 2, true);
          normalizedData_dirtyOnGpu = false;
          emxInit_real_T(&b_firstStepSquared, 1, true);
          firstStepSquared_dirtyOnGpu = false;
          emxInit_real_T(&b_secondStepSquared, 1, true);
          secondStepSquared_dirtyOnGpu = false;
          emxInit_real_T(&b_firstStep, 2, true);
          firstStep_dirtyOnGpu = false;
          emxInit_real_T(&b_secondStep, 2, true);
          secondStep_dirtyOnGpu = false;
          emxInit_real_T(&b_longStep, 2, true);
          longStep_dirtyOnGpu = false;
          emxInit_real_T(&r15, 2, true);
          emxInit_real_T(&b_newDataPoints, 2, true);
          newDataPoints_dirtyOnGpu = false;
          emxInit_real_T(&r18, 1, true);
          emxInit_boolean_T(&r20, 1, true);
          emxInit_boolean_T(&r22, 1, true);
          emxInit_boolean_T(&r24, 1, true);
          r21_dirtyOnGpu = false;
          emxInit_boolean_T(&r26, 1, true);
          emxInit_int32_T(&r28, 1, true);
          emxInit_int32_T(&r29, 1, true);
          emxInit_real_T(&b_z1, 1, true);
          g_z1_dirtyOnGpu = false;
          emxInit_real_T(&h_b, 2, true);
          emxInit_real_T(&g_x, 1, true);
          b_x_dirtyOnGpu = false;
          emxInit_creal_T(&h_x, 1, true);
          c_x_dirtyOnGpu = false;
          emxInit_real_T(&r31, 1, true);
          emxInit_int32_T(&b_idx, 1, true);
          idx_dirtyOnGpu = false;
          emxInit_boolean_T(&j_x, 1, true);
          emxInit_int32_T(&d_ii, 1, true);
          emxInit_boolean_T(&l_x, 1, true);
          emxInit_int32_T(&f_ii, 1, true);
          emxInit_boolean_T(&n_x, 1, true);
          emxInit_int32_T(&h_ii, 1, true);
          emxInit_real_T(&b_ycol, 1, true);
          ycol_dirtyOnGpu = false;
          emxInit_real_T(&e_z1, 1, true);
          z1_dirtyOnGpu = false;
          emxInit_real_T(&g_z1, 1, true);
          b_z1_dirtyOnGpu = false;
          emxInit_real_T(&i_z1, 1, true);
          c_z1_dirtyOnGpu = false;
          emxInit_real_T(&k_z1, 1, true);
          d_z1_dirtyOnGpu = false;
          emxInit_real_T(&m_z1, 1, true);
          e_z1_dirtyOnGpu = false;
          emxInit_real_T(&n_z1, 1, true);
          f_z1_dirtyOnGpu = false;
          emxInit_boolean_T(&p_x, 1, true);
          emxInit_int32_T(&j_ii, 1, true);
          emxInit_boolean_T(&r_x, 1, true);
          emxInit_int32_T(&l_ii, 1, true);
          emxInit_boolean_T(&t_x, 1, true);
          emxInit_int32_T(&n_ii, 1, true);
          emxInit_int32_T(&b_iwork, 1, true);
          emxInit_boolean_T(&d_trianglesToRefine, 1, true);
          emxInit_boolean_T(&r33, 1, true);
          r33_dirtyOnGpu = false;
          emxInit_real_T(&d_dataPoints, 2, true);
          b_dataPoints_dirtyOnGpu = false;
          for (b_i = 0; b_i < i; b_i++) {
            real_T s_sub;
            real_T reps;
            int32_T k;
            real_T nextLayRough;
            real_T bFactor;
            int32_T i2;
            real_T g_a;
            real_T l;
            real_T thisBoxCentre;
            real_T pair_im;
            int32_T c_i;
            real_T snair;
            real_T snsub;
            real_T b_r;
            boolean_T layerThicks_dirtyOnGpu;
            boolean_T sldProfile_dirtyOnCpu;
            boolean_T x_dirtyOnCpu;
            boolean_T Lays_dirtyOnCpu;
            boolean_T b_dirtyOnCpu;
            boolean_T r1_dirtyOnCpu;
            boolean_T r8_dirtyOnCpu;
            boolean_T xoffset_dirtyOnCpu;
            boolean_T exitg2;

            //  Extract the relevant parameter values for this contrast
            //  from the input arrays.
            //  First need to decide which values of the backrounds, scalefactors 
            //  data shifts and bulk contrasts are associated with this contrast 
            // Distributes the background and shift values among the different contrasts. 
            //
            // [backgs,qshifts,sfs,nbas,nbss,resols] = backSort(nc,cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,shifts,sf,nba,nbs,res) 
            //  Inputs:
            //        nc = number of contrasts (double)
            //        cBacks = Which backround value is associated with each contrast? 
            //        cShifts = Which qz_shift value is associated with each contrast? 
            //        cScales = Which scalefactor value is associated with each contrast? 
            //        cNba = Which NBa value is associated with each contrast?
            //        cNbs = Which Nbs value is associated with each contrast?
            //        cRes = Which resolution value is associated with each contrast? 
            //        backs = List of all background values.
            //        shifts = List of all qz-shift values
            //        sf = List of all scalefactor values
            //        nba = List of all nba values
            //        nbs = List of all nbs values
            //        res = List of all resolution values
            //
            //  Outputs:
            //        backgs = list of actual background values for each contrast 
            //        qshifts = list of actual shift values for each contrast       
            //        sfs = list of actual shift values for each contrast
            //        nbas = list of actual shift values for each contrast
            //        nbss = list of actual shift values for each contrast
            //        nbss = list of actual shift values for each contrast
            //  backgs = 0;%zeros(1,nc);
            //  qshifts = 0;%zeros(1,nc);
            //  sfs = 0;%zeros(1,nc);
            //  nbas = 0;%zeros(1,nc);
            //  nbss = 0;%zeros(1,nc);
            //  resols = 0;%zeros(1,nc);
            // for i = 1:nc
            // thisBack = cBacks(i);
            // thisShift = cShifts(i);
            // thisScale = cScales(i);
            // thisNbair = cNbas(i);
            // thisNbsub = cNbss(i);
            // thisResol = cRes(i);
            // end
            //  Also need to determine which layers from the overall layers list 
            //  are required for this contrast, and put them in the correct order  
            //  according to geometry
            //  Take the layers list for a contrast and build an
            //  array of real valued layers
            pg_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
              (*gpu_outParameterisedLayers, gpu_problemDef_cells, b_i,
               *gpu_thisContrastLayers);
            CUDACHECK(cudaGetLastError());

            //  For the other parameters, we extract the correct ones from the input 
            //  arrays
            //  Substrate roughness is always first parameter for standard layers 
            qg_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(160U, 1U,
              1U)>>>(gpu_problemDef_cells, b_i, *gpu_thisData);
            CUDACHECK(cudaGetLastError());

            //  Now call the core standardTF_stanlay reflectivity calculation
            //  In this case we parallelise over points.
            //  Call the calculation
            layerThicks = calcSld;
            layerThicks_dirtyOnGpu = false;

            //  function [sldProfile,reflect,Simul,shifted_dat,layerSld,chiSquared,ssubs] = ... 
            //      standardTF_stanlay_core(contrastLayers, rough, ...
            //      geometry, nba, nbs, resample, calcSld, sf, qshift,...
            //      dataPresent, data, dataLimits, simLimits, repeatLayers,...
            //      background,resol,backsType,params,paralellPoints)
            //
            //    This is the main reflectivity calculation for Layers models in the  
            //    standard target function. The function first arranges the
            //    roughness' in the correct order according
            //    to geometry. Then, if required it calculates the SLD profile and if 
            //    requested resamples this into a number of zero-roughness layers 
            //    (roughness resampling). It the applies any scalefactors and qz shifts 
            //    the data requires. This is done before calculating the reflectivity to 
            //    ensure that the reflectivity is calculated over the same range in qz as 
            //    the shifted datapoints. The main reflectivity calculation is then 
            //    called, including the resolution function. The calculation outputs two 
            //    profiles - 'reflect' which is the same range as the points, and 
            //    'Simulation' which can be a different range to allow extrapolation. 
            //    The background correction is the applied, and finally chi-squared is  
            //    calculated.
            //
            //  Inputs:
            //    contrastLayers  :
            //    rough           :
            //    geometry        :
            //    nba             :
            //    nbs             :
            //    resample        :
            //    calcSld         :
            //    sf              :
            //    qshift          :
            //    dataPresent     :
            //    data            :
            //    dataLimits      :
            //    simLimits       :
            //    repeatLayers    :
            //    background      :
            //    resol           :
            //    backsType       :
            //    params          :
            //    paralellPoints  :
            //
            //  Outputs:
            //
            //
            //
            //  ------------------------------------------------------------------------ 
            //
            //        (c) Arwel Hughes  -   12/1/21
            //
            //        Last Modified: 12/1/21 by Arwel Hughes.
            //
            //  ------------------------------------------------------------------------ 
            //  Bulid up the layers matrix for this contrast
            // Arrange layers according to geometry and apply any coverage correction. 
            //
            // [outLayers, outSsubs] = groupLayers_Mod(allLayers,allRoughs,numberOfContrasts,geometry,nbairs,nbsubs) 
            //  Inputs:
            //      allLayers = cell array, one for each contrast. Each cell is the  
            //                  list of layer values for each contrast.
            //                  e.g. allLayers{1} = [d1, rho1, r1, %hyd, hyd_which 
            //                                       d2, rho2, r2, %hyd2, hyd_which_2.. 
            //                                       etc]
            //      allRoughs = Double of substrate roughness for each contrast. 
            //      numberOfContrasts = double.
            //      geometry =  'Air / Liquid (or solid)' or 'Solid / Liquid'
            //      nbairs = vector of nbair values.
            //      nbsubs = vector of nbsub values.
            //
            //      The paratt calculation procedds through the
            //      z,rho,rough stack, and the parameter 'ssub' in
            //      callParatt is the final roughness encountered.
            //      For air liquid 'ssub' is therefore the substrate roughness.
            //      For solid liquid, the substrate roughness is the first roughness 
            //      encountered, and 'ssub' is then the roughness of the outermost layer. 
            //      The rougnesses need to be arranged accordingly.
            //
            //
            //  Outputs:
            //      outLayers = cell array of layers param values for each contrast. 
            //                  e.g. outLayers{1} = [d1 rho1 r1;
            //                                       d2 rho2 r2
            //                                       ... etc   ]
            //      outSsubs = vector of substrate roughness values.
            //
            // outLayers = cell(1,numberOfContrasts);
            // outSsubs = zeros(1,numberOfContrasts);
            // for i = 1:numberOfContrasts
            s_sub = problemDef->params[0];
            layers_size[0] = 2;
            layers_size[1] = 5;
            rg_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
              (*gpu_layers_data);
            CUDACHECK(cudaGetLastError());
            b_bool = false;
            xoffset = 0;
            xoffset_dirtyOnCpu = true;
            do {
              exitg1 = 0;
              if (xoffset + 1 < 14) {
                if (problemDef->geometry[xoffset] != cv3[xoffset]) {
                  exitg1 = 1;
                } else {
                  xoffset++;
                }
              } else {
                b_bool = true;
                exitg1 = 1;
              }
            } while (exitg1 == 0);

            if (b_bool) {
              vlen = 0;
            } else {
              vlen = -1;
            }

            if (vlen == 0) {
              layers_size[0] = 2;
              layers_size[1] = 5;
              sg_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(*gpu_thisContrastLayers, *gpu_layers_data);
              CUDACHECK(cudaGetLastError());

              // s_sub = rsub;
            }

            // Deal with the %coverage if present
            tg_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
              (nba, *problemDef, b_i, *gpu_thisContrastLayers, *gpu_layers_data);
            CUDACHECK(cudaGetLastError());

            //      problem.layers{i} = layers;
            //      problem.ssubs(i) = s_sub;
            // end
            //  Make the SLD profiles.
            //  If resampling is needed, then enforce the calcSLD flag, so as to catch 
            //  the error af trying to resample a non-existent profile.
            if ((problemDef->resample[b_i] == 1.0) && (calcSld == 0.0)) {
              layerThicks = 1.0;
            }

            //  If cal SLD flag is set, then calculate the SLD profile
            if (layerThicks == 1.0) {
              if (problemDef_cells->f1[b_i].f1[0] == 0.0) {
                reps = 1.0;
              } else {
                reps = problemDef_cells->f1[b_i].f1[1];
              }

              CUDACHECK(cudaMemcpy(&layers_data[0], gpu_layers_data, 10U *
                                   sizeof(real_T), cudaMemcpyDeviceToHost));
              layerThicks = layers_data[0];
              CUDACHECK(cudaMemcpy(gpu_layers_size, &layers_size[0], 8UL,
                                   cudaMemcpyHostToDevice));
              CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                   cudaMemcpyHostToDevice));
              vg_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(*gpu_layers_data, gpu_layerThicks);
              CUDACHECK(cudaGetLastError());
              CUDACHECK(cudaMemcpy(&layerThicks, gpu_layerThicks, 8UL,
                                   cudaMemcpyDeviceToHost));
              layerThicks = layerThicks * reps + 150.0;
              if (rtIsNaN(layerThicks)) {
                kEnd = b_x->size[0] * b_x->size[1];
                b_x->size[0] = 1;
                b_x->size[1] = 1;
                emxEnsureCapacity_real_T(b_x, kEnd);
                b_x->data[0] = rtNaN;
                x_dirtyOnCpu = true;
              } else if (layerThicks < 0.0) {
                b_x->size[0] = 1;
                b_x->size[1] = 0;
                x_dirtyOnCpu = true;
              } else if (rtIsInf(layerThicks) && (0.0 == layerThicks)) {
                kEnd = b_x->size[0] * b_x->size[1];
                b_x->size[0] = 1;
                b_x->size[1] = 1;
                emxEnsureCapacity_real_T(b_x, kEnd);
                b_x->data[0] = rtNaN;
                x_dirtyOnCpu = true;
              } else {
                kEnd = b_x->size[0] * b_x->size[1];
                b_x->size[0] = 1;
                b_x->size[1] = static_cast<int32_T>(floor(layerThicks)) + 1;
                emxEnsureCapacity_real_T(b_x, kEnd);
                x_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>(
                  static_cast<int32_T>(layerThicks) + 1L), &i_grid, &i_block,
                  1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                       cudaMemcpyHostToDevice));
                  gpuEmxMemcpyCpuToGpu_real_T(b_x, &k_inter_x, l_gpu_x);
                  wg_reflectivity_calculation_gpu<<<i_grid, i_block>>>
                    (gpu_layerThicks, l_gpu_x);
                  CUDACHECK(cudaGetLastError());
                  x_dirtyOnCpu = false;
                  x_dirtyOnGpu = true;
                }
              }

              kEnd = b_Lays->size[0] * b_Lays->size[1];
              if (x_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(b_x, &k_inter_x);
                x_dirtyOnGpu = false;
              }

              b_Lays->size[0] = b_x->size[1];
              b_Lays->size[1] = static_cast<int32_T>(2.0 * reps + 2.0);
              emxEnsureCapacity_real_T(b_Lays, kEnd);
              Lays_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((b_x->size[1] * static_cast<int32_T>(2.0 * reps + 2.0) - 1) +
                 1L), &j_grid, &j_block, 1024U, 65535U);
              if (validLaunchParams) {
                if (x_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(b_x, &k_inter_x, l_gpu_x);
                  x_dirtyOnCpu = false;
                }

                gpuEmxMemcpyCpuToGpu_real_T(b_Lays, &b_inter_Lays, b_gpu_Lays);
                xg_reflectivity_calculation_gpu<<<j_grid, j_block>>>(reps,
                  l_gpu_x, b_gpu_Lays);
                CUDACHECK(cudaGetLastError());
                Lays_dirtyOnCpu = false;
                Lays_dirtyOnGpu = true;
              }

              nextLayRough = layers_data[4];

              //  Produces a step function convoluted with differnt error functions 
              //  on each side.
              //  Convstep (x,xw,xcen,s1,s2,h)
              //        x = vector of x values
              //       xw = Width of step function
              //     xcen = Centre point of step function
              //        s1 = Roughness parameter of left side
              //        s2 = Roughness parameter of right side
              //        h = Height of step function.
              //  if length(xw) > 1
              //      ME = MException('VerifyOutput:OutOfBounds', ...
              //               'xw must be single value');
              //      throw(ME);
              //  end
              //
              //  if length(xcen) > 1
              //      ME = MException('VerifyOutput:OutOfBounds', ...
              //               'xcen must be single value');
              //      throw(ME);
              //  end
              //
              //  if length(s1) > 1
              //      ME = MException('VerifyOutput:OutOfBounds', ...
              //               's1 must be single value');
              //      throw(ME);
              //  end
              //
              //  if length(s2) > 1
              //      ME = MException('VerifyOutput:OutOfBounds', ...
              //               's2 must be single value');
              //      throw(ME);
              //  end
              layerThicks = 1.4142135623730951 * layers_data[4];
              kEnd = b_a->size[0] * b_a->size[1];
              b_a->size[0] = 1;
              b_a->size[1] = b_x->size[1];
              emxEnsureCapacity_real_T(b_a, kEnd);
              problemDef_cells_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((b_x->size[0] * b_x->size[1] - 1) + 1L), &k_grid, &k_block,
                1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                     cudaMemcpyHostToDevice));
                if (x_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(b_x, &k_inter_x, l_gpu_x);
                  x_dirtyOnCpu = false;
                }

                gpuEmxMemcpyCpuToGpu_real_T(b_a, &d_inter_a, d_gpu_a);
                yg_reflectivity_calculation_gpu<<<k_grid, k_block>>>
                  (gpu_layerThicks, l_gpu_x, d_gpu_a);
                CUDACHECK(cudaGetLastError());
                problemDef_cells_dirtyOnCpu = false;
                a_dirtyOnGpu = true;
              }

              kEnd = b_b->size[0] * b_b->size[1];
              b_b->size[0] = 1;
              b_b->size[1] = b_x->size[1];
              emxEnsureCapacity_real_T(b_b, kEnd);
              b_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((b_x->size[0] * b_x->size[1] - 1) + 1L), &l_grid, &l_block,
                1024U, 65535U);
              if (validLaunchParams) {
                if (x_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(b_x, &k_inter_x, l_gpu_x);
                  x_dirtyOnCpu = false;
                }

                gpuEmxMemcpyCpuToGpu_real_T(b_b, &e_inter_b, e_gpu_b);
                ah_reflectivity_calculation_gpu<<<l_grid, l_block>>>
                  (1.4142135623730951 * layers_data[4], l_gpu_x, e_gpu_b);
                CUDACHECK(cudaGetLastError());
                b_dirtyOnCpu = false;
                b_dirtyOnGpu = true;
              }

              if (a_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(b_a, &d_inter_a);
                a_dirtyOnGpu = false;
              }

              nx = b_a->size[1];
              if (r_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(r2, &inter_r2);
                r_dirtyOnGpu = false;
              }

              kEnd = r2->size[0] * r2->size[1];
              r2->size[0] = 1;
              r2->size[1] = b_a->size[1];
              emxEnsureCapacity_real_T(r2, kEnd);
              b_bool = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((nx
                - 1) + 1L), &m_grid, &m_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                if (problemDef_cells_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(b_a, &d_inter_a, d_gpu_a);
                }

                gpuEmxMemcpyCpuToGpu_real_T(r2, &inter_r2, gpu_r2);
                bh_reflectivity_calculation_gpu<<<m_grid, m_block>>>(d_gpu_a,
                  gpu_nx, gpu_r2);
                CUDACHECK(cudaGetLastError());
                b_bool = false;
                r_dirtyOnGpu = true;
              }

              if (b_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(b_b, &e_inter_b);
                b_dirtyOnGpu = false;
              }

              nx = b_b->size[1];
              if (r1_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(r3, &inter_r3);
                r1_dirtyOnGpu = false;
              }

              kEnd = r3->size[0] * r3->size[1];
              r3->size[0] = 1;
              r3->size[1] = b_b->size[1];
              emxEnsureCapacity_real_T(r3, kEnd);
              r1_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((nx
                - 1) + 1L), &n_grid, &n_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                if (b_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(b_b, &e_inter_b, e_gpu_b);
                }

                gpuEmxMemcpyCpuToGpu_real_T(r3, &inter_r3, gpu_r3);
                ch_reflectivity_calculation_gpu<<<n_grid, n_block>>>(e_gpu_b,
                  gpu_nx, gpu_r3);
                CUDACHECK(cudaGetLastError());
                r1_dirtyOnCpu = false;
                r1_dirtyOnGpu = true;
              }

              layerThicks = 50.0;
              kEnd = static_cast<int32_T>(reps);
              for (n = 0; n < kEnd; n++) {
                for (c_i = 0; c_i < 2; c_i++) {
                  if (c_i + 1 < 2) {
                    nextLayRough = layers_data[5];

                    //              elseif (i == numberOfLayers) && (n < nrepeats) 
                    //                  nextLayRough = layers(1,3);
                  } else {
                    nextLayRough = s_sub;
                  }

                  thisBoxCentre = layerThicks + layers_data[c_i] / 2.0;

                  //  Produces a step function convoluted with differnt error functions 
                  //  on each side.
                  //  Convstep (x,xw,xcen,s1,s2,h)
                  //        x = vector of x values
                  //       xw = Width of step function
                  //     xcen = Centre point of step function
                  //        s1 = Roughness parameter of left side
                  //        s2 = Roughness parameter of right side
                  //        h = Height of step function.
                  //  if length(xw) > 1
                  //      ME = MException('VerifyOutput:OutOfBounds', ...
                  //               'xw must be single value');
                  //      throw(ME);
                  //  end
                  //
                  //  if length(xcen) > 1
                  //      ME = MException('VerifyOutput:OutOfBounds', ...
                  //               'xcen must be single value');
                  //      throw(ME);
                  //  end
                  //
                  //  if length(s1) > 1
                  //      ME = MException('VerifyOutput:OutOfBounds', ...
                  //               's1 must be single value');
                  //      throw(ME);
                  //  end
                  //
                  //  if length(s2) > 1
                  //      ME = MException('VerifyOutput:OutOfBounds', ...
                  //               's2 must be single value');
                  //      throw(ME);
                  //  end
                  b_r = thisBoxCentre + layers_data[c_i] / 2.0;
                  l = thisBoxCentre - layers_data[c_i] / 2.0;
                  layerThicks = 1.4142135623730951 * layers_data[c_i + 4];
                  qEnd = f_a->size[0] * f_a->size[1];
                  f_a->size[0] = 1;
                  f_a->size[1] = b_x->size[1];
                  emxEnsureCapacity_real_T(f_a, qEnd);
                  problemDef_cells_dirtyOnCpu = true;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((b_x->size[0] * b_x->size[1] - 1) + 1L), &o_grid, &o_block,
                    1024U, 65535U);
                  if (validLaunchParams) {
                    CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                         cudaMemcpyHostToDevice));
                    if (x_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(b_x, &k_inter_x, l_gpu_x);
                      x_dirtyOnCpu = false;
                    }

                    gpuEmxMemcpyCpuToGpu_real_T(f_a, &e_inter_a, e_gpu_a);
                    dh_reflectivity_calculation_gpu<<<o_grid, o_block>>>
                      (gpu_layerThicks, l, l_gpu_x, e_gpu_a);
                    CUDACHECK(cudaGetLastError());
                    problemDef_cells_dirtyOnCpu = false;
                    b_a_dirtyOnGpu = true;
                  }

                  qEnd = f_b->size[0] * f_b->size[1];
                  f_b->size[0] = 1;
                  f_b->size[1] = b_x->size[1];
                  emxEnsureCapacity_real_T(f_b, qEnd);
                  b_dirtyOnCpu = true;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((b_x->size[0] * b_x->size[1] - 1) + 1L), &p_grid, &p_block,
                    1024U, 65535U);
                  if (validLaunchParams) {
                    if (x_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(b_x, &k_inter_x, l_gpu_x);
                      x_dirtyOnCpu = false;
                    }

                    gpuEmxMemcpyCpuToGpu_real_T(f_b, &f_inter_b, f_gpu_b);
                    eh_reflectivity_calculation_gpu<<<p_grid, p_block>>>
                      (1.4142135623730951 * nextLayRough, b_r, l_gpu_x, f_gpu_b);
                    CUDACHECK(cudaGetLastError());
                    b_dirtyOnCpu = false;
                    b_b_dirtyOnGpu = true;
                  }

                  if (b_a_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_real_T(f_a, &e_inter_a);
                    b_a_dirtyOnGpu = false;
                  }

                  nx = f_a->size[1];
                  if (r8_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_real_T(r10, &inter_r10);
                    r8_dirtyOnGpu = false;
                  }

                  qEnd = r10->size[0] * r10->size[1];
                  r10->size[0] = 1;
                  r10->size[1] = f_a->size[1];
                  emxEnsureCapacity_real_T(r10, qEnd);
                  r8_dirtyOnCpu = true;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((nx - 1) + 1L), &q_grid, &q_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL,
                                         cudaMemcpyHostToDevice));
                    if (problemDef_cells_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(f_a, &e_inter_a, e_gpu_a);
                    }

                    gpuEmxMemcpyCpuToGpu_real_T(r10, &inter_r10, gpu_r10);
                    fh_reflectivity_calculation_gpu<<<q_grid, q_block>>>(e_gpu_a,
                      gpu_nx, gpu_r10);
                    CUDACHECK(cudaGetLastError());
                    r8_dirtyOnCpu = false;
                    r8_dirtyOnGpu = true;
                  }

                  if (b_b_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_real_T(f_b, &f_inter_b);
                    b_b_dirtyOnGpu = false;
                  }

                  nx = f_b->size[1];
                  if (r9_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_real_T(r12, &inter_r12);
                    r9_dirtyOnGpu = false;
                  }

                  qEnd = r12->size[0] * r12->size[1];
                  r12->size[0] = 1;
                  r12->size[1] = f_b->size[1];
                  emxEnsureCapacity_real_T(r12, qEnd);
                  problemDef_cells_dirtyOnCpu = true;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((nx - 1) + 1L), &r_grid, &r_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL,
                                         cudaMemcpyHostToDevice));
                    if (b_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(f_b, &f_inter_b, f_gpu_b);
                    }

                    gpuEmxMemcpyCpuToGpu_real_T(r12, &inter_r12, gpu_r12);
                    gh_reflectivity_calculation_gpu<<<r_grid, r_block>>>(f_gpu_b,
                      gpu_nx, gpu_r12);
                    CUDACHECK(cudaGetLastError());
                    problemDef_cells_dirtyOnCpu = false;
                    r9_dirtyOnGpu = true;
                  }

                  layerThicks = layers_data[c_i + 2] / 2.0;
                  qEnd = c_i + (n << 1);
                  if (xoffset_dirtyOnCpu) {
                    CUDACHECK(cudaMemcpy(gpu_xoffset, &xoffset, 4UL,
                                         cudaMemcpyHostToDevice));
                    xoffset_dirtyOnCpu = false;
                  }

                  if (Lays_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(b_Lays, &b_inter_Lays,
                      b_gpu_Lays);
                    Lays_dirtyOnCpu = false;
                  }

                  hh_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U,
                    1U, 1U)>>>(b_gpu_Lays, gpu_xoffset);
                  CUDACHECK(cudaGetLastError());
                  CUDACHECK(cudaMemcpy(&xoffset, gpu_xoffset, 4UL,
                                       cudaMemcpyDeviceToHost));
                  ii_size[0] = xoffset;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((ii_size[0] - 1) + 1L), &s_grid, &s_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                         cudaMemcpyHostToDevice));
                    CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL,
                                         cudaMemcpyHostToDevice));
                    CUDACHECK(cudaMemcpy(gpu_ii_size, &ii_size[0], 4UL,
                                         cudaMemcpyHostToDevice));
                    if (r8_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(r10, &inter_r10, gpu_r10);
                    }

                    if (problemDef_cells_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(r12, &inter_r12, gpu_r12);
                    }

                    ih_reflectivity_calculation_gpu<<<s_grid, s_block>>>(gpu_r12,
                      gpu_r10, gpu_layerThicks, gpu_qEnd, *gpu_ii_size,
                      b_gpu_Lays);
                    CUDACHECK(cudaGetLastError());
                    Lays_dirtyOnGpu = true;
                  }

                  layerThicks = thisBoxCentre + layers_data[c_i] / 2.0;

                  // plot(x,Lays(:,i));
                }
              }

              // layers(end,3);
              layerThicks = (b_x->data[b_x->size[1] - 1] - layerThicks) * 2.0;
              kEnd = static_cast<int32_T>(2.0 * reps + 1.0);

              //  Produces a step function convoluted with differnt error functions 
              //  on each side.
              //  Convstep (x,xw,xcen,s1,s2,h)
              //        x = vector of x values
              //       xw = Width of step function
              //     xcen = Centre point of step function
              //        s1 = Roughness parameter of left side
              //        s2 = Roughness parameter of right side
              //        h = Height of step function.
              //  if length(xw) > 1
              //      ME = MException('VerifyOutput:OutOfBounds', ...
              //               'xw must be single value');
              //      throw(ME);
              //  end
              //
              //  if length(xcen) > 1
              //      ME = MException('VerifyOutput:OutOfBounds', ...
              //               'xcen must be single value');
              //      throw(ME);
              //  end
              //
              //  if length(s1) > 1
              //      ME = MException('VerifyOutput:OutOfBounds', ...
              //               's1 must be single value');
              //      throw(ME);
              //  end
              //
              //  if length(s2) > 1
              //      ME = MException('VerifyOutput:OutOfBounds', ...
              //               's2 must be single value');
              //      throw(ME);
              //  end
              b_r = b_x->data[b_x->size[1] - 1] + layerThicks / 2.0;
              l = b_x->data[b_x->size[1] - 1] - layerThicks / 2.0;
              layerThicks = 1.4142135623730951 * nextLayRough;
              qEnd = d_a->size[0] * d_a->size[1];
              d_a->size[0] = 1;
              d_a->size[1] = b_x->size[1];
              emxEnsureCapacity_real_T(d_a, qEnd);
              problemDef_cells_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((b_x->size[0] * b_x->size[1] - 1) + 1L), &t_grid, &t_block,
                1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                     cudaMemcpyHostToDevice));
                if (x_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(b_x, &k_inter_x, l_gpu_x);
                  x_dirtyOnCpu = false;
                }

                gpuEmxMemcpyCpuToGpu_real_T(d_a, &f_inter_a, f_gpu_a);
                jh_reflectivity_calculation_gpu<<<t_grid, t_block>>>
                  (gpu_layerThicks, l, l_gpu_x, f_gpu_a);
                CUDACHECK(cudaGetLastError());
                problemDef_cells_dirtyOnCpu = false;
                c_a_dirtyOnGpu = true;
              }

              qEnd = d_b->size[0] * d_b->size[1];
              d_b->size[0] = 1;
              d_b->size[1] = b_x->size[1];
              emxEnsureCapacity_real_T(d_b, qEnd);
              b_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((b_x->size[0] * b_x->size[1] - 1) + 1L), &u_grid, &u_block,
                1024U, 65535U);
              if (validLaunchParams) {
                if (x_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(b_x, &k_inter_x, l_gpu_x);
                  x_dirtyOnCpu = false;
                }

                gpuEmxMemcpyCpuToGpu_real_T(d_b, &g_inter_b, g_gpu_b);
                kh_reflectivity_calculation_gpu<<<u_grid, u_block>>>
                  (1.4142135623730951 * problemDef->params[0], b_r, l_gpu_x,
                   g_gpu_b);
                CUDACHECK(cudaGetLastError());
                b_dirtyOnCpu = false;
                c_b_dirtyOnGpu = true;
              }

              if (c_a_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(d_a, &f_inter_a);
                c_a_dirtyOnGpu = false;
              }

              nx = d_a->size[1];
              if (r4_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(r6, &inter_r6);
                r4_dirtyOnGpu = false;
              }

              qEnd = r6->size[0] * r6->size[1];
              r6->size[0] = 1;
              r6->size[1] = d_a->size[1];
              emxEnsureCapacity_real_T(r6, qEnd);
              r8_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((nx
                - 1) + 1L), &v_grid, &v_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                if (problemDef_cells_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(d_a, &f_inter_a, f_gpu_a);
                }

                gpuEmxMemcpyCpuToGpu_real_T(r6, &inter_r6, gpu_r6);
                lh_reflectivity_calculation_gpu<<<v_grid, v_block>>>(f_gpu_a,
                  gpu_nx, gpu_r6);
                CUDACHECK(cudaGetLastError());
                r8_dirtyOnCpu = false;
                r4_dirtyOnGpu = true;
              }

              if (c_b_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(d_b, &g_inter_b);
                c_b_dirtyOnGpu = false;
              }

              nx = d_b->size[1];
              if (r5_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(r7, &inter_r7);
                r5_dirtyOnGpu = false;
              }

              qEnd = r7->size[0] * r7->size[1];
              r7->size[0] = 1;
              r7->size[1] = d_b->size[1];
              emxEnsureCapacity_real_T(r7, qEnd);
              problemDef_cells_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((nx
                - 1) + 1L), &w_grid, &w_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                if (b_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(d_b, &g_inter_b, g_gpu_b);
                }

                gpuEmxMemcpyCpuToGpu_real_T(r7, &inter_r7, gpu_r7);
                mh_reflectivity_calculation_gpu<<<w_grid, w_block>>>(g_gpu_b,
                  gpu_nx, gpu_r7);
                CUDACHECK(cudaGetLastError());
                problemDef_cells_dirtyOnCpu = false;
                r5_dirtyOnGpu = true;
              }

              layerThicks = problemDef->nbs[static_cast<int32_T>
                (problemDef->contrastNbss[b_i]) - 1] / 2.0;
              CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL, cudaMemcpyHostToDevice));
              if (Lays_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(b_Lays, &b_inter_Lays, b_gpu_Lays);
              }

              nh_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(b_gpu_Lays, gpu_qEnd);
              CUDACHECK(cudaGetLastError());
              CUDACHECK(cudaMemcpy(&qEnd, gpu_qEnd, 4UL, cudaMemcpyDeviceToHost));
              ii_size[0] = qEnd;
              qEnd = kEnd - 1;
              Lays_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((ii_size[0] - 1) + 1L), &x_grid, &x_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                     cudaMemcpyHostToDevice));
                CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL,
                                     cudaMemcpyHostToDevice));
                Lays_dirtyOnCpu = false;
                CUDACHECK(cudaMemcpy(gpu_ii_size, &ii_size[0], 4UL,
                                     cudaMemcpyHostToDevice));
                if (r8_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(r6, &inter_r6, gpu_r6);
                }

                if (problemDef_cells_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(r7, &inter_r7, gpu_r7);
                }

                oh_reflectivity_calculation_gpu<<<x_grid, x_block>>>(gpu_r7,
                  gpu_r6, gpu_layerThicks, gpu_qEnd, *gpu_ii_size, b_gpu_Lays);
                CUDACHECK(cudaGetLastError());
                Lays_dirtyOnGpu = true;
              }

              // plot(x,Lays(:,(numberOfLayers*nrepeats)+1))
              kEnd = static_cast<int32_T>(2.0 * reps + 2.0);
              if (Lays_dirtyOnCpu) {
                CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL,
                                     cudaMemcpyHostToDevice));
              }

              ph_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(b_gpu_Lays, gpu_qEnd);
              CUDACHECK(cudaGetLastError());
              CUDACHECK(cudaMemcpy(&qEnd, gpu_qEnd, 4UL, cudaMemcpyDeviceToHost));
              ii_size[0] = qEnd;
              qEnd = kEnd - 1;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((ii_size[0] - 1) + 1L), &y_grid, &y_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL,
                                     cudaMemcpyHostToDevice));
                CUDACHECK(cudaMemcpy(gpu_ii_size, &ii_size[0], 4UL,
                                     cudaMemcpyHostToDevice));
                if (b_bool) {
                  gpuEmxMemcpyCpuToGpu_real_T(r2, &inter_r2, gpu_r2);
                }

                if (r1_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(r3, &inter_r3, gpu_r3);
                }

                qh_reflectivity_calculation_gpu<<<y_grid, y_block>>>(gpu_r3,
                  gpu_r2, nba / 2.0, gpu_qEnd, *gpu_ii_size, b_gpu_Lays);
                CUDACHECK(cudaGetLastError());
                Lays_dirtyOnGpu = true;
              }

              // plot(x,Lays(:,(numberOfLayers*nrepeats)+2))
              if (Lays_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(b_Lays, &b_inter_Lays);
                Lays_dirtyOnGpu = false;
              }

              vlen = b_Lays->size[1];
              if ((b_Lays->size[0] == 0) || (b_Lays->size[1] == 0)) {
                if (sz_dirtyOnCpu) {
                  CUDACHECK(cudaMemcpy(gpu_sz, &sz[0], 8UL,
                                       cudaMemcpyHostToDevice));
                }

                th_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                  1U)>>>(b_gpu_Lays, *gpu_sz);
                CUDACHECK(cudaGetLastError());
                kEnd = b_SLD->size[0];
                CUDACHECK(cudaMemcpy(&sz[0], gpu_sz, 8UL, cudaMemcpyDeviceToHost));
                b_SLD->size[0] = static_cast<int32_T>(sz[0]);
                emxEnsureCapacity_real_T(b_SLD, kEnd);
                r8_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((
                  static_cast<int32_T>(sz[0]) - 1) + 1L), &cb_grid, &cb_block,
                  1024U, 65535U);
                if (validLaunchParams) {
                  gpuEmxMemcpyCpuToGpu_real_T(b_SLD, &b_inter_SLD, b_gpu_SLD);
                  uh_reflectivity_calculation_gpu<<<cb_grid, cb_block>>>(*gpu_sz,
                    b_gpu_SLD);
                  CUDACHECK(cudaGetLastError());
                  r8_dirtyOnCpu = false;
                  SLD_dirtyOnGpu = true;
                }
              } else {
                vstride = b_Lays->size[0];
                kEnd = b_SLD->size[0];
                b_SLD->size[0] = b_Lays->size[0];
                emxEnsureCapacity_real_T(b_SLD, kEnd);
                r8_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((vstride - 1) + 1L), &ab_grid, &ab_block, 1024U, 65535U);
                if (validLaunchParams) {
                  gpuEmxMemcpyCpuToGpu_real_T(b_SLD, &b_inter_SLD, b_gpu_SLD);
                  rh_reflectivity_calculation_gpu<<<ab_grid, ab_block>>>
                    (b_gpu_Lays, vstride, b_gpu_SLD);
                  CUDACHECK(cudaGetLastError());
                  r8_dirtyOnCpu = false;
                  SLD_dirtyOnGpu = true;
                }

                for (k = 0; k <= vlen - 2; k++) {
                  xoffset = (k + 1) * vstride;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((vstride - 1) + 1L), &bb_grid, &bb_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    CUDACHECK(cudaMemcpy(gpu_xoffset, &xoffset, 4UL,
                                         cudaMemcpyHostToDevice));
                    if (r8_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(b_SLD, &b_inter_SLD, b_gpu_SLD);
                      r8_dirtyOnCpu = false;
                    }

                    sh_reflectivity_calculation_gpu<<<bb_grid, bb_block>>>
                      (gpu_xoffset, b_gpu_Lays, vstride, b_gpu_SLD);
                    CUDACHECK(cudaGetLastError());
                    SLD_dirtyOnGpu = true;
                  }
                }
              }

              // plot(x,SLD)
              xoffset = b_x->size[1];
              kEnd = b_sldProfile->size[0] * b_sldProfile->size[1];
              b_sldProfile->size[0] = xoffset;
              b_sldProfile->size[1] = 2;
              emxEnsureCapacity_real_T(b_sldProfile, kEnd);
              sldProfile_dirtyOnCpu = true;
              nx = xoffset - 1;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>(nx +
                1L), &db_grid, &db_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                gpuEmxMemcpyCpuToGpu_real_T(b_sldProfile, &b_inter_sldProfile,
                  b_gpu_sldProfile);
                if (x_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(b_x, &k_inter_x, l_gpu_x);
                }

                vh_reflectivity_calculation_gpu<<<db_grid, db_block>>>(l_gpu_x,
                  gpu_nx, b_gpu_sldProfile);
                CUDACHECK(cudaGetLastError());
                sldProfile_dirtyOnCpu = false;
                sldProfile_dirtyOnGpu = true;
              }

              if (SLD_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(b_SLD, &b_inter_SLD);
                SLD_dirtyOnGpu = false;
              }

              nx = b_SLD->size[0] - 1;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>(nx +
                1L), &eb_grid, &eb_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                if (sldProfile_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(b_sldProfile, &b_inter_sldProfile,
                    b_gpu_sldProfile);
                  sldProfile_dirtyOnCpu = false;
                }

                if (r8_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(b_SLD, &b_inter_SLD, b_gpu_SLD);
                }

                wh_reflectivity_calculation_gpu<<<eb_grid, eb_block>>>(b_gpu_SLD,
                  gpu_nx, b_gpu_sldProfile);
                CUDACHECK(cudaGetLastError());
                sldProfile_dirtyOnGpu = true;
              }
            } else {
              kEnd = b_sldProfile->size[0] * b_sldProfile->size[1];
              b_sldProfile->size[0] = 1;
              b_sldProfile->size[1] = 3;
              emxEnsureCapacity_real_T(b_sldProfile, kEnd);
              gpuEmxMemcpyCpuToGpu_real_T(b_sldProfile, &b_inter_sldProfile,
                b_gpu_sldProfile);
              ug_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(b_gpu_sldProfile);
              CUDACHECK(cudaGetLastError());
              sldProfile_dirtyOnCpu = false;
              sldProfile_dirtyOnGpu = true;
            }

            //  If required, then resample the SLD
            if (problemDef->resample[b_i] == 1.0) {
              boolean_T dataPoints_dirtyOnGpu;
              boolean_T dataBoxSize_dirtyOnCpu;

              //  Function handle for adaptive resampling
              //  f = @(x) sldFunc(x);
              //
              //  Keep points and minangle as constants for now
              //  will fix later
              if (dataBoxSize_dirtyOnGpu) {
                CUDACHECK(cudaMemcpy(&dataBoxSize[0], gpu_dataBoxSize, 16UL,
                                     cudaMemcpyDeviceToHost));
                dataBoxSize_dirtyOnGpu = false;
              }

              if (sldProfile_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(b_sldProfile, &b_inter_sldProfile);
                sldProfile_dirtyOnGpu = false;
              }

              dataBoxSize[0] = b_sldProfile->data[0];
              dataBoxSize[1] = b_sldProfile->data[b_sldProfile->size[0] - 1];

              //  adaptive: evaluates a matlab function on a given range
              //
              //  'adaptive.m' allows to sample a function using a reduced number of 
              //  points. It works iteratively adding new points where needed.
              //  It is especially useful for functions which are computationally intensive 
              //  (e.g. involve solving a differential equation).
              //
              //  Usage:
              //  XY = adaptive(func, [xstart, xend])
              //   evaluates 'func' in the range [xstart, xend]. Key-value arguments are 
              //   used to control the function evaluation. If the function 'func' returns 
              //   multiple output values, only the first one is used for the refinement 
              //   process, but all of them are calculated and returned as additional 
              //   columns in the output matrix. The output matrix XY contains the new 
              //   domain points in the first column and the output values in the other 
              //   columns.
              //  [x,yy] = adaptive(func, [xstart, xend])
              //    as before but separately returns the array with the domain points and 
              //    the array/matrix with the function output values.
              //  [x,yy] = adaptive(func, xarray, ...)
              //    as before but explicitly provide an initial array of domain points. 
              //
              //  Methods:
              //    'adaptive' provides three methods for refining the function evaluation: 
              //    1) add more points near the sharp corners, which are found by 
              //     considering the triangles formed by three successive points and 
              //     measuring the central angle.
              //    2) measure the area of the same triangles and add more points when the 
              //     area is bigger than a threshold.
              //    3) measure the length of the segments formed by pairs of successive 
              //     and split the segments which are longer than a threshold.
              //    If no methods is explicitly specified, the 'angle' method is used. 
              //
              //  Input parameters
              //   - func: input function (function handle)
              //   - initialDomain: initial domain points (1D array)
              //
              //  Optional key-value input parameters
              //   - 'nPoints': (default 20)
              //        initial number of domain points, only used if an initial domain 
              //        array is not excplitely provided.
              //   - 'maxRefinements': (default 10)
              //        Specifies the maximum number of refinement steps.
              //   - 'minAngle': (default 0.8*pi)
              //        Refine near the  points which forms, together with their left and right 
              //        neighbours, a triangle with central angle smaller than a given value. 
              //   - 'maxArea': (default 5e-4)
              //        Refine near the points which forms, together with their left and right 
              //        neighbours, a triangle with area larger than a threshold. The threshold 
              //        in normalized to the area enclosing th graph:
              //        threshold==maxArea*(max(x)-min(x))*(max(f(x))-min(f(x))) 
              //   - 'maxLength': (default Inf)
              //        Refine all the sements which are longer than a given threshold. The 
              //        threshold is relative to the input and output ranges. Specifically, 
              //        before applying the threshold, the data are normalized so that 
              //        max(x)-min(x)==1 and max(f(x))-min(f(x))==1.
              //   - 'minLength': (default 0)
              //        Exclude from the refinement process the segments which are shorter 
              //        than a given threshold. The threshold is relative to the input and 
              //        output ranges. Specifically, before applying the threshold, the 
              //        data are normalized so that max(x)-min(x)==1 and max(f(x))-min(f(x))==1. 
              //   - 'minSignal': (default 0.2)
              //        Exclude from the refinement process the points where the function is 
              //        below a threshold. The threshold is relative to the output range: In 
              //        this example threshold == 0.01*(max(f(x))-min(f(x))).
              //   - 'vectorizable': (default false)
              //        Specifies whether the input function accepts arrays as input 
              //        (e.g. f(x)==x.^2).
              //   - 'waitbar': (default false)
              //        Display a waitbar.
              //
              //  Output parameters
              //   - a NxM array where N is the number of domain points and M is the number 
              //     of output parameters of the input function.
              //
              //
              //  Examples:
              //
              //    % Refine a function near sharp corners. The option 'minAngle' is useful 
              //    % for having more points near the peaks of the function.
              //    f = @(x) exp(-x.^2/4).*sin(3*x);
              //    % for test-purpose also evaluate the function directly
              //    x2 = -10:0.01:10;
              //    y2 = f(x2);
              //    y = adaptive(f, [-5,5], 'minAngle',0.8*pi);
              //    figure(1); plot(x2,f(x2),'k--',y(:,1),y(:,2),'o-');
              //    legend('high sampling','adaptive')
              //    title('y = adaptive(f, [xstart, xend], ''minAngle'',0.8*pi)') 
              //    % as before but starting with an inital array of domain points 
              //    x = -5:5;
              //    y = adaptive(f, x, 'minAngle',0.8*pi);
              //    figure(2); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-'); 
              //    legend('initial sampling','high sampling','adaptive')
              //    title('y = adaptive(f, x, ''minAngle'',0.8*pi)')
              //
              //    % Refine a function near sharp corners, but do not split segments which 
              //    % are already shorter than 'minLength'.
              //    y = adaptive(f, x, 'minAngle',0.8*pi, 'minLength',0.05);
              //    figure(3); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-'); 
              //    legend('initial sampling','high sampling','adaptive')
              //    title('y = adaptive(f, x, ''minAngle'',0.8*pi, ''minLength'',0.05)'); 
              //
              //    % Refine a function until the areas of the triangles formed by 
              //    % triplets of successive points are smaller than 'maxArea'.
              //    y = adaptive(f, x, 'maxArea',1e-3);
              //    figure(4); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-'); 
              //    legend('initial sampling','high sampling','adaptive')
              //    title('y = adaptive(f, x, ''maxArea'',1e-3)')
              //
              //    % Refine a function until the segments formed by pairs of successive 
              //    % points are shorter than 'maxLength'.
              //    y = adaptive(f, x, 'maxLength',0.1);
              //    figure(5); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-'); 
              //    legend('initial sampling','high sampling','adaptive')
              //    title('y = adaptive(f, x, ''maxLength'',0.1)');
              //  Copyright
              //  2017, Alberto Comin -  LMU Muenchen
              //  Version changes:
              //
              //  24/01/2017: 1) new default: when no optional argument is given, use the 
              //   'angle' method as default 2) it is now possible to provide just the 
              //   start and the end of the function domain, instead of having to 
              //   explicitly provide an initial array 3) a new key-word argument 
              //   'nPoints' controls the number of initial domain points in the cases when 
              //   the initial array is not explicitly provided. 4) it is now possible to 
              //   return the domain points and the function values either as a single 2D 
              //   array or as two separate arrays.
              //  25/01/2017: fixed defaults for the case when no method is specified 
              //  Default settings
              //  units normalized to data range
              //  units normalized to data range
              //  units normalized to data range
              //  units normalized to data range
              //  Test-mode
              //  The test mode is activated by calling 'adaptive.m' with no input. 
              //  if nargin==0
              //    initialDomain =  -10:10;
              //    input_func = @(x) 100*exp(-(x+5.2).^2) + 50*exp(-5*(x-0.5).^2)+ 20*exp(-10*(x-5.8).^2); 
              //    thresholdingAngles = true;
              //    minAngle = 0.8*pi;
              //    thresholdingLength = true;
              //    minLength = 0.02;
              //    disp('Running adaptive.m in test mode');
              //    fprintf('input function: %s\n',func2str(input_func));
              //    disp('Plotting the function on a initial set of points');
              //    testFigureHandle = figure();
              //    plot(initialDomain, input_func(initialDomain),'bs-','LineWidth',1.5); 
              //    grid on; xlabel('x'); ylabel('y'); title('adaptive.m example'); 
              //  end
              //  Processing input arguments
              //  assert(isa(input_func,'function_handle'),'adaptiveFunctionEvaluation:ArgChk',... 
              //    'the first argument must be a function handle');
              //  assert(isnumeric(initialDomain) && isvector(initialDomain),... 
              //    'adaptiveFunctionEvaluation:ArgChk','initial points must be specified as a numeric vector'); 
              //
              //  if mod(nExtraArgIn,2)==1
              //    error('adaptiveFunctionEvaluation:ArgChk', ...
              //      'At least a key or a value is missing in the key-value arguments list.'); 
              //  end
              //  while n < nExtraArgIn
              //    switch lower(varargin{n})
              //      case 'minangle'
              //      case 'maxarea'
              //        maxArea = varargin{n+1};
              //        thresholdingArea = true;
              //        usingDefaultMethod = false;
              //        n = n+2;
              //      case 'maxlength'
              //        maxLength = varargin{n+1};
              //        thresholdingLength = true;
              //        usingDefaultMethod = false;
              //        n = n+2;
              //      case 'minlength'
              //        minLength = varargin{n+1};
              //        thresholdingLength = true;
              //        n = n+2;
              //      case 'minsignal'
              //        minSignal = varargin{n+1};
              //        thresholdingSignal = true;
              //        n = n+2;
              //      case 'npoints'
              //        nPoints = varargin{n+1};
              //        n = n+2;
              //      case 'vectorize'
              //        vectorizable = varargin{n+1};
              //        n = n+2;
              //      case 'maxrefinements'
              //        maxRefinements = varargin{n+1};
              //        n = n+2;
              //      case 'waitbar'
              //        displayWaitbar = varargin{n+1};
              //        n = n+2;
              //      otherwise
              //        error('adaptiveFunctionEvaluation:ArgChk',...
              //          ['unknown keyword argument: ', varargin{n}]);
              //    end
              //  end
              //  if no method is specified use the 'angle' method as default
              //  Initial function evaluation
              //  if initialDomain only contains the start and the end points, create a new 
              //  array with 'nPoints' points.
              layerThicks = dataBoxSize[0];
              CUDACHECK(cudaMemcpy(gpu_dataBoxSize, &dataBoxSize[0], 16UL,
                                   cudaMemcpyHostToDevice));
              dataBoxSize_dirtyOnCpu = false;
              yh_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(*gpu_dataBoxSize, *gpu_y);
              CUDACHECK(cudaGetLastError());
              if (dataBoxSize[0] == -dataBoxSize[1]) {
                ci_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(64U, 1U,
                  1U)>>>(*gpu_dataBoxSize, *gpu_y);
                CUDACHECK(cudaGetLastError());
                problemDef_cells_dirtyOnCpu = true;
              } else if (((dataBoxSize[0] < 0.0) != (dataBoxSize[1] < 0.0)) &&
                         ((fabs(dataBoxSize[0]) > 8.9884656743115785E+307) ||
                          (fabs(dataBoxSize[1]) > 8.9884656743115785E+307))) {
                bFactor = dataBoxSize[0] / 49.0;
                CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                     cudaMemcpyHostToDevice));
                bi_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(64U, 1U,
                  1U)>>>(bFactor, dataBoxSize[1] / 49.0, gpu_layerThicks, *gpu_y);
                CUDACHECK(cudaGetLastError());
                problemDef_cells_dirtyOnCpu = true;
              } else {
                CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                     cudaMemcpyHostToDevice));
                ai_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(64U, 1U,
                  1U)>>>((dataBoxSize[1] - dataBoxSize[0]) / 49.0,
                         gpu_layerThicks, *gpu_y);
                CUDACHECK(cudaGetLastError());
                problemDef_cells_dirtyOnCpu = true;
              }

              //  Normalize the input function: This step allows to use the same syntax for 
              //  functions with single or multiple output parameters.
              //  Remove this syntax for compile - AVH
              // func = @(x) normalizeFunction(x,sldProfile,vectorizable);
              //  Evaluate the input function on the initial set of points.
              //  Subfunctions
              //  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N 
              //  is the number of elements of x and M is the number of outputs of func. 
              //  All the outputs of func must be scalar.
              //  The optional parameter 'vectorizable' (default false) allows to specify 
              //  that the input function can be vectorized.
              //  Modified by AVH for use with coder
              // if (~exist('vectorizable','var') || isempty(vectorizable))
              //  end
              // abs(nargout(func)); %for anonymous functions nargout<0
              //  if vectorizable
              //    % For uniformity reasons, transform the 'x' array into a column vector. 
              //    % In this way it does not matter if it is given as a column or a row 
              //    % vector.
              //    [newValues{:}] = func(x(:));
              //    y = cell2mat(newValues);
              //  else
              for (c_i = 0; c_i < 50; c_i++) {
                //  Remove cell array so no need for cell2mat
                //  which won't compile - AVH
                // [newValues{:}] = func(x(i));
                // y(i,:) = cell2mat(newValues);
                //  sldVal = sldFunc(x,SLD)
                //  SLD = [x rho;....xn rho]
                //    x = value in Angstrom.
                //
                //  This function returns the SLD (y) value associated with the
                //  supplied value of x. SLD is a two column, XY array defining an 
                //  SLD profile. This function interpolates the SLD profile
                //  to return the SLD at the specific value of X. X can be a vector of 
                //  multiple points.
                //
                //  (c) Arwel Hughes 2019.
                //  Last modified - AVH, 26/11/19.
                //  global sldProfile
                //
                //  SLD = sldProfile;
                // SLD = getappdata(0,'sldFuncSLD');
                if (problemDef_cells_dirtyOnCpu) {
                  CUDACHECK(cudaMemcpy(&y[0], gpu_y, 400UL,
                                       cudaMemcpyDeviceToHost));
                  problemDef_cells_dirtyOnCpu = false;
                }

                layerThicks = y[c_i];
                kEnd = b_sldProfile->size[0] - 1;
                qEnd = j_x->size[0];
                j_x->size[0] = kEnd + 1;
                emxEnsureCapacity_boolean_T(j_x, qEnd);
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  (kEnd + 1L), &fb_grid, &fb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                       cudaMemcpyHostToDevice));
                  if (sldProfile_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(b_sldProfile,
                      &b_inter_sldProfile, b_gpu_sldProfile);
                    sldProfile_dirtyOnCpu = false;
                  }

                  gpuEmxMemcpyCpuToGpu_boolean_T(j_x, &l_inter_x, m_gpu_x);
                  di_reflectivity_calculation_gpu<<<fb_grid, fb_block>>>
                    (gpu_layerThicks, b_gpu_sldProfile, kEnd, m_gpu_x);
                  CUDACHECK(cudaGetLastError());
                  gpuEmxMemcpyGpuToCpu_boolean_T(j_x, &l_inter_x);
                }

                nx = j_x->size[0];
                vlen = 0;
                kEnd = d_ii->size[0];
                d_ii->size[0] = j_x->size[0];
                emxEnsureCapacity_int32_T(d_ii, kEnd);
                xoffset = 1;
                exitg2 = false;
                while ((!exitg2) && (xoffset <= nx)) {
                  if (j_x->data[xoffset - 1]) {
                    vlen++;
                    d_ii->data[vlen - 1] = xoffset;
                    if (vlen >= nx) {
                      exitg2 = true;
                    } else {
                      xoffset++;
                    }
                  } else {
                    xoffset++;
                  }
                }

                if (j_x->size[0] == 1) {
                  if (vlen == 0) {
                    d_ii->size[0] = 0;
                  }
                } else {
                  kEnd = d_ii->size[0];
                  if (1 > vlen) {
                    d_ii->size[0] = 0;
                  } else {
                    d_ii->size[0] = vlen;
                  }

                  emxEnsureCapacity_int32_T(d_ii, kEnd);
                }

                if (d_ii->size[0] != 0) {
                  kEnd = r13->size[0];
                  r13->size[0] = d_ii->size[0];
                  emxEnsureCapacity_real_T(r13, kEnd);
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((d_ii->size[0] - 1) + 1L), &ib_grid, &ib_block, 1024U,
                    65535U);
                  if (validLaunchParams) {
                    if (sldProfile_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(b_sldProfile,
                        &b_inter_sldProfile, b_gpu_sldProfile);
                      sldProfile_dirtyOnCpu = false;
                    }

                    gpuEmxMemcpyCpuToGpu_int32_T(d_ii, &d_inter_ii, d_gpu_ii);
                    gpuEmxMemcpyCpuToGpu_real_T(r13, &inter_r13, gpu_r13);
                    gi_reflectivity_calculation_gpu<<<ib_grid, ib_block>>>
                      (b_gpu_sldProfile, d_gpu_ii, gpu_r13);
                    CUDACHECK(cudaGetLastError());
                    r32_dirtyOnGpu = true;
                  }
                } else {
                  layerThicks = y[c_i];
                  kEnd = b_sldProfile->size[0] - 1;
                  qEnd = l_x->size[0];
                  l_x->size[0] = kEnd + 1;
                  emxEnsureCapacity_boolean_T(l_x, qEnd);
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    (kEnd + 1L), &gb_grid, &gb_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                         cudaMemcpyHostToDevice));
                    if (sldProfile_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(b_sldProfile,
                        &b_inter_sldProfile, b_gpu_sldProfile);
                      sldProfile_dirtyOnCpu = false;
                    }

                    gpuEmxMemcpyCpuToGpu_boolean_T(l_x, &m_inter_x, n_gpu_x);
                    ei_reflectivity_calculation_gpu<<<gb_grid, gb_block>>>
                      (b_gpu_sldProfile, gpu_layerThicks, kEnd, n_gpu_x);
                    CUDACHECK(cudaGetLastError());
                    gpuEmxMemcpyGpuToCpu_boolean_T(l_x, &m_inter_x);
                  }

                  nx = l_x->size[0];
                  vlen = 0;
                  kEnd = f_ii->size[0];
                  f_ii->size[0] = l_x->size[0];
                  emxEnsureCapacity_int32_T(f_ii, kEnd);
                  xoffset = 1;
                  exitg2 = false;
                  while ((!exitg2) && (xoffset <= nx)) {
                    if (l_x->data[xoffset - 1]) {
                      vlen++;
                      f_ii->data[vlen - 1] = xoffset;
                      if (vlen >= nx) {
                        exitg2 = true;
                      } else {
                        xoffset++;
                      }
                    } else {
                      xoffset++;
                    }
                  }

                  if (l_x->size[0] == 1) {
                    if (vlen == 0) {
                      f_ii->size[0] = 0;
                    }
                  } else {
                    kEnd = f_ii->size[0];
                    if (1 > vlen) {
                      f_ii->size[0] = 0;
                    } else {
                      f_ii->size[0] = vlen;
                    }

                    emxEnsureCapacity_int32_T(f_ii, kEnd);
                  }

                  layerThicks = y[c_i];
                  kEnd = b_sldProfile->size[0] - 1;
                  qEnd = n_x->size[0];
                  n_x->size[0] = kEnd + 1;
                  emxEnsureCapacity_boolean_T(n_x, qEnd);
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    (kEnd + 1L), &hb_grid, &hb_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                         cudaMemcpyHostToDevice));
                    if (sldProfile_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(b_sldProfile,
                        &b_inter_sldProfile, b_gpu_sldProfile);
                      sldProfile_dirtyOnCpu = false;
                    }

                    gpuEmxMemcpyCpuToGpu_boolean_T(n_x, &n_inter_x, o_gpu_x);
                    fi_reflectivity_calculation_gpu<<<hb_grid, hb_block>>>
                      (b_gpu_sldProfile, gpu_layerThicks, kEnd, o_gpu_x);
                    CUDACHECK(cudaGetLastError());
                    gpuEmxMemcpyGpuToCpu_boolean_T(n_x, &n_inter_x);
                  }

                  nx = n_x->size[0];
                  vlen = 0;
                  kEnd = h_ii->size[0];
                  h_ii->size[0] = n_x->size[0];
                  emxEnsureCapacity_int32_T(h_ii, kEnd);
                  xoffset = 1;
                  exitg2 = false;
                  while ((!exitg2) && (xoffset <= nx)) {
                    if (n_x->data[xoffset - 1]) {
                      vlen++;
                      h_ii->data[vlen - 1] = xoffset;
                      if (vlen >= nx) {
                        exitg2 = true;
                      } else {
                        xoffset++;
                      }
                    } else {
                      xoffset++;
                    }
                  }

                  if (n_x->size[0] == 1) {
                    if (vlen == 0) {
                      h_ii->size[0] = 0;
                    }
                  } else {
                    kEnd = h_ii->size[0];
                    if (1 > vlen) {
                      h_ii->size[0] = 0;
                    } else {
                      h_ii->size[0] = vlen;
                    }

                    emxEnsureCapacity_int32_T(h_ii, kEnd);
                  }

                  layerThicks = (y[c_i] - b_sldProfile->data[f_ii->data
                                 [f_ii->size[0] - 1] - 1]) * (fabs
                    (b_sldProfile->data[(h_ii->data[0] + b_sldProfile->size[0])
                     - 1] - b_sldProfile->data[(f_ii->data[f_ii->size[0] - 1] +
                    b_sldProfile->size[0]) - 1]) / (b_sldProfile->data
                    [h_ii->data[0] - 1] - b_sldProfile->data[f_ii->data
                    [f_ii->size[0] - 1] - 1]));
                  if (b_sldProfile->data[(f_ii->data[f_ii->size[0] - 1] +
                                          b_sldProfile->size[0]) - 1] <
                      b_sldProfile->data[(h_ii->data[0] + b_sldProfile->size[0])
                      - 1]) {
                    kEnd = r13->size[0];
                    r13->size[0] = 1;
                    emxEnsureCapacity_real_T(r13, kEnd);
                    r13->data[0] = b_sldProfile->data[(f_ii->data[f_ii->size[0]
                      - 1] + b_sldProfile->size[0]) - 1] + layerThicks;
                  } else {
                    kEnd = r13->size[0];
                    r13->size[0] = 1;
                    emxEnsureCapacity_real_T(r13, kEnd);
                    r13->data[0] = b_sldProfile->data[(f_ii->data[f_ii->size[0]
                      - 1] + b_sldProfile->size[0]) - 1] - layerThicks;
                  }

                  // sldVal = interp1(z,rho,x);
                }

                if (r32_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(r13, &inter_r13);
                  r32_dirtyOnGpu = false;
                }

                hiVal[c_i] = r13->data[0];
                hiVal_dirtyOnCpu = true;
              }

              // end
              // dataPoints = [initialDomain(:), func(initialDomain(:))];
              if (hiVal_dirtyOnCpu) {
                CUDACHECK(cudaMemcpy(gpu_hiVal, &hiVal[0], 400UL,
                                     cudaMemcpyHostToDevice));
                hiVal_dirtyOnCpu = false;
              }

              hi_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(64U, 1U,
                1U)>>>(*gpu_hiVal, *gpu_y, *b_gpu_y);
              CUDACHECK(cudaGetLastError());
              kEnd = b_dataPoints->size[0] * b_dataPoints->size[1];
              b_dataPoints->size[0] = 50;
              b_dataPoints->size[1] = 2;
              emxEnsureCapacity_real_T(b_dataPoints, kEnd);
              gpuEmxMemcpyCpuToGpu_real_T(b_dataPoints, &c_inter_dataPoints,
                c_gpu_dataPoints);
              ii_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(128U, 1U,
                1U)>>>(*b_gpu_y, c_gpu_dataPoints);
              CUDACHECK(cudaGetLastError());
              sz_dirtyOnCpu = false;
              dataPoints_dirtyOnGpu = true;

              //  Iterative function refinement
              //  if displayWaitbar
              //    refinementWaitbar = waitbar(0,['Evaluating function ',func2str(func)],... 
              //      'CreateCancelBtn','setappdata(gcbf,''canceling'',true)');
              //    setappdata(refinementWaitbar,'canceling',false)
              //  end
              for (int32_T nRefinements = 0; nRefinements < 10; nRefinements++)
              {
                //  calculate the box which encloses the current data points:
                if (dataPoints_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(b_dataPoints, &c_inter_dataPoints);
                  dataPoints_dirtyOnGpu = false;
                }

                vlen = b_dataPoints->size[0];
                if (dataBoxSize_dirtyOnCpu) {
                  CUDACHECK(cudaMemcpy(gpu_dataBoxSize, &dataBoxSize[0], 16UL,
                                       cudaMemcpyHostToDevice));
                  dataBoxSize_dirtyOnCpu = false;
                }

                if (sz_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(b_dataPoints, &c_inter_dataPoints,
                    c_gpu_dataPoints);
                  sz_dirtyOnCpu = false;
                }

                ji_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                  1U)>>>(vlen, c_gpu_dataPoints, *gpu_dataBoxSize);
                CUDACHECK(cudaGetLastError());
                vlen = b_dataPoints->size[0];
                ki_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                  1U)>>>(vlen, c_gpu_dataPoints, *gpu_minval);
                CUDACHECK(cudaGetLastError());
                li_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                  1U)>>>(*gpu_minval, *gpu_dataBoxSize);
                CUDACHECK(cudaGetLastError());
                dataBoxSize_dirtyOnGpu = true;

                //  Each point is considered as the central corner of the triangle formed 
                //  with its left and right hand side neighbours. The first and the last 
                //  points are not the central corner of any triangle, so for N points 
                //  there are only N-2 triangles.
                //  Calculate the central angle of the triangles formed by data points. 
                //  For input size NxM, the output size is (N-2)xN, because the first and the 
                //  last point are not the central corner of any triangle.
                //  Normalize data, because angles depend on scaling.
                kEnd = b_dataPoints->size[0];
                qEnd = h_b->size[0] * h_b->size[1];
                h_b->size[0] = kEnd;
                h_b->size[1] = 2;
                emxEnsureCapacity_real_T(h_b, qEnd);
                xoffset = b_dataPoints->size[0];
                for (nx = 0; nx < 2; nx++) {
                  vstride = nx * xoffset;
                  for (i2 = 0; i2 < xoffset; i2++) {
                    if (dataBoxSize_dirtyOnGpu) {
                      CUDACHECK(cudaMemcpy(&dataBoxSize[0], gpu_dataBoxSize,
                                           16UL, cudaMemcpyDeviceToHost));
                      dataBoxSize_dirtyOnGpu = false;
                    }

                    h_b->data[vstride + i2] = dataBoxSize[nx];
                  }
                }

                vlen = b_dataPoints->size[0];
                mi_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                  1U)>>>(vlen, c_gpu_dataPoints, *gpu_minval);
                CUDACHECK(cudaGetLastError());
                problemDef_cells_dirtyOnCpu = true;
                kEnd = b_dataPoints->size[0];
                qEnd = r15->size[0] * r15->size[1];
                r15->size[0] = kEnd;
                r15->size[1] = 2;
                emxEnsureCapacity_real_T(r15, qEnd);
                xoffset = b_dataPoints->size[0];
                for (nx = 0; nx < 2; nx++) {
                  vstride = nx * xoffset;
                  for (i2 = 0; i2 < xoffset; i2++) {
                    if (problemDef_cells_dirtyOnCpu) {
                      CUDACHECK(cudaMemcpy(&minval[0], gpu_minval, 16UL,
                                           cudaMemcpyDeviceToHost));
                      problemDef_cells_dirtyOnCpu = false;
                    }

                    r15->data[vstride + i2] = minval[nx];
                  }
                }

                kEnd = b_dataPoints->size[0] - 1;
                qEnd = b_normalizedData->size[0] * b_normalizedData->size[1];
                b_normalizedData->size[0] = kEnd + 1;
                b_normalizedData->size[1] = 2;
                emxEnsureCapacity_real_T(b_normalizedData, qEnd);
                problemDef_cells_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((kEnd + 1L) * 2L), &jb_grid, &jb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  gpuEmxMemcpyCpuToGpu_real_T(r15, &inter_r15, gpu_r15);
                  gpuEmxMemcpyCpuToGpu_real_T(h_b, &h_inter_b, h_gpu_b);
                  gpuEmxMemcpyCpuToGpu_real_T(b_normalizedData,
                    &b_inter_normalizedData, b_gpu_normalizedData);
                  ni_reflectivity_calculation_gpu<<<jb_grid, jb_block>>>(gpu_r15,
                    h_gpu_b, c_gpu_dataPoints, kEnd, b_gpu_normalizedData);
                  CUDACHECK(cudaGetLastError());
                  problemDef_cells_dirtyOnCpu = false;
                  normalizedData_dirtyOnGpu = true;
                }

                //  calculate cosine of central angles
                //  Return the sides (deltaX, deltaY) of the triangles formed by data points. 
                //  For input size NxM, the output size is (N-2)xN, because the first and the 
                //  last point are not the central corner of any triangle.
                if (normalizedData_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(b_normalizedData,
                    &b_inter_normalizedData);
                  normalizedData_dirtyOnGpu = false;
                }

                kEnd = b_normalizedData->size[0] - 2;
                qEnd = b_firstStep->size[0] * b_firstStep->size[1];
                b_firstStep->size[0] = kEnd;
                b_firstStep->size[1] = 2;
                emxEnsureCapacity_real_T(b_firstStep, qEnd);
                r8_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  (((kEnd - 1) + 1L) * 2L), &kb_grid, &kb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  if (problemDef_cells_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(b_normalizedData,
                      &b_inter_normalizedData, b_gpu_normalizedData);
                    problemDef_cells_dirtyOnCpu = false;
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(b_firstStep, &b_inter_firstStep,
                    b_gpu_firstStep);
                  oi_reflectivity_calculation_gpu<<<kb_grid, kb_block>>>
                    (b_gpu_normalizedData, kEnd, b_gpu_firstStep);
                  CUDACHECK(cudaGetLastError());
                  r8_dirtyOnCpu = false;
                  firstStep_dirtyOnGpu = true;
                }

                kEnd = b_normalizedData->size[0] - 1;
                qEnd = b_secondStep->size[0] * b_secondStep->size[1];
                b_secondStep->size[0] = kEnd - 1;
                b_secondStep->size[1] = 2;
                emxEnsureCapacity_real_T(b_secondStep, qEnd);
                r1_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  (((kEnd - 2) + 1L) * 2L), &lb_grid, &lb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  if (problemDef_cells_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(b_normalizedData,
                      &b_inter_normalizedData, b_gpu_normalizedData);
                    problemDef_cells_dirtyOnCpu = false;
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(b_secondStep, &b_inter_secondStep,
                    b_gpu_secondStep);
                  pi_reflectivity_calculation_gpu<<<lb_grid, lb_block>>>
                    (b_gpu_normalizedData, kEnd, b_gpu_secondStep);
                  CUDACHECK(cudaGetLastError());
                  r1_dirtyOnCpu = false;
                  secondStep_dirtyOnGpu = true;
                }

                kEnd = b_normalizedData->size[0] - 1;
                qEnd = b_longStep->size[0] * b_longStep->size[1];
                b_longStep->size[0] = kEnd - 1;
                b_longStep->size[1] = 2;
                emxEnsureCapacity_real_T(b_longStep, qEnd);
                b_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  (((kEnd - 2) + 1L) * 2L), &mb_grid, &mb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  if (problemDef_cells_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(b_normalizedData,
                      &b_inter_normalizedData, b_gpu_normalizedData);
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(b_longStep, &b_inter_longStep,
                    b_gpu_longStep);
                  qi_reflectivity_calculation_gpu<<<mb_grid, mb_block>>>
                    (b_gpu_normalizedData, kEnd, b_gpu_longStep);
                  CUDACHECK(cudaGetLastError());
                  b_dirtyOnCpu = false;
                  longStep_dirtyOnGpu = true;
                }

                //  calculate area of squares of length of triangle sides
                kEnd = e_z1->size[0];
                if (firstStep_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(b_firstStep, &b_inter_firstStep);
                  firstStep_dirtyOnGpu = false;
                }

                e_z1->size[0] = b_firstStep->size[0];
                emxEnsureCapacity_real_T(e_z1, kEnd);
                xoffset_dirtyOnCpu = true;
                nx = b_firstStep->size[0];
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((nx - 1) + 1L), &nb_grid, &nb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                  if (r8_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(b_firstStep, &b_inter_firstStep,
                      b_gpu_firstStep);
                    r8_dirtyOnCpu = false;
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(e_z1, &h_inter_z1, h_gpu_z1);
                  ri_reflectivity_calculation_gpu<<<nb_grid, nb_block>>>
                    (b_gpu_firstStep, gpu_nx, h_gpu_z1);
                  CUDACHECK(cudaGetLastError());
                  xoffset_dirtyOnCpu = false;
                  z1_dirtyOnGpu = true;
                }

                if (b_z1_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(g_z1, &i_inter_z1);
                  b_z1_dirtyOnGpu = false;
                }

                kEnd = g_z1->size[0];
                g_z1->size[0] = b_firstStep->size[0];
                emxEnsureCapacity_real_T(g_z1, kEnd);
                Lays_dirtyOnCpu = true;
                nx = b_firstStep->size[0];
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((nx - 1) + 1L), &ob_grid, &ob_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                  if (r8_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(b_firstStep, &b_inter_firstStep,
                      b_gpu_firstStep);
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(g_z1, &i_inter_z1, i_gpu_z1);
                  si_reflectivity_calculation_gpu<<<ob_grid, ob_block>>>
                    (b_gpu_firstStep, gpu_nx, i_gpu_z1);
                  CUDACHECK(cudaGetLastError());
                  Lays_dirtyOnCpu = false;
                  b_z1_dirtyOnGpu = true;
                }

                kEnd = b_firstStepSquared->size[0];
                if (z1_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(e_z1, &h_inter_z1);
                  z1_dirtyOnGpu = false;
                }

                b_firstStepSquared->size[0] = e_z1->size[0];
                emxEnsureCapacity_real_T(b_firstStepSquared, kEnd);
                b_bool = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((e_z1->size[0] - 1) + 1L), &pb_grid, &pb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  if (xoffset_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(e_z1, &h_inter_z1, h_gpu_z1);
                  }

                  if (Lays_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(g_z1, &i_inter_z1, i_gpu_z1);
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(b_firstStepSquared,
                    &b_inter_firstStepSquared, b_gpu_firstStepSquared);
                  ti_reflectivity_calculation_gpu<<<pb_grid, pb_block>>>
                    (i_gpu_z1, h_gpu_z1, b_gpu_firstStepSquared);
                  CUDACHECK(cudaGetLastError());
                  b_bool = false;
                  firstStepSquared_dirtyOnGpu = true;
                }

                kEnd = i_z1->size[0];
                if (secondStep_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(b_secondStep, &b_inter_secondStep);
                  secondStep_dirtyOnGpu = false;
                }

                i_z1->size[0] = b_secondStep->size[0];
                emxEnsureCapacity_real_T(i_z1, kEnd);
                xoffset_dirtyOnCpu = true;
                nx = b_secondStep->size[0];
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((nx - 1) + 1L), &qb_grid, &qb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                  if (r1_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(b_secondStep,
                      &b_inter_secondStep, b_gpu_secondStep);
                    r1_dirtyOnCpu = false;
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(i_z1, &j_inter_z1, j_gpu_z1);
                  ui_reflectivity_calculation_gpu<<<qb_grid, qb_block>>>
                    (b_gpu_secondStep, gpu_nx, j_gpu_z1);
                  CUDACHECK(cudaGetLastError());
                  xoffset_dirtyOnCpu = false;
                  c_z1_dirtyOnGpu = true;
                }

                if (d_z1_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(k_z1, &k_inter_z1);
                  d_z1_dirtyOnGpu = false;
                }

                kEnd = k_z1->size[0];
                k_z1->size[0] = b_secondStep->size[0];
                emxEnsureCapacity_real_T(k_z1, kEnd);
                Lays_dirtyOnCpu = true;
                nx = b_secondStep->size[0];
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((nx - 1) + 1L), &rb_grid, &rb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                  if (r1_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(b_secondStep,
                      &b_inter_secondStep, b_gpu_secondStep);
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(k_z1, &k_inter_z1, k_gpu_z1);
                  vi_reflectivity_calculation_gpu<<<rb_grid, rb_block>>>
                    (b_gpu_secondStep, gpu_nx, k_gpu_z1);
                  CUDACHECK(cudaGetLastError());
                  Lays_dirtyOnCpu = false;
                  d_z1_dirtyOnGpu = true;
                }

                if (secondStepSquared_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(b_secondStepSquared,
                    &b_inter_secondStepSquared);
                  secondStepSquared_dirtyOnGpu = false;
                }

                kEnd = b_secondStepSquared->size[0];
                if (c_z1_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(i_z1, &j_inter_z1);
                  c_z1_dirtyOnGpu = false;
                }

                b_secondStepSquared->size[0] = i_z1->size[0];
                emxEnsureCapacity_real_T(b_secondStepSquared, kEnd);
                problemDef_cells_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((i_z1->size[0] - 1) + 1L), &sb_grid, &sb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  if (xoffset_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(i_z1, &j_inter_z1, j_gpu_z1);
                  }

                  if (Lays_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(k_z1, &k_inter_z1, k_gpu_z1);
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(b_secondStepSquared,
                    &b_inter_secondStepSquared, b_gpu_secondStepSquared);
                  wi_reflectivity_calculation_gpu<<<sb_grid, sb_block>>>
                    (k_gpu_z1, j_gpu_z1, b_gpu_secondStepSquared);
                  CUDACHECK(cudaGetLastError());
                  problemDef_cells_dirtyOnCpu = false;
                  secondStepSquared_dirtyOnGpu = true;
                }

                if (e_z1_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(m_z1, &l_inter_z1);
                  e_z1_dirtyOnGpu = false;
                }

                kEnd = m_z1->size[0];
                if (longStep_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(b_longStep, &b_inter_longStep);
                  longStep_dirtyOnGpu = false;
                }

                m_z1->size[0] = b_longStep->size[0];
                emxEnsureCapacity_real_T(m_z1, kEnd);
                xoffset_dirtyOnCpu = true;
                nx = b_longStep->size[0];
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((nx - 1) + 1L), &tb_grid, &tb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                  if (b_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(b_longStep, &b_inter_longStep,
                      b_gpu_longStep);
                    b_dirtyOnCpu = false;
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(m_z1, &l_inter_z1, l_gpu_z1);
                  xi_reflectivity_calculation_gpu<<<tb_grid, tb_block>>>
                    (b_gpu_longStep, gpu_nx, l_gpu_z1);
                  CUDACHECK(cudaGetLastError());
                  xoffset_dirtyOnCpu = false;
                  e_z1_dirtyOnGpu = true;
                }

                if (f_z1_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(n_z1, &m_inter_z1);
                  f_z1_dirtyOnGpu = false;
                }

                kEnd = n_z1->size[0];
                n_z1->size[0] = b_longStep->size[0];
                emxEnsureCapacity_real_T(n_z1, kEnd);
                Lays_dirtyOnCpu = true;
                nx = b_longStep->size[0];
                r8_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((nx - 1) + 1L), &ub_grid, &ub_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                  r8_dirtyOnCpu = false;
                  if (b_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(b_longStep, &b_inter_longStep,
                      b_gpu_longStep);
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(n_z1, &m_inter_z1, m_gpu_z1);
                  yi_reflectivity_calculation_gpu<<<ub_grid, ub_block>>>
                    (b_gpu_longStep, gpu_nx, m_gpu_z1);
                  CUDACHECK(cudaGetLastError());
                  Lays_dirtyOnCpu = false;
                  f_z1_dirtyOnGpu = true;
                }

                if (b_x_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(g_x, &o_inter_x);
                  b_x_dirtyOnGpu = false;
                }

                kEnd = g_x->size[0];
                if (firstStepSquared_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_real_T(b_firstStepSquared,
                    &b_inter_firstStepSquared);
                  firstStepSquared_dirtyOnGpu = false;
                }

                g_x->size[0] = b_firstStepSquared->size[0];
                emxEnsureCapacity_real_T(g_x, kEnd);
                x_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((b_firstStepSquared->size[0] - 1) + 1L), &vb_grid, &vb_block,
                  1024U, 65535U);
                if (validLaunchParams) {
                  if (b_bool) {
                    gpuEmxMemcpyCpuToGpu_real_T(b_firstStepSquared,
                      &b_inter_firstStepSquared, b_gpu_firstStepSquared);
                    b_bool = false;
                  }

                  if (problemDef_cells_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(b_secondStepSquared,
                      &b_inter_secondStepSquared, b_gpu_secondStepSquared);
                    problemDef_cells_dirtyOnCpu = false;
                  }

                  gpuEmxMemcpyCpuToGpu_real_T(g_x, &o_inter_x, p_gpu_x);
                  aj_reflectivity_calculation_gpu<<<vb_grid, vb_block>>>
                    (b_gpu_secondStepSquared, b_gpu_firstStepSquared, p_gpu_x);
                  CUDACHECK(cudaGetLastError());
                  x_dirtyOnCpu = false;
                  b_x_dirtyOnGpu = true;
                }

                if (r8_dirtyOnCpu) {
                  CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                }

                if (x_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(g_x, &o_inter_x, p_gpu_x);
                }

                bj_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                  1U)>>>(p_gpu_x, gpu_nx);
                CUDACHECK(cudaGetLastError());
                CUDACHECK(cudaMemcpy(&nx, gpu_nx, 4UL, cudaMemcpyDeviceToHost));
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((nx - 1) + 1L), &wb_grid, &wb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  cj_reflectivity_calculation_gpu<<<wb_grid, wb_block>>>(gpu_nx,
                    p_gpu_x);
                  CUDACHECK(cudaGetLastError());
                  b_x_dirtyOnGpu = true;
                }

                if (c_x_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_creal_T(h_x, &p_inter_x);
                  c_x_dirtyOnGpu = false;
                }

                kEnd = h_x->size[0];
                h_x->size[0] = b_firstStepSquared->size[0];
                emxEnsureCapacity_creal_T(h_x, kEnd);
                x_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((b_firstStepSquared->size[0] - 1) + 1L), &xb_grid, &xb_block,
                  1024U, 65535U);
                if (validLaunchParams) {
                  if (b_bool) {
                    gpuEmxMemcpyCpuToGpu_real_T(b_firstStepSquared,
                      &b_inter_firstStepSquared, b_gpu_firstStepSquared);
                  }

                  if (problemDef_cells_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(b_secondStepSquared,
                      &b_inter_secondStepSquared, b_gpu_secondStepSquared);
                  }

                  if (xoffset_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(m_z1, &l_inter_z1, l_gpu_z1);
                  }

                  if (Lays_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_real_T(n_z1, &m_inter_z1, m_gpu_z1);
                  }

                  gpuEmxMemcpyCpuToGpu_creal_T(h_x, &p_inter_x, q_gpu_x);
                  dj_reflectivity_calculation_gpu<<<xb_grid, xb_block>>>(p_gpu_x,
                    m_gpu_z1, l_gpu_z1, b_gpu_secondStepSquared,
                    b_gpu_firstStepSquared, q_gpu_x);
                  CUDACHECK(cudaGetLastError());
                  x_dirtyOnCpu = false;
                  c_x_dirtyOnGpu = true;
                }

                if (x_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_creal_T(h_x, &p_inter_x, q_gpu_x);
                }

                ej_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                  1U)>>>(q_gpu_x, gpu_nx);
                CUDACHECK(cudaGetLastError());
                CUDACHECK(cudaMemcpy(&nx, gpu_nx, 4UL, cudaMemcpyDeviceToHost));
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((nx - 1) + 1L), &yb_grid, &yb_block, 1024U, 65535U);
                if (validLaunchParams) {
                  fj_reflectivity_calculation_gpu<<<yb_grid, yb_block>>>(gpu_nx,
                    q_gpu_x);
                  CUDACHECK(cudaGetLastError());
                  c_x_dirtyOnGpu = true;
                }

                kEnd = b_trianglesToRefine->size[0];
                b_trianglesToRefine->size[0] = b_dataPoints->size[0] - 2;
                emxEnsureCapacity_boolean_T(b_trianglesToRefine, kEnd);
                problemDef_cells_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((b_dataPoints->size[0] - 3) + 1L), &ac_grid, &ac_block, 1024U,
                  65535U);
                if (validLaunchParams) {
                  gpuEmxMemcpyCpuToGpu_boolean_T(b_trianglesToRefine,
                    &c_inter_trianglesToRefine, c_gpu_trianglesToRefine);
                  gj_reflectivity_calculation_gpu<<<ac_grid, ac_block>>>(q_gpu_x,
                    c_gpu_dataPoints, c_gpu_trianglesToRefine);
                  CUDACHECK(cudaGetLastError());
                  problemDef_cells_dirtyOnCpu = false;
                  trianglesToRefine_dirtyOnGpu = true;
                }

                //  For N points there are N-2 triangles and N-1 triangle sides. Each 
                //  triangle side is a segment, which can be split or not depending on the 
                //  refinement parameters.
                kEnd = d_trianglesToRefine->size[0];
                if (trianglesToRefine_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_boolean_T(b_trianglesToRefine,
                    &c_inter_trianglesToRefine);
                  trianglesToRefine_dirtyOnGpu = false;
                }

                d_trianglesToRefine->size[0] = b_trianglesToRefine->size[0] + 1;
                emxEnsureCapacity_boolean_T(d_trianglesToRefine, kEnd);
                r8_dirtyOnCpu = true;
                nx = b_trianglesToRefine->size[0] - 1;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>(nx
                  + 1L), &bc_grid, &bc_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                  if (problemDef_cells_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_boolean_T(b_trianglesToRefine,
                      &c_inter_trianglesToRefine, c_gpu_trianglesToRefine);
                    problemDef_cells_dirtyOnCpu = false;
                  }

                  gpuEmxMemcpyCpuToGpu_boolean_T(d_trianglesToRefine,
                    &d_inter_trianglesToRefine, d_gpu_trianglesToRefine);
                  hj_reflectivity_calculation_gpu<<<bc_grid, bc_block>>>
                    (c_gpu_trianglesToRefine, gpu_nx, d_gpu_trianglesToRefine);
                  CUDACHECK(cudaGetLastError());
                  r8_dirtyOnCpu = false;
                }

                if (problemDef_cells_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_boolean_T(b_trianglesToRefine,
                    &c_inter_trianglesToRefine, c_gpu_trianglesToRefine);
                }

                if (r8_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_boolean_T(d_trianglesToRefine,
                    &d_inter_trianglesToRefine, d_gpu_trianglesToRefine);
                }

                ij_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                  1U)>>>(c_gpu_trianglesToRefine, d_gpu_trianglesToRefine);
                CUDACHECK(cudaGetLastError());
                if (r33_dirtyOnGpu) {
                  gpuEmxMemcpyGpuToCpu_boolean_T(r33, &inter_r33);
                }

                kEnd = r33->size[0];
                r33->size[0] = b_trianglesToRefine->size[0] + 1;
                emxEnsureCapacity_boolean_T(r33, kEnd);
                gpuEmxMemcpyCpuToGpu_boolean_T(r33, &inter_r33, gpu_r33);
                jj_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                  1U)>>>(gpu_r33);
                CUDACHECK(cudaGetLastError());
                r33_dirtyOnGpu = true;
                nx = b_trianglesToRefine->size[0] - 1;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>(nx
                  + 1L), &cc_grid, &cc_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
                  kj_reflectivity_calculation_gpu<<<cc_grid, cc_block>>>
                    (c_gpu_trianglesToRefine, gpu_nx, gpu_r33);
                  CUDACHECK(cudaGetLastError());
                }

                kEnd = b_segmentsToSplit->size[0];
                gpuEmxMemcpyGpuToCpu_boolean_T(d_trianglesToRefine,
                  &d_inter_trianglesToRefine);
                b_segmentsToSplit->size[0] = d_trianglesToRefine->size[0];
                emxEnsureCapacity_boolean_T(b_segmentsToSplit, kEnd);
                r1_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                  ((d_trianglesToRefine->size[0] - 1) + 1L), &dc_grid, &dc_block,
                  1024U, 65535U);
                if (validLaunchParams) {
                  gpuEmxMemcpyCpuToGpu_boolean_T(b_segmentsToSplit,
                    &b_inter_segmentsToSplit, b_gpu_segmentsToSplit);
                  lj_reflectivity_calculation_gpu<<<dc_grid, dc_block>>>(gpu_r33,
                    d_gpu_trianglesToRefine, b_gpu_segmentsToSplit);
                  CUDACHECK(cudaGetLastError());
                  r1_dirtyOnCpu = false;
                  segmentsToSplit_dirtyOnGpu = true;
                }

                b_bool = false;
                xoffset = 1;
                do {
                  exitg1 = 0;
                  if (segmentsToSplit_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_boolean_T(b_segmentsToSplit,
                      &b_inter_segmentsToSplit);
                    segmentsToSplit_dirtyOnGpu = false;
                  }

                  if (xoffset <= b_segmentsToSplit->size[0]) {
                    problemDef_cells_dirtyOnCpu = !b_segmentsToSplit->
                      data[xoffset - 1];
                    if (!problemDef_cells_dirtyOnCpu) {
                      b_bool = true;
                      exitg1 = 1;
                    } else {
                      xoffset++;
                    }
                  } else {
                    exitg1 = 1;
                  }
                } while (exitg1 == 0);

                if (b_bool) {
                  //  increaseSampling increase the sampling of an input function 
                  vstride = b_segmentsToSplit->size[0];
                  xoffset = 0;
                  for (c_i = 0; c_i < vstride; c_i++) {
                    if (b_segmentsToSplit->data[c_i]) {
                      xoffset++;
                    }
                  }

                  kEnd = b_newDataPoints->size[0] * b_newDataPoints->size[1];
                  b_newDataPoints->size[0] = xoffset;
                  b_newDataPoints->size[1] = 2;
                  emxEnsureCapacity_real_T(b_newDataPoints, kEnd);
                  r8_dirtyOnCpu = true;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((xoffset * 2 - 1) + 1L), &ec_grid, &ec_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    CUDACHECK(cudaMemcpy(gpu_xoffset, &xoffset, 4UL,
                                         cudaMemcpyHostToDevice));
                    gpuEmxMemcpyCpuToGpu_real_T(b_newDataPoints,
                      &b_inter_newDataPoints, b_gpu_newDataPoints);
                    mj_reflectivity_calculation_gpu<<<ec_grid, ec_block>>>
                      (gpu_xoffset, b_gpu_newDataPoints);
                    CUDACHECK(cudaGetLastError());
                    r8_dirtyOnCpu = false;
                    newDataPoints_dirtyOnGpu = true;
                  }

                  if (r21_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_boolean_T(r24, &inter_r24);
                  }

                  kEnd = r24->size[0];
                  r24->size[0] = b_segmentsToSplit->size[0] + 1;
                  emxEnsureCapacity_boolean_T(r24, kEnd);
                  problemDef_cells_dirtyOnCpu = true;
                  nx = b_segmentsToSplit->size[0] - 1;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    (nx + 1L), &fc_grid, &fc_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL,
                                         cudaMemcpyHostToDevice));
                    if (r1_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_boolean_T(b_segmentsToSplit,
                        &b_inter_segmentsToSplit, b_gpu_segmentsToSplit);
                      r1_dirtyOnCpu = false;
                    }

                    gpuEmxMemcpyCpuToGpu_boolean_T(r24, &inter_r24, gpu_r24);
                    nj_reflectivity_calculation_gpu<<<fc_grid, fc_block>>>
                      (b_gpu_segmentsToSplit, gpu_nx, gpu_r24);
                    CUDACHECK(cudaGetLastError());
                    problemDef_cells_dirtyOnCpu = false;
                  }

                  if (r1_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_boolean_T(b_segmentsToSplit,
                      &b_inter_segmentsToSplit, b_gpu_segmentsToSplit);
                  }

                  if (problemDef_cells_dirtyOnCpu) {
                    gpuEmxMemcpyCpuToGpu_boolean_T(r24, &inter_r24, gpu_r24);
                  }

                  oj_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U,
                    1U, 1U)>>>(b_gpu_segmentsToSplit, gpu_r24);
                  CUDACHECK(cudaGetLastError());
                  kEnd = r26->size[0];
                  r26->size[0] = b_segmentsToSplit->size[0] + 1;
                  emxEnsureCapacity_boolean_T(r26, kEnd);
                  gpuEmxMemcpyCpuToGpu_boolean_T(r26, &inter_r26, gpu_r26);
                  pj_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U,
                    1U, 1U)>>>(gpu_r26);
                  CUDACHECK(cudaGetLastError());
                  nx = b_segmentsToSplit->size[0] - 1;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    (nx + 1L), &gc_grid, &gc_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL,
                                         cudaMemcpyHostToDevice));
                    qj_reflectivity_calculation_gpu<<<gc_grid, gc_block>>>
                      (b_gpu_segmentsToSplit, gpu_nx, gpu_r26);
                    CUDACHECK(cudaGetLastError());
                  }

                  gpuEmxMemcpyGpuToCpu_boolean_T(r24, &inter_r24);
                  r21_dirtyOnGpu = false;
                  vstride = r24->size[0] - 1;
                  xoffset = 0;
                  for (c_i = 0; c_i <= vstride; c_i++) {
                    if (r21_dirtyOnGpu) {
                      gpuEmxMemcpyGpuToCpu_boolean_T(r24, &inter_r24);
                      r21_dirtyOnGpu = false;
                    }

                    if (r24->data[c_i]) {
                      xoffset++;
                    }
                  }

                  kEnd = r28->size[0];
                  r28->size[0] = xoffset;
                  emxEnsureCapacity_int32_T(r28, kEnd);
                  xoffset = 0;
                  for (c_i = 0; c_i <= vstride; c_i++) {
                    if (r21_dirtyOnGpu) {
                      gpuEmxMemcpyGpuToCpu_boolean_T(r24, &inter_r24);
                      r21_dirtyOnGpu = false;
                    }

                    if (r24->data[c_i]) {
                      r28->data[xoffset] = c_i + 1;
                      xoffset++;
                    }
                  }

                  gpuEmxMemcpyGpuToCpu_boolean_T(r26, &inter_r26);
                  vstride = r26->size[0] - 1;
                  xoffset = 0;
                  for (c_i = 0; c_i <= vstride; c_i++) {
                    if (r26->data[c_i]) {
                      xoffset++;
                    }
                  }

                  kEnd = r29->size[0];
                  r29->size[0] = xoffset;
                  emxEnsureCapacity_int32_T(r29, kEnd);
                  xoffset = 0;
                  for (c_i = 0; c_i <= vstride; c_i++) {
                    if (r26->data[c_i]) {
                      r29->data[xoffset] = c_i + 1;
                      xoffset++;
                    }
                  }

                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((r28->size[0] - 1) + 1L), &hc_grid, &hc_block, 1024U,
                    65535U);
                  if (validLaunchParams) {
                    if (r8_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(b_newDataPoints,
                        &b_inter_newDataPoints, b_gpu_newDataPoints);
                      r8_dirtyOnCpu = false;
                    }

                    gpuEmxMemcpyCpuToGpu_int32_T(r29, &inter_r29, gpu_r29);
                    gpuEmxMemcpyCpuToGpu_int32_T(r28, &inter_r28, gpu_r28);
                    rj_reflectivity_calculation_gpu<<<hc_grid, hc_block>>>
                      (gpu_r29, c_gpu_dataPoints, gpu_r28, b_gpu_newDataPoints);
                    CUDACHECK(cudaGetLastError());
                    newDataPoints_dirtyOnGpu = true;
                  }

                  //  Subfunctions
                  //  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N 
                  //  is the number of elements of x and M is the number of outputs of func. 
                  //  All the outputs of func must be scalar.
                  //  The optional parameter 'vectorizable' (default false) allows to specify 
                  //  that the input function can be vectorized.
                  //  Modified by AVH for use with coder
                  // if (~exist('vectorizable','var') || isempty(vectorizable))
                  //  end
                  // abs(nargout(func)); %for anonymous functions nargout<0
                  //  if vectorizable
                  //    % For uniformity reasons, transform the 'x' array into a column vector. 
                  //    % In this way it does not matter if it is given as a column or a row 
                  //    % vector.
                  //    [newValues{:}] = func(x(:));
                  //    y = cell2mat(newValues);
                  //  else
                  if (newDataPoints_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_real_T(b_newDataPoints,
                      &b_inter_newDataPoints);
                    newDataPoints_dirtyOnGpu = false;
                  }

                  kEnd = b_newDataPoints->size[0];
                  qEnd = r18->size[0];
                  r18->size[0] = b_newDataPoints->size[0];
                  emxEnsureCapacity_real_T(r18, qEnd);
                  for (c_i = 0; c_i < kEnd; c_i++) {
                    //  Remove cell array so no need for cell2mat
                    //  which won't compile - AVH
                    // [newValues{:}] = func(x(i));
                    // y(i,:) = cell2mat(newValues);
                    //  sldVal = sldFunc(x,SLD)
                    //  SLD = [x rho;....xn rho]
                    //    x = value in Angstrom.
                    //
                    //  This function returns the SLD (y) value associated with the 
                    //  supplied value of x. SLD is a two column, XY array defining an 
                    //  SLD profile. This function interpolates the SLD profile
                    //  to return the SLD at the specific value of X. X can be a vector of 
                    //  multiple points.
                    //
                    //  (c) Arwel Hughes 2019.
                    //  Last modified - AVH, 26/11/19.
                    //  global sldProfile
                    //
                    //  SLD = sldProfile;
                    // SLD = getappdata(0,'sldFuncSLD');
                    layerThicks = b_newDataPoints->data[c_i];
                    qEnd = b_sldProfile->size[0] - 1;
                    xoffset = p_x->size[0];
                    p_x->size[0] = qEnd + 1;
                    emxEnsureCapacity_boolean_T(p_x, xoffset);
                    validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                      (qEnd + 1L), &ic_grid, &ic_block, 1024U, 65535U);
                    if (validLaunchParams) {
                      CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                           cudaMemcpyHostToDevice));
                      CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL,
                                           cudaMemcpyHostToDevice));
                      if (sldProfile_dirtyOnCpu) {
                        gpuEmxMemcpyCpuToGpu_real_T(b_sldProfile,
                          &b_inter_sldProfile, b_gpu_sldProfile);
                        sldProfile_dirtyOnCpu = false;
                      }

                      gpuEmxMemcpyCpuToGpu_boolean_T(p_x, &q_inter_x, r_gpu_x);
                      sj_reflectivity_calculation_gpu<<<ic_grid, ic_block>>>
                        (gpu_layerThicks, b_gpu_sldProfile, gpu_qEnd, r_gpu_x);
                      CUDACHECK(cudaGetLastError());
                      gpuEmxMemcpyGpuToCpu_boolean_T(p_x, &q_inter_x);
                    }

                    nx = p_x->size[0];
                    vlen = 0;
                    qEnd = j_ii->size[0];
                    j_ii->size[0] = p_x->size[0];
                    emxEnsureCapacity_int32_T(j_ii, qEnd);
                    xoffset = 1;
                    exitg2 = false;
                    while ((!exitg2) && (xoffset <= nx)) {
                      if (p_x->data[xoffset - 1]) {
                        vlen++;
                        j_ii->data[vlen - 1] = xoffset;
                        if (vlen >= nx) {
                          exitg2 = true;
                        } else {
                          xoffset++;
                        }
                      } else {
                        xoffset++;
                      }
                    }

                    if (p_x->size[0] == 1) {
                      if (vlen == 0) {
                        j_ii->size[0] = 0;
                      }
                    } else {
                      qEnd = j_ii->size[0];
                      if (1 > vlen) {
                        j_ii->size[0] = 0;
                      } else {
                        j_ii->size[0] = vlen;
                      }

                      emxEnsureCapacity_int32_T(j_ii, qEnd);
                    }

                    if (j_ii->size[0] != 0) {
                      qEnd = r31->size[0];
                      r31->size[0] = j_ii->size[0];
                      emxEnsureCapacity_real_T(r31, qEnd);
                      validLaunchParams = mwGetLaunchParameters
                        (static_cast<real_T>((j_ii->size[0] - 1) + 1L), &lc_grid,
                         &lc_block, 1024U, 65535U);
                      if (validLaunchParams) {
                        if (sldProfile_dirtyOnCpu) {
                          gpuEmxMemcpyCpuToGpu_real_T(b_sldProfile,
                            &b_inter_sldProfile, b_gpu_sldProfile);
                          sldProfile_dirtyOnCpu = false;
                        }

                        gpuEmxMemcpyCpuToGpu_int32_T(j_ii, &e_inter_ii, e_gpu_ii);
                        gpuEmxMemcpyCpuToGpu_real_T(r31, &inter_r31, gpu_r31);
                        vj_reflectivity_calculation_gpu<<<lc_grid, lc_block>>>
                          (b_gpu_sldProfile, e_gpu_ii, gpu_r31);
                        CUDACHECK(cudaGetLastError());
                        gpuEmxMemcpyGpuToCpu_real_T(r31, &inter_r31);
                      }
                    } else {
                      layerThicks = b_newDataPoints->data[c_i];
                      qEnd = b_sldProfile->size[0] - 1;
                      xoffset = r_x->size[0];
                      r_x->size[0] = qEnd + 1;
                      emxEnsureCapacity_boolean_T(r_x, xoffset);
                      validLaunchParams = mwGetLaunchParameters
                        (static_cast<real_T>(qEnd + 1L), &jc_grid, &jc_block,
                         1024U, 65535U);
                      if (validLaunchParams) {
                        CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                             cudaMemcpyHostToDevice));
                        CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL,
                                             cudaMemcpyHostToDevice));
                        if (sldProfile_dirtyOnCpu) {
                          gpuEmxMemcpyCpuToGpu_real_T(b_sldProfile,
                            &b_inter_sldProfile, b_gpu_sldProfile);
                          sldProfile_dirtyOnCpu = false;
                        }

                        gpuEmxMemcpyCpuToGpu_boolean_T(r_x, &r_inter_x, s_gpu_x);
                        tj_reflectivity_calculation_gpu<<<jc_grid, jc_block>>>
                          (b_gpu_sldProfile, gpu_layerThicks, gpu_qEnd, s_gpu_x);
                        CUDACHECK(cudaGetLastError());
                        gpuEmxMemcpyGpuToCpu_boolean_T(r_x, &r_inter_x);
                      }

                      nx = r_x->size[0];
                      vlen = 0;
                      qEnd = l_ii->size[0];
                      l_ii->size[0] = r_x->size[0];
                      emxEnsureCapacity_int32_T(l_ii, qEnd);
                      xoffset = 1;
                      exitg2 = false;
                      while ((!exitg2) && (xoffset <= nx)) {
                        if (r_x->data[xoffset - 1]) {
                          vlen++;
                          l_ii->data[vlen - 1] = xoffset;
                          if (vlen >= nx) {
                            exitg2 = true;
                          } else {
                            xoffset++;
                          }
                        } else {
                          xoffset++;
                        }
                      }

                      if (r_x->size[0] == 1) {
                        if (vlen == 0) {
                          l_ii->size[0] = 0;
                        }
                      } else {
                        qEnd = l_ii->size[0];
                        if (1 > vlen) {
                          l_ii->size[0] = 0;
                        } else {
                          l_ii->size[0] = vlen;
                        }

                        emxEnsureCapacity_int32_T(l_ii, qEnd);
                      }

                      layerThicks = b_newDataPoints->data[c_i];
                      qEnd = b_sldProfile->size[0] - 1;
                      xoffset = t_x->size[0];
                      t_x->size[0] = qEnd + 1;
                      emxEnsureCapacity_boolean_T(t_x, xoffset);
                      validLaunchParams = mwGetLaunchParameters
                        (static_cast<real_T>(qEnd + 1L), &kc_grid, &kc_block,
                         1024U, 65535U);
                      if (validLaunchParams) {
                        CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                             cudaMemcpyHostToDevice));
                        CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL,
                                             cudaMemcpyHostToDevice));
                        if (sldProfile_dirtyOnCpu) {
                          gpuEmxMemcpyCpuToGpu_real_T(b_sldProfile,
                            &b_inter_sldProfile, b_gpu_sldProfile);
                          sldProfile_dirtyOnCpu = false;
                        }

                        gpuEmxMemcpyCpuToGpu_boolean_T(t_x, &s_inter_x, t_gpu_x);
                        uj_reflectivity_calculation_gpu<<<kc_grid, kc_block>>>
                          (b_gpu_sldProfile, gpu_layerThicks, gpu_qEnd, t_gpu_x);
                        CUDACHECK(cudaGetLastError());
                        gpuEmxMemcpyGpuToCpu_boolean_T(t_x, &s_inter_x);
                      }

                      nx = t_x->size[0];
                      vlen = 0;
                      qEnd = n_ii->size[0];
                      n_ii->size[0] = t_x->size[0];
                      emxEnsureCapacity_int32_T(n_ii, qEnd);
                      xoffset = 1;
                      exitg2 = false;
                      while ((!exitg2) && (xoffset <= nx)) {
                        if (t_x->data[xoffset - 1]) {
                          vlen++;
                          n_ii->data[vlen - 1] = xoffset;
                          if (vlen >= nx) {
                            exitg2 = true;
                          } else {
                            xoffset++;
                          }
                        } else {
                          xoffset++;
                        }
                      }

                      if (t_x->size[0] == 1) {
                        if (vlen == 0) {
                          n_ii->size[0] = 0;
                        }
                      } else {
                        qEnd = n_ii->size[0];
                        if (1 > vlen) {
                          n_ii->size[0] = 0;
                        } else {
                          n_ii->size[0] = vlen;
                        }

                        emxEnsureCapacity_int32_T(n_ii, qEnd);
                      }

                      layerThicks = (b_newDataPoints->data[c_i] -
                                     b_sldProfile->data[l_ii->data[l_ii->size[0]
                                     - 1] - 1]) * (fabs(b_sldProfile->data
                        [(n_ii->data[0] + b_sldProfile->size[0]) - 1] -
                        b_sldProfile->data[(l_ii->data[l_ii->size[0] - 1] +
                                            b_sldProfile->size[0]) - 1]) /
                        (b_sldProfile->data[n_ii->data[0] - 1] -
                         b_sldProfile->data[l_ii->data[l_ii->size[0] - 1] - 1]));
                      if (b_sldProfile->data[(l_ii->data[l_ii->size[0] - 1] +
                                              b_sldProfile->size[0]) - 1] <
                          b_sldProfile->data[(n_ii->data[0] + b_sldProfile->
                                              size[0]) - 1]) {
                        qEnd = r31->size[0];
                        r31->size[0] = 1;
                        emxEnsureCapacity_real_T(r31, qEnd);
                        r31->data[0] = b_sldProfile->data[(l_ii->data[l_ii->
                          size[0] - 1] + b_sldProfile->size[0]) - 1] +
                          layerThicks;
                      } else {
                        qEnd = r31->size[0];
                        r31->size[0] = 1;
                        emxEnsureCapacity_real_T(r31, qEnd);
                        r31->data[0] = b_sldProfile->data[(l_ii->data[l_ii->
                          size[0] - 1] + b_sldProfile->size[0]) - 1] -
                          layerThicks;
                      }

                      // sldVal = interp1(z,rho,x);
                    }

                    r18->data[c_i] = r31->data[0];
                  }

                  // end
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((r18->size[0] - 1) + 1L), &mc_grid, &mc_block, 1024U,
                    65535U);
                  if (validLaunchParams) {
                    if (r8_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(b_newDataPoints,
                        &b_inter_newDataPoints, b_gpu_newDataPoints);
                    }

                    gpuEmxMemcpyCpuToGpu_real_T(r18, &inter_r18, gpu_r18);
                    wj_reflectivity_calculation_gpu<<<mc_grid, mc_block>>>
                      (gpu_r18, b_gpu_newDataPoints);
                    CUDACHECK(cudaGetLastError());
                    newDataPoints_dirtyOnGpu = true;
                  }

                  //  For simplicity append the new points at the end and then sort. 
                  if (newDataPoints_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_real_T(b_newDataPoints,
                      &b_inter_newDataPoints);
                    newDataPoints_dirtyOnGpu = false;
                  }

                  if (b_newDataPoints->size[0] != 0) {
                    xoffset = b_newDataPoints->size[0];
                  } else {
                    xoffset = 0;
                  }

                  kEnd = d_dataPoints->size[0] * d_dataPoints->size[1];
                  d_dataPoints->size[0] = b_dataPoints->size[0] + xoffset;
                  d_dataPoints->size[1] = 2;
                  emxEnsureCapacity_real_T(d_dataPoints, kEnd);
                  problemDef_cells_dirtyOnCpu = true;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    (((b_dataPoints->size[0] - 1) + 1L) * 2L), &nc_grid,
                    &nc_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    gpuEmxMemcpyCpuToGpu_real_T(d_dataPoints,
                      &d_inter_dataPoints, d_gpu_dataPoints);
                    xj_reflectivity_calculation_gpu<<<nc_grid, nc_block>>>
                      (c_gpu_dataPoints, d_gpu_dataPoints);
                    CUDACHECK(cudaGetLastError());
                    problemDef_cells_dirtyOnCpu = false;
                    b_dataPoints_dirtyOnGpu = true;
                  }

                  for (kEnd = 0; kEnd < 2; kEnd++) {
                    for (qEnd = 0; qEnd < xoffset; qEnd++) {
                      if (b_dataPoints_dirtyOnGpu) {
                        gpuEmxMemcpyGpuToCpu_real_T(d_dataPoints,
                          &d_inter_dataPoints);
                        b_dataPoints_dirtyOnGpu = false;
                      }

                      d_dataPoints->data[(qEnd + b_dataPoints->size[0]) +
                        d_dataPoints->size[0] * kEnd] = b_newDataPoints->
                        data[qEnd + b_newDataPoints->size[0] * kEnd];
                      problemDef_cells_dirtyOnCpu = true;
                    }
                  }

                  kEnd = b_dataPoints->size[0] * b_dataPoints->size[1];
                  if (b_dataPoints_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_real_T(d_dataPoints,
                      &d_inter_dataPoints);
                    b_dataPoints_dirtyOnGpu = false;
                  }

                  b_dataPoints->size[0] = d_dataPoints->size[0];
                  b_dataPoints->size[1] = 2;
                  emxEnsureCapacity_real_T(b_dataPoints, kEnd);
                  sz_dirtyOnCpu = true;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((d_dataPoints->size[0] * d_dataPoints->size[1] - 1) + 1L),
                    &oc_grid, &oc_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    gpuEmxMemcpyCpuToGpu_real_T(b_dataPoints,
                      &c_inter_dataPoints, c_gpu_dataPoints);
                    if (problemDef_cells_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(d_dataPoints,
                        &d_inter_dataPoints, d_gpu_dataPoints);
                    }

                    yj_reflectivity_calculation_gpu<<<oc_grid, oc_block>>>
                      (d_gpu_dataPoints, c_gpu_dataPoints);
                    CUDACHECK(cudaGetLastError());
                    sz_dirtyOnCpu = false;
                    dataPoints_dirtyOnGpu = true;
                  }

                  ak_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U,
                    1U, 1U)>>>(*gpu_col_data);
                  CUDACHECK(cudaGetLastError());
                  r8_dirtyOnCpu = true;
                  if (dataPoints_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_real_T(b_dataPoints,
                      &c_inter_dataPoints);
                    dataPoints_dirtyOnGpu = false;
                  }

                  n = b_dataPoints->size[0] + 1;
                  if (idx_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_int32_T(b_idx, &b_inter_idx);
                    idx_dirtyOnGpu = false;
                  }

                  kEnd = b_idx->size[0];
                  b_idx->size[0] = b_dataPoints->size[0];
                  emxEnsureCapacity_int32_T(b_idx, kEnd);
                  r1_dirtyOnCpu = true;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((b_dataPoints->size[0] - 1) + 1L), &pc_grid, &pc_block,
                    1024U, 65535U);
                  if (validLaunchParams) {
                    if (sz_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(b_dataPoints,
                        &c_inter_dataPoints, c_gpu_dataPoints);
                      sz_dirtyOnCpu = false;
                    }

                    gpuEmxMemcpyCpuToGpu_int32_T(b_idx, &b_inter_idx, b_gpu_idx);
                    bk_reflectivity_calculation_gpu<<<pc_grid, pc_block>>>
                      (c_gpu_dataPoints, b_gpu_idx);
                    CUDACHECK(cudaGetLastError());
                    r1_dirtyOnCpu = false;
                    idx_dirtyOnGpu = true;
                  }

                  kEnd = b_iwork->size[0];
                  b_iwork->size[0] = b_dataPoints->size[0];
                  emxEnsureCapacity_int32_T(b_iwork, kEnd);
                  problemDef_cells_dirtyOnCpu = true;
                  kEnd = b_dataPoints->size[0] - 1;
                  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                    ((kEnd - 1) / 2 + 1L), &qc_grid, &qc_block, 1024U, 65535U);
                  if (validLaunchParams) {
                    if (sz_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(b_dataPoints,
                        &c_inter_dataPoints, c_gpu_dataPoints);
                      sz_dirtyOnCpu = false;
                    }

                    if (r1_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_int32_T(b_idx, &b_inter_idx,
                        b_gpu_idx);
                      r1_dirtyOnCpu = false;
                    }

                    ck_reflectivity_calculation_gpu<<<qc_grid, qc_block>>>
                      (*gpu_col_data, c_gpu_dataPoints, kEnd, b_gpu_idx);
                    CUDACHECK(cudaGetLastError());
                    idx_dirtyOnGpu = true;
                  }

                  if ((b_dataPoints->size[0] & 1) != 0) {
                    if (sz_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_real_T(b_dataPoints,
                        &c_inter_dataPoints, c_gpu_dataPoints);
                      sz_dirtyOnCpu = false;
                    }

                    if (r1_dirtyOnCpu) {
                      gpuEmxMemcpyCpuToGpu_int32_T(b_idx, &b_inter_idx,
                        b_gpu_idx);
                      r1_dirtyOnCpu = false;
                    }

                    dk_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U,
                      1U, 1U)>>>(c_gpu_dataPoints, b_gpu_idx);
                    CUDACHECK(cudaGetLastError());
                    idx_dirtyOnGpu = true;
                  }

                  c_i = 2;
                  while (c_i < n - 1) {
                    i2 = c_i << 1;
                    j = 1;
                    for (xoffset = c_i + 1; xoffset < n; xoffset = qEnd + c_i) {
                      vstride = j;
                      vlen = xoffset;
                      qEnd = j + i2;
                      if (qEnd > n) {
                        qEnd = n;
                      }

                      k = 0;
                      kEnd = qEnd - j;
                      while (k + 1 <= kEnd) {
                        b_bool = true;
                        nx = 0;
                        exitg2 = false;
                        while ((!exitg2) && (nx + 1 < 3)) {
                          if (r8_dirtyOnCpu) {
                            CUDACHECK(cudaMemcpy(&col_data[0], gpu_col_data, 2U *
                                                 sizeof(int8_T),
                                                 cudaMemcpyDeviceToHost));
                            r8_dirtyOnCpu = false;
                          }

                          if (idx_dirtyOnGpu) {
                            gpuEmxMemcpyGpuToCpu_int32_T(b_idx, &b_inter_idx);
                            idx_dirtyOnGpu = false;
                          }

                          layerThicks = b_dataPoints->data[(b_idx->data[vstride
                            - 1] + b_dataPoints->size[0] * (col_data[nx] - 1)) -
                            1];
                          bFactor = b_dataPoints->data[(b_idx->data[vlen - 1] +
                            b_dataPoints->size[0] * (col_data[nx] - 1)) - 1];
                          if ((layerThicks == bFactor) || (rtIsNaN(layerThicks) &&
                               rtIsNaN(bFactor))) {
                            nx++;
                          } else {
                            if ((!(layerThicks <= bFactor)) && (!rtIsNaN(bFactor)))
                            {
                              b_bool = false;
                            }

                            exitg2 = true;
                          }
                        }

                        if (b_bool) {
                          if (idx_dirtyOnGpu) {
                            gpuEmxMemcpyGpuToCpu_int32_T(b_idx, &b_inter_idx);
                            idx_dirtyOnGpu = false;
                          }

                          b_iwork->data[k] = b_idx->data[vstride - 1];
                          problemDef_cells_dirtyOnCpu = true;
                          vstride++;
                          if (vstride == xoffset) {
                            while (vlen < qEnd) {
                              k++;
                              b_iwork->data[k] = b_idx->data[vlen - 1];
                              vlen++;
                            }
                          }
                        } else {
                          if (idx_dirtyOnGpu) {
                            gpuEmxMemcpyGpuToCpu_int32_T(b_idx, &b_inter_idx);
                            idx_dirtyOnGpu = false;
                          }

                          b_iwork->data[k] = b_idx->data[vlen - 1];
                          problemDef_cells_dirtyOnCpu = true;
                          vlen++;
                          if (vlen == qEnd) {
                            while (vstride < xoffset) {
                              k++;
                              b_iwork->data[k] = b_idx->data[vstride - 1];
                              vstride++;
                            }
                          }
                        }

                        k++;
                      }

                      validLaunchParams = mwGetLaunchParameters
                        (static_cast<real_T>((kEnd - 1) + 1L), &tc_grid,
                         &tc_block, 1024U, 65535U);
                      if (validLaunchParams) {
                        if (r1_dirtyOnCpu) {
                          gpuEmxMemcpyCpuToGpu_int32_T(b_idx, &b_inter_idx,
                            b_gpu_idx);
                          r1_dirtyOnCpu = false;
                        }

                        if (problemDef_cells_dirtyOnCpu) {
                          gpuEmxMemcpyCpuToGpu_int32_T(b_iwork, &b_inter_iwork,
                            b_gpu_iwork);
                          problemDef_cells_dirtyOnCpu = false;
                        }

                        gk_reflectivity_calculation_gpu<<<tc_grid, tc_block>>>
                          (b_gpu_iwork, j, kEnd, b_gpu_idx);
                        CUDACHECK(cudaGetLastError());
                        idx_dirtyOnGpu = true;
                      }

                      j = qEnd;
                    }

                    c_i = i2;
                  }

                  xoffset = b_dataPoints->size[0];
                  xoffset_dirtyOnCpu = true;
                  if (ycol_dirtyOnGpu) {
                    gpuEmxMemcpyGpuToCpu_real_T(b_ycol, &b_inter_ycol);
                    ycol_dirtyOnGpu = false;
                  }

                  kEnd = b_ycol->size[0];
                  b_ycol->size[0] = b_dataPoints->size[0];
                  emxEnsureCapacity_real_T(b_ycol, kEnd);
                  problemDef_cells_dirtyOnCpu = true;
                  for (j = 0; j < 2; j++) {
                    validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                      ((xoffset - 1) + 1L), &rc_grid, &rc_block, 1024U, 65535U);
                    if (validLaunchParams) {
                      if (xoffset_dirtyOnCpu) {
                        CUDACHECK(cudaMemcpy(gpu_xoffset, &xoffset, 4UL,
                                             cudaMemcpyHostToDevice));
                        xoffset_dirtyOnCpu = false;
                      }

                      if (sz_dirtyOnCpu) {
                        gpuEmxMemcpyCpuToGpu_real_T(b_dataPoints,
                          &c_inter_dataPoints, c_gpu_dataPoints);
                        sz_dirtyOnCpu = false;
                      }

                      if (r1_dirtyOnCpu) {
                        gpuEmxMemcpyCpuToGpu_int32_T(b_idx, &b_inter_idx,
                          b_gpu_idx);
                        r1_dirtyOnCpu = false;
                      }

                      if (problemDef_cells_dirtyOnCpu) {
                        gpuEmxMemcpyCpuToGpu_real_T(b_ycol, &b_inter_ycol,
                          b_gpu_ycol);
                        problemDef_cells_dirtyOnCpu = false;
                      }

                      ek_reflectivity_calculation_gpu<<<rc_grid, rc_block>>>(j,
                        c_gpu_dataPoints, b_gpu_idx, gpu_xoffset, b_gpu_ycol);
                      CUDACHECK(cudaGetLastError());
                      ycol_dirtyOnGpu = true;
                    }

                    validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                      ((xoffset - 1) + 1L), &sc_grid, &sc_block, 1024U, 65535U);
                    if (validLaunchParams) {
                      if (xoffset_dirtyOnCpu) {
                        CUDACHECK(cudaMemcpy(gpu_xoffset, &xoffset, 4UL,
                                             cudaMemcpyHostToDevice));
                        xoffset_dirtyOnCpu = false;
                      }

                      if (sz_dirtyOnCpu) {
                        gpuEmxMemcpyCpuToGpu_real_T(b_dataPoints,
                          &c_inter_dataPoints, c_gpu_dataPoints);
                        sz_dirtyOnCpu = false;
                      }

                      if (problemDef_cells_dirtyOnCpu) {
                        gpuEmxMemcpyCpuToGpu_real_T(b_ycol, &b_inter_ycol,
                          b_gpu_ycol);
                        problemDef_cells_dirtyOnCpu = false;
                      }

                      fk_reflectivity_calculation_gpu<<<sc_grid, sc_block>>>
                        (b_gpu_ycol, j, gpu_xoffset, c_gpu_dataPoints);
                      CUDACHECK(cudaGetLastError());
                      dataPoints_dirtyOnGpu = true;
                    }
                  }

                  //    else
                  //      break;
                }

                //  Removed waitbar for compile - AVH
                //    if displayWaitbar
                //      if getappdata(refinementWaitbar,'canceling'), break; end 
                //      waitbar(nRefinements/maxRefinements,refinementWaitbar);
                //    end
              }

              //  if displayWaitbar
              //    delete(refinementWaitbar);
              //  end
              //  Plotting refined function
              //  Removed for compile - AVH
              //  if nargin==0 % test mode
              //    figure(testFigureHandle);
              //    hold on;
              //    plot(dataPoints(:,1), dataPoints(:,2),'ro-');
              //    legend('initial', 'refiniment');
              //  end
              kEnd = b_layers->size[0] * b_layers->size[1];
              if (dataPoints_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(b_dataPoints, &c_inter_dataPoints);
              }

              b_layers->size[0] = b_dataPoints->size[0] - 1;
              b_layers->size[1] = 3;
              emxEnsureCapacity_real_T(b_layers, kEnd);
              problemDef_cells_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                (((b_dataPoints->size[0] - 1) * 3 - 1) + 1L), &uc_grid,
                &uc_block, 1024U, 65535U);
              if (validLaunchParams) {
                gpuEmxMemcpyCpuToGpu_real_T(b_layers, &b_inter_layers,
                  b_gpu_layers);
                if (sz_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(b_dataPoints, &c_inter_dataPoints,
                    c_gpu_dataPoints);
                  sz_dirtyOnCpu = false;
                }

                hk_reflectivity_calculation_gpu<<<uc_grid, uc_block>>>
                  (c_gpu_dataPoints, b_gpu_layers);
                CUDACHECK(cudaGetLastError());
                problemDef_cells_dirtyOnCpu = false;
                layers_dirtyOnGpu = true;
              }

              //  Now build a layer model from these resampled points
              kEnd = b_dataPoints->size[0] - 1;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((kEnd - 1) + 1L), &vc_grid, &vc_block, 1024U, 65535U);
              if (validLaunchParams) {
                if (problemDef_cells_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(b_layers, &b_inter_layers,
                    b_gpu_layers);
                }

                if (sz_dirtyOnCpu) {
                  gpuEmxMemcpyCpuToGpu_real_T(b_dataPoints, &c_inter_dataPoints,
                    c_gpu_dataPoints);
                }

                ik_reflectivity_calculation_gpu<<<vc_grid, vc_block>>>
                  (c_gpu_dataPoints, kEnd, b_gpu_layers);
                CUDACHECK(cudaGetLastError());
                layers_dirtyOnGpu = true;
              }
            } else {
              kEnd = b_layers->size[0] * b_layers->size[1];
              b_layers->size[0] = 2;
              b_layers->size[1] = 3;
              emxEnsureCapacity_real_T(b_layers, kEnd);
              gpuEmxMemcpyCpuToGpu_real_T(b_layers, &b_inter_layers,
                b_gpu_layers);
              xh_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(*gpu_layers_data, b_gpu_layers);
              CUDACHECK(cudaGetLastError());
              layers_dirtyOnGpu = true;
            }

            //  Apply scale factors and q shifts to the data
            layerThicks = sf;
            b_dirtyOnCpu = true;

            // Shifts the data according to scale factor
            //  scalefac = problem.scalefactors;
            //  horshift = problem.qshifts;
            //  numberOfContrasts = problem.numberOfContrasts;
            //  dataPresent = problem.dataPresent;
            //  allData = problem.data;
            //  dataLimits = problem.dataLimits;
            // shifted_data = cell(1,numberOfContrasts);
            switch (static_cast<int32_T>(problemDef->dataPresent[b_i])) {
             case 1:
              if (sf == 0.0) {
                layerThicks = 1.0E-30;
              }

              bFactor = problemDef_cells->f3[b_i].f1[0];
              CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                   cudaMemcpyHostToDevice));
              b_dirtyOnCpu = false;
              kk_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(64U, 1U,
                1U)>>>(bFactor, gpu_layerThicks, shifts, gpu_problemDef_cells,
                       b_i, *j_gpu_x, *gpu_thisData);
              CUDACHECK(cudaGetLastError());
              problemDef_cells_dirtyOnCpu = true;
              vlen = 0;
              xoffset = 1;
              exitg2 = false;
              while ((!exitg2) && (xoffset < 52)) {
                if (problemDef_cells_dirtyOnCpu) {
                  CUDACHECK(cudaMemcpy(&u_x[0], j_gpu_x, 51UL,
                                       cudaMemcpyDeviceToHost));
                  problemDef_cells_dirtyOnCpu = false;
                }

                if (u_x[xoffset - 1]) {
                  vlen++;
                  ii_data[vlen - 1] = static_cast<int8_T>(xoffset);
                  if (vlen >= 51) {
                    exitg2 = true;
                  } else {
                    xoffset++;
                  }
                } else {
                  xoffset++;
                }
              }

              if (1 > vlen) {
                kEnd = 0;
              } else {
                kEnd = vlen;
              }

              if (kEnd != 0) {
                vstride = ii_data[kEnd - 1];
              } else {
                vstride = 1;
              }

              lk_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(64U, 1U,
                1U)>>>(problemDef_cells->f3[b_i].f1[1], *gpu_thisData, *j_gpu_x);
              CUDACHECK(cudaGetLastError());
              problemDef_cells_dirtyOnCpu = true;
              vlen = 0;
              xoffset = 1;
              exitg2 = false;
              while ((!exitg2) && (xoffset < 52)) {
                if (problemDef_cells_dirtyOnCpu) {
                  CUDACHECK(cudaMemcpy(&u_x[0], j_gpu_x, 51UL,
                                       cudaMemcpyDeviceToHost));
                  problemDef_cells_dirtyOnCpu = false;
                }

                if (u_x[xoffset - 1]) {
                  vlen++;
                  ii_data[vlen - 1] = static_cast<int8_T>(xoffset);
                  if (vlen >= 51) {
                    exitg2 = true;
                  } else {
                    xoffset++;
                  }
                } else {
                  xoffset++;
                }
              }

              if (1 > vlen) {
                kEnd = 0;
              } else {
                kEnd = vlen;
              }

              if (kEnd != 0) {
                xoffset = ii_data[0];
              } else {
                xoffset = 51;
              }

              if (vstride > xoffset) {
                kEnd = 0;
                qEnd = -1;
              } else {
                kEnd = vstride - 1;
                qEnd = xoffset - 1;
              }

              shifted_dat_size[0] = (qEnd - kEnd) + 1;
              shifted_dat_size[1] = 3;
              r1_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                (((qEnd - kEnd) + 1L) * 3L), &wc_grid, &wc_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL,
                                     cudaMemcpyHostToDevice));
                CUDACHECK(cudaMemcpy(gpu_shifted_dat_size, &shifted_dat_size[0],
                                     8UL, cudaMemcpyHostToDevice));
                r1_dirtyOnCpu = false;
                mk_reflectivity_calculation_gpu<<<wc_grid, wc_block>>>
                  (*gpu_thisData, *gpu_shifted_dat_size, kEnd, gpu_qEnd,
                   *gpu_shifted_dat_data);
                CUDACHECK(cudaGetLastError());
                shifted_dat_data_dirtyOnGpu = true;
              }
              break;

             default:
              shifted_dat_size[0] = 51;
              shifted_dat_size[1] = 3;
              r1_dirtyOnCpu = true;
              jk_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(160U, 1U,
                1U)>>>(gpu_problemDef_cells, b_i, *gpu_shifted_dat_data);
              CUDACHECK(cudaGetLastError());
              shifted_dat_data_dirtyOnGpu = true;
              break;
            }

            //  function Ref = makeFresnelData(problem,contrast)
            //
            //      this_data = problem.shifted_data{contrast};
            //      xdata = this_data(:,1);
            //      nbair = problem.nbairs(contrast);
            //      nbsub = problem.nbsubs(contrast);
            //      slds = [0 0 0];
            //      resol = problem.resolution;
            //      resolType = problem.resolType;
            //      %abeles(xdata,SLDs,nbair,nbsub,ssub,nrepeats,sinter,resol)
            //      %Ref = abeles_new_2(xdata,slds,nbair,nbsub,s_sub,repeats,
            //      Ref = abeles_new_2(xdata,slds,nbair,nbsub,0,1,resolType,resol); 
            //  Calculate the reflectivity
            //  nbairs = problem.nbairs;
            //  nbsubs = problem.nbsubs;
            //  simLimits = problem.simLimits;
            //  repeatLayers = problem.repeatLayers;
            //  allData = problem.shifted_data;
            //  layers = problem.layers;
            //  ssubs = problem.ssubs;
            //  numberOfContrasts = problem.numberOfContrasts;
            //  reflectivity = cell(numberOfContrasts,1);
            //  Simulation = cell(numberOfContrasts,1);
            //
            //  parfor i = 1:numberOfContrasts
            // this_data = allData{i};
            if (layers_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(b_layers, &b_inter_layers);
              layers_dirtyOnGpu = false;
            }

            i2 = b_layers->size[0] - 1;
            if (shifted_dat_data_dirtyOnGpu) {
              CUDACHECK(cudaMemcpy(&shifted_dat_data[0], gpu_shifted_dat_data,
                                   shifted_dat_size[0] * shifted_dat_size[1] *
                                   sizeof(real_T), cudaMemcpyDeviceToHost));
              shifted_dat_data_dirtyOnGpu = false;
            }

            if (problemDef_cells->f4[b_i].f1[0] < shifted_dat_data[0]) {
              reps = shifted_dat_data[1] - shifted_dat_data[0];
              bFactor = shifted_dat_data[0] - reps;
              if (rtIsNaN(problemDef_cells->f4[b_i].f1[0]) || rtIsNaN(reps) ||
                  rtIsNaN(bFactor)) {
                kEnd = b_firstSection->size[0] * b_firstSection->size[1];
                b_firstSection->size[0] = 1;
                b_firstSection->size[1] = 1;
                emxEnsureCapacity_real_T(b_firstSection, kEnd);
                b_firstSection->data[0] = rtNaN;
                problemDef_cells_dirtyOnCpu = true;
              } else if ((reps == 0.0) || ((problemDef_cells->f4[b_i].f1[0] <
                           bFactor) && (reps < 0.0)) || ((bFactor <
                           problemDef_cells->f4[b_i].f1[0]) && (reps > 0.0))) {
                b_firstSection->size[0] = 1;
                b_firstSection->size[1] = 0;
                problemDef_cells_dirtyOnCpu = true;
              } else if ((rtIsInf(problemDef_cells->f4[b_i].f1[0]) || rtIsInf
                          (bFactor)) && (rtIsInf(reps) || (problemDef_cells->
                           f4[b_i].f1[0] == bFactor))) {
                kEnd = b_firstSection->size[0] * b_firstSection->size[1];
                b_firstSection->size[0] = 1;
                b_firstSection->size[1] = 1;
                emxEnsureCapacity_real_T(b_firstSection, kEnd);
                b_firstSection->data[0] = rtNaN;
                problemDef_cells_dirtyOnCpu = true;
              } else if (rtIsInf(reps)) {
                kEnd = b_firstSection->size[0] * b_firstSection->size[1];
                b_firstSection->size[0] = 1;
                b_firstSection->size[1] = 1;
                emxEnsureCapacity_real_T(b_firstSection, kEnd);
                b_firstSection->data[0] = problemDef_cells->f4[b_i].f1[0];
                problemDef_cells_dirtyOnCpu = true;
              } else if ((floor(problemDef_cells->f4[b_i].f1[0]) ==
                          problemDef_cells->f4[b_i].f1[0]) && (floor(reps) ==
                          reps)) {
                layerThicks = problemDef_cells->f4[b_i].f1[0];
                b_dirtyOnCpu = true;
                kEnd = b_firstSection->size[0] * b_firstSection->size[1];
                b_firstSection->size[0] = 1;
                b_firstSection->size[1] = static_cast<int32_T>(floor((bFactor -
                  problemDef_cells->f4[b_i].f1[0]) / reps)) + 1;
                emxEnsureCapacity_real_T(b_firstSection, kEnd);
                problemDef_cells_dirtyOnCpu = true;
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>(
                  static_cast<int32_T>((bFactor - layerThicks) / reps) + 1L),
                  &xc_grid, &xc_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                       cudaMemcpyHostToDevice));
                  b_dirtyOnCpu = false;
                  gpuEmxMemcpyCpuToGpu_real_T(b_firstSection,
                    &b_inter_firstSection, b_gpu_firstSection);
                  nk_reflectivity_calculation_gpu<<<xc_grid, xc_block>>>(reps,
                    gpu_layerThicks, bFactor, b_gpu_firstSection);
                  CUDACHECK(cudaGetLastError());
                  problemDef_cells_dirtyOnCpu = false;
                  firstSection_dirtyOnGpu = true;
                }
              } else {
                layerThicks = floor((bFactor - problemDef_cells->f4[b_i].f1[0]) /
                                    reps + 0.5);
                b_dirtyOnCpu = true;
                nextLayRough = problemDef_cells->f4[b_i].f1[0] + layerThicks *
                  reps;
                if (reps > 0.0) {
                  l = nextLayRough - bFactor;
                } else {
                  l = bFactor - nextLayRough;
                }

                thisBoxCentre = fabs(problemDef_cells->f4[b_i].f1[0]);
                pair_im = fabs(bFactor);
                if ((thisBoxCentre > pair_im) || rtIsNaN(pair_im)) {
                  pair_im = thisBoxCentre;
                }

                if (fabs(l) < 4.4408920985006262E-16 * pair_im) {
                  layerThicks++;
                  nextLayRough = bFactor;
                } else if (l > 0.0) {
                  nextLayRough = problemDef_cells->f4[b_i].f1[0] + (layerThicks
                    - 1.0) * reps;
                } else {
                  layerThicks++;
                }

                if (layerThicks >= 0.0) {
                  n = static_cast<int32_T>(layerThicks);
                } else {
                  n = 0;
                }

                kEnd = b_firstSection->size[0] * b_firstSection->size[1];
                b_firstSection->size[0] = 1;
                b_firstSection->size[1] = n;
                emxEnsureCapacity_real_T(b_firstSection, kEnd);
                problemDef_cells_dirtyOnCpu = true;
                if (n > 0) {
                  b_firstSection->data[0] = problemDef_cells->f4[b_i].f1[0];
                  if (n > 1) {
                    b_firstSection->data[n - 1] = nextLayRough;
                    xoffset = (n - 1) / 2;
                    for (k = 0; k <= xoffset - 2; k++) {
                      layerThicks = (static_cast<real_T>(k) + 1.0) * reps;
                      b_firstSection->data[k + 1] = problemDef_cells->f4[b_i]
                        .f1[0] + layerThicks;
                      b_firstSection->data[(n - k) - 2] = nextLayRough -
                        layerThicks;
                    }

                    if (xoffset << 1 == n - 1) {
                      b_firstSection->data[xoffset] = (problemDef_cells->f4[b_i]
                        .f1[0] + nextLayRough) / 2.0;
                    } else {
                      layerThicks = static_cast<real_T>(xoffset) * reps;
                      b_firstSection->data[xoffset] = problemDef_cells->f4[b_i].
                        f1[0] + layerThicks;
                      b_firstSection->data[xoffset + 1] = nextLayRough -
                        layerThicks;
                    }
                  }
                }
              }
            } else {
              b_firstSection->size[0] = 1;
              b_firstSection->size[1] = 0;
              problemDef_cells_dirtyOnCpu = true;
            }

            if (problemDef_cells->f4[b_i].f1[1] >
                shifted_dat_data[shifted_dat_size[0] - 1]) {
              reps = shifted_dat_data[shifted_dat_size[0] - 1] -
                shifted_dat_data[shifted_dat_size[0] - 2];
              g_a = shifted_dat_data[shifted_dat_size[0] - 1] + reps;
              if (rtIsNaN(g_a) || rtIsNaN(reps) || rtIsNaN(problemDef_cells->
                   f4[b_i].f1[1])) {
                kEnd = b_lastSection->size[0] * b_lastSection->size[1];
                b_lastSection->size[0] = 1;
                b_lastSection->size[1] = 1;
                emxEnsureCapacity_real_T(b_lastSection, kEnd);
                b_lastSection->data[0] = rtNaN;
              } else if ((reps == 0.0) || ((g_a < problemDef_cells->f4[b_i].f1[1])
                          && (reps < 0.0)) || ((problemDef_cells->f4[b_i].f1[1] <
                g_a) && (reps > 0.0))) {
                b_lastSection->size[0] = 1;
                b_lastSection->size[1] = 0;
              } else if ((rtIsInf(g_a) || rtIsInf(problemDef_cells->f4[b_i].f1[1]))
                         && (rtIsInf(reps) || (g_a == problemDef_cells->f4[b_i].
                           f1[1]))) {
                kEnd = b_lastSection->size[0] * b_lastSection->size[1];
                b_lastSection->size[0] = 1;
                b_lastSection->size[1] = 1;
                emxEnsureCapacity_real_T(b_lastSection, kEnd);
                b_lastSection->data[0] = rtNaN;
              } else if (rtIsInf(reps)) {
                kEnd = b_lastSection->size[0] * b_lastSection->size[1];
                b_lastSection->size[0] = 1;
                b_lastSection->size[1] = 1;
                emxEnsureCapacity_real_T(b_lastSection, kEnd);
                b_lastSection->data[0] = g_a;
              } else if ((floor(g_a) == g_a) && (floor(reps) == reps)) {
                layerThicks = problemDef_cells->f4[b_i].f1[1];
                b_dirtyOnCpu = true;
                kEnd = b_lastSection->size[0] * b_lastSection->size[1];
                b_lastSection->size[0] = 1;
                b_lastSection->size[1] = static_cast<int32_T>(floor
                  ((problemDef_cells->f4[b_i].f1[1] - g_a) / reps)) + 1;
                emxEnsureCapacity_real_T(b_lastSection, kEnd);
                validLaunchParams = mwGetLaunchParameters(static_cast<real_T>(
                  static_cast<int32_T>((layerThicks - g_a) / reps) + 1L),
                  &yc_grid, &yc_block, 1024U, 65535U);
                if (validLaunchParams) {
                  CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                       cudaMemcpyHostToDevice));
                  b_dirtyOnCpu = false;
                  gpuEmxMemcpyCpuToGpu_real_T(b_lastSection,
                    &b_inter_lastSection, b_gpu_lastSection);
                  ok_reflectivity_calculation_gpu<<<yc_grid, yc_block>>>(reps,
                    g_a, gpu_layerThicks, b_gpu_lastSection);
                  CUDACHECK(cudaGetLastError());
                  lastSection_dirtyOnGpu = true;
                }
              } else {
                layerThicks = floor((problemDef_cells->f4[b_i].f1[1] - g_a) /
                                    reps + 0.5);
                b_dirtyOnCpu = true;
                nextLayRough = g_a + layerThicks * reps;
                if (reps > 0.0) {
                  l = nextLayRough - problemDef_cells->f4[b_i].f1[1];
                } else {
                  l = problemDef_cells->f4[b_i].f1[1] - nextLayRough;
                }

                thisBoxCentre = fabs(g_a);
                pair_im = fabs(problemDef_cells->f4[b_i].f1[1]);
                if ((thisBoxCentre > pair_im) || rtIsNaN(pair_im)) {
                  pair_im = thisBoxCentre;
                }

                if (fabs(l) < 4.4408920985006262E-16 * pair_im) {
                  layerThicks++;
                  nextLayRough = problemDef_cells->f4[b_i].f1[1];
                } else if (l > 0.0) {
                  nextLayRough = g_a + (layerThicks - 1.0) * reps;
                } else {
                  layerThicks++;
                }

                if (layerThicks >= 0.0) {
                  n = static_cast<int32_T>(layerThicks);
                } else {
                  n = 0;
                }

                kEnd = b_lastSection->size[0] * b_lastSection->size[1];
                b_lastSection->size[0] = 1;
                b_lastSection->size[1] = n;
                emxEnsureCapacity_real_T(b_lastSection, kEnd);
                if (n > 0) {
                  b_lastSection->data[0] = g_a;
                  if (n > 1) {
                    b_lastSection->data[n - 1] = nextLayRough;
                    xoffset = (n - 1) / 2;
                    for (k = 0; k <= xoffset - 2; k++) {
                      layerThicks = (static_cast<real_T>(k) + 1.0) * reps;
                      b_lastSection->data[k + 1] = g_a + layerThicks;
                      b_lastSection->data[(n - k) - 2] = nextLayRough -
                        layerThicks;
                    }

                    if (xoffset << 1 == n - 1) {
                      b_lastSection->data[xoffset] = (g_a + nextLayRough) / 2.0;
                    } else {
                      layerThicks = static_cast<real_T>(xoffset) * reps;
                      b_lastSection->data[xoffset] = g_a + layerThicks;
                      b_lastSection->data[xoffset + 1] = nextLayRough -
                        layerThicks;
                    }
                  }
                }
              }
            } else {
              b_lastSection->size[0] = 1;
              b_lastSection->size[1] = 0;
            }

            if (firstSection_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(b_firstSection, &b_inter_firstSection);
              firstSection_dirtyOnGpu = false;
            }

            xoffset = b_firstSection->size[1];
            if (lastSection_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(b_lastSection, &b_inter_lastSection);
              lastSection_dirtyOnGpu = false;
            }

            vlen = b_lastSection->size[1];
            nx = shifted_dat_size[0];
            kEnd = b_simXdata->size[0];
            b_simXdata->size[0] = (xoffset + shifted_dat_size[0]) + vlen;
            emxEnsureCapacity_real_T(b_simXdata, kEnd);
            r8_dirtyOnCpu = true;
            vstride = xoffset - 1;
            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
              (vstride + 1L), &ad_grid, &ad_block, 1024U, 65535U);
            if (validLaunchParams) {
              if (problemDef_cells_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(b_firstSection,
                  &b_inter_firstSection, b_gpu_firstSection);
              }

              gpuEmxMemcpyCpuToGpu_real_T(b_simXdata, &b_inter_simXdata,
                b_gpu_simXdata);
              pk_reflectivity_calculation_gpu<<<ad_grid, ad_block>>>
                (b_gpu_firstSection, vstride, b_gpu_simXdata);
              CUDACHECK(cudaGetLastError());
              r8_dirtyOnCpu = false;
              simXdata_dirtyOnGpu = true;
            }

            for (kEnd = 0; kEnd < nx; kEnd++) {
              if (simXdata_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(b_simXdata, &b_inter_simXdata);
                simXdata_dirtyOnGpu = false;
              }

              b_simXdata->data[kEnd + xoffset] = shifted_dat_data[kEnd];
              r8_dirtyOnCpu = true;
            }

            for (kEnd = 0; kEnd < vlen; kEnd++) {
              if (simXdata_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(b_simXdata, &b_inter_simXdata);
                simXdata_dirtyOnGpu = false;
              }

              b_simXdata->data[(kEnd + xoffset) + nx] = b_lastSection->data[kEnd];
              r8_dirtyOnCpu = true;
            }

            sz[0] = b_firstSection->size[1] + 1U;
            sz[1] = static_cast<uint32_T>(b_firstSection->size[1]) +
              shifted_dat_size[0];
            sz_dirtyOnCpu = true;
            kEnd = b_Simul->size[0] * b_Simul->size[1];
            if (simXdata_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(b_simXdata, &b_inter_simXdata);
              simXdata_dirtyOnGpu = false;
            }

            b_Simul->size[0] = b_simXdata->size[0];
            b_Simul->size[1] = 2;
            emxEnsureCapacity_real_T(b_Simul, kEnd);
            b_bool = true;
            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
              ((b_simXdata->size[0] * 2 - 1) + 1L), &bd_grid, &bd_block, 1024U,
              65535U);
            if (validLaunchParams) {
              if (r8_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(b_simXdata, &b_inter_simXdata,
                  b_gpu_simXdata);
                r8_dirtyOnCpu = false;
              }

              gpuEmxMemcpyCpuToGpu_real_T(b_Simul, &b_inter_Simul, b_gpu_Simul);
              qk_reflectivity_calculation_gpu<<<bd_grid, bd_block>>>
                (b_gpu_simXdata, b_gpu_Simul);
              CUDACHECK(cudaGetLastError());
              b_bool = false;
              Simul_dirtyOnGpu = true;
            }

            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
              ((b_simXdata->size[0] - 1) + 1L), &cd_grid, &cd_block, 1024U,
              65535U);
            if (validLaunchParams) {
              if (r8_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(b_simXdata, &b_inter_simXdata,
                  b_gpu_simXdata);
                r8_dirtyOnCpu = false;
              }

              if (b_bool) {
                gpuEmxMemcpyCpuToGpu_real_T(b_Simul, &b_inter_Simul, b_gpu_Simul);
                b_bool = false;
              }

              rk_reflectivity_calculation_gpu<<<cd_grid, cd_block>>>
                (b_gpu_simXdata, b_gpu_Simul);
              CUDACHECK(cudaGetLastError());
              Simul_dirtyOnGpu = true;
            }

            //  Parallelise over points
            //  nbair = nbairs(thisCont);
            //  nbsub = nbsubs(thisCont);
            //  ssub = ssubs(thisCont);
            //  nrepeats = nrepeatss(thisCont);
            //  resol = resols(thisCont);
            // pi = 3.141592653589;
            snair = 1.0 - nba * 0.377451863036739;
            snsub = 1.0 - problemDef->nbs[static_cast<int32_T>
              (problemDef->contrastNbss[b_i]) - 1] * 0.377451863036739;
            kEnd = b_simXdata->size[0] - 1;
            qEnd = b_simRef->size[0];
            b_simRef->size[0] = b_simXdata->size[0];
            emxEnsureCapacity_real_T(b_simRef, qEnd);
            for (xoffset = 0; xoffset <= kEnd; xoffset++) {
              real_T theta;
              real_T psub_re;
              real_T yi;
              real_T yr;
              real_T blast_re;
              real_T blast_im;
              real_T ar;
              theta = asin(b_simXdata->data[xoffset] * 1.54 / 12.566370614359172);
              layerThicks = cos(theta);
              psub_re = snsub * snsub - snair * snair * (layerThicks *
                layerThicks);
              if ((snsub * snsub - snair * snair * (layerThicks * layerThicks)) *
                  0.0 == 0.0) {
                if (psub_re < 0.0) {
                  yr = 0.0;
                  yi = sqrt(-psub_re);
                } else {
                  yr = sqrt(psub_re);
                  yi = 0.0;
                }
              } else if (psub_re == 0.0) {
                yr = rtNaN;
                yi = rtNaN;
              } else if (rtIsNaN(psub_re)) {
                yr = psub_re;
                yi = psub_re;
              } else {
                yr = rtNaN;
                yi = rtNaN;
              }

              psub_re = yr;
              reps = snair * sin(theta);
              pair_im = snair * sin(theta) * 0.0;
              blast_re = 0.0;
              blast_im = 0.0;
              sk_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(*gpu_MI);
              CUDACHECK(cudaGetLastError());
              qEnd = static_cast<int32_T>(problemDef_cells->f1[b_i].f1[1]) - 1;
              for (vstride = 0; vstride <= qEnd; vstride++) {
                for (nx = 0; nx <= i2; nx++) {
                  real_T pimag_re;
                  l = b_layers->data[nx + (b_layers->size[0] << 1)];
                  bFactor = 1.0 - b_layers->data[nx + b_layers->size[0]] *
                    0.377451863036739;
                  layerThicks = cos(theta);
                  pimag_re = bFactor * bFactor - snair * snair * (layerThicks *
                    layerThicks);
                  if ((bFactor * bFactor - snair * snair * (layerThicks *
                        layerThicks)) * 0.0 == 0.0) {
                    if (pimag_re < 0.0) {
                      yr = 0.0;
                      pimag_re = sqrt(-pimag_re);
                    } else {
                      yr = sqrt(pimag_re);
                      pimag_re = 0.0;
                    }
                  } else if (pimag_re == 0.0) {
                    yr = rtNaN;
                    pimag_re = rtNaN;
                  } else if (rtIsNaN(pimag_re)) {
                    yr = pimag_re;
                  } else {
                    yr = rtNaN;
                    pimag_re = rtNaN;
                  }

                  layerThicks = -78.956835208714864 * reps;
                  bFactor = -78.956835208714864 * pair_im;
                  ar = (layerThicks * yr - bFactor * pimag_re) * (l * l);
                  l = (layerThicks * pimag_re + bFactor * yr) * (l * l);
                  if (l == 0.0) {
                    thisBoxCentre = ar / 2.3716;
                    g_a = 0.0;
                  } else if (ar == 0.0) {
                    thisBoxCentre = 0.0;
                    g_a = l / 2.3716;
                  } else {
                    thisBoxCentre = ar / 2.3716;
                    g_a = l / 2.3716;
                  }

                  if (g_a == 0.0) {
                    thisBoxCentre = exp(thisBoxCentre);
                    g_a = 0.0;
                  } else if (rtIsInf(g_a) && rtIsInf(thisBoxCentre) &&
                             (thisBoxCentre < 0.0)) {
                    thisBoxCentre = 0.0;
                    g_a = 0.0;
                  } else {
                    b_r = exp(thisBoxCentre / 2.0);
                    thisBoxCentre = b_r * (b_r * cos(g_a));
                    g_a = b_r * (b_r * sin(g_a));
                  }

                  ar = reps - yr;
                  l = pair_im - pimag_re;
                  layerThicks = reps + yr;
                  bFactor = pair_im + pimag_re;
                  if (bFactor == 0.0) {
                    if (l == 0.0) {
                      reps = ar / layerThicks;
                      pair_im = 0.0;
                    } else if (ar == 0.0) {
                      reps = 0.0;
                      pair_im = l / layerThicks;
                    } else {
                      reps = ar / layerThicks;
                      pair_im = l / layerThicks;
                    }
                  } else if (layerThicks == 0.0) {
                    if (ar == 0.0) {
                      reps = l / bFactor;
                      pair_im = 0.0;
                    } else if (l == 0.0) {
                      reps = 0.0;
                      pair_im = -(ar / bFactor);
                    } else {
                      reps = l / bFactor;
                      pair_im = -(ar / bFactor);
                    }
                  } else {
                    b_r = fabs(layerThicks);
                    reps = fabs(bFactor);
                    if (b_r > reps) {
                      nextLayRough = bFactor / layerThicks;
                      layerThicks += nextLayRough * bFactor;
                      reps = (ar + nextLayRough * l) / layerThicks;
                      pair_im = (l - nextLayRough * ar) / layerThicks;
                    } else if (reps == b_r) {
                      if (layerThicks > 0.0) {
                        nextLayRough = 0.5;
                      } else {
                        nextLayRough = -0.5;
                      }

                      if (bFactor > 0.0) {
                        layerThicks = 0.5;
                      } else {
                        layerThicks = -0.5;
                      }

                      reps = (ar * nextLayRough + l * layerThicks) / b_r;
                      pair_im = (l * nextLayRough - ar * layerThicks) / b_r;
                    } else {
                      nextLayRough = layerThicks / bFactor;
                      layerThicks = bFactor + nextLayRough * layerThicks;
                      reps = (nextLayRough * ar + l) / layerThicks;
                      pair_im = (nextLayRough * l - ar) / layerThicks;
                    }
                  }

                  nextLayRough = reps * thisBoxCentre - pair_im * g_a;
                  layerThicks = reps * g_a + pair_im * thisBoxCentre;
                  bFactor = blast_re * 0.0 - blast_im;
                  l = blast_re + blast_im * 0.0;
                  if (l == 0.0) {
                    bFactor = exp(bFactor);
                  } else if (rtIsInf(l) && rtIsInf(bFactor) && (bFactor < 0.0))
                  {
                    bFactor = 0.0;
                    l = 0.0;
                  } else {
                    b_r = exp(bFactor / 2.0);
                    bFactor = b_r * (b_r * cos(l));
                    l = b_r * (b_r * sin(l));
                  }

                  if (N_dirtyOnGpu) {
                    CUDACHECK(cudaMemcpy(&N[0], gpu_N, 64UL,
                                         cudaMemcpyDeviceToHost));
                  }

                  N[0].re = bFactor;
                  N[0].im = l;
                  bFactor = -blast_re * 0.0 - (-blast_im);
                  l = -blast_re + -blast_im * 0.0;
                  if (l == 0.0) {
                    bFactor = exp(bFactor);
                    l = 0.0;
                  } else if (rtIsInf(l) && rtIsInf(bFactor) && (bFactor < 0.0))
                  {
                    bFactor = 0.0;
                    l = 0.0;
                  } else {
                    b_r = exp(bFactor / 2.0);
                    bFactor = b_r * (b_r * cos(l));
                    l = b_r * (b_r * sin(l));
                  }

                  N[1].re = nextLayRough * bFactor - layerThicks * l;
                  N[1].im = nextLayRough * l + layerThicks * bFactor;
                  bFactor = -blast_re * 0.0 - (-blast_im);
                  l = -blast_re + -blast_im * 0.0;
                  if (l == 0.0) {
                    bFactor = exp(bFactor);
                    l = 0.0;
                  } else if (rtIsInf(l) && rtIsInf(bFactor) && (bFactor < 0.0))
                  {
                    bFactor = 0.0;
                    l = 0.0;
                  } else {
                    b_r = exp(bFactor / 2.0);
                    bFactor = b_r * (b_r * cos(l));
                    l = b_r * (b_r * sin(l));
                  }

                  N[3].re = bFactor;
                  N[3].im = l;
                  bFactor = blast_re * 0.0 - blast_im;
                  l = blast_re + blast_im * 0.0;
                  if (l == 0.0) {
                    bFactor = exp(bFactor);
                  } else if (rtIsInf(l) && rtIsInf(bFactor) && (bFactor < 0.0))
                  {
                    bFactor = 0.0;
                    l = 0.0;
                  } else {
                    b_r = exp(bFactor / 2.0);
                    bFactor = b_r * (b_r * cos(l));
                    l = b_r * (b_r * sin(l));
                  }

                  CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                       cudaMemcpyHostToDevice));
                  CUDACHECK(cudaMemcpy(gpu_N, &N[0], 64UL,
                                       cudaMemcpyHostToDevice));
                  tk_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U,
                    1U, 1U)>>>(l, gpu_layerThicks, bFactor, nextLayRough, *gpu_N);
                  CUDACHECK(cudaGetLastError());
                  N_dirtyOnGpu = true;
                  reps = yr;
                  pair_im = pimag_re;
                  blast_re = 4.0799904592075231 * b_layers->data[nx] * yr;
                  blast_im = 4.0799904592075231 * b_layers->data[nx] * pimag_re;
                  uk_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U,
                    1U, 1U)>>>(*gpu_N, *gpu_MI, *b_gpu_MI);
                  CUDACHECK(cudaGetLastError());
                  vk_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U,
                    1U, 1U)>>>(*b_gpu_MI, *gpu_MI);
                  CUDACHECK(cudaGetLastError());
                }
              }

              layerThicks = -78.956835208714864 * reps;
              bFactor = -78.956835208714864 * pair_im;
              ar = (layerThicks * psub_re - bFactor * yi) * (s_sub * s_sub);
              l = (layerThicks * yi + bFactor * psub_re) * (s_sub * s_sub);
              if (l == 0.0) {
                thisBoxCentre = ar / 2.3716;
                g_a = 0.0;
              } else if (ar == 0.0) {
                thisBoxCentre = 0.0;
                g_a = l / 2.3716;
              } else {
                thisBoxCentre = ar / 2.3716;
                g_a = l / 2.3716;
              }

              if (g_a == 0.0) {
                thisBoxCentre = exp(thisBoxCentre);
                g_a = 0.0;
              } else if (rtIsInf(g_a) && rtIsInf(thisBoxCentre) &&
                         (thisBoxCentre < 0.0)) {
                thisBoxCentre = 0.0;
                g_a = 0.0;
              } else {
                b_r = exp(thisBoxCentre / 2.0);
                thisBoxCentre = b_r * (b_r * cos(g_a));
                g_a = b_r * (b_r * sin(g_a));
              }

              ar = reps - psub_re;
              l = pair_im - yi;
              layerThicks = reps + psub_re;
              bFactor = pair_im + yi;
              if (bFactor == 0.0) {
                if (l == 0.0) {
                  reps = ar / layerThicks;
                  pair_im = 0.0;
                } else if (ar == 0.0) {
                  reps = 0.0;
                  pair_im = l / layerThicks;
                } else {
                  reps = ar / layerThicks;
                  pair_im = l / layerThicks;
                }
              } else if (layerThicks == 0.0) {
                if (ar == 0.0) {
                  reps = l / bFactor;
                  pair_im = 0.0;
                } else if (l == 0.0) {
                  reps = 0.0;
                  pair_im = -(ar / bFactor);
                } else {
                  reps = l / bFactor;
                  pair_im = -(ar / bFactor);
                }
              } else {
                b_r = fabs(layerThicks);
                reps = fabs(bFactor);
                if (b_r > reps) {
                  nextLayRough = bFactor / layerThicks;
                  layerThicks += nextLayRough * bFactor;
                  reps = (ar + nextLayRough * l) / layerThicks;
                  pair_im = (l - nextLayRough * ar) / layerThicks;
                } else if (reps == b_r) {
                  if (layerThicks > 0.0) {
                    nextLayRough = 0.5;
                  } else {
                    nextLayRough = -0.5;
                  }

                  if (bFactor > 0.0) {
                    layerThicks = 0.5;
                  } else {
                    layerThicks = -0.5;
                  }

                  reps = (ar * nextLayRough + l * layerThicks) / b_r;
                  pair_im = (l * nextLayRough - ar * layerThicks) / b_r;
                } else {
                  nextLayRough = layerThicks / bFactor;
                  layerThicks = bFactor + nextLayRough * layerThicks;
                  reps = (nextLayRough * ar + l) / layerThicks;
                  pair_im = (nextLayRough * l - ar) / layerThicks;
                }
              }

              nextLayRough = reps * thisBoxCentre - pair_im * g_a;
              layerThicks = reps * g_a + pair_im * thisBoxCentre;
              bFactor = blast_re * 0.0 - blast_im;
              l = blast_re + blast_im * 0.0;
              if (l == 0.0) {
                bFactor = exp(bFactor);
                l = 0.0;
              } else if (rtIsInf(l) && rtIsInf(bFactor) && (bFactor < 0.0)) {
                bFactor = 0.0;
                l = 0.0;
              } else {
                b_r = exp(bFactor / 2.0);
                bFactor = b_r * (b_r * cos(l));
                l = b_r * (b_r * sin(l));
              }

              wk_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(l, bFactor, *gpu_N);
              CUDACHECK(cudaGetLastError());
              bFactor = -blast_re * 0.0 - (-blast_im);
              l = -blast_re + -blast_im * 0.0;
              if (l == 0.0) {
                bFactor = exp(bFactor);
                l = 0.0;
              } else if (rtIsInf(l) && rtIsInf(bFactor) && (bFactor < 0.0)) {
                bFactor = 0.0;
                l = 0.0;
              } else {
                b_r = exp(bFactor / 2.0);
                bFactor = b_r * (b_r * cos(l));
                l = b_r * (b_r * sin(l));
              }

              CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                   cudaMemcpyHostToDevice));
              xk_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(l, gpu_layerThicks, bFactor, nextLayRough, *gpu_N);
              CUDACHECK(cudaGetLastError());
              bFactor = -blast_re * 0.0 - (-blast_im);
              l = -blast_re + -blast_im * 0.0;
              if (l == 0.0) {
                bFactor = exp(bFactor);
                l = 0.0;
              } else if (rtIsInf(l) && rtIsInf(bFactor) && (bFactor < 0.0)) {
                bFactor = 0.0;
                l = 0.0;
              } else {
                b_r = exp(bFactor / 2.0);
                bFactor = b_r * (b_r * cos(l));
                l = b_r * (b_r * sin(l));
              }

              yk_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(l, bFactor, *gpu_N);
              CUDACHECK(cudaGetLastError());
              bFactor = blast_re * 0.0 - blast_im;
              l = blast_re + blast_im * 0.0;
              if (l == 0.0) {
                bFactor = exp(bFactor);
                l = 0.0;
              } else if (rtIsInf(l) && rtIsInf(bFactor) && (bFactor < 0.0)) {
                bFactor = 0.0;
                l = 0.0;
              } else {
                b_r = exp(bFactor / 2.0);
                bFactor = b_r * (b_r * cos(l));
                l = b_r * (b_r * sin(l));
              }

              al_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(l, gpu_layerThicks, bFactor, nextLayRough, *gpu_N);
              CUDACHECK(cudaGetLastError());
              N_dirtyOnGpu = true;
              bl_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(*gpu_N, *gpu_MI, *b_gpu_MI);
              CUDACHECK(cudaGetLastError());
              cl_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(*b_gpu_MI, *gpu_MI);
              CUDACHECK(cudaGetLastError());
              CUDACHECK(cudaMemcpy(&MI[0], gpu_MI, 64UL, cudaMemcpyDeviceToHost));
              l = MI[1].re * MI[1].re - MI[1].im * -MI[1].im;
              thisBoxCentre = MI[1].re * -MI[1].im + MI[1].im * MI[1].re;
              layerThicks = MI[0].re * MI[0].re - MI[0].im * -MI[0].im;
              bFactor = MI[0].re * -MI[0].im + MI[0].im * MI[0].re;
              if (bFactor == 0.0) {
                if (thisBoxCentre == 0.0) {
                  pair_im = l / layerThicks;
                  layerThicks = 0.0;
                  b_dirtyOnCpu = true;
                } else if (l == 0.0) {
                  pair_im = 0.0;
                  layerThicks = thisBoxCentre / layerThicks;
                  b_dirtyOnCpu = true;
                } else {
                  pair_im = l / layerThicks;
                  layerThicks = thisBoxCentre / layerThicks;
                  b_dirtyOnCpu = true;
                }
              } else if (layerThicks == 0.0) {
                if (l == 0.0) {
                  pair_im = thisBoxCentre / bFactor;
                  layerThicks = 0.0;
                  b_dirtyOnCpu = true;
                } else if (thisBoxCentre == 0.0) {
                  pair_im = 0.0;
                  layerThicks = -(l / bFactor);
                  b_dirtyOnCpu = true;
                } else {
                  pair_im = thisBoxCentre / bFactor;
                  layerThicks = -(l / bFactor);
                  b_dirtyOnCpu = true;
                }
              } else {
                b_r = fabs(layerThicks);
                reps = fabs(bFactor);
                if (b_r > reps) {
                  nextLayRough = bFactor / layerThicks;
                  layerThicks += nextLayRough * bFactor;
                  pair_im = (l + nextLayRough * thisBoxCentre) / layerThicks;
                  layerThicks = (thisBoxCentre - nextLayRough * l) / layerThicks;
                  b_dirtyOnCpu = true;
                } else if (reps == b_r) {
                  if (layerThicks > 0.0) {
                    nextLayRough = 0.5;
                  } else {
                    nextLayRough = -0.5;
                  }

                  if (bFactor > 0.0) {
                    layerThicks = 0.5;
                  } else {
                    layerThicks = -0.5;
                  }

                  pair_im = (l * nextLayRough + thisBoxCentre * layerThicks) /
                    b_r;
                  layerThicks = (thisBoxCentre * nextLayRough - l * layerThicks)
                    / b_r;
                  b_dirtyOnCpu = true;
                } else {
                  nextLayRough = layerThicks / bFactor;
                  layerThicks = bFactor + nextLayRough * layerThicks;
                  pair_im = (nextLayRough * l + thisBoxCentre) / layerThicks;
                  layerThicks = (nextLayRough * thisBoxCentre - l) / layerThicks;
                  b_dirtyOnCpu = true;
                }
              }

              b_simRef->data[xoffset] = rt_hypotd_snf(pair_im, layerThicks);
            }

            // (x,sld,nbair,nbsub,nrepeats,ssub,layers,points)
            xoffset = b_simXdata->size[0];
            kEnd = b_dummydata->size[0];
            b_dummydata->size[0] = b_simXdata->size[0];
            emxEnsureCapacity_real_T(b_dummydata, kEnd);
            problemDef_cells_dirtyOnCpu = true;
            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
              ((b_simXdata->size[0] - 1) + 1L), &dd_grid, &dd_block, 1024U,
              65535U);
            if (validLaunchParams) {
              if (r8_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(b_simXdata, &b_inter_simXdata,
                  b_gpu_simXdata);
                r8_dirtyOnCpu = false;
              }

              gpuEmxMemcpyCpuToGpu_real_T(b_dummydata, &b_inter_dummydata,
                b_gpu_dummydata);
              dl_reflectivity_calculation_gpu<<<dd_grid, dd_block>>>
                (b_gpu_simXdata, b_gpu_dummydata);
              CUDACHECK(cudaGetLastError());
              problemDef_cells_dirtyOnCpu = false;
              dummydata_dirtyOnGpu = true;
            }

            kEnd = b_simXdata->size[0];
            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((kEnd
              - 1) + 1L), &ed_grid, &ed_block, 1024U, 65535U);
            if (validLaunchParams) {
              CUDACHECK(cudaMemcpy(gpu_xoffset, &xoffset, 4UL,
                                   cudaMemcpyHostToDevice));
              if (r8_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(b_simXdata, &b_inter_simXdata,
                  b_gpu_simXdata);
              }

              if (problemDef_cells_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(b_dummydata, &b_inter_dummydata,
                  b_gpu_dummydata);
                problemDef_cells_dirtyOnCpu = false;
              }

              gpuEmxMemcpyCpuToGpu_real_T(b_simRef, &b_inter_simRef,
                b_gpu_simRef);
              el_reflectivity_calculation_gpu<<<ed_grid, ed_block>>>
                (b_gpu_simRef, *problemDef, b_gpu_simXdata, gpu_xoffset, kEnd,
                 b_gpu_dummydata);
              CUDACHECK(cudaGetLastError());
              dummydata_dirtyOnGpu = true;
            }

            if (dummydata_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(b_dummydata, &b_inter_dummydata);
              dummydata_dirtyOnGpu = false;
            }

            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
              ((b_dummydata->size[0] - 1) + 1L), &fd_grid, &fd_block, 1024U,
              65535U);
            if (validLaunchParams) {
              if (b_bool) {
                gpuEmxMemcpyCpuToGpu_real_T(b_Simul, &b_inter_Simul, b_gpu_Simul);
                b_bool = false;
              }

              if (problemDef_cells_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(b_dummydata, &b_inter_dummydata,
                  b_gpu_dummydata);
              }

              fl_reflectivity_calculation_gpu<<<fd_grid, fd_block>>>
                (b_gpu_dummydata, b_gpu_Simul);
              CUDACHECK(cudaGetLastError());
              Simul_dirtyOnGpu = true;
            }

            if (sz[0] > sz[1]) {
              kEnd = 0;
              qEnd = -1;
              Lays_dirtyOnCpu = true;
            } else {
              kEnd = static_cast<int32_T>(sz[0]) - 1;
              qEnd = static_cast<int32_T>(sz[1]) - 1;
              Lays_dirtyOnCpu = true;
            }

            xoffset = b_reflect->size[0] * b_reflect->size[1];
            b_reflect->size[0] = (qEnd - kEnd) + 1;
            b_reflect->size[1] = 2;
            emxEnsureCapacity_real_T(b_reflect, xoffset);
            r8_dirtyOnCpu = true;
            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>(((qEnd
              - kEnd) + 1L) * 2L), &gd_grid, &gd_block, 1024U, 65535U);
            if (validLaunchParams) {
              CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL, cudaMemcpyHostToDevice));
              Lays_dirtyOnCpu = false;
              if (b_bool) {
                gpuEmxMemcpyCpuToGpu_real_T(b_Simul, &b_inter_Simul, b_gpu_Simul);
                b_bool = false;
              }

              gpuEmxMemcpyCpuToGpu_real_T(b_reflect, &b_inter_reflect,
                b_gpu_reflect);
              gl_reflectivity_calculation_gpu<<<gd_grid, gd_block>>>(b_gpu_Simul,
                kEnd, gpu_qEnd, b_gpu_reflect);
              CUDACHECK(cudaGetLastError());
              r8_dirtyOnCpu = false;
              reflect_dirtyOnGpu = true;
            }

            //  Apply background correction, either to the simulation or the data 
            switch (static_cast<int32_T>(problemDef->contrastBacksType[b_i])) {
             case 1:
              // Add background to the simulation
              layerThicks = problemDef->backs[static_cast<int32_T>
                (problemDef->contrastBacks[b_i]) - 1];
              if (reflect_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(b_reflect, &b_inter_reflect);
                reflect_dirtyOnGpu = false;
              }

              xoffset = b_reflect->size[0] * b_reflect->size[1];
              b_reflect->size[0] = (qEnd - kEnd) + 1;
              b_reflect->size[1] = 2;
              emxEnsureCapacity_real_T(b_reflect, xoffset);
              r8_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                (((qEnd - kEnd) + 1L) * 2L), &hd_grid, &hd_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                     cudaMemcpyHostToDevice));
                if (Lays_dirtyOnCpu) {
                  CUDACHECK(cudaMemcpy(gpu_qEnd, &qEnd, 4UL,
                                       cudaMemcpyHostToDevice));
                }

                if (b_bool) {
                  gpuEmxMemcpyCpuToGpu_real_T(b_Simul, &b_inter_Simul,
                    b_gpu_Simul);
                }

                gpuEmxMemcpyCpuToGpu_real_T(b_reflect, &b_inter_reflect,
                  b_gpu_reflect);
                hl_reflectivity_calculation_gpu<<<hd_grid, hd_block>>>
                  (gpu_layerThicks, b_gpu_Simul, kEnd, gpu_qEnd, b_gpu_reflect);
                CUDACHECK(cudaGetLastError());
                r8_dirtyOnCpu = false;
                reflect_dirtyOnGpu = true;
              }

              if (Simul_dirtyOnGpu) {
                gpuEmxMemcpyGpuToCpu_real_T(b_Simul, &b_inter_Simul);
                Simul_dirtyOnGpu = false;
              }

              kEnd = b_Simul->size[0] * b_Simul->size[1];
              qEnd = b_Simul->size[0] * b_Simul->size[1];
              b_Simul->size[1] = 2;
              emxEnsureCapacity_real_T(b_Simul, qEnd);
              layerThicks = problemDef->backs[static_cast<int32_T>
                (problemDef->contrastBacks[b_i]) - 1];
              b_dirtyOnCpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((kEnd - 1) + 1L), &id_grid, &id_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                     cudaMemcpyHostToDevice));
                b_dirtyOnCpu = false;
                gpuEmxMemcpyCpuToGpu_real_T(b_Simul, &b_inter_Simul, b_gpu_Simul);
                il_reflectivity_calculation_gpu<<<id_grid, id_block>>>
                  (gpu_layerThicks, kEnd, b_gpu_Simul);
                CUDACHECK(cudaGetLastError());
                Simul_dirtyOnGpu = true;
              }
              break;

             case 2:
              //          %Subtract the background from the data..
              layerThicks = problemDef->backs[static_cast<int32_T>
                (problemDef->contrastBacks[b_i]) - 1];
              b_dirtyOnCpu = true;
              kEnd = shifted_dat_size[0] - 1;
              ii_size[0] = shifted_dat_size[0];
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>(kEnd
                + 1L), &jd_grid, &jd_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                     cudaMemcpyHostToDevice));
                b_dirtyOnCpu = false;
                if (r1_dirtyOnCpu) {
                  CUDACHECK(cudaMemcpy(gpu_shifted_dat_size, &shifted_dat_size[0],
                                       8UL, cudaMemcpyHostToDevice));
                  r1_dirtyOnCpu = false;
                }

                jl_reflectivity_calculation_gpu<<<jd_grid, jd_block>>>
                  (gpu_layerThicks, *gpu_shifted_dat_data, *gpu_shifted_dat_size,
                   kEnd, *gpu_terms_data);
                CUDACHECK(cudaGetLastError());
              }

              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((ii_size[0] - 1) + 1L), &kd_grid, &kd_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_ii_size, &ii_size[0], 4UL,
                                     cudaMemcpyHostToDevice));
                if (r1_dirtyOnCpu) {
                  CUDACHECK(cudaMemcpy(gpu_shifted_dat_size, &shifted_dat_size[0],
                                       8UL, cudaMemcpyHostToDevice));
                  r1_dirtyOnCpu = false;
                }

                kl_reflectivity_calculation_gpu<<<kd_grid, kd_block>>>
                  (*gpu_terms_data, *gpu_shifted_dat_size, *gpu_ii_size,
                   *gpu_shifted_dat_data);
                CUDACHECK(cudaGetLastError());
                shifted_dat_data_dirtyOnGpu = true;
              }

              // shifted_dat(:,3) = shifted_dat(:,3) - backg;
              break;
            }

            //  Calculate chi squared.
            // chi_squared(func,data,numparams,errors)
            // allChis = zeros(1,numberOfContrasts);
            //      thisData = allData{i};
            //      thisFit = allFits{i};
            vstride = shifted_dat_size[0];
            if (shifted_dat_size[0] < 1) {
              vstride = 1;
            }

            if (vstride <= 10) {
              vstride = 11;
            }

            kEnd = shifted_dat_size[0] - 1;
            qEnd = b_z->size[0];
            b_z->size[0] = shifted_dat_size[0];
            emxEnsureCapacity_real_T(b_z, qEnd);
            problemDef_cells_dirtyOnCpu = true;
            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>(kEnd +
              1L), &ld_grid, &ld_block, 1024U, 65535U);
            if (validLaunchParams) {
              if (r1_dirtyOnCpu) {
                CUDACHECK(cudaMemcpy(gpu_shifted_dat_size, &shifted_dat_size[0],
                                     8UL, cudaMemcpyHostToDevice));
              }

              if (r8_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(b_reflect, &b_inter_reflect,
                  b_gpu_reflect);
              }

              gpuEmxMemcpyCpuToGpu_real_T(b_z, &b_inter_z, b_gpu_z);
              ll_reflectivity_calculation_gpu<<<ld_grid, ld_block>>>
                (b_gpu_reflect, *gpu_shifted_dat_data, *gpu_shifted_dat_size,
                 kEnd, b_gpu_z);
              CUDACHECK(cudaGetLastError());
              problemDef_cells_dirtyOnCpu = false;
              z_dirtyOnGpu = true;
            }

            kEnd = b_z1->size[0];
            if (z_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(b_z, &b_inter_z);
              z_dirtyOnGpu = false;
            }

            b_z1->size[0] = b_z->size[0];
            emxEnsureCapacity_real_T(b_z1, kEnd);
            xoffset_dirtyOnCpu = true;
            nx = b_z->size[0];
            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((nx -
              1) + 1L), &md_grid, &md_block, 1024U, 65535U);
            if (validLaunchParams) {
              CUDACHECK(cudaMemcpy(gpu_nx, &nx, 4UL, cudaMemcpyHostToDevice));
              if (problemDef_cells_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(b_z, &b_inter_z, b_gpu_z);
              }

              gpuEmxMemcpyCpuToGpu_real_T(b_z1, &n_inter_z1, n_gpu_z1);
              ml_reflectivity_calculation_gpu<<<md_grid, md_block>>>(b_gpu_z,
                gpu_nx, n_gpu_z1);
              CUDACHECK(cudaGetLastError());
              xoffset_dirtyOnCpu = false;
              g_z1_dirtyOnGpu = true;
            }

            if (g_z1_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(b_z1, &n_inter_z1);
              g_z1_dirtyOnGpu = false;
            }

            ii_size[0] = b_z1->size[0];
            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
              ((b_z1->size[0] - 1) + 1L), &nd_grid, &nd_block, 1024U, 65535U);
            if (validLaunchParams) {
              if (xoffset_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(b_z1, &n_inter_z1, n_gpu_z1);
                xoffset_dirtyOnCpu = false;
              }

              nl_reflectivity_calculation_gpu<<<nd_grid, nd_block>>>(n_gpu_z1,
                *gpu_terms_data);
              CUDACHECK(cudaGetLastError());
            }

            kEnd = d_x->size[0];
            d_x->size[0] = b_z1->size[0];
            emxEnsureCapacity_boolean_T(d_x, kEnd);
            validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
              ((b_z1->size[0] - 1) + 1L), &od_grid, &od_block, 1024U, 65535U);
            if (validLaunchParams) {
              if (xoffset_dirtyOnCpu) {
                gpuEmxMemcpyCpuToGpu_real_T(b_z1, &n_inter_z1, n_gpu_z1);
              }

              gpuEmxMemcpyCpuToGpu_boolean_T(d_x, &t_inter_x, u_gpu_x);
              ol_reflectivity_calculation_gpu<<<od_grid, od_block>>>(n_gpu_z1,
                u_gpu_x);
              CUDACHECK(cudaGetLastError());
              gpuEmxMemcpyGpuToCpu_boolean_T(d_x, &t_inter_x);
            }

            nx = d_x->size[0];
            vlen = 0;
            kEnd = b_ii->size[0];
            b_ii->size[0] = d_x->size[0];
            emxEnsureCapacity_int8_T(b_ii, kEnd);
            xoffset = 1;
            exitg2 = false;
            while ((!exitg2) && (xoffset <= nx)) {
              if (d_x->data[xoffset - 1]) {
                vlen++;
                b_ii->data[vlen - 1] = static_cast<int8_T>(xoffset);
                if (vlen >= nx) {
                  exitg2 = true;
                } else {
                  xoffset++;
                }
              } else {
                xoffset++;
              }
            }

            if (d_x->size[0] == 1) {
              if (vlen == 0) {
                b_ii->size[0] = 0;
              }
            } else {
              kEnd = b_ii->size[0];
              if (1 > vlen) {
                b_ii->size[0] = 0;
              } else {
                b_ii->size[0] = vlen;
              }

              emxEnsureCapacity_int8_T(b_ii, kEnd);
            }

            if (b_ii->size[0] != 0) {
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((b_ii->size[0] - 1) + 1L), &pd_grid, &pd_block, 1024U, 65535U);
              if (validLaunchParams) {
                gpuEmxMemcpyCpuToGpu_int8_T(b_ii, &f_inter_ii, f_gpu_ii);
                pl_reflectivity_calculation_gpu<<<pd_grid, pd_block>>>(f_gpu_ii,
                  *gpu_terms_data);
                CUDACHECK(cudaGetLastError());
              }
            }

            vlen = ii_size[0];
            if (ii_size[0] == 0) {
              layerThicks = 0.0;
            } else {
              if (b_dirtyOnCpu) {
                CUDACHECK(cudaMemcpy(gpu_layerThicks, &layerThicks, 8UL,
                                     cudaMemcpyHostToDevice));
              }

              ql_reflectivity_calculation_gpu<<<dim3(1U, 1U, 1U), dim3(32U, 1U,
                1U)>>>(*gpu_terms_data, gpu_layerThicks);
              CUDACHECK(cudaGetLastError());
              layerThicks_dirtyOnGpu = true;
              validLaunchParams = mwGetLaunchParameters(static_cast<real_T>
                ((vlen - 2) + 1L), &qd_grid, &qd_block, 1024U, 65535U);
              if (validLaunchParams) {
                CUDACHECK(cudaMemcpy(gpu_ii_size, &ii_size[0], 4UL,
                                     cudaMemcpyHostToDevice));
                rl_reflectivity_calculation_gpu<<<qd_grid, qd_block>>>
                  (*gpu_terms_data, vlen, gpu_layerThicks);
                CUDACHECK(cudaGetLastError());
              }
            }

            // allChis(i) = chi2;
            //  Store returned values for this contrast in the output arrays.
            //  As well as the calculated profiles, we also store a record of
            //  the other values (background, scalefactors etc) for each contrast 
            //  for future use.
            outSsubs->data[b_i] = problemDef->params[0];
            kEnd = b_sldProfiles->data[b_i].f1->size[0] * b_sldProfiles->
              data[b_i].f1->size[1];
            if (sldProfile_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(b_sldProfile, &b_inter_sldProfile);
              sldProfile_dirtyOnGpu = false;
            }

            b_sldProfiles->data[b_i].f1->size[0] = b_sldProfile->size[0];
            b_sldProfiles->data[b_i].f1->size[1] = b_sldProfile->size[1];
            emxEnsureCapacity_real_T(b_sldProfiles->data[b_i].f1, kEnd);
            for (kEnd = 0; kEnd < b_sldProfile->size[0] * b_sldProfile->size[1];
                 kEnd++) {
              b_sldProfiles->data[b_i].f1->data[kEnd] = b_sldProfile->data[kEnd];
            }

            kEnd = b_reflectivity->data[b_i].f1->size[0] * b_reflectivity->
              data[b_i].f1->size[1];
            if (reflect_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(b_reflect, &b_inter_reflect);
              reflect_dirtyOnGpu = false;
            }

            b_reflectivity->data[b_i].f1->size[0] = b_reflect->size[0];
            b_reflectivity->data[b_i].f1->size[1] = 2;
            emxEnsureCapacity_real_T(b_reflectivity->data[b_i].f1, kEnd);
            for (kEnd = 0; kEnd < b_reflect->size[0] * b_reflect->size[1]; kEnd
                 ++) {
              b_reflectivity->data[b_i].f1->data[kEnd] = b_reflect->data[kEnd];
            }

            kEnd = b_Simulation->data[b_i].f1->size[0] * b_Simulation->data[b_i]
              .f1->size[1];
            if (Simul_dirtyOnGpu) {
              gpuEmxMemcpyGpuToCpu_real_T(b_Simul, &b_inter_Simul);
              Simul_dirtyOnGpu = false;
            }

            b_Simulation->data[b_i].f1->size[0] = b_Simul->size[0];
            b_Simulation->data[b_i].f1->size[1] = 2;
            emxEnsureCapacity_real_T(b_Simulation->data[b_i].f1, kEnd);
            for (kEnd = 0; kEnd < b_Simul->size[0] * b_Simul->size[1]; kEnd++) {
              b_Simulation->data[b_i].f1->data[kEnd] = b_Simul->data[kEnd];
            }

            kEnd = b_shifted_data->data[b_i].f1->size[0] * b_shifted_data->
              data[b_i].f1->size[1];
            b_shifted_data->data[b_i].f1->size[0] = shifted_dat_size[0];
            b_shifted_data->data[b_i].f1->size[1] = 3;
            emxEnsureCapacity_real_T(b_shifted_data->data[b_i].f1, kEnd);
            for (kEnd = 0; kEnd < shifted_dat_size[0] * 3; kEnd++) {
              if (shifted_dat_data_dirtyOnGpu) {
                CUDACHECK(cudaMemcpy(&shifted_dat_data[0], gpu_shifted_dat_data,
                                     shifted_dat_size[0] * shifted_dat_size[1] *
                                     sizeof(real_T), cudaMemcpyDeviceToHost));
                shifted_dat_data_dirtyOnGpu = false;
              }

              b_shifted_data->data[b_i].f1->data[kEnd] = shifted_dat_data[kEnd];
            }

            kEnd = b_layerSlds->data[b_i].f1->size[0] * b_layerSlds->data[b_i].
              f1->size[1];
            b_layerSlds->data[b_i].f1->size[0] = b_layers->size[0];
            b_layerSlds->data[b_i].f1->size[1] = 3;
            emxEnsureCapacity_real_T(b_layerSlds->data[b_i].f1, kEnd);
            for (kEnd = 0; kEnd < b_layers->size[0] * b_layers->size[1]; kEnd++)
            {
              b_layerSlds->data[b_i].f1->data[kEnd] = b_layers->data[kEnd];
            }

            if (layerThicks_dirtyOnGpu) {
              CUDACHECK(cudaMemcpy(&layerThicks, gpu_layerThicks, 8UL,
                                   cudaMemcpyDeviceToHost));
            }

            chis->data[b_i] = 1.0 / (static_cast<real_T>(vstride) - 10.0) *
              layerThicks;
            backgs->data[b_i] = problemDef->backs[static_cast<int32_T>
              (problemDef->contrastBacks[b_i]) - 1];
            qshifts->data[b_i] = shifts;
            sfs->data[b_i] = sf;
            nbas->data[b_i] = nba;
            nbss->data[b_i] = problemDef->nbs[static_cast<int32_T>
              (problemDef->contrastNbss[b_i]) - 1];
            resols->data[b_i] = problemDef->res;
            allRoughs->data[b_i] = problemDef->params[0];
          }

          emxFree_real_T(&d_dataPoints);
          gpuEmxFree_real_T(&d_inter_dataPoints);
          emxFree_boolean_T(&r33);
          gpuEmxFree_boolean_T(&inter_r33);
          emxFree_boolean_T(&d_trianglesToRefine);
          gpuEmxFree_boolean_T(&d_inter_trianglesToRefine);
          emxFree_int32_T(&b_iwork);
          gpuEmxFree_int32_T(&b_inter_iwork);
          emxFree_int32_T(&n_ii);
          emxFree_boolean_T(&t_x);
          gpuEmxFree_boolean_T(&s_inter_x);
          emxFree_int32_T(&l_ii);
          emxFree_boolean_T(&r_x);
          gpuEmxFree_boolean_T(&r_inter_x);
          emxFree_int32_T(&j_ii);
          gpuEmxFree_int32_T(&e_inter_ii);
          emxFree_boolean_T(&p_x);
          gpuEmxFree_boolean_T(&q_inter_x);
          emxFree_real_T(&n_z1);
          gpuEmxFree_real_T(&m_inter_z1);
          emxFree_real_T(&m_z1);
          gpuEmxFree_real_T(&l_inter_z1);
          emxFree_real_T(&k_z1);
          gpuEmxFree_real_T(&k_inter_z1);
          emxFree_real_T(&i_z1);
          gpuEmxFree_real_T(&j_inter_z1);
          emxFree_real_T(&g_z1);
          gpuEmxFree_real_T(&i_inter_z1);
          emxFree_real_T(&e_z1);
          gpuEmxFree_real_T(&h_inter_z1);
          emxFree_real_T(&b_ycol);
          gpuEmxFree_real_T(&b_inter_ycol);
          emxFree_int32_T(&h_ii);
          emxFree_boolean_T(&n_x);
          gpuEmxFree_boolean_T(&n_inter_x);
          emxFree_int32_T(&f_ii);
          emxFree_boolean_T(&l_x);
          gpuEmxFree_boolean_T(&m_inter_x);
          emxFree_int32_T(&d_ii);
          gpuEmxFree_int32_T(&d_inter_ii);
          emxFree_boolean_T(&j_x);
          gpuEmxFree_boolean_T(&l_inter_x);
          emxFree_int32_T(&b_idx);
          gpuEmxFree_int32_T(&b_inter_idx);
          emxFree_real_T(&r31);
          gpuEmxFree_real_T(&inter_r31);
          emxFree_creal_T(&h_x);
          gpuEmxFree_creal_T(&p_inter_x);
          emxFree_real_T(&g_x);
          gpuEmxFree_real_T(&o_inter_x);
          emxFree_real_T(&h_b);
          gpuEmxFree_real_T(&h_inter_b);
          emxFree_real_T(&b_z1);
          gpuEmxFree_real_T(&n_inter_z1);
          emxFree_int32_T(&r29);
          gpuEmxFree_int32_T(&inter_r29);
          emxFree_int32_T(&r28);
          gpuEmxFree_int32_T(&inter_r28);
          emxFree_boolean_T(&r26);
          gpuEmxFree_boolean_T(&inter_r26);
          emxFree_boolean_T(&r24);
          gpuEmxFree_boolean_T(&inter_r24);
          emxFree_boolean_T(&r22);
          emxFree_boolean_T(&r20);
          emxFree_real_T(&r18);
          gpuEmxFree_real_T(&inter_r18);
          emxFree_real_T(&b_newDataPoints);
          gpuEmxFree_real_T(&b_inter_newDataPoints);
          emxFree_real_T(&r15);
          gpuEmxFree_real_T(&inter_r15);
          emxFree_real_T(&b_longStep);
          gpuEmxFree_real_T(&b_inter_longStep);
          emxFree_real_T(&b_secondStep);
          gpuEmxFree_real_T(&b_inter_secondStep);
          emxFree_real_T(&b_firstStep);
          gpuEmxFree_real_T(&b_inter_firstStep);
          emxFree_real_T(&b_secondStepSquared);
          gpuEmxFree_real_T(&b_inter_secondStepSquared);
          emxFree_real_T(&b_firstStepSquared);
          gpuEmxFree_real_T(&b_inter_firstStepSquared);
          emxFree_real_T(&b_normalizedData);
          gpuEmxFree_real_T(&b_inter_normalizedData);
          emxFree_real_T(&r13);
          gpuEmxFree_real_T(&inter_r13);
          emxFree_real_T(&r12);
          gpuEmxFree_real_T(&inter_r12);
          emxFree_real_T(&r10);
          gpuEmxFree_real_T(&inter_r10);
          emxFree_real_T(&f_b);
          gpuEmxFree_real_T(&f_inter_b);
          emxFree_real_T(&f_a);
          gpuEmxFree_real_T(&e_inter_a);
          emxFree_real_T(&r7);
          gpuEmxFree_real_T(&inter_r7);
          emxFree_real_T(&r6);
          gpuEmxFree_real_T(&inter_r6);
          emxFree_real_T(&d_b);
          gpuEmxFree_real_T(&g_inter_b);
          emxFree_real_T(&d_a);
          gpuEmxFree_real_T(&f_inter_a);
          emxFree_real_T(&r3);
          gpuEmxFree_real_T(&inter_r3);
          emxFree_real_T(&r2);
          gpuEmxFree_real_T(&inter_r2);
          emxFree_real_T(&b_b);
          gpuEmxFree_real_T(&e_inter_b);
          emxFree_real_T(&b_a);
          gpuEmxFree_real_T(&d_inter_a);
          emxFree_int8_T(&b_ii);
          gpuEmxFree_int8_T(&f_inter_ii);
          emxFree_boolean_T(&d_x);
          gpuEmxFree_boolean_T(&t_inter_x);
          emxFree_real_T(&b_z);
          gpuEmxFree_real_T(&b_inter_z);
          emxFree_real_T(&b_dummydata);
          gpuEmxFree_real_T(&b_inter_dummydata);
          emxFree_boolean_T(&b_segmentsToSplit);
          gpuEmxFree_boolean_T(&b_inter_segmentsToSplit);
          emxFree_boolean_T(&b_trianglesToRefine);
          gpuEmxFree_boolean_T(&c_inter_trianglesToRefine);
          emxFree_real_T(&b_dataPoints);
          gpuEmxFree_real_T(&c_inter_dataPoints);
          emxFree_real_T(&b_SLD);
          gpuEmxFree_real_T(&b_inter_SLD);
          emxFree_real_T(&b_Lays);
          gpuEmxFree_real_T(&b_inter_Lays);
          emxFree_real_T(&b_x);
          gpuEmxFree_real_T(&k_inter_x);
          emxFree_real_T(&b_simRef);
          gpuEmxFree_real_T(&b_inter_simRef);
          emxFree_real_T(&b_simXdata);
          gpuEmxFree_real_T(&b_inter_simXdata);
          emxFree_real_T(&b_lastSection);
          gpuEmxFree_real_T(&b_inter_lastSection);
          emxFree_real_T(&b_firstSection);
          gpuEmxFree_real_T(&b_inter_firstSection);
          emxFree_real_T(&b_layers);
          gpuEmxFree_real_T(&b_inter_layers);
          emxFree_real_T(&b_Simul);
          gpuEmxFree_real_T(&b_inter_Simul);
          emxFree_real_T(&b_reflect);
          gpuEmxFree_real_T(&b_inter_reflect);
          emxFree_real_T(&b_sldProfile);
          gpuEmxFree_real_T(&b_inter_sldProfile);
        }
        break;
      }

      if (chis_dirtyOnGpu) {
        gpuEmxMemcpyGpuToCpu_real_T(chis, &inter_chis);
      }

      vlen = chis->size[0];
      if (chis->size[0] == 0) {
        layerThicks = 0.0;
      } else {
        layerThicks = chis->data[0];
        for (j = 0; j <= vlen - 2; j++) {
          layerThicks += chis->data[j + 1];
        }
      }

      //      case 'Custom Layers'
      //          [problem,reflectivity,Simulation,...
      //              shifted_data,layerSlds,sldProfiles,...
      //              allLayers] = standardTF_custLay_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls); 
      //     case 'Custom XY'
      //         [problem,reflectivity,Simulation,...
      //             shifted_data,layerSlds,sldProfiles,...
      //             allLayers] = standardTF_custXY_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls); 
      //  end
      i = problem->ssubs->size[0];
      problem->ssubs->size[0] = outSsubs->size[0];
      emxEnsureCapacity_real_T(problem->ssubs, i);
      for (i = 0; i < outSsubs->size[0]; i++) {
        problem->ssubs->data[i] = outSsubs->data[i];
      }

      emxFree_real_T(&outSsubs);
      i = problem->backgrounds->size[0];
      if (backgs_dirtyOnGpu) {
        gpuEmxMemcpyGpuToCpu_real_T(backgs, &inter_backgs);
      }

      problem->backgrounds->size[0] = backgs->size[0];
      emxEnsureCapacity_real_T(problem->backgrounds, i);
      for (i = 0; i < backgs->size[0]; i++) {
        problem->backgrounds->data[i] = backgs->data[i];
      }

      emxFree_real_T(&backgs);
      gpuEmxFree_real_T(&inter_backgs);
      i = problem->qshifts->size[0];
      if (qshifts_dirtyOnGpu) {
        gpuEmxMemcpyGpuToCpu_real_T(qshifts, &inter_qshifts);
      }

      problem->qshifts->size[0] = qshifts->size[0];
      emxEnsureCapacity_real_T(problem->qshifts, i);
      for (i = 0; i < qshifts->size[0]; i++) {
        problem->qshifts->data[i] = qshifts->data[i];
      }

      emxFree_real_T(&qshifts);
      gpuEmxFree_real_T(&inter_qshifts);
      i = problem->scalefactors->size[0];
      if (sfs_dirtyOnGpu) {
        gpuEmxMemcpyGpuToCpu_real_T(sfs, &inter_sfs);
      }

      problem->scalefactors->size[0] = sfs->size[0];
      emxEnsureCapacity_real_T(problem->scalefactors, i);
      for (i = 0; i < sfs->size[0]; i++) {
        problem->scalefactors->data[i] = sfs->data[i];
      }

      emxFree_real_T(&sfs);
      gpuEmxFree_real_T(&inter_sfs);
      i = problem->nbairs->size[0];
      if (nbas_dirtyOnGpu) {
        gpuEmxMemcpyGpuToCpu_real_T(nbas, &inter_nbas);
      }

      problem->nbairs->size[0] = nbas->size[0];
      emxEnsureCapacity_real_T(problem->nbairs, i);
      for (i = 0; i < nbas->size[0]; i++) {
        problem->nbairs->data[i] = nbas->data[i];
      }

      emxFree_real_T(&nbas);
      gpuEmxFree_real_T(&inter_nbas);
      i = problem->nbsubs->size[0];
      if (nbss_dirtyOnGpu) {
        gpuEmxMemcpyGpuToCpu_real_T(nbss, &inter_nbss);
      }

      problem->nbsubs->size[0] = nbss->size[0];
      emxEnsureCapacity_real_T(problem->nbsubs, i);
      for (i = 0; i < nbss->size[0]; i++) {
        problem->nbsubs->data[i] = nbss->data[i];
      }

      emxFree_real_T(&nbss);
      gpuEmxFree_real_T(&inter_nbss);
      i = problem->resolutions->size[0];
      if (resols_dirtyOnGpu) {
        gpuEmxMemcpyGpuToCpu_real_T(resols, &inter_resols);
      }

      problem->resolutions->size[0] = resols->size[0];
      emxEnsureCapacity_real_T(problem->resolutions, i);
      for (i = 0; i < resols->size[0]; i++) {
        problem->resolutions->data[i] = resols->data[i];
      }

      emxFree_real_T(&resols);
      gpuEmxFree_real_T(&inter_resols);
      i = problem->calculations.all_chis->size[0];
      problem->calculations.all_chis->size[0] = chis->size[0];
      emxEnsureCapacity_real_T(problem->calculations.all_chis, i);
      for (i = 0; i < chis->size[0]; i++) {
        problem->calculations.all_chis->data[i] = chis->data[i];
      }

      emxFree_real_T(&chis);
      gpuEmxFree_real_T(&inter_chis);
      problem->calculations.sum_chi = layerThicks;
      i = problem->allSubRough->size[0];
      if (allRoughs_dirtyOnGpu) {
        gpuEmxMemcpyGpuToCpu_real_T(allRoughs, &inter_allRoughs);
      }

      problem->allSubRough->size[0] = allRoughs->size[0];
      emxEnsureCapacity_real_T(problem->allSubRough, i);
      for (i = 0; i < allRoughs->size[0]; i++) {
        problem->allSubRough->data[i] = allRoughs->data[i];
      }

      emxFree_real_T(&allRoughs);
      gpuEmxFree_real_T(&inter_allRoughs);
      i = reflectivity->size[0];
      reflectivity->size[0] = b_reflectivity->size[0];
      emxEnsureCapacity_cell_wrap_14(reflectivity, i);
      xoffset = b_reflectivity->size[0];
      for (j = 0; j < xoffset; j++) {
        reflectivity->data[j].f1.size[0] = b_reflectivity->data[j].f1->size[0];
        reflectivity->data[j].f1.size[1] = 2;
        n = b_reflectivity->data[j].f1->size[0] << 1;
        for (vstride = 0; vstride < n; vstride++) {
          reflectivity->data[j].f1.data[vstride] = b_reflectivity->data[j]
            .f1->data[vstride];
        }
      }

      emxFree_cell_wrap_11(&b_reflectivity);
      i = Simulation->size[0];
      Simulation->size[0] = b_Simulation->size[0];
      emxEnsureCapacity_cell_wrap_14(Simulation, i);
      xoffset = b_Simulation->size[0];
      for (j = 0; j < xoffset; j++) {
        Simulation->data[j].f1.size[0] = b_Simulation->data[j].f1->size[0];
        Simulation->data[j].f1.size[1] = 2;
        n = b_Simulation->data[j].f1->size[0] << 1;
        for (vstride = 0; vstride < n; vstride++) {
          Simulation->data[j].f1.data[vstride] = b_Simulation->data[j].f1->
            data[vstride];
        }
      }

      emxFree_cell_wrap_11(&b_Simulation);
      i = shifted_data->size[0];
      shifted_data->size[0] = b_shifted_data->size[0];
      emxEnsureCapacity_cell_wrap_15(shifted_data, i);
      xoffset = b_shifted_data->size[0];
      for (j = 0; j < xoffset; j++) {
        shifted_data->data[j].f1.size[0] = b_shifted_data->data[j].f1->size[0];
        shifted_data->data[j].f1.size[1] = 3;
        n = b_shifted_data->data[j].f1->size[0] * 3;
        for (vstride = 0; vstride < n; vstride++) {
          shifted_data->data[j].f1.data[vstride] = b_shifted_data->data[j]
            .f1->data[vstride];
        }
      }

      emxFree_cell_wrap_12(&b_shifted_data);
      i = layerSlds->size[0];
      layerSlds->size[0] = b_layerSlds->size[0];
      emxEnsureCapacity_cell_wrap_15(layerSlds, i);
      xoffset = b_layerSlds->size[0];
      for (j = 0; j < xoffset; j++) {
        layerSlds->data[j].f1.size[0] = b_layerSlds->data[j].f1->size[0];
        layerSlds->data[j].f1.size[1] = 3;
        n = b_layerSlds->data[j].f1->size[0] * 3;
        for (vstride = 0; vstride < n; vstride++) {
          layerSlds->data[j].f1.data[vstride] = b_layerSlds->data[j].f1->
            data[vstride];
        }
      }

      emxFree_cell_wrap_12(&b_layerSlds);
      i = sldProfiles->size[0];
      sldProfiles->size[0] = b_sldProfiles->size[0];
      emxEnsureCapacity_cell_wrap_14(sldProfiles, i);
      xoffset = b_sldProfiles->size[0];
      for (j = 0; j < xoffset; j++) {
        sldProfiles->data[j].f1.size[0] = b_sldProfiles->data[j].f1->size[0];
        sldProfiles->data[j].f1.size[1] = b_sldProfiles->data[j].f1->size[1];
        n = b_sldProfiles->data[j].f1->size[0] * b_sldProfiles->data[j].f1->
          size[1];
        for (vstride = 0; vstride < n; vstride++) {
          sldProfiles->data[j].f1.data[vstride] = b_sldProfiles->data[j]
            .f1->data[vstride];
        }
      }

      emxFree_cell_wrap_17(&b_sldProfiles);

      // case 'oilWaterTF'
      // problem = oilWaterTF_reflectivityCalculation(problemDef,problemDef_cells,controls);     
      // case 'polarisedTF'
      // problem = polarisedTF_reflectivityCalculation(problemDef,problemDef_cells,controls); 
      // case 'domainsTF'
      // problem = domainsTF_reflectivityCalculation(problemDef,problemDef_cells,controls); 
    }
    break;
  }

  emxInit_cell_wrap_11(&cell1, 1, true);

  // cell1Length = numberOfContrasts;
  i = static_cast<int32_T>(problemDef->numberOfContrasts);
  kEnd = cell1->size[0];
  cell1->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
  emxEnsureCapacity_cell_wrap_11(cell1, kEnd);
  for (b_i = 0; b_i < i; b_i++) {
    kEnd = cell1->data[b_i].f1->size[0] * cell1->data[b_i].f1->size[1];
    cell1->data[b_i].f1->size[0] = reflectivity->data[b_i].f1.size[0];
    cell1->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(cell1->data[b_i].f1, kEnd);
    for (kEnd = 0; kEnd < reflectivity->data[b_i].f1.size[0] *
         reflectivity->data[b_i].f1.size[1]; kEnd++) {
      cell1->data[b_i].f1->data[kEnd] = reflectivity->data[b_i].f1.data[kEnd];
    }
  }

  emxFree_cell_wrap_14(&reflectivity);
  i = result->f1->size[0];
  result->f1->size[0] = cell1->size[0];
  emxEnsureCapacity_cell_wrap_11(result->f1, i);
  for (i = 0; i < cell1->size[0]; i++) {
    emxCopyStruct_cell_wrap_11(&result->f1->data[i], &cell1->data[i]);
  }

  emxFree_cell_wrap_11(&cell1);
  emxInit_cell_wrap_11(&cell2, 1, true);

  //  cell2Length = 7;
  i = static_cast<int32_T>(problemDef->numberOfContrasts);
  kEnd = cell2->size[0];
  cell2->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
  emxEnsureCapacity_cell_wrap_11(cell2, kEnd);
  for (b_i = 0; b_i < i; b_i++) {
    kEnd = cell2->data[b_i].f1->size[0] * cell2->data[b_i].f1->size[1];
    cell2->data[b_i].f1->size[0] = Simulation->data[b_i].f1.size[0];
    cell2->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(cell2->data[b_i].f1, kEnd);
    for (kEnd = 0; kEnd < Simulation->data[b_i].f1.size[0] * Simulation->
         data[b_i].f1.size[1]; kEnd++) {
      cell2->data[b_i].f1->data[kEnd] = Simulation->data[b_i].f1.data[kEnd];
    }
  }

  emxFree_cell_wrap_14(&Simulation);
  i = result->f2->size[0];
  result->f2->size[0] = cell2->size[0];
  emxEnsureCapacity_cell_wrap_11(result->f2, i);
  for (i = 0; i < cell2->size[0]; i++) {
    emxCopyStruct_cell_wrap_11(&result->f2->data[i], &cell2->data[i]);
  }

  emxFree_cell_wrap_11(&cell2);
  emxInit_cell_wrap_12(&cell3, 1, true);

  //
  //  cell3Length = 7;
  i = static_cast<int32_T>(problemDef->numberOfContrasts);
  kEnd = cell3->size[0];
  cell3->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
  emxEnsureCapacity_cell_wrap_12(cell3, kEnd);
  for (b_i = 0; b_i < i; b_i++) {
    kEnd = cell3->data[b_i].f1->size[0] * cell3->data[b_i].f1->size[1];
    cell3->data[b_i].f1->size[0] = shifted_data->data[b_i].f1.size[0];
    cell3->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(cell3->data[b_i].f1, kEnd);
    for (kEnd = 0; kEnd < shifted_data->data[b_i].f1.size[0] *
         shifted_data->data[b_i].f1.size[1]; kEnd++) {
      cell3->data[b_i].f1->data[kEnd] = shifted_data->data[b_i].f1.data[kEnd];
    }
  }

  emxFree_cell_wrap_15(&shifted_data);
  i = result->f3->size[0];
  result->f3->size[0] = cell3->size[0];
  emxEnsureCapacity_cell_wrap_12(result->f3, i);
  for (i = 0; i < cell3->size[0]; i++) {
    emxCopyStruct_cell_wrap_12(&result->f3->data[i], &cell3->data[i]);
  }

  emxFree_cell_wrap_12(&cell3);
  emxInit_cell_wrap_12(&cell4, 1, true);

  //
  //  cell4Length = 7;
  i = static_cast<int32_T>(problemDef->numberOfContrasts);
  kEnd = cell4->size[0];
  cell4->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
  emxEnsureCapacity_cell_wrap_12(cell4, kEnd);
  for (b_i = 0; b_i < i; b_i++) {
    kEnd = cell4->data[b_i].f1->size[0] * cell4->data[b_i].f1->size[1];
    cell4->data[b_i].f1->size[0] = layerSlds->data[b_i].f1.size[0];
    cell4->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(cell4->data[b_i].f1, kEnd);
    for (kEnd = 0; kEnd < layerSlds->data[b_i].f1.size[0] * layerSlds->data[b_i]
         .f1.size[1]; kEnd++) {
      cell4->data[b_i].f1->data[kEnd] = layerSlds->data[b_i].f1.data[kEnd];
    }
  }

  emxFree_cell_wrap_15(&layerSlds);
  i = result->f4->size[0];
  result->f4->size[0] = cell4->size[0];
  emxEnsureCapacity_cell_wrap_12(result->f4, i);
  for (i = 0; i < cell4->size[0]; i++) {
    emxCopyStruct_cell_wrap_12(&result->f4->data[i], &cell4->data[i]);
  }

  emxFree_cell_wrap_12(&cell4);
  emxInit_cell_wrap_11(&cell5, 1, true);

  //
  //  cell5Length = 7;
  i = static_cast<int32_T>(problemDef->numberOfContrasts);
  kEnd = cell5->size[0];
  cell5->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
  emxEnsureCapacity_cell_wrap_11(cell5, kEnd);
  for (b_i = 0; b_i < i; b_i++) {
    kEnd = cell5->data[b_i].f1->size[0] * cell5->data[b_i].f1->size[1];
    cell5->data[b_i].f1->size[0] = sldProfiles->data[b_i].f1.size[0];
    cell5->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(cell5->data[b_i].f1, kEnd);
    for (kEnd = 0; kEnd < sldProfiles->data[b_i].f1.size[0] * sldProfiles->
         data[b_i].f1.size[1]; kEnd++) {
      cell5->data[b_i].f1->data[kEnd] = sldProfiles->data[b_i].f1.data[kEnd];
    }
  }

  emxFree_cell_wrap_14(&sldProfiles);
  i = result->f5->size[0];
  result->f5->size[0] = cell5->size[0];
  emxEnsureCapacity_cell_wrap_11(result->f5, i);
  for (i = 0; i < cell5->size[0]; i++) {
    emxCopyStruct_cell_wrap_11(&result->f5->data[i], &cell5->data[i]);
  }

  emxFree_cell_wrap_11(&cell5);
  emxInit_int8_T(&cell6, 1, true);
  problemDef_cells_dirtyOnCpu = false;

  //
  //  cell6Length = 7;
  i = static_cast<int32_T>(problemDef->numberOfContrasts);
  kEnd = cell6->size[0];
  cell6->size[0] = static_cast<int32_T>(problemDef->numberOfContrasts);
  emxEnsureCapacity_int8_T(cell6, kEnd);
  validLaunchParams = mwGetLaunchParameters(static_cast<real_T>((i - 1) + 1L),
    &rd_grid, &rd_block, 1024U, 65535U);
  if (validLaunchParams) {
    gpuEmxMemcpyCpuToGpu_int8_T(cell6, &inter_cell6, gpu_cell6);
    sl_reflectivity_calculation_gpu<<<rd_grid, rd_block>>>(i, gpu_cell6);
    CUDACHECK(cudaGetLastError());
    problemDef_cells_dirtyOnCpu = true;
  }

  i = result->f6->size[0];
  if (problemDef_cells_dirtyOnCpu) {
    gpuEmxMemcpyGpuToCpu_int8_T(cell6, &inter_cell6);
  }

  result->f6->size[0] = cell6->size[0];
  emxEnsureCapacity_real_T(result->f6, i);
  for (i = 0; i < cell6->size[0]; i++) {
    result->f6->data[i] = cell6->data[i];
  }

  emxFree_int8_T(&cell6);
  gpuEmxFree_int8_T(&inter_cell6);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  CUDACHECK(cudaFree(gpu_xoffset));
  CUDACHECK(cudaFree(gpu_backgs));
  CUDACHECK(cudaFree(gpu_qshifts));
  CUDACHECK(cudaFree(gpu_sfs));
  CUDACHECK(cudaFree(gpu_nbas));
  CUDACHECK(cudaFree(gpu_nbss));
  CUDACHECK(cudaFree(gpu_chis));
  CUDACHECK(cudaFree(gpu_resols));
  CUDACHECK(cudaFree(gpu_allRoughs));
  CUDACHECK(cudaFree(*gpu_thisOutLayer));
  CUDACHECK(cudaFree(gpu_problemDef_cells));
  CUDACHECK(cudaFree(*gpu_outParameterisedLayers));
  CUDACHECK(cudaFree(*gpu_thisContrastLayers));
  CUDACHECK(cudaFree(*gpu_thisData));
  CUDACHECK(cudaFree(*gpu_layers_size));
  CUDACHECK(cudaFree(*gpu_layers_data));
  CUDACHECK(cudaFree(gpu_layerThicks));
  CUDACHECK(cudaFree(gpu_sldProfile));
  CUDACHECK(cudaFree(gpu_x));
  CUDACHECK(cudaFree(gpu_Lays));
  CUDACHECK(cudaFree(gpu_a));
  CUDACHECK(cudaFree(gpu_b));
  CUDACHECK(cudaFree(gpu_r));
  CUDACHECK(cudaFree(gpu_nx));
  CUDACHECK(cudaFree(gpu_r1));
  CUDACHECK(cudaFree(b_gpu_a));
  CUDACHECK(cudaFree(gpu_qEnd));
  CUDACHECK(cudaFree(b_gpu_b));
  CUDACHECK(cudaFree(gpu_r8));
  CUDACHECK(cudaFree(gpu_r9));
  CUDACHECK(cudaFree(*gpu_ii_size));
  CUDACHECK(cudaFree(c_gpu_a));
  CUDACHECK(cudaFree(c_gpu_b));
  CUDACHECK(cudaFree(gpu_r4));
  CUDACHECK(cudaFree(gpu_r5));
  CUDACHECK(cudaFree(gpu_SLD));
  CUDACHECK(cudaFree(*gpu_sz));
  CUDACHECK(cudaFree(gpu_layers));
  CUDACHECK(cudaFree(*gpu_dataBoxSize));
  CUDACHECK(cudaFree(*gpu_y));
  CUDACHECK(cudaFree(b_gpu_x));
  CUDACHECK(cudaFree(gpu_ii));
  CUDACHECK(cudaFree(c_gpu_x));
  CUDACHECK(cudaFree(d_gpu_x));
  CUDACHECK(cudaFree(gpu_r11));
  CUDACHECK(cudaFree(*gpu_hiVal));
  CUDACHECK(cudaFree(*b_gpu_y));
  CUDACHECK(cudaFree(gpu_dataPoints));
  CUDACHECK(cudaFree(*gpu_minval));
  CUDACHECK(cudaFree(d_gpu_b));
  CUDACHECK(cudaFree(gpu_r14));
  CUDACHECK(cudaFree(gpu_normalizedData));
  CUDACHECK(cudaFree(gpu_firstStep));
  CUDACHECK(cudaFree(gpu_secondStep));
  CUDACHECK(cudaFree(gpu_longStep));
  CUDACHECK(cudaFree(gpu_z1));
  CUDACHECK(cudaFree(b_gpu_z1));
  CUDACHECK(cudaFree(gpu_firstStepSquared));
  CUDACHECK(cudaFree(c_gpu_z1));
  CUDACHECK(cudaFree(d_gpu_z1));
  CUDACHECK(cudaFree(gpu_secondStepSquared));
  CUDACHECK(cudaFree(e_gpu_z1));
  CUDACHECK(cudaFree(f_gpu_z1));
  CUDACHECK(cudaFree(e_gpu_x));
  CUDACHECK(cudaFree(f_gpu_x));
  CUDACHECK(cudaFree(gpu_trianglesToRefine));
  CUDACHECK(cudaFree(b_gpu_trianglesToRefine));
  CUDACHECK(cudaFree(gpu_r32));
  CUDACHECK(cudaFree(gpu_segmentsToSplit));
  CUDACHECK(cudaFree(gpu_newDataPoints));
  CUDACHECK(cudaFree(gpu_r21));
  CUDACHECK(cudaFree(gpu_r23));
  CUDACHECK(cudaFree(gpu_r25));
  CUDACHECK(cudaFree(gpu_r27));
  CUDACHECK(cudaFree(gpu_r16));
  CUDACHECK(cudaFree(g_gpu_x));
  CUDACHECK(cudaFree(b_gpu_ii));
  CUDACHECK(cudaFree(h_gpu_x));
  CUDACHECK(cudaFree(i_gpu_x));
  CUDACHECK(cudaFree(gpu_r30));
  CUDACHECK(cudaFree(b_gpu_dataPoints));
  CUDACHECK(cudaFree(*gpu_col_data));
  CUDACHECK(cudaFree(gpu_idx));
  CUDACHECK(cudaFree(gpu_iwork));
  CUDACHECK(cudaFree(gpu_ycol));
  CUDACHECK(cudaFree(*gpu_shifted_dat_size));
  CUDACHECK(cudaFree(*gpu_shifted_dat_data));
  CUDACHECK(cudaFree(*j_gpu_x));
  CUDACHECK(cudaFree(gpu_firstSection));
  CUDACHECK(cudaFree(gpu_lastSection));
  CUDACHECK(cudaFree(gpu_simXdata));
  CUDACHECK(cudaFree(gpu_Simul));
  CUDACHECK(cudaFree(gpu_simRef));
  CUDACHECK(cudaFree(*gpu_MI));
  CUDACHECK(cudaFree(*gpu_N));
  CUDACHECK(cudaFree(*b_gpu_MI));
  CUDACHECK(cudaFree(gpu_dummydata));
  CUDACHECK(cudaFree(gpu_reflect));
  CUDACHECK(cudaFree(*gpu_terms_data));
  CUDACHECK(cudaFree(gpu_z));
  CUDACHECK(cudaFree(g_gpu_z1));
  CUDACHECK(cudaFree(k_gpu_x));
  CUDACHECK(cudaFree(c_gpu_ii));
  CUDACHECK(cudaFree(b_gpu_sldProfile));
  CUDACHECK(cudaFree(l_gpu_x));
  CUDACHECK(cudaFree(b_gpu_Lays));
  CUDACHECK(cudaFree(d_gpu_a));
  CUDACHECK(cudaFree(e_gpu_b));
  CUDACHECK(cudaFree(gpu_r2));
  CUDACHECK(cudaFree(gpu_r3));
  CUDACHECK(cudaFree(e_gpu_a));
  CUDACHECK(cudaFree(f_gpu_b));
  CUDACHECK(cudaFree(gpu_r10));
  CUDACHECK(cudaFree(gpu_r12));
  CUDACHECK(cudaFree(f_gpu_a));
  CUDACHECK(cudaFree(g_gpu_b));
  CUDACHECK(cudaFree(gpu_r6));
  CUDACHECK(cudaFree(gpu_r7));
  CUDACHECK(cudaFree(b_gpu_SLD));
  CUDACHECK(cudaFree(b_gpu_layers));
  CUDACHECK(cudaFree(m_gpu_x));
  CUDACHECK(cudaFree(d_gpu_ii));
  CUDACHECK(cudaFree(n_gpu_x));
  CUDACHECK(cudaFree(o_gpu_x));
  CUDACHECK(cudaFree(gpu_r13));
  CUDACHECK(cudaFree(c_gpu_dataPoints));
  CUDACHECK(cudaFree(h_gpu_b));
  CUDACHECK(cudaFree(gpu_r15));
  CUDACHECK(cudaFree(b_gpu_normalizedData));
  CUDACHECK(cudaFree(b_gpu_firstStep));
  CUDACHECK(cudaFree(b_gpu_secondStep));
  CUDACHECK(cudaFree(b_gpu_longStep));
  CUDACHECK(cudaFree(h_gpu_z1));
  CUDACHECK(cudaFree(i_gpu_z1));
  CUDACHECK(cudaFree(b_gpu_firstStepSquared));
  CUDACHECK(cudaFree(j_gpu_z1));
  CUDACHECK(cudaFree(k_gpu_z1));
  CUDACHECK(cudaFree(b_gpu_secondStepSquared));
  CUDACHECK(cudaFree(l_gpu_z1));
  CUDACHECK(cudaFree(m_gpu_z1));
  CUDACHECK(cudaFree(p_gpu_x));
  CUDACHECK(cudaFree(q_gpu_x));
  CUDACHECK(cudaFree(c_gpu_trianglesToRefine));
  CUDACHECK(cudaFree(d_gpu_trianglesToRefine));
  CUDACHECK(cudaFree(gpu_r33));
  CUDACHECK(cudaFree(b_gpu_segmentsToSplit));
  CUDACHECK(cudaFree(b_gpu_newDataPoints));
  CUDACHECK(cudaFree(gpu_r24));
  CUDACHECK(cudaFree(gpu_r26));
  CUDACHECK(cudaFree(gpu_r28));
  CUDACHECK(cudaFree(gpu_r29));
  CUDACHECK(cudaFree(gpu_r18));
  CUDACHECK(cudaFree(r_gpu_x));
  CUDACHECK(cudaFree(e_gpu_ii));
  CUDACHECK(cudaFree(s_gpu_x));
  CUDACHECK(cudaFree(t_gpu_x));
  CUDACHECK(cudaFree(gpu_r31));
  CUDACHECK(cudaFree(d_gpu_dataPoints));
  CUDACHECK(cudaFree(b_gpu_idx));
  CUDACHECK(cudaFree(b_gpu_iwork));
  CUDACHECK(cudaFree(b_gpu_ycol));
  CUDACHECK(cudaFree(b_gpu_firstSection));
  CUDACHECK(cudaFree(b_gpu_lastSection));
  CUDACHECK(cudaFree(b_gpu_simXdata));
  CUDACHECK(cudaFree(b_gpu_Simul));
  CUDACHECK(cudaFree(b_gpu_simRef));
  CUDACHECK(cudaFree(b_gpu_dummydata));
  CUDACHECK(cudaFree(b_gpu_reflect));
  CUDACHECK(cudaFree(b_gpu_z));
  CUDACHECK(cudaFree(n_gpu_z1));
  CUDACHECK(cudaFree(u_gpu_x));
  CUDACHECK(cudaFree(f_gpu_ii));
  CUDACHECK(cudaFree(gpu_cell6));

#undef CUDACHECK

}

// End of code generation (reflectivity_calculation_gpu.cu)
