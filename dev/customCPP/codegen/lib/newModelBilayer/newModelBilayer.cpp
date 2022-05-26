//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// newModelBilayer.cpp
//
// Code generation for function 'newModelBilayer'
//

// Include files
#include "newModelBilayer.h"
#include "erf.h"
#include "exp.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "sum.h"
#include "coder_array.h"

// Function Declarations
static void convstep(const real_T x[200], real_T xw, real_T xcen, real_T s,
                     real_T f[200]);

static void gssian(const real_T z[200], real_T Z, real_T A, real_T f[200]);

static void lipid(real_T position, real_T APM, real_T alklength,
                  real_T Roughness, real_T direction, real_T coverage,
                  real_T SLD[200], real_T vfTot[200]);

// Function Definitions
//
// function f = convstep(x,xw,xcen,s,h)
static void convstep(const real_T x[200], real_T xw, real_T xcen, real_T s,
                     real_T f[200])
{
  real_T b[200];
  real_T b_x[200];
  real_T dv[200];
  real_T d;
  real_T l;
  real_T r;
  int32_T i;
  // -------------------------------------------------------------------------
  //  Produces a step function convoluted with an error function
  //  Convstep [x,xw,xcen,s,h]
  //        x = vector of x values
  //       xw = Width of step function
  //     xcen = Centre point of step function
  //        s = Roughness parameter
  //        h = Height of step function.
  // 'newModelBilayer:278' r = xcen + (xw/2);
  r = xcen + xw / 2.0;
  // 'newModelBilayer:279' l = xcen - (xw/2);
  l = xcen - xw / 2.0;
  // 'newModelBilayer:281' a = (x-l)./((2^0.5)*s);
  // 'newModelBilayer:282' b = (x-r)./((2^0.5)*s);
  // 'newModelBilayer:284' f = (h/2)*(erf(a)-erf(b));
  d = 1.4142135623730951 * s;
  for (i = 0; i < 200; i++) {
    b_x[i] = (x[i] - l) / d;
  }
  coder::b_erf(b_x, b);
  for (i = 0; i < 200; i++) {
    b_x[i] = (x[i] - r) / d;
  }
  coder::b_erf(b_x, dv);
  for (i = 0; i < 200; i++) {
    d = b[i] - dv[i];
    b[i] = d;
    f[i] = 0.5 * d;
  }
}

//
// function f = gssian(z,Z,N,A)
static void gssian(const real_T z[200], real_T Z, real_T A, real_T f[200])
{
  real_T b_z[200];
  real_T dv[200];
  real_T a;
  real_T c;
  int32_T i;
  // -------------------------------------------------------------------------
  // f(z) = gaussian(z,Z,N,A)
  //
  // 	produces a gaussian at centre Z, of height
  // 	N and 1/e half width of A.
  // 'newModelBilayer:262' pi = 3.142;
  // a = A*sqrt(2*pi);
  // 'newModelBilayer:264' f = (N/(A*sqrt(pi)))*exp(-((z-Z).^2)/(A^2));
  c = A * A;
  a = 1.0 / (A * 1.7725687574816384);
  for (i = 0; i < 200; i++) {
    b_z[i] = z[i] - Z;
  }
  coder::power(b_z, dv);
  for (i = 0; i < 200; i++) {
    dv[i] = -dv[i] / c;
  }
  coder::c_exp(dv);
  for (i = 0; i < 200; i++) {
    f[i] = a * dv[i];
  }
}

//
// function [SLD,vfTot] =
// lipid(x,position,APM,alklength,Roughness,direction,carbons,coverage)
static void lipid(real_T position, real_T APM, real_T alklength,
                  real_T Roughness, real_T direction, real_T coverage,
                  real_T SLD[200], real_T vfTot[200])
{
  coder::array<real_T, 2U> alk;
  coder::array<real_T, 2U> b_nDalk;
  coder::array<real_T, 2U> nDalk;
  real_T dv[200];
  real_T dv1[200];
  real_T nDGch3[200];
  real_T nDGchol[200];
  real_T nDGcoo[200];
  real_T nDGglyc[200];
  real_T nDGpo4[200];
  real_T Ach2;
  real_T Zcoo;
  real_T d;
  real_T step;
  int32_T i;
  int32_T i1;
  int32_T loop_ub_tmp;
  uint32_T num;
  //  hold on
  //  plot(x,sldWat,'b-');
  //  hold off
  // -------------------------------------------------------------------------
  // define all the neutron b's.
  // 'newModelBilayer:100' bc = 0.6646e-4;
  // Carbon
  // 'newModelBilayer:101' bo = 0.5843e-4;
  // Oxygen
  // 'newModelBilayer:102' bh = -0.3739e-4;
  // Hydrogen
  // 'newModelBilayer:103' bp = 0.513e-4;
  // Phosphorus
  // 'newModelBilayer:104' bn = 0.936e-4;
  // Nitrogen
  // 'newModelBilayer:105' bd = 0.6671e-4;
  // Deuterium
  // Work out the total scattering length in each fragment....
  // 'newModelBilayer:108' COO = (4*bo) + (2*bc);
  // 'newModelBilayer:109' GLYC = (3*bc) + (5*bh);
  // 'newModelBilayer:110' CH3 = (2*bc) + (6*bh);
  // 'newModelBilayer:111' PO4 = (1*bp) + (4*bo);
  // 'newModelBilayer:112' CH2 = (2*bc) + (4*bh);
  // 'newModelBilayer:113' H2O = (2*bh) + (1*bo);
  // 'newModelBilayer:114' D2O = (2*bd) + (1*bo);
  // 'newModelBilayer:115' CHOL = (5*bc) + (13*bh) + (1*bn);
  // Define volumes....
  // 'newModelBilayer:118' Vcoo = 44.09;
  // Carboxy group..
  // 'newModelBilayer:119' Vglyc = 63.59;
  // Glycerol group
  // 'newModelBilayer:120' Vpo4 = 65.63;
  // Phospho group..
  // 'newModelBilayer:121' Vchol = 108.6;
  // Choline group
  // 'newModelBilayer:122' Vwat = 30.18;
  // Water molecule
  // 'newModelBilayer:123' Vch3 = 53.6;
  // Methyl group
  // 'newModelBilayer:124' Vch2 = 27.9;
  // Methylene group
  // and intrinsic roughness'
  // 'newModelBilayer:127' Ach3 = 2.95;
  // 'newModelBilayer:128' Acoo = 2.73;
  // 'newModelBilayer:129' Aglyc = 2.37;
  // 'newModelBilayer:130' Apo4 = 3.08;
  // 'newModelBilayer:131' Achol = 3.48;
  // 'newModelBilayer:132' Ach2 = 3;
  // Include a general bilayer roughness
  // Use R = sqrt(i2 + r2)
  // 'newModelBilayer:136' Roughness = Roughness^2;
  Roughness *= Roughness;
  // 'newModelBilayer:137' Ach3 = sqrt(Ach3^2 + Roughness);
  // 'newModelBilayer:138' Acoo = sqrt(Acoo^2 + Roughness);
  // 'newModelBilayer:139' Aglyc = sqrt(Aglyc^2 + Roughness);
  // 'newModelBilayer:140' Apo4 = sqrt(Apo4^2 + Roughness);
  // 'newModelBilayer:141' Achol = sqrt(Achol^2 + Roughness);
  // 'newModelBilayer:142' Ach2 = sqrt(Ach2^2 + Roughness);
  Ach2 = Roughness + 9.0;
  coder::b_sqrt(&Ach2);
  // Each gaussian has a height of 1...
  // 'newModelBilayer:145' ncoo = 1;
  // i.e there's 1 coo fragment, 1 glyc fragment etc..
  // 'newModelBilayer:146' nglyc = 1;
  // 'newModelBilayer:147' npo4 = 1;
  // 'newModelBilayer:148' nchol = 1;
  // 'newModelBilayer:149' nch3 = 1;
  // -----------------------------------------------------
  //
  //                        Chains
  //
  // ------------------------------------------------------
  // construct the alkyl chain out of a series of Gaussians
  // 'newModelBilayer:159' nCh2 = carbons-2;
  // 'newModelBilayer:160' step = alklength/nCh2;
  step = alklength / 14.0;
  // 'newModelBilayer:161' num = 1;
  num = 1U;
  // 'newModelBilayer:162' nAlks = alklength/step;
  // 'newModelBilayer:163' alk = zeros(length(x),nAlks);
  loop_ub_tmp = static_cast<int32_T>(alklength / step);
  alk.set_size(200, loop_ub_tmp);
  for (i = 0; i < loop_ub_tmp; i++) {
    for (i1 = 0; i1 < 200; i1++) {
      alk[i1 + 200 * i] = 0.0;
    }
  }
  // 'newModelBilayer:164' for i = 1:step:alklength
  i = static_cast<int32_T>((alklength + (step - 1.0)) / step);
  if (0 <= i - 1) {
    for (i1 = 0; i1 < 200; i1++) {
      dv[i1] = static_cast<real_T>(i1) + 1.0;
    }
  }
  for (int32_T b_i{0}; b_i < i; b_i++) {
    // 'newModelBilayer:165' alk(:,num) =
    // gssian(x,(position+(i*direction)),1,Ach2);
    gssian(dv, position + (static_cast<real_T>(b_i) * step + 1.0) * direction,
           Ach2, dv1);
    for (i1 = 0; i1 < 200; i1++) {
      alk[i1 + 200 * (static_cast<int32_T>(num) - 1)] = dv1[i1];
    }
    // 'newModelBilayer:166' num = num + 1;
    num++;
  }
  // 'alk' is the number of 'molecules' per unit
  // length. To get per unit volume we divide by
  // the APM. Number per unit volume will be
  // the NUMBER DENSITY
  // 'newModelBilayer:173' nDalk = alk ./ APM;
  nDalk.set_size(200, alk.size(1));
  loop_ub_tmp = alk.size(1);
  for (i = 0; i < loop_ub_tmp; i++) {
    for (i1 = 0; i1 < 200; i1++) {
      nDalk[i1 + 200 * i] = alk[i1 + 200 * i] / APM;
    }
  }
  // Now, we need to calculate a volume fraction
  // i.e. a dimensionless quantity between 0 and 1.
  // We just multiply the number density by the component vol
  // 'newModelBilayer:178' vfalk = nDalk .* (2*Vch2);
  // Dimensionless since ≈3 * ≈-3
  //  %..can then calculate for water
  //  vfwat = ones(size(vfalk,1),1);
  //  for i = 1:size(alk,2)
  //      vfwat = vfwat-vfalk(:,i);
  //  end;
  //  nDwat = vfwat / Vwat;
  // ***********************************************************%
  //                                                            %
  //                    Headgroup                               %
  //                                                            %
  // ************************************************************
  // Define centre positions
  // 'newModelBilayer:195' Zcoo = position + (alklength*direction);
  Zcoo = position + alklength * direction;
  // 'newModelBilayer:196' Zglyc = Zcoo + (2.7*direction);
  // 'newModelBilayer:197' Zpo4 = Zcoo + (4.22*direction);
  // 'newModelBilayer:198' Zchol = Zcoo + (5.96*direction);
  // 'newModelBilayer:199' Zch3 = position;
  // Make gaussians
  // 'newModelBilayer:202' nGcoo = gssian(x,Zcoo,ncoo,Acoo);
  // 'newModelBilayer:203' nGglyc = gssian(x,Zglyc,nglyc,Aglyc);
  // 'newModelBilayer:204' nGpo4 = gssian(x,Zpo4,npo4,Apo4);
  // 'newModelBilayer:205' nGchol = gssian(x,Zchol,nchol,Achol);
  // 'newModelBilayer:206' nGch3 = gssian(x,Zch3,nch3,Ach3);
  // Gaussians are number of 'molecules' per unit
  // length. To get per unit volume we divide by
  // the APM. Number per unit volume will be
  // the NUMBER DENSITY
  // 'newModelBilayer:212' nDGcoo = nGcoo / APM;
  d = Roughness + 7.4529;
  coder::b_sqrt(&d);
  for (i = 0; i < 200; i++) {
    dv[i] = static_cast<real_T>(i) + 1.0;
  }
  gssian(dv, Zcoo, d, dv1);
  for (i = 0; i < 200; i++) {
    nDGcoo[i] = dv1[i] / APM;
  }
  // 'newModelBilayer:213' nDGglyc = nGglyc / APM;
  d = Roughness + 5.6169;
  coder::b_sqrt(&d);
  for (i = 0; i < 200; i++) {
    dv[i] = static_cast<real_T>(i) + 1.0;
  }
  gssian(dv, Zcoo + 2.7 * direction, d, dv1);
  for (i = 0; i < 200; i++) {
    nDGglyc[i] = dv1[i] / APM;
  }
  // 'newModelBilayer:214' nDGpo4 = nGpo4 / APM;
  d = Roughness + 9.4864;
  coder::b_sqrt(&d);
  for (i = 0; i < 200; i++) {
    dv[i] = static_cast<real_T>(i) + 1.0;
  }
  gssian(dv, Zcoo + 4.22 * direction, d, dv1);
  for (i = 0; i < 200; i++) {
    nDGpo4[i] = dv1[i] / APM;
  }
  // 'newModelBilayer:215' nDGchol = nGchol / APM;
  d = Roughness + 12.1104;
  coder::b_sqrt(&d);
  for (i = 0; i < 200; i++) {
    dv[i] = static_cast<real_T>(i) + 1.0;
  }
  gssian(dv, Zcoo + 5.96 * direction, d, dv1);
  for (i = 0; i < 200; i++) {
    nDGchol[i] = dv1[i] / APM;
  }
  // 'newModelBilayer:216' nDGch3 = nGch3 / APM;
  d = Roughness + 8.7025;
  coder::b_sqrt(&d);
  for (i = 0; i < 200; i++) {
    dv[i] = static_cast<real_T>(i) + 1.0;
  }
  gssian(dv, position, d, dv1);
  for (i = 0; i < 200; i++) {
    nDGch3[i] = dv1[i] / APM;
  }
  // Now, we need to calculate a volume fraction
  // i.e. a dimensionless quantity between 0 and 1.
  // We just multiply by the component vols
  // 'newModelBilayer:221' vfGcoo = nDGcoo * Vcoo;
  // ...these are now dimensionless
  // 'newModelBilayer:222' vfGglyc = nDGglyc * Vglyc;
  // since ≈3 * ≈-3
  // 'newModelBilayer:223' vfGpo4 = nDGpo4 * Vpo4;
  // 'newModelBilayer:224' vfGchol = nDGchol * Vchol;
  // 'newModelBilayer:225' vfGch3 = nDGch3 * (2*Vch3);
  // ------------------------------------------------------------
  //
  //                Scattering Length Density
  //
  // -------------------------------------------------------------
  // In each case, the SLD is the number density times sum b....
  // 'newModelBilayer:234' sld_coo = nDGcoo * COO;
  // 'newModelBilayer:235' sld_glyc = nDGglyc * GLYC;
  // 'newModelBilayer:236' sld_po4 = nDGpo4 * PO4;
  // 'newModelBilayer:237' sld_chol = nDGchol * CHOL;
  // 'newModelBilayer:238' sld_ch3 = nDGch3 * CH3;
  // 'newModelBilayer:239' sldAlk = nDalk .* CH2;
  // 'newModelBilayer:240' sldChain = sum(sldAlk,2);
  // 'newModelBilayer:241' SLD = sld_coo + sld_glyc + sld_po4 + sld_chol +
  // sld_ch3 + sldChain';
  // --------------------------------------------------------------
  //
  //                Free volume calculation
  //
  // ---------------------------------------------------------------
  // 'newModelBilayer:248' vfHead = vfGcoo + vfGglyc + vfGpo4 + vfGchol +
  // vfGch3; 'newModelBilayer:249' vfTail = sum(vfalk,2); 'newModelBilayer:250'
  // vfTot = vfHead + vfTail'; Try scaling for coverage 'newModelBilayer:252'
  // vfTot = vfTot * coverage;
  b_nDalk.set_size(200, nDalk.size(1));
  loop_ub_tmp = nDalk.size(1);
  for (i = 0; i < loop_ub_tmp; i++) {
    for (i1 = 0; i1 < 200; i1++) {
      b_nDalk[i1 + 200 * i] = nDalk[i1 + 200 * i] * 55.8;
    }
  }
  coder::sum(b_nDalk, dv);
  for (i = 0; i < 200; i++) {
    vfTot[i] =
        (((((nDGcoo[i] * 44.09 + nDGglyc[i] * 63.59) + nDGpo4[i] * 65.63) +
           nDGchol[i] * 108.6) +
          nDGch3[i] * 107.2) +
         dv[i]) *
        coverage;
  }
  // 'newModelBilayer:253' SLD = SLD * coverage;
  nDalk.set_size(200, nDalk.size(1));
  loop_ub_tmp = nDalk.size(1);
  for (i = 0; i < loop_ub_tmp; i++) {
    for (i1 = 0; i1 < 200; i1++) {
      nDalk[i1 + 200 * i] = nDalk[i1 + 200 * i] * -1.6640000000000003E-5;
    }
  }
  coder::sum(nDalk, dv);
  for (i = 0; i < 200; i++) {
    SLD[i] = (((((nDGcoo[i] * 0.00036664 + nDGglyc[i] * 1.2429999999999988E-5) +
                 nDGpo4[i] * 0.00028502) +
                nDGchol[i] * -6.0170000000000015E-5) +
               nDGch3[i] * -9.1420000000000016E-5) +
              dv[i]) *
             coverage;
  }
}

//
// function output = newModelBilayer(params,bulk_in,bulk_out,contrast)
void newModelBilayer(const coder::array<real_T, 1U> &params, real_T,
                     const real_T bulk_out[3], real_T contrast,
                     real_T output[2][200])
{
  real_T SLD[200];
  real_T SLD2[200];
  real_T SLDmon[200];
  real_T dv[200];
  real_T ox[200];
  real_T subs[200];
  real_T vfTot[200];
  real_T vfTot2[200];
  real_T vfTotMon[200];
  real_T b;
  real_T d2o_molfr;
  real_T d2o_molfr_tmp;
  int32_T i;
  // 'newModelBilayer:3' bd = 0.6671e-4;
  // Deuterium
  // 'newModelBilayer:4' bo = 0.5843e-4;
  // Oxygen
  // 'newModelBilayer:5' bh = -0.3739e-4;
  // Hydrogen
  // 'newModelBilayer:6' D2O = (2*bd) + (1*bo);
  // 'newModelBilayer:7' H2O = (2*bh) + (1*bo);
  // 'newModelBilayer:9' subrough = params(1);
  // 'newModelBilayer:10' ox_thick = params(2);
  // 'newModelBilayer:11' oxHydration = params(3);
  // 'newModelBilayer:12' samAPM = params(4);
  // 'newModelBilayer:13' samRough = params(5);
  // 'newModelBilayer:14' samLength = params(6);
  // 'newModelBilayer:15' bilayerPos = params(7);
  // 'newModelBilayer:16' bilayerAPM = params(8);
  // bilayerLength = params(9);5
  // 'newModelBilayer:18' bilayerRough = params(10);
  // 'newModelBilayer:19' methylOffset = 3;
  // params(11);
  // 'newModelBilayer:20' bil_coverage = params(11);
  // 'newModelBilayer:21' sam_coverage = params(12);
  // 'newModelBilayer:23' sldwat = bulk_out(contrast);
  // 'newModelBilayer:24' d2o_molfr = (1/D2O-H2O)*((sldwat/0.036182336306)-H2O);
  d2o_molfr_tmp = bulk_out[static_cast<int32_T>(contrast) - 1];
  d2o_molfr = 5212.4055414998566 *
              (d2o_molfr_tmp / 0.036182336306 - -1.6349999999999998E-5);
  // 'newModelBilayer:26' x = 1:200;
  // Substrate and Oxide
  // Make a substrate bit...
  // 'newModelBilayer:29' subcen = 0;
  // 'newModelBilayer:30' subs = convstep(x,50,0,subrough,1);
  for (i = 0; i < 200; i++) {
    dv[i] = static_cast<real_T>(i) + 1.0;
  }
  convstep(dv, 50.0, 0.0, params[0], subs);
  // 'newModelBilayer:31' subs_edge = 25;
  // 'newModelBilayer:32' ox_surf = subs_edge + ox_thick;
  // 'newModelBilayer:33' ox = convstep(x,ox_thick,(subs_edge +
  // (ox_thick/2)),subrough,1);
  for (i = 0; i < 200; i++) {
    dv[i] = static_cast<real_T>(i) + 1.0;
  }
  real_T length;
  convstep(dv, params[1], params[1] / 2.0 + 25.0, params[0], ox);
  // monolayer
  // 'newModelBilayer:36' APM = samAPM;
  // 48;
  // 'newModelBilayer:37' length = samLength;
  // 16;
  // 'newModelBilayer:38' roughness = samRough;
  // 3;
  // 'newModelBilayer:39' direction = 1;
  // 'newModelBilayer:40' carbons = 16;
  // 'newModelBilayer:41' [SLDmon,vfTotMon] =
  // lipid(x,ox_surf,APM,length,roughness,direction,carbons,sam_coverage);
  lipid(params[1] + 25.0, params[3], params[5], params[4], 1.0, params[11],
        SLDmon, vfTotMon);
  // top lipid
  // Bilayer
  // 'newModelBilayer:45' position = bilayerPos;
  // 130;
  // 'newModelBilayer:46' APM = bilayerAPM;
  // 68;
  // 'newModelBilayer:47' chainsVolume = 892.8;
  // 'newModelBilayer:48' length = chainsVolume/APM;
  length = 892.8 / params[7];
  // 'newModelBilayer:49' roughness = bilayerRough;
  // 3;
  // 'newModelBilayer:50' direction = 1;
  // 'newModelBilayer:51' carbons = 16;
  // 'newModelBilayer:53' [SLD,vfTot] =
  // lipid(x,position,APM,length,roughness,direction,carbons,bil_coverage);
  lipid(params[6], params[7], length, params[9], 1.0, params[10], SLD, vfTot);
  // top lipid
  // 'newModelBilayer:54' [SLD2,vfTot2] =
  // lipid(x,position-methylOffset,APM,length,roughness,-direction,carbons,bil_coverage);
  lipid(params[6] - 3.0, params[7], length, params[9], -1.0, params[10], SLD2,
        vfTot2);
  // bottom lipid
  // SLD
  // 'newModelBilayer:58' ox_scat_length = (oxHydration * sldwat) + ((1 -
  // oxHydration) * 3.41e-6);
  b = params[2] * d2o_molfr_tmp + (1.0 - params[2]) * 3.41E-6;
  // 'newModelBilayer:59' SLDox = ox * ox_scat_length;
  // 'newModelBilayer:60' SLDsub = subs * 2.07e-6;
  // 'newModelBilayer:62' vfWat = ones(size(vfTot,1),1);
  // 'newModelBilayer:63' vfWat = vfWat - vfTot - vfTot2 - subs - ox - vfTotMon;
  // 'newModelBilayer:64' ndWat = vfWat/30.13;
  // 'newModelBilayer:65' sldWat = ndWat * ((d2o_molfr * D2O) + (1 -
  // d2o_molfr)*H2O);
  d2o_molfr_tmp =
      d2o_molfr * 0.00019185 + (1.0 - d2o_molfr) * -1.6349999999999998E-5;
  //  figure(2)
  //  hold off
  //  plot(x,SLDsub,'k-');
  //  hold on
  //  plot(x,SLDox,'r-');
  //  plot(x,SLDmon,'g-');
  //  plot(x,SLD,'m-');
  //  plot(x,SLD2,'m-');
  //  plot(x,sldWat,'b-');
  // 'newModelBilayer:77' less = sldWat < 0;
  // 'newModelBilayer:78' sldWat(less) = 0;
  // 'newModelBilayer:80' sldTot = SLD + SLD2 + SLDox + SLDsub + SLDmon +
  // sldWat;
  //  figure (1);
  //  clf
  //  plot(x,sldTot,'k-');
  // 'newModelBilayer:87' output = [x(:) sldTot(:)];
  for (i = 0; i < 200; i++) {
    real_T d;
    real_T d1;
    real_T d2;
    d = subs[i];
    d1 = ox[i];
    d2 = (((((1.0 - vfTot[i]) - vfTot2[i]) - d) - d1) - vfTotMon[i]) / 30.13 *
         d2o_molfr_tmp;
    if (d2 < 0.0) {
      d2 = 0.0;
    }
    output[0][i] = static_cast<real_T>(i) + 1.0;
    output[1][i] =
        ((((SLD[i] + SLD2[i]) + d1 * b) + d * 2.07E-6) + SLDmon[i]) + d2;
  }
}

// End of code generation (newModelBilayer.cpp)
