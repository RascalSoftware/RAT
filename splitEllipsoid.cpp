//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// splitEllipsoid.cpp
//
// Code generation for function 'splitEllipsoid'
//

// Include files
#include "splitEllipsoid.h"
#include "RATMain_data.h"
#include "RATMain_types.h"
#include "calcEllipsoid.h"
#include "ifWhileCond.h"
#include "kmeans.h"
#include "makeCell.h"
#include "minOrMax.h"
#include "mrdivide_helper.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <stdio.h>

// Function Definitions
namespace RAT
{
  void splitEllipsoid(const ::coder::array<real_T, 2U> &u, real_T VS, ::coder::
                      array<real_T, 2U> &u1, ::coder::array<real_T, 2U> &u2,
                      real_T VE1_data[], int32_T VE1_size[2], real_T VE2_data[],
                      int32_T VE2_size[2], real_T *nosplit)
  {
    ::coder::array<real_T, 2U> B1;
    ::coder::array<real_T, 2U> B2;
    ::coder::array<real_T, 2U> b_u;
    ::coder::array<real_T, 2U> idx;
    ::coder::array<real_T, 2U> mu1;
    ::coder::array<real_T, 2U> mu2;
    ::coder::array<real_T, 2U> r2;
    ::coder::array<real_T, 2U> u1new;
    ::coder::array<real_T, 2U> u2new;
    ::coder::array<int32_T, 1U> r;
    ::coder::array<int32_T, 1U> r1;
    ::coder::array<boolean_T, 2U> b_VE1_data;
    cell_wrap_10 temp_u1[50];
    cell_wrap_10 temp_u2[50];
    real_T FS[50];
    real_T temp_VE1[50];
    real_T temp_VE2[50];
    real_T mu[2];
    real_T flag1;
    real_T flag2;
    real_T minFS;
    int32_T D;
    int32_T N;
    int32_T b_nosplit;
    int32_T iindx;
    boolean_T c_VE1_data;

    //  function [u1, u2, VE1, VE2, nosplit] = split_ellipsiod(u, VS)
    //
    //  This function takes in a set of multi-dimensional data points u and the
    //  sample volume (VS) that they occupy. It uses the k-means algorthim to
    //  split the points into two sub-clusters and uses an optimisation scheme to
    //  re-assign points, if necessary, between the sub-clusters. This is based
    //  on the description in Algorithm 1 of the MULTINEST paper by Feroz,
    //  Hobson, and Bridges, MNRAS, 398, 1601-1614 (2009).
    //
    //  The function returns the points in the two sub-cluster u1 and u2, and
    //  the volumes of the ellipsoid subclusters VE1 and VE2.  The flag nosplit
    //  is set to 1 if the splitting cannot be done; otherwise = 0.
    //
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //  maximum number of attempts to recluster points
    //  default return values
    b_nosplit = 0;
    VE1_size[0] = 0;
    VE1_size[1] = 0;
    VE2_size[0] = 0;
    VE2_size[1] = 0;
    u1.set_size(0, 0);
    u2.set_size(0, 0);

    //  extract number of samples and number of dimensions
    N = u.size(0);
    D = u.size(1);

    //  check total number of samples
    if (u.size(0) < 2.0 * (static_cast<real_T>(u.size(1)) + 1.0)) {
      if (DEBUG != 0.0) {
        printf("CANT SPLIT: total number of samples is too small!  N = %d\n",
               u.size(0));
        fflush(stdout);
      }

      b_nosplit = 1;
    } else {
      int32_T b_i;
      int32_T end;
      int32_T i;
      int32_T i1;
      int32_T loop_ub;
      int32_T n1;
      int32_T n2;

      //  use kmeans to separate the data points into two sub-clusters
      kmeans(u, idx, mu);
      end = (idx.size(1) << 1) - 1;
      iindx = 0;
      for (i = 0; i <= end; i++) {
        if (idx[i] == 1.0) {
          iindx++;
        }
      }

      r.set_size(iindx);
      iindx = 0;
      for (i = 0; i <= end; i++) {
        if (idx[i] == 1.0) {
          r[iindx] = i + 1;
          iindx++;
        }
      }

      end = u.size(1);
      u1.set_size(r.size(0), u.size(1));
      for (b_i = 0; b_i < end; b_i++) {
        loop_ub = r.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          u1[i1 + u1.size(0) * b_i] = u[(r[i1] + u.size(0) * b_i) - 1];
        }
      }

      end = (idx.size(1) << 1) - 1;
      iindx = 0;
      for (i = 0; i <= end; i++) {
        if (idx[i] == 2.0) {
          iindx++;
        }
      }

      r1.set_size(iindx);
      iindx = 0;
      for (i = 0; i <= end; i++) {
        if (idx[i] == 2.0) {
          r1[iindx] = i + 1;
          iindx++;
        }
      }

      end = u.size(1);
      u2.set_size(r1.size(0), u.size(1));
      for (b_i = 0; b_i < end; b_i++) {
        loop_ub = r1.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          u2[i1 + u2.size(0) * b_i] = u[(r1[i1] + u.size(0) * b_i) - 1];
        }
      }

      n1 = r.size(0);

      //  number of samples in S1
      n2 = r1.size(0);

      //  number of samples in S2
      //  check number of points in subclusters
      if ((static_cast<uint32_T>(r.size(0)) < u.size(1) + 1U) ||
          (static_cast<uint32_T>(r1.size(0)) < u.size(1) + 1U)) {
        if (DEBUG != 0.0) {
          printf("CANT SPLIT: number of samples in subclusters is too small! n1 = %d, n2 = %d\n",
                 r.size(0), r1.size(0));
          fflush(stdout);
        }

        b_nosplit = 1;
      } else {
        int32_T counter;

        //  preallocate temp arrays
        makeCell(temp_u1);
        for (i = 0; i < 50; i++) {
          temp_u2[i] = temp_u1[i];
          temp_VE1[i] = 0.0;
          temp_VE2[i] = 0.0;
          FS[i] = 0.0;
        }

        // %%%%%%%%%%%%%%%%%%%%%%%%%
        counter = 0;
        real_T VS1;
        real_T VS2;
        int32_T exitg1;
        do {
          exitg1 = 0;

          //  calculate minimum volume of ellipsoids
          VS1 = VS * static_cast<real_T>(n1) / static_cast<real_T>(N);
          VS2 = VS * static_cast<real_T>(n2) / static_cast<real_T>(N);

          //  calculate properties of bounding ellipsoids for the two subclusters
          calcEllipsoid(u1, VS1, B1, mu1, VE1_data, VE1_size, &flag1);
          calcEllipsoid(u2, VS2, B2, mu2, VE2_data, VE2_size, &flag2);

          //  check flags
          if ((flag1 != 0.0) || (flag2 != 0.0)) {
            if (DEBUG != 0.0) {
              printf("CANT SPLIT!!\n");
              fflush(stdout);
            }

            b_nosplit = 1;
            exitg1 = 1;
          } else {
            int32_T reassign;
            uint32_T m1;
            uint32_T m2;

            //  construct temporary arrays and cell arrays containing results for
            //  each pass through the loop
            temp_u1[counter].f1.set_size(u1.size(0), u1.size(1));
            end = u1.size(1);
            for (b_i = 0; b_i < end; b_i++) {
              loop_ub = u1.size(0);
              for (i1 = 0; i1 < loop_ub; i1++) {
                temp_u1[counter].f1[i1 + temp_u1[counter].f1.size(0) * b_i] =
                  u1[i1 + u1.size(0) * b_i];
              }
            }

            temp_u2[counter].f1.set_size(u2.size(0), u2.size(1));
            end = u2.size(1);
            for (b_i = 0; b_i < end; b_i++) {
              loop_ub = u2.size(0);
              for (i1 = 0; i1 < loop_ub; i1++) {
                temp_u2[counter].f1[i1 + temp_u2[counter].f1.size(0) * b_i] =
                  u2[i1 + u2.size(0) * b_i];
              }
            }

            temp_VE1[counter] = VE1_data[0];
            temp_VE2[counter] = VE2_data[0];
            FS[counter] = (VE1_data[0] + VE2_data[0]) / VS;

            //  DEBUG print statement
            //      if DEBUG
            //          fprintf('SPLIT ELLIPSOID: counter = %d, numreassigned = %d\n', ...
            //                  int32(counter), int32(numreassigned));
            //      end
            // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            //  check if points need to be reassigned to the other subcluster
            reassign = 0;
            m1 = 0U;
            m2 = 0U;
            u1new.set_size(N, D);
            u2new.set_size(N, D);
            for (b_i = 0; b_i < D; b_i++) {
              for (i1 = 0; i1 < N; i1++) {
                u1new[i1 + u1new.size(0) * b_i] = 0.0;
                u2new[i1 + u2new.size(0) * b_i] = 0.0;
              }
            }

            //  for all points get the Mahalanobis distance between each point and
            //  the centroid of each ellipse and assign accordingly
            for (i = 0; i < N; i++) {
              real_T b;
              real_T b_b;

              //  get d = (u-mu)^T * B^-1 * (u-mu)
              end = u.size(1);
              b_u.set_size(1, u.size(1));
              for (b_i = 0; b_i < end; b_i++) {
                b_u[b_i] = u[i + u.size(0) * b_i] - mu1[mu1.size(0) * b_i];
              }

              coder::internal::mrdiv(b_u, B1, r2);
              b = 0.0;
              end = r2.size(1);
              for (b_i = 0; b_i < end; b_i++) {
                b += r2[b_i] * (u[i + u.size(0) * b_i] - mu1[mu1.size(0) * b_i]);
              }

              end = u.size(1);
              b_u.set_size(1, u.size(1));
              for (b_i = 0; b_i < end; b_i++) {
                b_u[b_i] = u[i + u.size(0) * b_i] - mu2[mu2.size(0) * b_i];
              }

              coder::internal::mrdiv(b_u, B2, r2);
              b_b = 0.0;
              end = r2.size(1);
              for (b_i = 0; b_i < end; b_i++) {
                b_b += r2[b_i] * (u[i + u.size(0) * b_i] - mu2[mu2.size(0) * b_i]);
              }

              //  calculate hk = VEk * duk / VSk;
              end = VE1_size[1];
              for (b_i = 0; b_i < end; b_i++) {
                loop_ub = VE1_size[0];
                for (i1 = 0; i1 < loop_ub; i1++) {
                  c_VE1_data = (VE1_data[0] * b / VS1 < VE2_data[0] * b_b / VS2);
                }
              }

              b_VE1_data.set(&c_VE1_data, VE1_size[0], VE1_size[1]);
              if (coder::internal::b_ifWhileCond(b_VE1_data)) {
                m1++;
                end = u.size(1);
                for (b_i = 0; b_i < end; b_i++) {
                  u1new[(static_cast<int32_T>(m1) + u1new.size(0) * b_i) - 1] =
                    u[i + u.size(0) * b_i];
                }

                //  check if point has been reassigned or not
                if (idx[i] != 1.0) {
                  reassign = 1;
                  idx[i] = 1.0;
                }
              } else {
                m2++;
                end = u.size(1);
                for (b_i = 0; b_i < end; b_i++) {
                  u2new[(static_cast<int32_T>(m2) + u2new.size(0) * b_i) - 1] =
                    u[i + u.size(0) * b_i];
                }

                //  check if point has been reassigned or not
                if (idx[i] != 2.0) {
                  reassign = 1;
                  idx[i] = 2.0;
                }
              }
            }

            n1 = static_cast<int32_T>(m1);
            n2 = static_cast<int32_T>(m2);
            if (1 > static_cast<int32_T>(m1)) {
              end = 0;
            } else {
              end = static_cast<int32_T>(m1);
            }

            loop_ub = u1new.size(1);
            u1.set_size(end, u1new.size(1));
            for (b_i = 0; b_i < loop_ub; b_i++) {
              for (i1 = 0; i1 < end; i1++) {
                u1[i1 + u1.size(0) * b_i] = u1new[i1 + u1new.size(0) * b_i];
              }
            }

            if (1 > static_cast<int32_T>(m2)) {
              end = 0;
            } else {
              end = static_cast<int32_T>(m2);
            }

            loop_ub = u2new.size(1);
            u2.set_size(end, u2new.size(1));
            for (b_i = 0; b_i < loop_ub; b_i++) {
              for (i1 = 0; i1 < end; i1++) {
                u2[i1 + u2.size(0) * b_i] = u2new[i1 + u2new.size(0) * b_i];
              }
            }

            //  update counter
            counter++;
            if ((reassign == 0) || (counter + 1 > 50)) {
              //  DEBUG print statement
              //          if DEBUG
              //              %fprintf('SPLIT ELLIPSOID: counter = %d, FS = %f, numreassigned = %d\n', counter, (VE1+VE2)/VS, numreassigned);
              //              if counter > max_attempt
              //                  fprintf('SPLIT ELLIPSOID: exceeded maximum attempts; take min F(S).\n');
              //              end
              //          end
              exitg1 = 1;
            }
          }
        } while (exitg1 == 0);

        //  find minimum F(S) and return
        coder::internal::minimum(FS, &minFS, &iindx);
        u1.set_size(temp_u1[iindx - 1].f1.size(0), temp_u1[iindx - 1].f1.size(1));
        end = temp_u1[iindx - 1].f1.size(1);
        for (b_i = 0; b_i < end; b_i++) {
          loop_ub = temp_u1[iindx - 1].f1.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            u1[i1 + u1.size(0) * b_i] = temp_u1[iindx - 1].f1[i1 + temp_u1[iindx
              - 1].f1.size(0) * b_i];
          }
        }

        u2.set_size(temp_u2[iindx - 1].f1.size(0), temp_u2[iindx - 1].f1.size(1));
        end = temp_u2[iindx - 1].f1.size(1);
        for (b_i = 0; b_i < end; b_i++) {
          loop_ub = temp_u2[iindx - 1].f1.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            u2[i1 + u2.size(0) * b_i] = temp_u2[iindx - 1].f1[i1 + temp_u2[iindx
              - 1].f1.size(0) * b_i];
          }
        }

        VE1_size[0] = 1;
        VE1_size[1] = 1;
        VE1_data[0] = temp_VE1[iindx - 1];
        VE2_size[0] = 1;
        VE2_size[1] = 1;
        VE2_data[0] = temp_VE2[iindx - 1];
        if (DEBUG != 0.0) {
          printf("SPLIT ELLIPSOID: min F(S) = %f\n", minFS);
          fflush(stdout);
        }
      }
    }

    *nosplit = b_nosplit;
  }
}

// End of code generation (splitEllipsoid.cpp)
