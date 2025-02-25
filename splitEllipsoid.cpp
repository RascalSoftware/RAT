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
#include "RATMain_types.h"
#include "calcEllipsoid.h"
#include "ifWhileCond.h"
#include "kmeans.h"
#include "makeCell.h"
#include "minOrMax.h"
#include "mrdivide_helper.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void splitEllipsoid(const ::coder::array<double, 2U> &u, double VS, ::coder::
                      array<double, 2U> &u1, ::coder::array<double, 2U> &u2,
                      double VE1_data[], int VE1_size[2], double VE2_data[], int
                      VE2_size[2], double *nosplit)
  {
    ::coder::array<double, 2U> B1;
    ::coder::array<double, 2U> B2;
    ::coder::array<double, 2U> b_u;
    ::coder::array<double, 2U> idx;
    ::coder::array<double, 2U> mu1;
    ::coder::array<double, 2U> mu2;
    ::coder::array<double, 2U> r2;
    ::coder::array<double, 2U> u1new;
    ::coder::array<double, 2U> u2new;
    ::coder::array<int, 1U> r;
    ::coder::array<int, 1U> r1;
    ::coder::array<boolean_T, 2U> d_VE1_data;
    cell_wrap_9 temp_u1[50];
    cell_wrap_9 temp_u2[50];
    double FS[50];
    double temp_VE1[50];
    double temp_VE2[50];
    double mu[2];
    double b_VE1_data;
    double b_VE2_data;
    int b_VE1_size[2];
    int D;
    int N;
    int b_loop_ub;
    int b_nosplit;
    int c_loop_ub;
    int i1;
    int i2;
    int iindx;
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
    if (u.size(0) < 2.0 * (static_cast<double>(u.size(1)) + 1.0)) {
      b_nosplit = 1;
    } else {
      int b_i;
      int end;
      int i;
      int loop_ub;
      int n1;
      int n2;

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

      loop_ub = u.size(1);
      u1.set_size(r.size(0), u.size(1));
      for (b_i = 0; b_i < loop_ub; b_i++) {
        end = r.size(0);
        for (i = 0; i < end; i++) {
          u1[i + u1.size(0) * b_i] = u[(r[i] + u.size(0) * b_i) - 1];
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

      loop_ub = u.size(1);
      u2.set_size(r1.size(0), u.size(1));
      for (b_i = 0; b_i < loop_ub; b_i++) {
        end = r1.size(0);
        for (i = 0; i < end; i++) {
          u2[i + u2.size(0) * b_i] = u[(r1[i] + u.size(0) * b_i) - 1];
        }
      }

      n1 = r.size(0);

      //  number of samples in S1
      n2 = r1.size(0);

      //  number of samples in S2
      //  check number of points in subclusters
      if ((static_cast<unsigned int>(r.size(0)) < u.size(1) + 1U) || (
           static_cast<unsigned int>(r1.size(0)) < u.size(1) + 1U)) {
        b_nosplit = 1;
      } else {
        int counter;

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
        double VS1;
        double VS2;
        int reassign;
        do {
          unsigned int m1;
          unsigned int m2;

          //  calculate minimum volume of ellipsoids
          VS1 = VS * static_cast<double>(n1) / static_cast<double>(N);
          VS2 = VS * static_cast<double>(n2) / static_cast<double>(N);

          //  calculate properties of bounding ellipsoids for the two subclusters
          calcEllipsoid(u1, VS1, B1, mu1, (double *)&b_VE1_data, b_VE1_size);
          calcEllipsoid(u2, VS2, B2, mu2, (double *)&b_VE2_data, b_VE1_size);

          //  check flags
          //  construct temporary arrays and cell arrays containing results for
          //  each pass through the loop
          temp_u1[counter].f1.set_size(u1.size(0), u1.size(1));
          loop_ub = u1.size(1);
          for (b_i = 0; b_i < loop_ub; b_i++) {
            end = u1.size(0);
            for (i = 0; i < end; i++) {
              temp_u1[counter].f1[i + temp_u1[counter].f1.size(0) * b_i] = u1[i
                + u1.size(0) * b_i];
            }
          }

          temp_u2[counter].f1.set_size(u2.size(0), u2.size(1));
          loop_ub = u2.size(1);
          for (b_i = 0; b_i < loop_ub; b_i++) {
            end = u2.size(0);
            for (i = 0; i < end; i++) {
              temp_u2[counter].f1[i + temp_u2[counter].f1.size(0) * b_i] = u2[i
                + u2.size(0) * b_i];
            }
          }

          temp_VE1[counter] = b_VE1_data;
          temp_VE2[counter] = b_VE2_data;
          FS[counter] = (b_VE1_data + b_VE2_data) / VS;

          // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
          //  check if points need to be reassigned to the other subcluster
          reassign = 0;
          m1 = 0U;
          m2 = 0U;
          u1new.set_size(N, D);
          u2new.set_size(N, D);
          for (b_i = 0; b_i < D; b_i++) {
            for (i = 0; i < N; i++) {
              u1new[i + u1new.size(0) * b_i] = 0.0;
              u2new[i + u2new.size(0) * b_i] = 0.0;
            }
          }

          //  for all points get the Mahalanobis distance between each point and
          //  the centroid of each ellipse and assign accordingly
          if (0 <= N - 1) {
            i1 = u.size(1);
            b_loop_ub = u.size(1);
            i2 = u.size(1);
            c_loop_ub = u.size(1);
          }

          for (i = 0; i < N; i++) {
            double b;
            double b_b;

            //  get d = (u-mu)^T * B^-1 * (u-mu)
            b_u.set_size(1, i1);
            for (b_i = 0; b_i < b_loop_ub; b_i++) {
              b_u[b_i] = u[i + u.size(0) * b_i] - mu1[b_i];
            }

            coder::internal::mrdiv(b_u, B1, r2);
            b = 0.0;
            loop_ub = r2.size(1);
            for (b_i = 0; b_i < loop_ub; b_i++) {
              b += r2[b_i] * (u[i + u.size(0) * b_i] - mu1[b_i]);
            }

            b_u.set_size(1, i2);
            for (b_i = 0; b_i < c_loop_ub; b_i++) {
              b_u[b_i] = u[i + u.size(0) * b_i] - mu2[b_i];
            }

            coder::internal::mrdiv(b_u, B2, r2);
            b_b = 0.0;
            loop_ub = r2.size(1);
            for (b_i = 0; b_i < loop_ub; b_i++) {
              b_b += r2[b_i] * (u[i + u.size(0) * b_i] - mu2[b_i]);
            }

            //  calculate hk = VEk * duk / VSk;
            c_VE1_data = (b_VE1_data * b / VS1 < b_VE2_data * b_b / VS2);
            d_VE1_data.set(&c_VE1_data, 1, 1);
            if (coder::internal::c_ifWhileCond(d_VE1_data)) {
              m1++;
              loop_ub = u.size(1);
              for (b_i = 0; b_i < loop_ub; b_i++) {
                u1new[(static_cast<int>(m1) + u1new.size(0) * b_i) - 1] = u[i +
                  u.size(0) * b_i];
              }

              //  check if point has been reassigned or not
              if (idx[i] != 1.0) {
                reassign = 1;
                idx[i] = 1.0;
              }
            } else {
              m2++;
              loop_ub = u.size(1);
              for (b_i = 0; b_i < loop_ub; b_i++) {
                u2new[(static_cast<int>(m2) + u2new.size(0) * b_i) - 1] = u[i +
                  u.size(0) * b_i];
              }

              //  check if point has been reassigned or not
              if (idx[i] != 2.0) {
                reassign = 1;
                idx[i] = 2.0;
              }
            }
          }

          n1 = static_cast<int>(m1);
          n2 = static_cast<int>(m2);
          if (1 > static_cast<int>(m1)) {
            loop_ub = 0;
          } else {
            loop_ub = static_cast<int>(m1);
          }

          end = u1new.size(1);
          u1.set_size(loop_ub, u1new.size(1));
          for (b_i = 0; b_i < end; b_i++) {
            for (i = 0; i < loop_ub; i++) {
              u1[i + u1.size(0) * b_i] = u1new[i + u1new.size(0) * b_i];
            }
          }

          if (1 > static_cast<int>(m2)) {
            loop_ub = 0;
          } else {
            loop_ub = static_cast<int>(m2);
          }

          end = u2new.size(1);
          u2.set_size(loop_ub, u2new.size(1));
          for (b_i = 0; b_i < end; b_i++) {
            for (i = 0; i < loop_ub; i++) {
              u2[i + u2.size(0) * b_i] = u2new[i + u2new.size(0) * b_i];
            }
          }

          //  update counter
          counter++;
        } while ((reassign != 0) && (counter + 1 <= 50));

        //  find minimum F(S) and return
        coder::internal::minimum(FS, &b_VE1_data, &iindx);
        u1.set_size(temp_u1[iindx - 1].f1.size(0), temp_u1[iindx - 1].f1.size(1));
        loop_ub = temp_u1[iindx - 1].f1.size(1);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          end = temp_u1[iindx - 1].f1.size(0);
          for (i = 0; i < end; i++) {
            u1[i + u1.size(0) * b_i] = temp_u1[iindx - 1].f1[i + temp_u1[iindx -
              1].f1.size(0) * b_i];
          }
        }

        u2.set_size(temp_u2[iindx - 1].f1.size(0), temp_u2[iindx - 1].f1.size(1));
        loop_ub = temp_u2[iindx - 1].f1.size(1);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          end = temp_u2[iindx - 1].f1.size(0);
          for (i = 0; i < end; i++) {
            u2[i + u2.size(0) * b_i] = temp_u2[iindx - 1].f1[i + temp_u2[iindx -
              1].f1.size(0) * b_i];
          }
        }

        VE1_size[0] = 1;
        VE1_size[1] = 1;
        VE1_data[0] = temp_VE1[iindx - 1];
        VE2_size[0] = 1;
        VE2_size[1] = 1;
        VE2_data[0] = temp_VE2[iindx - 1];
      }
    }

    *nosplit = b_nosplit;
  }
}

// End of code generation (splitEllipsoid.cpp)
